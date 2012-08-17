
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
     PROGRESS = 315,
     EPROGRESS = 316,
     PART_PROGRESS = 317,
     LIST = 318,
     PART_LIST = 319,
     ELIST = 320,
     TABLE = 321,
     ETABLE = 322,
     COMBO = 323,
     PART_COMBO = 324,
     ECOMBO = 325,
     GVIM = 326,
     EGVIM = 327,
     TEXT = 328,
     PART_TEXT = 329,
     ETEXT = 330,
     PIXMAP = 331,
     PART_PIXMAP = 332,
     EPIXMAP = 333,
     DEFAULT = 334,
     EDEFAULT = 335,
     SENSITIVE = 336,
     ESENSITIVE = 337,
     VARIABLE = 338,
     EVARIABLE = 339,
     WIDTH = 340,
     EWIDTH = 341,
     HEIGHT = 342,
     EHEIGHT = 343,
     INPUT = 344,
     INPUTFILE = 345,
     EINPUT = 346,
     PART_INPUT = 347,
     PART_INPUTFILE = 348,
     OUTPUT = 349,
     OUTPUTFILE = 350,
     EOUTPUT = 351,
     ACTION = 352,
     EACTION = 353,
     PART_ACTION = 354,
     COMM = 355,
     ENDCOMM = 356,
     IF = 357,
     ENDIF = 358,
     WHILE = 359,
     EWHILE = 360,
     SHOW_WIDGETS = 361,
     EMB_VARIABLE = 362,
     EMB_NUMBER = 363,
     END_OF_FILE = 364,
     NUMBER = 365,
     STRING = 366,
     UMINUS = 367,
     HSEPARATOR = 368,
     PART_HSEPARATOR = 369,
     EHSEPARATOR = 370,
     VSEPARATOR = 371,
     PART_VSEPARATOR = 372,
     EVSEPARATOR = 373,
     COMBOBOXTEXT = 374,
     PART_COMBOBOXTEXT = 375,
     ECOMBOBOXTEXT = 376,
     COMBOBOXENTRY = 377,
     PART_COMBOBOXENTRY = 378,
     ECOMBOBOXENTRY = 379,
     HSCALE = 380,
     PART_HSCALE = 381,
     EHSCALE = 382,
     VSCALE = 383,
     PART_VSCALE = 384,
     EVSCALE = 385,
     SPINBUTTON = 386,
     PART_SPINBUTTON = 387,
     ESPINBUTTON = 388,
     TIMER = 389,
     PART_TIMER = 390,
     ETIMER = 391,
     TOGGLEBUTTON = 392,
     PART_TOGGLEBUTTON = 393,
     ETOGGLEBUTTON = 394,
     STATUSBAR = 395,
     PART_STATUSBAR = 396,
     ESTATUSBAR = 397,
     COLORBUTTON = 398,
     PART_COLORBUTTON = 399,
     ECOLORBUTTON = 400,
     FONTBUTTON = 401,
     PART_FONTBUTTON = 402,
     EFONTBUTTON = 403
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
#define PROGRESS 315
#define EPROGRESS 316
#define PART_PROGRESS 317
#define LIST 318
#define PART_LIST 319
#define ELIST 320
#define TABLE 321
#define ETABLE 322
#define COMBO 323
#define PART_COMBO 324
#define ECOMBO 325
#define GVIM 326
#define EGVIM 327
#define TEXT 328
#define PART_TEXT 329
#define ETEXT 330
#define PIXMAP 331
#define PART_PIXMAP 332
#define EPIXMAP 333
#define DEFAULT 334
#define EDEFAULT 335
#define SENSITIVE 336
#define ESENSITIVE 337
#define VARIABLE 338
#define EVARIABLE 339
#define WIDTH 340
#define EWIDTH 341
#define HEIGHT 342
#define EHEIGHT 343
#define INPUT 344
#define INPUTFILE 345
#define EINPUT 346
#define PART_INPUT 347
#define PART_INPUTFILE 348
#define OUTPUT 349
#define OUTPUTFILE 350
#define EOUTPUT 351
#define ACTION 352
#define EACTION 353
#define PART_ACTION 354
#define COMM 355
#define ENDCOMM 356
#define IF 357
#define ENDIF 358
#define WHILE 359
#define EWHILE 360
#define SHOW_WIDGETS 361
#define EMB_VARIABLE 362
#define EMB_NUMBER 363
#define END_OF_FILE 364
#define NUMBER 365
#define STRING 366
#define UMINUS 367
#define HSEPARATOR 368
#define PART_HSEPARATOR 369
#define EHSEPARATOR 370
#define VSEPARATOR 371
#define PART_VSEPARATOR 372
#define EVSEPARATOR 373
#define COMBOBOXTEXT 374
#define PART_COMBOBOXTEXT 375
#define ECOMBOBOXTEXT 376
#define COMBOBOXENTRY 377
#define PART_COMBOBOXENTRY 378
#define ECOMBOBOXENTRY 379
#define HSCALE 380
#define PART_HSCALE 381
#define EHSCALE 382
#define VSCALE 383
#define PART_VSCALE 384
#define EVSCALE 385
#define SPINBUTTON 386
#define PART_SPINBUTTON 387
#define ESPINBUTTON 388
#define TIMER 389
#define PART_TIMER 390
#define ETIMER 391
#define TOGGLEBUTTON 392
#define PART_TOGGLEBUTTON 393
#define ETOGGLEBUTTON 394
#define STATUSBAR 395
#define PART_STATUSBAR 396
#define ESTATUSBAR 397
#define COLORBUTTON 398
#define PART_COLORBUTTON 399
#define ECOLORBUTTON 400
#define FONTBUTTON 401
#define PART_FONTBUTTON 402
#define EFONTBUTTON 403




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 77 "gtkdialog_parser.y"
 
  double     dval;
  char      *cval;
  GList     *lval;
  tag_attr *nvval;
  gint       ival;



/* Line 1676 of yacc.c  */
#line 358 "gtkdialog_parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE gtkdialog_lval;


