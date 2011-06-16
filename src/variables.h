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
  int                 Type;              /* The type of the widget     */
  AttributeSet       *Attributes;        /* Attributes for Widget      */
  int                 row, column;       /* Selected items position.   */
  int                 ncolumns;          /* How many columns is in it. */
  struct _variable   *left;              /* The pointer used in to or- */
  struct _variable   *right;             /* ganise the Btree           */
  tag_attr           *widget_tag_attr;   /* Tag attributes of the widget. */
  int                 autonamed;         /* have a default name?       */
} variable;

/*
** Functions:
*/
variable *variables_new( const char *name );
variable *
variables_new_with_widget(
		AttributeSet *Attr, 
		tag_attr     *widget_tag_attr,
		GtkWidget    *widget, 
		int           type);

gboolean variables_is_avail_by_name( const char *name );
variable *variables_get_by_name( const char *name );
variable *find_variable_by_widget(GtkWidget *widget);

variable *variables_set_widget( const char *name, GtkWidget *widget );
variable *variables_set_parent( const char *name, GtkWidget *parent );
variable *variables_set_type( const char *name, int type );
variable *variables_set_attributes( const char *name, AttributeSet *a);
variable *variables_set_value( const char *name, const char *value );
variable *variables_set_row_column( const char *name,
                                    int row, int column );

void variables_drop_by_parent(variable *actual, GtkWidget *Parent);

variable *variables_refresh( const char *name );
variable *variables_clear( const char *name );
int remove_selected_variable(const char *name);
int append_fromto_variable(const char *from, const char *to);


void variables_export_all( void );
void variables_initialize_all( void );

void variables_print_debug( variable *actual );
void variables_print_one( variable *var );
gint variables_count_widgets(void);
#endif



