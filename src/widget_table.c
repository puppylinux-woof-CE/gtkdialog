/*
 * widget_table.c: 
 * Gtkdialog - A small utility for fast and easy GUI building.
 * Copyright (C) 2003-2007  László Pere <pipas@linux.pte.hu>
 * Copyright (C) 2011 Thunor <thunorsif@hotmail.com>
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
#include "config.h"
#include "gtkdialog.h"
#include "attributes.h"
#include "automaton.h"
#include "widgets.h"
#include "signals.h"
#include "tag_attributes.h"

/* Defines */
//#define DEBUG_CONTENT
//#define DEBUG_TRANSITS

/* Local function prototypes, located at file bottom */
static void widget_table_input_by_command(variable *var, char *filename,
	gint command_or_file);
static void widget_table_input_by_file(variable *var, char *filename);
static void widget_table_input_by_items(variable *var);
gboolean widget_table_click_column_callback(GtkWidget *widget,
	gint column, variable *var);
gint widget_table_natcmp(GtkCList *clist, gconstpointer ptr1,
	gconstpointer ptr2);
gint widget_table_natcasecmp(GtkCList *clist, gconstpointer ptr1,
	gconstpointer ptr2);
gint _widget_table_natcmp(GtkCList *clist, gconstpointer ptr1,
	gconstpointer ptr2, gint sensitive);
static gint strnatcmp(gchar *c1, gchar *c2, gint sensitive);

/* Notes: */

/***********************************************************************
 * Clear                                                               *
 ***********************************************************************/

void widget_table_clear(variable *var)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	gtk_clist_clear(GTK_CLIST(var->Widget));

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Create                                                              *
 ***********************************************************************/
