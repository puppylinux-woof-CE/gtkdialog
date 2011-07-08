/*
 * widgets.c: Widget manipulation functions
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

/* 
**
** $Id: widgets.c,v 1.2 2004/11/25 19:11:12 pipas Exp pipas $
** $Log: widgets.c,v $
** Revision 1.2  2004/11/25 19:11:12  pipas
** Small enhancements.
**
** Revision 1.1  2004/11/18 16:47:05  root
** Initial revision
**
 */

#include <gtk/gtk.h>
#include "widgets.h"
#include "stringman.h"

#undef DEBUG
#undef WARNING
#include "macros.h"

extern gboolean option_no_warning;

static void 
fill_list_by_items(AttributeSet *Attr, 
		GtkWidget * list)
{
	GtkWidget *item;
	char      *text;
	g_assert(Attr != NULL && list != NULL);
	
	text = attributeset_get_first(Attr, ATTR_ITEM);
	if (text == NULL)
		return;
	
	while (text != NULL) {
		item = gtk_list_item_new_with_label(text);
		gtk_object_set_user_data(GTK_OBJECT(item), (gpointer) text);
		gtk_container_add(GTK_CONTAINER(list), item);
next_line:	text = attributeset_get_next(Attr, ATTR_ITEM);
	}

	gtk_list_select_item(GTK_LIST(list), 0);
}

static void 
fill_clist_by_items(AttributeSet *Attr,
		         GtkWidget *list,
			 int separator)
{
	char *text;
	list_t *sliced;

	g_assert(Attr != NULL && list != NULL);
	
	text = attributeset_get_first(Attr, ATTR_ITEM);
	if (text == NULL)
		return;
	
	while (text != NULL){
		sliced = linecutter(text, separator);
		gtk_clist_append(GTK_CLIST(list), sliced->line);
next_line:	text = attributeset_get_next(Attr, ATTR_ITEM);
	}

	gtk_clist_select_row(GTK_CLIST(list), 0, 0);
}


static
void fill_combo_by_items(AttributeSet *Attr,
		         GtkWidget *combo)
{
	GList *glist = NULL;
	char *text;
	
	g_assert(Attr != NULL && combo != NULL);
	text = attributeset_get_first(Attr, ATTR_ITEM);
	if (text == NULL)
		return;
	
	while (text != NULL) {
		glist = g_list_append(glist, text);
next_line:	text = attributeset_get_next(Attr, ATTR_ITEM);
	}
	
	gtk_combo_set_popdown_strings(GTK_COMBO(combo), glist);
}

static
void fill_comboboxtext_by_items(AttributeSet *Attr,
	GtkWidget *comboboxtext)
{
	gchar *text;

	g_assert(Attr != NULL && comboboxtext != NULL);
	text = attributeset_get_first(Attr, ATTR_ITEM);
	while (text) {
		gtk_combo_box_append_text(GTK_COMBO_BOX(comboboxtext), text);
		text = attributeset_get_next(Attr, ATTR_ITEM);
	}
}

char *
widget_get_text_value(
		GtkWidget *widget, 
		int type)
{
	GtkTextBuffer    *text_buffer;
	GtkTextIter       start, end;		
	GList            *item;
	GtkTreeSelection *selection;
	GtkTreeModel     *model;
	GtkTreeIter       iter;
	gchar            *string;
	gint              n;
	gchar            *tmp;
	gint              selectionmode, initialrow, column;
	GList            *selectedrows, *row;
	GtkTreePath      *path;
	gchar            *line;

#ifdef DEBUG
	g_message("%s(): type: %08x\n", __func__, type);
#endif
	if (widget == NULL) {
		g_warning("%s(): NULL Widget", __func__);
		return ("NULL WIDGET");
	}

	switch (type) {
#if GTK_CHECK_VERSION(2,4,0)
		case WIDGET_CHOOSER:
			return gtk_file_chooser_get_filename(
					GTK_FILE_CHOOSER(widget));
			break;
#endif
		case WIDGET_ENTRY:
			return (char *) gtk_entry_get_text(GTK_ENTRY(widget));
			break;
			
		case WIDGET_COMBO:
			return (char *) gtk_entry_get_text(GTK_ENTRY(GTK_COMBO(widget)->entry));
			break;
		
		case WIDGET_CHECKBOX:
			if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
				return g_strdup("true");
			else
				return g_strdup("false");
			break;
			
		case WIDGET_RADIO:
			if (gtk_toggle_button_get_active
			    (GTK_TOGGLE_BUTTON(widget)))
				return g_strdup("true");
			else
				return g_strdup("false");
			break;
			
		case WIDGET_LIST:
			item = GTK_LIST(widget)->selection;
			if (item != NULL)
				return (gtk_object_get_user_data(item->data));
			else
				return g_strdup("");
			break;
			
		case WIDGET_TABLE:
			/*
			 ** I simply could not find a function to get the selected item,
			 ** so managed the selected item by callback function.
			 */
			return NULL;
			break;
			
		case WIDGET_EDIT:
			text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(widget));
			gtk_text_buffer_get_start_iter(text_buffer, &start);
			gtk_text_buffer_get_end_iter(text_buffer, &end);
			return gtk_text_buffer_get_text(text_buffer, &start, &end, TRUE);
			break;
			
		case WIDGET_TREE:
			/*
			 * Searching the selected row.
			 */
			selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(widget));
			selectionmode = gtk_tree_selection_get_mode(selection);
#ifdef DEBUG
			fprintf(stderr, "%s: widget=%p selectionmode=%i\n", __func__,
				widget, selectionmode);
			fprintf(stderr, "%s: widget=%p selected row count=%i\n", __func__,
				widget, gtk_tree_selection_count_selected_rows(selection));
