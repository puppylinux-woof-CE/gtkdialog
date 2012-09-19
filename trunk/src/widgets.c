/*
 * widgets.c: Widget manipulation functions
 * Gtkdialog - A small utility for fast and easy GUI building.
 * Copyright (C) 2003-2007  László Pere <pipas@linux.pte.hu>
 * Copyright (C) 2011-2012  Thunor <thunorsif@hotmail.com>
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

/* 
**
** $Id: widgets.c,v 1.2 2004/11/25 19:11:12 pipas Exp pipas $
** $Log: widgets.c,v $
** Revision 1.2  2004/11/25 19:11:12  pipas
** Small enhancements.
**
** Revision 1.1  2004/11/18 16:47:05  root
** Initial revision
**
 */

#include <gtk/gtk.h>
#include <math.h>
#include "gtkdialog.h"
#include "widgets.h"
#include "stringman.h"
#include "widget_button.h"
#include "widget_checkbox.h"
#include "widget_colorbutton.h"
#include "widget_combobox.h"
#include "widget_comboboxtext.h"
#include "widget_edit.h"
#include "widget_entry.h"
#include "widget_eventbox.h"
#include "widget_expander.h"
#include "widget_fontbutton.h"
#include "widget_frame.h"
#include "widget_hbox.h"
#include "widget_hscale.h"
#include "widget_hseparator.h"
#include "widget_list.h"
#include "widget_menubar.h"
#include "widget_menuitem.h"
#include "widget_notebook.h"
#include "widget_pixmap.h"
#include "widget_progressbar.h"
#include "widget_radiobutton.h"
#include "widget_spinbutton.h"
#include "widget_statusbar.h"
#include "widget_table.h"
#include "widget_terminal.h"
#include "widget_text.h"
#include "widget_timer.h"
#include "widget_tree.h"
#include "widget_vbox.h"
#include "widget_window.h"
#include "signals.h"
#include "tag_attributes.h"

#undef DEBUG
#undef WARNING
#include "macros.h"

extern gchar *option_include_file;

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

