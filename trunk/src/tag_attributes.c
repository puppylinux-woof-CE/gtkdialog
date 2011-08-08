/*
 * tag_attributes.c:
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

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <string.h>
#include "gtkdialog.h"
#include "tag_attributes.h"
#include "attributes.h"

typedef struct property {
	gchar *name;
	GType type;
} property;

extern gboolean option_no_warning;

static gboolean
try_set_property(GtkWidget *widget,
		namevalue  *nameval)
{
	GParamSpec       *paramspec;
	gint              n = 0;

	g_assert(nameval != NULL && GTK_IS_WIDGET(widget));

#ifdef DEBUG
	g_message("%s(): Start on '%s' = '%s'", __func__, 
			nameval->name, nameval->value);
#endif
	/*
	 * If the widget -- or its parents -- has not got this property
	 * we set this as data.
	 */
	paramspec = g_object_class_find_property(G_OBJECT_GET_CLASS(widget), 
			nameval->name);
	if (paramspec == NULL){
		g_object_set_data(G_OBJECT(widget), nameval->name, 
				g_strdup(nameval->value)); 
		return FALSE;
	}
	
	if (!paramspec->flags & G_PARAM_WRITABLE) {
		if (!option_no_warning)
			g_warning("%s(): Property '%s' is not writable.", 
				__func__, nameval->name);
		return FALSE;
	}
	
	switch (paramspec->value_type) {
		case G_TYPE_BOOLEAN:
			g_object_set(G_OBJECT(widget),
					nameval->name,
					!strcasecmp(nameval->value, "true"),
						NULL);
			break;

		case G_TYPE_INT:
			g_object_set(G_OBJECT(widget),
					nameval->name,
					atoi(nameval->value),
					NULL);
			break;
		case G_TYPE_FLOAT:
			g_object_set(G_OBJECT(widget),
					nameval->name,
					(gfloat)strtod(nameval->value, NULL),
					NULL);
			break;
		case G_TYPE_DOUBLE:
			g_object_set(G_OBJECT(widget),
					nameval->name,
					g_strtod(nameval->value, NULL),
					NULL);
			break;
		case G_TYPE_UINT:
			/* Thunor: Coding the spinbutton widget unearthed this rather
			 * nasty bug. nameval->value is supposed to be converted to
			 * a guint. I wonder how many things this has affected! Up until
			 * now I've found "border_width" to have always been about 50
			 * and now I understand why ;) I think that this entire function
			 * might benefit from a review so I'll mark it temp temp */
			g_object_set(G_OBJECT(widget),
				nameval->name,
				/* g_utf8_get_char(nameval->value),	Redundant: Bug */
				strtoul(nameval->value, NULL, 0),
				NULL);
			break;
		case G_TYPE_INVALID:
			if (!option_no_warning)
				g_warning("%s(): Unhandled G_TYPE_INVALID", __func__);
			break;
		case G_TYPE_NONE:
			if (!option_no_warning)
			g_warning("%s(): Unhandled G_TYPE_NONE", __func__);
			break;
		case G_TYPE_INTERFACE:
			if (!option_no_warning)
			g_warning("%s(): Unhandled G_TYPE_INTERFACE", __func__);
			break;
		case G_TYPE_CHAR:
			if (!option_no_warning)
			g_warning("%s(): Unhandled G_TYPE_CHAR", __func__);
			break;
		case G_TYPE_UCHAR:
			if (!option_no_warning)
			g_warning("%s(): Unhandled G_TYPE_UCHAR", __func__);
			break;
		case G_TYPE_LONG:
			if (!option_no_warning)
			g_warning("%s(): Unhandled G_TYPE_LONG", __func__);
			break;
		case G_TYPE_ULONG:
			if (!option_no_warning)
			g_warning("%s(): Unhandled G_TYPE_ULONG", __func__);
			break;
		case G_TYPE_INT64:
			if (!option_no_warning)
			g_warning("%s(): Unhandled G_TYPE_INT64", __func__);
			break;
		case G_TYPE_UINT64:
			if (!option_no_warning)
			g_warning("%s(): Unhandled G_TYPE_UINT64", __func__);
			break;
		case G_TYPE_ENUM:
			if (!option_no_warning)
			g_warning("%s(): Unhandled G_TYPE_ENUM", __func__);
			break;
		case G_TYPE_FLAGS:
			if (!option_no_warning)
			g_warning("%s(): Unhandled G_TYPE_FLAGS", __func__);
			break;
			
		case G_TYPE_STRING:
			g_object_set(G_OBJECT(widget),
				nameval->name, nameval->value,
				NULL);
			break;

		case G_TYPE_POINTER:
			if (!option_no_warning)
			g_warning("%s(): Unhandled G_TYPE_POINTER", __func__);
			break;
		case G_TYPE_BOXED:
			if (!option_no_warning)
			g_warning("%s(): Unhandled G_TYPE_BOXED", __func__);
			break;
		case G_TYPE_PARAM:
			if (!option_no_warning)
			g_warning("%s(): Unhandled G_TYPE_PARAM", __func__);
			break;
		case G_TYPE_OBJECT:
			if (!option_no_warning)
			g_warning("%s(): Unhandled G_TYPE_OBJECT", __func__);
			break;
		default:
			/*
			 * In case of an unknown property type...
			 */
			#ifdef DEBUG	
			g_warning("%s: Unknown attribute type for '%s': %d",
					__func__, nameval->name, 
					(paramspec->value_type));
			#endif
			g_object_set(G_OBJECT(widget),
					nameval->name,
					atoi(nameval->value),
					NULL);
			return FALSE;
	}
	
	return TRUE;
}

gint
widget_set_tag_attributes(
		GtkWidget *widget,
		tag_attr *attr)
{
	gboolean	success;
	gint 		q;
	gint 		retval = 0;

	g_assert(GTK_IS_WIDGET(widget));
#ifdef DEBUG
	g_message("%s(): Start on attr = %p.", __func__, attr);
#endif
	if (attr == NULL)
		return -1;
	
	for (q = 0; q < attr->n; ++q) {
		success = try_set_property(widget, attr->pairs + q);
		if (success)
			++retval;
	}
	
	return retval;
}

