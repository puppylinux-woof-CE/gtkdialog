
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
     EFONTBUTTON = 403,
     TERMINAL = 404,
     PART_TERMINAL = 405,
     ETERMINAL = 406
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
#define TERMINAL 404
#define PART_TERMINAL 405
#define ETERMINAL 406




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
#line 507 "gtkdialog_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 519 "gtkdialog_parser.c"

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
#define YYFINAL  119
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3491

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  160
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  185
/* YYNRULES -- Number of states.  */
#define YYNSTATES  522

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   406

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   159,     2,     2,     2,     2,     2,     2,
       2,     2,   115,   114,     2,   113,     2,   116,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   158,     2,
       2,   112,   157,     2,     2,     2,     2,     2,     2,     2,
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
     150,   151,   152,   153,   154,   155,   156
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
     305,   311,   315,   319,   325,   329,   333,   337,   343,   347,
     351,   357,   360,   365,   371,   378,   386,   388,   390,   392,
     395,   400,   406,   413,   421,   425,   430,   436,   443,   446,
     450,   453,   458,   461,   466,   470,   476,   480,   486,   490,
     496,   500,   506,   510,   516,   520,   526,   530,   536,   540,
     546,   550,   556,   560,   566,   570,   576,   577,   580,   583,
     586,   589,   592,   595,   598,   601,   604,   607,   611,   615,
     619,   623,   627,   631,   635,   641,   645,   651,   656,   660,
     664,   668,   674,   678,   681,   687,   691,   696,   701,   703,
     710,   717,   722,   724,   726,   730,   734,   738,   742,   746,
     751,   753,   754,   756,   758,   760
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     161,     0,    -1,   196,   162,    -1,     3,   162,   196,     5,
      -1,     4,   207,   157,   162,   196,     5,    -1,   163,    -1,
     162,   163,    -1,   208,    -1,   162,   208,    -1,     6,   162,
     196,     8,    -1,   162,     6,   162,   196,     8,    -1,     7,
     207,   157,   162,   196,     8,    -1,   162,     7,   207,   157,
     162,   196,     8,    -1,     9,   162,   196,    11,    -1,   162,
       9,   162,   196,    11,    -1,    10,   207,   157,   162,   196,
      11,    -1,   162,    10,   207,   157,   162,   196,    11,    -1,
      12,   162,   196,    13,    -1,   162,    12,   162,   196,    13,
      -1,    14,   207,   157,   162,   196,    13,    -1,   162,    14,
     207,   157,   162,   196,    13,    -1,    15,   162,   196,    17,
      -1,   162,    15,   162,   196,    17,    -1,   168,    -1,   164,
      -1,   165,    -1,   166,    -1,   167,    -1,   169,    -1,   170,
      -1,   171,    -1,   172,    -1,   173,    -1,   174,    -1,   175,
      -1,   177,    -1,   176,    -1,   178,    -1,   183,    -1,   184,
      -1,   185,    -1,   186,    -1,   187,    -1,   188,    -1,   189,
      -1,   190,    -1,   191,    -1,   192,    -1,   193,    -1,   194,
      -1,   195,    -1,    18,   196,    19,    -1,    20,   207,   157,
     196,    19,    -1,    18,   196,    18,    -1,    32,   196,    34,
      -1,    33,   207,   157,   196,    34,    -1,    32,   196,    32,
      -1,    35,   196,    37,    -1,    36,   207,   157,   196,    37,
      -1,    35,   196,    35,    -1,    38,   196,    40,    -1,    39,
     207,   157,   196,    40,    -1,    38,   196,    38,    -1,    73,
     196,    75,    -1,    74,   207,   157,   196,    75,    -1,    73,
     196,    73,    -1,    46,   196,    48,    -1,    47,   207,   157,
     196,    48,    -1,    49,   196,    48,    -1,    50,   196,    48,
      -1,    51,   196,    48,    -1,    53,   196,    48,    -1,    52,
     196,    48,    -1,    54,   196,    55,    -1,    56,   207,   157,
     196,    55,    -1,    54,   196,    54,    -1,    57,   196,    58,
      -1,    59,   207,   157,   196,    58,    -1,    57,   196,    57,
      -1,    60,   196,    61,    -1,    62,   207,   157,   196,    61,
      -1,    60,   196,    60,    -1,    63,   196,    65,    -1,    64,
     207,   157,   196,    65,    -1,    63,   196,    63,    -1,    66,
     196,    67,    -1,    68,   196,    70,    -1,    69,   207,   157,
     196,    70,    -1,    71,   196,    72,    -1,    76,   196,    78,
      -1,    77,   207,   157,   196,    78,    -1,    21,    23,    -1,
      21,   180,   196,    23,    -1,   180,    21,   180,   196,    23,
      -1,    22,   207,   157,   180,   196,    23,    -1,   180,    22,
     207,   157,   180,   196,    23,    -1,   180,    -1,   181,    -1,
     182,    -1,    24,    26,    -1,    24,   179,   196,    26,    -1,
     179,    24,   179,   196,    26,    -1,    25,   207,   157,   179,
     196,    26,    -1,   179,    25,   207,   157,   179,   196,    26,
      -1,    27,   196,    29,    -1,   179,    27,   196,    29,    -1,
      28,   207,   157,   196,    29,    -1,   179,    28,   207,   157,
     196,    29,    -1,    30,    31,    -1,   179,    30,    31,    -1,
     118,   120,    -1,   119,   207,   157,   120,    -1,   121,   123,
      -1,   122,   207,   157,   123,    -1,   124,   196,   126,    -1,
     125,   207,   157,   196,   126,    -1,   127,   196,   129,    -1,
     128,   207,   157,   196,   129,    -1,   130,   196,   132,    -1,
     131,   207,   157,   196,   132,    -1,   133,   196,   135,    -1,
     134,   207,   157,   196,   135,    -1,   136,   196,   138,    -1,
     137,   207,   157,   196,   138,    -1,   139,   196,   141,    -1,
     140,   207,   157,   196,   141,    -1,   142,   196,   144,    -1,
     143,   207,   157,   196,   144,    -1,   145,   196,   147,    -1,
     146,   207,   157,   196,   147,    -1,   148,   196,   150,    -1,
     149,   207,   157,   196,   150,    -1,   151,   196,   153,    -1,
     152,   207,   157,   196,   153,    -1,   154,   196,   156,    -1,
     155,   207,   157,   196,   156,    -1,    -1,   196,   200,    -1,
     196,   199,    -1,   196,   198,    -1,   196,   197,    -1,   196,
     201,    -1,   196,   202,    -1,   196,   203,    -1,   196,   204,
      -1,   196,   205,    -1,   196,   206,    -1,    41,   111,    42,
      -1,    83,   111,    84,    -1,    81,   111,    82,    -1,    79,
     111,    80,    -1,    85,   111,    86,    -1,    87,   111,    88,
      -1,    89,   111,    91,    -1,    92,   207,   157,   111,    91,
      -1,    90,   111,    91,    -1,    93,   207,   157,   111,    91,
      -1,    93,   207,   157,    91,    -1,    94,   111,    96,    -1,
      95,   111,    96,    -1,    97,   111,    98,    -1,    99,   207,
     157,   111,    98,    -1,    43,   111,    44,    -1,    43,    44,
      -1,    45,   207,   157,   111,    44,    -1,    16,   112,   111,
      -1,   207,    16,   112,   111,    -1,   100,   209,   157,   101,
      -1,   106,    -1,   211,   210,   157,   212,   162,   213,    -1,
     214,   210,   157,   216,   162,   215,    -1,   107,   158,   112,
     210,    -1,   107,    -1,   108,    -1,   210,   114,   210,    -1,
     210,   113,   210,    -1,   210,   115,   210,    -1,   210,   116,
     210,    -1,   210,   112,   210,    -1,   210,   159,   112,   210,
      -1,   102,    -1,    -1,   103,    -1,   104,    -1,   105,    -1,
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
     364,   367,   373,   376,   379,   385,   389,   392,   398,   402,
     403,   416,   419,   422,   426,   429,   436,   437,   438,   442,
     445,   448,   452,   455,   462,   465,   469,   472,   479,   482,
     489,   492,   498,   501,   507,   510,   516,   519,   525,   528,
     534,   537,   543,   546,   552,   555,   561,   564,   570,   573,
     579,   582,   588,   591,   597,   600,   605,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   620,   625,   630,
     635,   640,   645,   650,   653,   656,   659,   662,   668,   671,
     677,   680,   687,   690,   693,   699,   702,   708,   709,   712,
     715,   722,   728,   731,   734,   737,   740,   743,   746,   749,
     755,   759,   766,   770,   774,   781
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
  "ECOLORBUTTON", "FONTBUTTON", "PART_FONTBUTTON", "EFONTBUTTON",
  "TERMINAL", "PART_TERMINAL", "ETERMINAL", "'>'", "':'", "'!'", "$accept",
  "window", "wlist", "widget", "entry", "edit", "tree", "chooser", "text",
  "button", "checkbox", "radiobutton", "progressbar", "list", "table",
  "combo", "gvim", "pixmap", "menubar", "menuwlist", "menu", "menuitem",
  "menuitemseparator", "hseparator", "vseparator", "comboboxtext",
  "comboboxentry", "hscale", "vscale", "spinbutton", "timer",
  "togglebutton", "statusbar", "colorbutton", "fontbutton", "terminal",
  "attr", "label", "variable", "sensitive", "defaultvalue", "width",
  "height", "input", "output", "action", "item", "tagattr", "imperative",
  "assignment", "expression", "if", "then", "endif", "while", "ewhile",
  "do", 0
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
     400,   401,   402,   403,   404,   405,   406,    62,    58,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   160,   161,   161,   161,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   164,   164,   164,   165,   165,   165,   166,   166,   166,
     167,   167,   167,   168,   168,   168,   169,   169,   169,   169,
     169,   169,   169,   170,   170,   170,   171,   171,   171,   172,
     172,   172,   173,   173,   173,   174,   175,   175,   176,   177,
     177,   178,   178,   178,   178,   178,   179,   179,   179,   180,
     180,   180,   180,   180,   181,   181,   181,   181,   182,   182,
     183,   183,   184,   184,   185,   185,   186,   186,   187,   187,
     188,   188,   189,   189,   190,   190,   191,   191,   192,   192,
     193,   193,   194,   194,   195,   195,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   197,   198,   199,
     200,   201,   202,   203,   203,   203,   203,   203,   204,   204,
     205,   205,   206,   206,   206,   207,   207,   208,   208,   208,
     208,   209,   210,   210,   210,   210,   210,   210,   210,   210,
     211,   212,   213,   214,   215,   216
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
       5,     3,     3,     5,     3,     3,     3,     5,     3,     3,
       5,     2,     4,     5,     6,     7,     1,     1,     1,     2,
       4,     5,     6,     7,     3,     4,     5,     6,     2,     3,
       2,     4,     2,     4,     3,     5,     3,     5,     3,     5,
       3,     5,     3,     5,     3,     5,     3,     5,     3,     5,
       3,     5,     3,     5,     3,     5,     0,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     5,     3,     5,     4,     3,     3,
       3,     5,     3,     2,     5,     3,     4,     4,     1,     6,
       6,     4,     1,     1,     3,     3,     3,     3,     3,     4,
       1,     0,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,     0,     0,     0,   136,     0,
       0,   136,     0,   136,     0,   136,     0,   136,     0,   136,
     136,   136,   136,   136,   136,     0,   136,     0,   136,     0,
     136,     0,   136,   136,     0,   136,   136,     0,   136,     0,
       0,   180,   183,   168,     0,     0,     0,     0,   136,     0,
     136,     0,   136,     0,   136,     0,   136,     0,   136,     0,
     136,     0,   136,     0,   136,     0,   136,     0,   136,     0,
     136,     5,    24,    25,    26,    27,    23,    28,    29,    30,
      31,    32,    33,    34,    36,    35,    37,     0,    96,    97,
      98,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,     7,     0,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,   140,   139,   138,
     137,   141,   142,   143,   144,   145,   146,   136,     0,   136,
       0,   136,     0,   136,     0,     0,    91,   136,     0,    99,
     136,    96,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,     0,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     0,     8,     0,     0,   136,     0,     0,     0,     0,
     172,   173,     0,     0,     0,     0,     0,     0,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    51,   136,     0,     0,     0,     0,   104,   136,
      56,    54,   136,    59,    57,   136,    62,    60,   136,    66,
     136,    68,    69,    70,    72,    71,    75,    73,   136,    78,
      76,   136,    81,    79,   136,    84,    82,   136,    85,    86,
     136,    88,    65,    63,   136,    89,   136,     0,     0,     0,
       0,   114,   136,   116,   136,   118,   136,   120,   136,   122,
     136,   124,   136,   126,   136,   128,   136,   130,   136,   132,
     136,   134,   136,   136,     0,   136,     0,   136,     0,   136,
       3,   136,     0,     0,     0,   109,   136,     0,     0,     0,
       0,     0,     0,   181,     0,   185,   165,     0,   136,   147,
     162,     0,   150,   149,   148,   151,   152,   153,   155,     0,
       0,   158,   159,   160,     0,     9,   136,    13,   136,    17,
     136,    21,     0,    92,   136,   100,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   111,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   105,   136,     0,     0,   178,   175,   174,
     176,   177,     0,     0,     0,   166,     0,     0,     0,   157,
       0,     0,     0,     0,     0,    52,     0,     0,   106,    55,
      58,    61,    67,    74,    77,    80,    83,    87,    64,    90,
     171,   115,   117,   119,   121,   123,   125,   127,   129,   131,
     133,   135,    10,   136,    14,   136,    18,   136,    22,   101,
     136,     0,    93,   136,     0,   179,     0,     4,   164,   154,
     156,   161,    11,    15,    19,    94,   102,     0,     0,     0,
       0,   107,     0,   182,   169,   184,   170,    12,    16,    20,
     103,    95
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,     4,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   118,   114,   196,
     242,   115,   442,   514,   116,   516,   444
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -110
static const yytype_int16 yypact[] =
{
     100,  1187,    -8,     4,   737,  1187,    -8,  1187,    -8,  1187,
      -8,  1187,  -110,    -8,   102,    -8,   206,    -8,  -110,    -8,
     -21,  -110,    -8,  -110,    -8,  -110,    -8,  -110,    -8,  -110,
    -110,  -110,  -110,  -110,  -110,    -8,  -110,    -8,  -110,    -8,
    -110,    -8,  -110,  -110,    -8,  -110,  -110,    -8,  -110,    -8,
     -91,  -110,  -110,  -110,   -76,    -8,   -45,    -8,  -110,    -8,
    -110,    -8,  -110,    -8,  -110,    -8,  -110,    -8,  -110,    -8,
    -110,    -8,  -110,    -8,  -110,    -8,  -110,    -8,  -110,    -8,
    1337,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,   213,   112,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,    64,    64,   -28,   -11,  -110,
     -22,   -32,    -8,   -19,   -17,    17,    20,    32,    46,    48,
      -8,    -8,    50,    52,    66,    -8,  1337,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  1337,    -2,  1337,
       7,  1337,     9,  1337,  2313,    11,  -110,   230,    13,  -110,
     213,  -110,    16,  2542,    19,  -110,  2690,    21,  2669,    22,
    2772,    23,  2970,    24,  2987,  3013,  3030,  3056,  3073,  2844,
      25,  2458,    26,  2861,    27,  2904,    29,  3097,  3128,    31,
    3152,  2927,    33,  3185,    35,   -62,   -47,  -110,    37,  -110,
      39,  2209,    41,  1910,    43,  1752,    45,  1670,    47,  1610,
      49,  1551,    51,  1491,    53,  1452,    54,   582,    55,   505,
      56,   318,    57,  1187,    -8,  1187,    -8,  1187,    -8,  1187,
    -110,  1709,  -110,   241,    -8,  -110,    -8,    88,   241,    -8,
    -110,  -110,    -7,    -1,    82,    28,  1187,    96,  -110,    98,
      58,    74,    80,    81,    83,    87,   104,   106,    59,    60,
     103,   105,   107,    61,  1826,  1187,  1976,  1187,  2109,  1187,
     886,  -110,  -110,  -110,  2337,   241,  2439,   241,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,    91,   108,   101,
      84,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  1337,    65,  1337,    67,  1337,    69,  1337,
    -110,   213,    70,  2585,    71,  -110,   230,    72,    64,    64,
      64,    64,    64,  -110,   123,  -110,  -110,   128,  1337,  -110,
    -110,   131,  -110,  -110,  -110,  -110,  -110,  -110,  -110,   133,
      -9,  -110,  -110,  -110,   134,  -110,  1337,  -110,  1337,  -110,
    1337,  -110,  2296,  -110,   230,  -110,   213,  2604,  2647,  2712,
    2789,  3207,  3226,  3250,  3269,  3310,  3331,  3370,  3392,    64,
    -110,  -110,  -110,  2231,  2000,  1845,  1730,  1643,  1588,  1528,
    1469,   610,   527,   348,  1867,  1187,  2031,  1187,  2131,  1187,
    1036,  2480,   241,  -110,  -110,  2374,   241,   -15,     1,     1,
      89,    89,  1187,    64,  1187,  -110,  1769,   202,   156,  -110,
     165,   161,  1886,  2066,  2168,  -110,  2398,  2501,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
       8,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  1337,  -110,  1337,  -110,  1337,  -110,  -110,
     213,  2626,  -110,   230,   887,   -15,  1037,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  1941,  2090,  2192,
    2523,  -110,  2415,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,    86,     0,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,   -14,
     -13,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,   -12,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,   514,    38,  -110,
    -109,  -110,  -110,  -110,  -110,  -110,  -110
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -97
static const yytype_int16 yytable[] =
{
     154,   157,   160,   161,   119,   245,   163,   243,   117,   166,
     165,   168,   248,   170,   245,   172,   195,   174,   175,   176,
     177,   178,   179,   245,   181,   245,   183,   245,   185,   245,
     187,   188,   245,   190,   191,   245,   193,   245,   245,   245,
     245,   245,   245,   245,   197,   245,   201,   245,   203,   245,
     205,   245,   207,   245,   209,   245,   211,   245,   213,   245,
     215,   245,   217,   245,   219,   245,   221,   245,   231,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   199,   249,
     230,   245,   449,   245,   244,   245,   245,   245,   245,   247,
     136,   147,   251,   149,   252,   151,   317,   153,   359,   360,
     361,   362,   450,     1,     2,   358,   359,   360,   361,   362,
     318,   358,   359,   360,   361,   362,   361,   362,   232,   355,
     358,   359,   360,   361,   362,   156,    16,    17,   253,    18,
      19,   254,    20,   238,   239,   264,   230,   266,   369,   268,
     367,   270,   370,   255,   364,   274,   246,   230,   276,   230,
     363,   230,   364,   230,   372,   265,   365,   256,   364,   257,
     364,   260,   373,   261,   267,   374,   269,   364,   273,   375,
     275,   240,   241,   277,   232,   376,   279,   262,   282,   285,
     288,   290,   298,   301,   304,   232,   307,   232,   310,   232,
     314,   232,   316,   366,   319,   377,   320,   378,   322,   381,
     324,   382,   326,   409,   328,   383,   330,   412,   332,   410,
     334,   336,   338,   340,   342,   371,   379,   380,   384,   351,
     161,   411,   425,   353,   427,   356,   429,   432,   434,   436,
      16,    17,   159,    18,    19,   443,    20,   233,   234,   445,
     235,   236,   447,   237,   448,   451,   498,   499,   364,   437,
     438,   439,   440,   441,   -96,   -96,   500,   -96,   -96,   501,
     -96,   392,   394,   396,   161,    16,    17,   397,    18,    19,
     398,    20,     0,   399,     0,     0,   400,     0,   401,     0,
       0,     0,     0,     0,     0,     0,   402,     0,     0,   403,
       0,     0,   404,     0,     0,   405,     0,     0,   406,     0,
     470,     0,   407,     0,   408,     0,     0,     0,     0,   343,
     413,   345,   414,   347,   415,   349,   416,     0,   417,     0,
     418,     0,   419,     0,   420,     0,   421,     0,   422,     0,
     423,   424,   368,   426,   495,   428,     0,   430,     0,   431,
       0,     0,     0,   230,   435,   230,     0,   230,     0,   230,
       0,   386,     0,   388,     0,   390,   446,     0,     0,   120,
       0,   121,     0,   122,     0,     0,     0,     0,   230,     0,
       0,     0,     0,     0,   452,     0,   453,     0,   454,     0,
       0,   232,   456,   232,   457,   232,   230,   232,   230,   120,
     230,   121,     0,   122,     0,     0,     0,   123,     0,   124,
       0,   125,     0,   126,     0,   127,   232,   128,   129,     0,
     130,   131,   132,   133,     0,   134,     0,   135,   490,   161,
       0,     0,   491,   493,   232,     0,   232,   123,   232,   124,
       0,   125,     0,   126,     0,   127,     0,   128,   129,     0,
     130,   131,   132,   133,     0,   134,     0,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   507,     0,   508,   341,   509,     0,     0,   510,     0,
       0,   512,     0,   230,     0,   230,     0,   230,     0,     0,
       0,     0,     0,     0,   230,     0,   230,     0,     0,     0,
       0,     0,     0,     0,   481,     0,     0,     0,     0,     0,
       0,   483,     0,   485,     0,   487,     0,     0,     0,     0,
     148,   232,   150,   232,   152,   232,     0,   155,   494,   158,
     496,   162,   232,   164,   232,     0,   167,     0,   169,     0,
     171,     0,   173,     0,     0,     0,   120,     0,   121,   180,
     122,   182,     0,   184,     0,   186,     0,     0,   189,     0,
       0,   192,     0,   194,     0,     0,     0,     0,   120,   198,
     121,   200,   122,   202,     0,   204,     0,   206,     0,   208,
       0,   210,     0,   212,   123,   214,   124,   216,   125,   218,
     126,   220,   127,   222,   128,   129,     0,   130,   131,   132,
     133,     0,   134,     0,   135,     0,   123,     0,   124,     0,
     125,     0,   126,     0,   127,     0,   128,   129,     0,   130,
     131,   132,   133,   120,   134,   121,   135,   122,     0,     0,
       0,     0,     0,     0,     0,     0,   250,     0,     0,     0,
       0,     0,     0,     0,   258,   259,     0,     0,     0,   263,
       0,   120,     0,   121,     0,   122,     0,     0,   339,     0,
       0,   123,     0,   124,     0,   125,     0,   126,     0,   127,
       0,   128,   129,     0,   130,   131,   132,   133,     0,   134,
     480,   135,     0,     0,     0,     0,     0,     0,     0,   123,
       0,   124,     0,   125,     0,   126,     0,   127,     0,   128,
     129,     0,   130,   131,   132,   133,     0,   134,     0,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   337,     0,     0,     0,     0,     0,   344,     0,
     346,     0,   348,     5,     6,     0,     7,     8,   352,     9,
     354,    10,    11,   357,     0,    12,     0,    13,    14,    15,
     479,    16,    17,     0,    18,    19,     0,    20,     0,    21,
      22,     0,    23,    24,     0,    25,    26,     0,   120,     0,
     121,     0,   122,    27,    28,     0,    29,    30,    31,    32,
      33,    34,     0,    35,    36,     0,    37,    38,     0,    39,
      40,    41,     0,    42,     0,    43,    44,     0,    45,     0,
      46,    47,     0,    48,    49,     0,   123,     0,   124,     0,
     125,     0,   126,     0,   127,     0,   128,   129,     0,   130,
     131,   132,   133,     0,   134,     0,   135,    50,     0,    51,
       0,    52,     0,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    55,     0,    56,    57,
       0,    58,    59,     0,    60,    61,     0,    62,    63,     0,
      64,    65,     0,    66,    67,     0,    68,    69,     0,    70,
      71,     0,    72,    73,     0,    74,    75,     0,    76,    77,
       0,    78,    79,   223,   224,     0,   225,   226,     0,   227,
       0,   228,   229,   391,     0,    12,     0,    13,    14,    15,
       0,    16,    17,     0,    18,    19,     0,    20,     0,    21,
      22,     0,    23,    24,     0,    25,    26,   120,     0,   121,
       0,   122,     0,    27,    28,     0,    29,    30,    31,    32,
      33,    34,     0,    35,    36,     0,    37,    38,     0,    39,
      40,    41,     0,    42,     0,    43,    44,     0,    45,     0,
      46,    47,     0,    48,    49,   123,     0,   124,     0,   125,
       0,   126,     0,   127,     0,   128,   129,     0,   130,   131,
     132,   133,     0,   134,     0,   135,     0,    50,     0,    51,
     513,    52,     0,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    55,     0,    56,    57,
       0,    58,    59,     0,    60,    61,     0,    62,    63,     0,
      64,    65,     0,    66,    67,     0,    68,    69,     0,    70,
      71,     0,    72,    73,     0,    74,    75,     0,    76,    77,
       0,    78,    79,   223,   224,     0,   225,   226,     0,   227,
       0,   228,   229,   488,     0,    12,     0,    13,    14,    15,
       0,    16,    17,     0,    18,    19,     0,    20,     0,    21,
      22,     0,    23,    24,     0,    25,    26,   120,     0,   121,
       0,   122,     0,    27,    28,     0,    29,    30,    31,    32,
      33,    34,     0,    35,    36,     0,    37,    38,     0,    39,
      40,    41,     0,    42,     0,    43,    44,     0,    45,     0,
      46,    47,     0,    48,    49,   123,     0,   124,     0,   125,
       0,   126,     0,   127,     0,   128,   129,     0,   130,   131,
     132,   133,     0,   134,     0,   135,     0,    50,     0,    51,
       0,    52,   515,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    55,     0,    56,    57,
       0,    58,    59,     0,    60,    61,     0,    62,    63,     0,
      64,    65,     0,    66,    67,     0,    68,    69,     0,    70,
      71,     0,    72,    73,     0,    74,    75,     0,    76,    77,
       0,    78,    79,     5,     6,     0,     7,     8,     0,     9,
       0,    10,    11,     0,     0,    12,     0,    13,    14,    15,
       0,    16,    17,     0,    18,    19,     0,    20,     0,    21,
      22,     0,    23,    24,     0,    25,    26,     0,     0,     0,
       0,     0,     0,    27,    28,     0,    29,    30,    31,    32,
      33,    34,     0,    35,    36,     0,    37,    38,     0,    39,
      40,    41,     0,    42,     0,    43,    44,     0,    45,     0,
      46,    47,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,     0,    51,
       0,    52,     0,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    55,     0,    56,    57,
       0,    58,    59,     0,    60,    61,     0,    62,    63,     0,
      64,    65,     0,    66,    67,     0,    68,    69,     0,    70,
      71,     0,    72,    73,     0,    74,    75,     0,    76,    77,
       0,    78,    79,   223,   224,     0,   225,   226,     0,   227,
       0,   228,   229,     0,     0,    12,     0,    13,    14,    15,
       0,    16,    17,     0,    18,    19,     0,    20,     0,    21,
      22,     0,    23,    24,     0,    25,    26,     0,     0,     0,
       0,     0,     0,    27,    28,     0,    29,    30,    31,    32,
      33,    34,     0,    35,    36,     0,    37,    38,     0,    39,
      40,    41,     0,    42,     0,    43,    44,     0,    45,     0,
      46,    47,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,     0,    51,
       0,    52,     0,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    55,     0,    56,    57,
       0,    58,    59,     0,    60,    61,     0,    62,    63,     0,
      64,    65,     0,    66,    67,     0,    68,    69,     0,    70,
      71,     0,    72,    73,     0,    74,    75,     0,    76,    77,
       0,    78,    79,   120,     0,   121,     0,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,     0,   121,     0,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,   120,   124,   121,   125,   122,   126,     0,   127,
       0,   128,   129,     0,   130,   131,   132,   133,   123,   134,
     124,   135,   125,     0,   126,     0,   127,     0,   128,   129,
       0,   130,   131,   132,   133,     0,   134,     0,   135,   120,
     123,   121,   124,   122,   125,     0,   126,     0,   127,     0,
     128,   129,     0,   130,   131,   132,   133,     0,   134,     0,
     135,     0,   120,     0,   121,     0,   122,     0,     0,   335,
       0,     0,     0,     0,     0,     0,     0,   123,     0,   124,
       0,   125,     0,   126,     0,   127,   478,   128,   129,     0,
     130,   131,   132,   133,     0,   134,     0,   135,     0,   120,
     123,   121,   124,   122,   125,   333,   126,     0,   127,     0,
     128,   129,     0,   130,   131,   132,   133,     0,   134,     0,
     135,   120,     0,   121,     0,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   123,     0,   124,
       0,   125,   477,   126,     0,   127,     0,   128,   129,     0,
     130,   131,   132,   133,   120,   134,   121,   135,   122,   123,
       0,   124,   331,   125,     0,   126,     0,   127,     0,   128,
     129,     0,   130,   131,   132,   133,     0,   134,     0,   135,
       0,   120,     0,   121,   350,   122,     0,     0,     0,     0,
       0,     0,   123,     0,   124,     0,   125,     0,   126,   476,
     127,     0,   128,   129,     0,   130,   131,   132,   133,     0,
     134,     0,   135,     0,     0,     0,     0,     0,   329,   123,
     120,   124,   121,   125,   122,   126,     0,   127,     0,   128,
     129,     0,   130,   131,   132,   133,     0,   134,     0,   135,
       0,   120,     0,   121,   497,   122,     0,     0,     0,     0,
       0,   475,     0,     0,     0,     0,     0,     0,   123,     0,
     124,     0,   125,   120,   126,   121,   127,   122,   128,   129,
       0,   130,   131,   132,   133,   327,   134,     0,   135,   123,
     120,   124,   121,   125,   122,   126,     0,   127,     0,   128,
     129,     0,   130,   131,   132,   133,     0,   134,     0,   135,
       0,   123,     0,   124,   385,   125,     0,   126,     0,   127,
       0,   128,   129,     0,   130,   131,   132,   133,   123,   134,
     124,   135,   125,     0,   126,     0,   127,     0,   128,   129,
       0,   130,   131,   132,   133,   474,   134,   120,   135,   121,
       0,   122,     0,     0,     0,   482,     0,     0,     0,     0,
       0,     0,     0,     0,   325,     0,   120,     0,   121,     0,
     122,     0,     0,     0,   502,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   123,     0,   124,   120,   125,
     121,   126,   122,   127,     0,   128,   129,     0,   130,   131,
     132,   133,     0,   134,   123,   135,   124,   120,   125,   121,
     126,   122,   127,     0,   128,   129,     0,   130,   131,   132,
     133,     0,   134,     0,   135,     0,   123,     0,   124,   517,
     125,   120,   126,   121,   127,   122,   128,   129,     0,   130,
     131,   132,   133,     0,   134,   123,   135,   124,     0,   125,
       0,   126,     0,   127,     0,   128,   129,   473,   130,   131,
     132,   133,   120,   134,   121,   135,   122,   387,     0,   123,
       0,   124,     0,   125,     0,   126,     0,   127,     0,   128,
     129,     0,   130,   131,   132,   133,     0,   134,     0,   135,
       0,     0,     0,     0,     0,     0,     0,   120,     0,   121,
     123,   122,   124,     0,   125,     0,   126,     0,   127,     0,
     128,   129,     0,   130,   131,   132,   133,     0,   134,   323,
     135,   120,   484,   121,     0,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   123,     0,   124,     0,   125,
       0,   126,     0,   127,     0,   128,   129,     0,   130,   131,
     132,   133,   120,   134,   121,   135,   122,   503,     0,   123,
       0,   124,     0,   125,     0,   126,     0,   127,     0,   128,
     129,     0,   130,   131,   132,   133,     0,   134,     0,   135,
       0,   518,     0,     0,     0,     0,     0,   120,     0,   121,
     123,   122,   124,     0,   125,     0,   126,     0,   127,     0,
     128,   129,   389,   130,   131,   132,   133,     0,   134,   472,
     135,   120,     0,   121,     0,   122,     0,     0,     0,     0,
       0,     0,     0,     0,   486,   123,     0,   124,     0,   125,
     120,   126,   121,   127,   122,   128,   129,     0,   130,   131,
     132,   133,     0,   134,     0,   135,     0,     0,     0,   123,
       0,   124,   120,   125,   121,   126,   122,   127,     0,   128,
     129,   504,   130,   131,   132,   133,     0,   134,   123,   135,
     124,     0,   125,     0,   126,     0,   127,     0,   128,   129,
       0,   130,   131,   132,   133,   519,   134,     0,   135,   120,
     123,   121,   124,   122,   125,     0,   126,     0,   127,     0,
     128,   129,     0,   130,   131,   132,   133,     0,   134,     0,
     135,     0,     0,   120,     0,   121,     0,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   123,     0,   124,
     120,   125,   121,   126,   122,   127,     0,   128,   129,     0,
     130,   131,   132,   133,     0,   134,     0,   135,     0,     0,
       0,   123,   120,   124,   121,   125,   122,   126,     0,   127,
       0,   128,   129,     0,   130,   131,   132,   133,   123,   134,
     124,   135,   125,     0,   126,     0,   127,     0,   128,   129,
       0,   130,   131,   132,   133,     0,   134,     0,   135,     0,
     123,     0,   124,     0,   125,   455,   126,     0,   127,     0,
     128,   129,     0,   130,   131,   132,   133,     0,   134,     0,
     135,   271,   272,     0,     0,   321,     0,   120,     0,   121,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   120,     0,   121,   471,   122,     0,
     393,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   123,     0,   124,   120,   125,
     121,   126,   122,   127,     0,   128,   129,     0,   130,   131,
     132,   133,   123,   134,   124,   135,   125,   492,   126,     0,
     127,     0,   128,   129,     0,   130,   131,   132,   133,     0,
     134,     0,   135,     0,     0,   120,   123,   121,   124,   122,
     125,   505,   126,     0,   127,     0,   128,   129,     0,   130,
     131,   132,   133,     0,   134,     0,   135,     0,   521,   120,
       0,   121,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,     0,   124,   120,   125,   121,   126,
     122,   127,     0,   128,   129,   395,   130,   131,   132,   133,
       0,   134,     0,   135,     0,     0,     0,   123,     0,   124,
     120,   125,   121,   126,   122,   127,     0,   128,   129,     0,
     130,   131,   132,   133,   123,   134,   124,   135,   125,   120,
     126,   121,   127,   122,   128,   129,   489,   130,   131,   132,
     133,     0,   134,     0,   135,   299,   300,     0,   123,     0,
     124,   120,   125,   121,   126,   122,   127,   506,   128,   129,
       0,   130,   131,   132,   133,     0,   134,   123,   135,   124,
       0,   125,   120,   126,   121,   127,   122,   128,   129,   520,
     130,   131,   132,   133,     0,   134,     0,   135,     0,   123,
       0,   124,     0,   125,   120,   126,   121,   127,   122,   128,
     129,   278,   130,   131,   132,   133,     0,   134,     0,   135,
     123,     0,   124,   120,   125,   121,   126,   122,   127,     0,
     128,   129,     0,   130,   131,   132,   133,     0,   134,     0,
     135,     0,   123,     0,   124,     0,   125,     0,   126,     0,
     127,     0,   128,   129,   433,   130,   131,   132,   133,     0,
     134,   123,   135,   124,     0,   125,   120,   126,   121,   127,
     122,   128,   129,   458,   130,   131,   132,   133,     0,   134,
       0,   135,     0,     0,     0,   120,     0,   121,     0,   122,
       0,     0,     0,     0,     0,   511,     0,     0,     0,     0,
       0,     0,     0,     0,   123,     0,   124,   120,   125,   121,
     126,   122,   127,     0,   128,   129,     0,   130,   131,   132,
     133,   459,   134,   123,   135,   124,     0,   125,   120,   126,
     121,   127,   122,   128,   129,     0,   130,   131,   132,   133,
       0,   134,     0,   135,   283,   123,   284,   124,     0,   125,
     120,   126,   121,   127,   122,   128,   129,     0,   130,   131,
     132,   133,   280,   134,   281,   135,   123,     0,   124,     0,
     125,   120,   126,   121,   127,   122,   128,   129,     0,   130,
     131,   132,   133,     0,   134,     0,   135,     0,   123,   460,
     124,     0,   125,   120,   126,   121,   127,   122,   128,   129,
       0,   130,   131,   132,   133,     0,   134,     0,   135,   123,
       0,   124,     0,   125,     0,   126,     0,   127,     0,   128,
     129,     0,   130,   131,   132,   133,     0,   134,     0,   135,
       0,   123,     0,   124,     0,   125,     0,   126,     0,   127,
       0,   128,   129,     0,   130,   131,   132,   133,     0,   134,
     286,   135,   287,   120,     0,   121,     0,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   461,
     120,     0,   121,     0,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,     0,   124,     0,   125,     0,   126,     0,   127,
       0,   128,   129,     0,   130,   131,   132,   133,   123,   134,
     124,   135,   125,     0,   126,     0,   127,     0,   128,   129,
       0,   130,   131,   132,   133,   120,   134,   121,   135,   122,
       0,     0,     0,     0,     0,     0,     0,     0,   296,   297,
       0,     0,   120,     0,   121,     0,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   302,   303,   123,     0,   124,     0,   125,     0,   126,
       0,   127,     0,   128,   129,     0,   130,   131,   132,   133,
     123,   134,   124,   135,   125,   120,   126,   121,   127,   122,
     128,   129,     0,   130,   131,   132,   133,     0,   134,     0,
     135,     0,     0,     0,     0,     0,     0,   305,   120,   306,
     121,     0,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,     0,   124,     0,   125,     0,   126,
       0,   127,     0,   128,   129,     0,   130,   131,   132,   133,
     312,   134,   313,   135,     0,     0,   123,     0,   124,     0,
     125,   120,   126,   121,   127,   122,   128,   129,   289,   130,
     131,   132,   133,     0,   134,     0,   135,     0,   120,     0,
     121,     0,   122,     0,     0,   291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
       0,   124,     0,   125,   120,   126,   121,   127,   122,   128,
     129,   292,   130,   131,   132,   133,   123,   134,   124,   135,
     125,   120,   126,   121,   127,   122,   128,   129,   293,   130,
     131,   132,   133,     0,   134,     0,   135,     0,     0,     0,
       0,     0,   123,     0,   124,     0,   125,   120,   126,   121,
     127,   122,   128,   129,   294,   130,   131,   132,   133,   123,
     134,   124,   135,   125,   120,   126,   121,   127,   122,   128,
     129,   295,   130,   131,   132,   133,     0,   134,     0,   135,
       0,     0,     0,     0,     0,   123,     0,   124,   120,   125,
     121,   126,   122,   127,     0,   128,   129,     0,   130,   131,
     132,   133,   123,   134,   124,   135,   125,     0,   126,     0,
     127,     0,   128,   129,   308,   130,   131,   132,   133,   120,
     134,   121,   135,   122,     0,     0,   123,     0,   124,     0,
     125,     0,   126,     0,   127,     0,   128,   129,     0,   130,
     131,   132,   133,   120,   134,   121,   135,   122,   309,     0,
       0,     0,     0,     0,     0,     0,     0,   123,     0,   124,
       0,   125,     0,   126,     0,   127,     0,   128,   129,     0,
     130,   131,   132,   133,   311,   134,   120,   135,   121,     0,
     122,   123,     0,   124,     0,   125,     0,   126,     0,   127,
       0,   128,   129,     0,   130,   131,   132,   133,   120,   134,
     121,   135,   122,     0,     0,   462,     0,     0,     0,     0,
       0,     0,     0,   315,   123,     0,   124,   120,   125,   121,
     126,   122,   127,     0,   128,   129,     0,   130,   131,   132,
     133,   463,   134,     0,   135,     0,   123,     0,   124,     0,
     125,   120,   126,   121,   127,   122,   128,   129,     0,   130,
     131,   132,   133,     0,   134,   123,   135,   124,   464,   125,
     120,   126,   121,   127,   122,   128,   129,     0,   130,   131,
     132,   133,     0,   134,     0,   135,     0,     0,     0,   123,
     465,   124,     0,   125,     0,   126,     0,   127,     0,   128,
     129,     0,   130,   131,   132,   133,     0,   134,   123,   135,
     124,   120,   125,   121,   126,   122,   127,     0,   128,   129,
       0,   130,   131,   132,   133,     0,   134,     0,   135,     0,
       0,     0,   120,     0,   121,   466,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
       0,   124,     0,   125,     0,   126,     0,   127,     0,   128,
     129,   467,   130,   131,   132,   133,     0,   134,     0,   135,
     123,   120,   124,   121,   125,   122,   126,     0,   127,     0,
     128,   129,     0,   130,   131,   132,   133,     0,   134,     0,
     135,     0,     0,   120,     0,   121,     0,   122,     0,     0,
       0,     0,     0,     0,     0,   468,     0,     0,     0,   123,
       0,   124,     0,   125,     0,   126,     0,   127,     0,   128,
     129,     0,   130,   131,   132,   133,     0,   134,     0,   135,
     469,   123,     0,   124,     0,   125,     0,   126,     0,   127,
       0,   128,   129,     0,   130,   131,   132,   133,     0,   134,
       0,   135
};

static const yytype_int16 yycheck[] =
{
      12,    14,    16,    16,     0,    16,    18,   116,    16,    21,
      31,    23,    44,    25,    16,    27,   107,    29,    30,    31,
      32,    33,    34,    16,    36,    16,    38,    16,    40,    16,
      42,    43,    16,    45,    46,    16,    48,    16,    16,    16,
      16,    16,    16,    16,   120,    16,    58,    16,    60,    16,
      62,    16,    64,    16,    66,    16,    68,    16,    70,    16,
      72,    16,    74,    16,    76,    16,    78,    16,    80,    16,
      16,    16,    16,    16,    16,    16,    16,    16,   123,   111,
      80,    16,    91,    16,   112,    16,    16,    16,    16,   111,
       4,     5,   111,     7,   111,     9,   158,    11,   113,   114,
     115,   116,   111,     3,     4,   112,   113,   114,   115,   116,
     157,   112,   113,   114,   115,   116,   115,   116,    80,    31,
     112,   113,   114,   115,   116,    23,    24,    25,   111,    27,
      28,   111,    30,    21,    22,   147,   136,   149,    42,   151,
     112,   153,    44,   111,   159,   157,   157,   147,   160,   149,
     157,   151,   159,   153,    80,   157,   157,   111,   159,   111,
     159,   111,    82,   111,   157,    84,   157,   159,   157,    86,
     157,   107,   108,   157,   136,    88,   157,   111,   157,   157,
     157,   157,   157,   157,   157,   147,   157,   149,   157,   151,
     157,   153,   157,   111,   157,    91,   157,    91,   157,    96,
     157,    96,   157,   112,   157,    98,   157,   123,   157,   101,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   233,
     233,   120,   157,   235,   157,   238,   157,   157,   157,   157,
      24,    25,    26,    27,    28,   112,    30,    24,    25,   111,
      27,    28,   111,    30,   111,   111,    44,    91,   159,   358,
     359,   360,   361,   362,    24,    25,    91,    27,    28,    98,
      30,   273,   275,   277,   277,    24,    25,   279,    27,    28,
     282,    30,    -1,   285,    -1,    -1,   288,    -1,   290,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   298,    -1,    -1,   301,
      -1,    -1,   304,    -1,    -1,   307,    -1,    -1,   310,    -1,
     409,    -1,   314,    -1,   316,    -1,    -1,    -1,    -1,   223,
     322,   225,   324,   227,   326,   229,   328,    -1,   330,    -1,
     332,    -1,   334,    -1,   336,    -1,   338,    -1,   340,    -1,
     342,   343,   246,   345,   443,   347,    -1,   349,    -1,   351,
      -1,    -1,    -1,   343,   356,   345,    -1,   347,    -1,   349,
      -1,   265,    -1,   267,    -1,   269,   368,    -1,    -1,    41,
      -1,    43,    -1,    45,    -1,    -1,    -1,    -1,   368,    -1,
      -1,    -1,    -1,    -1,   386,    -1,   388,    -1,   390,    -1,
      -1,   343,   394,   345,   396,   347,   386,   349,   388,    41,
     390,    43,    -1,    45,    -1,    -1,    -1,    79,    -1,    81,
      -1,    83,    -1,    85,    -1,    87,   368,    89,    90,    -1,
      92,    93,    94,    95,    -1,    97,    -1,    99,   432,   432,
      -1,    -1,   434,   436,   386,    -1,   388,    79,   390,    81,
      -1,    83,    -1,    85,    -1,    87,    -1,    89,    90,    -1,
      92,    93,    94,    95,    -1,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   483,    -1,   485,   156,   487,    -1,    -1,   490,    -1,
      -1,   493,    -1,   483,    -1,   485,    -1,   487,    -1,    -1,
      -1,    -1,    -1,    -1,   494,    -1,   496,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,
      -1,   425,    -1,   427,    -1,   429,    -1,    -1,    -1,    -1,
       6,   483,     8,   485,    10,   487,    -1,    13,   442,    15,
     444,    17,   494,    19,   496,    -1,    22,    -1,    24,    -1,
      26,    -1,    28,    -1,    -1,    -1,    41,    -1,    43,    35,
      45,    37,    -1,    39,    -1,    41,    -1,    -1,    44,    -1,
      -1,    47,    -1,    49,    -1,    -1,    -1,    -1,    41,    55,
      43,    57,    45,    59,    -1,    61,    -1,    63,    -1,    65,
      -1,    67,    -1,    69,    79,    71,    81,    73,    83,    75,
      85,    77,    87,    79,    89,    90,    -1,    92,    93,    94,
      95,    -1,    97,    -1,    99,    -1,    79,    -1,    81,    -1,
      83,    -1,    85,    -1,    87,    -1,    89,    90,    -1,    92,
      93,    94,    95,    41,    97,    43,    99,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,    -1,    -1,    -1,   135,
      -1,    41,    -1,    43,    -1,    45,    -1,    -1,   153,    -1,
      -1,    79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,
      -1,    89,    90,    -1,    92,    93,    94,    95,    -1,    97,
     153,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    87,    -1,    89,
      90,    -1,    92,    93,    94,    95,    -1,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,   224,    -1,
     226,    -1,   228,     6,     7,    -1,     9,    10,   234,    12,
     236,    14,    15,   239,    -1,    18,    -1,    20,    21,    22,
     150,    24,    25,    -1,    27,    28,    -1,    30,    -1,    32,
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
     143,    -1,   145,   146,    -1,   148,   149,    -1,   151,   152,
      -1,   154,   155,     6,     7,    -1,     9,    10,    -1,    12,
      -1,    14,    15,    17,    -1,    18,    -1,    20,    21,    22,
      -1,    24,    25,    -1,    27,    28,    -1,    30,    -1,    32,
      33,    -1,    35,    36,    -1,    38,    39,    41,    -1,    43,
      -1,    45,    -1,    46,    47,    -1,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    -1,    59,    60,    -1,    62,
      63,    64,    -1,    66,    -1,    68,    69,    -1,    71,    -1,
      73,    74,    -1,    76,    77,    79,    -1,    81,    -1,    83,
      -1,    85,    -1,    87,    -1,    89,    90,    -1,    92,    93,
      94,    95,    -1,    97,    -1,    99,    -1,   100,    -1,   102,
     103,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,    -1,   121,   122,
      -1,   124,   125,    -1,   127,   128,    -1,   130,   131,    -1,
     133,   134,    -1,   136,   137,    -1,   139,   140,    -1,   142,
     143,    -1,   145,   146,    -1,   148,   149,    -1,   151,   152,
      -1,   154,   155,     6,     7,    -1,     9,    10,    -1,    12,
      -1,    14,    15,    17,    -1,    18,    -1,    20,    21,    22,
      -1,    24,    25,    -1,    27,    28,    -1,    30,    -1,    32,
      33,    -1,    35,    36,    -1,    38,    39,    41,    -1,    43,
      -1,    45,    -1,    46,    47,    -1,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    -1,    59,    60,    -1,    62,
      63,    64,    -1,    66,    -1,    68,    69,    -1,    71,    -1,
      73,    74,    -1,    76,    77,    79,    -1,    81,    -1,    83,
      -1,    85,    -1,    87,    -1,    89,    90,    -1,    92,    93,
      94,    95,    -1,    97,    -1,    99,    -1,   100,    -1,   102,
      -1,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,    -1,   121,   122,
      -1,   124,   125,    -1,   127,   128,    -1,   130,   131,    -1,
     133,   134,    -1,   136,   137,    -1,   139,   140,    -1,   142,
     143,    -1,   145,   146,    -1,   148,   149,    -1,   151,   152,
      -1,   154,   155,     6,     7,    -1,     9,    10,    -1,    12,
      -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,    22,
      -1,    24,    25,    -1,    27,    28,    -1,    30,    -1,    32,
      33,    -1,    35,    36,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    -1,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    -1,    59,    60,    -1,    62,
      63,    64,    -1,    66,    -1,    68,    69,    -1,    71,    -1,
      73,    74,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,
      -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,    -1,   121,   122,
      -1,   124,   125,    -1,   127,   128,    -1,   130,   131,    -1,
     133,   134,    -1,   136,   137,    -1,   139,   140,    -1,   142,
     143,    -1,   145,   146,    -1,   148,   149,    -1,   151,   152,
      -1,   154,   155,     6,     7,    -1,     9,    10,    -1,    12,
      -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,    22,
      -1,    24,    25,    -1,    27,    28,    -1,    30,    -1,    32,
      33,    -1,    35,    36,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    -1,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    -1,    59,    60,    -1,    62,
      63,    64,    -1,    66,    -1,    68,    69,    -1,    71,    -1,
      73,    74,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,
      -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,    -1,   121,   122,
      -1,   124,   125,    -1,   127,   128,    -1,   130,   131,    -1,
     133,   134,    -1,   136,   137,    -1,   139,   140,    -1,   142,
     143,    -1,   145,   146,    -1,   148,   149,    -1,   151,   152,
      -1,   154,   155,    41,    -1,    43,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    41,    81,    43,    83,    45,    85,    -1,    87,
      -1,    89,    90,    -1,    92,    93,    94,    95,    79,    97,
      81,    99,    83,    -1,    85,    -1,    87,    -1,    89,    90,
      -1,    92,    93,    94,    95,    -1,    97,    -1,    99,    41,
      79,    43,    81,    45,    83,    -1,    85,    -1,    87,    -1,
      89,    90,    -1,    92,    93,    94,    95,    -1,    97,    -1,
      99,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,   147,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,
      -1,    83,    -1,    85,    -1,    87,   147,    89,    90,    -1,
      92,    93,    94,    95,    -1,    97,    -1,    99,    -1,    41,
      79,    43,    81,    45,    83,   144,    85,    -1,    87,    -1,
      89,    90,    -1,    92,    93,    94,    95,    -1,    97,    -1,
      99,    41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,
      -1,    83,   144,    85,    -1,    87,    -1,    89,    90,    -1,
      92,    93,    94,    95,    41,    97,    43,    99,    45,    79,
      -1,    81,   141,    83,    -1,    85,    -1,    87,    -1,    89,
      90,    -1,    92,    93,    94,    95,    -1,    97,    -1,    99,
      -1,    41,    -1,    43,     5,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    81,    -1,    83,    -1,    85,   141,
      87,    -1,    89,    90,    -1,    92,    93,    94,    95,    -1,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   138,    79,
      41,    81,    43,    83,    45,    85,    -1,    87,    -1,    89,
      90,    -1,    92,    93,    94,    95,    -1,    97,    -1,    99,
      -1,    41,    -1,    43,     5,    45,    -1,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      81,    -1,    83,    41,    85,    43,    87,    45,    89,    90,
      -1,    92,    93,    94,    95,   135,    97,    -1,    99,    79,
      41,    81,    43,    83,    45,    85,    -1,    87,    -1,    89,
      90,    -1,    92,    93,    94,    95,    -1,    97,    -1,    99,
      -1,    79,    -1,    81,     8,    83,    -1,    85,    -1,    87,
      -1,    89,    90,    -1,    92,    93,    94,    95,    79,    97,
      81,    99,    83,    -1,    85,    -1,    87,    -1,    89,    90,
      -1,    92,    93,    94,    95,   135,    97,    41,    99,    43,
      -1,    45,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   132,    -1,    41,    -1,    43,    -1,
      45,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    41,    83,
      43,    85,    45,    87,    -1,    89,    90,    -1,    92,    93,
      94,    95,    -1,    97,    79,    99,    81,    41,    83,    43,
      85,    45,    87,    -1,    89,    90,    -1,    92,    93,    94,
      95,    -1,    97,    -1,    99,    -1,    79,    -1,    81,     8,
      83,    41,    85,    43,    87,    45,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    79,    99,    81,    -1,    83,
      -1,    85,    -1,    87,    -1,    89,    90,   132,    92,    93,
      94,    95,    41,    97,    43,    99,    45,    11,    -1,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    87,    -1,    89,
      90,    -1,    92,    93,    94,    95,    -1,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    43,
      79,    45,    81,    -1,    83,    -1,    85,    -1,    87,    -1,
      89,    90,    -1,    92,    93,    94,    95,    -1,    97,   129,
      99,    41,    11,    43,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    -1,    83,
      -1,    85,    -1,    87,    -1,    89,    90,    -1,    92,    93,
      94,    95,    41,    97,    43,    99,    45,    11,    -1,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    87,    -1,    89,
      90,    -1,    92,    93,    94,    95,    -1,    97,    -1,    99,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    41,    -1,    43,
      79,    45,    81,    -1,    83,    -1,    85,    -1,    87,    -1,
      89,    90,    13,    92,    93,    94,    95,    -1,    97,   129,
      99,    41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    79,    -1,    81,    -1,    83,
      41,    85,    43,    87,    45,    89,    90,    -1,    92,    93,
      94,    95,    -1,    97,    -1,    99,    -1,    -1,    -1,    79,
      -1,    81,    41,    83,    43,    85,    45,    87,    -1,    89,
      90,    13,    92,    93,    94,    95,    -1,    97,    79,    99,
      81,    -1,    83,    -1,    85,    -1,    87,    -1,    89,    90,
      -1,    92,    93,    94,    95,    13,    97,    -1,    99,    41,
      79,    43,    81,    45,    83,    -1,    85,    -1,    87,    -1,
      89,    90,    -1,    92,    93,    94,    95,    -1,    97,    -1,
      99,    -1,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,
      41,    83,    43,    85,    45,    87,    -1,    89,    90,    -1,
      92,    93,    94,    95,    -1,    97,    -1,    99,    -1,    -1,
      -1,    79,    41,    81,    43,    83,    45,    85,    -1,    87,
      -1,    89,    90,    -1,    92,    93,    94,    95,    79,    97,
      81,    99,    83,    -1,    85,    -1,    87,    -1,    89,    90,
      -1,    92,    93,    94,    95,    -1,    97,    -1,    99,    -1,
      79,    -1,    81,    -1,    83,    19,    85,    -1,    87,    -1,
      89,    90,    -1,    92,    93,    94,    95,    -1,    97,    -1,
      99,    18,    19,    -1,    -1,   126,    -1,    41,    -1,    43,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    43,   126,    45,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    41,    83,
      43,    85,    45,    87,    -1,    89,    90,    -1,    92,    93,
      94,    95,    79,    97,    81,    99,    83,    23,    85,    -1,
      87,    -1,    89,    90,    -1,    92,    93,    94,    95,    -1,
      97,    -1,    99,    -1,    -1,    41,    79,    43,    81,    45,
      83,    23,    85,    -1,    87,    -1,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    -1,    99,    -1,    23,    41,
      -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    81,    41,    83,    43,    85,
      45,    87,    -1,    89,    90,    26,    92,    93,    94,    95,
      -1,    97,    -1,    99,    -1,    -1,    -1,    79,    -1,    81,
      41,    83,    43,    85,    45,    87,    -1,    89,    90,    -1,
      92,    93,    94,    95,    79,    97,    81,    99,    83,    41,
      85,    43,    87,    45,    89,    90,    26,    92,    93,    94,
      95,    -1,    97,    -1,    99,    57,    58,    -1,    79,    -1,
      81,    41,    83,    43,    85,    45,    87,    26,    89,    90,
      -1,    92,    93,    94,    95,    -1,    97,    79,    99,    81,
      -1,    83,    41,    85,    43,    87,    45,    89,    90,    26,
      92,    93,    94,    95,    -1,    97,    -1,    99,    -1,    79,
      -1,    81,    -1,    83,    41,    85,    43,    87,    45,    89,
      90,    29,    92,    93,    94,    95,    -1,    97,    -1,    99,
      79,    -1,    81,    41,    83,    43,    85,    45,    87,    -1,
      89,    90,    -1,    92,    93,    94,    95,    -1,    97,    -1,
      99,    -1,    79,    -1,    81,    -1,    83,    -1,    85,    -1,
      87,    -1,    89,    90,    29,    92,    93,    94,    95,    -1,
      97,    79,    99,    81,    -1,    83,    41,    85,    43,    87,
      45,    89,    90,    29,    92,    93,    94,    95,    -1,    97,
      -1,    99,    -1,    -1,    -1,    41,    -1,    43,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    81,    41,    83,    43,
      85,    45,    87,    -1,    89,    90,    -1,    92,    93,    94,
      95,    34,    97,    79,    99,    81,    -1,    83,    41,    85,
      43,    87,    45,    89,    90,    -1,    92,    93,    94,    95,
      -1,    97,    -1,    99,    35,    79,    37,    81,    -1,    83,
      41,    85,    43,    87,    45,    89,    90,    -1,    92,    93,
      94,    95,    32,    97,    34,    99,    79,    -1,    81,    -1,
      83,    41,    85,    43,    87,    45,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    -1,    99,    -1,    79,    37,
      81,    -1,    83,    41,    85,    43,    87,    45,    89,    90,
      -1,    92,    93,    94,    95,    -1,    97,    -1,    99,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    87,    -1,    89,
      90,    -1,    92,    93,    94,    95,    -1,    97,    -1,    99,
      -1,    79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,
      -1,    89,    90,    -1,    92,    93,    94,    95,    -1,    97,
      38,    99,    40,    41,    -1,    43,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,
      -1,    89,    90,    -1,    92,    93,    94,    95,    79,    97,
      81,    99,    83,    -1,    85,    -1,    87,    -1,    89,    90,
      -1,    92,    93,    94,    95,    41,    97,    43,    99,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      -1,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    79,    -1,    81,    -1,    83,    -1,    85,
      -1,    87,    -1,    89,    90,    -1,    92,    93,    94,    95,
      79,    97,    81,    99,    83,    41,    85,    43,    87,    45,
      89,    90,    -1,    92,    93,    94,    95,    -1,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    63,    41,    65,
      43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    81,    -1,    83,    -1,    85,
      -1,    87,    -1,    89,    90,    -1,    92,    93,    94,    95,
      73,    97,    75,    99,    -1,    -1,    79,    -1,    81,    -1,
      83,    41,    85,    43,    87,    45,    89,    90,    48,    92,
      93,    94,    95,    -1,    97,    -1,    99,    -1,    41,    -1,
      43,    -1,    45,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    81,    -1,    83,    41,    85,    43,    87,    45,    89,
      90,    48,    92,    93,    94,    95,    79,    97,    81,    99,
      83,    41,    85,    43,    87,    45,    89,    90,    48,    92,
      93,    94,    95,    -1,    97,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    81,    -1,    83,    41,    85,    43,
      87,    45,    89,    90,    48,    92,    93,    94,    95,    79,
      97,    81,    99,    83,    41,    85,    43,    87,    45,    89,
      90,    48,    92,    93,    94,    95,    -1,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    41,    83,
      43,    85,    45,    87,    -1,    89,    90,    -1,    92,    93,
      94,    95,    79,    97,    81,    99,    83,    -1,    85,    -1,
      87,    -1,    89,    90,    67,    92,    93,    94,    95,    41,
      97,    43,    99,    45,    -1,    -1,    79,    -1,    81,    -1,
      83,    -1,    85,    -1,    87,    -1,    89,    90,    -1,    92,
      93,    94,    95,    41,    97,    43,    99,    45,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,
      -1,    83,    -1,    85,    -1,    87,    -1,    89,    90,    -1,
      92,    93,    94,    95,    72,    97,    41,    99,    43,    -1,
      45,    79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,
      -1,    89,    90,    -1,    92,    93,    94,    95,    41,    97,
      43,    99,    45,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    -1,    81,    41,    83,    43,
      85,    45,    87,    -1,    89,    90,    -1,    92,    93,    94,
      95,    55,    97,    -1,    99,    -1,    79,    -1,    81,    -1,
      83,    41,    85,    43,    87,    45,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    79,    99,    81,    58,    83,
      41,    85,    43,    87,    45,    89,    90,    -1,    92,    93,
      94,    95,    -1,    97,    -1,    99,    -1,    -1,    -1,    79,
      61,    81,    -1,    83,    -1,    85,    -1,    87,    -1,    89,
      90,    -1,    92,    93,    94,    95,    -1,    97,    79,    99,
      81,    41,    83,    43,    85,    45,    87,    -1,    89,    90,
      -1,    92,    93,    94,    95,    -1,    97,    -1,    99,    -1,
      -1,    -1,    41,    -1,    43,    65,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    87,    -1,    89,
      90,    70,    92,    93,    94,    95,    -1,    97,    -1,    99,
      79,    41,    81,    43,    83,    45,    85,    -1,    87,    -1,
      89,    90,    -1,    92,    93,    94,    95,    -1,    97,    -1,
      99,    -1,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    87,    -1,    89,
      90,    -1,    92,    93,    94,    95,    -1,    97,    -1,    99,
      78,    79,    -1,    81,    -1,    83,    -1,    85,    -1,    87,
      -1,    89,    90,    -1,    92,    93,    94,    95,    -1,    97,
      -1,    99
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,   161,   196,     6,     7,     9,    10,    12,
      14,    15,    18,    20,    21,    22,    24,    25,    27,    28,
      30,    32,    33,    35,    36,    38,    39,    46,    47,    49,
      50,    51,    52,    53,    54,    56,    57,    59,    60,    62,
      63,    64,    66,    68,    69,    71,    73,    74,    76,    77,
     100,   102,   104,   106,   118,   119,   121,   122,   124,   125,
     127,   128,   130,   131,   133,   134,   136,   137,   139,   140,
     142,   143,   145,   146,   148,   149,   151,   152,   154,   155,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   208,   211,   214,    16,   207,     0,
      41,    43,    45,    79,    81,    83,    85,    87,    89,    90,
      92,    93,    94,    95,    97,    99,   162,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   162,   207,   162,
     207,   162,   207,   162,   196,   207,    23,   180,   207,    26,
     179,   180,   207,   196,   207,    31,   196,   207,   196,   207,
     196,   207,   196,   207,   196,   196,   196,   196,   196,   196,
     207,   196,   207,   196,   207,   196,   207,   196,   196,   207,
     196,   196,   207,   196,   207,   107,   209,   120,   207,   123,
     207,   196,   207,   196,   207,   196,   207,   196,   207,   196,
     207,   196,   207,   196,   207,   196,   207,   196,   207,   196,
     207,   196,   207,     6,     7,     9,    10,    12,    14,    15,
     163,   196,   208,    24,    25,    27,    28,    30,    21,    22,
     107,   108,   210,   210,   112,    16,   157,   111,    44,   111,
     207,   111,   111,   111,   111,   111,   111,   111,   207,   207,
     111,   111,   111,   207,   196,   157,   196,   157,   196,   157,
     196,    18,    19,   157,   196,   157,   196,   157,    29,   157,
      32,    34,   157,    35,    37,   157,    38,    40,   157,    48,
     157,    48,    48,    48,    48,    48,    54,    55,   157,    57,
      58,   157,    60,    61,   157,    63,    65,   157,    67,    70,
     157,    72,    73,    75,   157,    78,   157,   158,   157,   157,
     157,   126,   157,   129,   157,   132,   157,   135,   157,   138,
     157,   141,   157,   144,   157,   147,   157,   150,   157,   153,
     157,   156,   157,   162,   207,   162,   207,   162,   207,   162,
       5,   179,   207,   196,   207,    31,   180,   207,   112,   113,
     114,   115,   116,   157,   159,   157,   111,   112,   162,    42,
      44,   157,    80,    82,    84,    86,    88,    91,    91,   157,
     157,    96,    96,    98,   157,     8,   162,    11,   162,    13,
     162,    17,   196,    23,   180,    26,   179,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   112,
     101,   120,   123,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   157,   196,   157,   196,   157,
     196,   196,   157,    29,   157,   196,   157,   210,   210,   210,
     210,   210,   212,   112,   216,   111,   196,   111,   111,    91,
     111,   111,   196,   196,   196,    19,   196,   196,    29,    34,
      37,    40,    48,    55,    58,    61,    65,    70,    75,    78,
     210,   126,   129,   132,   135,   138,   141,   144,   147,   150,
     153,   156,     8,   162,    11,   162,    13,   162,    17,    26,
     179,   196,    23,   180,   162,   210,   162,     5,    44,    91,
      91,    98,     8,    11,    13,    23,    26,   196,   196,   196,
     196,    29,   196,   103,   213,   105,   215,     8,    11,    13,
      26,    23
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
    {token_store(PUSH | WIDGET_TABLE);}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 389 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_COMBO);
	}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 392 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_COMBO, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 398 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_GVIM);}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 402 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_PIXMAP);}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 403 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_PIXMAP, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 416 "gtkdialog_parser.y"
    {
		yyerror("The menubar widget requires at least one menu widget.");
	}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 419 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUBAR);
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 422 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUBAR);
		token_store(SUM);
	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 426 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUBAR, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 429 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUBAR, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);
	}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 442 "gtkdialog_parser.y"
    {
		yyerror("The menu widget requires at least one menuitem widget.");
	}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 445 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENU);
	}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 448 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENU);
		token_store(SUM);
	}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 452 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENU, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 455 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENU, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);
	}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 462 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM);
	}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 465 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM);
		token_store(SUM);
	}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 469 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 472 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(3) - (6)].nvval));
		token_store(SUM);
	}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 479 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEMSEPARATOR);
	}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 482 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEMSEPARATOR);
		token_store(SUM);
	}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 489 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSEPARATOR);
	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 492 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 498 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSEPARATOR);
	}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 501 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 507 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXTEXT);
	}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 510 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXTEXT, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 516 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXENTRY);
	}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 519 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 525 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSCALE);
	}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 528 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSCALE, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 534 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSCALE);
	}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 537 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSCALE, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 543 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_SPINBUTTON);
	}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 546 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_SPINBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 552 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TIMER);
	}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 555 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TIMER, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 561 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TOGGLEBUTTON);
	}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 564 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TOGGLEBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 570 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_STATUSBAR);
	}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 573 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_STATUSBAR, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 579 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COLORBUTTON);
	}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 582 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COLORBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 588 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_FONTBUTTON);
	}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 591 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_FONTBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 597 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TERMINAL);
	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 600 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TERMINAL, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 620 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_LABEL, (yyvsp[(2) - (3)].cval));     }
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 625 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_VARIABLE, (yyvsp[(2) - (3)].cval)); }
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 630 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_SENSITIVE, (yyvsp[(2) - (3)].cval));  }
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 635 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_DEFAULT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 640 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_WIDTH, (yyvsp[(2) - (3)].cval));    }
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 645 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_HEIGHT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 650 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_SHELL,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 653 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 656 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 659 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 662 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, "", (yyvsp[(2) - (4)].nvval)); 
	}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 668 "gtkdialog_parser.y"
    {
	         fprintf( stderr, "<output>: Not implemented.\n" ); 
	}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 671 "gtkdialog_parser.y"
    {
         	token_store_with_argument(SET|ATTR_OUTPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 677 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET|ATTR_ACTION, (yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 680 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET | ATTR_ACTION, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 687 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET | ATTR_ITEM, (yyvsp[(2) - (3)].cval));
	}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 690 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_ITEM, "");
    	}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 693 "gtkdialog_parser.y"
    {
		      token_store_with_argument_attr(SET | ATTR_ITEM, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
                    }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 699 "gtkdialog_parser.y"
    {
       		(yyval.nvval) = new_tag_attributeset((yyvsp[(1) - (3)].cval), (yyvsp[(3) - (3)].cval)); 
	}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 702 "gtkdialog_parser.y"
    { 
       		(yyval.nvval) = add_tag_attribute((yyvsp[(1) - (4)].nvval), (yyvsp[(2) - (4)].cval), (yyvsp[(4) - (4)].cval)); 
	}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 709 "gtkdialog_parser.y"
    { 
		token_store(SHOW);     
	}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 712 "gtkdialog_parser.y"
    {
  		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
	}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 715 "gtkdialog_parser.y"
    {
		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
		instruction_set_jump((yyvsp[(6) - (6)].ival) + 1, (yyvsp[(1) - (6)].ival));
	}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 722 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMASSG | VARIABLE_NAME, (yyvsp[(1) - (4)].cval)); 
	}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 728 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | VARIABLE_NAME, (yyvsp[(1) - (1)].cval)); 
	}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 731 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | CONST_NUMBER, (yyvsp[(1) - (1)].cval)); 
  	}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 734 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_ADD);
	}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 737 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_SUBST);
	}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 740 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_MULT);
	}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 743 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_DIV);
	}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 746 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_EQ);
	}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 749 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_NE);
	}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 759 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 766 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 770 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 774 "gtkdialog_parser.y"
    {
		token_store(GOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 781 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
    }
    break;



/* Line 1455 of yacc.c  */
#line 4001 "gtkdialog_parser.c"
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
#line 787 "gtkdialog_parser.y"


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