GtkWidget *widget_table_create(
	AttributeSet *Attr, tag_attr *attr, gint Type)
{
	GList            *element;
	GtkWidget        *widget;
	gchar            *value;
	gint              column;
	gint              sort_function;
	list_t           *sliced;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (attributeset_is_avail(Attr, ATTR_LABEL)) {
		sliced = linecutter(g_strdup(attributeset_get_first(
			&element, Attr, ATTR_LABEL)), '|');
		widget = gtk_clist_new_with_titles(sliced->n_lines,
			sliced->line);
		if (sliced) list_t_free(sliced);	/* Free linecutter memory */
	} else {
		widget = gtk_clist_new(1);	/* 1 column */
	}

	if (attr) {
		/* Get sort-function (custom) */
		if ((value = get_tag_attribute(attr, "sort-function"))) {
			sort_function = atoi(value);
			if (sort_function == 1) {
				gtk_clist_set_compare_func(GTK_CLIST(widget), widget_table_natcmp);
			} else if (sort_function == 2) {
				gtk_clist_set_compare_func(GTK_CLIST(widget), widget_table_natcasecmp);
			}
		}
		/* Get sort-type (auto-sort will require this preset) */
		if ((value = get_tag_attribute(attr, "sort-type"))) {
			gtk_clist_set_sort_type(GTK_CLIST(widget), atoi(value));
		}
		/* Get sort-column (custom) */
		if ((value = get_tag_attribute(attr, "sort-column"))) {
			gtk_clist_set_sort_column(GTK_CLIST(widget), atoi(value));
		}
		/* Get auto-sort (custom) */
		if ((value = get_tag_attribute(attr, "auto-sort")) &&
			((strcasecmp(value, "true") == 0) || (strcasecmp(value, "yes") == 0) ||
			(atoi(value) == 1))) {
			gtk_clist_set_auto_sort(GTK_CLIST(widget), TRUE);
		} else {
			gtk_clist_set_auto_sort(GTK_CLIST(widget), FALSE);
		}
		/* Get column-header-active (custom) */
		if ((value = get_tag_attribute(attr, "column-header-active"))) {
			sliced = linecutter(g_strdup(value), '|');
			for (column = 0; column < sliced->n_lines; column++) {
				if ((strcasecmp(sliced->line[column], "true") == 0) ||
					(strcasecmp(sliced->line[column], "yes") == 0) ||
					(atoi(sliced->line[column]) == 1)) {
					gtk_clist_column_title_active(GTK_CLIST(widget), column);
				} else {
					gtk_clist_column_title_passive(GTK_CLIST(widget), column);
				}
			}
			if (sliced) list_t_free(sliced);	/* Free linecutter memory */
		}
		/* Get column-visible (custom) */
		if ((value = get_tag_attribute(attr, "column-visible"))) {
			sliced = linecutter(g_strdup(value), '|');
			for (column = 0; column < sliced->n_lines; column++) {
				if ((strcasecmp(sliced->line[column], "true") == 0) ||
					(strcasecmp(sliced->line[column], "yes") == 0) ||
					(atoi(sliced->line[column]) == 1)) {
					gtk_clist_set_column_visibility(GTK_CLIST(widget),
						column, TRUE);
				} else {
					gtk_clist_set_column_visibility(GTK_CLIST(widget),
						column, FALSE);
				}
			}
			if (sliced) list_t_free(sliced);	/* Free linecutter memory */
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

gchar *widget_table_envvar_all_construct(variable *var)
{
	gchar            *line;
	gchar            *string;
	gchar            *text;
	gchar            *value;
	gint              column = 0;
	gint              retval;
	gint              row = 0;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* Which column should we export */
	if (var->widget_tag_attr) {
		/* Get exported-column */
		if ((value = get_tag_attribute(var->widget_tag_attr, "exported-column")))
			column = atoi(value);
	}
	/* Where's the GtkCList row count? It's not such a problem as
	 * gtk_clist_get_text() returns 0 if it's not available at which
	 * point we'll stop */
	line = g_strdup_printf("%s_ALL=\"", var->Name);
	retval = gtk_clist_get_text(GTK_CLIST(var->Widget), row, column, &string);
	while (retval) {
		if (row == 0) {
			text = g_strconcat(line, "'", string, "'", NULL);
		} else {
			text = g_strconcat(line, " '", string, "'", NULL);
		}
		g_free(line);
		line = text;
		row++;
		retval = gtk_clist_get_text(GTK_CLIST(var->Widget), row, column, &string);
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

gchar *widget_table_envvar_construct(GtkWidget *widget)
{
	gchar            *line;
	gchar            *string;
	gchar            *text;
	gchar            *value;
	gint              column = 0;
	gint              count;
	gint              initialrow;
	gint              row;
	gint              selectionmode = GTK_SELECTION_SINGLE;
	variable         *var = find_variable_by_widget(widget);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (var->widget_tag_attr) {
		/* Get current selection-mode (there's no function to do this) */
		if ((value = get_tag_attribute(var->widget_tag_attr, "selection-mode")))
			selectionmode = atoi(value);
		/* Get exported-column */
		if ((value = get_tag_attribute(var->widget_tag_attr, "exported-column")))
			column = atoi(value);
	}

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s:() widget=%p selectionmode=%i column=%i\n",
		__func__, widget, selectionmode, column);
#endif

	if (selectionmode == GTK_SELECTION_NONE) {
		/* The API says that this is OK but a critical error gets dumped
		 * to the terminal and it doesn't actually prevent selection so
		 * it's not a usable selection mode */
		string = g_strdup("");	/* Nothing is selected */
	} else if (selectionmode == GTK_SELECTION_MULTIPLE) {
		initialrow = TRUE;
		line = g_strdup("");
		for (count = 0; count < g_list_length(GTK_CLIST(widget)->selection); count++) {
			row = (gint)g_list_nth_data(GTK_CLIST(widget)->selection, count);
			gtk_clist_get_text(GTK_CLIST(widget), row, column, &string);
			if (initialrow) {
				text = g_strconcat(line, string, NULL);
				initialrow = FALSE;
			} else {
				text = g_strconcat(line, "\n", string, NULL);
			}
			g_free(line);
			line = text;
		}
		string = line;
	} else {
		/* Default GTK_SELECTION_SINGLE and GTK_SELECTION_BROWSE.
		 * 
		 * There does not appear to be a way to get the selected item(s)
		 * outside of the select-row signal callback but I found this
		 * recommended technique from here:
		 * https://mail.gnome.org/archives/gtk-app-devel-list/1999-April/msg00033.html */
		if (g_list_length(GTK_CLIST(widget)->selection)) {
			row = (gint)g_list_nth_data(GTK_CLIST(widget)->selection, 0);
			gtk_clist_get_text(GTK_CLIST(widget), row, column, &value);
			string = g_strdup(value);
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

void widget_table_fileselect(
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
void widget_table_refresh(variable *var)
{
	GList            *element;
	gchar            *act;
	gchar            *value;
	gint              selected_row;
	gint              initialised = FALSE;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* Get initialised state of widget */
	if (g_object_get_data(G_OBJECT(var->Widget), "initialised") != NULL)
		initialised = (gint)g_object_get_data(G_OBJECT(var->Widget), "initialised");

	/* The <input> tag... */
	act = attributeset_get_first(&element, var->Attributes, ATTR_INPUT);
	while (act) {
		if (input_is_shell_command(act))
			widget_table_input_by_command(var, act + 8, TRUE);
		/* input file stock = "File:", input file = "File:/path/to/file" */
		if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5)
			widget_table_input_by_file(var, act + 5);
		act = attributeset_get_next(&element, var->Attributes, ATTR_INPUT);
	}

	/* The <item> tags... */
	if (attributeset_is_avail(var->Attributes, ATTR_ITEM))
		widget_table_input_by_items(var);

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
		g_signal_connect(G_OBJECT(var->Widget), "select-row",
			G_CALLBACK(on_any_widget_select_row_event), (gpointer)var->Attributes);
		g_signal_connect(G_OBJECT(var->Widget), "click-column",
			G_CALLBACK(widget_table_click_column_callback), (gpointer)var);

	}

	if (var->widget_tag_attr) {
		/* Get columns-autosize (custom)	Redundant: Works weirdly on initialisation.
		if ((value = get_tag_attribute(var->widget_tag_attr, "columns-autosize")) &&
			((strcasecmp(value, "true") == 0) || (strcasecmp(value, "yes") == 0) ||
			(atoi(value) == 1))) {
			gtk_clist_columns_autosize(GTK_CLIST(var->Widget));
		} */
		/* Get selected-row (custom) */
		if ((value = get_tag_attribute(var->widget_tag_attr, "selected-row"))) {
			selected_row = atoi(value);
			if (selected_row >= 0)
				gtk_clist_select_row(GTK_CLIST(var->Widget), selected_row, 0);
		}
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Removeselected                                                      *
 ***********************************************************************/

void widget_table_removeselected(variable *var)
{
	gchar            *string;
	gchar            *value;
	gint              column = 0;
	gint              count;
	gint              row;
	gint              selectionmode = GTK_SELECTION_SINGLE;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (var->widget_tag_attr) {
		/* Get current selection-mode (there's no function to do this) */
		if ((value = get_tag_attribute(var->widget_tag_attr, "selection-mode")))
			selectionmode = atoi(value);
		/* Get exported-column */
		if ((value = get_tag_attribute(var->widget_tag_attr, "exported-column")))
			column = atoi(value);
	}

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s:() widget=%p selectionmode=%i column=%i\n",
		__func__, var->Widget, selectionmode, column);
#endif

	if (selectionmode == GTK_SELECTION_NONE) {
		/* Nothing to do */
	} else if (selectionmode == GTK_SELECTION_MULTIPLE) {
		/* I'm assuming that selection is updated on row removal so
		 * it's likely not a good idea to iterate in a for loop */
		count = g_list_length(GTK_CLIST(var->Widget)->selection);
		while (count) {
			row = (gint)g_list_nth_data(GTK_CLIST(var->Widget)->selection, 0);
			gtk_clist_remove(GTK_CLIST(var->Widget), row);
			count = g_list_length(GTK_CLIST(var->Widget)->selection);
		}
	} else {
		/* Default GTK_SELECTION_SINGLE and GTK_SELECTION_BROWSE.
		 * 
		 * There does not appear to be a way to get the selected item(s)
		 * outside of the select-row signal callback but I found this
		 * recommended technique from here:
		 * https://mail.gnome.org/archives/gtk-app-devel-list/1999-April/msg00033.html */
		if (g_list_length(GTK_CLIST(var->Widget)->selection)) {
			row = (gint)g_list_nth_data(GTK_CLIST(var->Widget)->selection, 0);
			gtk_clist_remove(GTK_CLIST(var->Widget), row);
		}
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Save                                                                *
 ***********************************************************************/

void widget_table_save(variable *var)
{
	FILE             *outfile;
	GList            *element;
	gchar            *act;
	gchar            *filename = NULL;
	gchar            *string;
	gchar            *value;
	gint              column = 0;
	gint              retval;
	gint              row = 0;

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

			/* Which column should we export */
			if (var->widget_tag_attr) {
				/* Get exported-column */
				if ((value = get_tag_attribute(var->widget_tag_attr, "exported-column")))
					column = atoi(value);
			}
			/* Where's the GtkCList row count? It's not such a problem as
			 * gtk_clist_get_text() returns 0 if it's not available at which
			 * point we'll stop */
			retval = gtk_clist_get_text(GTK_CLIST(var->Widget), row, column, &string);
			while (retval) {
				if (row == 0) {
					fprintf(outfile, "%s", string);
				} else {
					fprintf(outfile, "\n%s", string);
				}
				row++;
				retval = gtk_clist_get_text(GTK_CLIST(var->Widget), row, column, &string);
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
 * Input by Command                                                    *
 ***********************************************************************/

static void widget_table_input_by_command(variable *var, char *filename,
	gint command_or_file)
{
	FILE             *infile;
	gchar             line[512];
	gint              count;
	list_t           *sliced;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (command_or_file) {
		infile = widget_opencommand(filename);
	} else {
		infile = fopen(filename, "r");
	}

	/* Opening pipe for reading... */
	if (infile) {
		/* Read the file one line at a time (trailing [CR]LFs are read too) */
		while (fgets(line, 512, infile) != NULL) {
			/* Enforce end of string in case of max chars read */
			line[512 - 1] = 0;
			/* Remove the trailing [CR]LFs */
			for (count = strlen(line) - 1; count >= 0; count--)
				if (line[count] == 13 || line[count] == 10) line[count] = 0;
			sliced = linecutter(g_strdup(line), '|');
			gtk_clist_append(GTK_CLIST(var->Widget), sliced->line);
			if (sliced) list_t_free(sliced);	/* Free linecutter memory */
		}
		/* Close the file */
		pclose(infile);
	} else {
		fprintf(stderr, "%s(): Couldn't open '%s' for reading.\n", __func__,
			filename);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by File                                                       *
 ***********************************************************************/

static void widget_table_input_by_file(variable *var, char *filename)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_table_input_by_command(var, filename, FALSE);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by Items                                                      *
 ***********************************************************************/

static void widget_table_input_by_items(variable *var)
{
	GList            *element;
	gchar            *text;
	list_t           *sliced;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	g_assert(var->Attributes != NULL && var->Widget != NULL);

	text = attributeset_get_first(&element, var->Attributes, ATTR_ITEM);
	while (text != NULL) {
		sliced = linecutter(g_strdup(text), '|');
		gtk_clist_append(GTK_CLIST(var->Widget), sliced->line);
		if (sliced) list_t_free(sliced);	/* Free linecutter memory */
		text = attributeset_get_next(&element, var->Attributes, ATTR_ITEM);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Click Column Callback                                               *
 ***********************************************************************/
/* Table Widget Behaviour
 * ----------------------
 * Assuming that the default sort direction is ascending:
 * 
 * Click column 0 and it'll sort ascending.
 * Click column 1 and it'll sort ascending.
 * Click column 1 and it'll sort descending having flipped.
 * Click column 0 and it'll sort descending.
 * Click column 1 and it'll sort descending.
 * 
 * Tree Widget Behaviour
 * ---------------------
 * Assuming that the default sort direction is ascending:
 * 
 * Click column 0 and it'll sort ascending.
 * Click column 1 and it'll sort ascending.
 * Click column 1 and it'll sort descending having flipped.
 * Click column 0 and it'll sort ascending.
 * Click column 1 and it'll sort ascending.
 * 
 * A descending column will not be in that same state when it is clicked
 * at a later time therefore tree defaults to ascending */

gboolean widget_table_click_column_callback(GtkWidget *widget,
	gint column, variable *var)
{
	gint              last_column = -1;
	gint              sort_type;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* Set sort column to the clicked column */
	gtk_clist_set_sort_column(GTK_CLIST(widget), column);

	/* Get last recorded column if it exists */
	if (g_object_get_data(G_OBJECT(widget), "last-column") != NULL) {
		last_column = (gint)g_object_get_data(G_OBJECT(widget), "last-column");
		last_column--;
	}

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): column=%i last-column=%i\n", __func__,
		column, last_column);
#endif

	/* If last recorded column matches column then flip sort direction */
	if (last_column == column) {
		/* Get sort-type (direction) and flip it */
		g_object_get(G_OBJECT(widget), "sort-type", &sort_type, NULL);
		sort_type = 1 - sort_type;
		gtk_clist_set_sort_type(GTK_CLIST(widget), sort_type);
	}

	/* Store "last-column" as a piece of widget data (recreated if exists) */
	/* Warning: Storing zero kills the piece of data so we have to
	 * maintain it with +1 on set, -1 on get */
	column++;
	g_object_set_data(G_OBJECT(widget), "last-column", (gpointer)column);

	/* Sit back and be amazed */
	gtk_clist_sort(GTK_CLIST(widget));

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return TRUE;
}

/***********************************************************************
 * Natural Compare                                                     *
 ***********************************************************************/
/* I found a useful example at:
 * 
 *   https://mail.gnome.org/archives/gtk-list/2000-April/msg00234.html
 * 
 * which explained how to get at the text in the rows */

gint widget_table_natcmp(GtkCList *clist, gconstpointer ptr1,
	gconstpointer ptr2)
{
	return _widget_table_natcmp(clist, ptr1, ptr2, TRUE);
}

gint widget_table_natcasecmp(GtkCList *clist, gconstpointer ptr1,
	gconstpointer ptr2)
{
	return _widget_table_natcmp(clist, ptr1, ptr2, FALSE);
}

gint _widget_table_natcmp(GtkCList *clist, gconstpointer ptr1,
	gconstpointer ptr2, gint sensitive)
{
	const GtkCListRow *row1 = (const GtkCListRow *) ptr1;
	const GtkCListRow *row2 = (const GtkCListRow *) ptr2;
	gchar            *r1 = NULL;
	gchar            *r2 = NULL;
	gint              retval;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	r1 = GTK_CELL_TEXT(row1->cell[clist->sort_column])->text;
	r2 = GTK_CELL_TEXT(row2->cell[clist->sort_column])->text;

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): r1=\"%s\" r2=\"%s\"\n", __func__, r1, r2);
#endif

	retval = strnatcmp(r1, r2, sensitive);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return retval;
}

/***********************************************************************
 * strnatcmp                                                           *
 ***********************************************************************/

static gint strnatcmp(gchar *c1, gchar *c2, gint sensitive)
{
	gint              c1val;
	gint              c2val;
	gint              retval;

	if (c1 == c2) {		/* Deals with both NULL, both empty, both equal */
		retval = 0;
	} else if (!c1) {
		retval = -1;
	} else if (!c2) {
		retval = 1;
	} else if (!*c1) {
		retval = -1;
	} else if (!*c2) {
		retval = 1;
	} else {
		/* There's definitely something different to compare */
		while (TRUE) {

			/* Ignore whitespace */
			while ((*c1 == ' ' || *c1 == '\t') && *(c1 + 1)) c1++;
			while ((*c2 == ' ' || *c2 == '\t') && *(c2 + 1)) c2++;

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): c1='%s' c2='%s'\n", __func__, c1, c2);
#endif

			/* Evaluate data being pointed to */
			if ((*c1 >= '0' && *c1 <= '9')) {
				/* Evaluate consecutive numbers */
				c1val = 100;
				while (*c1 >= '0' && *c1 <= '9') {
					/* This is Unicode safe */
					c1val = c1val * 10 + *c1 - '0';
					*c1++;
				}
			} else {
				/* Evaluate single chars */
				if (sensitive) {
					c1val = *c1;
				} else {
					/* tolower() determines what is upper
					 * and lower case dependent upon locale */
					c1val = tolower(*c1);
				}
				*c1++;
			}
			if ((*c2 >= '0' && *c2 <= '9')) {
				/* Evaluate consecutive numbers */
				c2val = 100;
				while (*c2 >= '0' && *c2 <= '9') {
					/* This is Unicode safe */
					c2val = c2val * 10 + *c2 - '0';
					*c2++;
				}
			} else {
				/* Evaluate single chars */
				if (sensitive) {
					c2val = *c2;
				} else {
					/* tolower() determines what is upper
					 * and lower case dependent upon locale */
					c2val = tolower(*c2);
				}
				*c2++;
			}

			/* At this point both c1 and c2 will be pointing to the next
			 * character to process which could be the terminating zero */

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): c1val=%i c2val=%i c1='%s' c2='%s'\n", __func__, c1val, c2val, c1, c2);
#endif

			/* Not equal? */
			if (c1val < c2val) {
				retval = -1;
				break;
			} else if (c1val > c2val) {
				retval = 1;
				break;
			}

			/* End of data? */
			if (!*c1 && !*c2) {
				retval = 0;
				break;
			} else if (!*c1) {
				retval = -1;
				break;
			} else if (!*c2) {
				retval = 1;
				break;
			}
		}
	}

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): retval=%i\n", __func__, retval);
#endif

	return retval;
}
