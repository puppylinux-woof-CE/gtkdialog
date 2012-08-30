/*
 * automaton.c: An automaton executing the program, creating widgets. 
 * Gtkdialog - A small utility for fast and easy GUI building.
 * Copyright (C) 2003-2007  László Pere <pipas@linux.pte.hu>
 * Copyright (C) 2011  Thunor <thunorsif@hotmail.com>
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
** $Id: automaton.c,v 1.3 2004/11/25 18:26:48 pipas Exp pipas $
** $Log: automaton.c,v $
** Revision 1.3  2004/11/25 18:26:48  pipas
** Menu seems to be much more better, and the actions are just the same.
**
** Revision 1.2  2004/11/18 16:45:52  root
**   The button now can have a pixmap and a label simultaneously.
**
** Revision 1.1  2004/11/16 20:45:22  root
** Initial revision
**
*/

#include <gtk/gtk.h>

#include "config.h"
#include "gtkdialog.h"
#include "widgets.h"
#include "automaton.h"
#include "stringman.h"
#include "attributes.h"
#include "widgets.h"
#include "widget_button.h"
#include "widget_checkbox.h"
#include "widget_colorbutton.h"
#include "widget_comboboxtext.h"
#include "widget_fontbutton.h"
#include "widget_frame.h"
#include "widget_hbox.h"
#include "widget_menubar.h"
#include "widget_notebook.h"
#include "widget_pixmap.h"
#include "widget_radiobutton.h"
#include "widget_spinbutton.h"
#include "widget_statusbar.h"
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

#if HAVE_VTE
#include <vte/vte.h>
#endif

#undef TOOLTIPS

extern gboolean option_no_warning;

instruction *program = NULL;
int instruction_counter = 0;		/* The first available memory cell */
size_t memory_counter = 0;			/* The size of program memory */

/* This records the last window widget created */
GtkWidget *window = NULL;

/*
 * Static function definitions.
 */
static int 
instruction_execute_push(token Token, 
		AttributeSet *Attr, 
		tag_attr *tag_attributes);


static gboolean
widget_connect_signals(
		GtkWidget    *widget,
		AttributeSet *Attr)
{
	g_return_val_if_fail(GTK_IS_WIDGET(widget), FALSE);

	PIP_DEBUG("Connecting signals for %p.", widget);

	g_signal_connect(G_OBJECT(widget), "button-press-event", 
			(GCallback) (on_any_widget_button_pressed), 
			(gpointer) Attr);
	g_signal_connect(G_OBJECT(widget), "button-release-event", 
			(GCallback) (on_any_widget_button_released), 
			(gpointer) Attr);
	g_signal_connect(G_OBJECT(widget), "configure-event", 
			(GCallback) (on_any_widget_configure_event), 
			(gpointer) Attr);
	g_signal_connect(G_OBJECT(widget), "delete-event", 
			(GCallback) (on_any_widget_delete_event), 
			(gpointer) Attr);
	g_signal_connect(G_OBJECT(widget), "destroy-event", 
			(GCallback) (on_any_widget_destroy_event), 
			(gpointer) Attr);
	g_signal_connect(G_OBJECT(widget), "enter-notify-event", 
			(GCallback) (on_any_widget_enter_notify_event), 
			(gpointer) Attr);
	g_signal_connect(G_OBJECT(widget), "leave-notify-event", 
			(GCallback) (on_any_widget_leave_notify_event), 
			(gpointer) Attr);
	g_signal_connect(G_OBJECT(widget), "focus-in-event", 
			(GCallback) (on_any_widget_focus_in_event), 
			(gpointer) Attr);
	g_signal_connect(G_OBJECT(widget), "focus-out-event", 
			(GCallback) (on_any_widget_focus_out_event), 
			(gpointer) Attr);
	g_signal_connect(G_OBJECT(widget), "hide", 
			(GCallback) (on_any_widget_hide), 
			(gpointer) Attr);
	g_signal_connect(G_OBJECT(widget), "key-press-event", 
			(GCallback) (on_any_widget_key_press_event), 
			(gpointer) Attr);
	g_signal_connect(G_OBJECT(widget), "key-release-event", 
			(GCallback) (on_any_widget_key_release_event), 
			(gpointer) Attr);
	g_signal_connect(G_OBJECT(widget), "map-event", 
			(GCallback) (on_any_widget_map_event), 
			(gpointer) Attr);
	g_signal_connect(G_OBJECT(widget), "unmap-event", 
			(GCallback) (on_any_widget_unmap_event), 
			(gpointer) Attr);
	g_signal_connect(G_OBJECT(widget), "show", 
			(GCallback) (on_any_widget_show), 
			(gpointer) Attr);

	return TRUE;
}

int 
execute_action(GtkWidget *widget, 
		const char *command, 
		const char *type)
{
	gchar *command_prefix;
	gchar *command_string;
	CommandType t;

	/* Thunor: I've re-engineered my signal blocking mechanism.
	 * There are a multitude of signal callbacks -- not just the
	 * widget_signal_executor -- but they all end up here, so if the
	 * global flag is true then the action functions simply don't
	 * get executed */
	if (!function_signals_block) {

		if (type == NULL || g_utf8_strlen(type, -1) == 0) {
			command_get_prefix(command, &command_prefix, &command_string);
		} else {
			command_prefix = g_strdup(type);
			command_string = g_strdup(command);
		}

		PIP_DEBUG("command: '%s' type: '%s'.", command_string, command_prefix);

		t = command_prefix_get_type(command_prefix);
		switch (t) {
			case CommandShellCommand:
				action_shellcommand(widget, command_string);
				break;

			case CommandExit:
				action_exitprogram(widget, command_string);
				break;

			case CommandCloseWindow:
				action_closewindow(widget, command_string);
				break;

			case CommandLaunch:
				action_launchwindow(widget, command_string);
				break;

			case CommandEnable:
				action_enable(widget, command_string);
				break;

			case CommandDisable:
				action_disable(widget, command_string);
				break;

			case CommandShow:
				action_show(widget, command_string);
				break;

			case CommandHide:
				action_hide(widget, command_string);
				break;

			case CommandActivate:
				action_activate(widget, command_string);
				break;

			case CommandGrabFocus:
				action_grabfocus(widget, command_string);
				break;

			case CommandPresentWindow:
				action_presentwindow(widget, command_string);
				break;

			case CommandRefresh:
				variables_export_all();
				action_refreshwidget(widget, command_string);
				break;

			case CommandSave:
				action_savewidget(widget, command_string);
				break;

			case CommandFileSelect:
				action_fileselect(widget, command_string);
				break;

			case CommandClear:
				action_clearwidget(widget, command_string);
				break;

			case CommandRemoveSelected:
				action_removeselected(widget, command_string);
				break;

			case CommandInsert:
				action_append(widget, command_string);
				break;

			case CommandAppend:
				action_append(widget, command_string);
				break;
			default:
				g_error("%s(): Unknown action type", __func__);
		}
			
		g_free(command_prefix);
		g_free(command_string);
	}

	return TRUE;
}


void print_command(instruction command)
{
    token Token;
    char *Argument;
    int Instr_Code;
    int Widget_Type;
    int Attribute_Number;
    static AttributeSet *Attr = NULL;

    Token = command.command;
    Argument = command.argument;

    Instr_Code = Token & COMMAND;
    Widget_Type = Token & WIDGET_TYPE;
    Attribute_Number = Token & ATTRIBUTE;

    switch (Instr_Code) {
    case PUSH:
	printf("push");
	switch (Widget_Type) {
		case WIDGET_CANCELBUTTON:
			printf("(new cancelbutton())");
			break;
		case WIDGET_HELPBUTTON:
			printf("(new helpbutton())");
			break;
		case WIDGET_NOBUTTON:
			printf("(new nobutton())");
			break;
		case WIDGET_OKBUTTON:
			printf("(new okbutton())");
			break;
		case WIDGET_YESBUTTON:
			printf("(new yesbutton())");
			break;
		case WIDGET_BUTTON:
			printf("(new button())");
			break;
		case WIDGET_CHECKBOX:
			printf("(new checkbox())");
			break;
		case WIDGET_COLORBUTTON:
			printf("(new colorbutton())");
			break;
		case WIDGET_COMBOBOXENTRY:
			printf("(new comboboxentry())");
			break;
		case WIDGET_COMBOBOXTEXT:
			printf("(new comboboxtext())");
			break;
		case WIDGET_FONTBUTTON:
			printf("(new fontbutton())");
			break;
		case WIDGET_FRAME:
			printf("(new frame(pop()))");
			break;
		case WIDGET_HBOX:
			printf("(new hbox(pop()))");
			break;
		case WIDGET_MENUBAR:
			printf("(new menubar(pop()))");
			break;
		case WIDGET_NOTEBOOK:
			printf("(new notebook(pop()))");
			break;
		case WIDGET_PIXMAP:
			printf("(new pixmap())");
			break;
		case WIDGET_RADIOBUTTON:
			printf("(new radiobutton())");
			break;
		case WIDGET_SPINBUTTON:
			printf("(new spinbutton())");
			break;
		case WIDGET_STATUSBAR:
			printf("(new statusbar())");
			break;
		case WIDGET_TERMINAL:
			printf("(new terminal())");
			break;
		case WIDGET_TEXT:
			printf("(new text())");
			break;
		case WIDGET_TIMER:
			printf("(new timer())");
			break;
		case WIDGET_TOGGLEBUTTON:
			printf("(new togglebutton())");
			break;
#if GTK_CHECK_VERSION(2,4,0)
		case WIDGET_TREE:
			printf("(new tree())");
			break;
#endif
		case WIDGET_VBOX:
			printf("(new vbox(pop()))");
			break;
		case WIDGET_WINDOW:
			printf("(new window(pop()))");
			break;


	case WIDGET_ENTRY:
	    printf("(new entry())");
	    break;
	case WIDGET_EDIT:
	    printf("(new edit)");
	    break;
	case WIDGET_PROGRESS:
	    printf("(new progressbar())");
	    break;
	case WIDGET_LIST:
	    printf("(new list())");
	    break;
	case WIDGET_TABLE:
	    printf("(new table())");
	    break;
	case WIDGET_COMBO:
	    printf("(new combo())");
	    break;
	case WIDGET_SCROLLEDW:
	    printf("(new scrolledwindow(pop()))");
	    break;
	case WIDGET_MENU:
	    printf("(new menu(pop()))");
	    break;
	case WIDGET_MENUITEM:
	    printf("(new menuitem())");
	    break;
	case WIDGET_MENUITEMSEPARATOR:
	    printf("(new menuitemseparator())");
	    break;
	case WIDGET_GVIM:
	    printf("(new gvim())");
	    break;
	case WIDGET_CHOOSER:
	    printf("(new chooser())");
	    break;
	case WIDGET_HSEPARATOR:
	    printf("(new hseparator())");
	    break;
	case WIDGET_VSEPARATOR:
	    printf("(new vseparator())");
	    break;
	case WIDGET_HSCALE:
	    printf("(new hscale())");
	    break;
	case WIDGET_VSCALE:
	    printf("(new vscale())");
	    break;
	default:
	    printf("(Unknown Widget: %d)", Widget_Type);
	}
	break;
    case IMASSG:
        printf("%s := pop()", Argument);
	break;
    case IMPUSH:
	printf("push");
	switch (Widget_Type) {
	case VARIABLE_NAME:
	    printf("(variable '%s')", Argument);
	    break;
	case CONST_NUMBER:
	    printf("(number '%s')", Argument);
	    break;
	case OP_ADD:
	    printf("(pop() + pop())");
	    break;
	case OP_SUBST:
	    printf("(pop() - pop())");
	    break;
	case OP_MULT:
	    printf("(pop() * pop())");
	    break;
	case OP_DIV:
	    printf("(pop() / pop())");
	    break;
	case REL_EQ:
	    printf("(pop() = pop())");
	    break;
	case REL_NE:
	    printf("(pop() != pop())");
	    break;

	default:
	    printf("(Unknown Parameter: %d)", Widget_Type);
	}
	break;
    case SUM:
	printf("push(pop() + pop())");
	break;
    case SHOW:
	printf("show");
	break;
    case SET:
	printf("%s := '%s'", attribute_name(Attribute_Number), Argument);
	break;
    case IFNGOTO:
	printf("if not pop() goto %d", command.ival);
	break;
    case GOTO:
	printf("goto %d", command.ival);
	break;
    default:
	printf(" %s(): unknown instruction: '%d' ", __func__, Instr_Code);
    }

    printf("\n");
    fflush(stdout);
}

void
print_program()
{
	gint pc;
	instruction command;
	
	for (pc = 0; pc < instruction_counter; ++pc) {
		command = program[pc];
		g_printf("%5d  ", pc);
		print_command(command);
	}
}

/*
** This function will run the program in memory.
*/
void run_program()
{
	static int        is_launched = 0;
	int               pc, q;
	stackelement      s;
	variable         *var;
	gchar            *progname;

	PIP_DEBUG("Program starting.");

	window_id++;	/* Generate a new unique window id */

	/*
	 * This is the main loop which creates the widgets, runs the program.
	 */
	for (pc = 0; pc < instruction_counter; ++pc) {
		instruction_execute(program[pc]);
	}

	PIP_DEBUG("Program ended.");

	/*
	 * When we executed the program, there is only one widget in
	 * the stack which is a window.
	 */
	s = pop();
	gtk_widget_show_all(s.widgets[0]);

	PIP_DEBUG("Window: %p.", s.widgets[0]);

	//
	// Now, all of the widgets are realized, so we can initialize
	// them as needed.
	//
	variables_initialize_all();

	/* Thunor: This verifies that later launched windows contain a variable
	 * that matches the exported shell variable which is a requirement.
	 * I can't enforce it since there will be applications out there that
	 * might break, but I can dump a warning to the terminal */
	if (is_launched++) {

		progname = get_program_name();
		var = variables_get_by_name(progname);

#ifdef DEBUG
		fprintf(stderr, "%s(): program_name=%s variable->Name=%s\n",
			__func__, progname, var->Name);
#endif
		if (var->Name == NULL) {
			g_warning("The recently launched window \"%s\" is missing \
an equivalently named variable directive <variable>%s</variable> which \
is a requirement of the launch action.", progname, progname);
		}

	}

	instruction_counter = 0;
	reset_program_source();

#ifdef DEBUG
	fprintf(stderr, "%s(): Calling gtk_main()\n", __func__);
#endif

	gtk_main();
}

void print_token(token Token)
{
	int Instr_Code;
	int Widget_Type;
	int Attribute_Number;
	Instr_Code = Token & COMMAND;
	Widget_Type = Token & WIDGET_TYPE;
	Attribute_Number = Token & ATTRIBUTE;

	switch (Instr_Code) {
		case PUSH:
			printf("push");
			break;
		case SUM:
			printf("push(pop() + pop())");
			goto finalize;
		case SET:
			printf("SET %s", 
					attribute_name(Attribute_Number));
			goto finalize;
		default:
			printf(" %s(): unknown instruction: '%d' ", __func__, Instr_Code);
	}

	switch (Widget_Type) {
		case WIDGET_CANCELBUTTON:
			printf("(CANCELBUTTON)");
			break;
		case WIDGET_HELPBUTTON:
			printf("(HELPBUTTON)");
			break;
		case WIDGET_NOBUTTON:
			printf("(NOBUTTON)");
			break;
		case WIDGET_OKBUTTON:
			printf("(OKBUTTON)");
			break;
		case WIDGET_YESBUTTON:
			printf("(YESBUTTON)");
			break;
		case WIDGET_BUTTON:
			printf("(BUTTON)");
			break;
		case WIDGET_CHECKBOX:
			printf("(CHECKBOX)");
			break;
		case WIDGET_COLORBUTTON:
			printf("(COLORBUTTON)");
			break;
		case WIDGET_COMBOBOXENTRY:
			printf("(COMBOBOXENTRY)");
			break;
		case WIDGET_COMBOBOXTEXT:
			printf("(COMBOBOXTEXT)");
			break;
		case WIDGET_FONTBUTTON:
			printf("(FONTBUTTON)");
			break;
		case WIDGET_FRAME:
			printf("(FRAME)");
			break;
		case WIDGET_HBOX:
			printf("(HBOX)");
			break;
		case WIDGET_MENUBAR:
			printf("(MENUBAR)");
			break;
		case WIDGET_NOTEBOOK:
			printf("(NOTEBOOK)");
			break;
		case WIDGET_PIXMAP:
			printf("(PIXMAP)");
			break;
		case WIDGET_RADIOBUTTON:
			printf("(RADIOBUTTON)");
			break;
		case WIDGET_SPINBUTTON:
			printf("(SPINBUTTON)");
			break;
		case WIDGET_STATUSBAR:
			printf("(STATUSBAR)");
			break;
		case WIDGET_TERMINAL:
			printf("(TERMINAL)");
			break;
		case WIDGET_TEXT:
			printf("(TEXT)");
			break;
		case WIDGET_TIMER:
			printf("(TIMER)");
			break;
		case WIDGET_TOGGLEBUTTON:
			printf("(TOGGLEBUTTON)");
			break;
#if GTK_CHECK_VERSION(2,4,0)
		case WIDGET_TREE:
			printf("(TREE)");
			break;
#endif
		case WIDGET_VBOX:
			printf("(VBOX)");
			break;
		case WIDGET_WINDOW:
			printf("(WINDOW)");
			break;


	case WIDGET_ENTRY:
		printf("(ENTRY)");
		break;
	case WIDGET_EDIT:
		printf("(EDIT)");
		break;
	case WIDGET_PROGRESS:
		printf("(PROGRESSBAR)");
		break;
	case WIDGET_LIST:
		printf("(LIST)");
		break;
	case WIDGET_TABLE:
		printf("(TABLE)");
		break;
	case WIDGET_COMBO:
		printf("(COMBO)");
		break;
	case WIDGET_SCROLLEDW:
		printf("(SCROLLEDW)");
		break;
	case WIDGET_MENU:
		printf("(MENU)");
		break;
	case WIDGET_MENUITEM:
		printf("(MENUITEM)");
		break;
	case WIDGET_GVIM:
		printf("(GVIM)");
		break;
	case WIDGET_CHOOSER:
		printf("(CHOOSER)");
		break;
	case WIDGET_HSEPARATOR:
		printf("(HSEPARATOR)");
	    break;
	case WIDGET_VSEPARATOR:
		printf("(VSEPARATOR)");
	    break;
	case WIDGET_HSCALE:
		printf("(HSCALE)");
		break;
	case WIDGET_VSCALE:
		printf("(VSCALE)");
		break;
	default:
		printf("Unknown Widget (%d)", Widget_Type);
	}
	
finalize:
	printf("\n");
	fflush(stdout);
}


