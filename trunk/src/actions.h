/*
 * actions.h:
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

#ifndef ACTIONS_H
#define ACTIONS_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#include "gtkdialog.h"
#include "stack.h"
#include "attributes.h"
#include "stringman.h"
#include "automaton.h"

extern char *program_name;
extern char *includefile;

/*
** Functions defined in actions.c
*/
int action_closewindow( GtkWidget *widget, char *string );
int action_launchwindow( GtkWidget *widget, char *string );
int action_exitprogram( GtkWidget *widget, char *string );
int action_refreshwidget( GtkWidget *widget, char *string );
int action_fileselect( GtkWidget *widget, char *string );
void action_fileselection_made( GtkWidget *w, actioncommand *ac );
void action_fileselection_destroy( GtkWidget *w, actioncommand *ac );
int action_clearwidget( GtkWidget *widget, char *string );
int action_removeselected( GtkWidget *widget, char *string );
int action_append( GtkWidget *widget, char *string );
int action_shellcommand( GtkWidget *widget, char *string );

#endif
