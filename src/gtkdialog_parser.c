
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
     ETERMINAL = 407,
     EVENTBOX = 408,
     PART_EVENTBOX = 409,
     EEVENTBOX = 410
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
#define EVENTBOX 408
#define PART_EVENTBOX 409
#define EEVENTBOX 410




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
#line 515 "gtkdialog_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 527 "gtkdialog_parser.c"

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
#define YYFINAL  122
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3669

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  164
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  191
/* YYNRULES -- Number of states.  */
#define YYNSTATES  548

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   410

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   163,     2,     2,     2,     2,     2,     2,
       2,     2,   116,   115,     2,   114,     2,   117,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   162,     2,
       2,   113,   161,     2,     2,     2,     2,     2,     2,     2,
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
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    11,    18,    20,    23,    25,    28,
      33,    39,    46,    54,    59,    65,    72,    80,    85,    91,
      98,   106,   111,   117,   124,   132,   137,   143,   145,   147,
     149,   151,   153,   155,   157,   159,   161,   163,   165,   167,
     169,   171,   173,   175,   177,   179,   181,   183,   185,   187,
     189,   191,   193,   195,   197,   199,   203,   209,   213,   217,
     223,   227,   231,   237,   241,   245,   251,   255,   259,   265,
     269,   273,   279,   283,   287,   291,   295,   299,   303,   309,
     313,   317,   323,   327,   331,   337,   341,   345,   351,   355,
     359,   365,   369,   373,   379,   383,   387,   393,   396,   401,
     407,   414,   422,   424,   426,   428,   431,   436,   442,   449,
     457,   461,   466,   472,   479,   482,   486,   489,   494,   497,
     502,   506,   512,   516,   522,   526,   532,   536,   542,   546,
     552,   556,   562,   566,   572,   576,   582,   586,   592,   596,
     602,   606,   612,   613,   616,   619,   622,   625,   628,   631,
     634,   637,   640,   643,   647,   651,   655,   659,   663,   667,
     671,   677,   681,   687,   692,   696,   700,   704,   710,   714,
     717,   723,   727,   732,   737,   739,   746,   753,   758,   760,
     762,   766,   770,   774,   778,   782,   787,   789,   790,   792,
     794,   796
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     165,     0,    -1,   200,   166,    -1,     3,   166,   200,     5,
      -1,     4,   211,   161,   166,   200,     5,    -1,   167,    -1,
     166,   167,    -1,   212,    -1,   166,   212,    -1,     6,   166,
     200,     8,    -1,   166,     6,   166,   200,     8,    -1,     7,
     211,   161,   166,   200,     8,    -1,   166,     7,   211,   161,
     166,   200,     8,    -1,     9,   166,   200,    11,    -1,   166,
       9,   166,   200,    11,    -1,    10,   211,   161,   166,   200,
      11,    -1,   166,    10,   211,   161,   166,   200,    11,    -1,
     158,   166,   200,   160,    -1,   166,   158,   166,   200,   160,
      -1,   159,   211,   161,   166,   200,   160,    -1,   166,   159,
     211,   161,   166,   200,   160,    -1,    12,   166,   200,    13,
      -1,   166,    12,   166,   200,    13,    -1,    14,   211,   161,
     166,   200,    13,    -1,   166,    14,   211,   161,   166,   200,
      13,    -1,    15,   166,   200,    17,    -1,   166,    15,   166,
     200,    17,    -1,   172,    -1,   168,    -1,   169,    -1,   170,
      -1,   171,    -1,   173,    -1,   174,    -1,   175,    -1,   176,
      -1,   177,    -1,   178,    -1,   179,    -1,   181,    -1,   180,
      -1,   182,    -1,   187,    -1,   188,    -1,   189,    -1,   190,
      -1,   191,    -1,   192,    -1,   193,    -1,   194,    -1,   195,
      -1,   196,    -1,   197,    -1,   198,    -1,   199,    -1,    18,
     200,    19,    -1,    20,   211,   161,   200,    19,    -1,    18,
     200,    18,    -1,    32,   200,    34,    -1,    33,   211,   161,
     200,    34,    -1,    32,   200,    32,    -1,    35,   200,    37,
      -1,    36,   211,   161,   200,    37,    -1,    35,   200,    35,
      -1,    38,   200,    40,    -1,    39,   211,   161,   200,    40,
      -1,    38,   200,    38,    -1,    74,   200,    76,    -1,    75,
     211,   161,   200,    76,    -1,    74,   200,    74,    -1,    46,
     200,    48,    -1,    47,   211,   161,   200,    48,    -1,    49,
     200,    48,    -1,    50,   200,    48,    -1,    51,   200,    48,
      -1,    53,   200,    48,    -1,    52,   200,    48,    -1,    54,
     200,    55,    -1,    56,   211,   161,   200,    55,    -1,    54,
     200,    54,    -1,    57,   200,    58,    -1,    59,   211,   161,
     200,    58,    -1,    57,   200,    57,    -1,    60,   200,    61,
      -1,    62,   211,   161,   200,    61,    -1,    60,   200,    60,
      -1,    63,   200,    65,    -1,    64,   211,   161,   200,    65,
      -1,    63,   200,    63,    -1,    66,   200,    67,    -1,    68,
     211,   161,   200,    67,    -1,    66,   200,    66,    -1,    69,
     200,    71,    -1,    70,   211,   161,   200,    71,    -1,    72,
     200,    73,    -1,    77,   200,    79,    -1,    78,   211,   161,
     200,    79,    -1,    21,    23,    -1,    21,   184,   200,    23,
      -1,   184,    21,   184,   200,    23,    -1,    22,   211,   161,
     184,   200,    23,    -1,   184,    22,   211,   161,   184,   200,
      23,    -1,   184,    -1,   185,    -1,   186,    -1,    24,    26,
      -1,    24,   183,   200,    26,    -1,   183,    24,   183,   200,
      26,    -1,    25,   211,   161,   183,   200,    26,    -1,   183,
      25,   211,   161,   183,   200,    26,    -1,    27,   200,    29,
      -1,   183,    27,   200,    29,    -1,    28,   211,   161,   200,
      29,    -1,   183,    28,   211,   161,   200,    29,    -1,    30,
      31,    -1,   183,    30,    31,    -1,   119,   121,    -1,   120,
     211,   161,   121,    -1,   122,   124,    -1,   123,   211,   161,
     124,    -1,   125,   200,   127,    -1,   126,   211,   161,   200,
     127,    -1,   128,   200,   130,    -1,   129,   211,   161,   200,
     130,    -1,   131,   200,   133,    -1,   132,   211,   161,   200,
     133,    -1,   134,   200,   136,    -1,   135,   211,   161,   200,
     136,    -1,   137,   200,   139,    -1,   138,   211,   161,   200,
     139,    -1,   140,   200,   142,    -1,   141,   211,   161,   200,
     142,    -1,   143,   200,   145,    -1,   144,   211,   161,   200,
     145,    -1,   146,   200,   148,    -1,   147,   211,   161,   200,
     148,    -1,   149,   200,   151,    -1,   150,   211,   161,   200,
     151,    -1,   152,   200,   154,    -1,   153,   211,   161,   200,
     154,    -1,   155,   200,   157,    -1,   156,   211,   161,   200,
     157,    -1,    -1,   200,   204,    -1,   200,   203,    -1,   200,
     202,    -1,   200,   201,    -1,   200,   205,    -1,   200,   206,
      -1,   200,   207,    -1,   200,   208,    -1,   200,   209,    -1,
     200,   210,    -1,    41,   112,    42,    -1,    84,   112,    85,
      -1,    82,   112,    83,    -1,    80,   112,    81,    -1,    86,
     112,    87,    -1,    88,   112,    89,    -1,    90,   112,    92,
      -1,    93,   211,   161,   112,    92,    -1,    91,   112,    92,
      -1,    94,   211,   161,   112,    92,    -1,    94,   211,   161,
      92,    -1,    95,   112,    97,    -1,    96,   112,    97,    -1,
      98,   112,    99,    -1,   100,   211,   161,   112,    99,    -1,
      43,   112,    44,    -1,    43,    44,    -1,    45,   211,   161,
     112,    44,    -1,    16,   113,   112,    -1,   211,    16,   113,
     112,    -1,   101,   213,   161,   102,    -1,   107,    -1,   215,
     214,   161,   216,   166,   217,    -1,   218,   214,   161,   220,
     166,   219,    -1,   108,   162,   113,   214,    -1,   108,    -1,
     109,    -1,   214,   115,   214,    -1,   214,   114,   214,    -1,
     214,   116,   214,    -1,   214,   117,   214,    -1,   214,   113,
     214,    -1,   214,   163,   113,   214,    -1,   103,    -1,    -1,
     104,    -1,   105,    -1,   106,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   162,   162,   166,   170,   179,   180,   183,   184,   185,
     188,   192,   195,   199,   202,   206,   209,   213,   216,   220,
     223,   227,   230,   234,   237,   241,   245,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   284,   287,   290,   295,   298,
     301,   307,   310,   313,   319,   322,   325,   331,   334,   337,
     341,   342,   345,   346,   347,   348,   349,   353,   356,   360,
     366,   369,   372,   378,   381,   384,   390,   393,   396,   402,
     405,   408,   414,   417,   423,   427,   428,   441,   444,   447,
     451,   454,   461,   462,   463,   467,   470,   473,   477,   480,
     487,   490,   494,   497,   504,   507,   514,   517,   523,   526,
     532,   535,   541,   544,   550,   553,   559,   562,   568,   571,
     577,   580,   586,   589,   595,   598,   604,   607,   613,   616,
     622,   625,   630,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   645,   650,   655,   660,   665,   670,   675,
     678,   681,   684,   687,   693,   696,   702,   705,   712,   715,
     718,   724,   727,   733,   734,   737,   740,   747,   753,   756,
     759,   762,   765,   768,   771,   774,   780,   784,   791,   795,
     799,   806
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
  "EFONTBUTTON", "TERMINAL", "PART_TERMINAL", "ETERMINAL", "EVENTBOX",
  "PART_EVENTBOX", "EEVENTBOX", "'>'", "':'", "'!'", "$accept", "window",
  "wlist", "widget", "entry", "edit", "tree", "chooser", "text", "button",
  "checkbox", "radiobutton", "progressbar", "list", "table", "combo",
  "gvim", "pixmap", "menubar", "menuwlist", "menu", "menuitem",
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
     365,   366,   367,    61,    45,    43,    42,    47,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,    62,    58,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   164,   165,   165,   165,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   168,   168,   168,   169,   169,
     169,   170,   170,   170,   171,   171,   171,   172,   172,   172,
     173,   173,   173,   173,   173,   173,   173,   174,   174,   174,
     175,   175,   175,   176,   176,   176,   177,   177,   177,   178,
     178,   178,   179,   179,   180,   181,   181,   182,   182,   182,
     182,   182,   183,   183,   183,   184,   184,   184,   184,   184,
     185,   185,   185,   185,   186,   186,   187,   187,   188,   188,
     189,   189,   190,   190,   191,   191,   192,   192,   193,   193,
     194,   194,   195,   195,   196,   196,   197,   197,   198,   198,
     199,   199,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   201,   202,   203,   204,   205,   206,   207,
     207,   207,   207,   207,   208,   208,   209,   209,   210,   210,
     210,   211,   211,   212,   212,   212,   212,   213,   214,   214,
     214,   214,   214,   214,   214,   214,   215,   216,   217,   218,
     219,   220
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     6,     1,     2,     1,     2,     4,
       5,     6,     7,     4,     5,     6,     7,     4,     5,     6,
       7,     4,     5,     6,     7,     4,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     5,     3,     3,     5,
       3,     3,     5,     3,     3,     5,     3,     3,     5,     3,
       3,     5,     3,     3,     3,     3,     3,     3,     5,     3,
       3,     5,     3,     3,     5,     3,     3,     5,     3,     3,
       5,     3,     3,     5,     3,     3,     5,     2,     4,     5,
       6,     7,     1,     1,     1,     2,     4,     5,     6,     7,
       3,     4,     5,     6,     2,     3,     2,     4,     2,     4,
       3,     5,     3,     5,     3,     5,     3,     5,     3,     5,
       3,     5,     3,     5,     3,     5,     3,     5,     3,     5,
       3,     5,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       5,     3,     5,     4,     3,     3,     3,     5,     3,     2,
       5,     3,     4,     4,     1,     6,     6,     4,     1,     1,
       3,     3,     3,     3,     3,     4,     1,     0,     1,     1,
       1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     142,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,     0,     0,     0,     0,     0,   142,     0,
       0,   142,     0,   142,     0,   142,     0,   142,     0,   142,
     142,   142,   142,   142,   142,     0,   142,     0,   142,     0,
     142,     0,   142,     0,   142,     0,   142,   142,     0,   142,
       0,     0,   186,   189,   174,     0,     0,     0,     0,   142,
       0,   142,     0,   142,     0,   142,     0,   142,     0,   142,
       0,   142,     0,   142,     0,   142,     0,   142,     0,   142,
       0,     0,     0,   142,     5,    28,    29,    30,    31,    27,
      32,    33,    34,    35,    36,    37,    38,    40,    39,    41,
       0,   102,   103,   104,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,     7,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
     146,   145,   144,   143,   147,   148,   149,   150,   151,   152,
     142,     0,   142,     0,   142,     0,   142,     0,     0,    97,
     142,     0,   105,   142,   102,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,     0,   118,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       8,     0,     0,   142,     0,     0,     0,     0,   178,   179,
       0,     0,     0,     0,     0,     0,   169,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      55,   142,     0,     0,     0,     0,   110,   142,    60,    58,
     142,    63,    61,   142,    66,    64,   142,    70,   142,    72,
      73,    74,    76,    75,    79,    77,   142,    82,    80,   142,
      85,    83,   142,    88,    86,   142,    91,    89,   142,    92,
     142,    94,    69,    67,   142,    95,   142,     0,     0,     0,
       0,   120,   142,   122,   142,   124,   142,   126,   142,   128,
     142,   130,   142,   132,   142,   134,   142,   136,   142,   138,
     142,   140,   142,     0,     0,   142,     0,   142,     0,   142,
       0,   142,   142,     0,     3,   142,     0,     0,     0,   115,
     142,     0,     0,     0,     0,     0,     0,   187,     0,   191,
     171,     0,   142,   153,   168,     0,   156,   155,   154,   157,
     158,   159,   161,     0,     0,   164,   165,   166,     0,     9,
     142,    13,   142,    21,   142,    25,     0,    98,   142,   106,
     142,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   173,   117,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
     142,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,   142,     0,     0,   184,   181,   180,   182,
     183,     0,     0,     0,   172,     0,     0,     0,   163,     0,
       0,     0,     0,     0,    56,     0,     0,   112,    59,    62,
      65,    71,    78,    81,    84,    87,    90,    93,    68,    96,
     177,   121,   123,   125,   127,   129,   131,   133,   135,   137,
     139,   141,     0,    10,   142,    14,   142,    22,   142,    26,
      18,   142,   107,   142,     0,    99,   142,     0,   185,     0,
       4,   170,   160,   162,   167,    11,    15,    23,   100,   108,
      19,     0,     0,     0,     0,     0,   113,     0,   188,   175,
     190,   176,    12,    16,    24,    20,   109,   101
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     4,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   121,   117,   200,
     250,   118,   461,   539,   119,   541,   463
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -115
static const yytype_int16 yypact[] =
{
      99,  1158,     0,     4,   696,  1158,     0,  1158,     0,  1158,
       0,  1158,  -115,     0,   100,     0,   221,     0,  -115,     0,
     -19,  -115,     0,  -115,     0,  -115,     0,  -115,     0,  -115,
    -115,  -115,  -115,  -115,  -115,     0,  -115,     0,  -115,     0,
    -115,     0,  -115,     0,  -115,     0,  -115,  -115,     0,  -115,
       0,   -85,  -115,  -115,  -115,   -82,     0,   -54,     0,  -115,
       0,  -115,     0,  -115,     0,  -115,     0,  -115,     0,  -115,
       0,  -115,     0,  -115,     0,  -115,     0,  -115,     0,  -115,
       0,  1158,     0,  1312,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
     249,    83,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,    41,    41,
     -71,    -9,  -115,   -29,   -30,     0,   -26,   -23,    -5,    -3,
       2,    14,    55,     0,     0,    72,    80,    82,     0,  1312,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    1312,    -8,  1312,    -6,  1312,     9,  1312,  2409,    11,  -115,
     263,    13,  -115,   249,  -115,    15,  2666,    17,  -115,  2766,
      20,  2828,    22,  2889,    24,  3133,    25,  3160,  3177,  3204,
    3221,  3248,  2945,    27,  2989,    28,  3031,    29,  3053,    30,
    3089,    32,  3279,    34,  3308,  3116,    36,  3335,    38,   -50,
     -45,  -115,    40,  -115,    42,  2305,    44,  2039,    46,  1894,
      48,  1806,    50,  1768,    52,  1704,    53,  1648,    56,  1592,
      57,  1530,    58,  1465,    59,   390,    60,  1312,    61,  1158,
       0,  1158,     0,  1158,     0,  1158,  1158,     0,  -115,  1831,
    -115,   271,     0,  -115,     0,    98,   271,     0,  -115,  -115,
     -18,     5,    84,    18,  1158,    95,  -115,    97,    62,    73,
      81,    54,    93,    67,    66,    79,    63,    64,   101,   103,
      70,    65,  1915,  1158,  2062,  1158,  2209,  1158,   849,  -115,
    -115,  -115,  2426,   271,  2549,   271,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,    47,   102,    85,
      86,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,   322,  1158,  1312,    68,  1312,    69,  1312,
      71,  1312,  1312,    75,  -115,   249,    76,  2688,    77,  -115,
     263,    78,    41,    41,    41,    41,    41,  -115,    89,  -115,
    -115,    96,  1312,  -115,  -115,   104,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,   123,    -4,  -115,  -115,  -115,   132,  -115,
    1312,  -115,  1312,  -115,  1312,  -115,  2388,  -115,   263,  -115,
     249,  2722,  2802,  2862,  2923,  3352,  3396,  3413,  3457,  3379,
    3479,  3513,  3540,  3569,    41,  -115,  -115,  -115,  2326,  2095,
    1938,  1850,  1789,  1728,  1672,  1616,  1554,  1492,  1448,  -115,
    1312,  1957,  1158,  2120,  1158,  2232,  1158,  1003,   544,  1158,
    2583,   271,  -115,  -115,  2488,   271,   126,   -16,   -16,    49,
      49,  1158,    41,  1158,  -115,  1873,   121,   160,  -115,   161,
     155,  1999,  2153,  2265,  -115,  2505,  2610,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
      19,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,   565,  -115,  1312,  -115,  1312,  -115,  1312,  -115,
    -115,  1312,  -115,   249,  2744,  -115,   263,   850,   126,  1004,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  2022,  2176,  2288,  1431,  2644,  -115,  2522,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,   106,     7,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,   -14,
     -13,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,   -12,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,   551,    23,  -115,
    -114,  -115,  -115,  -115,  -115,  -115,  -115
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -103
static const yytype_int16 yytable[] =
{
     157,   160,   163,   164,   122,   251,   166,   253,   253,   169,
     253,   171,   168,   173,   256,   175,   120,   177,   178,   179,
     180,   181,   182,   199,   184,   253,   186,   253,   188,   253,
     190,   253,   192,   253,   194,   195,   253,   197,   253,   201,
     253,   253,   252,   253,   253,   253,   253,   205,   253,   207,
     253,   209,   253,   211,   253,   213,   253,   215,   253,   217,
     253,   219,   253,   221,   253,   223,   253,   225,   253,   253,
     203,   239,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   257,   255,   253,   253,   259,   253,   468,   260,
     238,   253,   253,   253,   253,   372,   373,   374,   375,   376,
     375,   376,     1,     2,   246,   247,   240,   261,   469,   262,
     139,   150,   327,   152,   263,   154,   328,   156,   372,   373,
     374,   375,   376,   159,    16,    17,   264,    18,    19,   369,
      20,   381,   372,   373,   374,   375,   376,   383,   272,   388,
     274,   384,   276,   377,   278,   378,   238,   378,   282,   248,
     249,   284,   254,   273,   386,   275,   390,   238,   391,   238,
     424,   238,   240,   238,   387,   521,   379,   265,   378,   397,
     277,   392,   281,   240,   283,   240,   285,   240,   287,   240,
     389,   290,   378,   293,   268,   296,   298,   227,   306,   309,
     312,   315,   269,   318,   270,   320,   380,   324,   395,   326,
     396,   329,   462,   330,   425,   332,   426,   334,   464,   336,
     427,   338,   378,   340,   342,   353,   466,   344,   346,   348,
     350,   352,   354,   385,   393,   394,   398,   365,   164,   442,
     444,   367,   446,   370,   238,   467,   449,   451,   453,   455,
     373,   374,   375,   376,   470,    16,    17,   162,    18,    19,
     240,    20,   522,   523,   524,     0,     0,     0,   456,   457,
     458,   459,   460,     0,     0,     0,     0,     0,     0,   406,
     408,   410,   164,   241,   242,   411,   243,   244,   412,   245,
       0,   413,     0,     0,   414,     0,   415,  -102,  -102,   378,
    -102,  -102,     0,  -102,   416,    16,    17,   417,    18,    19,
     418,    20,     0,   419,     0,     0,   420,     0,   421,     0,
     490,     0,   422,     0,   423,     0,     0,     0,     0,     0,
     428,     0,   429,     0,   430,     0,   431,     0,   432,     0,
     433,     0,   434,     0,   435,   355,   436,   357,   437,   359,
     438,   361,   362,   441,     0,   443,     0,   445,   518,   447,
     448,     0,     0,   450,     0,     0,     0,     0,   454,     0,
     382,     0,   238,   123,   238,   124,   238,   125,   238,   238,
     465,     0,     0,     0,     0,     0,     0,     0,   240,   400,
     240,   402,   240,   404,   240,   240,     0,     0,   471,   238,
     472,     0,   473,     0,     0,     0,   475,     0,   476,     0,
       0,     0,   126,     0,   127,   240,   128,   238,   129,   238,
     130,   238,   131,   132,     0,   133,   134,   135,   136,     0,
     137,     0,   138,   240,     0,   240,     0,   240,   502,     0,
       0,   123,     0,   124,     0,   125,     0,   513,   164,     0,
       0,   514,   516,     0,     0,     0,     0,   238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     440,     0,     0,   240,     0,     0,     0,     0,     0,     0,
     126,     0,   127,     0,   128,     0,   129,     0,   130,     0,
     131,   132,   439,   133,   134,   135,   136,     0,   137,     0,
     138,     0,   531,     0,   532,     0,   533,     0,     0,   534,
       0,   535,     0,     0,   537,     0,     0,     0,     0,     0,
       0,   238,     0,   238,     0,   238,     0,     0,   238,     0,
       0,     0,     0,     0,   238,     0,   238,   240,     0,   240,
       0,   240,     0,     0,   240,     0,     0,     0,     0,     0,
     240,     0,   240,     0,     0,     0,     0,   351,   504,     0,
     506,     0,   508,     0,     0,   511,     0,   151,     0,   153,
       0,   155,     0,     0,   158,     0,   161,   517,   165,   519,
     167,     0,     0,   170,     0,   172,     0,   174,     0,   176,
       0,     0,     0,     0,     0,   123,   183,   124,   185,   125,
     187,     0,   189,     0,   191,     0,   193,     0,     0,   196,
       0,   198,     0,     0,     0,     0,   123,   202,   124,   204,
     125,   206,     0,   208,     0,   210,     0,   212,     0,   214,
       0,   216,     0,   218,   126,   220,   127,   222,   128,   224,
     129,   226,   130,   228,   131,   132,     0,   133,   134,   135,
     136,     0,   137,     0,   138,   126,     0,   127,     0,   128,
       0,   129,     0,   130,     0,   131,   132,     0,   133,   134,
     135,   136,     0,   137,     0,   138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   258,     0,     0,     0,
       0,     0,     0,     0,   266,   267,     0,     0,     0,   271,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     6,   510,     7,     8,     0,     9,     0,
      10,    11,     0,     0,    12,     0,    13,    14,    15,     0,
      16,    17,     0,    18,    19,   530,    20,     0,    21,    22,
       0,    23,    24,     0,    25,    26,     0,   123,     0,   124,
       0,   125,    27,    28,     0,    29,    30,    31,    32,    33,
      34,     0,    35,    36,     0,    37,    38,     0,    39,    40,
      41,     0,    42,     0,    43,    44,    45,     0,    46,     0,
      47,    48,     0,    49,    50,     0,   126,     0,   127,     0,
     128,   356,   129,   358,   130,   360,   131,   132,   363,   133,
     134,   135,   136,   366,   137,   368,   138,    51,   371,    52,
       0,    53,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    56,     0,    57,    58,
       0,    59,    60,     0,    61,    62,     0,    63,    64,     0,
      65,    66,     0,    67,    68,     0,    69,    70,     0,    71,
      72,     0,    73,    74,     0,    75,    76,     0,    77,    78,
       0,    79,    80,     0,    81,    82,   229,   230,     0,   231,
     232,     0,   233,     0,   234,   235,   405,     0,    12,     0,
      13,    14,    15,     0,    16,    17,     0,    18,    19,     0,
      20,     0,    21,    22,     0,    23,    24,     0,    25,    26,
     123,     0,   124,     0,   125,     0,    27,    28,     0,    29,
      30,    31,    32,    33,    34,     0,    35,    36,     0,    37,
      38,     0,    39,    40,    41,     0,    42,     0,    43,    44,
      45,     0,    46,     0,    47,    48,     0,    49,    50,   126,
       0,   127,     0,   128,     0,   129,     0,   130,     0,   131,
     132,     0,   133,   134,   135,   136,     0,   137,     0,   138,
       0,    51,     0,    52,   538,    53,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      56,     0,    57,    58,     0,    59,    60,     0,    61,    62,
       0,    63,    64,     0,    65,    66,     0,    67,    68,     0,
      69,    70,     0,    71,    72,     0,    73,    74,     0,    75,
      76,     0,    77,    78,     0,    79,    80,     0,   236,   237,
     229,   230,     0,   231,   232,     0,   233,     0,   234,   235,
     509,     0,    12,     0,    13,    14,    15,     0,    16,    17,
       0,    18,    19,     0,    20,     0,    21,    22,     0,    23,
      24,     0,    25,    26,   123,     0,   124,     0,   125,     0,
      27,    28,     0,    29,    30,    31,    32,    33,    34,     0,
      35,    36,     0,    37,    38,     0,    39,    40,    41,     0,
      42,     0,    43,    44,    45,     0,    46,     0,    47,    48,
       0,    49,    50,   126,     0,   127,     0,   128,     0,   129,
       0,   130,     0,   131,   132,     0,   133,   134,   135,   136,
       0,   137,     0,   138,     0,    51,     0,    52,     0,    53,
     540,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,     0,    57,    58,     0,    59,
      60,     0,    61,    62,     0,    63,    64,     0,    65,    66,
       0,    67,    68,     0,    69,    70,     0,    71,    72,     0,
      73,    74,     0,    75,    76,     0,    77,    78,     0,    79,
      80,     0,   236,   237,     5,     6,     0,     7,     8,     0,
       9,     0,    10,    11,     0,     0,    12,     0,    13,    14,
      15,     0,    16,    17,     0,    18,    19,     0,    20,     0,
      21,    22,     0,    23,    24,     0,    25,    26,     0,     0,
       0,     0,     0,     0,    27,    28,     0,    29,    30,    31,
      32,    33,    34,     0,    35,    36,     0,    37,    38,     0,
      39,    40,    41,     0,    42,     0,    43,    44,    45,     0,
      46,     0,    47,    48,     0,    49,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    51,
       0,    52,     0,    53,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    56,     0,
      57,    58,     0,    59,    60,     0,    61,    62,     0,    63,
      64,     0,    65,    66,     0,    67,    68,     0,    69,    70,
       0,    71,    72,     0,    73,    74,     0,    75,    76,     0,
      77,    78,     0,    79,    80,     0,    81,    82,   229,   230,
       0,   231,   232,     0,   233,     0,   234,   235,     0,     0,
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
       0,    75,    76,     0,    77,    78,     0,    79,    80,     0,
     236,   237,   123,     0,   124,     0,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
       0,   124,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   123,     0,   124,     0,
     125,   126,     0,   127,     0,   128,     0,   129,     0,   130,
       0,   131,   132,     0,   133,   134,   135,   136,   126,   137,
     127,   138,   128,   123,   129,   124,   130,   125,   131,   132,
       0,   133,   134,   135,   136,   126,   137,   127,   138,   128,
       0,   129,     0,   130,     0,   131,   132,     0,   133,   134,
     135,   136,     0,   137,     0,   138,     0,     0,     0,     0,
       0,   123,   126,   124,   127,   125,   128,     0,   129,     0,
     130,     0,   131,   132,     0,   133,   134,   135,   136,     0,
     137,   545,   138,     0,     0,   123,     0,   124,     0,   125,
       0,     0,     0,     0,     0,   501,     0,     0,     0,     0,
     126,     0,   127,     0,   128,     0,   129,     0,   130,   349,
     131,   132,     0,   133,   134,   135,   136,     0,   137,     0,
     138,     0,     0,   123,   126,   124,   127,   125,   128,     0,
     129,     0,   130,     0,   131,   132,   500,   133,   134,   135,
     136,     0,   137,     0,   138,     0,     0,   123,     0,   124,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   126,     0,   127,     0,   128,     0,   129,     0,
     130,   347,   131,   132,     0,   133,   134,   135,   136,   123,
     137,   124,   138,   125,     0,     0,   126,     0,   127,     0,
     128,     0,   129,     0,   130,   499,   131,   132,     0,   133,
     134,   135,   136,   123,   137,   124,   138,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,     0,
     127,     0,   128,     0,   129,     0,   130,     0,   131,   132,
     345,   133,   134,   135,   136,   123,   137,   124,   138,   125,
       0,     0,   126,     0,   127,     0,   128,     0,   129,     0,
     130,     0,   131,   132,   498,   133,   134,   135,   136,   123,
     137,   124,   138,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   126,     0,   127,     0,   128,     0,
     129,     0,   130,   343,   131,   132,     0,   133,   134,   135,
     136,     0,   137,     0,   138,     0,     0,     0,   126,   123,
     127,   124,   128,   125,   129,     0,   130,   497,   131,   132,
       0,   133,   134,   135,   136,     0,   137,     0,   138,     0,
     123,     0,   124,     0,   125,     0,   364,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   341,   123,   126,   124,
     127,   125,   128,     0,   129,     0,   130,     0,   131,   132,
       0,   133,   134,   135,   136,     0,   137,     0,   138,   126,
     496,   127,   123,   128,   124,   129,   125,   130,   520,   131,
     132,     0,   133,   134,   135,   136,   126,   137,   127,   138,
     128,   123,   129,   124,   130,   125,   131,   132,     0,   133,
     134,   135,   136,     0,   137,     0,   138,   339,     0,     0,
       0,   126,     0,   127,   123,   128,   124,   129,   125,   130,
       0,   131,   132,   399,   133,   134,   135,   136,   495,   137,
     126,   138,   127,     0,   128,   123,   129,   124,   130,   125,
     131,   132,   337,   133,   134,   135,   136,     0,   137,     0,
     138,     0,     0,   126,     0,   127,   123,   128,   124,   129,
     125,   130,     0,   131,   132,   503,   133,   134,   135,   136,
       0,   137,     0,   138,   126,     0,   127,     0,   128,   123,
     129,   124,   130,   125,   131,   132,   494,   133,   134,   135,
     136,     0,   137,     0,   138,   126,     0,   127,   123,   128,
     124,   129,   125,   130,     0,   131,   132,   525,   133,   134,
     135,   136,     0,   137,     0,   138,     0,     0,   126,     0,
     127,     0,   128,     0,   129,     0,   130,   335,   131,   132,
     542,   133,   134,   135,   136,     0,   137,   126,   138,   127,
     123,   128,   124,   129,   125,   130,     0,   131,   132,     0,
     133,   134,   135,   136,     0,   137,     0,   138,     0,     0,
       0,     0,     0,   123,     0,   124,     0,   125,     0,     0,
       0,   493,     0,   401,     0,     0,     0,     0,     0,   126,
     123,   127,   124,   128,   125,   129,     0,   130,     0,   131,
     132,     0,   133,   134,   135,   136,     0,   137,     0,   138,
       0,     0,   126,   123,   127,   124,   128,   125,   129,     0,
     130,     0,   131,   132,     0,   133,   134,   135,   136,   126,
     137,   127,   138,   128,     0,   129,     0,   130,     0,   131,
     132,   505,   133,   134,   135,   136,   123,   137,   124,   138,
     125,     0,   126,     0,   127,     0,   128,     0,   129,     0,
     130,     0,   131,   132,     0,   133,   134,   135,   136,     0,
     137,   123,   138,   124,   526,   125,     0,     0,     0,   333,
       0,     0,     0,     0,     0,   126,     0,   127,     0,   128,
       0,   129,     0,   130,     0,   131,   132,   543,   133,   134,
     135,   136,     0,   137,   123,   138,   124,     0,   125,     0,
     126,     0,   127,     0,   128,     0,   129,     0,   130,     0,
     131,   132,     0,   133,   134,   135,   136,   123,   137,   124,
     138,   125,   403,     0,     0,   492,     0,     0,     0,     0,
       0,     0,     0,   126,     0,   127,     0,   128,     0,   129,
       0,   130,     0,   131,   132,   507,   133,   134,   135,   136,
     123,   137,   124,   138,   125,     0,   126,     0,   127,     0,
     128,     0,   129,     0,   130,     0,   131,   132,     0,   133,
     134,   135,   136,   123,   137,   124,   138,   125,   527,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
       0,   127,     0,   128,     0,   129,     0,   130,     0,   131,
     132,   544,   133,   134,   135,   136,   123,   137,   124,   138,
     125,     0,   126,     0,   127,     0,   128,     0,   129,     0,
     130,     0,   131,   132,     0,   133,   134,   135,   136,   123,
     137,   124,   138,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,   123,   127,   124,   128,
     125,   129,     0,   130,     0,   131,   132,     0,   133,   134,
     135,   136,     0,   137,     0,   138,     0,   123,   126,   124,
     127,   125,   128,     0,   129,     0,   130,     0,   131,   132,
       0,   133,   134,   135,   136,   126,   137,   127,   138,   128,
       0,   129,     0,   130,     0,   131,   132,     0,   133,   134,
     135,   136,     0,   137,     0,   138,   126,   474,   127,     0,
     128,     0,   129,     0,   130,     0,   131,   132,     0,   133,
     134,   135,   136,     0,   137,     0,   138,   279,   280,   123,
       0,   124,   331,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   407,
     123,     0,   124,   491,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   123,   126,   124,
     127,   125,   128,     0,   129,     0,   130,     0,   131,   132,
       0,   133,   134,   135,   136,     0,   137,     0,   138,   126,
       0,   127,     0,   128,     0,   129,     0,   130,     0,   131,
     132,     0,   133,   134,   135,   136,   126,   137,   127,   138,
     128,   515,   129,     0,   130,     0,   131,   132,     0,   133,
     134,   135,   136,     0,   137,     0,   138,     0,   528,   123,
       0,   124,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   547,   123,     0,   124,     0,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,     0,   124,     0,   125,   126,     0,
     127,     0,   128,     0,   129,   409,   130,     0,   131,   132,
       0,   133,   134,   135,   136,   126,   137,   127,   138,   128,
     123,   129,   124,   130,   125,   131,   132,     0,   133,   134,
     135,   136,   126,   137,   127,   138,   128,     0,   129,   512,
     130,     0,   131,   132,     0,   133,   134,   135,   136,     0,
     137,     0,   138,     0,   123,     0,   124,     0,   125,   126,
       0,   127,     0,   128,     0,   129,   529,   130,     0,   131,
     132,     0,   133,   134,   135,   136,     0,   137,     0,   138,
       0,   123,     0,   124,     0,   125,     0,     0,     0,     0,
       0,     0,     0,   126,     0,   127,     0,   128,     0,   129,
     546,   130,     0,   131,   132,     0,   133,   134,   135,   136,
       0,   137,     0,   138,     0,   123,     0,   124,     0,   125,
     126,     0,   127,     0,   128,   286,   129,     0,   130,     0,
     131,   132,     0,   133,   134,   135,   136,   123,   137,   124,
     138,   125,     0,     0,     0,     0,     0,   452,     0,     0,
       0,     0,     0,     0,   126,     0,   127,     0,   128,   123,
     129,   124,   130,   125,   131,   132,     0,   133,   134,   135,
     136,     0,   137,     0,   138,     0,   126,     0,   127,     0,
     128,   477,   129,     0,   130,     0,   131,   132,     0,   133,
     134,   135,   136,   123,   137,   124,   138,   125,   126,     0,
     127,     0,   128,   536,   129,     0,   130,     0,   131,   132,
       0,   133,   134,   135,   136,   123,   137,   124,   138,   125,
       0,     0,     0,     0,     0,     0,     0,     0,   288,     0,
     289,     0,   126,     0,   127,     0,   128,   123,   129,   124,
     130,   125,   131,   132,     0,   133,   134,   135,   136,     0,
     137,     0,   138,     0,   126,     0,   127,     0,   128,     0,
     129,     0,   130,     0,   131,   132,   478,   133,   134,   135,
     136,     0,   137,   123,   138,   124,   126,   125,   127,     0,
     128,     0,   129,     0,   130,     0,   131,   132,     0,   133,
     134,   135,   136,   291,   137,   292,   138,     0,     0,   123,
       0,   124,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,   126,     0,   127,     0,   128,     0,   129,     0,
     130,     0,   131,   132,     0,   133,   134,   135,   136,   479,
     137,     0,   138,   123,     0,   124,     0,   125,   126,     0,
     127,     0,   128,     0,   129,     0,   130,     0,   131,   132,
       0,   133,   134,   135,   136,     0,   137,   294,   138,   295,
     123,     0,   124,     0,   125,     0,     0,     0,     0,     0,
       0,     0,   126,     0,   127,     0,   128,     0,   129,     0,
     130,     0,   131,   132,     0,   133,   134,   135,   136,     0,
     137,     0,   138,   480,   123,     0,   124,     0,   125,   126,
       0,   127,     0,   128,     0,   129,     0,   130,     0,   131,
     132,     0,   133,   134,   135,   136,   123,   137,   124,   138,
     125,     0,     0,     0,     0,     0,     0,     0,     0,   304,
     305,     0,     0,   126,     0,   127,     0,   128,     0,   129,
       0,   130,     0,   131,   132,     0,   133,   134,   135,   136,
       0,   137,     0,   138,     0,   126,     0,   127,     0,   128,
     123,   129,   124,   130,   125,   131,   132,     0,   133,   134,
     135,   136,     0,   137,     0,   138,   307,   308,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
       0,   127,   123,   128,   124,   129,   125,   130,     0,   131,
     132,     0,   133,   134,   135,   136,     0,   137,     0,   138,
       0,   310,   311,     0,   123,     0,   124,     0,   125,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,     0,   127,     0,   128,   313,   129,   314,   130,
       0,   131,   132,     0,   133,   134,   135,   136,     0,   137,
     123,   138,   124,   126,   125,   127,     0,   128,     0,   129,
       0,   130,     0,   131,   132,     0,   133,   134,   135,   136,
       0,   137,     0,   138,     0,   316,   317,   123,     0,   124,
       0,   125,     0,     0,     0,     0,     0,     0,     0,   126,
       0,   127,     0,   128,   123,   129,   124,   130,   125,   131,
     132,   297,   133,   134,   135,   136,     0,   137,     0,   138,
     322,     0,   323,     0,     0,     0,   126,     0,   127,     0,
     128,   123,   129,   124,   130,   125,   131,   132,   299,   133,
     134,   135,   136,   126,   137,   127,   138,   128,   123,   129,
     124,   130,   125,   131,   132,   300,   133,   134,   135,   136,
       0,   137,     0,   138,     0,     0,     0,     0,     0,     0,
     126,     0,   127,     0,   128,   123,   129,   124,   130,   125,
     131,   132,   301,   133,   134,   135,   136,   126,   137,   127,
     138,   128,   123,   129,   124,   130,   125,   131,   132,   302,
     133,   134,   135,   136,     0,   137,     0,   138,     0,     0,
       0,     0,     0,     0,   126,     0,   127,     0,   128,   123,
     129,   124,   130,   125,   131,   132,   303,   133,   134,   135,
     136,   126,   137,   127,   138,   128,     0,   129,     0,   130,
       0,   131,   132,     0,   133,   134,   135,   136,     0,   137,
     123,   138,   124,     0,   125,     0,     0,     0,   126,     0,
     127,     0,   128,     0,   129,     0,   130,     0,   131,   132,
       0,   133,   134,   135,   136,     0,   137,     0,   138,   123,
     319,   124,     0,   125,     0,     0,     0,     0,     0,   126,
       0,   127,     0,   128,     0,   129,     0,   130,     0,   131,
     132,     0,   133,   134,   135,   136,   123,   137,   124,   138,
     125,   321,     0,     0,     0,     0,     0,     0,   126,     0,
     127,     0,   128,   123,   129,   124,   130,   125,   131,   132,
     481,   133,   134,   135,   136,     0,   137,     0,   138,     0,
       0,     0,     0,     0,   325,   126,     0,   127,     0,   128,
     123,   129,   124,   130,   125,   131,   132,     0,   133,   134,
     135,   136,   126,   137,   127,   138,   128,   123,   129,   124,
     130,   125,   131,   132,   485,   133,   134,   135,   136,     0,
     137,   482,   138,     0,   123,     0,   124,     0,   125,   126,
       0,   127,     0,   128,     0,   129,     0,   130,     0,   131,
     132,   483,   133,   134,   135,   136,   126,   137,   127,   138,
     128,     0,   129,     0,   130,     0,   131,   132,     0,   133,
     134,   135,   136,   126,   137,   127,   138,   128,   123,   129,
     124,   130,   125,   131,   132,     0,   133,   134,   135,   136,
       0,   137,     0,   138,     0,     0,     0,     0,   484,     0,
     123,     0,   124,     0,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,     0,   127,
       0,   128,     0,   129,     0,   130,   486,   131,   132,     0,
     133,   134,   135,   136,   123,   137,   124,   138,   125,   126,
       0,   127,     0,   128,     0,   129,     0,   130,     0,   131,
     132,     0,   133,   134,   135,   136,     0,   137,     0,   138,
       0,   123,     0,   124,   487,   125,     0,     0,     0,     0,
       0,     0,     0,   126,     0,   127,     0,   128,     0,   129,
       0,   130,     0,   131,   132,     0,   133,   134,   135,   136,
     123,   137,   124,   138,   125,     0,   488,     0,     0,     0,
     126,     0,   127,     0,   128,     0,   129,     0,   130,     0,
     131,   132,     0,   133,   134,   135,   136,     0,   137,     0,
     138,     0,     0,     0,     0,     0,     0,     0,   489,   126,
       0,   127,     0,   128,     0,   129,     0,   130,     0,   131,
     132,     0,   133,   134,   135,   136,     0,   137,     0,   138
};

static const yytype_int16 yycheck[] =
{
      12,    14,    16,    16,     0,   119,    18,    16,    16,    21,
      16,    23,    31,    25,    44,    27,    16,    29,    30,    31,
      32,    33,    34,   108,    36,    16,    38,    16,    40,    16,
      42,    16,    44,    16,    46,    47,    16,    49,    16,   121,
      16,    16,   113,    16,    16,    16,    16,    59,    16,    61,
      16,    63,    16,    65,    16,    67,    16,    69,    16,    71,
      16,    73,    16,    75,    16,    77,    16,    79,    16,    16,
     124,    83,    16,    16,    16,    16,    16,    16,    16,    16,
      16,    16,   112,   112,    16,    16,   112,    16,    92,   112,
      83,    16,    16,    16,    16,   113,   114,   115,   116,   117,
     116,   117,     3,     4,    21,    22,    83,   112,   112,   112,
       4,     5,   162,     7,   112,     9,   161,    11,   113,   114,
     115,   116,   117,    23,    24,    25,   112,    27,    28,    31,
      30,   113,   113,   114,   115,   116,   117,    42,   150,    85,
     152,    44,   154,   161,   156,   163,   139,   163,   160,   108,
     109,   163,   161,   161,    81,   161,    89,   150,    92,   152,
     113,   154,   139,   156,    83,    44,   161,   112,   163,    99,
     161,    92,   161,   150,   161,   152,   161,   154,   161,   156,
      87,   161,   163,   161,   112,   161,   161,    81,   161,   161,
     161,   161,   112,   161,   112,   161,   112,   161,    97,   161,
      97,   161,   113,   161,   102,   161,   121,   161,   112,   161,
     124,   161,   163,   161,   161,   227,   112,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   241,   241,   161,
     161,   243,   161,   246,   227,   112,   161,   161,   161,   161,
     114,   115,   116,   117,   112,    24,    25,    26,    27,    28,
     227,    30,    92,    92,    99,    -1,    -1,    -1,   372,   373,
     374,   375,   376,    -1,    -1,    -1,    -1,    -1,    -1,   281,
     283,   285,   285,    24,    25,   287,    27,    28,   290,    30,
      -1,   293,    -1,    -1,   296,    -1,   298,    24,    25,   163,
      27,    28,    -1,    30,   306,    24,    25,   309,    27,    28,
     312,    30,    -1,   315,    -1,    -1,   318,    -1,   320,    -1,
     424,    -1,   324,    -1,   326,    -1,    -1,    -1,    -1,    -1,
     332,    -1,   334,    -1,   336,    -1,   338,    -1,   340,    -1,
     342,    -1,   344,    -1,   346,   229,   348,   231,   350,   233,
     352,   235,   236,   355,    -1,   357,    -1,   359,   462,   361,
     362,    -1,    -1,   365,    -1,    -1,    -1,    -1,   370,    -1,
     254,    -1,   355,    41,   357,    43,   359,    45,   361,   362,
     382,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,   273,
     357,   275,   359,   277,   361,   362,    -1,    -1,   400,   382,
     402,    -1,   404,    -1,    -1,    -1,   408,    -1,   410,    -1,
      -1,    -1,    80,    -1,    82,   382,    84,   400,    86,   402,
      88,   404,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    -1,   100,   400,    -1,   402,    -1,   404,   440,    -1,
      -1,    41,    -1,    43,    -1,    45,    -1,   451,   451,    -1,
      -1,   453,   455,    -1,    -1,    -1,    -1,   440,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     354,    -1,    -1,   440,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,
      90,    91,   160,    93,    94,    95,    96,    -1,    98,    -1,
     100,    -1,   504,    -1,   506,    -1,   508,    -1,    -1,   511,
      -1,   513,    -1,    -1,   516,    -1,    -1,    -1,    -1,    -1,
      -1,   504,    -1,   506,    -1,   508,    -1,    -1,   511,    -1,
      -1,    -1,    -1,    -1,   517,    -1,   519,   504,    -1,   506,
      -1,   508,    -1,    -1,   511,    -1,    -1,    -1,    -1,    -1,
     517,    -1,   519,    -1,    -1,    -1,    -1,   157,   442,    -1,
     444,    -1,   446,    -1,    -1,   449,    -1,     6,    -1,     8,
      -1,    10,    -1,    -1,    13,    -1,    15,   461,    17,   463,
      19,    -1,    -1,    22,    -1,    24,    -1,    26,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    41,    35,    43,    37,    45,
      39,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,    48,
      -1,    50,    -1,    -1,    -1,    -1,    41,    56,    43,    58,
      45,    60,    -1,    62,    -1,    64,    -1,    66,    -1,    68,
      -1,    70,    -1,    72,    80,    74,    82,    76,    84,    78,
      86,    80,    88,    82,    90,    91,    -1,    93,    94,    95,
      96,    -1,    98,    -1,   100,    80,    -1,    82,    -1,    84,
      -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,    94,
      95,    96,    -1,    98,    -1,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   133,   134,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,   160,     9,    10,    -1,    12,    -1,
      14,    15,    -1,    -1,    18,    -1,    20,    21,    22,    -1,
      24,    25,    -1,    27,    28,   160,    30,    -1,    32,    33,
      -1,    35,    36,    -1,    38,    39,    -1,    41,    -1,    43,
      -1,    45,    46,    47,    -1,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    -1,    59,    60,    -1,    62,    63,
      64,    -1,    66,    -1,    68,    69,    70,    -1,    72,    -1,
      74,    75,    -1,    77,    78,    -1,    80,    -1,    82,    -1,
      84,   230,    86,   232,    88,   234,    90,    91,   237,    93,
      94,    95,    96,   242,    98,   244,   100,   101,   247,   103,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,   120,    -1,   122,   123,
      -1,   125,   126,    -1,   128,   129,    -1,   131,   132,    -1,
     134,   135,    -1,   137,   138,    -1,   140,   141,    -1,   143,
     144,    -1,   146,   147,    -1,   149,   150,    -1,   152,   153,
      -1,   155,   156,    -1,   158,   159,     6,     7,    -1,     9,
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
     150,    -1,   152,   153,    -1,   155,   156,    -1,   158,   159,
       6,     7,    -1,     9,    10,    -1,    12,    -1,    14,    15,
      17,    -1,    18,    -1,    20,    21,    22,    -1,    24,    25,
      -1,    27,    28,    -1,    30,    -1,    32,    33,    -1,    35,
      36,    -1,    38,    39,    41,    -1,    43,    -1,    45,    -1,
      46,    47,    -1,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    -1,    59,    60,    -1,    62,    63,    64,    -1,
      66,    -1,    68,    69,    70,    -1,    72,    -1,    74,    75,
      -1,    77,    78,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    90,    91,    -1,    93,    94,    95,    96,
      -1,    98,    -1,   100,    -1,   101,    -1,   103,    -1,   105,
     106,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,   120,    -1,   122,   123,    -1,   125,
     126,    -1,   128,   129,    -1,   131,   132,    -1,   134,   135,
      -1,   137,   138,    -1,   140,   141,    -1,   143,   144,    -1,
     146,   147,    -1,   149,   150,    -1,   152,   153,    -1,   155,
     156,    -1,   158,   159,     6,     7,    -1,     9,    10,    -1,
      12,    -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,
      22,    -1,    24,    25,    -1,    27,    28,    -1,    30,    -1,
      32,    33,    -1,    35,    36,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    -1,    59,    60,    -1,
      62,    63,    64,    -1,    66,    -1,    68,    69,    70,    -1,
      72,    -1,    74,    75,    -1,    77,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,   103,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,    -1,
     122,   123,    -1,   125,   126,    -1,   128,   129,    -1,   131,
     132,    -1,   134,   135,    -1,   137,   138,    -1,   140,   141,
      -1,   143,   144,    -1,   146,   147,    -1,   149,   150,    -1,
     152,   153,    -1,   155,   156,    -1,   158,   159,     6,     7,
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
      -1,   149,   150,    -1,   152,   153,    -1,   155,   156,    -1,
     158,   159,    41,    -1,    43,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    43,    -1,
      45,    80,    -1,    82,    -1,    84,    -1,    86,    -1,    88,
      -1,    90,    91,    -1,    93,    94,    95,    96,    80,    98,
      82,   100,    84,    41,    86,    43,    88,    45,    90,    91,
      -1,    93,    94,    95,    96,    80,    98,    82,   100,    84,
      -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,    94,
      95,    96,    -1,    98,    -1,   100,    -1,    -1,    -1,    -1,
      -1,    41,    80,    43,    82,    45,    84,    -1,    86,    -1,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,   160,   100,    -1,    -1,    41,    -1,    43,    -1,    45,
      -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    84,    -1,    86,    -1,    88,   154,
      90,    91,    -1,    93,    94,    95,    96,    -1,    98,    -1,
     100,    -1,    -1,    41,    80,    43,    82,    45,    84,    -1,
      86,    -1,    88,    -1,    90,    91,   154,    93,    94,    95,
      96,    -1,    98,    -1,   100,    -1,    -1,    41,    -1,    43,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,
      88,   151,    90,    91,    -1,    93,    94,    95,    96,    41,
      98,    43,   100,    45,    -1,    -1,    80,    -1,    82,    -1,
      84,    -1,    86,    -1,    88,   151,    90,    91,    -1,    93,
      94,    95,    96,    41,    98,    43,   100,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,    91,
     148,    93,    94,    95,    96,    41,    98,    43,   100,    45,
      -1,    -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,
      88,    -1,    90,    91,   148,    93,    94,    95,    96,    41,
      98,    43,   100,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    84,    -1,
      86,    -1,    88,   145,    90,    91,    -1,    93,    94,    95,
      96,    -1,    98,    -1,   100,    -1,    -1,    -1,    80,    41,
      82,    43,    84,    45,    86,    -1,    88,   145,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    -1,   100,    -1,
      41,    -1,    43,    -1,    45,    -1,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,    41,    80,    43,
      82,    45,    84,    -1,    86,    -1,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    -1,   100,    80,
     142,    82,    41,    84,    43,    86,    45,    88,     5,    90,
      91,    -1,    93,    94,    95,    96,    80,    98,    82,   100,
      84,    41,    86,    43,    88,    45,    90,    91,    -1,    93,
      94,    95,    96,    -1,    98,    -1,   100,   139,    -1,    -1,
      -1,    80,    -1,    82,    41,    84,    43,    86,    45,    88,
      -1,    90,    91,     8,    93,    94,    95,    96,   139,    98,
      80,   100,    82,    -1,    84,    41,    86,    43,    88,    45,
      90,    91,   136,    93,    94,    95,    96,    -1,    98,    -1,
     100,    -1,    -1,    80,    -1,    82,    41,    84,    43,    86,
      45,    88,    -1,    90,    91,     8,    93,    94,    95,    96,
      -1,    98,    -1,   100,    80,    -1,    82,    -1,    84,    41,
      86,    43,    88,    45,    90,    91,   136,    93,    94,    95,
      96,    -1,    98,    -1,   100,    80,    -1,    82,    41,    84,
      43,    86,    45,    88,    -1,    90,    91,     8,    93,    94,
      95,    96,    -1,    98,    -1,   100,    -1,    -1,    80,    -1,
      82,    -1,    84,    -1,    86,    -1,    88,   133,    90,    91,
       8,    93,    94,    95,    96,    -1,    98,    80,   100,    82,
      41,    84,    43,    86,    45,    88,    -1,    90,    91,    -1,
      93,    94,    95,    96,    -1,    98,    -1,   100,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,
      -1,   133,    -1,    11,    -1,    -1,    -1,    -1,    -1,    80,
      41,    82,    43,    84,    45,    86,    -1,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    -1,    98,    -1,   100,
      -1,    -1,    80,    41,    82,    43,    84,    45,    86,    -1,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    80,
      98,    82,   100,    84,    -1,    86,    -1,    88,    -1,    90,
      91,    11,    93,    94,    95,    96,    41,    98,    43,   100,
      45,    -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    41,   100,    43,    11,    45,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    84,
      -1,    86,    -1,    88,    -1,    90,    91,    11,    93,    94,
      95,    96,    -1,    98,    41,   100,    43,    -1,    45,    -1,
      80,    -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    41,    98,    43,
     100,    45,    13,    -1,    -1,   130,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    90,    91,    13,    93,    94,    95,    96,
      41,    98,    43,   100,    45,    -1,    80,    -1,    82,    -1,
      84,    -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,
      94,    95,    96,    41,    98,    43,   100,    45,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,
      91,    13,    93,    94,    95,    96,    41,    98,    43,   100,
      45,    -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    41,
      98,    43,   100,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    41,    82,    43,    84,
      45,    86,    -1,    88,    -1,    90,    91,    -1,    93,    94,
      95,    96,    -1,    98,    -1,   100,    -1,    41,    80,    43,
      82,    45,    84,    -1,    86,    -1,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    80,    98,    82,   100,    84,
      -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,    94,
      95,    96,    -1,    98,    -1,   100,    80,    19,    82,    -1,
      84,    -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,
      94,    95,    96,    -1,    98,    -1,   100,    18,    19,    41,
      -1,    43,   127,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      41,    -1,    43,   127,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    80,    43,
      82,    45,    84,    -1,    86,    -1,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    -1,   100,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    80,    98,    82,   100,
      84,    23,    86,    -1,    88,    -1,    90,    91,    -1,    93,
      94,    95,    96,    -1,    98,    -1,   100,    -1,    23,    41,
      -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    41,    -1,    43,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    43,    -1,    45,    80,    -1,
      82,    -1,    84,    -1,    86,    26,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    80,    98,    82,   100,    84,
      41,    86,    43,    88,    45,    90,    91,    -1,    93,    94,
      95,    96,    80,    98,    82,   100,    84,    -1,    86,    26,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    -1,   100,    -1,    41,    -1,    43,    -1,    45,    80,
      -1,    82,    -1,    84,    -1,    86,    26,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    -1,    98,    -1,   100,
      -1,    41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    84,    -1,    86,
      26,    88,    -1,    90,    91,    -1,    93,    94,    95,    96,
      -1,    98,    -1,   100,    -1,    41,    -1,    43,    -1,    45,
      80,    -1,    82,    -1,    84,    29,    86,    -1,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    41,    98,    43,
     100,    45,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    84,    41,
      86,    43,    88,    45,    90,    91,    -1,    93,    94,    95,
      96,    -1,    98,    -1,   100,    -1,    80,    -1,    82,    -1,
      84,    29,    86,    -1,    88,    -1,    90,    91,    -1,    93,
      94,    95,    96,    41,    98,    43,   100,    45,    80,    -1,
      82,    -1,    84,    29,    86,    -1,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    41,    98,    43,   100,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      34,    -1,    80,    -1,    82,    -1,    84,    41,    86,    43,
      88,    45,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    -1,   100,    -1,    80,    -1,    82,    -1,    84,    -1,
      86,    -1,    88,    -1,    90,    91,    34,    93,    94,    95,
      96,    -1,    98,    41,   100,    43,    80,    45,    82,    -1,
      84,    -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,
      94,    95,    96,    35,    98,    37,   100,    -1,    -1,    41,
      -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    37,
      98,    -1,   100,    41,    -1,    43,    -1,    45,    80,    -1,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    38,   100,    40,
      41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    -1,   100,    40,    41,    -1,    43,    -1,    45,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    41,    98,    43,   100,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    -1,    -1,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    90,    91,    -1,    93,    94,    95,    96,
      -1,    98,    -1,   100,    -1,    80,    -1,    82,    -1,    84,
      41,    86,    43,    88,    45,    90,    91,    -1,    93,    94,
      95,    96,    -1,    98,    -1,   100,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    41,    84,    43,    86,    45,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    -1,    98,    -1,   100,
      -1,    60,    61,    -1,    41,    -1,    43,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    -1,    84,    63,    86,    65,    88,
      -1,    90,    91,    -1,    93,    94,    95,    96,    -1,    98,
      41,   100,    43,    80,    45,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    90,    91,    -1,    93,    94,    95,    96,
      -1,    98,    -1,   100,    -1,    66,    67,    41,    -1,    43,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    -1,    84,    41,    86,    43,    88,    45,    90,
      91,    48,    93,    94,    95,    96,    -1,    98,    -1,   100,
      74,    -1,    76,    -1,    -1,    -1,    80,    -1,    82,    -1,
      84,    41,    86,    43,    88,    45,    90,    91,    48,    93,
      94,    95,    96,    80,    98,    82,   100,    84,    41,    86,
      43,    88,    45,    90,    91,    48,    93,    94,    95,    96,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    84,    41,    86,    43,    88,    45,
      90,    91,    48,    93,    94,    95,    96,    80,    98,    82,
     100,    84,    41,    86,    43,    88,    45,    90,    91,    48,
      93,    94,    95,    96,    -1,    98,    -1,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    84,    41,
      86,    43,    88,    45,    90,    91,    48,    93,    94,    95,
      96,    80,    98,    82,   100,    84,    -1,    86,    -1,    88,
      -1,    90,    91,    -1,    93,    94,    95,    96,    -1,    98,
      41,   100,    43,    -1,    45,    -1,    -1,    -1,    80,    -1,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    -1,   100,    41,
      71,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    41,    98,    43,   100,
      45,    73,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    84,    41,    86,    43,    88,    45,    90,    91,
      48,    93,    94,    95,    96,    -1,    98,    -1,   100,    -1,
      -1,    -1,    -1,    -1,    79,    80,    -1,    82,    -1,    84,
      41,    86,    43,    88,    45,    90,    91,    -1,    93,    94,
      95,    96,    80,    98,    82,   100,    84,    41,    86,    43,
      88,    45,    90,    91,    65,    93,    94,    95,    96,    -1,
      98,    55,   100,    -1,    41,    -1,    43,    -1,    45,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,
      91,    58,    93,    94,    95,    96,    80,    98,    82,   100,
      84,    -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,
      94,    95,    96,    80,    98,    82,   100,    84,    41,    86,
      43,    88,    45,    90,    91,    -1,    93,    94,    95,    96,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    61,    -1,
      41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      -1,    84,    -1,    86,    -1,    88,    67,    90,    91,    -1,
      93,    94,    95,    96,    41,    98,    43,   100,    45,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    -1,    98,    -1,   100,
      -1,    41,    -1,    43,    71,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    90,    91,    -1,    93,    94,    95,    96,
      41,    98,    43,   100,    45,    -1,    76,    -1,    -1,    -1,
      80,    -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    -1,    98,    -1,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    -1,    98,    -1,   100
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,   165,   200,     6,     7,     9,    10,    12,
      14,    15,    18,    20,    21,    22,    24,    25,    27,    28,
      30,    32,    33,    35,    36,    38,    39,    46,    47,    49,
      50,    51,    52,    53,    54,    56,    57,    59,    60,    62,
      63,    64,    66,    68,    69,    70,    72,    74,    75,    77,
      78,   101,   103,   105,   107,   119,   120,   122,   123,   125,
     126,   128,   129,   131,   132,   134,   135,   137,   138,   140,
     141,   143,   144,   146,   147,   149,   150,   152,   153,   155,
     156,   158,   159,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   212,   215,   218,
      16,   211,     0,    41,    43,    45,    80,    82,    84,    86,
      88,    90,    91,    93,    94,    95,    96,    98,   100,   166,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     166,   211,   166,   211,   166,   211,   166,   200,   211,    23,
     184,   211,    26,   183,   184,   211,   200,   211,    31,   200,
     211,   200,   211,   200,   211,   200,   211,   200,   200,   200,
     200,   200,   200,   211,   200,   211,   200,   211,   200,   211,
     200,   211,   200,   211,   200,   200,   211,   200,   211,   108,
     213,   121,   211,   124,   211,   200,   211,   200,   211,   200,
     211,   200,   211,   200,   211,   200,   211,   200,   211,   200,
     211,   200,   211,   200,   211,   200,   211,   166,   211,     6,
       7,     9,    10,    12,    14,    15,   158,   159,   167,   200,
     212,    24,    25,    27,    28,    30,    21,    22,   108,   109,
     214,   214,   113,    16,   161,   112,    44,   112,   211,   112,
     112,   112,   112,   112,   112,   112,   211,   211,   112,   112,
     112,   211,   200,   161,   200,   161,   200,   161,   200,    18,
      19,   161,   200,   161,   200,   161,    29,   161,    32,    34,
     161,    35,    37,   161,    38,    40,   161,    48,   161,    48,
      48,    48,    48,    48,    54,    55,   161,    57,    58,   161,
      60,    61,   161,    63,    65,   161,    66,    67,   161,    71,
     161,    73,    74,    76,   161,    79,   161,   162,   161,   161,
     161,   127,   161,   130,   161,   133,   161,   136,   161,   139,
     161,   142,   161,   145,   161,   148,   161,   151,   161,   154,
     161,   157,   161,   200,   161,   166,   211,   166,   211,   166,
     211,   166,   166,   211,     5,   183,   211,   200,   211,    31,
     184,   211,   113,   114,   115,   116,   117,   161,   163,   161,
     112,   113,   166,    42,    44,   161,    81,    83,    85,    87,
      89,    92,    92,   161,   161,    97,    97,    99,   161,     8,
     166,    11,   166,    13,   166,    17,   200,    23,   184,    26,
     183,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   113,   102,   121,   124,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   160,
     166,   200,   161,   200,   161,   200,   161,   200,   200,   161,
     200,   161,    29,   161,   200,   161,   214,   214,   214,   214,
     214,   216,   113,   220,   112,   200,   112,   112,    92,   112,
     112,   200,   200,   200,    19,   200,   200,    29,    34,    37,
      40,    48,    55,    58,    61,    65,    67,    71,    76,    79,
     214,   127,   130,   133,   136,   139,   142,   145,   148,   151,
     154,   157,   200,     8,   166,    11,   166,    13,   166,    17,
     160,   166,    26,   183,   200,    23,   184,   166,   214,   166,
       5,    44,    92,    92,    99,     8,    11,    13,    23,    26,
     160,   200,   200,   200,   200,   200,    29,   200,   104,   217,
     106,   219,     8,    11,    13,   160,    26,    23
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
#line 162 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 166 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 170 "gtkdialog_parser.y"
    { 
    		token_store_attr(PUSH | WIDGET_WINDOW, (yyvsp[(2) - (6)].nvval)); 
		start_up();
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 180 "gtkdialog_parser.y"
    { 
		token_store(SUM);      
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 185 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
	}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 188 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
		token_store(SUM);      
	}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 192 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(2) - (6)].nvval)); 
	}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 195 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(3) - (7)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 199 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
	}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 202 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
		token_store(SUM);      
	}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 206 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(2) - (6)].nvval)); 
	}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 209 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(3) - (7)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 213 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_EVENTBOX); 
	}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 216 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_EVENTBOX); 
		token_store(SUM);      
	}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 220 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_EVENTBOX, (yyvsp[(2) - (6)].nvval)); 
	}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 223 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_EVENTBOX, (yyvsp[(3) - (7)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 227 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
	}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 230 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
		token_store(SUM);      
	}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 234 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 237 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);      
	}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 241 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(1) - (4)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
	}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 245 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(2) - (5)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
		token_store(SUM);      
	}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 284 "gtkdialog_parser.y"
    {
                          token_store(PUSH | WIDGET_ENTRY); 
			 }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 287 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_ENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 290 "gtkdialog_parser.y"
    {
                  yyerror("</entry> expected instead of <entry>.");}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 295 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_EDIT); 
	}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 298 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_EDIT, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 301 "gtkdialog_parser.y"
    {
    		yyerror("</edit> expected instead of <edit>.");
	}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 307 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TREE); 
	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 310 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_TREE, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 313 "gtkdialog_parser.y"
    {
   		yyerror("</tree> expected instead of <tree>.");
	}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 319 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHOOSER); 
	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 322 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_CHOOSER, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 325 "gtkdialog_parser.y"
    {
		yyerror("</chooser> expected instead of <chooser>.");
	}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 331 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TEXT); 
	}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 334 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_TEXT, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 337 "gtkdialog_parser.y"
    {yyerror("</text> expected instead of <text>.");}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 341 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_BUTTON);  }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 342 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_BUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 345 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_OKBUTTON);}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 346 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_CANCELBUTTON);}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 347 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_HELPBUTTON);}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 348 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_NOBUTTON);}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 349 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_YESBUTTON);}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 353 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHECKBOX);
	}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 356 "gtkdialog_parser.y"
    {
		//token_store_with_tag_attributes(PUSH | WIDGET_CHECKBOX, $2);
                token_store_attr(PUSH | WIDGET_CHECKBOX, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 360 "gtkdialog_parser.y"
    {
		yyerror("</checkbox> expected instead of <checkbox>.");
	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 366 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_RADIOBUTTON);
           }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 369 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_RADIOBUTTON, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 372 "gtkdialog_parser.y"
    {
		yyerror("</radiobutton> expected instead of <radiobutton>.");
           }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 378 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_PROGRESS);
           }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 381 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_PROGRESS, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 384 "gtkdialog_parser.y"
    {
		yyerror("</progressbar> expected instead of <progressbar>.");
           }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 390 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_LIST); 
	}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 393 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_LIST, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 396 "gtkdialog_parser.y"
    {
    		yyerror("</list> expected instead of <list>.");
	}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 402 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TABLE); 
	}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 405 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TABLE, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 408 "gtkdialog_parser.y"
    {
    		yyerror("</table> expected instead of <table>.");
	}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 414 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_COMBO);
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 417 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_COMBO, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 423 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_GVIM);}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 427 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_PIXMAP);}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 428 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_PIXMAP, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 441 "gtkdialog_parser.y"
    {
		yyerror("The menubar widget requires at least one menu widget.");
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 444 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUBAR);
	}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 447 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUBAR);
		token_store(SUM);
	}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 451 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUBAR, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 454 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUBAR, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);
	}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 467 "gtkdialog_parser.y"
    {
		yyerror("The menu widget requires at least one menuitem widget.");
	}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 470 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENU);
	}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 473 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENU);
		token_store(SUM);
	}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 477 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENU, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 480 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENU, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);
	}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 487 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM);
	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 490 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM);
		token_store(SUM);
	}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 494 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 497 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(3) - (6)].nvval));
		token_store(SUM);
	}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 504 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEMSEPARATOR);
	}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 507 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEMSEPARATOR);
		token_store(SUM);
	}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 514 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSEPARATOR);
	}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 517 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 523 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSEPARATOR);
	}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 526 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 532 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXTEXT);
	}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 535 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXTEXT, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 541 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXENTRY);
	}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 544 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 550 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSCALE);
	}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 553 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSCALE, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 559 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSCALE);
	}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 562 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSCALE, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 568 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_SPINBUTTON);
	}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 571 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_SPINBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 577 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TIMER);
	}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 580 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TIMER, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 586 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TOGGLEBUTTON);
	}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 589 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TOGGLEBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 595 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_STATUSBAR);
	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 598 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_STATUSBAR, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 604 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COLORBUTTON);
	}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 607 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COLORBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 613 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_FONTBUTTON);
	}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 616 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_FONTBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 622 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TERMINAL);
	}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 625 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TERMINAL, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 645 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_LABEL, (yyvsp[(2) - (3)].cval));     }
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 650 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_VARIABLE, (yyvsp[(2) - (3)].cval)); }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 655 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_SENSITIVE, (yyvsp[(2) - (3)].cval));  }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 660 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_DEFAULT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 665 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_WIDTH, (yyvsp[(2) - (3)].cval));    }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 670 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_HEIGHT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 675 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_SHELL,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 678 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 681 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 684 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 687 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, "", (yyvsp[(2) - (4)].nvval)); 
	}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 693 "gtkdialog_parser.y"
    {
	         fprintf( stderr, "<output>: Not implemented.\n" ); 
	}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 696 "gtkdialog_parser.y"
    {
         	token_store_with_argument(SET|ATTR_OUTPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 702 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET|ATTR_ACTION, (yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 705 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET | ATTR_ACTION, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 712 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET | ATTR_ITEM, (yyvsp[(2) - (3)].cval));
	}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 715 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_ITEM, "");
    	}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 718 "gtkdialog_parser.y"
    {
		      token_store_with_argument_attr(SET | ATTR_ITEM, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
                    }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 724 "gtkdialog_parser.y"
    {
       		(yyval.nvval) = new_tag_attributeset((yyvsp[(1) - (3)].cval), (yyvsp[(3) - (3)].cval)); 
	}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 727 "gtkdialog_parser.y"
    { 
       		(yyval.nvval) = add_tag_attribute((yyvsp[(1) - (4)].nvval), (yyvsp[(2) - (4)].cval), (yyvsp[(4) - (4)].cval)); 
	}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 734 "gtkdialog_parser.y"
    { 
		token_store(SHOW);     
	}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 737 "gtkdialog_parser.y"
    {
  		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
	}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 740 "gtkdialog_parser.y"
    {
		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
		instruction_set_jump((yyvsp[(6) - (6)].ival) + 1, (yyvsp[(1) - (6)].ival));
	}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 747 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMASSG | VARIABLE_NAME, (yyvsp[(1) - (4)].cval)); 
	}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 753 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | VARIABLE_NAME, (yyvsp[(1) - (1)].cval)); 
	}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 756 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | CONST_NUMBER, (yyvsp[(1) - (1)].cval)); 
  	}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 759 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_ADD);
	}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 762 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_SUBST);
	}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 765 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_MULT);
	}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 768 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_DIV);
	}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 771 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_EQ);
	}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 774 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_NE);
	}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 784 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 791 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 795 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 799 "gtkdialog_parser.y"
    {
		token_store(GOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 806 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
    }
    break;



/* Line 1455 of yacc.c  */
#line 4117 "gtkdialog_parser.c"
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
#line 812 "gtkdialog_parser.y"


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