int 
instruction_execute(instruction command)
{
	GList *element;
	token Token;
	char *Argument;
	int Instr_Code;
	int Widget_Type;
	int Attribute_Number;
	static AttributeSet *Attr = NULL;

	Token = command.command;
	Argument = command.argument;

	Instr_Code = Token & COMMAND;
	Widget_Type = Token & WIDGET_TYPE;
	Attribute_Number = Token & ATTRIBUTE;


	PIP_DEBUG("Executing token %08x with argument '%s'.", Token, Argument);
	PIP_DEBUG("   inst:%08x, widgt:%08x, argn:%08x\n",
		Instr_Code, Widget_Type, Attribute_Number);
#ifdef DEBUG
	print_token(Token);
#endif
	
	//print_command(command);
	
	if (Attr == NULL)
		Attr = attributeset_new();

	switch (Instr_Code) {
	case PUSH:
		/* These instructions will push widgets into the stack, some
		 ** of them will remove elements from it.
		 */
		instruction_execute_push(Token, Attr, command.tag_attributes);
		variables_refresh(attributeset_get_first(&element, Attr, ATTR_VARIABLE));
		Attr = NULL;
		break;
	case SET:
		/* 
		 ** SET instructions stores strings in the attributes.
		 */
		attributeset_insert_with_tagattrs(Attr, 
				    Attribute_Number, 
				    Argument,
				    command.tag_attributes);
		break;
	case SUM:
		/*
		 ** This instruction will add the to uppermost stack element and
		 ** push the result to the stack, so the upper element will 
		 ** contain all the widgets.
		 */
		push(_sum(pop(), pop()));
		break;
	/*
	 * The imperative instructions.
	 */
	case IMASSG:
		{
		/*
		 * FIXME: I'm working on this now.
		 */
		stackelement s;
		s = pop();
		g_message("  -> %s := '%s'", Argument, s.cval);
		g_setenv(Argument, s.cval, TRUE);
		}
		break;
	case IMPUSH:
		switch (Widget_Type) {
			case VARIABLE_NAME:
				{
				printf("(variable '%s')", Argument);
			    	}
			    break;
			case CONST_NUMBER:
			    printf("(number '%s')", Argument);
			    break;
			case OP_ADD:
			    printf("(pop() + pop())", Argument);
			    break;
			case OP_SUBST:
			    printf("(pop() - pop())", Argument);
			    break;
			case OP_MULT:
			    printf("(pop() * pop())", Argument);
			    break;
			case OP_DIV:
			    printf("(pop() / pop())", Argument);
			    break;
			case REL_EQ:
			    printf("(pop() = pop())", Argument);
			    break;
			case REL_NE:
			    printf("(pop() != pop())", Argument);
			    break;
			default:
			    printf("(Unknown Parameter: %d)", Widget_Type);
			}
		break;
	case SHOW:
		show_without_pop(window);
		break;
	case IFNGOTO:
		g_warning("Not implemented");
		break;
	case GOTO:
		g_warning("Not implemented");
		break;
	default:
		if (!option_no_warning)
			g_warning("%s(): Unknown instruction.", __func__);
	}

	PIP_DEBUG("Instruction executed.");
	return 0;
}

/***********************************************************************
 * Put in the Scrolled Window                                          *
 ***********************************************************************/
/* Places the widget into a scrolled window */

static GtkWidget *put_in_the_scrolled_window(GtkWidget *widget,
	AttributeSet *Attr, tag_attr *attr, gint Type)
{
	GList            *element;
	GtkWidget        *scrolledwindow;
	gchar            *value;
	gint              width = -1;
	gint              height = -1;
	gint              hscrollbar_policy = GTK_POLICY_AUTOMATIC;
	gint              vscrollbar_policy = GTK_POLICY_AUTOMATIC;
	gint              xpad;
	gint              ypad;
	glong             char_height;
	glong             char_width;
#if HAVE_VTE
#if 0 //#if VTE_CHECK_VERSION(0,26,0)
	GtkBorder         inner_border;
#endif
#endif

	g_assert(widget != NULL);

	/* Create the scrolled window */
	scrolledwindow = gtk_scrolled_window_new(NULL, NULL);

	/* Set the scrollbar policy for the scrollbars */
	if (Type == WIDGET_TERMINAL) {
		/* Get scrollbar policy from custom tag attributes */
		if (attr) {
			if ((value = get_tag_attribute(attr, "hscrollbar-policy")) ||
				(value = get_tag_attribute(attr, "hscrollbar_policy")))
				hscrollbar_policy = atoi(value);
			if ((value = get_tag_attribute(attr, "vscrollbar-policy")) ||
				(value = get_tag_attribute(attr, "vscrollbar_policy")))
				vscrollbar_policy = atoi(value);
		}
	}
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolledwindow), 
		hscrollbar_policy, vscrollbar_policy);

	/* Get dimensions from directives */
	if (attributeset_is_avail(Attr, ATTR_WIDTH))
		width = atoi(attributeset_get_first(&element, Attr, ATTR_WIDTH));
	if (attributeset_is_avail(Attr, ATTR_HEIGHT))
		height = atoi(attributeset_get_first(&element, Attr, ATTR_HEIGHT));

	/* Set scrolled window size */
	switch (Type) {
		case WIDGET_HBOX:
		case WIDGET_VBOX:
			/* Get dimensions from custom tag attributes */
			if (attr) {
				if (value = get_tag_attribute(attr, "width"))
					width = atoi(value);
				if (value = get_tag_attribute(attr, "height"))
					height = atoi(value);
			}
			/* Set some defaults */
			if (width == -1) width = 200;
			if (height == -1) height = 100;
			/* Set the size */
			gtk_widget_set_usize(scrolledwindow, width, height);
			/* Pack the widget */
			gtk_scrolled_window_add_with_viewport(
				GTK_SCROLLED_WINDOW(scrolledwindow), widget);
			break;
		case WIDGET_TERMINAL:
#if HAVE_VTE
			/* VTE is telling me that vte_terminal_get_padding() has been
			 * deprecated since 0.26 and that I should get 'inner-border'
			 * but GLib is telling me that 'VteTerminal' has no property
			 * named 'inner-border' so I have to go with the deprecated
			 * vte_terminal_get_padding() */
#if 0 //#if VTE_CHECK_VERSION(0,26,0)
			g_object_get(G_OBJECT(widget), "inner-border", &inner_border, NULL);
#ifdef DEBUG_CONTENT
			fprintf(stderr, "%s:() inner_border.left=%i inner_border.right=%i \
inner_border.top=%i inner_border.bottom=%i\n", __func__, inner_border.left,
				inner_border.right, inner_border.top, inner_border.bottom);
#endif
			xpad = inner_border.left + inner_border.right;
			ypad = inner_border.top + inner_border.bottom;
#else
			vte_terminal_get_padding(VTE_TERMINAL(widget), &xpad, &ypad);
#endif
			char_width = vte_terminal_get_char_width(VTE_TERMINAL(widget));
			char_height = vte_terminal_get_char_height(VTE_TERMINAL(widget));
#ifdef DEBUG_CONTENT
			fprintf(stderr, "%s:() xpad=%i ypad=%i char_width=%li char_height=%li\n",
				__func__, xpad, ypad, char_width, char_height);
#endif
			if (width != -1) width = width * char_width + xpad;
			if (height != -1) height = height * char_height + ypad;
			/* Set some defaults */
			if (width == -1) width = 80 * char_width + xpad;
			if (height == -1) height = 25 * char_height + ypad;
			/* Set the size */
			gtk_widget_set_usize(scrolledwindow, width, height);
			/* Pack the widget */
			gtk_container_add(GTK_CONTAINER(scrolledwindow), widget);
			break;
#endif
		default:
			/* Set some defaults */
			if (width == -1) width = 200;
			if (height == -1) height = 100;
			/* Set the size */
			gtk_widget_set_usize(scrolledwindow, width, height);
			/* Pack the widget */
			if (Type == WIDGET_LIST || Type == WIDGET_TERMINAL) {
				gtk_scrolled_window_add_with_viewport(
					GTK_SCROLLED_WINDOW(scrolledwindow), widget);
			} else {
				gtk_container_add(GTK_CONTAINER(scrolledwindow), widget);
			}
			break;
	}

