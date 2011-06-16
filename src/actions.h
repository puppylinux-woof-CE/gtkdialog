/* 
** actions.h: 
** copyright: (c) 2003 by László Pere
** email: pipas@linux.pte.hu
** This program is free software; you can redistribute it and/or 
** modify  it under the terms of the GNU General Public License as
** published by the Free Software Foundation; either version 2 of
** the License, or (at your option) any later version.
*/
#ifndef ACTIONS_H
#define ACTIONS_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#include "stack.h"
#include "attributes.h"
#include "stringman.h"
#include "automaton.h"
#include "main.h"

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
