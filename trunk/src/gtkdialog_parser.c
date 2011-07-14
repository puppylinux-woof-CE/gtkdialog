
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
     EMENU = 279,
     MENUITEM = 280,
     PART_MENUITEM = 281,
     EMENUITEM = 282,
     MENUITEMSEPARATOR = 283,
     EMENUITEMSEPARATOR = 284,
     EDIT = 285,
     PART_EDIT = 286,
     EEDIT = 287,
     TREE = 288,
     PART_TREE = 289,
     ETREE = 290,
     CHOOSER = 291,
     PART_CHOOSER = 292,
     ECHOOSER = 293,
     LABEL = 294,
     ELABEL = 295,
     ITEM = 296,
     EITEM = 297,
     PART_ITEM = 298,
     BUTTON = 299,
     PART_BUTTON = 300,
     EBUTTON = 301,
     BUTTONOK = 302,
     BUTTONCANCEL = 303,
     BUTTONHELP = 304,
     BUTTONYES = 305,
     BUTTONNO = 306,
     CHECKBOX = 307,
     ECHECKBOX = 308,
     PART_CHECKBOX = 309,
     RADIO = 310,
     ERADIO = 311,
     PART_RADIO = 312,
     PROGRESS = 313,
     EPROGRESS = 314,
     PART_PROGRESS = 315,
     LIST = 316,
     PART_LIST = 317,
     ELIST = 318,
     TABLE = 319,
     ETABLE = 320,
     COMBO = 321,
     PART_COMBO = 322,
     ECOMBO = 323,
     GVIM = 324,
     EGVIM = 325,
     TEXT = 326,
     PART_TEXT = 327,
     ETEXT = 328,
     PIXMAP = 329,
     PART_PIXMAP = 330,
     EPIXMAP = 331,
     DEFAULT = 332,
     EDEFAULT = 333,
     VISIBLE = 334,
     EVISIBLE = 335,
     VARIABLE = 336,
     EVARIABLE = 337,
     WIDTH = 338,
     EWIDTH = 339,
     HEIGHT = 340,
     EHEIGHT = 341,
     INPUT = 342,
     INPUTFILE = 343,
     EINPUT = 344,
     PART_INPUT = 345,
     PART_INPUTFILE = 346,
     OUTPUT = 347,
     OUTPUTFILE = 348,
     EOUTPUT = 349,
     ACTION = 350,
     EACTION = 351,
     PART_ACTION = 352,
     COMM = 353,
     ENDCOMM = 354,
     IF = 355,
     ENDIF = 356,
     WHILE = 357,
     EWHILE = 358,
     SHOW_WIDGETS = 359,
     EMB_VARIABLE = 360,
     EMB_NUMBER = 361,
     END_OF_FILE = 362,
     NUMBER = 363,
     STRING = 364,
     UMINUS = 365,
     HSEPARATOR = 366,
     PART_HSEPARATOR = 367,
     EHSEPARATOR = 368,
     VSEPARATOR = 369,
     PART_VSEPARATOR = 370,
     EVSEPARATOR = 371,
     COMBOBOXTEXT = 372,
     PART_COMBOBOXTEXT = 373,
     ECOMBOBOXTEXT = 374,
     COMBOBOXENTRY = 375,
     PART_COMBOBOXENTRY = 376,
     ECOMBOBOXENTRY = 377,
     HSCALE = 378,
     PART_HSCALE = 379,
     EHSCALE = 380,
     VSCALE = 381,
     PART_VSCALE = 382,
     EVSCALE = 383
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
#define EMENU 279
#define MENUITEM 280
#define PART_MENUITEM 281
#define EMENUITEM 282
#define MENUITEMSEPARATOR 283
#define EMENUITEMSEPARATOR 284
#define EDIT 285
#define PART_EDIT 286
#define EEDIT 287
#define TREE 288
#define PART_TREE 289
#define ETREE 290
#define CHOOSER 291
#define PART_CHOOSER 292
#define ECHOOSER 293
#define LABEL 294
#define ELABEL 295
#define ITEM 296
#define EITEM 297
#define PART_ITEM 298
#define BUTTON 299
#define PART_BUTTON 300
#define EBUTTON 301
#define BUTTONOK 302
#define BUTTONCANCEL 303
#define BUTTONHELP 304
#define BUTTONYES 305
#define BUTTONNO 306
#define CHECKBOX 307
#define ECHECKBOX 308
#define PART_CHECKBOX 309
#define RADIO 310
#define ERADIO 311
#define PART_RADIO 312
#define PROGRESS 313
#define EPROGRESS 314
#define PART_PROGRESS 315
#define LIST 316
#define PART_LIST 317
#define ELIST 318
#define TABLE 319
#define ETABLE 320
#define COMBO 321
#define PART_COMBO 322
#define ECOMBO 323
#define GVIM 324
#define EGVIM 325
#define TEXT 326
#define PART_TEXT 327
#define ETEXT 328
#define PIXMAP 329
#define PART_PIXMAP 330
#define EPIXMAP 331
#define DEFAULT 332
#define EDEFAULT 333
#define VISIBLE 334
#define EVISIBLE 335
#define VARIABLE 336
#define EVARIABLE 337
#define WIDTH 338
#define EWIDTH 339
#define HEIGHT 340
#define EHEIGHT 341
#define INPUT 342
#define INPUTFILE 343
#define EINPUT 344
#define PART_INPUT 345
#define PART_INPUTFILE 346
#define OUTPUT 347
#define OUTPUTFILE 348
#define EOUTPUT 349
#define ACTION 350
#define EACTION 351
#define PART_ACTION 352
#define COMM 353
#define ENDCOMM 354
#define IF 355
#define ENDIF 356
#define WHILE 357
#define EWHILE 358
#define SHOW_WIDGETS 359
#define EMB_VARIABLE 360
#define EMB_NUMBER 361
#define END_OF_FILE 362
#define NUMBER 363
#define STRING 364
#define UMINUS 365
#define HSEPARATOR 366
#define PART_HSEPARATOR 367
#define EHSEPARATOR 368
#define VSEPARATOR 369
#define PART_VSEPARATOR 370
#define EVSEPARATOR 371
#define COMBOBOXTEXT 372
#define PART_COMBOBOXTEXT 373
#define ECOMBOBOXTEXT 374
#define COMBOBOXENTRY 375
#define PART_COMBOBOXENTRY 376
#define ECOMBOBOXENTRY 377
#define HSCALE 378
#define PART_HSCALE 379
#define EHSCALE 380
#define VSCALE 381
#define PART_VSCALE 382
#define EVSCALE 383




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
#line 460 "gtkdialog_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 472 "gtkdialog_parser.c"

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
#define YYLAST   3882

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  137
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNRULES -- Number of states.  */
#define YYNSTATES  410

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   383

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   136,     2,     2,     2,     2,     2,     2,
       2,     2,   113,   112,     2,   111,     2,   114,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   135,     2,
       2,   110,   134,     2,     2,     2,     2,     2,     2,     2,
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
     105,   106,   107,   108,   109,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133
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
     309,   315,   319,   323,   329,   332,   336,   339,   344,   348,
     354,   358,   364,   369,   376,   380,   383,   388,   391,   396,
     400,   406,   410,   416,   420,   426,   430,   436,   437,   440,
     443,   446,   449,   452,   455,   458,   461,   464,   467,   471,
     475,   479,   483,   487,   491,   495,   501,   505,   511,   516,
     520,   524,   528,   534,   538,   541,   547,   551,   556,   561,
     563,   570,   577,   582,   584,   586,   590,   594,   598,   602,
     606,   611,   613,   614,   616,   618,   620
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     138,     0,    -1,   164,   139,    -1,     3,   139,   164,     5,
      -1,     4,   175,   134,   139,   164,     5,    -1,   140,    -1,
     139,   140,    -1,   176,    -1,   139,   176,    -1,     6,   139,
       8,    -1,   139,     6,   139,     8,    -1,     7,   175,   134,
     139,     8,    -1,   139,     7,   175,   134,   139,     8,    -1,
       9,   139,    11,    -1,   139,     9,   139,    11,    -1,    10,
     175,   134,   139,    11,    -1,   139,    10,   175,   134,   139,
      11,    -1,    12,   139,    13,    -1,   139,    12,   139,    13,
      -1,    14,   175,   134,   139,    13,    -1,   139,    14,   175,
     134,   139,    13,    -1,    15,   139,    17,    -1,   139,    15,
     139,    17,    -1,   145,    -1,   141,    -1,   142,    -1,   143,
      -1,   144,    -1,   146,    -1,   147,    -1,   148,    -1,   149,
      -1,   150,    -1,   151,    -1,   152,    -1,   154,    -1,   153,
      -1,   155,    -1,   158,    -1,   159,    -1,   160,    -1,   161,
      -1,   162,    -1,   163,    -1,    18,   164,    19,    -1,    20,
     175,   134,   164,    19,    -1,    18,   164,    18,    -1,    30,
     164,    32,    -1,    31,   175,   134,   164,    32,    -1,    30,
     164,    30,    -1,    33,   164,    35,    -1,    34,   175,   134,
     164,    35,    -1,    33,   164,    33,    -1,    36,   164,    38,
      -1,    37,   175,   134,   164,    38,    -1,    36,   164,    36,
      -1,    71,   164,    73,    -1,    72,   175,   134,   164,    73,
      -1,    71,   164,    71,    -1,    44,   164,    46,    -1,    45,
     175,   134,   164,    46,    -1,    47,   164,    46,    -1,    48,
     164,    46,    -1,    49,   164,    46,    -1,    51,   164,    46,
      -1,    50,   164,    46,    -1,    52,   164,    53,    -1,    54,
     175,   134,   164,    53,    -1,    52,   164,    52,    -1,    55,
     164,    56,    -1,    57,   175,   134,   164,    56,    -1,    55,
     164,    55,    -1,    58,   164,    59,    -1,    60,   175,   134,
     164,    59,    -1,    58,   164,    58,    -1,    61,   164,    63,
      -1,    62,   175,   134,   164,    63,    -1,    61,   164,    61,
      -1,    64,   164,    65,    -1,    66,   164,    68,    -1,    67,
     175,   134,   164,    68,    -1,    69,   164,    70,    -1,    74,
     164,    76,    -1,    75,   175,   134,   164,    76,    -1,    21,
      22,    -1,    21,   156,    22,    -1,    23,    24,    -1,    23,
     157,   164,    24,    -1,   156,    23,    24,    -1,   156,    23,
     157,   164,    24,    -1,    25,   164,    27,    -1,    26,   175,
     134,   164,    27,    -1,   157,    25,   164,    27,    -1,   157,
      26,   175,   134,   164,    27,    -1,   157,    28,    29,    -1,
     116,   118,    -1,   117,   175,   134,   118,    -1,   119,   121,
      -1,   120,   175,   134,   121,    -1,   122,   164,   124,    -1,
     123,   175,   134,   164,   124,    -1,   125,   164,   127,    -1,
     126,   175,   134,   164,   127,    -1,   128,   164,   130,    -1,
     129,   175,   134,   164,   130,    -1,   131,   164,   133,    -1,
     132,   175,   134,   164,   133,    -1,    -1,   164,   168,    -1,
     164,   167,    -1,   164,   166,    -1,   164,   165,    -1,   164,
     169,    -1,   164,   170,    -1,   164,   171,    -1,   164,   172,
      -1,   164,   173,    -1,   164,   174,    -1,    39,   109,    40,
      -1,    81,   109,    82,    -1,    79,   109,    80,    -1,    77,
     109,    78,    -1,    83,   109,    84,    -1,    85,   109,    86,
      -1,    87,   109,    89,    -1,    90,   175,   134,   109,    89,
      -1,    88,   109,    89,    -1,    91,   175,   134,   109,    89,
      -1,    91,   175,   134,    89,    -1,    92,   109,    94,    -1,
      93,   109,    94,    -1,    95,   109,    96,    -1,    97,   175,
     134,   109,    96,    -1,    41,   109,    42,    -1,    41,    42,
      -1,    43,   175,   134,   109,    42,    -1,    16,   110,   109,
      -1,   175,    16,   110,   109,    -1,    98,   177,   134,    99,
      -1,   104,    -1,   179,   178,   134,   180,   139,   181,    -1,
     182,   178,   134,   184,   139,   183,    -1,   105,   135,   110,
     178,    -1,   105,    -1,   106,    -1,   178,   112,   178,    -1,
     178,   111,   178,    -1,   178,   113,   178,    -1,   178,   114,
     178,    -1,   178,   110,   178,    -1,   178,   136,   110,   178,
      -1,   100,    -1,    -1,   101,    -1,   102,    -1,   103,    -1,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   152,   152,   156,   160,   167,   168,   171,   172,   173,
     176,   180,   183,   187,   190,   194,   197,   201,   204,   208,
     211,   215,   219,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   251,   254,   257,   262,   265,   268,
     274,   277,   280,   286,   289,   292,   298,   301,   304,   308,
     309,   312,   313,   314,   315,   316,   320,   323,   327,   333,
     336,   339,   345,   348,   351,   357,   360,   363,   369,   373,
     376,   382,   386,   387,   393,   396,   400,   401,   402,   403,
     410,   413,   416,   420,   424,   437,   440,   446,   449,   455,
     458,   464,   467,   473,   476,   482,   485,   490,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   505,   510,
     515,   520,   525,   530,   535,   538,   541,   544,   547,   553,
     556,   562,   565,   572,   575,   578,   584,   587,   593,   594,
     597,   600,   607,   613,   616,   619,   622,   625,   628,   631,
     634,   640,   644,   651,   655,   659,   666
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
  "ENTRY", "EENTRY", "PART_ENTRY", "MENUBAR", "EMENUBAR", "MENU", "EMENU",
  "MENUITEM", "PART_MENUITEM", "EMENUITEM", "MENUITEMSEPARATOR",
  "EMENUITEMSEPARATOR", "EDIT", "PART_EDIT", "EEDIT", "TREE", "PART_TREE",
  "ETREE", "CHOOSER", "PART_CHOOSER", "ECHOOSER", "LABEL", "ELABEL",
  "ITEM", "EITEM", "PART_ITEM", "BUTTON", "PART_BUTTON", "EBUTTON",
  "BUTTONOK", "BUTTONCANCEL", "BUTTONHELP", "BUTTONYES", "BUTTONNO",
  "CHECKBOX", "ECHECKBOX", "PART_CHECKBOX", "RADIO", "ERADIO",
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
      61,    45,    43,    42,    47,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,    62,    58,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   137,   138,   138,   138,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   141,   141,   141,   142,   142,   142,
     143,   143,   143,   144,   144,   144,   145,   145,   145,   146,
     146,   146,   146,   146,   146,   146,   147,   147,   147,   148,
     148,   148,   149,   149,   149,   150,   150,   150,   151,   152,
     152,   153,   154,   154,   155,   155,   156,   156,   156,   156,
     157,   157,   157,   157,   157,   158,   158,   159,   159,   160,
     160,   161,   161,   162,   162,   163,   163,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   165,   166,
     167,   168,   169,   170,   171,   171,   171,   171,   171,   172,
     172,   173,   173,   174,   174,   174,   175,   175,   176,   176,
     176,   176,   177,   178,   178,   178,   178,   178,   178,   178,
     178,   179,   180,   181,   182,   183,   184
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
       5,     3,     3,     5,     2,     3,     2,     4,     3,     5,
       3,     5,     4,     6,     3,     2,     4,     2,     4,     3,
       5,     3,     5,     3,     5,     3,     5,     0,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     5,     3,     5,     4,     3,
       3,     3,     5,     3,     2,     5,     3,     4,     4,     1,
       6,     6,     4,     1,     1,     3,     3,     3,     3,     3,
       4,     1,     0,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     0,   107,     0,   107,     0,   107,
       0,   107,     0,   107,   107,   107,   107,   107,   107,     0,
     107,     0,   107,     0,   107,     0,   107,   107,     0,   107,
     107,     0,   107,     0,     0,   151,   154,   139,     0,     0,
       0,     0,   107,     0,   107,     0,   107,     0,   107,     0,
     107,     5,    24,    25,    26,    27,    23,    28,    29,    30,
      31,    32,    33,    34,    36,    35,    37,    38,    39,    40,
      41,    42,    43,     7,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,   111,   110,   109,   108,
     112,   113,   114,   115,   116,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
       0,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       8,   143,   144,     0,     0,     0,     0,     0,     0,   134,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,     0,    13,     0,    17,
       0,    21,    46,    44,   107,    86,   107,     0,   107,    85,
       0,    49,    47,   107,    52,    50,   107,    55,    53,   107,
      59,   107,    61,    62,    63,    65,    64,    68,    66,   107,
      71,    69,   107,    74,    72,   107,    77,    75,   107,    78,
      79,   107,    81,    58,    56,   107,    82,   107,     0,     0,
       0,     0,    99,   107,   101,   107,   103,   107,   105,   107,
       0,     0,     0,     0,     0,     0,     0,     3,     0,     0,
       0,     0,     0,   152,     0,   156,   136,     0,   107,   118,
     133,     0,   121,   120,   119,   122,   123,   124,   126,     0,
       0,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,    88,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
      96,    98,     0,     0,     0,     0,    10,     0,    14,     0,
      18,     0,    22,   149,   146,   145,   147,   148,     0,     0,
       0,   137,     0,     0,     0,   128,     0,     0,    11,    15,
      19,    45,    90,   107,     0,     0,    94,    87,     0,    48,
      51,    54,    60,    67,    70,    73,    76,    80,    57,    83,
     142,   100,   102,   104,   106,     0,     0,     0,     0,   150,
       0,     4,   135,   125,   127,   132,     0,    92,   107,    89,
      12,    16,    20,   153,   140,   155,   141,    91,     0,    93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,   127,
     218,    77,    78,    79,    80,    81,    82,     4,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    87,    83,
     158,   183,    84,   348,   404,    85,   406,   350
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -29
static const yytype_int16 yypact[] =
{
      81,  2516,    34,    93,   357,  2516,    34,  2516,    34,  2516,
      34,  2516,   -29,    34,   135,   -29,    34,   -29,    34,   -29,
      34,   -29,    34,   -29,   -29,   -29,   -29,   -29,   -29,    34,
     -29,    34,   -29,    34,   -29,    34,   -29,   -29,    34,   -29,
     -29,    34,   -29,    34,   -26,   -29,   -29,   -29,   -22,    34,
      -9,    34,   -29,    34,   -29,    34,   -29,    34,   -29,    34,
    2643,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,    28,    28,   -11,    -6,   -29,     9,
      39,    34,    15,    20,    27,    29,    45,    64,    70,    34,
      34,    73,    83,    85,    34,  2643,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   484,     1,   611,     3,
     738,     5,   865,  3000,     7,   -29,   121,   137,  3022,    10,
    3065,    18,  3146,    19,  3359,    21,  3381,  3402,  3424,  3445,
    3467,  3218,    22,  3235,    31,  3278,    33,  3299,    35,  3484,
    3527,    37,  3546,  3338,    41,  3568,    43,   -19,   -13,   -29,
      44,   -29,    46,  2901,    47,  2860,    49,  2798,    51,  2699,
      52,  2516,    34,  2516,    34,  2516,    34,  2516,   -29,   229,
     -29,   -29,   -29,    -4,   175,    87,    30,  2516,    91,   -29,
     101,    53,    84,    86,    94,    77,    78,    74,   109,    54,
      55,    96,   106,   112,    57,   -29,  2516,   -29,  2516,   -29,
    2516,   -29,   -29,   -29,   -29,   -29,   -29,    34,    61,   -29,
     125,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   100,   113,
      97,    99,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     992,    59,  1119,    67,  1246,    75,  1373,   -29,    28,    28,
      28,    28,    28,   -29,   108,   -29,   -29,   117,  2643,   -29,
     -29,   119,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   120,
      16,   -29,   -29,   -29,   122,  1500,  1627,  1754,  2981,   737,
      79,   -29,    34,   203,   483,   -29,    61,  3043,  3086,  3163,
    3589,  3611,  3644,  3671,  3704,  3730,  3761,  3785,    28,   -29,
     -29,   -29,  2920,  2879,  2819,  2738,   -29,  2516,   -29,  2516,
     -29,  2516,   -29,   -10,     6,     6,   102,   102,  2516,    28,
    2516,   -29,  2759,   193,   148,   -29,   152,   153,   -29,   -29,
     -29,   -29,   -29,   -29,   864,    82,   -29,   -29,   610,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     111,   -29,   -29,   -29,   -29,  1881,  2008,  2135,  2262,   -10,
    2389,   -29,   -29,   -29,   -29,   -29,   991,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,  1118,   -29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,    -3,   -28,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
      32,   -29,   -29,   -29,   -29,   -29,   -29,   -12,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,    23,    -5,
     -29,    12,   -29,   -29,   -29,   -29,   -29,   -29
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     123,   105,   116,   128,   118,   130,   120,   132,   122,   134,
     186,   136,   137,   138,   139,   140,   141,   186,   143,   186,
     145,   186,   147,   186,   149,   150,   186,   152,   153,   117,
     155,   119,   178,   121,   186,   186,   124,   186,   186,   129,
     163,   131,   165,   133,   167,   135,   169,   186,   179,   186,
      86,   186,   142,   186,   144,   180,   146,   186,   148,   186,
     186,   151,   186,   186,   154,   186,   156,   186,   186,   186,
     186,   186,   160,   186,   162,   186,   164,   178,   166,   157,
     168,   189,   170,   186,     1,     2,   311,   312,   178,   313,
     178,   186,   178,    88,   178,   186,   159,   184,   186,   185,
     180,   279,   280,   281,   282,   355,   278,   279,   280,   281,
     282,   180,   161,   180,   191,   180,   258,   180,   188,   281,
     282,   259,   199,   200,   192,   356,   284,   204,   187,   193,
     283,   289,   284,   181,   182,   206,   194,   208,   195,   210,
     287,   214,   284,   290,   223,   215,   216,   217,   190,   315,
     216,   217,   226,   229,   196,   231,   239,   125,   126,   219,
     220,   295,   292,   297,   296,   242,   293,   245,   270,   248,
     272,   251,   274,   197,   276,   255,   294,   257,   260,   198,
     261,   263,   201,   265,   288,   267,   269,   291,   299,   300,
     301,   304,   202,   337,   203,   271,   286,   273,   298,   275,
     302,   339,   308,   305,   309,   306,   314,   307,   303,   341,
     328,   317,   329,   363,   318,   330,   398,   319,   349,   320,
     331,   278,   279,   280,   281,   282,   351,   321,   353,   354,
     322,   357,   366,   323,   277,   392,   324,   393,   284,   325,
     310,   394,   178,   326,   178,   327,   178,   284,   178,   395,
       0,   332,   316,   333,     0,   334,     0,   335,     0,     0,
     178,     0,     0,     0,     0,   180,     0,   180,    89,   180,
      90,   180,    91,     0,     0,     0,   352,   178,   178,   178,
       0,     0,     0,   180,     0,   278,   279,   280,   281,   282,
     343,   344,   345,   346,   347,     0,     0,     0,     0,   364,
     180,   180,   180,     0,   368,     0,    92,     0,    93,   285,
      94,   284,    95,     0,    96,     0,    97,    98,     0,    99,
     100,   101,   102,     0,   103,     0,   104,     0,     0,     0,
       0,     0,     0,     0,   385,   365,   386,     0,   387,     0,
     380,     0,     0,     0,     0,   388,     0,   390,     0,     0,
       0,   396,     0,     0,     0,     0,     0,   178,   178,   178,
     178,   389,   178,     5,     6,     0,     7,     8,     0,     9,
       0,    10,    11,     0,     0,    12,     0,    13,    14,     0,
     180,   180,   180,   180,     0,   180,   408,    15,    16,     0,
      17,    18,     0,    19,    20,     0,    89,     0,    90,     0,
      91,    21,    22,     0,    23,    24,    25,    26,    27,    28,
       0,    29,    30,     0,    31,    32,     0,    33,    34,    35,
       0,    36,     0,    37,    38,     0,    39,     0,    40,    41,
       0,    42,    43,     0,    92,     0,    93,     0,    94,     0,
      95,     0,    96,     0,    97,    98,     0,    99,   100,   101,
     102,     0,   103,     0,   104,    44,     0,    45,     0,    46,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    49,     0,    50,    51,     0,    52,
      53,     0,    54,    55,     0,    56,    57,     0,    58,    59,
     171,   172,   205,   173,   174,     0,   175,     0,   176,   177,
       0,     0,    12,     0,    13,    14,     0,   367,     0,     0,
       0,     0,     0,     0,    15,    16,     0,    17,    18,     0,
      19,    20,    89,     0,    90,     0,    91,     0,    21,    22,
       0,    23,    24,    25,    26,    27,    28,     0,    29,    30,
       0,    31,    32,     0,    33,    34,    35,     0,    36,     0,
      37,    38,     0,    39,     0,    40,    41,     0,    42,    43,
      92,     0,    93,     0,    94,     0,    95,     0,    96,     0,
      97,    98,     0,    99,   100,   101,   102,     0,   103,     0,
     104,     0,    44,     0,    45,     0,    46,     0,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,    49,     0,    50,    51,     0,    52,    53,     0,    54,
      55,     0,    56,    57,     0,    58,    59,   171,   172,     0,
     173,   174,   207,   175,     0,   176,   177,     0,     0,    12,
       0,    13,    14,     0,   399,     0,     0,     0,     0,     0,
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
      57,     0,    58,    59,   171,   172,     0,   173,   174,     0,
     175,   209,   176,   177,     0,     0,    12,     0,    13,    14,
       0,     0,     0,     0,   362,     0,     0,     0,    15,    16,
       0,    17,    18,     0,    19,    20,    89,     0,    90,     0,
      91,     0,    21,    22,     0,    23,    24,    25,    26,    27,
      28,     0,    29,    30,     0,    31,    32,     0,    33,    34,
      35,     0,    36,     0,    37,    38,     0,    39,     0,    40,
      41,     0,    42,    43,    92,     0,    93,     0,    94,     0,
      95,     0,    96,     0,    97,    98,     0,    99,   100,   101,
     102,     0,   103,     0,   104,     0,    44,     0,    45,     0,
      46,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    49,     0,    50,    51,     0,
      52,    53,     0,    54,    55,     0,    56,    57,     0,    58,
      59,   171,   172,     0,   173,   174,     0,   175,     0,   176,
     177,     0,   211,    12,     0,    13,    14,     0,     0,     0,
       0,   397,     0,     0,     0,    15,    16,     0,    17,    18,
       0,    19,    20,    89,     0,    90,     0,    91,     0,    21,
      22,     0,    23,    24,    25,    26,    27,    28,     0,    29,
      30,     0,    31,    32,     0,    33,    34,    35,     0,    36,
       0,    37,    38,     0,    39,     0,    40,    41,     0,    42,
      43,    92,     0,    93,     0,    94,     0,    95,     0,    96,
       0,    97,    98,     0,    99,   100,   101,   102,     0,   103,
       0,   104,     0,    44,     0,    45,     0,    46,     0,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    49,     0,    50,    51,     0,    52,    53,     0,
      54,    55,     0,    56,    57,     0,    58,    59,   171,   172,
     336,   173,   174,     0,   175,     0,   176,   177,     0,     0,
      12,     0,    13,    14,     0,     0,     0,     0,   407,     0,
       0,     0,    15,    16,     0,    17,    18,     0,    19,    20,
      89,     0,    90,     0,    91,     0,    21,    22,     0,    23,
      24,    25,    26,    27,    28,     0,    29,    30,     0,    31,
      32,     0,    33,    34,    35,     0,    36,     0,    37,    38,
       0,    39,     0,    40,    41,     0,    42,    43,    92,     0,
      93,     0,    94,     0,    95,     0,    96,     0,    97,    98,
       0,    99,   100,   101,   102,     0,   103,     0,   104,     0,
      44,     0,    45,     0,    46,     0,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    49,
       0,    50,    51,     0,    52,    53,     0,    54,    55,     0,
      56,    57,     0,    58,    59,   171,   172,     0,   173,   174,
     338,   175,     0,   176,   177,     0,     0,    12,     0,    13,
      14,     0,     0,     0,     0,   409,     0,     0,     0,    15,
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
      58,    59,   171,   172,     0,   173,   174,     0,   175,   340,
     176,   177,     0,     0,    12,     0,    13,    14,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,     0,    17,
      18,     0,    19,    20,     0,     0,     0,     0,     0,     0,
      21,    22,     0,    23,    24,    25,    26,    27,    28,     0,
      29,    30,     0,    31,    32,     0,    33,    34,    35,     0,
      36,     0,    37,    38,     0,    39,     0,    40,    41,     0,
      42,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,     0,    45,     0,    46,     0,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,     0,    50,    51,     0,    52,    53,
       0,    54,    55,     0,    56,    57,     0,    58,    59,   171,
     172,     0,   173,   174,     0,   175,     0,   176,   177,     0,
     342,    12,     0,    13,    14,     0,     0,     0,     0,     0,
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
       0,    56,    57,     0,    58,    59,   171,   172,   358,   173,
     174,     0,   175,     0,   176,   177,     0,     0,    12,     0,
      13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    16,     0,    17,    18,     0,    19,    20,     0,     0,
       0,     0,     0,     0,    21,    22,     0,    23,    24,    25,
      26,    27,    28,     0,    29,    30,     0,    31,    32,     0,
      33,    34,    35,     0,    36,     0,    37,    38,     0,    39,
       0,    40,    41,     0,    42,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,     0,
      45,     0,    46,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,    49,     0,    50,
      51,     0,    52,    53,     0,    54,    55,     0,    56,    57,
       0,    58,    59,   171,   172,     0,   173,   174,   359,   175,
       0,   176,   177,     0,     0,    12,     0,    13,    14,     0,
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
     171,   172,     0,   173,   174,     0,   175,   360,   176,   177,
       0,     0,    12,     0,    13,    14,     0,     0,     0,     0,
       0,     0,     0,     0,    15,    16,     0,    17,    18,     0,
      19,    20,     0,     0,     0,     0,     0,     0,    21,    22,
       0,    23,    24,    25,    26,    27,    28,     0,    29,    30,
       0,    31,    32,     0,    33,    34,    35,     0,    36,     0,
      37,    38,     0,    39,     0,    40,    41,     0,    42,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,     0,    45,     0,    46,     0,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,    49,     0,    50,    51,     0,    52,    53,     0,    54,
      55,     0,    56,    57,     0,    58,    59,   171,   172,   400,
     173,   174,     0,   175,     0,   176,   177,     0,     0,    12,
       0,    13,    14,     0,     0,     0,     0,     0,     0,     0,
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
      57,     0,    58,    59,   171,   172,     0,   173,   174,   401,
     175,     0,   176,   177,     0,     0,    12,     0,    13,    14,
       0,     0,     0,     0,     0,     0,     0,     0,    15,    16,
       0,    17,    18,     0,    19,    20,     0,     0,     0,     0,
       0,     0,    21,    22,     0,    23,    24,    25,    26,    27,
      28,     0,    29,    30,     0,    31,    32,     0,    33,    34,
      35,     0,    36,     0,    37,    38,     0,    39,     0,    40,
      41,     0,    42,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,     0,    45,     0,
      46,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    49,     0,    50,    51,     0,
      52,    53,     0,    54,    55,     0,    56,    57,     0,    58,
      59,   171,   172,     0,   173,   174,     0,   175,   402,   176,
     177,     0,     0,    12,     0,    13,    14,     0,     0,     0,
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
      54,    55,     0,    56,    57,     0,    58,    59,   171,   172,
       0,   173,   174,     0,   175,     0,   176,   177,     0,     0,
      12,     0,    13,    14,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    16,     0,    17,    18,     0,    19,    20,
       0,     0,     0,     0,     0,     0,    21,    22,     0,    23,
      24,    25,    26,    27,    28,     0,    29,    30,     0,    31,
      32,     0,    33,    34,    35,     0,    36,     0,    37,    38,
       0,    39,     0,    40,    41,     0,    42,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,     0,    45,   403,    46,     0,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    49,
       0,    50,    51,     0,    52,    53,     0,    54,    55,     0,
      56,    57,     0,    58,    59,   171,   172,     0,   173,   174,
       0,   175,     0,   176,   177,     0,     0,    12,     0,    13,
      14,     0,     0,     0,     0,     0,     0,     0,     0,    15,
      16,     0,    17,    18,     0,    19,    20,     0,     0,     0,
       0,     0,     0,    21,    22,     0,    23,    24,    25,    26,
      27,    28,     0,    29,    30,     0,    31,    32,     0,    33,
      34,    35,     0,    36,     0,    37,    38,     0,    39,     0,
      40,    41,     0,    42,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,    45,
       0,    46,   405,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    49,     0,    50,    51,
       0,    52,    53,     0,    54,    55,     0,    56,    57,     0,
      58,    59,     5,     6,     0,     7,     8,     0,     9,     0,
      10,    11,     0,     0,    12,     0,    13,    14,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,     0,    17,
      18,     0,    19,    20,     0,     0,     0,     0,     0,     0,
      21,    22,     0,    23,    24,    25,    26,    27,    28,     0,
      29,    30,     0,    31,    32,     0,    33,    34,    35,     0,
      36,     0,    37,    38,     0,    39,     0,    40,    41,     0,
      42,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,     0,    45,     0,    46,     0,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,     0,    50,    51,     0,    52,    53,
       0,    54,    55,     0,    56,    57,     0,    58,    59,   171,
     172,     0,   173,   174,     0,   175,     0,   176,   177,     0,
       0,    12,     0,    13,    14,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    16,     0,    17,    18,     0,    19,
      20,     0,     0,     0,     0,     0,     0,    21,    22,     0,
      23,    24,    25,    26,    27,    28,     0,    29,    30,     0,
      31,    32,     0,    33,    34,    35,     0,    36,     0,    37,
      38,     0,    39,     0,    40,    41,     0,    42,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     0,
      90,    44,    91,    45,     0,    46,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      49,     0,    50,    51,   391,    52,    53,     0,    54,    55,
       0,    56,    57,     0,    58,    59,    92,    89,    93,    90,
      94,    91,    95,     0,    96,     0,    97,    98,     0,    99,
     100,   101,   102,     0,   103,     0,   104,     0,    89,     0,
      90,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,     0,    93,     0,    94,
       0,    95,     0,    96,     0,    97,    98,     0,    99,   100,
     101,   102,   268,   103,     0,   104,    92,    89,    93,    90,
      94,    91,    95,     0,    96,     0,    97,    98,     0,    99,
     100,   101,   102,     0,   103,     0,   104,     0,    89,     0,
      90,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,   384,     0,     0,     0,    92,     0,    93,     0,    94,
       0,    95,     0,    96,     0,    97,    98,     0,    99,   100,
     101,   102,     0,   103,     0,   104,    92,     0,    93,    89,
      94,    90,    95,    91,    96,     0,    97,    98,     0,    99,
     100,   101,   102,     0,   103,     0,   104,     0,    89,     0,
      90,     0,    91,     0,     0,     0,     0,     0,   266,     0,
       0,     0,     0,     0,     0,     0,     0,    92,     0,    93,
      89,    94,    90,    95,    91,    96,     0,    97,    98,   383,
      99,   100,   101,   102,     0,   103,    92,   104,    93,    89,
      94,    90,    95,    91,    96,     0,    97,    98,     0,    99,
     100,   101,   102,     0,   103,     0,   104,     0,    92,     0,
      93,     0,    94,     0,    95,     0,    96,   264,    97,    98,
       0,    99,   100,   101,   102,     0,   103,    92,   104,    93,
     361,    94,     0,    95,     0,    96,   382,    97,    98,     0,
      99,   100,   101,   102,     0,   103,     0,   104,   212,   213,
      89,     0,    90,     0,    91,   262,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,    90,     0,    91,   381,     0,     0,     0,     0,     0,
       0,     0,   221,     0,   222,     0,     0,     0,    92,     0,
      93,    89,    94,    90,    95,    91,    96,     0,    97,    98,
       0,    99,   100,   101,   102,   369,   103,    92,   104,    93,
       0,    94,    89,    95,    90,    96,    91,    97,    98,     0,
      99,   100,   101,   102,     0,   103,     0,   104,   224,    92,
     225,    93,     0,    94,    89,    95,    90,    96,    91,    97,
      98,     0,    99,   100,   101,   102,     0,   103,     0,   104,
      92,   370,    93,     0,    94,    89,    95,    90,    96,    91,
      97,    98,     0,    99,   100,   101,   102,     0,   103,     0,
     104,     0,    92,     0,    93,     0,    94,     0,    95,     0,
      96,     0,    97,    98,     0,    99,   100,   101,   102,     0,
     103,     0,   104,    92,     0,    93,     0,    94,     0,    95,
       0,    96,     0,    97,    98,     0,    99,   100,   101,   102,
       0,   103,   227,   104,   228,    89,     0,    90,     0,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   371,    89,     0,    90,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,     0,    93,     0,    94,     0,    95,
       0,    96,     0,    97,    98,     0,    99,   100,   101,   102,
      92,   103,    93,   104,    94,     0,    95,     0,    96,     0,
      97,    98,     0,    99,   100,   101,   102,    89,   103,    90,
     104,    91,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,     0,     0,    89,     0,    90,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   241,     0,     0,     0,    92,     0,    93,     0,    94,
       0,    95,     0,    96,     0,    97,    98,     0,    99,   100,
     101,   102,    92,   103,    93,   104,    94,    89,    95,    90,
      96,    91,    97,    98,     0,    99,   100,   101,   102,     0,
     103,     0,   104,     0,     0,     0,   243,   244,    89,     0,
      90,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,     0,    93,     0,    94,
     246,    95,   247,    96,     0,    97,    98,     0,    99,   100,
     101,   102,     0,   103,     0,   104,    92,    89,    93,    90,
      94,    91,    95,     0,    96,     0,    97,    98,     0,    99,
     100,   101,   102,     0,   103,     0,   104,     0,    89,     0,
      90,     0,    91,     0,     0,   230,     0,     0,     0,   253,
       0,   254,     0,     0,     0,    92,     0,    93,     0,    94,
      89,    95,    90,    96,    91,    97,    98,   232,    99,   100,
     101,   102,     0,   103,     0,   104,    92,     0,    93,     0,
      94,    89,    95,    90,    96,    91,    97,    98,   233,    99,
     100,   101,   102,     0,   103,     0,   104,     0,    92,     0,
      93,     0,    94,    89,    95,    90,    96,    91,    97,    98,
     234,    99,   100,   101,   102,     0,   103,     0,   104,    92,
       0,    93,     0,    94,    89,    95,    90,    96,    91,    97,
      98,   235,    99,   100,   101,   102,     0,   103,     0,   104,
       0,    92,     0,    93,     0,    94,    89,    95,    90,    96,
      91,    97,    98,   236,    99,   100,   101,   102,     0,   103,
       0,   104,    92,    89,    93,    90,    94,    91,    95,     0,
      96,     0,    97,    98,     0,    99,   100,   101,   102,     0,
     103,     0,   104,     0,    92,     0,    93,     0,    94,   249,
      95,     0,    96,     0,    97,    98,     0,    99,   100,   101,
     102,    92,   103,    93,   104,    94,    89,    95,    90,    96,
      91,    97,    98,     0,    99,   100,   101,   102,     0,   103,
       0,   104,     0,     0,     0,    89,     0,    90,     0,    91,
       0,     0,     0,     0,     0,   250,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,    93,    89,    94,    90,
      95,    91,    96,     0,    97,    98,   252,    99,   100,   101,
     102,     0,   103,    92,   104,    93,     0,    94,    89,    95,
      90,    96,    91,    97,    98,   372,    99,   100,   101,   102,
       0,   103,     0,   104,   256,    92,     0,    93,     0,    94,
      89,    95,    90,    96,    91,    97,    98,     0,    99,   100,
     101,   102,     0,   103,   373,   104,    92,     0,    93,     0,
      94,     0,    95,     0,    96,     0,    97,    98,     0,    99,
     100,   101,   102,    89,   103,    90,   104,    91,    92,     0,
      93,     0,    94,     0,    95,     0,    96,     0,    97,    98,
     374,    99,   100,   101,   102,     0,   103,     0,   104,     0,
      89,     0,    90,     0,    91,     0,     0,     0,     0,     0,
       0,    92,     0,    93,     0,    94,     0,    95,     0,    96,
     375,    97,    98,     0,    99,   100,   101,   102,     0,   103,
       0,   104,     0,    89,     0,    90,     0,    91,    92,     0,
      93,     0,    94,     0,    95,     0,    96,     0,    97,    98,
       0,    99,   100,   101,   102,     0,   103,   376,   104,    89,
       0,    90,     0,    91,     0,     0,     0,     0,     0,     0,
       0,    92,     0,    93,     0,    94,     0,    95,     0,    96,
       0,    97,    98,     0,    99,   100,   101,   102,   377,   103,
      89,   104,    90,     0,    91,     0,     0,    92,     0,    93,
       0,    94,     0,    95,     0,    96,     0,    97,    98,     0,
      99,   100,   101,   102,    89,   103,    90,   104,    91,     0,
       0,     0,     0,     0,   378,     0,     0,     0,    92,     0,
      93,     0,    94,     0,    95,     0,    96,     0,    97,    98,
       0,    99,   100,   101,   102,     0,   103,     0,   104,     0,
       0,   379,    92,     0,    93,     0,    94,     0,    95,     0,
      96,     0,    97,    98,     0,    99,   100,   101,   102,     0,
     103,     0,   104
};

