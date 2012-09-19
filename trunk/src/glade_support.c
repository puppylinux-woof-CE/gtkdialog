/*
 * glade_support.c: The interface between Glade and Gtkdialog.
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

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>

#if HAVE_GLADE_LIB
#include <glade/glade.h>
#include "widgets.h"
#include "glade_support.h"
#include "signals.h"

/*************************************************************************
 * Static declarations:                                                  *
 *                                                                       *
 *                                                                       *
 *************************************************************************/
typedef struct _gtkdialog_signal {
	gchar     *name;
	GCallback callback;
} gtkdialog_signal;

/* function prototypes */
gint widget_get_type_from_pointer(GtkWidget *widget);

/*
** Signal handler callbascks.
*/

static void 
on_any_button_clicked(
		GtkButton *widget, 
		gchar     *full_command)
{
	gchar *prefix, *command;

	g_return_if_fail(full_command != NULL);
#ifdef DEBUG
	g_message("%s(%p, '%s')", __func__, widget, full_command);
#endif
	command_get_prefix(full_command, &prefix, &command);
	execute_action(widget, command, prefix);
	g_free(command);
	g_free(prefix);
}


static void 
on_any_entry_almost_any(GtkEntry *widget, 
		gchar     *full_command)
{
	gchar *prefix, *command;

	g_return_if_fail(full_command != NULL);
#ifdef DEBUG
	g_message("%s(%p, '%s')", __func__, widget, full_command);
#endif
	command_get_prefix(full_command, &prefix, &command);
	execute_action(widget, command, prefix);
	g_free(command);
	g_free(prefix);
}


static void 
on_any_entry_delete_from_cursor(
		GtkEntry *entry, 
		GtkDeleteType *arg1, 
		gint arg2, 
		gpointer user_data) 
{
	on_any_entry_almost_any(entry, user_data);
}

static void 
on_any_entry_insert_at_cursor(
		GtkEntry *entry, 
		gchar *arg1, 
		gpointer user_data)
{
	on_any_entry_almost_any(entry, user_data);
}

static void 
on_any_entry_move_cursor(
		GtkEntry *entry, 
		GtkMovementStep *arg1, 
		gint arg2, 
		gboolean arg3, 
		gpointer user_data)
{
	on_any_entry_almost_any(entry, user_data);
}

static void 
on_any_entry_populate_popup(
		GtkEntry *entry, 
		GtkMenu *arg1, 
		gpointer user_data)
{
	on_any_entry_almost_any(entry, user_data);
}

static void 
on_any_combobox_changed(
		GtkComboBox *widget, 
		gchar     *full_command)
{
	gchar *prefix, *command;

	g_return_if_fail(full_command != NULL);
#ifdef DEBUG
	g_message("%s(%p, '%s')", __func__, widget, full_command);
#endif
	command_get_prefix(full_command, &prefix, &command);
	execute_action(widget, command, prefix);
	g_free(command);
	g_free(prefix);
}

static void 
on_any_scale_value_changed(
		GtkScale *widget, 
		gchar     *full_command)
{
	gchar *prefix, *command;

	g_return_if_fail(full_command != NULL);
#ifdef DEBUG
	g_message("%s(%p, '%s')", __func__, widget, full_command);
#endif
	command_get_prefix(full_command, &prefix, &command);
	execute_action(widget, command, prefix);
	g_free(command);
	g_free(prefix);
}

static void 
on_any_widget_almost_any(
		GtkWidget *widget, 
		gchar *full_command)
{
	gchar *prefix, *command;

	g_return_if_fail(full_command != NULL);
#ifdef DEBUG
	g_message("%s(%p, '%s')", __func__, widget, full_command);
#endif
	command_get_prefix(full_command, &prefix, &command);
	execute_action(widget, command, prefix);
	g_free(command);
	g_free(prefix);
}

static gboolean 
on_any_widget_almost_any_gdk_event(
		 GtkWidget *widget, 
		 GdkEvent *event, 
		 gpointer user_data)
{
	on_any_widget_almost_any(widget, user_data);
	return FALSE;
}

#if 0
 /* 
  * GtkWidget unhandled signals.
  */
