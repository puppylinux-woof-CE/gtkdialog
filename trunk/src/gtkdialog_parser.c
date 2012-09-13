
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
     EEVENTBOX = 410,
     EXPANDER = 411,
     PART_EXPANDER = 412,
     EEXPANDER = 413
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
#define EXPANDER 411
#define PART_EXPANDER 412
#define EEXPANDER 413




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
#line 521 "gtkdialog_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 533 "gtkdialog_parser.c"

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
#define YYFINAL  124
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3948

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  167
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  195
/* YYNRULES -- Number of states.  */
#define YYNSTATES  568

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   413

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   166,     2,     2,     2,     2,     2,     2,
       2,     2,   116,   115,     2,   114,     2,   117,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   165,     2,
       2,   113,   164,     2,     2,     2,     2,     2,     2,     2,
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
     160,   161,   162,   163
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
     681,   685,   689,   693,   697,   703,   707,   713,   718,   722,
     726,   730,   736,   740,   743,   749,   753,   758,   763,   765,
     772,   779,   784,   786,   788,   792,   796,   800,   804,   808,
     813,   815,   816,   818,   820,   822
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     168,     0,    -1,   203,   169,    -1,     3,   169,   203,     5,
      -1,     4,   214,   164,   169,   203,     5,    -1,   170,    -1,
     169,   170,    -1,   215,    -1,   169,   215,    -1,     6,   169,
     203,     8,    -1,   169,     6,   169,   203,     8,    -1,     7,
     214,   164,   169,   203,     8,    -1,   169,     7,   214,   164,
     169,   203,     8,    -1,     9,   169,   203,    11,    -1,   169,
       9,   169,   203,    11,    -1,    10,   214,   164,   169,   203,
      11,    -1,   169,    10,   214,   164,   169,   203,    11,    -1,
     158,   169,   203,   160,    -1,   169,   158,   169,   203,   160,
      -1,   159,   214,   164,   169,   203,   160,    -1,   169,   159,
     214,   164,   169,   203,   160,    -1,   161,   169,   203,   163,
      -1,   169,   161,   169,   203,   163,    -1,   162,   214,   164,
     169,   203,   163,    -1,   169,   162,   214,   164,   169,   203,
     163,    -1,    12,   169,   203,    13,    -1,   169,    12,   169,
     203,    13,    -1,    14,   214,   164,   169,   203,    13,    -1,
     169,    14,   214,   164,   169,   203,    13,    -1,    15,   169,
     203,    17,    -1,   169,    15,   169,   203,    17,    -1,   175,
      -1,   171,    -1,   172,    -1,   173,    -1,   174,    -1,   176,
      -1,   177,    -1,   178,    -1,   179,    -1,   180,    -1,   181,
      -1,   182,    -1,   184,    -1,   183,    -1,   185,    -1,   190,
      -1,   191,    -1,   192,    -1,   193,    -1,   194,    -1,   195,
      -1,   196,    -1,   197,    -1,   198,    -1,   199,    -1,   200,
      -1,   201,    -1,   202,    -1,    18,   203,    19,    -1,    20,
     214,   164,   203,    19,    -1,    18,   203,    18,    -1,    32,
     203,    34,    -1,    33,   214,   164,   203,    34,    -1,    32,
     203,    32,    -1,    35,   203,    37,    -1,    36,   214,   164,
     203,    37,    -1,    35,   203,    35,    -1,    38,   203,    40,
      -1,    39,   214,   164,   203,    40,    -1,    38,   203,    38,
      -1,    74,   203,    76,    -1,    75,   214,   164,   203,    76,
      -1,    74,   203,    74,    -1,    46,   203,    48,    -1,    47,
     214,   164,   203,    48,    -1,    49,   203,    48,    -1,    50,
     203,    48,    -1,    51,   203,    48,    -1,    53,   203,    48,
      -1,    52,   203,    48,    -1,    54,   203,    55,    -1,    56,
     214,   164,   203,    55,    -1,    54,   203,    54,    -1,    57,
     203,    58,    -1,    59,   214,   164,   203,    58,    -1,    57,
     203,    57,    -1,    60,   203,    61,    -1,    62,   214,   164,
     203,    61,    -1,    60,   203,    60,    -1,    63,   203,    65,
      -1,    64,   214,   164,   203,    65,    -1,    63,   203,    63,
      -1,    66,   203,    67,    -1,    68,   214,   164,   203,    67,
      -1,    66,   203,    66,    -1,    69,   203,    71,    -1,    70,
     214,   164,   203,    71,    -1,    72,   203,    73,    -1,    77,
     203,    79,    -1,    78,   214,   164,   203,    79,    -1,    21,
      23,    -1,    21,   187,   203,    23,    -1,   187,    21,   187,
     203,    23,    -1,    22,   214,   164,   187,   203,    23,    -1,
     187,    22,   214,   164,   187,   203,    23,    -1,   187,    -1,
     188,    -1,   189,    -1,    24,    26,    -1,    24,   186,   203,
      26,    -1,   186,    24,   186,   203,    26,    -1,    25,   214,
     164,   186,   203,    26,    -1,   186,    25,   214,   164,   186,
     203,    26,    -1,    27,   203,    29,    -1,   186,    27,   203,
      29,    -1,    28,   214,   164,   203,    29,    -1,   186,    28,
     214,   164,   203,    29,    -1,    30,    31,    -1,   186,    30,
      31,    -1,   119,   121,    -1,   120,   214,   164,   121,    -1,
     122,   124,    -1,   123,   214,   164,   124,    -1,   125,   203,
     127,    -1,   126,   214,   164,   203,   127,    -1,   128,   203,
     130,    -1,   129,   214,   164,   203,   130,    -1,   131,   203,
     133,    -1,   132,   214,   164,   203,   133,    -1,   134,   203,
     136,    -1,   135,   214,   164,   203,   136,    -1,   137,   203,
     139,    -1,   138,   214,   164,   203,   139,    -1,   140,   203,
     142,    -1,   141,   214,   164,   203,   142,    -1,   143,   203,
     145,    -1,   144,   214,   164,   203,   145,    -1,   146,   203,
     148,    -1,   147,   214,   164,   203,   148,    -1,   149,   203,
     151,    -1,   150,   214,   164,   203,   151,    -1,   152,   203,
     154,    -1,   153,   214,   164,   203,   154,    -1,   155,   203,
     157,    -1,   156,   214,   164,   203,   157,    -1,    -1,   203,
     207,    -1,   203,   206,    -1,   203,   205,    -1,   203,   204,
      -1,   203,   208,    -1,   203,   209,    -1,   203,   210,    -1,
     203,   211,    -1,   203,   212,    -1,   203,   213,    -1,    41,
     112,    42,    -1,    84,   112,    85,    -1,    82,   112,    83,
      -1,    80,   112,    81,    -1,    86,   112,    87,    -1,    88,
     112,    89,    -1,    90,   112,    92,    -1,    93,   214,   164,
     112,    92,    -1,    91,   112,    92,    -1,    94,   214,   164,
     112,    92,    -1,    94,   214,   164,    92,    -1,    95,   112,
      97,    -1,    96,   112,    97,    -1,    98,   112,    99,    -1,
     100,   214,   164,   112,    99,    -1,    43,   112,    44,    -1,
      43,    44,    -1,    45,   214,   164,   112,    44,    -1,    16,
     113,   112,    -1,   214,    16,   113,   112,    -1,   101,   216,
     164,   102,    -1,   107,    -1,   218,   217,   164,   219,   169,
     220,    -1,   221,   217,   164,   223,   169,   222,    -1,   108,
     165,   113,   217,    -1,   108,    -1,   109,    -1,   217,   115,
     217,    -1,   217,   114,   217,    -1,   217,   116,   217,    -1,
     217,   117,   217,    -1,   217,   113,   217,    -1,   217,   166,
     113,   217,    -1,   103,    -1,    -1,   104,    -1,   105,    -1,
     106,    -1,    -1
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
     675,   680,   685,   690,   693,   696,   699,   702,   708,   711,
     717,   720,   727,   730,   733,   739,   742,   748,   749,   752,
     755,   762,   768,   771,   774,   777,   780,   783,   786,   789,
     795,   799,   806,   810,   814,   821
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
  "PART_EVENTBOX", "EEVENTBOX", "EXPANDER", "PART_EXPANDER", "EEXPANDER",
  "'>'", "':'", "'!'", "$accept", "window", "wlist", "widget", "entry",
  "edit", "tree", "chooser", "text", "button", "checkbox", "radiobutton",
  "progressbar", "list", "table", "combo", "gvim", "pixmap", "menubar",
  "menuwlist", "menu", "menuitem", "menuitemseparator", "hseparator",
  "vseparator", "comboboxtext", "comboboxentry", "hscale", "vscale",
  "spinbutton", "timer", "togglebutton", "statusbar", "colorbutton",
  "fontbutton", "terminal", "attr", "label", "variable", "sensitive",
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
     365,   366,   367,    61,    45,    43,    42,    47,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,    62,    58,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   167,   168,   168,   168,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   171,
     171,   171,   172,   172,   172,   173,   173,   173,   174,   174,
     174,   175,   175,   175,   176,   176,   176,   176,   176,   176,
     176,   177,   177,   177,   178,   178,   178,   179,   179,   179,
     180,   180,   180,   181,   181,   181,   182,   182,   183,   184,
     184,   185,   185,   185,   185,   185,   186,   186,   186,   187,
     187,   187,   187,   187,   188,   188,   188,   188,   189,   189,
     190,   190,   191,   191,   192,   192,   193,   193,   194,   194,
     195,   195,   196,   196,   197,   197,   198,   198,   199,   199,
     200,   200,   201,   201,   202,   202,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   204,   205,   206,
     207,   208,   209,   210,   210,   210,   210,   210,   211,   211,
     212,   212,   213,   213,   213,   214,   214,   215,   215,   215,
     215,   216,   217,   217,   217,   217,   217,   217,   217,   217,
     218,   219,   220,   221,   222,   223
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
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,     0,     0,     0,     0,     0,   146,     0,
       0,   146,     0,   146,     0,   146,     0,   146,     0,   146,
     146,   146,   146,   146,   146,     0,   146,     0,   146,     0,
     146,     0,   146,     0,   146,     0,   146,   146,     0,   146,
       0,     0,   190,   193,   178,     0,     0,     0,     0,   146,
       0,   146,     0,   146,     0,   146,     0,   146,     0,   146,
       0,   146,     0,   146,     0,   146,     0,   146,     0,   146,
       0,     0,     0,     0,     0,   146,     5,    32,    33,    34,
      35,    31,    36,    37,    38,    39,    40,    41,    42,    44,
      43,    45,     0,   106,   107,   108,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,     7,
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,   150,   149,   148,   147,   151,   152,   153,   154,
     155,   156,   146,     0,   146,     0,   146,     0,   146,     0,
       0,   101,   146,     0,   109,   146,   106,     0,     0,     0,
     118,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   120,     0,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
       0,   146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,     8,     0,     0,   146,
       0,     0,     0,     0,   182,   183,     0,     0,     0,     0,
       0,     0,   173,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,    59,   146,     0,     0,
       0,     0,   114,   146,    64,    62,   146,    67,    65,   146,
      70,    68,   146,    74,   146,    76,    77,    78,    80,    79,
      83,    81,   146,    86,    84,   146,    89,    87,   146,    92,
      90,   146,    95,    93,   146,    96,   146,    98,    73,    71,
     146,    99,   146,     0,     0,     0,     0,   124,   146,   126,
     146,   128,   146,   130,   146,   132,   146,   134,   146,   136,
     146,   138,   146,   140,   146,   142,   146,   144,   146,     0,
       0,     0,     0,   146,     0,   146,     0,   146,     0,   146,
     146,     0,   146,     0,     3,   146,     0,     0,     0,   119,
     146,     0,     0,     0,     0,     0,     0,   191,     0,   195,
     175,     0,   146,   157,   172,     0,   160,   159,   158,   161,
     162,   163,   165,     0,     0,   168,   169,   170,     0,     9,
     146,    13,   146,    25,   146,    29,     0,   102,   146,   110,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   121,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
     146,    21,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,   146,     0,     0,
     188,   185,   184,   186,   187,     0,     0,     0,   176,     0,
       0,     0,   167,     0,     0,     0,     0,     0,    60,     0,
       0,   116,    63,    66,    69,    75,    82,    85,    88,    91,
      94,    97,    72,   100,   181,   125,   127,   129,   131,   133,
     135,   137,   139,   141,   143,   145,     0,     0,    10,   146,
      14,   146,    26,   146,    30,    18,   146,    22,   146,   111,
     146,     0,   103,   146,     0,   189,     0,     4,   174,   164,
     166,   171,    11,    15,    27,   104,   112,    19,    23,     0,
       0,     0,     0,     0,     0,   117,     0,   192,   179,   194,
     180,    12,    16,    28,    20,    24,   113,   105
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,     4,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   123,   119,   202,
     256,   120,   475,   558,   121,   560,   477
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -118
static const yytype_int16 yypact[] =
{
     103,  1374,   -11,    31,   903,  1374,   -11,  1374,   -11,  1374,
     -11,  1374,  -118,   -11,    75,   -11,   233,   -11,  -118,   -11,
       2,  -118,   -11,  -118,   -11,  -118,   -11,  -118,   -11,  -118,
    -118,  -118,  -118,  -118,  -118,   -11,  -118,   -11,  -118,   -11,
    -118,   -11,  -118,   -11,  -118,   -11,  -118,  -118,   -11,  -118,
     -11,   -67,  -118,  -118,  -118,   -78,   -11,   -79,   -11,  -118,
     -11,  -118,   -11,  -118,   -11,  -118,   -11,  -118,   -11,  -118,
     -11,  -118,   -11,  -118,   -11,  -118,   -11,  -118,   -11,  -118,
     -11,  1374,   -11,  1374,   -11,  1531,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,   124,    87,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
       3,     3,   -42,    -9,  -118,   -21,   -15,   -11,   -16,     1,
       4,     6,     8,    27,    29,   -11,   -11,    33,    35,    45,
     -11,  1531,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  1531,    -8,  1531,    -6,  1531,    -4,  1531,  2665,
      -2,  -118,   255,     0,  -118,   124,  -118,     7,  2945,     9,
    -118,  3045,    11,  3107,    20,  3168,    22,  3412,    23,  3439,
    3456,  3483,  3500,  3527,  3224,    24,  3268,    26,  3310,    28,
    3332,    30,  3368,    32,  3558,    34,  3587,  3395,    36,  3614,
      38,   -64,   -60,  -118,    40,  -118,    42,  2582,    44,  2357,
      46,  2190,    48,  2088,    50,  2015,    52,  1937,    54,  1899,
      56,  1838,    58,  1776,    59,  1714,    60,  1670,    61,  1531,
      62,  1531,    63,  1374,   -11,  1374,   -11,  1374,   -11,  1374,
    1374,   -11,  1374,   -11,  -118,  2112,  -118,   280,   -11,  -118,
     -11,    91,   280,   -11,  -118,  -118,    10,    16,    47,    15,
    1374,    92,  -118,    93,    64,    55,    80,    53,    81,    83,
      51,    69,    65,    66,    70,    73,    86,    67,  2212,  1374,
    2374,  1374,  2502,  1374,  1059,  -118,  -118,  -118,  2705,   280,
    2828,   280,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,    82,    95,    57,    41,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,   670,
    1374,   440,  1374,  1531,    68,  1531,    71,  1531,    72,  1531,
    1531,    74,  1531,    76,  -118,   124,    77,  2967,    78,  -118,
     255,    79,     3,     3,     3,     3,     3,  -118,    88,  -118,
    -118,    97,  1531,  -118,  -118,    99,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,   101,   -23,  -118,  -118,  -118,   109,  -118,
    1531,  -118,  1531,  -118,  1531,  -118,  2688,  -118,   255,  -118,
     124,  3001,  3081,  3141,  3202,  3631,  3675,  3692,  3736,  3658,
    3758,  3792,  3819,  3848,     3,  -118,  -118,  -118,  2605,  2395,
    2234,  2146,  2032,  1998,  1916,  1876,  1814,  1752,  1687,  -118,
    1531,  -118,  1531,  2296,  1374,  2418,  1374,  2521,  1374,  1216,
     731,  1374,   500,  1374,  2862,   280,  -118,  -118,  2767,   280,
     135,   -31,   -31,    37,    37,  1374,     3,  1374,  -118,  2168,
     125,   107,  -118,   113,    90,  2313,  2460,  2544,  -118,  2784,
    2889,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,   131,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,   759,   522,  -118,  1531,
    -118,  1531,  -118,  1531,  -118,  -118,  1531,  -118,  1531,  -118,
     124,  3023,  -118,   255,  1060,   135,  1217,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  2330,
    2481,  2565,  1653,   653,  2923,  -118,  2801,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,  -118,   110,    25,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,   -14,
     -13,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,   -12,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,   658,   269,  -118,
    -117,  -118,  -118,  -118,  -118,  -118,  -118
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -107
static const yytype_int16 yytable[] =
{
     159,   162,   165,   166,   257,   122,   168,   259,   259,   171,
     259,   173,   259,   175,   259,   177,   259,   179,   180,   181,
     182,   183,   184,   259,   186,   259,   188,   259,   190,   262,
     192,   124,   194,   170,   196,   197,   259,   199,   259,   259,
     259,   201,   259,   203,   259,   205,   259,   207,   259,   209,
     259,   211,   259,   213,   259,   215,   259,   217,   259,   219,
     259,   221,   259,   223,   259,   225,   259,   227,   259,   482,
     259,   258,   259,   245,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   385,   386,   259,   259,   483,
     259,   261,   259,   259,   259,   259,   265,   263,   161,    16,
      17,   333,    18,    19,   334,    20,     1,     2,   252,   253,
     244,   254,   255,   266,   141,   152,   267,   154,   268,   156,
     269,   158,   379,   382,   383,   384,   385,   386,   391,   382,
     383,   384,   385,   386,   393,   388,   396,   394,   398,   270,
     278,   271,   280,   401,   282,   274,   284,   275,   247,   248,
     288,   249,   250,   290,   251,   260,   279,   276,   281,   390,
     283,   402,   287,   397,   289,   437,   244,   405,   399,   538,
     406,   291,   400,   293,   387,   296,   388,   244,   436,   244,
     389,   244,   388,   244,   299,   407,   302,   304,   312,   541,
     315,   229,   318,   231,   321,   434,   324,   435,   326,   539,
     330,   476,   332,   388,   335,   540,   336,     0,   338,   478,
     340,   480,   342,   481,   344,     0,   346,   359,   348,   361,
     350,   484,   352,   354,   356,   358,   360,   362,   395,   403,
     404,   408,   454,   375,   166,   456,   458,   377,   461,   380,
     463,   465,   467,   469,   382,   383,   384,   385,   386,   383,
     384,   385,   386,     0,   244,     0,   244,    16,    17,   164,
      18,    19,     0,    20,     0,   470,   471,   472,   473,   474,
       0,     0,     0,     0,     0,   416,   418,   420,   166,  -106,
    -106,   421,  -106,  -106,   422,  -106,     0,   423,     0,     0,
     424,     0,   425,     0,     0,     0,     0,   388,     0,     0,
     426,   388,     0,   427,    16,    17,   428,    18,    19,   429,
      20,     0,   430,     0,   431,     0,     0,   504,   432,     0,
     433,     0,     0,     0,     0,     0,   438,     0,   439,     0,
     440,     0,   441,     0,   442,     0,   443,     0,   444,     0,
     445,     0,   446,   363,   447,   365,   448,   367,     0,   369,
     370,   453,   372,   455,   246,   457,     0,   459,   460,   535,
     462,     0,     0,   464,     0,     0,     0,     0,   468,     0,
     392,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     479,     0,     0,     0,     0,     0,     0,     0,   244,   410,
     244,   412,   244,   414,   244,   244,     0,   244,   485,     0,
     486,     0,   487,     0,     0,     0,   489,     0,   490,     0,
     246,     0,     0,     0,     0,     0,     0,   244,     0,     0,
       0,   246,     0,   246,     0,   246,     0,   246,     0,     0,
       0,     0,     0,     0,     0,   244,     0,   244,   516,   244,
     517,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   530,   166,     0,     0,   531,   533,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     450,     0,   452,     0,     0,   244,     0,   244,     0,     0,
       0,   125,     0,   126,     0,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   246,     0,
     246,     0,     0,     0,     0,     0,     0,   549,     0,   550,
       0,   551,     0,     0,   552,     0,   553,     0,   554,     0,
     128,   556,   129,     0,   130,     0,   131,     0,   132,     0,
     133,   134,     0,   135,   136,   137,   138,     0,   139,     0,
     140,   125,     0,   126,   244,   127,   244,     0,   244,     0,
       0,   244,     0,   244,     0,     0,     0,     0,     0,   244,
       0,   244,     0,   125,   519,   126,   521,   127,   523,     0,
       0,   526,     0,   528,     0,     0,     0,     0,     0,     0,
     128,     0,   129,     0,   130,   534,   131,   536,   132,     0,
     133,   134,     0,   135,   136,   137,   138,     0,   139,     0,
     140,     0,   128,   451,   129,     0,   130,     0,   131,     0,
     132,     0,   133,   134,     0,   135,   136,   137,   138,     0,
     139,     0,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   246,     0,   246,     0,   246,     0,   246,   246,
       0,   246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   246,     0,   527,   153,     0,   155,     0,   157,     0,
       0,   160,     0,   163,     0,   167,     0,   169,     0,   246,
     172,   246,   174,   246,   176,   548,   178,     0,     0,     0,
       0,     0,     0,   185,   125,   187,   126,   189,   127,   191,
       0,   193,     0,   195,     0,     0,   198,     0,   200,     0,
       0,   125,     0,   126,   204,   127,   206,     0,   208,   246,
     210,   246,   212,     0,   214,     0,   216,     0,   218,     0,
     220,     0,   222,   128,   224,   129,   226,   130,   228,   131,
     230,   132,   232,   133,   134,     0,   135,   136,   137,   138,
     128,   139,   129,   140,   130,     0,   131,     0,   132,     0,
     133,   134,     0,   135,   136,   137,   138,     0,   139,     0,
     140,     0,   125,     0,   126,     0,   127,     0,     0,     0,
       0,     0,     0,     0,     0,   264,     0,     0,   246,     0,
     246,     0,   246,   272,   273,   246,     0,   246,   277,     0,
     125,     0,   126,   246,   127,   246,     0,     0,     0,     0,
       0,   128,     0,   129,     0,   130,   565,   131,     0,   132,
       0,   133,   134,     0,   135,   136,   137,   138,     0,   139,
     449,   140,     0,     0,     0,     0,     0,     0,     0,   128,
       0,   129,     0,   130,     0,   131,     0,   132,     0,   133,
     134,     0,   135,   136,   137,   138,     0,   139,     0,   140,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   525,   364,     0,   366,     0,   368,     0,     0,   371,
       0,   373,     0,     0,     0,     0,   376,     0,   378,     5,
       6,   381,     7,     8,     0,     9,     0,    10,    11,   547,
       0,    12,     0,    13,    14,    15,     0,    16,    17,     0,
      18,    19,     0,    20,     0,    21,    22,     0,    23,    24,
       0,    25,    26,     0,   125,     0,   126,     0,   127,    27,
      28,     0,    29,    30,    31,    32,    33,    34,     0,    35,
      36,     0,    37,    38,     0,    39,    40,    41,     0,    42,
       0,    43,    44,    45,     0,    46,     0,    47,    48,     0,
      49,    50,     0,   128,     0,   129,     0,   130,     0,   131,
       0,   132,     0,   133,   134,     0,   135,   136,   137,   138,
       0,   139,     0,   140,    51,     0,    52,     0,    53,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    56,     0,    57,    58,     0,    59,    60,
       0,    61,    62,     0,    63,    64,     0,    65,    66,     0,
      67,    68,     0,    69,    70,     0,    71,    72,     0,    73,
      74,     0,    75,    76,     0,    77,    78,     0,    79,    80,
       0,    81,    82,     0,    83,    84,   233,   234,     0,   235,
     236,     0,   237,     0,   238,   239,   415,     0,    12,     0,
      13,    14,    15,     0,    16,    17,     0,    18,    19,     0,
      20,     0,    21,    22,     0,    23,    24,     0,    25,    26,
     125,     0,   126,     0,   127,     0,    27,    28,     0,    29,
      30,    31,    32,    33,    34,     0,    35,    36,     0,    37,
      38,     0,    39,    40,    41,     0,    42,     0,    43,    44,
      45,     0,    46,     0,    47,    48,     0,    49,    50,   128,
       0,   129,     0,   130,     0,   131,     0,   132,     0,   133,
     134,     0,   135,   136,   137,   138,     0,   139,     0,   140,
       0,    51,     0,    52,   557,    53,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      56,     0,    57,    58,     0,    59,    60,     0,    61,    62,
       0,    63,    64,     0,    65,    66,     0,    67,    68,     0,
      69,    70,     0,    71,    72,     0,    73,    74,     0,    75,
      76,     0,    77,    78,     0,    79,    80,     0,   240,   241,
       0,   242,   243,   233,   234,     0,   235,   236,     0,   237,
       0,   238,   239,   524,     0,    12,     0,    13,    14,    15,
       0,    16,    17,     0,    18,    19,     0,    20,     0,    21,
      22,     0,    23,    24,     0,    25,    26,   125,     0,   126,
       0,   127,     0,    27,    28,     0,    29,    30,    31,    32,
      33,    34,     0,    35,    36,     0,    37,    38,     0,    39,
      40,    41,     0,    42,     0,    43,    44,    45,     0,    46,
       0,    47,    48,     0,    49,    50,   128,     0,   129,     0,
     130,     0,   131,     0,   132,     0,   133,   134,     0,   135,
     136,   137,   138,     0,   139,     0,   140,     0,    51,     0,
      52,     0,    53,   559,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,    56,     0,    57,
      58,     0,    59,    60,     0,    61,    62,     0,    63,    64,
       0,    65,    66,     0,    67,    68,     0,    69,    70,     0,
      71,    72,     0,    73,    74,     0,    75,    76,     0,    77,
      78,     0,    79,    80,     0,   240,   241,     0,   242,   243,
       5,     6,     0,     7,     8,     0,     9,     0,    10,    11,
       0,     0,    12,     0,    13,    14,    15,     0,    16,    17,
       0,    18,    19,     0,    20,     0,    21,    22,     0,    23,
      24,     0,    25,    26,     0,     0,     0,     0,     0,     0,
      27,    28,     0,    29,    30,    31,    32,    33,    34,     0,
      35,    36,     0,    37,    38,     0,    39,    40,    41,     0,
      42,     0,    43,    44,    45,     0,    46,     0,    47,    48,
       0,    49,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,    52,     0,    53,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,     0,    57,    58,     0,    59,
      60,     0,    61,    62,     0,    63,    64,     0,    65,    66,
       0,    67,    68,     0,    69,    70,     0,    71,    72,     0,
      73,    74,     0,    75,    76,     0,    77,    78,     0,    79,
      80,     0,    81,    82,     0,    83,    84,   233,   234,     0,
     235,   236,     0,   237,     0,   238,   239,     0,     0,    12,
       0,    13,    14,    15,     0,    16,    17,     0,    18,    19,
       0,    20,     0,    21,    22,     0,    23,    24,     0,    25,
      26,     0,     0,     0,     0,     0,     0,    27,    28,     0,
      29,    30,    31,    32,    33,    34,     0,    35,    36,     0,
      37,    38,     0,    39,    40,    41,     0,    42,     0,    43,
      44,    45,     0,    46,     0,    47,    48,     0,    49,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,    52,     0,    53,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    56,     0,    57,    58,     0,    59,    60,     0,    61,
      62,     0,    63,    64,     0,    65,    66,     0,    67,    68,
       0,    69,    70,     0,    71,    72,     0,    73,    74,     0,
      75,    76,     0,    77,    78,     0,    79,    80,     0,   240,
     241,     0,   242,   243,   125,     0,   126,     0,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,     0,   126,     0,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   125,     0,
     126,     0,   127,   128,     0,   129,     0,   130,     0,   131,
       0,   132,     0,   133,   134,     0,   135,   136,   137,   138,
     128,   139,   129,   140,   130,   125,   131,   126,   132,   127,
     133,   134,     0,   135,   136,   137,   138,   128,   139,   129,
     140,   130,     0,   131,     0,   132,     0,   133,   134,     0,
     135,   136,   137,   138,     0,   139,     0,   140,     0,     0,
       0,     0,     0,   125,   128,   126,   129,   127,   130,     0,
     131,     0,   132,     0,   133,   134,     0,   135,   136,   137,
     138,     0,   139,   564,   140,     0,     0,   125,     0,   126,
       0,   127,     0,     0,     0,     0,     0,   357,     0,     0,
       0,     0,   128,     0,   129,     0,   130,     0,   131,     0,
     132,     0,   133,   134,   515,   135,   136,   137,   138,     0,
     139,     0,   140,     0,     0,   125,   128,   126,   129,   127,
     130,     0,   131,     0,   132,     0,   133,   134,   355,   135,
     136,   137,   138,     0,   139,     0,   140,     0,     0,   125,
       0,   126,     0,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,     0,   129,     0,   130,     0,
     131,     0,   132,     0,   133,   134,   514,   135,   136,   137,
     138,     0,   139,     0,   140,     0,     0,   125,   128,   126,
     129,   127,   130,     0,   131,     0,   132,   353,   133,   134,
       0,   135,   136,   137,   138,     0,   139,     0,   140,     0,
     125,     0,   126,     0,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,   125,   129,   126,
     130,   127,   131,     0,   132,   513,   133,   134,     0,   135,
     136,   137,   138,     0,   139,     0,   140,     0,   125,   128,
     126,   129,   127,   130,     0,   131,   351,   132,     0,   133,
     134,     0,   135,   136,   137,   138,   128,   139,   129,   140,
     130,     0,   131,     0,   132,     0,   133,   134,     0,   135,
     136,   137,   138,     0,   139,     0,   140,   128,     0,   129,
       0,   130,     0,   131,   512,   132,     0,   133,   134,     0,
     135,   136,   137,   138,     0,   139,     0,   140,     0,   125,
       0,   126,     0,   127,   349,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,     0,   126,     0,
     127,   511,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,   126,     0,   127,   128,   347,
     129,     0,   130,     0,   131,     0,   132,     0,   133,   134,
       0,   135,   136,   137,   138,   128,   139,   129,   140,   130,
       0,   131,     0,   132,     0,   133,   134,     0,   135,   136,
     137,   138,   128,   139,   129,   140,   130,   374,   131,     0,
     132,     0,   133,   134,     0,   135,   136,   137,   138,   125,
     139,   126,   140,   127,     0,     0,     0,     0,     0,     0,
     510,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,   345,   126,     0,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   509,   130,   537,   131,     0,   132,     0,   133,   134,
       0,   135,   136,   137,   138,     0,   139,   125,   140,   126,
       0,   127,   128,     0,   129,     0,   130,     0,   131,     0,
     132,     0,   133,   134,     0,   135,   136,   137,   138,   125,
     139,   126,   140,   127,     0,     0,     0,     0,     0,     0,
     409,     0,     0,     0,   343,     0,   128,     0,   129,     0,
     130,   125,   131,   126,   132,   127,   133,   134,     0,   135,
     136,   137,   138,     0,   139,     0,   140,     0,   128,     0,
     129,     0,   130,   125,   131,   126,   132,   127,   133,   134,
       0,   135,   136,   137,   138,     0,   139,     0,   140,     0,
     128,     0,   129,     0,   130,   125,   131,   126,   132,   127,
     133,   134,   508,   135,   136,   137,   138,     0,   139,     0,
     140,     0,   128,     0,   129,     0,   130,     0,   131,     0,
     132,     0,   133,   134,   518,   135,   136,   137,   138,     0,
     139,     0,   140,     0,   128,     0,   129,     0,   130,     0,
     131,   542,   132,   341,   133,   134,     0,   135,   136,   137,
     138,     0,   139,     0,   140,     0,     0,   125,   561,   126,
       0,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,     0,   126,     0,   127,     0,
       0,     0,     0,     0,     0,     0,     0,   507,     0,     0,
       0,   125,     0,   126,     0,   127,   128,     0,   129,     0,
     130,     0,   131,     0,   132,   411,   133,   134,     0,   135,
     136,   137,   138,   128,   139,   129,   140,   130,   125,   131,
     126,   132,   127,   133,   134,     0,   135,   136,   137,   138,
     128,   139,   129,   140,   130,   125,   131,   126,   132,   127,
     133,   134,     0,   135,   136,   137,   138,     0,   139,   520,
     140,     0,     0,     0,     0,     0,   125,   128,   126,   129,
     127,   130,     0,   131,     0,   132,     0,   133,   134,     0,
     135,   136,   137,   138,   128,   139,   129,   140,   130,   125,
     131,   126,   132,   127,   133,   134,     0,   135,   136,   137,
     138,   543,   139,     0,   140,   128,     0,   129,     0,   130,
       0,   131,     0,   132,     0,   133,   134,   339,   135,   136,
     137,   138,   562,   139,     0,   140,     0,     0,   128,     0,
     129,   125,   130,   126,   131,   127,   132,     0,   133,   134,
       0,   135,   136,   137,   138,   413,   139,     0,   140,     0,
       0,     0,   125,     0,   126,   506,   127,     0,     0,     0,
       0,     0,     0,     0,   522,     0,     0,     0,     0,     0,
     128,     0,   129,   125,   130,   126,   131,   127,   132,     0,
     133,   134,     0,   135,   136,   137,   138,   544,   139,     0,
     140,   128,   125,   129,   126,   130,   127,   131,     0,   132,
       0,   133,   134,     0,   135,   136,   137,   138,   563,   139,
       0,   140,   128,     0,   129,   125,   130,   126,   131,   127,
     132,     0,   133,   134,     0,   135,   136,   137,   138,     0,
     139,   128,   140,   129,     0,   130,   125,   131,   126,   132,
     127,   133,   134,     0,   135,   136,   137,   138,     0,   139,
       0,   140,     0,   125,   128,   126,   129,   127,   130,     0,
     131,     0,   132,     0,   133,   134,     0,   135,   136,   137,
     138,     0,   139,     0,   140,   128,   125,   129,   126,   130,
     127,   131,     0,   132,     0,   133,   134,     0,   135,   136,
     137,   138,   128,   139,   129,   140,   130,     0,   131,     0,
     132,     0,   133,   134,     0,   135,   136,   137,   138,     0,
     139,     0,   140,   285,   286,   128,     0,   129,     0,   130,
       0,   131,     0,   132,     0,   133,   134,     0,   135,   136,
     137,   138,     0,   139,     0,   140,   125,   488,   126,   337,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   417,   125,
       0,   126,   505,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,   125,   129,   126,   130,
     127,   131,     0,   132,     0,   133,   134,     0,   135,   136,
     137,   138,     0,   139,     0,   140,     0,     0,   128,     0,
     129,     0,   130,     0,   131,     0,   132,     0,   133,   134,
       0,   135,   136,   137,   138,   128,   139,   129,   140,   130,
     532,   131,     0,   132,     0,   133,   134,     0,   135,   136,
     137,   138,     0,   139,     0,   140,     0,   545,   125,     0,
     126,     0,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   567,   125,     0,   126,     0,   127,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   125,     0,   126,     0,   127,   128,     0,   129,
       0,   130,     0,   131,   419,   132,     0,   133,   134,     0,
     135,   136,   137,   138,   128,   139,   129,   140,   130,   125,
     131,   126,   132,   127,   133,   134,     0,   135,   136,   137,
     138,   128,   139,   129,   140,   130,     0,   131,   529,   132,
       0,   133,   134,     0,   135,   136,   137,   138,     0,   139,
       0,   140,     0,   125,     0,   126,     0,   127,   128,     0,
     129,     0,   130,     0,   131,   546,   132,     0,   133,   134,
       0,   135,   136,   137,   138,     0,   139,     0,   140,     0,
     125,     0,   126,     0,   127,     0,     0,     0,     0,     0,
       0,     0,   128,     0,   129,     0,   130,     0,   131,   566,
     132,     0,   133,   134,     0,   135,   136,   137,   138,     0,
     139,     0,   140,     0,   125,     0,   126,     0,   127,   128,
       0,   129,     0,   130,   292,   131,     0,   132,     0,   133,
     134,     0,   135,   136,   137,   138,   125,   139,   126,   140,
     127,     0,     0,     0,     0,     0,   466,     0,     0,     0,
       0,     0,     0,   128,     0,   129,     0,   130,   125,   131,
     126,   132,   127,   133,   134,     0,   135,   136,   137,   138,
       0,   139,     0,   140,     0,   128,     0,   129,     0,   130,
     491,   131,     0,   132,     0,   133,   134,     0,   135,   136,
     137,   138,   125,   139,   126,   140,   127,   128,     0,   129,
       0,   130,   555,   131,     0,   132,     0,   133,   134,     0,
     135,   136,   137,   138,   125,   139,   126,   140,   127,     0,
       0,     0,     0,     0,     0,     0,     0,   294,     0,   295,
       0,   128,     0,   129,     0,   130,   125,   131,   126,   132,
     127,   133,   134,     0,   135,   136,   137,   138,     0,   139,
       0,   140,     0,   128,     0,   129,     0,   130,     0,   131,
       0,   132,     0,   133,   134,   492,   135,   136,   137,   138,
       0,   139,   125,   140,   126,   128,   127,   129,     0,   130,
       0,   131,     0,   132,     0,   133,   134,     0,   135,   136,
     137,   138,   297,   139,   298,   140,     0,     0,   125,     0,
     126,     0,   127,     0,     0,     0,     0,     0,     0,     0,
       0,   128,     0,   129,     0,   130,     0,   131,     0,   132,
       0,   133,   134,     0,   135,   136,   137,   138,   493,   139,
       0,   140,   125,     0,   126,     0,   127,   128,     0,   129,
       0,   130,     0,   131,     0,   132,     0,   133,   134,     0,
     135,   136,   137,   138,     0,   139,   300,   140,   301,   125,
       0,   126,     0,   127,     0,     0,     0,     0,     0,     0,
       0,   128,     0,   129,     0,   130,     0,   131,     0,   132,
       0,   133,   134,     0,   135,   136,   137,   138,     0,   139,
       0,   140,   494,   125,     0,   126,     0,   127,   128,     0,
     129,     0,   130,     0,   131,     0,   132,     0,   133,   134,
       0,   135,   136,   137,   138,   125,   139,   126,   140,   127,
       0,     0,     0,     0,     0,     0,     0,     0,   310,   311,
       0,     0,   128,     0,   129,     0,   130,     0,   131,     0,
     132,     0,   133,   134,     0,   135,   136,   137,   138,     0,
     139,     0,   140,     0,   128,     0,   129,     0,   130,   125,
     131,   126,   132,   127,   133,   134,     0,   135,   136,   137,
     138,     0,   139,     0,   140,   313,   314,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   125,   130,   126,   131,   127,   132,     0,   133,   134,
       0,   135,   136,   137,   138,     0,   139,     0,   140,     0,
     316,   317,     0,   125,     0,   126,     0,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,     0,   129,     0,   130,   319,   131,   320,   132,     0,
     133,   134,     0,   135,   136,   137,   138,     0,   139,   125,
     140,   126,   128,   127,   129,     0,   130,     0,   131,     0,
     132,     0,   133,   134,     0,   135,   136,   137,   138,     0,
     139,     0,   140,     0,   322,   323,   125,     0,   126,     0,
     127,     0,     0,     0,     0,     0,     0,     0,   128,     0,
     129,     0,   130,   125,   131,   126,   132,   127,   133,   134,
     303,   135,   136,   137,   138,     0,   139,     0,   140,   328,
       0,   329,     0,     0,     0,   128,     0,   129,     0,   130,
     125,   131,   126,   132,   127,   133,   134,   305,   135,   136,
     137,   138,   128,   139,   129,   140,   130,   125,   131,   126,
     132,   127,   133,   134,   306,   135,   136,   137,   138,     0,
     139,     0,   140,     0,     0,     0,     0,     0,     0,   128,
       0,   129,     0,   130,   125,   131,   126,   132,   127,   133,
     134,   307,   135,   136,   137,   138,   128,   139,   129,   140,
     130,   125,   131,   126,   132,   127,   133,   134,   308,   135,
     136,   137,   138,     0,   139,     0,   140,     0,     0,     0,
       0,     0,     0,   128,     0,   129,     0,   130,   125,   131,
     126,   132,   127,   133,   134,   309,   135,   136,   137,   138,
     128,   139,   129,   140,   130,     0,   131,     0,   132,     0,
     133,   134,     0,   135,   136,   137,   138,     0,   139,   125,
     140,   126,     0,   127,     0,     0,     0,   128,     0,   129,
       0,   130,     0,   131,     0,   132,     0,   133,   134,     0,
     135,   136,   137,   138,     0,   139,     0,   140,   125,   325,
     126,     0,   127,     0,     0,     0,     0,     0,   128,     0,
     129,     0,   130,     0,   131,     0,   132,     0,   133,   134,
       0,   135,   136,   137,   138,   125,   139,   126,   140,   127,
     327,     0,     0,     0,     0,     0,     0,   128,     0,   129,
       0,   130,   125,   131,   126,   132,   127,   133,   134,   495,
     135,   136,   137,   138,     0,   139,     0,   140,     0,     0,
       0,     0,     0,   331,   128,     0,   129,     0,   130,   125,
     131,   126,   132,   127,   133,   134,     0,   135,   136,   137,
     138,   128,   139,   129,   140,   130,   125,   131,   126,   132,
     127,   133,   134,   499,   135,   136,   137,   138,     0,   139,
     496,   140,     0,   125,     0,   126,     0,   127,   128,     0,
     129,     0,   130,     0,   131,     0,   132,     0,   133,   134,
     497,   135,   136,   137,   138,   128,   139,   129,   140,   130,
       0,   131,     0,   132,     0,   133,   134,     0,   135,   136,
     137,   138,   128,   139,   129,   140,   130,   125,   131,   126,
     132,   127,   133,   134,     0,   135,   136,   137,   138,     0,
     139,     0,   140,     0,     0,     0,     0,   498,     0,   125,
       0,   126,     0,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,   129,     0,
     130,     0,   131,     0,   132,   500,   133,   134,     0,   135,
     136,   137,   138,   125,   139,   126,   140,   127,   128,     0,
     129,     0,   130,     0,   131,     0,   132,     0,   133,   134,
       0,   135,   136,   137,   138,     0,   139,     0,   140,     0,
     125,     0,   126,   501,   127,     0,     0,     0,     0,     0,
       0,     0,   128,     0,   129,     0,   130,     0,   131,     0,
     132,     0,   133,   134,     0,   135,   136,   137,   138,   125,
     139,   126,   140,   127,     0,   502,     0,     0,     0,   128,
       0,   129,     0,   130,     0,   131,     0,   132,     0,   133,
     134,     0,   135,   136,   137,   138,     0,   139,     0,   140,
       0,     0,     0,     0,     0,     0,     0,   503,   128,     0,
     129,     0,   130,     0,   131,     0,   132,     0,   133,   134,
       0,   135,   136,   137,   138,     0,   139,     0,   140
};

static const yytype_int16 yycheck[] =
{
      12,    14,    16,    16,   121,    16,    18,    16,    16,    21,
      16,    23,    16,    25,    16,    27,    16,    29,    30,    31,
      32,    33,    34,    16,    36,    16,    38,    16,    40,    44,
      42,     0,    44,    31,    46,    47,    16,    49,    16,    16,
      16,   108,    16,   121,    16,   124,    16,    59,    16,    61,
      16,    63,    16,    65,    16,    67,    16,    69,    16,    71,
      16,    73,    16,    75,    16,    77,    16,    79,    16,    92,
      16,   113,    16,    85,    16,    16,    16,    16,    16,    16,
      16,    16,    16,    16,    16,   116,   117,    16,    16,   112,
      16,   112,    16,    16,    16,    16,   112,   112,    23,    24,
      25,   165,    27,    28,   164,    30,     3,     4,    21,    22,
      85,   108,   109,   112,     4,     5,   112,     7,   112,     9,
     112,    11,    31,   113,   114,   115,   116,   117,   113,   113,
     114,   115,   116,   117,    42,   166,    81,    44,    85,   112,
     152,   112,   154,    92,   156,   112,   158,   112,    24,    25,
     162,    27,    28,   165,    30,   164,   164,   112,   164,   112,
     164,    92,   164,    83,   164,   124,   141,    97,    87,    44,
      97,   164,    89,   164,   164,   164,   166,   152,   121,   154,
     164,   156,   166,   158,   164,    99,   164,   164,   164,    99,
     164,    81,   164,    83,   164,   113,   164,   102,   164,    92,
     164,   113,   164,   166,   164,    92,   164,    -1,   164,   112,
     164,   112,   164,   112,   164,    -1,   164,   229,   164,   231,
     164,   112,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   247,   247,   164,   164,   249,   164,   252,
     164,   164,   164,   164,   113,   114,   115,   116,   117,   114,
     115,   116,   117,    -1,   229,    -1,   231,    24,    25,    26,
      27,    28,    -1,    30,    -1,   382,   383,   384,   385,   386,
      -1,    -1,    -1,    -1,    -1,   287,   289,   291,   291,    24,
      25,   293,    27,    28,   296,    30,    -1,   299,    -1,    -1,
     302,    -1,   304,    -1,    -1,    -1,    -1,   166,    -1,    -1,
     312,   166,    -1,   315,    24,    25,   318,    27,    28,   321,
      30,    -1,   324,    -1,   326,    -1,    -1,   434,   330,    -1,
     332,    -1,    -1,    -1,    -1,    -1,   338,    -1,   340,    -1,
     342,    -1,   344,    -1,   346,    -1,   348,    -1,   350,    -1,
     352,    -1,   354,   233,   356,   235,   358,   237,    -1,   239,
     240,   363,   242,   365,    85,   367,    -1,   369,   370,   476,
     372,    -1,    -1,   375,    -1,    -1,    -1,    -1,   380,    -1,
     260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   363,   279,
     365,   281,   367,   283,   369,   370,    -1,   372,   410,    -1,
     412,    -1,   414,    -1,    -1,    -1,   418,    -1,   420,    -1,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   392,    -1,    -1,
      -1,   152,    -1,   154,    -1,   156,    -1,   158,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   410,    -1,   412,   450,   414,
     452,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   465,   465,    -1,    -1,   467,   469,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     360,    -1,   362,    -1,    -1,   450,    -1,   452,    -1,    -1,
      -1,    41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,   519,    -1,   521,
      -1,   523,    -1,    -1,   526,    -1,   528,    -1,   530,    -1,
      80,   533,    82,    -1,    84,    -1,    86,    -1,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    -1,    98,    -1,
     100,    41,    -1,    43,   519,    45,   521,    -1,   523,    -1,
      -1,   526,    -1,   528,    -1,    -1,    -1,    -1,    -1,   534,
      -1,   536,    -1,    41,   454,    43,   456,    45,   458,    -1,
      -1,   461,    -1,   463,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    84,   475,    86,   477,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    -1,    98,    -1,
     100,    -1,    80,   163,    82,    -1,    84,    -1,    86,    -1,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   363,    -1,   365,    -1,   367,    -1,   369,   370,
      -1,   372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   392,    -1,   163,     6,    -1,     8,    -1,    10,    -1,
      -1,    13,    -1,    15,    -1,    17,    -1,    19,    -1,   410,
      22,   412,    24,   414,    26,   163,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    41,    37,    43,    39,    45,    41,
      -1,    43,    -1,    45,    -1,    -1,    48,    -1,    50,    -1,
      -1,    41,    -1,    43,    56,    45,    58,    -1,    60,   450,
      62,   452,    64,    -1,    66,    -1,    68,    -1,    70,    -1,
      72,    -1,    74,    80,    76,    82,    78,    84,    80,    86,
      82,    88,    84,    90,    91,    -1,    93,    94,    95,    96,
      80,    98,    82,   100,    84,    -1,    86,    -1,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    -1,    98,    -1,
     100,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,   519,    -1,
     521,    -1,   523,   135,   136,   526,    -1,   528,   140,    -1,
      41,    -1,    43,   534,    45,   536,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    -1,    84,   163,    86,    -1,    88,
      -1,    90,    91,    -1,    93,    94,    95,    96,    -1,    98,
     160,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    -1,    98,    -1,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   160,   234,    -1,   236,    -1,   238,    -1,    -1,   241,
      -1,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,     6,
       7,   253,     9,    10,    -1,    12,    -1,    14,    15,   160,
      -1,    18,    -1,    20,    21,    22,    -1,    24,    25,    -1,
      27,    28,    -1,    30,    -1,    32,    33,    -1,    35,    36,
      -1,    38,    39,    -1,    41,    -1,    43,    -1,    45,    46,
      47,    -1,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    -1,    59,    60,    -1,    62,    63,    64,    -1,    66,
      -1,    68,    69,    70,    -1,    72,    -1,    74,    75,    -1,
      77,    78,    -1,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    90,    91,    -1,    93,    94,    95,    96,
      -1,    98,    -1,   100,   101,    -1,   103,    -1,   105,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,   120,    -1,   122,   123,    -1,   125,   126,
      -1,   128,   129,    -1,   131,   132,    -1,   134,   135,    -1,
     137,   138,    -1,   140,   141,    -1,   143,   144,    -1,   146,
     147,    -1,   149,   150,    -1,   152,   153,    -1,   155,   156,
      -1,   158,   159,    -1,   161,   162,     6,     7,    -1,     9,
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
      -1,   161,   162,     6,     7,    -1,     9,    10,    -1,    12,
      -1,    14,    15,    17,    -1,    18,    -1,    20,    21,    22,
      -1,    24,    25,    -1,    27,    28,    -1,    30,    -1,    32,
      33,    -1,    35,    36,    -1,    38,    39,    41,    -1,    43,
      -1,    45,    -1,    46,    47,    -1,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    -1,    59,    60,    -1,    62,
      63,    64,    -1,    66,    -1,    68,    69,    70,    -1,    72,
      -1,    74,    75,    -1,    77,    78,    80,    -1,    82,    -1,
      84,    -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,
      94,    95,    96,    -1,    98,    -1,   100,    -1,   101,    -1,
     103,    -1,   105,   106,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,   120,    -1,   122,
     123,    -1,   125,   126,    -1,   128,   129,    -1,   131,   132,
      -1,   134,   135,    -1,   137,   138,    -1,   140,   141,    -1,
     143,   144,    -1,   146,   147,    -1,   149,   150,    -1,   152,
     153,    -1,   155,   156,    -1,   158,   159,    -1,   161,   162,
       6,     7,    -1,     9,    10,    -1,    12,    -1,    14,    15,
      -1,    -1,    18,    -1,    20,    21,    22,    -1,    24,    25,
      -1,    27,    28,    -1,    30,    -1,    32,    33,    -1,    35,
      36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    -1,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    -1,    59,    60,    -1,    62,    63,    64,    -1,
      66,    -1,    68,    69,    70,    -1,    72,    -1,    74,    75,
      -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,   103,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,   120,    -1,   122,   123,    -1,   125,
     126,    -1,   128,   129,    -1,   131,   132,    -1,   134,   135,
      -1,   137,   138,    -1,   140,   141,    -1,   143,   144,    -1,
     146,   147,    -1,   149,   150,    -1,   152,   153,    -1,   155,
     156,    -1,   158,   159,    -1,   161,   162,     6,     7,    -1,
       9,    10,    -1,    12,    -1,    14,    15,    -1,    -1,    18,
      -1,    20,    21,    22,    -1,    24,    25,    -1,    27,    28,
      -1,    30,    -1,    32,    33,    -1,    35,    36,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    -1,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    -1,
      59,    60,    -1,    62,    63,    64,    -1,    66,    -1,    68,
      69,    70,    -1,    72,    -1,    74,    75,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    -1,   103,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,    -1,   122,   123,    -1,   125,   126,    -1,   128,
     129,    -1,   131,   132,    -1,   134,   135,    -1,   137,   138,
      -1,   140,   141,    -1,   143,   144,    -1,   146,   147,    -1,
     149,   150,    -1,   152,   153,    -1,   155,   156,    -1,   158,
     159,    -1,   161,   162,    41,    -1,    43,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    -1,    45,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    90,    91,    -1,    93,    94,    95,    96,
      80,    98,    82,   100,    84,    41,    86,    43,    88,    45,
      90,    91,    -1,    93,    94,    95,    96,    80,    98,    82,
     100,    84,    -1,    86,    -1,    88,    -1,    90,    91,    -1,
      93,    94,    95,    96,    -1,    98,    -1,   100,    -1,    -1,
      -1,    -1,    -1,    41,    80,    43,    82,    45,    84,    -1,
      86,    -1,    88,    -1,    90,    91,    -1,    93,    94,    95,
      96,    -1,    98,   160,   100,    -1,    -1,    41,    -1,    43,
      -1,    45,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,
      -1,    -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,
      88,    -1,    90,    91,   157,    93,    94,    95,    96,    -1,
      98,    -1,   100,    -1,    -1,    41,    80,    43,    82,    45,
      84,    -1,    86,    -1,    88,    -1,    90,    91,   154,    93,
      94,    95,    96,    -1,    98,    -1,   100,    -1,    -1,    41,
      -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    84,    -1,
      86,    -1,    88,    -1,    90,    91,   154,    93,    94,    95,
      96,    -1,    98,    -1,   100,    -1,    -1,    41,    80,    43,
      82,    45,    84,    -1,    86,    -1,    88,   151,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    -1,   100,    -1,
      41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    41,    82,    43,
      84,    45,    86,    -1,    88,   151,    90,    91,    -1,    93,
      94,    95,    96,    -1,    98,    -1,   100,    -1,    41,    80,
      43,    82,    45,    84,    -1,    86,   148,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    80,    98,    82,   100,
      84,    -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,
      94,    95,    96,    -1,    98,    -1,   100,    80,    -1,    82,
      -1,    84,    -1,    86,   148,    88,    -1,    90,    91,    -1,
      93,    94,    95,    96,    -1,    98,    -1,   100,    -1,    41,
      -1,    43,    -1,    45,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    43,    -1,
      45,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    43,    -1,    45,    80,   142,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    80,    98,    82,   100,    84,
      -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,    94,
      95,    96,    80,    98,    82,   100,    84,     5,    86,    -1,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    41,
      98,    43,   100,    45,    -1,    -1,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,   139,    43,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,   139,    84,     5,    86,    -1,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    41,   100,    43,
      -1,    45,    80,    -1,    82,    -1,    84,    -1,    86,    -1,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    41,
      98,    43,   100,    45,    -1,    -1,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    -1,   136,    -1,    80,    -1,    82,    -1,
      84,    41,    86,    43,    88,    45,    90,    91,    -1,    93,
      94,    95,    96,    -1,    98,    -1,   100,    -1,    80,    -1,
      82,    -1,    84,    41,    86,    43,    88,    45,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    -1,   100,    -1,
      80,    -1,    82,    -1,    84,    41,    86,    43,    88,    45,
      90,    91,   136,    93,    94,    95,    96,    -1,    98,    -1,
     100,    -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,
      88,    -1,    90,    91,     8,    93,    94,    95,    96,    -1,
      98,    -1,   100,    -1,    80,    -1,    82,    -1,    84,    -1,
      86,     8,    88,   133,    90,    91,    -1,    93,    94,    95,
      96,    -1,    98,    -1,   100,    -1,    -1,    41,     8,    43,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,    -1,
      -1,    41,    -1,    43,    -1,    45,    80,    -1,    82,    -1,
      84,    -1,    86,    -1,    88,    11,    90,    91,    -1,    93,
      94,    95,    96,    80,    98,    82,   100,    84,    41,    86,
      43,    88,    45,    90,    91,    -1,    93,    94,    95,    96,
      80,    98,    82,   100,    84,    41,    86,    43,    88,    45,
      90,    91,    -1,    93,    94,    95,    96,    -1,    98,    11,
     100,    -1,    -1,    -1,    -1,    -1,    41,    80,    43,    82,
      45,    84,    -1,    86,    -1,    88,    -1,    90,    91,    -1,
      93,    94,    95,    96,    80,    98,    82,   100,    84,    41,
      86,    43,    88,    45,    90,    91,    -1,    93,    94,    95,
      96,    11,    98,    -1,   100,    80,    -1,    82,    -1,    84,
      -1,    86,    -1,    88,    -1,    90,    91,   130,    93,    94,
      95,    96,    11,    98,    -1,   100,    -1,    -1,    80,    -1,
      82,    41,    84,    43,    86,    45,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    13,    98,    -1,   100,    -1,
      -1,    -1,    41,    -1,    43,   130,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    41,    84,    43,    86,    45,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    13,    98,    -1,
     100,    80,    41,    82,    43,    84,    45,    86,    -1,    88,
      -1,    90,    91,    -1,    93,    94,    95,    96,    13,    98,
      -1,   100,    80,    -1,    82,    41,    84,    43,    86,    45,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    80,   100,    82,    -1,    84,    41,    86,    43,    88,
      45,    90,    91,    -1,    93,    94,    95,    96,    -1,    98,
      -1,   100,    -1,    41,    80,    43,    82,    45,    84,    -1,
      86,    -1,    88,    -1,    90,    91,    -1,    93,    94,    95,
      96,    -1,    98,    -1,   100,    80,    41,    82,    43,    84,
      45,    86,    -1,    88,    -1,    90,    91,    -1,    93,    94,
      95,    96,    80,    98,    82,   100,    84,    -1,    86,    -1,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    -1,   100,    18,    19,    80,    -1,    82,    -1,    84,
      -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,    94,
      95,    96,    -1,    98,    -1,   100,    41,    19,    43,   127,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    41,
      -1,    43,   127,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    41,    82,    43,    84,
      45,    86,    -1,    88,    -1,    90,    91,    -1,    93,    94,
      95,    96,    -1,    98,    -1,   100,    -1,    -1,    80,    -1,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    80,    98,    82,   100,    84,
      23,    86,    -1,    88,    -1,    90,    91,    -1,    93,    94,
      95,    96,    -1,    98,    -1,   100,    -1,    23,    41,    -1,
      43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    41,    -1,    43,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    43,    -1,    45,    80,    -1,    82,
      -1,    84,    -1,    86,    26,    88,    -1,    90,    91,    -1,
      93,    94,    95,    96,    80,    98,    82,   100,    84,    41,
      86,    43,    88,    45,    90,    91,    -1,    93,    94,    95,
      96,    80,    98,    82,   100,    84,    -1,    86,    26,    88,
      -1,    90,    91,    -1,    93,    94,    95,    96,    -1,    98,
      -1,   100,    -1,    41,    -1,    43,    -1,    45,    80,    -1,
      82,    -1,    84,    -1,    86,    26,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    -1,   100,    -1,
      41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    -1,    84,    -1,    86,    26,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    -1,   100,    -1,    41,    -1,    43,    -1,    45,    80,
      -1,    82,    -1,    84,    29,    86,    -1,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    41,    98,    43,   100,
      45,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    84,    41,    86,
      43,    88,    45,    90,    91,    -1,    93,    94,    95,    96,
      -1,    98,    -1,   100,    -1,    80,    -1,    82,    -1,    84,
      29,    86,    -1,    88,    -1,    90,    91,    -1,    93,    94,
      95,    96,    41,    98,    43,   100,    45,    80,    -1,    82,
      -1,    84,    29,    86,    -1,    88,    -1,    90,    91,    -1,
      93,    94,    95,    96,    41,    98,    43,   100,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,
      -1,    80,    -1,    82,    -1,    84,    41,    86,    43,    88,
      45,    90,    91,    -1,    93,    94,    95,    96,    -1,    98,
      -1,   100,    -1,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    90,    91,    34,    93,    94,    95,    96,
      -1,    98,    41,   100,    43,    80,    45,    82,    -1,    84,
      -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,    94,
      95,    96,    35,    98,    37,   100,    -1,    -1,    41,    -1,
      43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,    88,
      -1,    90,    91,    -1,    93,    94,    95,    96,    37,    98,
      -1,   100,    41,    -1,    43,    -1,    45,    80,    -1,    82,
      -1,    84,    -1,    86,    -1,    88,    -1,    90,    91,    -1,
      93,    94,    95,    96,    -1,    98,    38,   100,    40,    41,
      -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,    88,
      -1,    90,    91,    -1,    93,    94,    95,    96,    -1,    98,
      -1,   100,    40,    41,    -1,    43,    -1,    45,    80,    -1,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    41,    98,    43,   100,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      -1,    -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    -1,   100,    -1,    80,    -1,    82,    -1,    84,    41,
      86,    43,    88,    45,    90,    91,    -1,    93,    94,    95,
      96,    -1,    98,    -1,   100,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    41,    84,    43,    86,    45,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    -1,   100,    -1,
      60,    61,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    84,    63,    86,    65,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    -1,    98,    41,
     100,    43,    80,    45,    82,    -1,    84,    -1,    86,    -1,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    -1,   100,    -1,    66,    67,    41,    -1,    43,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    84,    41,    86,    43,    88,    45,    90,    91,
      48,    93,    94,    95,    96,    -1,    98,    -1,   100,    74,
      -1,    76,    -1,    -1,    -1,    80,    -1,    82,    -1,    84,
      41,    86,    43,    88,    45,    90,    91,    48,    93,    94,
      95,    96,    80,    98,    82,   100,    84,    41,    86,    43,
      88,    45,    90,    91,    48,    93,    94,    95,    96,    -1,
      98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    -1,    84,    41,    86,    43,    88,    45,    90,
      91,    48,    93,    94,    95,    96,    80,    98,    82,   100,
      84,    41,    86,    43,    88,    45,    90,    91,    48,    93,
      94,    95,    96,    -1,    98,    -1,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    84,    41,    86,
      43,    88,    45,    90,    91,    48,    93,    94,    95,    96,
      80,    98,    82,   100,    84,    -1,    86,    -1,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    -1,    98,    41,
     100,    43,    -1,    45,    -1,    -1,    -1,    80,    -1,    82,
      -1,    84,    -1,    86,    -1,    88,    -1,    90,    91,    -1,
      93,    94,    95,    96,    -1,    98,    -1,   100,    41,    71,
      43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    41,    98,    43,   100,    45,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      -1,    84,    41,    86,    43,    88,    45,    90,    91,    48,
      93,    94,    95,    96,    -1,    98,    -1,   100,    -1,    -1,
      -1,    -1,    -1,    79,    80,    -1,    82,    -1,    84,    41,
      86,    43,    88,    45,    90,    91,    -1,    93,    94,    95,
      96,    80,    98,    82,   100,    84,    41,    86,    43,    88,
      45,    90,    91,    65,    93,    94,    95,    96,    -1,    98,
      55,   100,    -1,    41,    -1,    43,    -1,    45,    80,    -1,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,    91,
      58,    93,    94,    95,    96,    80,    98,    82,   100,    84,
      -1,    86,    -1,    88,    -1,    90,    91,    -1,    93,    94,
      95,    96,    80,    98,    82,   100,    84,    41,    86,    43,
      88,    45,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    -1,   100,    -1,    -1,    -1,    -1,    61,    -1,    41,
      -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,
      84,    -1,    86,    -1,    88,    67,    90,    91,    -1,    93,
      94,    95,    96,    41,    98,    43,   100,    45,    80,    -1,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    -1,   100,    -1,
      41,    -1,    43,    71,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    -1,    84,    -1,    86,    -1,
      88,    -1,    90,    91,    -1,    93,    94,    95,    96,    41,
      98,    43,   100,    45,    -1,    76,    -1,    -1,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    -1,    98,    -1,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    -1,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    -1,   100
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,   168,   203,     6,     7,     9,    10,    12,
      14,    15,    18,    20,    21,    22,    24,    25,    27,    28,
      30,    32,    33,    35,    36,    38,    39,    46,    47,    49,
      50,    51,    52,    53,    54,    56,    57,    59,    60,    62,
      63,    64,    66,    68,    69,    70,    72,    74,    75,    77,
      78,   101,   103,   105,   107,   119,   120,   122,   123,   125,
     126,   128,   129,   131,   132,   134,   135,   137,   138,   140,
     141,   143,   144,   146,   147,   149,   150,   152,   153,   155,
     156,   158,   159,   161,   162,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   215,
     218,   221,    16,   214,     0,    41,    43,    45,    80,    82,
      84,    86,    88,    90,    91,    93,    94,    95,    96,    98,
     100,   169,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   169,   214,   169,   214,   169,   214,   169,   203,
     214,    23,   187,   214,    26,   186,   187,   214,   203,   214,
      31,   203,   214,   203,   214,   203,   214,   203,   214,   203,
     203,   203,   203,   203,   203,   214,   203,   214,   203,   214,
     203,   214,   203,   214,   203,   214,   203,   203,   214,   203,
     214,   108,   216,   121,   214,   124,   214,   203,   214,   203,
     214,   203,   214,   203,   214,   203,   214,   203,   214,   203,
     214,   203,   214,   203,   214,   203,   214,   203,   214,   169,
     214,   169,   214,     6,     7,     9,    10,    12,    14,    15,
     158,   159,   161,   162,   170,   203,   215,    24,    25,    27,
      28,    30,    21,    22,   108,   109,   217,   217,   113,    16,
     164,   112,    44,   112,   214,   112,   112,   112,   112,   112,
     112,   112,   214,   214,   112,   112,   112,   214,   203,   164,
     203,   164,   203,   164,   203,    18,    19,   164,   203,   164,
     203,   164,    29,   164,    32,    34,   164,    35,    37,   164,
      38,    40,   164,    48,   164,    48,    48,    48,    48,    48,
      54,    55,   164,    57,    58,   164,    60,    61,   164,    63,
      65,   164,    66,    67,   164,    71,   164,    73,    74,    76,
     164,    79,   164,   165,   164,   164,   164,   127,   164,   130,
     164,   133,   164,   136,   164,   139,   164,   142,   164,   145,
     164,   148,   164,   151,   164,   154,   164,   157,   164,   203,
     164,   203,   164,   169,   214,   169,   214,   169,   214,   169,
     169,   214,   169,   214,     5,   186,   214,   203,   214,    31,
     187,   214,   113,   114,   115,   116,   117,   164,   166,   164,
     112,   113,   169,    42,    44,   164,    81,    83,    85,    87,
      89,    92,    92,   164,   164,    97,    97,    99,   164,     8,
     169,    11,   169,    13,   169,    17,   203,    23,   187,    26,
     186,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   113,   102,   121,   124,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   160,
     169,   163,   169,   203,   164,   203,   164,   203,   164,   203,
     203,   164,   203,   164,   203,   164,    29,   164,   203,   164,
     217,   217,   217,   217,   217,   219,   113,   223,   112,   203,
     112,   112,    92,   112,   112,   203,   203,   203,    19,   203,
     203,    29,    34,    37,    40,    48,    55,    58,    61,    65,
      67,    71,    76,    79,   217,   127,   130,   133,   136,   139,
     142,   145,   148,   151,   154,   157,   203,   203,     8,   169,
      11,   169,    13,   169,    17,   160,   169,   163,   169,    26,
     186,   203,    23,   187,   169,   217,   169,     5,    44,    92,
      92,    99,     8,    11,    13,    23,    26,   160,   163,   203,
     203,   203,   203,   203,   203,    29,   203,   104,   220,   106,
     222,     8,    11,    13,   160,   163,    26,    23
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
#line 163 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 167 "gtkdialog_parser.y"
    { 
    		token_store(PUSH | WIDGET_WINDOW); 
		start_up();
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 171 "gtkdialog_parser.y"
    { 
    		token_store_attr(PUSH | WIDGET_WINDOW, (yyvsp[(2) - (6)].nvval)); 
		start_up();
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 181 "gtkdialog_parser.y"
    { 
		token_store(SUM);      
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 186 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
	}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 189 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_VBOX); 
		token_store(SUM);      
	}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 193 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(2) - (6)].nvval)); 
	}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 196 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VBOX, (yyvsp[(3) - (7)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 200 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
	}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 203 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_HBOX); 
		token_store(SUM);      
	}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 207 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(2) - (6)].nvval)); 
	}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 210 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HBOX, (yyvsp[(3) - (7)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 214 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_EVENTBOX); 
	}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 217 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_EVENTBOX); 
		token_store(SUM);      
	}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 221 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_EVENTBOX, (yyvsp[(2) - (6)].nvval)); 
	}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 224 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_EVENTBOX, (yyvsp[(3) - (7)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 228 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_EXPANDER); 
	}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 231 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_EXPANDER); 
		token_store(SUM);      
	}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 235 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_EXPANDER, (yyvsp[(2) - (6)].nvval)); 
	}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 238 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_EXPANDER, (yyvsp[(3) - (7)].nvval)); 
		token_store(SUM);      
	}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 242 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
	}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 245 "gtkdialog_parser.y"
    { 
		token_store(PUSH | WIDGET_NOTEBOOK); 
		token_store(SUM);      
	}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 249 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 252 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_NOTEBOOK, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);      
	}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 256 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(1) - (4)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
	}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 260 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_LABEL, (yyvsp[(2) - (5)].cval)); 
		token_store(PUSH | WIDGET_FRAME); 
		token_store(SUM);      
	}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 299 "gtkdialog_parser.y"
    {
                          token_store(PUSH | WIDGET_ENTRY); 
			 }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 302 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_ENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 305 "gtkdialog_parser.y"
    {
                  yyerror("</entry> expected instead of <entry>.");}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 310 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_EDIT); 
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 313 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_EDIT, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 316 "gtkdialog_parser.y"
    {
    		yyerror("</edit> expected instead of <edit>.");
	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 322 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TREE); 
	}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 325 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_TREE, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 328 "gtkdialog_parser.y"
    {
   		yyerror("</tree> expected instead of <tree>.");
	}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 334 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHOOSER); 
	}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 337 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_CHOOSER, (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 340 "gtkdialog_parser.y"
    {
		yyerror("</chooser> expected instead of <chooser>.");
	}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 346 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TEXT); 
	}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 349 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_TEXT, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 352 "gtkdialog_parser.y"
    {yyerror("</text> expected instead of <text>.");}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 356 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_BUTTON);  }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 357 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_BUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 360 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_OKBUTTON);}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 361 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_CANCELBUTTON);}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 362 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_HELPBUTTON);}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 363 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_NOBUTTON);}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 364 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_YESBUTTON);}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 368 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_CHECKBOX);
	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 371 "gtkdialog_parser.y"
    {
		//token_store_with_tag_attributes(PUSH | WIDGET_CHECKBOX, $2);
                token_store_attr(PUSH | WIDGET_CHECKBOX, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 375 "gtkdialog_parser.y"
    {
		yyerror("</checkbox> expected instead of <checkbox>.");
	}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 381 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_RADIOBUTTON);
           }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 384 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_RADIOBUTTON, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 387 "gtkdialog_parser.y"
    {
		yyerror("</radiobutton> expected instead of <radiobutton>.");
           }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 393 "gtkdialog_parser.y"
    {
	   	token_store(PUSH | WIDGET_PROGRESS);
           }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 396 "gtkdialog_parser.y"
    {
                token_store_attr(PUSH | WIDGET_PROGRESS, (yyvsp[(2) - (5)].nvval));
	   }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 399 "gtkdialog_parser.y"
    {
		yyerror("</progressbar> expected instead of <progressbar>.");
           }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 405 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_LIST); 
	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 408 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_LIST, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 411 "gtkdialog_parser.y"
    {
    		yyerror("</list> expected instead of <list>.");
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 417 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TABLE); 
	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 420 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TABLE, (yyvsp[(2) - (5)].nvval)); 
    	}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 423 "gtkdialog_parser.y"
    {
    		yyerror("</table> expected instead of <table>.");
	}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 429 "gtkdialog_parser.y"
    {
    		token_store(PUSH | WIDGET_COMBO);
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 432 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_COMBO, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 438 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_GVIM);}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 442 "gtkdialog_parser.y"
    {token_store(PUSH | WIDGET_PIXMAP);}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 443 "gtkdialog_parser.y"
    {
    		token_store_attr(PUSH | WIDGET_PIXMAP, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 456 "gtkdialog_parser.y"
    {
		yyerror("The menubar widget requires at least one menu widget.");
	}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 459 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUBAR);
	}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 462 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUBAR);
		token_store(SUM);
	}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 466 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUBAR, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 469 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUBAR, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);
	}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 482 "gtkdialog_parser.y"
    {
		yyerror("The menu widget requires at least one menuitem widget.");
	}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 485 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENU);
	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 488 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENU);
		token_store(SUM);
	}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 492 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENU, (yyvsp[(2) - (6)].nvval));
	}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 495 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENU, (yyvsp[(3) - (7)].nvval));
		token_store(SUM);
	}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 502 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM);
	}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 505 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEM);
		token_store(SUM);
	}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 509 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 512 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_MENUITEM, (yyvsp[(3) - (6)].nvval));
		token_store(SUM);
	}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 519 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEMSEPARATOR);
	}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 522 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_MENUITEMSEPARATOR);
		token_store(SUM);
	}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 529 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSEPARATOR);
	}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 532 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 538 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSEPARATOR);
	}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 541 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSEPARATOR, (yyvsp[(2) - (4)].nvval));
	}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 547 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXTEXT);
	}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 550 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXTEXT, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 556 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COMBOBOXENTRY);
	}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 559 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COMBOBOXENTRY, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 565 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_HSCALE);
	}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 568 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_HSCALE, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 574 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_VSCALE);
	}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 577 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_VSCALE, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 583 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_SPINBUTTON);
	}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 586 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_SPINBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 592 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TIMER);
	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 595 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TIMER, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 601 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TOGGLEBUTTON);
	}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 604 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TOGGLEBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 610 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_STATUSBAR);
	}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 613 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_STATUSBAR, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 619 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_COLORBUTTON);
	}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 622 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_COLORBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 628 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_FONTBUTTON);
	}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 631 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_FONTBUTTON, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 637 "gtkdialog_parser.y"
    {
		token_store(PUSH | WIDGET_TERMINAL);
	}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 640 "gtkdialog_parser.y"
    {
		token_store_attr(PUSH | WIDGET_TERMINAL, (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 660 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_LABEL, (yyvsp[(2) - (3)].cval));     }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 665 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_VARIABLE, (yyvsp[(2) - (3)].cval)); }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 670 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_SENSITIVE, (yyvsp[(2) - (3)].cval));  }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 675 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_DEFAULT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 680 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_WIDTH, (yyvsp[(2) - (3)].cval));    }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 685 "gtkdialog_parser.y"
    {
     token_store_with_argument( SET | ATTR_HEIGHT, (yyvsp[(2) - (3)].cval));   }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 690 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_SHELL,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 693 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 696 "gtkdialog_parser.y"
    { 
		token_store_with_argument(SET|ATTR_INPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 699 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval)); 
	}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 702 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET|ATTR_INPUT|SUB_ATTR_FILE, "", (yyvsp[(2) - (4)].nvval)); 
	}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 708 "gtkdialog_parser.y"
    {
	         fprintf( stderr, "<output>: Not implemented.\n" ); 
	}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 711 "gtkdialog_parser.y"
    {
         	token_store_with_argument(SET|ATTR_OUTPUT|SUB_ATTR_FILE,(yyvsp[(2) - (3)].cval));
	}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 717 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET|ATTR_ACTION, (yyvsp[(2) - (3)].cval)); 
	}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 720 "gtkdialog_parser.y"
    {
		token_store_with_argument_attr(SET | ATTR_ACTION, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
	}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 727 "gtkdialog_parser.y"
    { 
		token_store_with_argument( SET | ATTR_ITEM, (yyvsp[(2) - (3)].cval));
	}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 730 "gtkdialog_parser.y"
    {
		token_store_with_argument( SET | ATTR_ITEM, "");
    	}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 733 "gtkdialog_parser.y"
    {
		      token_store_with_argument_attr(SET | ATTR_ITEM, (yyvsp[(4) - (5)].cval), (yyvsp[(2) - (5)].nvval));
                    }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 739 "gtkdialog_parser.y"
    {
       		(yyval.nvval) = new_tag_attributeset((yyvsp[(1) - (3)].cval), (yyvsp[(3) - (3)].cval)); 
	}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 742 "gtkdialog_parser.y"
    { 
       		(yyval.nvval) = add_tag_attribute((yyvsp[(1) - (4)].nvval), (yyvsp[(2) - (4)].cval), (yyvsp[(4) - (4)].cval)); 
	}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 749 "gtkdialog_parser.y"
    { 
		token_store(SHOW);     
	}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 752 "gtkdialog_parser.y"
    {
  		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
	}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 755 "gtkdialog_parser.y"
    {
		instruction_set_jump((yyvsp[(4) - (6)].ival), (yyvsp[(6) - (6)].ival) + 1);
		instruction_set_jump((yyvsp[(6) - (6)].ival) + 1, (yyvsp[(1) - (6)].ival));
	}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 762 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMASSG | VARIABLE_NAME, (yyvsp[(1) - (4)].cval)); 
	}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 768 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | VARIABLE_NAME, (yyvsp[(1) - (1)].cval)); 
	}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 771 "gtkdialog_parser.y"
    {
		token_store_with_argument(IMPUSH | CONST_NUMBER, (yyvsp[(1) - (1)].cval)); 
  	}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 774 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_ADD);
	}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 777 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_SUBST);
	}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 780 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_MULT);
	}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 783 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | OP_DIV);
	}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 786 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_EQ);
	}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 789 "gtkdialog_parser.y"
    {
  		token_store(IMPUSH | REL_NE);
	}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 799 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 806 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 810 "gtkdialog_parser.y"
    { (yyval.ival) = instruction_get_pc(); }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 814 "gtkdialog_parser.y"
    {
		token_store(GOTO); 
		(yyval.ival) = instruction_get_pc();
	}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 821 "gtkdialog_parser.y"
    { 
		token_store(IFNGOTO); 
		(yyval.ival) = instruction_get_pc();
    }
    break;



/* Line 1455 of yacc.c  */
#line 4226 "gtkdialog_parser.c"
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
#line 827 "gtkdialog_parser.y"


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