#endif
			if (selectionmode == GTK_SELECTION_NONE) {
				return g_strdup("");	/* Nothing is selected */
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

				/* Which column should we print? */
				tmp = g_object_get_data(G_OBJECT(widget), "exported_column");
				if (tmp) {
					column = atoi(tmp) + FirstDataColumn;
				} else {
					column = FirstDataColumn;
				}

				line = g_strdup("");
				if (gtk_tree_selection_count_selected_rows(selection)) {
					selectedrows = gtk_tree_selection_get_selected_rows(selection, &model);
					initialrow = TRUE;
					row = selectedrows;
					while (row) {
						path = (GtkTreePath*)(row->data);
						gtk_tree_model_get_iter(model, &iter, path);
						gtk_tree_model_get(model, &iter, column, &string, -1);
						if (initialrow) {
							//tmp = g_strconcat(line, "'", string, "'", NULL);
							tmp = g_strconcat(line, string, NULL);
							initialrow = FALSE;
						} else {
							//tmp = g_strconcat(line, " '", string, "'", NULL);
							tmp = g_strconcat(line, "\n", string, NULL);
						}
						g_free(line);
						line = tmp;
						g_free(string);
						row = row->next;
					}
					/* The GtkTreePaths and the GList should be freed now */
					g_list_foreach(selectedrows, (GFunc)gtk_tree_path_free, NULL);
					g_list_free(selectedrows);
				}
#ifdef DEBUG
				fprintf(stderr, "%s: line=%s\n", __func__, line);
#endif
				return line;
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
				 if (gtk_tree_store_iter_is_valid(GTK_TREE_STORE(model), &iter)){
					/*
					 * Let's find the first column storing text type data.
					 */
					tmp = g_object_get_data(G_OBJECT(widget), "exported_column");
					if (tmp != 0)
						n = atoi(tmp) + FirstDataColumn;
					else
						n = FirstDataColumn;
					/*
					 * Returning the text from the selected row.
					 */
					gtk_tree_model_get(model, &iter, n, &string, -1);
					return string;
				}else{
					return g_strdup("");
				}	
			}
			break;
			
		case WIDGET_COMBOBOXENTRY:
		case WIDGET_COMBOBOXTEXT:
			string = gtk_combo_box_get_active_text(GTK_COMBO_BOX(widget));
			if (string == NULL)
				string = g_strdup("");
			return string;
			break;
		
		default:
			return NULL;
	}
	g_error("%s(): this should not be reached", __func__);
}

static
void fill_label_by_file(GtkWidget * widget, char *filename)
{
	struct stat st;
	char *filebuffer;
	int infile, result;

	if (stat(filename, &st) != 0) {
		if (!option_no_warning)
			g_warning("%s(): Couldn't stat '%s'.", 
					__func__, filename);
		return;
	}

	filebuffer = g_malloc(st.st_size + 1);
	infile = open(filename, O_RDONLY);
	if (infile == -1) {
		if (!option_no_warning)
			g_warning("%s(): Could't open '%s' for reading.", 
					__func__, filename);
		return;
	}

	result = read(infile, filebuffer, st.st_size);
	filebuffer[st.st_size] = '\0';
	close(infile);

	gtk_label_set_text(GTK_LABEL(widget), filebuffer);
	return;
}

static
void save_edit_to_file(GtkWidget * widget, char *filename)
{
	int outfile, result;
	GtkTextBuffer *buffer;
	GtkTextIter start, end;
	gchar *text;
#ifdef DEBUG
	fprintf(stderr, "%s() Saving to '%s'.\n", __func__, filename);
	fflush(stderr);
#endif
	// FIXME: this is stupid, I really should correct this
	//
	if (strncasecmp(filename, "File: ", 6) == 0)
		filename += 6;
	if (strncasecmp(filename, "File:", 5) == 0)
		filename += 5;


	outfile = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (outfile == -1) {
		fprintf(stderr, "%s(): Could't open '%s' for writing.\n",
			__func__, filename);
		return;
	}
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(widget));
	gtk_text_buffer_get_start_iter(buffer, &start);
	gtk_text_buffer_get_end_iter(buffer, &end);
	text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
	result = write(outfile, text, strlen(text));
	close(outfile);
}


static
void fill_edit_by_file(GtkWidget * widget, char *filename)
{
	struct stat st;
	char *filebuffer;
	int infile, result;
	GtkTextBuffer *buffer;
	char *message;	

	// FIXME: this is stupid, I really should correct this
	//
	if (strncasecmp(filename, "File: ", 6) == 0)
		filename += 6;
	if (strncasecmp(filename, "File:", 5) == 0)
		filename += 5;

	if (stat(filename, &st) != 0) {
		message = g_strdup_printf("Could not stat '%s'.", filename);
		yywarning(message);
		g_free(message);
		return;
	}

	filebuffer = g_malloc(st.st_size);
	infile = open(filename, O_RDONLY);
	if (infile == -1) {
		message = g_strdup_printf("Could not open '%s' for reading.", filename);
		yywarning(message);
		g_free(message);
		return;
	}

	result = read(infile, filebuffer, st.st_size);
	close(infile);

	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(widget));
	gtk_text_buffer_set_text(buffer, filebuffer, st.st_size);
}

static
void fill_comboboxtext_by_file(GtkWidget *widget, char *filename)
{
	FILE *infile;
	char line[512];
	int count;

	if (infile = fopen(filename, "r")) {
		/* Read the file one line at a time (trailing [CR]LFs are read too) */
		while (fgets(line, 512, infile)) {
			/* Remove the trailing [CR]LFs */
			for (count = strlen(line) - 1; count >= 0; count--)
				if (line[count] == 13 || line[count] == 10) line[count] = 0;
			gtk_combo_box_append_text(GTK_COMBO_BOX(widget), line);
		}
		/* Close the file */
		fclose(infile);
	} else {
		if (!option_no_warning)
			g_warning("%s(): Could't open '%s' for reading.", 
				__func__, filename);
	}

}

int widget_label_refresh(variable * var)
{
	char *act;

	if (var == NULL || var->Attributes == NULL)
		return FALSE;

	act = attributeset_get_first(var->Attributes, ATTR_INPUT);
	while (act != NULL) {
		if (strncasecmp(act, "file:", 5) == 0)
			fill_label_by_file(var->Widget, act + 5);
		if (input_is_shell_command(act))
			fill_label_by_command(var->Widget, act + 8);
next_item:
		act = attributeset_get_next(var->Attributes, ATTR_INPUT);
	}

	return 0;
}

int widget_edit_refresh(variable * var)
{
	char *act;
	if (var == NULL || var->Attributes == NULL)
		return FALSE;

	act = attributeset_get_first(var->Attributes, ATTR_INPUT);
	while (act != NULL) {
		fill_edit_by_file(var->Widget, act);
		act = attributeset_get_next(var->Attributes, 
				ATTR_INPUT);
	}
}


void widget_edit_save(variable * var)
{
	char *filename;
#ifdef DEBUG
	fprintf(stderr, "%s(): Start.\n", __func__);
	fflush(stderr);
#endif
	g_assert(var != NULL);
	
	filename = attributeset_get_first(var->Attributes, ATTR_OUTPUT);
	if (filename == NULL){
		yywarning("Save activated but no output is given. "
			"Trying to save to the input file...");
		goto try_input;
	}

	while (filename != NULL) {
		save_edit_to_file(var->Widget, filename);
		filename = attributeset_get_next(var->Attributes, 
			ATTR_OUTPUT);
	}
	return;

	//
	// If there is no <output>, we try to use <input> file.
	//
try_input:
	filename = attributeset_get_first(var->Attributes, ATTR_INPUT);
	if (filename == NULL){
		yywarning("No input file either.");
		return;
	}
	save_edit_to_file(var->Widget, filename);
}