"can-activate-accel"
 gboolean user_function (GtkWidget *widget, guint signal_id, gpointer user_data)
"child-notify"
 void user_function (GtkWidget *widget, GParamSpec *pspec, gpointer user_data)
"direction-changed"
 void user_function (GtkWidget *widget, GtkTextDirection *arg1, gpointer user_data)
"drag-begin"
 void user_function (GtkWidget *widget, GdkDragContext *drag_context, gpointer user_data)
"drag-data-delete"
 void user_function (GtkWidget *widget, GdkDragContext *drag_context, gpointer user_data)
"drag-data-get"
 void user_function (GtkWidget *widget, GdkDragContext *drag_context, GtkSelectionData *data, guint info, guint time, gpointer user_data)
"drag-data-received"
 void user_function (GtkWidget *widget, GdkDragContext *drag_context, gint x, gint y, GtkSelectionData *data, guint info, guint time, gpointer user_data)
"drag-drop"
 gboolean user_function (GtkWidget *widget, GdkDragContext *drag_context, gint x, gint y, guint time, gpointer user_data)
"drag-end"
 void user_function (GtkWidget *widget, GdkDragContext *drag_context, gpointer user_data)
"drag-leave"
 void user_function (GtkWidget *widget, GdkDragContext *drag_context, guint time, gpointer user_data)
"drag-motion"
 gboolean user_function (GtkWidget *widget, GdkDragContext *drag_context, gint x, gint y, guint time, gpointer user_data)
"focus"
 gboolean user_function (GtkWidget *widget, GtkDirectionType *arg1, gpointer user_data)
"grab-notify"
 void user_function (GtkWidget *widget, gboolean was_grabbed, gpointer user_data)
"hierarchy-changed"
 void user_function (GtkWidget *widget, GtkWidget *widget2, gpointer user_data)
"mnemonic-activate"
 gboolean user_function (GtkWidget *widget, gboolean arg1, gpointer user_data)
"parent-set"
 void user_function (GtkWidget *widget, GtkObject *old_parent, gpointer user_data)
"screen-changed"
 void user_function (GtkWidget *widget, GdkScreen *arg1, gpointer user_data)
"selection-get"
 void user_function (GtkWidget *widget, GtkSelectionData *data, guint info, guint time, gpointer user_data)
"selection-received"
 void user_function (GtkWidget *widget, GtkSelectionData *data, guint time, gpointer user_data)
"show-help"
 gboolean user_function (GtkWidget *widget, GtkWidgetHelpType *arg1, gpointer user_data)
"size-allocate"
 void user_function (GtkWidget *widget, GtkAllocation *allocation, gpointer user_data)
"size-request"
 void user_function (GtkWidget *widget, GtkRequisition *requisition, gpointer user_data)
"state-changed"
 void user_function (GtkWidget *widget, GtkStateType state, gpointer user_data)
"style-set"
 void user_function (GtkWidget *widget, GtkStyle *previous_style, gpointer user_data)
"window-state-event"
 gboolean user_function (GtkWidget *widget, GdkEventWindowState *event, gpointer user_data)
#endif 

/*
** Signal handler connectors for each widget types we support.
*/
static gboolean
find_and_connect_handler(
		GtkWidget *widget,
		gtkdialog_signal *signals,
		const gchar *signal_name,
		const gchar *handler_name)
{
	gint n;
	
	for (n = 0; signals[n].name != NULL; ++n) {
		if (g_ascii_strcasecmp(signals[n].name, signal_name) == 0)
			g_signal_connect(G_OBJECT(widget), 
					signal_name, 
					signals[n].callback, 
					g_strdup(handler_name));
			return TRUE;
	}

	return FALSE;
}


static gboolean
gtk_toggle_button_signal_handler_connector(
		const gchar *handler_name, 
		GObject *object, 
		const gchar *signal_name, 
		const gchar *signal_data, 
		GObject *connect_object, 
		gboolean after, 
		gpointer user_data)
{
	/*
	 * As I see, the "toggle" function is the very same as of the "clicked"
	 * signal of the normal buttons.
	 */
	if (g_ascii_strcasecmp(signal_name, "toggled") == 0) {
		g_signal_connect(object, 
				signal_name, 
				G_CALLBACK(on_any_button_clicked), 
				g_strdup(handler_name));
		return TRUE;
	}
	return FALSE;
}

