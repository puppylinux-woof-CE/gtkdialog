/*
 * variables.c:
 * Gtkdialog - A small utility for fast and easy GUI building.
 * Copyright (C) 2003-2007  László Pere <pipas@linux.pte.hu>
 * Copyright (C) 2011 Thunor <thunorsif@hotmail.com>
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

#include "gtkdialog.h"
#include "variables.h"
#include "widgets.h"
#include "widget_comboboxtext.h"
#include "widget_pixmap.h"
#include "widget_spinbutton.h"
#include "widget_timer.h"

extern gboolean option_no_warning;

/*
** Local functions...
*/
static variable *_tree_find(const char *name, variable * actual);
static void _variables_export(variable * actual);

extern GtkWidget *window;	/* The actual window */
variable *root = NULL;

#ifdef DEBUG
void 
variables_print_one(variable * var)
{
	fprintf(stderr, "Name: %s\n", var->Name);
	fprintf(stderr, "  Widget: %p\n", var->Widget);
	fprintf(stderr, "  Type: %s\n", widgets_to_str(var->Type));
	fprintf(stderr, "  Parent: %p\n", var->ParentWindow);
	fflush(stderr);
}
#endif

/*
** This function will create a new variable.
*/
variable *
variables_new(const char *name)
{
	variable *new;
#ifdef DEBUG
	g_message("%s(): start '%s'.", __func__, name);
#endif
	/* 
	 ** If the variable exists we simply returns without making a 
	 ** a warning. 
	 */
	if (variables_is_avail_by_name(name))
		return (variables_get_by_name(name));

	new = g_malloc(sizeof(variable));
	strncpy(new->Name, name, NAMELEN);
	/* 
	 ** Setting the defaults for this variable.
	 */
	new->Widget = NULL;
	new->Attributes = NULL;
	new->Type = 0;
	new->row = -1;
	new->column = -1;
	new->ncolumns = -1;

	new->left = NULL;
	new->right = NULL;

	_tree_insert(new, NULL);
#ifdef DEBUG
	g_message("%s(): end '%s'.", __func__, name);
#endif
	return new;
}

/*
** This function will create a new variable with widget and type.
*/
variable *
variables_new_with_widget(
		AttributeSet *Attr, 
		tag_attr     *widget_tag_attr,
		GtkWidget    *widget, 
		int           type)
{
	char *name;
	variable *var;
	int autonamed = FALSE;

	g_assert(Attr != NULL);
	g_assert(widget != NULL);

#ifdef DEBUG
	g_message("%s(): Starting.", __func__);
#endif
	/*
	 ** If the widget have no name we create a default one for it.
	 */
	if (!attributeset_is_avail(Attr, ATTR_VARIABLE)) {
		attributeset_insert(Attr,
				    ATTR_VARIABLE,
				    (char *) str_default_name(type));
		autonamed = TRUE;
	}

	name = attributeset_get_first(Attr, ATTR_VARIABLE);

	/* 
	 ** If the variable exists we simply returns without making a 
	 ** a warning. 
	 */
	if (!variables_is_avail_by_name(name))
		var = variables_new(name);
	else
		var = variables_get_by_name(name);

	g_assert(var != NULL);

	var->Widget = widget;
	var->Type = type;
	var->autonamed = autonamed;
	var->Attributes = Attr;
	var->widget_tag_attr = widget_tag_attr;
#ifdef DEBUG
	g_message("%s(): End.", __func__);
#endif
	return (var);
}


variable *
variables_set_widget(const char *name, 
		GtkWidget * widget)
{
	variable *var;
#ifdef DEBUG
	g_message("%s(): variable '%s'.", __func__, name);
#endif
	var = variables_get_by_name(name);
	if (var == NULL)
		var = variables_new(name);

	var->Widget = widget;
	return (var);
}

#if 0
variable *
variables_set_parent(const char *name, 
		GtkWidget * parent)
{
	variable *var;
#ifdef DEBUG
	g_message("%s(): Start with '%s'", __func__, name);
#endif
	var = variables_get_by_name(name);
	if (var == NULL)
		var = variables_new(name);

	var->ParentWindow = parent;
#ifdef DEBUG
	g_message("%s(): End with '%s'", __func__, name);
#endif
	return var;
}
#endif

