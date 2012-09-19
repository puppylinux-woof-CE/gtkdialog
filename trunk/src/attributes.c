/*
 * attributes.c: Handles the attributes of widgets.
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

#include <gtk/gtk.h>
#include "gtkdialog.h"
#include "attributes.h"
#include "stringman.h"
#include "automaton.h"
#include "tag_attributes.h"

/* Defines */
//#define DEBUG_CONTENT
//#define DEBUG_TRANSITS

gchar *
attribute_name(gint attribute) 
{
	switch (attribute)  {
		case ATTR_LABEL:
			return "label";
		case ATTR_DEFAULT:
			return "default";
		case ATTR_VARIABLE:
			return "variable";
		case ATTR_HEIGHT:
			return "height";
		case ATTR_WIDTH:
			return "width";
		case ATTR_INPUT:
			return "input";
		case ATTR_SENSITIVE:
			return "sensitive";
		case ATTR_ACTION:
			return "action";
		case ATTR_ITEM:
			return "item";
		case ATTR_OUTPUT:
			return "output";
		case ATTR_SOCKET:
			return "socket";
		default:
			return "(unknown attribute)";
	}
}

AttributeSet *attributeset_new(void)
{
	AttributeSet *new_set;
	int n;

#ifdef DEBUG
	g_message("%s(): Start.", __func__);
#endif

	new_set = g_malloc(sizeof(AttributeSet));
	new_set->n_attr = ATTRNUMBER;
	new_set->attr = g_malloc(sizeof(GList *) * ATTRNUMBER);

	/*
	 * All the attributes are NULL pointers, thus they represent empty
	 * lists.
	 */
	for (n = 0; n < ATTRNUMBER; ++n) {
		new_set->attr[n] = NULL;
	}

	return new_set;
}

gboolean attributeset_is_avail(AttributeSet *set, int attribute)
{
#ifdef DEBUG
	g_message("%s(): Start attribute = %d (%s)", __func__, attribute,
			attribute_name(attribute));
#endif

	g_assert(set != NULL);
	g_assert(attribute >= 0 && attribute < ATTRNUMBER);

	if (set->attr[attribute] == NULL) {
#ifdef DEBUG
		g_message("%s(): Attribute %d is unset.", __func__, attribute);
#endif
		return FALSE;
	} else {
#ifdef DEBUG
		g_message("%s(): Attribute %d has been set.", __func__, attribute);
#endif
		return TRUE;
	}
}

gboolean attributeset_cmp_left(
	AttributeSet *set, int attribute, const char *str)
{
	Attribute *a;
	g_assert(set != NULL && str != NULL);
	g_assert(attribute >= 0 && attribute < ATTRNUMBER);

#ifdef DEBUG
	g_message("%s(): Start attribute = %d, str = '%s'", __func__, attribute, str);
#endif

	if (!attributeset_is_avail(set, attribute))
		return FALSE;

	a = set->attr[attribute]->data;

	if (a->text == NULL)
		return FALSE;

	if (strncasecmp(a->text, str, strlen(str)) == 0)
		return TRUE;
	else
		return FALSE;
}

gchar *attributeset_set_if_unset(
	AttributeSet *set, gint attribute, const gchar *value)
{
	GList *element;
	Attribute *a;

	g_assert(set != NULL);
	g_assert(attribute >= 0 && attribute < ATTRNUMBER);

#ifdef DEBUG	
	g_message("%s(): attribute = %d (%s) value = '%s'", 
			__func__, attribute, attribute_name(attribute), value);
#endif
	
	if (attributeset_is_avail(set, attribute))
		return attributeset_get_first(&element, set, attribute);
	else
		return (gchar *)attributeset_insert(set, attribute, value);
}

const gchar *attributeset_insert_with_tagattrs(
	AttributeSet *set, gint attribute, const gchar *value, tag_attr *tag_attributes)
{
	Attribute *a;
	g_assert(set != NULL);
	g_assert(attribute >= 0 && attribute < ATTRNUMBER);

#ifdef DEBUG
	g_message("%s(): Start: attribute = %d value = '%s' tag_attributes = %p", 
			__func__, attribute, value, tag_attributes);
#endif

	a = g_malloc(sizeof(Attribute));
	a->text = g_strdup(value);
	a->tag_attributes = tag_attributes;

	/*
	 * Adding a new attribute value to the linked list of this attribute.
	 */
	set->attr[attribute] = g_list_append(set->attr[attribute], a);

	return value;
}

