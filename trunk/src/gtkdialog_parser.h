
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     WINDOW = 258,
     PART_WINDOW = 259,
     EWINDOW = 260,
     VBOX = 261,
     PART_VBOX = 262,
     EVBOX = 263,
     HBOX = 264,
     PART_HBOX = 265,
     EHBOX = 266,
     NOTEBOOK = 267,
     ENOTEBOOK = 268,
     PART_NOTEBOOK = 269,
     FRAME = 270,
     TAG_ATTR_NAME = 271,
     EFRAME = 272,
     ENTRY = 273,
     EENTRY = 274,
     PART_ENTRY = 275,
     MENUBAR = 276,
     PART_MENUBAR = 277,
     EMENUBAR = 278,
     MENU = 279,
     PART_MENU = 280,
     EMENU = 281,
     MENUITEM = 282,
     PART_MENUITEM = 283,
     EMENUITEM = 284,
     MENUITEMSEPARATOR = 285,
     EMENUITEMSEPARATOR = 286,
     EDIT = 287,
     PART_EDIT = 288,
     EEDIT = 289,
     TREE = 290,
     PART_TREE = 291,
     ETREE = 292,
     CHOOSER = 293,
     PART_CHOOSER = 294,
     ECHOOSER = 295,
     LABEL = 296,
     ELABEL = 297,
     ITEM = 298,
     EITEM = 299,
     PART_ITEM = 300,
     BUTTON = 301,
     PART_BUTTON = 302,
     EBUTTON = 303,
     BUTTONOK = 304,
     BUTTONCANCEL = 305,
     BUTTONHELP = 306,
     BUTTONYES = 307,
     BUTTONNO = 308,
     CHECKBOX = 309,
     ECHECKBOX = 310,
     PART_CHECKBOX = 311,
     RADIO = 312,
     ERADIO = 313,
     PART_RADIO = 314,
     PROGRESSBAR = 315,
     EPROGRESSBAR = 316,
     PART_PROGRESSBAR = 317,
     LIST = 318,
     PART_LIST = 319,
     ELIST = 320,
     TABLE = 321,
     ETABLE = 322,
     PART_TABLE = 323,
     COMBOBOX = 324,
     PART_COMBOBOX = 325,
     ECOMBOBOX = 326,
     GVIM = 327,
     EGVIM = 328,
     TEXT = 329,
     PART_TEXT = 330,
     ETEXT = 331,
     PIXMAP = 332,
     PART_PIXMAP = 333,
     EPIXMAP = 334,
     DEFAULT = 335,
     EDEFAULT = 336,
     SENSITIVE = 337,
     ESENSITIVE = 338,
     VARIABLE = 339,
     EVARIABLE = 340,
     WIDTH = 341,
     EWIDTH = 342,
     HEIGHT = 343,
     EHEIGHT = 344,
     INPUT = 345,
     INPUTFILE = 346,
     EINPUT = 347,
     PART_INPUT = 348,
     PART_INPUTFILE = 349,
     OUTPUT = 350,
     OUTPUTFILE = 351,
     EOUTPUT = 352,
     ACTION = 353,
     EACTION = 354,
     PART_ACTION = 355,
     COMM = 356,
     ENDCOMM = 357,
     IF = 358,
     ENDIF = 359,
     WHILE = 360,
     EWHILE = 361,
     SHOW_WIDGETS = 362,
     EMB_VARIABLE = 363,
     EMB_NUMBER = 364,
     END_OF_FILE = 365,
     NUMBER = 366,
     STRING = 367,
     UMINUS = 368,
     HSEPARATOR = 369,
     PART_HSEPARATOR = 370,
     EHSEPARATOR = 371,
     VSEPARATOR = 372,
     PART_VSEPARATOR = 373,
     EVSEPARATOR = 374,
     COMBOBOXTEXT = 375,
     PART_COMBOBOXTEXT = 376,
     ECOMBOBOXTEXT = 377,
     COMBOBOXENTRY = 378,
     PART_COMBOBOXENTRY = 379,
     ECOMBOBOXENTRY = 380,
     HSCALE = 381,
     PART_HSCALE = 382,
     EHSCALE = 383,
     VSCALE = 384,
     PART_VSCALE = 385,
     EVSCALE = 386,
     SPINBUTTON = 387,
     PART_SPINBUTTON = 388,
     ESPINBUTTON = 389,
     TIMER = 390,
     PART_TIMER = 391,
     ETIMER = 392,
     TOGGLEBUTTON = 393,
     PART_TOGGLEBUTTON = 394,
     ETOGGLEBUTTON = 395,
     STATUSBAR = 396,
     PART_STATUSBAR = 397,
     ESTATUSBAR = 398,
     COLORBUTTON = 399,
     PART_COLORBUTTON = 400,
     ECOLORBUTTON = 401,
     FONTBUTTON = 402,
     PART_FONTBUTTON = 403,
     EFONTBUTTON = 404,
     TERMINAL = 405,
     PART_TERMINAL = 406,
     ETERMINAL = 407,
     EVENTBOX = 408,
     PART_EVENTBOX = 409,
     EEVENTBOX = 410,
     EXPANDER = 411,
     PART_EXPANDER = 412,
     EEXPANDER = 413
   };