variable *
variables_set_type(const char *name, 
		int type)
{
	variable *var;
#ifdef DEBUG
	fprintf(stderr, "%s(): variable '%s'.\n", __func__, name);
	fflush(stderr);
#endif
	var = variables_get_by_name(name);
	if (var == NULL)
		var = variables_new(name);

	var->Type = type;
	return (var);
}

variable *
variables_set_attributes(const char *name, 
		AttributeSet * a)
{
	variable *var;
#ifdef DEBUG
	g_message("%s(): start '%s'", __func__, name);
#endif
	var = variables_get_by_name(name);
	if (var == NULL)
		var = variables_new(name);

	var->Attributes = a;
	return (var);
}


variable *
variables_set_row_column(const char *name, 
		int row, 
		int column)
{
	variable *toset;
#ifdef DEBUG
	fprintf(stderr, "%s(): variable: %s\n", __func__, name);
	fflush(stderr);
#endif
	toset = _tree_find(name, NULL);
	if (toset == NULL)
		return (NULL);

	toset->row = row;
	toset->column = column;
	return (toset);
}



/*
** This function will set the value of the given variable. That mean
** it will set a widget's data or insert data to the widget as the
** type of the widget make it clear. 
*/
variable *
variables_set_value(const char *name, 
		const char *value)
{
	variable         *toset;
	gchar            *string;

#ifdef DEBUG
	fprintf(stderr, "%s(): variable '%s'.\n", __func__, name);
	fflush(stderr);
#endif
	g_assert(name != NULL && value != NULL);
	
	toset = _tree_find(name, NULL);

	if (toset == NULL)
		return (NULL);

	/* If the custom attribute "block-function-signals" is true
	 * then block signals whilst performing this function */
	if (toset->widget_tag_attr &&
		((string = get_tag_attribute(toset->widget_tag_attr, "block_function_signals")) ||
		(string = get_tag_attribute(toset->widget_tag_attr, "block-function-signals"))) &&
		((strcasecmp(string, "true") == 0) || (strcasecmp(string, "yes") == 0) ||
		(atoi(string) == 1))) {
		GTKD_FUNCTION_SIGNALS_BLOCK;
	}

	switch (toset->Type) {

		case WIDGET_COMBOBOXENTRY:
		case WIDGET_COMBOBOXTEXT:
			widget_comboboxtext_fileselect(toset, name, value);
			break;

		case WIDGET_PIXMAP:
			widget_pixmap_fileselect(toset, name, value);
			break;

		case WIDGET_SPINBUTTON:
			widget_spinbutton_fileselect(toset, name, value);
			break;

		case WIDGET_TIMER:
			widget_timer_fileselect(toset, name, value);
			break;

		case WIDGET_ENTRY:
			gtk_entry_set_text(GTK_ENTRY(toset->Widget), value);
			break;

		default:
			yywarning("Set-value not implemented for this widget.");
	}

	GTKD_FUNCTION_SIGNALS_RESET;

	return (toset);
}

variable *
variables_save(const char *name)
{
	variable *var;
	var = _tree_find(name, NULL);
	if (var == NULL)
		return (NULL);

	if (var->Widget == NULL)
		return (NULL);

	switch (var->Type) {

		case WIDGET_COMBOBOXENTRY:
		case WIDGET_COMBOBOXTEXT:
			widget_comboboxtext_save(var);
			break;

		case WIDGET_PIXMAP:
			widget_pixmap_save(var);
			break;

		case WIDGET_SPINBUTTON:
			widget_spinbutton_save(var);
			break;

		case WIDGET_TIMER:
			widget_timer_save(var);
			break;

		case WIDGET_ENTRY:
			save_entry_to_file(var);
			break;
		case WIDGET_EDIT:
			widget_edit_save(var);
			break;
		case WIDGET_VSCALE:
		case WIDGET_HSCALE:
			save_scale_to_file(var);
			break;
		case WIDGET_MENU:
		case WIDGET_MENUITEM:
			if (GTK_IS_CHECK_MENU_ITEM(var->Widget))
				save_menuitem_to_file(var);
			break;
		default:
			yywarning("Save not implemented for this widget.");
	}
	return (var);
}



