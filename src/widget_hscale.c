/*
 * widget_hscale.c: 
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
static void widget_hscale_input_by_command(variable *var, char *command);
static void widget_hscale_input_by_file(variable *var, char *filename);
static void widget_hscale_input_by_items(variable *var);

/* Notes: */

/***********************************************************************
 * Clear                                                               *
 ***********************************************************************/

void widget_hscale_clear(variable *var)
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

GtkWidget *widget_hscale_create(
	AttributeSet *Attr, tag_attr *attr, gint Type)
{
	GtkWidget        *widget;
	gdouble           range_min = 0;
	gdouble           range_max = 100;
	gdouble           range_step = 1;
	gdouble           range_value = 0;
	gchar            *value;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* Thunor: These "range-*" names are consistent with the spinbutton widget */
	if (attr) {
		if (!(value = get_tag_attribute(attr, "range-min")))
			value = get_tag_attribute(attr, "scale-min");
		if (value) range_min = atof(value);

		if (!(value = get_tag_attribute(attr, "range-max")))
			value = get_tag_attribute(attr, "scale-max");
		if (value) range_max = atof(value);

		if (!(value = get_tag_attribute(attr, "range-step")))
			value = get_tag_attribute(attr, "scale-step");
		if (value) range_step = atof(value);

		if (!(value = get_tag_attribute(attr, "range-value")))
			value = get_tag_attribute(attr, "scale-value");
		if (value) range_value = atof(value);
	}

	if (Type == WIDGET_HSCALE) {
#if !GTK_CHECK_VERSION(3,0,0)	/* gtk3: Deprecated in gtk3 so I've added the newly recommended equivalent */
		widget = gtk_hscale_new_with_range(range_min, range_max, range_step);
#else
		widget = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, range_min, range_max, range_step);
#endif
	} else {
#if !GTK_CHECK_VERSION(3,0,0)	/* gtk3: Deprecated in gtk3 so I've added the newly recommended equivalent */
		widget = gtk_vscale_new_with_range(range_min, range_max, range_step);
#else
		widget = gtk_scale_new_with_range(GTK_ORIENTATION_VERTICAL, range_min, range_max, range_step);
#endif
	}
	gtk_range_set_value(GTK_RANGE(widget), range_value);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return widget;
}

/***********************************************************************
 * Environment Variable All Construct                                  *
 ***********************************************************************/

gchar *widget_hscale_envvar_all_construct(variable *var)
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

gchar *widget_hscale_envvar_construct(GtkWidget *widget)
{
	gchar            *string;
	gchar             value[32];
	gdouble           val;
	gint              digits;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	digits = gtk_scale_get_digits(GTK_SCALE(widget));
	val = gtk_range_get_value(GTK_RANGE(widget));
	switch (digits) {
		case 0:
			sprintf(value, "%.0f", val);
			break;
		case 1:
			sprintf(value, "%.1f", val);
			break;
		case 2:
			sprintf(value, "%.2f", val);
			break;
		case 3:
			sprintf(value, "%.3f", val);
			break;
		case 4:
			sprintf(value, "%.4f", val);
			break;
		case 5:
			sprintf(value, "%.5f", val);
			break;
		case 6:
			sprintf(value, "%.6f", val);
			break;
		case 7:
			sprintf(value, "%.7f", val);
			break;
		case 8:
			sprintf(value, "%.8f", val);
			break;
		case 9:
			sprintf(value, "%.9f", val);
			break;
		case 10:
			sprintf(value, "%.10f", val);
			break;
		case 11:
			sprintf(value, "%.11f", val);
			break;
		case 12:
			sprintf(value, "%.12f", val);
			break;
		case 13:
			sprintf(value, "%.13f", val);
			break;
		case 14:
			sprintf(value, "%.14f", val);
			break;
		case 15:
			sprintf(value, "%.15f", val);
			break;
		case 16:
			sprintf(value, "%.16f", val);
			break;
		/* Is there much point going beyond 16? */
		default:
			sprintf(value, "%f", val);
			break;
	}
	string = g_strdup(value);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return string;
}

/***********************************************************************
 * Fileselect                                                          *
 ***********************************************************************/

void widget_hscale_fileselect(
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

void widget_hscale_refresh(variable *var)
{
	GList            *element;
	gchar            *act;
	gint              initialised = FALSE;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* Get initialised state of widget */
	if (g_object_get_data(G_OBJECT(var->Widget), "_initialised") != NULL)
		initialised = (gint)g_object_get_data(G_OBJECT(var->Widget), "_initialised");

	/* The <input> tag... */
	act = attributeset_get_first(&element, var->Attributes, ATTR_INPUT);
	while (act) {
		if (input_is_shell_command(act))
			widget_hscale_input_by_command(var, act + 8);
		/* input file stock = "File:", input file = "File:/path/to/file" */
		if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5) {
			if (!initialised) {
				/* Check for file-monitor and create if requested */
				widget_file_monitor_try_create(var, act + 5);
			}
			widget_hscale_input_by_file(var, act + 5);
		}
		act = attributeset_get_next(&element, var->Attributes, ATTR_INPUT);
	}

	/* The <item> tags... */
	if (attributeset_is_avail(var->Attributes, ATTR_ITEM)) {
#if GTK_CHECK_VERSION(2,16,0)
		gtk_scale_clear_marks(GTK_SCALE(var->Widget));
#endif
		widget_hscale_input_by_items(var);
	}

	/* Initialise these only once at start-up */
	if (!initialised) {
		/* Apply directives */
		if (attributeset_is_avail(var->Attributes, ATTR_LABEL))
			fprintf(stderr, "%s(): <label> not implemented for this widget.\n",
				__func__);
		if (attributeset_is_avail(var->Attributes, ATTR_DEFAULT)) {
			gtk_range_set_value(GTK_RANGE(var->Widget),
				atof(attributeset_get_first(&element, var->Attributes, ATTR_DEFAULT)));
		}
		if (attributeset_is_avail(var->Attributes, ATTR_HEIGHT))
			fprintf(stderr, "%s(): <height> not implemented for this widget.\n",
				__func__);
		if (attributeset_is_avail(var->Attributes, ATTR_WIDTH))
			fprintf(stderr, "%s(): <width> not implemented for this widget.\n",
				__func__);
		if ((attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "false")) ||
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "disabled")) ||	/* Deprecated */
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "no")) ||
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "0")))
			gtk_widget_set_sensitive(var->Widget, FALSE);

		/* Connect signals */
		g_signal_connect(G_OBJECT(var->Widget), "value-changed",
			G_CALLBACK(on_any_widget_value_changed_event), (gpointer)var->Attributes);

	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Removeselected                                                      *
 ***********************************************************************/

