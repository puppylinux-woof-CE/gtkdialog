/*
 * widget_tree.c: 
 * Gtkdialog - A small utility for fast and easy GUI building.
 * Copyright (C) 2003-2007  László Pere <pipas@linux.pte.hu>
 * Copyright (C) 2011-2012  Thunor <thunorsif@hotmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/* Includes */
#define _GNU_SOURCE
#include <gtk/gtk.h>

#if GTK_CHECK_VERSION(2,4,0)

#include "config.h"
#include "gtkdialog.h"
#include "attributes.h"
#include "automaton.h"
#include "widgets.h"
#include "signals.h"
#include "stringman.h"
#include "tag_attributes.h"

/* Defines */
//#define DEBUG_CONTENT
//#define DEBUG_TRANSITS

/* Local variables */
typedef enum {
	ColumnPixbuf,
	ColumnIconName,
	ColumnStockId,
	FirstDataColumn
} treecolumns;

gchar *icon_name;
gchar *stock_id;
gint icon_column;
gint stock_column;

/* Local function prototypes, located at file bottom */
static GtkTreeStore *widget_tree_create_tree_store(AttributeSet *Attr,
	tag_attr *attr);
static GtkWidget *widget_tree_create_tree_view(AttributeSet *Attr,
	tag_attr *attr, GtkTreeStore *store);
static void widget_tree_input_by_command(variable *var, char *command,
	gint command_or_file);
static void widget_tree_input_by_file(variable *var, char *filename);
static void widget_tree_input_by_items(variable *var);
static void widget_tree_pixmap_column_cell_layout_function(
	GtkCellLayout *cell_layout, GtkCellRenderer *cell,
	GtkTreeModel *tree_model, GtkTreeIter *iter, GtkTreeView *treeview);
gboolean widget_tree_changed_callback(GtkTreeSelection *treeselection,
	variable *var);
gint widget_tree_natcmp(GtkTreeModel *model, GtkTreeIter *a,
	GtkTreeIter *b, gpointer user_data);
gint widget_tree_natcasecmp(GtkTreeModel *model, GtkTreeIter *a,
	GtkTreeIter *b, gpointer user_data);
static gint _widget_tree_natcmp(GtkTreeModel *model, GtkTreeIter *a,
	GtkTreeIter *b, gpointer user_data, gint sensitive);

/* Notes:
 * I want to note that g_object_get_data is being used quite a bit here
 * where normally get_tag_attribute would be used instead.
 * 
 * I've tidied this widget up considerably and even fixed the problematic
 * pixmap rendering because I want to leave it in a usable stable state
 * but I don't recommend spending any more time on it as it's possibly
 * using the wrong GtkTreeStore model when GtkListStore might've been
 * the more suitable one. This would have to be tested though */

/***********************************************************************
 * Clear                                                               *
 ***********************************************************************/

void widget_tree_clear(variable *var)
{
	GtkTreeModel     *model;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* We drop all the lines here */
	model = gtk_tree_view_get_model(GTK_TREE_VIEW(var->Widget));
	gtk_tree_store_clear(GTK_TREE_STORE(model));
	/* Reset the current sort column to unsorted ascending */
	gtk_tree_sortable_set_sort_column_id(GTK_TREE_SORTABLE(model),
		GTK_TREE_SORTABLE_UNSORTED_SORT_COLUMN_ID, GTK_SORT_ASCENDING);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Create                                                              *
 ***********************************************************************/
/* Handling TreeView widgets.
 * 
 * The model always has the following columns:
 *   0) "pixbuf"     GdkPixbuf
 *   1) "icon-name"  gchar array
 *   2) "stock-id"   gchar array
 * 
 * We create the GtkTreeStore in:
 *   widget_tree_create_tree_store
 * We create the GtkTreeView in:
 *   widget_tree_create_tree_view */

GtkWidget *widget_tree_create(
	AttributeSet *Attr, tag_attr *attr, gint Type)
{
	GtkTreeSelection  *selection;
	GtkTreeStore      *store;
	GtkWidget         *widget;
	gchar             *value;	

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* We need a label so set a default if one wasn't declared */
	if (!attributeset_is_avail(Attr, ATTR_LABEL))
		attributeset_set_if_unset(Attr, ATTR_LABEL, "Column 0");

	/* Creating the tree store to hold the data and the tree view to
	 * represent it */
	store = widget_tree_create_tree_store(Attr, attr);
	widget = widget_tree_create_tree_view(Attr, attr, store);

	/* Thunor: Now we deal with setting the selection mode. The default
	 * is GTK_SELECTION_SINGLE so we'll leave that alone and only set a
	 * different mode if the user requests it */
	if (attr) {
		if ((value = get_tag_attribute(attr, "selection-mode"))) {
			/* Get a pointer to the selection object and set the requested mode */
			selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(widget));
			if (strcasecmp(value, "multiple") == 0 ||
				atoi(value) == GTK_SELECTION_MULTIPLE) {
				gtk_tree_selection_set_mode(selection, GTK_SELECTION_MULTIPLE);
			} else if (strcasecmp(value, "browse") == 0 ||
				atoi(value) == GTK_SELECTION_BROWSE) {
				gtk_tree_selection_set_mode(selection, GTK_SELECTION_BROWSE);
			} else if (strcasecmp(value, "single") == 0 ||
				atoi(value) == GTK_SELECTION_SINGLE) {
				gtk_tree_selection_set_mode(selection, GTK_SELECTION_SINGLE);
			} else /* if (strcasecmp(value, "none") == 0 ||
				atoi(value) == GTK_SELECTION_NONE) */ {
				/* Note that atoi will return 0 for any non-integer string in
				 * value, therefore GTK_SELECTION_NONE should be checked last */
				gtk_tree_selection_set_mode(selection, GTK_SELECTION_NONE);
			}
		}
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return widget;
}

/***********************************************************************
 * Environment Variable All Construct                                  *
 ***********************************************************************/

gchar *widget_tree_envvar_all_construct(variable *var)
{
	GtkTreeIter       iter;
	GtkTreeModel     *model;
	gchar            *line;
	gchar            *string;
	gchar            *text;
	gint              column;
	gint              index;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	model = gtk_tree_view_get_model(GTK_TREE_VIEW(var->Widget));
	gtk_tree_model_get_iter_first(model, &iter);

	/* Which column should we export
	 * variable *variables_get_by_name( const char *name ); */
	if ((string = g_object_get_data(G_OBJECT(var->Widget), "exported-column"))) {
		column = atoi(string) + FirstDataColumn;
	} else {
		column = FirstDataColumn;
	}

	line = g_strdup_printf("%s_ALL=\"", var->Name);
	index = 0;
	while (gtk_tree_store_iter_is_valid(GTK_TREE_STORE(model), &iter)) {
		gtk_tree_model_get(model, &iter, column, &text, -1);
		if (index == 0) {
			string = g_strconcat(line, "'", text, "'", NULL);
		} else {
			string = g_strconcat(line, " '", text, "'", NULL);
		}
		g_free(line);
		line = string;
		g_free(text);
		if (!gtk_tree_model_iter_next(GTK_TREE_MODEL(model), &iter)) break;
		++index;
	}
	string = g_strconcat(line, "\"\n", NULL);
	g_free(line);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return string;
}

/***********************************************************************
 * Environment Variable Construct                                      *
 ***********************************************************************/

gchar *widget_tree_envvar_construct(GtkWidget *widget)
{
	GList             *selectedrows, *row;
	GtkTreeIter        iter;
	GtkTreeModel      *model;
	GtkTreePath       *path;
	GtkTreeSelection  *selection;
	GType              coltype;
	gchar             *line;
	gchar             *string;
	gchar             *text;
	gdouble            valdouble;
	gint               column;
	gint               index;
	gint               initialrow;
	gint               selectionmode;
	gint64             valint64;
	guint64            valuint64;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* Searching the selected row */
	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(widget));
	selectionmode = gtk_tree_selection_get_mode(selection);

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): widget=%p selectionmode=%i\n", __func__,
		widget, selectionmode);
	fprintf(stderr, "%s(): widget=%p selected row count=%i\n", __func__,
		widget, gtk_tree_selection_count_selected_rows(selection));