/*
** This function will actualize the variable by reinitializing 
** widget.
*/
variable *
variables_refresh(const char *name)
{
	variable         *var;
	gchar            *string;
	gint              initialised = FALSE;

	g_assert(name != NULL);

#ifdef DEBUG
	g_message("%s(%s)", __func__, name);
#endif

	var = _tree_find(name, NULL);

	if (var == NULL || var->Widget == NULL)
		return NULL;

	g_assert(var->Attributes != NULL);

	/* Get initialised state of widget */
	if (g_object_get_data(G_OBJECT(var->Widget), "initialised") != NULL)
		initialised = (gint)g_object_get_data(G_OBJECT(var->Widget), "initialised");

	/* If the custom attribute "block-function-signals" is true
	 * then block signals whilst performing this function */
	if (var->widget_tag_attr &&
		((string = get_tag_attribute(var->widget_tag_attr, "block_function_signals")) ||
		(string = get_tag_attribute(var->widget_tag_attr, "block-function-signals"))) &&
		((strcasecmp(string, "true") == 0) || (strcasecmp(string, "yes") == 0) ||
		(atoi(string) == 1))) {
		GTKD_FUNCTION_SIGNALS_BLOCK;
	}

	switch (var->Type) {

		case WIDGET_COMBOBOXENTRY:
		case WIDGET_COMBOBOXTEXT:
			widget_comboboxtext_refresh(var);
			break;

		case WIDGET_PIXMAP:
			widget_pixmap_refresh(var);
			break;

		case WIDGET_SPINBUTTON:
			widget_spinbutton_refresh(var);
			break;

		case WIDGET_TIMER:
			widget_timer_refresh(var);
			break;

		case WIDGET_ENTRY:
			widget_entry_refresh(var);
			break;
		case WIDGET_LIST:
			widget_list_refresh(var);
			break;
		case WIDGET_TABLE:
			widget_table_refresh(var);
			break;
		case WIDGET_COMBO:
			widget_combo_refresh(var);
			break;
		case WIDGET_EDIT:
			widget_edit_refresh(var);
			break;
		case WIDGET_LABEL:
			widget_label_refresh(var);
			break;
		case WIDGET_CHECKBOX:
			widget_checkbox_refresh(var);
			break;
		case WIDGET_TREE:
			widget_tree_refresh(var);
			break;
		case WIDGET_BUTTON:
			widget_button_refresh(var);
			break; 
		case WIDGET_VSCALE:
		case WIDGET_HSCALE:
			widget_scale_refresh(var);
			break;
		case WIDGET_MENU:
		case WIDGET_MENUITEM:
			widget_menuitem_refresh(var);
			break;
		default:
			if (initialised)
				yywarning("Refresh not implemented for this widget.");
			break;
	}

	if (!initialised) {
		/* Store "initialised" as a piece of widget data to record that
		 * this widget has been through this function at start-up */
		g_object_set_data(G_OBJECT(var->Widget), "initialised", (gpointer)1);
	}

	GTKD_FUNCTION_SIGNALS_RESET;

#ifdef DEBUG
	g_message("%s(): end", __func__);
#endif

	return var;
}

variable *
variables_enable(const char *name)
{
	variable *var;
#ifdef DEBUG
	fprintf(stderr, "%s(): %s\n", __func__, name);
	fflush(stderr);
#endif
	var = _tree_find(name, NULL);
	if (var == NULL)
		return (NULL);
	if (var->Widget == NULL)
		return (NULL);

	gtk_widget_set_sensitive(var->Widget, TRUE);
	return (var);
}

variable *
variables_disable(const char *name)
{
	variable *var;
#ifdef DEBUG
	fprintf(stderr, "%s(): %s\n", __func__, name);
	fflush(stderr);
#endif
	var = _tree_find(name, NULL);
	if (var == NULL)
		return (NULL);
	if (var->Widget == NULL)
		return (NULL);

	gtk_widget_set_sensitive(var->Widget, FALSE);
	return (var);
}

gboolean 
variables_is_avail_by_name(const char *name)
{
	if (_tree_find(name, NULL) == NULL)
		return (FALSE);
	else
		return (TRUE);
}

variable *variables_get_by_name(const char *name)
{
	return _tree_find(name, NULL);
}


