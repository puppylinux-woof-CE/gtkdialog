
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
     VISIBLE = 335,
     EVISIBLE = 336,
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
     EVSCALE = 384
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
#define VISIBLE 335
#define EVISIBLE 336
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
#line 462 "gtkdialog_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 474 "gtkdialog_parser.c"

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
#define YYFINAL  88
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3961

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  138
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  158
/* YYNRULES -- Number of states.  */
#define YYNSTATES  422

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   384

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   137,     2,     2,     2,     2,     2,     2,
       2,     2,   114,   113,     2,   112,     2,   115,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   136,     2,
       2,   111,   135,     2,     2,     2,     2,     2,     2,     2,
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
     130,   131,   132,   133,   134
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    11,    18,    20,    23,    25,    28,
      32,    37,    43,    50,    54,    59,    65,    72,    76,    81,
      87,    94,    98,   103,   105,   107,   109,   111,   113,   115,
     117,   119,   121,   123,   125,   127,   129,   131,   133,   135,
     137,   139,   141,   143,   145,   149,   155,   159,   163,   169,
     173,   177,   183,   187,   191,   197,   201,   205,   211,   215,
     219,   225,   229,   233,   237,   241,   245,   249,   255,   259,
     263,   269,   273,   277,   283,   287,   291,   297,   301,   305,
     309,   315,   319,   323,   329,   332,   336,   339,   344,   351,
     355,   361,   369,   373,   379,   384,   391,   395,   398,   403,
     406,   411,   415,   421,   425,   431,   435,   441,   445,   451,
     452,   455,   458,   461,   464,   467,   470,   473,   476,   479,
     482,   486,   490,   494,   498,   502,   506,   510,   516,   520,
     526,   531,   535,   539,   543,   549,   553,   556,   562,   566,
     571,   576,   578,   585,   592,   597,   599,   601,   605,   609,
     613,   617,   621,   626,   628,   629,   631,   633,   635
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     139,     0,    -1,   165,   140,    -1,     3,   140,   165,     5,
      -1,     4,   176,   135,   140,   165,     5,    -1,   141,    -1,
     140,   141,    -1,   177,    -1,   140,   177,    -1,     6,   140,
       8,    -1,   140,     6,   140,     8,    -1,     7,   176,   135,
     140,     8,    -1,   140,     7,   176,   135,   140,     8,    -1,
       9,   140,    11,    -1,   140,     9,   140,    11,    -1,    10,
     176,   135,   140,    11,    -1,   140,    10,   176,   135,   140,
      11,    -1,    12,   140,    13,    -1,   140,    12,   140,    13,
      -1,    14,   176,   135,   140,    13,    -1,   140,    14,   176,
     135,   140,    13,    -1,    15,   140,    17,    -1,   140,    15,
     140,    17,    -1,   146,    -1,   142,    -1,   143,    -1,   144,
      -1,   145,    -1,   147,    -1,   148,    -1,   149,    -1,   150,
      -1,   151,    -1,   152,    -1,   153,    -1,   155,    -1,   154,
      -1,   156,    -1,   159,    -1,   160,    -1,   161,    -1,   162,
      -1,   163,    -1,   164,    -1,    18,   165,    19,    -1,    20,
     176,   135,   165,    19,    -1,    18,   165,    18,    -1,    31,
     165,    33,    -1,    32,   176,   135,   165,    33,    -1,    31,
     165,    31,    -1,    34,   165,    36,    -1,    35,   176,   135,
     165,    36,    -1,    34,   165,    34,    -1,    37,   165,    39,
      -1,    38,   176,   135,   165,    39,    -1,    37,   165,    37,
      -1,    72,   165,    74,    -1,    73,   176,   135,   165,    74,
      -1,    72,   165,    72,    -1,    45,   165,    47,    -1,    46,
     176,   135,   165,    47,    -1,    48,   165,    47,    -1,    49,
     165,    47,    -1,    50,   165,    47,    -1,    52,   165,    47,
      -1,    51,   165,    47,    -1,    53,   165,    54,    -1,    55,
     176,   135,   165,    54,    -1,    53,   165,    53,    -1,    56,
     165,    57,    -1,    58,   176,   135,   165,    57,    -1,    56,
     165,    56,    -1,    59,   165,    60,    -1,    61,   176,   135,
     165,    60,    -1,    59,   165,    59,    -1,    62,   165,    64,
      -1,    63,   176,   135,   165,    64,    -1,    62,   165,    62,
      -1,    65,   165,    66,    -1,    67,   165,    69,    -1,    68,
     176,   135,   165,    69,    -1,    70,   165,    71,    -1,    75,
     165,    77,    -1,    76,   176,   135,   165,    77,    -1,    21,
      22,    -1,    21,   157,    22,    -1,    23,    25,    -1,    23,
     158,   165,    25,    -1,    24,   176,   135,   158,   165,    25,
      -1,   157,    23,    25,    -1,   157,    23,   158,   165,    25,
      -1,   157,    24,   176,   135,   158,   165,    25,    -1,    26,
     165,    28,    -1,    27,   176,   135,   165,    28,    -1,   158,
      26,   165,    28,    -1,   158,    27,   176,   135,   165,    28,
      -1,   158,    29,    30,    -1,   117,   119,    -1,   118,   176,
     135,   119,    -1,   120,   122,    -1,   121,   176,   135,   122,
      -1,   123,   165,   125,    -1,   124,   176,   135,   165,   125,
      -1,   126,   165,   128,    -1,   127,   176,   135,   165,   128,
      -1,   129,   165,   131,    -1,   130,   176,   135,   165,   131,
      -1,   132,   165,   134,    -1,   133,   176,   135,   165,   134,
      -1,    -1,   165,   169,    -1,   165,   168,    -1,   165,   167,
      -1,   165,   166,    -1,   165,   170,    -1,   165,   171,    -1,
     165,   172,    -1,   165,   173,    -1,   165,   174,    -1,   165,
     175,    -1,    40,   110,    41,    -1,    82,   110,    83,    -1,
      80,   110,    81,    -1,    78,   110,    79,    -1,    84,   110,
      85,    -1,    86,   110,    87,    -1,    88,   110,    90,    -1,
      91,   176,   135,   110,    90,    -1,    89,   110,    90,    -1,
      92,   176,   135,   110,    90,    -1,    92,   176,   135,    90,
      -1,    93,   110,    95,    -1,    94,   110,    95,    -1,    96,
     110,    97,    -1,    98,   176,   135,   110,    97,    -1,    42,
     110,    43,    -1,    42,    43,    -1,    44,   176,   135,   110,
      43,    -1,    16,   111,   110,    -1,   176,    16,   111,   110,
      -1,    99,   178,   135,   100,    -1,   105,    -1,   180,   179,
     135,   181,   140,   182,    -1,   183,   179,   135,   185,   140,
     184,    -1,   106,   136,   111,   179,    -1,   106,    -1,   107,
      -1,   179,   113,   179,    -1,   179,   112,   179,    -1,   179,
     114,   179,    -1,   179,   115,   179,    -1,   179,   111,   179,
      -1,   179,   137,   111,   179,    -1,   101,    -1,    -1,   102,
      -1,   103,    -1,   104,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   153,   153,   157,   161,   168,   169,   172,   173,   174,
     177,   181,   184,   188,   191,   195,   198,   202,   205,   209,
     212,   216,   220,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   252,   255,   258,   263,   266,   269,
     275,   278,   281,   287,   290,   293,   299,   302,   305,   309,
     310,   313,   314,   315,   316,   317,   321,   324,   328,   334,
     337,   340,   346,   349,   352,   358,   361,   364,   370,   374,
     377,   383,   387,   388,   394,   397,   403,   406,   409,   412,
     415,   419,   426,   429,   432,   436,   440,   453,   456,   462,
     465,   471,   474,   480,   483,   489,   492,   498,   501,   506,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     521,   526,   531,   536,   541,   546,   551,   554,   557,   560,
     563,   569,   572,   578,   581,   588,   591,   594,   600,   603,
     609,   610,   613,   616,   623,   629,   632,   635,   638,   641,
     644,   647,   650,   656,   660,   667,   671,   675,   682
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
  "EPIXMAP", "DEFAULT", "EDEFAULT", "VISIBLE", "EVISIBLE", "VARIABLE",
  "EVARIABLE", "WIDTH", "EWIDTH", "HEIGHT", "EHEIGHT", "INPUT",
  "INPUTFILE", "EINPUT", "PART_INPUT", "PART_INPUTFILE", "OUTPUT",
  "OUTPUTFILE", "EOUTPUT", "ACTION", "EACTION", "PART_ACTION", "COMM",
  "ENDCOMM", "IF", "ENDIF", "WHILE", "EWHILE", "SHOW_WIDGETS",
  "EMB_VARIABLE", "EMB_NUMBER", "END_OF_FILE", "NUMBER", "STRING", "'='",
  "'-'", "'+'", "'*'", "'/'", "UMINUS", "HSEPARATOR", "PART_HSEPARATOR",
  "EHSEPARATOR", "VSEPARATOR", "PART_VSEPARATOR", "EVSEPARATOR",
  "COMBOBOXTEXT", "PART_COMBOBOXTEXT", "ECOMBOBOXTEXT", "COMBOBOXENTRY",
  "PART_COMBOBOXENTRY", "ECOMBOBOXENTRY", "HSCALE", "PART_HSCALE",
  "EHSCALE", "VSCALE", "PART_VSCALE", "EVSCALE", "'>'", "':'", "'!'",
  "$accept", "window", "wlist", "widget", "entry", "edit", "tree",
  "chooser", "text", "button", "checkbox", "radiobutton", "progressbar",
  "list", "table", "combo", "gvim", "pixmap", "menubar", "menus",
  "menuitems", "hseparator", "vseparator", "comboboxtext", "comboboxentry",
  "hscale", "vscale", "attr", "label", "variable", "visible",
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
     380,   381,   382,   383,   384,    62,    58,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   138,   139,   139,   139,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   142,   142,   142,   143,   143,   143,
     144,   144,   144,   145,   145,   145,   146,   146,   146,   147,
     147,   147,   147,   147,   147,   147,   148,   148,   148,   149,
     149,   149,   150,   150,   150,   151,   151,   151,   152,   153,
     153,   154,   155,   155,   156,   156,   157,   157,   157,   157,
     157,   157,   158,   158,   158,   158,   158,   159,   159,   160,
     160,   161,   161,   162,   162,   163,   163,   164,   164,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     166,   167,   168,   169,   170,   171,   172,   172,   172,   172,
     172,   173,   173,   174,   174,   175,   175,   175,   176,   176,
     177,   177,   177,   177,   178,   179,   179,   179,   179,   179,
     179,   179,   179,   180,   181,   182,   183,   184,   185
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     6,     1,     2,     1,     2,     3,
       4,     5,     6,     3,     4,     5,     6,     3,     4,     5,
       6,     3,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     5,     3,     3,     5,     3,
       3,     5,     3,     3,     5,     3,     3,     5,     3,     3,
       5,     3,     3,     3,     3,     3,     3,     5,     3,     3,
       5,     3,     3,     5,     3,     3,     5,     3,     3,     3,
       5,     3,     3,     5,     2,     3,     2,     4,     6,     3,
       5,     7,     3,     5,     4,     6,     3,     2,     4,     2,
       4,     3,     5,     3,     5,     3,     5,     3,     5,     0,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     5,     3,     5,
       4,     3,     3,     3,     5,     3,     2,     5,     3,     4,
       4,     1,     6,     6,     4,     1,     1,     3,     3,     3,
       3,     3,     4,     1,     0,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,     0,     0,   109,     0,   109,     0,   109,
       0,   109,     0,   109,   109,   109,   109,   109,   109,     0,
     109,     0,   109,     0,   109,     0,   109,   109,     0,   109,
     109,     0,   109,     0,     0,   153,   156,   141,     0,     0,
       0,     0,   109,     0,   109,     0,   109,     0,   109,     0,
     109,     5,    24,    25,    26,    27,    23,    28,    29,    30,
      31,    32,    33,    34,    36,    35,    37,    38,    39,    40,
      41,    42,    43,     7,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,   113,   112,   111,   110,
     114,   115,   116,   117,   118,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,     0,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       0,     8,   145,   146,     0,     0,     0,     0,     0,     0,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,     0,    13,     0,
      17,     0,    21,    46,    44,   109,    86,   109,     0,   109,
       0,    85,     0,     0,    49,    47,   109,    52,    50,   109,
      55,    53,   109,    59,   109,    61,    62,    63,    65,    64,
      68,    66,   109,    71,    69,   109,    74,    72,   109,    77,
      75,   109,    78,    79,   109,    81,    58,    56,   109,    82,
     109,     0,     0,     0,     0,   101,   109,   103,   109,   105,
     109,   107,   109,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     0,     0,     0,     0,   154,     0,   158,   138,
       0,   109,   120,   135,     0,   123,   122,   121,   124,   125,
     126,   128,     0,     0,   131,   132,   133,     0,     0,     0,
       0,     0,     0,     0,   109,     0,     0,     0,     0,    89,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   140,    98,   100,     0,     0,     0,
       0,    10,     0,    14,     0,    18,     0,    22,   151,   148,
     147,   149,   150,     0,     0,     0,   139,     0,     0,     0,
     130,     0,     0,    11,    15,    19,    45,    92,   109,     0,
       0,    96,    87,   109,     0,     0,    48,    51,    54,    60,
      67,    70,    73,    76,    80,    57,    83,   144,   102,   104,
     106,   108,     0,     0,     0,     0,   152,     0,     4,   137,
     127,   129,   134,     0,    94,   109,     0,    90,   109,    12,
      16,    20,   155,   142,   157,   143,    93,     0,    88,     0,
      95,    91
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,   128,
     219,    77,    78,    79,    80,    81,    82,     4,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    87,    83,
     159,   184,    84,   353,   413,    85,   415,   355
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -200
static const yytype_int16 yypact[] =
{
      95,  2564,    -6,    34,   388,  2564,    -6,  2564,    -6,  2564,
      -6,  2564,  -200,    -6,    73,  -200,    -6,  -200,    -6,  -200,
      -6,  -200,    -6,  -200,  -200,  -200,  -200,  -200,  -200,    -6,
    -200,    -6,  -200,    -6,  -200,    -6,  -200,  -200,    -6,  -200,
    -200,    -6,  -200,    -6,   -52,  -200,  -200,  -200,   -69,    -6,
     -70,    -6,  -200,    -6,  -200,    -6,  -200,    -6,  -200,    -6,
    2692,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,    26,    26,   -45,     1,  -200,   -53,
     -17,    -6,   -42,   -34,   -19,    -9,    -2,     0,    16,    -6,
      -6,    18,    20,    38,    -6,  2692,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,   516,     3,   644,     5,
     772,    15,   900,  3047,    17,  -200,   116,    -6,   261,  3086,
      19,  3147,    21,  3224,    22,  3437,    23,  3459,  3480,  3502,
    3523,  3545,  3296,    25,  3313,    27,  3356,    29,  3377,    31,
    3562,  3605,    33,  3624,  3416,    35,  3646,    37,    -1,    24,
    -200,    42,  -200,    43,  2946,    44,  2905,    45,  2826,    46,
    2748,    47,  2564,    -6,  2564,    -6,  2564,    -6,  2564,  -200,
    2809,  -200,  -200,  -200,   -32,     9,    64,    50,  2564,   122,
    -200,   124,    48,    86,   120,   119,   130,   129,   128,   131,
      49,    51,   136,   137,   127,    53,  -200,  2564,  -200,  2564,
    -200,  2564,  -200,  -200,  -200,  -200,  -200,  -200,    -6,    60,
      54,  -200,   265,    -6,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,   108,   134,   118,   121,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  1028,    55,  1156,    56,  1284,    57,  1412,
    -200,    26,    26,    26,    26,    26,  -200,   133,  -200,  -200,
     140,  2692,  -200,  -200,   142,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,   143,   -54,  -200,  -200,  -200,   145,  1540,  1668,
    1796,  3064,  1027,    58,  -200,    -6,   208,   515,   172,  -200,
      60,    59,  3121,  3164,  3241,  3667,  3689,  3722,  3749,  3782,
    3808,  3839,  3863,    26,  -200,  -200,  -200,  2965,  2924,  2883,
    2787,  -200,  2564,  -200,  2564,  -200,  2564,  -200,   152,   -30,
     -30,   103,   103,  2564,    26,  2564,  -200,  2850,   198,   167,
    -200,   169,   164,  -200,  -200,  -200,  -200,  -200,  -200,  1155,
      62,  -200,  -200,    60,   643,   172,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,    98,  -200,  -200,
    -200,  -200,  1924,  2052,  2180,  2308,   152,  2436,  -200,  -200,
    -200,  -200,  -200,  1283,  -200,  -200,   771,  -200,    60,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  1411,  -200,   899,
    -200,  -200
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -200,  -200,    -3,   -28,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -199,  -200,  -200,  -200,  -200,  -200,  -200,   -12,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,    96,    -5,
    -200,   -56,  -200,  -200,  -200,  -200,  -200,  -200
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     123,   105,   116,   129,   118,   131,   120,   133,   122,   135,
      86,   137,   138,   139,   140,   141,   142,   187,   144,   187,
     146,   187,   148,   320,   150,   151,   190,   153,   154,   185,
     156,   187,   179,   187,    88,   187,   360,   187,   187,   187,
     164,   187,   166,   187,   168,   187,   170,   187,   180,   187,
     160,   187,   162,   187,   158,   181,   361,   189,   187,   187,
     187,   187,   187,   187,   187,   187,   186,   187,   193,   187,
     187,   187,   187,   187,   187,   187,   194,   179,   187,   281,
     282,   283,   284,   285,   284,   285,   314,   315,   179,   316,
     179,   195,   179,   191,   179,   125,   126,   127,     1,     2,
     181,   196,   117,   286,   119,   287,   121,   287,   197,   124,
     198,   181,   130,   181,   132,   181,   134,   181,   136,   373,
     281,   282,   283,   284,   285,   143,   199,   145,   202,   147,
     203,   149,   182,   183,   152,   261,   188,   155,   207,   157,
     209,   216,   217,   218,   288,   161,   287,   163,   204,   165,
     211,   167,   215,   169,   226,   171,   229,   232,   234,   262,
     242,   290,   245,   292,   248,   295,   251,   293,   254,   273,
     258,   275,   260,   277,   289,   279,   408,   263,   264,   266,
     268,   270,   272,   294,   302,   291,   303,   192,   307,   318,
     342,   344,   346,   368,   375,   200,   201,   405,   217,   218,
     205,   296,   297,   311,   308,   312,   309,   317,   310,   281,
     282,   283,   284,   285,   322,   298,   299,   323,   300,   333,
     324,   301,   325,   220,   306,   348,   349,   350,   351,   352,
     326,   304,   305,   327,   334,   287,   328,   335,   371,   329,
     287,   399,   330,   336,   354,   179,   331,   179,   332,   179,
     356,   179,   358,   359,   337,   362,   338,   400,   339,   401,
     340,   402,     0,   179,   282,   283,   284,   285,   181,   274,
     181,   276,   181,   278,   181,     0,     0,   387,     0,   357,
     179,   179,   179,   221,   222,   223,   181,     0,     0,   287,
     319,   217,   218,     0,     0,     0,     0,     0,   396,     0,
       0,     0,   369,   181,   181,   181,     0,     0,   374,     0,
       0,     0,     0,     0,   313,     0,     0,     0,     0,   321,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   392,
       0,   393,     0,   394,     0,     0,     0,     0,     0,     0,
     395,     0,   397,     0,     0,     0,   403,     0,     0,     0,
       0,   406,     0,     0,   179,   179,   179,   179,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   181,   181,
     181,     0,   181,   417,     5,     6,   419,     7,     8,     0,
       9,     0,    10,    11,     0,     0,    12,     0,    13,    14,
       0,   370,     0,     0,     0,     0,     0,     0,     0,    15,
      16,     0,    17,    18,     0,    19,    20,     0,    89,     0,
      90,     0,    91,    21,    22,     0,    23,    24,    25,    26,
      27,    28,     0,    29,    30,     0,    31,    32,     0,    33,
      34,    35,     0,    36,     0,    37,    38,     0,    39,     0,
      40,    41,     0,    42,    43,     0,    92,     0,    93,     0,
      94,     0,    95,     0,    96,     0,    97,    98,     0,    99,
     100,   101,   102,     0,   103,     0,   104,    44,     0,    45,
       0,    46,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    49,     0,    50,    51,
       0,    52,    53,     0,    54,    55,     0,    56,    57,     0,
      58,    59,   172,   173,   206,   174,   175,     0,   176,     0,
     177,   178,     0,     0,    12,     0,    13,    14,     0,     0,
     372,     0,     0,     0,     0,     0,     0,    15,    16,     0,
      17,    18,     0,    19,    20,    89,     0,    90,     0,    91,
       0,    21,    22,     0,    23,    24,    25,    26,    27,    28,
       0,    29,    30,     0,    31,    32,     0,    33,    34,    35,
       0,    36,     0,    37,    38,     0,    39,     0,    40,    41,
       0,    42,    43,    92,     0,    93,     0,    94,     0,    95,
       0,    96,     0,    97,    98,     0,    99,   100,   101,   102,
       0,   103,     0,   104,     0,    44,     0,    45,     0,    46,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    49,     0,    50,    51,     0,    52,
      53,     0,    54,    55,     0,    56,    57,     0,    58,    59,
     172,   173,     0,   174,   175,   208,   176,     0,   177,   178,
       0,     0,    12,     0,    13,    14,     0,     0,   407,     0,
       0,     0,     0,     0,     0,    15,    16,     0,    17,    18,
       0,    19,    20,    89,     0,    90,     0,    91,     0,    21,
      22,     0,    23,    24,    25,    26,    27,    28,     0,    29,
      30,     0,    31,    32,     0,    33,    34,    35,     0,    36,
       0,    37,    38,     0,    39,     0,    40,    41,     0,    42,
      43,    92,     0,    93,     0,    94,     0,    95,     0,    96,
       0,    97,    98,     0,    99,   100,   101,   102,     0,   103,
       0,   104,     0,    44,     0,    45,     0,    46,     0,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    49,     0,    50,    51,     0,    52,    53,     0,
      54,    55,     0,    56,    57,     0,    58,    59,   172,   173,
       0,   174,   175,     0,   176,   210,   177,   178,     0,     0,
      12,     0,    13,    14,     0,     0,   418,     0,     0,     0,
       0,     0,     0,    15,    16,     0,    17,    18,     0,    19,
      20,    89,     0,    90,     0,    91,     0,    21,    22,     0,
      23,    24,    25,    26,    27,    28,     0,    29,    30,     0,
      31,    32,     0,    33,    34,    35,     0,    36,     0,    37,
      38,     0,    39,     0,    40,    41,     0,    42,    43,    92,
       0,    93,     0,    94,     0,    95,     0,    96,     0,    97,
      98,     0,    99,   100,   101,   102,     0,   103,     0,   104,
       0,    44,     0,    45,     0,    46,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      49,     0,    50,    51,     0,    52,    53,     0,    54,    55,
       0,    56,    57,     0,    58,    59,   172,   173,     0,   174,
     175,     0,   176,     0,   177,   178,     0,   212,    12,     0,
      13,    14,     0,     0,   421,     0,     0,     0,     0,     0,
       0,    15,    16,     0,    17,    18,     0,    19,    20,    89,
       0,    90,     0,    91,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,    31,    32,
       0,    33,    34,    35,     0,    36,     0,    37,    38,     0,
      39,     0,    40,    41,     0,    42,    43,    92,     0,    93,
       0,    94,     0,    95,     0,    96,     0,    97,    98,     0,
      99,   100,   101,   102,     0,   103,     0,   104,     0,    44,
       0,    45,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,     0,    56,
      57,     0,    58,    59,   172,   173,   341,   174,   175,     0,
     176,     0,   177,   178,     0,     0,    12,     0,    13,    14,
       0,     0,     0,     0,     0,   367,     0,     0,     0,    15,
      16,     0,    17,    18,     0,    19,    20,    89,     0,    90,
       0,    91,     0,    21,    22,     0,    23,    24,    25,    26,
      27,    28,     0,    29,    30,     0,    31,    32,     0,    33,
      34,    35,     0,    36,     0,    37,    38,     0,    39,     0,
      40,    41,     0,    42,    43,    92,     0,    93,     0,    94,
       0,    95,     0,    96,     0,    97,    98,     0,    99,   100,
     101,   102,     0,   103,     0,   104,     0,    44,     0,    45,
       0,    46,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    49,     0,    50,    51,
       0,    52,    53,     0,    54,    55,     0,    56,    57,     0,
      58,    59,   172,   173,     0,   174,   175,   343,   176,     0,
     177,   178,     0,     0,    12,     0,    13,    14,     0,     0,
       0,     0,     0,   404,     0,     0,     0,    15,    16,     0,
      17,    18,     0,    19,    20,    89,     0,    90,     0,    91,
       0,    21,    22,     0,    23,    24,    25,    26,    27,    28,
       0,    29,    30,     0,    31,    32,     0,    33,    34,    35,
       0,    36,     0,    37,    38,     0,    39,     0,    40,    41,
       0,    42,    43,    92,     0,    93,     0,    94,     0,    95,
       0,    96,     0,    97,    98,     0,    99,   100,   101,   102,
       0,   103,     0,   104,     0,    44,     0,    45,     0,    46,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    49,     0,    50,    51,     0,    52,
      53,     0,    54,    55,     0,    56,    57,     0,    58,    59,
     172,   173,     0,   174,   175,     0,   176,   345,   177,   178,
       0,     0,    12,     0,    13,    14,     0,     0,     0,     0,
       0,   416,     0,     0,     0,    15,    16,     0,    17,    18,
       0,    19,    20,    89,     0,    90,     0,    91,     0,    21,
      22,     0,    23,    24,    25,    26,    27,    28,     0,    29,
      30,     0,    31,    32,     0,    33,    34,    35,     0,    36,
       0,    37,    38,     0,    39,     0,    40,    41,     0,    42,
      43,    92,     0,    93,     0,    94,     0,    95,     0,    96,
       0,    97,    98,     0,    99,   100,   101,   102,     0,   103,
       0,   104,     0,    44,     0,    45,     0,    46,     0,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    49,     0,    50,    51,     0,    52,    53,     0,
      54,    55,     0,    56,    57,     0,    58,    59,   172,   173,
       0,   174,   175,     0,   176,     0,   177,   178,     0,   347,
      12,     0,    13,    14,     0,     0,     0,     0,     0,   420,
       0,     0,     0,    15,    16,     0,    17,    18,     0,    19,
      20,    89,     0,    90,     0,    91,     0,    21,    22,     0,
      23,    24,    25,    26,    27,    28,     0,    29,    30,     0,
      31,    32,     0,    33,    34,    35,     0,    36,     0,    37,
      38,     0,    39,     0,    40,    41,     0,    42,    43,    92,
       0,    93,     0,    94,     0,    95,     0,    96,     0,    97,
      98,     0,    99,   100,   101,   102,     0,   103,     0,   104,
       0,    44,     0,    45,     0,    46,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      49,     0,    50,    51,     0,    52,    53,     0,    54,    55,
       0,    56,    57,     0,    58,    59,   172,   173,   363,   174,
     175,     0,   176,     0,   177,   178,     0,     0,    12,     0,
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
      57,     0,    58,    59,   172,   173,     0,   174,   175,   364,
     176,     0,   177,   178,     0,     0,    12,     0,    13,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
      16,     0,    17,    18,     0,    19,    20,     0,     0,     0,
       0,     0,     0,    21,    22,     0,    23,    24,    25,    26,
      27,    28,     0,    29,    30,     0,    31,    32,     0,    33,
      34,    35,     0,    36,     0,    37,    38,     0,    39,     0,
      40,    41,     0,    42,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,    45,
       0,    46,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    49,     0,    50,    51,
       0,    52,    53,     0,    54,    55,     0,    56,    57,     0,
      58,    59,   172,   173,     0,   174,   175,     0,   176,   365,
     177,   178,     0,     0,    12,     0,    13,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    16,     0,
      17,    18,     0,    19,    20,     0,     0,     0,     0,     0,
       0,    21,    22,     0,    23,    24,    25,    26,    27,    28,
       0,    29,    30,     0,    31,    32,     0,    33,    34,    35,
       0,    36,     0,    37,    38,     0,    39,     0,    40,    41,
       0,    42,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,     0,    45,     0,    46,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    49,     0,    50,    51,     0,    52,
      53,     0,    54,    55,     0,    56,    57,     0,    58,    59,
     172,   173,   409,   174,   175,     0,   176,     0,   177,   178,
       0,     0,    12,     0,    13,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    16,     0,    17,    18,
       0,    19,    20,     0,     0,     0,     0,     0,     0,    21,
      22,     0,    23,    24,    25,    26,    27,    28,     0,    29,
      30,     0,    31,    32,     0,    33,    34,    35,     0,    36,
       0,    37,    38,     0,    39,     0,    40,    41,     0,    42,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,     0,    45,     0,    46,     0,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    49,     0,    50,    51,     0,    52,    53,     0,
      54,    55,     0,    56,    57,     0,    58,    59,   172,   173,
       0,   174,   175,   410,   176,     0,   177,   178,     0,     0,
      12,     0,    13,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    16,     0,    17,    18,     0,    19,
      20,     0,     0,     0,     0,     0,     0,    21,    22,     0,
      23,    24,    25,    26,    27,    28,     0,    29,    30,     0,
      31,    32,     0,    33,    34,    35,     0,    36,     0,    37,
      38,     0,    39,     0,    40,    41,     0,    42,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    44,     0,    45,     0,    46,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      49,     0,    50,    51,     0,    52,    53,     0,    54,    55,
       0,    56,    57,     0,    58,    59,   172,   173,     0,   174,
     175,     0,   176,   411,   177,   178,     0,     0,    12,     0,
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
      57,     0,    58,    59,   172,   173,     0,   174,   175,     0,
     176,     0,   177,   178,     0,     0,    12,     0,    13,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
      16,     0,    17,    18,     0,    19,    20,     0,     0,     0,
       0,     0,     0,    21,    22,     0,    23,    24,    25,    26,
      27,    28,     0,    29,    30,     0,    31,    32,     0,    33,
      34,    35,     0,    36,     0,    37,    38,     0,    39,     0,
      40,    41,     0,    42,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,    45,
     412,    46,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    49,     0,    50,    51,
       0,    52,    53,     0,    54,    55,     0,    56,    57,     0,
      58,    59,   172,   173,     0,   174,   175,     0,   176,     0,
     177,   178,     0,     0,    12,     0,    13,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    16,     0,
      17,    18,     0,    19,    20,     0,     0,     0,     0,     0,
       0,    21,    22,     0,    23,    24,    25,    26,    27,    28,
       0,    29,    30,     0,    31,    32,     0,    33,    34,    35,
       0,    36,     0,    37,    38,     0,    39,     0,    40,    41,
       0,    42,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,     0,    45,     0,    46,
     414,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    49,     0,    50,    51,     0,    52,
      53,     0,    54,    55,     0,    56,    57,     0,    58,    59,
       5,     6,     0,     7,     8,     0,     9,     0,    10,    11,
       0,     0,    12,     0,    13,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    16,     0,    17,    18,
       0,    19,    20,     0,     0,     0,     0,     0,     0,    21,
      22,     0,    23,    24,    25,    26,    27,    28,     0,    29,
      30,     0,    31,    32,     0,    33,    34,    35,     0,    36,
       0,    37,    38,     0,    39,     0,    40,    41,     0,    42,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,     0,    45,     0,    46,     0,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    49,     0,    50,    51,     0,    52,    53,     0,
      54,    55,     0,    56,    57,     0,    58,    59,   172,   173,
       0,   174,   175,     0,   176,     0,   177,   178,     0,     0,
      12,     0,    13,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    16,     0,    17,    18,     0,    19,
      20,     0,     0,     0,     0,     0,     0,    21,    22,     0,
      23,    24,    25,    26,    27,    28,     0,    29,    30,     0,
      31,    32,     0,    33,    34,    35,     0,    36,     0,    37,
      38,     0,    39,     0,    40,    41,     0,    42,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     0,
      90,    44,    91,    45,     0,    46,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      49,     0,    50,    51,   280,    52,    53,     0,    54,    55,
       0,    56,    57,     0,    58,    59,    92,    89,    93,    90,
      94,    91,    95,     0,    96,     0,    97,    98,     0,    99,
     100,   101,   102,     0,   103,     0,   104,     0,     0,    89,
       0,    90,     0,    91,     0,   398,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    89,    93,    90,    94,
      91,    95,     0,    96,     0,    97,    98,     0,    99,   100,
     101,   102,   271,   103,     0,   104,     0,    92,     0,    93,
      89,    94,    90,    95,    91,    96,     0,    97,    98,     0,
      99,   100,   101,   102,    92,   103,    93,   104,    94,     0,
      95,     0,    96,     0,    97,    98,     0,    99,   100,   101,
     102,   391,   103,    89,   104,    90,     0,    91,    92,     0,
      93,     0,    94,     0,    95,     0,    96,     0,    97,    98,
       0,    99,   100,   101,   102,    89,   103,    90,   104,    91,
       0,     0,     0,     0,     0,     0,     0,   269,     0,     0,
       0,    92,     0,    93,    89,    94,    90,    95,    91,    96,
       0,    97,    98,     0,    99,   100,   101,   102,     0,   103,
       0,   104,     0,    92,     0,    93,    89,    94,    90,    95,
      91,    96,     0,    97,    98,     0,    99,   100,   101,   102,
       0,   103,    92,   104,    93,    89,    94,    90,    95,    91,
      96,     0,    97,    98,   390,    99,   100,   101,   102,     0,
     103,     0,   104,     0,    92,     0,    93,     0,    94,     0,
      95,     0,    96,   267,    97,    98,     0,    99,   100,   101,
     102,     0,   103,    92,   104,    93,     0,    94,     0,    95,
       0,    96,   389,    97,    98,     0,    99,   100,   101,   102,
       0,   103,     0,   104,     0,   213,   214,     0,     0,     0,
       0,   265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   366,     0,     0,     0,    89,     0,    90,
     388,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,     0,    90,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,   224,     0,   225,
       0,     0,     0,     0,     0,    92,    89,    93,    90,    94,
      91,    95,     0,    96,     0,    97,    98,     0,    99,   100,
     101,   102,    92,   103,    93,   104,    94,     0,    95,     0,
      96,     0,    97,    98,   376,    99,   100,   101,   102,     0,
     103,    89,   104,    90,    92,    91,    93,     0,    94,     0,
      95,     0,    96,     0,    97,    98,     0,    99,   100,   101,
     102,   227,   103,   228,   104,     0,     0,    89,     0,    90,
       0,    91,     0,     0,     0,     0,     0,     0,     0,    92,
     377,    93,     0,    94,    89,    95,    90,    96,    91,    97,
      98,     0,    99,   100,   101,   102,     0,   103,     0,   104,
       0,     0,     0,     0,     0,    92,     0,    93,     0,    94,
       0,    95,     0,    96,     0,    97,    98,     0,    99,   100,
     101,   102,    92,   103,    93,   104,    94,     0,    95,     0,
      96,     0,    97,    98,     0,    99,   100,   101,   102,     0,
     103,   230,   104,   231,    89,     0,    90,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     378,    89,     0,    90,     0,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,    93,     0,    94,     0,    95,     0,
      96,     0,    97,    98,     0,    99,   100,   101,   102,    92,
     103,    93,   104,    94,     0,    95,     0,    96,     0,    97,
      98,     0,    99,   100,   101,   102,    89,   103,    90,   104,
      91,     0,     0,     0,     0,     0,     0,     0,     0,   240,
     241,     0,     0,    89,     0,    90,     0,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   243,
     244,     0,     0,     0,    92,     0,    93,     0,    94,     0,
      95,     0,    96,     0,    97,    98,     0,    99,   100,   101,
     102,    92,   103,    93,   104,    94,    89,    95,    90,    96,
      91,    97,    98,     0,    99,   100,   101,   102,     0,   103,
       0,   104,     0,     0,     0,   246,   247,    89,     0,    90,
       0,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,    93,     0,    94,   249,
      95,   250,    96,     0,    97,    98,     0,    99,   100,   101,
     102,     0,   103,     0,   104,    92,    89,    93,    90,    94,
      91,    95,     0,    96,     0,    97,    98,     0,    99,   100,
     101,   102,     0,   103,     0,   104,     0,    89,     0,    90,
       0,    91,     0,     0,   233,     0,     0,     0,   256,     0,
     257,     0,     0,     0,    92,     0,    93,     0,    94,    89,
      95,    90,    96,    91,    97,    98,   235,    99,   100,   101,
     102,     0,   103,     0,   104,    92,     0,    93,     0,    94,
      89,    95,    90,    96,    91,    97,    98,   236,    99,   100,
     101,   102,     0,   103,     0,   104,     0,    92,     0,    93,
       0,    94,    89,    95,    90,    96,    91,    97,    98,   237,
      99,   100,   101,   102,     0,   103,     0,   104,    92,     0,
      93,     0,    94,    89,    95,    90,    96,    91,    97,    98,
     238,    99,   100,   101,   102,     0,   103,     0,   104,     0,
      92,     0,    93,     0,    94,    89,    95,    90,    96,    91,
      97,    98,   239,    99,   100,   101,   102,     0,   103,     0,
     104,    92,    89,    93,    90,    94,    91,    95,     0,    96,
       0,    97,    98,     0,    99,   100,   101,   102,     0,   103,
       0,   104,     0,    92,     0,    93,     0,    94,   252,    95,
       0,    96,     0,    97,    98,     0,    99,   100,   101,   102,
      92,   103,    93,   104,    94,    89,    95,    90,    96,    91,
      97,    98,     0,    99,   100,   101,   102,     0,   103,     0,
     104,     0,     0,     0,    89,     0,    90,     0,    91,     0,
       0,     0,     0,     0,   253,     0,     0,     0,     0,     0,
       0,     0,     0,    92,     0,    93,    89,    94,    90,    95,
      91,    96,     0,    97,    98,   255,    99,   100,   101,   102,
       0,   103,    92,   104,    93,     0,    94,    89,    95,    90,
      96,    91,    97,    98,   379,    99,   100,   101,   102,     0,
     103,     0,   104,   259,    92,     0,    93,     0,    94,    89,
      95,    90,    96,    91,    97,    98,     0,    99,   100,   101,
     102,     0,   103,   380,   104,    92,     0,    93,     0,    94,
       0,    95,     0,    96,     0,    97,    98,     0,    99,   100,
     101,   102,    89,   103,    90,   104,    91,    92,     0,    93,
       0,    94,     0,    95,     0,    96,     0,    97,    98,   381,
      99,   100,   101,   102,     0,   103,     0,   104,     0,    89,
       0,    90,     0,    91,     0,     0,     0,     0,     0,     0,
      92,     0,    93,     0,    94,     0,    95,     0,    96,   382,
      97,    98,     0,    99,   100,   101,   102,     0,   103,     0,
     104,     0,    89,     0,    90,     0,    91,    92,     0,    93,
       0,    94,     0,    95,     0,    96,     0,    97,    98,     0,
      99,   100,   101,   102,     0,   103,   383,   104,    89,     0,
      90,     0,    91,     0,     0,     0,     0,     0,     0,     0,
      92,     0,    93,     0,    94,     0,    95,     0,    96,     0,
      97,    98,     0,    99,   100,   101,   102,   384,   103,    89,
     104,    90,     0,    91,     0,     0,    92,     0,    93,     0,
      94,     0,    95,     0,    96,     0,    97,    98,     0,    99,
     100,   101,   102,    89,   103,    90,   104,    91,     0,     0,
       0,     0,     0,   385,     0,     0,     0,    92,     0,    93,
       0,    94,     0,    95,     0,    96,     0,    97,    98,     0,
      99,   100,   101,   102,     0,   103,     0,   104,     0,     0,
     386,    92,     0,    93,     0,    94,     0,    95,     0,    96,
       0,    97,    98,     0,    99,   100,   101,   102,     0,   103,
       0,   104
};

