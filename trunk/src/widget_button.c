/*
 * widget_button.c: 
 * Gtkdialog - A small utility for fast and easy GUI building.
 * Copyright (C) 2003-2007  László Pere <pipas@linux.pte.hu>
 * Copyright (C) 2011 Thunor <thunorsif@hotmail.com>
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

/* Includes */
#define _GNU_SOURCE
#include <gtk/gtk.h>
#include "config.h"
#include "gtkdialog.h"
#include "attributes.h"
#include "automaton.h"
#include "widgets.h"

/* Defines */
//#define DEBUG_CONTENT
//#define DEBUG_TRANSITS

/* Local function prototypes, located at file bottom */
static void widget_button_input_by_command(variable *var, char *command);
static void widget_button_input_by_file(variable *var, char *filename);
static void widget_button_input_by_items(variable *var);

/* Notes:
 * The togglebutton widget is near identical to the button widget
 * so there's absolutely no point in maintaining another pair of files */

/***********************************************************************
 * Clear                                                               *
 ***********************************************************************/

void widget_button_clear(variable *var)
{
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	fprintf(stderr, "%s(): Clear not implemented for this widget.\n", __func__);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Create                                                              *
 ***********************************************************************/
GtkWidget *widget_button_create(
	AttributeSet *Attr, tag_attr *attr, gint Type)
{
	#define           TYPE_BUTTON 0
	#define           TYPE_BUTTON_LAB 1
	#define           TYPE_BUTTON_PIX 2
	#define           TYPE_BUTTON_LABPIX 3
	GdkPixbuf        *pixbuf = NULL;
	GError           *error = NULL;
	GList            *element;
	GtkIconTheme     *icon_theme;
	GtkWidget        *box = NULL;
	GtkWidget        *icon = NULL;
	GtkWidget        *label = NULL;
	GtkWidget        *widget = NULL;
	gchar            *file_name = NULL;
	gchar            *icon_name = NULL;
	gchar            *labeldirective;
	gchar            *stock_name = NULL;
	gchar            *value;
	gint              position = -1;
	gint              size = 20;
	gint              buttontype = TYPE_BUTTON;
	gint              width = -1, height = -1;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	switch (Type) {
		case WIDGET_OKBUTTON:
			widget = gtk_button_new_from_stock(GTK_STOCK_OK);
			attributeset_set_if_unset(Attr, ATTR_LABEL, "OK");
			break;
		case WIDGET_CANCELBUTTON:
			widget = gtk_button_new_from_stock(GTK_STOCK_CANCEL);
			attributeset_set_if_unset(Attr, ATTR_LABEL, "Cancel");
			break;
		case WIDGET_HELPBUTTON:
			widget = gtk_button_new_from_stock(GTK_STOCK_HELP);
			attributeset_set_if_unset(Attr, ATTR_LABEL, "Help");
			break;
		case WIDGET_YESBUTTON:
			widget = gtk_button_new_from_stock(GTK_STOCK_YES);
			attributeset_set_if_unset(Attr, ATTR_LABEL, "Yes");
			break;
		case WIDGET_NOBUTTON:
			widget = gtk_button_new_from_stock(GTK_STOCK_NO);
			attributeset_set_if_unset(Attr, ATTR_LABEL, "No");
			break;
		case WIDGET_TOGGLEBUTTON:
		case WIDGET_BUTTON:
			/* Read declared directives */
			if (attributeset_is_avail(Attr, ATTR_WIDTH))
				width = atoi(attributeset_get_first(&element, Attr, ATTR_WIDTH));
			if (attributeset_is_avail(Attr, ATTR_HEIGHT))
				height = atoi(attributeset_get_first(&element, Attr, ATTR_HEIGHT));

			/* Discover from the directives which type of button
			 * we are going to create */
			if (!attributeset_is_avail(Attr, ATTR_INPUT) &&
				attributeset_is_avail(Attr, ATTR_LABEL)) {
				buttontype = TYPE_BUTTON_LAB;
			} else if (attributeset_is_avail(Attr, ATTR_INPUT) &&
				!attributeset_is_avail(Attr, ATTR_LABEL)) {
				buttontype = TYPE_BUTTON_PIX;
			} else if (attributeset_is_avail(Attr, ATTR_INPUT) &&
				attributeset_is_avail(Attr, ATTR_LABEL)) {
				buttontype = TYPE_BUTTON_LABPIX;
			}

			/* Enforce a default label because TYPE_BUTTON and a
			 * default exit action will be created requiring it */
			if (!attributeset_is_avail(Attr, ATTR_LABEL))
				attributeset_set_if_unset(Attr, ATTR_LABEL, "OK");
			labeldirective = attributeset_get_first(&element, Attr, ATTR_LABEL);

#ifdef DEBUG_CONTENT
			fprintf(stderr, "%s(): buttontype=%i labeldirective=%s\n",
				__func__, buttontype, labeldirective);
#endif

			/* If the button is to contain an image then load it now */
			if (buttontype == TYPE_BUTTON_PIX || buttontype == TYPE_BUTTON_LABPIX) {
				file_name = attributeset_get_first(&element, Attr, ATTR_INPUT) + 5;
				icon_name = attributeset_get_this_tagattr(&element, Attr, ATTR_INPUT, "icon");
				stock_name = attributeset_get_this_tagattr(&element, Attr, ATTR_INPUT, "stock");
				if (stock_name != NULL) {
					icon = gtk_image_new_from_stock(stock_name, GTK_ICON_SIZE_BUTTON);
				} else if (icon_name != NULL) {
					icon_theme = gtk_icon_theme_get_default();
					/* Use the height or width dimension to override the default size */
					if (height > -1) size = height;
					else if (width > -1) size = width;
					pixbuf = gtk_icon_theme_load_icon (icon_theme, icon_name,
						size, 0, &error);
					icon = gtk_image_new_from_pixbuf(pixbuf);	
					/* pixbuf is no longer required and should be unreferenced */
					g_object_unref(pixbuf);
				} else {
					if (width == -1 && height == -1) {
						/* Handle unscaled images */
						icon = gtk_image_new_from_file(find_pixmap(file_name));
					} else {
						/* Handle scaled images */
						pixbuf = gdk_pixbuf_new_from_file_at_size(
							find_pixmap(file_name), width, height, NULL);
						if (pixbuf) {
							icon = gtk_image_new_from_pixbuf(pixbuf);
							/* pixbuf is no longer required and should be unreferenced */
							g_object_unref(pixbuf);
						} else {
							/* pixbuf is null (file not found) so by using this
							* function gtk will substitute a broken image icon */
							icon = gtk_image_new_from_file("");
						}
					}
				}
			}

			/* Create the button */
			switch (buttontype) {
				case TYPE_BUTTON:
					/* Thunor: No label or input directives were initially
					 * found, but "use-stock" and "label" tag attributes
					 * could exist which GTK+ will set after realization.
					 * We'll simply drop through to create a default button */
				case TYPE_BUTTON_LAB:
					if (Type == WIDGET_BUTTON) {
						widget = gtk_button_new_with_label(labeldirective);
					} else if (Type == WIDGET_TOGGLEBUTTON) {
						widget = gtk_toggle_button_new_with_label(labeldirective);
					}
					break;
				case TYPE_BUTTON_PIX:
					if (Type == WIDGET_BUTTON) {
						widget = gtk_button_new();
					} else if (Type == WIDGET_TOGGLEBUTTON) {
						widget = gtk_toggle_button_new();
					}
					gtk_container_add(GTK_CONTAINER(widget), icon);
					break;
				case TYPE_BUTTON_LABPIX:
					if (Type == WIDGET_BUTTON) {
						widget = gtk_button_new();
					} else if (Type == WIDGET_TOGGLEBUTTON) {
						widget = gtk_toggle_button_new();
					}
					/* Create the label supporting mnemonics if the
					 * GTK+ property "use-underline" is true */
					if (attr &&
						((value = get_tag_attribute(attr, "use-underline")) ||
						(value = get_tag_attribute(attr, "use_underline"))) &&
						((strcasecmp(value, "true") == 0) || (strcasecmp(value, "yes") == 0) ||
						(atoi(value) == 1))) {
						label = gtk_label_new_with_mnemonic(labeldirective);
					} else {
						label = gtk_label_new(labeldirective);
					}
					/* Thunor: If the GTK+ property "image-position" is declared
					 * (in this case being used as a custom attribute since it'll
					 * have no effect otherwise) then position the image relative
					 * to the label */
					if (attr) {
						if (!(value = get_tag_attribute(attr, "image_position")))
							value = get_tag_attribute(attr, "image-position");
						if (value) {
							if (strcasecmp(value, "bottom") == 0 ||
								atoi(value) == GTK_POS_BOTTOM) {
								position = GTK_POS_BOTTOM;
							} else if (strcasecmp(value, "top") == 0 ||
								atoi(value) == GTK_POS_TOP) {
								position = GTK_POS_TOP;
							} else if (strcasecmp(value, "right") == 0 ||
								atoi(value) == GTK_POS_RIGHT) {
								position = GTK_POS_RIGHT;
							} else /*if (strcasecmp(value, "left") == 0 ||
								atoi(value) == GTK_POS_LEFT) */ {
								/* Note that atoi will return 0 for any non-integer string in
								 * value, therefore GTK_POS_LEFT should be checked last */
								position = GTK_POS_LEFT;
							}
						}
					}
					/* Pack everything into a box inside the button */
					if (position == -1) {
						/* Thunor: This is the original code */
						box = gtk_hbox_new(FALSE, 5);
						gtk_container_add(GTK_CONTAINER(widget), box);
						gtk_box_pack_end(GTK_BOX(box), label, TRUE, TRUE, 0);
						gtk_box_pack_end(GTK_BOX(box), icon, TRUE, TRUE, 0);
					} else {
						/* Thunor: This code has been added to enable
						 * positioning of the image relative to the label */
						if (position == GTK_POS_BOTTOM || position == GTK_POS_TOP) {
							box = gtk_vbox_new(FALSE, 5);
						} else {
							box = gtk_hbox_new(FALSE, 5);
						}
						gtk_container_add(GTK_CONTAINER(widget), box);
						if (position == GTK_POS_BOTTOM || position == GTK_POS_RIGHT) {
							gtk_box_pack_end(GTK_BOX(box), icon, TRUE, TRUE, 0);
							gtk_box_pack_end(GTK_BOX(box), label, TRUE, TRUE, 0);
						} else {
							gtk_box_pack_end(GTK_BOX(box), label, TRUE, TRUE, 0);
							gtk_box_pack_end(GTK_BOX(box), icon, TRUE, TRUE, 0);
						}
					}
					break;
			}
			break;
	}

	switch (Type) {
		case WIDGET_OKBUTTON:
		case WIDGET_CANCELBUTTON:
		case WIDGET_HELPBUTTON:
		case WIDGET_YESBUTTON:
		case WIDGET_NOBUTTON:
		case WIDGET_BUTTON:
			/* For this widget there is a default exit action and
			 * this requires creating if no actions are set */
			if (!attributeset_is_avail(Attr, ATTR_ACTION)) {
				attributeset_insert(Attr, ATTR_ACTION,
					attributeset_get_first(&element, Attr, ATTR_LABEL));
				attributeset_get_first(&element, Attr, ATTR_ACTION);
				attributeset_set_this_tagattr(&element, Attr, ATTR_ACTION,
					"type", "exit");
			}
			break;
		case WIDGET_TOGGLEBUTTON:
			break;
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return widget;
}

/***********************************************************************
 * Environment Variable All Construct                                  *
 ***********************************************************************/

gchar *widget_button_envvar_all_construct(variable *var)
{
	gchar            *string;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* This function should not be connected-up by default */

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return string;
}

/***********************************************************************
 * Environment Variable Construct                                      *
 ***********************************************************************/

gchar *widget_button_envvar_construct(GtkWidget *widget)
{
	gchar            *string;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	string = g_strdup("");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return string;
}

/***********************************************************************
 * Fileselect                                                          *
 ***********************************************************************/

void widget_button_fileselect(
	variable *var, const char *name, const char *value)
{
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	fprintf(stderr, "%s(): Fileselect not implemented for this widget.\n", __func__);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Refresh                                                             *
 ***********************************************************************/
void widget_button_refresh(variable *var)
{
	GList            *element;
	gchar            *act;
	gint              initialised = FALSE;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* Get initialised state of widget */
	if (g_object_get_data(G_OBJECT(var->Widget), "initialised") != NULL)
		initialised = (gint)g_object_get_data(G_OBJECT(var->Widget), "initialised");

	/* The <input> tag... */
	act = attributeset_get_first(&element, var->Attributes, ATTR_INPUT);
	while (act) {
		if (input_is_shell_command(act))
			widget_button_input_by_command(var, act + 8);
		/* input file stock = "File:", input file = "File:/path/to/file" */
		if (strncasecmp(act, "file:", 5) == 0 && strlen(act) > 5)
			/* Don't refresh images on the first call otherwise they
			 * get created and then immediately refreshed at start-up */
			if (initialised)
				widget_button_input_by_file(var, act + 5);
		act = attributeset_get_next(&element, var->Attributes, ATTR_INPUT);
	}

	/* The <item> tags... */
	if (attributeset_is_avail(var->Attributes, ATTR_ITEM))
		widget_button_input_by_items(var);

	/* Initialise these only once at start-up */
	if (!initialised) {
		/* Apply directives */
		if (attributeset_is_avail(var->Attributes, ATTR_DEFAULT))
			fprintf(stderr, "%s(): <default> not implemented for this widget.\n",
				__func__);
		if ((attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "false")) ||
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "disabled")) ||	/* Deprecated */
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "no")) ||
			(attributeset_cmp_left(var->Attributes, ATTR_SENSITIVE, "0")))
			gtk_widget_set_sensitive(var->Widget, FALSE);

		/* Connect signals */
		g_signal_connect(G_OBJECT(var->Widget), "clicked", 
			G_CALLBACK(button_clicked_attr),(gpointer)var->Attributes);
		g_signal_connect(G_OBJECT(var->Widget), "enter",	/* Deprecated by "enter-notify-event" */
			G_CALLBACK(button_entered_attr),(gpointer)var->Attributes);
		g_signal_connect(G_OBJECT(var->Widget), "leave",	/* Deprecated by "leave-notify-event" */
			G_CALLBACK(button_leaved_attr),(gpointer)var->Attributes);
		g_signal_connect(G_OBJECT(var->Widget), "pressed",	/* Deprecated by "button-press-event" */
			G_CALLBACK(button_pressed_attr),(gpointer)var->Attributes);
		g_signal_connect(G_OBJECT(var->Widget), "released",	/* Deprecated by "button-release-event" */
			G_CALLBACK(button_released_attr),(gpointer)var->Attributes);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Removeselected                                                      *
 ***********************************************************************/

