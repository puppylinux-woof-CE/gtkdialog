
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
     ECOLORBUTTON = 400
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 77 "gtkdialog_parser.y"
 
  double     dval;
  char      *cval;
  GList     *lval;
  tag_attr *nvval;
  gint       ival;



/* Line 214 of yacc.c  */
#line 494 "gtkdialog_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 506 "gtkdialog_parser.c"

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
#define YYFINAL  113
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3318

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  154
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  179
/* YYNRULES -- Number of states.  */
#define YYNSTATES  504

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   400

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   153,     2,     2,     2,     2,     2,     2,
       2,     2,   115,   114,     2,   113,     2,   116,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   152,     2,
       2,   112,   151,     2,     2,     2,     2,     2,     2,     2,
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
     105,   106,   107,   108,   109,   110,   111,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150
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
     173,   179,   183,   187,   193,   197,   201,   207,   211,   215,
     221,   225,   229,   235,   239,   243,   249,   253,   257,   261,
     265,   269,   273,   279,   283,   287,   293,   297,   301,   307,
     311,   315,   321,   325,   329,   333,   339,   343,   347,   353,
     356,   361,   367,   374,   382,   384,   386,   388,   391,   396,
     402,   409,   417,   421,   426,   432,   439,   442,   446,   449,
     454,   457,   462,   466,   472,   476,   482,   486,   492,   496,
     502,   506,   512,   516,   522,   526,   532,   536,   542,   546,
     552,   553,   556,   559,   562,   565,   568,   571,   574,   577,
     580,   583,   587,   591,   595,   599,   603,   607,   611,   617,
     621,   627,   632,   636,   640,   644,   650,   654,   657,   663,
     667,   672,   677,   679,   686,   693,   698,   700,   702,   706,
     710,   714,   718,   722,   727,   729,   730,   732,   734,   736
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     155,     0,    -1,   188,   156,    -1,     3,   156,   188,     5,
      -1,     4,   199,   151,   156,   188,     5,    -1,   157,    -1,
     156,   157,    -1,   200,    -1,   156,   200,    -1,     6,   156,
     188,     8,    -1,   156,     6,   156,   188,     8,    -1,     7,
     199,   151,   156,   188,     8,    -1,   156,     7,   199,   151,
     156,   188,     8,    -1,     9,   156,   188,    11,    -1,   156,
       9,   156,   188,    11,    -1,    10,   199,   151,   156,   188,
      11,    -1,   156,    10,   199,   151,   156,   188,    11,    -1,
      12,   156,   188,    13,    -1,   156,    12,   156,   188,    13,
      -1,    14,   199,   151,   156,   188,    13,    -1,   156,    14,
     199,   151,   156,   188,    13,    -1,    15,   156,   188,    17,
      -1,   156,    15,   156,   188,    17,    -1,   162,    -1,   158,
      -1,   159,    -1,   160,    -1,   161,    -1,   163,    -1,   164,
      -1,   165,    -1,   166,    -1,   167,    -1,   168,    -1,   169,
      -1,   171,    -1,   170,    -1,   172,    -1,   177,    -1,   178,
      -1,   179,    -1,   180,    -1,   181,    -1,   182,    -1,   183,
      -1,   184,    -1,   185,    -1,   186,    -1,   187,    -1,    18,
     188,    19,    -1,    20,   199,   151,   188,    19,    -1,    18,
     188,    18,    -1,    32,   188,    34,    -1,    33,   199,   151,
     188,    34,    -1,    32,   188,    32,    -1,    35,   188,    37,
      -1,    36,   199,   151,   188,    37,    -1,    35,   188,    35,
      -1,    38,   188,    40,    -1,    39,   199,   151,   188,    40,
      -1,    38,   188,    38,    -1,    73,   188,    75,    -1,    74,
     199,   151,   188,    75,    -1,    73,   188,    73,    -1,    46,
     188,    48,    -1,    47,   199,   151,   188,    48,    -1,    49,
     188,    48,    -1,    50,   188,    48,    -1,    51,   188,    48,
      -1,    53,   188,    48,    -1,    52,   188,    48,    -1,    54,
     188,    55,    -1,    56,   199,   151,   188,    55,    -1,    54,
     188,    54,    -1,    57,   188,    58,    -1,    59,   199,   151,
     188,    58,    -1,    57,   188,    57,    -1,    60,   188,    61,
      -1,    62,   199,   151,   188,    61,    -1,    60,   188,    60,
      -1,    63,   188,    65,    -1,    64,   199,   151,   188,    65,
      -1,    63,   188,    63,    -1,    66,   188,    67,    -1,    68,
     188,    70,    -1,    69,   199,   151,   188,    70,    -1,    71,
     188,    72,    -1,    76,   188,    78,    -1,    77,   199,   151,
     188,    78,    -1,    21,    23,    -1,    21,   174,   188,    23,
      -1,   174,    21,   174,   188,    23,    -1,    22,   199,   151,
     174,   188,    23,    -1,   174,    22,   199,   151,   174,   188,
      23,    -1,   174,    -1,   175,    -1,   176,    -1,    24,    26,
      -1,    24,   173,   188,    26,    -1,   173,    24,   173,   188,
      26,    -1,    25,   199,   151,   173,   188,    26,    -1,   173,
      25,   199,   151,   173,   188,    26,    -1,    27,   188,    29,
      -1,   173,    27,   188,    29,    -1,    28,   199,   151,   188,
      29,    -1,   173,    28,   199,   151,   188,    29,    -1,    30,
      31,    -1,   173,    30,    31,    -1,   118,   120,    -1,   119,
     199,   151,   120,    -1,   121,   123,    -1,   122,   199,   151,
     123,    -1,   124,   188,   126,    -1,   125,   199,   151,   188,
     126,    -1,   127,   188,   129,    -1,   128,   199,   151,   188,
     129,    -1,   130,   188,   132,    -1,   131,   199,   151,   188,
     132,    -1,   133,   188,   135,    -1,   134,   199,   151,   188,
     135,    -1,   136,   188,   138,    -1,   137,   199,   151,   188,
     138,    -1,   139,   188,   141,    -1,   140,   199,   151,   188,
     141,    -1,   142,   188,   144,    -1,   143,   199,   151,   188,
     144,    -1,   145,   188,   147,    -1,   146,   199,   151,   188,
     147,    -1,   148,   188,   150,    -1,   149,   199,   151,   188,
     150,    -1,    -1,   188,   192,    -1,   188,   191,    -1,   188,
     190,    -1,   188,   189,    -1,   188,   193,    -1,   188,   194,
      -1,   188,   195,    -1,   188,   196,    -1,   188,   197,    -1,
     188,   198,    -1,    41,   111,    42,    -1,    83,   111,    84,
      -1,    81,   111,    82,    -1,    79,   111,    80,    -1,    85,
     111,    86,    -1,    87,   111,    88,    -1,    89,   111,    91,
      -1,    92,   199,   151,   111,    91,    -1,    90,   111,    91,
      -1,    93,   199,   151,   111,    91,    -1,    93,   199,   151,
      91,    -1,    94,   111,    96,    -1,    95,   111,    96,    -1,
      97,   111,    98,    -1,    99,   199,   151,   111,    98,    -1,
      43,   111,    44,    -1,    43,    44,    -1,    45,   199,   151,
     111,    44,    -1,    16,   112,   111,    -1,   199,    16,   112,
     111,    -1,   100,   201,   151,   101,    -1,   106,    -1,   203,
     202,   151,   204,   156,   205,    -1,   206,   202,   151,   208,
     156,   207,    -1,   107,   152,   112,   202,    -1,   107,    -1,
     108,    -1,   202,   114,   202,    -1,   202,   113,   202,    -1,
     202,   115,   202,    -1,   202,   116,   202,    -1,   202,   112,
     202,    -1,   202,   153,   112,   202,    -1,   102,    -1,    -1,
     103,    -1,   104,    -1,   105,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   158,   158,   162,   166,   173,   174,   177,   178,   179,
     182,   186,   189,   193,   196,   200,   203,   207,   210,   214,
     217,   221,   225,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   262,
     265,   268,   273,   276,   279,   285,   288,   291,   297,   300,
     303,   309,   312,   315,   319,   320,   323,   324,   325,   326,
     327,   331,   334,   338,   344,   347,   350,   356,   359,   362,
     368,   371,   374,   380,   384,   387,   393,   397,   398,   411,
     414,   417,   421,   424,   431,   432,   433,   437,   440,   443,
     447,   450,   457,   460,   464,   467,   474,   477,   484,   487,
     493,   496,   502,   505,   511,   514,   520,   523,   529,   532,
     538,   541,   547,   550,   556,   559,   565,   568,   574,   577,
     582,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   597,   602,   607,   612,   617,   622,   627,   630,   633,
     636,   639,   645,   648,   654,   657,   664,   667,   670,   676,
     679,   685,   686,   689,   692,   699,   705,   708,   711,   714,
     717,   720,   723,   726,   732,   736,   743,   747,   751,   758
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
  "PART_LIST", "ELIST", "TABLE", "ETABLE", "COMBO", "PART_COMBO", "ECOMBO",
  "GVIM", "EGVIM", "TEXT", "PART_TEXT", "ETEXT", "PIXMAP", "PART_PIXMAP",
  "EPIXMAP", "DEFAULT", "EDEFAULT", "SENSITIVE", "ESENSITIVE", "VARIABLE",
  "EVARIABLE", "WIDTH", "EWIDTH", "HEIGHT", "EHEIGHT", "INPUT",
  "INPUTFILE", "EINPUT", "PART_INPUT", "PART_INPUTFILE", "OUTPUT",
  "OUTPUTFILE", "EOUTPUT", "ACTION", "EACTION", "PART_ACTION", "COMM",
  "ENDCOMM", "IF", "ENDIF", "WHILE", "EWHILE", "SHOW_WIDGETS",
  "EMB_VARIABLE", "EMB_NUMBER", "END_OF_FILE", "NUMBER", "STRING", "'='",
  "'-'", "'+'", "'*'", "'/'", "UMINUS", "HSEPARATOR", "PART_HSEPARATOR",
  "EHSEPARATOR", "VSEPARATOR", "PART_VSEPARATOR", "EVSEPARATOR",
  "COMBOBOXTEXT", "PART_COMBOBOXTEXT", "ECOMBOBOXTEXT", "COMBOBOXENTRY",
  "PART_COMBOBOXENTRY", "ECOMBOBOXENTRY", "HSCALE", "PART_HSCALE",
  "EHSCALE", "VSCALE", "PART_VSCALE", "EVSCALE", "SPINBUTTON",
  "PART_SPINBUTTON", "ESPINBUTTON", "TIMER", "PART_TIMER", "ETIMER",
  "TOGGLEBUTTON", "PART_TOGGLEBUTTON", "ETOGGLEBUTTON", "STATUSBAR",
  "PART_STATUSBAR", "ESTATUSBAR", "COLORBUTTON", "PART_COLORBUTTON",
  "ECOLORBUTTON", "'>'", "':'", "'!'", "$accept", "window", "wlist",
  "widget", "entry", "edit", "tree", "chooser", "text", "button",
  "checkbox", "radiobutton", "progressbar", "list", "table", "combo",
  "gvim", "pixmap", "menubar", "menuwlist", "menu", "menuitem",
  "menuitemseparator", "hseparator", "vseparator", "comboboxtext",
  "comboboxentry", "hscale", "vscale", "spinbutton", "timer",
  "togglebutton", "statusbar", "colorbutton", "attr", "label", "variable",
  "sensitive", "defaultvalue", "width", "height", "input", "output",
  "action", "item", "tagattr", "imperative", "assignment", "expression",
  "if", "then", "endif", "while", "ewhile", "do", 0
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
     365,   366,    61,    45,    43,    42,    47,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,    62,    58,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   154,   155,   155,   155,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   158,
     158,   158,   159,   159,   159,   160,   160,   160,   161,   161,
     161,   162,   162,   162,   163,   163,   163,   163,   163,   163,
     163,   164,   164,   164,   165,   165,   165,   166,   166,   166,
     167,   167,   167,   168,   169,   169,   170,   171,   171,   172,
     172,   172,   172,   172,   173,   173,   173,   174,   174,   174,
     174,   174,   175,   175,   175,   175,   176,   176,   177,   177,
     178,   178,   179,   179,   180,   180,   181,   181,   182,   182,
     183,   183,   184,   184,   185,   185,   186,   186,   187,   187,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   189,   190,   191,   192,   193,   194,   195,   195,   195,
     195,   195,   196,   196,   197,   197,   198,   198,   198,   199,
     199,   200,   200,   200,   200,   201,   202,   202,   202,   202,
     202,   202,   202,   202,   203,   204,   205,   206,   207,   208
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     6,     1,     2,     1,     2,     4,
       5,     6,     7,     4,     5,     6,     7,     4,     5,     6,
       7,     4,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       5,     3,     3,     5,     3,     3,     5,     3,     3,     5,
       3,     3,     5,     3,     3,     5,     3,     3,     3,     3,
       3,     3,     5,     3,     3,     5,     3,     3,     5,     3,
       3,     5,     3,     3,     3,     5,     3,     3,     5,     2,
       4,     5,     6,     7,     1,     1,     1,     2,     4,     5,
       6,     7,     3,     4,     5,     6,     2,     3,     2,     4,
       2,     4,     3,     5,     3,     5,     3,     5,     3,     5,
       3,     5,     3,     5,     3,     5,     3,     5,     3,     5,
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     5,     3,
       5,     4,     3,     3,     3,     5,     3,     2,     5,     3,
       4,     4,     1,     6,     6,     4,     1,     1,     3,     3,
       3,     3,     3,     4,     1,     0,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,     0,     0,     0,     0,     0,   130,     0,
       0,   130,     0,   130,     0,   130,     0,   130,     0,   130,
     130,   130,   130,   130,   130,     0,   130,     0,   130,     0,
     130,     0,   130,   130,     0,   130,   130,     0,   130,     0,
       0,   174,   177,   162,     0,     0,     0,     0,   130,     0,
     130,     0,   130,     0,   130,     0,   130,     0,   130,     0,
     130,     0,   130,     0,   130,     0,   130,     5,    24,    25,
      26,    27,    23,    28,    29,    30,    31,    32,    33,    34,
      36,    35,    37,     0,    94,    95,    96,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     7,     0,
       0,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,   134,   133,   132,   131,   135,   136,   137,   138,   139,
     140,   130,     0,   130,     0,   130,     0,   130,     0,     0,
      89,   130,     0,    97,   130,    94,     0,     0,     0,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     0,     8,     0,     0,   130,     0,     0,     0,     0,
     166,   167,     0,     0,     0,     0,     0,     0,   157,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,    49,   130,     0,     0,     0,     0,   102,   130,
      54,    52,   130,    57,    55,   130,    60,    58,   130,    64,
     130,    66,    67,    68,    70,    69,    73,    71,   130,    76,
      74,   130,    79,    77,   130,    82,    80,   130,    83,    84,
     130,    86,    63,    61,   130,    87,   130,     0,     0,     0,
       0,   112,   130,   114,   130,   116,   130,   118,   130,   120,
     130,   122,   130,   124,   130,   126,   130,   128,   130,   130,
       0,   130,     0,   130,     0,   130,     3,   130,     0,     0,
       0,   107,   130,     0,     0,     0,     0,     0,     0,   175,
       0,   179,   159,     0,   130,   141,   156,     0,   144,   143,
     142,   145,   146,   147,   149,     0,     0,   152,   153,   154,
       0,     9,   130,    13,   130,    17,   130,    21,     0,    90,
     130,    98,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   161,   109,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   130,     0,
       0,   172,   169,   168,   170,   171,     0,     0,     0,   160,
       0,     0,     0,   151,     0,     0,     0,     0,     0,    50,
       0,     0,   104,    53,    56,    59,    65,    72,    75,    78,
      81,    85,    62,    88,   165,   113,   115,   117,   119,   121,
     123,   125,   127,   129,    10,   130,    14,   130,    18,   130,
      22,    99,   130,     0,    91,   130,     0,   173,     0,     4,
     158,   148,   150,   155,    11,    15,    19,    92,   100,     0,
       0,     0,     0,   105,     0,   176,   163,   178,   164,    12,
      16,    20,   101,    93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,     4,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   112,   108,   190,   232,   109,
     426,   496,   110,   498,   428
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -106
static const yytype_int16 yypact[] =
{
      99,  1139,    -8,     4,   707,  1139,    -8,  1139,    -8,  1139,
      -8,  1139,  -106,    -8,   201,    -8,   208,    -8,  -106,    -8,
     -21,  -106,    -8,  -106,    -8,  -106,    -8,  -106,    -8,  -106,
    -106,  -106,  -106,  -106,  -106,    -8,  -106,    -8,  -106,    -8,
    -106,    -8,  -106,  -106,    -8,  -106,  -106,    -8,  -106,    -8,
     -95,  -106,  -106,  -106,  -104,    -8,   -81,    -8,  -106,    -8,
    -106,    -8,  -106,    -8,  -106,    -8,  -106,    -8,  -106,    -8,
    -106,    -8,  -106,    -8,  -106,    -8,  1283,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,   220,   102,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,    18,
      18,   -68,    -2,  -106,   -36,   -37,    -8,   -33,   -31,   -19,
      17,    26,    40,    42,    -8,    -8,    44,    46,    58,    -8,
    1283,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,  1283,     7,  1283,     9,  1283,    11,  1283,  2140,    13,
    -106,   231,    16,  -106,   220,  -106,    19,  2369,    21,  -106,
    2517,    22,  2496,    23,  2599,    24,  2797,    25,  2814,  2840,
    2857,  2883,  2900,  2671,    27,  2285,    29,  2688,    31,  2731,
      33,  2924,  2955,    35,  2979,  2754,    37,  3012,    39,   -58,
     -47,  -106,    41,  -106,    43,  2036,    45,  1755,    47,  1595,
      49,  1496,    50,  1414,    51,   568,    52,   546,    53,   483,
      54,   302,    55,  1139,    -8,  1139,    -8,  1139,    -8,  1139,
    -106,  1513,  -106,   245,    -8,  -106,    -8,    80,   245,    -8,
    -106,  -106,   -17,    -7,    60,    15,  1139,    76,  -106,    88,
      56,    70,    74,    64,    75,    77,    94,    96,    57,    61,
      93,    95,    97,    63,  1618,  1139,  1772,  1139,  1917,  1139,
     850,  -106,  -106,  -106,  2164,   245,  2266,   245,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,    28,    62,    32,
      98,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  1283,
      65,  1283,    66,  1283,    67,  1283,  -106,   220,    68,  2412,
      69,  -106,   231,    72,    18,    18,    18,    18,    18,  -106,
      81,  -106,  -106,    86,  1283,  -106,  -106,   100,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,   111,    -1,  -106,  -106,  -106,
     116,  -106,  1283,  -106,  1283,  -106,  1283,  -106,  2123,  -106,
     231,  -106,   220,  2431,  2474,  2539,  2616,  3034,  3053,  3077,
    3096,  3137,  3158,  3197,  3219,    18,  -106,  -106,  -106,  2058,
    1796,  1650,  1535,  1436,  1393,  1354,   505,   332,  1673,  1139,
    1857,  1139,  1976,  1139,   994,  2307,   245,  -106,  -106,  2201,
     245,     6,   -15,   -15,    84,    84,  1139,    18,  1139,  -106,
    1556,   124,   108,  -106,   139,   148,  1712,  1876,  1995,  -106,
    2225,  2328,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,     1,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,  1283,  -106,  1283,  -106,  1283,
    -106,  -106,   220,  2453,  -106,   231,   851,     6,   995,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  1733,
    1898,  2017,  2350,  -106,  2242,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -106,  -106,    82,     0,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,   -14,
     -13,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,   -12,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,   494,    36,  -106,  -105,  -106,
    -106,  -106,  -106,  -106,  -106
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -95
static const yytype_int16 yytable[] =
{
     148,   151,   154,   155,   113,   233,   157,   238,   111,   160,
     159,   162,   189,   164,   235,   166,   191,   168,   169,   170,
     171,   172,   173,   235,   175,   235,   177,   235,   179,   235,
     181,   182,   235,   184,   185,   235,   187,   235,   235,   235,
     235,   235,   193,   235,   234,   235,   195,   235,   197,   235,
     199,   235,   201,   235,   203,   235,   205,   235,   207,   235,
     209,   235,   211,   235,   221,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   239,   237,   220,   235,   241,   235,
     242,   235,   235,   235,   235,   235,   130,   141,   235,   143,
     433,   145,   243,   147,   307,   344,   345,   346,   347,   348,
     347,   348,     1,     2,   308,   344,   345,   346,   347,   348,
     434,   341,   222,   344,   345,   346,   347,   348,   355,   345,
     346,   347,   348,   228,   229,   230,   231,   353,   244,   254,
     220,   256,   356,   258,   349,   260,   350,   245,   350,   264,
     395,   220,   266,   220,   351,   220,   350,   220,   360,   236,
     358,   246,   397,   247,   350,   250,   359,   251,   255,   350,
     257,   361,   259,   396,   263,   362,   222,   265,   480,   252,
     267,   352,   269,   272,   275,   278,   280,   222,   288,   222,
     291,   222,   294,   222,   297,   363,   300,   364,   304,   367,
     306,   368,   309,   427,   310,   369,   312,   429,   314,   481,
     316,   318,   320,   322,   324,   326,   328,   357,   365,   337,
     155,   431,   366,   339,   370,   342,   409,   411,   413,   416,
     418,   398,   432,   420,   150,    16,    17,   435,    18,    19,
     482,    20,    16,    17,   153,    18,    19,   350,    20,   421,
     422,   423,   424,   425,   223,   224,   483,   225,   226,     0,
     227,   378,   380,   382,   155,   -94,   -94,   383,   -94,   -94,
     384,   -94,     0,   385,     0,     0,   386,     0,   387,    16,
      17,     0,    18,    19,     0,    20,   388,     0,     0,   389,
       0,     0,   390,     0,     0,   391,     0,     0,   392,     0,
     454,     0,   393,     0,   394,   329,     0,   331,     0,   333,
     399,   335,   400,     0,   401,     0,   402,     0,   403,     0,
     404,     0,   405,     0,   406,     0,   407,   408,   354,   410,
       0,   412,   477,   414,     0,   415,     0,     0,     0,   220,
     419,   220,     0,   220,     0,   220,     0,   372,     0,   374,
       0,   376,   430,   114,     0,   115,     0,   116,     0,     0,
       0,     0,     0,     0,   220,     0,     0,     0,     0,     0,
     436,     0,   437,     0,   438,   222,     0,   222,   440,   222,
     441,   222,   220,   114,   220,   115,   220,   116,     0,     0,
       0,   117,     0,   118,     0,   119,     0,   120,     0,   121,
     222,   122,   123,     0,   124,   125,   126,   127,     0,   128,
       0,   129,   472,   155,     0,     0,   473,   475,   222,     0,
     222,   117,   222,   118,     0,   119,     0,   120,     0,   121,
       0,   122,   123,     0,   124,   125,   126,   127,     0,   128,
       0,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   327,   489,     0,   490,     0,   491,     0,     0,
     492,     0,     0,   494,     0,   220,     0,   220,     0,   220,
       0,     0,     0,     0,     0,     0,   220,     0,   220,     0,
       0,     0,   463,     0,     0,     0,     0,     0,     0,     0,
       0,   465,     0,   467,     0,   469,     0,     0,     0,     0,
     142,   222,   144,   222,   146,   222,     0,   149,   476,   152,
     478,   156,   222,   158,   222,     0,   161,     0,   163,     0,
     165,     0,   167,     0,   114,     0,   115,     0,   116,   174,
       0,   176,     0,   178,     0,   180,     0,     0,   183,     0,
       0,   186,     0,   188,     0,     0,   114,     0,   115,   192,
     116,   194,     0,   196,     0,   198,     0,   200,     0,   202,
       0,   204,   117,   206,   118,   208,   119,   210,   120,   212,
     121,     0,   122,   123,     0,   124,   125,   126,   127,     0,
     128,     0,   129,     0,   117,     0,   118,   114,   119,   115,
     120,   116,   121,     0,   122,   123,     0,   124,   125,   126,
     127,     0,   128,     0,   129,     0,     0,     0,     0,   114,
     240,   115,     0,   116,     0,     0,     0,     0,   248,   249,
       0,     0,     0,   253,     0,   117,     0,   118,     0,   119,
     325,   120,     0,   121,     0,   122,   123,     0,   124,   125,
     126,   127,     0,   128,     0,   129,     0,   117,     0,   118,
       0,   119,   462,   120,     0,   121,     0,   122,   123,     0,
     124,   125,   126,   127,     0,   128,     0,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     323,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   330,   321,
     332,     0,   334,     5,     6,     0,     7,     8,   338,     9,
     340,    10,    11,   343,     0,    12,     0,    13,    14,    15,
       0,    16,    17,     0,    18,    19,     0,    20,     0,    21,
      22,     0,    23,    24,     0,    25,    26,     0,   114,     0,
     115,     0,   116,    27,    28,     0,    29,    30,    31,    32,
      33,    34,     0,    35,    36,     0,    37,    38,     0,    39,
      40,    41,     0,    42,     0,    43,    44,     0,    45,     0,
      46,    47,     0,    48,    49,     0,   117,     0,   118,     0,
     119,     0,   120,     0,   121,     0,   122,   123,     0,   124,
     125,   126,   127,     0,   128,     0,   129,    50,     0,    51,
       0,    52,     0,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    55,     0,    56,    57,
       0,    58,    59,     0,    60,    61,     0,    62,    63,     0,
      64,    65,     0,    66,    67,     0,    68,    69,     0,    70,
      71,     0,    72,    73,     0,    74,    75,   213,   214,     0,
     215,   216,     0,   217,     0,   218,   219,   377,     0,    12,
       0,    13,    14,    15,     0,    16,    17,     0,    18,    19,
       0,    20,     0,    21,    22,     0,    23,    24,     0,    25,
      26,   114,     0,   115,     0,   116,     0,    27,    28,     0,
      29,    30,    31,    32,    33,    34,     0,    35,    36,     0,
      37,    38,     0,    39,    40,    41,     0,    42,     0,    43,
      44,     0,    45,     0,    46,    47,     0,    48,    49,   117,
       0,   118,     0,   119,     0,   120,     0,   121,     0,   122,
     123,     0,   124,   125,   126,   127,     0,   128,     0,   129,
       0,    50,     0,    51,   495,    52,     0,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
      55,     0,    56,    57,     0,    58,    59,     0,    60,    61,
       0,    62,    63,     0,    64,    65,     0,    66,    67,     0,
      68,    69,     0,    70,    71,     0,    72,    73,     0,    74,
      75,   213,   214,     0,   215,   216,     0,   217,     0,   218,
     219,   470,     0,    12,     0,    13,    14,    15,     0,    16,
      17,     0,    18,    19,     0,    20,     0,    21,    22,     0,
      23,    24,     0,    25,    26,   114,     0,   115,     0,   116,
       0,    27,    28,     0,    29,    30,    31,    32,    33,    34,
       0,    35,    36,     0,    37,    38,     0,    39,    40,    41,
       0,    42,     0,    43,    44,     0,    45,     0,    46,    47,
       0,    48,    49,   117,     0,   118,     0,   119,     0,   120,
       0,   121,     0,   122,   123,     0,   124,   125,   126,   127,
       0,   128,     0,   129,     0,    50,     0,    51,     0,    52,
     497,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,    55,     0,    56,    57,     0,    58,
      59,     0,    60,    61,     0,    62,    63,     0,    64,    65,
       0,    66,    67,     0,    68,    69,     0,    70,    71,     0,
      72,    73,     0,    74,    75,     5,     6,     0,     7,     8,
       0,     9,     0,    10,    11,     0,     0,    12,     0,    13,
      14,    15,     0,    16,    17,     0,    18,    19,     0,    20,
       0,    21,    22,     0,    23,    24,     0,    25,    26,     0,
       0,     0,     0,     0,     0,    27,    28,     0,    29,    30,
      31,    32,    33,    34,     0,    35,    36,     0,    37,    38,
       0,    39,    40,    41,     0,    42,     0,    43,    44,     0,
      45,     0,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,    51,     0,    52,     0,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,    55,     0,
      56,    57,     0,    58,    59,     0,    60,    61,     0,    62,
      63,     0,    64,    65,     0,    66,    67,     0,    68,    69,
       0,    70,    71,     0,    72,    73,     0,    74,    75,   213,
     214,     0,   215,   216,     0,   217,     0,   218,   219,     0,
       0,    12,     0,    13,    14,    15,     0,    16,    17,     0,
      18,    19,     0,    20,     0,    21,    22,     0,    23,    24,
       0,    25,    26,     0,     0,     0,     0,     0,     0,    27,
      28,     0,    29,    30,    31,    32,    33,    34,     0,    35,
      36,     0,    37,    38,     0,    39,    40,    41,     0,    42,
       0,    43,    44,     0,    45,     0,    46,    47,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,    51,     0,    52,     0,    53,
       0,     0,     0,     0,     0,   114,     0,   115,     0,   116,
       0,    54,    55,     0,    56,    57,     0,    58,    59,     0,
      60,    61,     0,    62,    63,     0,    64,    65,     0,    66,
      67,     0,    68,    69,     0,    70,    71,     0,    72,    73,
       0,    74,    75,   117,   114,   118,   115,   119,   116,   120,
       0,   121,     0,   122,   123,     0,   124,   125,   126,   127,
       0,   128,     0,   129,     0,   114,     0,   115,     0,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   117,     0,   118,     0,   119,   114,   120,   115,
     121,   116,   122,   123,     0,   124,   125,   126,   127,     0,
     128,     0,   129,   117,     0,   118,     0,   119,   461,   120,
       0,   121,     0,   122,   123,     0,   124,   125,   126,   127,
       0,   128,     0,   129,     0,   117,     0,   118,   336,   119,
       0,   120,     0,   121,     0,   122,   123,     0,   124,   125,
     126,   127,     0,   128,   460,   129,     0,   114,     0,   115,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   319,     0,   114,     0,   115,     0,   116,     0,
       0,   479,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   459,   117,   114,   118,   115,   119,
     116,   120,     0,   121,     0,   122,   123,     0,   124,   125,
     126,   127,   117,   128,   118,   129,   119,   114,   120,   115,
     121,   116,   122,   123,     0,   124,   125,   126,   127,     0,
     128,     0,   129,     0,   117,     0,   118,     0,   119,     0,
     120,     0,   121,     0,   122,   123,   371,   124,   125,   126,
     127,   317,   128,     0,   129,   117,   114,   118,   115,   119,
     116,   120,     0,   121,     0,   122,   123,     0,   124,   125,
     126,   127,     0,   128,     0,   129,     0,     0,     0,   114,
       0,   115,     0,   116,     0,     0,     0,     0,     0,     0,
     458,     0,     0,     0,   117,     0,   118,     0,   119,     0,
     120,   464,   121,     0,   122,   123,     0,   124,   125,   126,
     127,   114,   128,   115,   129,   116,     0,   117,     0,   118,
       0,   119,     0,   120,     0,   121,     0,   122,   123,     0,
     124,   125,   126,   127,   114,   128,   115,   129,   116,     0,
     484,     0,     0,     0,     0,     0,     0,   315,     0,   117,
       0,   118,     0,   119,     0,   120,     0,   121,     0,   122,
     123,   499,   124,   125,   126,   127,     0,   128,     0,   129,
       0,     0,   117,   114,   118,   115,   119,   116,   120,     0,
     121,     0,   122,   123,     0,   124,   125,   126,   127,     0,
     128,     0,   129,     0,   114,     0,   115,     0,   116,     0,
       0,     0,   457,   373,     0,     0,     0,     0,     0,     0,
       0,   117,     0,   118,     0,   119,   114,   120,   115,   121,
     116,   122,   123,     0,   124,   125,   126,   127,     0,   128,
       0,   129,   117,   114,   118,   115,   119,   116,   120,     0,
     121,     0,   122,   123,     0,   124,   125,   126,   127,     0,
     128,     0,   129,     0,   117,     0,   118,   114,   119,   115,
     120,   116,   121,     0,   122,   123,     0,   124,   125,   126,
     127,   117,   128,   118,   129,   119,     0,   120,     0,   121,
       0,   122,   123,     0,   124,   125,   126,   127,   466,   128,
       0,   129,     0,     0,     0,   117,     0,   118,     0,   119,
       0,   120,     0,   121,   313,   122,   123,   485,   124,   125,
     126,   127,     0,   128,     0,   129,     0,     0,   114,     0,
     115,     0,   116,     0,     0,     0,     0,     0,     0,   500,
       0,     0,     0,     0,     0,     0,     0,   114,     0,   115,
       0,   116,     0,     0,     0,   456,     0,     0,     0,     0,
     375,     0,     0,     0,     0,     0,   117,     0,   118,   114,
     119,   115,   120,   116,   121,     0,   122,   123,     0,   124,
     125,   126,   127,     0,   128,   117,   129,   118,   114,   119,
     115,   120,   116,   121,     0,   122,   123,     0,   124,   125,
     126,   127,     0,   128,     0,   129,     0,   117,     0,   118,
       0,   119,     0,   120,     0,   121,     0,   122,   123,   468,
     124,   125,   126,   127,     0,   128,   117,   129,   118,     0,
     119,     0,   120,     0,   121,     0,   122,   123,   486,   124,
     125,   126,   127,     0,   128,     0,   129,   114,     0,   115,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
     501,     0,     0,     0,     0,     0,   114,     0,   115,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   117,     0,   118,   114,   119,
     115,   120,   116,   121,     0,   122,   123,     0,   124,   125,
     126,   127,     0,   128,   117,   129,   118,   114,   119,   115,
     120,   116,   121,     0,   122,   123,     0,   124,   125,   126,
     127,     0,   128,     0,   129,     0,   117,     0,   118,   114,
     119,   115,   120,   116,   121,     0,   122,   123,     0,   124,
     125,   126,   127,     0,   128,   117,   129,   118,     0,   119,
       0,   120,     0,   121,     0,   122,   123,     0,   124,   125,
     126,   127,     0,   128,     0,   129,     0,   117,     0,   118,
       0,   119,   439,   120,     0,   121,     0,   122,   123,     0,
     124,   125,   126,   127,     0,   128,     0,   129,   261,   262,
       0,     0,   311,     0,   114,     0,   115,     0,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,     0,   115,   455,   116,     0,   379,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   117,     0,   118,   114,   119,   115,   120,   116,
     121,     0,   122,   123,     0,   124,   125,   126,   127,   117,
     128,   118,   129,   119,   474,   120,     0,   121,     0,   122,
     123,     0,   124,   125,   126,   127,     0,   128,     0,   129,
       0,     0,   114,   117,   115,   118,   116,   119,   487,   120,
       0,   121,     0,   122,   123,     0,   124,   125,   126,   127,
       0,   128,     0,   129,     0,   503,   114,     0,   115,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,     0,   118,   114,   119,   115,   120,   116,   121,     0,
     122,   123,   381,   124,   125,   126,   127,     0,   128,     0,
     129,     0,     0,     0,   117,     0,   118,   114,   119,   115,
     120,   116,   121,     0,   122,   123,     0,   124,   125,   126,
     127,   117,   128,   118,   129,   119,   114,   120,   115,   121,
     116,   122,   123,   471,   124,   125,   126,   127,     0,   128,
       0,   129,   289,   290,     0,   117,     0,   118,   114,   119,
     115,   120,   116,   121,   488,   122,   123,     0,   124,   125,
     126,   127,     0,   128,   117,   129,   118,     0,   119,   114,
     120,   115,   121,   116,   122,   123,   502,   124,   125,   126,
     127,     0,   128,     0,   129,     0,   117,     0,   118,     0,
     119,   114,   120,   115,   121,   116,   122,   123,   268,   124,
     125,   126,   127,     0,   128,     0,   129,   117,     0,   118,
     114,   119,   115,   120,   116,   121,     0,   122,   123,     0,
     124,   125,   126,   127,     0,   128,     0,   129,     0,   117,
       0,   118,     0,   119,     0,   120,     0,   121,     0,   122,
     123,   417,   124,   125,   126,   127,     0,   128,   117,   129,
     118,     0,   119,   114,   120,   115,   121,   116,   122,   123,
     442,   124,   125,   126,   127,     0,   128,     0,   129,     0,
       0,     0,   114,     0,   115,     0,   116,     0,     0,     0,
       0,     0,   493,     0,     0,     0,     0,     0,     0,     0,
       0,   117,     0,   118,   114,   119,   115,   120,   116,   121,
       0,   122,   123,     0,   124,   125,   126,   127,   443,   128,
     117,   129,   118,     0,   119,   114,   120,   115,   121,   116,
     122,   123,     0,   124,   125,   126,   127,     0,   128,     0,
     129,   273,   117,   274,   118,     0,   119,   114,   120,   115,
     121,   116,   122,   123,     0,   124,   125,   126,   127,   270,
     128,   271,   129,   117,     0,   118,     0,   119,   114,   120,
     115,   121,   116,   122,   123,     0,   124,   125,   126,   127,
       0,   128,     0,   129,     0,   117,   444,   118,     0,   119,
     114,   120,   115,   121,   116,   122,   123,     0,   124,   125,
     126,   127,     0,   128,     0,   129,   117,     0,   118,     0,
     119,     0,   120,     0,   121,     0,   122,   123,     0,   124,
     125,   126,   127,     0,   128,     0,   129,     0,   117,     0,
     118,     0,   119,     0,   120,     0,   121,     0,   122,   123,
       0,   124,   125,   126,   127,     0,   128,   276,   129,   277,
     114,     0,   115,     0,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   445,   114,     0,   115,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,     0,
     118,     0,   119,     0,   120,     0,   121,     0,   122,   123,
       0,   124,   125,   126,   127,   117,   128,   118,   129,   119,
       0,   120,     0,   121,     0,   122,   123,     0,   124,   125,
     126,   127,   114,   128,   115,   129,   116,     0,     0,     0,
       0,     0,     0,     0,     0,   286,   287,     0,     0,   114,
       0,   115,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   292,   293,
     117,     0,   118,     0,   119,     0,   120,     0,   121,     0,
     122,   123,     0,   124,   125,   126,   127,   117,   128,   118,
     129,   119,   114,   120,   115,   121,   116,   122,   123,     0,
     124,   125,   126,   127,     0,   128,     0,   129,     0,     0,
       0,     0,     0,     0,   295,   114,   296,   115,     0,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,     0,   118,     0,   119,     0,   120,     0,   121,     0,
     122,   123,     0,   124,   125,   126,   127,   302,   128,   303,
     129,     0,     0,   117,     0,   118,     0,   119,   114,   120,
     115,   121,   116,   122,   123,   279,   124,   125,   126,   127,
       0,   128,     0,   129,     0,   114,     0,   115,     0,   116,
       0,     0,   281,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,     0,   118,     0,
     119,   114,   120,   115,   121,   116,   122,   123,   282,   124,
     125,   126,   127,   117,   128,   118,   129,   119,   114,   120,
     115,   121,   116,   122,   123,   283,   124,   125,   126,   127,
       0,   128,     0,   129,     0,     0,     0,     0,     0,   117,
       0,   118,     0,   119,   114,   120,   115,   121,   116,   122,
     123,   284,   124,   125,   126,   127,   117,   128,   118,   129,
     119,   114,   120,   115,   121,   116,   122,   123,   285,   124,
     125,   126,   127,     0,   128,     0,   129,     0,     0,     0,
       0,     0,   117,     0,   118,   114,   119,   115,   120,   116,
     121,     0,   122,   123,     0,   124,   125,   126,   127,   117,
     128,   118,   129,   119,     0,   120,     0,   121,     0,   122,
     123,   298,   124,   125,   126,   127,   114,   128,   115,   129,
     116,     0,     0,   117,     0,   118,     0,   119,     0,   120,
       0,   121,     0,   122,   123,     0,   124,   125,   126,   127,
     114,   128,   115,   129,   116,   299,     0,     0,     0,     0,
       0,     0,     0,     0,   117,     0,   118,     0,   119,     0,
     120,     0,   121,     0,   122,   123,     0,   124,   125,   126,
     127,   301,   128,   114,   129,   115,     0,   116,   117,     0,
     118,     0,   119,     0,   120,     0,   121,     0,   122,   123,
       0,   124,   125,   126,   127,   114,   128,   115,   129,   116,
       0,     0,   446,     0,     0,     0,     0,     0,     0,     0,
     305,   117,     0,   118,   114,   119,   115,   120,   116,   121,
       0,   122,   123,     0,   124,   125,   126,   127,   447,   128,
       0,   129,     0,   117,     0,   118,     0,   119,   114,   120,
     115,   121,   116,   122,   123,     0,   124,   125,   126,   127,
       0,   128,   117,   129,   118,   448,   119,   114,   120,   115,
     121,   116,   122,   123,     0,   124,   125,   126,   127,     0,
     128,     0,   129,     0,     0,     0,   117,   449,   118,     0,
     119,     0,   120,     0,   121,     0,   122,   123,     0,   124,
     125,   126,   127,     0,   128,   117,   129,   118,   114,   119,
     115,   120,   116,   121,     0,   122,   123,     0,   124,   125,
     126,   127,     0,   128,     0,   129,     0,     0,     0,   114,
       0,   115,   450,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,     0,   118,     0,
     119,     0,   120,     0,   121,     0,   122,   123,   451,   124,
     125,   126,   127,     0,   128,     0,   129,   117,   114,   118,
     115,   119,   116,   120,     0,   121,     0,   122,   123,     0,
     124,   125,   126,   127,     0,   128,     0,   129,     0,     0,
     114,     0,   115,     0,   116,     0,     0,     0,     0,     0,
       0,     0,   452,     0,     0,     0,   117,     0,   118,     0,
     119,     0,   120,     0,   121,     0,   122,   123,     0,   124,
     125,   126,   127,     0,   128,     0,   129,   453,   117,     0,
     118,     0,   119,     0,   120,     0,   121,     0,   122,   123,
       0,   124,   125,   126,   127,     0,   128,     0,   129
};

static const yytype_int16 yycheck[] =
{
      12,    14,    16,    16,     0,   110,    18,    44,    16,    21,
      31,    23,   107,    25,    16,    27,   120,    29,    30,    31,
      32,    33,    34,    16,    36,    16,    38,    16,    40,    16,
      42,    43,    16,    45,    46,    16,    48,    16,    16,    16,
      16,    16,   123,    16,   112,    16,    58,    16,    60,    16,
      62,    16,    64,    16,    66,    16,    68,    16,    70,    16,
      72,    16,    74,    16,    76,    16,    16,    16,    16,    16,
      16,    16,    16,    16,   111,   111,    76,    16,   111,    16,
     111,    16,    16,    16,    16,    16,     4,     5,    16,     7,
      91,     9,   111,    11,   152,   112,   113,   114,   115,   116,
     115,   116,     3,     4,   151,   112,   113,   114,   115,   116,
     111,    31,    76,   112,   113,   114,   115,   116,    42,   113,
     114,   115,   116,    21,    22,   107,   108,   112,   111,   141,
     130,   143,    44,   145,   151,   147,   153,   111,   153,   151,
     112,   141,   154,   143,   151,   145,   153,   147,    84,   151,
      80,   111,   120,   111,   153,   111,    82,   111,   151,   153,
     151,    86,   151,   101,   151,    88,   130,   151,    44,   111,
     151,   111,   151,   151,   151,   151,   151,   141,   151,   143,
     151,   145,   151,   147,   151,    91,   151,    91,   151,    96,
     151,    96,   151,   112,   151,    98,   151,   111,   151,    91,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   223,
     223,   111,   151,   225,   151,   228,   151,   151,   151,   151,
     151,   123,   111,   151,    23,    24,    25,   111,    27,    28,
      91,    30,    24,    25,    26,    27,    28,   153,    30,   344,
     345,   346,   347,   348,    24,    25,    98,    27,    28,    -1,
      30,   263,   265,   267,   267,    24,    25,   269,    27,    28,
     272,    30,    -1,   275,    -1,    -1,   278,    -1,   280,    24,
      25,    -1,    27,    28,    -1,    30,   288,    -1,    -1,   291,
      -1,    -1,   294,    -1,    -1,   297,    -1,    -1,   300,    -1,
     395,    -1,   304,    -1,   306,   213,    -1,   215,    -1,   217,
     312,   219,   314,    -1,   316,    -1,   318,    -1,   320,    -1,
     322,    -1,   324,    -1,   326,    -1,   328,   329,   236,   331,
      -1,   333,   427,   335,    -1,   337,    -1,    -1,    -1,   329,
     342,   331,    -1,   333,    -1,   335,    -1,   255,    -1,   257,
      -1,   259,   354,    41,    -1,    43,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,   354,    -1,    -1,    -1,    -1,    -1,
     372,    -1,   374,    -1,   376,   329,    -1,   331,   380,   333,
     382,   335,   372,    41,   374,    43,   376,    45,    -1,    -1,
      -1,    79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,
     354,    89,    90,    -1,    92,    93,    94,    95,    -1,    97,
      -1,    99,   416,   416,    -1,    -1,   418,   420,   372,    -1,
     374,    79,   376,    81,    -1,    83,    -1,    85,    -1,    87,
      -1,    89,    90,    -1,    92,    93,    94,    95,    -1,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   150,   465,    -1,   467,    -1,   469,    -1,    -1,
     472,    -1,    -1,   475,    -1,   465,    -1,   467,    -1,   469,
      -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,   478,    -1,
      -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   409,    -1,   411,    -1,   413,    -1,    -1,    -1,    -1,
       6,   465,     8,   467,    10,   469,    -1,    13,   426,    15,
     428,    17,   476,    19,   478,    -1,    22,    -1,    24,    -1,
      26,    -1,    28,    -1,    41,    -1,    43,    -1,    45,    35,
      -1,    37,    -1,    39,    -1,    41,    -1,    -1,    44,    -1,
      -1,    47,    -1,    49,    -1,    -1,    41,    -1,    43,    55,
      45,    57,    -1,    59,    -1,    61,    -1,    63,    -1,    65,
      -1,    67,    79,    69,    81,    71,    83,    73,    85,    75,
      87,    -1,    89,    90,    -1,    92,    93,    94,    95,    -1,
      97,    -1,    99,    -1,    79,    -1,    81,    41,    83,    43,
      85,    45,    87,    -1,    89,    90,    -1,    92,    93,    94,
      95,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    41,
     116,    43,    -1,    45,    -1,    -1,    -1,    -1,   124,   125,
      -1,    -1,    -1,   129,    -1,    79,    -1,    81,    -1,    83,
     147,    85,    -1,    87,    -1,    89,    90,    -1,    92,    93,
      94,    95,    -1,    97,    -1,    99,    -1,    79,    -1,    81,
      -1,    83,   147,    85,    -1,    87,    -1,    89,    90,    -1,
      92,    93,    94,    95,    -1,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,   141,
     216,    -1,   218,     6,     7,    -1,     9,    10,   224,    12,
     226,    14,    15,   229,    -1,    18,    -1,    20,    21,    22,
      -1,    24,    25,    -1,    27,    28,    -1,    30,    -1,    32,
      33,    -1,    35,    36,    -1,    38,    39,    -1,    41,    -1,
      43,    -1,    45,    46,    47,    -1,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    -1,    59,    60,    -1,    62,
      63,    64,    -1,    66,    -1,    68,    69,    -1,    71,    -1,
      73,    74,    -1,    76,    77,    -1,    79,    -1,    81,    -1,
      83,    -1,    85,    -1,    87,    -1,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    -1,    99,   100,    -1,   102,
      -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,    -1,   121,   122,
      -1,   124,   125,    -1,   127,   128,    -1,   130,   131,    -1,
     133,   134,    -1,   136,   137,    -1,   139,   140,    -1,   142,
     143,    -1,   145,   146,    -1,   148,   149,     6,     7,    -1,
       9,    10,    -1,    12,    -1,    14,    15,    17,    -1,    18,
      -1,    20,    21,    22,    -1,    24,    25,    -1,    27,    28,
      -1,    30,    -1,    32,    33,    -1,    35,    36,    -1,    38,
      39,    41,    -1,    43,    -1,    45,    -1,    46,    47,    -1,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    -1,
      59,    60,    -1,    62,    63,    64,    -1,    66,    -1,    68,
      69,    -1,    71,    -1,    73,    74,    -1,    76,    77,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    87,    -1,    89,
      90,    -1,    92,    93,    94,    95,    -1,    97,    -1,    99,
      -1,   100,    -1,   102,   103,   104,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
     119,    -1,   121,   122,    -1,   124,   125,    -1,   127,   128,
      -1,   130,   131,    -1,   133,   134,    -1,   136,   137,    -1,
     139,   140,    -1,   142,   143,    -1,   145,   146,    -1,   148,
     149,     6,     7,    -1,     9,    10,    -1,    12,    -1,    14,
      15,    17,    -1,    18,    -1,    20,    21,    22,    -1,    24,
      25,    -1,    27,    28,    -1,    30,    -1,    32,    33,    -1,
      35,    36,    -1,    38,    39,    41,    -1,    43,    -1,    45,
      -1,    46,    47,    -1,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    -1,    59,    60,    -1,    62,    63,    64,
      -1,    66,    -1,    68,    69,    -1,    71,    -1,    73,    74,
      -1,    76,    77,    79,    -1,    81,    -1,    83,    -1,    85,
      -1,    87,    -1,    89,    90,    -1,    92,    93,    94,    95,
      -1,    97,    -1,    99,    -1,   100,    -1,   102,    -1,   104,
     105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,   119,    -1,   121,   122,    -1,   124,
     125,    -1,   127,   128,    -1,   130,   131,    -1,   133,   134,
      -1,   136,   137,    -1,   139,   140,    -1,   142,   143,    -1,
     145,   146,    -1,   148,   149,     6,     7,    -1,     9,    10,
      -1,    12,    -1,    14,    15,    -1,    -1,    18,    -1,    20,
      21,    22,    -1,    24,    25,    -1,    27,    28,    -1,    30,
      -1,    32,    33,    -1,    35,    36,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    -1,    59,    60,
      -1,    62,    63,    64,    -1,    66,    -1,    68,    69,    -1,
      71,    -1,    73,    74,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
      -1,   102,    -1,   104,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,    -1,
     121,   122,    -1,   124,   125,    -1,   127,   128,    -1,   130,
     131,    -1,   133,   134,    -1,   136,   137,    -1,   139,   140,
      -1,   142,   143,    -1,   145,   146,    -1,   148,   149,     6,
       7,    -1,     9,    10,    -1,    12,    -1,    14,    15,    -1,
      -1,    18,    -1,    20,    21,    22,    -1,    24,    25,    -1,
      27,    28,    -1,    30,    -1,    32,    33,    -1,    35,    36,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    -1,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    -1,    59,    60,    -1,    62,    63,    64,    -1,    66,
      -1,    68,    69,    -1,    71,    -1,    73,    74,    -1,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,    -1,   102,    -1,   104,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    45,
      -1,   118,   119,    -1,   121,   122,    -1,   124,   125,    -1,
     127,   128,    -1,   130,   131,    -1,   133,   134,    -1,   136,
     137,    -1,   139,   140,    -1,   142,   143,    -1,   145,   146,
      -1,   148,   149,    79,    41,    81,    43,    83,    45,    85,
      -1,    87,    -1,    89,    90,    -1,    92,    93,    94,    95,
      -1,    97,    -1,    99,    -1,    41,    -1,    43,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    81,    -1,    83,    41,    85,    43,
      87,    45,    89,    90,    -1,    92,    93,    94,    95,    -1,
      97,    -1,    99,    79,    -1,    81,    -1,    83,   144,    85,
      -1,    87,    -1,    89,    90,    -1,    92,    93,    94,    95,
      -1,    97,    -1,    99,    -1,    79,    -1,    81,     5,    83,
      -1,    85,    -1,    87,    -1,    89,    90,    -1,    92,    93,
      94,    95,    -1,    97,   141,    99,    -1,    41,    -1,    43,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    41,    -1,    43,    -1,    45,    -1,
      -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    79,    41,    81,    43,    83,
      45,    85,    -1,    87,    -1,    89,    90,    -1,    92,    93,
      94,    95,    79,    97,    81,    99,    83,    41,    85,    43,
      87,    45,    89,    90,    -1,    92,    93,    94,    95,    -1,
      97,    -1,    99,    -1,    79,    -1,    81,    -1,    83,    -1,
      85,    -1,    87,    -1,    89,    90,     8,    92,    93,    94,
      95,   135,    97,    -1,    99,    79,    41,    81,    43,    83,
      45,    85,    -1,    87,    -1,    89,    90,    -1,    92,    93,
      94,    95,    -1,    97,    -1,    99,    -1,    -1,    -1,    41,
      -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,    79,    -1,    81,    -1,    83,    -1,
      85,     8,    87,    -1,    89,    90,    -1,    92,    93,    94,
      95,    41,    97,    43,    99,    45,    -1,    79,    -1,    81,
      -1,    83,    -1,    85,    -1,    87,    -1,    89,    90,    -1,
      92,    93,    94,    95,    41,    97,    43,    99,    45,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    87,    -1,    89,
      90,     8,    92,    93,    94,    95,    -1,    97,    -1,    99,
      -1,    -1,    79,    41,    81,    43,    83,    45,    85,    -1,
      87,    -1,    89,    90,    -1,    92,    93,    94,    95,    -1,
      97,    -1,    99,    -1,    41,    -1,    43,    -1,    45,    -1,
      -1,    -1,   132,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    81,    -1,    83,    41,    85,    43,    87,
      45,    89,    90,    -1,    92,    93,    94,    95,    -1,    97,
      -1,    99,    79,    41,    81,    43,    83,    45,    85,    -1,
      87,    -1,    89,    90,    -1,    92,    93,    94,    95,    -1,
      97,    -1,    99,    -1,    79,    -1,    81,    41,    83,    43,
      85,    45,    87,    -1,    89,    90,    -1,    92,    93,    94,
      95,    79,    97,    81,    99,    83,    -1,    85,    -1,    87,
      -1,    89,    90,    -1,    92,    93,    94,    95,    11,    97,
      -1,    99,    -1,    -1,    -1,    79,    -1,    81,    -1,    83,
      -1,    85,    -1,    87,   129,    89,    90,    11,    92,    93,
      94,    95,    -1,    97,    -1,    99,    -1,    -1,    41,    -1,
      43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    43,
      -1,    45,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    41,
      83,    43,    85,    45,    87,    -1,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    79,    99,    81,    41,    83,
      43,    85,    45,    87,    -1,    89,    90,    -1,    92,    93,
      94,    95,    -1,    97,    -1,    99,    -1,    79,    -1,    81,
      -1,    83,    -1,    85,    -1,    87,    -1,    89,    90,    13,
      92,    93,    94,    95,    -1,    97,    79,    99,    81,    -1,
      83,    -1,    85,    -1,    87,    -1,    89,    90,    13,    92,
      93,    94,    95,    -1,    97,    -1,    99,    41,    -1,    43,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    41,    -1,    43,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    41,    83,
      43,    85,    45,    87,    -1,    89,    90,    -1,    92,    93,
      94,    95,    -1,    97,    79,    99,    81,    41,    83,    43,
      85,    45,    87,    -1,    89,    90,    -1,    92,    93,    94,
      95,    -1,    97,    -1,    99,    -1,    79,    -1,    81,    41,
      83,    43,    85,    45,    87,    -1,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    79,    99,    81,    -1,    83,
      -1,    85,    -1,    87,    -1,    89,    90,    -1,    92,    93,
      94,    95,    -1,    97,    -1,    99,    -1,    79,    -1,    81,
      -1,    83,    19,    85,    -1,    87,    -1,    89,    90,    -1,
      92,    93,    94,    95,    -1,    97,    -1,    99,    18,    19,
      -1,    -1,   126,    -1,    41,    -1,    43,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    43,   126,    45,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    81,    41,    83,    43,    85,    45,
      87,    -1,    89,    90,    -1,    92,    93,    94,    95,    79,
      97,    81,    99,    83,    23,    85,    -1,    87,    -1,    89,
      90,    -1,    92,    93,    94,    95,    -1,    97,    -1,    99,
      -1,    -1,    41,    79,    43,    81,    45,    83,    23,    85,
      -1,    87,    -1,    89,    90,    -1,    92,    93,    94,    95,
      -1,    97,    -1,    99,    -1,    23,    41,    -1,    43,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    81,    41,    83,    43,    85,    45,    87,    -1,
      89,    90,    26,    92,    93,    94,    95,    -1,    97,    -1,
      99,    -1,    -1,    -1,    79,    -1,    81,    41,    83,    43,
      85,    45,    87,    -1,    89,    90,    -1,    92,    93,    94,
      95,    79,    97,    81,    99,    83,    41,    85,    43,    87,
      45,    89,    90,    26,    92,    93,    94,    95,    -1,    97,
      -1,    99,    57,    58,    -1,    79,    -1,    81,    41,    83,
      43,    85,    45,    87,    26,    89,    90,    -1,    92,    93,
      94,    95,    -1,    97,    79,    99,    81,    -1,    83,    41,
      85,    43,    87,    45,    89,    90,    26,    92,    93,    94,
      95,    -1,    97,    -1,    99,    -1,    79,    -1,    81,    -1,
      83,    41,    85,    43,    87,    45,    89,    90,    29,    92,
      93,    94,    95,    -1,    97,    -1,    99,    79,    -1,    81,
      41,    83,    43,    85,    45,    87,    -1,    89,    90,    -1,
      92,    93,    94,    95,    -1,    97,    -1,    99,    -1,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    87,    -1,    89,
      90,    29,    92,    93,    94,    95,    -1,    97,    79,    99,
      81,    -1,    83,    41,    85,    43,    87,    45,    89,    90,
      29,    92,    93,    94,    95,    -1,    97,    -1,    99,    -1,
      -1,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    81,    41,    83,    43,    85,    45,    87,
      -1,    89,    90,    -1,    92,    93,    94,    95,    34,    97,
      79,    99,    81,    -1,    83,    41,    85,    43,    87,    45,
      89,    90,    -1,    92,    93,    94,    95,    -1,    97,    -1,
      99,    35,    79,    37,    81,    -1,    83,    41,    85,    43,
      87,    45,    89,    90,    -1,    92,    93,    94,    95,    32,
      97,    34,    99,    79,    -1,    81,    -1,    83,    41,    85,
      43,    87,    45,    89,    90,    -1,    92,    93,    94,    95,
      -1,    97,    -1,    99,    -1,    79,    37,    81,    -1,    83,
      41,    85,    43,    87,    45,    89,    90,    -1,    92,    93,
      94,    95,    -1,    97,    -1,    99,    79,    -1,    81,    -1,
      83,    -1,    85,    -1,    87,    -1,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    -1,    99,    -1,    79,    -1,
      81,    -1,    83,    -1,    85,    -1,    87,    -1,    89,    90,
      -1,    92,    93,    94,    95,    -1,    97,    38,    99,    40,
      41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    43,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      81,    -1,    83,    -1,    85,    -1,    87,    -1,    89,    90,
      -1,    92,    93,    94,    95,    79,    97,    81,    99,    83,
      -1,    85,    -1,    87,    -1,    89,    90,    -1,    92,    93,
      94,    95,    41,    97,    43,    99,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,    41,
      -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,    -1,
      89,    90,    -1,    92,    93,    94,    95,    79,    97,    81,
      99,    83,    41,    85,    43,    87,    45,    89,    90,    -1,
      92,    93,    94,    95,    -1,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    41,    65,    43,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,    -1,
      89,    90,    -1,    92,    93,    94,    95,    73,    97,    75,
      99,    -1,    -1,    79,    -1,    81,    -1,    83,    41,    85,
      43,    87,    45,    89,    90,    48,    92,    93,    94,    95,
      -1,    97,    -1,    99,    -1,    41,    -1,    43,    -1,    45,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    -1,
      83,    41,    85,    43,    87,    45,    89,    90,    48,    92,
      93,    94,    95,    79,    97,    81,    99,    83,    41,    85,
      43,    87,    45,    89,    90,    48,    92,    93,    94,    95,
      -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    81,    -1,    83,    41,    85,    43,    87,    45,    89,
      90,    48,    92,    93,    94,    95,    79,    97,    81,    99,
      83,    41,    85,    43,    87,    45,    89,    90,    48,    92,
      93,    94,    95,    -1,    97,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    81,    41,    83,    43,    85,    45,
      87,    -1,    89,    90,    -1,    92,    93,    94,    95,    79,
      97,    81,    99,    83,    -1,    85,    -1,    87,    -1,    89,
      90,    67,    92,    93,    94,    95,    41,    97,    43,    99,
      45,    -1,    -1,    79,    -1,    81,    -1,    83,    -1,    85,
      -1,    87,    -1,    89,    90,    -1,    92,    93,    94,    95,
      41,    97,    43,    99,    45,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    81,    -1,    83,    -1,
      85,    -1,    87,    -1,    89,    90,    -1,    92,    93,    94,
      95,    72,    97,    41,    99,    43,    -1,    45,    79,    -1,
      81,    -1,    83,    -1,    85,    -1,    87,    -1,    89,    90,
      -1,    92,    93,    94,    95,    41,    97,    43,    99,    45,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    -1,    81,    41,    83,    43,    85,    45,    87,
      -1,    89,    90,    -1,    92,    93,    94,    95,    55,    97,
      -1,    99,    -1,    79,    -1,    81,    -1,    83,    41,    85,
      43,    87,    45,    89,    90,    -1,    92,    93,    94,    95,
      -1,    97,    79,    99,    81,    58,    83,    41,    85,    43,
      87,    45,    89,    90,    -1,    92,    93,    94,    95,    -1,
      97,    -1,    99,    -1,    -1,    -1,    79,    61,    81,    -1,
      83,    -1,    85,    -1,    87,    -1,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    79,    99,    81,    41,    83,
      43,    85,    45,    87,    -1,    89,    90,    -1,    92,    93,
      94,    95,    -1,    97,    -1,    99,    -1,    -1,    -1,    41,
      -1,    43,    65,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    -1,
      83,    -1,    85,    -1,    87,    -1,    89,    90,    70,    92,
      93,    94,    95,    -1,    97,    -1,    99,    79,    41,    81,
      43,    83,    45,    85,    -1,    87,    -1,    89,    90,    -1,
      92,    93,    94,    95,    -1,    97,    -1,    99,    -1,    -1,
      41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    -1,    79,    -1,    81,    -1,
      83,    -1,    85,    -1,    87,    -1,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    -1,    99,    78,    79,    -1,
      81,    -1,    83,    -1,    85,    -1,    87,    -1,    89,    90,
      -1,    92,    93,    94,    95,    -1,    97,    -1,    99
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,   155,   188,     6,     7,     9,    10,    12,
      14,    15,    18,    20,    21,    22,    24,    25,    27,    28,
      30,    32,    33,    35,    36,    38,    39,    46,    47,    49,
      50,    51,    52,    53,    54,    56,    57,    59,    60,    62,
      63,    64,    66,    68,    69,    71,    73,    74,    76,    77,
     100,   102,   104,   106,   118,   119,   121,   122,   124,   125,
     127,   128,   130,   131,   133,   134,   136,   137,   139,   140,
     142,   143,   145,   146,   148,   149,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   200,   203,
     206,    16,   199,     0,    41,    43,    45,    79,    81,    83,
      85,    87,    89,    90,    92,    93,    94,    95,    97,    99,
     156,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   156,   199,   156,   199,   156,   199,   156,   188,   199,
      23,   174,   199,    26,   173,   174,   199,   188,   199,    31,
     188,   199,   188,   199,   188,   199,   188,   199,   188,   188,
     188,   188,   188,   188,   199,   188,   199,   188,   199,   188,
     199,   188,   188,   199,   188,   188,   199,   188,   199,   107,
     201,   120,   199,   123,   199,   188,   199,   188,   199,   188,
     199,   188,   199,   188,   199,   188,   199,   188,   199,   188,
     199,   188,   199,     6,     7,     9,    10,    12,    14,    15,
     157,   188,   200,    24,    25,    27,    28,    30,    21,    22,
     107,   108,   202,   202,   112,    16,   151,   111,    44,   111,
     199,   111,   111,   111,   111,   111,   111,   111,   199,   199,
     111,   111,   111,   199,   188,   151,   188,   151,   188,   151,
     188,    18,    19,   151,   188,   151,   188,   151,    29,   151,
      32,    34,   151,    35,    37,   151,    38,    40,   151,    48,
     151,    48,    48,    48,    48,    48,    54,    55,   151,    57,
      58,   151,    60,    61,   151,    63,    65,   151,    67,    70,
     151,    72,    73,    75,   151,    78,   151,   152,   151,   151,
     151,   126,   151,   129,   151,   132,   151,   135,   151,   138,
     151,   141,   151,   144,   151,   147,   151,   150,   151,   156,
     199,   156,   199,   156,   199,   156,     5,   173,   199,   188,
     199,    31,   174,   199,   112,   113,   114,   115,   116,   151,
     153,   151,   111,   112,   156,    42,    44,   151,    80,    82,
      84,    86,    88,    91,    91,   151,   151,    96,    96,    98,
     151,     8,   156,    11,   156,    13,   156,    17,   188,    23,
     174,    26,   173,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   112,   101,   120,   123,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   151,
     188,   151,   188,   151,   188,   188,   151,    29,   151,   188,
     151,   202,   202,   202,   202,   202,   204,   112,   208,   111,
     188,   111,   111,    91,   111,   111,   188,   188,   188,    19,
     188,   188,    29,    34,    37,    40,    48,    55,    58,    61,
      65,    70,    75,    78,   202,   126,   129,   132,   135,   138,
     141,   144,   147,   150,     8,   156,    11,   156,    13,   156,
      17,    26,   173,   188,    23,   174,   156,   202,   156,     5,
      44,    91,    91,    98,     8,    11,    13,    23,    26,   188,
     188,   188,   188,    29,   188,   103,   205,   105,   207,     8,
      11,    13,    26,    23
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
#line 158 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 162 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 166 "gtkdialog_parser.y"
    { 
    		token_store_attr(PUSH | WIDGET_WINDOW, (yyvsp[(2) - (6)].nvval)); 
		start_up();
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 174 "gtkdialog_parser.y"
    { 
		token_store(SUM);      
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 179 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
	}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 182 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
		token_store(SUM);      
	}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 186 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(2) - (6)].nvval)); 
	}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 189 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(3) - (7)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 193 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
	}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 196 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
		token_store(SUM);      
	}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 200 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(2) - (6)].nvval)); 
	}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 203 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(3) - (7)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 207 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
	}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 210 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
		token_store(SUM);      
	}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 214 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 217 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);      
	}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 221 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(1) - (4)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
	}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 225 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(2) - (5)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
		token_store(SUM);      
	}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 262 "gtkdialog_parser.y"
    {
                          token_store(PUSH | WIDGET_ENTRY); 
			 }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 265 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_ENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 268 "gtkdialog_parser.y"
    {
                  yyerror("</entry> expected instead of <entry>.");}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 273 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_EDIT); 
	}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 276 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_EDIT, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 279 "gtkdialog_parser.y"
    {
    		yyerror("</edit> expected instead of <edit>.");
	}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 285 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TREE); 
	}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 288 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_TREE, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 291 "gtkdialog_parser.y"
    {
   		yyerror("</tree> expected instead of <tree>.");
	}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 297 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHOOSER); 
	}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 300 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_CHOOSER, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 303 "gtkdialog_parser.y"
    {
		yyerror("</chooser> expected instead of <chooser>.");
	}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 309 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TEXT); 
	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 312 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_TEXT, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 315 "gtkdialog_parser.y"
    {yyerror("</text> expected instead of <text>.");}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 319 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_BUTTON);  }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 320 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_BUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 323 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_OKBUTTON);}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 324 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_CANCELBUTTON);}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 325 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_HELPBUTTON);}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 326 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_NOBUTTON);}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 327 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_YESBUTTON);}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 331 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHECKBOX);
	}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 334 "gtkdialog_parser.y"
    {
		//token_store_with_tag_attributes(PUSH | WIDGET_CHECKBOX, $2);
                token_store_attr(PUSH | WIDGET_CHECKBOX, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 338 "gtkdialog_parser.y"
    {
		yyerror("</checkbox> expected instead of <checkbox>.");
	}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 344 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_RADIOBUTTON);
           }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 347 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_RADIOBUTTON, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 350 "gtkdialog_parser.y"
    {
		yyerror("</radiobutton> expected instead of <radiobutton>.");
           }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 356 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_PROGRESS);
           }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 359 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_PROGRESS, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 362 "gtkdialog_parser.y"
    {
		yyerror("</progressbar> expected instead of <progressbar>.");
           }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 368 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_LIST); 
	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 371 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_LIST, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 374 "gtkdialog_parser.y"
    {
    		yyerror("</list> expected instead of <list>.");
	}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 380 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_TABLE);}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 384 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_COMBO);
	}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 387 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_COMBO, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 393 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_GVIM);}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 397 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_PIXMAP);}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 398 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_PIXMAP, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 411 "gtkdialog_parser.y"
    {
		yyerror("The menubar widget requires at least one menu widget.");
	}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 414 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUBAR);
	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 417 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUBAR);
		token_store(SUM);
	}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 421 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUBAR, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 424 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUBAR, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 437 "gtkdialog_parser.y"
    {
		yyerror("The menu widget requires at least one menuitem widget.");
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 440 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENU);
	}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 443 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENU);
		token_store(SUM);
	}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 447 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENU, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 450 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENU, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);
	}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 457 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM);
	}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 460 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM);
		token_store(SUM);
	}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 464 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 467 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(3) - (6)].nvval));
		token_store(SUM);
	}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 474 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEMSEPARATOR);
	}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 477 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEMSEPARATOR);
		token_store(SUM);
	}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 484 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSEPARATOR);
	}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 487 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 493 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSEPARATOR);
	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 496 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 502 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXTEXT);
	}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 505 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXTEXT, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 511 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXENTRY);
	}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 514 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 520 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSCALE);
	}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 523 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSCALE, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 529 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSCALE);
	}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 532 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSCALE, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 538 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_SPINBUTTON);
	}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 541 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_SPINBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 547 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TIMER);
	}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 550 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TIMER, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 556 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TOGGLEBUTTON);
	}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 559 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TOGGLEBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 565 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_STATUSBAR);
	}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 568 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_STATUSBAR, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 574 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COLORBUTTON);
	}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 577 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COLORBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 597 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_LABEL, (yyvsp[(2) - (3)].cval));     }
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 602 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_VARIABLE, (yyvsp[(2) - (3)].cval)); }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 607 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_SENSITIVE, (yyvsp[(2) - (3)].cval));  }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 612 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_DEFAULT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 617 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_WIDTH, (yyvsp[(2) - (3)].cval));    }
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 622 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_HEIGHT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 627 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_SHELL,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 630 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 633 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 636 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 639 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, "", (yyvsp[(2) - (4)].nvval)); 
	}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 645 "gtkdialog_parser.y"
    {
	         fprintf( stderr, "<output>: Not implemented.\n" ); 
	}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 648 "gtkdialog_parser.y"
    {
         	token_store_with_argument(SET|ATTR_OUTPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 654 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET|ATTR_ACTION, (yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 657 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET | ATTR_ACTION, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 664 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET | ATTR_ITEM, (yyvsp[(2) - (3)].cval));
	}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 667 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_ITEM, "");
    	}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 670 "gtkdialog_parser.y"
    {
		      token_store_with_argument_attr(SET | ATTR_ITEM, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
                    }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 676 "gtkdialog_parser.y"
    {
       		(yyval.nvval) = new_tag_attributeset((yyvsp[(1) - (3)].cval), (yyvsp[(3) - (3)].cval)); 
	}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 679 "gtkdialog_parser.y"
    { 
       		(yyval.nvval) = add_tag_attribute((yyvsp[(1) - (4)].nvval), (yyvsp[(2) - (4)].cval), (yyvsp[(4) - (4)].cval)); 
	}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 686 "gtkdialog_parser.y"
    { 
		token_store(SHOW);     
	}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 689 "gtkdialog_parser.y"
    {
  		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
	}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 692 "gtkdialog_parser.y"
    {
		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
		instruction_set_jump((yyvsp[(6) - (6)].ival) + 1, (yyvsp[(1) - (6)].ival));
	}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 699 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMASSG | VARIABLE_NAME, (yyvsp[(1) - (4)].cval)); 
	}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 705 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | VARIABLE_NAME, (yyvsp[(1) - (1)].cval)); 
	}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 708 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | CONST_NUMBER, (yyvsp[(1) - (1)].cval)); 
  	}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 711 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_ADD);
	}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 714 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_SUBST);
	}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 717 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_MULT);
	}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 720 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_DIV);
	}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 723 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_EQ);
	}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 726 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_NE);
	}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 736 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 743 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 747 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 751 "gtkdialog_parser.y"
    {
		token_store(GOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 758 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
    }
    break;



/* Line 1455 of yacc.c  */
#line 3901 "gtkdialog_parser.c"
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
#line 764 "gtkdialog_parser.y"


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