#endif

	if (selectionmode == GTK_SELECTION_NONE) {
		string = g_strdup("");	/* Nothing is selected */
	} else if (selectionmode == GTK_SELECTION_MULTIPLE) {
		/* Thunor: New code to return data from multiple selected rows.
		 * I need to document how it works (for my benefit at least)
		 * and what the user should expect to get from it:
		 * If gtk_tree_selection_count_selected_rows returns 0
		 * then we simply return a new empty string, otherwise
		 * gtk_tree_selection_get_selected_rows gives us a GList of
		 * GtkTreePaths (with a documented empty definition!). Then
		 * gtk_tree_model_get_iter will convert the mysterious
		 * GtkTreePath to a usable GtkTreeIter and then
		 * gtk_tree_model_get reads the data from the column.
		 * The cast GTK_TREE_PATH threw up an undefined reference
		 * warning so I used (GtkTreePath*) instead */
		/* Get exported-column (custom) */
		if ((text = g_object_get_data(G_OBJECT(widget), "exported-column"))) {
			index = atoi(text) + FirstDataColumn;
		} else {
			index = FirstDataColumn;
		}
		line = g_strdup("");
		if (gtk_tree_selection_count_selected_rows(selection)) {
			selectedrows = gtk_tree_selection_get_selected_rows(selection,
				&model);
			coltype = gtk_tree_model_get_column_type(GTK_TREE_MODEL(model),
				index);
			initialrow = TRUE;
			row = selectedrows;
			while (row) {
				path = (GtkTreePath*)(row->data);
				gtk_tree_model_get_iter(model, &iter, path);
				switch (coltype) {
					case G_TYPE_STRING:
						gtk_tree_model_get(GTK_TREE_MODEL(model), &iter,
							index, &string, -1);
						break;
					case G_TYPE_INT64:
						gtk_tree_model_get(GTK_TREE_MODEL(model), &iter,
							index, &valint64, -1);
						string = g_strdup_printf("%lli", valint64);
						break;
					case G_TYPE_UINT64:
						gtk_tree_model_get(GTK_TREE_MODEL(model), &iter,
							index, &valuint64, -1);
						string = g_strdup_printf("%llu", valuint64);
						break;
					case G_TYPE_DOUBLE:
						gtk_tree_model_get(GTK_TREE_MODEL(model), &iter,
							index, &valdouble, -1);
						string = g_strdup_printf("%f", valdouble);
						break;
					default:
						fprintf(stderr, "%s(): Unsupported column-type %i\n",
							__func__, coltype);
						string = g_strdup("");
				}
				if (initialrow) {
					//text = g_strconcat(line, "'", string, "'", NULL);
					text = g_strconcat(line, string, NULL);
					initialrow = FALSE;
				} else {
					//text = g_strconcat(line, " '", string, "'", NULL);
					text = g_strconcat(line, "\n", string, NULL);
				}
				g_free(line);
				line = text;
				g_free(string);
				row = row->next;
			}
			/* The GtkTreePaths and the GList should be freed now */
			g_list_foreach(selectedrows, (GFunc)gtk_tree_path_free, NULL);
			g_list_free(selectedrows);
		}

#ifdef DEBUG_CONTENT
		fprintf(stderr, "%s(): line=%s\n", __func__, line);
#endif

		string = line;
	} else {
		/* Thunor: Below is the original code that handles the
		 * default GTK_SELECTION_SINGLE mode and it's quite happy
		 * dealing with GTK_SELECTION_BROWSE too.
		 * 
		 * Regarding gtk_tree_store_iter_is_valid, GTK+ 2 docs state
		 * "WARNING: This function is slow. Only use it for debugging
		 * and/or testing purposes.". In fact there's no need to use
		 * it as gtk_tree_selection_get_selected returns true if there
		 * is a selected node. The docs also state "iter may be NULL if
		 * you just want to test if selection has any selected nodes".
		 * Anyway, I'll just note it for now as it's only dealing with
		 * either none or one row and I don't want to break anything ;) */
		 gtk_tree_selection_get_selected(selection, &model, &iter);
		 if (gtk_tree_store_iter_is_valid(GTK_TREE_STORE(model), &iter)) {
			/* Get exported-column (custom) */
			if ((text = g_object_get_data(G_OBJECT(widget), "exported-column"))) {
				index = atoi(text) + FirstDataColumn;
			} else {
				index = FirstDataColumn;
			}
			coltype = gtk_tree_model_get_column_type(GTK_TREE_MODEL(model),
				index);
			switch (coltype) {
				case G_TYPE_STRING:
					gtk_tree_model_get(GTK_TREE_MODEL(model), &iter,
						index, &string, -1);
					break;
				case G_TYPE_INT64:
					gtk_tree_model_get(GTK_TREE_MODEL(model), &iter,
						index, &valint64, -1);
					string = g_strdup_printf("%lli", valint64);
					break;
				case G_TYPE_UINT64:
					gtk_tree_model_get(GTK_TREE_MODEL(model), &iter,
						index, &valuint64, -1);
					string = g_strdup_printf("%llu", valuint64);
					break;
				case G_TYPE_DOUBLE:
					gtk_tree_model_get(GTK_TREE_MODEL(model), &iter,
						index, &valdouble, -1);
					string = g_strdup_printf("%f", valdouble);
					break;
				default:
					fprintf(stderr, "%s(): Unsupported column-type %i\n",
						__func__, coltype);
					string = g_strdup("");
			}
		} else {
			string = g_strdup("");
		}
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return string;
}

