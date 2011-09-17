
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
     EMENUBAR = 277,
     MENU = 278,
     PART_MENU = 279,
     EMENU = 280,
     MENUITEM = 281,
     PART_MENUITEM = 282,
     EMENUITEM = 283,
     MENUITEMSEPARATOR = 284,
     EMENUITEMSEPARATOR = 285,
     EDIT = 286,
     PART_EDIT = 287,
     EEDIT = 288,
     TREE = 289,
     PART_TREE = 290,
     ETREE = 291,
     CHOOSER = 292,
     PART_CHOOSER = 293,
     ECHOOSER = 294,
     LABEL = 295,
     ELABEL = 296,
     ITEM = 297,
     EITEM = 298,
     PART_ITEM = 299,
     BUTTON = 300,
     PART_BUTTON = 301,
     EBUTTON = 302,
     BUTTONOK = 303,
     BUTTONCANCEL = 304,
     BUTTONHELP = 305,
     BUTTONYES = 306,
     BUTTONNO = 307,
     CHECKBOX = 308,
     ECHECKBOX = 309,
     PART_CHECKBOX = 310,
     RADIO = 311,
     ERADIO = 312,
     PART_RADIO = 313,
     PROGRESS = 314,
     EPROGRESS = 315,
     PART_PROGRESS = 316,
     LIST = 317,
     PART_LIST = 318,
     ELIST = 319,
     TABLE = 320,
     ETABLE = 321,
     COMBO = 322,
     PART_COMBO = 323,
     ECOMBO = 324,
     GVIM = 325,
     EGVIM = 326,
     TEXT = 327,
     PART_TEXT = 328,
     ETEXT = 329,
     PIXMAP = 330,
     PART_PIXMAP = 331,
     EPIXMAP = 332,
     DEFAULT = 333,
     EDEFAULT = 334,
     SENSITIVE = 335,
     ESENSITIVE = 336,
     VARIABLE = 337,
     EVARIABLE = 338,
     WIDTH = 339,
     EWIDTH = 340,
     HEIGHT = 341,
     EHEIGHT = 342,
     INPUT = 343,
     INPUTFILE = 344,
     EINPUT = 345,
     PART_INPUT = 346,
     PART_INPUTFILE = 347,
     OUTPUT = 348,
     OUTPUTFILE = 349,
     EOUTPUT = 350,
     ACTION = 351,
     EACTION = 352,
     PART_ACTION = 353,
     COMM = 354,
     ENDCOMM = 355,
     IF = 356,
     ENDIF = 357,
     WHILE = 358,
     EWHILE = 359,
     SHOW_WIDGETS = 360,
     EMB_VARIABLE = 361,
     EMB_NUMBER = 362,
     END_OF_FILE = 363,
     NUMBER = 364,
     STRING = 365,
     UMINUS = 366,
     HSEPARATOR = 367,
     PART_HSEPARATOR = 368,
     EHSEPARATOR = 369,
     VSEPARATOR = 370,
     PART_VSEPARATOR = 371,
     EVSEPARATOR = 372,
     COMBOBOXTEXT = 373,
     PART_COMBOBOXTEXT = 374,
     ECOMBOBOXTEXT = 375,
     COMBOBOXENTRY = 376,
     PART_COMBOBOXENTRY = 377,
     ECOMBOBOXENTRY = 378,
     HSCALE = 379,
     PART_HSCALE = 380,
     EHSCALE = 381,
     VSCALE = 382,
     PART_VSCALE = 383,
     EVSCALE = 384,
     SPINBUTTON = 385,
     PART_SPINBUTTON = 386,
     ESPINBUTTON = 387,
     TIMER = 388,
     PART_TIMER = 389,
     ETIMER = 390,
     TOGGLEBUTTON = 391,
     PART_TOGGLEBUTTON = 392,
     ETOGGLEBUTTON = 393,
     STATUSBAR = 394,
     PART_STATUSBAR = 395,
     ESTATUSBAR = 396
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
#define EMENUBAR 277
#define MENU 278
#define PART_MENU 279
#define EMENU 280
#define MENUITEM 281
#define PART_MENUITEM 282
#define EMENUITEM 283
#define MENUITEMSEPARATOR 284
#define EMENUITEMSEPARATOR 285
#define EDIT 286
#define PART_EDIT 287
#define EEDIT 288
#define TREE 289
#define PART_TREE 290
#define ETREE 291
#define CHOOSER 292
#define PART_CHOOSER 293
#define ECHOOSER 294
#define LABEL 295
#define ELABEL 296
#define ITEM 297
#define EITEM 298
#define PART_ITEM 299
#define BUTTON 300
#define PART_BUTTON 301
#define EBUTTON 302
#define BUTTONOK 303
#define BUTTONCANCEL 304
#define BUTTONHELP 305
#define BUTTONYES 306
#define BUTTONNO 307
#define CHECKBOX 308
#define ECHECKBOX 309
#define PART_CHECKBOX 310
#define RADIO 311
#define ERADIO 312
#define PART_RADIO 313
#define PROGRESS 314
#define EPROGRESS 315
#define PART_PROGRESS 316
#define LIST 317
#define PART_LIST 318
#define ELIST 319
#define TABLE 320
#define ETABLE 321
#define COMBO 322
#define PART_COMBO 323
#define ECOMBO 324
#define GVIM 325
#define EGVIM 326
#define TEXT 327
#define PART_TEXT 328
#define ETEXT 329
#define PIXMAP 330
#define PART_PIXMAP 331
#define EPIXMAP 332
#define DEFAULT 333
#define EDEFAULT 334
#define SENSITIVE 335
#define ESENSITIVE 336
#define VARIABLE 337
#define EVARIABLE 338
#define WIDTH 339
#define EWIDTH 340
#define HEIGHT 341
#define EHEIGHT 342
#define INPUT 343
#define INPUTFILE 344
#define EINPUT 345
#define PART_INPUT 346
#define PART_INPUTFILE 347
#define OUTPUT 348
#define OUTPUTFILE 349
#define EOUTPUT 350
#define ACTION 351
#define EACTION 352
#define PART_ACTION 353
#define COMM 354
#define ENDCOMM 355
#define IF 356
#define ENDIF 357
#define WHILE 358
#define EWHILE 359
#define SHOW_WIDGETS 360
#define EMB_VARIABLE 361
#define EMB_NUMBER 362
#define END_OF_FILE 363
#define NUMBER 364
#define STRING 365
#define UMINUS 366
#define HSEPARATOR 367
#define PART_HSEPARATOR 368
#define EHSEPARATOR 369
#define VSEPARATOR 370
#define PART_VSEPARATOR 371
#define EVSEPARATOR 372
#define COMBOBOXTEXT 373
#define PART_COMBOBOXTEXT 374
#define ECOMBOBOXTEXT 375
#define COMBOBOXENTRY 376
#define PART_COMBOBOXENTRY 377
#define ECOMBOBOXENTRY 378
#define HSCALE 379
#define PART_HSCALE 380
#define EHSCALE 381
#define VSCALE 382
#define PART_VSCALE 383
#define EVSCALE 384
#define SPINBUTTON 385
#define PART_SPINBUTTON 386
#define ESPINBUTTON 387
#define TIMER 388
#define PART_TIMER 389
#define ETIMER 390
#define TOGGLEBUTTON 391
#define PART_TOGGLEBUTTON 392
#define ETOGGLEBUTTON 393
#define STATUSBAR 394
#define PART_STATUSBAR 395
#define ESTATUSBAR 396




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
#line 486 "gtkdialog_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 498 "gtkdialog_parser.c"

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
#define YYFINAL  100
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4116

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  150
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  173
/* YYNRULES -- Number of states.  */
#define YYNSTATES  467

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   396

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   149,     2,     2,     2,     2,     2,     2,
       2,     2,   114,   113,     2,   112,     2,   115,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   148,     2,
       2,   111,   147,     2,     2,     2,     2,     2,     2,     2,
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
     105,   106,   107,   108,   109,   110,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    11,    18,    20,    23,    25,    28,
      32,    37,    43,    50,    54,    59,    65,    72,    77,    83,
      90,    98,   102,   107,   109,   111,   113,   115,   117,   119,
     121,   123,   125,   127,   129,   131,   133,   135,   137,   139,
     141,   143,   145,   147,   149,   151,   153,   155,   157,   161,
     167,   171,   175,   181,   185,   189,   195,   199,   203,   209,
     213,   217,   223,   227,   231,   237,   241,   245,   249,   253,
     257,   261,   267,   271,   275,   281,   285,   289,   295,   299,
     303,   309,   313,   317,   321,   327,   331,   335,   341,   344,
     348,   350,   352,   354,   357,   362,   368,   375,   383,   387,
     392,   398,   405,   408,   412,   415,   420,   423,   428,   432,
     438,   442,   448,   452,   458,   462,   468,   472,   478,   482,
     488,   492,   498,   502,   508,   509,   512,   515,   518,   521,
     524,   527,   530,   533,   536,   539,   543,   547,   551,   555,
     559,   563,   567,   573,   577,   583,   588,   592,   596,   600,
     606,   610,   613,   619,   623,   628,   633,   635,   642,   649,
     654,   656,   658,   662,   666,   670,   674,   678,   683,   685,
     686,   688,   690,   692
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     151,     0,    -1,   183,   152,    -1,     3,   152,   183,     5,
      -1,     4,   194,   147,   152,   183,     5,    -1,   153,    -1,
     152,   153,    -1,   195,    -1,   152,   195,    -1,     6,   152,
       8,    -1,   152,     6,   152,     8,    -1,     7,   194,   147,
     152,     8,    -1,   152,     7,   194,   147,   152,     8,    -1,
       9,   152,    11,    -1,   152,     9,   152,    11,    -1,    10,
     194,   147,   152,    11,    -1,   152,    10,   194,   147,   152,
      11,    -1,    12,   152,   183,    13,    -1,   152,    12,   152,
     183,    13,    -1,    14,   194,   147,   152,   183,    13,    -1,
     152,    14,   194,   147,   152,   183,    13,    -1,    15,   152,
      17,    -1,   152,    15,   152,    17,    -1,   158,    -1,   154,
      -1,   155,    -1,   156,    -1,   157,    -1,   159,    -1,   160,
      -1,   161,    -1,   162,    -1,   163,    -1,   164,    -1,   165,
      -1,   167,    -1,   166,    -1,   168,    -1,   173,    -1,   174,
      -1,   175,    -1,   176,    -1,   177,    -1,   178,    -1,   179,
      -1,   180,    -1,   181,    -1,   182,    -1,    18,   183,    19,
      -1,    20,   194,   147,   183,    19,    -1,    18,   183,    18,
      -1,    31,   183,    33,    -1,    32,   194,   147,   183,    33,
      -1,    31,   183,    31,    -1,    34,   183,    36,    -1,    35,
     194,   147,   183,    36,    -1,    34,   183,    34,    -1,    37,
     183,    39,    -1,    38,   194,   147,   183,    39,    -1,    37,
     183,    37,    -1,    72,   183,    74,    -1,    73,   194,   147,
     183,    74,    -1,    72,   183,    72,    -1,    45,   183,    47,
      -1,    46,   194,   147,   183,    47,    -1,    48,   183,    47,
      -1,    49,   183,    47,    -1,    50,   183,    47,    -1,    52,
     183,    47,    -1,    51,   183,    47,    -1,    53,   183,    54,
      -1,    55,   194,   147,   183,    54,    -1,    53,   183,    53,
      -1,    56,   183,    57,    -1,    58,   194,   147,   183,    57,
      -1,    56,   183,    56,    -1,    59,   183,    60,    -1,    61,
     194,   147,   183,    60,    -1,    59,   183,    59,    -1,    62,
     183,    64,    -1,    63,   194,   147,   183,    64,    -1,    62,
     183,    62,    -1,    65,   183,    66,    -1,    67,   183,    69,
      -1,    68,   194,   147,   183,    69,    -1,    70,   183,    71,
      -1,    75,   183,    77,    -1,    76,   194,   147,   183,    77,
      -1,    21,    22,    -1,    21,   170,    22,    -1,   170,    -1,
     171,    -1,   172,    -1,    23,    25,    -1,    23,   169,   183,
      25,    -1,   169,    23,   169,   183,    25,    -1,    24,   194,
     147,   169,   183,    25,    -1,   169,    24,   194,   147,   169,
     183,    25,    -1,    26,   183,    28,    -1,   169,    26,   183,
      28,    -1,    27,   194,   147,   183,    28,    -1,   169,    27,
     194,   147,   183,    28,    -1,    29,    30,    -1,   169,    29,
      30,    -1,   117,   119,    -1,   118,   194,   147,   119,    -1,
     120,   122,    -1,   121,   194,   147,   122,    -1,   123,   183,
     125,    -1,   124,   194,   147,   183,   125,    -1,   126,   183,
     128,    -1,   127,   194,   147,   183,   128,    -1,   129,   183,
     131,    -1,   130,   194,   147,   183,   131,    -1,   132,   183,
     134,    -1,   133,   194,   147,   183,   134,    -1,   135,   183,
     137,    -1,   136,   194,   147,   183,   137,    -1,   138,   183,
     140,    -1,   139,   194,   147,   183,   140,    -1,   141,   183,
     143,    -1,   142,   194,   147,   183,   143,    -1,   144,   183,
     146,    -1,   145,   194,   147,   183,   146,    -1,    -1,   183,
     187,    -1,   183,   186,    -1,   183,   185,    -1,   183,   184,
      -1,   183,   188,    -1,   183,   189,    -1,   183,   190,    -1,
     183,   191,    -1,   183,   192,    -1,   183,   193,    -1,    40,
     110,    41,    -1,    82,   110,    83,    -1,    80,   110,    81,
      -1,    78,   110,    79,    -1,    84,   110,    85,    -1,    86,
     110,    87,    -1,    88,   110,    90,    -1,    91,   194,   147,
     110,    90,    -1,    89,   110,    90,    -1,    92,   194,   147,
     110,    90,    -1,    92,   194,   147,    90,    -1,    93,   110,
      95,    -1,    94,   110,    95,    -1,    96,   110,    97,    -1,
      98,   194,   147,   110,    97,    -1,    42,   110,    43,    -1,
      42,    43,    -1,    44,   194,   147,   110,    43,    -1,    16,
     111,   110,    -1,   194,    16,   111,   110,    -1,    99,   196,
     147,   100,    -1,   105,    -1,   198,   197,   147,   199,   152,
     200,    -1,   201,   197,   147,   203,   152,   202,    -1,   106,
     148,   111,   197,    -1,   106,    -1,   107,    -1,   197,   113,
     197,    -1,   197,   112,   197,    -1,   197,   114,   197,    -1,
     197,   115,   197,    -1,   197,   111,   197,    -1,   197,   149,
     111,   197,    -1,   101,    -1,    -1,   102,    -1,   103,    -1,
     104,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   157,   157,   161,   165,   172,   173,   176,   177,   178,
     181,   185,   188,   192,   195,   199,   202,   206,   209,   213,
     216,   220,   224,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   260,   263,
     266,   271,   274,   277,   283,   286,   289,   295,   298,   301,
     307,   310,   313,   317,   318,   321,   322,   323,   324,   325,
     329,   332,   336,   342,   345,   348,   354,   357,   360,   366,
     369,   372,   378,   382,   385,   391,   395,   396,   409,   412,
     418,   419,   420,   424,   427,   430,   434,   437,   444,   447,
     451,   454,   461,   464,   471,   474,   480,   483,   489,   492,
     498,   501,   507,   510,   516,   519,   525,   528,   534,   537,
     543,   546,   552,   555,   560,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   575,   580,   585,   590,   595,
     600,   605,   608,   611,   614,   617,   623,   626,   632,   635,
     642,   645,   648,   654,   657,   663,   664,   667,   670,   677,
     683,   686,   689,   692,   695,   698,   701,   704,   710,   714,
     721,   725,   729,   736
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
  "ENTRY", "EENTRY", "PART_ENTRY", "MENUBAR", "EMENUBAR", "MENU",
  "PART_MENU", "EMENU", "MENUITEM", "PART_MENUITEM", "EMENUITEM",
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
  "PART_STATUSBAR", "ESTATUSBAR", "'>'", "':'", "'!'", "$accept", "window",
  "wlist", "widget", "entry", "edit", "tree", "chooser", "text", "button",
  "checkbox", "radiobutton", "progressbar", "list", "table", "combo",
  "gvim", "pixmap", "menubar", "menuwlist", "menu", "menuitem",
  "menuitemseparator", "hseparator", "vseparator", "comboboxtext",
  "comboboxentry", "hscale", "vscale", "spinbutton", "timer",
  "togglebutton", "statusbar", "attr", "label", "variable", "sensitive",
  "defaultvalue", "width", "height", "input", "output", "action", "item",
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
     365,    61,    45,    43,    42,    47,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,    62,    58,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   150,   151,   151,   151,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   154,   154,
     154,   155,   155,   155,   156,   156,   156,   157,   157,   157,
     158,   158,   158,   159,   159,   159,   159,   159,   159,   159,
     160,   160,   160,   161,   161,   161,   162,   162,   162,   163,
     163,   163,   164,   165,   165,   166,   167,   167,   168,   168,
     169,   169,   169,   170,   170,   170,   170,   170,   171,   171,
     171,   171,   172,   172,   173,   173,   174,   174,   175,   175,
     176,   176,   177,   177,   178,   178,   179,   179,   180,   180,
     181,   181,   182,   182,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   184,   185,   186,   187,   188,
     189,   190,   190,   190,   190,   190,   191,   191,   192,   192,
     193,   193,   193,   194,   194,   195,   195,   195,   195,   196,
     197,   197,   197,   197,   197,   197,   197,   197,   198,   199,
     200,   201,   202,   203
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     6,     1,     2,     1,     2,     3,
       4,     5,     6,     3,     4,     5,     6,     4,     5,     6,
       7,     3,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     5,
       3,     3,     5,     3,     3,     5,     3,     3,     5,     3,
       3,     5,     3,     3,     5,     3,     3,     3,     3,     3,
       3,     5,     3,     3,     5,     3,     3,     5,     3,     3,
       5,     3,     3,     3,     5,     3,     3,     5,     2,     3,
       1,     1,     1,     2,     4,     5,     6,     7,     3,     4,
       5,     6,     2,     3,     2,     4,     2,     4,     3,     5,
       3,     5,     3,     5,     3,     5,     3,     5,     3,     5,
       3,     5,     3,     5,     0,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     5,     3,     5,     4,     3,     3,     3,     5,
       3,     2,     5,     3,     4,     4,     1,     6,     6,     4,
       1,     1,     3,     3,     3,     3,     3,     4,     1,     0,
       1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,     0,     0,   124,     0,   124,     0,   124,
       0,   124,     0,   124,   124,   124,   124,   124,   124,     0,
     124,     0,   124,     0,   124,     0,   124,   124,     0,   124,
     124,     0,   124,     0,     0,   168,   171,   156,     0,     0,
       0,     0,   124,     0,   124,     0,   124,     0,   124,     0,
     124,     0,   124,     0,   124,     0,   124,     0,   124,     5,
      24,    25,    26,    27,    23,    28,    29,    30,    31,    32,
      33,    34,    36,    35,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     7,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,   128,   127,
     126,   125,   129,   130,   131,   132,   133,   134,     0,     0,
       0,     0,   124,     0,     0,     0,     0,    88,     0,     0,
     124,     0,     0,     0,    90,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,     0,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     0,     8,   160,   161,
       0,     0,     0,     0,     0,     0,   151,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,    13,     0,     0,     0,    21,    50,
      48,   124,    93,   124,    90,     0,     0,     0,   102,     0,
       0,   124,     0,     0,    89,    53,    51,   124,    56,    54,
     124,    59,    57,   124,    63,   124,    65,    66,    67,    69,
      68,    72,    70,   124,    75,    73,   124,    78,    76,   124,
      81,    79,   124,    82,    83,   124,    85,    62,    60,   124,
      86,   124,     0,     0,     0,     0,   108,   124,   110,   124,
     112,   124,   114,   124,   116,   124,   118,   124,   120,   124,
     122,   124,     0,     0,     0,     0,   124,     0,     0,     3,
       0,     0,     0,     0,     0,   169,     0,   173,   153,     0,
     124,   135,   150,     0,   138,   137,   136,   139,   140,   141,
     143,     0,     0,   146,   147,   148,     0,     0,     0,    17,
     124,     0,     0,     0,    98,   124,   124,     0,     0,     0,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   155,   105,   107,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,    14,     0,     0,     0,
      22,   166,   163,   162,   164,   165,     0,     0,     0,   154,
       0,     0,     0,   145,     0,     0,    11,    15,     0,    49,
      94,   124,     0,     0,     0,    99,   124,    52,    55,    58,
      64,    71,    74,    77,    80,    84,    61,    87,   159,   109,
     111,   113,   115,   117,   119,   121,   123,     0,     0,    18,
     124,     0,   167,     0,     4,   152,   142,   144,   149,    19,
       0,   100,    95,   124,     0,    12,    16,     0,   170,   157,
     172,   158,    96,     0,   101,    20,    97
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,   143,
     244,   145,   146,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     4,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    99,    95,   177,   210,    96,   396,
     459,    97,   461,   398
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -113
static const yytype_int16 yypact[] =
{
     100,  2430,    48,    66,   610,  2430,    48,  2430,    48,  2430,
      48,  2430,  -113,    48,    85,  -113,    48,  -113,    48,  -113,
      48,  -113,    48,  -113,  -113,  -113,  -113,  -113,  -113,    48,
    -113,    48,  -113,    48,  -113,    48,  -113,  -113,    48,  -113,
    -113,    48,  -113,    48,   -38,  -113,  -113,  -113,   -49,    48,
     -44,    48,  -113,    48,  -113,    48,  -113,    48,  -113,    48,
    -113,    48,  -113,    48,  -113,    48,  -113,    48,  2570,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,    28,    28,   -18,    -6,
    -113,     0,    36,    48,    15,    34,    41,    52,    63,    65,
      67,    48,    48,    69,    71,    73,    48,  2570,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,   750,     1,
     890,     3,  2570,     5,  1030,  3219,     7,  -113,   132,    48,
    -113,    48,    83,   116,    93,  -113,  -113,  3236,    13,  3297,
      16,  3379,    17,  3592,    18,  3614,  3635,  3657,  3678,  3700,
    3451,    19,  3468,    20,  3511,    21,  3532,    22,  3717,  3760,
      23,  3779,  3571,    25,  3801,    27,   -10,     2,  -113,    29,
    -113,    31,  2989,    33,  2934,    35,  2893,    37,  2776,    39,
    2699,    42,  2638,    43,   443,    44,   270,    45,  2430,    48,
    2430,    48,  2430,    48,  2430,  -113,  2850,  -113,  -113,  -113,
     -25,   -17,    75,    76,  2430,   106,  -113,   110,    46,    92,
     107,   115,   129,   130,   126,   128,    47,    49,   124,   125,
     127,    53,  -113,  2430,  -113,  2430,  3006,  2430,  -113,  -113,
    -113,  -113,  -113,   116,  -113,    55,  1309,    56,  -113,   186,
      48,  -113,    48,   191,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,   111,   123,   108,   103,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  1170,    57,  1310,    58,  2570,    59,  1450,  -113,
      28,    28,    28,    28,    28,  -113,   117,  -113,  -113,   133,
    2570,  -113,  -113,   134,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,   136,    -5,  -113,  -113,  -113,   137,  1590,  1730,  -113,
    2570,  3162,   749,   186,  -113,  -113,   116,    60,  1449,    61,
    -113,  3258,  3319,  3396,  3822,  3844,  3877,  3904,  3937,  3963,
    3994,  4018,    28,  -113,  -113,  -113,  3061,  2965,  2910,  2793,
    2716,  2677,   503,   421,  -113,  2430,  -113,  2430,  3078,  2430,
    -113,   -13,   -23,   -23,    77,    77,  2430,    28,  2430,  -113,
    2871,   190,   145,  -113,   146,   140,  -113,  -113,  3121,  -113,
    -113,   116,  1589,   889,   186,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,   -31,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  1870,  2010,  -113,
    2570,  2150,   -13,  2290,  -113,  -113,  -113,  -113,  -113,  -113,
    1029,  -113,  -113,   116,  1729,  -113,  -113,  3138,  -113,  -113,
    -113,  -113,  -113,  1169,  -113,  -113,  -113
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,    -3,   -11,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -112,
     224,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,   -12,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,   437,    -1,  -113,   -66,  -113,  -113,
    -113,  -113,  -113,  -113
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     135,   117,   128,   147,   130,   149,   132,   151,   134,   153,
     213,   155,   156,   157,   158,   159,   160,   213,   162,   213,
     164,   213,   166,   213,   168,   169,   243,   171,   172,   213,
     174,   211,   213,   213,   213,   213,   213,   213,   213,   213,
     182,   213,   184,   213,   186,   213,   188,   213,   190,   213,
     192,   213,   194,   213,   196,   213,   206,   205,   213,   213,
     213,   213,   213,   213,    98,   213,   100,   207,   176,   213,
     178,   213,   213,   213,   213,   213,   213,   213,   180,   216,
     320,   321,   322,   323,   324,   403,   320,   321,   322,   323,
     324,   323,   324,   212,   320,   321,   322,   323,   324,   321,
     322,   323,   324,     1,     2,   404,   205,   137,   138,   139,
     215,   140,   141,   248,   142,   254,   207,   205,   326,   205,
     236,   205,   325,   205,   326,   219,   326,   207,   246,   207,
     327,   207,   326,   207,   208,   209,   326,   356,   292,   249,
     250,   214,   251,   252,   220,   253,   217,   331,   233,   293,
     235,   221,   237,   332,   241,   138,   139,   242,   140,   141,
     257,   142,   222,   260,   263,   265,   273,   276,   279,   282,
     285,   334,   289,   223,   291,   224,   294,   225,   295,   228,
     297,   229,   299,   230,   301,   328,   303,   329,   335,   305,
     307,   309,   311,   333,   341,   312,   342,   314,   336,   316,
     346,   318,   353,   355,   385,   387,   389,   414,   416,   138,
     139,   330,   140,   141,   337,   142,   339,   338,   340,   343,
     344,   360,   372,   373,   345,   375,   326,   374,   397,   351,
     347,   352,   348,   445,   350,   446,   447,   448,   144,   358,
       0,   411,     0,   399,   401,   361,   402,   405,   362,     0,
       0,   363,     0,   364,   391,   392,   393,   394,   395,     0,
       0,   365,     0,     0,   366,     0,     0,   367,     0,     0,
     368,     0,     0,   369,     0,     0,     0,   370,     0,   371,
       0,     0,     0,     0,     0,   376,     0,   377,     0,   378,
       0,   379,     0,   380,     0,   381,     0,   382,     0,   383,
       0,   205,   453,   205,   388,   205,   428,   205,     0,     0,
     101,   207,   102,   207,   103,   207,     0,   207,   400,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
       0,   442,     0,     0,     0,     0,   205,   205,   408,   205,
       0,     0,     0,   412,   413,     0,   207,   207,   104,   207,
     105,     0,   106,     0,   107,     0,   108,     0,   109,   110,
       0,   111,   112,   113,   114,     0,   115,     0,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   437,     0,   438,     0,   440,     0,     0,     0,
       0,     0,     0,   441,     0,   443,     0,     0,     0,   450,
       0,     0,     0,     0,   454,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   310,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   205,   205,   457,   205,
     205,     0,   205,     0,     0,     0,   207,   207,     0,   207,
     207,   463,   207,   129,     0,   131,     0,   133,     0,     0,
     136,     0,     0,   148,     0,   150,     0,   152,     0,   154,
       0,   101,     0,   102,     0,   103,   161,     0,   163,     0,
     165,     0,   167,     0,     0,   170,     0,     0,   173,     0,
     175,     0,     0,   101,     0,   102,   179,   103,   181,     0,
     183,     0,   185,     0,   187,     0,   189,     0,   191,   104,
     193,   105,   195,   106,   197,   107,     0,   108,     0,   109,
     110,     0,   111,   112,   113,   114,     0,   115,     0,   116,
       0,   104,     0,   105,     0,   106,     0,   107,     0,   108,
       0,   109,   110,     0,   111,   112,   113,   114,     0,   115,
     218,   116,     0,   101,     0,   102,     0,   103,   226,   227,
       0,     0,     0,   231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   436,     0,     0,
       0,     0,     0,     0,     0,     0,   245,     0,   247,     0,
       0,   104,     0,   105,     0,   106,   308,   107,     0,   108,
       0,   109,   110,     0,   111,   112,   113,   114,     0,   115,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     0,     7,
       8,     0,     9,     0,    10,    11,     0,     0,    12,     0,
      13,    14,     0,     0,     0,     0,   313,     0,   315,     0,
     317,    15,    16,     0,    17,    18,   435,    19,    20,     0,
     101,     0,   102,     0,   103,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,    31,    32,
       0,    33,    34,    35,     0,    36,     0,    37,    38,     0,
      39,     0,    40,    41,     0,    42,    43,   357,   104,   359,
     105,     0,   106,     0,   107,     0,   108,     0,   109,   110,
       0,   111,   112,   113,   114,     0,   115,     0,   116,    44,
       0,    45,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,     0,    56,
      57,     0,    58,    59,     0,    60,    61,     0,    62,    63,
       0,    64,    65,     0,    66,    67,   198,   199,   232,   200,
     201,     0,   202,     0,   203,   204,     0,     0,    12,     0,
      13,    14,     0,     0,   410,     0,     0,     0,     0,     0,
       0,    15,    16,     0,    17,    18,     0,    19,    20,   101,
       0,   102,     0,   103,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,    31,    32,
       0,    33,    34,    35,     0,    36,     0,    37,    38,     0,
      39,     0,    40,    41,     0,    42,    43,   104,     0,   105,
       0,   106,     0,   107,     0,   108,     0,   109,   110,     0,
     111,   112,   113,   114,     0,   115,     0,   116,     0,    44,
       0,    45,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,     0,    56,
      57,     0,    58,    59,     0,    60,    61,     0,    62,    63,
       0,    64,    65,     0,    66,    67,   198,   199,     0,   200,
     201,   234,   202,     0,   203,   204,     0,     0,    12,     0,
      13,    14,     0,     0,   452,     0,     0,     0,     0,     0,
       0,    15,    16,     0,    17,    18,     0,    19,    20,   101,
       0,   102,     0,   103,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,    31,    32,
       0,    33,    34,    35,     0,    36,     0,    37,    38,     0,
      39,     0,    40,    41,     0,    42,    43,   104,     0,   105,
       0,   106,     0,   107,     0,   108,     0,   109,   110,     0,
     111,   112,   113,   114,     0,   115,     0,   116,     0,    44,
       0,    45,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,     0,    56,
      57,     0,    58,    59,     0,    60,    61,     0,    62,    63,
       0,    64,    65,     0,    66,    67,   198,   199,     0,   200,
     201,     0,   202,     0,   203,   204,     0,   238,    12,     0,
      13,    14,     0,     0,   462,     0,     0,     0,     0,     0,
       0,    15,    16,     0,    17,    18,     0,    19,    20,   101,
       0,   102,     0,   103,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,    31,    32,
       0,    33,    34,    35,     0,    36,     0,    37,    38,     0,
      39,     0,    40,    41,     0,    42,    43,   104,     0,   105,
       0,   106,     0,   107,     0,   108,     0,   109,   110,     0,
     111,   112,   113,   114,     0,   115,     0,   116,     0,    44,
       0,    45,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,     0,    56,
      57,     0,    58,    59,     0,    60,    61,     0,    62,    63,
       0,    64,    65,     0,    66,    67,   198,   199,   384,   200,
     201,     0,   202,     0,   203,   204,     0,     0,    12,     0,
      13,    14,     0,     0,   466,     0,     0,     0,     0,     0,
       0,    15,    16,     0,    17,    18,     0,    19,    20,   101,
       0,   102,     0,   103,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,    31,    32,
       0,    33,    34,    35,     0,    36,     0,    37,    38,     0,
      39,     0,    40,    41,     0,    42,    43,   104,     0,   105,
       0,   106,     0,   107,     0,   108,     0,   109,   110,     0,
     111,   112,   113,   114,     0,   115,     0,   116,     0,    44,
       0,    45,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,     0,    56,
      57,     0,    58,    59,     0,    60,    61,     0,    62,    63,
       0,    64,    65,     0,    66,    67,   198,   199,     0,   200,
     201,   386,   202,     0,   203,   204,     0,     0,    12,     0,
      13,    14,     0,     0,     0,     0,     0,   354,     0,     0,
       0,    15,    16,     0,    17,    18,     0,    19,    20,   101,
       0,   102,     0,   103,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,    31,    32,
       0,    33,    34,    35,     0,    36,     0,    37,    38,     0,
      39,     0,    40,    41,     0,    42,    43,   104,     0,   105,
       0,   106,     0,   107,     0,   108,     0,   109,   110,     0,
     111,   112,   113,   114,     0,   115,     0,   116,     0,    44,
       0,    45,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,     0,    56,
      57,     0,    58,    59,     0,    60,    61,     0,    62,    63,
       0,    64,    65,     0,    66,    67,   198,   199,     0,   200,
     201,     0,   202,     0,   203,   204,     0,   390,    12,     0,
      13,    14,     0,     0,     0,     0,     0,   415,     0,     0,
       0,    15,    16,     0,    17,    18,     0,    19,    20,   101,
       0,   102,     0,   103,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,    31,    32,
       0,    33,    34,    35,     0,    36,     0,    37,    38,     0,
      39,     0,    40,    41,     0,    42,    43,   104,     0,   105,
       0,   106,     0,   107,     0,   108,     0,   109,   110,     0,
     111,   112,   113,   114,     0,   115,     0,   116,     0,    44,
       0,    45,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,     0,    56,
      57,     0,    58,    59,     0,    60,    61,     0,    62,    63,
       0,    64,    65,     0,    66,    67,   198,   199,   406,   200,
     201,     0,   202,     0,   203,   204,     0,     0,    12,     0,
      13,    14,     0,     0,     0,     0,     0,   451,     0,     0,
       0,    15,    16,     0,    17,    18,     0,    19,    20,   101,
       0,   102,     0,   103,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,    31,    32,
       0,    33,    34,    35,     0,    36,     0,    37,    38,     0,
      39,     0,    40,    41,     0,    42,    43,   104,     0,   105,
       0,   106,     0,   107,     0,   108,     0,   109,   110,     0,
     111,   112,   113,   114,     0,   115,     0,   116,     0,    44,
       0,    45,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,     0,    56,
      57,     0,    58,    59,     0,    60,    61,     0,    62,    63,
       0,    64,    65,     0,    66,    67,   198,   199,     0,   200,
     201,   407,   202,     0,   203,   204,     0,     0,    12,     0,
      13,    14,     0,     0,     0,     0,     0,   464,     0,     0,
       0,    15,    16,     0,    17,    18,     0,    19,    20,   101,
       0,   102,     0,   103,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,    31,    32,
       0,    33,    34,    35,     0,    36,     0,    37,    38,     0,
      39,     0,    40,    41,     0,    42,    43,   104,     0,   105,
       0,   106,     0,   107,     0,   108,     0,   109,   110,     0,
     111,   112,   113,   114,     0,   115,     0,   116,     0,    44,
       0,    45,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,     0,    56,
      57,     0,    58,    59,     0,    60,    61,     0,    62,    63,
       0,    64,    65,     0,    66,    67,   198,   199,   455,   200,
     201,     0,   202,     0,   203,   204,     0,     0,    12,     0,
      13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    16,     0,    17,    18,     0,    19,    20,     0,
       0,     0,     0,     0,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,    31,    32,
       0,    33,    34,    35,     0,    36,     0,    37,    38,     0,
      39,     0,    40,    41,     0,    42,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,    45,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,     0,    56,
      57,     0,    58,    59,     0,    60,    61,     0,    62,    63,
       0,    64,    65,     0,    66,    67,   198,   199,     0,   200,
     201,   456,   202,     0,   203,   204,     0,     0,    12,     0,
      13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    16,     0,    17,    18,     0,    19,    20,     0,
       0,     0,     0,     0,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,    31,    32,
       0,    33,    34,    35,     0,    36,     0,    37,    38,     0,
      39,     0,    40,    41,     0,    42,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,    45,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,     0,    56,
      57,     0,    58,    59,     0,    60,    61,     0,    62,    63,
       0,    64,    65,     0,    66,    67,   198,   199,     0,   200,
     201,     0,   202,     0,   203,   204,     0,     0,    12,     0,
      13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    16,     0,    17,    18,     0,    19,    20,     0,
       0,     0,     0,     0,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,    31,    32,
       0,    33,    34,    35,     0,    36,     0,    37,    38,     0,
      39,     0,    40,    41,     0,    42,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,    45,   458,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,     0,    56,
      57,     0,    58,    59,     0,    60,    61,     0,    62,    63,
       0,    64,    65,     0,    66,    67,   198,   199,     0,   200,
     201,     0,   202,     0,   203,   204,     0,     0,    12,     0,
      13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    16,     0,    17,    18,     0,    19,    20,     0,
       0,     0,     0,     0,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,    31,    32,
       0,    33,    34,    35,     0,    36,     0,    37,    38,     0,
      39,     0,    40,    41,     0,    42,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,    45,     0,    46,   460,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,     0,    56,
      57,     0,    58,    59,     0,    60,    61,     0,    62,    63,
       0,    64,    65,     0,    66,    67,     5,     6,     0,     7,
       8,     0,     9,     0,    10,    11,     0,     0,    12,     0,
      13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    16,     0,    17,    18,     0,    19,    20,     0,
       0,     0,     0,     0,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,    31,    32,
       0,    33,    34,    35,     0,    36,     0,    37,    38,     0,
      39,     0,    40,    41,     0,    42,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,    45,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,     0,    56,
      57,     0,    58,    59,     0,    60,    61,     0,    62,    63,
       0,    64,    65,     0,    66,    67,   198,   199,     0,   200,
     201,     0,   202,     0,   203,   204,     0,     0,    12,     0,
      13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    16,     0,    17,    18,     0,    19,    20,     0,
       0,     0,     0,     0,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,    31,    32,
       0,    33,    34,    35,     0,    36,     0,    37,    38,     0,
      39,     0,    40,    41,     0,    42,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,    45,     0,    46,     0,    47,     0,     0,   101,     0,
     102,     0,   103,     0,     0,     0,     0,    48,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,     0,    56,
      57,     0,    58,    59,     0,    60,    61,     0,    62,    63,
       0,    64,    65,     0,    66,    67,   104,   101,   105,   102,
     106,   103,   107,     0,   108,     0,   109,   110,     0,   111,
     112,   113,   114,     0,   115,     0,   116,     0,     0,   101,
       0,   102,     0,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   101,   105,   102,   106,
     103,   107,     0,   108,     0,   109,   110,     0,   111,   112,
     113,   114,     0,   115,     0,   116,     0,   104,   306,   105,
       0,   106,     0,   107,     0,   108,     0,   109,   110,     0,
     111,   112,   113,   114,   104,   115,   105,   116,   106,     0,
     107,     0,   108,     0,   109,   110,     0,   111,   112,   113,
     114,     0,   115,     0,   116,     0,   101,   434,   102,     0,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   101,     0,   102,   304,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   433,   104,   319,   105,     0,   106,     0,
     107,     0,   108,     0,   109,   110,     0,   111,   112,   113,
     114,   104,   115,   105,   116,   106,   444,   107,     0,   108,
       0,   109,   110,     0,   111,   112,   113,   114,     0,   115,
     101,   116,   102,     0,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     302,   101,     0,   102,     0,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   432,   104,     0,
     105,     0,   106,   101,   107,   102,   108,   103,   109,   110,
       0,   111,   112,   113,   114,     0,   115,     0,   116,   104,
     101,   105,   102,   106,   103,   107,     0,   108,     0,   109,
     110,     0,   111,   112,   113,   114,     0,   115,     0,   116,
       0,   104,     0,   105,   101,   106,   102,   107,   103,   108,
       0,   109,   110,     0,   111,   112,   113,   114,   104,   115,
     105,   116,   106,     0,   107,     0,   108,     0,   109,   110,
       0,   111,   112,   113,   114,   101,   115,   102,   116,   103,
       0,     0,   104,     0,   105,     0,   106,     0,   107,   349,
     108,     0,   109,   110,   300,   111,   112,   113,   114,   101,
     115,   102,   116,   103,     0,     0,     0,     0,     0,     0,
       0,   431,     0,   104,     0,   105,   101,   106,   102,   107,
     103,   108,     0,   109,   110,     0,   111,   112,   113,   114,
       0,   115,   298,   116,     0,     0,     0,   104,     0,   105,
       0,   106,     0,   107,     0,   108,     0,   109,   110,     0,
     111,   112,   113,   114,   104,   115,   105,   116,   106,     0,
     107,   439,   108,   430,   109,   110,     0,   111,   112,   113,
     114,   101,   115,   102,   116,   103,     0,     0,     0,     0,
       0,     0,     0,     0,   296,     0,     0,     0,   101,     0,
     102,     0,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   449,     0,     0,     0,     0,   104,
       0,   105,     0,   106,     0,   107,     0,   108,     0,   109,
     110,   465,   111,   112,   113,   114,   104,   115,   105,   116,
     106,   101,   107,   102,   108,   103,   109,   110,     0,   111,
     112,   113,   114,     0,   115,     0,   116,     0,   101,     0,
     102,   409,   103,     0,     0,     0,   429,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
       0,   105,   101,   106,   102,   107,   103,   108,     0,   109,
     110,     0,   111,   112,   113,   114,   104,   115,   105,   116,
     106,     0,   107,     0,   108,     0,   109,   110,     0,   111,
     112,   113,   114,     0,   115,     0,   116,   239,   240,     0,
     104,     0,   105,     0,   106,     0,   107,     0,   108,     0,
     109,   110,     0,   111,   112,   113,   114,     0,   115,   101,
     116,   102,     0,   103,     0,     0,     0,   255,     0,   256,
       0,     0,     0,     0,     0,     0,   101,     0,   102,     0,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   417,     0,     0,     0,     0,     0,   104,   101,   105,
     102,   106,   103,   107,     0,   108,     0,   109,   110,     0,
     111,   112,   113,   114,   104,   115,   105,   116,   106,     0,
     107,     0,   108,     0,   109,   110,     0,   111,   112,   113,
     114,   258,   115,   259,   116,     0,   104,   101,   105,   102,
     106,   103,   107,     0,   108,     0,   109,   110,     0,   111,
     112,   113,   114,     0,   115,   418,   116,     0,     0,   101,
       0,   102,     0,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,     0,   105,     0,   106,
       0,   107,     0,   108,     0,   109,   110,     0,   111,   112,
     113,   114,     0,   115,     0,   116,     0,   104,     0,   105,
       0,   106,     0,   107,     0,   108,     0,   109,   110,     0,
     111,   112,   113,   114,     0,   115,   261,   116,   262,   101,
       0,   102,     0,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   419,   101,     0,   102,     0,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,     0,   105,
       0,   106,     0,   107,     0,   108,     0,   109,   110,     0,
     111,   112,   113,   114,   104,   115,   105,   116,   106,     0,
     107,     0,   108,     0,   109,   110,     0,   111,   112,   113,
     114,   101,   115,   102,   116,   103,     0,     0,     0,     0,
       0,     0,     0,     0,   271,   272,     0,     0,   101,     0,
     102,     0,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   274,   275,     0,     0,     0,   104,
       0,   105,     0,   106,     0,   107,     0,   108,     0,   109,
     110,     0,   111,   112,   113,   114,   104,   115,   105,   116,
     106,   101,   107,   102,   108,   103,   109,   110,     0,   111,
     112,   113,   114,     0,   115,     0,   116,     0,     0,     0,
     277,   278,   101,     0,   102,     0,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
       0,   105,     0,   106,   280,   107,   281,   108,     0,   109,
     110,     0,   111,   112,   113,   114,     0,   115,     0,   116,
     104,   101,   105,   102,   106,   103,   107,     0,   108,     0,
     109,   110,     0,   111,   112,   113,   114,     0,   115,     0,
     116,     0,   101,     0,   102,     0,   103,     0,     0,   264,
       0,     0,     0,   287,     0,   288,     0,     0,     0,   104,
       0,   105,     0,   106,   101,   107,   102,   108,   103,   109,
     110,   266,   111,   112,   113,   114,     0,   115,     0,   116,
     104,     0,   105,     0,   106,   101,   107,   102,   108,   103,
     109,   110,   267,   111,   112,   113,   114,     0,   115,     0,
     116,     0,   104,     0,   105,     0,   106,   101,   107,   102,
     108,   103,   109,   110,   268,   111,   112,   113,   114,     0,
     115,     0,   116,   104,     0,   105,     0,   106,   101,   107,
     102,   108,   103,   109,   110,   269,   111,   112,   113,   114,
       0,   115,     0,   116,     0,   104,     0,   105,     0,   106,
     101,   107,   102,   108,   103,   109,   110,   270,   111,   112,
     113,   114,     0,   115,     0,   116,   104,   101,   105,   102,
     106,   103,   107,     0,   108,     0,   109,   110,     0,   111,
     112,   113,   114,     0,   115,     0,   116,     0,   104,     0,
     105,     0,   106,   283,   107,     0,   108,     0,   109,   110,
       0,   111,   112,   113,   114,   104,   115,   105,   116,   106,
     101,   107,   102,   108,   103,   109,   110,     0,   111,   112,
     113,   114,     0,   115,     0,   116,     0,     0,     0,   101,
       0,   102,     0,   103,     0,     0,     0,     0,     0,   284,
       0,     0,     0,     0,     0,     0,     0,     0,   104,     0,
     105,   101,   106,   102,   107,   103,   108,     0,   109,   110,
     286,   111,   112,   113,   114,     0,   115,   104,   116,   105,
       0,   106,   101,   107,   102,   108,   103,   109,   110,   420,
     111,   112,   113,   114,     0,   115,     0,   116,   290,   104,
       0,   105,     0,   106,   101,   107,   102,   108,   103,   109,
     110,     0,   111,   112,   113,   114,     0,   115,   421,   116,
     104,     0,   105,     0,   106,     0,   107,     0,   108,     0,
     109,   110,     0,   111,   112,   113,   114,   101,   115,   102,
     116,   103,   104,     0,   105,     0,   106,     0,   107,     0,
     108,     0,   109,   110,   422,   111,   112,   113,   114,     0,
     115,     0,   116,     0,   101,     0,   102,     0,   103,     0,
       0,     0,     0,     0,     0,   104,     0,   105,     0,   106,
       0,   107,     0,   108,   423,   109,   110,     0,   111,   112,
     113,   114,     0,   115,     0,   116,     0,   101,     0,   102,
       0,   103,   104,     0,   105,     0,   106,     0,   107,     0,
     108,     0,   109,   110,     0,   111,   112,   113,   114,     0,
     115,   424,   116,   101,     0,   102,     0,   103,     0,     0,
       0,     0,     0,     0,     0,   104,     0,   105,     0,   106,
       0,   107,     0,   108,     0,   109,   110,     0,   111,   112,
     113,   114,   425,   115,   101,   116,   102,     0,   103,     0,
       0,   104,     0,   105,     0,   106,     0,   107,     0,   108,
       0,   109,   110,     0,   111,   112,   113,   114,   101,   115,
     102,   116,   103,     0,     0,     0,     0,     0,   426,     0,
       0,     0,   104,     0,   105,     0,   106,     0,   107,     0,
     108,     0,   109,   110,     0,   111,   112,   113,   114,     0,
     115,     0,   116,     0,     0,   427,   104,     0,   105,     0,
     106,     0,   107,     0,   108,     0,   109,   110,     0,   111,
     112,   113,   114,     0,   115,     0,   116
};

