/*
 * main.h:
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

#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <gtk/gtk.h>
#include "variables.h"
#include "automaton.h"

#define PRG_UNKNOWN 0
#define PRG_MEMORY  1
#define PRG_STDIN   2
#define PRG_FILE    3

void reset_program_source(void);
gint set_program_source(gchar *name);
void set_program_name(gchar *name);
gchar *get_program_name(void);


#endif
