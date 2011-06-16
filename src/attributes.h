/* 
** attributes.h: Handles the attributes of widgets
** copyright: (c) 2003 by László Pere
** email: pipas@linux.pte.hu
**
** This program is free software; you can redistribute it and/or 
** modify  it under the terms of the GNU General Public License as
** published by the Free Software Foundation; either version 2 of
** the License, or (at your option) any later version.
*/
#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "gtkdialog.h"
#include "memory.h"

/* How much attributes we store in an attribute set? */
#define ATTRNUMBER 32 

typedef struct _namevalue {
	char *name;
	char *value;
} namevalue;

typedef struct _tag_attr {
	int n;
	int nmax;
	namevalue *pairs;
} tag_attr;

typedef struct _Attribute
{
  char *text;
  tag_attr *tag_attributes;
} Attribute;

typedef struct _AttributeSet
{
  int 	  n_attr;	/* How many attributes can be found here?  */
  GList **attr;		/* Attributes are linked lists.            */
  GList **_pointer;	/* Pointers for incremental read function. */
} AttributeSet;


gchar *attribute_name(gint attribute);

AttributeSet *attributeset_new( void );
gboolean attributeset_is_avail( AttributeSet *set, int attribute );
gboolean attributeset_cmp_left( AttributeSet *set, int attribute,
                                const char *str );
gchar *attributeset_get_first( AttributeSet *set, int attribute );
char *attributeset_get_next( AttributeSet *set, int attribute );
gchar *attributeset_set_if_unset(
		AttributeSet *set, 
		gint          attribute,
		const gchar  *value);

const char *
attributeset_insert(AttributeSet * set, 
		          int attribute, 
			  const char *value
			  );

const char *
attributeset_insert_with_tagattrs(
		AttributeSet * set, 
		int attribute, 
		const char *s, 
		tag_attr *t_attr);

char *attributeset_get_this_tagattr(
		AttributeSet *set, 
		int attribute, 
		const char *name);

void attributeset_set_this_tagattr(
		AttributeSet *set, 
		gint attribute, 
		gchar *name, 
		gchar *value);

inline gboolean is_input_with_this_tagattr( AttributeSet *Attr, const char *name);
inline gboolean is_item_with_this_tagattr(AttributeSet *Attr, const char *name);

#endif

