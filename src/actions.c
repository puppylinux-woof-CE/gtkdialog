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

extern gchar *option_include_file;

/* 
** This action will close a window. The program remain running.
** If we get a window's name, we close that if the name is null
** we close the widget's parent window.
*/
int 
action_closewindow(GtkWidget *widget, char *string)
{
	GtkWidget *parent_widget;

	g_assert(GTK_IS_WIDGET(widget));
#ifdef DEBUG
	g_message("%s(%p, '%s')", __func__, widget, string);
#endif

/**
 * Patriot Oct 2009: zigbert has been dreaming for this to be fixed.
 * Issue: closewindow command closes THE window its called from.
 * Fixed: Workaround applied to point to the correct window.
 **/

	variable *windowvar;
	windowvar = variables_get_by_name(string);
#ifdef DEBUG
		fprintf(stderr, "%s(): Widget name: %s.\n", __func__, windowvar->Name);
		fprintf(stderr, "%s(): Widget type: %d.\n", __func__, windowvar->Type);
		fflush(stderr);
#endif
	if (windowvar != NULL && windowvar->Widget != NULL) {
		parent_widget = gtk_widget_get_toplevel(windowvar->Widget);
	}
	else {
		return (0);
	}

//	parent_widget = gtk_widget_get_toplevel(widget);  // incorrect pointer
	variables_drop_by_parent(NULL, parent_widget);
	gtk_widget_destroy(parent_widget);

	/*
	 * Now, if this was the last window, we can exit.
	 */
	if (variables_count_widgets() == 0) {
		printf("EXIT=\"closewindow\"\n");
		print_variables(NULL);
		gtk_main_quit();
		exit(EXIT_SUCCESS);
	}
	return 0;
}

/*
** This action will launch a dialog box, a new window. It's a little
** bit tricky, because we have to exit the gtk main loop and call the
** parser to interpret new code.
*/
int action_launchwindow(GtkWidget * widget, char *string)
{
	GtkWidget *parent_widget;
	variable *existing;
#ifdef DEBUG
	fprintf(stderr, "%s(): Window: %s.\n", __func__, string);
	fflush(stderr);
#endif
	/*
	 ** If the window is already opened, we give the focus to it and
	 ** will not open another instance.
	 */
	existing = variables_get_by_name(string);
	if (existing != NULL && existing->Widget != NULL) {
	/**
	* Patriot Oct 2009: Fixing the issue above also 
	* require a minor adjustment to this section.
 	**/
		parent_widget = gtk_widget_get_toplevel(existing->Widget);
		gtk_window_present(GTK_WINDOW(parent_widget));
//		gtk_window_present(GTK_WINDOW(existing->Widget)); // incorrect pointer
		return (0);
	}

	/*
	 * Let's find the source of the window.
	 */
	set_program_source(string);

	/*
	 ** We exit the gtk main loop to call the parser to interpret the
	 ** new code.
	 */
	variables_export_all();
	//gtk_main_quit();
	gtkdialog_parse();
	return 0;
}

int action_exitprogram(GtkWidget *widget, 
		char *string)
{
	print_variables(NULL);
	if (string[0] == '=')
		printf("EXIT%s", string);
	else
		printf("EXIT=\"%s\"\n", string);
	exit(EXIT_SUCCESS);
}

int action_refreshwidget(GtkWidget * widget, char *string)
{
	variables_refresh(string);
	return (0);
}

int action_savewidget(GtkWidget * widget, char *string)
{
	variables_save(string);
	return (0);
}

/*
** This function will create and open a fileselection dialog and
** connect it to the action_fileselection_made function to take
** the selected file name.
*/
#if GTK_CHECK_VERSION(2,4,0)
int 
action_fileselect(GtkWidget *widget, 
		char *string)
{
	GList                  *element;
	GtkWidget              *chooser;
	gint                    response;
	gchar                  *filename;
	gchar                  *title = NULL;
	variable               *var = variables_get_by_name(string);
	GtkFileChooserAction    action;
	gchar                  *tmp;

	/*
	 * The title of the chooser dialog.
	 */
	if (var != NULL && attributeset_is_avail(var->Attributes, ATTR_LABEL))
		title = attributeset_get_first(&element, var->Attributes, ATTR_LABEL);
	if (title == NULL)
		title = "Gtkdialog";
	/*
	 * What type of filenames are accepted?
	 */
	tmp = g_object_get_data(G_OBJECT(var->Widget), "accept");
	if (tmp != NULL) {
		if (g_ascii_strcasecmp(tmp, "filename") == 0)
			action = GTK_FILE_CHOOSER_ACTION_OPEN;
		else if(g_ascii_strcasecmp(tmp, "savefilename") == 0)
			action = GTK_FILE_CHOOSER_ACTION_SAVE;
		else if(g_ascii_strcasecmp(tmp, "directory") == 0)
			action = GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER;
		else if(g_ascii_strcasecmp(tmp, "newdirectory") == 0)
			action = GTK_FILE_CHOOSER_ACTION_CREATE_FOLDER;
		else 
			action = GTK_FILE_CHOOSER_ACTION_OPEN;
	} else {
		action = GTK_FILE_CHOOSER_ACTION_OPEN;
	}
		
	/*
	 ** We create a new chooser dialog.
	 */
	chooser = gtk_file_chooser_dialog_new(title, NULL, action, 
			GTK_STOCK_OK, GTK_RESPONSE_OK,
			GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
			NULL);
	response = gtk_dialog_run(GTK_DIALOG(chooser));
	/*
	 * If the user pressed the OK button we set the target 
	 * widget.
	 */
	switch (response) {
		case GTK_RESPONSE_CANCEL:
			/* Nothing to do */
			break;
		case GTK_RESPONSE_OK:
			filename = gtk_file_chooser_get_filename(
					GTK_FILE_CHOOSER(chooser));
			variables_set_value(string, filename);
			g_free(filename);
			break;
	}
	/* We are ready. */
	gtk_widget_destroy(chooser);
	return 0;
}

#else

int 
action_fileselect(GtkWidget *widget, 
		char *string)
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

/*
** This function is called, when the user pressed the OK button in
** a fileselection dialog.
*/
void 
action_fileselection_made(GtkWidget * w, 
		actioncommand * ac)
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

/*
** This function is called, when the user pressed the Cancel button in
** a fileselection dialog.
*/
void action_fileselection_destroy(GtkWidget * w, actioncommand * ac)
{
	/*
	 ** We destroy the fileselection dialog and free the actioncommand
	 ** memory.
	 */
	gtk_widget_destroy(ac->source_widget);
	free(ac);
}


/*
** The action is about to remove all elements from the widget.
*/
int action_clearwidget(GtkWidget * widget, char *string)
{
	variables_clear(string);
	return (0);
}

/*
** This action is about to remove the selected element from a
** widget.
*/
int action_removeselected(GtkWidget * widget, char *string)
{
	remove_selected_variable(string);
	return 0;
}

int 
action_append(GtkWidget *widget, 
		char    *string)
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

/*
*/
int action_enable(GtkWidget * widget, char *string)
{
	variables_enable(string);
	return (0);
}

/*
*/
int action_disable(GtkWidget * widget, char *string)
{
	variables_disable(string);
	return (0);
}


/*
** This fuction will export variables and run a shell command.
*/
int action_shellcommand(GtkWidget * widget, char *string)
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