const char *attributeset_insert(
	AttributeSet *set, gint attribute, const char *value)
{
	tag_attr *text = new_tag_attributeset("text", (gchar *)value);

#ifdef DEBUG
	g_message("%s(): Start: attribute = %d, value = '%s'", 
			__func__, attribute, value);
#endif

	return attributeset_insert_with_tagattrs(set, attribute, value, text);
}

/***********************************************************************
 * AttributeSet Get First                                              *
 ***********************************************************************/
/* Thunor: I've re-engineered this function to make it reentrant */

gchar *attributeset_get_first(GList **element, AttributeSet *set, gint type)
{
	Attribute        *attribute = NULL;
	gchar            *text = NULL;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): *element=%p set=%p type=%i\n",
		__func__, *element, set, type);
#endif

	if (set == NULL) {
		fprintf(stderr, "%s(): set is NULL.\n", __func__);
	} else if (type < 0 || type >= ATTRNUMBER) {
		fprintf(stderr, "%s(): type %i is invalid.\n", __func__, type);
	} else if ((*element = set->attr[type]) != NULL) {
		attribute = (*element)->data;
		text = attribute->text;
	}

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): *element=%p set=%p type=%i text=%s\n",
		__func__, *element, set, type, text);
#endif

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return text;
}

/***********************************************************************
 * AttributeSet Get Next                                               *
 ***********************************************************************/
/* Thunor: I've re-engineered this function to make it reentrant */

gchar *attributeset_get_next(GList **element, AttributeSet *set, gint type)
{
	Attribute        *attribute = NULL;
	gchar            *text = NULL;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): *element=%p set=%p type=%i\n",
		__func__, *element, set, type);
#endif

	if (*element == NULL) {
		fprintf(stderr, "%s(): element is NULL.\n", __func__);
	} else if (set == NULL) {
		fprintf(stderr, "%s(): set is NULL.\n", __func__);
	} else if (type < 0 || type >= ATTRNUMBER) {
		fprintf(stderr, "%s(): type %i is invalid.\n", __func__, type);
	} else if ((*element = g_list_next(*element)) != NULL) {
		attribute = (*element)->data;
		text = attribute->text;
	}

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): *element=%p set=%p type=%i text=%s\n",
		__func__, *element, set, type, text);
#endif

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return text;
}

/***********************************************************************
 * AttributeSet Get This Tag Attribute                                 *
 ***********************************************************************/
/* Thunor: I've re-engineered this function to make it reentrant */

gchar *attributeset_get_this_tagattr(GList **element, AttributeSet *set,
	gint type, gchar *name)
{
	Attribute        *attribute = NULL;
	gchar            *value = NULL;	
	
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): *element=%p set=%p type=%i name=%s\n",
		__func__, *element, set, type, name);
#endif

	if (*element == NULL) {
		fprintf(stderr, "%s(): element is NULL.\n", __func__);
	} else if (set == NULL) {
		fprintf(stderr, "%s(): set is NULL.\n", __func__);
	} else if (type < 0 || type >= ATTRNUMBER) {
		fprintf(stderr, "%s(): type %i is invalid.\n", __func__, type);
	} else {
		attribute = (*element)->data;
		value = get_tag_attribute(attribute->tag_attributes, name);
	}

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): *element=%p set=%p type=%i name=%s value=%s\n",
		__func__, *element, set, type, name, value);
#endif

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return value;
}

/***********************************************************************
 * AttributeSet Set This Tag Attribute                                 *
 ***********************************************************************/
/* Thunor: I've re-engineered this function to make it reentrant */

void attributeset_set_this_tagattr(
	GList **element, AttributeSet *set, gint type, gchar *name, gchar *value)
{
	Attribute        *attribute = NULL;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): *element=%p set=%p type=%i name=%s value=%s\n",
		__func__, *element, set, type, name, value);
#endif

	if (*element == NULL) {
		fprintf(stderr, "%s(): element is NULL.\n", __func__);
	} else if (set == NULL) {
		fprintf(stderr, "%s(): set is NULL.\n", __func__);
	} else if (type < 0 || type >= ATTRNUMBER) {
		fprintf(stderr, "%s(): type %i is invalid.\n", __func__, type);
	} else {
		attribute = (*element)->data;
		add_tag_attribute(attribute->tag_attributes, name, value);
	}

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): *element=%p set=%p type=%i name=%s value=%s\n",
		__func__, *element, set, type, name, value);
#endif

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