/***********************************************************************
 * Fileselect                                                          *
 ***********************************************************************/

void widget_tree_fileselect(
	variable *var, const char *name, const char *value)
{
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	fprintf(stderr, "%s(): Fileselect not implemented for this widget.\n", __func__);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Refresh                                                             *
 ***********************************************************************/

void widget_tree_refresh(variable *var)
{
	GList            *element;
	GtkTreeIter       iter;
	GtkTreeSelection *selection;
	GtkTreeModel     *model;
	gchar            *act;
	gchar            *tmp;
	gchar            *value;
	gint              index;
	gint              initialised = FALSE;
	gint              selected_row;
	gint              selectionmode;
	gint              sort_column;
	gint              sort_type;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* Get default icon from the custom tag attributes if available */
	icon_name = stock_id = NULL;
	if (var->widget_tag_attr) {
		if ((value = get_tag_attribute(var->widget_tag_attr, "stock")) ||
			(value = get_tag_attribute(var->widget_tag_attr, "stock-id")))
			stock_id = value;
		if ((value = get_tag_attribute(var->widget_tag_attr, "icon")) ||
			(value = get_tag_attribute(var->widget_tag_attr, "icon-name")))
			icon_name = value;
	}

	/* Get initialised state of widget */
	if (g_object_get_data(G_OBJECT(var->Widget), "_initialised") != NULL)
		initialised = (gint)g_object_get_data(G_OBJECT(var->Widget), "_initialised");

	/* We drop all the lines here */
	/* Thunor: I'd like to stop doing this but some applications (pbackup,
	 * pcd, petget, pfind, pmusic, pprocess, psip) are refreshing without
	 * clearing first so I'll leave it as is. It's no big deal but giving
	 * the application developer the choice of clearing could make refresh
	 * behave as though it's appending data which is much more useful */
	/*gtk_tree_store_clear(GTK_TREE_STORE(model));	Redundant */
	widget_tree_clear(var);

	/* The <input> tag... */
	act = attributeset_get_first(&element, var->Attributes, ATTR_INPUT);
	while (act) {
		/* Get stock-column from the input tag if available */
		if ((tmp = attributeset_get_this_tagattr(&element, var->Attributes,
			ATTR_INPUT, "stock-column")) ||
			(tmp = attributeset_get_this_tagattr(&element, var->Attributes,
			ATTR_INPUT, "stock_column"))) {
			stock_column = atoi(tmp);
		} else {
			stock_column = -1;
		}
		/* Get icon-column from the input tag if available */
		if ((tmp = attributeset_get_this_tagattr(&element, var->Attributes,
			ATTR_INPUT, "icon-column")) ||
			(tmp = attributeset_get_this_tagattr(&element, var->Attributes,
			ATTR_INPUT, "icon_column"))) {
			icon_column = atoi(tmp);
		} else {
			icon_column = -1;
		}

		if (input_is_shell_command(act)) {
#ifdef DEBUG_CONTENT
			printf("%s(): 2: command='%s'\n", __func__, act);
#endif
			widget_tree_input_by_command(var, act + 8, TRUE);
		} else if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5) {
		/* input file stock = "File:", input file = "File:/path/to/file" */
#ifdef DEBUG_CONTENT
			printf("%s(): 1: command='%s'\n", __func__, act);
#endif
			if (!initialised) {
				/* Check for file-monitor and create if requested */
				widget_file_monitor_try_create(var, act + 5);
			}
			widget_tree_input_by_file(var, act + 5);
		} else {
#ifdef DEBUG_CONTENT
			printf("%s(): 3: command='%s'\n", __func__, act);
#endif
			/* Thunor: These are shell commands without the "Command:",
			 * but why is it missing? token_store_with_argument_attr()
			 * manages that. Whoever wrote the widget_tree_refresh()
			 * function knew this which is why an else clause exists here.
			 * 
			 * I think I've found the answer but I'm not going to mess
			 * about with it right now. It looks as though input isn't
			 * set-up properly in the parser which might uncover other
			 * issues when corrected so I'll mark it temp temp
			 * 
			 * [UPDATE] 2012-11-16
			 * I have a suspicion that the recently replaced custom tree
			 * signal handler may have been responsible for the above in
			 * which case it won't be a possible issue anymore.
			 */
			widget_tree_input_by_command(var, act, TRUE);
		}
		act = attributeset_get_next(&element, var->Attributes, ATTR_INPUT);
	}

	/* The <item> tags... */
	if (attributeset_is_avail(var->Attributes, ATTR_ITEM))
		widget_tree_input_by_items(var);

	/* Initialise these only once at start-up */
	if (!initialised) {
		/* Apply directives */
		if (attributeset_is_avail(var->Attributes, ATTR_DEFAULT))
			fprintf(stderr, "%s(): <default> not implemented for this widget.\n",
				__func__);
		if ((attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "false")) ||
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "disabled")) ||	/* Deprecated */
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "no")) ||
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "0")))
			gtk_widget_set_sensitive(var->Widget, FALSE);

		/* Connect signals */
		/* The default signal */
		g_signal_connect(G_OBJECT(var->Widget), "row-activated",
			G_CALLBACK(on_any_widget_row_activated_event), (gpointer)var->Attributes);
		/* This was also connected-up but I don't know if anyone is using it.
		 * This signal is always one selection behind which connect-after
		 * doesn't fix so it's of questionable worth */
		g_signal_connect(G_OBJECT(var->Widget), "cursor-changed",
			G_CALLBACK(on_any_widget_cursor_changed_event), (gpointer)var->Attributes);
		/* This signal originates from the selection object which is useful
		 * but we need to route it through a local callback first */
		selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(var->Widget));
		g_signal_connect(selection, "changed",
			G_CALLBACK(widget_tree_changed_callback), (gpointer)var);
	}

	if (var->widget_tag_attr) {
		/* Get auto-sort (custom) */
		if ((value = get_tag_attribute(var->widget_tag_attr, "auto-sort")) &&
			((strcasecmp(value, "true") == 0) || (strcasecmp(value, "yes") == 0) ||
			(atoi(value) == 1))) {
			/* Get sort-column (custom) */
			sort_column = 0;
			if ((value = get_tag_attribute(var->widget_tag_attr, "sort-column")))
				sort_column = atoi(value);
			sort_type = 0;
			/* Get sort-type (custom) */
			sort_type = 0;	/* 0=ascending, 1=descending  -- GtkSortType */
			if ((value = get_tag_attribute(var->widget_tag_attr, "sort-type")))
				sort_type = atoi(value);
			/* Sort! */
			model = gtk_tree_view_get_model(GTK_TREE_VIEW(var->Widget));
			gtk_tree_sortable_set_sort_column_id(GTK_TREE_SORTABLE(model),
				sort_column + FirstDataColumn, sort_type);
		}
		/* Get selected-row (custom) */
		if ((value = get_tag_attribute(var->widget_tag_attr, "selected-row"))) {
			selected_row = atoi(value);
			if (selected_row >= 0) {
				selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(var->Widget));
				selectionmode = gtk_tree_selection_get_mode(selection);
				if (selectionmode != GTK_SELECTION_NONE) {
					model = gtk_tree_view_get_model(GTK_TREE_VIEW(var->Widget));
					gtk_tree_model_get_iter_first(model, &iter);
					index = 0;
					while (gtk_tree_store_iter_is_valid(GTK_TREE_STORE(model), &iter)) {
						if (selected_row == index) {
							gtk_tree_selection_select_iter(selection, &iter);
							break;
						}
						if (!gtk_tree_model_iter_next(GTK_TREE_MODEL(model), &iter))
							break;
						index++;
					}
				}
			}
		}
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Removeselected                                                      *
 ***********************************************************************/