/* Redundant
	if (attributeset_is_avail(Attr, ATTR_HEIGHT) && 
			attributeset_is_avail(Attr, ATTR_WIDTH)) {
		gtk_widget_set_usize(scrolledwindow, 
			atoi(attributeset_get_first(&element, Attr, ATTR_WIDTH)),
			atoi(attributeset_get_first(&element, Attr, ATTR_HEIGHT)));
	} else if (attributeset_is_avail(Attr, ATTR_HEIGHT)) {
		gtk_widget_set_usize(scrolledwindow, 
			-1,
			atoi(attributeset_get_first(&element, Attr, ATTR_HEIGHT)));
	} else if (attributeset_is_avail(Attr, ATTR_WIDTH)) {
		gtk_widget_set_usize(scrolledwindow, 
			atoi(attributeset_get_first(&element, Attr, ATTR_WIDTH)),
			-1);
	} else if (GTK_IS_HBOX(widget) || GTK_IS_VBOX(widget)) {
		/$ These widgets before 0.8.1 didn't support directives so these
		 * values had to come from custom tag atributes which application
		 * developers will still be using $/
		if (attr) {
			if (value = get_tag_attribute(attr, "width"))
				width = atoi(value);
			if (value = get_tag_attribute(attr, "height"))
				height = atoi(value);
		}
		gtk_widget_set_usize(scrolledwindow, width, height);
	} else {
		gtk_widget_set_usize(scrolledwindow, SW_DEFAULT_WIDTH, SW_DEFAULT_HEIGHT);
	}

	/$ Packing the widget, possibly with a viewport $/
	if (GTK_IS_LIST(widget) || GTK_IS_HBOX(widget) || GTK_IS_VBOX(widget)) {
		gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolledwindow), 
			widget);
	} else {
		gtk_container_add(GTK_CONTAINER(scrolledwindow), widget);
	}
*/

	return scrolledwindow;
}

static
GtkWidget *create_menuitem(AttributeSet *Attr, tag_attr *attr)
{
	#define           TYPE_MENUITEM 0
	#define           TYPE_MENUITEM_IMAGE_STOCK 1
	#define           TYPE_MENUITEM_IMAGE_ICON 2
	#define           TYPE_MENUITEM_IMAGE_FILE 3
	#define           TYPE_MENUITEM_CHECK 4
	#define           TYPE_MENUITEM_RADIO 5
	GList            *element;
	GtkWidget        *menu_item;
	gchar            *icon_name, *image_name;
	GtkIconTheme     *icon_theme;
	GError           *error = NULL;
	GdkPixbuf        *pixbuf;
	GtkWidget        *image;
	GtkAccelGroup    *accel_group = NULL;
	gchar             accel_path[64];
	guint             accel_key = 0, accel_mods = 0, custom_accel = 0;
	gchar            *label, *stock_id, *value;
	gint              width = -1, height = -1, is_active;
	gint              size = 16;
	gint              menuitemtype = TYPE_MENUITEM;

	PIP_DEBUG("");

	/* Read declared directives */
	attributeset_set_if_unset(Attr, ATTR_LABEL, "menuitem");
	label = attributeset_get_first(&element, Attr, ATTR_LABEL);
	if (attributeset_is_avail(Attr, ATTR_WIDTH))
		width = atoi(attributeset_get_first(&element, Attr, ATTR_WIDTH));
	if (attributeset_is_avail(Attr, ATTR_HEIGHT))
		height = atoi(attributeset_get_first(&element, Attr, ATTR_HEIGHT));

	/* Thunor: We can add an accelerator for this menuitem if both
	 * "accel-key" and "accel-mods" are valid custom tag attributes.
	 * Note that because these widgets are created and pushed when the
	 * end tags are detected, everything gets done in reverse! So here
	 * the menuitems are created with possibly an accelerator, then
	 * when the menu end tag is detected the menu and accelerator group
	 * are created and finally the menuitems are appended to the menu */
	if (attr) {
		if (!(value = get_tag_attribute(attr, "accel_key")))
			value = get_tag_attribute(attr, "accel-key");
		if (value) {
			/* Read accel-key as a decimal integer or hex value */
			if (strncasecmp(value, "0x", 2) == 0) {
				sscanf(value, "%x", &accel_key);
			} else {
				sscanf(value, "%u", &accel_key);
			}
			if (!(value = get_tag_attribute(attr, "accel_mods")))
				value = get_tag_attribute(attr, "accel-mods");
			if (value) {
				/* Read accel-mods as a decimal integer or hex value */
				if (strncasecmp(value, "0x", 2) == 0) {
					sscanf(value, "%x", &accel_mods);
				} else {
					sscanf(value, "%u", &accel_mods);
				}
				/* Create a random accel-path (yeah, this is fine) */
				sprintf(accel_path, "<%i>/%i", rand(), rand());
				custom_accel = TRUE;
			}
		}
	}

#ifdef DEBUG
	fprintf(stderr, "%s: accel-path=%s\n", __func__, accel_path);
	fprintf(stderr, "%s: accel-key=%u\n", __func__, accel_key);
	fprintf(stderr, "%s: accel-mods=%u\n", __func__, accel_mods);
#endif

	/* We need to decode exactly what it is the user is trying to create
	 * and then make the right widget.
	 * 
	 * Originally as I couldn't use "stock", "icon" and "image" (image
	 * is a GTK+ property) I decided to make the meaningful names of
	 * "image-stock", "image-icon" and "image-file", but then I found that
	 * "stock[_id]" and "icon[_name]" were already being used within the
	 * tree widget (I missed that) so I'll document the latter but accept
	 * everything below (I'll have to now as they're likely being used) */
	if (attr &&
		(stock_id = get_tag_attribute(attr, "label")) &&
		((value = get_tag_attribute(attr, "use-stock")) &&
		((strcasecmp(value, "true") == 0) ||
		(strcasecmp(value, "yes") == 0) || (atoi(value) == 1)))) {
		menuitemtype = TYPE_MENUITEM_IMAGE_STOCK;
	} else if (attr &&
		((stock_id = get_tag_attribute(attr, "stock")) ||
		(stock_id = get_tag_attribute(attr, "stock_id")) ||
		(stock_id = get_tag_attribute(attr, "stock-id")) ||
		(stock_id = get_tag_attribute(attr, "image_stock")) ||	/* I don't want to keep this temp temp */
		(stock_id = get_tag_attribute(attr, "image-stock")))) {	/* I don't want to keep this temp temp */
		menuitemtype = TYPE_MENUITEM_IMAGE_STOCK;
	} else if (attr &&
		((icon_name = get_tag_attribute(attr, "icon")) ||
		(icon_name = get_tag_attribute(attr, "icon_name")) ||
		(icon_name = get_tag_attribute(attr, "icon-name")) ||
		(icon_name = get_tag_attribute(attr, "image_icon")) ||	/* I don't want to keep this temp temp */
		(icon_name = get_tag_attribute(attr, "image-icon")))) {	/* I don't want to keep this temp temp */
		menuitemtype = TYPE_MENUITEM_IMAGE_ICON;
	} else if (attr &&
		((image_name = get_tag_attribute(attr, "image_name")) ||
		(image_name = get_tag_attribute(attr, "image-name")) ||
		(image_name = get_tag_attribute(attr, "image_file")) ||	/* I don't want to keep this temp temp */
		(image_name = get_tag_attribute(attr, "image-file")))) {	/* I don't want to keep this temp temp */
		menuitemtype = TYPE_MENUITEM_IMAGE_FILE;
	} else if (attr &&
		(value = get_tag_attribute(attr, "checkbox"))) {
		menuitemtype = TYPE_MENUITEM_CHECK;
	} else if (attr &&
		(value = get_tag_attribute(attr, "radiobutton"))) {
		menuitemtype = TYPE_MENUITEM_RADIO;
	} else {
		menuitemtype = TYPE_MENUITEM;
	}

	/* Create the menuitem */
	switch (menuitemtype) {
		case TYPE_MENUITEM_IMAGE_STOCK:
			/* Create the GtkImageMenuItem from stock without stock
			 * accelerator */
			menu_item = gtk_image_menu_item_new_from_stock(stock_id, NULL);
#if 0
			/* Thunor: Unfortunately I can't enable stock accelerators
			 * by default as all existing applications will then get key
			 * combinations redirected to menuitems which might have
			 * unforseen consequences, but I'll leave this here anyway */

			/* Who is going to set the accelerator? */
			if (custom_accel) {
				/* Create the GtkImageMenuItem from stock without stock
				 * accelerator */
				menu_item = gtk_image_menu_item_new_from_stock(stock_id, NULL);
			} else {
				/* Create an accelerator group for this stock item and
				 * add it to the accelerator groups list which will get
				 * added to the window later */
				accel_group = gtk_accel_group_new();
				accel_groups = g_list_append(accel_groups, accel_group);
				/* Create the GtkImageMenuItem from stock with stock accelerator */
				menu_item = gtk_image_menu_item_new_from_stock(stock_id, accel_group);
			}
#endif
			break;
		case TYPE_MENUITEM_IMAGE_ICON:
			icon_theme = gtk_icon_theme_get_default();
			/* Use the height or width dimension to override the default size */
			if (height > -1) size = height;
			else if (width > -1) size = width;
			pixbuf = gtk_icon_theme_load_icon(icon_theme, icon_name,
				size, 0, &error);
			if (pixbuf) {
				image = gtk_image_new_from_pixbuf(pixbuf);
				/* pixbuf is no longer required and should be unreferenced */
				g_object_unref(pixbuf);
			} else {
				/* pixbuf is null (file not found) so by using this
				 * function gtk will substitute a broken image icon */
				image = gtk_image_new_from_file("");
			}
			/* Create the GtkImageMenuItem using an image from the theme */
			menu_item = gtk_image_menu_item_new_with_label(label);
			gtk_image_menu_item_set_image(GTK_IMAGE_MENU_ITEM(menu_item), image);
			break;
		case TYPE_MENUITEM_IMAGE_FILE:
			if (width == -1 && height == -1) {
				/* Handle unscaled images */
				image = gtk_image_new_from_file(find_pixmap(image_name));
			} else {
				/* Handle scaled images */
				pixbuf = gdk_pixbuf_new_from_file_at_size(
					find_pixmap(image_name), width, height, NULL);
				if (pixbuf) {
					image = gtk_image_new_from_pixbuf(pixbuf);
					/* pixbuf is no longer required and should be unreferenced */
					g_object_unref(pixbuf);
				} else {
					/* pixbuf is null (file not found) so by using this
					* function gtk will substitute a broken image icon */
					image = gtk_image_new_from_file("");
				}
			}
			/* Create the GtkImageMenuItem using an image from a file */
			menu_item = gtk_image_menu_item_new_with_label(label);
			gtk_image_menu_item_set_image(GTK_IMAGE_MENU_ITEM(menu_item), image);
			break;
		case TYPE_MENUITEM_CHECK:
			/* Create the GtkCheckMenuItem */
			menu_item = gtk_check_menu_item_new_with_label(label);
			/* Get the active state */
			if ((strcasecmp(value, "true") == 0) ||
				(strcasecmp(value, "yes") == 0) || (atoi(value) == 1)) {
				is_active = 1;
			} else {
				is_active = 0;
			}
			/* Set the active state */
			gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu_item), is_active);
			break;
		case TYPE_MENUITEM_RADIO:
			/* Create the GtkRadioMenuItem */
			if (lastradiowidget == NULL) {
				menu_item = gtk_radio_menu_item_new_with_label(NULL, label);
				lastradiowidget = menu_item;
			} else {
				menu_item = gtk_radio_menu_item_new_with_label_from_widget(
					GTK_RADIO_MENU_ITEM(lastradiowidget), label);
			}
			/* Get the active state */
			if ((strcasecmp(value, "true") == 0) ||
				(strcasecmp(value, "yes") == 0) || (atoi(value) == 1)) {
				is_active = 1;
			} else {
				is_active = 0;
			}
			/* Set the active state (yeah, it uses the same base class function) */
			gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu_item), is_active);
			break;
		case TYPE_MENUITEM:
		default:
			/* Create the GtkMenuItem */
			menu_item = gtk_menu_item_new_with_label(label);
			break;
	}

	/* Are we setting an accelerator? */
	if (custom_accel) {
		/* Register and set the accelerator path on the menuitem */
		gtk_accel_map_add_entry(accel_path, accel_key, accel_mods);
		gtk_menu_item_set_accel_path(GTK_MENU_ITEM(menu_item), accel_path);
	}

	return menu_item;
}