static const yytype_int16 yycheck[] =
{
      12,     4,     5,    15,     7,    17,     9,    19,    11,    21,
      16,    23,    24,    25,    26,    27,    28,    16,    30,    16,
      32,    16,    34,    16,    36,    37,    16,    39,    40,     6,
      42,     8,    60,    10,    16,    16,    13,    16,    16,    16,
      52,    18,    54,    20,    56,    22,    58,    16,    60,    16,
      16,    16,    29,    16,    31,    60,    33,    16,    35,    16,
      16,    38,    16,    16,    41,    16,    43,    16,    16,    16,
      16,    16,    49,    16,    51,    16,    53,   105,    55,   105,
      57,    42,    59,    16,     3,     4,    25,    26,   116,    28,
     118,    16,   120,     0,   122,    16,   118,    85,    16,   110,
     105,   111,   112,   113,   114,    89,   110,   111,   112,   113,
     114,   116,   121,   118,    91,   120,   135,   122,   109,   113,
     114,   134,    99,   100,   109,   109,   136,   104,   134,   109,
     134,    40,   136,   105,   106,   134,   109,   134,   109,   134,
     110,   134,   136,    42,   134,    24,    25,    26,   109,    24,
      25,    26,   134,   134,   109,   134,   134,    22,    23,    22,
      23,    84,    78,    89,    86,   134,    80,   134,   171,   134,
     173,   134,   175,   109,   177,   134,    82,   134,   134,   109,
     134,   134,   109,   134,   187,   134,   134,   134,   134,   134,
      94,   134,   109,   134,   109,   172,   109,   174,    89,   176,
      94,   134,   214,   206,   216,   208,   218,   210,    96,   134,
     110,   223,    99,   134,   226,   118,   134,   229,   110,   231,
     121,   110,   111,   112,   113,   114,   109,   239,   109,   109,
     242,   109,    29,   245,     5,    42,   248,    89,   136,   251,
     217,    89,   270,   255,   272,   257,   274,   136,   276,    96,
      -1,   263,   220,   265,    -1,   267,    -1,   269,    -1,    -1,
     288,    -1,    -1,    -1,    -1,   270,    -1,   272,    39,   274,
      41,   276,    43,    -1,    -1,    -1,   288,   305,   306,   307,
      -1,    -1,    -1,   288,    -1,   110,   111,   112,   113,   114,
     278,   279,   280,   281,   282,    -1,    -1,    -1,    -1,   311,
     305,   306,   307,    -1,   316,    -1,    77,    -1,    79,   134,
      81,   136,    83,    -1,    85,    -1,    87,    88,    -1,    90,
      91,    92,    93,    -1,    95,    -1,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   337,   312,   339,    -1,   341,    -1,
     328,    -1,    -1,    -1,    -1,   348,    -1,   350,    -1,    -1,
      -1,   363,    -1,    -1,    -1,    -1,    -1,   385,   386,   387,
     388,   349,   390,     6,     7,    -1,     9,    10,    -1,    12,
      -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,
     385,   386,   387,   388,    -1,   390,   398,    30,    31,    -1,
      33,    34,    -1,    36,    37,    -1,    39,    -1,    41,    -1,
      43,    44,    45,    -1,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    62,
      -1,    64,    -1,    66,    67,    -1,    69,    -1,    71,    72,
      -1,    74,    75,    -1,    77,    -1,    79,    -1,    81,    -1,
      83,    -1,    85,    -1,    87,    88,    -1,    90,    91,    92,
      93,    -1,    95,    -1,    97,    98,    -1,   100,    -1,   102,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,   117,    -1,   119,   120,    -1,   122,
     123,    -1,   125,   126,    -1,   128,   129,    -1,   131,   132,
       6,     7,     8,     9,    10,    -1,    12,    -1,    14,    15,
      -1,    -1,    18,    -1,    20,    21,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,
      36,    37,    39,    -1,    41,    -1,    43,    -1,    44,    45,
      -1,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      -1,    57,    58,    -1,    60,    61,    62,    -1,    64,    -1,
      66,    67,    -1,    69,    -1,    71,    72,    -1,    74,    75,
      77,    -1,    79,    -1,    81,    -1,    83,    -1,    85,    -1,
      87,    88,    -1,    90,    91,    92,    93,    -1,    95,    -1,
      97,    -1,    98,    -1,   100,    -1,   102,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,    -1,   119,   120,    -1,   122,   123,    -1,   125,
     126,    -1,   128,   129,    -1,   131,   132,     6,     7,    -1,
       9,    10,    11,    12,    -1,    14,    15,    -1,    -1,    18,
      -1,    20,    21,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    34,    -1,    36,    37,    39,
      -1,    41,    -1,    43,    -1,    44,    45,    -1,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    -1,    57,    58,
      -1,    60,    61,    62,    -1,    64,    -1,    66,    67,    -1,
      69,    -1,    71,    72,    -1,    74,    75,    77,    -1,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    87,    88,    -1,
      90,    91,    92,    93,    -1,    95,    -1,    97,    -1,    98,
      -1,   100,    -1,   102,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,
     119,   120,    -1,   122,   123,    -1,   125,   126,    -1,   128,
     129,    -1,   131,   132,     6,     7,    -1,     9,    10,    -1,
      12,    13,    14,    15,    -1,    -1,    18,    -1,    20,    21,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    30,    31,
      -1,    33,    34,    -1,    36,    37,    39,    -1,    41,    -1,
      43,    -1,    44,    45,    -1,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    -1,    57,    58,    -1,    60,    61,
      62,    -1,    64,    -1,    66,    67,    -1,    69,    -1,    71,
      72,    -1,    74,    75,    77,    -1,    79,    -1,    81,    -1,
      83,    -1,    85,    -1,    87,    88,    -1,    90,    91,    92,
      93,    -1,    95,    -1,    97,    -1,    98,    -1,   100,    -1,
     102,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,   117,    -1,   119,   120,    -1,
     122,   123,    -1,   125,   126,    -1,   128,   129,    -1,   131,
     132,     6,     7,    -1,     9,    10,    -1,    12,    -1,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    30,    31,    -1,    33,    34,
      -1,    36,    37,    39,    -1,    41,    -1,    43,    -1,    44,
      45,    -1,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    -1,    57,    58,    -1,    60,    61,    62,    -1,    64,
      -1,    66,    67,    -1,    69,    -1,    71,    72,    -1,    74,
      75,    77,    -1,    79,    -1,    81,    -1,    83,    -1,    85,
      -1,    87,    88,    -1,    90,    91,    92,    93,    -1,    95,
      -1,    97,    -1,    98,    -1,   100,    -1,   102,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   116,   117,    -1,   119,   120,    -1,   122,   123,    -1,
     125,   126,    -1,   128,   129,    -1,   131,   132,     6,     7,
       8,     9,    10,    -1,    12,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    30,    31,    -1,    33,    34,    -1,    36,    37,
      39,    -1,    41,    -1,    43,    -1,    44,    45,    -1,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    -1,    60,    61,    62,    -1,    64,    -1,    66,    67,
      -1,    69,    -1,    71,    72,    -1,    74,    75,    77,    -1,
      79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,    88,
      -1,    90,    91,    92,    93,    -1,    95,    -1,    97,    -1,
      98,    -1,   100,    -1,   102,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,
      -1,   119,   120,    -1,   122,   123,    -1,   125,   126,    -1,
     128,   129,    -1,   131,   132,     6,     7,    -1,     9,    10,
      11,    12,    -1,    14,    15,    -1,    -1,    18,    -1,    20,
      21,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    30,
      31,    -1,    33,    34,    -1,    36,    37,    39,    -1,    41,
      -1,    43,    -1,    44,    45,    -1,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    -1,    57,    58,    -1,    60,
      61,    62,    -1,    64,    -1,    66,    67,    -1,    69,    -1,
      71,    72,    -1,    74,    75,    77,    -1,    79,    -1,    81,
      -1,    83,    -1,    85,    -1,    87,    88,    -1,    90,    91,
      92,    93,    -1,    95,    -1,    97,    -1,    98,    -1,   100,
      -1,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,    -1,   119,   120,
      -1,   122,   123,    -1,   125,   126,    -1,   128,   129,    -1,
     131,   132,     6,     7,    -1,     9,    10,    -1,    12,    13,
      14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,
      34,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    -1,    57,    58,    -1,    60,    61,    62,    -1,
      64,    -1,    66,    67,    -1,    69,    -1,    71,    72,    -1,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,   100,    -1,   102,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,    -1,   119,   120,    -1,   122,   123,
      -1,   125,   126,    -1,   128,   129,    -1,   131,   132,     6,
       7,    -1,     9,    10,    -1,    12,    -1,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    -1,
      57,    58,    -1,    60,    61,    62,    -1,    64,    -1,    66,
      67,    -1,    69,    -1,    71,    72,    -1,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,   100,    -1,   102,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,    -1,   119,   120,    -1,   122,   123,    -1,   125,   126,
      -1,   128,   129,    -1,   131,   132,     6,     7,     8,     9,
      10,    -1,    12,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    34,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    -1,    57,    58,    -1,
      60,    61,    62,    -1,    64,    -1,    66,    67,    -1,    69,
      -1,    71,    72,    -1,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,
     100,    -1,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,   119,
     120,    -1,   122,   123,    -1,   125,   126,    -1,   128,   129,
      -1,   131,   132,     6,     7,    -1,     9,    10,    11,    12,
      -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    62,
      -1,    64,    -1,    66,    67,    -1,    69,    -1,    71,    72,
      -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,   100,    -1,   102,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,   117,    -1,   119,   120,    -1,   122,
     123,    -1,   125,   126,    -1,   128,   129,    -1,   131,   132,
       6,     7,    -1,     9,    10,    -1,    12,    13,    14,    15,
      -1,    -1,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      -1,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      -1,    57,    58,    -1,    60,    61,    62,    -1,    64,    -1,
      66,    67,    -1,    69,    -1,    71,    72,    -1,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,   100,    -1,   102,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,    -1,   119,   120,    -1,   122,   123,    -1,   125,
     126,    -1,   128,   129,    -1,   131,   132,     6,     7,     8,
       9,    10,    -1,    12,    -1,    14,    15,    -1,    -1,    18,
      -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    34,    -1,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    -1,    57,    58,
      -1,    60,    61,    62,    -1,    64,    -1,    66,    67,    -1,
      69,    -1,    71,    72,    -1,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,   100,    -1,   102,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,
     119,   120,    -1,   122,   123,    -1,   125,   126,    -1,   128,
     129,    -1,   131,   132,     6,     7,    -1,     9,    10,    11,
      12,    -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    -1,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    -1,    57,    58,    -1,    60,    61,
      62,    -1,    64,    -1,    66,    67,    -1,    69,    -1,    71,
      72,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,   100,    -1,
     102,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,   117,    -1,   119,   120,    -1,
     122,   123,    -1,   125,   126,    -1,   128,   129,    -1,   131,
     132,     6,     7,    -1,     9,    10,    -1,    12,    13,    14,
      15,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,
      -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    -1,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    -1,    57,    58,    -1,    60,    61,    62,    -1,    64,
      -1,    66,    67,    -1,    69,    -1,    71,    72,    -1,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,   100,    -1,   102,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   116,   117,    -1,   119,   120,    -1,   122,   123,    -1,
     125,   126,    -1,   128,   129,    -1,   131,   132,     6,     7,
      -1,     9,    10,    -1,    12,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    33,    34,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    -1,    60,    61,    62,    -1,    64,    -1,    66,    67,
      -1,    69,    -1,    71,    72,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,   100,   101,   102,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,
      -1,   119,   120,    -1,   122,   123,    -1,   125,   126,    -1,
     128,   129,    -1,   131,   132,     6,     7,    -1,     9,    10,
      -1,    12,    -1,    14,    15,    -1,    -1,    18,    -1,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    33,    34,    -1,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    -1,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    -1,    57,    58,    -1,    60,
      61,    62,    -1,    64,    -1,    66,    67,    -1,    69,    -1,
      71,    72,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,   100,
      -1,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,    -1,   119,   120,
      -1,   122,   123,    -1,   125,   126,    -1,   128,   129,    -1,
     131,   132,     6,     7,    -1,     9,    10,    -1,    12,    -1,
      14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,
      34,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    -1,    57,    58,    -1,    60,    61,    62,    -1,
      64,    -1,    66,    67,    -1,    69,    -1,    71,    72,    -1,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,   100,    -1,   102,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,    -1,   119,   120,    -1,   122,   123,
      -1,   125,   126,    -1,   128,   129,    -1,   131,   132,     6,
       7,    -1,     9,    10,    -1,    12,    -1,    14,    15,    -1,
      -1,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    -1,
      57,    58,    -1,    60,    61,    62,    -1,    64,    -1,    66,
      67,    -1,    69,    -1,    71,    72,    -1,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      41,    98,    43,   100,    -1,   102,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,    -1,   119,   120,     5,   122,   123,    -1,   125,   126,
      -1,   128,   129,    -1,   131,   132,    77,    39,    79,    41,
      81,    43,    83,    -1,    85,    -1,    87,    88,    -1,    90,
      91,    92,    93,    -1,    95,    -1,    97,    -1,    39,    -1,
      41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,
      -1,    83,    -1,    85,    -1,    87,    88,    -1,    90,    91,
      92,    93,   133,    95,    -1,    97,    77,    39,    79,    41,
      81,    43,    83,    -1,    85,    -1,    87,    88,    -1,    90,
      91,    92,    93,    -1,    95,    -1,    97,    -1,    39,    -1,
      41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   133,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,
      -1,    83,    -1,    85,    -1,    87,    88,    -1,    90,    91,
      92,    93,    -1,    95,    -1,    97,    77,    -1,    79,    39,
      81,    41,    83,    43,    85,    -1,    87,    88,    -1,    90,
      91,    92,    93,    -1,    95,    -1,    97,    -1,    39,    -1,
      41,    -1,    43,    -1,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,
      39,    81,    41,    83,    43,    85,    -1,    87,    88,   130,
      90,    91,    92,    93,    -1,    95,    77,    97,    79,    39,
      81,    41,    83,    43,    85,    -1,    87,    88,    -1,    90,
      91,    92,    93,    -1,    95,    -1,    97,    -1,    77,    -1,
      79,    -1,    81,    -1,    83,    -1,    85,   127,    87,    88,
      -1,    90,    91,    92,    93,    -1,    95,    77,    97,    79,
      19,    81,    -1,    83,    -1,    85,   127,    87,    88,    -1,
      90,    91,    92,    93,    -1,    95,    -1,    97,    18,    19,
      39,    -1,    41,    -1,    43,   124,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    41,    -1,    43,   124,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    32,    -1,    -1,    -1,    77,    -1,
      79,    39,    81,    41,    83,    43,    85,    -1,    87,    88,
      -1,    90,    91,    92,    93,    32,    95,    77,    97,    79,
      -1,    81,    39,    83,    41,    85,    43,    87,    88,    -1,
      90,    91,    92,    93,    -1,    95,    -1,    97,    33,    77,
      35,    79,    -1,    81,    39,    83,    41,    85,    43,    87,
      88,    -1,    90,    91,    92,    93,    -1,    95,    -1,    97,
      77,    35,    79,    -1,    81,    39,    83,    41,    85,    43,
      87,    88,    -1,    90,    91,    92,    93,    -1,    95,    -1,
      97,    -1,    77,    -1,    79,    -1,    81,    -1,    83,    -1,
      85,    -1,    87,    88,    -1,    90,    91,    92,    93,    -1,
      95,    -1,    97,    77,    -1,    79,    -1,    81,    -1,    83,
      -1,    85,    -1,    87,    88,    -1,    90,    91,    92,    93,
      -1,    95,    36,    97,    38,    39,    -1,    41,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    -1,    41,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    79,    -1,    81,    -1,    83,
      -1,    85,    -1,    87,    88,    -1,    90,    91,    92,    93,
      77,    95,    79,    97,    81,    -1,    83,    -1,    85,    -1,
      87,    88,    -1,    90,    91,    92,    93,    39,    95,    41,
      97,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    -1,    -1,    39,    -1,    41,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,
      -1,    83,    -1,    85,    -1,    87,    88,    -1,    90,    91,
      92,    93,    77,    95,    79,    97,    81,    39,    83,    41,
      85,    43,    87,    88,    -1,    90,    91,    92,    93,    -1,
      95,    -1,    97,    -1,    -1,    -1,    58,    59,    39,    -1,
      41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,
      61,    83,    63,    85,    -1,    87,    88,    -1,    90,    91,
      92,    93,    -1,    95,    -1,    97,    77,    39,    79,    41,
      81,    43,    83,    -1,    85,    -1,    87,    88,    -1,    90,
      91,    92,    93,    -1,    95,    -1,    97,    -1,    39,    -1,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    -1,    71,
      -1,    73,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,
      39,    83,    41,    85,    43,    87,    88,    46,    90,    91,
      92,    93,    -1,    95,    -1,    97,    77,    -1,    79,    -1,
      81,    39,    83,    41,    85,    43,    87,    88,    46,    90,
      91,    92,    93,    -1,    95,    -1,    97,    -1,    77,    -1,
      79,    -1,    81,    39,    83,    41,    85,    43,    87,    88,
      46,    90,    91,    92,    93,    -1,    95,    -1,    97,    77,
      -1,    79,    -1,    81,    39,    83,    41,    85,    43,    87,
      88,    46,    90,    91,    92,    93,    -1,    95,    -1,    97,
      -1,    77,    -1,    79,    -1,    81,    39,    83,    41,    85,
      43,    87,    88,    46,    90,    91,    92,    93,    -1,    95,
      -1,    97,    77,    39,    79,    41,    81,    43,    83,    -1,
      85,    -1,    87,    88,    -1,    90,    91,    92,    93,    -1,
      95,    -1,    97,    -1,    77,    -1,    79,    -1,    81,    65,
      83,    -1,    85,    -1,    87,    88,    -1,    90,    91,    92,
      93,    77,    95,    79,    97,    81,    39,    83,    41,    85,
      43,    87,    88,    -1,    90,    91,    92,    93,    -1,    95,
      -1,    97,    -1,    -1,    -1,    39,    -1,    41,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    79,    39,    81,    41,
      83,    43,    85,    -1,    87,    88,    70,    90,    91,    92,
      93,    -1,    95,    77,    97,    79,    -1,    81,    39,    83,
      41,    85,    43,    87,    88,    46,    90,    91,    92,    93,
      -1,    95,    -1,    97,    76,    77,    -1,    79,    -1,    81,
      39,    83,    41,    85,    43,    87,    88,    -1,    90,    91,
      92,    93,    -1,    95,    53,    97,    77,    -1,    79,    -1,
      81,    -1,    83,    -1,    85,    -1,    87,    88,    -1,    90,
      91,    92,    93,    39,    95,    41,    97,    43,    77,    -1,
      79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,    88,
      56,    90,    91,    92,    93,    -1,    95,    -1,    97,    -1,
      39,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    79,    -1,    81,    -1,    83,    -1,    85,
      59,    87,    88,    -1,    90,    91,    92,    93,    -1,    95,
      -1,    97,    -1,    39,    -1,    41,    -1,    43,    77,    -1,
      79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,    88,
      -1,    90,    91,    92,    93,    -1,    95,    63,    97,    39,
      -1,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    79,    -1,    81,    -1,    83,    -1,    85,
      -1,    87,    88,    -1,    90,    91,    92,    93,    68,    95,
      39,    97,    41,    -1,    43,    -1,    -1,    77,    -1,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    87,    88,    -1,
      90,    91,    92,    93,    39,    95,    41,    97,    43,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,    88,
      -1,    90,    91,    92,    93,    -1,    95,    -1,    97,    -1,
      -1,    76,    77,    -1,    79,    -1,    81,    -1,    83,    -1,
      85,    -1,    87,    88,    -1,    90,    91,    92,    93,    -1,
      95,    -1,    97
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,   138,   164,     6,     7,     9,    10,    12,
      14,    15,    18,    20,    21,    30,    31,    33,    34,    36,
      37,    44,    45,    47,    48,    49,    50,    51,    52,    54,
      55,    57,    58,    60,    61,    62,    64,    66,    67,    69,
      71,    72,    74,    75,    98,   100,   102,   104,   116,   117,
     119,   120,   122,   123,   125,   126,   128,   129,   131,   132,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   158,   159,   160,
     161,   162,   163,   176,   179,   182,    16,   175,     0,    39,
      41,    43,    77,    79,    81,    83,    85,    87,    88,    90,
      91,    92,    93,    95,    97,   139,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   139,   175,   139,   175,
     139,   175,   139,   164,   175,    22,    23,   156,   164,   175,
     164,   175,   164,   175,   164,   175,   164,   164,   164,   164,
     164,   164,   175,   164,   175,   164,   175,   164,   175,   164,
     164,   175,   164,   164,   175,   164,   175,   105,   177,   118,
     175,   121,   175,   164,   175,   164,   175,   164,   175,   164,
     175,     6,     7,     9,    10,    12,    14,    15,   140,   164,
     176,   105,   106,   178,   178,   110,    16,   134,   109,    42,
     109,   175,   109,   109,   109,   109,   109,   109,   109,   175,
     175,   109,   109,   109,   175,     8,   134,    11,   134,    13,
     134,    17,    18,    19,   134,    24,    25,    26,   157,    22,
      23,    30,    32,   134,    33,    35,   134,    36,    38,   134,
      46,   134,    46,    46,    46,    46,    46,    52,    53,   134,
      55,    56,   134,    58,    59,   134,    61,    63,   134,    65,
      68,   134,    70,    71,    73,   134,    76,   134,   135,   134,
     134,   134,   124,   134,   127,   134,   130,   134,   133,   134,
     139,   175,   139,   175,   139,   175,   139,     5,   110,   111,
     112,   113,   114,   134,   136,   134,   109,   110,   139,    40,
      42,   134,    78,    80,    82,    84,    86,    89,    89,   134,
     134,    94,    94,    96,   134,   139,   139,   139,   164,   164,
     175,    25,    26,    28,   164,    24,   157,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   110,    99,
     118,   121,   164,   164,   164,   164,     8,   134,    11,   134,
      13,   134,    17,   178,   178,   178,   178,   178,   180,   110,
     184,   109,   164,   109,   109,    89,   109,   109,     8,    11,
      13,    19,    27,   134,   164,   175,    29,    24,   164,    32,
      35,    38,    46,    53,    56,    59,    63,    68,    73,    76,
     178,   124,   127,   130,   133,   139,   139,   139,   139,   178,
     139,     5,    42,    89,    89,    96,   164,    27,   134,    24,
       8,    11,    13,   101,   181,   103,   183,    27,   164,    27
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
#line 152 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 156 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 160 "gtkdialog_parser.y"
    { 
    		token_store_attr(PUSH | WIDGET_WINDOW, (yyvsp[(2) - (6)].nvval)); 
		start_up();
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 168 "gtkdialog_parser.y"
    { 
		token_store(SUM);      
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 173 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
	}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 176 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
		token_store(SUM);      
	}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 180 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 183 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(3) - (6)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 187 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
	}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 190 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
		token_store(SUM);      
	}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 194 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 197 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(3) - (6)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 201 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
	}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 204 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
		token_store(SUM);      
	}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 208 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 211 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(3) - (6)].nvval));
		token_store(SUM);      
	}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 215 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(1) - (3)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
	}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 219 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(2) - (4)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
		token_store(SUM);      
	}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 251 "gtkdialog_parser.y"
    {
                          token_store(PUSH | WIDGET_ENTRY); 
			 }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 254 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_ENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 257 "gtkdialog_parser.y"
    {
                  yyerror("</entry> expected instead of <entry>.");}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 262 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_EDIT); 
	}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 265 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_EDIT, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 268 "gtkdialog_parser.y"
    {
    		yyerror("</edit> expected instead of <edit>.");
	}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 274 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TREE); 
	}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 277 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_TREE, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 280 "gtkdialog_parser.y"
    {
   		yyerror("</tree> expected instead of <tree>.");
	}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 286 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHOOSER); 
	}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 289 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_CHOOSER, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 292 "gtkdialog_parser.y"
    {
		yyerror("</chooser> expected instead of <chooser>.");
	}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 298 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_LABEL); 
	}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 301 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_LABEL, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 304 "gtkdialog_parser.y"
    {yyerror("</text> expected instead of <text>.");}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 308 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_BUTTON);  }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 309 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_BUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 312 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_OKBUTTON);}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 313 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_CANCELBUTTON);}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 314 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_HELPBUTTON);}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 315 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_NOBUTTON);}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 316 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_YESBUTTON);}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 320 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHECKBOX);
	}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 323 "gtkdialog_parser.y"
    {
		//token_store_with_tag_attributes(PUSH | WIDGET_CHECKBOX, $2);
                token_store_attr(PUSH | WIDGET_CHECKBOX, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 327 "gtkdialog_parser.y"
    {
		yyerror("</checkbox> expected instead of <checkbox>.");
	}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 333 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_RADIO);
           }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 336 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_RADIO, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 339 "gtkdialog_parser.y"
    {
		yyerror("</radiobutton> expected instead of <radiobutton>.");
           }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 345 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_PROGRESS);
           }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 348 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_PROGRESS, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 351 "gtkdialog_parser.y"
    {
		yyerror("</progressbar> expected instead of <progressbar>.");
           }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 357 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_LIST); 
	}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 360 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_LIST, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 363 "gtkdialog_parser.y"
    {
    		yyerror("</list> expected instead of <list>.");
	}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 369 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_TABLE);}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 373 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_COMBO);
	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 376 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_COMBO, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 382 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_GVIM);}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 386 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_PIXMAP);}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 387 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_PIXMAP, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 393 "gtkdialog_parser.y"
    {
                    yyerror("Empty menubar without a single <menu> tag.");
		    }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 396 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_MENUBAR);}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 400 "gtkdialog_parser.y"
    { yyerror("Empty menu without <menuitem> tag.");}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 401 "gtkdialog_parser.y"
    { token_store(PUSH | WIDGET_MENU);   }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 402 "gtkdialog_parser.y"
    { yyerror("Empty menu without <menuitem> tag.");}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 403 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_MENU);   
		token_store(SUM); 
	}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 410 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM); 
	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 413 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 416 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_MENUITEM); 
		token_store(SUM);
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 420 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(3) - (6)].nvval)); 
		token_store(SUM);
    	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 424 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEMSEPARATOR);
		token_store(SUM);
	}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 437 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSEPARATOR);
	}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 440 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 446 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSEPARATOR);
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 449 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 455 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXTEXT);
	}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 458 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXTEXT, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 464 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXENTRY);
	}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 467 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 473 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSCALE);
	}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 476 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSCALE, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 482 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSCALE);
	}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 485 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSCALE, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 505 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_LABEL, (yyvsp[(2) - (3)].cval));     }
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 510 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_VARIABLE, (yyvsp[(2) - (3)].cval)); }
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 515 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_VISIBLE, (yyvsp[(2) - (3)].cval));  }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 520 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_DEFAULT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 525 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_WIDTH, (yyvsp[(2) - (3)].cval));    }
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 530 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_HEIGHT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 535 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_SHELL,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 538 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 541 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 544 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 547 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, "", (yyvsp[(2) - (4)].nvval)); 
	}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 553 "gtkdialog_parser.y"
    {
	         fprintf( stderr, "<output>: Not implemented.\n" ); 
	}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 556 "gtkdialog_parser.y"
    {
         	token_store_with_argument(SET|ATTR_OUTPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 562 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET|ATTR_ACTION, (yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 565 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET | ATTR_ACTION, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 572 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET | ATTR_ITEM, (yyvsp[(2) - (3)].cval));
	}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 575 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_ITEM, "");
    	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 578 "gtkdialog_parser.y"
    {
		      token_store_with_argument_attr(SET | ATTR_ITEM, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
                    }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 584 "gtkdialog_parser.y"
    {
       		(yyval.nvval) = new_tag_attributeset((yyvsp[(1) - (3)].cval), (yyvsp[(3) - (3)].cval)); 
	}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 587 "gtkdialog_parser.y"
    { 
       		(yyval.nvval) = add_tag_attribute((yyvsp[(1) - (4)].nvval), (yyvsp[(2) - (4)].cval), (yyvsp[(4) - (4)].cval)); 
	}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 594 "gtkdialog_parser.y"
    { 
		token_store(SHOW);     
	}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 597 "gtkdialog_parser.y"
    {
  		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
	}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 600 "gtkdialog_parser.y"
    {
		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
		instruction_set_jump((yyvsp[(6) - (6)].ival) + 1, (yyvsp[(1) - (6)].ival));
	}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 607 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMASSG | VARIABLE_NAME, (yyvsp[(1) - (4)].cval)); 
	}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 613 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | VARIABLE_NAME, (yyvsp[(1) - (1)].cval)); 
	}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 616 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | CONST_NUMBER, (yyvsp[(1) - (1)].cval)); 
  	}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 619 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_ADD);
	}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 622 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_SUBST);
	}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 625 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_MULT);
	}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 628 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_DIV);
	}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 631 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_EQ);
	}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 634 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_NE);
	}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 644 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 651 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 655 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 659 "gtkdialog_parser.y"
    {
		token_store(GOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 666 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
    }
    break;



/* Line 1455 of yacc.c  */
#line 3775 "gtkdialog_parser.c"
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
#line 672 "gtkdialog_parser.y"


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


