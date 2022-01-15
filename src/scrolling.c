/*
 * scrolling.c: miscellaneous functions for scrollable widgets
 * Gtkdialog - A small utility for fast and easy GUI building.
 * Copyright (C) 2021       step https://github.com/step-
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
#include "scrolling.h"

/* Defines */
//#define DEBUG_CONTENT
//#define DEBUG_TRANSITS

/* Local function prototypes, located at file bottom */
static void scroll_value_changed (GtkAdjustment *adjustment, gpointer user_data);
static void scroll_bottom_gravity (GtkWidget *scrolled_window,
	GdkRectangle *allocation,
	gpointer      user_data);

/* Notes:
 * step - scroll to bottom inspired by https://discourse.gnome.org/t/1337/2 */

/***********************************************************************
 * Scroll to Bottom
 ***********************************************************************/

void setup_scroll_to_bottom(variable *var)
{
	/* var->Widget being a scrollable widget can be scrolled to bottom */
	GtkAdjustment *adjustment;
	GtkWidget     *w;
	gchar         *value;
	double *from_bottom;

	/* If the custom attribute "scroll-to-bottom" is true
	 * then arrange for the scrollbar to scroll to bottom */
	if (var->widget_tag_attr &&
		(value = get_tag_attribute(var->widget_tag_attr, "scroll-to-bottom")) &&
		((strcasecmp(value, "true") == 0) ||
		(strcasecmp(value, "yes") == 0) || (atoi(value) == 1)) &&
		(w = gtk_widget_get_ancestor(var->Widget, GTK_TYPE_SCROLLED_WINDOW)) &&
		(from_bottom = g_slice_new0(double))) /* from_bottom is never freed */
	{
		/* store the scroll adjustment as heap data to be shared between the event handlers */
		adjustment = gtk_scrolled_window_get_vadjustment(GTK_SCROLLED_WINDOW (w));
		g_signal_connect(w, "size-allocate", (GCallback) scroll_bottom_gravity, from_bottom);
		g_signal_connect(adjustment, "value-changed", (GCallback) scroll_value_changed, from_bottom);
	}
}

/***********************************************************************
 * Scroll to Bottom Callbacks                                          *
 ***********************************************************************/
static void scroll_value_changed (GtkAdjustment *adjustment, gpointer user_data)
{
	double *from_bottom = user_data;
	double value = gtk_adjustment_get_value (adjustment);
	double upper = gtk_adjustment_get_upper (adjustment);
	double page_size = gtk_adjustment_get_page_size (adjustment);
	*from_bottom = upper - page_size - value;
}

static void scroll_bottom_gravity (GtkWidget *scrolled_window,
	GdkRectangle *allocation,
	gpointer      user_data)
{
	GtkAdjustment *adjustment = gtk_scrolled_window_get_vadjustment (
		GTK_SCROLLED_WINDOW (scrolled_window));
	double *from_bottom = user_data;
	double upper = gtk_adjustment_get_upper (adjustment);
	double page_size = gtk_adjustment_get_page_size (adjustment);
	gtk_adjustment_set_value (adjustment, upper - page_size - *from_bottom);
}

