#!/bin/sh

ls -lha | grep "^d" | awk '{print "dir_o|" $1 "|" $8}'
ls -lha | grep "^-" | awk '{print "gexec|" $1 "|" $8}'