static
GtkWidget *create_menu(AttributeSet *Attr, tag_attr *attr, stackelement items)
{
	GList            *element;
	GtkAccelGroup    *accel_group;
	GtkWidget        *menu_items;
	GtkWidget        *root_menu;
	GtkWidget        *menu;
	gchar            *label;
	gint              n;

	menu = gtk_menu_new();

	/* Thunor: Each menu needs an accelerator group which requires adding
	 * to the window, but because everything is being done in reverse i.e.
	 * the window is created last, the accel-groups have to be temporarily
	 * stored within a list for adding later when the window is created */
	accel_group = gtk_accel_group_new();
	gtk_menu_set_accel_group(GTK_MENU(menu), accel_group);
	accel_groups = g_list_append(accel_groups, accel_group);
#ifdef DEBUG
	fprintf(stderr, "%s: Appending accel_group=%p to GList\n",
		__func__, accel_group);
#endif

	for (n = 0; n < items.nwidgets; ++n){
		menu_items = items.widgets[n];
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_items);
	}

	attributeset_set_if_unset(Attr, ATTR_LABEL, "menu");
	//Redundant: label = attributeset_get_first(&element, Attr, ATTR_LABEL);

	/* Thunor: A menu widget is in fact a menuitem widget with a submenu
	 * so it'll be created just like any other menuitem widget. It's
	 * possible to create image, checkbox or radiobutton menu widgets but
	 * their usefulness is questionable. In fact creating a menu widget
	 * closes any open radiobutton group so that makes that pointless */
	root_menu = create_menuitem(Attr, attr);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(root_menu), menu);

	return root_menu;
}

static
gboolean widget_moved(GtkWidget *widget,
                      GdkEvent *event,
                      gpointer user_data){
	GtkRequisition size;
	GtkWindow *window = user_data;
	GdkEventType type;
	GdkEventConfigure  *configure;
	
	type = event->type;
	
	if (type == 2)
		return FALSE;
#if 0
	fprintf(stderr, "%s(): event->type: %d mask %x.\n", __func__, 
			type,
			gtk_widget_get_events(widget)
			);
#endif	
  	if (type == GDK_EXPOSE ){
		return FALSE;
	}
	
	if (type == GDK_CONFIGURE){
		configure = (GdkEventConfigure *)event;
#if 0
		printf("   ->x = %d y = %d dx = %d dy = %d\n", 
				configure->x,
				configure->y,
				configure->width,
				configure->height);
#endif
		//gtk_widget_set_usize(window, 
		//		configure->width -20,
		//		configure->height);
		gtk_widget_set_uposition(GTK_WIDGET(window), 
				configure->x,
				configure->y);
	}
	
	fflush(stderr);

	return FALSE;
}

