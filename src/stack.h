/*
 * stack.h:
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

#ifndef MYSTACK_H
#define MYSTACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "gtkdialog.h"

/* This value represents the maximum number of widgets that one individual
 * stackelement can contain, so it can be viewed as widgets per container */
#define MAXWIDGETS 256

/* 
 * The elements in stack can contain MAXWIDGETS number of widgets.
 *
 */
typedef struct _stackelement {
	gchar       *cval;
	int          nwidgets;
	GtkWidget   *widgets[MAXWIDGETS];
	int          widgettypes[MAXWIDGETS];
} stackelement;

stackelement pop();
void push(stackelement a);
void show_without_pop(GtkWidget *window);

#endif

