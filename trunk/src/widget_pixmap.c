/*
 * widget_pixmap.c: 
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
#include "tag_attributes.h"

/* Defines */
//#define DEBUG_CONTENT
//#define DEBUG_TRANSITS

/* Local function prototypes, located at file bottom */
static void widget_pixmap_input_by_command(variable *var, char *command);
static void widget_pixmap_input_by_file(variable *var, char *filename);
static void widget_pixmap_input_by_items(variable *var);
void widget_pixmap_monitor_callback(GFileMonitor *monitor, GFile *file,
	GFile *other_file, GFileMonitorEvent event_type, variable *var);

/* Local variables */

/* Notes: */

/***********************************************************************
 * Clear                                                               *
 ***********************************************************************/

void widget_pixmap_clear(variable *var)
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

GtkWidget *widget_pixmap_create(
	AttributeSet *Attr, tag_attr *attr, gint Type)
{
	GError           *error = NULL;
	GFile            *file;
	GFileMonitor     *monitor;
	GList            *element;
	GtkIconTheme     *icon_theme;
	GtkWidget        *widget;
	GdkPixbuf        *pixbuf;
	gchar            *act;
	gchar            *file_name;
	gchar            *icon_name = NULL;
	gchar            *stock_name = NULL;
	gchar            *value;
	gint              width = -1, height = -1;
	gint              theme_icon_size = 32;
	gint              stock_icon_size = GTK_ICON_SIZE_DND;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (attributeset_is_avail(Attr, ATTR_HEIGHT))
		height = atoi(attributeset_get_first(&element, Attr, ATTR_HEIGHT));
	if (attributeset_is_avail(Attr, ATTR_WIDTH))
		width = atoi(attributeset_get_first(&element, Attr, ATTR_WIDTH));

	/* The <input> tag... */
	act = attributeset_get_first(&element, Attr, ATTR_INPUT);
	while (act) {
#ifdef DEBUG_CONTENT
		fprintf(stderr, "%s(): act=%s\n", __func__, act);
#endif
		/* input file stock = "File:", input file = "File:/path/to/file" */
		if (strncasecmp(act, "file:", 5) == 0) {
			if ((stock_name = attributeset_get_this_tagattr(&element,
				Attr, ATTR_INPUT, "stock")) != NULL) {
				/* Get stock-icon-size (custom) */
				if (attr &&
					(value = get_tag_attribute(attr, "stock-icon-size")))
					stock_icon_size = atoi(value);
				widget = gtk_image_new_from_stock(stock_name, stock_icon_size);
				break;	/* Only one image is required */
			}
			if ((icon_name = attributeset_get_this_tagattr(&element,
				Attr, ATTR_INPUT, "icon")) != NULL) {
				icon_theme = gtk_icon_theme_get_default();
				/* Use the height or width dimension to override the default size */
				if (height > -1) theme_icon_size = height;
				else if (width > -1) theme_icon_size = width;
				/* Get theme-icon-size (custom) */
				if (attr &&
					(value = get_tag_attribute(attr, "theme-icon-size")))
					theme_icon_size = atoi(value);
				pixbuf = gtk_icon_theme_load_icon(icon_theme, icon_name,
					theme_icon_size, 0, &error);
				if (pixbuf) {
					widget = gtk_image_new_from_pixbuf(pixbuf);
					/* pixbuf is no longer required and should be unreferenced */
					g_object_unref(pixbuf);
				} else {
					/* pixbuf is null (file not found) so by using this
					 * function gtk will substitute a broken image icon */
					widget = gtk_image_new_from_file("");
				}
				break;	/* Only one image is required */
			}
			if (strlen(act) > 5) {
				file_name = act + 5;
				if (width == -1 && height == -1) {
					/* Handle unscaled images */
					widget = gtk_image_new_from_file(find_pixmap(file_name));
				} else {
					/* Handle scaled images */
					pixbuf = gdk_pixbuf_new_from_file_at_size(
						find_pixmap(file_name), width, height, NULL);
					if (pixbuf) {
						widget = gtk_image_new_from_pixbuf(pixbuf);
						/* pixbuf is no longer required and should be unreferenced */
						g_object_unref(pixbuf);
					} else {
						/* pixbuf is null (file not found) so by using this
						 * function gtk will substitute a broken image icon */
						widget = gtk_image_new_from_file("");
					}
				}
				/* Are we auto-refreshing this pixmap? */
				if (attr) {
					/* Get auto-refresh (custom) */
					if ((value = get_tag_attribute(attr, "auto-refresh")) &&
						((strcasecmp(value, "true") == 0) ||
						(strcasecmp(value, "yes") == 0) ||
						(atoi(value) == 1))) {
						/* GIO Reference states this will never fail */
						file = g_file_new_for_path(find_pixmap(file_name));
						/* I can't make this return NULL although if the
						 * file doesn't exist then it just doesn't work */
						monitor = g_file_monitor_file(file, G_FILE_MONITOR_NONE,
							FALSE, &error);
#ifdef DEBUG_CONTENT
						fprintf(stderr, "%s(): file=%p monitor=%p\n", __func__,
							file, monitor);
#endif
						if (monitor) {
							/* Get rate-limit (custom) */
							if ((value = get_tag_attribute(attr, "rate-limit"))) {
								/* I tested this and couldn't detect a change */
								g_file_monitor_set_rate_limit(monitor, atoi(value));
							}
							/* Store monitor as a piece of widget data */
							g_object_set_data(G_OBJECT(widget), "monitor",
								(gpointer)monitor);
						} else {
							if (file) g_object_unref(file);
						}
					}
				}
				break;	/* Only one image is required */
			}
		}
		act = attributeset_get_next(&element, Attr, ATTR_INPUT);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return widget;
}

/***********************************************************************
 * Environment Variable All Construct                                  *
 ***********************************************************************/

gchar *widget_pixmap_envvar_all_construct(variable *var)
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

gchar *widget_pixmap_envvar_construct(GtkWidget *widget)
{
	gchar            *string;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	string = g_strdup("");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return string;
}

/***********************************************************************
 * Fileselect                                                          *
 ***********************************************************************/

void widget_pixmap_fileselect(
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

void widget_pixmap_refresh(variable *var)
{
	GFileMonitor     *monitor;
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
			widget_pixmap_input_by_command(var, act + 8);
		/* input file stock = "File:", input file = "File:/path/to/file" */
		if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5) {
			/* Don't refresh images on the first call otherwise they
			 * get created and then immediately refreshed at start-up */
			if (initialised)
				widget_pixmap_input_by_file(var, act + 5);
		}
		act = attributeset_get_next(&element, var->Attributes, ATTR_INPUT);
	}

	/* The <item> tags... */
	if (attributeset_is_avail(var->Attributes, ATTR_ITEM))
		widget_pixmap_input_by_items(var);

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
		if ((monitor = g_object_get_data(G_OBJECT(var->Widget), "monitor"))) {
			g_signal_connect(monitor, "changed",
				G_CALLBACK(widget_pixmap_monitor_callback), (gpointer)var);
		}
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Removeselected                                                      *
 ***********************************************************************/

void widget_pixmap_removeselected(variable *var)
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

void widget_pixmap_save(variable *var)
{
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	fprintf(stderr, "%s(): Save not implemented for this widget.\n", __func__);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by Command                                                    *
 ***********************************************************************/

static void widget_pixmap_input_by_command(variable *var, char *command)
{
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	fprintf(stderr, "%s(): <input> not implemented for this widget.\n", __func__);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by File                                                       *
 ***********************************************************************/

static void widget_pixmap_input_by_file(variable *var, char *filename)
{
	GdkPixbuf        *pixbuf;
	GList            *element;
	gint              width = -1, height = -1;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (attributeset_is_avail(var->Attributes, ATTR_WIDTH))
		width = atoi(attributeset_get_first(&element, var->Attributes, ATTR_WIDTH));
	if (attributeset_is_avail(var->Attributes, ATTR_HEIGHT))
		height = atoi(attributeset_get_first(&element, var->Attributes, ATTR_HEIGHT));

	if (width == -1 && height == -1) {
		/* Handle unscaled images */
		gtk_image_set_from_file(GTK_IMAGE(var->Widget), find_pixmap(filename));
	} else {
		/* Handle scaled images */
		pixbuf = gdk_pixbuf_new_from_file_at_size(
			find_pixmap(filename), width, height, NULL);
		if (pixbuf) {
			gtk_image_set_from_pixbuf(GTK_IMAGE(var->Widget), pixbuf);
			/* pixbuf is no longer required and should be unreferenced */
			g_object_unref(pixbuf);
		} else {
			/* pixbuf is null (file not found) so by using this
			 * function gtk will substitute a broken image icon */
			gtk_image_set_from_file(GTK_IMAGE(var->Widget), "");
		}
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by Items                                                      *
 ***********************************************************************/

static void widget_pixmap_input_by_items(variable *var)
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

/***********************************************************************
 * Auto-Refresh File Monitor Callback                                  *
 ***********************************************************************/
/* Events occur in this sequence when a file is recreated using rox:
 * 
 * G_FILE_MONITOR_EVENT_DELETED (2)
 * G_FILE_MONITOR_EVENT_CREATED (3)
 * G_FILE_MONITOR_EVENT_CHANGED (0)
 * G_FILE_MONITOR_EVENT_CHANGES_DONE_HINT (1)
 * G_FILE_MONITOR_EVENT_ATTRIBUTE_CHANGED (4)
 * G_FILE_MONITOR_EVENT_CHANGES_DONE_HINT (1)
 * 
 * And from rxvt:
 * 
 * G_FILE_MONITOR_EVENT_CHANGED (0)
 * G_FILE_MONITOR_EVENT_CHANGES_DONE_HINT (1)
 * 
 */

void widget_pixmap_monitor_callback(GFileMonitor *monitor, GFile *file,
	GFile *other_file, GFileMonitorEvent event_type, variable *var)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): event_type=%i filename=%s\n", __func__,
		event_type, g_file_get_path(file));
#endif

	if (var && var->Widget) {
		if (event_type == G_FILE_MONITOR_EVENT_CHANGED) {
			/* Refresh the image from file */
			widget_pixmap_input_by_file(var, g_file_get_path(file));
			/* Make the "changed" signal available to the app. developer */
			on_any_widget_changed_event(var->Widget, var->Attributes);
		}
	} else {
		/* The widget has been dropped/destroyed so kill the monitor */
		if (monitor) g_file_monitor_cancel(monitor);
		if (monitor) g_object_unref(monitor);
		if (file) g_object_unref(file);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}
