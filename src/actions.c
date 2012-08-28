/*
 * actions.c:
 * Gtkdialog - A small utility for fast and easy GUI building.
 * Copyright (C) 2003-2007  László Pere <pipas@linux.pte.hu>
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

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <gtk/gtk.h>

#ifndef G_OS_WIN32
#include <sys/types.h>
#include <regex.h>
#endif

#include "gtkdialog.h"
#include "widgets.h"
#include "actions.h"
#include "attributes.h"
#include "variables.h"
#include "tag_attributes.h"

extern gchar *option_include_file;

/* Local function prototypes */
void action_fileselection_made(GtkWidget *w, actioncommand *ac);
void action_fileselection_destroy(GtkWidget *w, actioncommand *ac);

/***********************************************************************
 * Action closewindow                                                  *
 ***********************************************************************/
/* Thunor: This function will close an existing window that contains a
 * variable that matches string although ideally the application developer
 * would have supplied a unique name in the window widget's variable
 * directive.
 */

int action_closewindow(GtkWidget *widget, char *string)
{
	GtkWidget        *window;
	variable         *existing;

	g_assert(GTK_IS_WIDGET(widget));

#ifdef DEBUG
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/**
	 * Patriot Oct 2009: zigbert has been dreaming for this to be fixed.
	 * Issue: closewindow command closes THE window its called from.
	 * Fixed: Workaround applied to point to the correct window.
	 **/

	existing = variables_get_by_name(string);

#ifdef DEBUG
	fprintf(stderr, "%s(): string=%s existing=%p\n",
		__func__, string, existing);
	fflush(stderr);
#endif

	if (existing != NULL && existing->Widget != NULL) {

#ifdef DEBUG
		fprintf(stderr, "%s(): Name=%s Type=%i\n",
			__func__, existing->Name, existing->Type);
		fflush(stderr);
#endif

		//Redundant: parent = gtk_widget_get_toplevel(existing->Widget);
		window = gtk_widget_get_ancestor(existing->Widget, GTK_TYPE_WINDOW);
		//Redundant: variables_drop_by_parent(NULL, parent);
		variables_drop_by_window_id(NULL, existing->window_id);
		gtk_widget_destroy(window);

#ifdef DEBUG
		fprintf(stderr, "%s(): variables_count_widgets()=%i\n", __func__,
			variables_count_widgets());
#endif

		/* If we are closing the last window then we can exit gtkdialog */
		if (variables_count_widgets() == 0) {

			printf("EXIT=\"closewindow\"\n");

			/* Redundant: Since being here requires that there are no
			 * remaining variables therefore there's nothing to print.
			 * print_variables(NULL); */

#ifdef DEBUG
			fprintf(stderr, "%s(): Calling exit(EXIT_SUCCESS)\n", __func__);
#endif

			exit(EXIT_SUCCESS);

		}
	}

#ifdef DEBUG
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return 0;
}

/***********************************************************************
 * Action launchwindow                                                 *
 ***********************************************************************/
/* Thunor: This function will launch a new window, the source of which
 * should be contained within an existing exported shell variable.
 * 
 * The parameter to this function is the shell variable name which MUST
 * match any widget's variable within the program, although it would be
 * better practice to use a dedicated window widget's variable for this.
 * 
 * Currently the variable name matching requirement remains unenforced
 * and will require to remain so as there will be broken applications
 * out there using fixes and workarounds. The best that can be hoped for
 * is a warning message once the new window has been loaded. 
 */

