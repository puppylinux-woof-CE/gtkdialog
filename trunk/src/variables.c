/*
 * variables.c:
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

#include "config.h"
#include "gtkdialog.h"
#include "variables.h"
#include "widgets.h"
#include "widget_button.h"
#include "widget_checkbox.h"
#include "widget_colorbutton.h"
#include "widget_combobox.h"
#include "widget_comboboxtext.h"
#include "widget_edit.h"
#include "widget_entry.h"
#include "widget_eventbox.h"
#include "widget_expander.h"
#include "widget_fontbutton.h"
#include "widget_frame.h"
#include "widget_hbox.h"
#include "widget_hscale.h"
#include "widget_hseparator.h"
#include "widget_list.h"
#include "widget_menubar.h"
#include "widget_menuitem.h"
#include "widget_notebook.h"
#include "widget_pixmap.h"
#include "widget_progressbar.h"
#include "widget_radiobutton.h"
#include "widget_spinbutton.h"
#include "widget_statusbar.h"
#include "widget_table.h"
#include "widget_terminal.h"
#include "widget_text.h"
#include "widget_timer.h"
#include "widget_tree.h"
#include "widget_vbox.h"
#include "widget_window.h"
#include "tag_attributes.h"
#if HAVE_SYS_INOTIFY_H
#include <sys/inotify.h>
#endif

extern gboolean option_no_warning;

/* Local function prototypes */
#ifdef DEBUG
void variables_print_one(variable *var);
#endif
variable *variables_new(const char *name);
/* Redundant: Not being used: variable *variables_set_widget(const char *name, GtkWidget *widget); */
/* Redundant: Not being used: variable *variables_set_parent(const char *name, GtkWidget *parent); */
/* Redundant: Not being used: variable *variables_set_type(const char *name, int type); */
gboolean variables_is_avail_by_name(const char *name);
int _tree_insert(variable *new, variable *actual);
static variable *_tree_find(const char *name, variable *actual);
static gint do_variables_count_widgets(variable *actual, gint n);
static variable *do_find_variable_by_widget(variable *actual, GtkWidget *widget);
static void _variables_initialize(variable *actual);
static void _variables_export(variable * actual);
#ifdef DEBUG
void variables_print_debug(variable *actual);
#endif

variable *root = NULL;

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

#ifdef DEBUG
void variables_print_one(variable *var)
{
	fprintf(stderr, "Name: %s\n", var->Name);
	fprintf(stderr, "  Widget: %p\n", var->Widget);
	fprintf(stderr, "  Type: %s\n", widgets_to_str(var->Type));
	fprintf(stderr, "  Parent: %p\n", var->ParentWindow);
	fflush(stderr);
}
#endif

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* This function will create a new variable */