void widget_tree_removeselected(variable *var)
{
	GList             *rowreferences = NULL;
	GList             *selectedrows, *row;
	GtkTreeIter        iter;
	GtkTreeModel      *model;
	GtkTreeSelection  *selection;
	gint               selectionmode;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(var->Widget));
	selectionmode = gtk_tree_selection_get_mode(selection);
	if (selectionmode == GTK_SELECTION_NONE) {
		/* Nothing to do */
	} else if (selectionmode == GTK_SELECTION_MULTIPLE) {
		/* Thunor: New code to delete multiple selected rows.
		 * http://scentric.net/tutorial/sec-treemodel-rowref.html
		 * is a good place to learn about paths and row references.
		 * This is based on the code I added to widget_get_text_value.
		 * We get the list of selected rows as normal but we can't
		 * iterate through it and delete them one by one because the
		 * paths to the rows change, but we can convert those paths
		 * to GtkTreeRowReferences which we'll store in another list.
		 * GtkTreeRowReferences watch for row changes and maintain
		 * themselves so we can delete them one by one without
		 * worrying about the others becoming out-of-date. */
		if (gtk_tree_selection_count_selected_rows(selection)) {
			selectedrows = gtk_tree_selection_get_selected_rows(selection, &model);
			row = selectedrows;
			while (row) {
				rowreferences = g_list_append(rowreferences,
					gtk_tree_row_reference_new(model, (GtkTreePath*)(row->data)));
				row = row->next;
			}
			/* The GtkTreePaths and the GList should be freed now */
			g_list_foreach(selectedrows, (GFunc)gtk_tree_path_free, NULL);
			g_list_free(selectedrows);
			row = rowreferences;
			while (row) {
				if (gtk_tree_model_get_iter(model, &iter,
					gtk_tree_row_reference_get_path((GtkTreeRowReference*)row->data)))
					gtk_tree_store_remove(GTK_TREE_STORE(model), &iter);
				row = row->next;
			}
			/* The GList should be freed now */
			g_list_free(rowreferences);
		}
	} else {
		/* Thunor: Below is the original code that handles the
		 * default GTK_SELECTION_SINGLE mode and it's quite happy
		 * dealing with GTK_SELECTION_BROWSE too.
		 * 
		 * It didn't check that something is actually selected
		 * but since gtk_tree_selection_get_selected returns
		 * true if something is then making a simple modification
		 * seemed to be the sensible thing to do. Now there's no
		 * Gtk-CRITICAL message appearing in the terminal */
		if (gtk_tree_selection_get_selected(selection, &model, &iter))
			gtk_tree_store_remove(GTK_TREE_STORE(model), &iter);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Save                                                                *
 ***********************************************************************/

void widget_tree_save(variable *var)
{
	FILE             *outfile;
	GList            *element;
	GtkTreeIter       iter;
	GtkTreeModel     *model;
	GType             coltype;
	gdouble           valdouble;
	gchar            *act;
	gchar            *filename = NULL;
	gchar            *line;
	gchar            *string;
	gchar            *text;
	gint              column, columnmax;
	gint              initialrow = TRUE;
	gint64            valint64;
	guint64           valuint64;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* We'll use the output file filename if available */
	act = attributeset_get_first(&element, var->Attributes, ATTR_OUTPUT);
	while (act) {
		if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5) {
			filename = act + 5;
			break;
		}
		act = attributeset_get_next(&element, var->Attributes, ATTR_OUTPUT);
	}

	/* If we have a valid filename then open it and dump the
	 * widget's data to it */
	if (filename) {
		if ((outfile = fopen(filename, "w"))) {

			model = gtk_tree_view_get_model(GTK_TREE_VIEW(var->Widget));
			columnmax = gtk_tree_model_get_n_columns(GTK_TREE_MODEL(model));

			gtk_tree_model_get_iter_first(model, &iter);
			while (gtk_tree_store_iter_is_valid(GTK_TREE_STORE(model), &iter)) {

				line = g_strdup("");
				for (column = ColumnIconName; column < columnmax; column++) {

					coltype = gtk_tree_model_get_column_type
						(GTK_TREE_MODEL(model), column);
					switch (coltype) {
						case G_TYPE_STRING:
							gtk_tree_model_get(GTK_TREE_MODEL(model), &iter,
								column, &string, -1);
							break;
						case G_TYPE_INT64:
							gtk_tree_model_get(GTK_TREE_MODEL(model), &iter,
								column, &valint64, -1);
							string = g_strdup_printf("%lli", valint64);
							break;
						case G_TYPE_UINT64:
							gtk_tree_model_get(GTK_TREE_MODEL(model), &iter,
								column, &valuint64, -1);
							string = g_strdup_printf("%llu", valuint64);
							break;
						case G_TYPE_DOUBLE:
							gtk_tree_model_get(GTK_TREE_MODEL(model), &iter,
								column, &valdouble, -1);
							string = g_strdup_printf("%f", valdouble);
							break;
						default:
							fprintf(stderr, "%s(): Unsupported column-type %i\n",
								__func__, coltype);
							string = g_strdup("");
					}
					if (column == ColumnIconName) {
						text = g_strconcat(line, string, NULL);
					} else {
						text = g_strconcat(line, "|", string, NULL);
					}
					g_free(line);
					line = text;
					g_free(string);
				}
				if (initialrow) {
					fprintf(outfile, "%s", text);
					initialrow = FALSE;
				} else {
					fprintf(outfile, "\n%s", text);
				}
				g_free(text);

				if (!gtk_tree_model_iter_next(GTK_TREE_MODEL(model), &iter)) break;
			}

			fclose(outfile);
		} else {
			fprintf(stderr, "%s(): Couldn't open '%s' for writing.\n",
				__func__, filename);
		}
	} else {
		fprintf(stderr, "%s(): No <output file> directive found.\n", __func__);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Create GtkTreeStore                                                 *
 ***********************************************************************/
/* Creating tree store from <label></label> tags */

static GtkTreeStore *widget_tree_create_tree_store(AttributeSet *Attr,
	tag_attr *attr)
{
	GList            *element;
	GtkTreeStore     *treestore;
	GType            *types;
	gchar            *label;
	gchar            *value;
	gint              index;
	gint              ncolumns;
	gint              user_type;
	list_t           *columns = NULL;
	list_t           *column_type = NULL;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* We create as many columns as the label tag suggests */
	label = g_strdup(attributeset_get_first(&element, Attr, ATTR_LABEL));
	columns = linecutter(label, '|');
	ncolumns = columns->n_lines;

	/* Set type for image columns */
	types = g_new(GType, ncolumns + FirstDataColumn);
	types[ColumnPixbuf]   = G_TYPE_POINTER;
	types[ColumnIconName] = G_TYPE_STRING;
	types[ColumnStockId]  = G_TYPE_STRING;

	if (attr) {
		/* Get column-type (custom) */
		if ((value = get_tag_attribute(attr, "column-type"))) {
			column_type = linecutter(g_strdup(value), '|');
		}
	}

	/* Set type for user columns */
	for (index = FirstDataColumn; index < ncolumns + FirstDataColumn; ++index) {
		/* Set a default type */
		types[index] = G_TYPE_STRING;
		/* Set a user requested type? */
		if (column_type && column_type->n_lines > index - FirstDataColumn) {
			if (strcasecmp(column_type->line[index - FirstDataColumn],
				"int64") == 0) {
				user_type = G_TYPE_INT64;
			} else if (strcasecmp(column_type->line[index - FirstDataColumn],
				"uint64") == 0) {
				user_type = G_TYPE_UINT64;
			} else if (strcasecmp(column_type->line[index - FirstDataColumn],
				"double") == 0) {
				user_type = G_TYPE_DOUBLE;
			} else {
				user_type = G_TYPE_STRING;
			}
#ifdef DEBUG_CONTENT
			fprintf(stderr, "%s(): column_type=%p column_type->n_lines=%i \
index-FirstDataColumn=%i user_type=%i\n", __func__, column_type,
				column_type->n_lines, index - FirstDataColumn, user_type);
#endif
			types[index] = user_type;
		}
	}

	treestore = gtk_tree_store_newv(ncolumns + FirstDataColumn, types);

	/* Free linecutter memory */
	if (columns) list_t_free(columns);
	if (column_type) list_t_free(column_type);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return treestore;
}

/***********************************************************************
 * Create GtkTreeView                                                  *
 ***********************************************************************/

static GtkWidget *widget_tree_create_tree_view(AttributeSet *Attr,
	tag_attr *attr, GtkTreeStore *store)
{
	GList             *element;
	GtkCellRenderer   *renderer;
	GtkTreeViewColumn *column;
	GtkWidget         *tree_view;
	gchar             *headline = NULL;
	gchar             *value;
	gint               index;
	gint               function;
	list_t            *column_sizing = NULL;
	list_t            *column_resizeable = NULL;
	list_t            *column_header_active = NULL;
	list_t            *column_visible = NULL;
	list_t            *column_sort_function = NULL;
	list_t            *columns = NULL;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	headline = g_strdup(attributeset_get_first(&element, Attr, ATTR_LABEL));
	columns = linecutter(headline, '|');

	if (attr) {
		/* Get column-sizing (custom) */
		if ((value = get_tag_attribute(attr, "column-sizing")))
			column_sizing = linecutter(g_strdup(value), '|');
		/* Get column-resizeable (custom) */
		if ((value = get_tag_attribute(attr, "column-resizeable")))
			column_resizeable = linecutter(g_strdup(value), '|');
		/* Get column-header-active (custom) */
		if ((value = get_tag_attribute(attr, "column-header-active")))
			column_header_active = linecutter(g_strdup(value), '|');
		/* Get column-visible (custom) */
		if ((value = get_tag_attribute(attr, "column-visible")))
			column_visible = linecutter(g_strdup(value), '|');
		/* Get column-sort-function (custom) */
		if ((value = get_tag_attribute(attr, "column-sort-function")))
			column_sort_function = linecutter(g_strdup(value), '|');
	}

	/* We create the TreeView here */
	tree_view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));

	/* Remove the default indentation in column 0 */
	gtk_tree_view_set_show_expanders(GTK_TREE_VIEW(tree_view), FALSE);

	/* This makes no difference to performance in my tests (see below)
	gtk_tree_view_set_fixed_height_mode(GTK_TREE_VIEW(tree_view), TRUE); */

	/* Create the columns */
	for (index = 0; index < columns->n_lines; ++index) {
		column = gtk_tree_view_column_new();
		/* This makes no difference to performance in my tests (see above)
		gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
		gtk_tree_view_column_set_fixed_width(column, 50); */
		/* gtk_tree_view_column_set_resizable(column, TRUE);	Redundant: Now managed below by column */
		gtk_tree_view_column_set_title(column, columns->line[index]);
		gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);
		gtk_tree_view_column_set_sort_column_id(column, index + FirstDataColumn);

		if (index == 0) {
			/* The first column will hold two cell renderer. One for the
			 * pixmap with a complex cell data function and one text
			 * renderer with the first real data column given by the user */
			renderer = gtk_cell_renderer_pixbuf_new();
			gtk_tree_view_column_pack_start(column, renderer, FALSE);
			gtk_cell_layout_set_cell_data_func(GTK_CELL_LAYOUT(column),
				renderer,
				(GtkCellLayoutDataFunc)widget_tree_pixmap_column_cell_layout_function,
				tree_view, NULL);
			renderer = gtk_cell_renderer_text_new();
			gtk_tree_view_column_pack_start(column, renderer, FALSE);
			gtk_tree_view_column_add_attribute(column, renderer, "text",
				index + FirstDataColumn);
		} else {
			/* Create the other columns holding data from the user */
			renderer = gtk_cell_renderer_text_new ();
			gtk_tree_view_column_pack_start(column, renderer, TRUE);
			gtk_tree_view_column_add_attribute(column, renderer, "text",
				index + FirstDataColumn);
		}
		/* Resize mode? (the default is to grow) */
		if (column_sizing && index < column_sizing->n_lines) {
			if (atoi(column_sizing->line[index]) == GTK_TREE_VIEW_COLUMN_GROW_ONLY) {
				gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_GROW_ONLY);
			} else if (atoi(column_sizing->line[index]) == GTK_TREE_VIEW_COLUMN_AUTOSIZE) {
				gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
			} else {
				gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
				gtk_tree_view_column_set_fixed_width(column,
					atoi(column_sizing->line[index]));
			}
		}
		/* Resizeable column? (gtkdialog's default is resizeable) */
		gtk_tree_view_column_set_resizable(column, TRUE);
		if (column_resizeable && index < column_resizeable->n_lines) {
			if ((strcasecmp(column_resizeable->line[index], "false") == 0) ||
				(strcasecmp(column_resizeable->line[index], "no") == 0) ||
				(strcasecmp(column_resizeable->line[index], "0") == 0)) {
				gtk_tree_view_column_set_resizable(column, FALSE);
			}
		}
		/* Deactivate column header? (the default is active) */
		if (column_header_active && index < column_header_active->n_lines) {
			if ((strcasecmp(column_header_active->line[index], "false") == 0) ||
				(strcasecmp(column_header_active->line[index], "no") == 0) ||
				(strcasecmp(column_header_active->line[index], "0") == 0)) {
				gtk_tree_view_column_set_clickable(column, FALSE);
			}
		}
		/* Hide column? (the default is shown) */
		if (column_visible && index < column_visible->n_lines) {
			if ((strcasecmp(column_visible->line[index], "false") == 0) ||
				(strcasecmp(column_visible->line[index], "no") == 0) ||
				(strcasecmp(column_visible->line[index], "0") == 0)) {
				gtk_tree_view_column_set_visible(column, FALSE);
			}
		}
		/* Set custom sort function for column? */
		if (column_sort_function && index < column_sort_function->n_lines) {
			function = atoi(column_sort_function->line[index]);
			if (function == 1 || function == 2) {
				if ((gtk_tree_model_get_column_type(GTK_TREE_MODEL(store),
					index + FirstDataColumn) == G_TYPE_STRING)) {
					if (function == 1) {
						gtk_tree_sortable_set_sort_func(GTK_TREE_SORTABLE(store),
							index + FirstDataColumn, widget_tree_natcmp,
							(gpointer)(index + FirstDataColumn), NULL);
					} else {
						gtk_tree_sortable_set_sort_func(GTK_TREE_SORTABLE(store),
							index + FirstDataColumn, widget_tree_natcasecmp,
							(gpointer)(index + FirstDataColumn), NULL);
					}
				} else {
					fprintf(stderr, "%s(): column-sort-function: natural \
sorting is compatible only with columns of type string.\n", __func__);
				}
			}
		}
	}

	/* Free linecutter memory */
	if (column_sizing) list_t_free(column_sizing);
	if (column_resizeable) list_t_free(column_resizeable);
	if (column_header_active) list_t_free(column_header_active);
	if (column_visible) list_t_free(column_visible);
	if (column_sort_function) list_t_free(column_sort_function);
	if (columns) list_t_free(columns);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return tree_view;
}

