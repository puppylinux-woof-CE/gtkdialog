; The config file 

[Setup]
AppName=GtkDialog
AppVerName=GtkDialog version 1.7.2
DefaultDirName={pf}\PipDTK
DefaultGroupName=Pip's Development Tools
UninstallDisplayIcon={app}\gtkdialog.exe
Compression=lzma
SolidCompression=yes
OutputDir=.
;userdocs:Inno Setup Examples Output

[Files]
;
; Executable program files
;
Source: "src\gtkdialog.exe"; DestDir: "{app}"
;
; Example batch files for windows
;
Source: "examples/00.00-text.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/00.01-text_attributes.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/01.00-button.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/01.01-button_attributes.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/01.02-button_action_types.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/01.03-button_signals.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/01.04-button_icon_actions.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/02.00-entry.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/02.01-entry_attributes.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/03.00-checkbox.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/03.01-checkbox_attributes.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/04.01-radiobutton_attributes.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/05.00-combo.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/05.01-combo_attributes.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/05.02-combo_input.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/06.00-editor.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/06.01-editor_attributes.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/07.00-list.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/07.01-list_attributes.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/07.02-list_actions.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/08.00-table.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/09.00-tree.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/09.01-tree_attributes.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/09.02-tree_actions.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/09.03-tree_insert.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/09.10-tree_icon_actions.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/10.00-vbox_and_hbox.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/10.01-vbox_and_hbox_attributes.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/11.00-frame.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/12.00-notebook.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/13.00-chooser.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/14.00-menubar.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/15.00-window.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/15.01.window_attributes.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/16.00-fileselect.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/90.00-event_driven.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/90.00-standalone_file.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/90.01-input_file.bat"; DestDir: "{app}\GtkDialog-examples"
Source: "examples/90.01-print_ir.bat"; DestDir: "{app}\GtkDialog-examples"
;
; The MinGW libraries needed to run this program.
;
Source: "..\..\..\mingw\bin\gettextlib.dll";          DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\bin\libglib-2.0-0.dll";       DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\bin\libgobject-2.0-0.dll";    DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\bin\libgthread-2.0-0.dll";    DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\bin\libgdk-win32-2.0-0.dll";  DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\bin\libgtk-win32-2.0-0.dll";  DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\bin\mingwm10.dll";            DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\bin\libatk-1.0-0.dll";        DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\bin\iconv.dll";               DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\bin\intl.dll";                DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\bin\libgdk_pixbuf-2.0-0.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\bin\libgmodule-2.0-0.dll";    DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\bin\libcairo-2.dll";          DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\bin\libpng13.dll";            DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\bin\zlib1.dll";               DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\bin\libpango-1.0-0.dll";      DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall

Source: "..\..\..\mingw\bin\libpangocairo-1.0-0.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\bin\libpangowin32-1.0-0.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\pango\1.5.0\modules\pango-arabic-fc.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\pango\1.5.0\modules\pango-basic-fc.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\pango\1.5.0\modules\pango-basic-win32.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\pango\1.5.0\modules\pango-hangul-fc.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\pango\1.5.0\modules\pango-hebrew-fc.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\pango\1.5.0\modules\pango-indic-fc.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\pango\1.5.0\modules\pango-khmer-fc.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\pango\1.5.0\modules\pango-syriac-fc.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\pango\1.5.0\modules\pango-thai-fc.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\pango\1.5.0\modules\pango-tibetan-fc.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "pango.aliases"; DestDir: "{app}\etc\pango"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "pango.modules"; DestDir: "{app}\etc\pango"; Flags: onlyifdoesntexist uninsneveruninstall

Source: "..\..\..\mingw\lib\gtk-2.0\2.4.0\loaders\libpixbufloader-ani.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\gtk-2.0\2.4.0\loaders\libpixbufloader-bmp.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\gtk-2.0\2.4.0\loaders\libpixbufloader-gif.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\gtk-2.0\2.4.0\loaders\libpixbufloader-ico.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\gtk-2.0\2.4.0\loaders\libpixbufloader-jpeg.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\gtk-2.0\2.4.0\loaders\libpixbufloader-pcx.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\gtk-2.0\2.4.0\loaders\libpixbufloader-png.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\gtk-2.0\2.4.0\loaders\libpixbufloader-pnm.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\gtk-2.0\2.4.0\loaders\libpixbufloader-ras.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\gtk-2.0\2.4.0\loaders\libpixbufloader-tga.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\gtk-2.0\2.4.0\loaders\libpixbufloader-tiff.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\gtk-2.0\2.4.0\loaders\libpixbufloader-wbmp.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\gtk-2.0\2.4.0\loaders\libpixbufloader-xbm.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\..\mingw\lib\gtk-2.0\2.4.0\loaders\libpixbufloader-xpm.dll"; DestDir: "{app}"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "gdk-pixbuf.loaders"; DestDir: "{app}\etc\gtk-2.0"; Flags: onlyifdoesntexist uninsneveruninstall