static GtkWidget *
create_gvim(AttributeSet * Attr)
{
	GtkWidget *Window = gtk_window_new(GTK_WINDOW_POPUP);
	GtkWidget *socket = gtk_socket_new();
	GtkWidget *fake = gtk_drawing_area_new();
	gtk_widget_set_events(fake, GDK_ALL_EVENTS_MASK);
	gtk_widget_set_extension_events (fake,
			GDK_EXTENSION_EVENTS_ALL);
	char socket_id[32];

	//gtk_window_set_transient_for(Window, window);
	gtk_widget_set_usize(Window, 350, 150);
	gtk_widget_set_usize(fake, 350, 150);
	
	gtk_container_add (GTK_CONTAINER (Window), socket);
	gtk_widget_show (socket);
	gtk_widget_show (Window);
	gtk_widget_realize (socket);
	sprintf(socket_id, "%d", gtk_socket_get_id (GTK_SOCKET(socket)));
	attributeset_set_if_unset(Attr, ATTR_SOCKET, socket_id); 
	//
	// 
	//
	//gtk_widget_add_events(fake, GDK_ALL_EVENTS_MASK);
	//g_signal_connect(G_OBJECT(fake), "configure-event",
	//		 widget_moved, Window);
	g_signal_connect(G_OBJECT(window), "configure-event",
			 (GCallback)widget_moved, Window);
	//g_signal_connect(G_OBJECT(window), "event",
	//		 widget_moved, Window);
	return fake;
}

#if GTK_CHECK_VERSION(2,4,0)
static GtkWidget *
create_chooser(AttributeSet *Attr)
{
	GList     *element;
	GtkWidget *chooser;
	char      *act;
	char      *tagattr_value;

	PIP_DEBUG("");
/*
	GTK_FILE_CHOOSER_ACTION_OPEN	
	Indicates open mode. The file chooser will only let the user
	pick an existing file.

	GTK_FILE_CHOOSER_ACTION_SAVE	
	Indicates save mode. The file chooser will let the user pick
	an existing file, or type in a new filename.

	GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER	
	Indicates an Open mode for selecting folders. The
	file chooser will let the user pick an existing folder.

	GTK_FILE_CHOOSER_ACTION_CREATE_FOLDER	
	Indicates a mode for creating a new folder. The file
	chooser will let the user name an existing or new folder.
*/
	chooser = gtk_file_chooser_widget_new(GTK_FILE_CHOOSER_ACTION_OPEN); 
	if (attributeset_is_avail(Attr, ATTR_HEIGHT) &&
	    attributeset_is_avail(Attr, ATTR_WIDTH))
		gtk_widget_set_usize(chooser, 
				atoi(attributeset_get_first(&element, Attr, ATTR_WIDTH)),
				atoi(attributeset_get_first(&element, Attr, ATTR_HEIGHT)));
	
	if (attributeset_is_avail(Attr, ATTR_DEFAULT))
		gtk_file_chooser_set_current_folder((GtkFileChooser *)chooser, 
				attributeset_get_first(&element, Attr, ATTR_DEFAULT));
	
	act = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (act != NULL) {
		tagattr_value = attributeset_get_this_tagattr(&element, Attr,
			ATTR_ACTION, "when");
		if (tagattr_value == NULL)
			tagattr_value = "file-activated";
		
		gtk_signal_connect(GTK_OBJECT(chooser),
				   tagattr_value,
				   GTK_SIGNAL_FUNC
				   (button_pressed), (gpointer) act);
		act = attributeset_get_next(&element, Attr, ATTR_ACTION);
	}

	//gtk_file_chooser_set_preview_widget_active(chooser, TRUE);
	return chooser;
}
#endif


/*****************************************************************************
 * List handling functions.                                                  *
 *                                                                           *
 *****************************************************************************/
static GtkWidget *
create_list(AttributeSet   *Attr,
		tag_attr   *attr)
{
	GtkWidget *widget;
	
	widget = gtk_list_new();
	return widget;
}

static GtkWidget *
create_table(AttributeSet   *Attr,
		tag_attr   *attr)
{
	GList *element;
	GtkWidget *widget;
	
	list_t *table_header;
	if (attributeset_is_avail(Attr, ATTR_LABEL)) {
		table_header =
		linecutter(attributeset_get_first(&element, Attr, ATTR_LABEL), '|');
		widget=gtk_clist_new_with_titles
				    (table_header->n_lines,
				     table_header->line);
	} else {
		widget = gtk_clist_new(1);
	}
	
	return widget;
}


static GtkWidget *
create_edit(AttributeSet *Attr, 
		tag_attr   *attr)
{
	GList         *element;
	GtkWidget     *text_view;
	GtkTextBuffer *text_buffer;
	/*
	 * Creating text view.
	 */
	text_view = gtk_text_view_new();
	text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

	if ((attributeset_cmp_left(Attr, ATTR_SENSITIVE, "false")) ||
		(attributeset_cmp_left(Attr, ATTR_SENSITIVE, "disabled")) ||	/* Deprecated */
		(attributeset_cmp_left(Attr, ATTR_SENSITIVE, "no")) ||
		(attributeset_cmp_left(Attr, ATTR_SENSITIVE, "0")))
		gtk_widget_set_sensitive(text_view, FALSE);
 
	if (attributeset_is_avail(Attr, ATTR_DEFAULT))
		gtk_text_buffer_set_text(text_buffer, 
				attributeset_get_first(&element, Attr, ATTR_DEFAULT), -1);

	return text_view;
}

static GtkWidget *
create_scale(AttributeSet * Attr, tag_attr *attr, gint horv)
{
	GtkWidget        *scale;
	gdouble           range_min = 0;
	gdouble           range_max = 100;
	gdouble           range_step = 1;
	gdouble           range_value = 0;
	gchar            *value;

	/* Thunor: These "range-*" names are consistent with the spinbutton widget */
	if (attr) {
		if (!(value = get_tag_attribute(attr, "range_min")) &&
			!(value = get_tag_attribute(attr, "range-min")) &&
			!(value = get_tag_attribute(attr, "scale_min")))
			value = get_tag_attribute(attr, "scale-min");
		if (value) range_min = atof(value);

		if (!(value = get_tag_attribute(attr, "range_max")) &&
			!(value = get_tag_attribute(attr, "range-max")) &&
			!(value = get_tag_attribute(attr, "scale_max")))
			value = get_tag_attribute(attr, "scale-max");
		if (value) range_max = atof(value);

		if (!(value = get_tag_attribute(attr, "range_step")) &&
			!(value = get_tag_attribute(attr, "range-step")) &&
			!(value = get_tag_attribute(attr, "scale_step")))
			value = get_tag_attribute(attr, "scale-step");
		if (value) range_step = atof(value);

		if (!(value = get_tag_attribute(attr, "range_value")) &&
			!(value = get_tag_attribute(attr, "range-value")) &&
			!(value = get_tag_attribute(attr, "scale_value")))
			value = get_tag_attribute(attr, "scale-value");
		if (value) range_value = atof(value);
	}

	if (!horv) {
		scale = gtk_hscale_new_with_range(range_min, range_max, range_step);
	} else {
		scale = gtk_vscale_new_with_range(range_min, range_max, range_step);
	}
	gtk_range_set_value(GTK_RANGE(scale), range_value);

	return scale;
}

