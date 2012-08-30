
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.4.1"

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
 * Copyright (C) 2011  Thunor <thunorsif@hotmail.com>
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
#line 159 "gtkdialog_parser.c"

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
     PROGRESS = 315,
     EPROGRESS = 316,
     PART_PROGRESS = 317,
     LIST = 318,
     PART_LIST = 319,
     ELIST = 320,
     TABLE = 321,
     ETABLE = 322,
     PART_TABLE = 323,
     COMBO = 324,
     PART_COMBO = 325,
     ECOMBO = 326,
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
     ETERMINAL = 407
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
#define PART_TABLE 323
#define COMBO 324
#define PART_COMBO 325
#define ECOMBO 326
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
#line 509 "gtkdialog_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 521 "gtkdialog_parser.c"

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
# if YYENABLE_NLS
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
#define YYFINAL  120
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3483

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  161
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  187
/* YYNRULES -- Number of states.  */
#define YYNSTATES  528

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   407

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   160,     2,     2,     2,     2,     2,     2,
       2,     2,   116,   115,     2,   114,     2,   117,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   159,     2,
       2,   113,   158,     2,     2,     2,     2,     2,     2,     2,
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
     105,   106,   107,   108,   109,   110,   111,   112,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    11,    18,    20,    23,    25,    28,
      33,    39,    46,    54,    59,    65,    72,    80,    85,    91,
      98,   106,   111,   117,   119,   121,   123,   125,   127,   129,
     131,   133,   135,   137,   139,   141,   143,   145,   147,   149,
     151,   153,   155,   157,   159,   161,   163,   165,   167,   169,
     171,   173,   177,   183,   187,   191,   197,   201,   205,   211,
     215,   219,   225,   229,   233,   239,   243,   247,   253,   257,
     261,   265,   269,   273,   277,   283,   287,   291,   297,   301,
     305,   311,   315,   319,   325,   329,   333,   339,   343,   347,
     353,   357,   361,   367,   370,   375,   381,   388,   396,   398,
     400,   402,   405,   410,   416,   423,   431,   435,   440,   446,
     453,   456,   460,   463,   468,   471,   476,   480,   486,   490,
     496,   500,   506,   510,   516,   520,   526,   530,   536,   540,
     546,   550,   556,   560,   566,   570,   576,   580,   586,   587,
     590,   593,   596,   599,   602,   605,   608,   611,   614,   617,
     621,   625,   629,   633,   637,   641,   645,   651,   655,   661,
     666,   670,   674,   678,   684,   688,   691,   697,   701,   706,
     711,   713,   720,   727,   732,   734,   736,   740,   744,   748,
     752,   756,   761,   763,   764,   766,   768,   770
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     162,     0,    -1,   197,   163,    -1,     3,   163,   197,     5,
      -1,     4,   208,   158,   163,   197,     5,    -1,   164,    -1,
     163,   164,    -1,   209,    -1,   163,   209,    -1,     6,   163,
     197,     8,    -1,   163,     6,   163,   197,     8,    -1,     7,
     208,   158,   163,   197,     8,    -1,   163,     7,   208,   158,
     163,   197,     8,    -1,     9,   163,   197,    11,    -1,   163,
       9,   163,   197,    11,    -1,    10,   208,   158,   163,   197,
      11,    -1,   163,    10,   208,   158,   163,   197,    11,    -1,
      12,   163,   197,    13,    -1,   163,    12,   163,   197,    13,
      -1,    14,   208,   158,   163,   197,    13,    -1,   163,    14,
     208,   158,   163,   197,    13,    -1,    15,   163,   197,    17,
      -1,   163,    15,   163,   197,    17,    -1,   169,    -1,   165,
      -1,   166,    -1,   167,    -1,   168,    -1,   170,    -1,   171,
      -1,   172,    -1,   173,    -1,   174,    -1,   175,    -1,   176,
      -1,   178,    -1,   177,    -1,   179,    -1,   184,    -1,   185,
      -1,   186,    -1,   187,    -1,   188,    -1,   189,    -1,   190,
      -1,   191,    -1,   192,    -1,   193,    -1,   194,    -1,   195,
      -1,   196,    -1,    18,   197,    19,    -1,    20,   208,   158,
     197,    19,    -1,    18,   197,    18,    -1,    32,   197,    34,
      -1,    33,   208,   158,   197,    34,    -1,    32,   197,    32,
      -1,    35,   197,    37,    -1,    36,   208,   158,   197,    37,
      -1,    35,   197,    35,    -1,    38,   197,    40,    -1,    39,
     208,   158,   197,    40,    -1,    38,   197,    38,    -1,    74,
     197,    76,    -1,    75,   208,   158,   197,    76,    -1,    74,
     197,    74,    -1,    46,   197,    48,    -1,    47,   208,   158,
     197,    48,    -1,    49,   197,    48,    -1,    50,   197,    48,
      -1,    51,   197,    48,    -1,    53,   197,    48,    -1,    52,
     197,    48,    -1,    54,   197,    55,    -1,    56,   208,   158,
     197,    55,    -1,    54,   197,    54,    -1,    57,   197,    58,
      -1,    59,   208,   158,   197,    58,    -1,    57,   197,    57,
      -1,    60,   197,    61,    -1,    62,   208,   158,   197,    61,
      -1,    60,   197,    60,    -1,    63,   197,    65,    -1,    64,
     208,   158,   197,    65,    -1,    63,   197,    63,    -1,    66,
     197,    67,    -1,    68,   208,   158,   197,    67,    -1,    66,
     197,    66,    -1,    69,   197,    71,    -1,    70,   208,   158,
     197,    71,    -1,    72,   197,    73,    -1,    77,   197,    79,
      -1,    78,   208,   158,   197,    79,    -1,    21,    23,    -1,
      21,   181,   197,    23,    -1,   181,    21,   181,   197,    23,
      -1,    22,   208,   158,   181,   197,    23,    -1,   181,    22,
     208,   158,   181,   197,    23,    -1,   181,    -1,   182,    -1,
     183,    -1,    24,    26,    -1,    24,   180,   197,    26,    -1,
     180,    24,   180,   197,    26,    -1,    25,   208,   158,   180,
     197,    26,    -1,   180,    25,   208,   158,   180,   197,    26,
      -1,    27,   197,    29,    -1,   180,    27,   197,    29,    -1,
      28,   208,   158,   197,    29,    -1,   180,    28,   208,   158,
     197,    29,    -1,    30,    31,    -1,   180,    30,    31,    -1,
     119,   121,    -1,   120,   208,   158,   121,    -1,   122,   124,
      -1,   123,   208,   158,   124,    -1,   125,   197,   127,    -1,
     126,   208,   158,   197,   127,    -1,   128,   197,   130,    -1,
     129,   208,   158,   197,   130,    -1,   131,   197,   133,    -1,
     132,   208,   158,   197,   133,    -1,   134,   197,   136,    -1,
     135,   208,   158,   197,   136,    -1,   137,   197,   139,    -1,
     138,   208,   158,   197,   139,    -1,   140,   197,   142,    -1,
     141,   208,   158,   197,   142,    -1,   143,   197,   145,    -1,
     144,   208,   158,   197,   145,    -1,   146,   197,   148,    -1,
     147,   208,   158,   197,   148,    -1,   149,   197,   151,    -1,
     150,   208,   158,   197,   151,    -1,   152,   197,   154,    -1,
     153,   208,   158,   197,   154,    -1,   155,   197,   157,    -1,
     156,   208,   158,   197,   157,    -1,    -1,   197,   201,    -1,
     197,   200,    -1,   197,   199,    -1,   197,   198,    -1,   197,
     202,    -1,   197,   203,    -1,   197,   204,    -1,   197,   205,
      -1,   197,   206,    -1,   197,   207,    -1,    41,   112,    42,
      -1,    84,   112,    85,    -1,    82,   112,    83,    -1,    80,
     112,    81,    -1,    86,   112,    87,    -1,    88,   112,    89,
      -1,    90,   112,    92,    -1,    93,   208,   158,   112,    92,
      -1,    91,   112,    92,    -1,    94,   208,   158,   112,    92,
      -1,    94,   208,   158,    92,    -1,    95,   112,    97,    -1,
      96,   112,    97,    -1,    98,   112,    99,    -1,   100,   208,
     158,   112,    99,    -1,    43,   112,    44,    -1,    43,    44,
      -1,    45,   208,   158,   112,    44,    -1,    16,   113,   112,
      -1,   208,    16,   113,   112,    -1,   101,   210,   158,   102,
      -1,   107,    -1,   212,   211,   158,   213,   163,   214,    -1,
     215,   211,   158,   217,   163,   216,    -1,   108,   159,   113,
     211,    -1,   108,    -1,   109,    -1,   211,   115,   211,    -1,
     211,   114,   211,    -1,   211,   116,   211,    -1,   211,   117,
     211,    -1,   211,   113,   211,    -1,   211,   160,   113,   211,
      -1,   103,    -1,    -1,   104,    -1,   105,    -1,   106,    -1,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   161,   161,   165,   169,   176,   177,   180,   181,   182,
     185,   189,   192,   196,   199,   203,   206,   210,   213,   217,
     220,   224,   228,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   267,   270,   273,   278,   281,   284,   290,   293,   296,
     302,   305,   308,   314,   317,   320,   324,   325,   328,   329,
     330,   331,   332,   336,   339,   343,   349,   352,   355,   361,
     364,   367,   373,   376,   379,   385,   388,   391,   397,   400,
     406,   410,   411,   424,   427,   430,   434,   437,   444,   445,
     446,   450,   453,   456,   460,   463,   470,   473,   477,   480,
     487,   490,   497,   500,   506,   509,   515,   518,   524,   527,
     533,   536,   542,   545,   551,   554,   560,   563,   569,   572,
     578,   581,   587,   590,   596,   599,   605,   608,   613,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   628,
     633,   638,   643,   648,   653,   658,   661,   664,   667,   670,
     676,   679,   685,   688,   695,   698,   701,   707,   710,   716,
     717,   720,   723,   730,   736,   739,   742,   745,   748,   751,
     754,   757,   763,   767,   774,   778,   782,   789
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
  "PART_RADIO", "PROGRESS", "EPROGRESS", "PART_PROGRESS", "LIST",
  "PART_LIST", "ELIST", "TABLE", "ETABLE", "PART_TABLE", "COMBO",
  "PART_COMBO", "ECOMBO", "GVIM", "EGVIM", "TEXT", "PART_TEXT", "ETEXT",
  "PIXMAP", "PART_PIXMAP", "EPIXMAP", "DEFAULT", "EDEFAULT", "SENSITIVE",
  "ESENSITIVE", "VARIABLE", "EVARIABLE", "WIDTH", "EWIDTH", "HEIGHT",
  "EHEIGHT", "INPUT", "INPUTFILE", "EINPUT", "PART_INPUT",
  "PART_INPUTFILE", "OUTPUT", "OUTPUTFILE", "EOUTPUT", "ACTION", "EACTION",
  "PART_ACTION", "COMM", "ENDCOMM", "IF", "ENDIF", "WHILE", "EWHILE",
  "SHOW_WIDGETS", "EMB_VARIABLE", "EMB_NUMBER", "END_OF_FILE", "NUMBER",
  "STRING", "'='", "'-'", "'+'", "'*'", "'/'", "UMINUS", "HSEPARATOR",
  "PART_HSEPARATOR", "EHSEPARATOR", "VSEPARATOR", "PART_VSEPARATOR",
  "EVSEPARATOR", "COMBOBOXTEXT", "PART_COMBOBOXTEXT", "ECOMBOBOXTEXT",
  "COMBOBOXENTRY", "PART_COMBOBOXENTRY", "ECOMBOBOXENTRY", "HSCALE",
  "PART_HSCALE", "EHSCALE", "VSCALE", "PART_VSCALE", "EVSCALE",
  "SPINBUTTON", "PART_SPINBUTTON", "ESPINBUTTON", "TIMER", "PART_TIMER",
  "ETIMER", "TOGGLEBUTTON", "PART_TOGGLEBUTTON", "ETOGGLEBUTTON",
  "STATUSBAR", "PART_STATUSBAR", "ESTATUSBAR", "COLORBUTTON",
  "PART_COLORBUTTON", "ECOLORBUTTON", "FONTBUTTON", "PART_FONTBUTTON",
  "EFONTBUTTON", "TERMINAL", "PART_TERMINAL", "ETERMINAL", "'>'", "':'",
  "'!'", "$accept", "window", "wlist", "widget", "entry", "edit", "tree",
  "chooser", "text", "button", "checkbox", "radiobutton", "progressbar",
  "list", "table", "combo", "gvim", "pixmap", "menubar", "menuwlist",
  "menu", "menuitem", "menuitemseparator", "hseparator", "vseparator",
  "comboboxtext", "comboboxentry", "hscale", "vscale", "spinbutton",
  "timer", "togglebutton", "statusbar", "colorbutton", "fontbutton",
  "terminal", "attr", "label", "variable", "sensitive", "defaultvalue",
  "width", "height", "input", "output", "action", "item", "tagattr",
  "imperative", "assignment", "expression", "if", "then", "endif", "while",
  "ewhile", "do", 0
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
     365,   366,   367,    61,    45,    43,    42,    47,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,    62,    58,
      33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   161,   162,   162,   162,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   165,   165,   165,   166,   166,   166,   167,   167,   167,
     168,   168,   168,   169,   169,   169,   170,   170,   170,   170,
     170,   170,   170,   171,   171,   171,   172,   172,   172,   173,
     173,   173,   174,   174,   174,   175,   175,   175,   176,   176,
     177,   178,   178,   179,   179,   179,   179,   179,   180,   180,
     180,   181,   181,   181,   181,   181,   182,   182,   182,   182,
     183,   183,   184,   184,   185,   185,   186,   186,   187,   187,
     188,   188,   189,   189,   190,   190,   191,   191,   192,   192,
     193,   193,   194,   194,   195,   195,   196,   196,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   198,
     199,   200,   201,   202,   203,   204,   204,   204,   204,   204,
     205,   205,   206,   206,   207,   207,   207,   208,   208,   209,
     209,   209,   209,   210,   211,   211,   211,   211,   211,   211,
     211,   211,   212,   213,   214,   215,   216,   217
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     6,     1,     2,     1,     2,     4,
       5,     6,     7,     4,     5,     6,     7,     4,     5,     6,
       7,     4,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     5,     3,     3,     5,     3,     3,     5,     3,
       3,     5,     3,     3,     5,     3,     3,     5,     3,     3,
       3,     3,     3,     3,     5,     3,     3,     5,     3,     3,
       5,     3,     3,     5,     3,     3,     5,     3,     3,     5,
       3,     3,     5,     2,     4,     5,     6,     7,     1,     1,
       1,     2,     4,     5,     6,     7,     3,     4,     5,     6,
       2,     3,     2,     4,     2,     4,     3,     5,     3,     5,
       3,     5,     3,     5,     3,     5,     3,     5,     3,     5,
       3,     5,     3,     5,     3,     5,     3,     5,     0,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     5,     3,     5,     4,
       3,     3,     3,     5,     3,     2,     5,     3,     4,     4,
       1,     6,     6,     4,     1,     1,     3,     3,     3,     3,
       3,     4,     1,     0,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,     0,     0,     0,   138,     0,
       0,   138,     0,   138,     0,   138,     0,   138,     0,   138,
     138,   138,   138,   138,   138,     0,   138,     0,   138,     0,
     138,     0,   138,     0,   138,     0,   138,   138,     0,   138,
       0,     0,   182,   185,   170,     0,     0,     0,     0,   138,
       0,   138,     0,   138,     0,   138,     0,   138,     0,   138,
       0,   138,     0,   138,     0,   138,     0,   138,     0,   138,
       0,   138,     5,    24,    25,    26,    27,    23,    28,    29,
      30,    31,    32,    33,    34,    36,    35,    37,     0,    98,
      99,   100,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,     7,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,   142,   141,
     140,   139,   143,   144,   145,   146,   147,   148,   138,     0,
     138,     0,   138,     0,   138,     0,     0,    93,   138,     0,
     101,   138,    98,     0,     0,     0,   110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112,
       0,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     0,     8,     0,     0,   138,     0,     0,
       0,     0,   174,   175,     0,     0,     0,     0,     0,     0,
     165,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    51,   138,     0,     0,     0,     0,
     106,   138,    56,    54,   138,    59,    57,   138,    62,    60,
     138,    66,   138,    68,    69,    70,    72,    71,    75,    73,
     138,    78,    76,   138,    81,    79,   138,    84,    82,   138,
      87,    85,   138,    88,   138,    90,    65,    63,   138,    91,
     138,     0,     0,     0,     0,   116,   138,   118,   138,   120,
     138,   122,   138,   124,   138,   126,   138,   128,   138,   130,
     138,   132,   138,   134,   138,   136,   138,   138,     0,   138,
       0,   138,     0,   138,     3,   138,     0,     0,     0,   111,
     138,     0,     0,     0,     0,     0,     0,   183,     0,   187,
     167,     0,   138,   149,   164,     0,   152,   151,   150,   153,
     154,   155,   157,     0,     0,   160,   161,   162,     0,     9,
     138,    13,   138,    17,   138,    21,     0,    94,   138,   102,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   113,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   138,
       0,     0,   180,   177,   176,   178,   179,     0,     0,     0,
     168,     0,     0,     0,   159,     0,     0,     0,     0,     0,
      52,     0,     0,   108,    55,    58,    61,    67,    74,    77,
      80,    83,    86,    89,    64,    92,   173,   117,   119,   121,
     123,   125,   127,   129,   131,   133,   135,   137,    10,   138,
      14,   138,    18,   138,    22,   103,   138,     0,    95,   138,
       0,   181,     0,     4,   166,   156,   158,   163,    11,    15,
      19,    96,   104,     0,     0,     0,     0,   109,     0,   184,
     171,   186,   172,    12,    16,    20,   105,    97
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,     4,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   119,   115,   198,
     244,   116,   447,   520,   117,   522,   449
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -111
static const yytype_int16 yypact[] =
{
      99,  1162,    -8,    10,   709,  1162,    -8,  1162,    -8,  1162,
      -8,  1162,  -111,    -8,   103,    -8,   209,    -8,  -111,    -8,
     -27,  -111,    -8,  -111,    -8,  -111,    -8,  -111,    -8,  -111,
    -111,  -111,  -111,  -111,  -111,    -8,  -111,    -8,  -111,    -8,
    -111,    -8,  -111,    -8,  -111,    -8,  -111,  -111,    -8,  -111,
      -8,   -68,  -111,  -111,  -111,   -42,    -8,   -41,    -8,  -111,
      -8,  -111,    -8,  -111,    -8,  -111,    -8,  -111,    -8,  -111,
      -8,  -111,    -8,  -111,    -8,  -111,    -8,  -111,    -8,  -111,
      -8,  1313,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,   216,   113,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,   139,   139,   -28,   -11,
    -111,   -21,   -32,    -8,   -18,    20,    31,    33,    43,    51,
      65,    -8,    -8,    67,    77,    79,    -8,  1313,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  1313,    -2,
    1313,     7,  1313,     9,  1313,  2223,    11,  -111,   243,    13,
    -111,   216,  -111,    15,  2480,    17,  -111,  2580,    22,  2642,
      23,  2703,    25,  2947,    26,  2974,  2991,  3018,  3035,  3062,
    2759,    27,  2803,    28,  2845,    29,  2867,    30,  2903,    32,
    3093,    34,  3122,  2930,    36,  3149,    38,   -63,   -60,  -111,
      40,  -111,    42,  2119,    44,  1853,    46,  1698,    48,  1610,
      50,  1568,    52,  1507,    54,  1463,    55,  1429,    56,   584,
      57,   498,    58,   309,    59,  1162,    -8,  1162,    -8,  1162,
      -8,  1162,  -111,  1633,  -111,   257,    -8,  -111,    -8,    80,
     257,    -8,  -111,  -111,    -7,    -1,    81,    -9,  1162,    87,
    -111,    95,    60,    85,    75,    97,    83,   106,    49,   105,
      61,    62,    63,   102,   104,    66,  1717,  1162,  1876,  1162,
    2023,  1162,   859,  -111,  -111,  -111,  2240,   257,  2363,   257,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,    92,   107,    41,   114,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  1313,    68,  1313,
      70,  1313,    71,  1313,  -111,   216,    72,  2502,    73,  -111,
     243,    74,   139,   139,   139,   139,   139,  -111,    94,  -111,
    -111,    89,  1313,  -111,  -111,   111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,   130,   -76,  -111,  -111,  -111,   133,  -111,
    1313,  -111,  1313,  -111,  1313,  -111,  2202,  -111,   243,  -111,
     216,  2536,  2616,  2676,  2737,  3166,  3210,  3227,  3271,  3193,
    3293,  3327,  3354,  3383,   139,  -111,  -111,  -111,  2140,  1909,
    1742,  1654,  1591,  1530,  1490,  1446,   613,   542,   374,  1759,
    1162,  1934,  1162,  2046,  1162,  1010,  2397,   257,  -111,  -111,
    2302,   257,     8,   -16,   -16,    90,    90,  1162,   139,  1162,
    -111,  1675,   167,   157,  -111,   159,   158,  1815,  1967,  2079,
    -111,  2319,  2424,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,     4,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  1313,
    -111,  1313,  -111,  1313,  -111,  -111,   216,  2558,  -111,   243,
     860,     8,  1011,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  1836,  1990,  2102,  2458,  -111,  2336,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,    88,     0,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,   -14,
     -13,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,   -12,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,   484,    24,  -111,
    -110,  -111,  -111,  -111,  -111,  -111,  -111
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -99
static const yytype_int16 yytable[] =
{
     155,   158,   161,   162,   166,   247,   164,   245,   118,   167,
     120,   169,   250,   171,   247,   173,   454,   175,   176,   177,
     178,   179,   180,   247,   182,   247,   184,   247,   186,   247,
     188,   247,   190,   247,   192,   193,   455,   195,   247,   247,
     197,   247,   247,   247,   247,   247,   247,   203,   247,   205,
     247,   207,   247,   209,   247,   211,   247,   213,   247,   215,
     247,   217,   247,   219,   247,   221,   247,   223,   247,   233,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   199,
     251,   232,   247,   201,   247,   246,   247,   247,   247,   247,
     247,   249,   137,   148,   253,   150,   321,   152,   322,   154,
     365,   366,     1,     2,   371,   234,   362,   363,   364,   365,
     366,   359,   362,   363,   364,   365,   366,   362,   363,   364,
     365,   366,   363,   364,   365,   366,   157,    16,    17,   373,
      18,    19,   254,    20,   240,   241,   266,   232,   268,   374,
     270,   381,   272,   255,   368,   256,   276,   248,   232,   278,
     232,   367,   232,   368,   232,   257,   267,   369,   377,   368,
     385,   234,   416,   258,   368,   269,   376,   271,   368,   275,
     379,   277,   234,   279,   234,   281,   234,   259,   234,   262,
     284,   287,   378,   290,   292,   300,   303,   306,   309,   263,
     312,   264,   314,   370,   318,   380,   320,   382,   323,   386,
     324,   450,   326,   387,   328,   414,   330,   448,   332,   415,
     334,   504,   336,   338,   340,   342,   344,   346,   375,   383,
     384,   355,   162,   452,   388,   357,   430,   360,   432,   434,
     437,   439,   441,    16,    17,   160,    18,    19,   417,    20,
     235,   236,   453,   237,   238,   456,   239,   242,   243,   505,
     368,   506,   442,   443,   444,   445,   446,   507,     0,     0,
       0,     0,     0,   396,   398,   400,   162,   -98,   -98,   401,
     -98,   -98,   402,   -98,     0,   403,     0,     0,   404,     0,
     405,    16,    17,     0,    18,    19,     0,    20,   406,     0,
       0,   407,     0,     0,   408,     0,     0,   409,     0,     0,
     410,     0,   411,     0,   476,     0,   412,     0,   413,     0,
       0,     0,     0,   347,   418,   349,   419,   351,   420,   353,
     421,     0,   422,     0,   423,     0,   424,     0,   425,     0,
     426,     0,   427,     0,   428,   429,   372,   431,   501,   433,
       0,   435,     0,   436,     0,     0,     0,   232,   440,   232,
     121,   232,   122,   232,   123,   390,     0,   392,     0,   394,
     451,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,   232,   234,     0,   234,     0,   234,   457,     0,
     458,     0,   459,     0,     0,     0,   461,     0,   462,   124,
     232,   125,   232,   126,   232,   127,   234,   128,     0,   129,
     130,     0,   131,   132,   133,   134,     0,   135,     0,   136,
       0,     0,     0,     0,   234,   121,   234,   122,   234,   123,
       0,     0,     0,   496,   162,     0,     0,   497,   499,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,     0,   125,     0,   126,     0,
     127,     0,   128,     0,   129,   130,   345,   131,   132,   133,
     134,     0,   135,     0,   136,     0,     0,   513,     0,   514,
       0,   515,     0,     0,   516,     0,     0,   518,     0,   232,
     149,   232,   151,   232,   153,     0,     0,   156,     0,   159,
     232,   163,   232,   165,     0,     0,   168,     0,   170,     0,
     172,     0,   174,   234,     0,   234,     0,   234,   489,   181,
     491,   183,   493,   185,   234,   187,   234,   189,     0,   191,
       0,   487,   194,     0,   196,   500,     0,   502,     0,   121,
     200,   122,   202,   123,   204,     0,   206,     0,   208,     0,
     210,     0,   212,     0,   214,     0,   216,     0,   218,     0,
     220,     0,   222,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,     0,
     125,     0,   126,   121,   127,   122,   128,   123,   129,   130,
       0,   131,   132,   133,   134,     0,   135,     0,   136,     0,
       0,     0,     0,     0,     0,     0,     0,   252,     0,     0,
       0,     0,     0,     0,     0,   260,   261,     0,     0,     0,
     265,     0,   124,     0,   125,   121,   126,   122,   127,   123,
     128,     0,   129,   130,     0,   131,   132,   133,   134,     0,
     135,     0,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   343,     0,   121,     0,   122,     0,   123,     0,
       0,     0,     0,     0,   124,     0,   125,     0,   126,     0,
     127,     0,   128,     0,   129,   130,     0,   131,   132,   133,
     134,     0,   135,     0,   136,     0,     0,     0,     0,     0,
       0,     0,     0,   124,     0,   125,   486,   126,     0,   127,
       0,   128,     0,   129,   130,     0,   131,   132,   133,   134,
     348,   135,   350,   136,   352,     5,     6,     0,     7,     8,
     356,     9,   358,    10,    11,   361,     0,    12,     0,    13,
      14,    15,     0,    16,    17,   341,    18,    19,     0,    20,
       0,    21,    22,     0,    23,    24,     0,    25,    26,     0,
     121,     0,   122,     0,   123,    27,    28,     0,    29,    30,
      31,    32,    33,    34,   485,    35,    36,     0,    37,    38,
       0,    39,    40,    41,     0,    42,     0,    43,    44,    45,
       0,    46,     0,    47,    48,     0,    49,    50,     0,   124,
       0,   125,     0,   126,     0,   127,     0,   128,     0,   129,
     130,     0,   131,   132,   133,   134,     0,   135,     0,   136,
      51,     0,    52,     0,    53,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    56,
       0,    57,    58,     0,    59,    60,     0,    61,    62,     0,
      63,    64,     0,    65,    66,     0,    67,    68,     0,    69,
      70,     0,    71,    72,     0,    73,    74,     0,    75,    76,
       0,    77,    78,     0,    79,    80,   225,   226,     0,   227,
     228,     0,   229,     0,   230,   231,   395,     0,    12,     0,
      13,    14,    15,     0,    16,    17,     0,    18,    19,     0,
      20,     0,    21,    22,     0,    23,    24,     0,    25,    26,
     121,     0,   122,     0,   123,     0,    27,    28,     0,    29,
      30,    31,    32,    33,    34,     0,    35,    36,     0,    37,
      38,     0,    39,    40,    41,     0,    42,     0,    43,    44,
      45,     0,    46,     0,    47,    48,     0,    49,    50,   124,
       0,   125,     0,   126,     0,   127,     0,   128,     0,   129,
     130,     0,   131,   132,   133,   134,     0,   135,     0,   136,
       0,    51,     0,    52,   519,    53,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      56,     0,    57,    58,     0,    59,    60,     0,    61,    62,
       0,    63,    64,     0,    65,    66,     0,    67,    68,     0,
      69,    70,     0,    71,    72,     0,    73,    74,     0,    75,
      76,     0,    77,    78,     0,    79,    80,   225,   226,     0,
     227,   228,     0,   229,     0,   230,   231,   494,     0,    12,
       0,    13,    14,    15,     0,    16,    17,     0,    18,    19,
       0,    20,     0,    21,    22,     0,    23,    24,     0,    25,
      26,   121,     0,   122,     0,   123,     0,    27,    28,     0,
      29,    30,    31,    32,    33,    34,     0,    35,    36,     0,
      37,    38,     0,    39,    40,    41,     0,    42,     0,    43,
      44,    45,     0,    46,     0,    47,    48,     0,    49,    50,
     124,     0,   125,     0,   126,     0,   127,     0,   128,     0,
     129,   130,     0,   131,   132,   133,   134,     0,   135,     0,
     136,     0,    51,     0,    52,     0,    53,   521,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    56,     0,    57,    58,     0,    59,    60,     0,    61,
      62,     0,    63,    64,     0,    65,    66,     0,    67,    68,
       0,    69,    70,     0,    71,    72,     0,    73,    74,     0,
      75,    76,     0,    77,    78,     0,    79,    80,     5,     6,
       0,     7,     8,     0,     9,     0,    10,    11,     0,     0,
      12,     0,    13,    14,    15,     0,    16,    17,     0,    18,
      19,     0,    20,     0,    21,    22,     0,    23,    24,     0,
      25,    26,     0,     0,     0,     0,     0,     0,    27,    28,
       0,    29,    30,    31,    32,    33,    34,     0,    35,    36,
       0,    37,    38,     0,    39,    40,    41,     0,    42,     0,
      43,    44,    45,     0,    46,     0,    47,    48,     0,    49,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,     0,    52,     0,    53,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    56,     0,    57,    58,     0,    59,    60,     0,
      61,    62,     0,    63,    64,     0,    65,    66,     0,    67,
      68,     0,    69,    70,     0,    71,    72,     0,    73,    74,
       0,    75,    76,     0,    77,    78,     0,    79,    80,   225,
     226,     0,   227,   228,     0,   229,     0,   230,   231,     0,
       0,    12,     0,    13,    14,    15,     0,    16,    17,     0,
      18,    19,     0,    20,     0,    21,    22,     0,    23,    24,
       0,    25,    26,     0,     0,     0,     0,     0,     0,    27,
      28,     0,    29,    30,    31,    32,    33,    34,     0,    35,
      36,     0,    37,    38,     0,    39,    40,    41,     0,    42,
       0,    43,    44,    45,     0,    46,     0,    47,    48,     0,
      49,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,    52,     0,    53,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    56,     0,    57,    58,     0,    59,    60,
       0,    61,    62,     0,    63,    64,     0,    65,    66,     0,
      67,    68,     0,    69,    70,     0,    71,    72,     0,    73,
      74,     0,    75,    76,     0,    77,    78,     0,    79,    80,
     121,     0,   122,     0,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,   122,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,   122,     0,   123,   124,
       0,   125,     0,   126,     0,   127,     0,   128,     0,   129,
     130,     0,   131,   132,   133,   134,   124,   135,   125,   136,
     126,   121,   127,   122,   128,   123,   129,   130,     0,   131,
     132,   133,   134,   124,   135,   125,   136,   126,   121,   127,
     122,   128,   123,   129,   130,     0,   131,   132,   133,   134,
       0,   135,     0,   136,     0,     0,     0,     0,     0,     0,
     124,   121,   125,   122,   126,   123,   127,   339,   128,     0,
     129,   130,     0,   131,   132,   133,   134,   124,   135,   125,
     136,   126,     0,   127,   484,   128,     0,   129,   130,     0,
     131,   132,   133,   134,     0,   135,     0,   136,   337,   121,
     124,   122,   125,   123,   126,     0,   127,     0,   128,     0,
     129,   130,     0,   131,   132,   133,   134,     0,   135,     0,
     136,     0,   121,     0,   122,   483,   123,     0,   354,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,   335,
     125,   121,   126,   122,   127,   123,   128,     0,   129,   130,
       0,   131,   132,   133,   134,     0,   135,     0,   136,     0,
       0,   124,   482,   125,   121,   126,   122,   127,   123,   128,
     503,   129,   130,     0,   131,   132,   133,   134,     0,   135,
     124,   136,   125,     0,   126,   121,   127,   122,   128,   123,
     129,   130,     0,   131,   132,   133,   134,   333,   135,     0,
     136,     0,     0,   124,     0,   125,   121,   126,   122,   127,
     123,   128,     0,   129,   130,   389,   131,   132,   133,   134,
     481,   135,     0,   136,   124,     0,   125,     0,   126,   121,
     127,   122,   128,   123,   129,   130,   331,   131,   132,   133,
     134,     0,   135,     0,   136,   124,     0,   125,   121,   126,
     122,   127,   123,   128,     0,   129,   130,   488,   131,   132,
     133,   134,     0,   135,     0,   136,     0,     0,   124,     0,
     125,     0,   126,   121,   127,   122,   128,   123,   129,   130,
     480,   131,   132,   133,   134,     0,   135,   124,   136,   125,
     121,   126,   122,   127,   123,   128,     0,   129,   130,     0,
     131,   132,   133,   134,     0,   135,     0,   136,     0,     0,
       0,     0,   124,   508,   125,     0,   126,     0,   127,     0,
     128,   329,   129,   130,     0,   131,   132,   133,   134,   124,
     135,   125,   136,   126,   523,   127,     0,   128,     0,   129,
     130,     0,   131,   132,   133,   134,   121,   135,   122,   136,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   479,     0,   121,     0,   122,
       0,   123,     0,     0,     0,     0,     0,   391,     0,     0,
       0,     0,     0,     0,   121,   124,   122,   125,   123,   126,
       0,   127,     0,   128,     0,   129,   130,     0,   131,   132,
     133,   134,     0,   135,     0,   136,   124,   121,   125,   122,
     126,   123,   127,     0,   128,     0,   129,   130,     0,   131,
     132,   133,   134,   124,   135,   125,   136,   126,     0,   127,
       0,   128,     0,   129,   130,   490,   131,   132,   133,   134,
     121,   135,   122,   136,   123,     0,   124,     0,   125,     0,
     126,     0,   127,     0,   128,     0,   129,   130,     0,   131,
     132,   133,   134,     0,   135,   121,   136,   122,   509,   123,
       0,     0,     0,   327,     0,     0,     0,     0,     0,   124,
       0,   125,     0,   126,     0,   127,     0,   128,     0,   129,
     130,   524,   131,   132,   133,   134,     0,   135,   121,   136,
     122,     0,   123,     0,   124,     0,   125,     0,   126,     0,
     127,     0,   128,     0,   129,   130,     0,   131,   132,   133,
     134,   121,   135,   122,   136,   123,   393,     0,     0,   478,
       0,     0,     0,     0,     0,     0,     0,   124,     0,   125,
       0,   126,     0,   127,     0,   128,     0,   129,   130,   492,
     131,   132,   133,   134,   121,   135,   122,   136,   123,     0,
     124,     0,   125,     0,   126,     0,   127,     0,   128,     0,
     129,   130,     0,   131,   132,   133,   134,   121,   135,   122,
     136,   123,   510,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,     0,   125,     0,   126,     0,   127,
       0,   128,     0,   129,   130,   525,   131,   132,   133,   134,
     121,   135,   122,   136,   123,     0,   124,     0,   125,     0,
     126,     0,   127,     0,   128,     0,   129,   130,     0,   131,
     132,   133,   134,   121,   135,   122,   136,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
     121,   125,   122,   126,   123,   127,     0,   128,     0,   129,
     130,     0,   131,   132,   133,   134,     0,   135,     0,   136,
       0,   121,   124,   122,   125,   123,   126,     0,   127,     0,
     128,     0,   129,   130,     0,   131,   132,   133,   134,   124,
     135,   125,   136,   126,     0,   127,     0,   128,     0,   129,
     130,     0,   131,   132,   133,   134,     0,   135,     0,   136,
     124,   460,   125,     0,   126,     0,   127,     0,   128,     0,
     129,   130,     0,   131,   132,   133,   134,     0,   135,     0,
     136,   273,   274,   121,     0,   122,   325,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   397,   121,     0,   122,   477,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,   124,   122,   125,   123,   126,     0,   127,     0,
     128,     0,   129,   130,     0,   131,   132,   133,   134,     0,
     135,     0,   136,   124,     0,   125,     0,   126,     0,   127,
       0,   128,     0,   129,   130,     0,   131,   132,   133,   134,
     124,   135,   125,   136,   126,   498,   127,     0,   128,     0,
     129,   130,     0,   131,   132,   133,   134,     0,   135,     0,
     136,     0,   511,   121,     0,   122,     0,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   527,
     121,     0,   122,     0,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,   122,
       0,   123,   124,     0,   125,     0,   126,     0,   127,   399,
     128,     0,   129,   130,     0,   131,   132,   133,   134,   124,
     135,   125,   136,   126,   121,   127,   122,   128,   123,   129,
     130,     0,   131,   132,   133,   134,   124,   135,   125,   136,
     126,     0,   127,   495,   128,     0,   129,   130,     0,   131,
     132,   133,   134,     0,   135,     0,   136,     0,   121,     0,
     122,     0,   123,   124,     0,   125,     0,   126,     0,   127,
     512,   128,     0,   129,   130,     0,   131,   132,   133,   134,
       0,   135,     0,   136,     0,   121,     0,   122,     0,   123,
       0,     0,     0,     0,     0,     0,     0,   124,     0,   125,
       0,   126,     0,   127,   526,   128,     0,   129,   130,     0,
     131,   132,   133,   134,     0,   135,     0,   136,     0,   121,
       0,   122,     0,   123,   124,     0,   125,     0,   126,   280,
     127,     0,   128,     0,   129,   130,     0,   131,   132,   133,
     134,   121,   135,   122,   136,   123,     0,     0,     0,     0,
       0,   438,     0,     0,     0,     0,     0,     0,   124,     0,
     125,     0,   126,   121,   127,   122,   128,   123,   129,   130,
       0,   131,   132,   133,   134,     0,   135,     0,   136,     0,
     124,     0,   125,     0,   126,   463,   127,     0,   128,     0,
     129,   130,     0,   131,   132,   133,   134,   121,   135,   122,
     136,   123,   124,     0,   125,     0,   126,   517,   127,     0,
     128,     0,   129,   130,     0,   131,   132,   133,   134,   121,
     135,   122,   136,   123,     0,     0,     0,     0,     0,     0,
       0,     0,   282,     0,   283,     0,   124,     0,   125,     0,
     126,   121,   127,   122,   128,   123,   129,   130,     0,   131,
     132,   133,   134,     0,   135,     0,   136,     0,   124,     0,
     125,     0,   126,     0,   127,     0,   128,     0,   129,   130,
     464,   131,   132,   133,   134,     0,   135,   121,   136,   122,
     124,   123,   125,     0,   126,     0,   127,     0,   128,     0,
     129,   130,     0,   131,   132,   133,   134,   285,   135,   286,
     136,     0,     0,   121,     0,   122,     0,   123,     0,     0,
       0,     0,     0,     0,     0,     0,   124,     0,   125,     0,
     126,     0,   127,     0,   128,     0,   129,   130,     0,   131,
     132,   133,   134,   465,   135,     0,   136,   121,     0,   122,
       0,   123,   124,     0,   125,     0,   126,     0,   127,     0,
     128,     0,   129,   130,     0,   131,   132,   133,   134,     0,
     135,   288,   136,   289,   121,     0,   122,     0,   123,     0,
       0,     0,     0,     0,     0,     0,   124,     0,   125,     0,
     126,     0,   127,     0,   128,     0,   129,   130,     0,   131,
     132,   133,   134,     0,   135,     0,   136,   466,   121,     0,
     122,     0,   123,   124,     0,   125,     0,   126,     0,   127,
       0,   128,     0,   129,   130,     0,   131,   132,   133,   134,
     121,   135,   122,   136,   123,     0,     0,     0,     0,     0,
       0,     0,     0,   298,   299,     0,     0,   124,     0,   125,
       0,   126,     0,   127,     0,   128,     0,   129,   130,     0,
     131,   132,   133,   134,     0,   135,     0,   136,     0,   124,
       0,   125,     0,   126,   121,   127,   122,   128,   123,   129,
     130,     0,   131,   132,   133,   134,     0,   135,     0,   136,
     301,   302,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,     0,   125,   121,   126,   122,   127,
     123,   128,     0,   129,   130,     0,   131,   132,   133,   134,
       0,   135,     0,   136,     0,   304,   305,     0,   121,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,     0,   125,     0,   126,
     307,   127,   308,   128,     0,   129,   130,     0,   131,   132,
     133,   134,     0,   135,   121,   136,   122,   124,   123,   125,
       0,   126,     0,   127,     0,   128,     0,   129,   130,     0,
     131,   132,   133,   134,     0,   135,     0,   136,     0,   310,
     311,   121,     0,   122,     0,   123,     0,     0,     0,     0,
       0,     0,     0,   124,     0,   125,     0,   126,   121,   127,
     122,   128,   123,   129,   130,   291,   131,   132,   133,   134,
       0,   135,     0,   136,   316,     0,   317,     0,     0,     0,
     124,     0,   125,     0,   126,   121,   127,   122,   128,   123,
     129,   130,   293,   131,   132,   133,   134,   124,   135,   125,
     136,   126,   121,   127,   122,   128,   123,   129,   130,   294,
     131,   132,   133,   134,     0,   135,     0,   136,     0,     0,
       0,     0,     0,     0,   124,     0,   125,     0,   126,   121,
     127,   122,   128,   123,   129,   130,   295,   131,   132,   133,
     134,   124,   135,   125,   136,   126,   121,   127,   122,   128,
     123,   129,   130,   296,   131,   132,   133,   134,     0,   135,
       0,   136,     0,     0,     0,     0,     0,     0,   124,     0,
     125,     0,   126,   121,   127,   122,   128,   123,   129,   130,
     297,   131,   132,   133,   134,   124,   135,   125,   136,   126,
       0,   127,     0,   128,     0,   129,   130,     0,   131,   132,
     133,   134,     0,   135,   121,   136,   122,     0,   123,     0,
       0,     0,   124,     0,   125,     0,   126,     0,   127,     0,
     128,     0,   129,   130,     0,   131,   132,   133,   134,     0,
     135,     0,   136,   121,   313,   122,     0,   123,     0,     0,
       0,     0,     0,   124,     0,   125,     0,   126,     0,   127,
       0,   128,     0,   129,   130,     0,   131,   132,   133,   134,
     121,   135,   122,   136,   123,   315,     0,     0,     0,     0,
       0,     0,   124,     0,   125,     0,   126,   121,   127,   122,
     128,   123,   129,   130,   467,   131,   132,   133,   134,     0,
     135,     0,   136,     0,     0,     0,     0,     0,   319,   124,
       0,   125,     0,   126,   121,   127,   122,   128,   123,   129,
     130,     0,   131,   132,   133,   134,   124,   135,   125,   136,
     126,   121,   127,   122,   128,   123,   129,   130,   471,   131,
     132,   133,   134,     0,   135,   468,   136,     0,   121,     0,
     122,     0,   123,   124,     0,   125,     0,   126,     0,   127,
       0,   128,     0,   129,   130,   469,   131,   132,   133,   134,
     124,   135,   125,   136,   126,     0,   127,     0,   128,     0,
     129,   130,     0,   131,   132,   133,   134,   124,   135,   125,
     136,   126,   121,   127,   122,   128,   123,   129,   130,     0,
     131,   132,   133,   134,     0,   135,     0,   136,     0,     0,
       0,     0,   470,     0,   121,     0,   122,     0,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,     0,   125,     0,   126,     0,   127,     0,   128,
     472,   129,   130,     0,   131,   132,   133,   134,   121,   135,
     122,   136,   123,   124,     0,   125,     0,   126,     0,   127,
       0,   128,     0,   129,   130,     0,   131,   132,   133,   134,
       0,   135,     0,   136,     0,   121,     0,   122,   473,   123,
       0,     0,     0,     0,     0,     0,     0,   124,     0,   125,
       0,   126,     0,   127,     0,   128,     0,   129,   130,     0,
     131,   132,   133,   134,   121,   135,   122,   136,   123,     0,
     474,     0,     0,     0,   124,     0,   125,     0,   126,     0,
     127,     0,   128,     0,   129,   130,     0,   131,   132,   133,
     134,     0,   135,     0,   136,     0,     0,     0,     0,     0,
       0,     0,   475,   124,     0,   125,     0,   126,     0,   127,
       0,   128,     0,   129,   130,     0,   131,   132,   133,   134,
       0,   135,     0,   136
};

static const yytype_int16 yycheck[] =
{
      12,    14,    16,    16,    31,    16,    18,   117,    16,    21,
       0,    23,    44,    25,    16,    27,    92,    29,    30,    31,
      32,    33,    34,    16,    36,    16,    38,    16,    40,    16,
      42,    16,    44,    16,    46,    47,   112,    49,    16,    16,
     108,    16,    16,    16,    16,    16,    16,    59,    16,    61,
      16,    63,    16,    65,    16,    67,    16,    69,    16,    71,
      16,    73,    16,    75,    16,    77,    16,    79,    16,    81,
      16,    16,    16,    16,    16,    16,    16,    16,    16,   121,
     112,    81,    16,   124,    16,   113,    16,    16,    16,    16,
      16,   112,     4,     5,   112,     7,   159,     9,   158,    11,
     116,   117,     3,     4,   113,    81,   113,   114,   115,   116,
     117,    31,   113,   114,   115,   116,   117,   113,   114,   115,
     116,   117,   114,   115,   116,   117,    23,    24,    25,    42,
      27,    28,   112,    30,    21,    22,   148,   137,   150,    44,
     152,    92,   154,   112,   160,   112,   158,   158,   148,   161,
     150,   158,   152,   160,   154,   112,   158,   158,    83,   160,
      97,   137,   121,   112,   160,   158,    81,   158,   160,   158,
      87,   158,   148,   158,   150,   158,   152,   112,   154,   112,
     158,   158,    85,   158,   158,   158,   158,   158,   158,   112,
     158,   112,   158,   112,   158,    89,   158,    92,   158,    97,
     158,   112,   158,    99,   158,   113,   158,   113,   158,   102,
     158,    44,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   235,   235,   112,   158,   237,   158,   240,   158,   158,
     158,   158,   158,    24,    25,    26,    27,    28,   124,    30,
      24,    25,   112,    27,    28,   112,    30,   108,   109,    92,
     160,    92,   362,   363,   364,   365,   366,    99,    -1,    -1,
      -1,    -1,    -1,   275,   277,   279,   279,    24,    25,   281,
      27,    28,   284,    30,    -1,   287,    -1,    -1,   290,    -1,
     292,    24,    25,    -1,    27,    28,    -1,    30,   300,    -1,
      -1,   303,    -1,    -1,   306,    -1,    -1,   309,    -1,    -1,
     312,    -1,   314,    -1,   414,    -1,   318,    -1,   320,    -1,
      -1,    -1,    -1,   225,   326,   227,   328,   229,   330,   231,
     332,    -1,   334,    -1,   336,    -1,   338,    -1,   340,    -1,
     342,    -1,   344,    -1,   346,   347,   248,   349,   448,   351,
      -1,   353,    -1,   355,    -1,    -1,    -1,   347,   360,   349,
      41,   351,    43,   353,    45,   267,    -1,   269,    -1,   271,
     372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   347,   372,   349,    -1,   351,    -1,   353,   390,    -1,
     392,    -1,   394,    -1,    -1,    -1,   398,    -1,   400,    80,
     390,    82,   392,    84,   394,    86,   372,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    -1,    98,    -1,   100,
      -1,    -1,    -1,    -1,   390,    41,   392,    43,   394,    45,
      -1,    -1,    -1,   437,   437,    -1,    -1,   439,   441,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    84,    -1,
      86,    -1,    88,    -1,    90,    91,   157,    93,    94,    95,
      96,    -1,    98,    -1,   100,    -1,    -1,   489,    -1,   491,
      -1,   493,    -1,    -1,   496,    -1,    -1,   499,    -1,   489,
       6,   491,     8,   493,    10,    -1,    -1,    13,    -1,    15,
     500,    17,   502,    19,    -1,    -1,    22,    -1,    24,    -1,
      26,    -1,    28,   489,    -1,   491,    -1,   493,   430,    35,
     432,    37,   434,    39,   500,    41,   502,    43,    -1,    45,
      -1,   157,    48,    -1,    50,   447,    -1,   449,    -1,    41,
      56,    43,    58,    45,    60,    -1,    62,    -1,    64,    -1,
      66,    -1,    68,    -1,    70,    -1,    72,    -1,    74,    -1,
      76,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    84,    41,    86,    43,    88,    45,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    -1,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,    -1,    -1,    -1,
     136,    -1,    80,    -1,    82,    41,    84,    43,    86,    45,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   154,    -1,    41,    -1,    43,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    84,    -1,
      86,    -1,    88,    -1,    90,    91,    -1,    93,    94,    95,
      96,    -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,   154,    84,    -1,    86,
      -1,    88,    -1,    90,    91,    -1,    93,    94,    95,    96,
     226,    98,   228,   100,   230,     6,     7,    -1,     9,    10,
     236,    12,   238,    14,    15,   241,    -1,    18,    -1,    20,
      21,    22,    -1,    24,    25,   151,    27,    28,    -1,    30,
      -1,    32,    33,    -1,    35,    36,    -1,    38,    39,    -1,
      41,    -1,    43,    -1,    45,    46,    47,    -1,    49,    50,
      51,    52,    53,    54,   151,    56,    57,    -1,    59,    60,
      -1,    62,    63,    64,    -1,    66,    -1,    68,    69,    70,
      -1,    72,    -1,    74,    75,    -1,    77,    78,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    -1,    98,    -1,   100,
     101,    -1,   103,    -1,   105,    -1,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,
      -1,   122,   123,    -1,   125,   126,    -1,   128,   129,    -1,
     131,   132,    -1,   134,   135,    -1,   137,   138,    -1,   140,
     141,    -1,   143,   144,    -1,   146,   147,    -1,   149,   150,
      -1,   152,   153,    -1,   155,   156,     6,     7,    -1,     9,
      10,    -1,    12,    -1,    14,    15,    17,    -1,    18,    -1,
      20,    21,    22,    -1,    24,    25,    -1,    27,    28,    -1,
      30,    -1,    32,    33,    -1,    35,    36,    -1,    38,    39,
      41,    -1,    43,    -1,    45,    -1,    46,    47,    -1,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    -1,    59,
      60,    -1,    62,    63,    64,    -1,    66,    -1,    68,    69,
      70,    -1,    72,    -1,    74,    75,    -1,    77,    78,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    -1,    98,    -1,   100,
      -1,   101,    -1,   103,   104,   105,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,    -1,   122,   123,    -1,   125,   126,    -1,   128,   129,
      -1,   131,   132,    -1,   134,   135,    -1,   137,   138,    -1,
     140,   141,    -1,   143,   144,    -1,   146,   147,    -1,   149,
     150,    -1,   152,   153,    -1,   155,   156,     6,     7,    -1,
       9,    10,    -1,    12,    -1,    14,    15,    17,    -1,    18,
      -1,    20,    21,    22,    -1,    24,    25,    -1,    27,    28,
      -1,    30,    -1,    32,    33,    -1,    35,    36,    -1,    38,
      39,    41,    -1,    43,    -1,    45,    -1,    46,    47,    -1,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    -1,
      59,    60,    -1,    62,    63,    64,    -1,    66,    -1,    68,
      69,    70,    -1,    72,    -1,    74,    75,    -1,    77,    78,
      80,    -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    -1,    98,    -1,
     100,    -1,   101,    -1,   103,    -1,   105,   106,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,    -1,   122,   123,    -1,   125,   126,    -1,   128,
     129,    -1,   131,   132,    -1,   134,   135,    -1,   137,   138,
      -1,   140,   141,    -1,   143,   144,    -1,   146,   147,    -1,
     149,   150,    -1,   152,   153,    -1,   155,   156,     6,     7,
      -1,     9,    10,    -1,    12,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    22,    -1,    24,    25,    -1,    27,
      28,    -1,    30,    -1,    32,    33,    -1,    35,    36,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      -1,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      -1,    59,    60,    -1,    62,    63,    64,    -1,    66,    -1,
      68,    69,    70,    -1,    72,    -1,    74,    75,    -1,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,   103,    -1,   105,    -1,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,   120,    -1,   122,   123,    -1,   125,   126,    -1,
     128,   129,    -1,   131,   132,    -1,   134,   135,    -1,   137,
     138,    -1,   140,   141,    -1,   143,   144,    -1,   146,   147,
      -1,   149,   150,    -1,   152,   153,    -1,   155,   156,     6,
       7,    -1,     9,    10,    -1,    12,    -1,    14,    15,    -1,
      -1,    18,    -1,    20,    21,    22,    -1,    24,    25,    -1,
      27,    28,    -1,    30,    -1,    32,    33,    -1,    35,    36,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    -1,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    -1,    59,    60,    -1,    62,    63,    64,    -1,    66,
      -1,    68,    69,    70,    -1,    72,    -1,    74,    75,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,   103,    -1,   105,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,   120,    -1,   122,   123,    -1,   125,   126,
      -1,   128,   129,    -1,   131,   132,    -1,   134,   135,    -1,
     137,   138,    -1,   140,   141,    -1,   143,   144,    -1,   146,
     147,    -1,   149,   150,    -1,   152,   153,    -1,   155,   156,
      41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    43,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    45,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    80,    98,    82,   100,
      84,    41,    86,    43,    88,    45,    90,    91,    -1,    93,
      94,    95,    96,    80,    98,    82,   100,    84,    41,    86,
      43,    88,    45,    90,    91,    -1,    93,    94,    95,    96,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    41,    82,    43,    84,    45,    86,   148,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    80,    98,    82,
     100,    84,    -1,    86,   148,    88,    -1,    90,    91,    -1,
      93,    94,    95,    96,    -1,    98,    -1,   100,   145,    41,
      80,    43,    82,    45,    84,    -1,    86,    -1,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    -1,    98,    -1,
     100,    -1,    41,    -1,    43,   145,    45,    -1,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,   142,
      82,    41,    84,    43,    86,    45,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    -1,   100,    -1,
      -1,    80,   142,    82,    41,    84,    43,    86,    45,    88,
       5,    90,    91,    -1,    93,    94,    95,    96,    -1,    98,
      80,   100,    82,    -1,    84,    41,    86,    43,    88,    45,
      90,    91,    -1,    93,    94,    95,    96,   139,    98,    -1,
     100,    -1,    -1,    80,    -1,    82,    41,    84,    43,    86,
      45,    88,    -1,    90,    91,     8,    93,    94,    95,    96,
     139,    98,    -1,   100,    80,    -1,    82,    -1,    84,    41,
      86,    43,    88,    45,    90,    91,   136,    93,    94,    95,
      96,    -1,    98,    -1,   100,    80,    -1,    82,    41,    84,
      43,    86,    45,    88,    -1,    90,    91,     8,    93,    94,
      95,    96,    -1,    98,    -1,   100,    -1,    -1,    80,    -1,
      82,    -1,    84,    41,    86,    43,    88,    45,    90,    91,
     136,    93,    94,    95,    96,    -1,    98,    80,   100,    82,
      41,    84,    43,    86,    45,    88,    -1,    90,    91,    -1,
      93,    94,    95,    96,    -1,    98,    -1,   100,    -1,    -1,
      -1,    -1,    80,     8,    82,    -1,    84,    -1,    86,    -1,
      88,   133,    90,    91,    -1,    93,    94,    95,    96,    80,
      98,    82,   100,    84,     8,    86,    -1,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    41,    98,    43,   100,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   133,    -1,    41,    -1,    43,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    80,    43,    82,    45,    84,
      -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,    94,
      95,    96,    -1,    98,    -1,   100,    80,    41,    82,    43,
      84,    45,    86,    -1,    88,    -1,    90,    91,    -1,    93,
      94,    95,    96,    80,    98,    82,   100,    84,    -1,    86,
      -1,    88,    -1,    90,    91,    11,    93,    94,    95,    96,
      41,    98,    43,   100,    45,    -1,    80,    -1,    82,    -1,
      84,    -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,
      94,    95,    96,    -1,    98,    41,   100,    43,    11,    45,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,
      91,    11,    93,    94,    95,    96,    -1,    98,    41,   100,
      43,    -1,    45,    -1,    80,    -1,    82,    -1,    84,    -1,
      86,    -1,    88,    -1,    90,    91,    -1,    93,    94,    95,
      96,    41,    98,    43,   100,    45,    13,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      -1,    84,    -1,    86,    -1,    88,    -1,    90,    91,    13,
      93,    94,    95,    96,    41,    98,    43,   100,    45,    -1,
      80,    -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    41,    98,    43,
     100,    45,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    90,    91,    13,    93,    94,    95,    96,
      41,    98,    43,   100,    45,    -1,    80,    -1,    82,    -1,
      84,    -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,
      94,    95,    96,    41,    98,    43,   100,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      41,    82,    43,    84,    45,    86,    -1,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    -1,    98,    -1,   100,
      -1,    41,    80,    43,    82,    45,    84,    -1,    86,    -1,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    80,
      98,    82,   100,    84,    -1,    86,    -1,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    -1,    98,    -1,   100,
      80,    19,    82,    -1,    84,    -1,    86,    -1,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    -1,    98,    -1,
     100,    18,    19,    41,    -1,    43,   127,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    41,    -1,    43,   127,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    80,    43,    82,    45,    84,    -1,    86,    -1,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    -1,   100,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    90,    91,    -1,    93,    94,    95,    96,
      80,    98,    82,   100,    84,    23,    86,    -1,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    -1,    98,    -1,
     100,    -1,    23,    41,    -1,    43,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    43,
      -1,    45,    80,    -1,    82,    -1,    84,    -1,    86,    26,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    80,
      98,    82,   100,    84,    41,    86,    43,    88,    45,    90,
      91,    -1,    93,    94,    95,    96,    80,    98,    82,   100,
      84,    -1,    86,    26,    88,    -1,    90,    91,    -1,    93,
      94,    95,    96,    -1,    98,    -1,   100,    -1,    41,    -1,
      43,    -1,    45,    80,    -1,    82,    -1,    84,    -1,    86,
      26,    88,    -1,    90,    91,    -1,    93,    94,    95,    96,
      -1,    98,    -1,   100,    -1,    41,    -1,    43,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      -1,    84,    -1,    86,    26,    88,    -1,    90,    91,    -1,
      93,    94,    95,    96,    -1,    98,    -1,   100,    -1,    41,
      -1,    43,    -1,    45,    80,    -1,    82,    -1,    84,    29,
      86,    -1,    88,    -1,    90,    91,    -1,    93,    94,    95,
      96,    41,    98,    43,   100,    45,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    84,    41,    86,    43,    88,    45,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    -1,   100,    -1,
      80,    -1,    82,    -1,    84,    29,    86,    -1,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    41,    98,    43,
     100,    45,    80,    -1,    82,    -1,    84,    29,    86,    -1,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    41,
      98,    43,   100,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    -1,    80,    -1,    82,    -1,
      84,    41,    86,    43,    88,    45,    90,    91,    -1,    93,
      94,    95,    96,    -1,    98,    -1,   100,    -1,    80,    -1,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,    91,
      34,    93,    94,    95,    96,    -1,    98,    41,   100,    43,
      80,    45,    82,    -1,    84,    -1,    86,    -1,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    35,    98,    37,
     100,    -1,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,
      84,    -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,
      94,    95,    96,    37,    98,    -1,   100,    41,    -1,    43,
      -1,    45,    80,    -1,    82,    -1,    84,    -1,    86,    -1,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    38,   100,    40,    41,    -1,    43,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,
      84,    -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,
      94,    95,    96,    -1,    98,    -1,   100,    40,    41,    -1,
      43,    -1,    45,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    90,    91,    -1,    93,    94,    95,    96,
      41,    98,    43,   100,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    -1,    -1,    80,    -1,    82,
      -1,    84,    -1,    86,    -1,    88,    -1,    90,    91,    -1,
      93,    94,    95,    96,    -1,    98,    -1,   100,    -1,    80,
      -1,    82,    -1,    84,    41,    86,    43,    88,    45,    90,
      91,    -1,    93,    94,    95,    96,    -1,    98,    -1,   100,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    41,    84,    43,    86,
      45,    88,    -1,    90,    91,    -1,    93,    94,    95,    96,
      -1,    98,    -1,   100,    -1,    60,    61,    -1,    41,    -1,
      43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    84,
      63,    86,    65,    88,    -1,    90,    91,    -1,    93,    94,
      95,    96,    -1,    98,    41,   100,    43,    80,    45,    82,
      -1,    84,    -1,    86,    -1,    88,    -1,    90,    91,    -1,
      93,    94,    95,    96,    -1,    98,    -1,   100,    -1,    66,
      67,    41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    84,    41,    86,
      43,    88,    45,    90,    91,    48,    93,    94,    95,    96,
      -1,    98,    -1,   100,    74,    -1,    76,    -1,    -1,    -1,
      80,    -1,    82,    -1,    84,    41,    86,    43,    88,    45,
      90,    91,    48,    93,    94,    95,    96,    80,    98,    82,
     100,    84,    41,    86,    43,    88,    45,    90,    91,    48,
      93,    94,    95,    96,    -1,    98,    -1,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    84,    41,
      86,    43,    88,    45,    90,    91,    48,    93,    94,    95,
      96,    80,    98,    82,   100,    84,    41,    86,    43,    88,
      45,    90,    91,    48,    93,    94,    95,    96,    -1,    98,
      -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    84,    41,    86,    43,    88,    45,    90,    91,
      48,    93,    94,    95,    96,    80,    98,    82,   100,    84,
      -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,    94,
      95,    96,    -1,    98,    41,   100,    43,    -1,    45,    -1,
      -1,    -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    -1,   100,    41,    71,    43,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    90,    91,    -1,    93,    94,    95,    96,
      41,    98,    43,   100,    45,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    -1,    84,    41,    86,    43,
      88,    45,    90,    91,    48,    93,    94,    95,    96,    -1,
      98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    79,    80,
      -1,    82,    -1,    84,    41,    86,    43,    88,    45,    90,
      91,    -1,    93,    94,    95,    96,    80,    98,    82,   100,
      84,    41,    86,    43,    88,    45,    90,    91,    65,    93,
      94,    95,    96,    -1,    98,    55,   100,    -1,    41,    -1,
      43,    -1,    45,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    90,    91,    58,    93,    94,    95,    96,
      80,    98,    82,   100,    84,    -1,    86,    -1,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    80,    98,    82,
     100,    84,    41,    86,    43,    88,    45,    90,    91,    -1,
      93,    94,    95,    96,    -1,    98,    -1,   100,    -1,    -1,
      -1,    -1,    61,    -1,    41,    -1,    43,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,    88,
      67,    90,    91,    -1,    93,    94,    95,    96,    41,    98,
      43,   100,    45,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    90,    91,    -1,    93,    94,    95,    96,
      -1,    98,    -1,   100,    -1,    41,    -1,    43,    71,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      -1,    84,    -1,    86,    -1,    88,    -1,    90,    91,    -1,
      93,    94,    95,    96,    41,    98,    43,   100,    45,    -1,
      76,    -1,    -1,    -1,    80,    -1,    82,    -1,    84,    -1,
      86,    -1,    88,    -1,    90,    91,    -1,    93,    94,    95,
      96,    -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    90,    91,    -1,    93,    94,    95,    96,
      -1,    98,    -1,   100
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,   162,   197,     6,     7,     9,    10,    12,
      14,    15,    18,    20,    21,    22,    24,    25,    27,    28,
      30,    32,    33,    35,    36,    38,    39,    46,    47,    49,
      50,    51,    52,    53,    54,    56,    57,    59,    60,    62,
      63,    64,    66,    68,    69,    70,    72,    74,    75,    77,
      78,   101,   103,   105,   107,   119,   120,   122,   123,   125,
     126,   128,   129,   131,   132,   134,   135,   137,   138,   140,
     141,   143,   144,   146,   147,   149,   150,   152,   153,   155,
     156,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   209,   212,   215,    16,   208,
       0,    41,    43,    45,    80,    82,    84,    86,    88,    90,
      91,    93,    94,    95,    96,    98,   100,   163,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   163,   208,
     163,   208,   163,   208,   163,   197,   208,    23,   181,   208,
      26,   180,   181,   208,   197,   208,    31,   197,   208,   197,
     208,   197,   208,   197,   208,   197,   197,   197,   197,   197,
     197,   208,   197,   208,   197,   208,   197,   208,   197,   208,
     197,   208,   197,   197,   208,   197,   208,   108,   210,   121,
     208,   124,   208,   197,   208,   197,   208,   197,   208,   197,
     208,   197,   208,   197,   208,   197,   208,   197,   208,   197,
     208,   197,   208,   197,   208,     6,     7,     9,    10,    12,
      14,    15,   164,   197,   209,    24,    25,    27,    28,    30,
      21,    22,   108,   109,   211,   211,   113,    16,   158,   112,
      44,   112,   208,   112,   112,   112,   112,   112,   112,   112,
     208,   208,   112,   112,   112,   208,   197,   158,   197,   158,
     197,   158,   197,    18,    19,   158,   197,   158,   197,   158,
      29,   158,    32,    34,   158,    35,    37,   158,    38,    40,
     158,    48,   158,    48,    48,    48,    48,    48,    54,    55,
     158,    57,    58,   158,    60,    61,   158,    63,    65,   158,
      66,    67,   158,    71,   158,    73,    74,    76,   158,    79,
     158,   159,   158,   158,   158,   127,   158,   130,   158,   133,
     158,   136,   158,   139,   158,   142,   158,   145,   158,   148,
     158,   151,   158,   154,   158,   157,   158,   163,   208,   163,
     208,   163,   208,   163,     5,   180,   208,   197,   208,    31,
     181,   208,   113,   114,   115,   116,   117,   158,   160,   158,
     112,   113,   163,    42,    44,   158,    81,    83,    85,    87,
      89,    92,    92,   158,   158,    97,    97,    99,   158,     8,
     163,    11,   163,    13,   163,    17,   197,    23,   181,    26,
     180,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   113,   102,   121,   124,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     158,   197,   158,   197,   158,   197,   197,   158,    29,   158,
     197,   158,   211,   211,   211,   211,   211,   213,   113,   217,
     112,   197,   112,   112,    92,   112,   112,   197,   197,   197,
      19,   197,   197,    29,    34,    37,    40,    48,    55,    58,
      61,    65,    67,    71,    76,    79,   211,   127,   130,   133,
     136,   139,   142,   145,   148,   151,   154,   157,     8,   163,
      11,   163,    13,   163,    17,    26,   180,   197,    23,   181,
     163,   211,   163,     5,    44,    92,    92,    99,     8,    11,
      13,    23,    26,   197,   197,   197,   197,    29,   197,   104,
     214,   106,   216,     8,    11,    13,    26,    23
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

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
# if YYLTYPE_IS_TRIVIAL
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

/* Line 1455 of yacc.c  */
#line 161 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 165 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 169 "gtkdialog_parser.y"
    { 
    		token_store_attr(PUSH | WIDGET_WINDOW, (yyvsp[(2) - (6)].nvval)); 
		start_up();
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 177 "gtkdialog_parser.y"
    { 
		token_store(SUM);      
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 182 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
	}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 185 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
		token_store(SUM);      
	}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 189 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(2) - (6)].nvval)); 
	}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 192 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(3) - (7)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 196 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
	}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 199 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
		token_store(SUM);      
	}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 203 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(2) - (6)].nvval)); 
	}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 206 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(3) - (7)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 210 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
	}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 213 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
		token_store(SUM);      
	}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 217 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 220 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);      
	}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 224 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(1) - (4)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
	}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 228 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(2) - (5)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
		token_store(SUM);      
	}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 267 "gtkdialog_parser.y"
    {
                          token_store(PUSH | WIDGET_ENTRY); 
			 }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 270 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_ENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 273 "gtkdialog_parser.y"
    {
                  yyerror("</entry> expected instead of <entry>.");}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 278 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_EDIT); 
	}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 281 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_EDIT, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 284 "gtkdialog_parser.y"
    {
    		yyerror("</edit> expected instead of <edit>.");
	}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 290 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TREE); 
	}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 293 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_TREE, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 296 "gtkdialog_parser.y"
    {
   		yyerror("</tree> expected instead of <tree>.");
	}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 302 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHOOSER); 
	}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 305 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_CHOOSER, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 308 "gtkdialog_parser.y"
    {
		yyerror("</chooser> expected instead of <chooser>.");
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 314 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TEXT); 
	}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 317 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_TEXT, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 320 "gtkdialog_parser.y"
    {yyerror("</text> expected instead of <text>.");}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 324 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_BUTTON);  }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 325 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_BUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 328 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_OKBUTTON);}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 329 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_CANCELBUTTON);}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 330 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_HELPBUTTON);}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 331 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_NOBUTTON);}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 332 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_YESBUTTON);}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 336 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHECKBOX);
	}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 339 "gtkdialog_parser.y"
    {
		//token_store_with_tag_attributes(PUSH | WIDGET_CHECKBOX, $2);
                token_store_attr(PUSH | WIDGET_CHECKBOX, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 343 "gtkdialog_parser.y"
    {
		yyerror("</checkbox> expected instead of <checkbox>.");
	}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 349 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_RADIOBUTTON);
           }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 352 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_RADIOBUTTON, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 355 "gtkdialog_parser.y"
    {
		yyerror("</radiobutton> expected instead of <radiobutton>.");
           }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 361 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_PROGRESS);
           }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 364 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_PROGRESS, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 367 "gtkdialog_parser.y"
    {
		yyerror("</progressbar> expected instead of <progressbar>.");
           }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 373 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_LIST); 
	}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 376 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_LIST, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 379 "gtkdialog_parser.y"
    {
    		yyerror("</list> expected instead of <list>.");
	}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 385 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TABLE); 
	}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 388 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TABLE, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 391 "gtkdialog_parser.y"
    {
    		yyerror("</table> expected instead of <table>.");
	}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 397 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_COMBO);
	}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 400 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_COMBO, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 406 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_GVIM);}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 410 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_PIXMAP);}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 411 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_PIXMAP, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 424 "gtkdialog_parser.y"
    {
		yyerror("The menubar widget requires at least one menu widget.");
	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 427 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUBAR);
	}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 430 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUBAR);
		token_store(SUM);
	}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 434 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUBAR, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 437 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUBAR, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);
	}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 450 "gtkdialog_parser.y"
    {
		yyerror("The menu widget requires at least one menuitem widget.");
	}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 453 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENU);
	}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 456 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENU);
		token_store(SUM);
	}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 460 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENU, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 463 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENU, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);
	}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 470 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM);
	}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 473 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM);
		token_store(SUM);
	}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 477 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 480 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(3) - (6)].nvval));
		token_store(SUM);
	}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 487 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEMSEPARATOR);
	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 490 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEMSEPARATOR);
		token_store(SUM);
	}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 497 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSEPARATOR);
	}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 500 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 506 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSEPARATOR);
	}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 509 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 515 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXTEXT);
	}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 518 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXTEXT, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 524 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXENTRY);
	}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 527 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 533 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSCALE);
	}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 536 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSCALE, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 542 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSCALE);
	}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 545 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSCALE, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 551 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_SPINBUTTON);
	}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 554 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_SPINBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 560 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TIMER);
	}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 563 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TIMER, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 569 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TOGGLEBUTTON);
	}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 572 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TOGGLEBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 578 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_STATUSBAR);
	}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 581 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_STATUSBAR, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 587 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COLORBUTTON);
	}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 590 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COLORBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 596 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_FONTBUTTON);
	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 599 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_FONTBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 605 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TERMINAL);
	}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 608 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TERMINAL, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 628 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_LABEL, (yyvsp[(2) - (3)].cval));     }
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 633 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_VARIABLE, (yyvsp[(2) - (3)].cval)); }
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 638 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_SENSITIVE, (yyvsp[(2) - (3)].cval));  }
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 643 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_DEFAULT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 648 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_WIDTH, (yyvsp[(2) - (3)].cval));    }
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 653 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_HEIGHT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 658 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_SHELL,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 661 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 664 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 667 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 670 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, "", (yyvsp[(2) - (4)].nvval)); 
	}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 676 "gtkdialog_parser.y"
    {
	         fprintf( stderr, "<output>: Not implemented.\n" ); 
	}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 679 "gtkdialog_parser.y"
    {
         	token_store_with_argument(SET|ATTR_OUTPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 685 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET|ATTR_ACTION, (yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 688 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET | ATTR_ACTION, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 695 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET | ATTR_ITEM, (yyvsp[(2) - (3)].cval));
	}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 698 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_ITEM, "");
    	}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 701 "gtkdialog_parser.y"
    {
		      token_store_with_argument_attr(SET | ATTR_ITEM, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
                    }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 707 "gtkdialog_parser.y"
    {
       		(yyval.nvval) = new_tag_attributeset((yyvsp[(1) - (3)].cval), (yyvsp[(3) - (3)].cval)); 
	}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 710 "gtkdialog_parser.y"
    { 
       		(yyval.nvval) = add_tag_attribute((yyvsp[(1) - (4)].nvval), (yyvsp[(2) - (4)].cval), (yyvsp[(4) - (4)].cval)); 
	}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 717 "gtkdialog_parser.y"
    { 
		token_store(SHOW);     
	}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 720 "gtkdialog_parser.y"
    {
  		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
	}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 723 "gtkdialog_parser.y"
    {
		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
		instruction_set_jump((yyvsp[(6) - (6)].ival) + 1, (yyvsp[(1) - (6)].ival));
	}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 730 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMASSG | VARIABLE_NAME, (yyvsp[(1) - (4)].cval)); 
	}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 736 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | VARIABLE_NAME, (yyvsp[(1) - (1)].cval)); 
	}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 739 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | CONST_NUMBER, (yyvsp[(1) - (1)].cval)); 
  	}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 742 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_ADD);
	}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 745 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_SUBST);
	}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 748 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_MULT);
	}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 751 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_DIV);
	}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 754 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_EQ);
	}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 757 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_NE);
	}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 767 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 774 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 778 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 782 "gtkdialog_parser.y"
    {
		token_store(GOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 789 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
    }
    break;



/* Line 1455 of yacc.c  */
#line 4023 "gtkdialog_parser.c"
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



/* Line 1675 of yacc.c  */
#line 795 "gtkdialog_parser.y"


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


