/*
 * attributes.h: Handles the attributes of widgets.
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

#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "gtkdialog.h"
#include "memory.h"

/* How much attributes we store in an attribute set? */
#define ATTRNUMBER 32 

typedef struct _namevalue {
	char *name;
	char *value;
} namevalue;

typedef struct _tag_attr {
	int n;
	int nmax;
	namevalue *pairs;
} tag_attr;

typedef struct _Attribute {
	char *text;
	tag_attr *tag_attributes;
} Attribute;

typedef struct _AttributeSet {
	int n_attr;				/* How many attributes can be found here?  */
	GList **attr;			/* Attributes are linked lists.            */
} AttributeSet;

gchar *attribute_name(gint attribute);

AttributeSet *attributeset_new(void);
gboolean attributeset_is_avail(
	AttributeSet *set, int attribute);
gboolean attributeset_cmp_left(
	AttributeSet *set, int attribute, const char *str);
gchar *attributeset_set_if_unset(
	AttributeSet *set, gint attribute, const gchar *value);
const char *attributeset_insert(
	AttributeSet *set, int attribute, const char *value);
const char *attributeset_insert_with_tagattrs(
	AttributeSet *set, int attribute, const char *s, tag_attr *t_attr);

/* Thunor: I've re-engineered these functions to make them reentrant */
gchar *attributeset_get_first(
	GList **element, AttributeSet *set, gint type);
gchar *attributeset_get_next(
	GList **element, AttributeSet *set, gint type);
gchar *attributeset_get_this_tagattr(
	GList **element, AttributeSet *set, gint type, gchar *name);
void attributeset_set_this_tagattr(
	GList **element, AttributeSet *set, gint type, gchar *name, gchar *value);

#endif