static gint 
instruction_execute_push(
		token          Token, 
		AttributeSet  *Attr,
		tag_attr      *tag_attributes)
{
	GList            *element;
	GtkWidget        *scrolled_window;	
	GtkWidget        *OtherWidget;
	GtkWidget        *Widget;
	variable         *var;
	gint              Widget_Type, n, border_width;
	gchar            *value;
	GList            *accel_group = NULL;
	gint              original_expand, original_fill;
	gint              space_expand, space_fill;

	PIP_DEBUG("token: %d", Token);
	
	Widget_Type = Token & WIDGET_TYPE;

	switch (Widget_Type) {
		case WIDGET_CANCELBUTTON:
		case WIDGET_HELPBUTTON:
		case WIDGET_NOBUTTON:
		case WIDGET_OKBUTTON:
		case WIDGET_YESBUTTON:
		case WIDGET_TOGGLEBUTTON:
		case WIDGET_BUTTON:
			Widget = widget_button_create(Attr, tag_attributes, Widget_Type);
			push_widget(Widget, Widget_Type);
			break;
		case WIDGET_CHECKBOX:
			Widget = widget_checkbox_create(Attr, tag_attributes, Widget_Type);
			push_widget(Widget, Widget_Type);
			break;
		case WIDGET_COLORBUTTON:
			Widget = widget_colorbutton_create(Attr, tag_attributes, Widget_Type);
			push_widget(Widget, Widget_Type);
			break;
		case WIDGET_COMBOBOXENTRY:
		case WIDGET_COMBOBOXTEXT:
			Widget = widget_comboboxtext_create(Attr, tag_attributes, Widget_Type);
			push_widget(Widget, Widget_Type);
			break;
		case WIDGET_FONTBUTTON:
			Widget = widget_fontbutton_create(Attr, tag_attributes, Widget_Type);
			push_widget(Widget, Widget_Type);
			break;
		case WIDGET_FRAME:
			Widget = widget_frame_create(Attr, tag_attributes, Widget_Type);
			push_widget(Widget, Widget_Type);
			/* Creating this widget closes any open group */
			lastradiowidget = NULL;
			break;
		case WIDGET_HBOX:
			Widget = widget_hbox_create(Attr, tag_attributes, Widget_Type);
			/* Thunor: If the custom attribute "scrollable" is true
			 * then place the hbox inside a GtkScrolledWindow */
			if (tag_attributes &&
				(value = get_tag_attribute(tag_attributes, "scrollable")) &&
				((strcasecmp(value, "true") == 0) ||
				(strcasecmp(value, "yes") == 0) || (atoi(value) == 1))) {
				scrolled_window = put_in_the_scrolled_window(Widget, Attr,
					tag_attributes, Widget_Type);
				push_widget(scrolled_window, WIDGET_SCROLLEDW);
			} else {
				push_widget(Widget, Widget_Type);
			}
			/* Creating this widget closes any open group */
			lastradiowidget = NULL;
			break;
		case WIDGET_MENUBAR:
			Widget = widget_menubar_create(Attr, tag_attributes, Widget_Type);
			push_widget(Widget, Widget_Type);
			/* Creating this widget closes any open group */
			lastradiowidget = NULL;
			break;
		case WIDGET_NOTEBOOK:
			Widget = widget_notebook_create(Attr, tag_attributes, Widget_Type);
			push_widget(Widget, Widget_Type);
			/* Creating this widget closes any open group */
			lastradiowidget = NULL;
			break;
		case WIDGET_PIXMAP:
			Widget = widget_pixmap_create(Attr, tag_attributes, Widget_Type);
			push_widget(Widget, Widget_Type);
			break;
		case WIDGET_RADIOBUTTON:
			Widget = widget_radiobutton_create(Attr, tag_attributes, Widget_Type);
			push_widget(Widget, Widget_Type);
			break;
		case WIDGET_SPINBUTTON:
			Widget = widget_spinbutton_create(Attr, tag_attributes, Widget_Type);
			push_widget(Widget, Widget_Type);
			break;
		case WIDGET_STATUSBAR:
			Widget = widget_statusbar_create(Attr, tag_attributes, Widget_Type);
			push_widget(Widget, Widget_Type);
			break;
		case WIDGET_TERMINAL:
			Widget = widget_terminal_create(Attr, tag_attributes, Widget_Type);
			scrolled_window = put_in_the_scrolled_window(Widget, Attr,
				tag_attributes, Widget_Type);
			push_widget(scrolled_window, WIDGET_SCROLLEDW);
			break;
		case WIDGET_TEXT:
			Widget = widget_text_create(Attr, tag_attributes, Widget_Type);
			push_widget(Widget, Widget_Type);
			break;
		case WIDGET_TIMER:
			Widget = widget_timer_create(Attr, tag_attributes, Widget_Type);
			push_widget(Widget, Widget_Type);
			break;
#if GTK_CHECK_VERSION(2,4,0)
		case WIDGET_TREE:
			Widget = widget_tree_create(Attr, tag_attributes, Widget_Type);
			scrolled_window = put_in_the_scrolled_window(Widget, Attr,
				tag_attributes, Widget_Type);
			push_widget(scrolled_window, WIDGET_SCROLLEDW);
			break;
#endif
		case WIDGET_VBOX:
			Widget = widget_vbox_create(Attr, tag_attributes, Widget_Type);
			/* Thunor: If the custom attribute "scrollable" is true
			 * then place the vbox inside a GtkScrolledWindow */
			if (tag_attributes &&
				(value = get_tag_attribute(tag_attributes, "scrollable")) &&
				((strcasecmp(value, "true") == 0) ||
				(strcasecmp(value, "yes") == 0) || (atoi(value) == 1))) {
				scrolled_window = put_in_the_scrolled_window(Widget, Attr,
					tag_attributes, Widget_Type);
				push_widget(scrolled_window, WIDGET_SCROLLEDW);
			} else {
				push_widget(Widget, Widget_Type);
			}
			/* Creating this widget closes any open group */
			lastradiowidget = NULL;
			break;
		case WIDGET_WINDOW:
			Widget = window = widget_window_create(Attr, tag_attributes, Widget_Type);
			push_widget(Widget, Widget_Type);
			break;


	case WIDGET_ENTRY:
		/*
		 ** Creating the widget, and pushing it into the stack.
		 */
		Widget = gtk_entry_new();
		push_widget(Widget, Widget_Type);
		break;

	case WIDGET_CHOOSER:
		/* Thunor: This widget is incredibly lacking in comparison to
		 * the fileselect action function and really needs a newer
		 * alternative (is anyone actually using this?) */
#if GTK_CHECK_VERSION(2,4,0)
		Widget = create_chooser(Attr);
		push_widget(Widget, Widget_Type);
#else
		yyerror_simple("Chooser widget is not supported by"
				"this version of GTK+, you need at"
				"least GTK+ 2.4.0\n");
#endif
		break;
		
	case WIDGET_EDIT:
#if GTK_CHECK_VERSION(2, 4, 0)
		Widget = create_edit(Attr, tag_attributes);
		scrolled_window = put_in_the_scrolled_window(Widget, Attr,
			tag_attributes, Widget_Type);
		push_widget(scrolled_window, WIDGET_SCROLLEDW);
		
#else
		yyerror_simple("Editor widget is not supported by"
				"this version of GTK+, you need at"
				"least GTK+ 2.4.0\n");
#endif
		break;

	case WIDGET_COMBO:
		/* The combo box is quiet simple, however it can be filled with
		 ** a GList which contains a list of items.
		 */
		//Widget = gtk_combo_box_new();
		Widget = gtk_combo_new();

		if ((attributeset_cmp_left(Attr, ATTR_SENSITIVE, "false")) ||
			(attributeset_cmp_left(Attr, ATTR_SENSITIVE, "disabled")) ||	/* Deprecated */
			(attributeset_cmp_left(Attr, ATTR_SENSITIVE, "no")) ||
			(attributeset_cmp_left(Attr, ATTR_SENSITIVE, "0")))
			gtk_widget_set_sensitive(Widget, FALSE);

		push_widget(Widget, Widget_Type);
		break;

	case WIDGET_GVIM:
		Widget = create_gvim(Attr);
		push_widget(Widget, Widget_Type);
		break;
		
	case WIDGET_MENU:
		Widget = create_menu(Attr, tag_attributes, pop());
		push_widget(Widget, Widget_Type);
		/* Creating this widget closes any open group */
		lastradiowidget = NULL;
		break;

	case WIDGET_MENUITEM:
		Widget = create_menuitem(Attr, tag_attributes);
		push_widget(Widget, Widget_Type);
		/* Creating a non radiobutton menuitem widget closes any open group */
		if (!(GTK_IS_RADIO_MENU_ITEM(Widget))) lastradiowidget = NULL;
		break;

	case WIDGET_MENUITEMSEPARATOR:
		Widget = gtk_separator_menu_item_new();
		push_widget(Widget, Widget_Type);
		/* Creating this widget closes any open group */
		lastradiowidget = NULL;
		break;

	case WIDGET_PROGRESS:
		Widget = gtk_progress_bar_new();
		/*
		 *
		 */
		if (attributeset_is_avail(Attr, ATTR_LABEL)) {
			char *t;
			t = attributeset_get_first(&element, Attr, ATTR_LABEL);
			gtk_progress_bar_set_text(GTK_PROGRESS_BAR(Widget), t);
		}
		/*
		 * We start the input command in a separate thread when the
		 * widget gets realized.
		 */
		g_signal_connect(G_OBJECT(Widget),
				"realize",
				(GCallback)on_any_progress_bar_realized,
				(gpointer) Attr);

		push_widget(Widget, WIDGET_PROGRESS);
		break;

	case WIDGET_LIST:
		/* 
		 * When we have create a new LIST widget, we also have to make
		 * GtkScrolledWindow, because this is the only way we can 
		 * scroll in the list. We put the _scrolled window_ into the 
		 * stack, because this holds the list.
		 */
		Widget = create_list(Attr, tag_attributes);
		scrolled_window = put_in_the_scrolled_window(Widget, Attr,
			tag_attributes, Widget_Type);
		push_widget(scrolled_window, WIDGET_SCROLLEDW);
		
		/*
		 ** The LIST widget can handle actions...
		 */
		gtk_signal_connect(GTK_OBJECT(Widget),
						   "selection-changed",
						   GTK_SIGNAL_FUNC
						   (list_selection),
						   (gpointer) Attr);

		break;

	case WIDGET_TABLE:
		/*
		 * When create a new TABLE (clist in gtk) widget, we 
		 * also have to create a GtkScrolledWindow, because this is the 
		 * only way we can scroll in the clist. We put the _scrolled 
		 * window_ into the stack, because this holds the list.  
		 */
		Widget = create_table(Attr, tag_attributes);
		scrolled_window = put_in_the_scrolled_window(Widget, Attr,
			tag_attributes, Widget_Type);
		push_widget(scrolled_window, WIDGET_SCROLLEDW);		
		
		/*
		 ** We need connect the select_row to a function to store the
		 ** selected row.
		 */
		g_signal_connect(G_OBJECT(Widget), "select-row",
				 G_CALLBACK(table_selection),
				 (gpointer) Attr);
		break;

	case WIDGET_HSEPARATOR:
		/* Thunor: My first new widget :) */
		Widget = gtk_hseparator_new();
		push_widget(Widget, Widget_Type);
		break;

	case WIDGET_VSEPARATOR:
		/* Thunor: I'm on a roll now... */
		Widget = gtk_vseparator_new();
		push_widget(Widget, Widget_Type);
		break;

	case WIDGET_HSCALE:
		Widget = create_scale(Attr, tag_attributes, 0);
		/* The directives are applied in the refresh function */
		/* The signals are connected in the refresh function */
		push_widget(Widget, Widget_Type);
		break;

	case WIDGET_VSCALE:
		Widget = create_scale(Attr, tag_attributes, 1);
		/* The directives are applied in the refresh function */
		/* The signals are connected in the refresh function */
		push_widget(Widget, Widget_Type);
		break;

	default:
		if (!option_no_warning)
		g_warning("%s(): Unknown widget type.", __func__);
	}
	
	PIP_DEBUG("Widget created: %p", Widget);
	
	/*
	 ** Now we create a new variable or refresh the old one for this
	 ** new widget.
	 */
	variables_new_with_widget(Attr, tag_attributes, Widget, Widget_Type);

	variables_set_attributes(attributeset_get_first(&element, Attr,
		ATTR_VARIABLE), Attr);

	/*
	 * This is where we set the properties and connect signals 
	 * for the widget.
	 */
	//widget_set_tag_attributes(Widget, tag_attributes);
	g_signal_connect(G_OBJECT(Widget),
				"realize",
				(GCallback)on_any_widget_realized,
				(gpointer) tag_attributes);

	/* Thunor: This is in addition to the widget specific signals that
	 * are generally connected within each widget's refresh function at
	 * start-up. */
	widget_connect_signals(Widget, Attr);

	PIP_DEBUG("Variable created.");

	return 0;
}


