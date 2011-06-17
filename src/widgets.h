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
#include "stack.h"
#include "attributes.h"
#include "stringman.h"
#include "variables.h"
#include "automaton.h"

typedef enum {
	ColumnPixbuf,
	ColumnIconName,
	ColumnStockId,
	FirstDataColumn
} treecolumns;

char *widget_get_text_value( GtkWidget *widget, int type );
int widget_label_refresh( variable *var );
int widget_edit_refresh( variable *var );
void widget_entry_refresh( variable *var );
void widget_list_refresh( variable *var );
void widget_tree_refresh( variable *var );
void widget_table_refresh( variable *var );
void widget_combo_refresh( variable *var );
void widget_pixmap_refresh(variable *var);
void widget_button_refresh(variable *var);
FILE *widget_opencommand( const char *command );

void fill_text_by_file( GtkTextBuffer *buffer, char *filename );
void fill_label_by_command(GtkWidget *label, char *command);

void fill_clist_by_command( GtkWidget *list,int columns,char *command );
void fill_list_by_command( GtkWidget *list, char *command );
void fill_entry_by_command( GtkWidget *entry, char *command);
void fill_table_by_command( GtkWidget *list, char *command );
void fill_checkbox_by_command(GtkWidget *checkbox, char *command);
char *widgets_to_str( int itype );

void register_progress_bar_callbacks(
		GtkWidget    *bar, 
		const gchar  *input,
		AttributeSet *Attr);

void
on_any_progress_bar_realized(GtkWidget *widget, 
		AttributeSet *Attr);

gint widget_get_type_from_pointer(GtkWidget *widget);
#endif
