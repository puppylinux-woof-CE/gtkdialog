project('gtkdialog', 'c', version: '0.8.4', license: 'GPLv2')

gthread = dependency('gthread-2.0')

gtkver = get_option('gtkver')

if gtkver == 3
	gtk = dependency('gtk+-3.0')
	vte = dependency('vte-2.91', required: false)
else
	gtk = dependency('gtk+-2.0')
	vte = dependency('vte', required: false)
endif

subdir('src')