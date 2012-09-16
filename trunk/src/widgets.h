/*
 * widgets.h: Widget manipulation functions
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

#ifndef WIDGETS_H
#define WIDGETS_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <gtk/gtk.h>
#include "gtkdialog.h"
#include "stack.h"
#include "attributes.h"
#include "stringman.h"
#include "variables.h"
#include "automaton.h"

struct _progr_descr {
	GtkWidget    *widget;
	gdouble       fraction;
	const gchar  *shell_command;
	FILE         *pipe;
	GThread      *thread;
	AttributeSet *Attr;
};
typedef struct _progr_descr progr_descr;

/* Thunor: I've pulled out all the prototypes static or not and grouped
 * and reordered them alphabetically to show what's been implemented.
 * In my opinion there should be one source and header file for each widget
 * with all of the functions in a consistent order as finding stuff is
 * incredibly time consuming. Another job for another [rainy] day :) */
static void fill_scale_by_items(AttributeSet *Attr, GtkWidget *scale);

char *widget_get_text_value(GtkWidget *widget, int type);

static void fill_scale_by_file(GtkWidget *widget, char *filename);
static void fill_menuitem_by_file(GtkWidget *widget, char *filename);

void widget_scale_refresh(variable *var);
void widget_menuitem_refresh(variable *var);

void save_scale_to_file(variable *var);
void save_menuitem_to_file(variable *var);

FILE *widget_opencommand(const char *command);

void fill_scale_by_command(GtkWidget *widget, char *command);
void fill_menuitem_by_command(GtkWidget *widget, char *command);

char *widgets_to_str(int itype);

void perform_progress_bar_actions(progr_descr *descr);
gpointer progress_bar_thread_entry(progr_descr *descr);
void descriptor_destroy_notify(progr_descr *descr);
void on_any_progress_bar_realized(GtkWidget *widget, AttributeSet *Attr);

#endif
