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
	list_t           *table_header;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (attributeset_is_avail(Attr, ATTR_LABEL)) {
		table_header = linecutter(g_strdup(attributeset_get_first(
			&element, Attr, ATTR_LABEL)), '|');
		widget = gtk_clist_new_with_titles(table_header->n_lines,
			table_header->line);
		list_t_free(table_header);	/* Free linecutter memory */
	} else {
		widget = gtk_clist_new(1);	/* 1 column */
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
		if ((value = get_tag_attribute(var->widget_tag_attr, "exported-column")) ||
			(value = get_tag_attribute(var->widget_tag_attr, "exported_column")))
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
		if ((value = get_tag_attribute(var->widget_tag_attr, "selection-mode")) ||
			(value = get_tag_attribute(var->widget_tag_attr, "selection_mode")))
			selectionmode = atoi(value);
		/* Get exported-column */
		if ((value = get_tag_attribute(var->widget_tag_attr, "exported-column")) ||
			(value = get_tag_attribute(var->widget_tag_attr, "exported_column")))
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
	gint              selected_row = -1;
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

	/* Are we selecting a row on initialisation or refresh? */
	if (var->widget_tag_attr) {
		/* selected-row */
		if ((value = get_tag_attribute(var->widget_tag_attr, "selected-row")) ||
			(value = get_tag_attribute(var->widget_tag_attr, "selected_row")))
			selected_row = atoi(value);
	}
	if (selected_row >= 0)
		gtk_clist_select_row(GTK_CLIST(var->Widget), selected_row, 0);

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
		if ((value = get_tag_attribute(var->widget_tag_attr, "selection-mode")) ||
			(value = get_tag_attribute(var->widget_tag_attr, "selection_mode")))
			selectionmode = atoi(value);
		/* Get exported-column */
		if ((value = get_tag_attribute(var->widget_tag_attr, "exported-column")) ||
			(value = get_tag_attribute(var->widget_tag_attr, "exported_column")))
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
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	fprintf(stderr, "%s(): Save not implemented for this widget.\n", __func__);

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
			list_t_free(sliced);	/* Free linecutter memory */

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
		list_t_free(sliced);	/* Free linecutter memory */
		text = attributeset_get_next(&element, var->Attributes, ATTR_ITEM);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}
