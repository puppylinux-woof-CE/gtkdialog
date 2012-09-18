/*
 * widget_comboboxtext.c: 
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

/* Defines */
//#define DEBUG_CONTENT
//#define DEBUG_TRANSITS

/* Local function prototypes, located at file bottom */
static void widget_comboboxtext_input_by_command(variable *var, char *command);
static void widget_comboboxtext_input_by_file(variable *var, char *filename);
static void widget_comboboxtext_input_by_items(variable *var);

/* Notes:
 * The comboboxentry widget is near identical to the comboboxtext widget
 * so there's absolutely no point in maintaining another pair of files */

/***********************************************************************
 * Clear                                                               *
 ***********************************************************************/

void widget_comboboxtext_clear(variable *var)
{
	GtkTreeIter       iter;
	GtkTreeModel     *model;
	gchar             oldselected[512];
	gchar            *string;
	gint              rowcount;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* We'll manage signals ourselves */
	GTKD_FUNCTION_SIGNALS_BLOCK;

	/* Record the currently selected text if any */
	if ((string = gtk_combo_box_get_active_text(GTK_COMBO_BOX(var->Widget)))) {
		strcpy(oldselected, string);
	} else {
		strcpy(oldselected, "");
	}
#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): oldselected='%s'\n", __func__, oldselected);
#endif

	model = gtk_combo_box_get_model(GTK_COMBO_BOX(var->Widget));
	if (gtk_tree_model_get_iter_first(model, &iter)) {
		/* Count the number of rows in the GtkComboBox */
		rowcount = 1;
		while (gtk_tree_model_iter_next(model, &iter)) rowcount++;
#ifdef DEBUG_CONTENT
		fprintf(stderr, "%s(): rowcount=%i\n", __func__, rowcount);
#endif
		/* Delete the rows */
		while (rowcount--)
			gtk_combo_box_remove_text(GTK_COMBO_BOX(var->Widget), rowcount);
	}
	/* The comboboxtext functions also manage the comboboxentry:
	 * clear the entry */
	if (var->Type == WIDGET_COMBOBOXENTRY) {
#ifdef DEBUG_CONTENT
		fprintf(stderr, "%s(): clearing the entry\n", __func__);
#endif
		gtk_entry_set_text(
			GTK_ENTRY(gtk_bin_get_child(GTK_BIN(var->Widget))), "");
	}

	/* We'll manage signals ourselves */
	GTKD_FUNCTION_SIGNALS_UNBLOCK;

	/* The widget will now be empty (entry included if applicable)
	 * and its active index will be -1, so if the recorded text
	 * isn't null then we'll emit a changed signal */
	if (strcmp(oldselected, "")) {
		g_signal_emit_by_name(GTK_OBJECT(var->Widget), "changed");
#ifdef DEBUG_CONTENT
		fprintf(stderr, "%s(): emitting 'changed' signal\n", __func__);
#endif
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Create                                                              *
 ***********************************************************************/

GtkWidget *widget_comboboxtext_create(
	AttributeSet *Attr, tag_attr *attr, gint Type)
{
	GtkWidget        *widget;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (Type == WIDGET_COMBOBOXTEXT) {
		/* Thunor: gtk_combo_box_new_text() is deprecated but
		 * gtk_combo_box_text_new() and associated functions are
		 * unavailable so I have to use the deprecated functions */
		widget = gtk_combo_box_new_text();
	} else {
		/* Thunor: gtk_combo_box_entry_new_text() is deprectated too:
		 * gtk_combo_box_new_with_entry() is unavailable,
		 * gtk_combo_box_text_new_with_entry() is unavailable,
		 * and my brain hurts badly when I read the API ;) */
		widget = gtk_combo_box_entry_new_text();
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return widget;
}

/***********************************************************************
 * Environment Variable All Construct                                  *
 ***********************************************************************/

gchar *widget_comboboxtext_envvar_all_construct(variable *var)
{
	GtkTreeIter       iter;
	GtkTreeModel     *model;
	gchar            *line;
	gchar            *string;
	gchar            *text;
	gint              index;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* Thunor: I've noticed that the existing combobox widget isn't
	 * completely dumped, but it's my new widget so I'll be thorough :) */
	line = g_strdup_printf("%s_ALL=\"", var->Name);
	index = 0;
	/* The comboboxtext functions also manage the comboboxentry:
	 * export the entry if the active index is -1 and the entry
	 * isn't empty */
	if ((var->Type == WIDGET_COMBOBOXENTRY) &&
		(gtk_combo_box_get_active(GTK_COMBO_BOX(var->Widget)) == -1) &&
		(text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(var->Widget))) &&
		(strcmp(text, ""))) {
		string = g_strconcat(line, "'", text, "'", NULL);
		g_free(line);
		line = string;
		index++;
	}
	model = gtk_combo_box_get_model(GTK_COMBO_BOX(var->Widget));
	if (gtk_tree_model_get_iter_first(model, &iter)) {
		do {
			gtk_tree_model_get(model, &iter, 0, &text, -1);
			if (index) {
				string = g_strconcat(line, " '", text, "'", NULL);
			} else {
				string = g_strconcat(line, "'", text, "'", NULL);
				index++;
			}
			g_free(line);
			line = string;
			g_free(text);
		} while (gtk_tree_model_iter_next(model, &iter));
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

gchar *widget_comboboxtext_envvar_construct(GtkWidget *widget)
{
	gchar            *string;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	string = gtk_combo_box_get_active_text(GTK_COMBO_BOX(widget));
	if (string == NULL)
		string = g_strdup("");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return string;
}

/***********************************************************************
 * Fileselect                                                          *
 ***********************************************************************/

void widget_comboboxtext_fileselect(
	variable *var, const char *name, const char *value)
{
	gint              index;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	index = gtk_combo_box_get_active(GTK_COMBO_BOX(var->Widget));

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): index=%i name=%s value=%s\n", __func__, index, name,
		value);
#endif

	if (index < 0) index = 0;
	gtk_combo_box_insert_text(GTK_COMBO_BOX(var->Widget), index, value);
	gtk_combo_box_set_active(GTK_COMBO_BOX(var->Widget), index);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Refresh                                                             *
 ***********************************************************************/

void widget_comboboxtext_refresh(variable *var)
{
	GFileMonitor     *monitor;
	GList            *element;
	GtkTreeIter       iter;
	GtkTreeModel     *model;
	gchar            *act;
	gchar             newselected[512];
	gchar             oldselected[512];
	gchar            *string;
	gchar            *text;
	gint              found;
	gint              index;
	gint              initialised = FALSE;
	gint              rowcount;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* Get initialised state of widget */
	if (g_object_get_data(G_OBJECT(var->Widget), "_initialised") != NULL)
		initialised = (gint)g_object_get_data(G_OBJECT(var->Widget), "_initialised");

	/* We'll manage signals ourselves */
	GTKD_FUNCTION_SIGNALS_BLOCK;

	/* Record the currently selected text if any */
	if ((string = gtk_combo_box_get_active_text(
		GTK_COMBO_BOX(var->Widget)))) {
		strcpy(oldselected, string);
	} else {
		strcpy(oldselected, "");
	}
#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): oldselected='%s'\n", __func__, oldselected);
#endif

	/* Clear the widget if it has been initialised */
	if (initialised) {
		model = gtk_combo_box_get_model(GTK_COMBO_BOX(var->Widget));
		if (gtk_tree_model_get_iter_first(model, &iter)) {
			/* Count the number of rows in the GtkComboBox */
			rowcount = 1;
			while (gtk_tree_model_iter_next(model, &iter)) rowcount++;
#ifdef DEBUG_CONTENT
			fprintf(stderr, "%s(): rowcount=%i\n", __func__, rowcount);
#endif
			/* Delete the rows */
			while (rowcount--)
				gtk_combo_box_remove_text(GTK_COMBO_BOX(var->Widget),
					rowcount);
		}
		/* The comboboxtext functions also manage the comboboxentry:
		 * clear the entry */
		if (var->Type == WIDGET_COMBOBOXENTRY) {
			gtk_entry_set_text(
				GTK_ENTRY(gtk_bin_get_child(GTK_BIN(var->Widget))), "");
		}
	}

	/* The <input> tag... */
	act = attributeset_get_first(&element, var->Attributes, ATTR_INPUT);
	while (act) {
		if (input_is_shell_command(act))
			widget_comboboxtext_input_by_command(var, act + 8);
		/* input file stock = "File:", input file = "File:/path/to/file" */
		if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5) {
			if (!initialised) {
				/* Check for file-monitor and create if requested */
				widget_file_monitor_try_create(var, act + 5);
			}
			widget_comboboxtext_input_by_file(var, act + 5);
		}
		act = attributeset_get_next(&element, var->Attributes, ATTR_INPUT);
	}

	/* The <item> tags... */
	if (attributeset_is_avail(var->Attributes, ATTR_ITEM))
		widget_comboboxtext_input_by_items(var);

	/* Select a default item */
	if (var->Type == WIDGET_COMBOBOXTEXT) {
		gtk_combo_box_set_active(GTK_COMBO_BOX(var->Widget), 0);
	} else if (var->Type == WIDGET_COMBOBOXENTRY) {
		/* The comboboxtext functions also manage the comboboxentry:
		 * default to the entry */
		gtk_combo_box_set_active(GTK_COMBO_BOX(var->Widget), -1);
	}

	/* We'll manage signals ourselves */
	GTKD_FUNCTION_SIGNALS_UNBLOCK;

	/* Record the currently selected text if any */
	if ((string = gtk_combo_box_get_active_text(
		GTK_COMBO_BOX(var->Widget)))) {
		strcpy(newselected, string);
	} else {
		strcpy(newselected, "");
	}
#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): newselected='%s'\n", __func__, newselected);
#endif
	/* If the before and after selected items are different then
	 * emit a changed signal */
	if (strcmp(oldselected, newselected)) {
#ifdef DEBUG_CONTENT
		fprintf(stderr, "%s(): emitting 'changed' signal\n", __func__);
#endif
		g_signal_emit_by_name(GTK_OBJECT(var->Widget), "changed");
	}

	/* Initialise these only once at start-up */
	if (!initialised) {
		/* Apply directives */
		if (attributeset_is_avail(var->Attributes, ATTR_LABEL))
			fprintf(stderr, "%s(): <label> not implemented for this widget.\n",
				__func__);
		if (attributeset_is_avail(var->Attributes, ATTR_DEFAULT)) {
			string = attributeset_get_first(&element, var->Attributes, ATTR_DEFAULT);
			model = gtk_combo_box_get_model(GTK_COMBO_BOX(var->Widget));
			if (gtk_tree_model_get_iter_first(model, &iter)) {
				index = 0;
				found = FALSE;
				do {
					gtk_tree_model_get(model, &iter, 0, &text, -1);
#ifdef DEBUG_CONTENT
					fprintf(stderr, "%s(): string=%s text=%s\n", __func__,
						string, text);
#endif
					if (strcmp(string, text) == 0) {
						gtk_combo_box_set_active(GTK_COMBO_BOX(var->Widget),
							index);
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
		if (attributeset_is_avail(var->Attributes, ATTR_HEIGHT))
			fprintf(stderr, "%s(): <height> not implemented for this widget.\n",
				__func__);
		if (attributeset_is_avail(var->Attributes, ATTR_WIDTH))
			fprintf(stderr, "%s(): <width> not implemented for this widget.\n",
				__func__);
		if ((attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "false")) ||
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "disabled")) ||	/* Deprecated */
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "no")) ||
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "0")))
			gtk_widget_set_sensitive(var->Widget, FALSE);

		/* Connect signals */
		g_signal_connect(G_OBJECT(var->Widget), "changed", 
			G_CALLBACK(on_any_widget_changed_event),
			(gpointer)var->Attributes);
		/* The comboboxtext functions also manage the comboboxentry:
		 * connect to the activate signal emitted when Enter is pressed
		 * within the entry */
		if (var->Type == WIDGET_COMBOBOXENTRY) {
			g_signal_connect(G_OBJECT(gtk_bin_get_child(
				GTK_BIN(var->Widget))), "activate",
				G_CALLBACK(on_any_widget_activate_event),
				(gpointer)var->Attributes);
		}
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Removeselected                                                      *
 ***********************************************************************/

