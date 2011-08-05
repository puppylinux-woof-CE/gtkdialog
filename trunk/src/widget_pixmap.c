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
#include "attributes.h"
#include "automaton.h"

/* Defines */
//#define DEBUG_CONTENT
//#define DEBUG_TRANSITS

/* Local function prototypes */
static void fill_by_command(variable *var, char *command);
static void fill_by_file(variable *var, char *filename);
static void fill_by_items(variable *var);

/* Notes: */

/***********************************************************************
 * Clear                                                               *
 ***********************************************************************/

void widget_pixmap_clear(variable *var)
{
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	g_message("%s(): Entering.", __func__);
#endif

	g_message("%s(): Clear not implemented for this widget.", __func__);

#ifdef DEBUG_TRANSITS
	g_message("%s(): Exiting.", __func__);
#endif
}

/***********************************************************************
 * Create                                                              *
 ***********************************************************************/
GtkWidget *widget_pixmap_create(
	AttributeSet *Attr, tag_attr *tag_attributes, gint Type)
{
	GtkWidget        *widget;
	GdkPixbuf        *pixbuf;
	gchar            *icon_file_name, *icon_stock_name;
	gint              width = -1, height = -1;

#ifdef DEBUG_TRANSITS
	g_message("%s(): Entering.", __func__);
#endif

	icon_file_name = attributeset_get_first(Attr, ATTR_INPUT) + 5;
	icon_stock_name = attributeset_get_this_tagattr(Attr, ATTR_INPUT, "stock");

	if (icon_stock_name != NULL) {
		widget = gtk_image_new_from_stock(icon_stock_name, GTK_ICON_SIZE_DND);
	} else {
		if (attributeset_is_avail(Attr, ATTR_WIDTH))
			width = atoi(attributeset_get_first(Attr, ATTR_WIDTH));
		if (attributeset_is_avail(Attr, ATTR_HEIGHT))
			height = atoi(attributeset_get_first(Attr, ATTR_HEIGHT));

		if (width == -1 && height == -1) {
			/* Handle unscaled images */
			widget = gtk_image_new_from_file(find_pixmap(icon_file_name));
		} else {
			/* Handle scaled images */
			pixbuf = gdk_pixbuf_new_from_file_at_size(
				find_pixmap(icon_file_name), width, height, NULL);
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
	}

#ifdef DEBUG_TRANSITS
	g_message("%s(): Exiting.", __func__);
#endif

	return widget;
}

/***********************************************************************
 * Environment Variable All Compose                                    *
 ***********************************************************************/

gchar *widget_pixmap_envvar_all_compose(variable *var)
{
	gchar            *string;

#ifdef DEBUG_TRANSITS
	g_message("%s(): Entering.", __func__);
#endif

	/* This function should not be connected-up by default */

#ifdef DEBUG_TRANSITS
	g_message("%s(): Exiting.", __func__);
#endif

	return string;
}

/***********************************************************************
 * Environment Variable One Compose                                    *
 ***********************************************************************/

gchar *widget_pixmap_envvar_one_compose(GtkWidget *widget)
{
	gchar            *string;

#ifdef DEBUG_TRANSITS
	g_message("%s(): Entering.", __func__);
#endif

	string = g_strdup("");

#ifdef DEBUG_TRANSITS
	g_message("%s(): Exiting.", __func__);
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
	g_message("%s(): Entering.", __func__);
#endif

	g_message("%s(): Fileselect not implemented for this widget.", __func__);

#ifdef DEBUG_TRANSITS
	g_message("%s(): Exiting.", __func__);
#endif
}

/***********************************************************************
 * Refresh                                                             *
 ***********************************************************************/
void widget_pixmap_refresh(variable *var)
{
	gchar            *act;
	gint              initialised = FALSE;

#ifdef DEBUG_TRANSITS
	g_message("%s(): Entering.", __func__);
#endif

	/* Get initialised state of widget */
	if (g_object_get_data(G_OBJECT(var->Widget), "initialised") != NULL)
		initialised = (gint)g_object_get_data(G_OBJECT(var->Widget), "initialised");

	act = attributeset_get_first(var->Attributes, ATTR_INPUT);
	while (act) {
		if (input_is_shell_command(act))
			fill_by_command(var, act + 8);
		/* input file stock = "File:", input file = "File:/path/to/file" */
		if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5)
			fill_by_file(var, act + 5);
		act = attributeset_get_next(var->Attributes, ATTR_INPUT);
	}

	/* The <item> tags... */
	if (attributeset_is_avail(var->Attributes, ATTR_ITEM))
		fill_by_items(var);

	/* Initialise these only once at start-up */
	if (!initialised) {
		/* Apply directives */
		if (attributeset_cmp_left(var->Attributes, ATTR_VISIBLE, "disabled"))
			gtk_widget_set_sensitive(var->Widget, FALSE);

		/* Connect signals */

	}

#ifdef DEBUG_TRANSITS
	g_message("%s(): Exiting.", __func__);
#endif
}

/***********************************************************************
 * Remove Selected                                                     *
 ***********************************************************************/

void widget_pixmap_removeselected(variable *var)
{
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	g_message("%s(): Entering.", __func__);
#endif

	g_message("%s(): Removeselected not implemented for this widget.", __func__);

#ifdef DEBUG_TRANSITS
	g_message("%s(): Exiting.", __func__);
#endif
}

/***********************************************************************
 * Save to File                                                        *
 ***********************************************************************/

void widget_pixmap_save_to_file(variable *var)
{
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	g_message("%s(): Entering.", __func__);
#endif

	g_message("%s(): Save to File not implemented for this widget.", __func__);

#ifdef DEBUG_TRANSITS
	g_message("%s(): Exiting.", __func__);
#endif
}

/***********************************************************************
 * Fill by Command                                                     *
 ***********************************************************************/

static void fill_by_command(variable *var, char *command)
{
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	g_message("%s(): Entering.", __func__);
#endif

	g_message("%s(): Fill by Command not implemented for this widget.", __func__);

#ifdef DEBUG_TRANSITS
	g_message("%s(): Exiting.", __func__);
#endif
}

/***********************************************************************
 * Fill by File                                                        *
 ***********************************************************************/

static void fill_by_file(variable *var, char *filename)
{
	GdkPixbuf        *pixbuf;
	gint              initialised = FALSE;
	gint              width = -1, height = -1;

#ifdef DEBUG_TRANSITS
	g_message("%s(): Entering.", __func__);
#endif

	/* Get initialised state of widget */
	if (g_object_get_data(G_OBJECT(var->Widget), "initialised") != NULL)
		initialised = (gint)g_object_get_data(G_OBJECT(var->Widget), "initialised");

	if (initialised) {
		if (attributeset_is_avail(var->Attributes, ATTR_WIDTH))
			width = atoi(attributeset_get_first(var->Attributes, ATTR_WIDTH));
		if (attributeset_is_avail(var->Attributes, ATTR_HEIGHT))
			height = atoi(attributeset_get_first(var->Attributes, ATTR_HEIGHT));

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
	}

#ifdef DEBUG_TRANSITS
	g_message("%s(): Exiting.", __func__);
#endif
}

/***********************************************************************
 * Fill by Items                                                       *
 ***********************************************************************/

static void fill_by_items(variable *var)
{
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	g_message("%s(): Entering.", __func__);
#endif

	g_message("%s(): Fill by Items not implemented for this widget.", __func__);

#ifdef DEBUG_TRANSITS
	g_message("%s(): Exiting.", __func__);
#endif
}
