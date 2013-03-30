/*
 * widget_hbox.c: 
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
static void widget_hbox_input_by_command(variable *var, char *command);
static void widget_hbox_input_by_file(variable *var, char *filename);
static void widget_hbox_input_by_items(variable *var);

/* Notes: */

/***********************************************************************
 * Clear                                                               *
 ***********************************************************************/

void widget_hbox_clear(variable *var)
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
GtkWidget *widget_hbox_create(
	AttributeSet *Attr, tag_attr *attr, gint Type)
{
	gchar            *value;
	gint              border_width;
	gint              n;
	gint              original_expand, original_fill;
	gint              space_expand, space_fill;
	GtkWidget        *widget;
	stackelement      s;
	variable         *var;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* The spacing value here is the GtkBox "spacing" property
	 * and therefore can be overridden with a spacing="0" tag
	 * attribute*/
#if !GTK_CHECK_VERSION(3,0,0)	/* gtk3: Deprecated in gtk3 so I've added the newly recommended equivalent */
	widget = gtk_hbox_new(FALSE, 5);
#else
	widget = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	gtk_box_set_homogeneous(GTK_BOX(widget), FALSE);
#endif

	if (attr &&
		(value = get_tag_attribute(attr, "margin"))) {	/* Deprecated */
		border_width = atoi(value);
		gtk_container_set_border_width(GTK_CONTAINER(widget), border_width);
	}

	/* Calculate values for expand and fill at the container level */
	space_expand = project_space_expand;
	if (attr &&
		((value = get_tag_attribute(attr, "space-expand")))) {
		if ((strcasecmp(value, "true") == 0) ||
			(strcasecmp(value, "yes") == 0) || (atoi(value) == 1)) {
			space_expand = TRUE;
		} else {
			space_expand = FALSE;
		}
	}
	space_fill = project_space_fill;
	if (attr &&
		((value = get_tag_attribute(attr, "space-fill")))) {
		if ((strcasecmp(value, "true") == 0) ||
			(strcasecmp(value, "yes") == 0) || (atoi(value) == 1)) {
			space_fill = TRUE;
		} else {
			space_fill = FALSE;
		}
	}

	/* Pack the widgets into the container */
	s = pop();
	for (n = s.nwidgets - 1; n >= 0; --n) {

		/* Calculate values for expand and fill at the widget level */
		var = find_variable_by_widget(s.widgets[n]);
		if (var && var->widget_tag_attr &&
			((value = get_tag_attribute(var->widget_tag_attr, "space-expand")))) {
			if ((strcasecmp(value, "true") == 0) ||
				(strcasecmp(value, "yes") == 0) || (atoi(value) == 1)) {
				space_expand = TRUE;
			} else {
				space_expand = FALSE;
			}
		}
		if (var && var->widget_tag_attr &&
			((value = get_tag_attribute(var->widget_tag_attr, "space-fill")))) {
			if ((strcasecmp(value, "true") == 0) ||
				(strcasecmp(value, "yes") == 0) || (atoi(value) == 1)) {
				space_fill = TRUE;
			} else {
				space_fill = FALSE;
			}
		}

		/* Thunor: The entry widget here is being packed with expand
		 * and fill set to true but not in the vbox or frame, so I'll
		 * mark this temp temp as it could be a bug */
		if (s.widgettypes[n] == WIDGET_EDIT ||
			s.widgettypes[n] == WIDGET_FRAME ||
			s.widgettypes[n] == WIDGET_SCROLLEDW ||
			s.widgettypes[n] == WIDGET_ENTRY) {
			original_expand = original_fill = TRUE;
		} else {
			original_expand = original_fill = FALSE;
		}
		if (space_expand != -1) original_expand = space_expand;
		if (space_fill != -1) original_fill = space_fill;
#ifdef DEBUG_CONTENT
		fprintf(stderr, "%s(): hbox expand=%i fill=%i\n", __func__,
			original_expand, original_fill);
#endif
		gtk_box_pack_end(GTK_BOX(widget), s.widgets[n],
			original_expand, original_fill, 0);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return widget;
}

/***********************************************************************
 * Environment Variable All Construct                                  *
 ***********************************************************************/

gchar *widget_hbox_envvar_all_construct(variable *var)
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

gchar *widget_hbox_envvar_construct(GtkWidget *widget)
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

void widget_hbox_fileselect(
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
void widget_hbox_refresh(variable *var)
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
			widget_hbox_input_by_command(var, act + 8);
		/* input file stock = "File:", input file = "File:/path/to/file" */
		if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5)
			widget_hbox_input_by_file(var, act + 5);
		act = attributeset_get_next(&element, var->Attributes, ATTR_INPUT);
	}

	/* The <item> tags... */
	if (attributeset_is_avail(var->Attributes, ATTR_ITEM))
		widget_hbox_input_by_items(var);

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

	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Removeselected                                                      *
 ***********************************************************************/

void widget_hbox_removeselected(variable *var)
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

void widget_hbox_save(variable *var)
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

static void widget_hbox_input_by_command(variable *var, char *command)
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

static void widget_hbox_input_by_file(variable *var, char *filename)
{
	gchar            *var1;
	gint              var2;

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

static void widget_hbox_input_by_items(variable *var)
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
