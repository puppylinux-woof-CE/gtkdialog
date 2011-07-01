#include "variables.h"
#include "gtkdialog.h"
#include "widgets.h"

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
	variable *toset;
	gint      index;

#ifdef DEBUG
	fprintf(stderr, "%s(): variable '%s'.\n", __func__, name);
	fflush(stderr);
#endif
	g_assert(name != NULL && value != NULL);
	
	toset = _tree_find(name, NULL);
	if (toset == NULL)
		return (NULL);

	switch (toset->Type) {
		case WIDGET_ENTRY:
			gtk_entry_set_text(GTK_ENTRY(toset->Widget), value);
			gtk_signal_emit_by_name(GTK_OBJECT(toset->Widget),
						"changed");
			break;
		case WIDGET_COMBOBOXTEXT:
			index = gtk_combo_box_get_active(GTK_COMBO_BOX(toset->Widget));
#ifdef DEBUG
			fprintf(stderr, "%s: index=%i name=%s value=%s\n", __func__,
				index, name, value);
#endif
			if (index < 0) index = 0;
			gtk_combo_box_insert_text(
				GTK_COMBO_BOX(toset->Widget), index, value);
			gtk_combo_box_set_active(GTK_COMBO_BOX(toset->Widget), index);
			break;
		default:
			yywarning("Set not implemented for this widget.");
	}

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
		case WIDGET_EDIT:
			widget_edit_save(var);
			break;
		case WIDGET_COMBOBOXTEXT:
			save_comboboxtext_to_file(var);
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
	variable *var;
	
	g_assert(name != NULL);
#ifdef DEBUG
	g_message("%s(%s)", __func__, name);
