#
# We do this becouse this way we can use multiple parsers in a single binary
# program.
#
AM_LFLAGS=-P$$(basename $@ lexer.c) -olex.yy.c
AM_YFLAGS=-d -p $$(basename $@ parser.c)
BUILT_SOURCES = \
		gtkdialog_parser.h 

bin_PROGRAMS = gtkdialog 
gtkdialog_SOURCES = \
		    gtkdialog.c gtkdialog.h \
		    macros.h \
		    printing.h printing.c \
		    variables.h variables.c \
		    gtkdialog_parser.y gtkdialog_lexer.l \
		    stack.h stack.c \
		    automaton.c automaton.h \
		    attributes.c attributes.h \
		    stringman.c stringman.h \
		    widgets.c widgets.h \
		    actions.c actions.h \
		    tag_attributes.h tag_attributes.c \
		    glade_support.c glade_support.h \
		    widget_button.c widget_button.h \
		    widget_comboboxtext.c widget_comboboxtext.h \
		    widget_notebook.c widget_notebook.h \
		    widget_pixmap.c widget_pixmap.h \
		    widget_spinbutton.c widget_spinbutton.h \
		    widget_timer.c widget_timer.h

AM_CFLAGS = $(GTK_CFLAGS) \
	    $(GTHREAD_CFLAGS) \
	    $(GLADE_LIB_CFLAGS) -DHAVE_GLADE_LIB=$(HAVE_GLADE_LIB)

LIBS = $(GTK_LIBS) \
       $(GTHREAD_LIBS) \
       $(GLADE_LIB_LIBS) \
       @LIBS@

