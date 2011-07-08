/*
 * macros.h:
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

#include <gtk/gtk.h>
#include "printing.h"

#define PIP_DEBUG_ALL 0

#if PIP_DEBUG_ALL
#  define DEBUG
#  define WARNING
#endif

/**
 * PIP_DEBUG:
 * @...: The format string and the data to print as in #printf.
 *
 * Prints a debug message to the standard output. This macro is turned off, if
 * the #DEBUG macro is not defined before loading of the pip/macros.h header
 * file.
 */
#undef PIP_DEBUG
#ifndef DEBUG
#  define PIP_DEBUG(...) /* nop */
#else
#  define PIP_DEBUG(...) pip_message_print_debug(__func__, __VA_ARGS__);
#endif

#ifdef DEBUG
#  ifndef WARNING
#    define WARNING
#  endif
#endif

/**
 * PIP_WARNING:
 * @...: The format string and the data to print as in #printf.
 *
 * Prints a warning message to the standard output. This macro is turned off, 
 * if the #DEBUG and the #WARNING macros are not defined before loading of 
 * the pip/macros.h header file.
 */
#undef PIP_WARNING
#ifndef WARNING
#  define PIP_WARNING(...) /* nop */
#else
#  define PIP_WARNING(...) pip_message_print_warning(__func__, __VA_ARGS__);
#endif

/**
 * UNIMPLEMENTED:
 *
 * Starts up a warning message window showing that a feature is unimplemented.
 */
#define UNIMPLEMENTED unimplemented(__func__, __FILE__, __LINE__)

