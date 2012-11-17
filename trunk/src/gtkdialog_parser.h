/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
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
     PART_VARIABLE = 340,
     EVARIABLE = 341,
     WIDTH = 342,
     EWIDTH = 343,
     HEIGHT = 344,
     EHEIGHT = 345,
     INPUT = 346,
     INPUTFILE = 347,
     EINPUT = 348,
     PART_INPUT = 349,
     PART_INPUTFILE = 350,
     OUTPUT = 351,
     OUTPUTFILE = 352,
     EOUTPUT = 353,
     ACTION = 354,
     EACTION = 355,
     PART_ACTION = 356,
     COMM = 357,
     ENDCOMM = 358,
     IF = 359,
     ENDIF = 360,
     WHILE = 361,
     EWHILE = 362,
     SHOW_WIDGETS = 363,
     EMB_VARIABLE = 364,
     EMB_NUMBER = 365,
     END_OF_FILE = 366,
     NUMBER = 367,
     STRING = 368,
     UMINUS = 369,
     HSEPARATOR = 370,
     PART_HSEPARATOR = 371,
     EHSEPARATOR = 372,
     VSEPARATOR = 373,
     PART_VSEPARATOR = 374,
     EVSEPARATOR = 375,
     COMBOBOXTEXT = 376,
     PART_COMBOBOXTEXT = 377,
     ECOMBOBOXTEXT = 378,
     COMBOBOXENTRY = 379,
     PART_COMBOBOXENTRY = 380,
     ECOMBOBOXENTRY = 381,
     HSCALE = 382,
     PART_HSCALE = 383,
     EHSCALE = 384,
     VSCALE = 385,
     PART_VSCALE = 386,
     EVSCALE = 387,
     SPINBUTTON = 388,
     PART_SPINBUTTON = 389,
     ESPINBUTTON = 390,
     TIMER = 391,
     PART_TIMER = 392,
     ETIMER = 393,
     TOGGLEBUTTON = 394,
     PART_TOGGLEBUTTON = 395,
     ETOGGLEBUTTON = 396,
     STATUSBAR = 397,
     PART_STATUSBAR = 398,
     ESTATUSBAR = 399,
     COLORBUTTON = 400,
     PART_COLORBUTTON = 401,
     ECOLORBUTTON = 402,
     FONTBUTTON = 403,
     PART_FONTBUTTON = 404,
     EFONTBUTTON = 405,
     TERMINAL = 406,
     PART_TERMINAL = 407,
     ETERMINAL = 408,
     EVENTBOX = 409,
     PART_EVENTBOX = 410,
     EEVENTBOX = 411,
     EXPANDER = 412,
     PART_EXPANDER = 413,
     EEXPANDER = 414
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
#define PART_VARIABLE 340
#define EVARIABLE 341
#define WIDTH 342
#define EWIDTH 343
#define HEIGHT 344
#define EHEIGHT 345
#define INPUT 346
#define INPUTFILE 347
#define EINPUT 348
#define PART_INPUT 349
#define PART_INPUTFILE 350
#define OUTPUT 351
#define OUTPUTFILE 352
#define EOUTPUT 353
#define ACTION 354
#define EACTION 355
#define PART_ACTION 356
#define COMM 357
#define ENDCOMM 358
#define IF 359
#define ENDIF 360
#define WHILE 361
#define EWHILE 362
#define SHOW_WIDGETS 363
#define EMB_VARIABLE 364
#define EMB_NUMBER 365
#define END_OF_FILE 366
#define NUMBER 367
#define STRING 368
#define UMINUS 369
#define HSEPARATOR 370
#define PART_HSEPARATOR 371
#define EHSEPARATOR 372
#define VSEPARATOR 373
#define PART_VSEPARATOR 374
#define EVSEPARATOR 375
#define COMBOBOXTEXT 376
#define PART_COMBOBOXTEXT 377
#define ECOMBOBOXTEXT 378
#define COMBOBOXENTRY 379
#define PART_COMBOBOXENTRY 380
#define ECOMBOBOXENTRY 381
#define HSCALE 382
#define PART_HSCALE 383
#define EHSCALE 384
#define VSCALE 385
#define PART_VSCALE 386
#define EVSCALE 387
#define SPINBUTTON 388
#define PART_SPINBUTTON 389
#define ESPINBUTTON 390
#define TIMER 391
#define PART_TIMER 392
#define ETIMER 393
#define TOGGLEBUTTON 394
#define PART_TOGGLEBUTTON 395
#define ETOGGLEBUTTON 396
#define STATUSBAR 397
#define PART_STATUSBAR 398
#define ESTATUSBAR 399
#define COLORBUTTON 400
#define PART_COLORBUTTON 401
#define ECOLORBUTTON 402
#define FONTBUTTON 403
#define PART_FONTBUTTON 404
#define EFONTBUTTON 405
#define TERMINAL 406
#define PART_TERMINAL 407
#define ETERMINAL 408
#define EVENTBOX 409
#define PART_EVENTBOX 410
#define EEVENTBOX 411
#define EXPANDER 412
#define PART_EXPANDER 413
#define EEXPANDER 414




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 78 "gtkdialog_parser.y"
 
  double     dval;
  char      *cval;
  GList     *lval;
  tag_attr *nvval;
  gint       ival;



/* Line 1685 of yacc.c  */
#line 379 "gtkdialog_parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE gtkdialog_lval;