void save_comboboxtext_to_file(variable *var)
{
	FILE             *outfile;
	gchar            *act;
	gchar            *filename = NULL;
	GtkTreeModel     *model;
	GtkTreeIter       iter;
	gchar            *text;
	gint              index;

	/* Preferably we'll use the output file filename if available */
	act = attributeset_get_first(var->Attributes, ATTR_OUTPUT);
	while (act) {
		if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5) {
			filename = act + 5;
			break;
		}
		act = attributeset_get_next(var->Attributes, ATTR_OUTPUT);
	}

#if 0
	/* Thunor: I don't really like this behaviour so I'm disabling it */
	if (filename == NULL) {
		/* The output file filename isn't available but we can use
		 * the input file filename instead if available (it's the
		 * same method that the existing functions use) */
		act = attributeset_get_first(var->Attributes, ATTR_INPUT);
		while (act) {
			if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5) {
				filename = act + 5;
				break;
			}
			act = attributeset_get_next(var->Attributes, ATTR_INPUT);
		}
	}
#endif

#ifdef DEBUG
	fprintf(stderr, "%s: filename=%s\n", __func__, filename);
#endif

	/* If we have a valid filename then open it and dump the
	 * widget's data to it carefully not leaving a newline so
	 * that it can be read back in again */
	if (filename) {
		if ((outfile = fopen(filename, "w"))) {
			index = 0;
			/* The comboboxtext functions also manage the comboboxentry:
			 * save the entry if the active index is -1 and the entry
			 * isn't empty */
			if ((var->Type == WIDGET_COMBOBOXENTRY) &&
				(gtk_combo_box_get_active(GTK_COMBO_BOX(var->Widget)) == -1) &&
				(text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(var->Widget))) &&
				(strcmp(text, ""))) {
				fprintf(outfile, "%s", text);
				index++;
			}
			model = gtk_combo_box_get_model(GTK_COMBO_BOX(var->Widget));
			if (gtk_tree_model_get_iter_first(model, &iter)) {
				do {
					gtk_tree_model_get(model, &iter, 0, &text, -1);
					if (index) {
						fprintf(outfile, "\n%s", text);
					} else {
						fprintf(outfile, "%s", text);
						index++;
					}
					g_free(text);
				} while (gtk_tree_model_iter_next(model, &iter));
			}
			fclose(outfile);
		} else {
			fprintf(stderr, "%s(): Couldn't open '%s' for writing.\n",
				__func__, filename);
		}
	} else {
		yywarning("No output file directive found");
	}
}

void 
widget_entry_refresh(variable *var)
{
	char *act;
	
	g_assert(var != NULL);
	
#ifdef DEBUG
	g_message("%s(%p)", __func__, var);
#endif
	/*
	 ** The <input> tag... 
	 */
	act = attributeset_get_first(var->Attributes, ATTR_INPUT);
	while (act != NULL) {
		if (input_is_shell_command(act)) {
			fill_entry_by_command(var->Widget, act + 8);
			goto next_input;
		}
		
		fill_entry_by_command(var->Widget, act);
next_input:
		act = attributeset_get_next(var->Attributes, ATTR_INPUT);
	}

	if (attributeset_cmp_left
	    (var->Attributes, ATTR_VISIBLE, "disabled"))
		gtk_widget_set_sensitive(var->Widget, FALSE);
}

void widget_checkbox_refresh(variable * var)
{
	char *act;

	if (var == NULL || var->Attributes == NULL)
		return;
	/*
	 ** The <input> tag... 
	 */
	act = attributeset_get_first(var->Attributes, ATTR_INPUT);
	while (act != NULL) {
		if (input_is_shell_command(act))
			fill_checkbox_by_command(var->Widget, act + 8);
		act = attributeset_get_next(var->Attributes, ATTR_INPUT);
	}

	if (attributeset_cmp_left
	    (var->Attributes, ATTR_VISIBLE, "disabled"))
		gtk_widget_set_sensitive(var->Widget, FALSE);

}


void widget_list_refresh(variable * var)
{
	char *act;

	if (var == NULL || var->Attributes == NULL)
		return;
#ifdef DEBUG
	g_message("%s(): entering.", __func__);
#endif
	/* 
	 ** The <input> tag... 
	 */
	act = attributeset_get_first(var->Attributes, ATTR_INPUT);
	while (act != NULL) {
		if (input_is_shell_command(act))
			fill_list_by_command(var->Widget, act + 8);
		act = attributeset_get_next(var->Attributes, ATTR_INPUT);
	}			/*while */
	/*
	 ** The <item> tags...
	 */
	if (attributeset_is_avail(var->Attributes, ATTR_ITEM))
		fill_list_by_items(var->Attributes, var->Widget);

	if (attributeset_cmp_left
	    (var->Attributes, ATTR_VISIBLE, "disabled"))
		gtk_widget_set_sensitive(var->Widget, FALSE);

	gtk_widget_queue_draw(var->Widget);
}

