/*
 * tag_attributes.c:
 * Gtkdialog - A small utility for fast and easy GUI building.
 * Copyright (C) 2003-2007  László Pere <pipas@linux.pte.hu>
 * Copyright (C) 2012       Thunor <thunorsif@hotmail.com>
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
#include "attributes.h"
#include "tag_attributes.h"

typedef struct property {
	gchar *name;
	GType type;
} property;

extern gboolean option_no_warning;

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

static gboolean try_set_property(GtkWidget *widget, namevalue  *nameval)
{
	GParamSpec       *paramspec;
	gint              n = 0;

	g_assert(nameval != NULL && GTK_IS_WIDGET(widget));

#ifdef DEBUG
	g_message("%s(): Start on '%s' = '%s'", __func__, 
			nameval->name, nameval->value);
#endif

	/* Thunor: The visible property should not be modified here */
	if (strcmp(nameval->name, "visible") == 0) {
#ifdef DEBUG
		fprintf(stderr, "%s(): not applying visible property\n", __func__);
#endif
		return FALSE;
	}

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
			 * might benefit from a review so I'll mark it temp temp
			 * 
			 * [UPDATE] 2012-09-10
			 * No further problems have been discovered */
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
			/* Thunor: I don't know why unknown Gtk properties are copied
			 * as widget data because they still exist as tag attributes */
			g_object_set(G_OBJECT(widget),
					nameval->name,
					atoi(nameval->value),
					NULL);
			return FALSE;
	}
	
	return TRUE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gint widget_set_tag_attributes(GtkWidget *widget, tag_attr *attr)
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
		/* Thunor: killed tag attributes have null names */
		if (attr->pairs[q].name[0] != 0) {
			success = try_set_property(widget, attr->pairs + q);
			if (success) ++retval;
		}
	}
	
	return retval;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

char *get_tag_attribute(tag_attr *attr, const char *name)
{
	int q;
	
	g_assert(attr != NULL && name != NULL);
#ifdef DEBUG
	g_message("%s(): searching for name = '%s' in %p", 
			__func__, name, attr);
#endif
	for (q = 0; q < attr->n; ++q) 
		if (strcmp(attr->pairs[q].name, name) == 0)
			return attr->pairs[q].value;

	return NULL;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

tag_attr *add_tag_attribute(tag_attr *attr, char *name, char *value)
{
	g_assert(attr != NULL);
	g_assert(name != NULL && value != NULL);
#ifdef DEBUG	
	g_message("%s(): name = '%s' value = '%s'", __func__, name, value);
#endif 
		
	if (name[strlen(name) - 1] == '=')
		name[strlen(name) - 1] = '\0';
	//
	// If the store is full, we enlarge its size.
	//
	if (attr->n == attr->nmax){
		attr->nmax += 32;
		attr->pairs = g_realloc(attr->pairs,
				attr->nmax * sizeof(namevalue));
	}
	/*
	 * What if this tagattr is already exists?
	 */
	attr->pairs[attr->n].name = g_strdup(name);
	attr->pairs[attr->n].value = g_strdup(value);
	++attr->n;
	return attr;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/*
 * Simple functions to handle attributesets, name/value pair list.
 */

tag_attr *new_tag_attributeset(char *name, char *value)
{
	tag_attr *New;

	g_assert(name != NULL);
	g_assert(value != NULL);
	
#ifdef DEBUG
	g_message("%s(): Name: '%s' Value: '%s'.", __func__, name, value);
#endif
	if (name[strlen(name) - 1] == '=')
		name[strlen(name) - 1] = '\0';
	
	New = g_malloc(sizeof(tag_attr));
	
	New->pairs = g_malloc(sizeof(namevalue) * 32);
	New->nmax = 32;
	New->n = 1;
	
	New->pairs[0].name = g_strdup(name);
	New->pairs[0].value = g_strdup(value);
	return New;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* Thunor: The tag attribute utility functions are quite simple and
 * sparse and I require a way to nullify/erase/kill a tag attribute
 * that I don't want gtk applying on widget realization */

void kill_tag_attribute(tag_attr *attr, const char *name)
{
	int q;
	
	g_assert(attr != NULL && name != NULL);
#ifdef DEBUG
	g_message("%s(): searching for name = '%s' in %p", 
			__func__, name, attr);
#endif
	for (q = 0; q < attr->n; ++q) {
		if (strcmp(attr->pairs[q].name, name) == 0) {
			attr->pairs[q].name[0] = 0;
		}
	}

}

