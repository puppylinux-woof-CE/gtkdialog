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
static void fill_clist_by_items(AttributeSet *Attr, GtkWidget *list, int separator);
static void fill_combo_by_items(AttributeSet *Attr, GtkWidget *combo);
static void fill_comboboxtext_by_items(AttributeSet *Attr, GtkWidget *comboboxtext);
static void fill_list_by_items(AttributeSet *Attr, GtkWidget *list);
void fill_tree_model_by_items(GtkTreeModel *tree_model, variable *var);

char *widget_get_text_value(GtkWidget *widget, int type);

static void fill_comboboxtext_by_file(GtkWidget *widget, char *filename);
static void fill_edit_by_file(GtkWidget *widget, char *filename);
static void fill_label_by_file(GtkWidget *widget, char *filename);
void fill_text_by_file(GtkTextBuffer *buffer, char *filename );	/* Redundant: never implemented */

void widget_button_refresh(variable *var);
void widget_checkbox_refresh(variable *var);
void widget_combo_refresh(variable *var);
void widget_comboboxtext_refresh(variable *var);
int widget_edit_refresh(variable *var);
void widget_entry_refresh(variable *var);
int widget_label_refresh(variable *var);
void widget_list_refresh(variable *var);
void widget_pixmap_refresh(variable *var);
void widget_table_refresh(variable *var);
void widget_tree_refresh(variable *var);

void save_comboboxtext_to_file(variable *var);
void widget_edit_save(variable *var);
static void save_edit_to_file(GtkWidget *widget, char *filename);

FILE *widget_opencommand(const char *command);

void fill_checkbox_by_command(GtkWidget *checkbox, char *command);
void fill_clist_by_command(GtkWidget *list, int columns, char *command);
void fill_comboboxtext_by_command(GtkWidget *widget, char *command);
void fill_entry_by_command(GtkWidget *entry, char *command);
void fill_label_by_command(GtkWidget *label, char *command);
void fill_list_by_command(GtkWidget *list, char *command);
void fill_table_by_command(GtkWidget *list, char *command);
static void fill_tree_view_by_command(GtkWidget *tree_view,
	GtkTreeModel *tree_model, const gchar *command, gint stock_column,
	gint icon_column);

char *widgets_to_str(int itype);

gint widget_get_type_from_pointer(GtkWidget *widget);

void perform_progress_bar_actions(progr_descr *descr);
gpointer progress_bar_thread_entry(progr_descr *descr);
void descriptor_destroy_notify(progr_descr *descr);
void on_any_progress_bar_realized(GtkWidget *widget, AttributeSet *Attr);

void register_progress_bar_callbacks(	/* Redundant: not found */
		GtkWidget    *bar, 
		const gchar  *input,
		AttributeSet *Attr);

#endif