/******************************************************************************
 * Handling TreeView widgets. The model always has the following columns:     *
 *   0) "pixbuf"     GdkPixbuf                                                *
 *   1) "icon-name"  gchararray                                               *
 *   2) "stock-id"   gchararray                                               *
 *                                                                            *
 * We create the TreeStore in the following function:                         *
 *   gtkdialog_tree_store_new                                                 *
 * We create the TreeView in:                                                 *
 *   create_tree_view                                                         *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/
void
fill_tree_model_by_items(
	GtkTreeModel  *tree_model,
	variable      *var)
{
	gchar        *act;
	gchar       **columns;
	gint          n, ncolumns;
	GType         coltype;
	GtkTreeIter   iter;
	gchar        *stock_name;
	gchar        *tagattr;

	PIP_DEBUG("tree_model: %p var: %p", tree_model, var);
	
	ncolumns = gtk_tree_model_get_n_columns(tree_model) - FirstDataColumn;
	
	act = attributeset_get_first(var->Attributes, ATTR_ITEM);
	while (act != NULL) {
		gtk_tree_store_append(GTK_TREE_STORE(tree_model), &iter, NULL);
		
		tagattr = attributeset_get_this_tagattr(var->Attributes, ATTR_ITEM, "stock");
		if (tagattr != NULL)
			gtk_tree_store_set(GTK_TREE_STORE(tree_model), &iter,
					ColumnStockId, tagattr,
					-1);

		tagattr = attributeset_get_this_tagattr(var->Attributes, ATTR_ITEM, "stock_id");
		if (tagattr != NULL)
			gtk_tree_store_set(GTK_TREE_STORE(tree_model), &iter,
					ColumnStockId, tagattr,
					-1);
		
		tagattr = attributeset_get_this_tagattr(var->Attributes, ATTR_ITEM, "icon");
		if (tagattr != NULL)
			gtk_tree_store_set(GTK_TREE_STORE(tree_model), &iter,
					ColumnIconName, tagattr,
					-1);
		
		tagattr = attributeset_get_this_tagattr(var->Attributes, ATTR_ITEM, "icon_name");
		if (tagattr != NULL)
			gtk_tree_store_set(GTK_TREE_STORE(tree_model), &iter,
					ColumnIconName, tagattr,
					-1);

		columns = g_strsplit(act, "|", 128);
		for (n = 0; columns[n] != NULL; ++n) {
			if (n >= ncolumns)
				break;
			g_strstrip(columns[n]);
			coltype = gtk_tree_model_get_column_type(tree_model, n + FirstDataColumn);
			
			switch (coltype) {
				case G_TYPE_STRING:
					gtk_tree_store_set(
						GTK_TREE_STORE(tree_model),
						&iter,
						n + FirstDataColumn, columns[n],
						-1);
					break;
				default:
					g_warning("%s(): Unhandled column type", __func__);
			}
		}
		g_strfreev(columns);

next_item:
		act = attributeset_get_next(var->Attributes, ATTR_ITEM);
	}
}

static void
fill_tree_view_by_command(
		GtkWidget     *tree_view, 
		GtkTreeModel  *tree_model, 
		const gchar   *command, 
		gint           stock_column, 
		gint           icon_column)
{
	FILE      *infile;
	char        oneline[512];
	gchar     **columns;
	gint        n, ncolumns;
	GType       coltype;
	GtkTreeIter iter;
	gint        hiddencolumns;


	PIP_DEBUG("tree_view: %p, command: '%s'", tree_view, command);

	infile = widget_opencommand(command);
	if (infile == NULL) {
		g_warning("%s(): command %s, %m", __func__, command);
		return;
	}

	
	ncolumns = gtk_tree_model_get_n_columns(tree_model) - FirstDataColumn;
	while (fgets(oneline, 512, infile) != NULL) {
		PIP_DEBUG("Line from pipe: '%s'", oneline);

		hiddencolumns = 0;
		g_strstrip(oneline);
		columns = g_strsplit(oneline, "|", 128);
		gtk_tree_store_append(GTK_TREE_STORE(tree_model), &iter, NULL);
		for (n = 0; columns[n] != NULL; ++n) {
			if (n - hiddencolumns >= ncolumns)
				break;
			g_strstrip(columns[n]);
			if (n == stock_column) {
				PIP_DEBUG("Stock: '%s'", columns[n]);
				gtk_tree_store_set(
					GTK_TREE_STORE(tree_model), &iter,
					ColumnStockId, columns[n],
						-1);
				++hiddencolumns;
				continue;
			}
			
			if (n == icon_column) {
				PIP_DEBUG("Icon: '%s'", columns[n]);
				gtk_tree_store_set(
					GTK_TREE_STORE(tree_model), &iter,
					ColumnIconName, columns[n],
						-1);
				++hiddencolumns;
				continue;
			}

			coltype = gtk_tree_model_get_column_type(
					tree_model, n + FirstDataColumn - 
					hiddencolumns);
			switch (coltype) {
				case G_TYPE_STRING:
					gtk_tree_store_set(
						GTK_TREE_STORE(tree_model),
						&iter,
						n + FirstDataColumn - 
						hiddencolumns, columns[n],
						-1);
					break;
				default:
					PIP_DEBUG("Unhandled column type.");
			}
		}
		g_strfreev(columns);
	}

	pclose(infile);
}

void 
widget_tree_refresh(variable *var)
{
	gchar        *act;
	GtkTreeModel *tree_model;
	
	if (var == NULL || var->Attributes == NULL)
		return;

	PIP_DEBUG("Refreshing variable %p.", var);

	g_return_if_fail(GTK_IS_TREE_VIEW(var->Widget));
	tree_model = gtk_tree_view_get_model(GTK_TREE_VIEW(var->Widget));
	g_return_if_fail(GTK_IS_TREE_STORE(tree_model));
	/*
	 * We drop all the lines here.
	 */
	gtk_tree_store_clear(GTK_TREE_STORE(tree_model));
	/*
	 * If the widget has an input tag (command, file, stc.) we load the
	 * lines from there.
	 */
	act = attributeset_get_first(var->Attributes, ATTR_INPUT);
	while (act != NULL) {
		gchar         *tmp;
		gint           stock_column = -1;
		gint           icon_column = -1;

		tmp = attributeset_get_this_tagattr(var->Attributes, ATTR_INPUT, "stock_column");
		if (tmp != NULL)
			stock_column = atoi(tmp);
		tmp = attributeset_get_this_tagattr(var->Attributes, ATTR_INPUT, "icon_column");
		if (tmp != NULL)
			icon_column = atoi(tmp);

		if (input_is_shell_command(act))
			fill_tree_view_by_command(var->Widget, tree_model, act + 8, stock_column, icon_column);
		else
			fill_tree_view_by_command(var->Widget, tree_model, act, stock_column, icon_column);
		act = attributeset_get_next(var->Attributes, ATTR_INPUT);
	}
	/*
	 * If there are items, we load them too.
	 */
	fill_tree_model_by_items(tree_model, var);
}




void 
widget_table_refresh(variable * var)
{
	char *act;
	if (var == NULL || var->Attributes == NULL)
		return;
	/*
	 ** The <input> tags.
	 */
	act = attributeset_get_first(var->Attributes, ATTR_INPUT);
	while (act != NULL) {
		if (input_is_shell_command(act))
			fill_table_by_command(var->Widget, act + 8);
		act = attributeset_get_next(var->Attributes, ATTR_INPUT);
	}

	if (attributeset_is_avail(var->Attributes, ATTR_ITEM))
		fill_clist_by_items(var->Attributes, var->Widget, '|');

	if (attributeset_cmp_left
	    (var->Attributes, ATTR_VISIBLE, "disabled"))
		gtk_widget_set_sensitive(var->Widget, FALSE);
}

void 
widget_combo_refresh(variable * var)
{
	if (var == NULL || var->Attributes == NULL)
		return;
	/*
	 ** The <item> tags
	 */
	if (attributeset_is_avail(var->Attributes, ATTR_ITEM))
		fill_combo_by_items(var->Attributes, var->Widget);

	if (attributeset_cmp_left
	    (var->Attributes, ATTR_VISIBLE, "disabled"))
		gtk_widget_set_sensitive(var->Widget, FALSE);
}

