/*
 * stringman.h: Special string manipulation functions
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

#ifndef STRINGMAN_H
#define STRINGMAN_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#include "gtkdialog.h"
#include "attributes.h"

typedef struct list_t {
	int n_lines;
	int maxlines;
	char **line;
} list_t;

typedef enum {
	CommandShellCommand      = 0,
	CommandExit              = 1,
	CommandCloseWindow       = 2,
	CommandLaunch            = 3,
	CommandEnable            = 4,
	CommandDisable           = 5,
	CommandRefresh           = 6,
	CommandSave              = 7,
	CommandFileSelect        = 8,
	CommandClear             = 9,
	CommandRemoveSelected    = 10,
	CommandInsert            = 11,
	CommandAppend            = 12
} CommandType;

#ifdef G_OS_WIN32
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
#endif

list_t *linecutter(char *str, int fs );
char *find_pixmap( char *filename );
tag_attr *new_tag_attributeset(char *name, char *value);
tag_attr *add_tag_attribute(tag_attr *attr, char *name, char *value);
char *str_default_name (int itype);
char *get_tag_attribute(tag_attr *attr, const char *name);

gboolean input_is_shell_command(const gchar *command);
const gchar *input_get_shell_command(const gchar *command);
gboolean command_is_shell_command(const gchar *command);
const gchar *command_get_shell_command(const gchar *command);
gboolean command_is_exit_command(const gchar *command);
const gchar *command_get_exit_command(const gchar *command);
gboolean command_is_exit_command(const gchar *command);
const gchar *command_get_exit_command(const gchar *command);
gboolean command_is_closewindow_command(const gchar *command);
const gchar *command_get_closewindow_command(const gchar *command);
gboolean command_is_launch_command(const gchar *command);
const gchar *command_get_launch_command(const gchar *command);
gboolean command_is_enable_command(const gchar *command);
const gchar *command_get_enable_command(const gchar *command);
gboolean command_is_disable_command(const gchar *command);
const gchar *command_get_disable_command(const gchar *command);
gboolean command_is_refresh_command(const gchar *command);
const gchar *command_get_refresh_command(const gchar *command);
gboolean command_is_save_command(const gchar *command);
const gchar *command_get_save_command(const gchar *command);
gboolean command_is_fileselect_command(const gchar *command);
const gchar *command_get_fileselect_command(const gchar *command);
gboolean command_is_clear_command(const gchar *command);
const gchar *command_get_clear_command(const gchar *command);
gboolean command_is_removeselected_command(const gchar *command);
const gchar *command_get_removeselected_command(const gchar *command);
gboolean command_is_insert_command(const gchar *command);
const gchar *command_get_insert_command(const gchar *command);
gboolean command_is_append_command(const gchar *command);
const gchar *command_get_append_command(const gchar *command);
void command_get_prefix(const gchar *string, gchar **prefix, gchar **command);
CommandType command_prefix_get_type(const gchar *prefix);




#endif