static gboolean
gtk_button_signal_handler_connector(
		const gchar *handler_name, 
		GObject *object, 
		const gchar *signal_name, 
		const gchar *signal_data, 
		GObject *connect_object, 
		gboolean after, 
		gpointer user_data)
{
	gint n;
	gchar *signal_names[] = {
		"activate", "clicked", "enter", "leave", "pressed",
		"released", NULL
	};

	for (n = 0; signal_names[n] != NULL; ++n) {
		if (g_ascii_strcasecmp(signal_name, signal_names[n]) == 0) {
			g_signal_connect(object, 
					signal_names[n], 
					G_CALLBACK(on_any_button_clicked), 
					g_strdup(handler_name));
			return TRUE;
		}
	}
	return FALSE;
}

static gboolean
gtk_entry_signal_handler_connector(
		const gchar *handler_name, 
		GObject *object, 
		const gchar *signal_name, 
		const gchar *signal_data, 
		GObject *connect_object, 
		gboolean after, 
		gpointer user_data)
{
	gint n;
	gtkdialog_signal entry_signals[] = {
		{ "activate",           (GCallback)on_any_entry_almost_any },
		{ "backspace",          (GCallback)on_any_entry_almost_any },
		{ "copy-clipboard",     (GCallback)on_any_entry_almost_any },
		{ "cut-clipboard",      (GCallback)on_any_entry_almost_any },
		{ "paste-clipboard",    (GCallback)on_any_entry_almost_any },
		{ "toggle-overwrite",   (GCallback)on_any_entry_almost_any },
		{ "delete-from-cursor", (GCallback)on_any_entry_delete_from_cursor },
		{ "insert-at-cursor",   (GCallback)on_any_entry_insert_at_cursor },
		{ "move-cursor",        (GCallback)on_any_entry_move_cursor },
		{ "populate-popup",     (GCallback)on_any_entry_populate_popup },
		{ NULL,                 (GCallback)NULL }
	};

	return find_and_connect_handler(GTK_WIDGET(object), 
			entry_signals, 
			signal_name,
			handler_name);
}

static gboolean
gtk_combobox_signal_handler_connector(
		const gchar *handler_name, 
		GObject *object, 
		const gchar *signal_name, 
		const gchar *signal_data, 
		GObject *connect_object, 
		gboolean after, 
		gpointer user_data)
{
	if (g_ascii_strcasecmp(signal_name, "changed") == 0) {
		g_signal_connect(object, 
				signal_name, 
				G_CALLBACK(on_any_combobox_changed), 
				g_strdup(handler_name));
		return TRUE;
	}
	return FALSE;
}

static gboolean
gtk_scale_signal_handler_connector(
		const gchar *handler_name, 
		GObject *object, 
		const gchar *signal_name, 
		const gchar *signal_data, 
		GObject *connect_object, 
		gboolean after, 
		gpointer user_data)
{
	/* Thunor: There's an issue with the name of this signal as the Glade
	 * Interface Designer and the GTK+ 2 Reference Manual:GtkScale will
	 * write it with an underscore but it's actually the GtkRange signal
	 * value-changed and this is equivalent to the GtkSpinButton signal
	 * value-changed and both widgets are identical in code. I'd say that
	 * GTK+ doesn't distinguish between underscores and hyphens as a
	 * separator within names but Gtkdialog up until now did */
	if ((g_ascii_strcasecmp(signal_name, "value_changed") == 0) ||
		(g_ascii_strcasecmp(signal_name, "value-changed") == 0)) {
		g_signal_connect(object, 
				signal_name, 
				G_CALLBACK(on_any_scale_value_changed), 
				g_strdup(handler_name));
		return TRUE;
	}
	return FALSE;
}