void widget_button_refresh(variable *var)
{
	gchar            *act;
	GList            *btnchildren = NULL;
	GList            *boxchildren = NULL;
	GList            *child;
	GdkPixbuf        *pixbuf;
	gint              width = -1, height = -1;

	if (var != NULL && var->Attributes != NULL) {

#ifdef DEBUG
		g_message("%s(): entering.", __func__);
#endif

		/* Thunor: Refresh functions are also called at start-up so this
		 * has to be taken into account to avoid duplicating code that
		 * already exists in the creation function. The way to do this
		 * is to simply check if the widget has been realized yet */
#if GTK_CHECK_VERSION(2,20,0)
		if ((gtk_widget_get_realized(var->Widget)))
#else
		if ((GTK_WIDGET_REALIZED(var->Widget)))
#endif
		{
			act = attributeset_get_first(var->Attributes, ATTR_INPUT);
			while (act != NULL) {
				/* input file stock = "File:", input file = "File:/path/to/file" */
				if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5) {
					btnchildren = gtk_container_get_children(GTK_CONTAINER(var->Widget));
					child = g_list_first(btnchildren);
					while (child) {
						if (GTK_IS_IMAGE(child->data)) {
							if (attributeset_is_avail(var->Attributes, ATTR_WIDTH))
								width = atoi(attributeset_get_first(var->Attributes, ATTR_WIDTH));
							if (attributeset_is_avail(var->Attributes, ATTR_HEIGHT))
								height = atoi(attributeset_get_first(var->Attributes, ATTR_HEIGHT));

							if (width == -1 && height == -1) {
								/* Handle unscaled images */
								gtk_image_set_from_file(GTK_IMAGE(child->data), find_pixmap(act + 5));
							} else {
								/* Handle scaled images */
								pixbuf = gdk_pixbuf_new_from_file_at_size(
									find_pixmap(act + 5), width, height, NULL);
								if (pixbuf) {
									gtk_image_set_from_pixbuf(GTK_IMAGE(child->data), pixbuf);
									/* pixbuf is no longer required and should be unreferenced */
									g_object_unref(pixbuf);
								} else {
									/* pixbuf is null (file not found) so by using this
									 * function gtk will substitute a broken image icon */
									gtk_image_set_from_file(GTK_IMAGE(child->data), "");
								}
							}
							break;
						} else if (GTK_IS_BOX(child->data)) {
							boxchildren = gtk_container_get_children(GTK_CONTAINER(child->data));
							child = g_list_first(boxchildren);
						} else {
							child = child->next;
						}
					}
					if (boxchildren) {
						g_list_free(boxchildren);
						boxchildren = NULL;
					}
					if (btnchildren) {
						g_list_free(btnchildren);
						btnchildren = NULL;
					}
				}
				act = attributeset_get_next(var->Attributes, ATTR_INPUT);
			}
		}
	}
}

void widget_pixmap_refresh(variable *var)
{
	gchar            *act;
	GdkPixbuf        *pixbuf;
	gint              width = -1, height = -1;

	if (var != NULL && var->Attributes != NULL) {

#ifdef DEBUG
		g_message("%s(): entering.", __func__);
#endif

		/* Thunor: Refresh functions are also called at start-up so this
		 * has to be taken into account to avoid duplicating code that
		 * already exists in the creation function. The way to do this
		 * is to simply check if the widget has been realized yet */
#if GTK_CHECK_VERSION(2,20,0)
		if ((gtk_widget_get_realized(var->Widget)))
#else
		if ((GTK_WIDGET_REALIZED(var->Widget)))
#endif
		{
			act = attributeset_get_first(var->Attributes, ATTR_INPUT);
			while (act != NULL) {
				/* input file stock = "File:", input file = "File:/path/to/file" */
				if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5) {
					if (attributeset_is_avail(var->Attributes, ATTR_WIDTH))
						width = atoi(attributeset_get_first(var->Attributes, ATTR_WIDTH));
					if (attributeset_is_avail(var->Attributes, ATTR_HEIGHT))
						height = atoi(attributeset_get_first(var->Attributes, ATTR_HEIGHT));

					if (width == -1 && height == -1) {
						/* Handle unscaled images */
						gtk_image_set_from_file(GTK_IMAGE(var->Widget), find_pixmap(act + 5));
					} else {
						/* Handle scaled images */
						pixbuf = gdk_pixbuf_new_from_file_at_size(
							find_pixmap(act + 5), width, height, NULL);
						if (pixbuf) {
							gtk_image_set_from_pixbuf(GTK_IMAGE(var->Widget), pixbuf);
							/* pixbuf is no longer required and should be unreferenced */
							g_object_unref(pixbuf);
						} else {
							/* pixbuf is null (file not found) so by using this
							 * function gtk will substitute a broken image icon */
							gtk_image_set_from_file(GTK_IMAGE(var->Widget), "");
						}
					}
				}
				act = attributeset_get_next(var->Attributes, ATTR_INPUT);
			}
		}
	}
}

