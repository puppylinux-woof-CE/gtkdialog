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
