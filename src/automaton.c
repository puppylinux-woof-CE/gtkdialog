/*
** automaton.c: An automaton executing the program, creating widgets. 
** copyright: (c) 2003 by László Pere
** email: pipas@linux.pte.hu
**
** This program is free software; you can redistribute it and/or 
** modify  it under the terms of the GNU General Public License as
** published by the Free Software Foundation; either version 2 of
** the License, or (at your option) any later version.
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
#include "tag_attributes.h"
#include "widgets.h"

#undef DEBUG
#undef WARNING
#include "macros.h"

#undef TOOLTIPS
#define TYPE_NOTHING 0
#define TYPE_LAB 1
#define TYPE_PIX 2
#define TYPE_LABPIX 3

extern gboolean option_no_warning;
extern gboolean option_centering;

//
// Command line -geometry options
//
extern gboolean have_geometry_xy;
extern gboolean have_geometry_dxdy;
extern gint geometry_dx;
extern gint geometry_dy;
extern gint geometry_x;
extern gint geometry_y;



instruction *program = NULL;
int instruction_counter = 0;	/* The first available memory cell. */
size_t memory_counter = 0;	/* The size of program memory.     */
GtkWidget *window = NULL;	/* The actual window.              */

/*
 * Static function definitions.
 */
static int 
instruction_execute_push(token Token, 
		AttributeSet *Attr, 
		tag_attr *tag_attributes);


/*****************************************************************************
 * GtkWidget handling functions.                                             *
 *                                                                           *
 *****************************************************************************/
static void
on_any_widget_realized(
		GtkWidget *widget, 
		tag_attr  *tag_attributes)
{
	widget_set_tag_attributes(widget, tag_attributes);
}