static const yytype_int16 yycheck[] =
{
      12,     4,     5,    15,     7,    17,     9,    19,    11,    21,
      16,    23,    24,    25,    26,    27,    28,    16,    30,    16,
      32,    16,    34,   222,    36,    37,    43,    39,    40,    85,
      42,    16,    60,    16,     0,    16,    90,    16,    16,    16,
      52,    16,    54,    16,    56,    16,    58,    16,    60,    16,
     119,    16,   122,    16,   106,    60,   110,   110,    16,    16,
      16,    16,    16,    16,    16,    16,   111,    16,   110,    16,
      16,    16,    16,    16,    16,    16,   110,   105,    16,   111,
     112,   113,   114,   115,   114,   115,    26,    27,   116,    29,
     118,   110,   120,   110,   122,    22,    23,    24,     3,     4,
     105,   110,     6,   135,     8,   137,    10,   137,   110,    13,
     110,   116,    16,   118,    18,   120,    20,   122,    22,   318,
     111,   112,   113,   114,   115,    29,   110,    31,   110,    33,
     110,    35,   106,   107,    38,   136,   135,    41,   135,    43,
     135,    25,    26,    27,   135,    49,   137,    51,   110,    53,
     135,    55,   135,    57,   135,    59,   135,   135,   135,   135,
     135,   111,   135,    41,   135,    79,   135,    43,   135,   172,
     135,   174,   135,   176,   110,   178,   375,   135,   135,   135,
     135,   135,   135,   135,   135,   188,   135,    91,   135,   135,
     135,   135,   135,   135,   135,    99,   100,   135,    26,    27,
     104,    81,    83,   215,   207,   217,   209,   219,   211,   111,
     112,   113,   114,   115,   226,    85,    87,   229,    90,   111,
     232,    90,   234,   127,    97,   281,   282,   283,   284,   285,
     242,    95,    95,   245,   100,   137,   248,   119,    30,   251,
     137,    43,   254,   122,   111,   273,   258,   275,   260,   277,
     110,   279,   110,   110,   266,   110,   268,    90,   270,    90,
     272,    97,    -1,   291,   112,   113,   114,   115,   273,   173,
     275,   175,   277,   177,   279,    -1,    -1,   333,    -1,   291,
     308,   309,   310,    22,    23,    24,   291,    -1,    -1,   137,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,   354,    -1,
      -1,    -1,   314,   308,   309,   310,    -1,    -1,   320,    -1,
      -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   342,
      -1,   344,    -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,
     353,    -1,   355,    -1,    -1,    -1,   368,    -1,    -1,    -1,
      -1,   373,    -1,    -1,   392,   393,   394,   395,    -1,   397,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,   393,   394,
     395,    -1,   397,   405,     6,     7,   408,     9,    10,    -1,
      12,    -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,
      -1,   315,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    -1,    37,    38,    -1,    40,    -1,
      42,    -1,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    -1,    58,    59,    -1,    61,
      62,    63,    -1,    65,    -1,    67,    68,    -1,    70,    -1,
      72,    73,    -1,    75,    76,    -1,    78,    -1,    80,    -1,
      82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,    91,
      92,    93,    94,    -1,    96,    -1,    98,    99,    -1,   101,
      -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,    -1,   120,   121,
      -1,   123,   124,    -1,   126,   127,    -1,   129,   130,    -1,
     132,   133,     6,     7,     8,     9,    10,    -1,    12,    -1,
      14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    -1,    37,    38,    40,    -1,    42,    -1,    44,
      -1,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    -1,    58,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    67,    68,    -1,    70,    -1,    72,    73,
      -1,    75,    76,    78,    -1,    80,    -1,    82,    -1,    84,
      -1,    86,    -1,    88,    89,    -1,    91,    92,    93,    94,
      -1,    96,    -1,    98,    -1,    99,    -1,   101,    -1,   103,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,    -1,   120,   121,    -1,   123,
     124,    -1,   126,   127,    -1,   129,   130,    -1,   132,   133,
       6,     7,    -1,     9,    10,    11,    12,    -1,    14,    15,
      -1,    -1,    18,    -1,    20,    21,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      -1,    37,    38,    40,    -1,    42,    -1,    44,    -1,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    -1,    58,    59,    -1,    61,    62,    63,    -1,    65,
      -1,    67,    68,    -1,    70,    -1,    72,    73,    -1,    75,
      76,    78,    -1,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    89,    -1,    91,    92,    93,    94,    -1,    96,
      -1,    98,    -1,    99,    -1,   101,    -1,   103,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,   120,   121,    -1,   123,   124,    -1,
     126,   127,    -1,   129,   130,    -1,   132,   133,     6,     7,
      -1,     9,    10,    -1,    12,    13,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    -1,    37,
      38,    40,    -1,    42,    -1,    44,    -1,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    -1,
      58,    59,    -1,    61,    62,    63,    -1,    65,    -1,    67,
      68,    -1,    70,    -1,    72,    73,    -1,    75,    76,    78,
      -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,    88,
      89,    -1,    91,    92,    93,    94,    -1,    96,    -1,    98,
      -1,    99,    -1,   101,    -1,   103,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,    -1,   120,   121,    -1,   123,   124,    -1,   126,   127,
      -1,   129,   130,    -1,   132,   133,     6,     7,    -1,     9,
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
     130,    -1,   132,   133,     6,     7,     8,     9,    10,    -1,
      12,    -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    -1,    37,    38,    40,    -1,    42,
      -1,    44,    -1,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    -1,    58,    59,    -1,    61,
      62,    63,    -1,    65,    -1,    67,    68,    -1,    70,    -1,
      72,    73,    -1,    75,    76,    78,    -1,    80,    -1,    82,
      -1,    84,    -1,    86,    -1,    88,    89,    -1,    91,    92,
      93,    94,    -1,    96,    -1,    98,    -1,    99,    -1,   101,
      -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,    -1,   120,   121,
      -1,   123,   124,    -1,   126,   127,    -1,   129,   130,    -1,
     132,   133,     6,     7,    -1,     9,    10,    11,    12,    -1,
      14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    -1,    37,    38,    40,    -1,    42,    -1,    44,
      -1,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    -1,    58,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    67,    68,    -1,    70,    -1,    72,    73,
      -1,    75,    76,    78,    -1,    80,    -1,    82,    -1,    84,
      -1,    86,    -1,    88,    89,    -1,    91,    92,    93,    94,
      -1,    96,    -1,    98,    -1,    99,    -1,   101,    -1,   103,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,    -1,   120,   121,    -1,   123,
     124,    -1,   126,   127,    -1,   129,   130,    -1,   132,   133,
       6,     7,    -1,     9,    10,    -1,    12,    13,    14,    15,
      -1,    -1,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      -1,    37,    38,    40,    -1,    42,    -1,    44,    -1,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    -1,    58,    59,    -1,    61,    62,    63,    -1,    65,
      -1,    67,    68,    -1,    70,    -1,    72,    73,    -1,    75,
      76,    78,    -1,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    89,    -1,    91,    92,    93,    94,    -1,    96,
      -1,    98,    -1,    99,    -1,   101,    -1,   103,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,   120,   121,    -1,   123,   124,    -1,
     126,   127,    -1,   129,   130,    -1,   132,   133,     6,     7,
      -1,     9,    10,    -1,    12,    -1,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    -1,    37,
      38,    40,    -1,    42,    -1,    44,    -1,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    -1,
      58,    59,    -1,    61,    62,    63,    -1,    65,    -1,    67,
      68,    -1,    70,    -1,    72,    73,    -1,    75,    76,    78,
      -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,    88,
      89,    -1,    91,    92,    93,    94,    -1,    96,    -1,    98,
      -1,    99,    -1,   101,    -1,   103,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,    -1,   120,   121,    -1,   123,   124,    -1,   126,   127,
      -1,   129,   130,    -1,   132,   133,     6,     7,     8,     9,
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
     130,    -1,   132,   133,     6,     7,    -1,     9,    10,    11,
      12,    -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    -1,    58,    59,    -1,    61,
      62,    63,    -1,    65,    -1,    67,    68,    -1,    70,    -1,
      72,    73,    -1,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101,
      -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,    -1,   120,   121,
      -1,   123,   124,    -1,   126,   127,    -1,   129,   130,    -1,
     132,   133,     6,     7,    -1,     9,    10,    -1,    12,    13,
      14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    -1,    58,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    67,    68,    -1,    70,    -1,    72,    73,
      -1,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,   101,    -1,   103,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,    -1,   120,   121,    -1,   123,
     124,    -1,   126,   127,    -1,   129,   130,    -1,   132,   133,
       6,     7,     8,     9,    10,    -1,    12,    -1,    14,    15,
      -1,    -1,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    -1,    58,    59,    -1,    61,    62,    63,    -1,    65,
      -1,    67,    68,    -1,    70,    -1,    72,    73,    -1,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,   101,    -1,   103,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,   120,   121,    -1,   123,   124,    -1,
     126,   127,    -1,   129,   130,    -1,   132,   133,     6,     7,
      -1,     9,    10,    11,    12,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    -1,
      58,    59,    -1,    61,    62,    63,    -1,    65,    -1,    67,
      68,    -1,    70,    -1,    72,    73,    -1,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,   101,    -1,   103,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,    -1,   120,   121,    -1,   123,   124,    -1,   126,   127,
      -1,   129,   130,    -1,   132,   133,     6,     7,    -1,     9,
      10,    -1,    12,    13,    14,    15,    -1,    -1,    18,    -1,
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
     130,    -1,   132,   133,     6,     7,    -1,     9,    10,    -1,
      12,    -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    -1,    58,    59,    -1,    61,
      62,    63,    -1,    65,    -1,    67,    68,    -1,    70,    -1,
      72,    73,    -1,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101,
     102,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,    -1,   120,   121,
      -1,   123,   124,    -1,   126,   127,    -1,   129,   130,    -1,
     132,   133,     6,     7,    -1,     9,    10,    -1,    12,    -1,
      14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    -1,    58,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    67,    68,    -1,    70,    -1,    72,    73,
      -1,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,   101,    -1,   103,
     104,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,    -1,   120,   121,    -1,   123,
     124,    -1,   126,   127,    -1,   129,   130,    -1,   132,   133,
       6,     7,    -1,     9,    10,    -1,    12,    -1,    14,    15,
      -1,    -1,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    -1,    58,    59,    -1,    61,    62,    63,    -1,    65,
      -1,    67,    68,    -1,    70,    -1,    72,    73,    -1,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,   101,    -1,   103,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,   120,   121,    -1,   123,   124,    -1,
     126,   127,    -1,   129,   130,    -1,   132,   133,     6,     7,
      -1,     9,    10,    -1,    12,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    -1,
      58,    59,    -1,    61,    62,    63,    -1,    65,    -1,    67,
      68,    -1,    70,    -1,    72,    73,    -1,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      42,    99,    44,   101,    -1,   103,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,    -1,   120,   121,     5,   123,   124,    -1,   126,   127,
      -1,   129,   130,    -1,   132,   133,    78,    40,    80,    42,
      82,    44,    84,    -1,    86,    -1,    88,    89,    -1,    91,
      92,    93,    94,    -1,    96,    -1,    98,    -1,    -1,    40,
      -1,    42,    -1,    44,    -1,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    40,    80,    42,    82,
      44,    84,    -1,    86,    -1,    88,    89,    -1,    91,    92,
      93,    94,   134,    96,    -1,    98,    -1,    78,    -1,    80,
      40,    82,    42,    84,    44,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    78,    96,    80,    98,    82,    -1,
      84,    -1,    86,    -1,    88,    89,    -1,    91,    92,    93,
      94,   134,    96,    40,    98,    42,    -1,    44,    78,    -1,
      80,    -1,    82,    -1,    84,    -1,    86,    -1,    88,    89,
      -1,    91,    92,    93,    94,    40,    96,    42,    98,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    78,    -1,    80,    40,    82,    42,    84,    44,    86,
      -1,    88,    89,    -1,    91,    92,    93,    94,    -1,    96,
      -1,    98,    -1,    78,    -1,    80,    40,    82,    42,    84,
      44,    86,    -1,    88,    89,    -1,    91,    92,    93,    94,
      -1,    96,    78,    98,    80,    40,    82,    42,    84,    44,
      86,    -1,    88,    89,   131,    91,    92,    93,    94,    -1,
      96,    -1,    98,    -1,    78,    -1,    80,    -1,    82,    -1,
      84,    -1,    86,   128,    88,    89,    -1,    91,    92,    93,
      94,    -1,    96,    78,    98,    80,    -1,    82,    -1,    84,
      -1,    86,   128,    88,    89,    -1,    91,    92,    93,    94,
      -1,    96,    -1,    98,    -1,    18,    19,    -1,    -1,    -1,
      -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    40,    -1,    42,
     125,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    42,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    78,    40,    80,    42,    82,
      44,    84,    -1,    86,    -1,    88,    89,    -1,    91,    92,
      93,    94,    78,    96,    80,    98,    82,    -1,    84,    -1,
      86,    -1,    88,    89,    33,    91,    92,    93,    94,    -1,
      96,    40,    98,    42,    78,    44,    80,    -1,    82,    -1,
      84,    -1,    86,    -1,    88,    89,    -1,    91,    92,    93,
      94,    34,    96,    36,    98,    -1,    -1,    40,    -1,    42,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      36,    80,    -1,    82,    40,    84,    42,    86,    44,    88,
      89,    -1,    91,    92,    93,    94,    -1,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,    82,
      -1,    84,    -1,    86,    -1,    88,    89,    -1,    91,    92,
      93,    94,    78,    96,    80,    98,    82,    -1,    84,    -1,
      86,    -1,    88,    89,    -1,    91,    92,    93,    94,    -1,
      96,    37,    98,    39,    40,    -1,    42,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    80,    -1,    82,    -1,    84,    -1,
      86,    -1,    88,    89,    -1,    91,    92,    93,    94,    78,
      96,    80,    98,    82,    -1,    84,    -1,    86,    -1,    88,
      89,    -1,    91,    92,    93,    94,    40,    96,    42,    98,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    -1,    -1,    40,    -1,    42,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    -1,    -1,    -1,    78,    -1,    80,    -1,    82,    -1,
      84,    -1,    86,    -1,    88,    89,    -1,    91,    92,    93,
      94,    78,    96,    80,    98,    82,    40,    84,    42,    86,
      44,    88,    89,    -1,    91,    92,    93,    94,    -1,    96,
      -1,    98,    -1,    -1,    -1,    59,    60,    40,    -1,    42,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    80,    -1,    82,    62,
      84,    64,    86,    -1,    88,    89,    -1,    91,    92,    93,
      94,    -1,    96,    -1,    98,    78,    40,    80,    42,    82,
      44,    84,    -1,    86,    -1,    88,    89,    -1,    91,    92,
      93,    94,    -1,    96,    -1,    98,    -1,    40,    -1,    42,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    72,    -1,
      74,    -1,    -1,    -1,    78,    -1,    80,    -1,    82,    40,
      84,    42,    86,    44,    88,    89,    47,    91,    92,    93,
      94,    -1,    96,    -1,    98,    78,    -1,    80,    -1,    82,
      40,    84,    42,    86,    44,    88,    89,    47,    91,    92,
      93,    94,    -1,    96,    -1,    98,    -1,    78,    -1,    80,
      -1,    82,    40,    84,    42,    86,    44,    88,    89,    47,
      91,    92,    93,    94,    -1,    96,    -1,    98,    78,    -1,
      80,    -1,    82,    40,    84,    42,    86,    44,    88,    89,
      47,    91,    92,    93,    94,    -1,    96,    -1,    98,    -1,
      78,    -1,    80,    -1,    82,    40,    84,    42,    86,    44,
      88,    89,    47,    91,    92,    93,    94,    -1,    96,    -1,
      98,    78,    40,    80,    42,    82,    44,    84,    -1,    86,
      -1,    88,    89,    -1,    91,    92,    93,    94,    -1,    96,
      -1,    98,    -1,    78,    -1,    80,    -1,    82,    66,    84,
      -1,    86,    -1,    88,    89,    -1,    91,    92,    93,    94,
      78,    96,    80,    98,    82,    40,    84,    42,    86,    44,
      88,    89,    -1,    91,    92,    93,    94,    -1,    96,    -1,
      98,    -1,    -1,    -1,    40,    -1,    42,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    80,    40,    82,    42,    84,
      44,    86,    -1,    88,    89,    71,    91,    92,    93,    94,
      -1,    96,    78,    98,    80,    -1,    82,    40,    84,    42,
      86,    44,    88,    89,    47,    91,    92,    93,    94,    -1,
      96,    -1,    98,    77,    78,    -1,    80,    -1,    82,    40,
      84,    42,    86,    44,    88,    89,    -1,    91,    92,    93,
      94,    -1,    96,    54,    98,    78,    -1,    80,    -1,    82,
      -1,    84,    -1,    86,    -1,    88,    89,    -1,    91,    92,
      93,    94,    40,    96,    42,    98,    44,    78,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    89,    57,
      91,    92,    93,    94,    -1,    96,    -1,    98,    -1,    40,
      -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    80,    -1,    82,    -1,    84,    -1,    86,    60,
      88,    89,    -1,    91,    92,    93,    94,    -1,    96,    -1,
      98,    -1,    40,    -1,    42,    -1,    44,    78,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    -1,    96,    64,    98,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,
      88,    89,    -1,    91,    92,    93,    94,    69,    96,    40,
      98,    42,    -1,    44,    -1,    -1,    78,    -1,    80,    -1,
      82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,    91,
      92,    93,    94,    40,    96,    42,    98,    44,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    -1,    96,    -1,    98,    -1,    -1,
      77,    78,    -1,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    89,    -1,    91,    92,    93,    94,    -1,    96,
      -1,    98
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,   139,   165,     6,     7,     9,    10,    12,
      14,    15,    18,    20,    21,    31,    32,    34,    35,    37,
      38,    45,    46,    48,    49,    50,    51,    52,    53,    55,
      56,    58,    59,    61,    62,    63,    65,    67,    68,    70,
      72,    73,    75,    76,    99,   101,   103,   105,   117,   118,
     120,   121,   123,   124,   126,   127,   129,   130,   132,   133,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   159,   160,   161,
     162,   163,   164,   177,   180,   183,    16,   176,     0,    40,
      42,    44,    78,    80,    82,    84,    86,    88,    89,    91,
      92,    93,    94,    96,    98,   140,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   140,   176,   140,   176,
     140,   176,   140,   165,   176,    22,    23,    24,   157,   165,
     176,   165,   176,   165,   176,   165,   176,   165,   165,   165,
     165,   165,   165,   176,   165,   176,   165,   176,   165,   176,
     165,   165,   176,   165,   165,   176,   165,   176,   106,   178,
     119,   176,   122,   176,   165,   176,   165,   176,   165,   176,
     165,   176,     6,     7,     9,    10,    12,    14,    15,   141,
     165,   177,   106,   107,   179,   179,   111,    16,   135,   110,
      43,   110,   176,   110,   110,   110,   110,   110,   110,   110,
     176,   176,   110,   110,   110,   176,     8,   135,    11,   135,
      13,   135,    17,    18,    19,   135,    25,    26,    27,   158,
     176,    22,    23,    24,    31,    33,   135,    34,    36,   135,
      37,    39,   135,    47,   135,    47,    47,    47,    47,    47,
      53,    54,   135,    56,    57,   135,    59,    60,   135,    62,
      64,   135,    66,    69,   135,    71,    72,    74,   135,    77,
     135,   136,   135,   135,   135,   125,   135,   128,   135,   131,
     135,   134,   135,   140,   176,   140,   176,   140,   176,   140,
       5,   111,   112,   113,   114,   115,   135,   137,   135,   110,
     111,   140,    41,    43,   135,    79,    81,    83,    85,    87,
      90,    90,   135,   135,    95,    95,    97,   135,   140,   140,
     140,   165,   165,   176,    26,    27,    29,   165,   135,    25,
     158,   176,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   111,   100,   119,   122,   165,   165,   165,
     165,     8,   135,    11,   135,    13,   135,    17,   179,   179,
     179,   179,   179,   181,   111,   185,   110,   165,   110,   110,
      90,   110,   110,     8,    11,    13,    19,    28,   135,   165,
     176,    30,    25,   158,   165,   135,    33,    36,    39,    47,
      54,    57,    60,    64,    69,    74,    77,   179,   125,   128,
     131,   134,   140,   140,   140,   140,   179,   140,     5,    43,
      90,    90,    97,   165,    28,   135,   165,    25,   158,     8,
      11,    13,   102,   182,   104,   184,    28,   165,    25,   165,
      28,    25
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
#line 153 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 157 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 161 "gtkdialog_parser.y"
    { 
    		token_store_attr(PUSH | WIDGET_WINDOW, (yyvsp[(2) - (6)].nvval)); 
		start_up();
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 169 "gtkdialog_parser.y"
    { 
		token_store(SUM);      
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 174 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
	}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 177 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
		token_store(SUM);      
	}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 181 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 184 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(3) - (6)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 188 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
	}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 191 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
		token_store(SUM);      
	}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 195 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 198 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(3) - (6)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 202 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
	}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 205 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
		token_store(SUM);      
	}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 209 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 212 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(3) - (6)].nvval));
		token_store(SUM);      
	}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 216 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(1) - (3)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
	}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 220 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(2) - (4)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
		token_store(SUM);      
	}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 252 "gtkdialog_parser.y"
    {
                          token_store(PUSH | WIDGET_ENTRY); 
			 }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 255 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_ENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 258 "gtkdialog_parser.y"
    {
                  yyerror("</entry> expected instead of <entry>.");}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 263 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_EDIT); 
	}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 266 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_EDIT, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 269 "gtkdialog_parser.y"
    {
    		yyerror("</edit> expected instead of <edit>.");
	}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 275 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TREE); 
	}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 278 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_TREE, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 281 "gtkdialog_parser.y"
    {
   		yyerror("</tree> expected instead of <tree>.");
	}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 287 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHOOSER); 
	}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 290 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_CHOOSER, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 293 "gtkdialog_parser.y"
    {
		yyerror("</chooser> expected instead of <chooser>.");
	}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 299 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_LABEL); 
	}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 302 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_LABEL, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 305 "gtkdialog_parser.y"
    {yyerror("</text> expected instead of <text>.");}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 309 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_BUTTON);  }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 310 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_BUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 313 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_OKBUTTON);}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 314 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_CANCELBUTTON);}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 315 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_HELPBUTTON);}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 316 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_NOBUTTON);}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 317 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_YESBUTTON);}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 321 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHECKBOX);
	}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 324 "gtkdialog_parser.y"
    {
		//token_store_with_tag_attributes(PUSH | WIDGET_CHECKBOX, $2);
                token_store_attr(PUSH | WIDGET_CHECKBOX, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 328 "gtkdialog_parser.y"
    {
		yyerror("</checkbox> expected instead of <checkbox>.");
	}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 334 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_RADIO);
           }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 337 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_RADIO, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 340 "gtkdialog_parser.y"
    {
		yyerror("</radiobutton> expected instead of <radiobutton>.");
           }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 346 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_PROGRESS);
           }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 349 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_PROGRESS, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 352 "gtkdialog_parser.y"
    {
		yyerror("</progressbar> expected instead of <progressbar>.");
           }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 358 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_LIST); 
	}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 361 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_LIST, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 364 "gtkdialog_parser.y"
    {
    		yyerror("</list> expected instead of <list>.");
	}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 370 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_TABLE);}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 374 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_COMBO);
	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 377 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_COMBO, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 383 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_GVIM);}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 387 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_PIXMAP);}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 388 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_PIXMAP, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 394 "gtkdialog_parser.y"
    {
		yyerror("Empty menubar without a single <menu> tag.");
	}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 397 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUBAR);
	}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 403 "gtkdialog_parser.y"
    {
		yyerror("Empty menu without <menuitem> tag.");
	}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 406 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENU);
	}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 409 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENU, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 412 "gtkdialog_parser.y"
    {
		yyerror("Empty menu without <menuitem> tag.");
	}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 415 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENU);
		token_store(SUM);
	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 419 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENU, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);
	}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 426 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM);
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 429 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(2) - (5)].nvval));
    	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 432 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM);
		token_store(SUM);
	}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 436 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(3) - (6)].nvval));
		token_store(SUM);
    	}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 440 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEMSEPARATOR);
		token_store(SUM);
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 453 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSEPARATOR);
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 456 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 462 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSEPARATOR);
	}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 465 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 471 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXTEXT);
	}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 474 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXTEXT, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 480 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXENTRY);
	}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 483 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 489 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSCALE);
	}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 492 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSCALE, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 498 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSCALE);
	}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 501 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSCALE, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 521 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_LABEL, (yyvsp[(2) - (3)].cval));     }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 526 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_VARIABLE, (yyvsp[(2) - (3)].cval)); }
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 531 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_VISIBLE, (yyvsp[(2) - (3)].cval));  }
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 536 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_DEFAULT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 541 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_WIDTH, (yyvsp[(2) - (3)].cval));    }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 546 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_HEIGHT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 551 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_SHELL,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 554 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 557 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 560 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 563 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, "", (yyvsp[(2) - (4)].nvval)); 
	}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 569 "gtkdialog_parser.y"
    {
	         fprintf( stderr, "<output>: Not implemented.\n" ); 
	}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 572 "gtkdialog_parser.y"
    {
         	token_store_with_argument(SET|ATTR_OUTPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 578 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET|ATTR_ACTION, (yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 581 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET | ATTR_ACTION, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 588 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET | ATTR_ITEM, (yyvsp[(2) - (3)].cval));
	}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 591 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_ITEM, "");
    	}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 594 "gtkdialog_parser.y"
    {
		      token_store_with_argument_attr(SET | ATTR_ITEM, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
                    }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 600 "gtkdialog_parser.y"
    {
       		(yyval.nvval) = new_tag_attributeset((yyvsp[(1) - (3)].cval), (yyvsp[(3) - (3)].cval)); 
	}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 603 "gtkdialog_parser.y"
    { 
       		(yyval.nvval) = add_tag_attribute((yyvsp[(1) - (4)].nvval), (yyvsp[(2) - (4)].cval), (yyvsp[(4) - (4)].cval)); 
	}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 610 "gtkdialog_parser.y"
    { 
		token_store(SHOW);     
	}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 613 "gtkdialog_parser.y"
    {
  		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
	}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 616 "gtkdialog_parser.y"
    {
		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
		instruction_set_jump((yyvsp[(6) - (6)].ival) + 1, (yyvsp[(1) - (6)].ival));
	}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 623 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMASSG | VARIABLE_NAME, (yyvsp[(1) - (4)].cval)); 
	}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 629 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | VARIABLE_NAME, (yyvsp[(1) - (1)].cval)); 
	}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 632 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | CONST_NUMBER, (yyvsp[(1) - (1)].cval)); 
  	}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 635 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_ADD);
	}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 638 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_SUBST);
	}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 641 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_MULT);
	}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 644 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_DIV);
	}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 647 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_EQ);
	}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 650 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_NE);
	}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 660 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 667 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 671 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 675 "gtkdialog_parser.y"
    {
		token_store(GOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 682 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
    }
    break;



/* Line 1455 of yacc.c  */
#line 3827 "gtkdialog_parser.c"
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
#line 688 "gtkdialog_parser.y"


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


