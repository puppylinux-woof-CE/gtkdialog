bison = generator(find_program('bison'),
                  output: ['@BASENAME@.c', '@BASENAME@.h'],
                  arguments: ['@INPUT@', '--defines=@OUTPUT1@', '--output=@OUTPUT0@', '-p', 'gtkdialog_'])

flex = generator(find_program('flex'),
                 output: '@BASENAME@.c',
                 arguments: ['-P', 'gtkdialog_', '-o', '@OUTPUT@', '@INPUT@'])

src = [
	'actions.c',
	'attributes.c',
	'automaton.c',
	'glade_support.c',
	'gtkdialog.c',
	'printing.c',
	'scrolling.c',
	'signals.c',
	'stack.c',
	'stringman.c',
	'tag_attributes.c',
	'variables.c',
	'widget_button.c',
	'widget_checkbox.c',
	'widget_colorbutton.c',
	'widget_combobox.c',
	'widget_comboboxtext.c',
	'widget_edit.c',
	'widget_entry.c',
	'widget_eventbox.c',
	'widget_expander.c',
	'widget_fontbutton.c',
	'widget_frame.c',
	'widget_hbox.c',
	'widget_hscale.c',
	'widget_hseparator.c',
	'widget_list.c',
	'widget_menubar.c',
	'widget_menuitem.c',
	'widget_notebook.c',
	'widget_pixmap.c',
	'widget_progressbar.c',
	'widget_radiobutton.c',
	'widgets.c',
	'widget_spinbutton.c',
	'widget_statusbar.c',
	'widget_table.c',
	'widget_template.c',
	'widget_terminal.c',
	'widget_text.c',
	'widget_timer.c',
	'widget_tree.c',
	'widget_vbox.c',
	'widget_window.c'
]

cfg = configuration_data(
	{
		'HAVE_GTK': gtkver,
	}
)

cfg.set_quoted('PACKAGE', meson.project_name())
cfg.set_quoted('PACKAGE_NAME', meson.project_name())
cfg.set_quoted('PACKAGE_VERSION', meson.project_version())
cfg.set_quoted('BUILD_DETAILS', '') # TODO

dep = [gtk, gthread]

if vte.found()
	dep += [vte]
	cfg.set('HAVE_VTE', 1)
else
	cfg.set('HAVE_VTE', 0)
endif
if gtkver == 3 and gtk_layer_shell.found()
	dep += [gtk_layer_shell.get_variable('gtk_layer_shell')]
	cfg.set('HAVE_GTK_LAYER_SHELL', 1)
else
	cfg.set('HAVE_GTK_LAYER_SHELL', 0)
endif

configure_file(
	output : 'config.h',
	configuration : cfg,
)

gtkdialog = executable(
	'gtkdialog',
	bison.process('gtkdialog_parser.y'),
	flex.process('gtkdialog_lexer.l'),
	src,
	dependencies: dep,
	install: true,
)
