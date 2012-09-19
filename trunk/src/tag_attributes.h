/*
 * tag_attributes.h:
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

#ifndef TAG_ATTRIBUTES_H
#define TAG_ATTRIBUTES_H

#include <gtk/gtk.h>
#include "attributes.h"
#include "gtkdialog.h"

typedef struct tag_attribute {
	gchar    *name;
	gchar    *sval;
	gint      ival;
	gdouble   dval;
	gfloat    fval;
	gboolean  bval;
} tag_attribute;


GList *tag_attributeset_append(GList *list, gchar *name, gchar *value);
gint widget_set_tag_attributes(GtkWidget *widget, tag_attr *attr);
char *get_tag_attribute(tag_attr *attr, const char *name);
tag_attr *add_tag_attribute(tag_attr *attr, char *name, char *value);
tag_attr *new_tag_attributeset(char *name, char *value);
void kill_tag_attribute(tag_attr *attr, const char *name);

#endif
