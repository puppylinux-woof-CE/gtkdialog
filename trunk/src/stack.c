/*
 * stack.c:
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

#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "gtkdialog.h"
#include "stack.h"

/* This value represents the maximum number of stackelements that the
 * stack can contain, but a stackelement can contain one widget or it
 * can contain a container full of widgets so the maximum number of
 * widgets that the project can accept is STACKSIZE * MAXWIDGETS */
#ifndef STACKSIZE
#define STACKSIZE 2048
#endif

stackelement stack[STACKSIZE];
int sp = 0;

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void push_widget(GtkWidget * widget, int widgettype)
{
#ifdef DEBUG
	g_message("%s(): Start.", __func__);
#endif
	stackelement s;
	s.nwidgets = 1;
	s.widgets[0] = widget;
	s.widgettypes[0] = widgettype;
	push(s);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void push(stackelement new)
{
#ifdef DEBUG
	static int spgreatest = 0;

	if (sp > spgreatest) {
		spgreatest = sp;
		g_message("%s: spgreatest=%d", __func__, spgreatest);
	}

	g_message("%s: Start sp = %d", __func__, sp);
#endif

	if (sp == STACKSIZE) {
		fprintf(stderr, "Stack overflow.\n");
		exit(EXIT_FAILURE);
	}
	stack[sp++] = new;

#ifdef DEBUG
	g_message("%s()): end sp = %d", __func__, sp);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

stackelement pop(void)
{
	if (sp == 0) 
		g_error("Stack underflow: Empty program or internal error.");
	
	sp--;

#ifdef DEBUG
	fprintf(stderr, "%s: stack pointer: %d\n", __func__, sp);
	fflush(stderr);
#endif

	return (stack[sp]);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* This show command is much more complex than I thought */

void show_without_pop(GtkWidget *window)
{
	GtkWidget *parent;
	stackelement *current;
	g_assert(window != NULL);
	g_assert(sp != 0);

	current = stack + (sp - 1);
	parent = gtk_widget_get_parent(current->widgets[0]);
	//gtk_widget_reparent(current->widgets[0], window);
	g_message("sp = %d nwidgets = %d", sp, current->nwidgets);
	gtk_container_add(GTK_CONTAINER(window), current->widgets[0]);
	gtk_widget_show_all(window);
	//gtk_main();
}
