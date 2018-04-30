# terminal widget #

A [VteTerminal](http://developer.gnome.org/vte/unstable/VteTerminal.html) packed inside a [GtkScrolledWindow](http://developer.gnome.org/gtk2/2.24/GtkScrolledWindow.html)


---


## Definition ##

```
<terminal tag_attr="value"...>
	<variable>varname</variable>
	<height>value</height>
	<width>value</width>
	<input>command</input>
	<input file>filename</input>
	<sensitive>state</sensitive>
	<action>activity</action>...
	<action signal="type">activity</action>...
	<action function="type">parameter</action>...
</terminal>
```

"..." denotes acceptance of multiples of the same thing.

## Tag Attributes ##

See the [VteTerminal](http://developer.gnome.org/vte/unstable/VteTerminal.html#VteTerminal.object-hierarchy) widget and ancestor class properties.

The following custom tag attributes are available:

| **Name** | **Description** | **Value** | **Since** |
|:---------|:----------------|:----------|:----------|
| space-expand | Pack widget expanding into space | `true` or `false` |  |
| space-fill | Pack widget filling space | `true` or `false` |  |
| block-function-signals | Block signal emissions from functions | `true` or `false` |  |
| file-monitor | Emit signal when input file(s) change | `true` or `false` |  |
| auto-refresh | Auto refresh when input file(s) change | `true` or `false` |  |
| hscrollbar-policy | Policy for the horizontal scrollbar | `0`, `1`, `2` (always, automatic, never) |  |
| vscrollbar-policy | Policy for the vertical scrollbar | `0`, `1`, `2` (always, automatic, never) |  |
| font-name | Font description | Example: `Monospace Bold 14` |  |
| background-tint-color<sup>[1][2]</sup> | Background tint colour | A standard name,  _#rgb_ or  _#rrggbb_ |  |
| text-background-color | Text background colour | A standard name,  _#rgb_ or  _#rrggbb_ |  |
| text-foreground-color | Text foreground colour | A standard name,  _#rgb_ or  _#rrggbb_ |  |
| bold-foreground-color | Bold text foreground colour | A standard name,  _#rgb_ or  _#rrggbb_ |  |
| dim-foreground-color<sup>[2]</sup> | Dim text foreground colour | A standard name,  _#rgb_ or  _#rrggbb_ |  |
| cursor-background-color | Cursor background colour | A standard name,  _#rgb_ or  _#rrggbb_ |  |
| highlight-background-color | Highlighted text background colour | A standard name,  _#rgb_ or  _#rrggbb_ |  |
| argv? | Arguments starting at argv0 (command) | Example: `/bin/sh` |  |
| envv? | Environment variables starting at envv0 | Example: `MESSAGE=Hello` |  |

## Directives ##

Some of these may have tag attribute equivalents.

| **Name** | **Description** | **Contents** | **Since** |
|:---------|:----------------|:-------------|:----------|
| variable | Variable name | Command's PID (`0` if dead) |  |
| variable export="false" | Variable name, not exported to shell |  | 0.8.3 |
| height | Initial height | An integer > `0` or `-1` to ignore |  |
| width | Initial width | An integer > `0` or `-1` to ignore |  |
| input | Data input source | Shell command |  |
| input file | Data input source | Filename |  |
| sensitive | Active state | `true` or `false` |  |
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

## Signals ##

The default signal is "[child-exited](http://developer.gnome.org/vte/unstable/VteTerminal.html#VteTerminal-child-exited)", emitted when the terminal detects that the child has exited.

The "file-changed" signal is emitted if file-monitor is true and the input file being monitored has changed.

The following signals are connected-up for all widgets:

[button-press-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-button-press-event), [button-release-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-button-release-event), [configure-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-configure-event), [enter-notify-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-enter-notify-event), [leave-notify-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-leave-notify-event), [focus-in-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-focus-in-event), [focus-out-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-focus-out-event), [hide](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-hide), [show](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-show), [realize](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-realize), [key-press-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-key-press-event), [key-release-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-key-release-event), [map-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-map-event), [unmap-event](http://developer.gnome.org/gtk2/2.24/GtkWidget.html#GtkWidget-unmap-event)

## Functions ##

The following functions can be performed upon this widget by any widget capable of emitting signals:

| **Type** | **Description** | **Parameter** | **Since** |
|:---------|:----------------|:--------------|:----------|
| enable | Reactivate timer | Variable name |  |
| disable | Deactivate timer | Variable name |  |
| show | Show widget | Variable name |  |
| hide | Hide widget | Variable name |  |
| grabfocus | Grab input focus | Variable name |  |
| refresh | Reload input data | Variable name |  |
| clear | Reset terminal and re-execute command | Variable name |  |

The following general functions can be performed by any widget capable of emitting signals:

| **Type** | **Description** | **Parameter** | **Since** |
|:---------|:----------------|:--------------|:----------|
| break | Break out of actions list | None | 0.8.3 |
| command | Execute command | Shell command |  |
| exit | Exit dialog | A value for the `EXIT` variable |  |
| closewindow | Close dialog | Variable name |  |
| launch | Launch dialog | Variable name |  |
| presentwindow | [Present](http://developer.gnome.org/gtk2/2.24/GtkWindow.html#gtk-window-present) dialog | Variable name |  |

## Conditions ##

The following conditions can be used within the condition attribute of action directives:

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

true means "true", "yes" or a non-zero value, false means "false", "no" or zero, therefore the shell command is expected to echo one of these values to stdout.

## Notes ##

1. There exists an equivalently named "[background-tint-color](http://developer.gnome.org/vte/unstable/VteTerminal.html#VteTerminal--background-tint-color)" VTE property but it doesn't accept strings so it's converted by Gtkdialog.
2. The "background-tint-color" and "dim-foreground-color" tag attributes are not permitted when using VTE >= 0.38 (which is the case for gtk3).

This is a non-mandatory widget that requires [libvte](http://ftp.gnome.org/pub/gnome/sources/vte/) support be built into Gtkdialog at compile time.

This widget was introduced in version 0.8.1.


---
