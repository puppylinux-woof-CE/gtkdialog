
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
     UMINUS = 365
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
#line 410 "gtkdialog_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 422 "gtkdialog_parser.c"

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
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2821

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  119
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNRULES -- Number of states.  */
#define YYNSTATES  360

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   365

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   118,     2,     2,     2,     2,     2,     2,
       2,     2,   113,   112,     2,   111,     2,   114,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   117,     2,
       2,   110,   116,     2,     2,     2,     2,     2,     2,     2,
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
     105,   106,   107,   108,   109,   115
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    11,    18,    20,    23,    25,    28,
      32,    37,    43,    50,    54,    59,    65,    72,    76,    81,
      87,    94,    98,   103,   105,   107,   109,   111,   113,   115,
     117,   119,   121,   123,   125,   127,   129,   131,   133,   137,
     143,   147,   151,   157,   161,   165,   171,   175,   179,   185,
     189,   193,   199,   203,   207,   213,   217,   221,   225,   229,
     233,   237,   243,   247,   251,   257,   261,   265,   271,   275,
     279,   285,   289,   293,   297,   303,   307,   311,   317,   320,
     324,   327,   332,   336,   342,   346,   352,   357,   364,   368,
     369,   372,   375,   378,   381,   384,   387,   390,   393,   396,
     399,   403,   407,   411,   415,   419,   423,   427,   433,   437,
     443,   448,   452,   456,   460,   466,   470,   473,   479,   483,
     488,   493,   495,   502,   509,   514,   516,   518,   522,   526,
     530,   534,   538,   543,   545,   546,   548,   550,   552
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     120,     0,    -1,   140,   121,    -1,     3,   121,   140,     5,
      -1,     4,   151,   116,   121,   140,     5,    -1,   122,    -1,
     121,   122,    -1,   152,    -1,   121,   152,    -1,     6,   121,
       8,    -1,   121,     6,   121,     8,    -1,     7,   151,   116,
     121,     8,    -1,   121,     7,   151,   116,   121,     8,    -1,
       9,   121,    11,    -1,   121,     9,   121,    11,    -1,    10,
     151,   116,   121,    11,    -1,   121,    10,   151,   116,   121,
      11,    -1,    12,   121,    13,    -1,   121,    12,   121,    13,
      -1,    14,   151,   116,   121,    13,    -1,   121,    14,   151,
     116,   121,    13,    -1,    15,   121,    17,    -1,   121,    15,
     121,    17,    -1,   127,    -1,   123,    -1,   124,    -1,   125,
      -1,   126,    -1,   128,    -1,   129,    -1,   130,    -1,   131,
      -1,   132,    -1,   133,    -1,   134,    -1,   136,    -1,   135,
      -1,   137,    -1,    18,   140,    19,    -1,    20,   151,   116,
     140,    19,    -1,    18,   140,    18,    -1,    30,   140,    32,
      -1,    31,   151,   116,   140,    32,    -1,    30,   140,    30,
      -1,    33,   140,    35,    -1,    34,   151,   116,   140,    35,
      -1,    33,   140,    33,    -1,    36,   140,    38,    -1,    37,
     151,   116,   140,    38,    -1,    36,   140,    36,    -1,    71,
     140,    73,    -1,    72,   151,   116,   140,    73,    -1,    71,
     140,    71,    -1,    44,   140,    46,    -1,    45,   151,   116,
     140,    46,    -1,    47,   140,    46,    -1,    48,   140,    46,
      -1,    49,   140,    46,    -1,    51,   140,    46,    -1,    50,
     140,    46,    -1,    52,   140,    53,    -1,    54,   151,   116,
     140,    53,    -1,    52,   140,    52,    -1,    55,   140,    56,
      -1,    57,   151,   116,   140,    56,    -1,    55,   140,    55,
      -1,    58,   140,    59,    -1,    60,   151,   116,   140,    59,
      -1,    58,   140,    58,    -1,    61,   140,    63,    -1,    62,
     151,   116,   140,    63,    -1,    61,   140,    61,    -1,    64,
     140,    65,    -1,    66,   140,    68,    -1,    67,   151,   116,
     140,    68,    -1,    69,   140,    70,    -1,    74,   140,    76,
      -1,    75,   151,   116,   140,    76,    -1,    21,    22,    -1,
      21,   138,    22,    -1,    23,    24,    -1,    23,   139,   140,
      24,    -1,   138,    23,    24,    -1,   138,    23,   139,   140,
      24,    -1,    27,   140,    29,    -1,    28,   151,   116,   140,
      29,    -1,   139,    27,   140,    29,    -1,   139,    28,   151,
     116,   140,    29,    -1,   139,    25,    26,    -1,    -1,   140,
     144,    -1,   140,   143,    -1,   140,   142,    -1,   140,   141,
      -1,   140,   145,    -1,   140,   146,    -1,   140,   147,    -1,
     140,   148,    -1,   140,   149,    -1,   140,   150,    -1,    39,
     109,    40,    -1,    81,   109,    82,    -1,    79,   109,    80,
      -1,    77,   109,    78,    -1,    83,   109,    84,    -1,    85,
     109,    86,    -1,    87,   109,    89,    -1,    90,   151,   116,
     109,    89,    -1,    88,   109,    89,    -1,    91,   151,   116,
     109,    89,    -1,    91,   151,   116,    89,    -1,    92,   109,
      94,    -1,    93,   109,    94,    -1,    95,   109,    96,    -1,
      97,   151,   116,   109,    96,    -1,    41,   109,    42,    -1,
      41,    42,    -1,    43,   151,   116,   109,    42,    -1,    16,
     110,   109,    -1,   151,    16,   110,   109,    -1,    98,   153,
     116,    99,    -1,   104,    -1,   155,   154,   116,   156,   121,
     157,    -1,   158,   154,   116,   160,   121,   159,    -1,   105,
     117,   110,   154,    -1,   105,    -1,   106,    -1,   154,   112,
     154,    -1,   154,   111,   154,    -1,   154,   113,   154,    -1,
     154,   114,   154,    -1,   154,   110,   154,    -1,   154,   118,
     110,   154,    -1,   100,    -1,    -1,   101,    -1,   102,    -1,
     103,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   129,   129,   133,   137,   144,   145,   148,   149,   150,
     153,   157,   160,   164,   167,   171,   174,   178,   181,   185,
     188,   192,   196,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   222,   225,
     228,   233,   236,   239,   245,   248,   251,   257,   260,   263,
     269,   272,   275,   279,   280,   283,   284,   285,   286,   287,
     291,   294,   298,   304,   307,   310,   316,   319,   322,   328,
     331,   334,   340,   344,   347,   353,   357,   358,   364,   367,
     371,   372,   373,   374,   381,   384,   387,   391,   395,   401,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     416,   421,   426,   431,   436,   441,   446,   449,   452,   455,
     458,   464,   467,   473,   476,   483,   486,   489,   495,   498,
     504,   505,   508,   511,   518,   524,   527,   530,   533,   536,
     539,   542,   545,   551,   555,   562,   566,   570,   577
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
  "UMINUS", "'>'", "':'", "'!'", "$accept", "window", "wlist", "widget",
  "entry", "edit", "tree", "chooser", "text", "button", "checkbox",
  "radiobutton", "progressbar", "list", "table", "combo", "gvim", "pixmap",
  "menubar", "menus", "menuitems", "attr", "label", "variable", "visible",
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
      61,    45,    43,    42,    47,   365,    62,    58,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   119,   120,   120,   120,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   123,   123,
     123,   124,   124,   124,   125,   125,   125,   126,   126,   126,
     127,   127,   127,   128,   128,   128,   128,   128,   128,   128,
     129,   129,   129,   130,   130,   130,   131,   131,   131,   132,
     132,   132,   133,   134,   134,   135,   136,   136,   137,   137,
     138,   138,   138,   138,   139,   139,   139,   139,   139,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     141,   142,   143,   144,   145,   146,   147,   147,   147,   147,
     147,   148,   148,   149,   149,   150,   150,   150,   151,   151,
     152,   152,   152,   152,   153,   154,   154,   154,   154,   154,
     154,   154,   154,   155,   156,   157,   158,   159,   160
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     6,     1,     2,     1,     2,     3,
       4,     5,     6,     3,     4,     5,     6,     3,     4,     5,
       6,     3,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     5,
       3,     3,     5,     3,     3,     5,     3,     3,     5,     3,
       3,     5,     3,     3,     5,     3,     3,     3,     3,     3,
       3,     5,     3,     3,     5,     3,     3,     5,     3,     3,
       5,     3,     3,     3,     5,     3,     3,     5,     2,     3,
       2,     4,     3,     5,     3,     5,     4,     6,     3,     0,
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
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,    89,     0,    89,     0,    89,
       0,    89,     0,    89,    89,    89,    89,    89,    89,     0,
      89,     0,    89,     0,    89,     0,    89,    89,     0,    89,
      89,     0,    89,     0,     0,   133,   136,   121,    89,     5,
      24,    25,    26,    27,    23,    28,    29,    30,    31,    32,
      33,    34,    36,    35,    37,     7,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,    93,    92,
      91,    90,    94,    95,    96,    97,    98,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       8,   125,   126,     0,     0,     0,     0,     0,     0,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,     0,    13,     0,    17,
       0,    21,    40,    38,    89,    80,    89,     0,    89,    79,
       0,    43,    41,    89,    46,    44,    89,    49,    47,    89,
      53,    89,    55,    56,    57,    59,    58,    62,    60,    89,
      65,    63,    89,    68,    66,    89,    71,    69,    89,    72,
      73,    89,    75,    52,    50,    89,    76,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,     0,     0,
       0,     0,     0,   134,     0,   138,   118,     0,    89,   100,
     115,     0,   103,   102,   101,   104,   105,   106,   108,     0,
       0,   111,   112,   113,     0,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,    82,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
      10,     0,    14,     0,    18,     0,    22,   131,   128,   127,
     129,   130,     0,     0,     0,   119,     0,     0,     0,   110,
       0,     0,    11,    15,    19,    39,    84,    89,    88,     0,
       0,    81,     0,    42,    45,    48,    54,    61,    64,    67,
      70,    74,    51,    77,   124,     0,     0,     0,     0,   132,
       0,     4,   117,   107,   109,   114,     0,    86,    89,    83,
      12,    16,    20,   135,   122,   137,   123,    85,     0,    87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   109,
     188,     4,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    69,    65,   140,   153,    66,   302,   354,    67,
     356,   304
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int16 yypact[] =
{
     122,  1622,     1,    38,   323,  1622,     1,  1622,     1,  1622,
       1,  1622,   -67,     1,   141,   -67,     1,   -67,     1,   -67,
       1,   -67,     1,   -67,   -67,   -67,   -67,   -67,   -67,     1,
     -67,     1,   -67,     1,   -67,     1,   -67,   -67,     1,   -67,
     -67,     1,   -67,     1,   -63,   -67,   -67,   -67,  1697,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,    61,    61,   -66,     5,
     -67,   -57,   -32,     1,   -55,   -38,   -34,   -30,   -28,   -26,
     -18,     1,     1,   -13,    -9,     4,     1,  1697,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   422,     7,
     497,    13,   572,    15,   647,  1784,    16,   -67,    91,   146,
    1952,    17,  2013,    19,  2073,    21,  2298,    23,  2320,  2341,
    2363,  2384,  2406,  2157,    25,  2174,    27,  2217,    29,  2238,
      30,  2423,  2466,    31,  2485,  2277,    32,  2507,    33,   -15,
       0,  1622,     1,  1622,     1,  1622,     1,  1622,   -67,   190,
     -67,   -67,   -67,   -44,    -7,    62,    20,  1622,    94,   -67,
     128,    34,    58,    98,    97,    96,    99,    93,   107,    35,
      37,    89,    92,   102,    39,   -67,  1622,   -67,  1622,   -67,
    1622,   -67,   -67,   -67,   -67,   -67,   -67,     1,    36,   -67,
     100,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,    78,   103,
     722,    40,   797,    41,   872,    42,   947,   -67,    61,    61,
      61,    61,    61,   -67,    95,   -67,   -67,    90,  1697,   -67,
     -67,   108,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   110,
     -49,   -67,   -67,   -67,   115,  1022,  1097,  1172,  1751,  1866,
      43,   175,   -67,     1,  1811,   -67,    36,  1983,  2042,  2102,
    2528,  2550,  2583,  2610,  2643,  2669,  2700,  2724,    61,   -67,
     -67,  1622,   -67,  1622,   -67,  1622,   -67,   145,   -20,   -20,
      86,    86,  1622,    61,  1622,   -67,  1696,   165,   138,   -67,
     139,   134,   -67,   -67,   -67,   -67,   -67,   -67,   -67,  1883,
      46,   -67,  1844,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   136,  1247,  1322,  1397,  1472,   145,
    1547,   -67,   -67,   -67,   -67,   -67,  1909,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,  1926,   -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,    -3,   -22,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
      45,   -12,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,    79,   -14,   -67,   -48,   -67,   -67,   -67,   -67,
     -67,   -67
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     105,    87,    98,   110,   100,   112,   102,   114,   104,   116,
     159,   118,   119,   120,   121,   122,   123,    68,   125,   154,
     127,   156,   129,   156,   131,   132,   148,   134,   135,   156,
     137,   156,   156,   156,   150,   156,   149,   156,    70,   156,
     309,   156,   139,   156,   155,   156,   156,   156,   156,   156,
     156,   156,   158,   156,   162,   156,   156,   156,   156,   156,
     310,   271,   156,   272,   273,   148,   238,   239,   240,   241,
     242,   163,   243,   150,   244,   164,   148,   160,   148,   165,
     148,   166,   148,   167,   150,    99,   150,   101,   150,   103,
     150,   168,   106,   241,   242,   111,   171,   113,   244,   115,
     172,   117,   228,   238,   239,   240,   241,   242,   124,   245,
     126,   244,   128,   173,   130,   185,   229,   133,   186,   187,
     136,   157,   138,   176,   275,     1,     2,   186,   187,   178,
     247,   180,   184,   193,   249,   196,   252,   199,   230,   201,
     232,   209,   234,   212,   236,   215,   218,   221,   225,   227,
     251,   259,   161,   260,   248,   264,   291,   293,   295,   317,
     169,   170,   348,   107,   108,   174,   151,   152,   189,   190,
     250,   246,   268,   265,   269,   266,   274,   267,   253,   254,
     255,   277,   257,   261,   278,   256,   262,   279,   288,   280,
     297,   298,   299,   300,   301,   237,   258,   281,   263,   305,
     282,   318,   289,   283,   244,   303,   284,   342,   148,   285,
     148,     0,   148,   286,   148,   287,   150,   307,   150,   308,
     150,   231,   150,   233,   311,   235,   148,   343,   344,    71,
     345,    72,     0,    73,   150,   276,   306,     0,     0,     0,
     334,     0,     0,   148,   148,   148,   238,   239,   240,   241,
     242,   150,   150,   150,   244,   339,   239,   240,   241,   242,
     319,     0,     0,   244,   322,     0,   270,    74,     0,    75,
       0,    76,     0,    77,     0,    78,     0,    79,    80,     0,
      81,    82,    83,    84,     0,    85,     0,    86,   335,     0,
     336,     0,   337,     0,     0,     0,     0,     0,     0,   338,
       0,   340,     0,     0,     0,   346,     0,     0,     0,     0,
       0,     0,     0,   148,   148,   148,   148,     0,   148,     0,
       0,   150,   150,   150,   150,     0,   150,     0,     0,     5,
       6,     0,     7,     8,     0,     9,   358,    10,    11,     0,
       0,    12,     0,    13,    14,     0,     0,     0,     0,     0,
       0,     0,   320,    15,    16,     0,    17,    18,     0,    19,
      20,     0,    71,     0,    72,     0,    73,    21,    22,     0,
      23,    24,    25,    26,    27,    28,     0,    29,    30,     0,
      31,    32,     0,    33,    34,    35,     0,    36,     0,    37,
      38,     0,    39,     0,    40,    41,     0,    42,    43,     0,
      74,     0,    75,     0,    76,     0,    77,     0,    78,     0,
      79,    80,     0,    81,    82,    83,    84,     0,    85,     0,
      86,    44,     0,    45,     0,    46,     0,    47,   141,   142,
     175,   143,   144,     0,   145,     0,   146,   147,     0,     0,
      12,     0,    13,    14,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    16,     0,    17,    18,     0,    19,    20,
       0,     0,     0,     0,     0,     0,    21,    22,     0,    23,
      24,    25,    26,    27,    28,     0,    29,    30,     0,    31,
      32,     0,    33,    34,    35,     0,    36,     0,    37,    38,
       0,    39,     0,    40,    41,     0,    42,    43,     0,     0,
       0,     0,     0,   141,   142,     0,   143,   144,   177,   145,
       0,   146,   147,     0,     0,    12,     0,    13,    14,     0,
      44,     0,    45,     0,    46,     0,    47,    15,    16,     0,
      17,    18,     0,    19,    20,     0,     0,     0,     0,     0,
       0,    21,    22,     0,    23,    24,    25,    26,    27,    28,
       0,    29,    30,     0,    31,    32,     0,    33,    34,    35,
       0,    36,     0,    37,    38,     0,    39,     0,    40,    41,
       0,    42,    43,     0,     0,     0,     0,     0,   141,   142,
       0,   143,   144,     0,   145,   179,   146,   147,     0,     0,
      12,     0,    13,    14,     0,    44,     0,    45,     0,    46,
       0,    47,    15,    16,     0,    17,    18,     0,    19,    20,
       0,     0,     0,     0,     0,     0,    21,    22,     0,    23,
      24,    25,    26,    27,    28,     0,    29,    30,     0,    31,
      32,     0,    33,    34,    35,     0,    36,     0,    37,    38,
       0,    39,     0,    40,    41,     0,    42,    43,     0,     0,
       0,     0,     0,   141,   142,     0,   143,   144,     0,   145,
       0,   146,   147,     0,   181,    12,     0,    13,    14,     0,
      44,     0,    45,     0,    46,     0,    47,    15,    16,     0,
      17,    18,     0,    19,    20,     0,     0,     0,     0,     0,
       0,    21,    22,     0,    23,    24,    25,    26,    27,    28,
       0,    29,    30,     0,    31,    32,     0,    33,    34,    35,
       0,    36,     0,    37,    38,     0,    39,     0,    40,    41,
       0,    42,    43,     0,     0,     0,     0,     0,   141,   142,
     290,   143,   144,     0,   145,     0,   146,   147,     0,     0,
      12,     0,    13,    14,     0,    44,     0,    45,     0,    46,
       0,    47,    15,    16,     0,    17,    18,     0,    19,    20,
       0,     0,     0,     0,     0,     0,    21,    22,     0,    23,
      24,    25,    26,    27,    28,     0,    29,    30,     0,    31,
      32,     0,    33,    34,    35,     0,    36,     0,    37,    38,
       0,    39,     0,    40,    41,     0,    42,    43,     0,     0,
       0,     0,     0,   141,   142,     0,   143,   144,   292,   145,
       0,   146,   147,     0,     0,    12,     0,    13,    14,     0,
      44,     0,    45,     0,    46,     0,    47,    15,    16,     0,
      17,    18,     0,    19,    20,     0,     0,     0,     0,     0,
       0,    21,    22,     0,    23,    24,    25,    26,    27,    28,
       0,    29,    30,     0,    31,    32,     0,    33,    34,    35,
       0,    36,     0,    37,    38,     0,    39,     0,    40,    41,
       0,    42,    43,     0,     0,     0,     0,     0,   141,   142,
       0,   143,   144,     0,   145,   294,   146,   147,     0,     0,
      12,     0,    13,    14,     0,    44,     0,    45,     0,    46,
       0,    47,    15,    16,     0,    17,    18,     0,    19,    20,
       0,     0,     0,     0,     0,     0,    21,    22,     0,    23,
      24,    25,    26,    27,    28,     0,    29,    30,     0,    31,
      32,     0,    33,    34,    35,     0,    36,     0,    37,    38,
       0,    39,     0,    40,    41,     0,    42,    43,     0,     0,
       0,     0,     0,   141,   142,     0,   143,   144,     0,   145,
       0,   146,   147,     0,   296,    12,     0,    13,    14,     0,
      44,     0,    45,     0,    46,     0,    47,    15,    16,     0,
      17,    18,     0,    19,    20,     0,     0,     0,     0,     0,
       0,    21,    22,     0,    23,    24,    25,    26,    27,    28,
       0,    29,    30,     0,    31,    32,     0,    33,    34,    35,
       0,    36,     0,    37,    38,     0,    39,     0,    40,    41,
       0,    42,    43,     0,     0,     0,     0,     0,   141,   142,
     312,   143,   144,     0,   145,     0,   146,   147,     0,     0,
      12,     0,    13,    14,     0,    44,     0,    45,     0,    46,
       0,    47,    15,    16,     0,    17,    18,     0,    19,    20,
       0,     0,     0,     0,     0,     0,    21,    22,     0,    23,
      24,    25,    26,    27,    28,     0,    29,    30,     0,    31,
      32,     0,    33,    34,    35,     0,    36,     0,    37,    38,
       0,    39,     0,    40,    41,     0,    42,    43,     0,     0,
       0,     0,     0,   141,   142,     0,   143,   144,   313,   145,
       0,   146,   147,     0,     0,    12,     0,    13,    14,     0,
      44,     0,    45,     0,    46,     0,    47,    15,    16,     0,
      17,    18,     0,    19,    20,     0,     0,     0,     0,     0,
       0,    21,    22,     0,    23,    24,    25,    26,    27,    28,
       0,    29,    30,     0,    31,    32,     0,    33,    34,    35,
       0,    36,     0,    37,    38,     0,    39,     0,    40,    41,
       0,    42,    43,     0,     0,     0,     0,     0,   141,   142,
       0,   143,   144,     0,   145,   314,   146,   147,     0,     0,
      12,     0,    13,    14,     0,    44,     0,    45,     0,    46,
       0,    47,    15,    16,     0,    17,    18,     0,    19,    20,
       0,     0,     0,     0,     0,     0,    21,    22,     0,    23,
      24,    25,    26,    27,    28,     0,    29,    30,     0,    31,
      32,     0,    33,    34,    35,     0,    36,     0,    37,    38,
       0,    39,     0,    40,    41,     0,    42,    43,     0,     0,
       0,     0,     0,   141,   142,   350,   143,   144,     0,   145,
       0,   146,   147,     0,     0,    12,     0,    13,    14,     0,
      44,     0,    45,     0,    46,     0,    47,    15,    16,     0,
      17,    18,     0,    19,    20,     0,     0,     0,     0,     0,
       0,    21,    22,     0,    23,    24,    25,    26,    27,    28,
       0,    29,    30,     0,    31,    32,     0,    33,    34,    35,
       0,    36,     0,    37,    38,     0,    39,     0,    40,    41,
       0,    42,    43,     0,     0,     0,     0,     0,   141,   142,
       0,   143,   144,   351,   145,     0,   146,   147,     0,     0,
      12,     0,    13,    14,     0,    44,     0,    45,     0,    46,
       0,    47,    15,    16,     0,    17,    18,     0,    19,    20,
       0,     0,     0,     0,     0,     0,    21,    22,     0,    23,
      24,    25,    26,    27,    28,     0,    29,    30,     0,    31,
      32,     0,    33,    34,    35,     0,    36,     0,    37,    38,
       0,    39,     0,    40,    41,     0,    42,    43,     0,     0,
       0,     0,     0,   141,   142,     0,   143,   144,     0,   145,
     352,   146,   147,     0,     0,    12,     0,    13,    14,     0,
      44,     0,    45,     0,    46,     0,    47,    15,    16,     0,
      17,    18,     0,    19,    20,     0,     0,     0,     0,     0,
       0,    21,    22,     0,    23,    24,    25,    26,    27,    28,
       0,    29,    30,     0,    31,    32,     0,    33,    34,    35,
       0,    36,     0,    37,    38,     0,    39,     0,    40,    41,
       0,    42,    43,     0,     0,     0,     0,     0,   141,   142,
       0,   143,   144,     0,   145,     0,   146,   147,     0,     0,
      12,     0,    13,    14,     0,    44,     0,    45,     0,    46,
       0,    47,    15,    16,     0,    17,    18,     0,    19,    20,
       0,     0,     0,     0,     0,     0,    21,    22,     0,    23,
      24,    25,    26,    27,    28,     0,    29,    30,     0,    31,
      32,     0,    33,    34,    35,     0,    36,     0,    37,    38,
       0,    39,     0,    40,    41,     0,    42,    43,     0,     0,
       0,     0,     0,   141,   142,     0,   143,   144,     0,   145,
       0,   146,   147,     0,     0,    12,     0,    13,    14,     0,
      44,     0,    45,   353,    46,     0,    47,    15,    16,     0,
      17,    18,     0,    19,    20,     0,     0,     0,     0,     0,
       0,    21,    22,     0,    23,    24,    25,    26,    27,    28,
       0,    29,    30,     0,    31,    32,     0,    33,    34,    35,
       0,    36,     0,    37,    38,     0,    39,     0,    40,    41,
       0,    42,    43,     0,     0,     0,     0,     0,     5,     6,
       0,     7,     8,     0,     9,     0,    10,    11,     0,     0,
      12,     0,    13,    14,     0,    44,     0,    45,     0,    46,
     355,    47,    15,    16,     0,    17,    18,     0,    19,    20,
       0,     0,     0,     0,     0,     0,    21,    22,     0,    23,
      24,    25,    26,    27,    28,     0,    29,    30,     0,    31,
      32,     0,    33,    34,    35,     0,    36,     0,    37,    38,
       0,    39,     0,    40,    41,     0,    42,    43,     0,     0,
       0,   341,     0,   141,   142,     0,   143,   144,     0,   145,
       0,   146,   147,     0,     0,    12,     0,    13,    14,     0,
      44,     0,    45,     0,    46,     0,    47,    15,    16,     0,
      17,    18,     0,    19,    20,    71,     0,    72,     0,    73,
       0,    21,    22,     0,    23,    24,    25,    26,    27,    28,
       0,    29,    30,     0,    31,    32,     0,    33,    34,    35,
       0,    36,     0,    37,    38,     0,    39,     0,    40,    41,
     315,    42,    43,    74,     0,    75,     0,    76,     0,    77,
       0,    78,     0,    79,    80,     0,    81,    82,    83,    84,
      71,    85,    72,    86,    73,    44,     0,    45,     0,    46,
       0,    47,   182,   183,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,     0,    72,     0,    73,    74,     0,
      75,     0,    76,     0,    77,   321,    78,     0,    79,    80,
       0,    81,    82,    83,    84,     0,    85,     0,    86,     0,
      71,     0,    72,     0,    73,     0,     0,     0,     0,     0,
       0,    74,     0,    75,     0,    76,     0,    77,   349,    78,
       0,    79,    80,     0,    81,    82,    83,    84,     0,    85,
       0,    86,     0,    71,     0,    72,     0,    73,    74,     0,
      75,     0,    76,     0,    77,   316,    78,     0,    79,    80,
       0,    81,    82,    83,    84,    71,    85,    72,    86,    73,
       0,     0,   347,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    71,    75,    72,    76,    73,    77,     0,    78,
       0,    79,    80,     0,    81,    82,    83,    84,   357,    85,
       0,    86,     0,    74,     0,    75,     0,    76,    71,    77,
      72,    78,    73,    79,    80,   359,    81,    82,    83,    84,
      74,    85,    75,    86,    76,    71,    77,    72,    78,    73,
      79,    80,     0,    81,    82,    83,    84,     0,    85,     0,
      86,     0,   191,     0,   192,     0,    74,     0,    75,     0,
      76,    71,    77,    72,    78,    73,    79,    80,     0,    81,
      82,    83,    84,    74,    85,    75,    86,    76,     0,    77,
       0,    78,     0,    79,    80,   323,    81,    82,    83,    84,
       0,    85,    71,    86,    72,     0,    73,     0,     0,    74,
       0,    75,     0,    76,     0,    77,     0,    78,     0,    79,
      80,     0,    81,    82,    83,    84,   194,    85,   195,    86,
       0,     0,    71,     0,    72,     0,    73,     0,     0,     0,
      74,     0,    75,     0,    76,     0,    77,     0,    78,     0,
      79,    80,     0,    81,    82,    83,    84,   324,    85,     0,
      86,    71,     0,    72,     0,    73,     0,     0,     0,     0,
      74,     0,    75,     0,    76,     0,    77,     0,    78,     0,
      79,    80,     0,    81,    82,    83,    84,     0,    85,   197,
      86,   198,    71,     0,    72,     0,    73,     0,     0,    74,
       0,    75,     0,    76,     0,    77,     0,    78,     0,    79,
      80,     0,    81,    82,    83,    84,     0,    85,     0,    86,
     325,    71,     0,    72,     0,    73,     0,     0,     0,     0,
      74,     0,    75,     0,    76,     0,    77,     0,    78,     0,
      79,    80,     0,    81,    82,    83,    84,     0,    85,     0,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    74,
       0,    75,     0,    76,     0,    77,     0,    78,     0,    79,
      80,     0,    81,    82,    83,    84,    71,    85,    72,    86,
      73,     0,     0,     0,     0,     0,     0,     0,     0,   207,
     208,     0,     0,    71,     0,    72,     0,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   210,
     211,     0,     0,     0,    74,     0,    75,     0,    76,     0,
      77,     0,    78,     0,    79,    80,     0,    81,    82,    83,
      84,    74,    85,    75,    86,    76,    71,    77,    72,    78,
      73,    79,    80,     0,    81,    82,    83,    84,     0,    85,
       0,    86,     0,     0,     0,   213,   214,    71,     0,    72,
       0,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,     0,    75,     0,    76,   216,
      77,   217,    78,     0,    79,    80,     0,    81,    82,    83,
      84,     0,    85,     0,    86,    74,    71,    75,    72,    76,
      73,    77,     0,    78,     0,    79,    80,     0,    81,    82,
      83,    84,     0,    85,     0,    86,     0,    71,     0,    72,
       0,    73,     0,     0,   200,     0,     0,     0,   223,     0,
     224,     0,     0,     0,    74,     0,    75,     0,    76,    71,
      77,    72,    78,    73,    79,    80,   202,    81,    82,    83,
      84,     0,    85,     0,    86,    74,     0,    75,     0,    76,
      71,    77,    72,    78,    73,    79,    80,   203,    81,    82,
      83,    84,     0,    85,     0,    86,     0,    74,     0,    75,
       0,    76,    71,    77,    72,    78,    73,    79,    80,   204,
      81,    82,    83,    84,     0,    85,     0,    86,    74,     0,
      75,     0,    76,    71,    77,    72,    78,    73,    79,    80,
     205,    81,    82,    83,    84,     0,    85,     0,    86,     0,
      74,     0,    75,     0,    76,    71,    77,    72,    78,    73,
      79,    80,   206,    81,    82,    83,    84,     0,    85,     0,
      86,    74,    71,    75,    72,    76,    73,    77,     0,    78,
       0,    79,    80,     0,    81,    82,    83,    84,     0,    85,
       0,    86,     0,    74,     0,    75,     0,    76,   219,    77,
       0,    78,     0,    79,    80,     0,    81,    82,    83,    84,
      74,    85,    75,    86,    76,    71,    77,    72,    78,    73,
      79,    80,     0,    81,    82,    83,    84,     0,    85,     0,
      86,     0,     0,     0,    71,     0,    72,     0,    73,     0,
       0,     0,     0,     0,   220,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,    75,    71,    76,    72,    77,
      73,    78,     0,    79,    80,   222,    81,    82,    83,    84,
       0,    85,    74,    86,    75,     0,    76,    71,    77,    72,
      78,    73,    79,    80,   326,    81,    82,    83,    84,     0,
      85,     0,    86,   226,    74,     0,    75,     0,    76,    71,
      77,    72,    78,    73,    79,    80,     0,    81,    82,    83,
      84,     0,    85,   327,    86,    74,     0,    75,     0,    76,
       0,    77,     0,    78,     0,    79,    80,     0,    81,    82,
      83,    84,    71,    85,    72,    86,    73,    74,     0,    75,
       0,    76,     0,    77,     0,    78,     0,    79,    80,   328,
      81,    82,    83,    84,     0,    85,     0,    86,     0,    71,
       0,    72,     0,    73,     0,     0,     0,     0,     0,     0,
      74,     0,    75,     0,    76,     0,    77,     0,    78,   329,
      79,    80,     0,    81,    82,    83,    84,     0,    85,     0,
      86,     0,    71,     0,    72,     0,    73,    74,     0,    75,
       0,    76,     0,    77,     0,    78,     0,    79,    80,     0,
      81,    82,    83,    84,     0,    85,   330,    86,    71,     0,
      72,     0,    73,     0,     0,     0,     0,     0,     0,     0,
      74,     0,    75,     0,    76,     0,    77,     0,    78,     0,
      79,    80,     0,    81,    82,    83,    84,   331,    85,    71,
      86,    72,     0,    73,     0,     0,    74,     0,    75,     0,
      76,     0,    77,     0,    78,     0,    79,    80,     0,    81,
      82,    83,    84,    71,    85,    72,    86,    73,     0,     0,
       0,     0,     0,   332,     0,     0,     0,    74,     0,    75,
       0,    76,     0,    77,     0,    78,     0,    79,    80,     0,
      81,    82,    83,    84,     0,    85,     0,    86,     0,     0,
     333,    74,     0,    75,     0,    76,     0,    77,     0,    78,
       0,    79,    80,     0,    81,    82,    83,    84,     0,    85,
       0,    86
};

