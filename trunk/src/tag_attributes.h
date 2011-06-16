/*
 * Copyright (C) 2004 Laszlo Pere
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