void widget_comboboxtext_removeselected(variable *var)
{
	gchar             newselected[512];
	gchar             oldselected[512];
	gchar            *string;
	gint              index;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* Thunor: We'll manage signals ourselves */
	GTKD_FUNCTION_SIGNALS_BLOCK;

	/* Record the currently selected text if any */
	if ((string = gtk_combo_box_get_active_text(GTK_COMBO_BOX(var->Widget)))) {
		strcpy(oldselected, string);
	} else {
		strcpy(oldselected, "");
	}
#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): oldselected='%s'\n", __func__, oldselected);
#endif
	/* Delete the selected item */
	index = gtk_combo_box_get_active(GTK_COMBO_BOX(var->Widget));
	if (index >= 0) {
		gtk_combo_box_remove_text(GTK_COMBO_BOX(var->Widget), index);
	}
	/* The comboboxtext functions also manage the comboboxentry:
	 * clear the entry */
	if (var->Type == WIDGET_COMBOBOXENTRY) {
		gtk_entry_set_text(
			GTK_ENTRY(gtk_bin_get_child(GTK_BIN(var->Widget))), "");
	}
	/* Auto-select the previous item rather than leaving it empty */
	if (index > 0) index--; else index = 0;
	gtk_combo_box_set_active(GTK_COMBO_BOX(var->Widget), index);

	/* Thunor: We'll manage signals ourselves */
	GTKD_FUNCTION_SIGNALS_UNBLOCK;

	/* Record the currently selected text if any */
	if ((string = gtk_combo_box_get_active_text(GTK_COMBO_BOX(var->Widget)))) {
		strcpy(newselected, string);
	} else {
		strcpy(newselected, "");
	}
#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): newselected='%s'\n", __func__, newselected);
#endif
	/* If the before and after selected items are different then
	 * emit a changed signal */
	if (strcmp(oldselected, newselected)) {
#ifdef DEBUG_CONTENT
		fprintf(stderr, "%s(): emitting 'changed' signal\n", __func__);
#endif
		g_signal_emit_by_name(GTK_OBJECT(var->Widget), "changed");
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Save                                                                *
 ***********************************************************************/

void widget_comboboxtext_save(variable *var)
{
	FILE             *outfile;
	GList            *element;
	GtkTreeModel     *model;
	GtkTreeIter       iter;
	gchar            *act;
	gchar            *filename = NULL;
	gchar            *text;
	gint              index;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* Preferably we'll use the output file filename if available */
	act = attributeset_get_first(&element, var->Attributes, ATTR_OUTPUT);
	while (act) {
		if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5) {
			filename = act + 5;
			break;
		}
		act = attributeset_get_next(&element, var->Attributes, ATTR_OUTPUT);
	}

#if 0
	/* Thunor: I don't really like this behaviour so I'm disabling it */
	if (filename == NULL) {
		/* The output file filename isn't available but we can use
		 * the input file filename instead if available (it's the
		 * same method that the existing functions use) */
		act = attributeset_get_first(&element, var->Attributes, ATTR_INPUT);
		while (act) {
			if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5) {
				filename = act + 5;
				break;
			}
			act = attributeset_get_next(&element, var->Attributes, ATTR_INPUT);
		}
	}
#endif

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): filename=%s\n", __func__, filename);
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
		fprintf(stderr, "%s(): No <output file> directive found.\n", __func__);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by Command                                                    *
 ***********************************************************************/