static const yytype_int16 yycheck[] =
{
      12,     4,     5,    15,     7,    17,     9,    19,    11,    21,
      42,    23,    24,    25,    26,    27,    28,    16,    30,    67,
      32,    16,    34,    16,    36,    37,    48,    39,    40,    16,
      42,    16,    16,    16,    48,    16,    48,    16,     0,    16,
      89,    16,   105,    16,   110,    16,    16,    16,    16,    16,
      16,    16,   109,    16,   109,    16,    16,    16,    16,    16,
     109,    25,    16,    27,    28,    87,   110,   111,   112,   113,
     114,   109,   116,    87,   118,   109,    98,   109,   100,   109,
     102,   109,   104,   109,    98,     6,   100,     8,   102,    10,
     104,   109,    13,   113,   114,    16,   109,    18,   118,    20,
     109,    22,   117,   110,   111,   112,   113,   114,    29,   116,
      31,   118,    33,   109,    35,    24,   116,    38,    27,    28,
      41,   116,    43,   116,    24,     3,     4,    27,    28,   116,
     110,   116,   116,   116,    40,   116,    78,   116,   141,   116,
     143,   116,   145,   116,   147,   116,   116,   116,   116,   116,
     116,   116,    73,   116,   157,   116,   116,   116,   116,   116,
      81,    82,   116,    22,    23,    86,   105,   106,    22,    23,
      42,   109,   184,   176,   186,   178,   188,   180,    80,    82,
      84,   193,    89,    94,   196,    86,    94,   199,   110,   201,
     238,   239,   240,   241,   242,     5,    89,   209,    96,   109,
     212,    26,    99,   215,   118,   110,   218,    42,   230,   221,
     232,    -1,   234,   225,   236,   227,   230,   109,   232,   109,
     234,   142,   236,   144,   109,   146,   248,    89,    89,    39,
      96,    41,    -1,    43,   248,   190,   248,    -1,    -1,    -1,
     288,    -1,    -1,   265,   266,   267,   110,   111,   112,   113,
     114,   265,   266,   267,   118,   303,   111,   112,   113,   114,
     272,    -1,    -1,   118,   276,    -1,   187,    77,    -1,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    87,    88,    -1,
      90,    91,    92,    93,    -1,    95,    -1,    97,   291,    -1,
     293,    -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,   302,
      -1,   304,    -1,    -1,    -1,   317,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   335,   336,   337,   338,    -1,   340,    -1,
      -1,   335,   336,   337,   338,    -1,   340,    -1,    -1,     6,
       7,    -1,     9,    10,    -1,    12,   348,    14,    15,    -1,
      -1,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   273,    30,    31,    -1,    33,    34,    -1,    36,
      37,    -1,    39,    -1,    41,    -1,    43,    44,    45,    -1,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    -1,
      57,    58,    -1,    60,    61,    62,    -1,    64,    -1,    66,
      67,    -1,    69,    -1,    71,    72,    -1,    74,    75,    -1,
      77,    -1,    79,    -1,    81,    -1,    83,    -1,    85,    -1,
      87,    88,    -1,    90,    91,    92,    93,    -1,    95,    -1,
      97,    98,    -1,   100,    -1,   102,    -1,   104,     6,     7,
       8,     9,    10,    -1,    12,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    33,    34,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    -1,    60,    61,    62,    -1,    64,    -1,    66,    67,
      -1,    69,    -1,    71,    72,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,     6,     7,    -1,     9,    10,    11,    12,
      -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,
      98,    -1,   100,    -1,   102,    -1,   104,    30,    31,    -1,
      33,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    62,
      -1,    64,    -1,    66,    67,    -1,    69,    -1,    71,    72,
      -1,    74,    75,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,     9,    10,    -1,    12,    13,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    98,    -1,   100,    -1,   102,
      -1,   104,    30,    31,    -1,    33,    34,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    -1,    60,    61,    62,    -1,    64,    -1,    66,    67,
      -1,    69,    -1,    71,    72,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,     6,     7,    -1,     9,    10,    -1,    12,
      -1,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      98,    -1,   100,    -1,   102,    -1,   104,    30,    31,    -1,
      33,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    62,
      -1,    64,    -1,    66,    67,    -1,    69,    -1,    71,    72,
      -1,    74,    75,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    -1,    12,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    98,    -1,   100,    -1,   102,
      -1,   104,    30,    31,    -1,    33,    34,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    -1,    60,    61,    62,    -1,    64,    -1,    66,    67,
      -1,    69,    -1,    71,    72,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,     6,     7,    -1,     9,    10,    11,    12,
      -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,
      98,    -1,   100,    -1,   102,    -1,   104,    30,    31,    -1,
      33,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    62,
      -1,    64,    -1,    66,    67,    -1,    69,    -1,    71,    72,
      -1,    74,    75,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,     9,    10,    -1,    12,    13,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    98,    -1,   100,    -1,   102,
      -1,   104,    30,    31,    -1,    33,    34,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    -1,    60,    61,    62,    -1,    64,    -1,    66,    67,
      -1,    69,    -1,    71,    72,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,     6,     7,    -1,     9,    10,    -1,    12,
      -1,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      98,    -1,   100,    -1,   102,    -1,   104,    30,    31,    -1,
      33,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    62,
      -1,    64,    -1,    66,    67,    -1,    69,    -1,    71,    72,
      -1,    74,    75,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    -1,    12,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    98,    -1,   100,    -1,   102,
      -1,   104,    30,    31,    -1,    33,    34,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    -1,    60,    61,    62,    -1,    64,    -1,    66,    67,
      -1,    69,    -1,    71,    72,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,     6,     7,    -1,     9,    10,    11,    12,
      -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,
      98,    -1,   100,    -1,   102,    -1,   104,    30,    31,    -1,
      33,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    62,
      -1,    64,    -1,    66,    67,    -1,    69,    -1,    71,    72,
      -1,    74,    75,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,     9,    10,    -1,    12,    13,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    98,    -1,   100,    -1,   102,
      -1,   104,    30,    31,    -1,    33,    34,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    -1,    60,    61,    62,    -1,    64,    -1,    66,    67,
      -1,    69,    -1,    71,    72,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    -1,    12,
      -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,
      98,    -1,   100,    -1,   102,    -1,   104,    30,    31,    -1,
      33,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    62,
      -1,    64,    -1,    66,    67,    -1,    69,    -1,    71,    72,
      -1,    74,    75,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,     9,    10,    11,    12,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    98,    -1,   100,    -1,   102,
      -1,   104,    30,    31,    -1,    33,    34,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    -1,    60,    61,    62,    -1,    64,    -1,    66,    67,
      -1,    69,    -1,    71,    72,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,     6,     7,    -1,     9,    10,    -1,    12,
      13,    14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,
      98,    -1,   100,    -1,   102,    -1,   104,    30,    31,    -1,
      33,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    62,
      -1,    64,    -1,    66,    67,    -1,    69,    -1,    71,    72,
      -1,    74,    75,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,     9,    10,    -1,    12,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    98,    -1,   100,    -1,   102,
      -1,   104,    30,    31,    -1,    33,    34,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    -1,    60,    61,    62,    -1,    64,    -1,    66,    67,
      -1,    69,    -1,    71,    72,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,     6,     7,    -1,     9,    10,    -1,    12,
      -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,
      98,    -1,   100,   101,   102,    -1,   104,    30,    31,    -1,
      33,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    62,
      -1,    64,    -1,    66,    67,    -1,    69,    -1,    71,    72,
      -1,    74,    75,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,     9,    10,    -1,    12,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    98,    -1,   100,    -1,   102,
     103,   104,    30,    31,    -1,    33,    34,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    -1,    60,    61,    62,    -1,    64,    -1,    66,    67,
      -1,    69,    -1,    71,    72,    -1,    74,    75,    -1,    -1,
      -1,     5,    -1,     6,     7,    -1,     9,    10,    -1,    12,
      -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,
      98,    -1,   100,    -1,   102,    -1,   104,    30,    31,    -1,
      33,    34,    -1,    36,    37,    39,    -1,    41,    -1,    43,
      -1,    44,    45,    -1,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    62,
      -1,    64,    -1,    66,    67,    -1,    69,    -1,    71,    72,
      19,    74,    75,    77,    -1,    79,    -1,    81,    -1,    83,
      -1,    85,    -1,    87,    88,    -1,    90,    91,    92,    93,
      39,    95,    41,    97,    43,    98,    -1,   100,    -1,   102,
      -1,   104,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    41,    -1,    43,    77,    -1,
      79,    -1,    81,    -1,    83,    24,    85,    -1,    87,    88,
      -1,    90,    91,    92,    93,    -1,    95,    -1,    97,    -1,
      39,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    79,    -1,    81,    -1,    83,    24,    85,
      -1,    87,    88,    -1,    90,    91,    92,    93,    -1,    95,
      -1,    97,    -1,    39,    -1,    41,    -1,    43,    77,    -1,
      79,    -1,    81,    -1,    83,    29,    85,    -1,    87,    88,
      -1,    90,    91,    92,    93,    39,    95,    41,    97,    43,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    39,    79,    41,    81,    43,    83,    -1,    85,
      -1,    87,    88,    -1,    90,    91,    92,    93,    29,    95,
      -1,    97,    -1,    77,    -1,    79,    -1,    81,    39,    83,
      41,    85,    43,    87,    88,    29,    90,    91,    92,    93,
      77,    95,    79,    97,    81,    39,    83,    41,    85,    43,
      87,    88,    -1,    90,    91,    92,    93,    -1,    95,    -1,
      97,    -1,    30,    -1,    32,    -1,    77,    -1,    79,    -1,
      81,    39,    83,    41,    85,    43,    87,    88,    -1,    90,
      91,    92,    93,    77,    95,    79,    97,    81,    -1,    83,
      -1,    85,    -1,    87,    88,    32,    90,    91,    92,    93,
      -1,    95,    39,    97,    41,    -1,    43,    -1,    -1,    77,
      -1,    79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,
      88,    -1,    90,    91,    92,    93,    33,    95,    35,    97,
      -1,    -1,    39,    -1,    41,    -1,    43,    -1,    -1,    -1,
      77,    -1,    79,    -1,    81,    -1,    83,    -1,    85,    -1,
      87,    88,    -1,    90,    91,    92,    93,    35,    95,    -1,
      97,    39,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,
      77,    -1,    79,    -1,    81,    -1,    83,    -1,    85,    -1,
      87,    88,    -1,    90,    91,    92,    93,    -1,    95,    36,
      97,    38,    39,    -1,    41,    -1,    43,    -1,    -1,    77,
      -1,    79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,
      88,    -1,    90,    91,    92,    93,    -1,    95,    -1,    97,
      38,    39,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,
      77,    -1,    79,    -1,    81,    -1,    83,    -1,    85,    -1,
      87,    88,    -1,    90,    91,    92,    93,    -1,    95,    -1,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,
      88,    -1,    90,    91,    92,    93,    39,    95,    41,    97,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    -1,    -1,    39,    -1,    41,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,    -1,
      83,    -1,    85,    -1,    87,    88,    -1,    90,    91,    92,
      93,    77,    95,    79,    97,    81,    39,    83,    41,    85,
      43,    87,    88,    -1,    90,    91,    92,    93,    -1,    95,
      -1,    97,    -1,    -1,    -1,    58,    59,    39,    -1,    41,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,    61,
      83,    63,    85,    -1,    87,    88,    -1,    90,    91,    92,
      93,    -1,    95,    -1,    97,    77,    39,    79,    41,    81,
      43,    83,    -1,    85,    -1,    87,    88,    -1,    90,    91,
      92,    93,    -1,    95,    -1,    97,    -1,    39,    -1,    41,
      -1,    43,    -1,    -1,    46,    -1,    -1,    -1,    71,    -1,
      73,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,    39,
      83,    41,    85,    43,    87,    88,    46,    90,    91,    92,
      93,    -1,    95,    -1,    97,    77,    -1,    79,    -1,    81,
      39,    83,    41,    85,    43,    87,    88,    46,    90,    91,
      92,    93,    -1,    95,    -1,    97,    -1,    77,    -1,    79,
      -1,    81,    39,    83,    41,    85,    43,    87,    88,    46,
      90,    91,    92,    93,    -1,    95,    -1,    97,    77,    -1,
      79,    -1,    81,    39,    83,    41,    85,    43,    87,    88,
      46,    90,    91,    92,    93,    -1,    95,    -1,    97,    -1,
      77,    -1,    79,    -1,    81,    39,    83,    41,    85,    43,
      87,    88,    46,    90,    91,    92,    93,    -1,    95,    -1,
      97,    77,    39,    79,    41,    81,    43,    83,    -1,    85,
      -1,    87,    88,    -1,    90,    91,    92,    93,    -1,    95,
      -1,    97,    -1,    77,    -1,    79,    -1,    81,    65,    83,
      -1,    85,    -1,    87,    88,    -1,    90,    91,    92,    93,
      77,    95,    79,    97,    81,    39,    83,    41,    85,    43,
      87,    88,    -1,    90,    91,    92,    93,    -1,    95,    -1,
      97,    -1,    -1,    -1,    39,    -1,    41,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    79,    39,    81,    41,    83,
      43,    85,    -1,    87,    88,    70,    90,    91,    92,    93,
      -1,    95,    77,    97,    79,    -1,    81,    39,    83,    41,
      85,    43,    87,    88,    46,    90,    91,    92,    93,    -1,
      95,    -1,    97,    76,    77,    -1,    79,    -1,    81,    39,
      83,    41,    85,    43,    87,    88,    -1,    90,    91,    92,
      93,    -1,    95,    53,    97,    77,    -1,    79,    -1,    81,
      -1,    83,    -1,    85,    -1,    87,    88,    -1,    90,    91,
      92,    93,    39,    95,    41,    97,    43,    77,    -1,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    87,    88,    56,
      90,    91,    92,    93,    -1,    95,    -1,    97,    -1,    39,
      -1,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    79,    -1,    81,    -1,    83,    -1,    85,    59,
      87,    88,    -1,    90,    91,    92,    93,    -1,    95,    -1,
      97,    -1,    39,    -1,    41,    -1,    43,    77,    -1,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    87,    88,    -1,
      90,    91,    92,    93,    -1,    95,    63,    97,    39,    -1,
      41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    79,    -1,    81,    -1,    83,    -1,    85,    -1,
      87,    88,    -1,    90,    91,    92,    93,    68,    95,    39,
      97,    41,    -1,    43,    -1,    -1,    77,    -1,    79,    -1,
      81,    -1,    83,    -1,    85,    -1,    87,    88,    -1,    90,
      91,    92,    93,    39,    95,    41,    97,    43,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    87,    88,    -1,
      90,    91,    92,    93,    -1,    95,    -1,    97,    -1,    -1,
      76,    77,    -1,    79,    -1,    81,    -1,    83,    -1,    85,
      -1,    87,    88,    -1,    90,    91,    92,    93,    -1,    95,
      -1,    97
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,   120,   140,     6,     7,     9,    10,    12,
      14,    15,    18,    20,    21,    30,    31,    33,    34,    36,
      37,    44,    45,    47,    48,    49,    50,    51,    52,    54,
      55,    57,    58,    60,    61,    62,    64,    66,    67,    69,
      71,    72,    74,    75,    98,   100,   102,   104,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   152,   155,   158,    16,   151,
       0,    39,    41,    43,    77,    79,    81,    83,    85,    87,
      88,    90,    91,    92,    93,    95,    97,   121,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   121,   151,
     121,   151,   121,   151,   121,   140,   151,    22,    23,   138,
     140,   151,   140,   151,   140,   151,   140,   151,   140,   140,
     140,   140,   140,   140,   151,   140,   151,   140,   151,   140,
     151,   140,   140,   151,   140,   140,   151,   140,   151,   105,
     153,     6,     7,     9,    10,    12,    14,    15,   122,   140,
     152,   105,   106,   154,   154,   110,    16,   116,   109,    42,
     109,   151,   109,   109,   109,   109,   109,   109,   109,   151,
     151,   109,   109,   109,   151,     8,   116,    11,   116,    13,
     116,    17,    18,    19,   116,    24,    27,    28,   139,    22,
      23,    30,    32,   116,    33,    35,   116,    36,    38,   116,
      46,   116,    46,    46,    46,    46,    46,    52,    53,   116,
      55,    56,   116,    58,    59,   116,    61,    63,   116,    65,
      68,   116,    70,    71,    73,   116,    76,   116,   117,   116,
     121,   151,   121,   151,   121,   151,   121,     5,   110,   111,
     112,   113,   114,   116,   118,   116,   109,   110,   121,    40,
      42,   116,    78,    80,    82,    84,    86,    89,    89,   116,
     116,    94,    94,    96,   116,   121,   121,   121,   140,   140,
     151,    25,    27,    28,   140,    24,   139,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   110,    99,
       8,   116,    11,   116,    13,   116,    17,   154,   154,   154,
     154,   154,   156,   110,   160,   109,   140,   109,   109,    89,
     109,   109,     8,    11,    13,    19,    29,   116,    26,   140,
     151,    24,   140,    32,    35,    38,    46,    53,    56,    59,
      63,    68,    73,    76,   154,   121,   121,   121,   121,   154,
     121,     5,    42,    89,    89,    96,   140,    29,   116,    24,
       8,    11,    13,   101,   157,   103,   159,    29,   140,    29
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
#line 129 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 133 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 137 "gtkdialog_parser.y"
    { 
    		token_store_attr(PUSH | WIDGET_WINDOW, (yyvsp[(2) - (6)].nvval)); 
		start_up();
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 145 "gtkdialog_parser.y"
    { 
		token_store(SUM);      
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 150 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
	}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 153 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
		token_store(SUM);      
	}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 157 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 160 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(3) - (6)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 164 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
	}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 167 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
		token_store(SUM);      
	}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 171 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 174 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(3) - (6)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 178 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
	}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 181 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
		token_store(SUM);      
	}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 185 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 188 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(3) - (6)].nvval));
		token_store(SUM);      
	}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 192 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(1) - (3)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
	}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 196 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(2) - (4)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
		token_store(SUM);      
	}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 222 "gtkdialog_parser.y"
    {
                          token_store(PUSH | WIDGET_ENTRY); 
			 }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 225 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_ENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 228 "gtkdialog_parser.y"
    {
                  yyerror("</entry> expected instead of <entry>.");}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 233 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_EDIT); 
	}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 236 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_EDIT, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 239 "gtkdialog_parser.y"
    {
    		yyerror("</edit> expected instead of <edit>.");
	}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 245 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TREE); 
	}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 248 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_TREE, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 251 "gtkdialog_parser.y"
    {
   		yyerror("</tree> expected instead of <tree>.");
	}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 257 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHOOSER); 
	}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 260 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_CHOOSER, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 263 "gtkdialog_parser.y"
    {
		yyerror("</chooser> expected instead of <chooser>.");
	}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 269 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_LABEL); 
	}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 272 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_LABEL, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 275 "gtkdialog_parser.y"
    {yyerror("</text> expected instead of <text>.");}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 279 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_BUTTON);  }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 280 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_BUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 283 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_OKBUTTON);}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 284 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_CANCELBUTTON);}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 285 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_HELPBUTTON);}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 286 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_NOBUTTON);}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 287 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_YESBUTTON);}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 291 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHECKBOX);
	}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 294 "gtkdialog_parser.y"
    {
		//token_store_with_tag_attributes(PUSH | WIDGET_CHECKBOX, $2);
                token_store_attr(PUSH | WIDGET_CHECKBOX, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 298 "gtkdialog_parser.y"
    {
		yyerror("</checkbox> expected instead of <checkbox>.");
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 304 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_RADIO);
           }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 307 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_RADIO, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 310 "gtkdialog_parser.y"
    {
		yyerror("</radiobutton> expected instead of <radiobutton>.");
           }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 316 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_PROGRESS);
           }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 319 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_PROGRESS, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 322 "gtkdialog_parser.y"
    {
		yyerror("</progressbar> expected instead of <progressbar>.");
           }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 328 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_LIST); 
	}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 331 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_LIST, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 334 "gtkdialog_parser.y"
    {
    		yyerror("</list> expected instead of <list>.");
	}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 340 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_TABLE);}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 344 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_COMBO);
	}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 347 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_COMBO, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 353 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_GVIM);}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 357 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_PIXMAP);}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 358 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_PIXMAP, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 364 "gtkdialog_parser.y"
    {
                    yyerror("Empty menubar without a single <menu> tag.");
		    }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 367 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_MENUBAR);}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 371 "gtkdialog_parser.y"
    { yyerror("Empty menu without <menuitem> tag.");}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 372 "gtkdialog_parser.y"
    { token_store(PUSH | WIDGET_MENU);   }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 373 "gtkdialog_parser.y"
    { yyerror("Empty menu without <menuitem> tag.");}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 374 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_MENU);   
		token_store(SUM); 
	}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 381 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM); 
	}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 384 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 387 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_MENUITEM); 
		token_store(SUM);
	}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 391 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(3) - (6)].nvval)); 
		token_store(SUM);
    	}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 395 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUSEP);
		token_store(SUM);
	}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 416 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_LABEL, (yyvsp[(2) - (3)].cval));     }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 421 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_VARIABLE, (yyvsp[(2) - (3)].cval)); }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 426 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_VISIBLE, (yyvsp[(2) - (3)].cval));  }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 431 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_DEFAULT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 436 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_WIDTH, (yyvsp[(2) - (3)].cval));    }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 441 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_HEIGHT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 446 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_SHELL,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 449 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 452 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 455 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 458 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, "", (yyvsp[(2) - (4)].nvval)); 
	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 464 "gtkdialog_parser.y"
    {
	         fprintf( stderr, "<output>: Not implemented.\n" ); 
	}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 467 "gtkdialog_parser.y"
    {
         	token_store_with_argument(SET|ATTR_OUTPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 473 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET|ATTR_ACTION, (yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 476 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET | ATTR_ACTION, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 483 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET | ATTR_ITEM, (yyvsp[(2) - (3)].cval));
	}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 486 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_ITEM, "");
    	}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 489 "gtkdialog_parser.y"
    {
		      token_store_with_argument_attr(SET | ATTR_ITEM, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
                    }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 495 "gtkdialog_parser.y"
    {
       		(yyval.nvval) = new_tag_attributeset((yyvsp[(1) - (3)].cval), (yyvsp[(3) - (3)].cval)); 
	}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 498 "gtkdialog_parser.y"
    { 
       		(yyval.nvval) = add_tag_attribute((yyvsp[(1) - (4)].nvval), (yyvsp[(2) - (4)].cval), (yyvsp[(4) - (4)].cval)); 
	}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 505 "gtkdialog_parser.y"
    { 
		token_store(SHOW);     
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 508 "gtkdialog_parser.y"
    {
  		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
	}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 511 "gtkdialog_parser.y"
    {
		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
		instruction_set_jump((yyvsp[(6) - (6)].ival) + 1, (yyvsp[(1) - (6)].ival));
	}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 518 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMASSG | VARIABLE_NAME, (yyvsp[(1) - (4)].cval)); 
	}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 524 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | VARIABLE_NAME, (yyvsp[(1) - (1)].cval)); 
	}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 527 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | CONST_NUMBER, (yyvsp[(1) - (1)].cval)); 
  	}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 530 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_ADD);
	}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 533 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_SUBST);
	}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 536 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_MULT);
	}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 539 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_DIV);
	}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 542 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_EQ);
	}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 545 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_NE);
	}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 555 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 562 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 566 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 570 "gtkdialog_parser.y"
    {
		token_store(GOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 577 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
    }
    break;



/* Line 1455 of yacc.c  */
#line 3365 "gtkdialog_parser.c"
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
#line 583 "gtkdialog_parser.y"


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


