/*
 * signals.c:
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

/* Includes */
#define _GNU_SOURCE
#include <gtk/gtk.h>
#include "config.h"
#include "gtkdialog.h"
#include "attributes.h"
#include "signals.h"

/* Defines */
//#define DEBUG_CONTENT
//#define DEBUG_TRANSITS

/* Local function prototypes, located at file bottom */

/* Notes:
 * I'm not quite convinced about these button_* callbacks at the moment
 * as they are/were old code and only appear to be duplicating code within
 * the widget_signal_executor anyway, so I'll mark them temp temp
 * 
 * list_selection and table_selection are equally as dodgy.
 * 
 * tree_row_activated_attr and tree_cursor_changed too.
 * 
 *  */

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void button_clicked_attr(GtkWidget *button, AttributeSet *Attr)
{
	GList *element;
	gchar *command;
	gchar *signal;
	gchar *type;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command != NULL) {

#ifdef DEBUG_CONTENT
		GList *attr;
		Attribute *data;
		attr = g_list_first(Attr->attr[ATTR_ACTION]);
		while (attr) {
			data = attr->data;
			printf("%s: BEFORE: element=%p attr->data->text='%s'\n",
				__func__, element, data->text);
			attr = g_list_next(attr);
		}
#endif

		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "signal");
		if (signal != NULL && g_ascii_strcasecmp(signal, "clicked") != 0) {
		} else {
			execute_action(button, command, type);
		}

#ifdef DEBUG_CONTENT
		attr = g_list_first(Attr->attr[ATTR_ACTION]);
		while (attr) {
			data = attr->data;
			printf("%s:  AFTER: element=%p attr->data->text='%s'\n",
				__func__, element, data->text);
			attr = g_list_next(attr);
		}
#endif

		command = attributeset_get_next(&element, Attr, ATTR_ACTION);

#ifdef DEBUG_CONTENT
		printf("%s: element=%p\n", __func__, element);
#endif
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void button_entered_attr(GtkWidget *button, AttributeSet *Attr)
{
	GList *element;
	gchar *command;
	gchar *signal;
	gchar *type;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command != NULL) {
		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "signal");
		if (signal == NULL || g_ascii_strcasecmp(signal, "enter") != 0) {
		} else {
			execute_action(button, command, type);
		}
		command = attributeset_get_next(&element, Attr, ATTR_ACTION);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void button_leaved_attr(GtkWidget *button, AttributeSet *Attr)
{
	GList *element;
	gchar *command;
	gchar *signal;
	gchar *type;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command != NULL) {
		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "signal");
		if (signal == NULL || g_ascii_strcasecmp(signal, "leave") != 0) {
		} else {
			execute_action(button, command, type);
		}
		command = attributeset_get_next(&element, Attr, ATTR_ACTION);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

/* Thunor: create_chooser() is now the only function calling this */

