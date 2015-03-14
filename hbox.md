# hbox widget #

A [GtkHBox](http://developer.gnome.org/gtk2/2.24/GtkHBox.html) optionally packed inside a [GtkViewport](http://developer.gnome.org/gtk2/2.24/GtkViewport.html) inside a [GtkScrolledWindow](http://developer.gnome.org/gtk2/2.24/GtkScrolledWindow.html)


---


## Definition ##

```
<hbox tag_attr="value"...>
	widget...
	<variable>varname</variable>
	<height>value</height>
	<width>value</width>
	<sensitive>state</sensitive>
	<action signal="type">activity</action>...
</hbox>
```

"..." denotes acceptance of multiples of the same thing.

## Tag Attributes ##

See the [GtkHBox](http://developer.gnome.org/gtk2/2.24/GtkHBox.html#GtkHBox.object-hierarchy) widget and ancestor class properties.

The following custom tag attributes are available:

<a href='Hidden comment: ExportTableStart'></a>
| **Name** | **Description** | **Value** | **Since** |
|:---------|:----------------|:----------|:----------|
| space-expand<sup>[1]</sup> | Pack this and nested widgets expanding into space | `true` or `false` | 0.7.21 |
| space-fill<sup>[1]</sup> | Pack this and nested widgets filling space | `true` or `false` | 0.7.21 |
| block-function-signals | Block signal emissions from functions | `true` or `false` | 0.8.1 |
| hscrollbar-policy | Policy for the horizontal scrollbar | `0`, `1`, `2` (always, automatic, never) | 0.8.1 |
| vscrollbar-policy | Policy for the vertical scrollbar | `0`, `1`, `2` (always, automatic, never) | 0.8.1 |
| scrollable | Scrolled window capability | `true` or `false` | 0.7.21 |
| height | Scrolled window dimension | An integer > `0` or `-1` to ignore | 0.7.21 |
| width | Scrolled window dimension | An integer > `0` or `-1` to ignore | 0.7.21 |
| shadow-type | Viewport shadow type | `0` to `4` (see [GtkShadowType](http://developer.gnome.org/gtk2/2.24/gtk2-Standard-Enumerations.html#GtkShadowType)) | 0.8.1 |
<a href='Hidden comment: ExportTableEnd'></a>

## Directives ##

Some of these may have tag attribute equivalents.

<a href='Hidden comment: ExportTableStart'></a>
| **Name** | **Description** | **Contents** | **Since** |
|:---------|:----------------|:-------------|:----------|
| variable | Variable name |  | 0.8.1 |
| variable export="false" | Variable name, not exported to shell |  | 0.8.3 |
| height<sup>[2]</sup> | Scrolled window dimension | An integer > `0` or `-1` to ignore | 0.8.1 |
| width<sup>[2]</sup> | Scrolled window dimension | An integer > `0` or `-1` to ignore | 0.8.1 |
| sensitive | Sensitive state | `true` or `false` | 0.8.1 |
| action signal="_type_" | Execute command on signal | Shell command | 0.8.1 |
| action signal="_type_" | Perform function on signal | _function_:_parameter_ | 0.8.1 |
| action signal="_type_" condition="_type_" | Execute command on signal conditionally | Shell command | 0.8.3 |
| action signal="_type_" condition="_type_" | Perform function on signal conditionally | _function_:_parameter_ | 0.8.3 |
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
<a href='Hidden comment: ExportTableEnd'></a>

The following general functions can be performed by any widget capable of emitting signals:

<a href='Hidden comment: ExportTableStart'></a>
| **Type** | **Description** | **Parameter** | **Since** |
|:---------|:----------------|:--------------|:----------|
| break | Break out of actions list | None | 0.8.3 |
| command | Execute command | Shell command | 0.8.1 |
| exit | Exit dialog | A value for the `EXIT` variable | 0.8.1 |
| closewindow | Close dialog | Variable name | 0.8 1 |
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

1. By default the frame widget and every widget automatically placed inside a scrolled window (edit, tree, list, table and optionally the h/vbox) are packed with expand and fill set to true, otherwise widgets are packed with expand and fill set to false. This rather quirky system constitutes the original Gtkdialog widget packing method and therefore must continue to be supported, but since 0.7.21 it's now possible to override this behaviour globally with the --space-expand=state and --space-fill=state command line options, at the h/vbox container level or at the individual widget level or a combination thereof.

2. The scrolled window has a default dimension of 200x100 which can be overridden with the height and/or width directives.

This widget has a default spacing of 5 which can be overridden with the "[spacing](http://developer.gnome.org/gtk2/2.24/GtkBox.html#GtkBox--spacing)" tag attribute.


---
