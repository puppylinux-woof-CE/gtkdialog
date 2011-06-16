#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "stack.h"
#include "gtkdialog.h"

#ifndef STACKSIZE
#define STACKSIZE 2048 
#endif

stackelement stack[STACKSIZE];
int sp = 0;

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


void 
push(stackelement new)
{
#ifdef DEBUG
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

stackelement 
pop(void)
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

/*
 * This show command is much more complex than I thought.
 */
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