int action_launchwindow(GtkWidget *widget, char *string)
{
#ifdef DEBUG
	extern gchar     *program_src;
	extern gint       charsreaded;
#endif
	extern int        instruction_counter;
	GtkWidget        *window;
	variable         *existing;

#ifdef DEBUG
	fprintf(stderr, "%s(): string=%s\n", __func__, string);
#endif

	/* Thunor: Added to check that a program isn't already being parsed
	 * as run_program() is not reentrant and it'll error with a parser
	 * message that actually relates to the newly launched program
	 * (see Issue16 on the gtkdialog website) */
	if (instruction_counter == 0) {

		/* Check if a variable already exists with the same name as that
		 * passed as the parameter to launch to establish if the window
		 * has already been launched (it's not foolproof but it works) */
		existing = variables_get_by_name(string);

		if (existing != NULL && existing->Widget != NULL) {

			/* The window has already been launched so just give it the focus */
#ifdef DEBUG
			fprintf(stderr, "%s(): existing=%p Name=%s\n", __func__,
				existing, existing->Name);
#endif

			/**
			* Patriot Oct 2009: Fixing the issue above [in action_closewindow]
			* also requires a minor adjustment to this section.
			**/
			//Redundant: parent = gtk_widget_get_toplevel(existing->Widget);
			window = gtk_widget_get_ancestor(existing->Widget, GTK_TYPE_WINDOW);
			gtk_window_present(GTK_WINDOW(window));

		} else {

			/* Get the program source from the envvar and initialise
			 * everything necessary ready for a new parse */
			//Redundant: set_program_source(string);
			get_program_from_variable(string);

#ifdef DEBUG
			fprintf(stderr, "%s():\ncharsreaded=%i\nprogram_src=%s\n",
				__func__, charsreaded, program_src);
#endif

			/* Export all variables */
			variables_export_all();

#ifdef DEBUG
			fprintf(stderr, "%s():\ncharsreaded=%i\nprogram_src=%s\n",
				__func__, charsreaded, program_src);
#endif

			/* Call the parser to interpret the new code (it won't return) */
			gtkdialog_parse();

			g_warning("%s(): This won't be reached.", __func__);

		}

	} else {
		fprintf(stderr, "%s(): It's not possible to launch %s at this time: \
try launching after the originating window has fully loaded.\n",
			__func__, string);
	}

	return 0;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

int action_exitprogram(GtkWidget *widget, char *string)
{
	print_variables(NULL);

	if (string[0] == '=')
		/* Thunor: An interesting undocumented feature temp temp */
		printf("EXIT%s", string);
	else
		printf("EXIT=\"%s\"\n", string);

#ifdef DEBUG
	fprintf(stderr, "%s(): Calling exit(EXIT_SUCCESS)\n", __func__);
#endif

	exit(EXIT_SUCCESS);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

int action_refreshwidget(GtkWidget *widget, char *string)
{
	variables_refresh(string);
	return (0);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

int action_savewidget(GtkWidget *widget, char *string)
{
	variables_save(string);
	return (0);
}

/***********************************************************************
 * Action fileselect                                                   *
 ***********************************************************************/
/* This function will create and open a fileselection dialog and
 * connect it to the action_fileselection_made function to take
 * the selected file name */

#if GTK_CHECK_VERSION(2,4,0)
int action_fileselect(GtkWidget *widget, char *string)
{
	list_t                 *mime_types = NULL;
	list_t                 *patterns = NULL;
	variable               *var = NULL;
	GList                  *element;
	GtkFileChooserAction    action = GTK_FILE_CHOOSER_ACTION_OPEN;
	GtkFileFilter          *filter;
	GtkWidget              *chooser;
	gchar                  *filename = NULL;
	gchar                  *title = "Gtkdialog";
	gchar                  *value;
	gint                    count;
	gint                    response;

#ifdef DEBUG
	fprintf(stderr, "%s(): string='%s'\n", __func__, string);
#endif

	if (var = variables_get_by_name(string)) {

		/* Set the title of the chooser dialog to the label directive
		 * of the target widget if available (this was the original
		 * behaviour that although used in the 16.00-fileselect example
		 * it is undocumented so possibly few people have realised this) */
		if (attributeset_is_avail(var->Attributes, ATTR_LABEL)) {
			title = attributeset_get_first(&element, var->Attributes, ATTR_LABEL);
#ifdef DEBUG
			fprintf(stderr, "%s(): title='%s' from label directive\n",
				__func__, title);
#endif
		}

		if (var->widget_tag_attr) {
			/* Set title if present */
			if ((value = get_tag_attribute(var->widget_tag_attr, "fs-title")) ||
				(value = get_tag_attribute(var->widget_tag_attr, "fs_title"))) {
				title = value;
#ifdef DEBUG
				fprintf(stderr, "%s(): title='%s' from tag attribute\n",
					__func__, title);
#endif
			}
			/* Set file chooser action if present */
			if ((value = get_tag_attribute(var->widget_tag_attr, "fs-action")) ||
				(value = get_tag_attribute(var->widget_tag_attr, "fs_action")) ||
				(value = get_tag_attribute(var->widget_tag_attr, "accept"))) {	/* Deprecated */				
				if ((strcasecmp(value, "file") == 0) ||
					(strcasecmp(value, "filename") == 0)) {			/* Deprecated */
					action = GTK_FILE_CHOOSER_ACTION_OPEN;
				} else if ((strcasecmp(value, "newfile") == 0) ||
					(strcasecmp(value, "savefilename") == 0)) {		/* Deprecated */
					action = GTK_FILE_CHOOSER_ACTION_SAVE;
				} else if ((strcasecmp(value, "folder") == 0) ||
					(strcasecmp(value, "directory") == 0)) {		/* Deprecated */
					action = GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER;
				} else if ((strcasecmp(value, "newfolder") == 0) ||
					(strcasecmp(value, "newdirectory") == 0)) {		/* Deprecated */
					action = GTK_FILE_CHOOSER_ACTION_CREATE_FOLDER;
				}
#ifdef DEBUG
				fprintf(stderr, "%s(): action=%i\n", __func__, action);
#endif
			}
		}

		/* Create the file chooser dialog */
		chooser = gtk_file_chooser_dialog_new(title, NULL, action,
			GTK_STOCK_OK, GTK_RESPONSE_OK,
			GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, NULL);

		/* Set current folder if present */
		if (var->widget_tag_attr &&
			((value = get_tag_attribute(var->widget_tag_attr, "fs-folder")) ||
			(value = get_tag_attribute(var->widget_tag_attr, "fs_folder")))) {
			gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(chooser), value);
#ifdef DEBUG
			fprintf(stderr, "%s(): current folder='%s'\n", __func__, value);
#endif
		}

		/* Add file filters */
		if (var->widget_tag_attr) {
			/* Filters of type pattern */
			if ((value = get_tag_attribute(var->widget_tag_attr, "fs-filters")) ||
				(value = get_tag_attribute(var->widget_tag_attr, "fs_filters"))) {
				patterns = linecutter(g_strdup(value), '|');
				for (count = 0; count < patterns->n_lines; count++) {
					filter = gtk_file_filter_new();
					gtk_file_filter_set_name(filter, patterns->line[count]);
					gtk_file_filter_add_pattern(filter, patterns->line[count]);
					gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(chooser), filter);
#ifdef DEBUG
					fprintf(stderr, "%s(): patterns->line[count]='%s'\n",
						__func__, patterns->line[count]);
#endif
				}
			}
			/* Filters of type mime */
			if ((value = get_tag_attribute(var->widget_tag_attr, "fs-filters-mime")) ||
				(value = get_tag_attribute(var->widget_tag_attr, "fs_filters_mime"))) {
				mime_types = linecutter(g_strdup(value), '|');
				for (count = 0; count < mime_types->n_lines; count++) {
					filter = gtk_file_filter_new();
					gtk_file_filter_set_name(filter, mime_types->line[count]);
					gtk_file_filter_add_mime_type(filter, mime_types->line[count]);
					gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(chooser), filter);
#ifdef DEBUG
					fprintf(stderr, "%s(): mime_types->line[count]='%s'\n",
						__func__, mime_types->line[count]);
#endif
				}
			}
		}

		/* Add an "All files" "*" filter which will become the
		 * default if no user filters were added above */
		filter = gtk_file_filter_new();
		gtk_file_filter_set_name(filter, "All files");
		gtk_file_filter_add_pattern(filter, "*");
		gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(chooser), filter);

		/* Run the file chooser dialog and get the response.
		 * Note that accept="newdirectory" (fs-action="newfolder")
		 * currently crashes the file chooser dialog if nothing is
		 * selected or created which is mentioned in the example */
		response = gtk_dialog_run(GTK_DIALOG(chooser));

#ifdef DEBUG
		fprintf(stderr, "%s(): response=%i\n", __func__, response);
#endif

		/* If the user pressed the OK button we set the target widget */
		switch (response) {
			case GTK_RESPONSE_CANCEL:
				/* Nothing to do */
				break;
			case GTK_RESPONSE_OK:
				filename = gtk_file_chooser_get_filename(
					GTK_FILE_CHOOSER(chooser));
#ifdef DEBUG
				fprintf(stderr, "%s(): filename=%s\n", __func__, filename);
#endif
				if (filename) {
					variables_set_value(string, filename);
					g_free(filename);
				}
				break;
		}

		/* Free linecutter memory */
		if (patterns) list_t_free(patterns);
		if (mime_types) list_t_free(mime_types);

		/* Destroy the file chooser dialog */
		gtk_widget_destroy(chooser);
	}

	return 0;
}

