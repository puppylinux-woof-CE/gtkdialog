/*
 * signals.h:
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

#ifndef SIGNALS_H
#define SIGNALS_H

/* Function prototypes */
void button_clicked_attr(GtkWidget *button, AttributeSet *Attr);
void button_entered_attr(GtkWidget *button, AttributeSet *Attr);
void button_leaved_attr(GtkWidget *button, AttributeSet *Attr);
void button_pressed(GtkWidget *button, const gchar *str);
void button_pressed_attr(GtkWidget *button, AttributeSet *Attr);
void button_released_attr(GtkWidget *button, AttributeSet *Attr);

void on_any_widget_activate_event(GtkWidget *widget, AttributeSet  *Attr);
gboolean on_any_widget_button_pressed(GtkWidget *widget,
	GdkEventButton *event, AttributeSet *Attr);
gboolean on_any_widget_button_released(GtkWidget *widget,
	GdkEventButton *event, AttributeSet *Attr);
void on_any_widget_changed_event(GtkWidget *widget, AttributeSet  *Attr);
void on_any_widget_color_set_event(GtkWidget *widget, AttributeSet *Attr);
void on_any_widget_font_set_event(GtkWidget *widget, AttributeSet *Attr);
gboolean on_any_widget_configure_event(GtkWidget *widget,
	GdkEventConfigure *event, AttributeSet *Attr);
gboolean on_any_widget_delete_event(GtkWidget *widget, GdkEvent *event,
	AttributeSet *Attr);
gboolean on_any_widget_destroy_event(GtkWidget *widget, GdkEvent *event,
	AttributeSet *Attr);
gboolean on_any_widget_enter_notify_event(GtkWidget *widget,
	GdkEventCrossing *event, AttributeSet *Attr);
gboolean on_any_widget_focus_in_event(GtkWidget *widget,
	GdkEventFocus *event, AttributeSet *Attr);
gboolean on_any_widget_focus_out_event(GtkWidget *widget,
	GdkEventFocus *event, AttributeSet *Attr);
void on_any_widget_hide(GtkWidget *widget, AttributeSet *Attr);
#if GTK_CHECK_VERSION(2,16,0)
void on_any_widget_icon_press_event(GtkWidget *widget,
	GtkEntryIconPosition pos, GdkEvent *event, AttributeSet *Attr);
void on_any_widget_icon_release_event(GtkWidget *widget,
	GtkEntryIconPosition pos, GdkEvent *event, AttributeSet *Attr);
#endif
void on_any_widget_child_exited_event(GtkWidget *widget, AttributeSet *Attr);
gboolean on_any_widget_key_press_event(GtkWidget *widget,
	GdkEventKey *event, AttributeSet *Attr);
gboolean on_any_widget_key_release_event(GtkWidget*widget,
	GdkEventKey *event, AttributeSet *Attr);
gboolean on_any_widget_leave_notify_event(GtkWidget *widget,
	GdkEventCrossing *event, AttributeSet *Attr);
gboolean on_any_widget_map_event(GtkWidget *widget, GdkEvent *event,
	AttributeSet *Attr);
void on_any_widget_realized(GtkWidget *widget, tag_attr *tag_attributes);
void on_any_widget_show(GtkWidget *widget, AttributeSet *Attr);
void on_any_widget_toggled_event(GtkWidget *widget, AttributeSet *Attr);
gboolean on_any_widget_unmap_event(GtkWidget *widget, GdkEvent *event,
	AttributeSet *Attr);
void on_any_widget_value_changed_event(GtkWidget *widget, AttributeSet  *Attr);

void on_any_widget_select_row_event(GtkWidget *widget, gint row,
	gint column, GdkEvent *event, gpointer Attr);
void on_any_widget_selection_changed_event(GtkWidget *widget, AttributeSet *Attr);
void on_any_widget_row_activated_event(GtkWidget *widget,
	GtkTreePath *path, GtkTreeViewColumn *column, AttributeSet *Attr);
void on_any_widget_cursor_changed_event(GtkWidget *widget, AttributeSet *Attr);

#if HAVE_SYS_INOTIFY_H
void on_any_widget_file_changed_event(gpointer data, gint source,
	GdkInputCondition condition);
void on_any_widget_auto_refresh_event(gpointer data, gint source,
	GdkInputCondition condition);
#else
void on_any_widget_file_changed_event(GFileMonitor *monitor, GFile *file,
	GFile *other_file, GFileMonitorEvent event_type, variable *var);
void on_any_widget_auto_refresh_event(GFileMonitor *monitor, GFile *file,
	GFile *other_file, GFileMonitorEvent event_type, variable *var);
#endif

/*void tree_row_activated_attr(GtkTreeView *tree_view, GtkTreePath *path,
	GtkTreeViewColumn *column, AttributeSet *Attr); Redundant */
/*gboolean tree_cursor_changed(GtkTreeView *tree_view, AttributeSet *Attr); Redundant */

gint window_delete_event_handler(GtkWidget *widget, GtkWidget *event,
	gpointer data);
void widget_signal_executor(GtkWidget *widget, AttributeSet *Attr,
	const gchar *signal_name);
void widget_file_monitor_try_create(variable *var, gchar *filename);

#endif
