project('gtkdialog', 'c', version: '0.8.5', license: 'GPLv2')

gthread = dependency('gthread-2.0')

gtkver = get_option('gtkver')

if gtkver == 3
	gtk = dependency('gtk+-3.0')
	vte = dependency('vte-2.91', required: false)
	gtk_layer_shell = subproject(
		'gtk-layer-shell',
		default_options: ['default_library=static', 'introspection=false'],
		required: false,
	)
else
	gtk = dependency('gtk+-2.0')
	vte = dependency('vte', required: false)
endif

if get_option('docs')
	subdir('doc')
	install_subdir(
	'examples', install_dir : join_paths(get_option('datadir'), 'doc')
	)
endif

subdir('src')
subdir('data')