static void widget_comboboxtext_input_by_command(variable *var, char *command)
{
	FILE             *infile;
	gchar             line[512];
	gint              count;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): command: '%s'\n", __func__, command);
#endif

	/* Opening pipe for reading... */
	if (infile = widget_opencommand(command)) {
		/* Read the file one line at a time (trailing [CR]LFs are read too) */
		while (fgets(line, 512, infile)) {
			/* Enforce end of string in case of max chars read */
			line[512 - 1] = 0;
			/* Remove the trailing [CR]LFs */
			for (count = strlen(line) - 1; count >= 0; count--)
				if (line[count] == 13 || line[count] == 10) line[count] = 0;
			gtk_combo_box_append_text(GTK_COMBO_BOX(var->Widget), line);
		}
		/* Close the file */
		pclose(infile);
	} else {
		fprintf(stderr, "%s(): Couldn't open '%s' for reading.\n", __func__,
			command);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by File                                                       *
 ***********************************************************************/

static void widget_comboboxtext_input_by_file(variable *var, char *filename)
{
	FILE             *infile;
	gchar             line[512];
	gint              count;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (infile = fopen(filename, "r")) {
		/* Read the file one line at a time (trailing [CR]LFs are read too) */
		while (fgets(line, 512, infile)) {
			/* Enforce end of string in case of max chars read */
			line[512 - 1] = 0;
			/* Remove the trailing [CR]LFs */
			for (count = strlen(line) - 1; count >= 0; count--)
				if (line[count] == 13 || line[count] == 10) line[count] = 0;
			gtk_combo_box_append_text(GTK_COMBO_BOX(var->Widget), line);
		}
		/* Close the file */
		fclose(infile);
	} else {
		fprintf(stderr, "%s(): Couldn't open '%s' for reading.\n", __func__,
			filename);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by Items                                                      *
 ***********************************************************************/

static void widget_comboboxtext_input_by_items(variable *var)
{
	GList            *element;
	gchar            *text;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	text = attributeset_get_first(&element, var->Attributes, ATTR_ITEM);
	while (text) {
		gtk_combo_box_append_text(GTK_COMBO_BOX(var->Widget), text);
		text = attributeset_get_next(&element, var->Attributes, ATTR_ITEM);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}