variable *variables_new(const char *name)
{
	variable *new;

#ifdef DEBUG
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* 
	 ** If the variable exists we simply returns without making a 
	 ** a warning. 
	 */
	if (variables_is_avail_by_name(name))
		return (variables_get_by_name(name));

	new = g_malloc(sizeof(variable));
	strncpy(new->Name, name, NAMELEN);
	/* 
	 ** Setting the defaults for this variable.
	 */
	new->Widget = NULL;
	new->window_id = 0;
	new->Attributes = NULL;
	new->Type = 0;
	new->row = -1;
	new->column = -1;
	new->ncolumns = -1;

	new->left = NULL;
	new->right = NULL;

	_tree_insert(new, NULL);

#ifdef DEBUG
	fprintf(stderr, "%s(): Name=%s\n", __func__, new->Name);
#endif

#ifdef DEBUG
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return new;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* This function will create a new variable with widget and type.
 * 
 * Thunor: The way in which this operates is flawed but it works:
 * Attempting to create a variable with a duplicate name results in the
 * original variable's widget pointer being overwritten and in fact all
 * of the original widget's attributes will be overwritten too. So if
 * you call find_variable_by_widget() you'll get NULL for the original
 * widget and in any case surely the application will be compromised?
 * 
 * Now, if you try to enforce unique variable names you'll encounter a
 * problem in that launched windows' widget's are destroyed but their
 * variables aren't, and if you launch the same window again then the
 * variables will already exist and an attempt will be made to recreate
 * them but because they already exist they'll be reused, therefore
 * enforcing unique variable names is not going to be possible.
 * 
 * Basically you have accept that the system has been designed to reuse
 * variables even though it could result in widgets with NULL variables
 * and a compromised application.
 * 
 * It's not even possible to detect duplicate variable names after the
 * initial window has been created so it's pointless making the effort
 * to warn the user.
 */

variable *variables_new_with_widget(AttributeSet *Attr,
	tag_attr *widget_tag_attr, GtkWidget *widget, int type)
{
	GList *element;
	char *name;
	variable *var;
	int autonamed = FALSE;

#ifdef DEBUG
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	g_assert(Attr != NULL);
	g_assert(widget != NULL);

	/*
	 ** If the widget have no name we create a default one for it.
	 */
	if (!attributeset_is_avail(Attr, ATTR_VARIABLE)) {
		attributeset_insert(Attr,
				    ATTR_VARIABLE,
				    (char *) str_default_name(type));
		autonamed = TRUE;
	}

	name = attributeset_get_first(&element, Attr, ATTR_VARIABLE);

	/* 
	 ** If the variable exists we simply returns without making a 
	 ** a warning.
	 */
	if (!variables_is_avail_by_name(name)) {
		var = variables_new(name);
	} else {
		var = variables_get_by_name(name);
	}

	g_assert(var != NULL);

	var->Widget = widget;
	var->window_id = window_id;
	var->Type = type;
	var->Attributes = Attr;
	var->widget_tag_attr = widget_tag_attr;
	var->autonamed = autonamed;

#ifdef DEBUG
	fprintf(stderr, "%s(): Name=%s Widget=%p window_id=%i Type=%i\n",
		__func__, var->Name, var->Widget, var->window_id, var->Type);
#endif

#ifdef DEBUG
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return (var);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

/* Redundant: Not being used.
variable *variables_set_widget(const char *name, GtkWidget *widget)
{
	variable *var;
#ifdef DEBUG
	g_message("%s(): variable '%s'.", __func__, name);
#endif
	var = variables_get_by_name(name);
	if (var == NULL)
		var = variables_new(name);

	var->Widget = widget;
	return (var);
} */

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

/* Redundant: Not being used.
#if 0
variable *variables_set_parent(const char *name, GtkWidget *parent)
{
	variable *var;
#ifdef DEBUG
	g_message("%s(): Start with '%s'", __func__, name);
#endif
	var = variables_get_by_name(name);
	if (var == NULL)
		var = variables_new(name);

	var->ParentWindow = parent;
#ifdef DEBUG
	g_message("%s(): End with '%s'", __func__, name);
#endif
	return var;
}
#endif */

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

/* Redundant: Not being used.
variable *variables_set_type(const char *name, int type)
{
	variable *var;
#ifdef DEBUG
	fprintf(stderr, "%s(): variable '%s'.\n", __func__, name);
	fflush(stderr);
#endif
	var = variables_get_by_name(name);
	if (var == NULL)
		var = variables_new(name);

	var->Type = type;
	return (var);
} */

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

variable *variables_set_attributes(const char *name, AttributeSet *a)
{
	variable *var;
#ifdef DEBUG
	g_message("%s(): start '%s'", __func__, name);
#endif
	var = variables_get_by_name(name);
	if (var == NULL)
		var = variables_new(name);

	var->Attributes = a;
	return (var);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

variable *variables_set_row_column(const char *name, int row, int column)
{
	variable *toset;
#ifdef DEBUG
	fprintf(stderr, "%s(): variable: %s\n", __func__, name);
	fflush(stderr);
#endif
	toset = _tree_find(name, NULL);
	if (toset == NULL)
		return (NULL);

	toset->row = row;
	toset->column = column;
	return (toset);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* This function will set the value of the given variable. This means
 * that it will set a widget's data or insert data to the widget as the
 * type of the widget makes clear */

variable *variables_set_value(const char *name, const char *value)
{
	variable         *toset;
	gchar            *string;

#ifdef DEBUG
	fprintf(stderr, "%s(): variable '%s'.\n", __func__, name);
	fflush(stderr);
#endif
	g_assert(name != NULL && value != NULL);
	
	toset = _tree_find(name, NULL);

	if (toset == NULL)
		return (NULL);

	/* If the custom attribute "block-function-signals" is true
	 * then block signals whilst performing this function */
	if (toset->widget_tag_attr &&
		((string = get_tag_attribute(toset->widget_tag_attr, "block-function-signals"))) &&
		((strcasecmp(string, "true") == 0) || (strcasecmp(string, "yes") == 0) ||
		(atoi(string) == 1))) {
		GTKD_FUNCTION_SIGNALS_BLOCK;
	}

	switch (toset->Type) {
		case WIDGET_CANCELBUTTON:
		case WIDGET_HELPBUTTON:
		case WIDGET_NOBUTTON:
		case WIDGET_OKBUTTON:
		case WIDGET_YESBUTTON:
		case WIDGET_TOGGLEBUTTON:
		case WIDGET_BUTTON:
			widget_button_fileselect(toset, name, value);
			break;
		case WIDGET_CHECKBOX:
			widget_checkbox_fileselect(toset, name, value);
			break;
		case WIDGET_COLORBUTTON:
			widget_colorbutton_fileselect(toset, name, value);
			break;
		case WIDGET_COMBOBOX:
			widget_combobox_fileselect(toset, name, value);
			break;
		case WIDGET_COMBOBOXENTRY:
		case WIDGET_COMBOBOXTEXT:
			widget_comboboxtext_fileselect(toset, name, value);
			break;
		case WIDGET_EDIT:
			widget_edit_fileselect(toset, name, value);
			break;
		case WIDGET_ENTRY:
			widget_entry_fileselect(toset, name, value);
			break;
		case WIDGET_EVENTBOX:
			widget_eventbox_fileselect(toset, name, value);
			break;
		case WIDGET_EXPANDER:
			widget_expander_fileselect(toset, name, value);
			break;
		case WIDGET_FONTBUTTON:
			widget_fontbutton_fileselect(toset, name, value);
			break;
		case WIDGET_FRAME:
			widget_frame_fileselect(toset, name, value);
			break;
		case WIDGET_HBOX:
			widget_hbox_fileselect(toset, name, value);
			break;
		case WIDGET_HSCALE:
		case WIDGET_VSCALE:
			widget_hscale_fileselect(toset, name, value);
			break;
		case WIDGET_HSEPARATOR:
		case WIDGET_VSEPARATOR:
			widget_hseparator_fileselect(toset, name, value);
			break;
		case WIDGET_LIST:
			widget_list_fileselect(toset, name, value);
			break;
		case WIDGET_MENUBAR:
			widget_menubar_fileselect(toset, name, value);
			break;
		case WIDGET_MENUITEMSEPARATOR:
		case WIDGET_MENUITEM:
		case WIDGET_MENU:
			widget_menuitem_fileselect(toset, name, value);
			break;
		case WIDGET_NOTEBOOK:
			widget_notebook_fileselect(toset, name, value);
			break;
		case WIDGET_PIXMAP:
			widget_pixmap_fileselect(toset, name, value);
			break;
		case WIDGET_PROGRESSBAR:
			widget_progressbar_fileselect(toset, name, value);
			break;
		case WIDGET_RADIOBUTTON:
			widget_radiobutton_fileselect(toset, name, value);
			break;
		case WIDGET_SPINBUTTON:
			widget_spinbutton_fileselect(toset, name, value);
			break;
		case WIDGET_STATUSBAR:
			widget_statusbar_fileselect(toset, name, value);
			break;
		case WIDGET_TABLE:
			widget_table_fileselect(toset, name, value);
			break;
		case WIDGET_TERMINAL:
			widget_terminal_fileselect(toset, name, value);
			break;
		case WIDGET_TEXT:
			widget_text_fileselect(toset, name, value);
			break;
		case WIDGET_TIMER:
			widget_timer_fileselect(toset, name, value);
			break;
#if GTK_CHECK_VERSION(2,4,0)
		case WIDGET_TREE:
			widget_tree_fileselect(toset, name, value);
			break;
#endif
		case WIDGET_VBOX:
			widget_vbox_fileselect(toset, name, value);
			break;
		case WIDGET_WINDOW:
			widget_window_fileselect(toset, name, value);
			break;
		default:
			yywarning("Set-value not implemented for this widget.");
	}

	GTKD_FUNCTION_SIGNALS_RESET;

	return (toset);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

variable *variables_save(const char *name)
{
	variable *var;
	var = _tree_find(name, NULL);
	if (var == NULL)
		return (NULL);

	if (var->Widget == NULL)
		return (NULL);

	switch (var->Type) {
		case WIDGET_CANCELBUTTON:
		case WIDGET_HELPBUTTON:
		case WIDGET_NOBUTTON:
		case WIDGET_OKBUTTON:
		case WIDGET_YESBUTTON:
		case WIDGET_TOGGLEBUTTON:
		case WIDGET_BUTTON:
			widget_button_save(var);
			break;
		case WIDGET_CHECKBOX:
			widget_checkbox_save(var);
			break;
		case WIDGET_COLORBUTTON:
			widget_colorbutton_save(var);
			break;
		case WIDGET_COMBOBOX:
			widget_combobox_save(var);
			break;
		case WIDGET_COMBOBOXENTRY:
		case WIDGET_COMBOBOXTEXT:
			widget_comboboxtext_save(var);
			break;
		case WIDGET_EDIT:
			widget_edit_save(var);
			break;
		case WIDGET_ENTRY:
			widget_entry_save(var);
			break;
		case WIDGET_EVENTBOX:
			widget_eventbox_save(var);
			break;
		case WIDGET_EXPANDER:
			widget_expander_save(var);
			break;
		case WIDGET_FONTBUTTON:
			widget_fontbutton_save(var);
			break;
		case WIDGET_FRAME:
			widget_frame_save(var);
			break;
		case WIDGET_HBOX:
			widget_hbox_save(var);
			break;
		case WIDGET_HSCALE:
		case WIDGET_VSCALE:
			widget_hscale_save(var);
			break;
		case WIDGET_HSEPARATOR:
		case WIDGET_VSEPARATOR:
			widget_hseparator_save(var);
			break;
		case WIDGET_LIST:
			widget_list_save(var);
			break;
		case WIDGET_MENUBAR:
			widget_menubar_save(var);
			break;
		case WIDGET_MENUITEMSEPARATOR:
		case WIDGET_MENUITEM:
		case WIDGET_MENU:
			widget_menuitem_save(var);
			break;
		case WIDGET_NOTEBOOK:
			widget_notebook_save(var);
			break;
		case WIDGET_PIXMAP:
			widget_pixmap_save(var);
			break;
		case WIDGET_PROGRESSBAR:
			widget_progressbar_save(var);
			break;
		case WIDGET_RADIOBUTTON:
			widget_radiobutton_save(var);
			break;
		case WIDGET_SPINBUTTON:
			widget_spinbutton_save(var);
			break;
		case WIDGET_STATUSBAR:
			widget_statusbar_save(var);
			break;
		case WIDGET_TABLE:
			widget_table_save(var);
			break;
		case WIDGET_TERMINAL:
			widget_terminal_save(var);
			break;
		case WIDGET_TEXT:
			widget_text_save(var);
			break;
		case WIDGET_TIMER:
			widget_timer_save(var);
			break;
#if GTK_CHECK_VERSION(2,4,0)
		case WIDGET_TREE:
			widget_tree_save(var);
			break;
#endif
		case WIDGET_VBOX:
			widget_vbox_save(var);
			break;
		case WIDGET_WINDOW:
			widget_window_save(var);
			break;
		default:
			yywarning("Save not implemented for this widget.");
	}
	return (var);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* This function will actualize the variable by reinitializing widget */

variable *variables_refresh(const char *name)
{
	variable         *var;
	gchar            *string;
	gint              initialised = FALSE;

	g_assert(name != NULL);

#ifdef DEBUG
	g_message("%s(%s)", __func__, name);
#endif

	var = _tree_find(name, NULL);

	if (var == NULL || var->Widget == NULL)
		return NULL;

	g_assert(var->Attributes != NULL);

	/* Get initialised state of widget */
	if (g_object_get_data(G_OBJECT(var->Widget), "_initialised") != NULL)
		initialised = (gint)g_object_get_data(G_OBJECT(var->Widget), "_initialised");

	/* If the custom attribute "block-function-signals" is true
	 * then block signals whilst performing this function */
	if (var->widget_tag_attr &&
		((string = get_tag_attribute(var->widget_tag_attr, "block-function-signals"))) &&
		((strcasecmp(string, "true") == 0) || (strcasecmp(string, "yes") == 0) ||
		(atoi(string) == 1))) {
		GTKD_FUNCTION_SIGNALS_BLOCK;
	}

	switch (var->Type) {
		case WIDGET_CANCELBUTTON:
		case WIDGET_HELPBUTTON:
		case WIDGET_NOBUTTON:
		case WIDGET_OKBUTTON:
		case WIDGET_YESBUTTON:
		case WIDGET_TOGGLEBUTTON:
		case WIDGET_BUTTON:
			widget_button_refresh(var);
			break;
		case WIDGET_CHECKBOX:
			widget_checkbox_refresh(var);
			break;
		case WIDGET_COLORBUTTON:
			widget_colorbutton_refresh(var);
			break;
		case WIDGET_COMBOBOX:
			widget_combobox_refresh(var);
			break;
		case WIDGET_COMBOBOXENTRY:
		case WIDGET_COMBOBOXTEXT:
			widget_comboboxtext_refresh(var);
			break;
		case WIDGET_EDIT:
			widget_edit_refresh(var);
			break;
		case WIDGET_ENTRY:
			widget_entry_refresh(var);
			break;
		case WIDGET_EVENTBOX:
			widget_eventbox_refresh(var);
			break;
		case WIDGET_EXPANDER:
			widget_expander_refresh(var);
			break;
		case WIDGET_FONTBUTTON:
			widget_fontbutton_refresh(var);
			break;
		case WIDGET_FRAME:
			widget_frame_refresh(var);
			break;
		case WIDGET_HBOX:
			widget_hbox_refresh(var);
			break;
		case WIDGET_HSCALE:
		case WIDGET_VSCALE:
			widget_hscale_refresh(var);
			break;
		case WIDGET_HSEPARATOR:
		case WIDGET_VSEPARATOR:
			widget_hseparator_refresh(var);
			break;
		case WIDGET_LIST:
			widget_list_refresh(var);
			break;
		case WIDGET_MENUBAR:
			widget_menubar_refresh(var);
			break;
		case WIDGET_MENUITEMSEPARATOR:
		case WIDGET_MENUITEM:
		case WIDGET_MENU:
			widget_menuitem_refresh(var);
			break;
		case WIDGET_NOTEBOOK:
			widget_notebook_refresh(var);
			break;
		case WIDGET_PIXMAP:
			widget_pixmap_refresh(var);
			break;
		case WIDGET_PROGRESSBAR:
			widget_progressbar_refresh(var);
			break;
		case WIDGET_RADIOBUTTON:
			widget_radiobutton_refresh(var);
			break;
		case WIDGET_SPINBUTTON:
			widget_spinbutton_refresh(var);
			break;
		case WIDGET_STATUSBAR:
			widget_statusbar_refresh(var);
			break;
		case WIDGET_TABLE:
			widget_table_refresh(var);
			break;
		case WIDGET_TERMINAL:
			widget_terminal_refresh(var);
			break;
		case WIDGET_TEXT:
			widget_text_refresh(var);
			break;
		case WIDGET_TIMER:
			widget_timer_refresh(var);
			break;
#if GTK_CHECK_VERSION(2,4,0)
		case WIDGET_TREE:
			widget_tree_refresh(var);
			break;
#endif
		case WIDGET_VBOX:
			widget_vbox_refresh(var);
			break;
		case WIDGET_WINDOW:
			widget_window_refresh(var);
			break;
		default:
			if (initialised)
				yywarning("Refresh not implemented for this widget.");
			break;
	}

	if (!initialised) {
		/* Store "initialised" as a piece of widget data to record that
		 * this widget has been through this function at start-up */
		g_object_set_data(G_OBJECT(var->Widget), "_initialised", (gpointer)1);
	}

	GTKD_FUNCTION_SIGNALS_RESET;

#ifdef DEBUG
	g_message("%s(): end", __func__);
#endif

	return var;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

variable *variables_enable(const char *name)
{
	variable *var;
#ifdef DEBUG
	fprintf(stderr, "%s(): %s\n", __func__, name);
	fflush(stderr);
#endif
	var = _tree_find(name, NULL);
	if (var == NULL)
		return (NULL);
	if (var->Widget == NULL)
		return (NULL);

	gtk_widget_set_sensitive(var->Widget, TRUE);
	return (var);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

variable *variables_disable(const char *name)
{
	variable *var;
#ifdef DEBUG
	fprintf(stderr, "%s(): %s\n", __func__, name);
	fflush(stderr);
#endif
	var = _tree_find(name, NULL);
	if (var == NULL)
		return (NULL);
	if (var->Widget == NULL)
		return (NULL);

	gtk_widget_set_sensitive(var->Widget, FALSE);
	return (var);
}

/***********************************************************************
 * Variables show                                                      *
 ***********************************************************************/

variable *variables_show(const char *name)
{
	GtkWidget        *grandparent = NULL;
	GtkWidget        *parent = NULL;
	variable         *var;

#ifdef DEBUG
	fprintf(stderr, "%s(): %s\n", __func__, name);
	fflush(stderr);
#endif

	var = _tree_find(name, NULL);
	if (var == NULL)
		return (NULL);
	if (var->Widget == NULL)
		return (NULL);

	/* The widget could be inside a scrolled window or inside a viewport
	 * inside a scrolled window so we need to show all of the widgets */
	parent = gtk_widget_get_parent(var->Widget);
	if (parent) grandparent = gtk_widget_get_parent(parent);

	if (!(parent && ((GTK_IS_SCROLLED_WINDOW(parent)) ||
		(GTK_IS_VIEWPORT(parent))))) parent = NULL;

	if (!(parent && (GTK_IS_VIEWPORT(parent)) && grandparent &&
		GTK_IS_SCROLLED_WINDOW(grandparent))) grandparent = NULL;

	if (grandparent)
		gtk_widget_show(grandparent);

	if (parent)
		gtk_widget_show(parent);

	if (var->Type == WIDGET_BUTTON) {
		/* Button widgets can have up to four added child widgets */
		gtk_widget_show_all(var->Widget);
	} else if (var->Type == WIDGET_FRAME) {
		/* Frame widgets have an added child widget */
		gtk_widget_show(gtk_bin_get_child(GTK_BIN(var->Widget)));
		gtk_widget_show(var->Widget);
	} else {
		gtk_widget_show(var->Widget);
	}

	return (var);
}

/***********************************************************************
 * Variables hide                                                      *
 ***********************************************************************/

variable *variables_hide(const char *name)
{
	GtkWidget        *grandparent = NULL;
	GtkWidget        *parent = NULL;
	variable         *var;

#ifdef DEBUG
	fprintf(stderr, "%s(): %s\n", __func__, name);
	fflush(stderr);
#endif

	var = _tree_find(name, NULL);
	if (var == NULL)
		return (NULL);
	if (var->Widget == NULL)
		return (NULL);

	/* The widget could be inside a scrolled window or inside a viewport
	 * inside a scrolled window so we need to hide all of the widgets */
	parent = gtk_widget_get_parent(var->Widget);
	if (parent) grandparent = gtk_widget_get_parent(parent);

	if (!(parent && ((GTK_IS_SCROLLED_WINDOW(parent)) ||
		(GTK_IS_VIEWPORT(parent))))) parent = NULL;

	if (!(parent && (GTK_IS_VIEWPORT(parent)) && grandparent &&
		GTK_IS_SCROLLED_WINDOW(grandparent))) grandparent = NULL;

#ifdef DEBUG
	fprintf(stderr, "%s(): Hiding widget\n", __func__);
#endif
	gtk_widget_hide(var->Widget);

	if (parent) {
#ifdef DEBUG
		fprintf(stderr, "%s(): Hiding parent\n", __func__);
#endif
		gtk_widget_hide(parent);
	}

	if (grandparent) {
#ifdef DEBUG
		fprintf(stderr, "%s(): Hiding grandparent\n", __func__);
#endif
		gtk_widget_hide(grandparent);
	}

/* Redundant
	parent = gtk_widget_get_parent(var->Widget);
	if (parent != NULL) grandparent = gtk_widget_get_parent(parent);

	if (parent != NULL && GTK_IS_SCROLLED_WINDOW(parent)) {
		gtk_widget_hide(parent);
	} else if (parent != NULL && GTK_IS_VIEWPORT(parent)) {
		/$ A viewport will always be inside a scrolled window $/
		if (grandparent != NULL && GTK_IS_SCROLLED_WINDOW(grandparent)) {
			gtk_widget_hide(grandparent);
		}
	} else {
		gtk_widget_hide(var->Widget);
	}*/

	return (var);
}

/***********************************************************************
 * Variables activate                                                  *
 ***********************************************************************/

variable *variables_activate(const char *name)
{
	gboolean  retval;
	variable *var;

#ifdef DEBUG
	fprintf(stderr, "%s(): %s\n", __func__, name);
	fflush(stderr);
#endif

	var = _tree_find(name, NULL);
	if (var == NULL)
		return (NULL);
	if (var->Widget == NULL)
		return (NULL);

	retval = gtk_widget_activate(var->Widget);

	if (!retval)
		fprintf(stderr, "%s(): %s is not an activatable widget.\n", __func__, name);

	return (var);
}

/***********************************************************************
 * Variables grabfocus                                                 *
 ***********************************************************************/

variable *variables_grabfocus(const char *name)
{
	variable *var;

#ifdef DEBUG
	fprintf(stderr, "%s(): %s\n", __func__, name);
	fflush(stderr);
#endif

	var = _tree_find(name, NULL);
	if (var == NULL)
		return (NULL);
	if (var->Widget == NULL)
		return (NULL);

	gtk_widget_grab_focus(var->Widget);

	return (var);
}

/***********************************************************************
 * Variables presentwindow                                             *
 ***********************************************************************/

variable *variables_presentwindow(const char *name)
{
	variable *var;

#ifdef DEBUG
	fprintf(stderr, "%s(): %s\n", __func__, name);
	fflush(stderr);
#endif

	var = _tree_find(name, NULL);
	if (var == NULL)
		return (NULL);
	if (var->Widget == NULL)
		return (NULL);

	gtk_window_present(GTK_WINDOW(var->Widget));

	return (var);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean variables_is_avail_by_name(const char *name)
{
	if (_tree_find(name, NULL) == NULL)
		return (FALSE);
	else
		return (TRUE);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

variable *variables_get_by_name(const char *name)
{
	return _tree_find(name, NULL);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* This function inserts a new tree node. The node must have a unique
 * name or the function will abort the program */

int _tree_insert(variable *new, variable *actual)
{
	int compare;
	if (new == NULL) {
		fprintf(stderr, "%s(): Inserting a NULL element.\n", __func__);
		exit(EXIT_FAILURE);
	}

	if (root == NULL) {
		root = new;
		return (0);
	}

	if (actual == NULL)
		actual = root;

	compare = strncmp(new->Name, actual->Name, NAMELEN);

	if (compare == 0) {
		fprintf(stderr, "%s(): Inserting existing variable: '%s'.",
			__func__, new->Name);
		exit(EXIT_FAILURE);
	}

	if (compare < 0)
		if (actual->left == NULL) {
			actual->left = new;
			return (0);
		} else {
			return (_tree_insert(new, actual->left));
		}

	if (compare > 0)
		if (actual->right == NULL) {
			actual->right = new;
			return (0);
		} else {
			return (_tree_insert(new, actual->right));
		}
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* This function finds the variable by its name and returns the pointer
 * to it */

static variable *_tree_find(const char *name, variable *actual)
{
	int compare;

	if (actual == NULL)
		actual = root;
	if (actual == NULL)
		return NULL;

	compare = strcmp(name, actual->Name);

	if (compare == 0)
		return (actual);

	if (compare < 0)
		if (actual->left != NULL)
			return _tree_find(name, actual->left);
		else
			return NULL;

	if (compare > 0)
		if (actual->right != NULL)
			return _tree_find(name, actual->right);
		else
			return NULL;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

static gint do_variables_count_widgets(variable *actual, gint n)
{
	if (actual == NULL)
		actual = root;

	if (actual == NULL)
		return;

	if (actual->left != NULL)
		n = do_variables_count_widgets(actual->left, n);

	if (actual->Widget != NULL) 
		++n;

	if (actual->right != NULL)
		n = do_variables_count_widgets(actual->right, n);

	return n;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gint variables_count_widgets(void) 
{
	return do_variables_count_widgets(NULL, 0);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* This function will drop all the widgets with the given parent */

void variables_drop_by_window_id(variable *actual, gint window_id)
{
	gint              index = 0;
#if HAVE_SYS_INOTIFY_H
	gchar             fdname[16];
	gchar             wdname[16];
	gint              fd, wd;
#else
	GFileMonitor     *monitor;
	gchar             name[16];
#endif

#ifdef DEBUG
	GtkWidget *ancestor;
#endif

#ifdef DEBUG
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (actual == NULL) actual = root;

	if (actual != NULL) {

		if (actual->left != NULL)
			variables_drop_by_window_id(actual->left, window_id);

		if (actual->Widget != NULL) {

#ifdef DEBUG
			fprintf(stderr, "%s(): Name=%s Widget=%p window_id=%i Type=%i\n",
				__func__, actual->Name, actual->Widget, actual->window_id, actual->Type);
#endif

			g_assert(GTK_IS_WIDGET(actual->Widget));

#ifdef DEBUG
			ancestor = gtk_widget_get_parent(actual->Widget);
			fprintf(stderr, "%s(): ancestor1=%p\n", __func__, ancestor);
			if (ancestor) ancestor = gtk_widget_get_parent(ancestor);
			fprintf(stderr, "%s(): ancestor2=%p\n", __func__, ancestor);
			if (ancestor) ancestor = gtk_widget_get_parent(ancestor);
			fprintf(stderr, "%s(): ancestor3=%p\n", __func__, ancestor);
			if (ancestor) ancestor = gtk_widget_get_parent(ancestor);
			fprintf(stderr, "%s(): ancestor4=%p\n", __func__, ancestor);
#endif

			//Redundant: if (gtk_widget_get_toplevel(actual->Widget) == Parent) {
			//Redundant: if (gtk_widget_get_ancestor(actual->Widget, GTK_TYPE_WINDOW) == Parent) {
			if (actual->window_id == window_id) {

				/* Timer callbacks cancel themselves when they
				 * detect that var and var->widget are NULL */

				/* Cancel any existing file monitors */
#if HAVE_SYS_INOTIFY_H
				while (TRUE) {
					sprintf(fdname, "_inotifyfd%i", index);
					sprintf(wdname, "_inotifywd%i", index);
					if ((g_object_get_data(G_OBJECT(actual->Widget), fdname)) &&
						(g_object_get_data(G_OBJECT(actual->Widget), wdname))) {
						fd = (gint)g_object_get_data(G_OBJECT(actual->Widget),
							fdname);
						wd = (gint)g_object_get_data(G_OBJECT(actual->Widget),
							wdname);
#ifdef DEBUG
						fprintf(stderr, "%s(): fd=%i wd=%i\n", __func__,
							fd, wd);
#endif
						inotify_rm_watch(fd, wd);
					} else {
						break;
					}
					index++;
				}
#else
				while (TRUE) {
					sprintf(name, "_monitor%i", index);
					monitor = g_object_get_data(G_OBJECT(actual->Widget), name);
					if (monitor) {
#ifdef DEBUG
						fprintf(stderr, "%s(): cancelling %s\n", __func__, name);
#endif
						g_file_monitor_cancel(monitor);
						g_object_unref(monitor);
						/* I don't have access to file to unref it */
					} else {
						break;
					}
					index++;
				}
#endif

				actual->Widget = NULL;

#ifdef DEBUG
				fprintf(stderr, "%s(): Name=%s Widget=%p window_id=%i Type=%i\n",
					__func__, actual->Name, actual->Widget, actual->window_id, actual->Type);
#endif

			}
		}

		if (actual->right != NULL)
			variables_drop_by_window_id(actual->right, window_id);

	}

#ifdef DEBUG
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

static variable *do_find_variable_by_widget(variable *actual,
	GtkWidget *widget)
{
	variable *found;

	if (actual == NULL)
		return NULL;
	
	if (actual->left != NULL) {
		found = do_find_variable_by_widget(actual->left, widget);
		if (found != NULL)
			return found;
	}
	
	if (actual->Widget == widget)
		return actual;

	if (actual->right != NULL) {
		return do_find_variable_by_widget(actual->right, widget);
	}

	return NULL;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

variable *find_variable_by_widget(GtkWidget *widget)
{
	return do_find_variable_by_widget(root, widget);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void variables_initialize_all(void)
{
	_variables_initialize(NULL);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
static void _variables_initialize(variable *actual)
{
	GList *element;
#if !GTK_CHECK_VERSION(3,0,0)	/* gtk3: Redundant: WIDGET_GVIM is being purged */
	char *socket_id;
#endif
	char command[128];
	int result;

#ifdef DEBUG
	fprintf(stderr, "%s: Start.\n", __func__);
	fflush(stderr);
#endif

	if (actual == NULL)
		actual = root;
	if (actual == NULL)
		return;

	if (actual->left != NULL)
		_variables_initialize(actual->left);

#if !GTK_CHECK_VERSION(3,0,0)	/* gtk3: Redundant: WIDGET_GVIM is being purged */
	if (actual->Widget != NULL && actual->Type == WIDGET_GVIM) {
		gtk_widget_show(actual->Widget);
		socket_id = attributeset_get_first(&element, actual->Attributes,
			ATTR_SOCKET);
		//printf("----->%p\n", actual->Widget->window); 
		//printf("----->%x\n", atoi(socket_id));        
		if (socket_id != NULL) {
			sprintf(command, "gvim --socketid %s &",
				socket_id);
			result = system(command);
		} else {
			yywarning("Socket ID is NULL\n");
		}
	}
#endif

	if (actual->right != NULL)
		_variables_initialize(actual->right);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* This function will export the variables as environment variables */

void variables_export_all(void)
{
	_variables_export(NULL);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

static void _variables_export(variable *actual)
{
	GList            *element;
	gchar            *act;
	gchar            *line;
	gchar            *value;
	gint              export = TRUE;

#ifdef DEBUG
	g_message("%s(%p)", __func__, actual);
#endif

	if (actual == NULL)
		actual = root;
	if (actual == NULL)
		return;

#ifdef DEBUG
	g_message("    actual->name = '%s'", actual->Name);
#endif

	if (actual->left != NULL)
		_variables_export(actual->left);

	/* Thunor: It's now possible to prevent the exporting of declared
	 * variables by using <variable export="false">VARNAME</variable> */
	if ((act = attributeset_get_first(&element, actual->Attributes,
		ATTR_VARIABLE)) &&
		(value = attributeset_get_this_tagattr(&element, actual->Attributes,
		ATTR_VARIABLE, "export")) &&
		((strcasecmp(value, "false") == 0) ||
		(strcasecmp(value, "no") == 0) ||
		(strcasecmp(value, "0") == 0))) {
		export = FALSE;
#ifdef DEBUG
		fprintf(stderr, "%s(): variable=%s export=%s\n",
			__func__, act, value);
#endif
	}

	/* Thunor: I've stopped this from exporting autonamed variables
	 * because it's pointless and will affect performance. There's no
	 * reason why this should export them when print_variables() doesn't
	 * so it's a bug -- the developer wouldn't even know they existed.
	if (actual->Widget != NULL) { */
	if (actual->Widget != NULL && !actual->autonamed && export) {
		//
		// To export only the active element
		//
		value = widget_get_text_value(actual->Widget, actual->Type);

		/* Redundant.
		 ** FIXME: awfull
		 *
		if (actual->Type == WIDGET_TABLE && actual->row != -1) {
			gtk_clist_get_text(GTK_CLIST(actual->Widget),
					   actual->row, 0, &value);
		} */

		if (value != NULL) {
			line = g_strdup_printf("%s=%s", actual->Name, value);
			putenv(line);
		}

		/* Thunor: I've disabled this for performance reasons. Zigbert was
		 * experiencing terrible table performance which I've tested too.
		 * Initially it may have been practicable with simple dialogs to
		 * dump the entire contents of a widget on every signal, but it
		 * definitely isn't anymore */
#if 0
		//
		// To export all of the elements in the list
		//
		switch (actual->Type) {
			case WIDGET_LIST:
				line = g_strdup_printf("%s_ALL=\"", actual->Name);
				itemlist = GTK_LIST(actual->Widget)->children;
				n = 0;
				while (itemlist != NULL) {
					/* Thunor: Well, here's the bug that was making the
					 * list widget hang: I think it was assumed that the
					 * continue instruction was being placed inside the
					 * nonexistent 'if' block.	Redundant: Bug
					if (itemlist->data == NULL) 
						itemlist = itemlist->next;
						continue; */
					if (itemlist->data != NULL) {
						text = gtk_object_get_user_data(itemlist->data);
						if (n == 0)
							tmp = g_strconcat(line, "'", text, "'", NULL);
						else
							tmp = g_strconcat(line, " '", text, "'", NULL);
						g_free(line);
						line = tmp;
						++n;
					}
					itemlist = itemlist->next;
				}
				putenv(line);
				break;

			case WIDGET_TABLE:
				tmp = widget_table_envvar_all_construct(actual);
				putenv(tmp);
				break;

#if GTK_CHECK_VERSION(2,4,0)
			case WIDGET_TREE:
				tmp = widget_tree_envvar_all_construct(actual);
				putenv(tmp);
				break;
#endif

			case WIDGET_COMBOBOXENTRY:
			case WIDGET_COMBOBOXTEXT:
				tmp = widget_comboboxtext_envvar_all_construct(actual);
				putenv(tmp);
				break;
		}
#endif

	}

	if (actual->right != NULL)
		_variables_export(actual->right);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* This function is called when we want to send the variable's values
 * to the standard output */

void print_variables(variable *actual)
{
	GList            *element;
	gchar            *act;
	gchar            *value;
	gint              export = TRUE;

	if (actual == NULL)
		actual = root;

	if (actual == NULL)
		return;

	if (actual->left != NULL)
		print_variables(actual->left);

	/* Thunor: It's now possible to prevent the exporting of declared
	 * variables by using <variable export="false">VARNAME</variable> */
	if ((act = attributeset_get_first(&element, actual->Attributes,
		ATTR_VARIABLE)) &&
		(value = attributeset_get_this_tagattr(&element, actual->Attributes,
		ATTR_VARIABLE, "export")) &&
		((strcasecmp(value, "false") == 0) ||
		(strcasecmp(value, "no") == 0) ||
		(strcasecmp(value, "0") == 0))) {
		export = FALSE;
#ifdef DEBUG
		fprintf(stderr, "%s(): variable=%s export=%s\n",
			__func__, act, value);
#endif
	}

	if (actual->Widget != NULL && !actual->autonamed && export) {
		//
		// To print only the active element
		//
		value = widget_get_text_value(actual->Widget, actual->Type);

		/* Redundant.
		 ** FIXME: awfull
		 *
		if (actual->Type == WIDGET_TABLE && actual->row != -1) {
			gtk_clist_get_text(GTK_CLIST(actual->Widget),
					   actual->row, 0, &value);
		} */

		if (value == NULL)
			value = "";
		printf("%s=\"%s\"\n", actual->Name, value);

		/* Thunor: I've disabled this for performance reasons. Zigbert was
		 * experiencing terrible table performance which I've tested too.
		 * Initially it may have been practicable with simple dialogs to
		 * dump the entire contents of a widget on every signal, but it
		 * definitely isn't anymore */
#if 0
		//
		// To print all of the elements in the list
		//
		switch (actual->Type) {
			case WIDGET_LIST:
				n = 0;
				printf("%s_ALL=\"", actual->Name);
				itemlist = GTK_LIST(actual->Widget)->children;
				while (itemlist != NULL) {
					if (itemlist->data == NULL)
						goto next_item;
					if (n == 0)
						printf("'%s'", (char*)gtk_object_get_user_data (itemlist->data));
					else
						printf(" '%s'", (char*)gtk_object_get_user_data (itemlist->data));
next_item:
					itemlist = itemlist->next;
					++n;
				}
				printf("\"\n");
				break;

			case WIDGET_TABLE:
				tmp = widget_table_envvar_all_construct(actual);
				g_printf("%s", tmp);
				g_free(tmp);
				break;

#if GTK_CHECK_VERSION(2,4,0)
			case WIDGET_TREE:
				tmp = widget_tree_envvar_all_construct(actual);
				g_printf("%s", tmp);
				g_free(tmp);
				break;
#endif

			case WIDGET_COMBOBOXENTRY:
			case WIDGET_COMBOBOXTEXT:
				tmp = widget_comboboxtext_envvar_all_construct(actual);
				g_printf("%s", tmp);
				g_free(tmp);
				break;
		}
#endif

	}

	if (actual->right != NULL)
		print_variables(actual->right);

	fflush(stdout);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

/* Redundant: Only used by action_append() which isn't being used anyway so purge it.
int append_fromto_variable(const char *from, const char *to)
{
	GtkTreeModel *model;
	GtkTreeIter   iter;
	variable     *var_from, *var_to;
	char         *value;
	GtkWidget    *item;
	GList        *glist = NULL;

	g_assert(from != NULL);
	g_assert(to != NULL);

#ifdef DEBUG
	g_message("%s(): from: '%s' to: '%s'", __func__, from, to);
#endif

	var_from = _tree_find(from, NULL);
	var_to = _tree_find(to, NULL);
	if (var_from == NULL || var_to == NULL) {
		yywarning("Insert: variable not found.");
		return FALSE;
	}

	value = g_strdup(widget_get_text_value(var_from->Widget, var_from->Type));

	if (strlen(value) == 0)
		return FALSE;

	switch (var_to->Type) {
		case WIDGET_LIST:
			item = gtk_list_item_new_with_label(value);
			gtk_widget_show(item);
			gtk_object_set_user_data(GTK_OBJECT(item), (gpointer) value);
			glist = g_list_append(glist, item);

			gtk_list_prepend_items(GTK_LIST(var_to->Widget), glist);
			gtk_list_select_item(GTK_LIST(var_to->Widget), 0);
		break;
		
		case WIDGET_ENTRY:
			gtk_entry_set_text(GTK_ENTRY(var_to->Widget), value);
			break;
		
		case WIDGET_EDIT:
			gtk_text_buffer_insert_at_cursor(
					gtk_text_view_get_buffer(GTK_TEXT_VIEW(var_to->Widget)), 
					value, g_utf8_strlen(value, -1));
			break;
#if GTK_CHECK_VERSION(2,4,0)
		case WIDGET_TREE:
			model = gtk_tree_view_get_model(GTK_TREE_VIEW(var_to->Widget));
			gtk_tree_store_append(GTK_TREE_STORE(model), &iter, NULL); 
			gtk_tree_store_set(GTK_TREE_STORE(model), &iter, 1, value, -1);
			break;
#endif

#if GTK_CHECK_VERSION(2,4,0)
		case WIDGET_CHOOSER:
			gtk_file_chooser_add_shortcut_folder(
					GTK_FILE_CHOOSER(var_to->Widget), 
					value, NULL);
		break;
#endif
	default:
		yywarning("Copy not implemented for this widget.");
		return FALSE;
	}
	return TRUE;
} */

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* This function will clear the variable by deleting everything from
 * the widget */

variable *variables_clear(const char *name)
{
	variable         *toclear;
	gchar            *string;

#ifdef DEBUG
	fprintf(stderr, "%s(): variable: %s\n", __func__, name);
	fflush(stderr);
#endif

	toclear = _tree_find(name, NULL);
	if (toclear == NULL)
		return (NULL);

	/* If the custom attribute "block-function-signals" is true
	 * then block signals whilst performing this function */
	if (toclear->widget_tag_attr &&
		((string = get_tag_attribute(toclear->widget_tag_attr, "block-function-signals"))) &&
		((strcasecmp(string, "true") == 0) || (strcasecmp(string, "yes") == 0) ||
		(atoi(string) == 1))) {
		GTKD_FUNCTION_SIGNALS_BLOCK;
	}

	switch (toclear->Type) {
		case WIDGET_CANCELBUTTON:
		case WIDGET_HELPBUTTON:
		case WIDGET_NOBUTTON:
		case WIDGET_OKBUTTON:
		case WIDGET_YESBUTTON:
		case WIDGET_TOGGLEBUTTON:
		case WIDGET_BUTTON:
			widget_button_clear(toclear);
			break;
		case WIDGET_CHECKBOX:
			widget_checkbox_clear(toclear);
			break;
		case WIDGET_COLORBUTTON:
			widget_colorbutton_clear(toclear);
			break;
		case WIDGET_COMBOBOX:
			widget_combobox_clear(toclear);
			break;
		case WIDGET_COMBOBOXENTRY:
		case WIDGET_COMBOBOXTEXT:
			widget_comboboxtext_clear(toclear);
			break;
		case WIDGET_EDIT:
			widget_edit_clear(toclear);
			break;
		case WIDGET_ENTRY:
			widget_entry_clear(toclear);
			break;
		case WIDGET_EVENTBOX:
			widget_eventbox_clear(toclear);
			break;
		case WIDGET_EXPANDER:
			widget_expander_clear(toclear);
			break;
		case WIDGET_FONTBUTTON:
			widget_fontbutton_clear(toclear);
			break;
		case WIDGET_FRAME:
			widget_frame_clear(toclear);
			break;
		case WIDGET_HBOX:
			widget_hbox_clear(toclear);
			break;
		case WIDGET_HSCALE:
		case WIDGET_VSCALE:
			widget_hscale_clear(toclear);
			break;
		case WIDGET_HSEPARATOR:
		case WIDGET_VSEPARATOR:
			widget_hseparator_clear(toclear);
			break;
		case WIDGET_LIST:
			widget_list_clear(toclear);
			break;
		case WIDGET_MENUBAR:
			widget_menubar_clear(toclear);
			break;
		case WIDGET_MENUITEMSEPARATOR:
		case WIDGET_MENUITEM:
		case WIDGET_MENU:
			widget_menuitem_clear(toclear);
			break;
		case WIDGET_NOTEBOOK:
			widget_notebook_clear(toclear);
			break;
		case WIDGET_PIXMAP:
			widget_pixmap_clear(toclear);
			break;
		case WIDGET_PROGRESSBAR:
			widget_progressbar_clear(toclear);
			break;
		case WIDGET_RADIOBUTTON:
			widget_radiobutton_clear(toclear);
			break;
		case WIDGET_SPINBUTTON:
			widget_spinbutton_clear(toclear);
			break;
		case WIDGET_STATUSBAR:
			widget_statusbar_clear(toclear);
			break;
		case WIDGET_TABLE:
			widget_table_clear(toclear);
			break;
		case WIDGET_TERMINAL:
			widget_terminal_clear(toclear);
			break;
		case WIDGET_TEXT:
			widget_text_clear(toclear);
			break;
		case WIDGET_TIMER:
			widget_timer_clear(toclear);
			break;
#if GTK_CHECK_VERSION(2,4,0)
		case WIDGET_TREE:
			widget_tree_clear(toclear);
			break;
#endif
		case WIDGET_VBOX:
			widget_vbox_clear(toclear);
			break;
		case WIDGET_WINDOW:
			widget_window_clear(toclear);
			break;
		default:
			yywarning("Clear not implemented for this widget.");
	}

	GTKD_FUNCTION_SIGNALS_RESET;

	return (toclear);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* This function will remove the selected item from the widget */

int remove_selected_variable(const char *name)
{
	variable         *toclear;
	gchar            *string;

	g_assert(name != NULL);

#ifdef DEBUG
	g_message("%s(): variable: %s", __func__, name);
#endif
	/*
	 * Searching for the given variable.
	 */
	toclear = _tree_find(name, NULL);
	if (toclear == NULL)
		return -1;

	/* If the custom attribute "block-function-signals" is true
	 * then block signals whilst performing this function */
	if (toclear->widget_tag_attr &&
		((string = get_tag_attribute(toclear->widget_tag_attr, "block-function-signals"))) &&
		((strcasecmp(string, "true") == 0) || (strcasecmp(string, "yes") == 0) ||
		(atoi(string) == 1))) {
		GTKD_FUNCTION_SIGNALS_BLOCK;
	}

	/*
	 * Removing the selected item or text range from the widget.
	 */
	switch (toclear->Type) {
		case WIDGET_CANCELBUTTON:
		case WIDGET_HELPBUTTON:
		case WIDGET_NOBUTTON:
		case WIDGET_OKBUTTON:
		case WIDGET_YESBUTTON:
		case WIDGET_TOGGLEBUTTON:
		case WIDGET_BUTTON:
			widget_button_removeselected(toclear);
			break;
		case WIDGET_CHECKBOX:
			widget_checkbox_removeselected(toclear);
			break;
		case WIDGET_COLORBUTTON:
			widget_colorbutton_removeselected(toclear);
			break;
		case WIDGET_COMBOBOX:
			widget_combobox_removeselected(toclear);
			break;
		case WIDGET_COMBOBOXENTRY:
		case WIDGET_COMBOBOXTEXT:
			widget_comboboxtext_removeselected(toclear);
			break;
		case WIDGET_EDIT:
			widget_edit_removeselected(toclear);
			break;
		case WIDGET_ENTRY:
			widget_entry_removeselected(toclear);
			break;
		case WIDGET_EVENTBOX:
			widget_eventbox_removeselected(toclear);
			break;
		case WIDGET_EXPANDER:
			widget_expander_removeselected(toclear);
			break;
		case WIDGET_FONTBUTTON:
			widget_fontbutton_removeselected(toclear);
			break;
		case WIDGET_FRAME:
			widget_frame_removeselected(toclear);
			break;
		case WIDGET_HBOX:
			widget_hbox_removeselected(toclear);
			break;
		case WIDGET_HSCALE:
		case WIDGET_VSCALE:
			widget_hscale_removeselected(toclear);
			break;
		case WIDGET_HSEPARATOR:
		case WIDGET_VSEPARATOR:
			widget_hseparator_removeselected(toclear);
			break;
		case WIDGET_LIST:
			widget_list_removeselected(toclear);
			break;
		case WIDGET_MENUBAR:
			widget_menubar_removeselected(toclear);
			break;
		case WIDGET_MENUITEMSEPARATOR:
		case WIDGET_MENUITEM:
		case WIDGET_MENU:
			widget_menuitem_removeselected(toclear);
			break;
		case WIDGET_NOTEBOOK:
			widget_notebook_removeselected(toclear);
			break;
		case WIDGET_PIXMAP:
			widget_pixmap_removeselected(toclear);
			break;
		case WIDGET_PROGRESSBAR:
			widget_progressbar_removeselected(toclear);
			break;
		case WIDGET_RADIOBUTTON:
			widget_radiobutton_removeselected(toclear);
			break;
		case WIDGET_SPINBUTTON:
			widget_spinbutton_removeselected(toclear);
			break;
		case WIDGET_STATUSBAR:
			widget_statusbar_removeselected(toclear);
			break;
		case WIDGET_TABLE:
			widget_table_removeselected(toclear);
			break;
		case WIDGET_TERMINAL:
			widget_terminal_removeselected(toclear);
			break;
		case WIDGET_TEXT:
			widget_text_removeselected(toclear);
			break;
		case WIDGET_TIMER:
			widget_timer_removeselected(toclear);
			break;
#if GTK_CHECK_VERSION(2,4,0)
		case WIDGET_TREE:
			widget_tree_removeselected(toclear);
			break;
#endif
		case WIDGET_VBOX:
			widget_vbox_removeselected(toclear);
			break;
		case WIDGET_WINDOW:
			widget_window_removeselected(toclear);
			break;
		default:
			yywarning("Delete not implemented for this widget.");
	}

	GTKD_FUNCTION_SIGNALS_RESET;

	return 0;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* This is a debug function we use to print all variables to the 
 * standard error. It will print a lot of information */

#ifdef DEBUG
void variables_print_debug(variable *actual)
{
	if (actual == NULL)
		actual = root;
	if (actual == NULL)
		return;

	if (actual->left != NULL)
		variables_print_debug(actual->left);

	variables_print_one(actual);

	if (actual->right != NULL)
		variables_print_debug(actual->right);
}
#endif
