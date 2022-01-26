/*
 * widget_chooser.c:
 * Gtkdialog - A small utility for fast and easy GUI building.
 * Copyright (C) 2003-2007  László Pere <pipas@linux.pte.hu>
 * Copyright (C) 2011-2012  Thunor <thunorsif@hotmail.com>
 * Copyright (C) 2021-2022  step https://github.com/step-
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
static void widget_chooser_input_by_command(variable *var, char *command);
static void widget_chooser_input_by_file(variable *var, char *filename);
static void widget_chooser_input_by_items(variable *var);

/* Notes: */

/***********************************************************************
 * Clear                                                               *
 ***********************************************************************/

void widget_chooser_clear(variable *var)
{
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* step: effectively this sets the browsed-in folder to $PWD's parent */
	gtk_file_chooser_set_filename(GTK_FILE_CHOOSER(var->Widget), "");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Create                                                              *
 ***********************************************************************/

GtkWidget *widget_chooser_create(
	AttributeSet *Attr, tag_attr *attr, gint Type)
{
	GtkWidget       *widget;
	GList           *element;
	gchar           *act;
	gchar           *tagattr_value;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

/*
	step 2022: GTK_FILE_CHOOSER_ACTION_OPEN only is implemented.

	GTK_FILE_CHOOSER_ACTION_OPEN
	Indicates open mode. The file chooser will only let the user
	pick an existing file.

	GTK_FILE_CHOOSER_ACTION_SAVE
	Indicates save mode. The file chooser will let the user pick
	an existing file, or type in a new filename.

	GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER
	Indicates an Open mode for selecting folders. The
	file chooser will let the user pick an existing folder.

	GTK_FILE_CHOOSER_ACTION_CREATE_FOLDER
	Indicates a mode for creating a new folder. The file
	chooser will let the user name an existing or new folder.
*/
	widget = gtk_file_chooser_widget_new(GTK_FILE_CHOOSER_ACTION_OPEN);

	/* step: for backward-compatibility convert the deprecated signal
	* attribute "when" to the new attribute "signal" so the
	* widget_signal_executor can take care of it */

	act = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (act != NULL) {
		tagattr_value = attributeset_get_this_tagattr(&element, Attr,
			ATTR_ACTION, "when");

		/* default signal */
		if (tagattr_value == NULL)
			tagattr_value = "file-activated";
		else {
			/* add "signal" while leaving "when" as is because
			*  widget_signal_executor will just ignore "when" */
			attributeset_set_this_tagattr(&element, Attr,
				ATTR_ACTION, "signal", tagattr_value);
			fprintf(stderr, "%s(): %s %s\n", __func__,
				"Warning: action attribute \"when\" is deprecated.",
				"Consider replacing \"when\" with \"signal\".\n");
		}

		act = attributeset_get_next(&element, Attr, ATTR_ACTION);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return widget;
}

/***********************************************************************
 * Environment Variable All Construct                                  *
 ***********************************************************************/

gchar *widget_chooser_envvar_all_construct(variable *var)
{
	gchar            *string;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* This function should not be connected-up by default */

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): Hello.\n", __func__);
#endif

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return string;
}

/***********************************************************************
 * Environment Variable Construct                                      *
 ***********************************************************************/

gchar *widget_chooser_envvar_construct(GtkWidget *widget)
{
	gchar            *string = NULL;
	gchar            *text;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	text = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(widget));
	if (text) {
		string = g_strdup(text);
		g_free(text);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return string;
}

/***********************************************************************
 * Fileselect                                                          *
 ***********************************************************************/

void widget_chooser_fileselect(
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

void widget_chooser_refresh(variable *var)
{
	GList           *element;
	gchar           *act;
	gint            initialised = FALSE;
	gchar           *tagattr_value;
	list_t          *mime_types = NULL;
	list_t          *patterns = NULL;
	gint            count;
	GtkFileFilter   *filter;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* Get initialised state of widget */
	if (g_object_get_data(G_OBJECT(var->Widget), "_initialised") != NULL)
		initialised = (gint)g_object_get_data(G_OBJECT(var->Widget), "_initialised");

	/* The <input> tag... */
	act = attributeset_get_first(&element, var->Attributes, ATTR_INPUT);
	while (act) {
		if (input_is_shell_command(act))
			widget_chooser_input_by_command(var, act + 8);
		/* input file stock = "File:", input file = "File:/path/to/file" */
		if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5) {
			if (!initialised) {
				/* Check for file-monitor and create if requested */
				widget_file_monitor_try_create(var, act + 5);
			}
			widget_chooser_input_by_file(var, act + 5);
		}
		act = attributeset_get_next(&element, var->Attributes, ATTR_INPUT);
	}

	/* The <item> tags... */
	if (attributeset_is_avail(var->Attributes, ATTR_ITEM))
		widget_chooser_input_by_items(var);

	/* Initialise these only once at start-up */
	if (!initialised) {
		/* Apply directives */
		if (attributeset_is_avail(var->Attributes, ATTR_LABEL))
			fprintf(stderr, "%s(): <label> not implemented for this widget.\n",
				__func__);

		if (attributeset_is_avail(var->Attributes, ATTR_DEFAULT)) {
			gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(var->Widget),
				attributeset_get_first(&element, var->Attributes, ATTR_DEFAULT));
		} else {
			/* cwd */
			gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(var->Widget), "");
		}

		/* set either width or height or both from directives */
		gtk_widget_set_size_request(var->Widget,
			attributeset_is_avail(var->Attributes, ATTR_WIDTH)
			? atoi(attributeset_get_first(&element, var->Attributes, ATTR_WIDTH))
			: -1,
			attributeset_is_avail(var->Attributes, ATTR_HEIGHT)
			? atoi(attributeset_get_first(&element, var->Attributes, ATTR_HEIGHT))
			: -1);

		if ((attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "false")) ||
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "disabled")) ||	/* Deprecated */
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "no")) ||
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "0")))
			gtk_widget_set_sensitive(var->Widget, FALSE);

		//gtk_file_chooser_set_preview_widget_active(GTK_FILE_CHOOSER(var->Widget), TRUE);

		if (var->widget_tag_attr) {
			/* step 2021 New custom tag attributes:
			* (older versions ignore them therefore degrade gracefully)
			* "default-file"      overrides <default> - specify both if sensible
			* "fs-filters-mime"   like <entry>'s and listed before fs-filters
			* "fs-filters"        like <entry>'s */

			/* Default file overrides <default> directory */
			if ((tagattr_value = get_tag_attribute(var->widget_tag_attr, "default-file")))
				gtk_file_chooser_set_filename(GTK_FILE_CHOOSER(var->Widget), tagattr_value);

			/* File Filters of type mime are listed before pattern filters */
			if ((tagattr_value = get_tag_attribute(var->widget_tag_attr, "fs-filters-mime"))) {
				mime_types = linecutter(g_strdup(tagattr_value), '|');
				for (count = 0; count < mime_types->n_lines; count++) {
					filter = gtk_file_filter_new();
					gtk_file_filter_set_name(filter, mime_types->line[count]);
					gtk_file_filter_add_mime_type(filter, mime_types->line[count]);
					gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(var->Widget), filter);
				}
				if (mime_types) list_t_free(mime_types);
			}

			/* File filters of type pattern are listed after mime-type filters */
			if ((tagattr_value = get_tag_attribute(var->widget_tag_attr, "fs-filters"))) {
				patterns = linecutter(g_strdup(tagattr_value), '|');
				for (count = 0; count < patterns->n_lines; count++) {
					filter = gtk_file_filter_new();
					gtk_file_filter_set_name(filter, patterns->line[count]);
					gtk_file_filter_add_pattern(filter, patterns->line[count]);
					gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(var->Widget), filter);
				}
				if (patterns) list_t_free(patterns);
			}
		}

		/* Connect signals */

		g_signal_connect(G_OBJECT(var->Widget), "file-activated",
			G_CALLBACK(on_chooser_widget_file_activated_event), (gpointer)var->Attributes);
		g_signal_connect(G_OBJECT(var->Widget), "selection-changed",
			G_CALLBACK(on_chooser_widget_selection_changed_event), (gpointer)var->Attributes);
		g_signal_connect(G_OBJECT(var->Widget), "update-preview",
			G_CALLBACK(on_chooser_widget_update_preview_event), (gpointer)var->Attributes);
		g_signal_connect(G_OBJECT(var->Widget), "current-folder-changed",
			G_CALLBACK(on_chooser_widget_current_folder_changed_event), (gpointer)var->Attributes);
		/* step: confirm-overwrite not implemented */
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Removeselected                                                      *
 ***********************************************************************/