void widget_comboboxtext_refresh(variable *var)
{
	char             *act;
	GtkTreeModel     *model;
	GtkTreeIter       iter;
	gint              handler_id_changed;
	gint              rowcount;
	gchar             oldselected[512];
	gchar             newselected[512];
	gchar            *string;
	gchar            *text;
	gint              index;
	gint              found;

	if (var != NULL && var->Attributes != NULL) {

#ifdef DEBUG
		g_message("%s(): entering.", __func__);
#endif

		/* We'll manage signals ourselves */
#if GTK_CHECK_VERSION(2,20,0)
		if ((gtk_widget_get_realized(var->Widget)))
#else
		if ((GTK_WIDGET_REALIZED(var->Widget)))
#endif
		{
			/* Block the signal handler */
			handler_id_changed = (gint)g_object_get_data(
				G_OBJECT(var->Widget), "handler_id_changed");
			g_signal_handler_block(var->Widget, handler_id_changed);
			/* Record the currently selected text if any */
			if ((string = gtk_combo_box_get_active_text(GTK_COMBO_BOX(var->Widget)))) {
				strcpy(oldselected, string);
			} else {
				strcpy(oldselected, "");
			}
#ifdef DEBUG
			fprintf(stderr, "%s: oldselected=\"%s\"\n", __func__, oldselected);
#endif
		}

		/* Clear the widget if it has been realized */
#if GTK_CHECK_VERSION(2,20,0)
		if ((gtk_widget_get_realized(var->Widget)))
#else
		if ((GTK_WIDGET_REALIZED(var->Widget)))
#endif
		{
			model = gtk_combo_box_get_model(GTK_COMBO_BOX(var->Widget));
			if (gtk_tree_model_get_iter_first(model, &iter)) {
				/* Count the number of rows in the GtkComboBox */
				rowcount = 1;
				while (gtk_tree_model_iter_next(model, &iter)) rowcount++;
#ifdef DEBUG
				fprintf(stderr, "%s: rowcount=%i\n", __func__, rowcount);
#endif
				/* Delete the rows */
				while (rowcount--)
					gtk_combo_box_remove_text(
						GTK_COMBO_BOX(var->Widget), rowcount);
			}
			/* The comboboxtext functions also manage the comboboxentry:
			 * clear the entry */
			if (var->Type == WIDGET_COMBOBOXENTRY) {
				gtk_entry_set_text(
					GTK_ENTRY(gtk_bin_get_child(GTK_BIN(var->Widget))), "");
			}
		}

		/* The <input> tag... */
		act = attributeset_get_first(var->Attributes, ATTR_INPUT);
		while (act) {
			/* input file stock = "File:", input file = "File:/path/to/file" */
			if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5)
				fill_comboboxtext_by_file(var->Widget, act + 5);
			if (input_is_shell_command(act))
				fill_comboboxtext_by_command(var->Widget, act + 8);
			act = attributeset_get_next(var->Attributes, ATTR_INPUT);
		}

		/* The <item> tags... */
		if (attributeset_is_avail(var->Attributes, ATTR_ITEM))
			fill_comboboxtext_by_items(var->Attributes, var->Widget);

		/* Select a default item */
		if (var->Type == WIDGET_COMBOBOXTEXT) {
			gtk_combo_box_set_active(GTK_COMBO_BOX(var->Widget), 0);
		} else if (var->Type == WIDGET_COMBOBOXENTRY) {
			/* The comboboxtext functions also manage the comboboxentry:
			 * default to the entry */
			gtk_combo_box_set_active(GTK_COMBO_BOX(var->Widget), -1);
		}

		/* We'll manage signals ourselves */
#if GTK_CHECK_VERSION(2,20,0)
		if ((gtk_widget_get_realized(var->Widget)))
#else
		if ((GTK_WIDGET_REALIZED(var->Widget)))
#endif
		{
			/* Unblock the signal handler */
			g_signal_handler_unblock(var->Widget, handler_id_changed);
			/* Record the currently selected text if any */
			if ((string = gtk_combo_box_get_active_text(GTK_COMBO_BOX(var->Widget)))) {
				strcpy(newselected, string);
			} else {
				strcpy(newselected, "");
			}
#ifdef DEBUG
			fprintf(stderr, "%s: newselected=\"%s\"\n", __func__, newselected);
#endif
			/* If the before and after selected items are different then
			 * emit a changed signal */
			if (strcmp(oldselected, newselected)) {
#ifdef DEBUG
				fprintf(stderr, "%s: emitting \"changed\" signal\n", __func__);
#endif
				g_signal_emit_by_name(GTK_OBJECT(var->Widget), "changed");
			}
		}

		/* Initialise these only once i.e. when the widget is unrealized.
		 * Also, directives should only really be applied once at start-up */
#if GTK_CHECK_VERSION(2,20,0)
		if (!(gtk_widget_get_realized(var->Widget)))
#else
		if (!(GTK_WIDGET_REALIZED(var->Widget)))
#endif
		{
			/* Apply the default directive if available */
			if (attributeset_is_avail(var->Attributes, ATTR_DEFAULT)) {
				string = attributeset_get_first(var->Attributes, ATTR_DEFAULT);
				model = gtk_combo_box_get_model(GTK_COMBO_BOX(var->Widget));
				if (gtk_tree_model_get_iter_first(model, &iter)) {
					index = 0;
					found = FALSE;
					do {
						gtk_tree_model_get(model, &iter, 0, &text, -1);
#ifdef DEBUG
						fprintf(stderr, "%s: string=%s text=%s\n", __func__, string, text);
#endif
						if (strcmp(string, text) == 0) {
							gtk_combo_box_set_active(GTK_COMBO_BOX(var->Widget), index);
							g_free(text);
							found = TRUE;
							break;
						}
						g_free(text);
						index++;
					} while (gtk_tree_model_iter_next(model, &iter));
					/* The comboboxtext functions also manage the comboboxentry:
					 * if default text not found then set it as default entry text */
					if (var->Type == WIDGET_COMBOBOXENTRY) {
						if (!found) {
							gtk_entry_set_text(GTK_ENTRY(
								gtk_bin_get_child(GTK_BIN(var->Widget))), string);
						}
					}
				}
			}

			/* Apply the visible directive if available */
			if (attributeset_cmp_left
				(var->Attributes, ATTR_VISIBLE, "disabled"))
				gtk_widget_set_sensitive(var->Widget, FALSE);

			/* Connect uncommon signals */
			handler_id_changed = g_signal_connect(G_OBJECT(var->Widget), "changed", 
				G_CALLBACK(on_any_widget_changed_event), (gpointer)var->Attributes);
			/* Store the handler id as a piece of widget data so that
			 * it can be blocked and unblocked later when necessary */
			g_object_set_data(G_OBJECT(var->Widget), "handler_id_changed",
				(gpointer)handler_id_changed);
			/* The comboboxtext functions also manage the comboboxentry:
			 * connect to the activate signal emitted when Enter is pressed
			 * within the entry (storing the handler id is not necessary) */
			if (var->Type == WIDGET_COMBOBOXENTRY) {
				g_signal_connect(G_OBJECT(gtk_bin_get_child(GTK_BIN(var->Widget))),
					"activate", G_CALLBACK(on_any_widget_activate_event),
					(gpointer)var->Attributes);
			}
		}
	}
}

void widget_scale_refresh(variable *var)
{
	gint              handler_id_value_changed;

	if (var != NULL && var->Attributes != NULL) {

#ifdef DEBUG
		g_message("%s(): entering.", __func__);
#endif

		/* Initialise these only once i.e. when the widget is unrealized.
		 * Also, directives should only really be applied once at start-up */
#if GTK_CHECK_VERSION(2,20,0)
		if (!(gtk_widget_get_realized(var->Widget)))
#else
		if (!(GTK_WIDGET_REALIZED(var->Widget)))
#endif
		{
			/* Apply the visible directive if available */
			if (attributeset_cmp_left
				(var->Attributes, ATTR_VISIBLE, "disabled"))
				gtk_widget_set_sensitive(var->Widget, FALSE);

			/* Connect uncommon signals */
			handler_id_value_changed = g_signal_connect(G_OBJECT(var->Widget),
				"value_changed", G_CALLBACK(on_any_widget_value_changed_event),
				(gpointer)var->Attributes);
			/* Store the handler id as a piece of widget data so that
			 * it can be blocked and unblocked later when necessary */
			g_object_set_data(G_OBJECT(var->Widget), "handler_id_value_changed",
				(gpointer)handler_id_value_changed);




		}
	}
}

extern gchar *option_include_file;

FILE *
widget_opencommand(
		const char *command)
{
	char *the_line;
	FILE *infile;

	PIP_DEBUG("Opening command: '%s'", command);

	if (option_include_file != NULL) {
		/* Debian 01_bashism patch: use dot rather than source.
		the_line = g_strdup_printf("source %s; %s", */
		the_line = g_strdup_printf(". %s; %s",
				option_include_file, command);
		infile = popen(the_line, "r");
		g_free(the_line);
	} else {
		infile = popen(command, "r");
	}
	
	if (infile == NULL) 
		g_warning("%s(): %m", __func__);
	
	return infile;
}


