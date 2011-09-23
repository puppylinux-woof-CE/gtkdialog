/*
 * stack.h:
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

#ifndef MYSTACK_H
#define MYSTACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "gtkdialog.h"

#define MAXWIDGETS (529)	//256

/* Using examples/expand_and_fill:
 * 
 * 256  (16^) = 21940 virtual memory
 * 484  (22^) = 25588 virtual memory
 * 529  (23^) = 26308 virtual memory
 * 625  (25^) = 27844 virtual memory
 * 729  (27^) = 29512 virtual memory
 * 1024 (32^) = 34248 virtual memory
 */

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