[Icons]
;
; The start menu item for the executable.
;
Name: "{group}\GtkDialog"; Filename: "{app}\gtkdialog.exe"
;
; The start menu item for the example batch files.
;
Name: "{group}\GtkDialog"; Filename: "{app}\gtkdialog.exe"
 Name: "{group}\GtkDialog-examples\00.00-text"; Filename: "{app}\GtkDialog-examples\00.00-text.bat"
 Name: "{group}\GtkDialog-examples\00.01-text_attributes"; Filename: "{app}\GtkDialog-examples\00.01-text_attributes.bat"
 Name: "{group}\GtkDialog-examples\01.00-button"; Filename: "{app}\GtkDialog-examples\01.00-button.bat"
 Name: "{group}\GtkDialog-examples\01.01-button_attributes"; Filename: "{app}\GtkDialog-examples\01.01-button_attributes.bat"
 Name: "{group}\GtkDialog-examples\01.02-button_action_types"; Filename: "{app}\GtkDialog-examples\01.02-button_action_types.bat"
 Name: "{group}\GtkDialog-examples\01.03-button_signals.bat"; Filename: "{app}\GtkDialog-examples\01.03-button_signals.bat"
 Name: "{group}\GtkDialog-examples\01.04-button_icon_actions"; Filename: "{app}\GtkDialog-examples\01.04-button_icon_actions.bat"
 Name: "{group}\GtkDialog-examples\02.00-entry"; Filename: "{app}\GtkDialog-examples\02.00-entry.bat"
 Name: "{group}\GtkDialog-examples\02.01-entry_attributes"; Filename: "{app}\GtkDialog-examples\02.01-entry_attributes.bat"
 Name: "{group}\GtkDialog-examples\03.00-checkbox"; Filename: "{app}\GtkDialog-examples\03.00-checkbox.bat"
 Name: "{group}\GtkDialog-examples\03.01-checkbox_attributes"; Filename: "{app}\GtkDialog-examples\03.01-checkbox_attributes.bat"
 Name: "{group}\GtkDialog-examples\04.01-radiobutton_attributes"; Filename: "{app}\GtkDialog-examples\04.01-radiobutton_attributes.bat"
 Name: "{group}\GtkDialog-examples\05.00-combo"; Filename: "{app}\GtkDialog-examples\05.00-combo.bat"
 Name: "{group}\GtkDialog-examples\05.01-combo_attributes"; Filename: "{app}\GtkDialog-examples\05.01-combo_attributes.bat"
 Name: "{group}\GtkDialog-examples\05.02-combo_input"; Filename: "{app}\GtkDialog-examples\05.02-combo_input.bat"
 Name: "{group}\GtkDialog-examples\06.00-editor"; Filename: "{app}\GtkDialog-examples\06.00-editor.bat"
 Name: "{group}\GtkDialog-examples\06.01-editor_attributes"; Filename: "{app}\GtkDialog-examples\06.01-editor_attributes.bat"
 Name: "{group}\GtkDialog-examples\07.00-list"; Filename: "{app}\GtkDialog-examples\07.00-list.bat"
 Name: "{group}\GtkDialog-examples\07.01-list_attributes"; Filename: "{app}\GtkDialog-examples\07.01-list_attributes.bat"
 Name: "{group}\GtkDialog-examples\07.02-list_actions"; Filename: "{app}\GtkDialog-examples\07.02-list_actions.bat"
 Name: "{group}\GtkDialog-examples\08.00-table"; Filename: "{app}\GtkDialog-examples\08.00-table.bat"
 Name: "{group}\GtkDialog-examples\09.00-tree"; Filename: "{app}\GtkDialog-examples\09.00-tree.bat"
 Name: "{group}\GtkDialog-examples\09.01-tree_attributes"; Filename: "{app}\GtkDialog-examples\09.01-tree_attributes.bat"
 Name: "{group}\GtkDialog-examples\09.02-tree_actions"; Filename: "{app}\GtkDialog-examples\09.02-tree_actions.bat"
 Name: "{group}\GtkDialog-examples\09.03-tree_insert"; Filename: "{app}\GtkDialog-examples\09.03-tree_insert.bat"
 Name: "{group}\GtkDialog-examples\09.10-tree_icon_actions"; Filename: "{app}\GtkDialog-examples\09.10-tree_icon_actions.bat"
 Name: "{group}\GtkDialog-examples\10.00-vbox_and_hbox"; Filename: "{app}\GtkDialog-examples\10.00-vbox_and_hbox.bat"
 Name: "{group}\GtkDialog-examples\10.01-vbox_and_hbox_attributes"; Filename: "{app}\GtkDialog-examples\10.01-vbox_and_hbox_attributes.bat"
 Name: "{group}\GtkDialog-examples\11.00-frame"; Filename: "{app}\GtkDialog-examples\11.00-frame.bat"
 Name: "{group}\GtkDialog-examples\12.00-notebook"; Filename: "{app}\GtkDialog-examples\12.00-notebook.bat"
 Name: "{group}\GtkDialog-examples\13.00-chooser"; Filename: "{app}\GtkDialog-examples\13.00-chooser.bat"
 Name: "{group}\GtkDialog-examples\14.00-menubar"; Filename: "{app}\GtkDialog-examples\14.00-menubar.bat"
 Name: "{group}\GtkDialog-examples\15.00-window"; Filename: "{app}\GtkDialog-examples\15.00-window.bat"
 Name: "{group}\GtkDialog-examples\15.01.window_attributes"; Filename: "{app}\GtkDialog-examples\15.01.window_attributes.bat"
 Name: "{group}\GtkDialog-examples\16.00-fileselect"; Filename: "{app}\GtkDialog-examples\16.00-fileselect.bat"
 Name: "{group}\GtkDialog-examples\90.00-event_driven"; Filename: "{app}\GtkDialog-examples\90.00-event_driven.bat"
 Name: "{group}\GtkDialog-examples\90.00-standalone_file"; Filename: "{app}\GtkDialog-examples\90.00-standalone_file.bat"
 Name: "{group}\GtkDialog-examples\90.01-input_file"; Filename: "{app}\GtkDialog-examples\90.01-input_file.bat"
 Name: "{group}\GtkDialog-examples\90.01-print_ir"; Filename: "{app}\GtkDialog-examples\90.01-print_ir.bat"