/***********************************************************************
 * Input by Command                                                    *
 ***********************************************************************/
/* This function requires that the variables (local to this file)
 * icon_column, stock_column, icon_name and stock_id are initialised
 * before calling */

static void widget_tree_input_by_command(variable *var, char *filename,
	gint command_or_file)
{
	FILE             *infile;
	GtkTreeIter       iter;
	GtkTreeModel     *model;
	GType             coltype;
	gchar           **columns;
	gchar             oneline[512];
	gint              count;
	gint              hiddencolumns;
	gint              n, ncolumns;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (command_or_file) {
		infile = widget_opencommand(filename);
	} else {
		infile = fopen(filename, "r");
	}

	if (infile) {

		model = gtk_tree_view_get_model(GTK_TREE_VIEW(var->Widget));

		ncolumns = gtk_tree_model_get_n_columns(model) - FirstDataColumn;

		while (fgets(oneline, 512, infile) != NULL) {
			hiddencolumns = 0;
			/*g_strstrip(oneline);	Redundant */

			/* Enforce end of string in case of max chars read */
			oneline[512 - 1] = 0;
			/* Remove the trailing [CR]LFs */
			for (count = strlen(oneline) - 1; count >= 0; count--)
				if (oneline[count] == 13 || oneline[count] == 10) oneline[count] = 0;

			columns = g_strsplit(oneline, "|", 128);

			gtk_tree_store_append(GTK_TREE_STORE(model), &iter, NULL);

			if (stock_id) {
				/* If a default stock-id was declared then set it here */
				gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
					ColumnStockId, stock_id, -1);
#ifdef DEBUG_CONTENT
				fprintf(stderr, "%s(): <tree stock-id='%s'>\n", __func__, stock_id);
#endif
			} else if (icon_name) {
				/* If a default icon-name was declared then set it here */
				gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
					ColumnIconName, icon_name, -1);
#ifdef DEBUG_CONTENT
				fprintf(stderr, "%s(): <tree icon-name='%s'>\n", __func__, icon_name);
#endif
			}

			for (n = 0; columns[n] != NULL; ++n) {

				if (n - hiddencolumns >= ncolumns) break;

				/*g_strstrip(columns[n]);	Redundant: only needed for icon names */

				if (n == stock_column) {
					g_strstrip(columns[n]);	/* Required */
					gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
						ColumnStockId, columns[n], -1);
					gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
						ColumnIconName, NULL, -1);
#ifdef DEBUG_CONTENT
					fprintf(stderr, "%s(): <input stock-column=%i>\n", __func__, stock_column);
#endif
					++hiddencolumns;
				} else if (n == icon_column) {
					g_strstrip(columns[n]);	/* Required */
					gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
						ColumnStockId, NULL, -1);
					gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
						ColumnIconName, columns[n], -1);
