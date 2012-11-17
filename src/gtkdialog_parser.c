/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         gtkdialog_parse
#define yylex           gtkdialog_lex
#define yyerror         gtkdialog_error
#define yylval          gtkdialog_lval
#define yychar          gtkdialog_char
#define yydebug         gtkdialog_debug
#define yynerrs         gtkdialog_nerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "gtkdialog_parser.y"

/*
 * gtkdialog_parser.y: A simple grammar for the XML-like language we use.
 * Gtkdialog - A small utility for fast and easy GUI building.
 * Copyright (C) 2003-2007  László Pere <pipas@linux.pte.hu>
 * Copyright (C) 2011-2012  Thunor <thunorsif@hotmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/*
**
** $Id: parser.y,v 1.5 2004/11/25 21:16:57 root Exp root $
** $Log: parser.y,v $
** Revision 1.5  2004/11/25 21:16:57  root
** *** empty log message ***
**
** Revision 1.4  2004/11/25 21:15:21  root
**   o No, the grammar still has problems.
**
** Revision 1.2  2004/11/25 19:53:03  pipas
**   o New object: tag attributes.
**
** Revision 1.1  2004/11/19 22:10:08  pipas
** Initial revision
**
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

#include "gtkdialog.h"
#include "config.h"
#include "automaton.h"
#include "attributes.h"
#include "gtkdialog_parser.h"
#include "tag_attributes.h"

int linenumber = 1;
extern gchar *Token;
extern gboolean option_no_warning;
extern gboolean option_print_ir;

//
// Function declarations
//
int yywarning(char *c);
void yyerror_simple(char *c);

static inline void
start_up(void) 
{
	if (!option_print_ir) {
		run_program();
		return;
	} else {
		print_program();
		exit(EXIT_SUCCESS);
	}
}



/* Line 189 of yacc.c  */
#line 158 "gtkdialog_parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 78 "gtkdialog_parser.y"
 
  double     dval;
  char      *cval;
  GList     *lval;
  tag_attr *nvval;
  gint       ival;