void widget_button_removeselected(variable *var)
{
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	fprintf(stderr, "%s(): Removeselected not implemented for this widget.\n",
		__func__);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Save                                                                *
 ***********************************************************************/

void widget_button_save(variable *var)
{
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	fprintf(stderr, "%s(): Save not implemented for this widget.\n", __func__);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by Command                                                    *
 ***********************************************************************/

static void widget_button_input_by_command(variable *var, char *command)
{
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	fprintf(stderr, "%s(): <input> not implemented for this widget.\n", __func__);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by File                                                       *
 ***********************************************************************/

static void widget_button_input_by_file(variable *var, char *filename)
{
	GdkPixbuf        *pixbuf;
	GList            *boxchildren = NULL;
	GList            *btnchildren = NULL;
	GList            *child;
	GList            *element;
	gint              width = -1, height = -1;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (attributeset_is_avail(var->Attributes, ATTR_WIDTH))
		width = atoi(attributeset_get_first(&element, var->Attributes, ATTR_WIDTH));
	if (attributeset_is_avail(var->Attributes, ATTR_HEIGHT))
		height = atoi(attributeset_get_first(&element, var->Attributes, ATTR_HEIGHT));

	btnchildren = gtk_container_get_children(GTK_CONTAINER(var->Widget));
	child = g_list_first(btnchildren);
	while (child) {
		if (GTK_IS_IMAGE(child->data)) {
			if (width == -1 && height == -1) {
				/* Handle unscaled images */
				gtk_image_set_from_file(GTK_IMAGE(child->data), find_pixmap(filename));
			} else {
				/* Handle scaled images */
				pixbuf = gdk_pixbuf_new_from_file_at_size(
					find_pixmap(filename), width, height, NULL);
				if (pixbuf) {
					gtk_image_set_from_pixbuf(GTK_IMAGE(child->data), pixbuf);
					/* pixbuf is no longer required and should be unreferenced */
					g_object_unref(pixbuf);
				} else {
					/* pixbuf is null (file not found) so by using this
					 * function gtk will substitute a broken image icon */
					gtk_image_set_from_file(GTK_IMAGE(child->data), "");
				}
			}
			break;
		} else if (GTK_IS_BOX(child->data)) {
			boxchildren = gtk_container_get_children(GTK_CONTAINER(child->data));
			child = g_list_first(boxchildren);
		} else {
			child = child->next;
		}
	}
	if (boxchildren) {
		g_list_free(boxchildren);
		boxchildren = NULL;
	}
	if (btnchildren) {
		g_list_free(btnchildren);
		btnchildren = NULL;
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Input by Items                                                      *
 ***********************************************************************/

static void widget_button_input_by_items(variable *var)
{
	gchar            *var1;
	gint              var2;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	fprintf(stderr, "%s(): <item> not implemented for this widget.\n", __func__);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}