/*
** This function insert a new tree node. The node must have a unique
** name or the function will abort the program.
*/
int 
_tree_insert(variable * new, 
		variable * actual)
{
	int compare;
	if (new == NULL) {
		fprintf(stderr, "%s(): Inserting a NULL element.\n", __func__);
		exit(EXIT_FAILURE);
	}

	if (root == NULL) {
		root = new;
		return (0);
	}

	if (actual == NULL)
		actual = root;

	compare = strncmp(new->Name, actual->Name, NAMELEN);

	if (compare == 0) {
		fprintf(stderr, "%s(): Inserting existing variable: '%s'.",
			__func__, new->Name);
		exit(EXIT_FAILURE);
	}

	if (compare < 0)
		if (actual->left == NULL) {
			actual->left = new;
			return (0);
		} else {
			return (_tree_insert(new, actual->left));
		}

	if (compare > 0)
		if (actual->right == NULL) {
			actual->right = new;
			return (0);
		} else {
			return (_tree_insert(new, actual->right));
		}
}

/*
** This function finds the variable by its name and returns the ponter
** to it.
*/
static variable *
_tree_find(const char *name, variable * actual)
{
	int compare;

	if (actual == NULL)
		actual = root;
	if (actual == NULL)
		return NULL;

	compare = strcmp(name, actual->Name);

	if (compare == 0)
		return (actual);

	if (compare < 0)
		if (actual->left != NULL)
			return _tree_find(name, actual->left);
		else
			return NULL;

	if (compare > 0)
		if (actual->right != NULL)
			return _tree_find(name, actual->right);
		else
			return NULL;
}

static gint
do_variables_count_widgets(variable *actual, gint n)
{
	if (actual == NULL)
		actual = root;

	if (actual == NULL)
		return;

	if (actual->left != NULL)
		n = do_variables_count_widgets(actual->left, n);

	if (actual->Widget != NULL) 
		++n;

	if (actual->right != NULL)
		n = do_variables_count_widgets(actual->right, n);

	return n;
}

gint 
variables_count_widgets(void) 
{
	return do_variables_count_widgets(NULL, 0);
}

/*
** This function will drop all the widgets with the given parent.
*/
void 
variables_drop_by_parent(variable *actual, GtkWidget *Parent)
{
	if (actual == NULL)
		actual = root;
	if (actual == NULL)
		return;

	if (actual->left != NULL)
		variables_drop_by_parent(actual->left, Parent);

	if (actual->Widget != NULL) {
		g_assert(GTK_IS_WIDGET(actual->Widget));
		if (gtk_widget_get_toplevel(actual->Widget) == Parent) 
			actual->Widget = NULL;
	}

	if (actual->right != NULL)
		variables_drop_by_parent(actual->right, Parent);
}

static variable *
do_find_variable_by_widget(variable *actual,
		GtkWidget *widget)
{
	variable *found;

	if (actual == NULL)
		return NULL;
	
	if (actual->left != NULL) {
		found = do_find_variable_by_widget(actual->left, widget);
		if (found != NULL)
			return found;
	}
	
	if (actual->Widget == widget)
		return actual;

	if (actual->right != NULL) {
		return do_find_variable_by_widget(actual->right, widget);
	}

	return NULL;
}

variable *
find_variable_by_widget(GtkWidget *widget)
{
	return do_find_variable_by_widget(root, widget);
}


static void 
_variables_initialize(variable *actual)
{
	char *socket_id;
	char command[128];
	int result;

#ifdef DEBUG
	fprintf(stderr, "%s: Start.\n", __func__);
	fflush(stderr);
#endif

	if (actual == NULL)
		actual = root;
	if (actual == NULL)
		return;

	if (actual->left != NULL)
		_variables_initialize(actual->left);

	if (actual->Widget != NULL && actual->Type == WIDGET_GVIM) {
		gtk_widget_show(actual->Widget);
		socket_id = attributeset_get_first(actual->Attributes,
						   ATTR_SOCKET);
		//printf("----->%p\n", actual->Widget->window); 
		//printf("----->%x\n", atoi(socket_id));        
		if (socket_id != NULL) {
			sprintf(command, "gvim --socketid %s &",
				socket_id);
			result = system(command);
		} else {
			yywarning("Socket ID is NULL\n");
		}
	}

	if (actual->right != NULL)
		_variables_initialize(actual->right);
}