/* Line 214 of yacc.c  */
#line 522 "gtkdialog_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 534 "gtkdialog_parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  124
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4101

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  168
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  196
/* YYNRULES -- Number of states.  */
#define YYNSTATES  573

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   414

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   167,     2,     2,     2,     2,     2,     2,
       2,     2,   117,   116,     2,   115,     2,   118,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   166,     2,
       2,   114,   165,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    11,    18,    20,    23,    25,    28,
      33,    39,    46,    54,    59,    65,    72,    80,    85,    91,
      98,   106,   111,   117,   124,   132,   137,   143,   150,   158,
     163,   169,   171,   173,   175,   177,   179,   181,   183,   185,
     187,   189,   191,   193,   195,   197,   199,   201,   203,   205,
     207,   209,   211,   213,   215,   217,   219,   221,   223,   225,
     229,   235,   239,   243,   249,   253,   257,   263,   267,   271,
     277,   281,   285,   291,   295,   299,   305,   309,   313,   317,
     321,   325,   329,   335,   339,   343,   349,   353,   357,   363,
     367,   371,   377,   381,   385,   391,   395,   399,   405,   409,
     413,   419,   422,   427,   433,   440,   448,   450,   452,   454,
     457,   462,   468,   475,   483,   487,   492,   498,   505,   508,
     512,   515,   520,   523,   528,   532,   538,   542,   548,   552,
     558,   562,   568,   572,   578,   582,   588,   592,   598,   602,
     608,   612,   618,   622,   628,   632,   638,   639,   642,   645,
     648,   651,   654,   657,   660,   663,   666,   669,   673,   677,
     681,   685,   689,   693,   699,   703,   709,   714,   718,   722,
     726,   732,   736,   742,   746,   749,   755,   759,   764,   769,
     771,   778,   785,   790,   792,   794,   798,   802,   806,   810,
     814,   819,   821,   822,   824,   826,   828
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     169,     0,    -1,   204,   170,    -1,     3,   170,   204,     5,
      -1,     4,   215,   165,   170,   204,     5,    -1,   171,    -1,
     170,   171,    -1,   216,    -1,   170,   216,    -1,     6,   170,
     204,     8,    -1,   170,     6,   170,   204,     8,    -1,     7,
     215,   165,   170,   204,     8,    -1,   170,     7,   215,   165,
     170,   204,     8,    -1,     9,   170,   204,    11,    -1,   170,
       9,   170,   204,    11,    -1,    10,   215,   165,   170,   204,
      11,    -1,   170,    10,   215,   165,   170,   204,    11,    -1,
     159,   170,   204,   161,    -1,   170,   159,   170,   204,   161,
      -1,   160,   215,   165,   170,   204,   161,    -1,   170,   160,
     215,   165,   170,   204,   161,    -1,   162,   170,   204,   164,
      -1,   170,   162,   170,   204,   164,    -1,   163,   215,   165,
     170,   204,   164,    -1,   170,   163,   215,   165,   170,   204,
     164,    -1,    12,   170,   204,    13,    -1,   170,    12,   170,
     204,    13,    -1,    14,   215,   165,   170,   204,    13,    -1,
     170,    14,   215,   165,   170,   204,    13,    -1,    15,   170,
     204,    17,    -1,   170,    15,   170,   204,    17,    -1,   176,
      -1,   172,    -1,   173,    -1,   174,    -1,   175,    -1,   177,
      -1,   178,    -1,   179,    -1,   180,    -1,   181,    -1,   182,
      -1,   183,    -1,   185,    -1,   184,    -1,   186,    -1,   191,
      -1,   192,    -1,   193,    -1,   194,    -1,   195,    -1,   196,
      -1,   197,    -1,   198,    -1,   199,    -1,   200,    -1,   201,
      -1,   202,    -1,   203,    -1,    18,   204,    19,    -1,    20,
     215,   165,   204,    19,    -1,    18,   204,    18,    -1,    32,
     204,    34,    -1,    33,   215,   165,   204,    34,    -1,    32,
     204,    32,    -1,    35,   204,    37,    -1,    36,   215,   165,
     204,    37,    -1,    35,   204,    35,    -1,    38,   204,    40,
      -1,    39,   215,   165,   204,    40,    -1,    38,   204,    38,
      -1,    74,   204,    76,    -1,    75,   215,   165,   204,    76,
      -1,    74,   204,    74,    -1,    46,   204,    48,    -1,    47,
     215,   165,   204,    48,    -1,    49,   204,    48,    -1,    50,
     204,    48,    -1,    51,   204,    48,    -1,    53,   204,    48,
      -1,    52,   204,    48,    -1,    54,   204,    55,    -1,    56,
     215,   165,   204,    55,    -1,    54,   204,    54,    -1,    57,
     204,    58,    -1,    59,   215,   165,   204,    58,    -1,    57,
     204,    57,    -1,    60,   204,    61,    -1,    62,   215,   165,
     204,    61,    -1,    60,   204,    60,    -1,    63,   204,    65,
      -1,    64,   215,   165,   204,    65,    -1,    63,   204,    63,
      -1,    66,   204,    67,    -1,    68,   215,   165,   204,    67,
      -1,    66,   204,    66,    -1,    69,   204,    71,    -1,    70,
     215,   165,   204,    71,    -1,    72,   204,    73,    -1,    77,
     204,    79,    -1,    78,   215,   165,   204,    79,    -1,    21,
      23,    -1,    21,   188,   204,    23,    -1,   188,    21,   188,
     204,    23,    -1,    22,   215,   165,   188,   204,    23,    -1,
     188,    22,   215,   165,   188,   204,    23,    -1,   188,    -1,
     189,    -1,   190,    -1,    24,    26,    -1,    24,   187,   204,
      26,    -1,   187,    24,   187,   204,    26,    -1,    25,   215,
     165,   187,   204,    26,    -1,   187,    25,   215,   165,   187,
     204,    26,    -1,    27,   204,    29,    -1,   187,    27,   204,
      29,    -1,    28,   215,   165,   204,    29,    -1,   187,    28,
     215,   165,   204,    29,    -1,    30,    31,    -1,   187,    30,
      31,    -1,   120,   122,    -1,   121,   215,   165,   122,    -1,
     123,   125,    -1,   124,   215,   165,   125,    -1,   126,   204,
     128,    -1,   127,   215,   165,   204,   128,    -1,   129,   204,
     131,    -1,   130,   215,   165,   204,   131,    -1,   132,   204,
     134,    -1,   133,   215,   165,   204,   134,    -1,   135,   204,
     137,    -1,   136,   215,   165,   204,   137,    -1,   138,   204,
     140,    -1,   139,   215,   165,   204,   140,    -1,   141,   204,
     143,    -1,   142,   215,   165,   204,   143,    -1,   144,   204,
     146,    -1,   145,   215,   165,   204,   146,    -1,   147,   204,
     149,    -1,   148,   215,   165,   204,   149,    -1,   150,   204,
     152,    -1,   151,   215,   165,   204,   152,    -1,   153,   204,
     155,    -1,   154,   215,   165,   204,   155,    -1,   156,   204,
     158,    -1,   157,   215,   165,   204,   158,    -1,    -1,   204,
     207,    -1,   204,   206,    -1,   204,   205,    -1,   204,   208,
      -1,   204,   209,    -1,   204,   210,    -1,   204,   211,    -1,
     204,   212,    -1,   204,   213,    -1,   204,   214,    -1,    41,
     113,    42,    -1,    82,   113,    83,    -1,    80,   113,    81,
      -1,    87,   113,    88,    -1,    89,   113,    90,    -1,    91,
     113,    93,    -1,    94,   215,   165,   113,    93,    -1,    92,
     113,    93,    -1,    95,   215,   165,   113,    93,    -1,    95,
     215,   165,    93,    -1,    96,   113,    98,    -1,    97,   113,
      98,    -1,    84,   113,    86,    -1,    85,   215,   165,   113,
      86,    -1,    99,   113,   100,    -1,   101,   215,   165,   113,
     100,    -1,    43,   113,    44,    -1,    43,    44,    -1,    45,
     215,   165,   113,    44,    -1,    16,   114,   113,    -1,   215,
      16,   114,   113,    -1,   102,   217,   165,   103,    -1,   108,
      -1,   219,   218,   165,   220,   170,   221,    -1,   222,   218,
     165,   224,   170,   223,    -1,   109,   166,   114,   218,    -1,
     109,    -1,   110,    -1,   218,   116,   218,    -1,   218,   115,
     218,    -1,   218,   117,   218,    -1,   218,   118,   218,    -1,
     218,   114,   218,    -1,   218,   167,   114,   218,    -1,   104,
      -1,    -1,   105,    -1,   106,    -1,   107,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   163,   163,   167,   171,   180,   181,   184,   185,   186,
     189,   193,   196,   200,   203,   207,   210,   214,   217,   221,
     224,   228,   231,   235,   238,   242,   245,   249,   252,   256,
     260,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   299,
     302,   305,   310,   313,   316,   322,   325,   328,   334,   337,
     340,   346,   349,   352,   356,   357,   360,   361,   362,   363,
     364,   368,   371,   375,   381,   384,   387,   393,   396,   399,
     405,   408,   411,   417,   420,   423,   429,   432,   438,   442,
     443,   456,   459,   462,   466,   469,   476,   477,   478,   482,
     485,   488,   492,   495,   502,   505,   509,   512,   519,   522,
     529,   532,   538,   541,   547,   550,   556,   559,   565,   568,
     574,   577,   583,   586,   592,   595,   601,   604,   610,   613,
     619,   622,   628,   631,   637,   640,   645,   647,   648,   649,
     650,   651,   652,   653,   654,   655,   656,   660,   665,   670,
     675,   680,   685,   688,   691,   694,   697,   703,   706,   712,
     715,   721,   724,   730,   733,   736,   742,   745,   751,   752,
     755,   758,   765,   771,   774,   777,   780,   783,   786,   789,
     792,   798,   802,   809,   813,   817,   824
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WINDOW", "PART_WINDOW", "EWINDOW",
  "VBOX", "PART_VBOX", "EVBOX", "HBOX", "PART_HBOX", "EHBOX", "NOTEBOOK",
  "ENOTEBOOK", "PART_NOTEBOOK", "FRAME", "TAG_ATTR_NAME", "EFRAME",
  "ENTRY", "EENTRY", "PART_ENTRY", "MENUBAR", "PART_MENUBAR", "EMENUBAR",
  "MENU", "PART_MENU", "EMENU", "MENUITEM", "PART_MENUITEM", "EMENUITEM",
  "MENUITEMSEPARATOR", "EMENUITEMSEPARATOR", "EDIT", "PART_EDIT", "EEDIT",
  "TREE", "PART_TREE", "ETREE", "CHOOSER", "PART_CHOOSER", "ECHOOSER",
  "LABEL", "ELABEL", "ITEM", "EITEM", "PART_ITEM", "BUTTON", "PART_BUTTON",
  "EBUTTON", "BUTTONOK", "BUTTONCANCEL", "BUTTONHELP", "BUTTONYES",
  "BUTTONNO", "CHECKBOX", "ECHECKBOX", "PART_CHECKBOX", "RADIO", "ERADIO",
  "PART_RADIO", "PROGRESSBAR", "EPROGRESSBAR", "PART_PROGRESSBAR", "LIST",
  "PART_LIST", "ELIST", "TABLE", "ETABLE", "PART_TABLE", "COMBOBOX",
  "PART_COMBOBOX", "ECOMBOBOX", "GVIM", "EGVIM", "TEXT", "PART_TEXT",
  "ETEXT", "PIXMAP", "PART_PIXMAP", "EPIXMAP", "DEFAULT", "EDEFAULT",
  "SENSITIVE", "ESENSITIVE", "VARIABLE", "PART_VARIABLE", "EVARIABLE",
  "WIDTH", "EWIDTH", "HEIGHT", "EHEIGHT", "INPUT", "INPUTFILE", "EINPUT",
  "PART_INPUT", "PART_INPUTFILE", "OUTPUT", "OUTPUTFILE", "EOUTPUT",
  "ACTION", "EACTION", "PART_ACTION", "COMM", "ENDCOMM", "IF", "ENDIF",
  "WHILE", "EWHILE", "SHOW_WIDGETS", "EMB_VARIABLE", "EMB_NUMBER",
  "END_OF_FILE", "NUMBER", "STRING", "'='", "'-'", "'+'", "'*'", "'/'",
  "UMINUS", "HSEPARATOR", "PART_HSEPARATOR", "EHSEPARATOR", "VSEPARATOR",
  "PART_VSEPARATOR", "EVSEPARATOR", "COMBOBOXTEXT", "PART_COMBOBOXTEXT",
  "ECOMBOBOXTEXT", "COMBOBOXENTRY", "PART_COMBOBOXENTRY", "ECOMBOBOXENTRY",
  "HSCALE", "PART_HSCALE", "EHSCALE", "VSCALE", "PART_VSCALE", "EVSCALE",
  "SPINBUTTON", "PART_SPINBUTTON", "ESPINBUTTON", "TIMER", "PART_TIMER",
  "ETIMER", "TOGGLEBUTTON", "PART_TOGGLEBUTTON", "ETOGGLEBUTTON",
  "STATUSBAR", "PART_STATUSBAR", "ESTATUSBAR", "COLORBUTTON",
  "PART_COLORBUTTON", "ECOLORBUTTON", "FONTBUTTON", "PART_FONTBUTTON",
  "EFONTBUTTON", "TERMINAL", "PART_TERMINAL", "ETERMINAL", "EVENTBOX",
  "PART_EVENTBOX", "EEVENTBOX", "EXPANDER", "PART_EXPANDER", "EEXPANDER",
  "'>'", "':'", "'!'", "$accept", "window", "wlist", "widget", "entry",
  "edit", "tree", "chooser", "text", "button", "checkbox", "radiobutton",
  "progressbar", "list", "table", "combobox", "gvim", "pixmap", "menubar",
  "menuwlist", "menu", "menuitem", "menuitemseparator", "hseparator",
  "vseparator", "comboboxtext", "comboboxentry", "hscale", "vscale",
  "spinbutton", "timer", "togglebutton", "statusbar", "colorbutton",
  "fontbutton", "terminal", "attr", "label", "sensitive", "defaultvalue",
  "width", "height", "input", "output", "variable", "action", "item",
  "tagattr", "imperative", "assignment", "expression", "if", "then",
  "endif", "while", "ewhile", "do", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,    61,    45,    43,    42,    47,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,    62,    58,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   168,   169,   169,   169,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   172,
     172,   172,   173,   173,   173,   174,   174,   174,   175,   175,
     175,   176,   176,   176,   177,   177,   177,   177,   177,   177,
     177,   178,   178,   178,   179,   179,   179,   180,   180,   180,
     181,   181,   181,   182,   182,   182,   183,   183,   184,   185,
     185,   186,   186,   186,   186,   186,   187,   187,   187,   188,
     188,   188,   188,   188,   189,   189,   189,   189,   190,   190,
     191,   191,   192,   192,   193,   193,   194,   194,   195,   195,
     196,   196,   197,   197,   198,   198,   199,   199,   200,   200,
     201,   201,   202,   202,   203,   203,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   205,   206,   207,
     208,   209,   210,   210,   210,   210,   210,   211,   211,   212,
     212,   213,   213,   214,   214,   214,   215,   215,   216,   216,
     216,   216,   217,   218,   218,   218,   218,   218,   218,   218,
     218,   219,   220,   221,   222,   223,   224
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     6,     1,     2,     1,     2,     4,
       5,     6,     7,     4,     5,     6,     7,     4,     5,     6,
       7,     4,     5,     6,     7,     4,     5,     6,     7,     4,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       5,     3,     3,     5,     3,     3,     5,     3,     3,     5,
       3,     3,     5,     3,     3,     5,     3,     3,     3,     3,
       3,     3,     5,     3,     3,     5,     3,     3,     5,     3,
       3,     5,     3,     3,     5,     3,     3,     5,     3,     3,
       5,     2,     4,     5,     6,     7,     1,     1,     1,     2,
       4,     5,     6,     7,     3,     4,     5,     6,     2,     3,
       2,     4,     2,     4,     3,     5,     3,     5,     3,     5,
       3,     5,     3,     5,     3,     5,     3,     5,     3,     5,
       3,     5,     3,     5,     3,     5,     0,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     5,     3,     5,     4,     3,     3,     3,
       5,     3,     5,     3,     2,     5,     3,     4,     4,     1,
       6,     6,     4,     1,     1,     3,     3,     3,     3,     3,
       4,     1,     0,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,     0,     0,     0,     0,     0,   146,     0,
       0,   146,     0,   146,     0,   146,     0,   146,     0,   146,
     146,   146,   146,   146,   146,     0,   146,     0,   146,     0,
     146,     0,   146,     0,   146,     0,   146,   146,     0,   146,
       0,     0,   191,   194,   179,     0,     0,     0,     0,   146,
       0,   146,     0,   146,     0,   146,     0,   146,     0,   146,
       0,   146,     0,   146,     0,   146,     0,   146,     0,   146,
       0,     0,     0,     0,     0,   146,     5,    32,    33,    34,
      35,    31,    36,    37,    38,    39,    40,    41,    42,    44,
      43,    45,     0,   106,   107,   108,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,     7,
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,   149,   148,   147,   150,   151,   152,   153,
     154,   155,   156,   146,     0,   146,     0,   146,     0,   146,
       0,     0,   101,   146,     0,   109,   146,   106,     0,     0,
       0,   118,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   120,     0,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,     0,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     0,     8,     0,     0,
     146,     0,     0,     0,     0,   183,   184,     0,     0,     0,
       0,     0,     0,   174,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,    59,   146,
       0,     0,     0,     0,   114,   146,    64,    62,   146,    67,
      65,   146,    70,    68,   146,    74,   146,    76,    77,    78,
      80,    79,    83,    81,   146,    86,    84,   146,    89,    87,
     146,    92,    90,   146,    95,    93,   146,    96,   146,    98,
      73,    71,   146,    99,   146,     0,     0,     0,     0,   124,
     146,   126,   146,   128,   146,   130,   146,   132,   146,   134,
     146,   136,   146,   138,   146,   140,   146,   142,   146,   144,
     146,     0,     0,     0,     0,   146,     0,   146,     0,   146,
       0,   146,   146,     0,   146,     0,     3,   146,     0,     0,
       0,   119,   146,     0,     0,     0,     0,     0,     0,   192,
       0,   196,   176,     0,   146,   157,   173,     0,   159,   158,
     169,     0,   160,   161,   162,   164,     0,     0,   167,   168,
     171,     0,     9,   146,    13,   146,    25,   146,    29,     0,
     102,   146,   110,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   178,   121,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,   146,    21,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     146,     0,     0,   189,   186,   185,   187,   188,     0,     0,
       0,   177,     0,     0,     0,     0,   166,     0,     0,     0,
       0,     0,    60,     0,     0,   116,    63,    66,    69,    75,
      82,    85,    88,    91,    94,    97,    72,   100,   182,   125,
     127,   129,   131,   133,   135,   137,   139,   141,   143,   145,
       0,     0,    10,   146,    14,   146,    26,   146,    30,    18,
     146,    22,   146,   111,   146,     0,   103,   146,     0,   190,
       0,     4,   175,   170,   163,   165,   172,    11,    15,    27,
     104,   112,    19,    23,     0,     0,     0,     0,     0,     0,
     117,     0,   193,   180,   195,   181,    12,    16,    28,    20,
      24,   113,   105
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,     4,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   123,   119,   203,
     257,   120,   478,   563,   121,   565,   480
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -114
static const yytype_int16 yypact[] =
{
     106,  1293,    -9,    43,   819,  1293,    -9,  1293,    -9,  1293,
      -9,  1293,  -114,    -9,   230,    -9,   237,    -9,  -114,    -9,
     -27,  -114,    -9,  -114,    -9,  -114,    -9,  -114,    -9,  -114,
    -114,  -114,  -114,  -114,  -114,    -9,  -114,    -9,  -114,    -9,
    -114,    -9,  -114,    -9,  -114,    -9,  -114,  -114,    -9,  -114,
      -9,   -64,  -114,  -114,  -114,   -41,    -9,   -34,    -9,  -114,
      -9,  -114,    -9,  -114,    -9,  -114,    -9,  -114,    -9,  -114,
      -9,  -114,    -9,  -114,    -9,  -114,    -9,  -114,    -9,  -114,
      -9,  1293,    -9,  1293,    -9,  1451,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,   260,    90,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
      39,    39,   -31,    -6,  -114,   -20,   -42,    -9,   -18,     1,
       8,    -9,    27,    29,    31,    33,    -9,    -9,    37,    45,
      47,    -9,  1451,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  1451,    -4,  1451,    -2,  1451,     0,  1451,
    2785,     7,  -114,   271,     9,  -114,   260,  -114,    11,  3069,
      13,  -114,  2765,    15,  3248,    17,  3280,    20,  3555,    22,
    3578,  3600,  3623,  3645,  3668,  3367,    23,  3385,    24,  3430,
      25,  3453,    26,  3489,    28,  3690,    30,  3735,  3517,    32,
    3758,    34,   -53,   -36,  -114,    36,  -114,    38,  2673,    40,
    2375,    42,  2200,    44,  2058,    46,  1983,    48,  1947,    50,
    1866,    52,  1821,    56,  1762,    58,  1705,    59,  1637,    60,
    1451,    61,  1451,    62,  1293,    -9,  1293,    -9,  1293,    -9,
    1293,  1293,    -9,  1293,    -9,  -114,  2121,  -114,   350,    -9,
    -114,    -9,    92,   350,    -9,  -114,  -114,   -29,   -10,    51,
      21,  1293,    88,  -114,    93,    63,    71,    70,    53,    64,
      91,    94,    73,    75,    66,    68,    72,    83,    96,    74,
    2223,  1293,  2434,  1293,  2552,  1293,   976,  -114,  -114,  -114,
    2830,   350,  2955,   350,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,    98,    95,   100,    79,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,   706,  1293,   392,  1293,  1451,    76,  1451,    78,  1451,
      80,  1451,  1451,    82,  1451,    84,  -114,   260,    85,  3100,
      86,  -114,   271,    87,    39,    39,    39,    39,    39,  -114,
     102,  -114,  -114,    89,  1451,  -114,  -114,    97,  -114,  -114,
    -114,   101,  -114,  -114,  -114,  -114,   129,     4,  -114,  -114,
    -114,   135,  -114,  1451,  -114,  1451,  -114,  1451,  -114,  2803,
    -114,   271,  -114,   260,  3126,  3185,  3218,  3310,  3780,  3803,
    3848,  3825,  3886,  3909,  3943,  3970,  4000,    39,  -114,  -114,
    -114,  2699,  2401,  2257,  2141,  2040,  1965,  1884,  1848,  1789,
    1732,  1667,  -114,  1451,  -114,  1451,  2280,  1293,  2462,  1293,
    2583,  1293,  1134,  1574,  1293,   579,  1293,  2986,   350,  -114,
    -114,  2866,   350,    16,   -48,   -48,    19,    19,  1293,    39,
    1293,  -114,  2166,   131,   114,   113,  -114,   115,   156,  2318,
    2493,  2616,  -114,  2893,  3012,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,    10,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
    1592,   597,  -114,  1451,  -114,  1451,  -114,  1451,  -114,  -114,
    1451,  -114,  1451,  -114,   260,  3157,  -114,   271,   977,    16,
    1135,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  2342,  2526,  2642,  1610,   678,  3043,
    -114,  2929,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,   111,    14,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,   -11,
     -13,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,   -12,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,   573,    77,  -114,
    -113,  -114,  -114,  -114,  -114,  -114,  -114
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -107
static const yytype_int16 yytable[] =
{
     160,   163,   263,   167,   171,   166,   169,   122,   258,   172,
     260,   174,   260,   176,   260,   178,   260,   180,   181,   182,
     183,   184,   185,   260,   187,   260,   189,   260,   191,   260,
     193,   260,   195,   260,   197,   198,   260,   200,   260,   260,
     260,   260,   260,   124,   260,   202,   260,   208,   260,   210,
     260,   212,   260,   214,   260,   216,   260,   218,   260,   220,
     260,   222,   260,   224,   260,   226,   260,   228,   260,   387,
     388,   264,   260,   246,   260,   260,   260,   260,   260,   260,
     260,   204,   260,   259,   260,   384,   385,   386,   387,   388,
     260,   206,   260,   262,   260,   266,   260,   486,   260,   245,
     260,   260,   260,   260,   384,   385,   386,   387,   388,     1,
       2,   253,   254,   335,   267,   142,   153,   487,   155,   390,
     157,   268,   159,   381,   384,   385,   386,   387,   388,   336,
     395,   385,   386,   387,   388,   393,   389,   396,   390,   400,
     270,   280,   271,   282,   272,   284,   273,   286,   255,   256,
     276,   290,   398,   399,   292,   391,   245,   390,   277,   261,
     278,   281,   247,   283,   392,   285,   404,   245,   405,   245,
     408,   245,   289,   245,   291,   542,   293,   390,   295,   402,
     298,   409,   301,   390,   403,   304,   390,   306,   314,   317,
     320,   323,   230,   326,   232,   328,   410,   332,   438,   334,
     543,   337,   481,   338,   440,   340,   544,   342,   545,   344,
     483,   346,   437,   348,   484,   350,   479,   352,   361,   247,
     363,   354,   439,   356,   358,   360,   362,   364,   397,   401,
     247,   406,   247,   407,   247,   167,   247,   377,   379,   411,
     382,   457,   485,   459,   245,   461,   245,   464,   488,   466,
     468,   470,   472,   162,    16,    17,   546,    18,    19,     0,
      20,    16,    17,   165,    18,    19,     0,    20,     0,     0,
       0,   473,   474,   475,   476,   477,     0,   419,   421,     0,
     167,     0,   423,   424,   248,   249,   425,   250,   251,   426,
     252,     0,   427,     0,   428,  -106,  -106,     0,  -106,  -106,
       0,  -106,   429,     0,     0,   430,     0,   247,   431,   247,
       0,   432,     0,     0,   433,     0,   434,     0,     0,     0,
     435,     0,   436,     0,   508,     0,     0,     0,   441,     0,
     442,     0,   443,     0,   444,     0,   445,     0,   446,     0,
     447,     0,   448,     0,   449,   365,   450,   367,   451,   369,
       0,   371,   372,   456,   374,   458,     0,   460,     0,   462,
     463,     0,   465,     0,     0,   467,   539,     0,     0,     0,
     471,     0,   394,     0,    16,    17,     0,    18,    19,   245,
      20,   245,   482,   245,     0,   245,   245,     0,   245,     0,
       0,     0,   413,     0,   415,     0,   417,     0,     0,     0,
       0,   489,     0,   490,     0,   491,     0,     0,   245,   493,
       0,   494,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,     0,   245,
       0,   245,     0,   125,     0,   126,     0,   127,     0,     0,
       0,   520,   247,   521,   247,     0,   247,     0,   247,   247,
       0,   247,     0,     0,     0,   167,     0,   534,   535,   537,
       0,     0,     0,     0,     0,     0,     0,   245,     0,   245,
       0,   247,   128,   453,   129,   455,   130,   131,     0,   132,
       0,   133,     0,   134,   135,     0,   136,   137,   138,   139,
     247,   140,   247,   141,   247,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   554,     0,   555,     0,   556,     0,     0,   557,     0,
     558,     0,   559,     0,     0,   561,     0,     0,     0,     0,
     247,     0,   247,     0,     0,     0,     0,   245,     0,   245,
       0,   245,     0,     0,   245,     0,   245,     0,     0,     0,
       0,     0,   245,     0,   245,     0,   454,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   523,     0,
     525,     0,   527,     0,     0,   530,     0,   532,     0,   154,
       0,   156,     0,   158,     0,     0,   161,     0,   164,   538,
     168,   540,   170,     0,     0,   173,     0,   175,     0,   177,
     247,   179,   247,     0,   247,     0,     0,   247,   186,   247,
     188,     0,   190,     0,   192,   247,   194,   247,   196,     0,
     125,   199,   126,   201,   127,     0,     0,     0,     0,   205,
       0,   207,     0,   209,     0,   211,     0,   213,   125,   215,
     126,   217,   127,   219,     0,   221,     0,   223,     0,   225,
       0,   227,     0,   229,     0,   231,     0,   233,     0,   128,
       0,   129,     0,   130,   131,     0,   132,     0,   133,     0,
     134,   135,     0,   136,   137,   138,   139,   128,   140,   129,
     141,   130,   131,     0,   132,     0,   133,     0,   134,   135,
       0,   136,   137,   138,   139,     0,   140,     0,   141,     0,
     265,     0,     0,     0,   269,     0,     0,     0,     0,   274,
     275,     0,     0,     0,   279,     0,     0,     0,     0,   125,
       0,   126,     0,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   531,     0,     0,     0,   125,     0,   126,
       0,   127,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   553,   130,   131,     0,   132,     0,   133,     0,   134,
     135,     0,   136,   137,   138,   139,     0,   140,     0,   141,
       0,     0,     0,     0,     0,     0,   128,     0,   129,     0,
     130,   131,     0,   132,     0,   133,     0,   134,   135,     0,
     136,   137,   138,   139,     0,   140,     0,   141,   366,     0,
     368,     0,   370,     0,     0,   373,     0,   375,     0,     0,
       0,     0,   378,     0,   380,     5,     6,   383,     7,     8,
       0,     9,     0,    10,    11,     0,     0,    12,     0,    13,
      14,    15,   570,    16,    17,     0,    18,    19,     0,    20,
       0,    21,    22,     0,    23,    24,     0,    25,    26,     0,
     125,     0,   126,     0,   127,    27,    28,   452,    29,    30,
      31,    32,    33,    34,     0,    35,    36,     0,    37,    38,
       0,    39,    40,    41,     0,    42,     0,    43,    44,    45,
       0,    46,     0,    47,    48,     0,    49,    50,     0,   128,
       0,   129,     0,   130,   131,     0,   132,     0,   133,     0,
     134,   135,     0,   136,   137,   138,   139,     0,   140,     0,
     141,    51,     0,    52,     0,    53,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      56,     0,    57,    58,     0,    59,    60,     0,    61,    62,
       0,    63,    64,     0,    65,    66,     0,    67,    68,     0,
      69,    70,     0,    71,    72,     0,    73,    74,     0,    75,
      76,     0,    77,    78,     0,    79,    80,     0,    81,    82,
       0,    83,    84,   234,   235,     0,   236,   237,     0,   238,
       0,   239,   240,   418,     0,    12,     0,    13,    14,    15,
       0,    16,    17,     0,    18,    19,     0,    20,     0,    21,
      22,     0,    23,    24,     0,    25,    26,   125,     0,   126,
       0,   127,     0,    27,    28,     0,    29,    30,    31,    32,
      33,    34,     0,    35,    36,     0,    37,    38,     0,    39,
      40,    41,     0,    42,     0,    43,    44,    45,     0,    46,
       0,    47,    48,     0,    49,    50,   128,     0,   129,     0,
     130,   131,     0,   132,     0,   133,     0,   134,   135,     0,
     136,   137,   138,   139,     0,   140,     0,   141,     0,    51,
       0,    52,   562,    53,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    56,     0,
      57,    58,     0,    59,    60,     0,    61,    62,     0,    63,
      64,     0,    65,    66,     0,    67,    68,     0,    69,    70,
       0,    71,    72,     0,    73,    74,     0,    75,    76,     0,
      77,    78,     0,    79,    80,     0,   241,   242,     0,   243,
     244,   234,   235,     0,   236,   237,     0,   238,     0,   239,
     240,   528,     0,    12,     0,    13,    14,    15,     0,    16,
      17,     0,    18,    19,     0,    20,     0,    21,    22,     0,
      23,    24,     0,    25,    26,   125,     0,   126,     0,   127,
       0,    27,    28,     0,    29,    30,    31,    32,    33,    34,
       0,    35,    36,     0,    37,    38,     0,    39,    40,    41,
       0,    42,     0,    43,    44,    45,     0,    46,     0,    47,
      48,     0,    49,    50,   128,     0,   129,     0,   130,   131,
       0,   132,     0,   133,     0,   134,   135,     0,   136,   137,
     138,   139,     0,   140,     0,   141,     0,    51,     0,    52,
       0,    53,   564,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    56,     0,    57,    58,
       0,    59,    60,     0,    61,    62,     0,    63,    64,     0,
      65,    66,     0,    67,    68,     0,    69,    70,     0,    71,
      72,     0,    73,    74,     0,    75,    76,     0,    77,    78,
       0,    79,    80,     0,   241,   242,     0,   243,   244,     5,
       6,     0,     7,     8,     0,     9,     0,    10,    11,     0,
       0,    12,     0,    13,    14,    15,     0,    16,    17,     0,
      18,    19,     0,    20,     0,    21,    22,     0,    23,    24,
       0,    25,    26,     0,     0,     0,     0,     0,     0,    27,
      28,     0,    29,    30,    31,    32,    33,    34,     0,    35,
      36,     0,    37,    38,     0,    39,    40,    41,     0,    42,
       0,    43,    44,    45,     0,    46,     0,    47,    48,     0,
      49,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,    52,     0,    53,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,     0,    57,    58,     0,    59,
      60,     0,    61,    62,     0,    63,    64,     0,    65,    66,
       0,    67,    68,     0,    69,    70,     0,    71,    72,     0,
      73,    74,     0,    75,    76,     0,    77,    78,     0,    79,
      80,     0,    81,    82,     0,    83,    84,   234,   235,     0,
     236,   237,     0,   238,     0,   239,   240,     0,     0,    12,
       0,    13,    14,    15,     0,    16,    17,     0,    18,    19,
       0,    20,     0,    21,    22,     0,    23,    24,     0,    25,
      26,     0,     0,     0,     0,     0,     0,    27,    28,     0,
      29,    30,    31,    32,    33,    34,     0,    35,    36,     0,
      37,    38,     0,    39,    40,    41,     0,    42,     0,    43,
      44,    45,     0,    46,     0,    47,    48,     0,    49,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,     0,    52,     0,    53,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    56,     0,    57,    58,     0,    59,    60,     0,
      61,    62,     0,    63,    64,     0,    65,    66,     0,    67,
      68,     0,    69,    70,     0,    71,    72,     0,    73,    74,
       0,    75,    76,     0,    77,    78,     0,    79,    80,     0,
     241,   242,     0,   243,   244,   125,     0,   126,     0,   127,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,   126,     0,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,     0,   126,   128,   127,   129,     0,   130,   131,
       0,   132,     0,   133,     0,   134,   135,     0,   136,   137,
     138,   139,   128,   140,   129,   141,   130,   131,   125,   132,
     126,   133,   127,   134,   135,     0,   136,   137,   138,   139,
     128,   140,   129,   141,   130,   131,     0,   132,     0,   133,
       0,   134,   135,     0,   136,   137,   138,   139,   125,   140,
     126,   141,   127,     0,     0,     0,     0,   128,     0,   129,
       0,   130,   131,     0,   132,     0,   133,     0,   134,   135,
       0,   136,   137,   138,   139,   529,   140,     0,   141,     0,
       0,     0,     0,     0,     0,     0,   125,   128,   126,   129,
     127,   130,   131,   552,   132,     0,   133,     0,   134,   135,
       0,   136,   137,   138,   139,     0,   140,     0,   141,     0,
       0,   569,     0,   125,     0,   126,     0,   127,     0,     0,
       0,     0,     0,     0,     0,   128,     0,   129,     0,   130,
     131,     0,   132,     0,   133,   359,   134,   135,     0,   136,
     137,   138,   139,   125,   140,   126,   141,   127,     0,     0,
       0,     0,   128,     0,   129,     0,   130,   131,     0,   132,
       0,   133,     0,   134,   135,   519,   136,   137,   138,   139,
     125,   140,   126,   141,   127,     0,     0,     0,     0,     0,
       0,     0,   128,     0,   129,     0,   130,   131,     0,   132,
       0,   133,     0,   134,   135,     0,   136,   137,   138,   139,
     357,   140,   125,   141,   126,     0,   127,     0,     0,   128,
       0,   129,     0,   130,   131,     0,   132,     0,   133,     0,
     134,   135,     0,   136,   137,   138,   139,   518,   140,   125,
     141,   126,     0,   127,     0,     0,     0,     0,     0,     0,
       0,   128,     0,   129,     0,   130,   131,   125,   132,   126,
     133,   127,   134,   135,   355,   136,   137,   138,   139,     0,
     140,     0,   141,     0,     0,   125,     0,   126,   128,   127,
     129,     0,   130,   131,     0,   132,     0,   133,     0,   134,
     135,   517,   136,   137,   138,   139,   128,   140,   129,   141,
     130,   131,     0,   132,     0,   133,     0,   134,   135,     0,
     136,   137,   138,   139,   128,   140,   129,   141,   130,   131,
     353,   132,     0,   133,     0,   134,   135,     0,   136,   137,
     138,   139,     0,   140,     0,   141,     0,     0,   125,     0,
     126,     0,   127,     0,     0,     0,     0,   516,     0,     0,
       0,     0,     0,     0,     0,     0,   125,     0,   126,     0,
     127,     0,   351,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,     0,   126,   128,   127,   129,
     515,   130,   131,     0,   132,     0,   133,     0,   134,   135,
       0,   136,   137,   138,   139,   128,   140,   129,   141,   130,
     131,     0,   132,     0,   133,     0,   134,   135,     0,   136,
     137,   138,   139,   128,   140,   129,   141,   130,   131,     0,
     132,     0,   133,     0,   134,   135,     0,   136,   137,   138,
     139,   125,   140,   126,   141,   127,     0,     0,     0,     0,
     349,     0,     0,     0,     0,     0,     0,     0,     0,   125,
       0,   126,     0,   127,     0,     0,     0,     0,   514,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,     0,   129,   347,   130,   131,   376,   132,     0,   133,
       0,   134,   135,     0,   136,   137,   138,   139,   128,   140,
     129,   141,   130,   131,     0,   132,     0,   133,     0,   134,
     135,     0,   136,   137,   138,   139,     0,   140,     0,   141,
       0,     0,   125,     0,   126,     0,   127,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,     0,     0,     0,
     513,     0,   125,     0,   126,     0,   127,     0,     0,     0,
       0,     0,     0,     0,     0,   345,     0,     0,     0,     0,
       0,   128,     0,   129,     0,   130,   131,   125,   132,   126,
     133,   127,   134,   135,     0,   136,   137,   138,   139,     0,
     140,   128,   141,   129,     0,   130,   131,     0,   132,     0,
     133,   412,   134,   135,     0,   136,   137,   138,   139,     0,
     140,   125,   141,   126,     0,   127,   128,     0,   129,     0,
     130,   131,     0,   132,     0,   133,     0,   134,   135,     0,
     136,   137,   138,   139,   125,   140,   126,   141,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   512,     0,
     128,     0,   129,     0,   130,   131,     0,   132,   522,   133,
       0,   134,   135,     0,   136,   137,   138,   139,   125,   140,
     126,   141,   127,   128,     0,   129,     0,   130,   131,     0,
     132,     0,   133,     0,   134,   135,     0,   136,   137,   138,
     139,   125,   140,   126,   141,   127,   547,     0,     0,     0,
       0,     0,     0,     0,   343,     0,     0,   128,     0,   129,
       0,   130,   131,     0,   132,     0,   133,     0,   134,   135,
     566,   136,   137,   138,   139,     0,   140,     0,   141,   125,
     128,   126,   129,   127,   130,   131,     0,   132,     0,   133,
       0,   134,   135,     0,   136,   137,   138,   139,     0,   140,
       0,   141,     0,   125,     0,   126,     0,   127,     0,     0,
       0,   511,     0,     0,     0,     0,     0,     0,   128,     0,
     129,     0,   130,   131,     0,   132,     0,   133,     0,   134,
     135,     0,   136,   137,   138,   139,   125,   140,   126,   141,
     127,     0,   128,     0,   129,     0,   130,   131,     0,   132,
       0,   133,     0,   134,   135,     0,   136,   137,   138,   139,
       0,   140,   125,   141,   126,   414,   127,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,   129,     0,   130,
     131,     0,   132,     0,   133,     0,   134,   135,     0,   136,
     137,   138,   139,   524,   140,   125,   141,   126,     0,   127,
       0,   128,     0,   129,     0,   130,   131,     0,   132,     0,
     133,     0,   134,   135,     0,   136,   137,   138,   139,     0,
     140,     0,   141,   125,   548,   126,   341,   127,     0,     0,
       0,     0,     0,     0,   128,     0,   129,     0,   130,   131,
       0,   132,     0,   133,     0,   134,   135,     0,   136,   137,
     138,   139,   510,   140,   125,   141,   126,   567,   127,     0,
       0,     0,   128,     0,   129,     0,   130,   131,     0,   132,
       0,   133,     0,   134,   135,     0,   136,   137,   138,   139,
       0,   140,     0,   141,     0,   416,     0,   125,     0,   126,
       0,   127,     0,   128,     0,   129,     0,   130,   131,     0,
     132,     0,   133,     0,   134,   135,     0,   136,   137,   138,
     139,     0,   140,   125,   141,   126,   526,   127,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,   129,     0,
     130,   131,     0,   132,     0,   133,     0,   134,   135,     0,
     136,   137,   138,   139,   125,   140,   126,   141,   127,   549,
       0,     0,   128,     0,   129,     0,   130,   131,     0,   132,
       0,   133,     0,   134,   135,     0,   136,   137,   138,   139,
       0,   140,     0,   141,     0,   568,     0,   125,     0,   126,
       0,   127,     0,   128,     0,   129,     0,   130,   131,     0,
     132,     0,   133,     0,   134,   135,     0,   136,   137,   138,
     139,     0,   140,   125,   141,   126,     0,   127,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,   129,     0,
     130,   131,     0,   132,     0,   133,     0,   134,   135,     0,
     136,   137,   138,   139,   125,   140,   126,   141,   127,     0,
       0,     0,   128,     0,   129,     0,   130,   131,     0,   132,
       0,   133,     0,   134,   135,     0,   136,   137,   138,   139,
     125,   140,   126,   141,   127,     0,     0,     0,     0,     0,
       0,     0,     0,   128,     0,   129,     0,   130,   131,     0,
     132,     0,   133,     0,   134,   135,     0,   136,   137,   138,
     139,     0,   140,     0,   141,     0,     0,     0,     0,   128,
       0,   129,     0,   130,   131,     0,   132,     0,   133,     0,
     134,   135,     0,   136,   137,   138,   139,   296,   140,   297,
     141,   339,     0,   287,   288,     0,   125,     0,   126,     0,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   492,     0,     0,     0,   125,   509,   126,     0,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,   128,   126,   129,   127,   130,
     131,     0,   132,   420,   133,     0,   134,   135,     0,   136,
     137,   138,   139,     0,   140,   128,   141,   129,     0,   130,
     131,   125,   132,   126,   133,   127,   134,   135,     0,   136,
     137,   138,   139,   128,   140,   129,   141,   130,   131,   536,
     132,     0,   133,     0,   134,   135,     0,   136,   137,   138,
     139,     0,   140,     0,   141,     0,     0,   125,     0,   126,
     128,   127,   129,     0,   130,   131,   550,   132,     0,   133,
       0,   134,   135,     0,   136,   137,   138,   139,     0,   140,
       0,   141,     0,     0,   125,     0,   126,     0,   127,     0,
       0,     0,     0,     0,     0,     0,   128,     0,   129,     0,
     130,   131,   572,   132,     0,   133,     0,   134,   135,     0,
     136,   137,   138,   139,     0,   140,     0,   141,     0,     0,
     125,     0,   126,   128,   127,   129,     0,   130,   131,     0,
     132,   422,   133,     0,   134,   135,     0,   136,   137,   138,
     139,     0,   140,     0,   141,     0,   125,     0,   126,     0,
     127,     0,     0,     0,     0,     0,     0,     0,     0,   128,
       0,   129,   533,   130,   131,     0,   132,     0,   133,     0,
     134,   135,     0,   136,   137,   138,   139,   125,   140,   126,
     141,   127,     0,     0,     0,   128,     0,   129,   551,   130,
     131,     0,   132,     0,   133,     0,   134,   135,     0,   136,
     137,   138,   139,   125,   140,   126,   141,   127,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,   129,   571,
     130,   131,     0,   132,     0,   133,     0,   134,   135,     0,
     136,   137,   138,   139,   125,   140,   126,   141,   127,     0,
       0,     0,   128,     0,   129,     0,   130,   131,   294,   132,
       0,   133,     0,   134,   135,     0,   136,   137,   138,   139,
     125,   140,   126,   141,   127,     0,     0,     0,     0,     0,
       0,     0,     0,   128,     0,   129,     0,   130,   131,   469,
     132,     0,   133,     0,   134,   135,     0,   136,   137,   138,
     139,   125,   140,   126,   141,   127,     0,     0,     0,   128,
       0,   129,     0,   130,   131,   495,   132,     0,   133,     0,
     134,   135,     0,   136,   137,   138,   139,   125,   140,   126,
     141,   127,     0,     0,     0,     0,     0,     0,     0,     0,
     128,     0,   129,     0,   130,   131,   560,   132,     0,   133,
       0,   134,   135,     0,   136,   137,   138,   139,   125,   140,
     126,   141,   127,     0,     0,     0,   128,     0,   129,     0,
     130,   131,     0,   132,     0,   133,     0,   134,   135,   496,
     136,   137,   138,   139,     0,   140,   125,   141,   126,     0,
     127,     0,     0,     0,     0,     0,     0,   128,     0,   129,
       0,   130,   131,     0,   132,     0,   133,     0,   134,   135,
       0,   136,   137,   138,   139,   497,   140,     0,   141,   125,
       0,   126,     0,   127,     0,   128,     0,   129,     0,   130,
     131,     0,   132,     0,   133,     0,   134,   135,     0,   136,
     137,   138,   139,   299,   140,   300,   141,     0,     0,   125,
       0,   126,     0,   127,     0,     0,     0,     0,   128,     0,
     129,     0,   130,   131,     0,   132,     0,   133,     0,   134,
     135,     0,   136,   137,   138,   139,     0,   140,   302,   141,
     303,   125,     0,   126,     0,   127,     0,     0,   128,     0,
     129,     0,   130,   131,     0,   132,     0,   133,     0,   134,
     135,     0,   136,   137,   138,   139,     0,   140,     0,   141,
     498,   125,     0,   126,     0,   127,     0,     0,     0,     0,
     128,     0,   129,     0,   130,   131,     0,   132,     0,   133,
       0,   134,   135,     0,   136,   137,   138,   139,     0,   140,
       0,   141,     0,     0,     0,     0,     0,     0,     0,     0,
     128,     0,   129,     0,   130,   131,     0,   132,     0,   133,
       0,   134,   135,     0,   136,   137,   138,   139,   125,   140,
     126,   141,   127,     0,     0,     0,     0,     0,     0,     0,
       0,   312,   313,     0,     0,     0,   125,     0,   126,     0,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   315,   316,     0,     0,     0,   128,     0,   129,
       0,   130,   131,     0,   132,     0,   133,     0,   134,   135,
       0,   136,   137,   138,   139,   128,   140,   129,   141,   130,
     131,   125,   132,   126,   133,   127,   134,   135,     0,   136,
     137,   138,   139,     0,   140,     0,   141,     0,     0,     0,
     318,   319,     0,     0,   125,     0,   126,     0,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,     0,   129,     0,   130,   131,   321,   132,   322,   133,
       0,   134,   135,     0,   136,   137,   138,   139,     0,   140,
     125,   141,   126,   128,   127,   129,     0,   130,   131,     0,
     132,     0,   133,     0,   134,   135,     0,   136,   137,   138,
     139,     0,   140,     0,   141,   324,   325,     0,   125,     0,
     126,     0,   127,     0,     0,     0,     0,     0,     0,   128,
       0,   129,     0,   130,   131,     0,   132,     0,   133,     0,
     134,   135,     0,   136,   137,   138,   139,     0,   140,     0,
     141,   330,     0,   331,     0,     0,   125,   128,   126,   129,
     127,   130,   131,   305,   132,     0,   133,     0,   134,   135,
       0,   136,   137,   138,   139,     0,   140,     0,   141,   125,
       0,   126,     0,   127,     0,     0,   307,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,   129,     0,   130,
     131,   125,   132,   126,   133,   127,   134,   135,   308,   136,
     137,   138,   139,     0,   140,     0,   141,     0,   128,     0,
     129,     0,   130,   131,   125,   132,   126,   133,   127,   134,
     135,   309,   136,   137,   138,   139,     0,   140,     0,   141,
     128,     0,   129,     0,   130,   131,   125,   132,   126,   133,
     127,   134,   135,   310,   136,   137,   138,   139,     0,   140,
       0,   141,     0,   128,     0,   129,     0,   130,   131,   125,
     132,   126,   133,   127,   134,   135,   311,   136,   137,   138,
     139,     0,   140,     0,   141,   128,     0,   129,     0,   130,
     131,   125,   132,   126,   133,   127,   134,   135,     0,   136,
     137,   138,   139,     0,   140,     0,   141,     0,   128,     0,
     129,     0,   130,   131,     0,   132,     0,   133,     0,   134,
     135,   327,   136,   137,   138,   139,     0,   140,     0,   141,
     128,     0,   129,     0,   130,   131,   125,   132,   126,   133,
     127,   134,   135,     0,   136,   137,   138,   139,     0,   140,
       0,   141,     0,     0,     0,     0,     0,     0,     0,   125,
       0,   126,     0,   127,     0,     0,     0,     0,   329,     0,
       0,     0,     0,     0,     0,   128,     0,   129,     0,   130,
     131,   125,   132,   126,   133,   127,   134,   135,   499,   136,
     137,   138,   139,     0,   140,     0,   141,   333,   128,     0,
     129,     0,   130,   131,   125,   132,   126,   133,   127,   134,
     135,     0,   136,   137,   138,   139,     0,   140,   500,   141,
     128,     0,   129,     0,   130,   131,   125,   132,   126,   133,
     127,   134,   135,     0,   136,   137,   138,   139,     0,   140,
       0,   141,     0,   128,     0,   129,   502,   130,   131,   125,
     132,   126,   133,   127,   134,   135,     0,   136,   137,   138,
     139,     0,   140,     0,   141,   128,   501,   129,     0,   130,
     131,     0,   132,     0,   133,     0,   134,   135,     0,   136,
     137,   138,   139,     0,   140,     0,   141,   125,   128,   126,
     129,   127,   130,   131,     0,   132,     0,   133,     0,   134,
     135,     0,   136,   137,   138,   139,     0,   140,     0,   141,
     125,   503,   126,     0,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,   129,     0,
     130,   131,     0,   132,     0,   133,   504,   134,   135,     0,
     136,   137,   138,   139,   125,   140,   126,   141,   127,   128,
       0,   129,     0,   130,   131,     0,   132,     0,   133,     0,
     134,   135,     0,   136,   137,   138,   139,     0,   140,     0,
     141,   125,     0,   126,   505,   127,     0,     0,     0,     0,
       0,     0,     0,   128,     0,   129,     0,   130,   131,     0,
     132,     0,   133,     0,   134,   135,     0,   136,   137,   138,
     139,   125,   140,   126,   141,   127,   506,     0,     0,     0,
     128,     0,   129,     0,   130,   131,     0,   132,     0,   133,
       0,   134,   135,     0,   136,   137,   138,   139,     0,   140,
       0,   141,     0,     0,     0,     0,     0,     0,     0,   507,
     128,     0,   129,     0,   130,   131,     0,   132,     0,   133,
       0,   134,   135,     0,   136,   137,   138,   139,     0,   140,
       0,   141
};

static const yytype_int16 yycheck[] =
{
      12,    14,    44,    16,    31,    16,    18,    16,   121,    21,
      16,    23,    16,    25,    16,    27,    16,    29,    30,    31,
      32,    33,    34,    16,    36,    16,    38,    16,    40,    16,
      42,    16,    44,    16,    46,    47,    16,    49,    16,    16,
      16,    16,    16,     0,    16,   109,    16,    59,    16,    61,
      16,    63,    16,    65,    16,    67,    16,    69,    16,    71,
      16,    73,    16,    75,    16,    77,    16,    79,    16,   117,
     118,   113,    16,    85,    16,    16,    16,    16,    16,    16,
      16,   122,    16,   114,    16,   114,   115,   116,   117,   118,
      16,   125,    16,   113,    16,   113,    16,    93,    16,    85,
      16,    16,    16,    16,   114,   115,   116,   117,   118,     3,
       4,    21,    22,   166,   113,     4,     5,   113,     7,   167,
       9,   113,    11,    31,   114,   115,   116,   117,   118,   165,
      42,   115,   116,   117,   118,   114,   165,    44,   167,    86,
     113,   153,   113,   155,   113,   157,   113,   159,   109,   110,
     113,   163,    81,    83,   166,   165,   142,   167,   113,   165,
     113,   165,    85,   165,   113,   165,    93,   153,    93,   155,
      98,   157,   165,   159,   165,    44,   165,   167,   165,    88,
     165,    98,   165,   167,    90,   165,   167,   165,   165,   165,
     165,   165,    81,   165,    83,   165,   100,   165,   103,   165,
      86,   165,   113,   165,   125,   165,    93,   165,    93,   165,
     113,   165,   114,   165,   113,   165,   114,   165,   230,   142,
     232,   165,   122,   165,   165,   165,   165,   165,   165,   165,
     153,   165,   155,   165,   157,   248,   159,   248,   250,   165,
     253,   165,   113,   165,   230,   165,   232,   165,   113,   165,
     165,   165,   165,    23,    24,    25,   100,    27,    28,    -1,
      30,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      -1,   384,   385,   386,   387,   388,    -1,   289,   291,    -1,
     293,    -1,   293,   295,    24,    25,   298,    27,    28,   301,
      30,    -1,   304,    -1,   306,    24,    25,    -1,    27,    28,
      -1,    30,   314,    -1,    -1,   317,    -1,   230,   320,   232,
      -1,   323,    -1,    -1,   326,    -1,   328,    -1,    -1,    -1,
     332,    -1,   334,    -1,   437,    -1,    -1,    -1,   340,    -1,
     342,    -1,   344,    -1,   346,    -1,   348,    -1,   350,    -1,
     352,    -1,   354,    -1,   356,   234,   358,   236,   360,   238,
      -1,   240,   241,   365,   243,   367,    -1,   369,    -1,   371,
     372,    -1,   374,    -1,    -1,   377,   479,    -1,    -1,    -1,
     382,    -1,   261,    -1,    24,    25,    -1,    27,    28,   365,
      30,   367,   394,   369,    -1,   371,   372,    -1,   374,    -1,
      -1,    -1,   281,    -1,   283,    -1,   285,    -1,    -1,    -1,
      -1,   413,    -1,   415,    -1,   417,    -1,    -1,   394,   421,
      -1,   423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   413,    -1,   415,
      -1,   417,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,
      -1,   453,   365,   455,   367,    -1,   369,    -1,   371,   372,
      -1,   374,    -1,    -1,    -1,   468,    -1,   468,   470,   472,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,    -1,   455,
      -1,   394,    80,   362,    82,   364,    84,    85,    -1,    87,
      -1,    89,    -1,    91,    92,    -1,    94,    95,    96,    97,
     413,    99,   415,   101,   417,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   523,    -1,   525,    -1,   527,    -1,    -1,   530,    -1,
     532,    -1,   534,    -1,    -1,   537,    -1,    -1,    -1,    -1,
     453,    -1,   455,    -1,    -1,    -1,    -1,   523,    -1,   525,
      -1,   527,    -1,    -1,   530,    -1,   532,    -1,    -1,    -1,
      -1,    -1,   538,    -1,   540,    -1,   164,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   457,    -1,
     459,    -1,   461,    -1,    -1,   464,    -1,   466,    -1,     6,
      -1,     8,    -1,    10,    -1,    -1,    13,    -1,    15,   478,
      17,   480,    19,    -1,    -1,    22,    -1,    24,    -1,    26,
     523,    28,   525,    -1,   527,    -1,    -1,   530,    35,   532,
      37,    -1,    39,    -1,    41,   538,    43,   540,    45,    -1,
      41,    48,    43,    50,    45,    -1,    -1,    -1,    -1,    56,
      -1,    58,    -1,    60,    -1,    62,    -1,    64,    41,    66,
      43,    68,    45,    70,    -1,    72,    -1,    74,    -1,    76,
      -1,    78,    -1,    80,    -1,    82,    -1,    84,    -1,    80,
      -1,    82,    -1,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    92,    -1,    94,    95,    96,    97,    80,    99,    82,
     101,    84,    85,    -1,    87,    -1,    89,    -1,    91,    92,
      -1,    94,    95,    96,    97,    -1,    99,    -1,   101,    -1,
     127,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,
     137,    -1,    -1,    -1,   141,    -1,    -1,    -1,    -1,    41,
      -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   164,    -1,    -1,    -1,    41,    -1,    43,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,   164,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      92,    -1,    94,    95,    96,    97,    -1,    99,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,
      84,    85,    -1,    87,    -1,    89,    -1,    91,    92,    -1,
      94,    95,    96,    97,    -1,    99,    -1,   101,   235,    -1,
     237,    -1,   239,    -1,    -1,   242,    -1,   244,    -1,    -1,
      -1,    -1,   249,    -1,   251,     6,     7,   254,     9,    10,
      -1,    12,    -1,    14,    15,    -1,    -1,    18,    -1,    20,
      21,    22,   164,    24,    25,    -1,    27,    28,    -1,    30,
      -1,    32,    33,    -1,    35,    36,    -1,    38,    39,    -1,
      41,    -1,    43,    -1,    45,    46,    47,   161,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    -1,    59,    60,
      -1,    62,    63,    64,    -1,    66,    -1,    68,    69,    70,
      -1,    72,    -1,    74,    75,    -1,    77,    78,    -1,    80,
      -1,    82,    -1,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    92,    -1,    94,    95,    96,    97,    -1,    99,    -1,
     101,   102,    -1,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
     121,    -1,   123,   124,    -1,   126,   127,    -1,   129,   130,
      -1,   132,   133,    -1,   135,   136,    -1,   138,   139,    -1,
     141,   142,    -1,   144,   145,    -1,   147,   148,    -1,   150,
     151,    -1,   153,   154,    -1,   156,   157,    -1,   159,   160,
      -1,   162,   163,     6,     7,    -1,     9,    10,    -1,    12,
      -1,    14,    15,    17,    -1,    18,    -1,    20,    21,    22,
      -1,    24,    25,    -1,    27,    28,    -1,    30,    -1,    32,
      33,    -1,    35,    36,    -1,    38,    39,    41,    -1,    43,
      -1,    45,    -1,    46,    47,    -1,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    -1,    59,    60,    -1,    62,
      63,    64,    -1,    66,    -1,    68,    69,    70,    -1,    72,
      -1,    74,    75,    -1,    77,    78,    80,    -1,    82,    -1,
      84,    85,    -1,    87,    -1,    89,    -1,    91,    92,    -1,
      94,    95,    96,    97,    -1,    99,    -1,   101,    -1,   102,
      -1,   104,   105,   106,    -1,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,    -1,
     123,   124,    -1,   126,   127,    -1,   129,   130,    -1,   132,
     133,    -1,   135,   136,    -1,   138,   139,    -1,   141,   142,
      -1,   144,   145,    -1,   147,   148,    -1,   150,   151,    -1,
     153,   154,    -1,   156,   157,    -1,   159,   160,    -1,   162,
     163,     6,     7,    -1,     9,    10,    -1,    12,    -1,    14,
      15,    17,    -1,    18,    -1,    20,    21,    22,    -1,    24,
      25,    -1,    27,    28,    -1,    30,    -1,    32,    33,    -1,
      35,    36,    -1,    38,    39,    41,    -1,    43,    -1,    45,
      -1,    46,    47,    -1,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    -1,    59,    60,    -1,    62,    63,    64,
      -1,    66,    -1,    68,    69,    70,    -1,    72,    -1,    74,
      75,    -1,    77,    78,    80,    -1,    82,    -1,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    92,    -1,    94,    95,
      96,    97,    -1,    99,    -1,   101,    -1,   102,    -1,   104,
      -1,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   120,   121,    -1,   123,   124,
      -1,   126,   127,    -1,   129,   130,    -1,   132,   133,    -1,
     135,   136,    -1,   138,   139,    -1,   141,   142,    -1,   144,
     145,    -1,   147,   148,    -1,   150,   151,    -1,   153,   154,
      -1,   156,   157,    -1,   159,   160,    -1,   162,   163,     6,
       7,    -1,     9,    10,    -1,    12,    -1,    14,    15,    -1,
      -1,    18,    -1,    20,    21,    22,    -1,    24,    25,    -1,
      27,    28,    -1,    30,    -1,    32,    33,    -1,    35,    36,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    -1,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    -1,    59,    60,    -1,    62,    63,    64,    -1,    66,
      -1,    68,    69,    70,    -1,    72,    -1,    74,    75,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,    -1,   104,    -1,   106,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   120,   121,    -1,   123,   124,    -1,   126,
     127,    -1,   129,   130,    -1,   132,   133,    -1,   135,   136,
      -1,   138,   139,    -1,   141,   142,    -1,   144,   145,    -1,
     147,   148,    -1,   150,   151,    -1,   153,   154,    -1,   156,
     157,    -1,   159,   160,    -1,   162,   163,     6,     7,    -1,
       9,    10,    -1,    12,    -1,    14,    15,    -1,    -1,    18,
      -1,    20,    21,    22,    -1,    24,    25,    -1,    27,    28,
      -1,    30,    -1,    32,    33,    -1,    35,    36,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    -1,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    -1,
      59,    60,    -1,    62,    63,    64,    -1,    66,    -1,    68,
      69,    70,    -1,    72,    -1,    74,    75,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,    -1,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,   121,    -1,   123,   124,    -1,   126,   127,    -1,
     129,   130,    -1,   132,   133,    -1,   135,   136,    -1,   138,
     139,    -1,   141,   142,    -1,   144,   145,    -1,   147,   148,
      -1,   150,   151,    -1,   153,   154,    -1,   156,   157,    -1,
     159,   160,    -1,   162,   163,    41,    -1,    43,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    43,    80,    45,    82,    -1,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    92,    -1,    94,    95,
      96,    97,    80,    99,    82,   101,    84,    85,    41,    87,
      43,    89,    45,    91,    92,    -1,    94,    95,    96,    97,
      80,    99,    82,   101,    84,    85,    -1,    87,    -1,    89,
      -1,    91,    92,    -1,    94,    95,    96,    97,    41,    99,
      43,   101,    45,    -1,    -1,    -1,    -1,    80,    -1,    82,
      -1,    84,    85,    -1,    87,    -1,    89,    -1,    91,    92,
      -1,    94,    95,    96,    97,   161,    99,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    80,    43,    82,
      45,    84,    85,   161,    87,    -1,    89,    -1,    91,    92,
      -1,    94,    95,    96,    97,    -1,    99,    -1,   101,    -1,
      -1,   161,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    84,
      85,    -1,    87,    -1,    89,   158,    91,    92,    -1,    94,
      95,    96,    97,    41,    99,    43,   101,    45,    -1,    -1,
      -1,    -1,    80,    -1,    82,    -1,    84,    85,    -1,    87,
      -1,    89,    -1,    91,    92,   158,    94,    95,    96,    97,
      41,    99,    43,   101,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    -1,    84,    85,    -1,    87,
      -1,    89,    -1,    91,    92,    -1,    94,    95,    96,    97,
     155,    99,    41,   101,    43,    -1,    45,    -1,    -1,    80,
      -1,    82,    -1,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    92,    -1,    94,    95,    96,    97,   155,    99,    41,
     101,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    -1,    84,    85,    41,    87,    43,
      89,    45,    91,    92,   152,    94,    95,    96,    97,    -1,
      99,    -1,   101,    -1,    -1,    41,    -1,    43,    80,    45,
      82,    -1,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      92,   152,    94,    95,    96,    97,    80,    99,    82,   101,
      84,    85,    -1,    87,    -1,    89,    -1,    91,    92,    -1,
      94,    95,    96,    97,    80,    99,    82,   101,    84,    85,
     149,    87,    -1,    89,    -1,    91,    92,    -1,    94,    95,
      96,    97,    -1,    99,    -1,   101,    -1,    -1,    41,    -1,
      43,    -1,    45,    -1,    -1,    -1,    -1,   149,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    43,    -1,
      45,    -1,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    43,    80,    45,    82,
     146,    84,    85,    -1,    87,    -1,    89,    -1,    91,    92,
      -1,    94,    95,    96,    97,    80,    99,    82,   101,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    92,    -1,    94,
      95,    96,    97,    80,    99,    82,   101,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    92,    -1,    94,    95,    96,
      97,    41,    99,    43,   101,    45,    -1,    -1,    -1,    -1,
     143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    43,    -1,    45,    -1,    -1,    -1,    -1,   143,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,   140,    84,    85,     5,    87,    -1,    89,
      -1,    91,    92,    -1,    94,    95,    96,    97,    80,    99,
      82,   101,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      92,    -1,    94,    95,    96,    97,    -1,    99,    -1,   101,
      -1,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,    -1,
      -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     140,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    -1,    84,    85,    41,    87,    43,
      89,    45,    91,    92,    -1,    94,    95,    96,    97,    -1,
      99,    80,   101,    82,    -1,    84,    85,    -1,    87,    -1,
      89,     8,    91,    92,    -1,    94,    95,    96,    97,    -1,
      99,    41,   101,    43,    -1,    45,    80,    -1,    82,    -1,
      84,    85,    -1,    87,    -1,    89,    -1,    91,    92,    -1,
      94,    95,    96,    97,    41,    99,    43,   101,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
      80,    -1,    82,    -1,    84,    85,    -1,    87,     8,    89,
      -1,    91,    92,    -1,    94,    95,    96,    97,    41,    99,
      43,   101,    45,    80,    -1,    82,    -1,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    92,    -1,    94,    95,    96,
      97,    41,    99,    43,   101,    45,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   134,    -1,    -1,    80,    -1,    82,
      -1,    84,    85,    -1,    87,    -1,    89,    -1,    91,    92,
       8,    94,    95,    96,    97,    -1,    99,    -1,   101,    41,
      80,    43,    82,    45,    84,    85,    -1,    87,    -1,    89,
      -1,    91,    92,    -1,    94,    95,    96,    97,    -1,    99,
      -1,   101,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,
      -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      92,    -1,    94,    95,    96,    97,    41,    99,    43,   101,
      45,    -1,    80,    -1,    82,    -1,    84,    85,    -1,    87,
      -1,    89,    -1,    91,    92,    -1,    94,    95,    96,    97,
      -1,    99,    41,   101,    43,    11,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    92,    -1,    94,
      95,    96,    97,    11,    99,    41,   101,    43,    -1,    45,
      -1,    80,    -1,    82,    -1,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    92,    -1,    94,    95,    96,    97,    -1,
      99,    -1,   101,    41,    11,    43,   131,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    92,    -1,    94,    95,
      96,    97,   131,    99,    41,   101,    43,    11,    45,    -1,
      -1,    -1,    80,    -1,    82,    -1,    84,    85,    -1,    87,
      -1,    89,    -1,    91,    92,    -1,    94,    95,    96,    97,
      -1,    99,    -1,   101,    -1,    13,    -1,    41,    -1,    43,
      -1,    45,    -1,    80,    -1,    82,    -1,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    92,    -1,    94,    95,    96,
      97,    -1,    99,    41,   101,    43,    13,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,
      84,    85,    -1,    87,    -1,    89,    -1,    91,    92,    -1,
      94,    95,    96,    97,    41,    99,    43,   101,    45,    13,
      -1,    -1,    80,    -1,    82,    -1,    84,    85,    -1,    87,
      -1,    89,    -1,    91,    92,    -1,    94,    95,    96,    97,
      -1,    99,    -1,   101,    -1,    13,    -1,    41,    -1,    43,
      -1,    45,    -1,    80,    -1,    82,    -1,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    92,    -1,    94,    95,    96,
      97,    -1,    99,    41,   101,    43,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,
      84,    85,    -1,    87,    -1,    89,    -1,    91,    92,    -1,
      94,    95,    96,    97,    41,    99,    43,   101,    45,    -1,
      -1,    -1,    80,    -1,    82,    -1,    84,    85,    -1,    87,
      -1,    89,    -1,    91,    92,    -1,    94,    95,    96,    97,
      41,    99,    43,   101,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    92,    -1,    94,    95,    96,
      97,    -1,    99,    -1,   101,    -1,    -1,    -1,    -1,    80,
      -1,    82,    -1,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    92,    -1,    94,    95,    96,    97,    32,    99,    34,
     101,   128,    -1,    18,    19,    -1,    41,    -1,    43,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    41,   128,    43,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    80,    43,    82,    45,    84,
      85,    -1,    87,    23,    89,    -1,    91,    92,    -1,    94,
      95,    96,    97,    -1,    99,    80,   101,    82,    -1,    84,
      85,    41,    87,    43,    89,    45,    91,    92,    -1,    94,
      95,    96,    97,    80,    99,    82,   101,    84,    85,    23,
      87,    -1,    89,    -1,    91,    92,    -1,    94,    95,    96,
      97,    -1,    99,    -1,   101,    -1,    -1,    41,    -1,    43,
      80,    45,    82,    -1,    84,    85,    23,    87,    -1,    89,
      -1,    91,    92,    -1,    94,    95,    96,    97,    -1,    99,
      -1,   101,    -1,    -1,    41,    -1,    43,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,
      84,    85,    23,    87,    -1,    89,    -1,    91,    92,    -1,
      94,    95,    96,    97,    -1,    99,    -1,   101,    -1,    -1,
      41,    -1,    43,    80,    45,    82,    -1,    84,    85,    -1,
      87,    26,    89,    -1,    91,    92,    -1,    94,    95,    96,
      97,    -1,    99,    -1,   101,    -1,    41,    -1,    43,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    26,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    92,    -1,    94,    95,    96,    97,    41,    99,    43,
     101,    45,    -1,    -1,    -1,    80,    -1,    82,    26,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    92,    -1,    94,
      95,    96,    97,    41,    99,    43,   101,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    26,
      84,    85,    -1,    87,    -1,    89,    -1,    91,    92,    -1,
      94,    95,    96,    97,    41,    99,    43,   101,    45,    -1,
      -1,    -1,    80,    -1,    82,    -1,    84,    85,    29,    87,
      -1,    89,    -1,    91,    92,    -1,    94,    95,    96,    97,
      41,    99,    43,   101,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    84,    85,    29,
      87,    -1,    89,    -1,    91,    92,    -1,    94,    95,    96,
      97,    41,    99,    43,   101,    45,    -1,    -1,    -1,    80,
      -1,    82,    -1,    84,    85,    29,    87,    -1,    89,    -1,
      91,    92,    -1,    94,    95,    96,    97,    41,    99,    43,
     101,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    84,    85,    29,    87,    -1,    89,
      -1,    91,    92,    -1,    94,    95,    96,    97,    41,    99,
      43,   101,    45,    -1,    -1,    -1,    80,    -1,    82,    -1,
      84,    85,    -1,    87,    -1,    89,    -1,    91,    92,    34,
      94,    95,    96,    97,    -1,    99,    41,   101,    43,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      -1,    84,    85,    -1,    87,    -1,    89,    -1,    91,    92,
      -1,    94,    95,    96,    97,    37,    99,    -1,   101,    41,
      -1,    43,    -1,    45,    -1,    80,    -1,    82,    -1,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    92,    -1,    94,
      95,    96,    97,    35,    99,    37,   101,    -1,    -1,    41,
      -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      92,    -1,    94,    95,    96,    97,    -1,    99,    38,   101,
      40,    41,    -1,    43,    -1,    45,    -1,    -1,    80,    -1,
      82,    -1,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      92,    -1,    94,    95,    96,    97,    -1,    99,    -1,   101,
      40,    41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    84,    85,    -1,    87,    -1,    89,
      -1,    91,    92,    -1,    94,    95,    96,    97,    -1,    99,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    84,    85,    -1,    87,    -1,    89,
      -1,    91,    92,    -1,    94,    95,    96,    97,    41,    99,
      43,   101,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    -1,    -1,    -1,    41,    -1,    43,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    -1,    -1,    -1,    80,    -1,    82,
      -1,    84,    85,    -1,    87,    -1,    89,    -1,    91,    92,
      -1,    94,    95,    96,    97,    80,    99,    82,   101,    84,
      85,    41,    87,    43,    89,    45,    91,    92,    -1,    94,
      95,    96,    97,    -1,    99,    -1,   101,    -1,    -1,    -1,
      60,    61,    -1,    -1,    41,    -1,    43,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    84,    85,    63,    87,    65,    89,
      -1,    91,    92,    -1,    94,    95,    96,    97,    -1,    99,
      41,   101,    43,    80,    45,    82,    -1,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    92,    -1,    94,    95,    96,
      97,    -1,    99,    -1,   101,    66,    67,    -1,    41,    -1,
      43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    -1,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    92,    -1,    94,    95,    96,    97,    -1,    99,    -1,
     101,    74,    -1,    76,    -1,    -1,    41,    80,    43,    82,
      45,    84,    85,    48,    87,    -1,    89,    -1,    91,    92,
      -1,    94,    95,    96,    97,    -1,    99,    -1,   101,    41,
      -1,    43,    -1,    45,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    84,
      85,    41,    87,    43,    89,    45,    91,    92,    48,    94,
      95,    96,    97,    -1,    99,    -1,   101,    -1,    80,    -1,
      82,    -1,    84,    85,    41,    87,    43,    89,    45,    91,
      92,    48,    94,    95,    96,    97,    -1,    99,    -1,   101,
      80,    -1,    82,    -1,    84,    85,    41,    87,    43,    89,
      45,    91,    92,    48,    94,    95,    96,    97,    -1,    99,
      -1,   101,    -1,    80,    -1,    82,    -1,    84,    85,    41,
      87,    43,    89,    45,    91,    92,    48,    94,    95,    96,
      97,    -1,    99,    -1,   101,    80,    -1,    82,    -1,    84,
      85,    41,    87,    43,    89,    45,    91,    92,    -1,    94,
      95,    96,    97,    -1,    99,    -1,   101,    -1,    80,    -1,
      82,    -1,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      92,    71,    94,    95,    96,    97,    -1,    99,    -1,   101,
      80,    -1,    82,    -1,    84,    85,    41,    87,    43,    89,
      45,    91,    92,    -1,    94,    95,    96,    97,    -1,    99,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    84,
      85,    41,    87,    43,    89,    45,    91,    92,    48,    94,
      95,    96,    97,    -1,    99,    -1,   101,    79,    80,    -1,
      82,    -1,    84,    85,    41,    87,    43,    89,    45,    91,
      92,    -1,    94,    95,    96,    97,    -1,    99,    55,   101,
      80,    -1,    82,    -1,    84,    85,    41,    87,    43,    89,
      45,    91,    92,    -1,    94,    95,    96,    97,    -1,    99,
      -1,   101,    -1,    80,    -1,    82,    61,    84,    85,    41,
      87,    43,    89,    45,    91,    92,    -1,    94,    95,    96,
      97,    -1,    99,    -1,   101,    80,    58,    82,    -1,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    92,    -1,    94,
      95,    96,    97,    -1,    99,    -1,   101,    41,    80,    43,
      82,    45,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      92,    -1,    94,    95,    96,    97,    -1,    99,    -1,   101,
      41,    65,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,
      84,    85,    -1,    87,    -1,    89,    67,    91,    92,    -1,
      94,    95,    96,    97,    41,    99,    43,   101,    45,    80,
      -1,    82,    -1,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    92,    -1,    94,    95,    96,    97,    -1,    99,    -1,
     101,    41,    -1,    43,    71,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    92,    -1,    94,    95,    96,
      97,    41,    99,    43,   101,    45,    76,    -1,    -1,    -1,
      80,    -1,    82,    -1,    84,    85,    -1,    87,    -1,    89,
      -1,    91,    92,    -1,    94,    95,    96,    97,    -1,    99,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      80,    -1,    82,    -1,    84,    85,    -1,    87,    -1,    89,
      -1,    91,    92,    -1,    94,    95,    96,    97,    -1,    99,
      -1,   101
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,   169,   204,     6,     7,     9,    10,    12,
      14,    15,    18,    20,    21,    22,    24,    25,    27,    28,
      30,    32,    33,    35,    36,    38,    39,    46,    47,    49,
      50,    51,    52,    53,    54,    56,    57,    59,    60,    62,
      63,    64,    66,    68,    69,    70,    72,    74,    75,    77,
      78,   102,   104,   106,   108,   120,   121,   123,   124,   126,
     127,   129,   130,   132,   133,   135,   136,   138,   139,   141,
     142,   144,   145,   147,   148,   150,   151,   153,   154,   156,
     157,   159,   160,   162,   163,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   216,
     219,   222,    16,   215,     0,    41,    43,    45,    80,    82,
      84,    85,    87,    89,    91,    92,    94,    95,    96,    97,
      99,   101,   170,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   170,   215,   170,   215,   170,   215,   170,
     204,   215,    23,   188,   215,    26,   187,   188,   215,   204,
     215,    31,   204,   215,   204,   215,   204,   215,   204,   215,
     204,   204,   204,   204,   204,   204,   215,   204,   215,   204,
     215,   204,   215,   204,   215,   204,   215,   204,   204,   215,
     204,   215,   109,   217,   122,   215,   125,   215,   204,   215,
     204,   215,   204,   215,   204,   215,   204,   215,   204,   215,
     204,   215,   204,   215,   204,   215,   204,   215,   204,   215,
     170,   215,   170,   215,     6,     7,     9,    10,    12,    14,
      15,   159,   160,   162,   163,   171,   204,   216,    24,    25,
      27,    28,    30,    21,    22,   109,   110,   218,   218,   114,
      16,   165,   113,    44,   113,   215,   113,   113,   113,   215,
     113,   113,   113,   113,   215,   215,   113,   113,   113,   215,
     204,   165,   204,   165,   204,   165,   204,    18,    19,   165,
     204,   165,   204,   165,    29,   165,    32,    34,   165,    35,
      37,   165,    38,    40,   165,    48,   165,    48,    48,    48,
      48,    48,    54,    55,   165,    57,    58,   165,    60,    61,
     165,    63,    65,   165,    66,    67,   165,    71,   165,    73,
      74,    76,   165,    79,   165,   166,   165,   165,   165,   128,
     165,   131,   165,   134,   165,   137,   165,   140,   165,   143,
     165,   146,   165,   149,   165,   152,   165,   155,   165,   158,
     165,   204,   165,   204,   165,   170,   215,   170,   215,   170,
     215,   170,   170,   215,   170,   215,     5,   187,   215,   204,
     215,    31,   188,   215,   114,   115,   116,   117,   118,   165,
     167,   165,   113,   114,   170,    42,    44,   165,    81,    83,
      86,   165,    88,    90,    93,    93,   165,   165,    98,    98,
     100,   165,     8,   170,    11,   170,    13,   170,    17,   204,
      23,   188,    26,   187,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   114,   103,   122,
     125,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   161,   170,   164,   170,   204,   165,   204,   165,
     204,   165,   204,   204,   165,   204,   165,   204,   165,    29,
     165,   204,   165,   218,   218,   218,   218,   218,   220,   114,
     224,   113,   204,   113,   113,   113,    93,   113,   113,   204,
     204,   204,    19,   204,   204,    29,    34,    37,    40,    48,
      55,    58,    61,    65,    67,    71,    76,    79,   218,   128,
     131,   134,   137,   140,   143,   146,   149,   152,   155,   158,
     204,   204,     8,   170,    11,   170,    13,   170,    17,   161,
     170,   164,   170,    26,   187,   204,    23,   188,   170,   218,
     170,     5,    44,    86,    93,    93,   100,     8,    11,    13,
      23,    26,   161,   164,   204,   204,   204,   204,   204,   204,
      29,   204,   105,   221,   107,   223,     8,    11,    13,   161,
     164,    26,    23
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1464 of yacc.c  */
#line 163 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 167 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 171 "gtkdialog_parser.y"
    { 
    		token_store_attr(PUSH | WIDGET_WINDOW, (yyvsp[(2) - (6)].nvval)); 
		start_up();
	}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 181 "gtkdialog_parser.y"
    { 
		token_store(SUM);      
	}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 186 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
	}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 189 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
		token_store(SUM);      
	}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 193 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(2) - (6)].nvval)); 
	}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 196 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(3) - (7)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 200 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
	}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 203 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
		token_store(SUM);      
	}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 207 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(2) - (6)].nvval)); 
	}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 210 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(3) - (7)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 214 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_EVENTBOX); 
	}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 217 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_EVENTBOX); 
		token_store(SUM);      
	}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 221 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_EVENTBOX, (yyvsp[(2) - (6)].nvval)); 
	}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 224 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_EVENTBOX, (yyvsp[(3) - (7)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 228 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_EXPANDER); 
	}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 231 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_EXPANDER); 
		token_store(SUM);      
	}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 235 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_EXPANDER, (yyvsp[(2) - (6)].nvval)); 
	}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 238 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_EXPANDER, (yyvsp[(3) - (7)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 242 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
	}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 245 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
		token_store(SUM);      
	}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 249 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 252 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);      
	}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 256 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(1) - (4)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
	}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 260 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(2) - (5)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
		token_store(SUM);      
	}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 299 "gtkdialog_parser.y"
    {
                          token_store(PUSH | WIDGET_ENTRY); 
			 }
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 302 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_ENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 305 "gtkdialog_parser.y"
    {
                  yyerror("</entry> expected instead of <entry>.");}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 310 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_EDIT); 
	}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 313 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_EDIT, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 316 "gtkdialog_parser.y"
    {
    		yyerror("</edit> expected instead of <edit>.");
	}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 322 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TREE); 
	}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 325 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_TREE, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 328 "gtkdialog_parser.y"
    {
   		yyerror("</tree> expected instead of <tree>.");
	}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 334 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHOOSER); 
	}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 337 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_CHOOSER, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 340 "gtkdialog_parser.y"
    {
		yyerror("</chooser> expected instead of <chooser>.");
	}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 346 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TEXT); 
	}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 349 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_TEXT, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 352 "gtkdialog_parser.y"
    {yyerror("</text> expected instead of <text>.");}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 356 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_BUTTON);  }
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 357 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_BUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 360 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_OKBUTTON);}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 361 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_CANCELBUTTON);}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 362 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_HELPBUTTON);}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 363 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_NOBUTTON);}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 364 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_YESBUTTON);}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 368 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHECKBOX);
	}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 371 "gtkdialog_parser.y"
    {
		//token_store_with_tag_attributes(PUSH | WIDGET_CHECKBOX, $2);
                token_store_attr(PUSH | WIDGET_CHECKBOX, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 375 "gtkdialog_parser.y"
    {
		yyerror("</checkbox> expected instead of <checkbox>.");
	}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 381 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_RADIOBUTTON);
           }
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 384 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_RADIOBUTTON, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 387 "gtkdialog_parser.y"
    {
		yyerror("</radiobutton> expected instead of <radiobutton>.");
           }
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 393 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_PROGRESSBAR);
           }
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 396 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_PROGRESSBAR, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 399 "gtkdialog_parser.y"
    {
		yyerror("</progressbar> expected instead of <progressbar>.");
           }
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 405 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_LIST); 
	}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 408 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_LIST, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 411 "gtkdialog_parser.y"
    {
    		yyerror("</list> expected instead of <list>.");
	}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 417 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TABLE); 
	}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 420 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TABLE, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 423 "gtkdialog_parser.y"
    {
    		yyerror("</table> expected instead of <table>.");
	}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 429 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_COMBOBOX);
	}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 432 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_COMBOBOX, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 438 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_GVIM);}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 442 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_PIXMAP);}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 443 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_PIXMAP, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 456 "gtkdialog_parser.y"
    {
		yyerror("The menubar widget requires at least one menu widget.");
	}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 459 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUBAR);
	}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 462 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUBAR);
		token_store(SUM);
	}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 466 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUBAR, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 469 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUBAR, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);
	}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 482 "gtkdialog_parser.y"
    {
		yyerror("The menu widget requires at least one menuitem widget.");
	}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 485 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENU);
	}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 488 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENU);
		token_store(SUM);
	}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 492 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENU, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 495 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENU, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);
	}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 502 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM);
	}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 505 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM);
		token_store(SUM);
	}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 509 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 512 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(3) - (6)].nvval));
		token_store(SUM);
	}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 519 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEMSEPARATOR);
	}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 522 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEMSEPARATOR);
		token_store(SUM);
	}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 529 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSEPARATOR);
	}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 532 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 538 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSEPARATOR);
	}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 541 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 547 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXTEXT);
	}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 550 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXTEXT, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 556 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXENTRY);
	}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 559 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 565 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSCALE);
	}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 568 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSCALE, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 574 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSCALE);
	}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 577 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSCALE, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 583 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_SPINBUTTON);
	}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 586 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_SPINBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 592 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TIMER);
	}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 595 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TIMER, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 601 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TOGGLEBUTTON);
	}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 604 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TOGGLEBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 610 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_STATUSBAR);
	}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 613 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_STATUSBAR, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 619 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COLORBUTTON);
	}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 622 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COLORBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 628 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_FONTBUTTON);
	}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 631 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_FONTBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 637 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TERMINAL);
	}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 640 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TERMINAL, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 660 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_LABEL, (yyvsp[(2) - (3)].cval));     }
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 665 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_SENSITIVE, (yyvsp[(2) - (3)].cval));  }
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 670 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_DEFAULT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 675 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_WIDTH, (yyvsp[(2) - (3)].cval));    }
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 680 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_HEIGHT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 685 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_SHELL,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 688 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 691 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 694 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 697 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, "", (yyvsp[(2) - (4)].nvval)); 
	}
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 703 "gtkdialog_parser.y"
    {
	         fprintf( stderr, "<output>: Not implemented.\n" ); 
	}
    break;

  case 168:

/* Line 1464 of yacc.c  */
#line 706 "gtkdialog_parser.y"
    {
         	token_store_with_argument(SET|ATTR_OUTPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 169:

/* Line 1464 of yacc.c  */
#line 712 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET | ATTR_VARIABLE, (yyvsp[(2) - (3)].cval));
	}
    break;

  case 170:

/* Line 1464 of yacc.c  */
#line 715 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET | ATTR_VARIABLE, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 721 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET|ATTR_ACTION, (yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 724 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET | ATTR_ACTION, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 730 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET | ATTR_ITEM, (yyvsp[(2) - (3)].cval));
	}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 733 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_ITEM, "");
    	}
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 736 "gtkdialog_parser.y"
    {
		      token_store_with_argument_attr(SET | ATTR_ITEM, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
                    }
    break;

  case 176:

/* Line 1464 of yacc.c  */
#line 742 "gtkdialog_parser.y"
    {
       		(yyval.nvval) = new_tag_attributeset((yyvsp[(1) - (3)].cval), (yyvsp[(3) - (3)].cval)); 
	}
    break;

  case 177:

/* Line 1464 of yacc.c  */
#line 745 "gtkdialog_parser.y"
    { 
       		(yyval.nvval) = add_tag_attribute((yyvsp[(1) - (4)].nvval), (yyvsp[(2) - (4)].cval), (yyvsp[(4) - (4)].cval)); 
	}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 752 "gtkdialog_parser.y"
    { 
		token_store(SHOW);     
	}
    break;

  case 180:

/* Line 1464 of yacc.c  */
#line 755 "gtkdialog_parser.y"
    {
  		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
	}
    break;

  case 181:

/* Line 1464 of yacc.c  */
#line 758 "gtkdialog_parser.y"
    {
		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
		instruction_set_jump((yyvsp[(6) - (6)].ival) + 1, (yyvsp[(1) - (6)].ival));
	}
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 765 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMASSG | VARIABLE_NAME, (yyvsp[(1) - (4)].cval)); 
	}
    break;

  case 183:

