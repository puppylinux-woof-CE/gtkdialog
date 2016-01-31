# button widget #

A [GtkButton](http://developer.gnome.org/gtk2/2.24/GtkButton.html) containing either a [GtkLabel](http://developer.gnome.org/gtk2/2.24/GtkLabel.html), a [GtkImage](http://developer.gnome.org/gtk2/2.24/GtkImage.html) or both packed inside a [GtkHBox](http://developer.gnome.org/gtk2/2.24/GtkHBox.html) or [GtkVBox](http://developer.gnome.org/gtk2/2.24/GtkVBox.html)


---


## Definition ##

```
<button yes no ok cancel help tag_attr="value"...>
	<label>text</label>
	<variable>varname</variable>
	<height>value</height>
	<width>value</width>
	<input file>filename</input>
	<input file icon="image"></input>
	<input file stock="gtk-image"></input>
	<sensitive>state</sensitive>
	<action>activity</action>...
	<action signal="type">activity</action>...
	<action function="type">parameter</action>...
</button>
```

"..." denotes acceptance of multiples of the same thing.

## Tag Attributes ##

See the [GtkButton](http://developer.gnome.org/gtk2/2.24/GtkButton.html#GtkButton.object-hierarchy) widget and ancestor class properties.

The following custom tag attributes are available:

<a href='Hidden comment: ExportTableStart'></a>
| Name | Description | Value | Since |
|:---------|:----------------|:----------|:----------|
| space-expand | Pack widget expanding into space | `true` or `false` | 0.7.21 |
| space-fill | Pack widget filling space | `true` or `false` | 0.7.21 |
| block-function-signals | Block signal emissions from functions | `true` or `false` | 0.7.21 |
| file-monitor | Emit signal when input file(s) change | `true` or `false` | 0.8.1 |
| auto-refresh | Auto refresh when input file(s) change | `true` or `false` | 0.8.1 |
| image-position<sup>[1]</sup> | Image position relative to label | `0`, `1`, `2`, `3` (left, right, top, bottom) | 0.7.21 |
| homogeneous<sup>[2]</sup> | Horizontal uniformity of an image with label | `true` or `false` | 0.8.1 |
| theme-icon-size | The size of the GTK theme icon | An integer > `0` or `-1` to ignore | 0.8.1 |
| stock-icon-size | The size of the GTK stock icon | `0` to `6` (see [GtkIconSize](http://developer.gnome.org/gtk2/2.24/gtk2-Themeable-Stock-Images.html#GtkIconSize)) | 0.8.1 |
<a href='Hidden comment: ExportTableEnd'></a>

## Directives ##

Some of these may have tag attribute equivalents.

<a href='Hidden comment: ExportTableStart'></a>
| **Name** | **Description** | **Contents** | **Since** |
|:---------|:----------------|:-------------|:----------|
| label | Initial text |  |  |
| variable | Variable name |  |  |
| variable export="false" | Variable name, not exported to shell |  | 0.8.3 |
| height | Image scaling dimension | An integer > `0` or `-1` to ignore | 0.7.21 |
| width | Image scaling dimension | An integer > `0` or `-1` to ignore | 0.7.21 |
| input file | Data input source | Image filename |  |
| input file icon="_image_"<sup>[3]</sup> | GTK theme icon name |  |  |
| input file stock="_gtk-image_"<sup>[4]</sup> | GTK stock icon ID | `gtk-about`, `gtk-add`, ... ([full list](http://developer.gnome.org/gtk2/2.24/gtk2-Stock-Items.html#GTK-STOCK-ABOUT:CAPS)) |  |
| sensitive | Sensitive state | `true` or `false` | 0.7.21 |
| action | Execute command on default signal | Shell command |  |
| action | Perform function on default signal | _function_:_parameter_ |  |
| action signal="_type_" | Execute command on signal | Shell command |  |
| action signal="_type_" | Perform function on signal | _function_:_parameter_ |  |
| action function="_type_" | Perform function on default signal | _parameter_ | 0.8.3 |
| action condition="_type_" | Execute command on default signal conditionally | Shell command | 0.8.3 |
| action condition="_type_" | Perform function on default signal conditionally | _function_:_parameter_ | 0.8.3 |
| action signal="_type_" condition="_type_" | Execute command on signal conditionally | Shell command | 0.8.3 |
| action signal="_type_" condition="_type_" | Perform function on signal conditionally | _function_:_parameter_ | 0.8.3 |
| action function="_type_" condition="_type_" | Perform function on default signal conditionally | _parameter_ | 0.8.3 |
<a href='Hidden comment: ExportTableEnd'></a>

## Signals ##

The default signal is "[clicked](http://developer.gnome.org/gtk2/2.24/GtkButton.html#GtkButton-clicked)", emitted when the button has been activated (pressed and released).

The "file-changed" signal is emitted if file-monitor is true and the input file being monitored has changed.

The following signals are connected-up for all widgets:

[button-press-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-button-press-event), [button-release-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-button-release-event), [configure-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-configure-event), [enter-notify-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-enter-notify-event), [leave-notify-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-leave-notify-event), [focus-in-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-focus-in-event), [focus-out-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-focus-out-event), [hide](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-hide), [show](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-show), [realize](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-realize), [key-press-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-key-press-event), [key-release-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-key-release-event), [map-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-map-event), [unmap-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-unmap-event)

## Functions ##

The following functions can be performed upon this widget by any widget capable of emitting signals:

<a href='Hidden comment: ExportTableStart'></a>
| **Type** | **Description** | **Parameter** | **Since** |
|:---------|:----------------|:--------------|:----------|
| enable | Sensitise widget | Variable name |  |
| disable | Desensitise widget | Variable name |  |
| show | Show widget | Variable name | 0.8.1 |
| hide | Hide widget | Variable name | 0.8.1 |
| activate | Activate widget | Variable name | 0.8.1 |
| grabfocus | Grab input focus | Variable name | 0.8.1 |
| refresh | Reload input data | Variable name | 0.7.21 |
<a href='Hidden comment: ExportTableEnd'></a>

The following general functions can be performed by any widget capable of emitting signals:

<a href='Hidden comment: ExportTableStart'></a>
| **Type** | **Description** | **Parameter** | **Since** |
|:---------|:----------------|:--------------|:----------|
| break | Break out of actions list | None | 0.8.3 |
| command | Execute command | Shell command |  |
| exit | Exit dialog | A value for the `EXIT` variable |  |
| closewindow | Close dialog | Variable name |  |
| launch | Launch dialog | Variable name |  |
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

1. The existing "[image-position](http://developer.gnome.org/gtk2/2.24/GtkButton.html#GtkButton--image-position)" GTK+ property -- normally only applicable to stock buttons -- has been extended to apply to all Gtkdialog buttons.

2. The existing "[homogeneous](http://developer.gnome.org/gtk2/2.24/GtkBox.html#GtkBox--homogeneous)" GTK+ property -- applicable to the hbox and vbox -- can be used here to effect the box inside the button when including an image and a label.

3. Theme icons default to 20 and do not scale or refresh (the "theme-icon-size" custom tag attribute can be used to request a size).

4. Stock icons default to GTK\_ICON\_SIZE\_BUTTON and do not scale or refresh (the "stock-icon-size" custom tag attribute can be used to request a size).


---