static void 
_variables_export(variable *actual)
{
	gchar            *value;
	GList            *itemlist;
//	size_t            length;	Redundant
	gint              n;
	gint              column;
	gchar            *tmp;
	GtkTreeModel     *model;
	GtkTreeIter       iter;
	gchar            *text;
	gchar            *line;

#ifdef DEBUG
	g_message("%s(%p)", __func__, actual);
#endif

	if (actual == NULL)
		actual = root;
	if (actual == NULL)
		return;

#ifdef DEBUG
	g_message("    actual->name = '%s'", actual->Name);
#endif

	if (actual->left != NULL)
		_variables_export(actual->left);

	if (actual->Widget != NULL) {
		//
		// To export only the active element
		//
		value = widget_get_text_value(actual->Widget, actual->Type);

		/* 
		 ** FIXME: awfull
		 */
		if (actual->Type == WIDGET_TABLE && actual->row != -1) {
			gtk_clist_get_text(GTK_CLIST(actual->Widget),
					   actual->row, 0, &value);
		}

		if (value != NULL) {
			line = g_strdup_printf("%s=%s", actual->Name, value);
			putenv(line);
		}

		//
		// To export all of the elements in the list
		//
		switch (actual->Type) {
			case WIDGET_LIST:
				line = g_strdup_printf("%s_ALL=\"", actual->Name);
				itemlist = GTK_LIST(actual->Widget)->children;
				n = 0;
				while (itemlist != NULL) {
					if (itemlist->data == NULL) 
						itemlist = itemlist->next;
						continue;
					text = gtk_object_get_user_data(itemlist->data);
					if (n == 0)
						tmp = g_strconcat(line, "'", text, "'", NULL);
					else
						tmp = g_strconcat(line, " '", text, "'", NULL);
					g_free(line);
					line = tmp;
					++n;
					itemlist = itemlist->next;
				}
				putenv(line);
				break;

			case WIDGET_TREE:
				model = gtk_tree_view_get_model(GTK_TREE_VIEW(actual->Widget));
				gtk_tree_model_get_iter_first(model, &iter);
				/*
				 * Which column should we exportvariable *variables_get_by_name( const char *name );
				 */
				tmp = g_object_get_data(G_OBJECT(actual->Widget), "exported_column");
				if (tmp != 0)
					column = atoi(tmp) + FirstDataColumn;
				else
					column = FirstDataColumn;

				line = g_strdup_printf("%s_ALL=\"", actual->Name);
				n = 0;
				while (gtk_tree_store_iter_is_valid(GTK_TREE_STORE(model), &iter)) {
					gtk_tree_model_get(model, &iter, column, &text, -1);
					if (n == 0)
						tmp = g_strconcat(line, "'", text, "'", NULL);
					else
						tmp = g_strconcat(line, " '", text, "'", NULL);

					g_free(line);
					line = tmp;
					g_free(text);

					if (!gtk_tree_model_iter_next(GTK_TREE_MODEL(model), &iter))
						break;
					++n;
				}
				tmp = g_strconcat(line, "\"\n", NULL);
				g_free(line); line = NULL;
				putenv(tmp);
				break;

			case WIDGET_COMBOBOXENTRY:
			case WIDGET_COMBOBOXTEXT:
				tmp = widget_comboboxtext_envvar_all_construct(actual);
				putenv(tmp);
				break;
		}
	}

	if (actual->right != NULL)
		_variables_export(actual->right);
}

/*
** This function will export the variables as environment variables.
*/
void variables_export_all(void)
{
	_variables_export(NULL);
}

void variables_initialize_all(void)
{
	_variables_initialize(NULL);
}

