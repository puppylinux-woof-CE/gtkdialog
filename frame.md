# frame widget #

A [GtkFrame](http://developer.gnome.org/gtk2/2.24/GtkFrame.html) containing a [GtkVBox](http://developer.gnome.org/gtk2/2.24/GtkVBox.html)


---


## Definition ##

```
<frame label>
	widget...
	<label>text</label>
	<variable>varname</variable>
	<input>command</input>
	<input file>filename</input>
	<sensitive>state</sensitive>
	<action signal="type">activity</action>...
	<output file>filename</output>
</frame>
```

"..." denotes acceptance of multiples of the same thing.

## Tag Attributes ##

None, as the label consumes all of the space normally occupied by the tag attributes.

The following custom tag attributes are available:

None.

## Directives ##

Some of these may have tag attribute equivalents.

<a href='Hidden comment: ExportTableStart'></a>
| **Name** | **Description** | **Contents** | **Since** |
|:---------|:----------------|:-------------|:----------|
| label | Initial text |  | 0.8.1 |
| variable | Variable name |  | 0.8.1 |
| variable export="false" | Variable name, not exported to shell |  | 0.8.3 |
| input | Data input source | Shell command | 0.8.1 |
| input file | Data input source | Filename | 0.8.1 |
| sensitive | Sensitive state | `true` or `false` | 0.8.1 |
| action signal="_type_" | Execute command on signal | Shell command | 0.8.1 |
| action signal="_type_" | Perform function on signal | _function_:_parameter_ | 0.8.1 |
| action signal="_type_" condition="_type_" | Execute command on signal conditionally | Shell command | 0.8.3 |
| action signal="_type_" condition="_type_" | Perform function on signal conditionally | _function_:_parameter_ | 0.8.3 |
| output file | Data output target | Filename | 0.8.1 |
<a href='Hidden comment: ExportTableEnd'></a>

## Signals ##

There is no default signal for this widget.

The following signals are connected-up for all widgets:

[button-press-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-button-press-event), [button-release-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-button-release-event), [configure-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-configure-event), [enter-notify-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-enter-notify-event), [leave-notify-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-leave-notify-event), [focus-in-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-focus-in-event), [focus-out-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-focus-out-event), [hide](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-hide), [show](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-show), [realize](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-realize), [key-press-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-key-press-event), [key-release-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-key-release-event), [map-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-map-event), [unmap-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-unmap-event)

## Functions ##

The following functions can be performed upon this widget by any widget capable of emitting signals:

<a href='Hidden comment: ExportTableStart'></a>
| **Type** | **Description** | **Parameter** | **Since** |
|:---------|:----------------|:--------------|:----------|
| enable | Sensitise widget | Variable name | 0.8.1 |
| disable | Desensitise widget | Variable name | 0.8.1 |
| show | Show widget | Variable name | 0.8.1 |
| hide | Hide widget | Variable name | 0.8.1 |
| refresh | Reload input data | Variable name | 0.8.1 |
| save | Save widget data | Variable name | 0.8.1 |
| clear | Remove all widget data | Variable name | 0.8.1 |
<a href='Hidden comment: ExportTableEnd'></a>

The following general functions can be performed by any widget capable of emitting signals:

<a href='Hidden comment: ExportTableStart'></a>
| **Type** | **Description** | **Parameter** | **Since** |
|:---------|:----------------|:--------------|:----------|
| break | Break out of actions list | None | 0.8.3 |
| command | Execute command | Shell command | 0.8.1 |
| exit | Exit dialog | A value for the `EXIT` variable | 0.8.1 |
| closewindow | Close dialog | Variable name | 0.8.1 |
| launch | Launch dialog | Variable name | 0.8.1 |
| presentwindow | [Present](http://developer.gnome.org/gtk2/2.24/GtkWindow.html#gtk-window-present) dialog | Variable name | 0.8.1 |
<a href='Hidden comment: ExportTableEnd'></a>

## Conditions ##

The following conditions can be used within the condition attribute of action directives:

<a href='Hidden comment: ExportTableStart'></a>
| **Type** | **Description** | **Argument** | **Since** |
|:---------|:----------------|:-------------|:----------|
| active\_is\_true(_argument_) | Active state of toggle widget | Variable name | 0.8.3 |
| active\_is\_false(_argument_) | Active state of toggle widget | Variable name | 0.8.3 |
| command\_is\_true(_argument_) | Output of shell command | Shell command | 0.8.3 |
| command\_is\_false(_argument_) | Output of shell command | Shell command | 0.8.3 |
| file\_is\_true(_argument_) | Contents of a file | Filename | 0.8.3 |
| file\_is\_false(_argument_) | Contents of a file | Filename | 0.8.3 |
| sensitive\_is\_true(_argument_) | Sensitive state of widget | Variable name | 0.8.3 |
| sensitive\_is\_false(_argument_) | Sensitive state of widget | Variable name | 0.8.3 |
| visible\_is\_true(_argument_) | Visible state of widget | Variable name | 0.8.3 |
| visible\_is\_false(_argument_) | Visible state of widget | Variable name | 0.8.3 |
<a href='Hidden comment: ExportTableEnd'></a>

true means "true", "yes" or a non-zero value, false means "false", "no" or zero, therefore the shell command is expected to echo one of these values to stdout.

## Notes ##

This widget has a default border width of 5 and a default spacing of 5 which cannot be overridden.


---