#endif
	var = _tree_find(name, NULL);
	
	if (var == NULL || var->Widget == NULL)
		return NULL;
	
	switch (var->Type) {
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
		case WIDGET_PIXMAP:
			widget_pixmap_refresh(var);
			break;
		case WIDGET_BUTTON:
			widget_button_refresh(var);
			break; 
		case WIDGET_COMBOBOXTEXT:
			widget_comboboxtext_refresh(var);
			break;
#ifdef DEBUG
		default:
			if (!option_no_warning)
				g_warning("%s(): Refresh not implemented "
					"ont his widget.", __func__);
#endif
	}
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
	char             *value;
	GList            *itemlist;
	size_t            length;
	gint              n;
	gint              column;
	gchar  		     *tmp;
	GtkTreeModel	 *model;
	GtkTreeIter   	  iter;
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
		if (actual->Type == WIDGET_LIST) {
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
		}
		

		if (actual->Type == WIDGET_TREE) {			
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
		}

		/* Thunor: I've noticed that the existing combobox widget isn't
		 * completely dumped, but it's my new widget so I'll be thorough :) */
		if (actual->Type == WIDGET_COMBOBOXTEXT) {
			line = g_strdup_printf("%s_ALL=\"", actual->Name);
			model = gtk_combo_box_get_model(GTK_COMBO_BOX(actual->Widget));
			if (gtk_tree_model_get_iter_first(model, &iter)) {
				gtk_tree_model_get(model, &iter, 0, &text, -1);
				tmp = g_strconcat(line, "'", text, "'", NULL);
				g_free(line);
				line = tmp;
				g_free(text);
				while (gtk_tree_model_iter_next(model, &iter)) {
					gtk_tree_model_get(model, &iter, 0, &text, -1);
					tmp = g_strconcat(line, " '", text, "'", NULL);
					g_free(line);
					line = tmp;
					g_free(text);
				}
			}
			tmp = g_strconcat(line, "\"\n", NULL);
			g_free(line); line = NULL;
			putenv(tmp);
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
	char             *value;
	GList            *itemlist;
	gint              n;
	gint              column;
	gchar  		 *tmp;
	GtkTreeModel	 *model;
	GtkTreeIter   	  iter;
	gchar            *text;
	gchar            *line;

	if (actual == NULL)
		actual = root;
	
	if (actual == NULL)
		return;
	
	if (actual->left != NULL)
		print_variables(actual->left);

	if (actual->Widget != NULL && !actual->autonamed) {
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
		/*
		 * If  this is a list we print all the items also.
		 */
		n = 0;
		if (actual->Type == WIDGET_LIST) {
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
		}

		if (actual->Type == WIDGET_TREE) {
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
		}

		/* Thunor: I've noticed that the existing combobox widget isn't
		 * completely dumped, but it's my new widget so I'll be thorough :) */
		if (actual->Type == WIDGET_COMBOBOXTEXT) {
			line = g_strdup_printf("%s_ALL=\"", actual->Name);
			model = gtk_combo_box_get_model(GTK_COMBO_BOX(actual->Widget));
			if (gtk_tree_model_get_iter_first(model, &iter)) {
				gtk_tree_model_get(model, &iter, 0, &text, -1);
				tmp = g_strconcat(line, "'", text, "'", NULL);
				g_free(line);
				line = tmp;
				g_free(text);
				while (gtk_tree_model_iter_next(model, &iter)) {
					gtk_tree_model_get(model, &iter, 0, &text, -1);
					tmp = g_strconcat(line, " '", text, "'", NULL);
					g_free(line);
					line = tmp;
					g_free(text);
				}
			}
			tmp = g_strconcat(line, "\"\n", NULL);
			g_printf("%s", tmp);
			g_free(line);
			g_free(tmp);
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
	GtkTreeModel     *model;
	GtkTreeIter       iter;
	gint              handler_id;
	gint              rowcount;
	gint              index;

#ifdef DEBUG
	fprintf(stderr, "%s(): variable: %s\n", __func__, name);
	fflush(stderr);
#endif

	toclear = _tree_find(name, NULL);
	if (toclear == NULL)
		return (NULL);

	switch (toclear->Type) {
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
		case WIDGET_COMBOBOXTEXT:
			model = gtk_combo_box_get_model(GTK_COMBO_BOX(toclear->Widget));
			if (gtk_tree_model_get_iter_first(model, &iter)) {
				/* We'll manage signals ourselves */
				/* Block the signal handler */
				handler_id = (gint)g_object_get_data(
					G_OBJECT(toclear->Widget), "handler_id");
				g_signal_handler_block(toclear->Widget, handler_id);

				/* Record the currently selected index */
				index = gtk_combo_box_get_active(GTK_COMBO_BOX(toclear->Widget));

				/* Count the number of rows in the GtkComboBox */
				rowcount = 1;
				while (gtk_tree_model_iter_next(model, &iter)) rowcount++;
#ifdef DEBUG
				fprintf(stderr, "%s: rowcount=%i\n", __func__, rowcount);
#endif
				/* Delete the rows */
				while (rowcount--)
					gtk_combo_box_remove_text(
						GTK_COMBO_BOX(toclear->Widget), rowcount);

				/* Unblock the signal handler */
				g_signal_handler_unblock(toclear->Widget, handler_id);

				/* The widget will now be empty and its active index
				 * will be -1, so if the recorded index pre-clearing
				 * wasn't -1 then we'll emit a changed signal */
				if (index > -1)
					g_signal_emit_by_name(GTK_OBJECT(toclear->Widget), "changed");
			}
			break;

		default:
			yywarning("Clear not implemented for this widget.");
	}

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
	GList            *empty = NULL;
	variable         *toclear;
	gint              selectionmode;
	GList            *selectedrows, *row;
	GList            *rowreferences = NULL;
	gint              index;
	gint              handler_id;

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

	/*
	 * Removing the selected item or text range from the widget.
	 */
	switch (toclear->Type) {
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
			
		case WIDGET_COMBOBOXTEXT:
			/* Thunor: I'm limiting the possible number of changed events
			 * here as I'm auto-selecting the previous item after deletion */
			if ((index = gtk_combo_box_get_active(GTK_COMBO_BOX(toclear->Widget))) >= 0) {
				/* Block the signal handler on the delete */
				handler_id = (gint)g_object_get_data(
					G_OBJECT(toclear->Widget), "handler_id");
				g_signal_handler_block(toclear->Widget, handler_id);
				/* Delete the selected item */
				gtk_combo_box_remove_text(GTK_COMBO_BOX(toclear->Widget), index);
				/* Unblock the signal handler */
				g_signal_handler_unblock(toclear->Widget, handler_id);
			}
			/* Auto-select the previous item rather than leaving it empty */
			if (index > 0) index--;
			gtk_combo_box_set_active(GTK_COMBO_BOX(toclear->Widget), index);
			break;

		default:
			yywarning("Delete not implemented for this widget.");
	}

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