#ifdef DEBUG_CONTENT
					fprintf(stderr, "%s(): <input icon-column=%i>\n", __func__, icon_column);
#endif
					++hiddencolumns;
				} else {
					coltype = gtk_tree_model_get_column_type(model,
						n + FirstDataColumn - hiddencolumns);
					switch (coltype) {
						case G_TYPE_STRING:
							gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
								n + FirstDataColumn - hiddencolumns,
								columns[n], -1);
							break;
						case G_TYPE_INT64:
							gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
								n + FirstDataColumn - hiddencolumns,
								strtoll(columns[n], NULL, 0), -1);
							break;
						case G_TYPE_UINT64:
							gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
								n + FirstDataColumn - hiddencolumns,
								strtoull(columns[n], NULL, 0), -1);
							break;
						case G_TYPE_DOUBLE:
							gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
								n + FirstDataColumn - hiddencolumns,
								strtod(columns[n], NULL), -1);
							break;
						default:
							fprintf(stderr, "%s(): Unsupported column-type %i\n",
								__func__, coltype);
					}
				}
			}
			g_strfreev(columns);
		}

		if (command_or_file) {
			pclose(infile);
		} else {
			fclose(infile);
		}

	} else {
		fprintf(stderr, "%s(): Couldn't open '%s' for reading.\n",
			__func__, filename);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by File                                                       *
 ***********************************************************************/

static void widget_tree_input_by_file(variable *var, char *filename)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_tree_input_by_command(var, filename, FALSE);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by Items                                                      *
 ***********************************************************************/
/* This function requires that the variables (local to this file)
 * icon_name and stock_id are initialised before calling */

static void widget_tree_input_by_items(variable *var)
{
	GList            *element;
	GtkTreeIter       iter;
	GtkTreeModel     *model;
	GType             coltype;
	gchar            *act;
	gchar           **columns;
	gchar            *value;
	gint              n, ncolumns;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	model = gtk_tree_view_get_model(GTK_TREE_VIEW(var->Widget));

	ncolumns = gtk_tree_model_get_n_columns(model) - FirstDataColumn;

	/* act points to the original string so we can't remove [CR]LFs
	 * although it's not going to be likely within <item>"..."</item> */
	act = attributeset_get_first(&element, var->Attributes, ATTR_ITEM);
	while (act != NULL) {
		gtk_tree_store_append(GTK_TREE_STORE(model), &iter, NULL);

		if ((value = attributeset_get_this_tagattr(&element, var->Attributes,
			ATTR_ITEM, "stock")) ||
			(value = attributeset_get_this_tagattr(&element, var->Attributes,
			ATTR_ITEM, "stock-id")) ||
			(value = attributeset_get_this_tagattr(&element, var->Attributes,
			ATTR_ITEM, "stock_id"))) {
			gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
				ColumnStockId, value, -1);
#ifdef DEBUG_CONTENT
			fprintf(stderr, "%s(): <item stock-id='%s'>\n", __func__, value);
#endif
		} else if ((value = attributeset_get_this_tagattr(&element, var->Attributes,
			ATTR_ITEM, "icon")) ||
			(value = attributeset_get_this_tagattr(&element, var->Attributes,
			ATTR_ITEM, "icon-name")) ||
			(value = attributeset_get_this_tagattr(&element, var->Attributes,
			ATTR_ITEM, "icon_name"))) {
			gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
				ColumnIconName, value, -1);
#ifdef DEBUG_CONTENT
			fprintf(stderr, "%s(): <item icon-name='%s'>\n", __func__, value);
#endif
		} else if (stock_id) {
			/* If a default stock-id was declared then set it here */
			gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
				ColumnStockId, stock_id, -1);
#ifdef DEBUG_CONTENT
			fprintf(stderr, "%s(): <tree stock-id='%s'>\n", __func__, stock_id);
#endif
		} else if (icon_name) {
			/* If a default icon-name was declared then set it here */
			gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
				ColumnIconName, icon_name, -1);
