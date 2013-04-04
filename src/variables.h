/*
 * variables.h:
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

#ifndef VARIABLES_H
#define VARIABLES_H

#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "gtkdialog.h"
#include "attributes.h"
#include "automaton.h"

#define NAMELEN 512

typedef struct _variable {
  char                Name[ NAMELEN+1 ]; /* The name of the variable   */
  GtkWidget          *Widget;            /* The pointer to the widget  */
  int                 window_id;         /* The id of the owning window */
  int                 Type;              /* The type of the widget     */
  AttributeSet       *Attributes;        /* Attributes for Widget      */
  int                 row, column;       /* Selected items position.   */
  int                 ncolumns;          /* How many columns is in it. */
  struct _variable   *left;              /* The pointer used in to or- */
  struct _variable   *right;             /* ganise the Btree           */
  tag_attr           *widget_tag_attr;   /* Tag attributes of the widget. */
  int                 autonamed;         /* have a default name?       */
} variable;

/* Function prototypes */
variable *variables_new_with_widget(AttributeSet *Attr,
	tag_attr *widget_tag_attr, GtkWidget *widget, int type);
variable *variables_set_attributes(const char *name, AttributeSet *a);
variable *variables_set_row_column(const char *name, int row, int column);
variable *variables_set_value(const char *name, const char *value);
variable *variables_save(const char *name);
variable *variables_refresh(const char *name);
variable *variables_enable(const char *name);
variable *variables_disable(const char *name);
variable *variables_show(const char *name);
variable *variables_hide(const char *name);
variable *variables_activate(const char *name);
variable *variables_grabfocus(const char *name);
variable *variables_presentwindow(const char *name);
variable *variables_get_by_name(const char *name);
gint variables_count_widgets(void);
void variables_drop_by_window_id(variable *actual, gint window_id);
variable *find_variable_by_widget(GtkWidget *widget);
void variables_initialize_all(void);
void variables_export_all(void);
void print_variables(variable *actual);
/* int append_fromto_variable(const char *from, const char *to);	Redundant: Only used by action_append() which isn't being used anyway so purge it */
variable *variables_clear(const char *name);
int remove_selected_variable(const char *name);

#endif