void widget_hscale_removeselected(variable *var)
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

void widget_hscale_save(variable *var)
{
	FILE             *outfile;
	GList            *element;
	gchar            *act;
	gchar            *filename = NULL;
	gdouble           value;
	guint             digits;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

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

			digits = gtk_scale_get_digits(GTK_SCALE(var->Widget));
			value = gtk_range_get_value(GTK_RANGE(var->Widget));
			switch (digits) {
				case 0:
					fprintf(outfile, "%.0f", value);
					break;
				case 1:
					fprintf(outfile, "%.1f", value);
					break;
				case 2:
					fprintf(outfile, "%.2f", value);
					break;
				case 3:
					fprintf(outfile, "%.3f", value);
					break;
				case 4:
					fprintf(outfile, "%.4f", value);
					break;
				case 5:
					fprintf(outfile, "%.5f", value);
					break;
				case 6:
					fprintf(outfile, "%.6f", value);
					break;
				case 7:
					fprintf(outfile, "%.7f", value);
					break;
				case 8:
					fprintf(outfile, "%.8f", value);
					break;
				case 9:
					fprintf(outfile, "%.9f", value);
					break;
				case 10:
					fprintf(outfile, "%.10f", value);
					break;
				case 11:
					fprintf(outfile, "%.11f", value);
					break;
				case 12:
					fprintf(outfile, "%.12f", value);
					break;
				case 13:
					fprintf(outfile, "%.13f", value);
					break;
				case 14:
					fprintf(outfile, "%.14f", value);
					break;
				case 15:
					fprintf(outfile, "%.15f", value);
					break;
				case 16:
					fprintf(outfile, "%.16f", value);
					break;
				/* Is there much point going beyond 16? */
				default:
					fprintf(outfile, "%f", value);
					break;
			}

			fclose(outfile);
		} else {
			fprintf(stderr, "%s(): Couldn't open '%s' for writing.\n",
				__func__, filename);
		}
	} else {
		fprintf(stderr, "%s(): No <output file> directive found.\n", __func__);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by Command                                                    *
 ***********************************************************************/

static void widget_hscale_input_by_command(variable *var, char *command)
{
	FILE             *infile;
	gchar             line[512];
	gint              count;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): command: '%s'\n", __func__, command);
#endif

	/* Opening pipe for reading... */
	if (infile = widget_opencommand(command)) {
		/* Just one line */
		if (fgets(line, 512, infile)) {
			/* Enforce end of string in case of max chars read */
			line[512 - 1] = 0;
			/* Remove the trailing [CR]LFs */
			for (count = strlen(line) - 1; count >= 0; count--)
				if (line[count] == 13 || line[count] == 10) line[count] = 0;

			gtk_range_set_value(GTK_RANGE(var->Widget), atof(line));

		}
		/* Close the file */
		pclose(infile);
	} else {
		fprintf(stderr, "%s(): Couldn't open '%s' for reading.\n", __func__,
			command);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by File                                                       *
 ***********************************************************************/

static void widget_hscale_input_by_file(variable *var, char *filename)
{
	FILE             *infile;
	gchar             line[512];
	gint              count;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (infile = fopen(filename, "r")) {
		/* Just one line */
		if (fgets(line, 512, infile)) {
			/* Enforce end of string in case of max chars read */
			line[512 - 1] = 0;
			/* Remove the trailing [CR]LFs */
			for (count = strlen(line) - 1; count >= 0; count--)
				if (line[count] == 13 || line[count] == 10) line[count] = 0;

			gtk_range_set_value(GTK_RANGE(var->Widget), atof(line));

		}
		/* Close the file */
		fclose(infile);
	} else {
		fprintf(stderr, "%s(): Couldn't open '%s' for reading.\n", __func__,
			filename);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by Items                                                      *
 ***********************************************************************/

static void widget_hscale_input_by_items(variable *var)
{
	GList            *element;
	gchar            *text;
	gdouble           value;
	gint              position, count;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#if GTK_CHECK_VERSION(2,16,0)

	g_assert(var->Attributes != NULL && var->Widget != NULL);

	text = attributeset_get_first(&element, var->Attributes, ATTR_ITEM);
	while (text) {
		/* sscanf is good for the first two values */
		if (sscanf(text, "%lf | %d", &value, &position) == 2) {
			/* Now we'll position on the markup or the terminating zero */
			count = 0;
			while (*text != 0 && count < 2) {
				if (*text == '|') count++;
				text++;
			}
#ifdef DEBUG_CONTENT
			printf("%s: value=%.16f position=%i markup='%s'\n",
				__func__, value, position, text);
#endif
			gtk_scale_add_mark(GTK_SCALE(var->Widget), value, position, text);
		}
		text = attributeset_get_next(&element, var->Attributes, ATTR_ITEM);
	}
#endif

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}
