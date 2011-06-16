/*
 * Copyright (C) 2004, 2005, 2006, 2007 Laszlo Pere
 * $Id:$
 *
 * This is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Library General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * $Log:$
 */
#include <gtk/gtk.h>
#include "gtkdialog.h"
#include "attributes.h"
#include "stringman.h"
#include "automaton.h"

extern gboolean *option_no_warning;

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
		case ATTR_VISIBLE:
			return "visible";
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


AttributeSet *
attributeset_new(void)
{
	AttributeSet *new_set;
	int n;

#ifdef DEBUG
	g_message("%s(): Start.", __func__);
#endif
	new_set = g_malloc(sizeof(AttributeSet));
	new_set->n_attr = ATTRNUMBER;
	new_set->attr = g_malloc(sizeof(GList *) * ATTRNUMBER);
	new_set->_pointer = g_malloc(sizeof(GList *) * ATTRNUMBER);
	/*
	 * All the attributes are NULL pointers, thus they represent empty
	 * lists.
	 */
	for (n = 0; n < ATTRNUMBER; ++n) {
		new_set->attr[n] = NULL;
		new_set->_pointer[n] = NULL;
	}

	return new_set;
}

gboolean 
attributeset_is_avail(
		AttributeSet * set, 
		int attribute)
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

gboolean 
attributeset_cmp_left(
		AttributeSet *set, 
		int           attribute,
	        const char   *str)
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

gchar *
attributeset_get_first(
		AttributeSet * set, 
		int attribute)
{
	Attribute *a;
#ifdef DEBUG
	g_message("%s(): Start attribute = %d.", __func__, attribute);
#endif
	g_assert(set != NULL);
	g_assert(attribute >= 0 && attribute < ATTRNUMBER);
	/*
	 * Resetting the actual attribute pointer to the first list item.
	 */
	set->_pointer[attribute] = set->attr[attribute];
	/*
	 * If this attribute is not available we return NULL.
	 */
	if (set->_pointer[attribute] == NULL)
		return NULL;
	/*
	 * If available, we return the value.
	 */
	a = set->_pointer[attribute]->data;
	return a->text;
}

void
attributeset_set_this_tagattr(
		AttributeSet *set,
		gint attribute,
		gchar *name,
		gchar *value)
{
	Attribute *attr_pointer;
	
	g_assert(set != NULL && name != NULL);
	g_assert(attribute >= 0 && attribute < ATTRNUMBER);
#ifdef DEBUG
	g_message("%s(): Setting for '%s' = '%s' attribute = %d, n_attr = %d", 
			__func__, name, value, attribute, set->n_attr);
#endif
	
	/*
	 * If this is a nonexistent attribute token, we return.
	 */
	if (set->_pointer[attribute] == NULL) {
		if (!option_no_warning)
			g_warning("%s(): Attribute %d has not been set yet.", 
					__func__, attribute);
		return;
	}
	attr_pointer = set->_pointer[attribute]->data;
	add_tag_attribute(attr_pointer->tag_attributes, name, value);
}

char *
attributeset_get_this_tagattr(
		AttributeSet *set,
		int attribute,
		const char *name)
{
	Attribute *attr_pointer;
	gchar *value;	
	
	g_assert(set != NULL && name != NULL);
	g_assert(attribute >= 0 && attribute < ATTRNUMBER);

#ifdef DEBUG
	g_message("%s(): Searching for '%s' attribute = %d, n_attr = %d", 
			__func__, name, attribute, set->n_attr);
#endif
	/*
	 * If this is a nonexistent attribute token, we return NULL.
	 */
	if (set->attr[attribute] == NULL)	
		return NULL;
	attr_pointer = set->_pointer[attribute]->data;
	
	value = get_tag_attribute(attr_pointer->tag_attributes, name);
#ifdef DEBUG
	g_message("%s(): end name = '%s', value = '%s'", __func__, name, value);
#endif
	return value;	
}

char *
attributeset_get_next(
		AttributeSet * set, 
		int attribute)
{
	Attribute *a;
	
	g_assert(set != NULL);
	g_assert(attribute >= 0 && attribute < ATTRNUMBER);

#ifdef DEBUG
	g_message("%s(): Start.", __func__);
#endif
	
	if (attribute >= set->n_attr || g_list_next(set->_pointer[attribute]) == NULL)
		return NULL;
	
	set->_pointer[attribute] = g_list_next(set->_pointer[attribute]);
	
	a = set->_pointer[attribute]->data;
	if (a != NULL)
		return a->text;
	else
		return NULL;
}


gchar *
attributeset_set_if_unset(
		AttributeSet *set, 
		gint          attribute,
		const gchar  *value)
{
	Attribute *a;

	g_assert(set != NULL);
	g_assert(attribute >= 0 && attribute < ATTRNUMBER);

#ifdef DEBUG	
	g_message("%s(): attribute = %d (%s) value = '%s'", 
			__func__, attribute, attribute_name(attribute), value);
#endif
	
	if (attributeset_is_avail(set, attribute))
		return attributeset_get_first(set, attribute);
	else
		return (gchar *)attributeset_insert(set, attribute, value);
}

const gchar *
attributeset_insert_with_tagattrs(
		AttributeSet *set, 
		gint          attribute, 
		const gchar  *value, 
		tag_attr     *tag_attributes) 
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

const char *
attributeset_insert(
		AttributeSet   *set, 
		gint 		attribute, 
		const char     *value)
{
	tag_attr *text = new_tag_attributeset("text", (gchar *)value);
#ifdef DEBUG
	g_message("%s(): Start: attribute = %d, value = '%s'", 
			__func__, attribute, value);
#endif
	return attributeset_insert_with_tagattrs(set, attribute, value, text);
}

inline gboolean 
is_input_with_this_tagattr(
		AttributeSet *Attr, 
		const char *name)
{
	if (attributeset_get_first(Attr, ATTR_INPUT) == NULL)
		return FALSE;
	do {
		if (attributeset_get_this_tagattr(Attr, ATTR_INPUT, name) != NULL)
			return TRUE;
	} while (attributeset_get_next(Attr, ATTR_INPUT));

	return FALSE;
}

inline gboolean 
is_item_with_this_tagattr(AttributeSet *Attr, 
		const char *name)
{
	if (attributeset_get_first(Attr, ATTR_ITEM) == NULL)
		return FALSE;
	do {
		if (attributeset_get_this_tagattr(Attr, ATTR_ITEM, name) != NULL)
			return TRUE;
	} while (attributeset_get_next(Attr, ATTR_ITEM));

	return FALSE;
}