#ifdef DEBUG_CONTENT
			fprintf(stderr, "%s(): <tree icon-name='%s'>\n", __func__, icon_name);
#endif
		}

		columns = g_strsplit(act, "|", 128);
		for (n = 0; columns[n] != NULL; ++n) {
			if (n >= ncolumns)
				break;
			/*g_strstrip(columns[n]);	Redundant */
			coltype = gtk_tree_model_get_column_type(model, n + FirstDataColumn);
			switch (coltype) {
				case G_TYPE_STRING:
					gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
						n + FirstDataColumn,
						columns[n], -1);
					break;
				case G_TYPE_INT64:
					gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
						n + FirstDataColumn,
						strtoll(columns[n], NULL, 0), -1);
					break;
				case G_TYPE_UINT64:
					gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
						n + FirstDataColumn,
						strtoull(columns[n], NULL, 0), -1);
					break;
				case G_TYPE_DOUBLE:
					gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
						n + FirstDataColumn,
						strtod(columns[n], NULL), -1);
					break;
				default:
					fprintf(stderr, "%s(): Unsupported column-type %i\n",
						__func__, coltype);
			}
		}
		g_strfreev(columns);

		act = attributeset_get_next(&element, var->Attributes, ATTR_ITEM);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Pixmap Column Cell Layout Function                                  *
 ***********************************************************************/