/* Line 1464 of yacc.c  */
#line 771 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | VARIABLE_NAME, (yyvsp[(1) - (1)].cval)); 
	}
    break;

  case 184:

/* Line 1464 of yacc.c  */
#line 774 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | CONST_NUMBER, (yyvsp[(1) - (1)].cval)); 
  	}
    break;

  case 185:

/* Line 1464 of yacc.c  */
#line 777 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_ADD);
	}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 780 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_SUBST);
	}
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 783 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_MULT);
	}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 786 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_DIV);
	}
    break;

  case 189:

/* Line 1464 of yacc.c  */
#line 789 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_EQ);
	}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 792 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_NE);
	}
    break;

  case 192:

/* Line 1464 of yacc.c  */
#line 802 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 809 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 813 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 817 "gtkdialog_parser.y"
    {
		token_store(GOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 196:

/* Line 1464 of yacc.c  */
#line 824 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
    }
    break;



/* Line 1464 of yacc.c  */
#line 4281 "gtkdialog_parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 830 "gtkdialog_parser.y"


extern gboolean option_print_ir;

int gtkdialog_wrap(void)
{
	#ifdef DEBUG
	g_message("%s(): Start", __func__);
	#endif
	return 1;
}

int gtkdialog_error(char *c)
{
	g_error("%s: Error in line %d, near token '%s': %s\n", 
		PACKAGE, linenumber, Token, c);
}

void yyerror_simple(char *c)
{
	g_error("%s: Error: %s", PACKAGE, c);
}

int yywarning(char *c){
	#ifdef DEBUG
		g_warning("Warning: %s.", c);
	#endif
	if (!option_no_warning)
		g_warning("%s: Warning: %s.", PACKAGE, c);
	return option_no_warning;
}


