/*
 * widget_list.c: 
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
static void widget_list_input_by_command(variable *var, char *filename,
	gint command_or_file);
static void widget_list_input_by_file(variable *var, char *filename);
static void widget_list_input_by_items(variable *var);

/* Notes:
 * Using this on Puppy lupu 520:
 * 
 * find /sbin /usr -type f -exec grep -qI "gtkdialog" {} \; -print > installed_gtkdialog_apps
 * for f in `cat ./installed_gtkdialog_apps`; do grep -Hn "<list" $f; done
 * 
 * Resulted in this:
 * 
 * /usr/local/apps/pnethood/pnethood:159:    <list><height>300</height>
 * 
 * And it's only using <list> to present data (no actions) so I'm going
 * to tweak this widget (0.8.1 2012-09-09) to make it usable although it
 * appears to be well past its sell-by-date since GTK_SELECTION_MULTIPLE
 * won't work.
 */

/***********************************************************************
 * Clear                                                               *
 ***********************************************************************/

void widget_list_clear(variable *var)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#if !GTK_CHECK_VERSION(3,0,0)	/* gtk3: Deprecated in gtk2 and now gone */
	/* Thunor: This is all original code moved across when refactoring */
	gtk_list_clear_items(GTK_LIST(var->Widget), 0, -1);
#endif

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Create                                                              *
 ***********************************************************************/
GtkWidget *widget_list_create(
	AttributeSet *Attr, tag_attr *attr, gint Type)
{
	GtkWidget        *widget;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#if !GTK_CHECK_VERSION(3,0,0)	/* gtk3: Deprecated in gtk2 and now gone */
	/* Thunor: This is all original code moved across when refactoring */
	widget = gtk_list_new();
#else
	fprintf(stderr, "%s(): The list (GtkList) widget has been removed from GTK+ 3 and tree is recommended as a replacement.\n", __func__);
	exit(EXIT_FAILURE);
#endif

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return widget;
}

/***********************************************************************
 * Environment Variable All Construct                                  *
 ***********************************************************************/

gchar *widget_list_envvar_all_construct(variable *var)
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

gchar *widget_list_envvar_construct(GtkWidget *widget)
{
	GList            *item;
	gchar            *string;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#if !GTK_CHECK_VERSION(3,0,0)	/* gtk3: Deprecated in gtk2 and now gone */
	/* Thunor: 2012-09-09 GTK_SELECTION_MULTIPLE does not work. According
	 * to http://developer.gnome.org/gtk-faq/stable/c707.html, selection
	 * should return a pointer to the first selected item but it returns
	 * nothing but NULL in that mode so I can't implement it */

	/* Thunor: This is all original code moved across when refactoring */
	item = GTK_LIST(widget)->selection;
	if (item != NULL) {
		/* Thunor: Is this right? It's not being duplicated temp temp */
		string = gtk_object_get_user_data(item->data);
	} else {
		string = g_strdup("");
	}
#endif

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return string;
}

/***********************************************************************
 * Fileselect                                                          *
 ***********************************************************************/

void widget_list_fileselect(
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
void widget_list_refresh(variable *var)
{
	GList            *element;
	gchar            *act;
	gchar            *value;
	gint              initialised = FALSE;
	gint              selected_row;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#if !GTK_CHECK_VERSION(3,0,0)	/* gtk3: Deprecated in gtk2 and now gone */
	/* Get initialised state of widget */
	if (g_object_get_data(G_OBJECT(var->Widget), "_initialised") != NULL)
		initialised = (gint)g_object_get_data(G_OBJECT(var->Widget), "_initialised");

	/* The <input> tag... */
	act = attributeset_get_first(&element, var->Attributes, ATTR_INPUT);
	while (act) {
		if (input_is_shell_command(act))
			widget_list_input_by_command(var, act + 8, TRUE);
		/* input file stock = "File:", input file = "File:/path/to/file" */
		if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5) {
			if (!initialised) {
				/* Check for file-monitor and create if requested */
				widget_file_monitor_try_create(var, act + 5);
			}
			widget_list_input_by_file(var, act + 5);
		}
		act = attributeset_get_next(&element, var->Attributes, ATTR_INPUT);
	}

	/* The <item> tags... */
	if (attributeset_is_avail(var->Attributes, ATTR_ITEM))
		widget_list_input_by_items(var);

	/* Initialise these only once at start-up */
	if (!initialised) {
		/* Apply directives */
		if (attributeset_is_avail(var->Attributes, ATTR_LABEL))
			fprintf(stderr, "%s(): <label> not implemented for this widget.\n",
				__func__);
		if (attributeset_is_avail(var->Attributes, ATTR_DEFAULT))
			fprintf(stderr, "%s(): <default> not implemented for this widget.\n",
				__func__);
		if ((attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "false")) ||
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "disabled")) ||	/* Deprecated */
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "no")) ||
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "0")))
			gtk_widget_set_sensitive(var->Widget, FALSE);

		/* Connect signals */
		g_signal_connect(G_OBJECT(var->Widget), "selection-changed",
			G_CALLBACK(on_any_widget_selection_changed_event),
			(gpointer)var->Attributes);

	}

	/* Thunor: This was executed after filling by command and item
	 * so I've put it here and made it optional */
	if (var->widget_tag_attr) {
		/* Get selected-row (custom) */
		if ((value = get_tag_attribute(var->widget_tag_attr, "selected-row"))) {
			selected_row = atoi(value);
			if (selected_row >= 0)
				gtk_list_select_item(GTK_LIST(var->Widget), selected_row);
		}
	}
#endif

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Removeselected                                                      *
 ***********************************************************************/

