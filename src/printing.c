/*
 * printing.c:
 * Gtkdialog - A small utility for fast and easy GUI building.
 * Copyright (C) 2003-2007  László Pere <pipas@linux.pte.hu>
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

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "gtkdialog.h"
#include "printing.h"

/*************************************************************************
 * Static declarations:                                                  *
 *                                                                       *
 *                                                                       *
 *************************************************************************/


/*************************************************************************
 * Functions:                                                            *
 *                                                                       *
 *                                                                       *
 *************************************************************************/
inline void
pip_message_print_debug(
		const gchar *function,
		const gchar *format,
		...)
{
	va_list args;
	
	va_start (args, format);
	printf("\033[1;32m%32s()\033[0;39m: ", function);
	g_vprintf(format, args);
	va_end (args);
	putchar('\n');
	fflush(stdout);
}

inline void
pip_message_print_warning(
		const gchar *function,
		const gchar *format,
		...)
{
	va_list args;
	
	va_start (args, format);
	printf("\033[1;31m%32s()\033[0;39m: ", function);
	g_vprintf(format, args);
	va_end (args);
	putchar('\n');
	fflush(stdout);
}


void 
unimplemented(const char *function_name, 
		const char *filename,
		gint linenumber)
{
	GtkWidget *dialog;
	dialog = gtk_message_dialog_new (NULL,
                                  GTK_DIALOG_DESTROY_WITH_PARENT,
                                  GTK_MESSAGE_ERROR,
                                  GTK_BUTTONS_CLOSE,
        			  "Unimplementes function "
				  "'%s()' at line %d of source file '%s'.",
                                  function_name,
				  linenumber,
				  filename);
	
	gtk_dialog_run (GTK_DIALOG (dialog));
	gtk_widget_destroy (dialog);
}
