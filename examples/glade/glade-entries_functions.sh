#!/bin/sh 

gtkdialog --glade-xml=glade-entries_functions.glade \
          --include=glade-entries_functions.functions \
          --program=login_window
