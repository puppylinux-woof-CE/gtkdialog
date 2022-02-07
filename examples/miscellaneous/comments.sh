#!/bin/sh

[ -z $GTKDIALOG ] && GTKDIALOG=gtkdialog

MAIN_DIALOG='
<!--
XML-style comments like this one work anywhere but:
* inside double-quoted strings they become verbatim text;
* inside a tag they are invalid;
* comments cannot be nested.
-->
<window title="Comments" window-position="1" width-request="800" height-request="600">
	<!-- a comment -->
	<vbox scrollable="true"><!-- another comment -->
		<text wrap="false" label="not a comment:
<!-- #1 verbatim text inside double quotes -->">
		</text>
		<edit editable="false">
			<height>40</height>
			<default>"not a comment:
<!-- #2 verbatim text inside double quotes -->"</default>
		</edit>
		<entry sensitive="false">
			<!-- next line is chopped by a shell hack to avoid triggering a syntax error -->
			'${HACK# <default>unquoted<!-- inside a tag is a -->syntax error</default>}'
		</entry>
		<!-- ok button -->
		<hbox space-expand="true">
			<button use-stock="true" label="gtk-ok"></button>
			<!-- this comments out a whole button tag
			<button use-stock="true" label="gtk-ok"></button>
			-->
		</hbox>
		<hseparator></hseparator>
		<text xalign="0.5" use-markup="true" label="<b>dump of MAIN_DIALOG</b>"></text>
		<text wrap="false">
			<input>echo "$MAIN_DIALOG" | cat -n</input>
		</text>
	</vbox>
</window>
'
export MAIN_DIALOG

case $1 in
	-d | --dump) echo "$MAIN_DIALOG" ;;
	*) $GTKDIALOG --program=MAIN_DIALOG ;;
esac

# vim:ft=xml:

