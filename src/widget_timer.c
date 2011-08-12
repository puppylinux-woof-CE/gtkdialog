/*
 * widget_timer.c: 
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
#include "widgets.h"

/* Defines */
//#define DEBUG_CONTENT
//#define DEBUG_TRANSITS

/* Local function prototypes, located at file bottom */
static void widget_timer_input_by_command(variable *var, char *command);
static void widget_timer_input_by_file(variable *var, char *filename);
static void widget_timer_input_by_items(variable *var);
gboolean widget_timer_timer_callback(gpointer data);

/* Notes:
 * This is a custom widget in that it's a GtkLabel displaying the
 * widget's variable name with a timer_id set as a piece of widget data
 * (the user is responsible for hiding it with the "visible" property).
 * The timer callback calls the widget_signal_executor with a custom
 * "tick" signal if the widget is sensitive, and then it's processed the
 * same as any other signal */

/***********************************************************************
 * Clear                                                               *
 ***********************************************************************/

void widget_timer_clear(variable *var)
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
GtkWidget *widget_timer_create(
	AttributeSet *Attr, tag_attr *attr, gint Type)
{
	GtkWidget        *widget;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget = gtk_label_new("");

	/* I can't create the label here as a default variable name isn't
	 * created until after widget creation.
	 * 
	 * I can't create the timer here as I need a pointer to its variable
	 * and this isn't created until after widget creation.
	 * 
	 * I can't set the widget invisible here because gtk_widget_show_all
	 * in automaton.c will unhide everything, so it must be managed by
	 * the user with the "visible" tag attribute -- GTK+ will apply this
	 * on widget realization.
	 * 
	 * These things are accomplished in the refresh function which is
	 * called next */

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return widget;
}

/***********************************************************************
 * Environment Variable All Construct                                  *
 ***********************************************************************/

gchar *widget_timer_envvar_all_construct(variable *var)
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

gchar *widget_timer_envvar_construct(GtkWidget *widget)
{
	gchar            *string;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#if GTK_CHECK_VERSION(2,18,0)
	if (gtk_widget_get_sensitive(widget))
#else
	if (GTK_WIDGET_SENSITIVE(widget))
#endif
	{
		string = g_strdup("true");
	} else {
		string = g_strdup("false");
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return string;
}

/***********************************************************************
 * Fileselect                                                          *
 ***********************************************************************/

void widget_timer_fileselect(
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
void widget_timer_refresh(variable *var)
{
	gchar            *act;
	gchar             text[256];
	gchar            *value;
	gint              initialised = FALSE;
	gint              milliseconds = FALSE;
	guint             interval = 1;
	guint             timer_id;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* Get initialised state of widget */
	if (g_object_get_data(G_OBJECT(var->Widget), "initialised") != NULL)
		initialised = (gint)g_object_get_data(G_OBJECT(var->Widget), "initialised");

	/* The <input> tag... */
	act = attributeset_get_first(var->Attributes, ATTR_INPUT);
	while (act) {
		if (input_is_shell_command(act))
			widget_timer_input_by_command(var, act + 8);
		/* input file stock = "File:", input file = "File:/path/to/file" */
		if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5)
			widget_timer_input_by_file(var, act + 5);
		act = attributeset_get_next(var->Attributes, ATTR_INPUT);
	}

	/* The <item> tags... */
	if (attributeset_is_avail(var->Attributes, ATTR_ITEM))
		widget_timer_input_by_items(var);

	/* Initialise these only once at start-up */
	if (!initialised) {
		/* Create the timer */
		if (var->widget_tag_attr &&
			(value = get_tag_attribute(var->widget_tag_attr, "milliseconds")) &&
			((strcasecmp(value, "true") == 0) || (strcasecmp(value, "yes") == 0) ||
			(atoi(value) == 1))) {
			milliseconds = TRUE;
			interval = 1000;	/* Set default of 1000ms */
		}
		if (var->widget_tag_attr &&
			(value = get_tag_attribute(var->widget_tag_attr, "interval"))) {
			interval = atoi(value);
		}
		if (milliseconds) {
			/* Precision in milliseconds */
			timer_id = g_timeout_add(
				interval, widget_timer_timer_callback, (gpointer)var);
		} else {
			/* Precision in seconds (default) */
			timer_id = g_timeout_add_seconds(
				interval, widget_timer_timer_callback, (gpointer)var);
		}
		/* Store the timer_id as a piece of widget data */
		g_object_set_data(G_OBJECT(var->Widget), "timer_id", (gpointer)timer_id);
		/* Set the text of the label to its variable name */
		sprintf(text,
			"<span fgcolor='white' bgcolor='darkred'> %s </span>",
			attributeset_get_first(var->Attributes, ATTR_VARIABLE));
		gtk_label_set_markup(GTK_LABEL(var->Widget), text);

		/* Apply directives */
		if (attributeset_is_avail(var->Attributes, ATTR_DEFAULT))
			fprintf(stderr, "%s(): <default> not implemented for this widget.\n",
				__func__);
		if (attributeset_is_avail(var->Attributes, ATTR_HEIGHT))
			fprintf(stderr, "%s(): <height> not implemented for this widget.\n",
				__func__);
		if (attributeset_is_avail(var->Attributes, ATTR_WIDTH))
			fprintf(stderr, "%s(): <width> not implemented for this widget.\n",
				__func__);
		/* if (attributeset_cmp_left(var->Attributes, ATTR_VISIBLE, "disabled"))	Redundant */
		if ((attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "false")) ||
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "disabled")) ||	/* Deprecated */
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "no")) ||
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "0")))
			gtk_widget_set_sensitive(var->Widget, FALSE);

		/* Connect signals */

	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Removeselected                                                      *
 ***********************************************************************/

void widget_timer_removeselected(variable *var)
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

void widget_timer_save(variable *var)
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

static void widget_timer_input_by_command(variable *var, char *command)
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

static void widget_timer_input_by_file(variable *var, char *filename)
{

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	fprintf(stderr, "%s(): <input file> not implemented for this widget.\n", __func__);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by Items                                                      *
 ***********************************************************************/

static void widget_timer_input_by_items(variable *var)
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
 * Timer Callback                                                      *
 ***********************************************************************/

gboolean widget_timer_timer_callback(gpointer data)
{
	variable         *var = (variable*)data;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#ifdef DEBUG_CONTENT
	/* ATTR_VARIABLE and "timer_id" will definitely exist */
	fprintf(stderr, "%s(): ATTR_VARIABLE=%s  timer_id=%u\n", __func__,
		attributeset_get_first(var->Attributes, ATTR_VARIABLE),
		(guint)g_object_get_data(G_OBJECT(var->Widget), "timer_id"));
#endif

	/* Generate a custom signal if sensitive is true */
#if GTK_CHECK_VERSION(2,18,0)
	if (gtk_widget_get_sensitive(var->Widget))
#else
	if (GTK_WIDGET_SENSITIVE(var->Widget))
#endif
	{
		widget_signal_executor(var->Widget, var->Attributes, "tick");
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return TRUE;
}