/* The next few functions operates on stack
   Miert nem kapja meg az adatokat parameterben es foglalkozik
   a veremmel a hivo?
 */
#ifdef __arm__
/* 120701 BK Puppy Linux forum member jamesbond fixed this for arm cpus...*/
stackelement _sum(stackelement b, stackelement a)
#else
stackelement _sum(stackelement a, stackelement b)
#endif
{
	int n;
	/* Let's copy the widgets from b to a */
	for (n = 0; n < b.nwidgets; ++n) {
		a.widgets[a.nwidgets + n] = b.widgets[n];
		a.widgettypes[a.nwidgets + n] = b.widgettypes[n];
	}
	a.nwidgets += b.nwidgets;
	return a;
}

void _more_memory_needed(void)
{
	void *memory = NULL;

	if (program == NULL) {
		memory_counter = 128;
		memory = malloc(memory_counter * sizeof(instruction));
	} else {
		memory_counter *= 2;
		memory =
		    realloc(program, memory_counter * sizeof(instruction));
	}

	if (memory == NULL) {
		fprintf(stderr, "%s: not enought memory.\n", __func__);
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	fprintf(stderr, "%s: Memory allocated: %d.\n",
		__func__, memory_counter);
#endif

	program = memory;
}

void 
instruction_new(instruction new)
{
	PIP_DEBUG("instruction_counter=%d, memory_counter=%d", 
			instruction_counter, memory_counter);
	
	if (instruction_counter == memory_counter)
		_more_memory_needed();

	program[instruction_counter++] = new;
}

gint
instruction_get_pc(void)
{
	return instruction_counter - 1;
}

void
instruction_set_jump(gint from, gint where)
{
	if (from >= memory_counter)
		g_error("Jump from a nonexistent instruction memory location.");
	program[from].ival = where;
}

/* 
** Functions to store a token in the memory 
*/
int token_store(token command)
{
	instruction inst;
	
	inst.command = command;
	inst.argument = NULL;
	inst.tag_attributes = NULL;
	
	instruction_new(inst);
	return TRUE;
}

int 
token_store_attr(token command, 
		tag_attr *attributes)
{
	instruction inst;
	
	inst.command = command;
	inst.argument = NULL;
	inst.tag_attributes = attributes;
	instruction_new(inst);

	return TRUE;
}

#if 0
gboolean
token_store_with_tag_attributes(
		token command,
		GList *attr)
{
	instruction inst;
	
	inst.command = command;
	inst.argument = NULL;
	inst.tag_attributes = NULL;
	instruction_new(inst);

	return TRUE;
}
#endif

int 
token_store_with_argument_attr(
		token command, 
		const char *argument, 
		tag_attr *attributes)
{
	instruction       inst;
	gint              sub_attribute;
	gint              count, index;

	PIP_DEBUG("Start argument='%s' attributes: %p", argument, attributes);

	/* Thunor: I've added this to convert underscores to hyphens within
	 * signal names declared by the user so that we can deal exclusively
	 * in hyphenated strings throughout the remainder of this program */
	for (count = 0; count < attributes->n; count++) {
		if (g_ascii_strcasecmp(attributes->pairs[count].name, "signal") == 0) {
#ifdef DEBUG
			fprintf(stderr, "%s: Before: pairs[%i].name=%s  pairs[%i].value=%s\n",
				__func__, count, attributes->pairs[count].name,
				count, attributes->pairs[count].value);
#endif
			index = 0;
			while (attributes->pairs[count].value[index]) {
				if (attributes->pairs[count].value[index] == '_')
					attributes->pairs[count].value[index] = '-';
				index++;
			}
#ifdef DEBUG
			fprintf(stderr, "%s:  After: pairs[%i].name=%s  pairs[%i].value=%s\n",
				__func__, count, attributes->pairs[count].name,
				count, attributes->pairs[count].value);
#endif
		}
	}

	inst.tag_attributes = attributes;

	if (argument == NULL)
		argument = "";

	sub_attribute = (command & SUB_ATTRIBUTE) >> 24;
	inst.argument = g_malloc(strlen(argument) + 32);
	switch (sub_attribute) {
	case 0:
		/* 
		 ** No sub_attribute, it is just a normal text.
		 */
		inst.argument = strdup(argument);
		sprintf(inst.argument, "%s", argument);
		break;
	case 1:
		/*
		 ** The text argument is a shell command.
		 */
		sprintf(inst.argument, "Command:%s", argument);
		break;
	case 2:
		/* 
		 ** The text argument is a file name.
		 */
		sprintf(inst.argument, "File:%s", argument);
		break;
	case 3:
		/* 
		 ** The text argument is a widget name which must be
		 ** cleared.
		 */
		sprintf(inst.argument, "Clear:%s", argument);
		break;
	case 4:
		/*
		**
		*/
		sprintf(inst.argument, "Append:%s", argument);
		break;
	case 10:
		/* 
		 ** The text argument is widget name which must be filled with
		 ** a file name from a file selection dialog.
		 */
		sprintf(inst.argument, "Fileselect:%s", argument);
		break;
	case 11:
		/* 
		 ** The text argument is widget name and we have to remove the
		 ** selected element from it.
		 */
		sprintf(inst.argument, "Removeselected:%s", argument);
		break;
	case 12:
		/* 
		 ** The text argument is widget name and we have to remove the
		 ** selected element from it.
		 */
		sprintf(inst.argument, "Refresh:%s", argument);
		break;
	case 13:
		/* 
		 ** The text argument is widget name and we have to
		 ** remove the selected element from it.
		 **  
		 */
		sprintf(inst.argument, "Launch:%s", argument);
		break;
	default:
		fprintf(stderr, "%s(): Warning: Unknown sub-attribute %d",
			__func__, sub_attribute);
		fflush(stderr);
	}
	inst.command = command;
	instruction_new(inst);
	return (0);
	
}

int token_store_with_argument(
		token command, 
		const char *argument)
{
	tag_attr *attributes = new_tag_attributeset(
			strdup("text"),
			strdup(argument));
	
	return token_store_with_argument_attr(
			command, 
			argument,
			attributes);
}