static const yytype_int16 yycheck[] =
{
      12,     4,     5,    15,     7,    17,     9,    19,    11,    21,
      16,    23,    24,    25,    26,    27,    28,    16,    30,    16,
      32,    16,    34,    16,    36,    37,   138,    39,    40,    16,
      42,    97,    16,    16,    16,    16,    16,    16,    16,    16,
      52,    16,    54,    16,    56,    16,    58,    16,    60,    16,
      62,    16,    64,    16,    66,    16,    68,    68,    16,    16,
      16,    16,    16,    16,    16,    16,     0,    68,   106,    16,
     119,    16,    16,    16,    16,    16,    16,    16,   122,    43,
     111,   112,   113,   114,   115,    90,   111,   112,   113,   114,
     115,   114,   115,   111,   111,   112,   113,   114,   115,   112,
     113,   114,   115,     3,     4,   110,   117,    22,    23,    24,
     110,    26,    27,    30,    29,    22,   117,   128,   149,   130,
     132,   132,   147,   134,   149,   110,   149,   128,   140,   130,
     147,   132,   149,   134,   106,   107,   149,   249,   148,    23,
      24,   147,    26,    27,   110,    29,   110,    41,   147,   147,
     147,   110,   147,    43,   147,    23,    24,    25,    26,    27,
     147,    29,   110,   147,   147,   147,   147,   147,   147,   147,
     147,    79,   147,   110,   147,   110,   147,   110,   147,   110,
     147,   110,   147,   110,   147,   110,   147,   111,    81,   147,
     147,   147,   147,   147,   147,   198,   147,   200,    83,   202,
     147,   204,   147,   147,   147,   147,   147,   147,   147,    23,
      24,   214,    26,    27,    85,    29,    90,    87,    90,    95,
      95,    30,   111,   100,    97,   122,   149,   119,   111,   241,
     233,   243,   235,    43,   237,    90,    90,    97,    14,   251,
      -1,   353,    -1,   110,   110,   257,   110,   110,   260,    -1,
      -1,   263,    -1,   265,   320,   321,   322,   323,   324,    -1,
      -1,   273,    -1,    -1,   276,    -1,    -1,   279,    -1,    -1,
     282,    -1,    -1,   285,    -1,    -1,    -1,   289,    -1,   291,
      -1,    -1,    -1,    -1,    -1,   297,    -1,   299,    -1,   301,
      -1,   303,    -1,   305,    -1,   307,    -1,   309,    -1,   311,
      -1,   312,   414,   314,   316,   316,   372,   318,    -1,    -1,
      40,   312,    42,   314,    44,   316,    -1,   318,   330,   330,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   330,
      -1,   397,    -1,    -1,    -1,    -1,   347,   348,   350,   350,
      -1,    -1,    -1,   355,   356,    -1,   347,   348,    78,   350,
      80,    -1,    82,    -1,    84,    -1,    86,    -1,    88,    89,
      -1,    91,    92,    93,    94,    -1,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   385,    -1,   387,    -1,   389,    -1,    -1,    -1,
      -1,    -1,    -1,   396,    -1,   398,    -1,    -1,    -1,   411,
      -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   437,   438,   440,   440,
     441,    -1,   443,    -1,    -1,    -1,   437,   438,    -1,   440,
     441,   453,   443,     6,    -1,     8,    -1,    10,    -1,    -1,
      13,    -1,    -1,    16,    -1,    18,    -1,    20,    -1,    22,
      -1,    40,    -1,    42,    -1,    44,    29,    -1,    31,    -1,
      33,    -1,    35,    -1,    -1,    38,    -1,    -1,    41,    -1,
      43,    -1,    -1,    40,    -1,    42,    49,    44,    51,    -1,
      53,    -1,    55,    -1,    57,    -1,    59,    -1,    61,    78,
      63,    80,    65,    82,    67,    84,    -1,    86,    -1,    88,
      89,    -1,    91,    92,    93,    94,    -1,    96,    -1,    98,
      -1,    78,    -1,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    89,    -1,    91,    92,    93,    94,    -1,    96,
     103,    98,    -1,    40,    -1,    42,    -1,    44,   111,   112,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,   141,    -1,
      -1,    78,    -1,    80,    -1,    82,   143,    84,    -1,    86,
      -1,    88,    89,    -1,    91,    92,    93,    94,    -1,    96,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,     9,
      10,    -1,    12,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,   199,    -1,   201,    -1,
     203,    31,    32,    -1,    34,    35,   143,    37,    38,    -1,
      40,    -1,    42,    -1,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    67,    68,    -1,
      70,    -1,    72,    73,    -1,    75,    76,   250,    78,   252,
      80,    -1,    82,    -1,    84,    -1,    86,    -1,    88,    89,
      -1,    91,    92,    93,    94,    -1,    96,    -1,    98,    99,
      -1,   101,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
     120,   121,    -1,   123,   124,    -1,   126,   127,    -1,   129,
     130,    -1,   132,   133,    -1,   135,   136,    -1,   138,   139,
      -1,   141,   142,    -1,   144,   145,     6,     7,     8,     9,
      10,    -1,    12,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    -1,    37,    38,    40,
      -1,    42,    -1,    44,    -1,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    67,    68,    -1,
      70,    -1,    72,    73,    -1,    75,    76,    78,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    -1,    96,    -1,    98,    -1,    99,
      -1,   101,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
     120,   121,    -1,   123,   124,    -1,   126,   127,    -1,   129,
     130,    -1,   132,   133,    -1,   135,   136,    -1,   138,   139,
      -1,   141,   142,    -1,   144,   145,     6,     7,    -1,     9,
      10,    11,    12,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    -1,    37,    38,    40,
      -1,    42,    -1,    44,    -1,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    67,    68,    -1,
      70,    -1,    72,    73,    -1,    75,    76,    78,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    -1,    96,    -1,    98,    -1,    99,
      -1,   101,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
     120,   121,    -1,   123,   124,    -1,   126,   127,    -1,   129,
     130,    -1,   132,   133,    -1,   135,   136,    -1,   138,   139,
      -1,   141,   142,    -1,   144,   145,     6,     7,    -1,     9,
      10,    -1,    12,    -1,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    -1,    37,    38,    40,
      -1,    42,    -1,    44,    -1,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    67,    68,    -1,
      70,    -1,    72,    73,    -1,    75,    76,    78,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    -1,    96,    -1,    98,    -1,    99,
      -1,   101,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
     120,   121,    -1,   123,   124,    -1,   126,   127,    -1,   129,
     130,    -1,   132,   133,    -1,   135,   136,    -1,   138,   139,
      -1,   141,   142,    -1,   144,   145,     6,     7,     8,     9,
      10,    -1,    12,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    -1,    37,    38,    40,
      -1,    42,    -1,    44,    -1,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    67,    68,    -1,
      70,    -1,    72,    73,    -1,    75,    76,    78,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    -1,    96,    -1,    98,    -1,    99,
      -1,   101,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
     120,   121,    -1,   123,   124,    -1,   126,   127,    -1,   129,
     130,    -1,   132,   133,    -1,   135,   136,    -1,   138,   139,
      -1,   141,   142,    -1,   144,   145,     6,     7,    -1,     9,
      10,    11,    12,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    -1,    37,    38,    40,
      -1,    42,    -1,    44,    -1,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    67,    68,    -1,
      70,    -1,    72,    73,    -1,    75,    76,    78,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    -1,    96,    -1,    98,    -1,    99,
      -1,   101,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
     120,   121,    -1,   123,   124,    -1,   126,   127,    -1,   129,
     130,    -1,   132,   133,    -1,   135,   136,    -1,   138,   139,
      -1,   141,   142,    -1,   144,   145,     6,     7,    -1,     9,
      10,    -1,    12,    -1,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    -1,    37,    38,    40,
      -1,    42,    -1,    44,    -1,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    67,    68,    -1,
      70,    -1,    72,    73,    -1,    75,    76,    78,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    -1,    96,    -1,    98,    -1,    99,
      -1,   101,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
     120,   121,    -1,   123,   124,    -1,   126,   127,    -1,   129,
     130,    -1,   132,   133,    -1,   135,   136,    -1,   138,   139,
      -1,   141,   142,    -1,   144,   145,     6,     7,     8,     9,
      10,    -1,    12,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    -1,    37,    38,    40,
      -1,    42,    -1,    44,    -1,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    67,    68,    -1,
      70,    -1,    72,    73,    -1,    75,    76,    78,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    -1,    96,    -1,    98,    -1,    99,
      -1,   101,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
     120,   121,    -1,   123,   124,    -1,   126,   127,    -1,   129,
     130,    -1,   132,   133,    -1,   135,   136,    -1,   138,   139,
      -1,   141,   142,    -1,   144,   145,     6,     7,    -1,     9,
      10,    11,    12,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    -1,    37,    38,    40,
      -1,    42,    -1,    44,    -1,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    67,    68,    -1,
      70,    -1,    72,    73,    -1,    75,    76,    78,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    -1,    96,    -1,    98,    -1,    99,
      -1,   101,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
     120,   121,    -1,   123,   124,    -1,   126,   127,    -1,   129,
     130,    -1,   132,   133,    -1,   135,   136,    -1,   138,   139,
      -1,   141,   142,    -1,   144,   145,     6,     7,     8,     9,
      10,    -1,    12,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    67,    68,    -1,
      70,    -1,    72,    73,    -1,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,   101,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
     120,   121,    -1,   123,   124,    -1,   126,   127,    -1,   129,
     130,    -1,   132,   133,    -1,   135,   136,    -1,   138,   139,
      -1,   141,   142,    -1,   144,   145,     6,     7,    -1,     9,
      10,    11,    12,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    67,    68,    -1,
      70,    -1,    72,    73,    -1,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,   101,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
     120,   121,    -1,   123,   124,    -1,   126,   127,    -1,   129,
     130,    -1,   132,   133,    -1,   135,   136,    -1,   138,   139,
      -1,   141,   142,    -1,   144,   145,     6,     7,    -1,     9,
      10,    -1,    12,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    67,    68,    -1,
      70,    -1,    72,    73,    -1,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,   101,   102,   103,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
     120,   121,    -1,   123,   124,    -1,   126,   127,    -1,   129,
     130,    -1,   132,   133,    -1,   135,   136,    -1,   138,   139,
      -1,   141,   142,    -1,   144,   145,     6,     7,    -1,     9,
      10,    -1,    12,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    67,    68,    -1,
      70,    -1,    72,    73,    -1,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,   101,    -1,   103,   104,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
     120,   121,    -1,   123,   124,    -1,   126,   127,    -1,   129,
     130,    -1,   132,   133,    -1,   135,   136,    -1,   138,   139,
      -1,   141,   142,    -1,   144,   145,     6,     7,    -1,     9,
      10,    -1,    12,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    67,    68,    -1,
      70,    -1,    72,    73,    -1,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,   101,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
     120,   121,    -1,   123,   124,    -1,   126,   127,    -1,   129,
     130,    -1,   132,   133,    -1,   135,   136,    -1,   138,   139,
      -1,   141,   142,    -1,   144,   145,     6,     7,    -1,     9,
      10,    -1,    12,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    67,    68,    -1,
      70,    -1,    72,    73,    -1,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,   101,    -1,   103,    -1,   105,    -1,    -1,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,   117,   118,    -1,
     120,   121,    -1,   123,   124,    -1,   126,   127,    -1,   129,
     130,    -1,   132,   133,    -1,   135,   136,    -1,   138,   139,
      -1,   141,   142,    -1,   144,   145,    78,    40,    80,    42,
      82,    44,    84,    -1,    86,    -1,    88,    89,    -1,    91,
      92,    93,    94,    -1,    96,    -1,    98,    -1,    -1,    40,
      -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    40,    80,    42,    82,
      44,    84,    -1,    86,    -1,    88,    89,    -1,    91,    92,
      93,    94,    -1,    96,    -1,    98,    -1,    78,   140,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    78,    96,    80,    98,    82,    -1,
      84,    -1,    86,    -1,    88,    89,    -1,    91,    92,    93,
      94,    -1,    96,    -1,    98,    -1,    40,   140,    42,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    42,   137,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,    78,     5,    80,    -1,    82,    -1,
      84,    -1,    86,    -1,    88,    89,    -1,    91,    92,    93,
      94,    78,    96,    80,    98,    82,     5,    84,    -1,    86,
      -1,    88,    89,    -1,    91,    92,    93,    94,    -1,    96,
      40,    98,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     134,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,    78,    -1,
      80,    -1,    82,    40,    84,    42,    86,    44,    88,    89,
      -1,    91,    92,    93,    94,    -1,    96,    -1,    98,    78,
      40,    80,    42,    82,    44,    84,    -1,    86,    -1,    88,
      89,    -1,    91,    92,    93,    94,    -1,    96,    -1,    98,
      -1,    78,    -1,    80,    40,    82,    42,    84,    44,    86,
      -1,    88,    89,    -1,    91,    92,    93,    94,    78,    96,
      80,    98,    82,    -1,    84,    -1,    86,    -1,    88,    89,
      -1,    91,    92,    93,    94,    40,    96,    42,    98,    44,
      -1,    -1,    78,    -1,    80,    -1,    82,    -1,    84,    13,
      86,    -1,    88,    89,   131,    91,    92,    93,    94,    40,
      96,    42,    98,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    78,    -1,    80,    40,    82,    42,    84,
      44,    86,    -1,    88,    89,    -1,    91,    92,    93,    94,
      -1,    96,   128,    98,    -1,    -1,    -1,    78,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    78,    96,    80,    98,    82,    -1,
      84,    13,    86,   128,    88,    89,    -1,    91,    92,    93,
      94,    40,    96,    42,    98,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    78,
      -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,    88,
      89,    13,    91,    92,    93,    94,    78,    96,    80,    98,
      82,    40,    84,    42,    86,    44,    88,    89,    -1,    91,
      92,    93,    94,    -1,    96,    -1,    98,    -1,    40,    -1,
      42,    19,    44,    -1,    -1,    -1,   125,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    80,    40,    82,    42,    84,    44,    86,    -1,    88,
      89,    -1,    91,    92,    93,    94,    78,    96,    80,    98,
      82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,    91,
      92,    93,    94,    -1,    96,    -1,    98,    18,    19,    -1,
      78,    -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,
      88,    89,    -1,    91,    92,    93,    94,    -1,    96,    40,
      98,    42,    -1,    44,    -1,    -1,    -1,    31,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    42,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    78,    40,    80,
      42,    82,    44,    84,    -1,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    78,    96,    80,    98,    82,    -1,
      84,    -1,    86,    -1,    88,    89,    -1,    91,    92,    93,
      94,    34,    96,    36,    98,    -1,    78,    40,    80,    42,
      82,    44,    84,    -1,    86,    -1,    88,    89,    -1,    91,
      92,    93,    94,    -1,    96,    36,    98,    -1,    -1,    40,
      -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,    82,
      -1,    84,    -1,    86,    -1,    88,    89,    -1,    91,    92,
      93,    94,    -1,    96,    -1,    98,    -1,    78,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    -1,    96,    37,    98,    39,    40,
      -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    -1,    42,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    78,    96,    80,    98,    82,    -1,
      84,    -1,    86,    -1,    88,    89,    -1,    91,    92,    93,
      94,    40,    96,    42,    98,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    -1,    -1,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    -1,    -1,    -1,    78,
      -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,    88,
      89,    -1,    91,    92,    93,    94,    78,    96,    80,    98,
      82,    40,    84,    42,    86,    44,    88,    89,    -1,    91,
      92,    93,    94,    -1,    96,    -1,    98,    -1,    -1,    -1,
      59,    60,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    80,    -1,    82,    62,    84,    64,    86,    -1,    88,
      89,    -1,    91,    92,    93,    94,    -1,    96,    -1,    98,
      78,    40,    80,    42,    82,    44,    84,    -1,    86,    -1,
      88,    89,    -1,    91,    92,    93,    94,    -1,    96,    -1,
      98,    -1,    40,    -1,    42,    -1,    44,    -1,    -1,    47,
      -1,    -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    78,
      -1,    80,    -1,    82,    40,    84,    42,    86,    44,    88,
      89,    47,    91,    92,    93,    94,    -1,    96,    -1,    98,
      78,    -1,    80,    -1,    82,    40,    84,    42,    86,    44,
      88,    89,    47,    91,    92,    93,    94,    -1,    96,    -1,
      98,    -1,    78,    -1,    80,    -1,    82,    40,    84,    42,
      86,    44,    88,    89,    47,    91,    92,    93,    94,    -1,
      96,    -1,    98,    78,    -1,    80,    -1,    82,    40,    84,
      42,    86,    44,    88,    89,    47,    91,    92,    93,    94,
      -1,    96,    -1,    98,    -1,    78,    -1,    80,    -1,    82,
      40,    84,    42,    86,    44,    88,    89,    47,    91,    92,
      93,    94,    -1,    96,    -1,    98,    78,    40,    80,    42,
      82,    44,    84,    -1,    86,    -1,    88,    89,    -1,    91,
      92,    93,    94,    -1,    96,    -1,    98,    -1,    78,    -1,
      80,    -1,    82,    66,    84,    -1,    86,    -1,    88,    89,
      -1,    91,    92,    93,    94,    78,    96,    80,    98,    82,
      40,    84,    42,    86,    44,    88,    89,    -1,    91,    92,
      93,    94,    -1,    96,    -1,    98,    -1,    -1,    -1,    40,
      -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      80,    40,    82,    42,    84,    44,    86,    -1,    88,    89,
      71,    91,    92,    93,    94,    -1,    96,    78,    98,    80,
      -1,    82,    40,    84,    42,    86,    44,    88,    89,    47,
      91,    92,    93,    94,    -1,    96,    -1,    98,    77,    78,
      -1,    80,    -1,    82,    40,    84,    42,    86,    44,    88,
      89,    -1,    91,    92,    93,    94,    -1,    96,    54,    98,
      78,    -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,
      88,    89,    -1,    91,    92,    93,    94,    40,    96,    42,
      98,    44,    78,    -1,    80,    -1,    82,    -1,    84,    -1,
      86,    -1,    88,    89,    57,    91,    92,    93,    94,    -1,
      96,    -1,    98,    -1,    40,    -1,    42,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,    82,
      -1,    84,    -1,    86,    60,    88,    89,    -1,    91,    92,
      93,    94,    -1,    96,    -1,    98,    -1,    40,    -1,    42,
      -1,    44,    78,    -1,    80,    -1,    82,    -1,    84,    -1,
      86,    -1,    88,    89,    -1,    91,    92,    93,    94,    -1,
      96,    64,    98,    40,    -1,    42,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,    82,
      -1,    84,    -1,    86,    -1,    88,    89,    -1,    91,    92,
      93,    94,    69,    96,    40,    98,    42,    -1,    44,    -1,
      -1,    78,    -1,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    89,    -1,    91,    92,    93,    94,    40,    96,
      42,    98,    44,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    78,    -1,    80,    -1,    82,    -1,    84,    -1,
      86,    -1,    88,    89,    -1,    91,    92,    93,    94,    -1,
      96,    -1,    98,    -1,    -1,    77,    78,    -1,    80,    -1,
      82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,    91,
      92,    93,    94,    -1,    96,    -1,    98
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,   151,   183,     6,     7,     9,    10,    12,
      14,    15,    18,    20,    21,    31,    32,    34,    35,    37,
      38,    45,    46,    48,    49,    50,    51,    52,    53,    55,
      56,    58,    59,    61,    62,    63,    65,    67,    68,    70,
      72,    73,    75,    76,    99,   101,   103,   105,   117,   118,
     120,   121,   123,   124,   126,   127,   129,   130,   132,   133,
     135,   136,   138,   139,   141,   142,   144,   145,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   195,   198,   201,    16,   194,
       0,    40,    42,    44,    78,    80,    82,    84,    86,    88,
      89,    91,    92,    93,    94,    96,    98,   152,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   152,   194,
     152,   194,   152,   194,   152,   183,   194,    22,    23,    24,
      26,    27,    29,   169,   170,   171,   172,   183,   194,   183,
     194,   183,   194,   183,   194,   183,   183,   183,   183,   183,
     183,   194,   183,   194,   183,   194,   183,   194,   183,   183,
     194,   183,   183,   194,   183,   194,   106,   196,   119,   194,
     122,   194,   183,   194,   183,   194,   183,   194,   183,   194,
     183,   194,   183,   194,   183,   194,   183,   194,     6,     7,
       9,    10,    12,    14,    15,   153,   183,   195,   106,   107,
     197,   197,   111,    16,   147,   110,    43,   110,   194,   110,
     110,   110,   110,   110,   110,   110,   194,   194,   110,   110,
     110,   194,     8,   147,    11,   147,   183,   147,    17,    18,
      19,   147,    25,   169,   170,   194,   183,   194,    30,    23,
      24,    26,    27,    29,    22,    31,    33,   147,    34,    36,
     147,    37,    39,   147,    47,   147,    47,    47,    47,    47,
      47,    53,    54,   147,    56,    57,   147,    59,    60,   147,
      62,    64,   147,    66,    69,   147,    71,    72,    74,   147,
      77,   147,   148,   147,   147,   147,   125,   147,   128,   147,
     131,   147,   134,   147,   137,   147,   140,   147,   143,   147,
     146,   147,   152,   194,   152,   194,   152,   194,   152,     5,
     111,   112,   113,   114,   115,   147,   149,   147,   110,   111,
     152,    41,    43,   147,    79,    81,    83,    85,    87,    90,
      90,   147,   147,    95,    95,    97,   147,   152,   152,    13,
     152,   183,   183,   147,    28,   147,   169,   194,   183,   194,
      30,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   111,   100,   119,   122,   183,   183,   183,   183,
     183,   183,   183,   183,     8,   147,    11,   147,   183,   147,
      17,   197,   197,   197,   197,   197,   199,   111,   203,   110,
     183,   110,   110,    90,   110,   110,     8,    11,   183,    19,
      25,   169,   183,   183,   147,    28,   147,    33,    36,    39,
      47,    54,    57,    60,    64,    69,    74,    77,   197,   125,
     128,   131,   134,   137,   140,   143,   146,   152,   152,    13,
     152,   152,   197,   152,     5,    43,    90,    90,    97,    13,
     183,    28,    25,   169,   183,     8,    11,   183,   102,   200,
     104,   202,    25,   183,    28,    13,    25
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
#line 157 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 161 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 165 "gtkdialog_parser.y"
    { 
    		token_store_attr(PUSH | WIDGET_WINDOW, (yyvsp[(2) - (6)].nvval)); 
		start_up();
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 173 "gtkdialog_parser.y"
    { 
		token_store(SUM);      
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 178 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
	}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 181 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
		token_store(SUM);      
	}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 185 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 188 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(3) - (6)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 192 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
	}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 195 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
		token_store(SUM);      
	}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 199 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 202 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(3) - (6)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 206 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
	}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 209 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
		token_store(SUM);      
	}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 213 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 216 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);      
	}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 220 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(1) - (3)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
	}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 224 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(2) - (4)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
		token_store(SUM);      
	}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 260 "gtkdialog_parser.y"
    {
                          token_store(PUSH | WIDGET_ENTRY); 
			 }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 263 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_ENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 266 "gtkdialog_parser.y"
    {
                  yyerror("</entry> expected instead of <entry>.");}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 271 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_EDIT); 
	}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 274 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_EDIT, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 277 "gtkdialog_parser.y"
    {
    		yyerror("</edit> expected instead of <edit>.");
	}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 283 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TREE); 
	}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 286 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_TREE, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 289 "gtkdialog_parser.y"
    {
   		yyerror("</tree> expected instead of <tree>.");
	}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 295 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHOOSER); 
	}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 298 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_CHOOSER, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 301 "gtkdialog_parser.y"
    {
		yyerror("</chooser> expected instead of <chooser>.");
	}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 307 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TEXT); 
	}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 310 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_TEXT, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 313 "gtkdialog_parser.y"
    {yyerror("</text> expected instead of <text>.");}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 317 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_BUTTON);  }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 318 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_BUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 321 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_OKBUTTON);}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 322 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_CANCELBUTTON);}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 323 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_HELPBUTTON);}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 324 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_NOBUTTON);}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 325 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_YESBUTTON);}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 329 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHECKBOX);
	}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 332 "gtkdialog_parser.y"
    {
		//token_store_with_tag_attributes(PUSH | WIDGET_CHECKBOX, $2);
                token_store_attr(PUSH | WIDGET_CHECKBOX, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 336 "gtkdialog_parser.y"
    {
		yyerror("</checkbox> expected instead of <checkbox>.");
	}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 342 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_RADIO);
           }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 345 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_RADIO, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 348 "gtkdialog_parser.y"
    {
		yyerror("</radiobutton> expected instead of <radiobutton>.");
           }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 354 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_PROGRESS);
           }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 357 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_PROGRESS, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 360 "gtkdialog_parser.y"
    {
		yyerror("</progressbar> expected instead of <progressbar>.");
           }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 366 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_LIST); 
	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 369 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_LIST, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 372 "gtkdialog_parser.y"
    {
    		yyerror("</list> expected instead of <list>.");
	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 378 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_TABLE);}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 382 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_COMBO);
	}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 385 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_COMBO, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 391 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_GVIM);}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 395 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_PIXMAP);}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 396 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_PIXMAP, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 409 "gtkdialog_parser.y"
    {
		yyerror("The menubar widget requires at least one menu widget.");
	}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 412 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUBAR);
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 424 "gtkdialog_parser.y"
    {
		yyerror("The menu widget requires at least one menuitem widget.");
	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 427 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENU);
	}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 430 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENU);
		token_store(SUM);
	}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 434 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENU, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 437 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENU, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 444 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM);
	}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 447 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM);
		token_store(SUM);
	}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 451 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 454 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(3) - (6)].nvval));
		token_store(SUM);
	}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 461 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEMSEPARATOR);
	}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 464 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEMSEPARATOR);
		token_store(SUM);
	}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 471 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSEPARATOR);
	}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 474 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 480 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSEPARATOR);
	}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 483 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 489 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXTEXT);
	}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 492 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXTEXT, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 498 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXENTRY);
	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 501 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 507 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSCALE);
	}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 510 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSCALE, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 516 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSCALE);
	}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 519 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSCALE, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 525 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_SPINBUTTON);
	}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 528 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_SPINBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 534 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TIMER);
	}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 537 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TIMER, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 543 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TOGGLEBUTTON);
	}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 546 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TOGGLEBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 552 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_STATUSBAR);
	}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 555 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_STATUSBAR, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 575 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_LABEL, (yyvsp[(2) - (3)].cval));     }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 580 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_VARIABLE, (yyvsp[(2) - (3)].cval)); }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 585 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_SENSITIVE, (yyvsp[(2) - (3)].cval));  }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 590 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_DEFAULT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 595 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_WIDTH, (yyvsp[(2) - (3)].cval));    }
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 600 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_HEIGHT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 605 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_SHELL,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 608 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 611 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 614 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 617 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, "", (yyvsp[(2) - (4)].nvval)); 
	}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 623 "gtkdialog_parser.y"
    {
	         fprintf( stderr, "<output>: Not implemented.\n" ); 
	}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 626 "gtkdialog_parser.y"
    {
         	token_store_with_argument(SET|ATTR_OUTPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 632 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET|ATTR_ACTION, (yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 635 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET | ATTR_ACTION, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 642 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET | ATTR_ITEM, (yyvsp[(2) - (3)].cval));
	}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 645 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_ITEM, "");
    	}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 648 "gtkdialog_parser.y"
    {
		      token_store_with_argument_attr(SET | ATTR_ITEM, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
                    }
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 654 "gtkdialog_parser.y"
    {
       		(yyval.nvval) = new_tag_attributeset((yyvsp[(1) - (3)].cval), (yyvsp[(3) - (3)].cval)); 
	}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 657 "gtkdialog_parser.y"
    { 
       		(yyval.nvval) = add_tag_attribute((yyvsp[(1) - (4)].nvval), (yyvsp[(2) - (4)].cval), (yyvsp[(4) - (4)].cval)); 
	}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 664 "gtkdialog_parser.y"
    { 
		token_store(SHOW);     
	}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 667 "gtkdialog_parser.y"
    {
  		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
	}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 670 "gtkdialog_parser.y"
    {
		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
		instruction_set_jump((yyvsp[(6) - (6)].ival) + 1, (yyvsp[(1) - (6)].ival));
	}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 677 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMASSG | VARIABLE_NAME, (yyvsp[(1) - (4)].cval)); 
	}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 683 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | VARIABLE_NAME, (yyvsp[(1) - (1)].cval)); 
	}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 686 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | CONST_NUMBER, (yyvsp[(1) - (1)].cval)); 
  	}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 689 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_ADD);
	}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 692 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_SUBST);
	}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 695 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_MULT);
	}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 698 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_DIV);
	}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 701 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_EQ);
	}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 704 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_NE);
	}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 714 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 721 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 725 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 729 "gtkdialog_parser.y"
    {
		token_store(GOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 736 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
    }
    break;



/* Line 1455 of yacc.c  */
#line 3987 "gtkdialog_parser.c"
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
#line 742 "gtkdialog_parser.y"


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


