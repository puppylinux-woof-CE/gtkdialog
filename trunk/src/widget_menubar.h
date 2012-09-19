/*
 * widget_menubar.h: 
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

#ifndef WIDGET_MENUBAR_H
#define WIDGET_MENUBAR_H

/* Function prototypes */
void widget_menubar_clear(variable *var);
GtkWidget *widget_menubar_create(
	AttributeSet *Attr, tag_attr *attr, gint Type);
gchar *widget_menubar_envvar_all_construct(variable *var);
gchar *widget_menubar_envvar_construct(GtkWidget *widget);
void widget_menubar_fileselect(
	variable *var, const char *name, const char *value);
void widget_menubar_refresh(variable *var);
void widget_menubar_removeselected(variable *var);
void widget_menubar_save(variable *var);

#endif