#endif
/* Tokens.  */
#define WINDOW 258
#define PART_WINDOW 259
#define EWINDOW 260
#define VBOX 261
#define PART_VBOX 262
#define EVBOX 263
#define HBOX 264
#define PART_HBOX 265
#define EHBOX 266
#define NOTEBOOK 267
#define ENOTEBOOK 268
#define PART_NOTEBOOK 269
#define FRAME 270
#define TAG_ATTR_NAME 271
#define EFRAME 272
#define ENTRY 273
#define EENTRY 274
#define PART_ENTRY 275
#define MENUBAR 276
#define PART_MENUBAR 277
#define EMENUBAR 278
#define MENU 279
#define PART_MENU 280
#define EMENU 281
#define MENUITEM 282
#define PART_MENUITEM 283
#define EMENUITEM 284
#define MENUITEMSEPARATOR 285
#define EMENUITEMSEPARATOR 286
#define EDIT 287
#define PART_EDIT 288
#define EEDIT 289
#define TREE 290
#define PART_TREE 291
#define ETREE 292
#define CHOOSER 293
#define PART_CHOOSER 294
#define ECHOOSER 295
#define LABEL 296
#define ELABEL 297
#define ITEM 298
#define EITEM 299
#define PART_ITEM 300
#define BUTTON 301
#define PART_BUTTON 302
#define EBUTTON 303
#define BUTTONOK 304
#define BUTTONCANCEL 305
#define BUTTONHELP 306
#define BUTTONYES 307
#define BUTTONNO 308
#define CHECKBOX 309
#define ECHECKBOX 310
#define PART_CHECKBOX 311
#define RADIO 312
#define ERADIO 313
#define PART_RADIO 314
#define PROGRESSBAR 315
#define EPROGRESSBAR 316
#define PART_PROGRESSBAR 317
#define LIST 318
#define PART_LIST 319
#define ELIST 320
#define TABLE 321
#define ETABLE 322
#define PART_TABLE 323
#define COMBOBOX 324
#define PART_COMBOBOX 325
#define ECOMBOBOX 326
#define GVIM 327
#define EGVIM 328
#define TEXT 329
#define PART_TEXT 330
#define ETEXT 331
#define PIXMAP 332
#define PART_PIXMAP 333
#define EPIXMAP 334
#define DEFAULT 335
#define EDEFAULT 336
#define SENSITIVE 337
#define ESENSITIVE 338
#define VARIABLE 339
#define EVARIABLE 340
#define WIDTH 341
#define EWIDTH 342
#define HEIGHT 343
#define EHEIGHT 344
#define INPUT 345
#define INPUTFILE 346
#define EINPUT 347
#define PART_INPUT 348
#define PART_INPUTFILE 349
#define OUTPUT 350
#define OUTPUTFILE 351
#define EOUTPUT 352
#define ACTION 353
#define EACTION 354
#define PART_ACTION 355
#define COMM 356
#define ENDCOMM 357
#define IF 358
#define ENDIF 359
#define WHILE 360
#define EWHILE 361
#define SHOW_WIDGETS 362
#define EMB_VARIABLE 363
#define EMB_NUMBER 364
#define END_OF_FILE 365
#define NUMBER 366
#define STRING 367
#define UMINUS 368
#define HSEPARATOR 369
#define PART_HSEPARATOR 370
#define EHSEPARATOR 371
#define VSEPARATOR 372
#define PART_VSEPARATOR 373
#define EVSEPARATOR 374
#define COMBOBOXTEXT 375
#define PART_COMBOBOXTEXT 376
#define ECOMBOBOXTEXT 377
#define COMBOBOXENTRY 378
#define PART_COMBOBOXENTRY 379
#define ECOMBOBOXENTRY 380
#define HSCALE 381
#define PART_HSCALE 382
#define EHSCALE 383
#define VSCALE 384
#define PART_VSCALE 385
#define EVSCALE 386
#define SPINBUTTON 387
#define PART_SPINBUTTON 388
#define ESPINBUTTON 389
#define TIMER 390
#define PART_TIMER 391
#define ETIMER 392
#define TOGGLEBUTTON 393
#define PART_TOGGLEBUTTON 394
#define ETOGGLEBUTTON 395
#define STATUSBAR 396
#define PART_STATUSBAR 397
#define ESTATUSBAR 398
#define COLORBUTTON 399
#define PART_COLORBUTTON 400
#define ECOLORBUTTON 401
#define FONTBUTTON 402
#define PART_FONTBUTTON 403
#define EFONTBUTTON 404
#define TERMINAL 405
#define PART_TERMINAL 406
#define ETERMINAL 407
#define EVENTBOX 408
#define PART_EVENTBOX 409
#define EEVENTBOX 410
#define EXPANDER 411
#define PART_EXPANDER 412
#define EEXPANDER 413




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 78 "gtkdialog_parser.y"
 
  double     dval;
  char      *cval;
  GList     *lval;
  tag_attr *nvval;
  gint       ival;



/* Line 1676 of yacc.c  */
#line 378 "gtkdialog_parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE gtkdialog_lval;