#else

int action_fileselect(GtkWidget *widget, char *string)
{
	actioncommand *ac;
	/*
	 ** We create a new actioncommand.
	 */
	ac = g_malloc(sizeof(actioncommand));
	ac->source_widget = gtk_file_selection_new("gtkwindow");
	ac->destination_name = string;
	gtk_widget_show(ac->source_widget);

	/*
	 ** We connect the OK button in fileselection dialog
	 */
	g_signal_connect(G_OBJECT
			 (GTK_FILE_SELECTION(ac->source_widget)->
			  ok_button), "clicked",
			 G_CALLBACK(action_fileselection_made),
			 (gpointer) ac);
	/*
	 ** We connect the Cancel button in fileselection dialog
	 */
	g_signal_connect(G_OBJECT
			 (GTK_FILE_SELECTION(ac->source_widget)->
			  cancel_button), "clicked",
			 G_CALLBACK(action_fileselection_destroy),
			 (gpointer) ac);
	return;
}
#endif

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* This function is called when the user presses the OK button in
 * a fileselection dialog */

void action_fileselection_made(GtkWidget *w, actioncommand * ac)
{
	/*
	 ** Let's copy the selected file name to the destination widget.
	 */
	variables_set_value((const char *)ac->destination_name,
		gtk_file_selection_get_filename(GTK_FILE_SELECTION(ac->source_widget))
	    );
	/*
	 ** We destroy the fileselection dialog and free the actioncommand
	 ** memory.
	 */
	gtk_widget_destroy(ac->source_widget);
	free(ac);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* This function is called when the user presses the Cancel button in
 * a fileselection dialog */

void action_fileselection_destroy(GtkWidget *w, actioncommand *ac)
{
	/*
	 ** We destroy the fileselection dialog and free the actioncommand
	 ** memory.
	 */
	gtk_widget_destroy(ac->source_widget);
	free(ac);
}


/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* This action removes all elements from a widget */

int action_clearwidget(GtkWidget *widget, char *string)
{
	variables_clear(string);
	return (0);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* This action removes a selected element from a widget */

int action_removeselected(GtkWidget *widget, char *string)
{
	remove_selected_variable(string);
	return 0;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

int action_append(GtkWidget *widget, char *string)
{
#ifndef G_OS_WIN32
	regex_t twoparams;
	regmatch_t matched[3];
	char *regular = "[ ]*([A-Za-z_]+),[ ]*([A-Za-z_]+)";
	char *from, *to;
	int length_from, length_to;
	
	g_assert(string != NULL);
	
	if (regcomp(&twoparams, regular, REG_EXTENDED) != 0)
		g_error("%s(): Internal error: %m", __func__);

	if (regexec(&twoparams, string, 3, matched, 0) != 0) {
		yywarning("Insert action needs two parameters.");
		return FALSE;
	}
	
	length_from = matched[1].rm_eo - matched[1].rm_so;
	from = g_malloc(length_from + 1);

	length_to = matched[2].rm_eo - matched[2].rm_so;
	to = g_malloc(length_to + 1);

	strncpy(from, string, length_from);
	from[length_from] = '\0';

	strncpy(to, string + matched[2].rm_so, length_to);
	to[length_to] = '\0';

	return append_fromto_variable(from, to);
#else
	g_warning("%s(): Unimplemented.", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

int action_enable(GtkWidget *widget, char *string)
{
	variables_enable(string);
	return (0);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

int action_disable(GtkWidget *widget, char *string)
{
	variables_disable(string);
	return (0);
}

/***********************************************************************
 * Action show                                                         *
 ***********************************************************************/

int action_show(GtkWidget *widget, char *string)
{
	variables_show(string);
	return 0;
}

/***********************************************************************
 * Action hide                                                         *
 ***********************************************************************/

int action_hide(GtkWidget *widget, char *string)
{
	variables_hide(string);
	return 0;
}

/***********************************************************************
 * Action activate                                                     *
 ***********************************************************************/

int action_activate(GtkWidget *widget, char *string)
{
	variables_activate(string);
	return 0;
}

/***********************************************************************
 * Action grabfocus                                                    *
 ***********************************************************************/

int action_grabfocus(GtkWidget *widget, char *string)
{
	variables_grabfocus(string);
	return 0;
}

/***********************************************************************
 * Action presentwindow                                                *
 ***********************************************************************/

int action_presentwindow(GtkWidget *widget, char *string)
{
	variables_presentwindow(string);
	return 0;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* This fuction will export variables and run a shell command */

int action_shellcommand(GtkWidget *widget, char *string)
{
	char *command;
	int result;

	variables_export_all();

	if (option_include_file == NULL) {
		result = system(string);
		return (0);
	}

	/* Debian 01_bashism patch: use dot rather than source.
	command = g_strdup_printf("source %s; %s", */
	command = g_strdup_printf(". %s; %s",
			option_include_file, string);
	result = system(command);
	g_free(command);
	return;
}