//void fill_text_by_file( GtkTextBuffer *buffer, char *filename ){
//  #ifdef DEBUG
//    fprintf( stderr, "%s(): file: '%s'\n", __func__, filename );
//    fflush( stderr );
//  #endif 
  //text=gtk_text_view_get_buffer(GTK_TEXT_VIEW(widget));
//  printf("%s(): buffer is at %p.\n", __func__, buffer );
//   if( text==NULL ){
//     fprintf( stderr, "%s(): buffer is NULL\n", __func__);
//     fflush(stderr);
//   }
   //gtk_text_buffer_insert_at_cursor( text, filename, -1 );
//}/*fill_text_by_file*/


void fill_clist_by_command(GtkWidget * list, int columns, char *command)
{
	int c;
	FILE *infile;
	char *oneline = NULL;
	list_t *thisline;
	int size = 0;
	/*
	 ** Opening pipe for reading...
	 */
	infile = widget_opencommand(command);
	if (infile == NULL) {
		fprintf(stderr, "%s(): command %s, %m\n", __func__,
			command);
		return;
	}

	/*
	 ** Reading and filling the lines to the clist...
	 */
	while (getline(&oneline, &size, infile) != -1) {
		thisline = linecutter(oneline, '|');
		gtk_clist_append(GTK_CLIST(list), thisline->line);
	}

	pclose(infile);
	gtk_clist_select_row(GTK_CLIST(list), 0, 0);
}

void 
fill_label_by_command(GtkWidget *label, 
		char *command)
{
	FILE *infile;
	char oneline[512];
	gchar *error_msg;
	GString *text = g_string_sized_new(512);

#ifdef DEBUG
	g_message("%s(): command: '%s'", __func__, command);
#endif

	infile = widget_opencommand(command);
	if (infile == NULL) {
		g_warning("%s(): command %s, %m\n", __func__, command);
		error_msg = g_strdup_printf("Unable to start command: %s", 
				command);
		gtk_label_set_text(GTK_LABEL(label), error_msg);
		g_free(error_msg);
		return;
	}

	while (fgets(oneline, 512, infile) != NULL) 
		g_string_append(text, oneline);

ready_reading:
	gtk_label_set_text(GTK_LABEL(label), text->str);
	g_string_free(text, TRUE);
	pclose(infile);
}

void 
fill_list_by_command(GtkWidget * list, 
		char *command)
{
	FILE *infile;
	char oneline[512];
	char *saved;
	GtkWidget *item;
#ifdef DEBUG
	g_message("%s(): command: '%s'", __func__, command);
#endif

	infile = widget_opencommand(command);
	if (infile == NULL) {
		fprintf(stderr, "%s(): command %s, %m\n", __func__,
			command);
		return;
	}
	while (fgets(oneline, 512, infile) != NULL) {
		if (oneline[strlen(oneline) - 1] == '\n')
			oneline[strlen(oneline) - 1] = '\0';
		/* Who the hell will free this memory? */
		saved = g_strdup(oneline);
		item = gtk_list_item_new_with_label(oneline);
		gtk_widget_show(item);
		gtk_object_set_user_data(GTK_OBJECT(item),
					 (gpointer) saved);
		gtk_container_add(GTK_CONTAINER(list), item);
	}
	pclose(infile);

	gtk_list_select_item(GTK_LIST(list), 0);
}


void fill_entry_by_command(GtkWidget * entry, char *command)
{
	FILE *infile;
	char line[512];

	g_assert(entry != NULL && command != NULL);

	infile = widget_opencommand(command);
	if (infile == NULL) {
		g_warning("%s(): command %s, %m\n", __func__, command);
		return;
	}

	if (fgets(line, 512, infile) != NULL) {
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		gtk_entry_set_text(GTK_ENTRY(entry), (const gchar *) line);
	}

	pclose(infile);
}

void fill_checkbox_by_command(GtkWidget *checkbox, char *command)
{
	FILE *infile;
	char line[512];

	g_assert(checkbox != NULL && command != NULL);

	infile = widget_opencommand(command);
	if (infile == NULL) {
		fprintf(stderr, "%s(): command %s, %m\n", __func__, command);
		return;
	}

	if (fgets(line, 512, infile) != NULL) {
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		if (strcmp(line, "true") == 0 || strcmp(line, "yes") == 0)
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbox), TRUE);
		else
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbox), FALSE);
	}
	pclose(infile);
}



void 
fill_table_by_command(
	GtkWidget * list, 
	char *command)
{
	FILE *infile;
	char oneline[512];
	int q, n, length;
	char *c[32];
	infile = widget_opencommand(command);
	if (infile == NULL) {
		fprintf(stderr, "%s(): command %s, %m\n", __func__,
			command);
		return;
	}

	while (fgets(oneline, 512, infile) != NULL) {
		if (oneline[strlen(oneline) - 1] == '\n')
			oneline[strlen(oneline) - 1] = '\0';
		for (q = 0; q < 32; ++q)
			c[q] = NULL;

		c[0] = oneline;
		n = 1;
		length = strlen(oneline);
		for (q = 0; q < length; ++q) {
			if (oneline[q] == '|') {
				oneline[q] = '\0';
				c[n] = &oneline[q + 1];
				n++;
			}
		}
		gtk_clist_append((GtkCList *) list, c);
	}
	pclose(infile);
}

void fill_comboboxtext_by_command(GtkWidget *widget, char *command)
{
	FILE *infile;
	char line[512];
	int count;

	g_assert(widget != NULL && command != NULL);

#ifdef DEBUG
	g_message("%s(): command: '%s'", __func__, command);
#endif

	/* Opening pipe for reading... */
	if (infile = widget_opencommand(command)) {
		/* Read the file one line at a time (trailing [CR]LFs are read too) */
		while (fgets(line, 512, infile)) {
			/* Remove the trailing [CR]LFs */
			for (count = strlen(line) - 1; count >= 0; count--)
				if (line[count] == 13 || line[count] == 10) line[count] = 0;
			gtk_combo_box_append_text(GTK_COMBO_BOX(widget), line);
		}
		/* Close the file */
		pclose(infile);
	} else {
		g_warning("%s(): command %s, %m\n", __func__, command);
	}
}