void button_pressed(GtkWidget *button, const gchar *str)
{
	execute_action(GTK_WIDGET(button), str, NULL);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void button_pressed_attr(GtkWidget *button, AttributeSet *Attr)
{
	GList *element;
	gchar *command;
	gchar *signal;
	gchar *type;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command != NULL) {
		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "signal");
		if (signal == NULL || g_ascii_strcasecmp(signal, "pressed") != 0) {
		} else {
			execute_action(button, command, type);
		}
		command = attributeset_get_next(&element, Attr, ATTR_ACTION);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void button_released_attr(GtkWidget *button, AttributeSet *Attr)
{
	GList *element;
	gchar *command;
	gchar *signal;
	gchar *type;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command != NULL) {
		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "signal");
		if (signal == NULL || g_ascii_strcasecmp(signal, "released") != 0) {
		} else {
			execute_action(button, command, type);
		}
		command = attributeset_get_next(&element, Attr, ATTR_ACTION);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void list_selection(GtkWidget *list, gpointer Attr)
{
	GList *element;
	gchar *command;
	gchar *signal;
	gchar *type;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (Attr == NULL) return;

	/* Thunor: This code does not support <action signal="type">.
	 * This callback is connected to the "selection-changed" signal,
	 * therefore if there exists an action directive specifying a
	 * particular signal then that will be executed as well.
	 * 
	 * This widget was in fact deprecated in GTK+ 2.0 anyway */

	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command != NULL){
		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		execute_action(list, command, type);
		command = attributeset_get_next(&element, Attr, ATTR_ACTION);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_activate_event(GtkWidget *widget, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "activate");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_button_pressed(GtkWidget *widget,
	GdkEventButton *event, AttributeSet *Attr)
{
	gchar *button = g_strdup_printf("%d", event->button);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	g_setenv("BUTTON", button, TRUE);
	widget_signal_executor(widget, Attr, "button-press-event");
	g_unsetenv("BUTTON");
	g_free(button);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_button_released(GtkWidget *widget,
	GdkEventButton *event, AttributeSet *Attr)
{
	gchar *button = g_strdup_printf("%d", event->button);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	g_setenv("BUTTON", button, TRUE);
	widget_signal_executor(widget, Attr, "button-release-event");
	g_unsetenv("BUTTON");
	g_free(button);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_changed_event(GtkWidget *widget, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "changed");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_color_set_event(GtkWidget *widget, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "color-set");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_configure_event(GtkWidget *widget,
	GdkEventConfigure *event, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "configure-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_delete_event(GtkWidget *widget, GdkEvent *event,
	AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "delete-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_destroy_event(GtkWidget *widget, GdkEvent *event,
	AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "destroy-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_enter_notify_event(GtkWidget *widget,
	GdkEventCrossing *event, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "enter-notify-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_focus_in_event(GtkWidget *widget,
	GdkEventFocus *event, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "focus-in-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_focus_out_event(GtkWidget *widget,
	GdkEventFocus *event, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "focus-out-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_hide(GtkWidget *widget, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "hide");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

#if GTK_CHECK_VERSION(2,16,0)
/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_icon_press_event(GtkWidget *widget,
	GtkEntryIconPosition pos, GdkEvent *event, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (pos == GTK_ENTRY_ICON_PRIMARY)
		widget_signal_executor(widget, Attr, "primary-icon-press");
	else
		widget_signal_executor(widget, Attr, "secondary-icon-press");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_icon_release_event(GtkWidget *widget,
	GtkEntryIconPosition pos, GdkEvent *event, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (pos == GTK_ENTRY_ICON_PRIMARY)
		widget_signal_executor(widget, Attr, "primary-icon-release");
	else
		widget_signal_executor(widget, Attr, "secondary-icon-release");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}
#endif

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_key_press_event(GtkWidget *widget,
	GdkEventKey *event, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif


#if 0
	// This is TODO temp temp
	// Trouble is the key press events stop firing when the popup is
	// active i.e. when you press Enter on the combobox.

	/* comboxtext supports the key-search custom tag attribute which
	 * must be managed here first before continuing. It has to be done
	 * here because we need access to the event and we're really doing
	 * is intercepting the signal before passing it to the executor */
	if (GTK_IS_COMBO_BOX(widget)) {

		/* Get initialised state of widget */
		if ((g_object_get_data(G_OBJECT(widget), "key-search") != NULL) ||
			(g_object_get_data(G_OBJECT(widget), "key_search") != NULL)) {
				
			fprintf(stderr, "%s(): key-search found\n", __func__);

		}
	}
#endif


	widget_signal_executor(widget, Attr, "key-press-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_key_release_event(GtkWidget*widget,
	GdkEventKey *event, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "key-release-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_leave_notify_event(GtkWidget *widget,
	GdkEventCrossing *event, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "leave-notify-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_map_event(GtkWidget *widget, GdkEvent *event,
	AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "map-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_realized(GtkWidget *widget, tag_attr *tag_attributes)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): widget=%p  tag_attributes=%p\n", __func__,
		widget, tag_attributes);
#endif
	widget_set_tag_attributes(widget, tag_attributes);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_show(GtkWidget *widget, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "show");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_toggled_event(GtkWidget *widget, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "toggled");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_unmap_event(GtkWidget *widget, GdkEvent *event,
	AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "unmap-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_value_changed_event(GtkWidget *widget, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "value-changed");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void table_selection(GtkWidget *clist, gint row, gint column,
	GdkEventButton *event, gpointer Attr)
{
	GList *element;
	gchar *command;
	gchar *signal;
	gchar *type;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (Attr == NULL) return;

	variables_set_row_column(
		attributeset_get_first(&element, Attr, ATTR_VARIABLE),
		row, column);

	/* Thunor: This code does not support <action signal="type">.
	 * This callback is connected to the "select-row" signal,
	 * therefore if there exists an action directive specifying a
	 * particular signal then that will be executed as well.
	 * 
	 * This widget was in fact deprecated in GTK+ 2.0 anyway */

	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command != NULL){
		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		execute_action(clist, command, type);
		command = attributeset_get_next(&element, Attr, ATTR_ACTION);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void tree_row_activated_attr(GtkTreeView *tree_view, GtkTreePath *path,
	GtkTreeViewColumn *column, AttributeSet *Attr)
{
	GList *element;
	gchar *command;
	gchar *signal;
	gchar *type;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command != NULL){
		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "signal");
		if (signal != NULL && g_ascii_strcasecmp(signal, "row-activated") != 0)
			goto next_command;
		
		execute_action(GTK_WIDGET(tree_view), command, type);
next_command:   
		command = attributeset_get_next(&element, Attr, ATTR_ACTION);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean tree_cursor_changed(GtkTreeView *tree_view, AttributeSet *Attr)
{
	GList *element;
	gchar *command;
	gchar *signal;
	gchar *type;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command != NULL){
		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "signal");
		if (signal == NULL || g_ascii_strcasecmp(signal, "cursor-changed") != 0)
			goto next_command;
		
		execute_action(GTK_WIDGET(tree_view), command, type);
next_command:   
		command = attributeset_get_next(&element, Attr, ATTR_ACTION);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return TRUE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean window_delete_event_handler(GtkWidget *widget, GtkWidget *event,
	gpointer data)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	variables_drop_by_parent(NULL, widget);

	if (variables_count_widgets() == 0) {
		gtk_main_quit();
		printf("EXIT=\"abort\"\n");
		exit(EXIT_SUCCESS);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 * Widget Signal Executor                                              *
 ***********************************************************************/
/* Thunor: With the work I've been doing I've called this function from
 * signal callbacks and let this iterate through the actions, manage the
 * default widget signal and the "if true/false" if applicable. I think
 * that originally each individual callback dealt with this but as the
 * number of widgets increases it makes sense to do everything here */

void widget_signal_executor(GtkWidget *widget, AttributeSet *Attr,
	const gchar *signal_name)
{
	GList            *element;
	gchar            *command, *type, *signal;
	gint              execute, is_active;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): Executing signal '%s' on widget %p\n",
		__func__, signal_name, widget);
#endif

	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command) {
		execute = FALSE;

		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "signal");

		if (signal && g_ascii_strcasecmp(signal, signal_name) == 0) {
			/************************************************************************
			 * This manages <action signal="type"> i.e the specified signal         *
			 ************************************************************************/

#ifdef DEBUG_CONTENT
			fprintf(stderr, "%s: command=%s type=%s signal=%s signal_name=%s\n",
				__func__, command, type, signal, signal_name);
#endif

			/* Some widgets support conditional function execution on certain signals */
			if (strncasecmp(command, "if true ", 8) == 0) {
				if (strcasecmp(signal_name, "toggled") == 0) {
					/* There's a class hierarchy to be aware of here */
					if (GTK_IS_CHECK_MENU_ITEM(widget)) {
						is_active = gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget));
						command += 8;
						if (is_active) execute = TRUE;
					} else if (GTK_IS_TOGGLE_BUTTON(widget)) {
						is_active = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
						command += 8;
						if (is_active) execute = TRUE;
					}
				}
			} else if (strncasecmp(command, "if false ", 9) == 0) {
				if (strcasecmp(signal_name, "toggled") == 0) {
					/* There's a class hierarchy to be aware of here */
					if (GTK_IS_CHECK_MENU_ITEM(widget)) {
						is_active = gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget));
						command += 9;
						if (!is_active) execute = TRUE;
					} else if (GTK_IS_TOGGLE_BUTTON(widget)) {
						is_active = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
						command += 9;
						if (!is_active) execute = TRUE;
					}
				}
			} else {
				execute = TRUE;
			}
		} else if (signal == NULL) {
			/************************************************************************
			 * This manages <action> i.e. the default widget signal                 *
			 ************************************************************************/

#ifdef DEBUG_CONTENT
			fprintf(stderr, "%s: command=%s type=%s signal=%s signal_name=%s\n",
				__func__, command, type, signal, signal_name);
#endif

			/* There's a class hierarchy to be aware of here */
			if (GTK_IS_CHECK_MENU_ITEM(widget)) {
				if (strcasecmp(signal_name, "toggled") == 0) {
					/* Checkbox menuitems support conditional function execution */
					is_active = gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget));
					if (strncasecmp(command, "if true ", 8) == 0) {
						command += 8;
						if (is_active) execute = TRUE;
					} else if (strncasecmp(command, "if false ", 9) == 0) {
						command += 9;
						if (!is_active) execute = TRUE;
					} else {
						execute = TRUE;
					}
				}
			} else if (GTK_IS_MENU_ITEM(widget)) {
				if (strcasecmp(signal_name, "activate") == 0)
					execute = TRUE;
			} else if (GTK_IS_SPIN_BUTTON(widget)) {
				if (strcasecmp(signal_name, "value-changed") == 0)
					execute = TRUE;
			} else if (GTK_IS_ENTRY(widget) || GTK_IS_COMBO_BOX(widget)) {
				if (strcasecmp(signal_name, "changed") == 0)
					execute = TRUE;
			} else if (GTK_IS_SCALE(widget)) {
				if (strcasecmp(signal_name, "value-changed") == 0)
					execute = TRUE;
			} else if (GTK_IS_LABEL(widget)) {
				/* A GtkLabel that ticks is a timer */
				if (strcasecmp(signal_name, "tick") == 0)
					execute = TRUE;
			} else if (GTK_IS_COLOR_BUTTON(widget)) {
				if (strcasecmp(signal_name, "color-set") == 0)
					execute = TRUE;
			} else if (GTK_IS_TOGGLE_BUTTON(widget)) {
				if (strcasecmp(signal_name, "toggled") == 0) {
					/* togglebuttons support conditional function execution */
					is_active = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
					if (strncasecmp(command, "if true ", 8) == 0) {
						command += 8;
						if (is_active) execute = TRUE;
					} else if (strncasecmp(command, "if false ", 9) == 0) {
						command += 9;
						if (!is_active) execute = TRUE;
					} else {
						execute = TRUE;
					}
				}
			}
		}
		if (execute) execute_action(widget, command, type);
		command = attributeset_get_next(&element, Attr, ATTR_ACTION);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}