/* This is a callback */

static void widget_tree_pixmap_column_cell_layout_function(
	GtkCellLayout *cell_layout, GtkCellRenderer *cell,
	GtkTreeModel *tree_model, GtkTreeIter *iter, GtkTreeView *treeview)
{
	gchar            *icon_name;
	gchar            *stock_id;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	gtk_tree_model_get(tree_model, iter, ColumnStockId, &stock_id,
		ColumnIconName, &icon_name, -1);

	if (stock_id != NULL) {
#ifdef DEBUG_CONTENT
		fprintf(stderr, "%s(): This row has a stock_id: '%s'\n",
			__func__, stock_id);
#endif
		g_object_set(G_OBJECT(cell), "stock-id", stock_id, NULL);
		g_object_set(G_OBJECT(cell), "icon-name", NULL, NULL);
	} else if (icon_name != NULL) {
#ifdef DEBUG_CONTENT
		fprintf(stderr, "%s(): This row has an icon_name: '%s'\n",
			__func__, icon_name);
#endif
		g_object_set(G_OBJECT(cell), "stock-id", NULL, NULL);
		g_object_set(G_OBJECT(cell), "icon-name", icon_name, NULL);
	} else {
#ifdef DEBUG_CONTENT
		fprintf(stderr, "%s(): This row has no icon set.\n", __func__);
#endif
		g_object_set(G_OBJECT(cell), "stock-id", NULL, NULL);
		g_object_set(G_OBJECT(cell), "icon-name", NULL, NULL);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Changed Callback                                                    *
 ***********************************************************************/

gboolean widget_tree_changed_callback(GtkTreeSelection *treeselection,
	variable *var)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): treeselection=%p var->Widget=%p\n", __func__,
		treeselection, var->Widget);
#endif

	/* Pass the correct var->Widget which will be the GtkTreeView */
	on_any_widget_changed_event(var->Widget, var->Attributes);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return TRUE;
}

/***********************************************************************
 * Natural Compare                                                     *
 ***********************************************************************/

gint widget_tree_natcmp(GtkTreeModel *model, GtkTreeIter *a,
	GtkTreeIter *b, gpointer user_data)
{
	return _widget_tree_natcmp(model, a, b, user_data, TRUE);
}

gint widget_tree_natcasecmp(GtkTreeModel *model, GtkTreeIter *a,
	GtkTreeIter *b, gpointer user_data)
{
	return _widget_tree_natcmp(model, a, b, user_data, FALSE);
}

static gint _widget_tree_natcmp(GtkTreeModel *model, GtkTreeIter *a,
	GtkTreeIter *b, gpointer user_data, gint sensitive)
{
	gchar            *r1 = NULL;
	gchar            *r2 = NULL;
	gint              retval;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	gtk_tree_model_get(model, a, (gint)user_data, &r1, -1);
	gtk_tree_model_get(model, b, (gint)user_data, &r2, -1);

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): r1=\"%s\" r2=\"%s\"\n", __func__, r1, r2);
#endif

	retval = strnatcmp(r1, r2, sensitive);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return retval;
}

#endif