static gboolean
gtk_widget_signal_handler_connector(
		const gchar *handler_name, 
		GObject *object, 
		const gchar *signal_name, 
		const gchar *signal_data, 
		GObject *connect_object, 
		gboolean after, 
		gpointer user_data)
{
	variable *var;
	gtkdialog_signal widget_signals[] = {
		{ "accel-closures-changed",    (GCallback)on_any_widget_almost_any },
		{ "composited-changed",        (GCallback)on_any_widget_almost_any },
		{ "grab-focus",                (GCallback)on_any_widget_almost_any },
		{ "hide",                      (GCallback)on_any_widget_almost_any },
		{ "map",                       (GCallback)on_any_widget_almost_any },
		{ "popup-menu",                (GCallback)on_any_widget_almost_any },
		{ "show",                      (GCallback)on_any_widget_almost_any },
		{ "unmap",                     (GCallback)on_any_widget_almost_any },
		{ "unrealize",                 (GCallback)on_any_widget_almost_any },
		{ "button-press-event",        (GCallback)on_any_widget_almost_any_gdk_event },
		{ "client-event",              (GCallback)on_any_widget_almost_any_gdk_event },
		{ "configure-event",           (GCallback)on_any_widget_almost_any_gdk_event },
		{ "delete-event",              (GCallback)on_any_widget_almost_any_gdk_event },
		{ "destroy-event",             (GCallback)on_any_widget_almost_any_gdk_event },
		{ "enter-notify-event",        (GCallback)on_any_widget_almost_any_gdk_event },
		{ "event",                     (GCallback)on_any_widget_almost_any_gdk_event },
		{ "event-after",               (GCallback)on_any_widget_almost_any_gdk_event },
		{ "expose-event",              (GCallback)on_any_widget_almost_any_gdk_event },
		{ "focus-in-event",            (GCallback)on_any_widget_almost_any_gdk_event },
		{ "focus-out-event",           (GCallback)on_any_widget_almost_any_gdk_event },
		{ "grab-broken-event",         (GCallback)on_any_widget_almost_any_gdk_event },
		{ "key-press-event",           (GCallback)on_any_widget_almost_any_gdk_event },
		{ "key-relese-event",          (GCallback)on_any_widget_almost_any_gdk_event },
		{ "leave-notify-event",        (GCallback)on_any_widget_almost_any_gdk_event },
		{ "map-event",                 (GCallback)on_any_widget_almost_any_gdk_event },
		{ "motion-notify-event",       (GCallback)on_any_widget_almost_any_gdk_event },
		{ "no-expose-event",           (GCallback)on_any_widget_almost_any_gdk_event },
		{ "property-notify-event",     (GCallback)on_any_widget_almost_any_gdk_event },
		{ "proximity-in-event",        (GCallback)on_any_widget_almost_any_gdk_event },
		{ "proximity-out-event",       (GCallback)on_any_widget_almost_any_gdk_event },
		{ "scroll-event",              (GCallback)on_any_widget_almost_any_gdk_event },
		{ "selection-clear-event",     (GCallback)on_any_widget_almost_any_gdk_event },
		{ "selection-notify-event",    (GCallback)on_any_widget_almost_any_gdk_event },
		{ "selection-request-event",   (GCallback)on_any_widget_almost_any_gdk_event },
		{ "unmap-event",               (GCallback)on_any_widget_almost_any_gdk_event },
		{ "visibility-notify-event",   (GCallback)on_any_widget_almost_any_gdk_event },
		{ NULL,                        (GCallback)NULL }
	};
	/*
	 * The best thing to do is to register this callback as the input
	 * attribute of the given variable. We can't connect the signal to a
	 * signal handler, for it is already created.
	 */
	if (g_ascii_strcasecmp(signal_name, "realize") == 0) {
		var = find_variable_by_widget(GTK_WIDGET(object));
		/*
		 * We should always find this variable.
		 */
		g_return_val_if_fail(var != NULL, FALSE);
		attributeset_insert(var->Attributes, ATTR_INPUT, handler_name);
		return TRUE;
	}
	
	return find_and_connect_handler(GTK_WIDGET(object), 
			widget_signals, 
			signal_name,
			handler_name);
}


/*
 */
