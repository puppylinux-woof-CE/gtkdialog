/*
 * glade_support.h: The interface between Glade and Gtkdialog.
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

#ifndef GLADE_SUPPORT_H
#define GLADE_SUPPORT_H

#if HAVE_GLADE_LIB

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <glade/glade.h>
#include "attributes.h"

/*************************************************************************
 * Structures, unions, types:                                            *
 *                                                                       *
 *                                                                       *
 *************************************************************************/


/*************************************************************************
 * Functions:                                                            *
 *                                                                       *
 *                                                                       *
 *************************************************************************/
void run_program_by_glade(const gchar *filename, const gchar *window_name);

#endif
#endif