char *widgets_to_str(int itype)
{
	char *type;
	switch (itype) {
	case WIDGET_LABEL:
		type = "LABEL";
		break;
	case WIDGET_ENTRY:
		type = "ENTRY";
		break;
	case WIDGET_EDIT:
		type = "EDIT";
		break;
	case WIDGET_BUTTON:
		type = "BUTTON";
		break;
	case WIDGET_CHECKBOX:
		type = "CHECKBOX";
		break;
	case WIDGET_RADIO:
		type = "RADIO";
		break;
	case WIDGET_LIST:
		type = "LIST";
		break;
	case WIDGET_TABLE:
		type = "TABLE";
		break;
	case WIDGET_COMBO:
		type = "COMBO";
		break;
	case WIDGET_OKBUTTON:
		type = "OKBUTTON";
		break;
	case WIDGET_CANCELBUTTON:
		type = "CANCELBUTTON";
		break;
	case WIDGET_HELPBUTTON:
		type = "HELPBUTTON";
		break;
	case WIDGET_NOBUTTON:
		type = "NOBUTTON";
		break;
	case WIDGET_YESBUTTON:
		type = "YESBUTTON";
		break;
	case WIDGET_SCROLLEDW:
		type = "SCROLLEDW";
		break;
	case WIDGET_VBOX:
		type = "VBOX";
		break;
	case WIDGET_HBOX:
		type = "HBOX";
		break;
	case WIDGET_FRAME:
		type = "FRAME";
		break;
	case WIDGET_WINDOW:
		type = "WINDOW";
		break;
	case WIDGET_PIXMAP:
		type = "PIXMAP";
		break;
	case WIDGET_MENUBAR:
		type = "MENUBAR";
		break;
	case WIDGET_HSEPARATOR:
		type = "HSEPARATOR";
	    break;
	case WIDGET_VSEPARATOR:
		type = "VSEPARATOR";
	    break;
	case WIDGET_COMBOBOXTEXT:
		type = "COMBOBOXTEXT";
		break;
	case WIDGET_COMBOBOXENTRY:
		type = "COMBOBOXENTRY";
		break;
	case WIDGET_HSCALE:
		type = "HSCALE";
		break;
	case WIDGET_VSCALE:
		type = "VSCALE";
		break;
	default:
		type = "THINGY";
	}
	return (type);
}

/*
 * Some stuff to handle progress bars.
 */
G_LOCK_DEFINE_STATIC(any_progress_bar);

void
perform_progress_bar_actions(progr_descr *descr)
{
	gchar *command;
	gchar *type;

	command = attributeset_get_first(descr->Attr, ATTR_ACTION);
	while (command != NULL){
		type = attributeset_get_this_tagattr(descr->Attr, 
				ATTR_ACTION, "type");
		execute_action(descr->widget, command, type);
next_command:   
		command = attributeset_get_next(descr->Attr, ATTR_ACTION);
	}
}

gpointer 
progress_bar_thread_entry(progr_descr *descr)
{
	char      oneline[512];
	gboolean  actions_performed = FALSE;
	long int  ival;
	char     *end;
	gint length;
	
	while (fgets(oneline, 512, descr->pipe) != NULL) {
		length = strlen(oneline) - 1;
		if (oneline[length] == '\n')
			oneline[length] = '\0';

		ival = strtol(oneline, &end, 0);
		descr->fraction =  ival / 100.0;
		if (descr->fraction > 1.0)
			descr->fraction = 1.0;
		/*
		 * Entering critical region.
		 */
		gdk_threads_enter();
		/*
		 * Updating the screen, for this we need a progress bar.
		 */
		G_LOCK(any_progress_bar);
		if (descr->widget != NULL) {
			if (end != oneline)
				gtk_progress_bar_set_fraction(
					GTK_PROGRESS_BAR(descr->widget), 
					descr->fraction);
			else
				gtk_progress_bar_set_text(
					GTK_PROGRESS_BAR(descr->widget), 
					oneline);
		}
		G_UNLOCK(any_progress_bar);
		/*
		 * Processing pending events.
		 */
		while (gtk_events_pending()) 
			gtk_main_iteration_do(FALSE);
		/*
		 * Performing actions if needed.
		 */
		if (ival != 100)
			actions_performed = FALSE;
		if (ival == 100 && !actions_performed) {
			perform_progress_bar_actions(descr);
			actions_performed = TRUE;
		}
		
		/*
		 * Processing pending events.
		 */
		while (gtk_events_pending()) 
			gtk_main_iteration_do(FALSE);
		/*
		 * Leaving critical region.
		 */
		gdk_threads_leave();

		if (descr->widget == NULL)
			break;

	}

	pclose(descr->pipe);
	return NULL;
}


void 
descriptor_destroy_notify(progr_descr *descr)
{
	g_assert(descr != NULL);
	G_LOCK(any_progress_bar);
	descr->widget = NULL;
	G_UNLOCK(any_progress_bar);
}

/*
 * In this function we create a descriptor and start up a thread to handle the
 * input of the progress bar.
 */
void
on_any_progress_bar_realized(GtkWidget *widget, 
		AttributeSet *Attr)
{
	progr_descr *descr;
	gchar *input;

#ifdef DEBUG
	g_message("%s(%p, %p);", __func__, widget, Attr);
#endif	
	g_assert(GTK_IS_WIDGET(widget) && Attr != NULL);
	/*
	 * If there is no input, we can return.
	 */
	if (!attributeset_is_avail(Attr, ATTR_INPUT))
		return;
	/*
	 * Creating the descriptor from the first input.
	 */
	input = attributeset_get_first(Attr, ATTR_INPUT);
	descr = g_new0(progr_descr, 1);
	descr->Attr = Attr;
	descr->widget = widget;
	descr->shell_command = input_get_shell_command(input);
	descr->pipe = widget_opencommand(descr->shell_command);
	/*
	 * When the widget gets destroyed we call this function to prevent
	 * further reading the pipe and setting the destroyed progress bar.
	 */
	g_object_set_data_full(G_OBJECT(widget),
			"descriptor",
			descr, 
			(GDestroyNotify)descriptor_destroy_notify);
	/*
	 * Now we can fire up the reader thread.
	 */
	descr->thread = g_thread_create(
			(GThreadFunc) progress_bar_thread_entry, 
			descr, FALSE, NULL);
}



gint
widget_get_type_from_pointer(GtkWidget *widget)
{
	/*
	 * Must be in a perfect order, since there is a class hierarchy here!
	 */
	if (GTK_IS_LABEL(widget))
		return WIDGET_LABEL;
	else if (GTK_IS_ENTRY(widget))
		return WIDGET_ENTRY;
	else if (GTK_IS_TEXT_VIEW(widget))
		return WIDGET_EDIT;
	else if (GTK_IS_CHECK_BUTTON(widget))
		return WIDGET_CHECKBOX;
	else if (GTK_IS_RADIO_BUTTON(widget))
		return WIDGET_RADIO;
	else if (GTK_IS_PROGRESS_BAR(widget))
		return WIDGET_PROGRESS;
	else if (GTK_IS_WINDOW(widget))
		return WIDGET_WINDOW;
	else if (GTK_IS_BUTTON(widget))
		return WIDGET_BUTTON;
	return 0;
}