/* 
** This function is called when we want to send the variables values
** to the standard output.
*/
void 
print_variables(variable * actual)
{
	gchar            *value;
	GList            *itemlist;
	gint              n;
	gint              column;
	gchar            *tmp;
	GtkTreeModel     *model;
	GtkTreeIter       iter;
	gchar            *text;
	gchar            *line;

	if (actual == NULL)
		actual = root;

	if (actual == NULL)
		return;

	if (actual->left != NULL)
		print_variables(actual->left);

	if (actual->Widget != NULL && !actual->autonamed) {
		//
		// To print only the active element
		//
		value = widget_get_text_value(actual->Widget, actual->Type);

		/* 
		 ** FIXME: awfull
		 */
		if (actual->Type == WIDGET_TABLE && actual->row != -1) {
			gtk_clist_get_text(GTK_CLIST(actual->Widget),
					   actual->row, 0, &value);
		}

		if (value == NULL)
			value = "";
		printf("%s=\"%s\"\n", actual->Name, value);

		//
		// To print all of the elements in the list
		//
		switch (actual->Type) {
			case WIDGET_LIST:
				n = 0;
				printf("%s_ALL=\"", actual->Name);
				itemlist = GTK_LIST(actual->Widget)->children;
				while (itemlist != NULL) {
					if (itemlist->data == NULL)
						goto next_item;
					if (n == 0)
						printf("'%s'", (char*)gtk_object_get_user_data (itemlist->data));
					else
						printf(" '%s'", (char*)gtk_object_get_user_data (itemlist->data));
next_item:
					itemlist = itemlist->next;
					++n;
				}
				printf("\"\n");
				break;

			case WIDGET_TREE:
				model = gtk_tree_view_get_model(
						GTK_TREE_VIEW(actual->Widget));
				gtk_tree_model_get_iter_first(model, &iter);
				/*
				 * Which column should we print?
				 */
				tmp = g_object_get_data(G_OBJECT(actual->Widget), "exported_column");
				if (tmp != 0) {
					column = atoi(tmp) + FirstDataColumn;
					//g_message("%s: Exported column: %d", __func__, column);
					//g_message("%s: FirstDataColumn: %d", __func__, FirstDataColumn);
				} else {
					column = FirstDataColumn;
				}

				line = g_strdup_printf("%s_ALL=\"", actual->Name);
				n = 0;
				while (gtk_tree_store_iter_is_valid(GTK_TREE_STORE(model), &iter)) {
					gtk_tree_model_get(model, &iter, column, &text, -1);
					if (n == 0)
						tmp = g_strconcat(line, "'", text, "'", NULL);
					else
						tmp = g_strconcat(line, " '", text, "'", NULL);
					g_free(line);
					line = tmp;
					g_free(text);
									
					if (!gtk_tree_model_iter_next(GTK_TREE_MODEL(model), &iter))
						break;
					++n;
				}
				tmp = g_strconcat(line, "\"\n", NULL);
				g_printf("%s", tmp);
				g_free(line);
				g_free(tmp);
				break;

			case WIDGET_COMBOBOXENTRY:
			case WIDGET_COMBOBOXTEXT:
				tmp = widget_comboboxtext_envvar_all_construct(actual);
				g_printf("%s", tmp);
				g_free(tmp);
				break;
		}
	}

	if (actual->right != NULL)
		print_variables(actual->right);

	fflush(stdout);
}


int 
append_fromto_variable(const char *from, 
		const char *to)
{
	GtkTreeModel *model;
	GtkTreeIter   iter;
	variable     *var_from, *var_to;
	char         *value;
	GtkWidget    *item;
	GList        *glist = NULL;

	g_assert(from != NULL);
	g_assert(to != NULL);

#ifdef DEBUG
	g_message("%s(): from: '%s' to: '%s'", __func__, from, to);
#endif

	var_from = _tree_find(from, NULL);
	var_to = _tree_find(to, NULL);
	if (var_from == NULL || var_to == NULL) {
		yywarning("Insert: variable not found.");
		return FALSE;
	}

	value = g_strdup(widget_get_text_value(var_from->Widget, var_from->Type));

	if (strlen(value) == 0)
		return FALSE;

	switch (var_to->Type) {
		case WIDGET_LIST:
			item = gtk_list_item_new_with_label(value);
			gtk_widget_show(item);
			gtk_object_set_user_data(GTK_OBJECT(item), (gpointer) value);
			glist = g_list_append(glist, item);

			gtk_list_prepend_items(GTK_LIST(var_to->Widget), glist);
			gtk_list_select_item(GTK_LIST(var_to->Widget), 0);
		break;
		
		case WIDGET_ENTRY:
			gtk_entry_set_text(GTK_ENTRY(var_to->Widget), value);
			break;
		
		case WIDGET_EDIT:
			gtk_text_buffer_insert_at_cursor(
					gtk_text_view_get_buffer(GTK_TEXT_VIEW(var_to->Widget)), 
					value, g_utf8_strlen(value, -1));
			break;
		case WIDGET_TREE:
			model = gtk_tree_view_get_model(GTK_TREE_VIEW(var_to->Widget));
			gtk_tree_store_append(GTK_TREE_STORE(model), &iter, NULL); 
			gtk_tree_store_set(GTK_TREE_STORE(model), &iter,
					1, value,
					-1);
			break;

#if GTK_CHECK_VERSION(2,4,0)
		case WIDGET_CHOOSER:
			gtk_file_chooser_add_shortcut_folder(
					GTK_FILE_CHOOSER(var_to->Widget), 
					value, NULL);
		break;
#endif
	default:
		yywarning("Copy not implemented for this widget.");
		return FALSE;
	}
	return TRUE;
}

