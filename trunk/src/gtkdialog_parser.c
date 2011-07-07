
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
** parser.y: A simple grammar for the XML-like language we use.
** copyright: (c) 2003 by László Pere
** email: pipas@linux.pte.hu
**
** This program is free software; you can redistribute it and/or 
** modify  it under the terms of the GNU General Public License as
** published by the Free Software Foundation; either version 2 of
** the License, or (at your option) any later version.
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
#line 144 "gtkdialog_parser.c"

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
     SEPARATOR = 280,
     ESEPARATOR = 281,
     MENUITEM = 282,
     PART_MENUITEM = 283,
     EMENUITEM = 284,
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
     ECOMBOBOXENTRY = 377
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
#define SEPARATOR 280
#define ESEPARATOR 281
#define MENUITEM 282
#define PART_MENUITEM 283
#define EMENUITEM 284
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 63 "gtkdialog_parser.y"
 
  double     dval;
  char      *cval;
  GList     *lval;
  tag_attr *nvval;
  gint       ival;



/* Line 214 of yacc.c  */
#line 434 "gtkdialog_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 446 "gtkdialog_parser.c"

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
#define YYFINAL  82
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3638

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  131
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNRULES -- Number of states.  */
#define YYNSTATES  392

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   377

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   130,     2,     2,     2,     2,     2,     2,
       2,     2,   113,   112,     2,   111,     2,   114,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   129,     2,
       2,   110,   128,     2,     2,     2,     2,     2,     2,     2,
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
     120,   121,   122,   123,   124,   125,   126,   127
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
     137,   139,   141,   145,   151,   155,   159,   165,   169,   173,
     179,   183,   187,   193,   197,   201,   207,   211,   215,   221,
     225,   229,   233,   237,   241,   245,   251,   255,   259,   265,
     269,   273,   279,   283,   287,   293,   297,   301,   305,   311,
     315,   319,   325,   328,   332,   335,   340,   344,   350,   354,
     360,   365,   372,   376,   379,   384,   387,   392,   396,   402,
     406,   412,   413,   416,   419,   422,   425,   428,   431,   434,
     437,   440,   443,   447,   451,   455,   459,   463,   467,   471,
     477,   481,   487,   492,   496,   500,   504,   510,   514,   517,
     523,   527,   532,   537,   539,   546,   553,   558,   560,   562,
     566,   570,   574,   578,   582,   587,   589,   590,   592,   594,
     596
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     132,     0,    -1,   156,   133,    -1,     3,   133,   156,     5,
      -1,     4,   167,   128,   133,   156,     5,    -1,   134,    -1,
     133,   134,    -1,   168,    -1,   133,   168,    -1,     6,   133,
       8,    -1,   133,     6,   133,     8,    -1,     7,   167,   128,
     133,     8,    -1,   133,     7,   167,   128,   133,     8,    -1,
       9,   133,    11,    -1,   133,     9,   133,    11,    -1,    10,
     167,   128,   133,    11,    -1,   133,    10,   167,   128,   133,
      11,    -1,    12,   133,    13,    -1,   133,    12,   133,    13,
      -1,    14,   167,   128,   133,    13,    -1,   133,    14,   167,
     128,   133,    13,    -1,    15,   133,    17,    -1,   133,    15,
     133,    17,    -1,   139,    -1,   135,    -1,   136,    -1,   137,
      -1,   138,    -1,   140,    -1,   141,    -1,   142,    -1,   143,
      -1,   144,    -1,   145,    -1,   146,    -1,   148,    -1,   147,
      -1,   149,    -1,   152,    -1,   153,    -1,   154,    -1,   155,
      -1,    18,   156,    19,    -1,    20,   167,   128,   156,    19,
      -1,    18,   156,    18,    -1,    30,   156,    32,    -1,    31,
     167,   128,   156,    32,    -1,    30,   156,    30,    -1,    33,
     156,    35,    -1,    34,   167,   128,   156,    35,    -1,    33,
     156,    33,    -1,    36,   156,    38,    -1,    37,   167,   128,
     156,    38,    -1,    36,   156,    36,    -1,    71,   156,    73,
      -1,    72,   167,   128,   156,    73,    -1,    71,   156,    71,
      -1,    44,   156,    46,    -1,    45,   167,   128,   156,    46,
      -1,    47,   156,    46,    -1,    48,   156,    46,    -1,    49,
     156,    46,    -1,    51,   156,    46,    -1,    50,   156,    46,
      -1,    52,   156,    53,    -1,    54,   167,   128,   156,    53,
      -1,    52,   156,    52,    -1,    55,   156,    56,    -1,    57,
     167,   128,   156,    56,    -1,    55,   156,    55,    -1,    58,
     156,    59,    -1,    60,   167,   128,   156,    59,    -1,    58,
     156,    58,    -1,    61,   156,    63,    -1,    62,   167,   128,
     156,    63,    -1,    61,   156,    61,    -1,    64,   156,    65,
      -1,    66,   156,    68,    -1,    67,   167,   128,   156,    68,
      -1,    69,   156,    70,    -1,    74,   156,    76,    -1,    75,
     167,   128,   156,    76,    -1,    21,    22,    -1,    21,   150,
      22,    -1,    23,    24,    -1,    23,   151,   156,    24,    -1,
     150,    23,    24,    -1,   150,    23,   151,   156,    24,    -1,
      27,   156,    29,    -1,    28,   167,   128,   156,    29,    -1,
     151,    27,   156,    29,    -1,   151,    28,   167,   128,   156,
      29,    -1,   151,    25,    26,    -1,   116,   118,    -1,   117,
     167,   128,   118,    -1,   119,   121,    -1,   120,   167,   128,
     121,    -1,   122,   156,   124,    -1,   123,   167,   128,   156,
     124,    -1,   125,   156,   127,    -1,   126,   167,   128,   156,
     127,    -1,    -1,   156,   160,    -1,   156,   159,    -1,   156,
     158,    -1,   156,   157,    -1,   156,   161,    -1,   156,   162,
      -1,   156,   163,    -1,   156,   164,    -1,   156,   165,    -1,
     156,   166,    -1,    39,   109,    40,    -1,    81,   109,    82,
      -1,    79,   109,    80,    -1,    77,   109,    78,    -1,    83,
     109,    84,    -1,    85,   109,    86,    -1,    87,   109,    89,
      -1,    90,   167,   128,   109,    89,    -1,    88,   109,    89,
      -1,    91,   167,   128,   109,    89,    -1,    91,   167,   128,
      89,    -1,    92,   109,    94,    -1,    93,   109,    94,    -1,
      95,   109,    96,    -1,    97,   167,   128,   109,    96,    -1,
      41,   109,    42,    -1,    41,    42,    -1,    43,   167,   128,
     109,    42,    -1,    16,   110,   109,    -1,   167,    16,   110,
     109,    -1,    98,   169,   128,    99,    -1,   104,    -1,   171,
     170,   128,   172,   133,   173,    -1,   174,   170,   128,   176,
     133,   175,    -1,   105,   129,   110,   170,    -1,   105,    -1,
     106,    -1,   170,   112,   170,    -1,   170,   111,   170,    -1,
     170,   113,   170,    -1,   170,   114,   170,    -1,   170,   110,
     170,    -1,   170,   130,   110,   170,    -1,   100,    -1,    -1,
     101,    -1,   102,    -1,   103,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   134,   134,   138,   142,   149,   150,   153,   154,   155,
     158,   162,   165,   169,   172,   176,   179,   183,   186,   190,
     193,   197,   201,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   231,   234,   237,   242,   245,   248,   254,   257,
     260,   266,   269,   272,   278,   281,   284,   288,   289,   292,
     293,   294,   295,   296,   300,   303,   307,   313,   316,   319,
     325,   328,   331,   337,   340,   343,   349,   353,   356,   362,
     366,   367,   373,   376,   380,   381,   382,   383,   390,   393,
     396,   400,   404,   413,   416,   422,   425,   431,   434,   440,
     443,   448,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   463,   468,   473,   478,   483,   488,   493,   496,
     499,   502,   505,   511,   514,   520,   523,   530,   533,   536,
     542,   545,   551,   552,   555,   558,   565,   571,   574,   577,
     580,   583,   586,   589,   592,   598,   602,   609,   613,   617,
     624
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
  "SEPARATOR", "ESEPARATOR", "MENUITEM", "PART_MENUITEM", "EMENUITEM",
  "EDIT", "PART_EDIT", "EEDIT", "TREE", "PART_TREE", "ETREE", "CHOOSER",
  "PART_CHOOSER", "ECHOOSER", "LABEL", "ELABEL", "ITEM", "EITEM",
  "PART_ITEM", "BUTTON", "PART_BUTTON", "EBUTTON", "BUTTONOK",
  "BUTTONCANCEL", "BUTTONHELP", "BUTTONYES", "BUTTONNO", "CHECKBOX",
  "ECHECKBOX", "PART_CHECKBOX", "RADIO", "ERADIO", "PART_RADIO",
  "PROGRESS", "EPROGRESS", "PART_PROGRESS", "LIST", "PART_LIST", "ELIST",
  "TABLE", "ETABLE", "COMBO", "PART_COMBO", "ECOMBO", "GVIM", "EGVIM",
  "TEXT", "PART_TEXT", "ETEXT", "PIXMAP", "PART_PIXMAP", "EPIXMAP",
  "DEFAULT", "EDEFAULT", "VISIBLE", "EVISIBLE", "VARIABLE", "EVARIABLE",
  "WIDTH", "EWIDTH", "HEIGHT", "EHEIGHT", "INPUT", "INPUTFILE", "EINPUT",
  "PART_INPUT", "PART_INPUTFILE", "OUTPUT", "OUTPUTFILE", "EOUTPUT",
  "ACTION", "EACTION", "PART_ACTION", "COMM", "ENDCOMM", "IF", "ENDIF",
  "WHILE", "EWHILE", "SHOW_WIDGETS", "EMB_VARIABLE", "EMB_NUMBER",
  "END_OF_FILE", "NUMBER", "STRING", "'='", "'-'", "'+'", "'*'", "'/'",
  "UMINUS", "HSEPARATOR", "PART_HSEPARATOR", "EHSEPARATOR", "VSEPARATOR",
  "PART_VSEPARATOR", "EVSEPARATOR", "COMBOBOXTEXT", "PART_COMBOBOXTEXT",
  "ECOMBOBOXTEXT", "COMBOBOXENTRY", "PART_COMBOBOXENTRY", "ECOMBOBOXENTRY",
  "'>'", "':'", "'!'", "$accept", "window", "wlist", "widget", "entry",
  "edit", "tree", "chooser", "text", "button", "checkbox", "radiobutton",
  "progressbar", "list", "table", "combo", "gvim", "pixmap", "menubar",
  "menus", "menuitems", "hseparator", "vseparator", "comboboxtext",
  "comboboxentry", "attr", "label", "variable", "visible", "defaultvalue",
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
      61,    45,    43,    42,    47,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,    62,    58,
      33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   131,   132,   132,   132,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   135,   135,   135,   136,   136,   136,   137,   137,
     137,   138,   138,   138,   139,   139,   139,   140,   140,   140,
     140,   140,   140,   140,   141,   141,   141,   142,   142,   142,
     143,   143,   143,   144,   144,   144,   145,   146,   146,   147,
     148,   148,   149,   149,   150,   150,   150,   150,   151,   151,
     151,   151,   151,   152,   152,   153,   153,   154,   154,   155,
     155,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   157,   158,   159,   160,   161,   162,   163,   163,
     163,   163,   163,   164,   164,   165,   165,   166,   166,   166,
     167,   167,   168,   168,   168,   168,   169,   170,   170,   170,
     170,   170,   170,   170,   170,   171,   172,   173,   174,   175,
     176
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     6,     1,     2,     1,     2,     3,
       4,     5,     6,     3,     4,     5,     6,     3,     4,     5,
       6,     3,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     5,     3,     3,     5,     3,     3,     5,
       3,     3,     5,     3,     3,     5,     3,     3,     5,     3,
       3,     3,     3,     3,     3,     5,     3,     3,     5,     3,
       3,     5,     3,     3,     5,     3,     3,     3,     5,     3,
       3,     5,     2,     3,     2,     4,     3,     5,     3,     5,
       4,     6,     3,     2,     4,     2,     4,     3,     5,     3,
       5,     0,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     5,
       3,     5,     4,     3,     3,     3,     5,     3,     2,     5,
       3,     4,     4,     1,     6,     6,     4,     1,     1,     3,
       3,     3,     3,     3,     4,     1,     0,     1,     1,     1,
       0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,     0,     0,   101,     0,   101,     0,   101,
       0,   101,     0,   101,   101,   101,   101,   101,   101,     0,
     101,     0,   101,     0,   101,     0,   101,   101,     0,   101,
     101,     0,   101,     0,     0,   145,   148,   133,     0,     0,
       0,     0,   101,     0,   101,     0,   101,     5,    24,    25,
      26,    27,    23,    28,    29,    30,    31,    32,    33,    34,
      36,    35,    37,    38,    39,    40,    41,     7,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
     105,   104,   103,   102,   106,   107,   108,   109,   110,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       8,   137,   138,     0,     0,     0,     0,     0,     0,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,     0,    13,     0,    17,
       0,    21,    44,    42,   101,    84,   101,     0,   101,    83,
       0,    47,    45,   101,    50,    48,   101,    53,    51,   101,
      57,   101,    59,    60,    61,    63,    62,    66,    64,   101,
      69,    67,   101,    72,    70,   101,    75,    73,   101,    76,
      77,   101,    79,    56,    54,   101,    80,   101,     0,     0,
       0,     0,    97,   101,    99,   101,     0,     0,     0,     0,
       0,     0,     0,     3,     0,     0,     0,     0,     0,   146,
       0,   150,   130,     0,   101,   112,   127,     0,   115,   114,
     113,   116,   117,   118,   120,     0,     0,   123,   124,   125,
       0,     0,     0,     0,     0,     0,     0,     0,   101,     0,
       0,    86,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   132,    94,    96,     0,     0,
      10,     0,    14,     0,    18,     0,    22,   143,   140,   139,
     141,   142,     0,     0,     0,   131,     0,     0,     0,   122,
       0,     0,    11,    15,    19,    43,    88,   101,    92,     0,
       0,    85,     0,    46,    49,    52,    58,    65,    68,    71,
      74,    78,    55,    81,   136,    98,   100,     0,     0,     0,
       0,   144,     0,     4,   129,   119,   121,   126,     0,    90,
     101,    87,    12,    16,    20,   147,   134,   149,   135,    89,
       0,    91
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,   121,
     208,    73,    74,    75,    76,     4,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,    81,    77,   152,   173,
      78,   332,   386,    79,   388,   334
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -87
static const yytype_int16 yypact[] =
{
     108,  2403,    32,    50,   346,  2403,    32,  2403,    32,  2403,
      32,  2403,   -87,    32,   109,   -87,    32,   -87,    32,   -87,
      32,   -87,    32,   -87,   -87,   -87,   -87,   -87,   -87,    32,
     -87,    32,   -87,    32,   -87,    32,   -87,   -87,    32,   -87,
     -87,    32,   -87,    32,   -86,   -87,   -87,   -87,   -66,    32,
     -59,    32,   -87,    32,   -87,    32,  2524,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,    76,    76,
     -42,    -6,   -87,   -35,    16,    32,   -27,   -22,    -5,    -1,
      12,    28,    30,    32,    32,    43,    62,    71,    32,  2524,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     467,     1,   588,     5,   709,     7,   830,  2756,    13,   -87,
      57,   168,  2778,    15,  2821,    17,  2902,    18,  3115,    19,
    3137,  3158,  3180,  3201,  3223,  2974,    20,  2991,    21,  3034,
      22,  3055,    23,  3240,  3283,    25,  3302,  3094,    27,  3324,
      29,    -2,    -4,   -87,    31,   -87,    33,  2657,    35,  2614,
      37,  2403,    32,  2403,    32,  2403,    32,  2403,   -87,  2575,
     -87,   -87,   -87,   -34,    75,    89,    34,  2403,    90,   -87,
     112,    38,    64,   104,    74,   115,   114,   113,   117,    39,
      40,   121,   122,   123,    41,   -87,  2403,   -87,  2403,   -87,
    2403,   -87,   -87,   -87,   -87,   -87,   -87,    32,    72,   -87,
      82,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,    98,   119,
     103,   101,   -87,   -87,   -87,   -87,   951,    44,  1072,    45,
    1193,    47,  1314,   -87,    76,    76,    76,    76,    76,   -87,
     118,   -87,   -87,   116,  2524,   -87,   -87,   128,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   130,   -63,   -87,   -87,   -87,
     131,  1435,  1556,  1677,  2737,   708,    48,   198,   -87,    32,
     466,   -87,    72,  2799,  2842,  2919,  3345,  3367,  3400,  3427,
    3460,  3486,  3517,  3541,    76,   -87,   -87,   -87,  2676,  2635,
     -87,  2403,   -87,  2403,   -87,  2403,   -87,   -41,   -47,   -47,
      97,    97,  2403,    76,  2403,   -87,  2592,   189,   153,   -87,
     155,   149,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   829,
      49,   -87,   587,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   100,   -87,   -87,  1798,  1919,  2040,
    2161,   -41,  2282,   -87,   -87,   -87,   -87,   -87,   950,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
    1071,   -87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -87,   -87,    -3,   -24,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
      36,   -87,   -87,   -87,   -87,   -12,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,    85,     3,   -87,   -10,
     -87,   -87,   -87,   -87,   -87,   -87
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     117,    99,   110,   122,   112,   124,   114,   126,   116,   128,
     176,   130,   131,   132,   133,   134,   135,   176,   137,   151,
     139,   176,   141,   176,   143,   144,   339,   146,   147,   176,
     149,   176,   168,   176,   176,   176,   176,   176,   176,   176,
     157,   176,   159,   176,   169,   176,   340,   176,    80,   176,
      82,   176,   153,   176,   176,   176,   176,   176,   179,   170,
     176,   176,   155,   176,   176,   176,   267,   268,   175,   174,
     265,   266,   267,   268,   178,   168,   264,   265,   266,   267,
     268,   205,   182,   270,   206,   207,   168,   183,   168,   270,
     168,   111,   168,   113,   269,   115,   270,   297,   118,   298,
     299,   123,   170,   125,   184,   127,   301,   129,   185,   206,
     207,     1,     2,   170,   136,   170,   138,   170,   140,   170,
     142,   186,   177,   145,   249,   180,   148,   248,   150,   196,
     275,   119,   120,   198,   154,   200,   156,   187,   158,   188,
     160,   204,   278,   213,   273,   216,   219,   221,   229,   232,
     235,   238,   191,   241,   276,   245,   280,   247,   256,   250,
     258,   251,   260,   253,   262,   255,   277,   285,   286,   290,
     181,   192,   321,   323,   274,   325,   347,   380,   189,   190,
     193,   171,   172,   194,   279,   264,   265,   266,   267,   268,
     209,   210,   294,   291,   295,   292,   300,   293,   272,   281,
     282,   303,   283,   271,   304,   270,   284,   305,   314,   306,
     264,   265,   266,   267,   268,   287,   288,   307,   315,   289,
     308,   316,   317,   309,   348,   335,   310,   270,   333,   311,
     270,   374,   168,   312,   168,   313,   168,   337,   168,   338,
     341,   318,   375,   319,   376,   377,   302,   257,     0,   259,
     168,   261,     0,     0,   327,   328,   329,   330,   331,   170,
       0,   170,   336,   170,     0,   170,     0,   168,   168,   168,
       0,     0,     0,     0,     0,     0,     0,   170,     0,     0,
       0,     0,     0,     0,     0,     0,   349,     0,     0,     0,
     352,     0,   296,     0,   170,   170,   170,     0,     0,     0,
       0,     0,     0,     0,   364,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   367,     0,
     368,     0,   369,   371,     0,     0,     0,     0,     0,   370,
       0,   372,     0,     0,     0,   378,     0,     0,     0,     0,
       0,     0,     0,   168,   168,   168,   168,     0,   168,     0,
       0,     0,     5,     6,     0,     7,     8,     0,     9,     0,
      10,    11,     0,     0,    12,     0,    13,    14,   390,     0,
     170,   170,   170,   170,     0,   170,    15,    16,     0,    17,
      18,     0,    19,    20,   350,    83,     0,    84,     0,    85,
      21,    22,     0,    23,    24,    25,    26,    27,    28,     0,
      29,    30,     0,    31,    32,     0,    33,    34,    35,     0,
      36,     0,    37,    38,     0,    39,     0,    40,    41,     0,
      42,    43,     0,    86,     0,    87,     0,    88,     0,    89,
       0,    90,     0,    91,    92,     0,    93,    94,    95,    96,
       0,    97,     0,    98,    44,     0,    45,     0,    46,     0,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,     0,    50,    51,     0,    52,    53,
       0,    54,    55,   161,   162,   195,   163,   164,     0,   165,
       0,   166,   167,     0,     0,    12,     0,    13,    14,     0,
     351,     0,     0,     0,     0,     0,     0,    15,    16,     0,
      17,    18,     0,    19,    20,    83,     0,    84,     0,    85,
       0,    21,    22,     0,    23,    24,    25,    26,    27,    28,
       0,    29,    30,     0,    31,    32,     0,    33,    34,    35,
       0,    36,     0,    37,    38,     0,    39,     0,    40,    41,
       0,    42,    43,    86,     0,    87,     0,    88,     0,    89,
       0,    90,     0,    91,    92,     0,    93,    94,    95,    96,
       0,    97,     0,    98,     0,    44,     0,    45,     0,    46,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    49,     0,    50,    51,     0,    52,
      53,     0,    54,    55,   161,   162,     0,   163,   164,   197,
     165,     0,   166,   167,     0,     0,    12,     0,    13,    14,
       0,   381,     0,     0,     0,     0,     0,     0,    15,    16,
       0,    17,    18,     0,    19,    20,    83,     0,    84,     0,
      85,     0,    21,    22,     0,    23,    24,    25,    26,    27,
      28,     0,    29,    30,     0,    31,    32,     0,    33,    34,
      35,     0,    36,     0,    37,    38,     0,    39,     0,    40,
      41,     0,    42,    43,    86,     0,    87,     0,    88,     0,
      89,     0,    90,     0,    91,    92,     0,    93,    94,    95,
      96,     0,    97,     0,    98,     0,    44,     0,    45,     0,
      46,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    49,     0,    50,    51,     0,
      52,    53,     0,    54,    55,   161,   162,     0,   163,   164,
       0,   165,   199,   166,   167,     0,     0,    12,     0,    13,
      14,     0,     0,     0,     0,     0,     0,   346,     0,    15,
      16,     0,    17,    18,     0,    19,    20,    83,     0,    84,
       0,    85,     0,    21,    22,     0,    23,    24,    25,    26,
      27,    28,     0,    29,    30,     0,    31,    32,     0,    33,
      34,    35,     0,    36,     0,    37,    38,     0,    39,     0,
      40,    41,     0,    42,    43,    86,     0,    87,     0,    88,
       0,    89,     0,    90,     0,    91,    92,     0,    93,    94,
      95,    96,     0,    97,     0,    98,     0,    44,     0,    45,
       0,    46,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    49,     0,    50,    51,
       0,    52,    53,     0,    54,    55,   161,   162,     0,   163,
     164,     0,   165,     0,   166,   167,     0,   201,    12,     0,
      13,    14,     0,     0,     0,     0,     0,     0,   379,     0,
      15,    16,     0,    17,    18,     0,    19,    20,    83,     0,
      84,     0,    85,     0,    21,    22,     0,    23,    24,    25,
      26,    27,    28,     0,    29,    30,     0,    31,    32,     0,
      33,    34,    35,     0,    36,     0,    37,    38,     0,    39,
       0,    40,    41,     0,    42,    43,    86,     0,    87,     0,
      88,     0,    89,     0,    90,     0,    91,    92,     0,    93,
      94,    95,    96,     0,    97,     0,    98,     0,    44,     0,
      45,     0,    46,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,    49,     0,    50,
      51,     0,    52,    53,     0,    54,    55,   161,   162,   320,
     163,   164,     0,   165,     0,   166,   167,     0,     0,    12,
       0,    13,    14,     0,     0,     0,     0,     0,     0,   389,
       0,    15,    16,     0,    17,    18,     0,    19,    20,    83,
       0,    84,     0,    85,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,    31,    32,
       0,    33,    34,    35,     0,    36,     0,    37,    38,     0,
      39,     0,    40,    41,     0,    42,    43,    86,     0,    87,
       0,    88,     0,    89,     0,    90,     0,    91,    92,     0,
      93,    94,    95,    96,     0,    97,     0,    98,     0,    44,
       0,    45,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,   161,   162,
       0,   163,   164,   322,   165,     0,   166,   167,     0,     0,
      12,     0,    13,    14,     0,     0,     0,     0,     0,     0,
     391,     0,    15,    16,     0,    17,    18,     0,    19,    20,
      83,     0,    84,     0,    85,     0,    21,    22,     0,    23,
      24,    25,    26,    27,    28,     0,    29,    30,     0,    31,
      32,     0,    33,    34,    35,     0,    36,     0,    37,    38,
       0,    39,     0,    40,    41,     0,    42,    43,    86,     0,
      87,     0,    88,     0,    89,     0,    90,     0,    91,    92,
       0,    93,    94,    95,    96,     0,    97,     0,    98,     0,
      44,     0,    45,     0,    46,     0,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    49,
       0,    50,    51,     0,    52,    53,     0,    54,    55,   161,
     162,     0,   163,   164,     0,   165,   324,   166,   167,     0,
       0,    12,     0,    13,    14,     0,     0,     0,     0,     0,
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
     161,   162,     0,   163,   164,     0,   165,     0,   166,   167,
       0,   326,    12,     0,    13,    14,     0,     0,     0,     0,
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
      55,   161,   162,   342,   163,   164,     0,   165,     0,   166,
     167,     0,     0,    12,     0,    13,    14,     0,     0,     0,
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
      54,    55,   161,   162,     0,   163,   164,   343,   165,     0,
     166,   167,     0,     0,    12,     0,    13,    14,     0,     0,
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
       0,    54,    55,   161,   162,     0,   163,   164,     0,   165,
     344,   166,   167,     0,     0,    12,     0,    13,    14,     0,
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
      53,     0,    54,    55,   161,   162,   382,   163,   164,     0,
     165,     0,   166,   167,     0,     0,    12,     0,    13,    14,
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
      52,    53,     0,    54,    55,   161,   162,     0,   163,   164,
     383,   165,     0,   166,   167,     0,     0,    12,     0,    13,
      14,     0,     0,     0,     0,     0,     0,     0,     0,    15,
      16,     0,    17,    18,     0,    19,    20,     0,     0,     0,
       0,     0,     0,    21,    22,     0,    23,    24,    25,    26,
      27,    28,     0,    29,    30,     0,    31,    32,     0,    33,
      34,    35,     0,    36,     0,    37,    38,     0,    39,     0,
      40,    41,     0,    42,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,    45,
       0,    46,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    49,     0,    50,    51,
       0,    52,    53,     0,    54,    55,   161,   162,     0,   163,
     164,     0,   165,   384,   166,   167,     0,     0,    12,     0,
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
      51,     0,    52,    53,     0,    54,    55,   161,   162,     0,
     163,   164,     0,   165,     0,   166,   167,     0,     0,    12,
       0,    13,    14,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    16,     0,    17,    18,     0,    19,    20,     0,
       0,     0,     0,     0,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,    29,    30,     0,    31,    32,
       0,    33,    34,    35,     0,    36,     0,    37,    38,     0,
      39,     0,    40,    41,     0,    42,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,    45,   385,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,   161,   162,
       0,   163,   164,     0,   165,     0,   166,   167,     0,     0,
      12,     0,    13,    14,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    16,     0,    17,    18,     0,    19,    20,
       0,     0,     0,     0,     0,     0,    21,    22,     0,    23,
      24,    25,    26,    27,    28,     0,    29,    30,     0,    31,
      32,     0,    33,    34,    35,     0,    36,     0,    37,    38,
       0,    39,     0,    40,    41,     0,    42,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,     0,    45,     0,    46,   387,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    49,
       0,    50,    51,     0,    52,    53,     0,    54,    55,     5,
       6,     0,     7,     8,     0,     9,     0,    10,    11,     0,
       0,    12,     0,    13,    14,     0,     0,     0,     0,     0,
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
     161,   162,     0,   163,   164,     0,   165,     0,   166,   167,
       0,     0,    12,     0,    13,    14,     0,     0,     0,     0,
       0,     0,     0,     0,    15,    16,     0,    17,    18,     0,
      19,    20,     0,     0,     0,     0,     0,     0,    21,    22,
       0,    23,    24,    25,    26,    27,    28,     0,    29,    30,
     263,    31,    32,     0,    33,    34,    35,     0,    36,     0,
      37,    38,     0,    39,     0,    40,    41,   373,    42,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,     0,    84,     0,    85,     0,
       0,     0,    44,     0,    45,     0,    46,     0,    47,     0,
       0,    83,     0,    84,     0,    85,     0,     0,     0,     0,
      48,    49,     0,    50,    51,     0,    52,    53,     0,    54,
      55,     0,    86,    83,    87,    84,    88,    85,    89,     0,
      90,     0,    91,    92,     0,    93,    94,    95,    96,    86,
      97,    87,    98,    88,    83,    89,    84,    90,    85,    91,
      92,     0,    93,    94,    95,    96,     0,    97,     0,    98,
       0,    86,     0,    87,     0,    88,    83,    89,    84,    90,
      85,    91,    92,     0,    93,    94,    95,    96,     0,    97,
       0,    98,    86,     0,    87,    83,    88,    84,    89,    85,
      90,     0,    91,    92,     0,    93,    94,    95,    96,     0,
      97,     0,    98,     0,    86,     0,    87,     0,    88,     0,
      89,   254,    90,     0,    91,    92,     0,    93,    94,    95,
      96,     0,    97,    86,    98,    87,   345,    88,     0,    89,
       0,    90,   366,    91,    92,     0,    93,    94,    95,    96,
       0,    97,     0,    98,   202,   203,    83,     0,    84,     0,
      85,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83,     0,    84,     0,    85,
     365,     0,     0,     0,     0,     0,     0,     0,   211,     0,
     212,     0,     0,     0,    86,     0,    87,    83,    88,    84,
      89,    85,    90,     0,    91,    92,     0,    93,    94,    95,
      96,   353,    97,    86,    98,    87,     0,    88,    83,    89,
      84,    90,    85,    91,    92,     0,    93,    94,    95,    96,
       0,    97,     0,    98,   214,    86,   215,    87,     0,    88,
      83,    89,    84,    90,    85,    91,    92,     0,    93,    94,
      95,    96,     0,    97,     0,    98,    86,   354,    87,     0,
      88,    83,    89,    84,    90,    85,    91,    92,     0,    93,
      94,    95,    96,     0,    97,     0,    98,     0,    86,     0,
      87,     0,    88,     0,    89,     0,    90,     0,    91,    92,
       0,    93,    94,    95,    96,     0,    97,     0,    98,    86,
       0,    87,     0,    88,     0,    89,     0,    90,     0,    91,
      92,     0,    93,    94,    95,    96,     0,    97,   217,    98,
     218,    83,     0,    84,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   355,    83,     0,
      84,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
       0,    87,     0,    88,     0,    89,     0,    90,     0,    91,
      92,     0,    93,    94,    95,    96,    86,    97,    87,    98,
      88,     0,    89,     0,    90,     0,    91,    92,     0,    93,
      94,    95,    96,    83,    97,    84,    98,    85,     0,     0,
       0,     0,     0,     0,     0,     0,   227,   228,     0,     0,
      83,     0,    84,     0,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   230,   231,     0,     0,
       0,    86,     0,    87,     0,    88,     0,    89,     0,    90,
       0,    91,    92,     0,    93,    94,    95,    96,    86,    97,
      87,    98,    88,    83,    89,    84,    90,    85,    91,    92,
       0,    93,    94,    95,    96,     0,    97,     0,    98,     0,
       0,     0,   233,   234,    83,     0,    84,     0,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,     0,    87,     0,    88,   236,    89,   237,    90,
       0,    91,    92,     0,    93,    94,    95,    96,     0,    97,
       0,    98,    86,    83,    87,    84,    88,    85,    89,     0,
      90,     0,    91,    92,     0,    93,    94,    95,    96,     0,
      97,     0,    98,     0,    83,     0,    84,     0,    85,     0,
       0,   220,     0,     0,     0,   243,     0,   244,     0,     0,
       0,    86,     0,    87,     0,    88,    83,    89,    84,    90,
      85,    91,    92,   222,    93,    94,    95,    96,     0,    97,
       0,    98,    86,     0,    87,     0,    88,    83,    89,    84,
      90,    85,    91,    92,   223,    93,    94,    95,    96,     0,
      97,     0,    98,     0,    86,     0,    87,     0,    88,    83,
      89,    84,    90,    85,    91,    92,   224,    93,    94,    95,
      96,     0,    97,     0,    98,    86,     0,    87,     0,    88,
      83,    89,    84,    90,    85,    91,    92,   225,    93,    94,
      95,    96,     0,    97,     0,    98,     0,    86,     0,    87,
       0,    88,    83,    89,    84,    90,    85,    91,    92,   226,
      93,    94,    95,    96,     0,    97,     0,    98,    86,    83,
      87,    84,    88,    85,    89,     0,    90,     0,    91,    92,
       0,    93,    94,    95,    96,     0,    97,     0,    98,     0,
      86,     0,    87,     0,    88,   239,    89,     0,    90,     0,
      91,    92,     0,    93,    94,    95,    96,    86,    97,    87,
      98,    88,    83,    89,    84,    90,    85,    91,    92,     0,
      93,    94,    95,    96,     0,    97,     0,    98,     0,     0,
       0,    83,     0,    84,     0,    85,     0,     0,     0,     0,
       0,   240,     0,     0,     0,     0,     0,     0,     0,     0,
      86,     0,    87,    83,    88,    84,    89,    85,    90,     0,
      91,    92,   242,    93,    94,    95,    96,     0,    97,    86,
      98,    87,     0,    88,    83,    89,    84,    90,    85,    91,
      92,   356,    93,    94,    95,    96,     0,    97,     0,    98,
     246,    86,     0,    87,     0,    88,    83,    89,    84,    90,
      85,    91,    92,     0,    93,    94,    95,    96,     0,    97,
     357,    98,    86,     0,    87,     0,    88,     0,    89,     0,
      90,     0,    91,    92,     0,    93,    94,    95,    96,    83,
      97,    84,    98,    85,    86,     0,    87,     0,    88,     0,
      89,     0,    90,     0,    91,    92,   358,    93,    94,    95,
      96,     0,    97,     0,    98,     0,    83,     0,    84,     0,
      85,     0,     0,     0,     0,     0,     0,    86,     0,    87,
       0,    88,     0,    89,     0,    90,   359,    91,    92,     0,
      93,    94,    95,    96,     0,    97,     0,    98,     0,    83,
       0,    84,     0,    85,    86,     0,    87,     0,    88,     0,
      89,     0,    90,     0,    91,    92,     0,    93,    94,    95,
      96,     0,    97,   360,    98,    83,     0,    84,     0,    85,
       0,     0,     0,     0,     0,     0,     0,    86,     0,    87,
       0,    88,     0,    89,     0,    90,     0,    91,    92,     0,
      93,    94,    95,    96,   361,    97,    83,    98,    84,     0,
      85,     0,     0,    86,     0,    87,     0,    88,     0,    89,
       0,    90,     0,    91,    92,     0,    93,    94,    95,    96,
      83,    97,    84,    98,    85,     0,     0,     0,     0,     0,
     362,     0,     0,     0,    86,     0,    87,     0,    88,     0,
      89,     0,    90,     0,    91,    92,     0,    93,    94,    95,
      96,     0,    97,     0,    98,     0,     0,   363,    86,     0,
      87,     0,    88,     0,    89,     0,    90,     0,    91,    92,
       0,    93,    94,    95,    96,     0,    97,     0,    98
};