static void 
signal_handler_connector(
		const gchar *handler_name, 
		GObject *object, 
		const gchar *signal_name, 
		const gchar *signal_data, 
		GObject *connect_object, 
		gboolean after, 
		gpointer user_data)
{
#ifdef DEBUG
	g_message("%s(): start", __func__);
	g_message("      signal_name: '%s'", signal_name);
	g_message("     handler_name: '%s'", handler_name);
	//g_message("           object: %p", object);
	//g_message("      signal_data: '%s' <------", signal_data);
	//g_message("   connect_object: '%p'", connect_object);
	//g_message("        user_data: '%s'", user_data);
#endif
	if (GTK_IS_ENTRY(object))
		if (gtk_entry_signal_handler_connector(handler_name, 
					object,
					signal_name,
					signal_data,
					connect_object,
					after,
					user_data))
			return;
	
	if (GTK_IS_TOGGLE_BUTTON(object))
		if (gtk_toggle_button_signal_handler_connector(handler_name, 
					object,
					signal_name,
					signal_data,
					connect_object,
					after,
					user_data))
			return;

	if (GTK_IS_BUTTON(object))
		if (gtk_button_signal_handler_connector(handler_name, 
					object,
					signal_name,
					signal_data,
					connect_object,
					after,
					user_data))
			return;
	
	if (GTK_IS_TOOL_BUTTON(object))
		if (gtk_button_signal_handler_connector(handler_name,
					object,
					signal_name,
					signal_data,
					connect_object,
					after,
					user_data))
			return;

	if (GTK_IS_COMBO_BOX(object))
		if (gtk_combobox_signal_handler_connector(handler_name,
					object,
					signal_name,
					signal_data,
					connect_object,
					after,
					user_data))
			return;

	if (GTK_IS_SCALE(object))
		if (gtk_scale_signal_handler_connector(handler_name,
					object,
					signal_name,
					signal_data,
					connect_object,
					after,
					user_data))
			return;
	/*
	 * Some thing is obviously missing.
	 */
	if (GTK_IS_WIDGET(object))
		if (gtk_widget_signal_handler_connector(handler_name, 
				object,
				signal_name,
				signal_data,
				connect_object,
				after,
				user_data))
			return;

	g_warning("%s(): Unhandled signal: '%s'", __func__, signal_name);
		
}


static void
register_widgets(GladeXML *glade_xml)
{
	GList        *widget_list, *li;
	GtkWidget    *widget;
	AttributeSet *Attr;
	gint          type;
	const gchar  *name;

	widget_list = glade_xml_get_widget_prefix(glade_xml, "");
	for (li = widget_list; li != NULL; li = li->next) {
		widget = li->data;
		name = gtk_widget_get_name(li->data);
		Attr = attributeset_new();
		attributeset_set_if_unset(Attr, ATTR_VARIABLE, name);
		type = widget_get_type_from_pointer(widget);
		variables_new_with_widget(Attr, NULL, widget, type);
#ifdef DEBUG
		g_message("%s(): widget name: %s, type: %d", 
				__func__, name, type);
#endif
	}
	g_list_free(widget_list);
}

static void
refresh_widgets(GladeXML *glade_xml)
{
	GList        *widget_list, *li;
	GtkWidget    *widget;
	AttributeSet *Attr;
	gint          type;
	const gchar  *name;

	widget_list = glade_xml_get_widget_prefix(glade_xml, "");
	for (li = widget_list; li != NULL; li = li->next) {
		widget = li->data;
		name = gtk_widget_get_name(li->data);
		variables_refresh(name);
	}

	g_list_free(widget_list);
}

/* Thunor 2011-07-16: This seems so incredibly out-of-date -- it's only
 * got 20% of the widgets in there! It's returning the widget type to
 * glade_support.c and variable->Type is checked throughout the code so
 * it must be important.
 * 
 * These MUST be in an order that returns widgets lower down the
 * hierarchy before those higher up.
 * 
 * WIDGET_GVIM is a custom widget and isn't included.
 */