static void
widget_signal_executor(
		GtkWidget    *widget,
		AttributeSet *Attr,
		const gchar  *signal_name)
{
	gchar *signal;
	gchar *command;
	gchar *type;

#ifdef LOTS_OF_MESSAGES
	PIP_DEBUG("Executing signal '%s' on widget %p.", signal_name, widget);
#endif
	g_return_if_fail(GTK_IS_WIDGET(widget));

	command = attributeset_get_first(Attr, ATTR_ACTION);
	if (command == NULL){
		return;
	}

	while (command != NULL){
		type = attributeset_get_this_tagattr(Attr, 
				ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(Attr, 
				ATTR_ACTION, "signal");
		if (signal != NULL && 
				g_ascii_strcasecmp(signal, signal_name) == 0) {
			//g_message("'%s' = '%s'", signal, signal_name);
			execute_action(widget, command, type);
		}
next_command:   
		command = attributeset_get_next(Attr, ATTR_ACTION);
	}
}


static gboolean
on_any_widget_button_pressed(
		GtkWidget      *widget,
                GdkEventButton *event,
                AttributeSet   *Attr) 
{
	gchar *button = g_strdup_printf("%d", event->button);
	g_setenv("BUTTON", button, TRUE);
	
	widget_signal_executor(widget, Attr, "button-press-event");
	
	g_unsetenv("BUTTON");
	g_free(button);
	return FALSE;
}

static gboolean
on_any_widget_button_released(
		GtkWidget      *widget,
                GdkEventButton *event,
                AttributeSet   *Attr) 
{
	gchar *button = g_strdup_printf("%d", event->button);
	g_setenv("BUTTON", button, TRUE);
	
	widget_signal_executor(widget, Attr, "button-release-event");
	
	g_unsetenv("BUTTON");
	g_free(button);
	return FALSE;
}

static gboolean
on_any_widget_configure_event(
		GtkWidget         *widget, 
		GdkEventConfigure *event,
                AttributeSet      *Attr) 
{
	widget_signal_executor(widget, Attr, "configure-event");
	return FALSE;
}

static gboolean
on_any_widget_delete_event(
		GtkWidget     *widget, 
		GdkEvent      *event, 
                AttributeSet  *Attr) 
{
	widget_signal_executor(widget, Attr, "delete-event");
	return FALSE;
}

static gboolean
on_any_widget_destroy_event(GtkWidget *widget, 
		GdkEvent  *event, 
                AttributeSet  *Attr) 
{
	widget_signal_executor(widget, Attr, "destroy-event");
	return FALSE;
}

static gboolean
on_any_widget_enter_notify_event(
		GtkWidget        *widget, 
		GdkEventCrossing *event, 
                AttributeSet     *Attr) 
{
	widget_signal_executor(widget, Attr, "enter-notify-event");
	return FALSE;
}

static gboolean
on_any_widget_leave_notify_event(
		GtkWidget        *widget, 
		GdkEventCrossing *event, 
                AttributeSet     *Attr) 
{
	widget_signal_executor(widget, Attr, "leave-notify-event");
	return FALSE;
}

static gboolean
on_any_widget_focus_in_event(
		GtkWidget     *widget, 
		GdkEventFocus *event, 
                AttributeSet  *Attr) 
{
	widget_signal_executor(widget, Attr, "focus-in-event");
	return FALSE;
}

static gboolean
on_any_widget_focus_out_event(
		GtkWidget     *widget, 
		GdkEventFocus *event, 
                AttributeSet  *Attr) 
{
	widget_signal_executor(widget, Attr, "focus-out-event");
	return FALSE;
}

static void
on_any_widget_hide(
		GtkWidget *widget, 
                AttributeSet  *Attr) 
{
	widget_signal_executor(widget, Attr, "hide");
}

static gboolean
on_any_widget_key_press_event(
		GtkWidget   *widget, 
		GdkEventKey *event,
                AttributeSet  *Attr) 
{
	widget_signal_executor(widget, Attr, "key-press-event");
	return FALSE;
}

static gboolean
on_any_widget_key_release_event(
		GtkWidget   *widget, 
		GdkEventKey *event,
                AttributeSet  *Attr) 
{
	widget_signal_executor(widget, Attr, "key-release-event");
	return FALSE;
}

static gboolean
on_any_widget_map_event(
		GtkWidget *widget,
		GdkEvent  *event,
                AttributeSet  *Attr) 
{
	widget_signal_executor(widget, Attr, "map-event");
	return FALSE;
}

static gboolean
on_any_widget_unmap_event(
		GtkWidget *widget, 
		GdkEvent  *event, 
                AttributeSet  *Attr) 
{
	widget_signal_executor(widget, Attr, "unmap-event");
	return FALSE;
}

static void
on_any_widget_show(
		GtkWidget     *widget, 
                AttributeSet  *Attr) 
{
	widget_signal_executor(widget, Attr, "show");
}

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

void 
table_selection(GtkWidget      *clist, 
		gint            row, 
		gint            column, 
		GdkEventButton *event, 
		gpointer        Attr)
{

	gchar *signal;
	gchar *command;
	gchar *type;	
	
	if (Attr == NULL)
		return;
    
	variables_set_row_column(attributeset_get_first(Attr, ATTR_VARIABLE), 
			row, column);

	command = attributeset_get_first(Attr, ATTR_ACTION);

	while (command != NULL){
		type = attributeset_get_this_tagattr(Attr, ATTR_ACTION, "type");
		execute_action(clist, command, type);
		command = attributeset_get_next(Attr, ATTR_ACTION);
	}
	return;
	
}


void 
entry_inserted(GtkWidget * entry, gpointer str)
{
	button_pressed(entry, str);
}

void button_toggled(GtkToggleButton * button, gpointer str)
{
	/*
	 ** First we check for "if true" and "if false" prefixes.
	 */
	if (strncasecmp(str, "if true ", 8) == 0) {
		if (gtk_toggle_button_get_active
		    (GTK_TOGGLE_BUTTON(button)))
			button_pressed((GtkWidget *) button,
				       &((char *) str)[8]);
		return;
	}
	if (strncasecmp(str, "if false ", 9) == 0) {
		if (!gtk_toggle_button_get_active
		    (GTK_TOGGLE_BUTTON(button)))
			button_pressed((GtkWidget *) button,
				       &((char *) str)[9]);
		return;
	}

	/*
	 ** Otherwise we just call the function we used to call when a
	 ** button is pressed.
	 */
	button_pressed((GtkWidget *) button, str);
	return;
}

void list_selection(GtkWidget * list, gpointer Attr)
{
	gchar *signal;
	gchar *command;
	gchar *type;	
	
	if (Attr == NULL)
		return;

	command = attributeset_get_first(Attr, ATTR_ACTION);

	while (command != NULL){
		type = attributeset_get_this_tagattr(Attr, ATTR_ACTION, "type");
		execute_action(list, command, type);
		command = attributeset_get_next(Attr, ATTR_ACTION);
	}
	return;
}


int 
execute_action(GtkWidget *widget, 
		const char *command, 
		const char *type)
{
	gchar *command_prefix;
	gchar *command_string;
	CommandType t;

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
	return TRUE;
}

/*
 * Callback functions for buttons.
 *
 */
void 
button_pressed_attr(
		GtkWidget     *button,
		AttributeSet  *Attr)
{
	gchar *signal;
	gchar *command;
	gchar *type;

	PIP_DEBUG("Button: %p.", button);
	
	command = attributeset_get_first(Attr, ATTR_ACTION);
	if (command == NULL){
		return;
	}

	while (command != NULL){
		type = attributeset_get_this_tagattr(Attr, 
				ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(Attr, 
				ATTR_ACTION, "signal");
		if (signal == NULL || 
				g_ascii_strcasecmp(signal, "pressed") != 0)
			goto next_command;
		
		execute_action(button, command, type);
next_command:   
		command = attributeset_get_next(Attr, ATTR_ACTION);
	}
}


void button_released_attr(
		GtkWidget     *button,
		AttributeSet  *Attr)
{
	gchar *signal;
	gchar *command;
	gchar *type;
	
	PIP_DEBUG("bitton: %p", button);
	
	command = attributeset_get_first(Attr, ATTR_ACTION);
	if (command == NULL){
		return;
	}

	while (command != NULL){
		type = attributeset_get_this_tagattr(Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(Attr, ATTR_ACTION, "signal");
		if (signal == NULL || g_ascii_strcasecmp(signal, "released") != 0)
			goto next_command;
		
		execute_action(button, command, type);
next_command:   
		command = attributeset_get_next(Attr, ATTR_ACTION);
	}
}


void 
button_leaved_attr(GtkWidget     *button,
		   AttributeSet  *Attr)
{
	gchar *signal;
	gchar *command;
	gchar *type;

	PIP_DEBUG("button: %p.", button);
	
	command = attributeset_get_first(Attr, ATTR_ACTION);

	while (command != NULL){
		type = attributeset_get_this_tagattr(Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(Attr, ATTR_ACTION, "signal");
		if (signal == NULL || g_ascii_strcasecmp(signal, "leave") != 0)
			goto next_command;
		
		execute_action(button, command, type);
next_command:   
		command = attributeset_get_next(Attr, ATTR_ACTION);
	}
}


void 
button_entered_attr(
		GtkWidget     *button,
		AttributeSet  *Attr)
{
	gchar *signal;
	gchar *command;
	gchar *type;
	
	PIP_DEBUG("Start.");
	
	command = attributeset_get_first(Attr, ATTR_ACTION);
	if (command == NULL){
		return;
	}

	while (command != NULL){
		type = attributeset_get_this_tagattr(Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(Attr, ATTR_ACTION, "signal");
		if (signal == NULL || g_ascii_strcasecmp(signal, "enter") != 0)
			goto next_command;
		
		execute_action(button, command, type);
next_command:   
		command = attributeset_get_next(Attr, ATTR_ACTION);
	}
}

void 
button_clicked_attr(
		GtkWidget     *button,
		AttributeSet  *Attr)
{
	gchar *signal;
	gchar *command;
	gchar *type;
	
	PIP_DEBUG("button: %p, Attr: %p", button, Attr);
	
	command = attributeset_get_first(Attr, ATTR_ACTION);
	if (command == NULL){
		if (!option_no_warning)
			g_warning("%s(): Button without action.", __func__);
		return;
	}

	while (command != NULL){
		type = attributeset_get_this_tagattr(Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(Attr, ATTR_ACTION, "signal");
		if (signal != NULL && g_ascii_strcasecmp(signal, "clicked") != 0)
			goto next_command;
		
		execute_action(button, command, type);
next_command:   
		command = attributeset_get_next(Attr, ATTR_ACTION);
	}
}
		

/*
** This function is called when a button is pressed. The first
** argument is a pointer to the window, the second is the command
** string.
*/
void 
button_pressed(GtkWidget *button, 
		const gchar *str)
{
	PIP_DEBUG("");
	execute_action(GTK_WIDGET(button), str, NULL);
	return;
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
	case WIDGET_LABEL:
	    printf("(new text())");
	    break;
	case WIDGET_ENTRY:
	    printf("(new entry())");
	    break;
	case WIDGET_EDIT:
	    printf("(new edit)");
	    break;
	case WIDGET_BUTTON:
	    printf("(new button())");
	    break;
	case WIDGET_CHECKBOX:
	    printf("(new checkbox())");
	    break;
	case WIDGET_RADIO:
	    printf("(new radio())");
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
	case WIDGET_OKBUTTON:
	    printf("(new okbutton())");
	    break;
	case WIDGET_CANCELBUTTON:
	    printf("(new cancelbutton())");
	    break;
	case WIDGET_HELPBUTTON:
	    printf("(new helpbutton())");
	    break;
	case WIDGET_NOBUTTON:
	    printf("(new nobutton())");
	    break;
	case WIDGET_YESBUTTON:
	    printf("(new yesbutton())");
	    break;
	case WIDGET_SCROLLEDW:
	    printf("(new scrolledwindow(pop()))");
	    break;
	case WIDGET_VBOX:
	    printf("(new vbox(pop()))");
	    break;
	case WIDGET_HBOX:
	    printf("(new hbox(pop()))");
	    break;
	case WIDGET_FRAME:
	    printf("(new frame(pop()))");
	    break;
	case WIDGET_NOTEBOOK:
	    printf("(new notebook(pop()))");
	    break;
	case WIDGET_WINDOW:
	    printf("(new window(pop()))");
	    break;
	case WIDGET_PIXMAP:
	    printf("(new pixmap())");
	    break;
	case WIDGET_MENUBAR:
	    printf("(new menubar(pop()))");
	    break;
	case WIDGET_MENU:
	    printf("(new menu(pop()))");
	    break;
	case WIDGET_MENUITEM:
	    printf("(new menuitem())");
	    break;
	case WIDGET_GVIM:
	    printf("(new gvim())");
	    break;
	case WIDGET_TREE:
	    printf("(new tree())");
	    break;
	case WIDGET_CHOOSER:
	    printf("(new chooser())");
	    break;
	case WIDGET_MENUSEP:
	    printf("(new menuseparator())");
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
	int pc, q;
	stackelement s;
	
	PIP_DEBUG("Program starting.");

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
	
	instruction_counter = 0;
	reset_program_source();	
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
	case WIDGET_LABEL:
		printf("(LABEL)");
		break;
	case WIDGET_ENTRY:
		printf("(ENTRY)");
		break;
	case WIDGET_EDIT:
		printf("(EDIT)");
		break;
	case WIDGET_BUTTON:
		printf("(BUTTON)");
		break;
	case WIDGET_CHECKBOX:
		printf("(CHECKBOX)");
		break;
	case WIDGET_RADIO:
		printf("(RADIO)");
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
	case WIDGET_OKBUTTON:
		printf("(OKBUTTON)");
		break;
	case WIDGET_CANCELBUTTON:
		printf("(CANCELBUTTON)");
		break;
	case WIDGET_HELPBUTTON:
		printf("(HELPBUTTON)");
		break;
	case WIDGET_NOBUTTON:
		printf("(NOBUTTON)");
		break;
	case WIDGET_YESBUTTON:
		printf("(YESBUTTON)");
		break;
	case WIDGET_SCROLLEDW:
		printf("(SCROLLEDW)");
		break;
	case WIDGET_VBOX:
		printf("(VBOX)");
		break;
	case WIDGET_HBOX:
		printf("(HBOX)");
		break;
	case WIDGET_FRAME:
		printf("(FRAME)");
		break;
	case WIDGET_NOTEBOOK:
		printf("(NOTEBOOK)");
		break;
	case WIDGET_WINDOW:
		printf("(WINDOW)");
		break;
	case WIDGET_PIXMAP:
		printf("(PIXMAP)");
		break;
	case WIDGET_MENUBAR:
		printf("(MENUBAR)");
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
	case WIDGET_TREE:
		printf("(TREE)");
		break;
	case WIDGET_CHOOSER:
		printf("(CHOOSER)");
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
		variables_refresh(attributeset_get_first(Attr, ATTR_VARIABLE));
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

static void
menu_callback(
		GtkWidget *menu_item, 
		AttributeSet *Attr)
{
	gchar *command;
	gchar *type;
	
	PIP_DEBUG("Starting.");

	command = attributeset_get_first(Attr, ATTR_ACTION);
	if (command == NULL){
		if (!option_no_warning)
			g_warning("%s(): Menu item without action.", __func__);
		return;
	}
	
	
	while (command != NULL){
		type = attributeset_get_this_tagattr(Attr, ATTR_ACTION, "type");
		if (type == NULL)
			type = "";
		
		execute_action(menu_item, command, type);
next_command:   
		command = attributeset_get_next(Attr, ATTR_ACTION);
	}
}

/*
 * Puts the widget into a scolled window. This function is similar to the
 * create_* functions we use to create various widgets as we execute the
 * internal representation of the dialog description.
 */
static GtkWidget *
put_in_the_scrolled_window(GtkWidget *widget,
		AttributeSet *Attr,
		tag_attr     *attr)
{
	GtkWidget *scrolledwindow;

	g_assert(widget != NULL);
	/*
	 * Creating the scrolled window.
	 */
	scrolledwindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolledwindow), 
			GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	/*
	 * Setting the size of the scolled window.
	 */
	if (attributeset_is_avail(Attr, ATTR_HEIGHT) && 
			attributeset_is_avail(Attr, ATTR_WIDTH))
		gtk_widget_set_usize(scrolledwindow, 
				atoi(attributeset_get_first(Attr, ATTR_WIDTH)),
				atoi(attributeset_get_first(Attr, ATTR_HEIGHT)));
	else if (attributeset_is_avail(Attr, ATTR_HEIGHT))
		gtk_widget_set_usize(scrolledwindow, 
				-1,
				atoi(attributeset_get_first(Attr, ATTR_HEIGHT)));
	else if (attributeset_is_avail(Attr, ATTR_WIDTH))
		gtk_widget_set_usize(scrolledwindow, 
				atoi(attributeset_get_first(Attr, ATTR_WIDTH)),
				-1);

	else 
		gtk_widget_set_usize(scrolledwindow, 200, 100);
		
	if (GTK_IS_LIST(widget))
		gtk_scrolled_window_add_with_viewport(
				GTK_SCROLLED_WINDOW(scrolledwindow), 
				widget);
	else
		gtk_container_add(GTK_CONTAINER(scrolledwindow), widget);
	return scrolledwindow;
}

static GtkWidget *
create_menuitem(AttributeSet *Attr, 
		tag_attr     *attr)
{
	GtkIconTheme *icon_theme;
	GdkPixbuf    *pixbuf;
	GError       *error = NULL;
	GtkWidget    *menu_item;
	GtkWidget    *Icon;
	gchar        *label;
	int           q;

	PIP_DEBUG("");

	label = attributeset_get_first(Attr, ATTR_LABEL);
	
	if (attr != NULL) {
		for (q = 0; q < attr->n; ++q) {
			if (strcmp(attr->pairs[q].name, "stock") == 0) {
				menu_item = gtk_image_menu_item_new_from_stock(
						attr->pairs[q].value, NULL);
				goto item_ready;
			}
			if (strcmp(attr->pairs[q].name, "icon") == 0) {
				icon_theme = gtk_icon_theme_get_default();
				pixbuf = gtk_icon_theme_load_icon (icon_theme,
                                   attr->pairs[q].value, 20, 0, &error);
				Icon = gtk_image_new_from_pixbuf(pixbuf);	
				menu_item = gtk_image_menu_item_new_with_label(label);
				gtk_image_menu_item_set_image(GTK_IMAGE_MENU_ITEM(menu_item), Icon);
				goto item_ready;
			}

		}
	}
	menu_item = gtk_menu_item_new_with_label(label);
	
item_ready:
	
	if (attributeset_is_avail(Attr, ATTR_ACTION)){
		g_signal_connect(G_OBJECT(menu_item), 
				"activate", (GCallback)menu_callback, Attr);
	}else{
		if (!option_no_warning)
			g_warning("%s(): Menu item without action.", __func__);
	}
	return menu_item;
}

static
GtkWidget *create_menu(AttributeSet *Attr, stackelement items){
	int n;
	GtkWidget *menu;
	GtkWidget *root_menu;
	GtkWidget *menu_items;
	
	menu = gtk_menu_new();
	for (n = 0; n < items.nwidgets; ++n){
		menu_items = items.widgets[n];
        	gtk_menu_shell_append (GTK_MENU_SHELL (menu), menu_items);
	}
	
	root_menu = gtk_menu_item_new_with_label (
			attributeset_get_first(Attr, ATTR_LABEL));
	gtk_menu_item_set_submenu (GTK_MENU_ITEM (root_menu), menu);
	
	return root_menu;
}

static
GtkWidget *create_menubar(AttributeSet * Attr, stackelement menus)
{
	int n;
	GtkWidget *menu_bar;
	GtkWidget *root_menu;
	
	menu_bar = gtk_menu_bar_new ();
	for (n = 0; n < menus.nwidgets; ++n){
		root_menu = menus.widgets[n];
		gtk_menu_shell_append (GTK_MENU_SHELL (menu_bar), root_menu);
	}
	
	return menu_bar;
}

static GtkWidget *
create_label(AttributeSet * Attr)
{
	GtkWidget *Label;
	/* 
	 ** Setting up the default values for the new label.
	 */
	attributeset_set_if_unset(Attr, ATTR_LABEL, "(unnamed label)");
	/*
	 ** Creating the widget, and pushing it into the stack.
	 */
	Label = gtk_label_new(attributeset_get_first (Attr, ATTR_LABEL));
	gtk_label_set_line_wrap(GTK_LABEL(Label), TRUE);

	if (attributeset_cmp_left(Attr, ATTR_VISIBLE, "disabled"))
		gtk_widget_set_sensitive(Label, FALSE);

	return Label;
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


/******************************************************************************
 * Handling TreeView widgets. The model always has the following columns:     *
 *   0) "pixbuf"     GdkPixbuf                                                *
 *   1) "icon-name"  gchararray                                               *
 *   2) "stock-id"   gchararray                                               *
 *                                                                            *
 * We create the TreeStore in the following function:                         *
 *   gtkdialog_tree_store_new                                                 *
 * We create the TreeView in:                                                 *
 *   create_tree_view                                                         *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/
static GtkTreeStore *
gtkdialog_tree_store_new(gint ndatacolumn)
{
	GtkTreeStore *tree_store;
	GType        *types;
	gint          n;
	
	PIP_DEBUG("ndatacolumn: %d", ndatacolumn);

	types = g_new(GType, ndatacolumn + FirstDataColumn);
	types[ColumnPixbuf]   = G_TYPE_POINTER;
	types[ColumnIconName] = G_TYPE_STRING;
	types[ColumnStockId]  = G_TYPE_STRING;

	for (n = FirstDataColumn; n < ndatacolumn + FirstDataColumn; ++n) {
		types[n] = G_TYPE_STRING;
	}
	
	tree_store = gtk_tree_store_newv(ndatacolumn + FirstDataColumn, types);
	return tree_store;
}


/*
 * Creating tree store from <label></label> tags.
 */
static GtkTreeStore *
create_store_from_label(AttributeSet *Attr)
{
	GtkTreeStore   *treestore;
	gchar          *label;
	list_t         *columns = NULL;
	gint            ncolumns;

	PIP_DEBUG("Attributeset: %p", Attr);

	if (!attributeset_is_avail(Attr, ATTR_LABEL)) {
		//g_warning("%s(): TreeView with no label.", __func__);
		attributeset_set_if_unset(Attr, ATTR_LABEL, "Column0");
		//return NULL;
	}
	/*
	 * We create as much columns as much the label tag suggests.
	 */
	label = g_strdup(attributeset_get_first(Attr, ATTR_LABEL));
	columns = linecutter(label, '|');
	ncolumns = columns->n_lines;
	// FIXME: swe should free some memory here

	treestore = gtkdialog_tree_store_new(ncolumns);

	return treestore;
}


#if GTK_CHECK_VERSION(2,4,0)
void 
pixmap_column_cell_layout_function(
		GtkCellLayout    *cell_layout, 
		GtkCellRenderer  *cell, 
		GtkTreeModel     *tree_model, 
		GtkTreeIter      *iter, 
		GtkTreeView      *treeview)
{
	gchar *stock_id;
	gchar *icon_name;

	gtk_tree_model_get(tree_model, iter,
			ColumnStockId,  &stock_id,
			ColumnIconName, &icon_name,
			-1);

	if (stock_id != NULL) {
		PIP_DEBUG("This row has a stock_id: '%s'", stock_id);
		g_object_set(G_OBJECT(cell), 
			"stock-id", stock_id,
			NULL);
		return;
	}

	if (icon_name != NULL) {
		PIP_DEBUG("This row has a icon_name: '%s'", icon_name);
		g_object_set(G_OBJECT(cell), 
			"icon-name", icon_name,
			NULL);
		return;
	}

	stock_id = g_object_get_data(G_OBJECT(treeview), "stock");
	if (stock_id != NULL) {
		PIP_DEBUG("This row has a default icon stock_id(stock): '%s'",
				stock_id);
		g_object_set(G_OBJECT(cell), 
			"stock-id", stock_id,
			NULL);
		return;
	}
	
	stock_id = g_object_get_data(G_OBJECT(treeview), "stock_id");
	if (stock_id != NULL) {
		PIP_DEBUG("This row has a default icon stock_id(stock_id): '%s'",
				stock_id);
		g_object_set(G_OBJECT(cell), 
			"stock-id", stock_id,
			NULL);
		return;
	}

	stock_id = g_object_get_data(G_OBJECT(treeview), "icon");
	if (stock_id != NULL) {
		PIP_DEBUG("This row has a default icon_name(icon): '%s'",
				stock_id);
		g_object_set(G_OBJECT(cell), 
			"icon-name", stock_id,
			NULL);
		return;
	}
	
	stock_id = g_object_get_data(G_OBJECT(treeview), "icon_name");
	if (stock_id != NULL) {
		PIP_DEBUG("This row has a default icon_name(icon_name): '%s'",
				stock_id);
		g_object_set(G_OBJECT(cell), 
			"icon-name", stock_id,
			NULL);
		return;
	}

	PIP_DEBUG("We have no icon at all.");
}

static GtkWidget *
create_tree_view(
		AttributeSet *Attr, 
		GtkTreeStore *store)
{
	GtkWidget          *tree_view;
	GtkCellRenderer    *renderer;
	GtkTreeViewColumn  *column;
	list_t             *columns;
	char               *headline = NULL;
	int                n;
	
	PIP_DEBUG("Attr: %p store: %p", Attr, store);

	if (!attributeset_is_avail(Attr, ATTR_LABEL)) {
		//g_warning("%s(): TreeView with no label.", __func__);
		attributeset_set_if_unset(Attr, ATTR_LABEL, "Column0");
		//return NULL;
	}

	headline = g_strdup(attributeset_get_first(Attr, ATTR_LABEL));
	columns = linecutter(headline, '|');
	
	/*
	 * We create the TreeView here.
	 */
	tree_view = gtk_tree_view_new_with_model(GTK_TREE_MODEL (store));
	/*
	 * The first column will hold two cell renderer. One for the pixmap with
	 * a complex cell data function and one text renderer with the first
	 * real data column given by the user.
	 */
	column = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title(column, columns->line[0]);
	gtk_tree_view_append_column(tree_view, column);
	gtk_tree_view_column_set_sort_column_id(column, FirstDataColumn);
	
	renderer = gtk_cell_renderer_pixbuf_new();
	gtk_tree_view_column_pack_start(column, renderer, FALSE);
	gtk_cell_layout_set_cell_data_func(GTK_CELL_LAYOUT(column), 
		renderer,
		(GtkCellLayoutDataFunc )pixmap_column_cell_layout_function,
		tree_view, 
		NULL);

	renderer = gtk_cell_renderer_text_new();
	gtk_tree_view_column_pack_start(column, renderer, FALSE);
	gtk_tree_view_column_add_attribute(column, renderer, "text",
			FirstDataColumn);
	/*
	 * Now creating the other columns holding text style data from the 
	 * user.
	 */
	for (n = 1; n < columns->n_lines; ++n){
		column = gtk_tree_view_column_new();
		gtk_tree_view_column_set_title(column, columns->line[n]);	
		gtk_tree_view_append_column(tree_view, column);
		gtk_tree_view_column_set_sort_column_id(column, 
				n + FirstDataColumn);
		
		renderer = gtk_cell_renderer_text_new ();
		gtk_tree_view_column_pack_start(column, renderer, TRUE);
		gtk_tree_view_column_add_attribute(column, renderer, 
				"text", n + FirstDataColumn);
	}
	return tree_view;
}

/*
 * This is the main function where we create the tree view.  
 */
static GtkWidget *
create_tree(AttributeSet  *Attr, 
		tag_attr  *attr)
{
	GtkWidget          *tree;
	GtkTreeStore       *store;

	PIP_DEBUG("Attr: %p, attr: %p", Attr, attr);

	if (!attributeset_is_avail(Attr, ATTR_LABEL)) {
		g_warning("%s(): A TreeView with no label.", __func__);
		return NULL;
	}

	/*
	 * Creating the store to hold the data and the tree view to
	 * represent it.
	 */
	store = create_store_from_label(Attr);
	tree = create_tree_view(Attr, store);
//**NEW------------------------------------------------------------------------
	if (attr) {
		int count;
		for (count = 0; count < attr->n; ++count) {

			//GtkTreeSelection *selection;
			//selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(widget));
			//gtk_tree_selection_set_mode(selection, GTK_SELECTION_MULTIPLE);
			//gtk_tree_selection_set_mode(selection, GTK_SELECTION_SINGLE);

			if (strcasecmp((attr->pairs + count)->name, "selection_mode") == 0 ||
				strcasecmp((attr->pairs + count)->name, "selection-mode") == 0) {

				printf("%s: attr->pairs->name=%s\n", __func__, (attr->pairs + count)->name);//temp temp
				printf("%s: attr->pairs->value=%s\n", __func__, (attr->pairs + count)->value);//temp temp
					
			}

/*			gchar *tmp;
			tmp = g_object_get_data(G_OBJECT(tree), "selection_mode");
			printf("%s: selection_mode=\"%s\"\n", __func__, tmp);//temp temp
			tmp = g_object_get_data(G_OBJECT(tree), "exported_column");
			printf("%s: exported_column=\"%s\"\n", __func__, tmp);//temp temp
			printf("%s: GTK_SELECTION_SINGLE=\"%i\" GTK_SELECTION_MULTIPLE=\"%i\"\n", __func__, 
				GTK_SELECTION_SINGLE, GTK_SELECTION_MULTIPLE);//temp temp
*/
		}
	}
//**NEW------------------------------------------------------------------------
	return tree;
}


#endif

#if GTK_CHECK_VERSION(2,4,0)
static GtkWidget *
create_chooser(AttributeSet *Attr)
{
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
				atoi(attributeset_get_first(Attr, ATTR_WIDTH)),
				atoi(attributeset_get_first(Attr, ATTR_HEIGHT)));
	
	if (attributeset_is_avail(Attr, ATTR_DEFAULT))
		gtk_file_chooser_set_current_folder((GtkFileChooser *)chooser, 
				attributeset_get_first(Attr, ATTR_DEFAULT));
	
	act = attributeset_get_first(Attr, ATTR_ACTION);
	while (act != NULL) {
		tagattr_value = attributeset_get_this_tagattr(
				Attr, ATTR_ACTION, "when");
		if (tagattr_value == NULL)
			tagattr_value = "file-activated";
		
		gtk_signal_connect(GTK_OBJECT(chooser),
				   tagattr_value,
				   GTK_SIGNAL_FUNC
				   (button_pressed), (gpointer) act);
		act = attributeset_get_next(Attr, ATTR_ACTION);
	}

	//gtk_file_chooser_set_preview_widget_active(chooser, TRUE);
	return chooser;
}
#endif

/******************************************************************************
 * GtkTreeView signal handlers.                                               *
 *                                                                            *
 ******************************************************************************/
void        
tree_row_activated_attr(GtkTreeView  *tree_view, 
		GtkTreePath          *path, 
		GtkTreeViewColumn    *column, 
		AttributeSet         *Attr)
{
	gchar *signal;
	gchar *command;
	gchar *type;
	
	PIP_DEBUG("tree_view: %p", tree_view);
	
	command = attributeset_get_first(Attr, ATTR_ACTION);
	if (command == NULL)
		return;

	while (command != NULL){
		type = attributeset_get_this_tagattr(Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(Attr, ATTR_ACTION, "signal");
		if (signal != NULL && g_ascii_strcasecmp(signal, "row_activated") != 0)
			goto next_command;
		
		execute_action(GTK_WIDGET(tree_view), command, type);
next_command:   
		command = attributeset_get_next(Attr, ATTR_ACTION);
	}
}

gboolean    
tree_cursor_changed(
		GtkTreeView    *tree_view, 
		AttributeSet   *Attr)
{
	gchar *signal;
	gchar *command;
	gchar *type;

	PIP_DEBUG("tree_view: %p, Attr: %p", tree_view, Attr);
	
	command = attributeset_get_first(Attr, ATTR_ACTION);
	if (command == NULL)
		return;

	while (command != NULL){
		type = attributeset_get_this_tagattr(Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(Attr, ATTR_ACTION, "signal");
		if (signal == NULL || g_ascii_strcasecmp(signal, "cursor_changed") != 0)
			goto next_command;
		
		execute_action(GTK_WIDGET(tree_view), command, type);
next_command:   
		command = attributeset_get_next(Attr, ATTR_ACTION);
	}
	return TRUE;
}

/**
 *
 * Connects the signals of the GtkTreeView to the signal handlers.
 */
static void
connect_tree_signals(
		GtkTreeView *tree_view,
		AttributeSet *Attr)
{
	PIP_DEBUG("tree_view: %p, Attr: %p", tree_view, Attr);

	g_assert(tree_view != NULL && Attr != NULL);
	/*
	 ** Here we connect GtkTreeView signals to signal handlers.
	 */
	gtk_signal_connect(GTK_OBJECT(tree_view), "row-activated", 
			GTK_SIGNAL_FUNC (tree_row_activated_attr), 
			(gpointer) Attr);
	
	gtk_signal_connect(GTK_OBJECT(tree_view), "cursor-changed", 
			GTK_SIGNAL_FUNC (tree_cursor_changed), 
			(gpointer) Attr);
}

static void
connect_button_signals(
		GtkButton *Button,
		AttributeSet *Attr)
{
	PIP_DEBUG("Button: %p, Attr: %p", Button, Attr);	
	g_assert(Button != NULL && Attr != NULL);
	
	/*
	 * If a button has no action, the action will be the exit
	 * which is the default action.
	 */
	if (!attributeset_is_avail(Attr, ATTR_ACTION)) {
		attributeset_set_if_unset(Attr, ATTR_LABEL, "unnamed");
		attributeset_insert(Attr, ATTR_ACTION, 
				attributeset_get_first(Attr, ATTR_LABEL));
		attributeset_get_first(Attr, ATTR_ACTION);  
		attributeset_set_this_tagattr(Attr, ATTR_ACTION, 
				"type", "exit");
	}
	/*
	 ** Here we connect GtkButton signals to signal handlers.
	 ** The action attribute can hold arbitrary number of actions,
	 ** whose execution is a an important task when the button is
	 ** pressed by the user. However, we connect the signal handlers
	 ** only once, since the handler itself can handle each actions in
	 ** order.
	 */
	gtk_signal_connect(GTK_OBJECT(Button), "clicked", GTK_SIGNAL_FUNC
				   (button_clicked_attr), (gpointer) Attr);
	gtk_signal_connect(GTK_OBJECT(Button), "enter", GTK_SIGNAL_FUNC
				   (button_entered_attr), (gpointer) Attr);
	gtk_signal_connect(GTK_OBJECT(Button), "leave", GTK_SIGNAL_FUNC
				   (button_leaved_attr), (gpointer) Attr);
	gtk_signal_connect(GTK_OBJECT(Button), "pressed", GTK_SIGNAL_FUNC
				   (button_pressed_attr), (gpointer) Attr);
	gtk_signal_connect(GTK_OBJECT(Button), "released", GTK_SIGNAL_FUNC
				   (button_released_attr), (gpointer) Attr);
}

/*****************************************************************************
 * Window handling functions.                                                *
 *                                                                           *
 *****************************************************************************/
gboolean
window_delete_event_handler(
		GtkWidget *widget, 
		GtkWidget *event, 
		gpointer data)
{
	PIP_DEBUG("widget: %p", widget);

	variables_drop_by_parent(NULL, widget);
		
	if (variables_count_widgets() == 0) {
		gtk_main_quit();
		printf("EXIT=\"abort\"\n");
		exit(EXIT_SUCCESS);
	}
	return FALSE;
}

static GtkWidget *
create_window(
		AttributeSet *Attr, 
		tag_attr   *attr)
{
	PIP_DEBUG("Attr: %p", Attr);
	/*
	 * Creating a window with the default settings.
	 */
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
	gtk_container_set_border_width(GTK_CONTAINER(window), 5);
	
	/*
	 * The windows can send signals, so they can have actions.
	 */
	widget_connect_signals(window, Attr);
			
	gtk_signal_connect(GTK_OBJECT(window), "delete_event",
			   GTK_SIGNAL_FUNC(window_delete_event_handler), NULL);

	/*
	 * If we have geometry given in the command line, we set that.
	 */
	if (have_geometry_dxdy)
		gtk_widget_set_usize(window, geometry_dx, geometry_dy);
	if (have_geometry_xy)
		gtk_widget_set_uposition(window, geometry_x, geometry_y);
	if (option_centering)
		gtk_window_set_position(GTK_WINDOW(window), 
				GTK_WIN_POS_CENTER_ALWAYS);
	/*
	 * Setting the title of the window
	 */
	attributeset_set_if_unset(Attr, ATTR_LABEL, PACKAGE);
	gtk_window_set_title(GTK_WINDOW(window), 
			attributeset_get_first(Attr, ATTR_LABEL));

	return window;
}


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
	GtkWidget *widget;
	
	list_t *table_header;
	if (attributeset_is_avail(Attr, ATTR_LABEL)) {
		table_header =
		linecutter(attributeset_get_first(Attr, ATTR_LABEL), '|');
		widget=gtk_clist_new_with_titles
				    (table_header->n_lines,
				     table_header->line);
	} else {
		widget = gtk_clist_new(1);
	}
	
	return widget;
}

static GtkWidget *
create_button(AttributeSet *Attr, 
		tag_attr   *attr)
{
	GtkWidget *Button = NULL;
	GtkWidget *Icon = NULL;
	GtkWidget *Label = NULL;
	GtkWidget *Box = NULL;
	GdkPixbuf *pixbuf = NULL;
	char *icon_stock_name = NULL;
	char *icon_file_name = NULL;
	char *str;
	char *act;
	int type;
	int width = -1, height = -1;
	
	PIP_DEBUG("");
	
	type = TYPE_NOTHING;
	if (!attributeset_is_avail(Attr, ATTR_INPUT) &&
		attributeset_is_avail(Attr, ATTR_LABEL))
		type = TYPE_LAB;
	
	if (attributeset_is_avail(Attr, ATTR_INPUT) &&
		!attributeset_is_avail(Attr, ATTR_LABEL))
		type = TYPE_PIX;
	
	if (attributeset_is_avail(Attr, ATTR_INPUT) &&
		attributeset_is_avail(Attr, ATTR_LABEL))
		type = TYPE_LABPIX;

	if (type == TYPE_PIX || type == TYPE_LABPIX){
		icon_file_name = attributeset_get_first(Attr, ATTR_INPUT) + 5;
		icon_stock_name = attributeset_get_this_tagattr(Attr, ATTR_INPUT, "stock");
		if (icon_stock_name != NULL){
			Icon = gtk_image_new_from_stock(icon_stock_name,
					GTK_ICON_SIZE_BUTTON);

#if GTK_CHECK_VERSION(2,4,0)
		}else{
			char *icon_name = attributeset_get_this_tagattr(Attr, ATTR_INPUT, "icon");
			
			if (icon_name != NULL){
				GtkIconTheme *icon_theme;
				GdkPixbuf *pixbuf;
				GError *error = NULL;
				
				icon_theme = gtk_icon_theme_get_default();
				pixbuf = gtk_icon_theme_load_icon (icon_theme,
                                   icon_name,
                                   20,
                                   0,
                                   &error);
				Icon = gtk_image_new_from_pixbuf(pixbuf);	
			}else{
				if (attributeset_is_avail(Attr, ATTR_WIDTH))
					width = atoi(attributeset_get_first(Attr, ATTR_WIDTH));
				if (attributeset_is_avail(Attr, ATTR_HEIGHT))
					height = atoi(attributeset_get_first(Attr, ATTR_HEIGHT));

				if (width == -1 && height == -1) {
					/* Handle unscaled images */
					Icon = gtk_image_new_from_file(find_pixmap(icon_file_name));
				} else {
					/* Handle scaled images */
					pixbuf = gdk_pixbuf_new_from_file_at_size(
						find_pixmap(icon_file_name), width, height, NULL);
					if (pixbuf) {
						Icon = gtk_image_new_from_pixbuf(pixbuf);
						/* pixbuf is no longer required and should be unreferenced */
						g_object_unref(pixbuf);
					} else {
						/* pixbuf is null (file not found) so by using this
						* function gtk will substitute a broken image icon */
						Icon = gtk_image_new_from_file("");
					}
				}
			}
#endif
		}
	}

	attributeset_set_if_unset(Attr, ATTR_LABEL, "OK");
	attributeset_set_if_unset(Attr, ATTR_DEFAULT, "OK");
		
	switch (type) {
		case TYPE_NOTHING:
		case TYPE_LAB:
			Button = gtk_button_new_with_label(
					attributeset_get_first(Attr, 
						ATTR_LABEL));
			break;
		case TYPE_PIX:
			Button = gtk_button_new();
			gtk_container_add(GTK_CONTAINER(Button), Icon);
			break;
		case TYPE_LABPIX:
			Box = gtk_hbox_new(FALSE, 5);
			Button = gtk_button_new();
		    	Label = gtk_label_new(attributeset_get_first
				  (Attr, ATTR_LABEL));
			gtk_container_add(GTK_CONTAINER(Button), Box);
			gtk_box_pack_end(GTK_BOX(Box), Label, TRUE, TRUE, 0);
			gtk_box_pack_end(GTK_BOX(Box), Icon, TRUE, TRUE, 0);
	}

	PIP_DEBUG("");
	return Button;
}


static GtkWidget *
create_edit(AttributeSet *Attr, 
		tag_attr   *attr)
{
	GtkWidget     *text_view;
	GtkTextBuffer *text_buffer;
	/*
	 * Creating text view.
	 */
	text_view = gtk_text_view_new();
	text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

	if (attributeset_cmp_left(Attr, ATTR_VISIBLE, "disabled"))
		gtk_widget_set_sensitive(text_view, FALSE);
 
	if (attributeset_is_avail(Attr, ATTR_DEFAULT))
		gtk_text_buffer_set_text(text_buffer, 
				attributeset_get_first(Attr, ATTR_DEFAULT), 
				-1);

	return text_view;
}


static GtkWidget *
create_pixmap(AttributeSet * Attr)
{
	GdkPixbuf *pixbuf;
	GtkWidget *Pixmap;
	char *icon_file_name;
	char *icon_stock_name;
	int width = -1, height = -1;
	
	icon_file_name = attributeset_get_first(Attr, ATTR_INPUT) + 5;
	icon_stock_name = attributeset_get_this_tagattr(Attr, 
				ATTR_INPUT, 
				"stock");
	// GTK_STOCK_OPEN
	if (icon_stock_name != NULL)
		Pixmap = gtk_image_new_from_stock(icon_stock_name,
					GTK_ICON_SIZE_DND);
	else {
		if (attributeset_is_avail(Attr, ATTR_WIDTH))
			width = atoi(attributeset_get_first(Attr, ATTR_WIDTH));
		if (attributeset_is_avail(Attr, ATTR_HEIGHT))
			height = atoi(attributeset_get_first(Attr, ATTR_HEIGHT));

		if (width == -1 && height == -1) {
			/* Handle unscaled images */
			Pixmap = gtk_image_new_from_file(find_pixmap(icon_file_name));
		} else {
			/* Handle scaled images */
			pixbuf = gdk_pixbuf_new_from_file_at_size(
				find_pixmap(icon_file_name), width, height, NULL);
			if (pixbuf) {
				Pixmap = gtk_image_new_from_pixbuf(pixbuf);
				/* pixbuf is no longer required and should be unreferenced */
				g_object_unref(pixbuf);
			} else {
				/* pixbuf is null (file not found) so by using this
				 * function gtk will substitute a broken image icon */
				Pixmap = gtk_image_new_from_file("");
			}
		}
	}

	if (attributeset_cmp_left(Attr, ATTR_VISIBLE, "disabled"))
		gtk_widget_set_sensitive(Pixmap, FALSE);
	
	return Pixmap;
}


static gint 
instruction_execute_push(
		token          Token, 
		AttributeSet  *Attr,
		tag_attr      *tag_attributes)
{
	GtkWidget        *scrolled_window;	
	int 		  Widget_Type;
	GtkWidget 	 *Widget;
	GtkWidget 	 *OtherWidget;
	int 		  n;
	static GtkWidget *LastRadioButton = NULL;
	//char 		 *attribute_value;

	PIP_DEBUG("token: %d", Token);
	
	Widget_Type = Token & WIDGET_TYPE;

	switch (Widget_Type) {
	case WIDGET_LABEL:
		Widget = create_label(Attr);
		push_widget(Widget, Widget_Type);
		break;
	case WIDGET_PIXMAP:
		Widget = create_pixmap(Attr);
		push_widget(Widget, Widget_Type);
		break;

	case WIDGET_ENTRY:
		/*
		 ** Creating the widget, and pushing it into the stack.
		 */
		Widget = gtk_entry_new();
		push_widget(Widget, Widget_Type);

		if (attributeset_is_avail(Attr, ATTR_DEFAULT))
			gtk_entry_set_text(GTK_ENTRY(Widget),
					   attributeset_get_first(Attr,
								  ATTR_DEFAULT));

		if (attributeset_cmp_left(Attr, ATTR_VISIBLE, "password"))
			gtk_entry_set_visibility(GTK_ENTRY(Widget), FALSE);

		if (attributeset_is_avail(Attr, ATTR_HEIGHT) &&
		    attributeset_is_avail(Attr, ATTR_WIDTH))
			gtk_widget_set_usize(Widget,
					     atoi(attributeset_get_first
						  (Attr, ATTR_WIDTH)),
					     atoi(attributeset_get_first
						  (Attr, ATTR_HEIGHT)));
		/*
		 * If this entry has an action which we didn't specify with a
		 * signal name we execute when the text changes.
		 */
		if (attributeset_is_avail(Attr, ATTR_ACTION)) {
			char  *act;
			gchar *signal;

			act = attributeset_get_first(Attr, ATTR_ACTION);
			signal = attributeset_get_this_tagattr(Attr, 
					ATTR_ACTION, "signal");
			while (act != NULL) {
				if (signal == 0)
					gtk_signal_connect(GTK_OBJECT(Widget),
							   "changed",
							   GTK_SIGNAL_FUNC
							   (entry_inserted),
							   (gpointer) act);
					act =
					    attributeset_get_next(Attr,
								  ATTR_ACTION);
					signal = attributeset_get_this_tagattr(
							Attr, 
							ATTR_ACTION, "signal");
			}
		}
		
		//entry_set_attributes(Tag_Attributes, Widget);

#if 0
	attribute_value = get_tag_attribute(Tag_Attributes, "max_length=");
	if (attribute_value != NULL){
		g_object_set(G_OBJECT(Widget),
				"max-length",
				atoi(attribute_value),
				NULL);
	}
#endif
		break;

	case WIDGET_CHOOSER:
#if GTK_CHECK_VERSION(2,4,0)
		Widget = create_chooser(Attr);
		push_widget(Widget, Widget_Type);
#else
		yyerror_simple("Chooser widget is not supported by"
				"this version of GTK+, you need at"
				"least GTK+ 2.4.0\n");
#endif
		break;
	case WIDGET_TREE:
#if GTK_CHECK_VERSION(2,4,0)
		Widget = create_tree(Attr, tag_attributes);
		connect_tree_signals(GTK_TREE_VIEW(Widget), Attr);
		scrolled_window = put_in_the_scrolled_window(Widget, Attr, tag_attributes);
		push_widget(scrolled_window, WIDGET_SCROLLEDW);
#else
		yyerror_simple("Tree widget is not supported by"
				"this version of GTK+, you need at"
				"least GTK+ 2.4.0\n");
#endif
		break;
		
	case WIDGET_EDIT:
#if GTK_CHECK_VERSION(2, 4, 0)
		Widget = create_edit(Attr, tag_attributes);
		scrolled_window = put_in_the_scrolled_window(Widget, Attr, tag_attributes);
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

		if (attributeset_cmp_left(Attr, ATTR_VISIBLE, "disabled"))
			gtk_widget_set_sensitive(Widget, FALSE);

		push_widget(Widget, Widget_Type);
		break;

	case WIDGET_OKBUTTON:
		Widget = gtk_button_new_from_stock(GTK_STOCK_OK);
		attributeset_set_if_unset(Attr, ATTR_LABEL, "OK");
		connect_button_signals(GTK_BUTTON(Widget), Attr);
		if (attributeset_cmp_left(Attr, ATTR_VISIBLE, "disabled"))
			gtk_widget_set_sensitive(Widget, FALSE);
		/*
		 * The OK button is a default widget in the dialog box. FIXME:
		 * it is not working because the widget is not in the window
		 * yet.
		 */
		//GTK_WIDGET_SET_FLAGS(Widget, GTK_CAN_DEFAULT);
		//gtk_widget_grab_default(Widget);

		push_widget(Widget, Widget_Type);
		break;

	case WIDGET_CANCELBUTTON:
		Widget = gtk_button_new_from_stock(GTK_STOCK_CANCEL);
		attributeset_set_if_unset(Attr, ATTR_LABEL, "Cancel");
		connect_button_signals(GTK_BUTTON(Widget), Attr);
		if (attributeset_cmp_left(Attr, ATTR_VISIBLE, "disabled"))
			gtk_widget_set_sensitive(Widget, FALSE);

		push_widget(Widget, Widget_Type);
		break;

	case WIDGET_HELPBUTTON:
		Widget = gtk_button_new_from_stock(GTK_STOCK_HELP);
		attributeset_set_if_unset(Attr, ATTR_LABEL, "Help");
		connect_button_signals(GTK_BUTTON(Widget), Attr);
		if (attributeset_cmp_left(Attr, ATTR_VISIBLE, "disabled"))
			gtk_widget_set_sensitive(Widget, FALSE);

		push_widget(Widget, Widget_Type);
		break;

	case WIDGET_YESBUTTON:
		Widget = gtk_button_new_from_stock(GTK_STOCK_YES);
		attributeset_set_if_unset(Attr, ATTR_LABEL, "Yes");
		connect_button_signals(GTK_BUTTON(Widget), Attr);
		if (attributeset_cmp_left(Attr, ATTR_VISIBLE, "disabled"))
			gtk_widget_set_sensitive(Widget, FALSE);

		push_widget(Widget, Widget_Type);
		break;

	case WIDGET_NOBUTTON:
		Widget = gtk_button_new_from_stock(GTK_STOCK_NO);
		attributeset_set_if_unset(Attr, ATTR_LABEL, "No");
		connect_button_signals(GTK_BUTTON(Widget), Attr);
		if (attributeset_cmp_left(Attr, ATTR_VISIBLE, "disabled"))
			gtk_widget_set_sensitive(Widget, FALSE);

		push_widget(Widget, Widget_Type);
		break;

	case WIDGET_BUTTON:
		Widget = create_button(Attr, tag_attributes);
		connect_button_signals(GTK_BUTTON(Widget), Attr);
		if (attributeset_cmp_left(Attr, ATTR_VISIBLE, "disabled"))
			gtk_widget_set_sensitive(Widget, FALSE);
		push_widget(Widget, Widget_Type);
		break;
		
	case WIDGET_GVIM:
		Widget = create_gvim(Attr);
		push_widget(Widget, Widget_Type);
		break;
		
	case WIDGET_MENUBAR:
		Widget = create_menubar(Attr, pop());
		push_widget(Widget, Widget_Type);
		break;

	case WIDGET_MENU:
		attributeset_set_if_unset(Attr, ATTR_LABEL, "Unlabelled menu");
		Widget = create_menu(Attr, pop());
		push_widget(Widget, Widget_Type);
		break;
	case WIDGET_MENUITEM:
		attributeset_set_if_unset(Attr, ATTR_LABEL, "Unlabelled menu item");
		Widget = create_menuitem(Attr, tag_attributes);
		push_widget(Widget, Widget_Type);
		break;
	case WIDGET_MENUSEP:
		Widget = gtk_separator_menu_item_new();
		push_widget(Widget, Widget_Type);
		break;
	case WIDGET_CHECKBOX:
		/*
		 **
		 */
		attributeset_set_if_unset(Attr, ATTR_LABEL,
					  "Uninitialized checkbox");
		/*
		 **
		 */
		Widget =
		    gtk_check_button_new_with_label(attributeset_get_first
						    (Attr, ATTR_LABEL));
		/*
		 **
		 */
		if (attributeset_cmp_left(Attr, ATTR_DEFAULT, "true") ||
		    attributeset_cmp_left(Attr, ATTR_DEFAULT, "yes"))
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON
						     (Widget), TRUE);
		/*
		 ** Checkboxes also can take actions...
		 */
		if (attributeset_is_avail(Attr, ATTR_ACTION)) {
			char *act;
			act = attributeset_get_first(Attr, ATTR_ACTION);
			while (act != NULL) {
				gtk_signal_connect(GTK_OBJECT(Widget),
						   "toggled",
						   GTK_SIGNAL_FUNC
						   (button_toggled),
						   (gpointer) act);
				act =
				    attributeset_get_next(Attr,
							  ATTR_ACTION);
			}
		}

		if (attributeset_cmp_left(Attr, ATTR_VISIBLE, "disabled"))
			gtk_widget_set_sensitive(Widget, FALSE);

		push_widget(Widget, Widget_Type);
		break;

	case WIDGET_RADIO:
		attributeset_set_if_unset(Attr, ATTR_LABEL, "Unnamed");
		/* 
		 ** It is a little strange hack with the radiobuttons. Not easy
		 ** to force them work together.
		 */
		if (LastRadioButton == NULL) {
			Widget = gtk_radio_button_new_with_label(NULL,
								 attributeset_get_first
								 (Attr,
								  ATTR_LABEL));
			LastRadioButton = Widget;
		} else {
			Widget =
			    gtk_radio_button_new_with_label_from_widget
			    (GTK_RADIO_BUTTON(LastRadioButton),
			     attributeset_get_first(Attr, ATTR_LABEL));
//        gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON(Widget),
//                                      FALSE );
		}

		/*
		 ** Radio buttons can have a default value.
		 */
		if (attributeset_cmp_left(Attr, ATTR_DEFAULT, "true") ||
		    attributeset_cmp_left(Attr, ATTR_DEFAULT, "yes"))
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON
						     (Widget), TRUE);

		/*
		 ** Radiobuttons also can take actions...
		 */
		if (attributeset_is_avail(Attr, ATTR_ACTION)) {
			char *act;
			act = attributeset_get_first(Attr, ATTR_ACTION);
			while (act != NULL) {
				gtk_signal_connect(GTK_OBJECT(Widget),
						   "toggled",
						   GTK_SIGNAL_FUNC
						   (button_toggled),
						   (gpointer) act);
				act =
				    attributeset_get_next(Attr,
							  ATTR_ACTION);
			}
		}
		
		push_widget(Widget, Widget_Type);

		if (attributeset_cmp_left(Attr, ATTR_VISIBLE, "disabled"))
			gtk_widget_set_sensitive(Widget, FALSE);
		break;

	case WIDGET_PROGRESS:
		Widget = gtk_progress_bar_new();
		/*
		 *
		 */
		if (attributeset_is_avail(Attr, ATTR_LABEL)) {
			char *t;
			t = attributeset_get_first(Attr, ATTR_LABEL);
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
		scrolled_window = put_in_the_scrolled_window(Widget, Attr, tag_attributes);
		push_widget(scrolled_window, WIDGET_SCROLLEDW);
		
		/*
		 ** The LIST widget can handle actions...
		 */
		gtk_signal_connect(GTK_OBJECT(Widget),
						   "selection_changed",
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
		scrolled_window = put_in_the_scrolled_window(Widget, Attr, tag_attributes);
		push_widget(scrolled_window, WIDGET_SCROLLEDW);		
		
		/*
		 ** We need connect the select_row to a function to store the
		 ** selected row.
		 */
		g_signal_connect(G_OBJECT(Widget), "select_row",
				 G_CALLBACK(table_selection),
				 (gpointer) Attr);
		break;
		
	case WIDGET_NOTEBOOK:
		{
			stackelement s;
			GtkWidget *Label;
			list_t *lines = NULL;
			
			char *labels = 
				get_tag_attribute(tag_attributes, "labels");
			if (labels != NULL)
				lines = linecutter(strdup(labels), '|');
				
			s = pop();
			Widget = gtk_notebook_new();
			
			for (n = 0; n < s.nwidgets; ++n){
				if (lines != NULL &&
						lines->n_lines > n)
					Label = gtk_label_new(lines->line[n]);
				else
					Label = gtk_label_new("Unnamed");
				
				gtk_notebook_append_page(GTK_NOTEBOOK(Widget), s.widgets[n], Label);
			}
			push_widget(Widget, Widget_Type);
			LastRadioButton = NULL;
		}
		break;

	case WIDGET_VBOX:
		{
			/*
			 ** Creating a box is not a simple process, because we have to
			 ** add the widgets to it. First we remove the widgets from the
			 ** top of the stack (only one stack element with more widgets,
			 ** thanks to the SUM instruction), then we add it to the box.
			 ** The last step is pushing the box back to the stack.
			 */
			stackelement s;
			s = pop();
			Widget = gtk_vbox_new(FALSE, 5);
			for (n = 0; n < s.nwidgets; ++n)
				if (s.widgettypes[n] == WIDGET_EDIT ||
				    s.widgettypes[n] == WIDGET_FRAME ||
				    s.widgettypes[n] == WIDGET_SCROLLEDW)
					gtk_box_pack_start(GTK_BOX(Widget),
							   s.widgets[n],
							   TRUE, TRUE, 0);
				else
					gtk_box_pack_start(GTK_BOX(Widget),
							   s.widgets[n],
							   FALSE, FALSE,
							   0);

			push_widget(Widget, Widget_Type);
			/*
			 ** The box widgets are holding the radiobuttons to groups, so
			 ** one radiobutton can turn off the others. 
			 */
			LastRadioButton = NULL;
		}
		break;
	case WIDGET_HBOX:
		{
			/*
			 ** The hbox is very similar to vbox...
			 */
			stackelement s;
			s = pop();
			Widget = gtk_hbox_new(FALSE, 5);
			for (n = s.nwidgets - 1; n >= 0; --n)
				if (s.widgettypes[n] == WIDGET_EDIT ||
				    s.widgettypes[n] == WIDGET_FRAME ||
				    s.widgettypes[n] == WIDGET_SCROLLEDW ||
				    s.widgettypes[n] == WIDGET_ENTRY)
					gtk_box_pack_end(GTK_BOX(Widget),
							 s.widgets[n],
							 TRUE, TRUE, 0);
				else {
					/*
					 * I can't make it work... I mean to set the expand and fill
					 * from the dialog description.
					 */ 
					gtk_box_pack_end(GTK_BOX(Widget),
							 s.widgets[n],
							 FALSE, // Expand
							 FALSE, // Fill
							 0);
				}

			push_widget(Widget, Widget_Type);
			/*
			 ** The box widgets holds the radiobuttons to groups, so
			 ** one radiobutton can turn off the others. 
			 */
			LastRadioButton = NULL;
		}
		break;

	case WIDGET_FRAME:
		{
			stackelement s;
			GtkWidget *vbox;
			s = pop();
			vbox = gtk_vbox_new(FALSE, 5);
			gtk_container_set_border_width(GTK_CONTAINER(vbox), 5);

			for (n = 0; n < s.nwidgets; ++n)
				if (s.widgettypes[n] == WIDGET_EDIT ||
				    s.widgettypes[n] == WIDGET_FRAME ||
				    s.widgettypes[n] == WIDGET_SCROLLEDW)
					gtk_box_pack_start(GTK_BOX(vbox),
							   s.widgets[n],
							   TRUE, TRUE, 0);
				else
					gtk_box_pack_start(GTK_BOX(vbox),
							   s.widgets[n],
							   FALSE, FALSE,
							   0);

			attributeset_set_if_unset(Attr, ATTR_LABEL, "");
			Widget = gtk_frame_new(attributeset_get_first
						  (Attr, ATTR_LABEL));
			gtk_container_add(GTK_CONTAINER(Widget), vbox);
		}
		push_widget(Widget, Widget_Type);
		/*
		 ** The frame widget holds the radiobuttons to groups, so
		 ** one radiobutton can turn off the others. 
		 */
		LastRadioButton = NULL;
		break;

	case WIDGET_WINDOW:
		{
		stackelement s;
		s = pop();
		Widget = create_window(Attr, tag_attributes);
		gtk_container_add(GTK_CONTAINER (Widget), s.widgets[0]);
		push_widget(Widget, Widget_Type);
		}
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

	variables_set_attributes(attributeset_get_first
				 (Attr, ATTR_VARIABLE), Attr);

	/*
	 * This is where we set the properties and connect signals 
	 * for the widget.
	 */
	//widget_set_tag_attributes(Widget, tag_attributes);
	g_signal_connect(G_OBJECT(Widget),
				"realize",
				(GCallback)on_any_widget_realized,
				(gpointer) tag_attributes);
	widget_connect_signals(Widget, Attr);

	PIP_DEBUG("Variable created.");

	return 0;
}


/* The next few functions operates on stack
   Miert nem kapja meg az adatokat parameterben es foglalkozik
   a veremmel a hivo?
 */
stackelement _sum(stackelement a, stackelement b)
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
	instruction inst;
	int sub_attribute;

	PIP_DEBUG("Start argument='%s' attributes: %p", argument, attributes);
	
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