static const yytype_int16 yycheck[] =
{
      12,     4,     5,    15,     7,    17,     9,    19,    11,    21,
      16,    23,    24,    25,    26,    27,    28,    16,    30,   105,
      32,    16,    34,    16,    36,    37,    89,    39,    40,    16,
      42,    16,    56,    16,    16,    16,    16,    16,    16,    16,
      52,    16,    54,    16,    56,    16,   109,    16,    16,    16,
       0,    16,   118,    16,    16,    16,    16,    16,    42,    56,
      16,    16,   121,    16,    16,    16,   113,   114,   110,    79,
     111,   112,   113,   114,   109,    99,   110,   111,   112,   113,
     114,    24,   109,   130,    27,    28,   110,   109,   112,   130,
     114,     6,   116,     8,   128,    10,   130,    25,    13,    27,
      28,    16,    99,    18,   109,    20,    24,    22,   109,    27,
      28,     3,     4,   110,    29,   112,    31,   114,    33,   116,
      35,   109,   128,    38,   128,   109,    41,   129,    43,   128,
      40,    22,    23,   128,    49,   128,    51,   109,    53,   109,
      55,   128,    78,   128,   110,   128,   128,   128,   128,   128,
     128,   128,   109,   128,    42,   128,    82,   128,   161,   128,
     163,   128,   165,   128,   167,   128,   128,   128,   128,   128,
      85,   109,   128,   128,   177,   128,   128,   128,    93,    94,
     109,   105,   106,    98,    80,   110,   111,   112,   113,   114,
      22,    23,   204,   196,   206,   198,   208,   200,   109,    84,
      86,   213,    89,   128,   216,   130,    89,   219,   110,   221,
     110,   111,   112,   113,   114,    94,    94,   229,    99,    96,
     232,   118,   121,   235,    26,   109,   238,   130,   110,   241,
     130,    42,   256,   245,   258,   247,   260,   109,   262,   109,
     109,   253,    89,   255,    89,    96,   210,   162,    -1,   164,
     274,   166,    -1,    -1,   264,   265,   266,   267,   268,   256,
      -1,   258,   274,   260,    -1,   262,    -1,   291,   292,   293,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   298,    -1,    -1,    -1,
     302,    -1,   207,    -1,   291,   292,   293,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   314,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,    -1,
     323,    -1,   325,   333,    -1,    -1,    -1,    -1,    -1,   332,
      -1,   334,    -1,    -1,    -1,   347,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   367,   368,   369,   370,    -1,   372,    -1,
      -1,    -1,     6,     7,    -1,     9,    10,    -1,    12,    -1,
      14,    15,    -1,    -1,    18,    -1,    20,    21,   380,    -1,
     367,   368,   369,   370,    -1,   372,    30,    31,    -1,    33,
      34,    -1,    36,    37,   299,    39,    -1,    41,    -1,    43,
      44,    45,    -1,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    -1,    57,    58,    -1,    60,    61,    62,    -1,
      64,    -1,    66,    67,    -1,    69,    -1,    71,    72,    -1,
      74,    75,    -1,    77,    -1,    79,    -1,    81,    -1,    83,
      -1,    85,    -1,    87,    88,    -1,    90,    91,    92,    93,
      -1,    95,    -1,    97,    98,    -1,   100,    -1,   102,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,    -1,   119,   120,    -1,   122,   123,
      -1,   125,   126,     6,     7,     8,     9,    10,    -1,    12,
      -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    34,    -1,    36,    37,    39,    -1,    41,    -1,    43,
      -1,    44,    45,    -1,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    62,
      -1,    64,    -1,    66,    67,    -1,    69,    -1,    71,    72,
      -1,    74,    75,    77,    -1,    79,    -1,    81,    -1,    83,
      -1,    85,    -1,    87,    88,    -1,    90,    91,    92,    93,
      -1,    95,    -1,    97,    -1,    98,    -1,   100,    -1,   102,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,   117,    -1,   119,   120,    -1,   122,
     123,    -1,   125,   126,     6,     7,    -1,     9,    10,    11,
      12,    -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    34,    -1,    36,    37,    39,    -1,    41,    -1,
      43,    -1,    44,    45,    -1,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    -1,    57,    58,    -1,    60,    61,
      62,    -1,    64,    -1,    66,    67,    -1,    69,    -1,    71,
      72,    -1,    74,    75,    77,    -1,    79,    -1,    81,    -1,
      83,    -1,    85,    -1,    87,    88,    -1,    90,    91,    92,
      93,    -1,    95,    -1,    97,    -1,    98,    -1,   100,    -1,
     102,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,   117,    -1,   119,   120,    -1,
     122,   123,    -1,   125,   126,     6,     7,    -1,     9,    10,
      -1,    12,    13,    14,    15,    -1,    -1,    18,    -1,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    30,
      31,    -1,    33,    34,    -1,    36,    37,    39,    -1,    41,
      -1,    43,    -1,    44,    45,    -1,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    -1,    57,    58,    -1,    60,
      61,    62,    -1,    64,    -1,    66,    67,    -1,    69,    -1,
      71,    72,    -1,    74,    75,    77,    -1,    79,    -1,    81,
      -1,    83,    -1,    85,    -1,    87,    88,    -1,    90,    91,
      92,    93,    -1,    95,    -1,    97,    -1,    98,    -1,   100,
      -1,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,    -1,   119,   120,
      -1,   122,   123,    -1,   125,   126,     6,     7,    -1,     9,
      10,    -1,    12,    -1,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      30,    31,    -1,    33,    34,    -1,    36,    37,    39,    -1,
      41,    -1,    43,    -1,    44,    45,    -1,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    -1,    57,    58,    -1,
      60,    61,    62,    -1,    64,    -1,    66,    67,    -1,    69,
      -1,    71,    72,    -1,    74,    75,    77,    -1,    79,    -1,
      81,    -1,    83,    -1,    85,    -1,    87,    88,    -1,    90,
      91,    92,    93,    -1,    95,    -1,    97,    -1,    98,    -1,
     100,    -1,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,   119,
     120,    -1,   122,   123,    -1,   125,   126,     6,     7,     8,
       9,    10,    -1,    12,    -1,    14,    15,    -1,    -1,    18,
      -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    30,    31,    -1,    33,    34,    -1,    36,    37,    39,
      -1,    41,    -1,    43,    -1,    44,    45,    -1,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    -1,    57,    58,
      -1,    60,    61,    62,    -1,    64,    -1,    66,    67,    -1,
      69,    -1,    71,    72,    -1,    74,    75,    77,    -1,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    87,    88,    -1,
      90,    91,    92,    93,    -1,    95,    -1,    97,    -1,    98,
      -1,   100,    -1,   102,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,
     119,   120,    -1,   122,   123,    -1,   125,   126,     6,     7,
      -1,     9,    10,    11,    12,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    30,    31,    -1,    33,    34,    -1,    36,    37,
      39,    -1,    41,    -1,    43,    -1,    44,    45,    -1,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    -1,    60,    61,    62,    -1,    64,    -1,    66,    67,
      -1,    69,    -1,    71,    72,    -1,    74,    75,    77,    -1,
      79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,    88,
      -1,    90,    91,    92,    93,    -1,    95,    -1,    97,    -1,
      98,    -1,   100,    -1,   102,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,
      -1,   119,   120,    -1,   122,   123,    -1,   125,   126,     6,
       7,    -1,     9,    10,    -1,    12,    13,    14,    15,    -1,
      -1,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,
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
       6,     7,    -1,     9,    10,    -1,    12,    -1,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,
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
     126,     6,     7,     8,     9,    10,    -1,    12,    -1,    14,
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
     125,   126,     6,     7,    -1,     9,    10,    11,    12,    -1,
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
      -1,   125,   126,     6,     7,    -1,     9,    10,    -1,    12,
      13,    14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,
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
     123,    -1,   125,   126,     6,     7,     8,     9,    10,    -1,
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
     122,   123,    -1,   125,   126,     6,     7,    -1,     9,    10,
      11,    12,    -1,    14,    15,    -1,    -1,    18,    -1,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    33,    34,    -1,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    -1,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    -1,    57,    58,    -1,    60,
      61,    62,    -1,    64,    -1,    66,    67,    -1,    69,    -1,
      71,    72,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,   100,
      -1,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,    -1,   119,   120,
      -1,   122,   123,    -1,   125,   126,     6,     7,    -1,     9,
      10,    -1,    12,    13,    14,    15,    -1,    -1,    18,    -1,
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
     120,    -1,   122,   123,    -1,   125,   126,     6,     7,    -1,
       9,    10,    -1,    12,    -1,    14,    15,    -1,    -1,    18,
      -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    34,    -1,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    -1,    57,    58,
      -1,    60,    61,    62,    -1,    64,    -1,    66,    67,    -1,
      69,    -1,    71,    72,    -1,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,   100,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,
     119,   120,    -1,   122,   123,    -1,   125,   126,     6,     7,
      -1,     9,    10,    -1,    12,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    33,    34,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    -1,    60,    61,    62,    -1,    64,    -1,    66,    67,
      -1,    69,    -1,    71,    72,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,   100,    -1,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,
      -1,   119,   120,    -1,   122,   123,    -1,   125,   126,     6,
       7,    -1,     9,    10,    -1,    12,    -1,    14,    15,    -1,
      -1,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,
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
       6,     7,    -1,     9,    10,    -1,    12,    -1,    14,    15,
      -1,    -1,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      -1,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
       5,    57,    58,    -1,    60,    61,    62,    -1,    64,    -1,
      66,    67,    -1,    69,    -1,    71,    72,     5,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    41,    -1,    43,    -1,
      -1,    -1,    98,    -1,   100,    -1,   102,    -1,   104,    -1,
      -1,    39,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,
     116,   117,    -1,   119,   120,    -1,   122,   123,    -1,   125,
     126,    -1,    77,    39,    79,    41,    81,    43,    83,    -1,
      85,    -1,    87,    88,    -1,    90,    91,    92,    93,    77,
      95,    79,    97,    81,    39,    83,    41,    85,    43,    87,
      88,    -1,    90,    91,    92,    93,    -1,    95,    -1,    97,
      -1,    77,    -1,    79,    -1,    81,    39,    83,    41,    85,
      43,    87,    88,    -1,    90,    91,    92,    93,    -1,    95,
      -1,    97,    77,    -1,    79,    39,    81,    41,    83,    43,
      85,    -1,    87,    88,    -1,    90,    91,    92,    93,    -1,
      95,    -1,    97,    -1,    77,    -1,    79,    -1,    81,    -1,
      83,   127,    85,    -1,    87,    88,    -1,    90,    91,    92,
      93,    -1,    95,    77,    97,    79,    19,    81,    -1,    83,
      -1,    85,   127,    87,    88,    -1,    90,    91,    92,    93,
      -1,    95,    -1,    97,    18,    19,    39,    -1,    41,    -1,
      43,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    41,    -1,    43,
     124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      32,    -1,    -1,    -1,    77,    -1,    79,    39,    81,    41,
      83,    43,    85,    -1,    87,    88,    -1,    90,    91,    92,
      93,    32,    95,    77,    97,    79,    -1,    81,    39,    83,
      41,    85,    43,    87,    88,    -1,    90,    91,    92,    93,
      -1,    95,    -1,    97,    33,    77,    35,    79,    -1,    81,
      39,    83,    41,    85,    43,    87,    88,    -1,    90,    91,
      92,    93,    -1,    95,    -1,    97,    77,    35,    79,    -1,
      81,    39,    83,    41,    85,    43,    87,    88,    -1,    90,
      91,    92,    93,    -1,    95,    -1,    97,    -1,    77,    -1,
      79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,    88,
      -1,    90,    91,    92,    93,    -1,    95,    -1,    97,    77,
      -1,    79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,
      88,    -1,    90,    91,    92,    93,    -1,    95,    36,    97,
      38,    39,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,
      41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,
      88,    -1,    90,    91,    92,    93,    77,    95,    79,    97,
      81,    -1,    83,    -1,    85,    -1,    87,    88,    -1,    90,
      91,    92,    93,    39,    95,    41,    97,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,    -1,
      39,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,
      -1,    77,    -1,    79,    -1,    81,    -1,    83,    -1,    85,
      -1,    87,    88,    -1,    90,    91,    92,    93,    77,    95,
      79,    97,    81,    39,    83,    41,    85,    43,    87,    88,
      -1,    90,    91,    92,    93,    -1,    95,    -1,    97,    -1,
      -1,    -1,    58,    59,    39,    -1,    41,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    79,    -1,    81,    61,    83,    63,    85,
      -1,    87,    88,    -1,    90,    91,    92,    93,    -1,    95,
      -1,    97,    77,    39,    79,    41,    81,    43,    83,    -1,
      85,    -1,    87,    88,    -1,    90,    91,    92,    93,    -1,
      95,    -1,    97,    -1,    39,    -1,    41,    -1,    43,    -1,
      -1,    46,    -1,    -1,    -1,    71,    -1,    73,    -1,    -1,
      -1,    77,    -1,    79,    -1,    81,    39,    83,    41,    85,
      43,    87,    88,    46,    90,    91,    92,    93,    -1,    95,
      -1,    97,    77,    -1,    79,    -1,    81,    39,    83,    41,
      85,    43,    87,    88,    46,    90,    91,    92,    93,    -1,
      95,    -1,    97,    -1,    77,    -1,    79,    -1,    81,    39,
      83,    41,    85,    43,    87,    88,    46,    90,    91,    92,
      93,    -1,    95,    -1,    97,    77,    -1,    79,    -1,    81,
      39,    83,    41,    85,    43,    87,    88,    46,    90,    91,
      92,    93,    -1,    95,    -1,    97,    -1,    77,    -1,    79,
      -1,    81,    39,    83,    41,    85,    43,    87,    88,    46,
      90,    91,    92,    93,    -1,    95,    -1,    97,    77,    39,
      79,    41,    81,    43,    83,    -1,    85,    -1,    87,    88,
      -1,    90,    91,    92,    93,    -1,    95,    -1,    97,    -1,
      77,    -1,    79,    -1,    81,    65,    83,    -1,    85,    -1,
      87,    88,    -1,    90,    91,    92,    93,    77,    95,    79,
      97,    81,    39,    83,    41,    85,    43,    87,    88,    -1,
      90,    91,    92,    93,    -1,    95,    -1,    97,    -1,    -1,
      -1,    39,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    79,    39,    81,    41,    83,    43,    85,    -1,
      87,    88,    70,    90,    91,    92,    93,    -1,    95,    77,
      97,    79,    -1,    81,    39,    83,    41,    85,    43,    87,
      88,    46,    90,    91,    92,    93,    -1,    95,    -1,    97,
      76,    77,    -1,    79,    -1,    81,    39,    83,    41,    85,
      43,    87,    88,    -1,    90,    91,    92,    93,    -1,    95,
      53,    97,    77,    -1,    79,    -1,    81,    -1,    83,    -1,
      85,    -1,    87,    88,    -1,    90,    91,    92,    93,    39,
      95,    41,    97,    43,    77,    -1,    79,    -1,    81,    -1,
      83,    -1,    85,    -1,    87,    88,    56,    90,    91,    92,
      93,    -1,    95,    -1,    97,    -1,    39,    -1,    41,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,
      -1,    81,    -1,    83,    -1,    85,    59,    87,    88,    -1,
      90,    91,    92,    93,    -1,    95,    -1,    97,    -1,    39,
      -1,    41,    -1,    43,    77,    -1,    79,    -1,    81,    -1,
      83,    -1,    85,    -1,    87,    88,    -1,    90,    91,    92,
      93,    -1,    95,    63,    97,    39,    -1,    41,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    87,    88,    -1,
      90,    91,    92,    93,    68,    95,    39,    97,    41,    -1,
      43,    -1,    -1,    77,    -1,    79,    -1,    81,    -1,    83,
      -1,    85,    -1,    87,    88,    -1,    90,    91,    92,    93,
      39,    95,    41,    97,    43,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,    -1,
      83,    -1,    85,    -1,    87,    88,    -1,    90,    91,    92,
      93,    -1,    95,    -1,    97,    -1,    -1,    76,    77,    -1,
      79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,    88,
      -1,    90,    91,    92,    93,    -1,    95,    -1,    97
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,   132,   156,     6,     7,     9,    10,    12,
      14,    15,    18,    20,    21,    30,    31,    33,    34,    36,
      37,    44,    45,    47,    48,    49,    50,    51,    52,    54,
      55,    57,    58,    60,    61,    62,    64,    66,    67,    69,
      71,    72,    74,    75,    98,   100,   102,   104,   116,   117,
     119,   120,   122,   123,   125,   126,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   152,   153,   154,   155,   168,   171,   174,
      16,   167,     0,    39,    41,    43,    77,    79,    81,    83,
      85,    87,    88,    90,    91,    92,    93,    95,    97,   133,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     133,   167,   133,   167,   133,   167,   133,   156,   167,    22,
      23,   150,   156,   167,   156,   167,   156,   167,   156,   167,
     156,   156,   156,   156,   156,   156,   167,   156,   167,   156,
     167,   156,   167,   156,   156,   167,   156,   156,   167,   156,
     167,   105,   169,   118,   167,   121,   167,   156,   167,   156,
     167,     6,     7,     9,    10,    12,    14,    15,   134,   156,
     168,   105,   106,   170,   170,   110,    16,   128,   109,    42,
     109,   167,   109,   109,   109,   109,   109,   109,   109,   167,
     167,   109,   109,   109,   167,     8,   128,    11,   128,    13,
     128,    17,    18,    19,   128,    24,    27,    28,   151,    22,
      23,    30,    32,   128,    33,    35,   128,    36,    38,   128,
      46,   128,    46,    46,    46,    46,    46,    52,    53,   128,
      55,    56,   128,    58,    59,   128,    61,    63,   128,    65,
      68,   128,    70,    71,    73,   128,    76,   128,   129,   128,
     128,   128,   124,   128,   127,   128,   133,   167,   133,   167,
     133,   167,   133,     5,   110,   111,   112,   113,   114,   128,
     130,   128,   109,   110,   133,    40,    42,   128,    78,    80,
      82,    84,    86,    89,    89,   128,   128,    94,    94,    96,
     128,   133,   133,   133,   156,   156,   167,    25,    27,    28,
     156,    24,   151,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   110,    99,   118,   121,   156,   156,
       8,   128,    11,   128,    13,   128,    17,   170,   170,   170,
     170,   170,   172,   110,   176,   109,   156,   109,   109,    89,
     109,   109,     8,    11,    13,    19,    29,   128,    26,   156,
     167,    24,   156,    32,    35,    38,    46,    53,    56,    59,
      63,    68,    73,    76,   170,   124,   127,   133,   133,   133,
     133,   170,   133,     5,    42,    89,    89,    96,   156,    29,
     128,    24,     8,    11,    13,   101,   173,   103,   175,    29,
     156,    29
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
#line 134 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 138 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 142 "gtkdialog_parser.y"
    { 
    		token_store_attr(PUSH | WIDGET_WINDOW, (yyvsp[(2) - (6)].nvval)); 
		start_up();
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 150 "gtkdialog_parser.y"
    { 
		token_store(SUM);      
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 155 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
	}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 158 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
		token_store(SUM);      
	}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 162 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 165 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(3) - (6)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 169 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
	}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 172 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
		token_store(SUM);      
	}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 176 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 179 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(3) - (6)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 183 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
	}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 186 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
		token_store(SUM);      
	}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 190 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 193 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(3) - (6)].nvval));
		token_store(SUM);      
	}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 197 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(1) - (3)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
	}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 201 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(2) - (4)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
		token_store(SUM);      
	}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 231 "gtkdialog_parser.y"
    {
                          token_store(PUSH | WIDGET_ENTRY); 
			 }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 234 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_ENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 237 "gtkdialog_parser.y"
    {
                  yyerror("</entry> expected instead of <entry>.");}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 242 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_EDIT); 
	}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 245 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_EDIT, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 248 "gtkdialog_parser.y"
    {
    		yyerror("</edit> expected instead of <edit>.");
	}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 254 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TREE); 
	}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 257 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_TREE, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 260 "gtkdialog_parser.y"
    {
   		yyerror("</tree> expected instead of <tree>.");
	}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 266 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHOOSER); 
	}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 269 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_CHOOSER, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 272 "gtkdialog_parser.y"
    {
		yyerror("</chooser> expected instead of <chooser>.");
	}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 278 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_LABEL); 
	}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 281 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_LABEL, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 284 "gtkdialog_parser.y"
    {yyerror("</text> expected instead of <text>.");}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 288 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_BUTTON);  }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 289 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_BUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 292 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_OKBUTTON);}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 293 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_CANCELBUTTON);}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 294 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_HELPBUTTON);}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 295 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_NOBUTTON);}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 296 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_YESBUTTON);}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 300 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHECKBOX);
	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 303 "gtkdialog_parser.y"
    {
		//token_store_with_tag_attributes(PUSH | WIDGET_CHECKBOX, $2);
                token_store_attr(PUSH | WIDGET_CHECKBOX, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 307 "gtkdialog_parser.y"
    {
		yyerror("</checkbox> expected instead of <checkbox>.");
	}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 313 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_RADIO);
           }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 316 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_RADIO, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 319 "gtkdialog_parser.y"
    {
		yyerror("</radiobutton> expected instead of <radiobutton>.");
           }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 325 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_PROGRESS);
           }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 328 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_PROGRESS, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 331 "gtkdialog_parser.y"
    {
		yyerror("</progressbar> expected instead of <progressbar>.");
           }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 337 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_LIST); 
	}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 340 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_LIST, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 343 "gtkdialog_parser.y"
    {
    		yyerror("</list> expected instead of <list>.");
	}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 349 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_TABLE);}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 353 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_COMBO);
	}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 356 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_COMBO, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 362 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_GVIM);}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 366 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_PIXMAP);}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 367 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_PIXMAP, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 373 "gtkdialog_parser.y"
    {
                    yyerror("Empty menubar without a single <menu> tag.");
		    }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 376 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_MENUBAR);}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 380 "gtkdialog_parser.y"
    { yyerror("Empty menu without <menuitem> tag.");}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 381 "gtkdialog_parser.y"
    { token_store(PUSH | WIDGET_MENU);   }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 382 "gtkdialog_parser.y"
    { yyerror("Empty menu without <menuitem> tag.");}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 383 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_MENU);   
		token_store(SUM); 
	}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 390 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM); 
	}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 393 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 396 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_MENUITEM); 
		token_store(SUM);
	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 400 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(3) - (6)].nvval)); 
		token_store(SUM);
    	}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 404 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUSEP);
		token_store(SUM);
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 413 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSEPARATOR);
	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 416 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 422 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSEPARATOR);
	}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 425 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 431 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXTEXT);
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 434 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXTEXT, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 440 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXENTRY);
	}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 443 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 463 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_LABEL, (yyvsp[(2) - (3)].cval));     }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 468 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_VARIABLE, (yyvsp[(2) - (3)].cval)); }
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 473 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_VISIBLE, (yyvsp[(2) - (3)].cval));  }
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 478 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_DEFAULT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 483 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_WIDTH, (yyvsp[(2) - (3)].cval));    }
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 488 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_HEIGHT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 493 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_SHELL,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 496 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 499 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 502 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 505 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, "", (yyvsp[(2) - (4)].nvval)); 
	}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 511 "gtkdialog_parser.y"
    {
	         fprintf( stderr, "<output>: Not implemented.\n" ); 
	}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 514 "gtkdialog_parser.y"
    {
         	token_store_with_argument(SET|ATTR_OUTPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 520 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET|ATTR_ACTION, (yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 523 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET | ATTR_ACTION, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 530 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET | ATTR_ITEM, (yyvsp[(2) - (3)].cval));
	}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 533 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_ITEM, "");
    	}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 536 "gtkdialog_parser.y"
    {
		      token_store_with_argument_attr(SET | ATTR_ITEM, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
                    }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 542 "gtkdialog_parser.y"
    {
       		(yyval.nvval) = new_tag_attributeset((yyvsp[(1) - (3)].cval), (yyvsp[(3) - (3)].cval)); 
	}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 545 "gtkdialog_parser.y"
    { 
       		(yyval.nvval) = add_tag_attribute((yyvsp[(1) - (4)].nvval), (yyvsp[(2) - (4)].cval), (yyvsp[(4) - (4)].cval)); 
	}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 552 "gtkdialog_parser.y"
    { 
		token_store(SHOW);     
	}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 555 "gtkdialog_parser.y"
    {
  		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 558 "gtkdialog_parser.y"
    {
		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
		instruction_set_jump((yyvsp[(6) - (6)].ival) + 1, (yyvsp[(1) - (6)].ival));
	}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 565 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMASSG | VARIABLE_NAME, (yyvsp[(1) - (4)].cval)); 
	}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 571 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | VARIABLE_NAME, (yyvsp[(1) - (1)].cval)); 
	}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 574 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | CONST_NUMBER, (yyvsp[(1) - (1)].cval)); 
  	}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 577 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_ADD);
	}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 580 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_SUBST);
	}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 583 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_MULT);
	}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 586 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_DIV);
	}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 589 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_EQ);
	}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 592 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_NE);
	}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 602 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 609 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 613 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 617 "gtkdialog_parser.y"
    {
		token_store(GOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 624 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
    }
    break;



/* Line 1455 of yacc.c  */
#line 3654 "gtkdialog_parser.c"
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
#line 630 "gtkdialog_parser.y"


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


