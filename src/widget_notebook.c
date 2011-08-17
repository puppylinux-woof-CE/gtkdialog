/*
 * widget_notebook.c: 
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

/* Defines */
//#define DEBUG_CONTENT
//#define DEBUG_TRANSITS

/* Local function prototypes, located at file bottom */
static void widget_notebook_input_by_command(variable *var, char *command);
static void widget_notebook_input_by_file(variable *var, char *filename);
static void widget_notebook_input_by_items(variable *var);

/* Notes: */

/***********************************************************************
 * Clear                                                               *
 ***********************************************************************/

void widget_notebook_clear(variable *var)
{
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	fprintf(stderr, "%s(): Clear not implemented for this widget.\n", __func__);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Create                                                              *
 ***********************************************************************/
GtkWidget *widget_notebook_create(
	AttributeSet *Attr, tag_attr *attr, gint Type)
{
	GtkWidget        *label;
	GtkWidget        *widget;
	list_t           *labels = NULL;
	stackelement      elements;
	gchar            *tab_prefix = NULL;
	gchar            *tab_suffix = NULL;
	gchar             text[128];
	gchar            *value;
	gint              count;
	gint              tab_base_index = 1;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* Create the notebook widget */
	widget = gtk_notebook_new();

	/* Read the tag attributes */
	if (attr) {
		if ((value = get_tag_attribute(attr, "tab-labels")) ||
			(value = get_tag_attribute(attr, "tab_labels")) ||
			(value = get_tag_attribute(attr, "labels")))	/* Deprecated */
			labels = linecutter(strdup(value), '|');
		if (!(tab_prefix = get_tag_attribute(attr, "tab-prefix")))
			tab_prefix = get_tag_attribute(attr, "tab_prefix");
		if (!(tab_suffix = get_tag_attribute(attr, "tab-suffix")))
			tab_suffix = get_tag_attribute(attr, "tab_suffix");
		if ((value = get_tag_attribute(attr, "tab-base-index")) ||
			(value = get_tag_attribute(attr, "tab_base_index")))
			tab_base_index = atoi(value);
	}

	elements = pop();
	for (count = 0; count < elements.nwidgets; count++) {
		/* Build the tab label */
		if (labels && labels->n_lines > count)
			sprintf(text, "%s", labels->line[count]);
		else if (tab_prefix && tab_suffix)
			sprintf(text, "%s%i%s", tab_prefix, count + tab_base_index, tab_suffix);
		else if (tab_prefix)
			sprintf(text, "%s%i", tab_prefix, count + tab_base_index);
		else if (tab_suffix)
			sprintf(text, "%i%s", count + tab_base_index, tab_suffix);
		else
			sprintf(text, "Page %i", count + tab_base_index);
		/* Create the label and append the notebook page with label */
		label = gtk_label_new(text);
		gtk_notebook_append_page(GTK_NOTEBOOK(widget),
			elements.widgets[count], label);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return widget;
}

/***********************************************************************
 * Environment Variable All Construct                                  *
 ***********************************************************************/

gchar *widget_notebook_envvar_all_construct(variable *var)
{
	gchar            *string;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* This function should not be connected-up by default */

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return string;
}

/***********************************************************************
 * Environment Variable Construct                                      *
 ***********************************************************************/

gchar *widget_notebook_envvar_construct(GtkWidget *widget)
{
	gchar             envvar[8];
	gchar            *string;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	sprintf(envvar, "%i", gtk_notebook_get_current_page(GTK_NOTEBOOK(widget)));
	string = g_strdup(envvar);

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): string='%s'\n", __func__, string);
#endif

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return string;
}

/***********************************************************************
 * Fileselect                                                          *
 ***********************************************************************/

void widget_notebook_fileselect(
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
void widget_notebook_refresh(variable *var)
{
	GList            *element;
	gchar            *act;
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
			widget_notebook_input_by_command(var, act + 8);
		/* input file stock = "File:", input file = "File:/path/to/file" */
		if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5)
			widget_notebook_input_by_file(var, act + 5);
		act = attributeset_get_next(&element, var->Attributes, ATTR_INPUT);
	}

	/* The <item> tags... */
	if (attributeset_is_avail(var->Attributes, ATTR_ITEM))
		widget_notebook_input_by_items(var);

	/* Initialise these only once at start-up */
	if (!initialised) {
		/* Apply directives */
		if (attributeset_is_avail(var->Attributes, ATTR_DEFAULT))
			fprintf(stderr, "%s(): <default> not implemented for this widget.\n",
				__func__);
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

	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Removeselected                                                      *
 ***********************************************************************/

void widget_notebook_removeselected(variable *var)
{
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	fprintf(stderr, "%s(): Removeselected not implemented for this widget.\n",
		__func__);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Save                                                                *
 ***********************************************************************/

void widget_notebook_save(variable *var)
{
	FILE             *outfile;
	GList            *element;
	gchar            *act;
	gchar            *filename = NULL;
	gint              index;

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
			index = gtk_notebook_get_current_page(GTK_NOTEBOOK(var->Widget));
			fprintf(outfile, "%i", index);
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

static void widget_notebook_input_by_command(variable *var, char *command)
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
		/* Just one line */
		if (fgets(line, 512, infile)) {
			/* Enforce end of string in case of more chars read */
			line[512 - 1] = 0;
			/* Remove the trailing [CR]LFs */
			for (count = strlen(line) - 1; count >= 0; count--)
				if (line[count] == 13 || line[count] == 10) line[count] = 0;
			/* From the GTK+ 2 Reference Manual:
			 * "Note that due to historical reasons, GtkNotebook refuses to switch
			 * to a page unless the child widget is visible. Therefore, it is
			 * recommended to show child widgets before adding them to a notebook".
			 * 
			 * I'm not going to get involved in showing widgets because currently
			 * on_any_widget_realized is setting the GTK+ properties and it'll set
			 * things prematurely, so the initial refresh won't change the page */
			gtk_notebook_set_current_page(GTK_NOTEBOOK(var->Widget), atoi(line));
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

static void widget_notebook_input_by_file(variable *var, char *filename)
{
	FILE             *infile;
	gchar             line[512];
	gint              count;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (infile = fopen(filename, "r")) {
		/* Just one line */
		if (fgets(line, 512, infile)) {
			/* Enforce end of string in case of more chars read */
			line[512 - 1] = 0;
			/* Remove the trailing [CR]LFs */
			for (count = strlen(line) - 1; count >= 0; count--)
				if (line[count] == 13 || line[count] == 10) line[count] = 0;
			/* From the GTK+ 2 Reference Manual:
			 * "Note that due to historical reasons, GtkNotebook refuses to switch
			 * to a page unless the child widget is visible. Therefore, it is
			 * recommended to show child widgets before adding them to a notebook".
			 * 
			 * I'm not going to get involved in showing widgets because currently
			 * on_any_widget_realized is setting the GTK+ properties and it'll set
			 * things prematurely, so the initial refresh won't change the page */
			gtk_notebook_set_current_page(GTK_NOTEBOOK(var->Widget), atoi(line));
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

static void widget_notebook_input_by_items(variable *var)
{
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	fprintf(stderr, "%s(): <item> not implemented for this widget.\n", __func__);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}