gint widget_get_type_from_pointer(GtkWidget *widget)
{
	gint              retval = 0;

/* GtkWidget--->GtkContainer--->GtkBin--->GtkButton--->GtkToggleButton--->GtkCheckButton--->GtkRadioButton */
	if (GTK_IS_RADIO_BUTTON(widget))
		retval = WIDGET_RADIOBUTTON;
/* GtkWidget--->GtkContainer--->GtkBin--->GtkButton--->GtkToggleButton--->GtkCheckButton */
	else if (GTK_IS_CHECK_BUTTON(widget))
		retval = WIDGET_CHECKBOX;
/* GtkWidget--->GtkContainer--->GtkBin--->GtkButton--->GtkColorButton */
	else if (GTK_IS_COLOR_BUTTON(widget))
		retval = WIDGET_COLORBUTTON;
/* GtkWidget--->GtkContainer--->GtkBin--->GtkButton--->GtkToggleButton */
	else if (GTK_IS_TOGGLE_BUTTON(widget))
		retval = WIDGET_TOGGLEBUTTON;
/* GtkWidget--->GtkContainer--->GtkBin--->GtkButton--->GtkFontButton */
	else if (GTK_IS_FONT_BUTTON(widget))
		retval = WIDGET_FONTBUTTON;
/* GtkWidget--->GtkContainer--->GtkBin--->GtkButton */
	else if (GTK_IS_BUTTON(widget))
		retval = WIDGET_BUTTON;
/* GtkWidget--->GtkContainer--->GtkBin--->GtkComboBox--->GtkComboBoxEntry */
	else if (GTK_IS_COMBO_BOX_ENTRY(widget))
		retval = WIDGET_COMBOBOXENTRY;
/* GtkWidget--->GtkContainer--->GtkBin--->GtkComboBox */
/* NOTE: <comboboxtext> is actually a combobox and not a comboboxtext */
	else if (GTK_IS_COMBO_BOX(widget))
		retval = WIDGET_COMBOBOXTEXT;
/* GtkWidget--->GtkContainer--->GtkBin--->GtkEventBox */
	else if (GTK_IS_EVENT_BOX(widget))
		retval = WIDGET_EVENTBOX;
/* GtkWidget--->GtkContainer--->GtkBin--->GtkExpander */
	else if (GTK_IS_EXPANDER(widget))
		retval = WIDGET_EXPANDER;
/* GtkWidget--->GtkContainer--->GtkBin--->GtkFrame */
	else if (GTK_IS_FRAME(widget))
		retval = WIDGET_FRAME;
/* GtkWidget--->GtkContainer--->GtkBin--->GtkItem--->GtkMenuItem--->GtkSeparatorMenuItem */
	else if (GTK_IS_SEPARATOR_MENU_ITEM(widget))
		retval = WIDGET_MENUITEMSEPARATOR;
/* GtkWidget--->GtkContainer--->GtkBin--->GtkItem--->GtkMenuItem */
	else if (GTK_IS_MENU_ITEM(widget))
		retval = WIDGET_MENUITEM;
/* GtkWidget--->GtkContainer--->GtkBin--->GtkScrolledWindow */
	else if (GTK_IS_SCROLLED_WINDOW(widget))
		retval = WIDGET_SCROLLEDW;
/* GtkWidget--->GtkContainer--->GtkBin--->GtkWindow */
	else if (GTK_IS_WINDOW(widget))
		retval = WIDGET_WINDOW;
/* GtkWidget--->GtkContainer--->GtkBox--->GtkHBox--->GtkCombo */
	else if (GTK_IS_COMBO(widget))
		retval = WIDGET_COMBOBOX;
/* GtkWidget--->GtkContainer--->GtkBox--->GtkHBox--->GtkStatusbar */
	else if (GTK_IS_STATUSBAR(widget))
		retval = WIDGET_STATUSBAR;
/* GtkWidget--->GtkContainer--->GtkBox--->GtkHBox */
	else if (GTK_IS_HBOX(widget))
		retval = WIDGET_HBOX;
/* GtkWidget--->GtkContainer--->GtkBox--->GtkVBox--->GtkFileChooserWidget */
	else if (GTK_IS_FILE_CHOOSER_WIDGET(widget))
		retval = WIDGET_CHOOSER;
/* GtkWidget--->GtkContainer--->GtkBox--->GtkVBox */
	else if (GTK_IS_VBOX(widget))
		retval = WIDGET_VBOX;
/* GtkWidget--->GtkContainer--->GtkCList */
	else if (GTK_IS_CLIST(widget))
		retval = WIDGET_TABLE;
/* GtkWidget--->GtkContainer--->GtkList */
	else if (GTK_IS_LIST(widget))
		retval = WIDGET_LIST;
/* GtkWidget--->GtkContainer--->GtkMenuShell--->GtkMenuBar */
	else if (GTK_IS_MENU_BAR(widget))
		retval = WIDGET_MENUBAR;
/* GtkWidget--->GtkContainer--->GtkMenuShell--->GtkMenu */
	else if (GTK_IS_MENU(widget))
		retval = WIDGET_MENU;
/* GtkWidget--->GtkContainer--->GtkNotebook */
	else if (GTK_IS_NOTEBOOK(widget))
		retval = WIDGET_NOTEBOOK;
/* GtkWidget--->GtkContainer--->GtkTextView */
	else if (GTK_IS_TEXT_VIEW(widget))
		retval = WIDGET_EDIT;
/* GtkWidget--->GtkContainer--->GtkTreeView */
	else if (GTK_IS_TREE_VIEW(widget))
		retval = WIDGET_TREE;
/* GtkWidget--->GtkEntry-->GtkSpinButton */
	else if (GTK_IS_SPIN_BUTTON(widget))
		retval = WIDGET_SPINBUTTON;
/* GtkWidget--->GtkEntry */
	else if (GTK_IS_ENTRY(widget))
		retval = WIDGET_ENTRY;
/* GtkWidget--->GtkMisc--->GtkImage */
	else if (GTK_IS_IMAGE(widget))
		retval = WIDGET_PIXMAP;
/* GtkWidget--->GtkMisc--->GtkLabel */
	else if (GTK_IS_LABEL(widget))
		retval = WIDGET_TEXT;
/* GtkWidget--->GtkProgress--->GtkProgressBar */
	else if (GTK_IS_PROGRESS_BAR(widget))
		retval = WIDGET_PROGRESSBAR;
/* GtkWidget--->GtkRange--->GtkScale--->GtkHScale */
	else if (GTK_IS_HSCALE(widget))
		retval = WIDGET_HSCALE;
/* GtkWidget--->GtkRange--->GtkScale--->GtkVScale */
	else if (GTK_IS_VSCALE(widget))
		retval = WIDGET_VSCALE;
/* GtkWidget--->GtkSeparator--->GtkHSeparator */
	else if (GTK_IS_HSEPARATOR(widget))
		retval = WIDGET_HSEPARATOR;
/* GtkWidget--->GtkSeparator--->GtkVSeparator */
	else if (GTK_IS_VSEPARATOR(widget))
		retval = WIDGET_VSEPARATOR;
/* GtkWidget hasn't been accounted for */
	else
		retval = 0;

	return retval;
}

/*************************************************************************
 * Public functions:                                                     *
 *                                                                       *
 *                                                                       *
 *************************************************************************/
void
run_program_by_glade(
		const gchar *filename,
		const gchar *window_name) 
{
	GladeXML  *glade_xml;
	GtkWidget *main_window;

	glade_init();	
	glade_xml = glade_xml_new(filename, NULL, PACKAGE);
	if (window_name != NULL)
		main_window = glade_xml_get_widget(glade_xml, window_name);
	else
		main_window = glade_xml_get_widget(glade_xml, "MAIN_WINDOW");

	if (main_window == NULL)
		g_error("Can not load '%s' from file '%s'", window_name,
				filename);
	/*
	 *
	 */
	register_widgets(glade_xml);
	/*
	 * Connecting the signals.
	 */
	glade_xml_signal_autoconnect_full(glade_xml,
			(GladeXMLConnectFunc) signal_handler_connector,
			NULL);
	gtk_signal_connect(GTK_OBJECT(main_window), "delete-event",
			   GTK_SIGNAL_FUNC(window_delete_event_handler), NULL);
	
	refresh_widgets(glade_xml);
	
	gtk_widget_show(main_window);
	gtk_main();
}

#endif	/* HAVE_GLADE_LIB */