/* 
** This function will clear the variable by deleting everything from
** the widget.
*/
variable *
variables_clear(const char *name)
{
	variable         *toclear;
	GList            *empty = NULL;
	gchar            *string;

#ifdef DEBUG
	fprintf(stderr, "%s(): variable: %s\n", __func__, name);
	fflush(stderr);
#endif

	toclear = _tree_find(name, NULL);
	if (toclear == NULL)
		return (NULL);

	/* If the custom attribute "block-function-signals" is true
	 * then block signals whilst performing this function */
	if (toclear->widget_tag_attr &&
		((string = get_tag_attribute(toclear->widget_tag_attr, "block_function_signals")) ||
		(string = get_tag_attribute(toclear->widget_tag_attr, "block-function-signals"))) &&
		((strcasecmp(string, "true") == 0) || (strcasecmp(string, "yes") == 0) ||
		(atoi(string) == 1))) {
		GTKD_FUNCTION_SIGNALS_BLOCK;
	}

	switch (toclear->Type) {

		case WIDGET_COMBOBOXENTRY:
		case WIDGET_COMBOBOXTEXT:
			widget_comboboxtext_clear(toclear);
			break;

		case WIDGET_PIXMAP:
			widget_pixmap_clear(toclear);
			break;

		case WIDGET_SPINBUTTON:
			widget_spinbutton_clear(toclear);
			break;

		case WIDGET_TIMER:
			widget_timer_clear(toclear);
			break;

		case WIDGET_ENTRY:
			gtk_entry_set_text(GTK_ENTRY(toclear->Widget), "");
			break;
		case WIDGET_TABLE:
			gtk_clist_clear(GTK_CLIST(toclear->Widget));
			break;
		case WIDGET_LIST:
			gtk_list_clear_items(GTK_LIST(toclear->Widget), 
					0, -1);
			break;
		case WIDGET_COMBO:
			empty = g_list_append(empty, "");
			gtk_combo_set_popdown_strings(
					GTK_COMBO(toclear->Widget), empty);
			break;
		case WIDGET_CHECKBOX:
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON
					     (toclear->Widget), FALSE);
			break;
		case WIDGET_EDIT:
			gtk_text_buffer_set_text(
				gtk_text_view_get_buffer(
					GTK_TEXT_VIEW(toclear->Widget)),
					"",
					0
					);
			break;
		default:
			yywarning("Clear not implemented for this widget.");
	}

	GTKD_FUNCTION_SIGNALS_RESET;

	return (toclear);
}