void widget_chooser_removeselected(variable *var)
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

void widget_chooser_save(variable *var)
{
	FILE             *outfile;
	GList            *element;
	GtkTextBuffer    *buffer;
	GtkTextIter       start, end;
	gchar            *act;
	gchar            *filename = NULL;
	gchar            *text;
	gchar            *string;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* We'll use the output file filename if available */
	act = attributeset_get_first(&element, var->Attributes, ATTR_OUTPUT);
	while (act) {
		if (strlen(act) > 5 && strncasecmp(act, "file:", 5)) {
			filename = act + 5;
			break;
		}
		act = attributeset_get_next(&element, var->Attributes, ATTR_OUTPUT);
	}

	/* If we have a valid filename then open it and dump the widget's data to it */
	if (filename) {
		text = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(var->Widget));
			if (text) {
				string = g_strdup(text);
				if ((outfile = fopen(filename, "w"))) {
					fprintf(outfile, "%s", string);
					fclose(outfile);
				} else {
					fprintf(stderr, "%s(): Couldn't open '%s' for writing.\n",
						__func__, filename);
				}
				g_free(text);
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

static void widget_chooser_input_by_command(variable *var, char *command)
{
	FILE             *infile;
	GString          *text = g_string_sized_new(512);
	gchar             line[512];

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): command: '%s'\n", __func__, command);
#endif

	/* Opening pipe for reading... */
	if (infile = widget_opencommand(command)) {
		/* Read the file one line at a time */
		while (fgets(line, sizeof(line), infile)) {
			g_string_append(text, line);
		}

		gtk_file_chooser_set_filename(GTK_FILE_CHOOSER(var->Widget), text->str);
		g_string_free(text, TRUE);

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

static void widget_chooser_input_by_file(variable *var, char *filename)
{
	FILE             *infile;
	GString          *text = g_string_sized_new(512);
	gchar             line[512];

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (infile = fopen(filename, "r")) {
		/* Read the file one line at a time */
		while (fgets(line, sizeof(line), infile)) {
			g_string_append(text, line);
		}

		gtk_file_chooser_set_filename(GTK_FILE_CHOOSER(var->Widget), text->str);
		g_string_free(text, TRUE);

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

static void widget_chooser_input_by_items(variable *var)
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