char *widget_get_text_value(GtkWidget *widget, int type)
{
	gchar            *string;

#ifdef DEBUG
	g_message("%s(): type: %08x\n", __func__, type);
#endif
	if (widget == NULL) {
		g_warning("%s(): NULL Widget", __func__);
		return ("NULL WIDGET");
	}

	switch (type) {
		case WIDGET_CANCELBUTTON:
		case WIDGET_HELPBUTTON:
		case WIDGET_NOBUTTON:
		case WIDGET_OKBUTTON:
		case WIDGET_YESBUTTON:
		case WIDGET_TOGGLEBUTTON:
		case WIDGET_BUTTON:
			string = widget_button_envvar_construct(widget);
			return string;
			break;
		case WIDGET_CHECKBOX:
			string = widget_checkbox_envvar_construct(widget);
			return string;
			break;
		case WIDGET_COLORBUTTON:
			string = widget_colorbutton_envvar_construct(widget);
			return string;
			break;
		case WIDGET_COMBOBOX:
			string = widget_combobox_envvar_construct(widget);
			return string;
			break;
		case WIDGET_COMBOBOXENTRY:
		case WIDGET_COMBOBOXTEXT:
			string = widget_comboboxtext_envvar_construct(widget);
			return string;
			break;
		case WIDGET_EDIT:
			string = widget_edit_envvar_construct(widget);
			return string;
			break;
		case WIDGET_ENTRY:
			string = widget_entry_envvar_construct(widget);
			return string;
			break;
		case WIDGET_EVENTBOX:
			string = widget_eventbox_envvar_construct(widget);
			return string;
			break;
		case WIDGET_EXPANDER:
			string = widget_expander_envvar_construct(widget);
			return string;
			break;
		case WIDGET_FONTBUTTON:
			string = widget_fontbutton_envvar_construct(widget);
			return string;
			break;
		case WIDGET_FRAME:
			string = widget_frame_envvar_construct(widget);
			return string;
			break;
		case WIDGET_HBOX:
			string = widget_hbox_envvar_construct(widget);
			return string;
			break;
		case WIDGET_HSCALE:
		case WIDGET_VSCALE:
			string = widget_hscale_envvar_construct(widget);
			return string;
			break;
		case WIDGET_HSEPARATOR:
		case WIDGET_VSEPARATOR:
			string = widget_hseparator_envvar_construct(widget);
			return string;
			break;
		case WIDGET_LIST:
			string = widget_list_envvar_construct(widget);
			return string;
			break;
		case WIDGET_MENUBAR:
			string = widget_menubar_envvar_construct(widget);
			return string;
			break;
		case WIDGET_MENUITEMSEPARATOR:
		case WIDGET_MENUITEM:
		case WIDGET_MENU:
			string = widget_menuitem_envvar_construct(widget);
			return string;
			break;
		case WIDGET_NOTEBOOK:
			string = widget_notebook_envvar_construct(widget);
			return string;
			break;
		case WIDGET_PIXMAP:
			string = widget_pixmap_envvar_construct(widget);
			return string;
			break;
		case WIDGET_PROGRESSBAR:
			string = widget_progressbar_envvar_construct(widget);
			return string;
			break;
		case WIDGET_RADIOBUTTON:
			string = widget_radiobutton_envvar_construct(widget);
			return string;
			break;
		case WIDGET_SPINBUTTON:
			string = widget_spinbutton_envvar_construct(widget);
			return string;
			break;
		case WIDGET_STATUSBAR:
			string = widget_statusbar_envvar_construct(widget);
			return string;
			break;
		case WIDGET_TABLE:
			string = widget_table_envvar_construct(widget);
			return string;
			break;
		case WIDGET_TERMINAL:
			string = widget_terminal_envvar_construct(widget);
			return string;
			break;
		case WIDGET_TEXT:
			string = widget_text_envvar_construct(widget);
			return string;
			break;
		case WIDGET_TIMER:
			string = widget_timer_envvar_construct(widget);
			return string;
			break;
#if GTK_CHECK_VERSION(2,4,0)
		case WIDGET_TREE:
			string = widget_tree_envvar_construct(widget);
			return string;
			break;
#endif
		case WIDGET_VBOX:
			string = widget_vbox_envvar_construct(widget);
			return string;
			break;
		case WIDGET_WINDOW:
			string = widget_window_envvar_construct(widget);
			return string;
			break;


#if GTK_CHECK_VERSION(2,4,0)
		case WIDGET_CHOOSER:
			return gtk_file_chooser_get_filename(
					GTK_FILE_CHOOSER(widget));
			break;
#endif


		default:
			return NULL;
	}
	g_error("%s(): this should not be reached", __func__);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

FILE *widget_opencommand(const char *command)
{
	char *the_line;
	FILE *infile;

	PIP_DEBUG("Opening command: '%s'", command);

	if (option_include_file != NULL) {
		/* Debian 01_bashism patch: use dot rather than source.
		the_line = g_strdup_printf("source %s; %s", */
		the_line = g_strdup_printf(". %s; %s",
				option_include_file, command);
		infile = popen(the_line, "r");
		g_free(the_line);
	} else {
		infile = popen(command, "r");
	}
	
	if (infile == NULL) 
		g_warning("%s(): %m", __func__);
	
	return infile;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

char *widgets_to_str(int itype)
{
	char *type;
	switch (itype) {
		case WIDGET_CANCELBUTTON:
			type = "CANCELBUTTON";
			break;
		case WIDGET_HELPBUTTON:
			type = "HELPBUTTON";
			break;
		case WIDGET_NOBUTTON:
			type = "NOBUTTON";
			break;
		case WIDGET_OKBUTTON:
			type = "OKBUTTON";
			break;
		case WIDGET_YESBUTTON:
			type = "YESBUTTON";
			break;
		case WIDGET_BUTTON:
			type = "BUTTON";
			break;
		case WIDGET_CHECKBOX:
			type = "CHECKBOX";
			break;
		case WIDGET_COLORBUTTON:
			type = "COLORBUTTON";
			break;
		case WIDGET_COMBOBOX:
			type = "COMBOBOX";
			break;
		case WIDGET_COMBOBOXENTRY:
			type = "COMBOBOXENTRY";
			break;
		case WIDGET_COMBOBOXTEXT:
			type = "COMBOBOXTEXT";
			break;
		case WIDGET_EDIT:
			type = "EDIT";
			break;
		case WIDGET_ENTRY:
			type = "ENTRY";
			break;
		case WIDGET_EVENTBOX:
			type = "EVENTBOX";
			break;
		case WIDGET_EXPANDER:
			type = "EXPANDER";
			break;
		case WIDGET_FONTBUTTON:
			type = "FONTBUTTON";
			break;
		case WIDGET_FRAME:
			type = "FRAME";
			break;
		case WIDGET_HBOX:
			type = "HBOX";
			break;
		case WIDGET_HSCALE:
			type = "HSCALE";
			break;
		case WIDGET_HSEPARATOR:
			type = "HSEPARATOR";
			break;
		case WIDGET_LIST:
			type = "LIST";
			break;
		case WIDGET_MENU:
			type = "MENU";
			break;
		case WIDGET_MENUBAR:
			type = "MENUBAR";
			break;
		case WIDGET_MENUITEM:
			type = "MENUITEM";
			break;
		case WIDGET_MENUITEMSEPARATOR:
			type = "MENUITEMSEPARATOR";
			break;
		case WIDGET_NOTEBOOK:
			type = "NOTEBOOK";
			break;
		case WIDGET_PIXMAP:
			type = "PIXMAP";
			break;
		case WIDGET_PROGRESSBAR:
			type = "PROGRESSBAR";
			break;
		case WIDGET_RADIOBUTTON:
			type = "RADIOBUTTON";
			break;
		case WIDGET_SPINBUTTON:
			type = "SPINBUTTON";
			break;
		case WIDGET_STATUSBAR:
			type = "STATUSBAR";
			break;
		case WIDGET_TABLE:
			type = "TABLE";
			break;
		case WIDGET_TERMINAL:
			type = "TERMINAL";
			break;
		case WIDGET_TEXT:
			type = "TEXT";
			break;
		case WIDGET_TIMER:
			type = "TIMER";
			break;
		case WIDGET_TOGGLEBUTTON:
			type = "TOGGLEBUTTON";
			break;
#if GTK_CHECK_VERSION(2,4,0)
		case WIDGET_TREE:
			type = "TREE";
			break;
#endif
		case WIDGET_VBOX:
			type = "VBOX";
			break;
		case WIDGET_VSCALE:
			type = "VSCALE";
			break;
		case WIDGET_VSEPARATOR:
			type = "VSEPARATOR";
			break;
		case WIDGET_WINDOW:
			type = "WINDOW";
			break;


	case WIDGET_SCROLLEDW:
		type = "SCROLLEDW";
		break;
	default:
		type = "THINGY";
	}
	return (type);
}
