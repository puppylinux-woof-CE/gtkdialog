#ifndef MYSTACK_H
#define MYSTACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#define MAXWIDGETS 256;


/* 
 * The elements in stack can contain MAXWIDGETS number of widgets.
 *
 */
typedef struct _stackelement {
	gchar       *cval;
	int          nwidgets;
	GtkWidget   *widgets[256];
	int          widgettypes[256];
} stackelement;

stackelement pop();
void push(stackelement a);
void show_without_pop(GtkWidget *window);

#endif