void widget_list_removeselected(variable *var)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#if !GTK_CHECK_VERSION(3,0,0)	/* gtk3: Deprecated in gtk2 and now gone */
#ifdef DEBUG_CONTENT
	/* Thunor: 2012-09-09 GTK_SELECTION_MULTIPLE does not work. According
	 * to http://developer.gnome.org/gtk-faq/stable/c707.html, selection
	 * should return a pointer to the first selected item but it returns
	 * nothing but NULL in that mode so I can't implement it */
	GList            *items = NULL;
	items = GTK_LIST(var->Widget)->selection;
	items = g_list_first(items);
	fprintf(stderr, "%s(): items=%p\n", __func__, items);
	while (items) {
		if (GTK_IS_LIST_ITEM(items->data))
			fprintf(stderr, "%s():   items->data=%s\n", __func__,
				(gchar*)gtk_object_get_user_data(items->data));
		items = g_list_next(items);
	}
#endif

	/* Thunor: This is all original code moved across when refactoring */
	if (GTK_LIST(var->Widget)->selection != NULL)
		gtk_widget_destroy(GTK_WIDGET(GTK_LIST(var->Widget)->selection->data));
	/* Thunor: I've disabled this code.
	if (GTK_LIST(var->Widget)->children != NULL)
		gtk_list_select_item(GTK_LIST(var->Widget), 0);
	gtk_signal_emit_by_name(GTK_OBJECT(var->Widget), "selection-changed"); */
#endif

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Save                                                                *
 ***********************************************************************/

void widget_list_save(variable *var)
{
	FILE             *outfile;
	GList            *child;
	GList            *element;
	GList            *listchildren = NULL;
	gchar            *act;
	gchar            *filename = NULL;
	gchar            *string;
	gint              count = 0;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#if !GTK_CHECK_VERSION(3,0,0)	/* gtk3: Deprecated in gtk2 and now gone */
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

			/* A GtkList is simply a container full of GtkListItems with
			 * each GtkListItem containing a label. The item text is also
			 * attached to the GtkListItem widget as a piece of user data
			 * presumably because it's easier to access than digging out
			 * from the label within the GtkListItem */
			listchildren = gtk_container_get_children(GTK_CONTAINER(var->Widget));
			child = g_list_first(listchildren);
			while (child) {
				if (GTK_IS_LIST_ITEM(child->data)) {
					string = gtk_object_get_user_data(child->data);
#ifdef DEBUG_CONTENT
					fprintf(stderr, "%s(): child->data='%s'\n", __func__, string);
#endif
					if (count == 0) {
						fprintf(outfile, "%s", string);
					} else {
						fprintf(outfile, "\n%s", string);
					}
					count++;
				}
				child = child->next;
			}
			if (listchildren) {
				g_list_free(listchildren);
				listchildren = NULL;
			}

			/* Close the file */
			fclose(outfile);
		} else {
			fprintf(stderr, "%s(): Couldn't open '%s' for writing.\n",
				__func__, filename);
		}
	} else {
		fprintf(stderr, "%s(): No <output file> directive found.\n", __func__);
	}
#endif

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by Command                                                    *
 ***********************************************************************/

static void widget_list_input_by_command(variable *var, char *filename,
	gint command_or_file)
{
	FILE             *infile;
	GtkWidget        *item;
	gchar             line[512];
	gchar            *saved;
	gint              count;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#if !GTK_CHECK_VERSION(3,0,0)	/* gtk3: Deprecated in gtk2 and now gone */
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

			/* Thunor: This is all original code moved across when refactoring */
			/* Who the hell will free this memory? */
			saved = g_strdup(line);
			item = gtk_list_item_new_with_label(line);
			gtk_widget_show(item);
			gtk_object_set_user_data(GTK_OBJECT(item), (gpointer)saved);
			gtk_container_add(GTK_CONTAINER(var->Widget), item);

		}
		/* Close the file */
		pclose(infile);
	} else {
		fprintf(stderr, "%s(): Couldn't open '%s' for reading.\n", __func__,
			filename);
	}
#endif

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by File                                                       *
 ***********************************************************************/

static void widget_list_input_by_file(variable *var, char *filename)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#if !GTK_CHECK_VERSION(3,0,0)	/* gtk3: Deprecated in gtk2 and now gone */
	widget_list_input_by_command(var, filename, FALSE);
#endif

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by Items                                                      *
 ***********************************************************************/

static void widget_list_input_by_items(variable *var)
{
	GList            *element;
	GtkWidget        *item;
	gchar            *text;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#if !GTK_CHECK_VERSION(3,0,0)	/* gtk3: Deprecated in gtk2 and now gone */
	/* Thunor: This is all original code moved across when refactoring */
	g_assert(var->Attributes != NULL && var->Widget != NULL);

	text = attributeset_get_first(&element, var->Attributes, ATTR_ITEM);
	if (text == NULL)
		return;

	while (text != NULL) {
		item = gtk_list_item_new_with_label(text);
		/* Thunor: 2011-09-08: Refreshing items should work the same way
		 * as refreshing data from a command but there is an instruction
		 * missing here and it is this:
		 * 
		 * gtk_widget_show(item);
		 * 
		 * The problem is that if I add it then it could uncover errors
		 * in people's applications or there may exist applications that
		 * are designed around the fact that cleared items won't reappear
		 * but data from a command will. Therefore I'm not fixing it.
		 * 
		 * [UPDATE] 2012-09-08 (exactly a year later!)
		 * I've added it */
		gtk_widget_show(item);
		gtk_object_set_user_data(GTK_OBJECT(item), (gpointer)text);
		gtk_container_add(GTK_CONTAINER(var->Widget), item);
		text = attributeset_get_next(&element, var->Attributes, ATTR_ITEM);
	}
#endif

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}
