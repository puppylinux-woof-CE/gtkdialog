/*
 * Copyright (C) 2007 Pere Laszlo
 * $Id: $
 *
 * This is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Library General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * $Log: $
 * 
 */

#ifndef PIP_PRINTING_H
#define PIP_PRINTING_H

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

/*************************************************************************
 * Structures, unions, types:                                            *
 *                                                                       *
 *                                                                       *
 *************************************************************************/
typedef enum {
  PIP_PRINT_OPERATION_ACTION_PRINT_DIALOG,
  PIP_PRINT_OPERATION_ACTION_PRINT,
  PIP_PRINT_OPERATION_ACTION_PREVIEW,
  PIP_PRINT_OPERATION_ACTION_EXPORT
} PipPrintOperationAction;


/*************************************************************************
 * Functions:                                                            *
 *                                                                       *
 *                                                                       *
 *************************************************************************/
inline void
pip_message_print_debug(
		const gchar *function,
		const gchar *message,
		...);

inline void
pip_message_print_warning(
		const gchar *function,
		const gchar *message,
		...);


void 
unimplemented(const char *function_name, 
		const char *filename,
		gint linenumber);
#endif