/*
** This function will remove the selected item from the widget.
*/
int 
remove_selected_variable(const char *name)
{
	GtkTreeSelection *selection;
	GtkTreeModel     *model;
	GtkTreeIter       iter;
//	GList            *empty = NULL;	Redundant
	variable         *toclear;
	gint              selectionmode;
	GList            *selectedrows, *row;
	GList            *rowreferences = NULL;
	gchar            *string;

	g_assert(name != NULL);

#ifdef DEBUG
	g_message("%s(): variable: %s", __func__, name);
#endif
	/*
	 * Searching for the given variable.
	 */
	toclear = _tree_find(name, NULL);
	if (toclear == NULL)
		return -1;

	/* If the custom attribute "block-function-signals" is true
	 * then block signals whilst performing this function */
	if (toclear->widget_tag_attr &&
		((string = get_tag_attribute(toclear->widget_tag_attr, "block_function_signals")) ||
		(string = get_tag_attribute(toclear->widget_tag_attr, "block-function-signals"))) &&
		((strcasecmp(string, "true") == 0) || (strcasecmp(string, "yes") == 0) ||
		(atoi(string) == 1))) {
		GTKD_FUNCTION_SIGNALS_BLOCK;
	}

	/*
	 * Removing the selected item or text range from the widget.
	 */
	switch (toclear->Type) {

		case WIDGET_COMBOBOXENTRY:
		case WIDGET_COMBOBOXTEXT:
			widget_comboboxtext_removeselected(toclear);
			break;

		case WIDGET_PIXMAP:
			widget_pixmap_removeselected(toclear);
			break;

		case WIDGET_SPINBUTTON:
			widget_spinbutton_removeselected(toclear);
			break;

		case WIDGET_TIMER:
			widget_timer_removeselected(toclear);
			break;


		case WIDGET_ENTRY:
			gtk_entry_set_text(GTK_ENTRY(toclear->Widget), "");
			break;

		case WIDGET_LIST:
			if (GTK_LIST(toclear->Widget)->selection != NULL)
				gtk_widget_destroy(GTK_WIDGET (GTK_LIST(toclear->Widget)-> selection->data));
			if (GTK_LIST(toclear->Widget)->children != NULL)
				gtk_list_select_item(GTK_LIST(toclear->Widget), 0);
			gtk_signal_emit_by_name(GTK_OBJECT(toclear->Widget), "selection-changed");
			break;
			
		case WIDGET_TABLE:
			if (toclear->row != -1)
				gtk_clist_remove(GTK_CLIST(toclear->Widget), toclear->row);
			break;
			
		case WIDGET_EDIT:
			gtk_text_buffer_delete_selection(gtk_text_view_get_buffer(GTK_TEXT_VIEW(toclear->Widget)), 
					FALSE, TRUE);
			break;
			
		case WIDGET_TREE:
			selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(toclear->Widget));
			selectionmode = gtk_tree_selection_get_mode(selection);
			if (selectionmode == GTK_SELECTION_NONE) {
				/* Nothing to do */
			} else if (selectionmode == GTK_SELECTION_MULTIPLE) {
				/* Thunor: New code to delete multiple selected rows.
				 * http://scentric.net/tutorial/sec-treemodel-rowref.html
				 * is a good place to learn about paths and row references.
				 * This is based on the code I added to widget_get_text_value.
				 * We get the list of selected rows as normal but we can't
				 * iterate through it and delete them one by one because the
				 * paths to the rows change, but we can convert those paths
				 * to GtkTreeRowReferences which we'll store in another list.
				 * GtkTreeRowReferences watch for row changes and maintain
				 * themselves so we can delete them one by one without
				 * worrying about the others becoming out-of-date. */
				if (gtk_tree_selection_count_selected_rows(selection)) {
					selectedrows = gtk_tree_selection_get_selected_rows(selection, &model);
					row = selectedrows;
					while (row) {
						rowreferences = g_list_append(rowreferences,
							gtk_tree_row_reference_new(model, (GtkTreePath*)(row->data)));
						row = row->next;
					}
					/* The GtkTreePaths and the GList should be freed now */
					g_list_foreach(selectedrows, (GFunc)gtk_tree_path_free, NULL);
					g_list_free(selectedrows);
					row = rowreferences;
					while (row) {
						if (gtk_tree_model_get_iter(model, &iter,
							gtk_tree_row_reference_get_path((GtkTreeRowReference*)row->data)))
							gtk_tree_store_remove(GTK_TREE_STORE(model), &iter);
						row = row->next;
					}
					/* The GList should be freed now */
					g_list_free(rowreferences);
				}
			} else {
				/* Thunor: Below is the original code that handles the
				 * default GTK_SELECTION_SINGLE mode and it's quite happy
				 * dealing with GTK_SELECTION_BROWSE too.
				 * 
				 * It didn't check that something is actually selected
				 * but since gtk_tree_selection_get_selected returns
				 * true if something is then making a simple modification
				 * seemed to be the sensible thing to do. Now there's no
				 * Gtk-CRITICAL message appearing in the terminal */
				if (gtk_tree_selection_get_selected(selection, &model, &iter))
					gtk_tree_store_remove(GTK_TREE_STORE(model), &iter);
			}
			break;

		default:
			yywarning("Delete not implemented for this widget.");
	}

	GTKD_FUNCTION_SIGNALS_RESET;

	return 0;
}

#ifdef DEBUG
/* 
** This is a debug function we use to print all variables to the 
** standard error. It will print a lot of information.
*/
void 
variables_print_debug(variable * actual)
{
	if (actual == NULL)
		actual = root;
	if (actual == NULL)
		return;

	if (actual->left != NULL)
		variables_print_debug(actual->left);

	variables_print_one(actual);

	if (actual->right != NULL)
		variables_print_debug(actual->right);
}
#endif
