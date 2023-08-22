/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 18 "src/compiler.y"
	
	#include <stdio.h>
	#include "../include/AbsSynTree.h"
	#include<string.h>
	//#define YYSTYPE double
	int yylex();
	void yyerror( char* );
        int i;	
        int cnt=0;
		 struct arrtype* cratfirst(char *s);//
		 struct arrtype* crat(struct arrtype * ar,int n);//
		 struct glis * arcrgli(struct arrtype *ar);//
		void joinglis(struct glis * hd,struct glis * nw);//
		void joingdec(struct glis * nw,int ty);//50
	
		struct varlis *crvhead(char *s);
		void joinv(struct varlis*head,char *s);
		struct nptlist * nphd;
		struct gdec * headgd;
		struct nptlist * crhnpt();

		struct nptstmt * sts(stmtp vale,struct nptstmt *f,struct nptlist* ff,struct nptlist *ss,int nu,struct varlis*vv,char *se);

		struct nptstmt * exprs(struct nptstmt* left,struct nptstmt* right,operat valu,stmtp vale);

		void joinnpt(struct nptlist *head,struct nptstmt *sm);
		struct nptstmt* ttt;
		struct symtab{
			char * nam;
		int tp;
		int *val;
		int size;//0 for variable

		}smt[50];
		int symcnt;
		int sfind(char *s);
		void sinsert(struct arrtype *temp,int typ);
		
		void executegd();

		void synprint(int type,struct nptlist *li,struct nptstmt * sta);
		void stupdate(char * s,int n,int v);
		int stval(char * s,int n);
		void prinvlis(struct varlis *v);
		
		void evprinvlis(struct varlis *v);
		int evaluate(int type,struct nptlist *li,struct nptstmt * sta);
		void stprint();
		int rtty;

#line 121 "src/y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SRC_Y_TAB_H_INCLUDED
# define YY_YY_SRC_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BEG = 258,
    END = 259,
    T_INT = 260,
    T_BOOL = 261,
    WRITE = 262,
    DECL = 263,
    ENDDECL = 264,
    NUM = 265,
    VAR = 266,
    IF = 267,
    THEN = 268,
    ELSE = 269,
    ENDIF = 270,
    LOGICAL_AND = 271,
    LOGICAL_NOT = 272,
    LOGICAL_OR = 273,
    EQUALEQUAL = 274,
    LESSTHANOREQUAL = 275,
    GREATERTHANOREQUAL = 276,
    NOTEQUAL = 277,
    WHILE = 278,
    DO = 279,
    ENDWHILE = 280,
    FOR = 281,
    T = 282,
    F = 283,
    MAIN = 284,
    RETURN = 285
  };
#endif
/* Tokens.  */
#define BEG 258
#define END 259
#define T_INT 260
#define T_BOOL 261
#define WRITE 262
#define DECL 263
#define ENDDECL 264
#define NUM 265
#define VAR 266
#define IF 267
#define THEN 268
#define ELSE 269
#define ENDIF 270
#define LOGICAL_AND 271
#define LOGICAL_NOT 272
#define LOGICAL_OR 273
#define EQUALEQUAL 274
#define LESSTHANOREQUAL 275
#define GREATERTHANOREQUAL 276
#define NOTEQUAL 277
#define WHILE 278
#define DO 279
#define ENDWHILE 280
#define FOR 281
#define T 282
#define F 283
#define MAIN 284
#define RETURN 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 68 "src/compiler.y"

	int iValue;
	char * sindex;
	struct varlis*vl;
	struct arrtype*at;
	struct glis*gl;
	struct nptstmt * npt;
	struct nptlist * nptlis;
	struct gdec*gd;

#line 244 "src/y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   222

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

#define YYUNDEFTOK  2
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    46,     2,     2,    37,     2,     2,
      42,    43,    35,    33,    39,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
      31,    47,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   107,   107,   110,   113,   114,   117,   120,   121,   124,
     125,   128,   129,   133,   136,   138,   139,   143,   149,   150,
     153,   154,   155,   158,   159,   163,   166,   167,   168,   171,
     172,   173,   174,   175,   176,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   190,   191,   194,   195
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BEG", "END", "T_INT", "T_BOOL", "WRITE",
  "DECL", "ENDDECL", "NUM", "VAR", "IF", "THEN", "ELSE", "ENDIF",
  "LOGICAL_AND", "LOGICAL_NOT", "LOGICAL_OR", "EQUALEQUAL",
  "LESSTHANOREQUAL", "GREATERTHANOREQUAL", "NOTEQUAL", "WHILE", "DO",
  "ENDWHILE", "FOR", "T", "F", "MAIN", "RETURN", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "';'", "','", "'['", "']'", "'('", "')'",
  "'{'", "'}'", "'\"'", "'='", "$accept", "Prog", "Gdecl_sec",
  "Gdecl_list", "Gdecl", "ret_type", "Glist", "Gid", "ret_stmt",
  "MainBlock", "func_ret_type", "main", "stmt_list", "statement",
  "write_stmt", "assign_stmt", "cond_stmt", "expr", "str_expr", "var_expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    60,    62,    43,    45,    42,    47,    37,    59,    44,
      91,    93,    40,    41,   123,   125,    34,    61
};
# endif

#define YYPACT_NINF (-60)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,     7,    21,    41,   -60,   -60,    40,     7,    15,   -60,
     -60,   -60,   -60,    24,   -60,   -60,   -60,    19,    22,   -60,
      23,   -60,    15,    53,    28,    22,    37,    56,   -60,    94,
     -60,    43,    57,   -60,    17,    17,    17,    97,   -60,    64,
      65,   -60,   -36,    14,   -60,   -60,   -60,   106,    17,    48,
      78,   136,   116,    59,   -60,   -60,    17,    17,   108,    55,
     -60,    74,   -60,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,   -60,   -60,   -60,    93,   143,   -60,
      -3,   -60,   -60,   193,   -17,   -17,   -17,   -17,   162,   162,
     -30,   -30,    83,    83,   -60,   178,   -60,   -60,    79,   -60,
     -60,    85,   -60,   199,   -60,   -60
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     0,     0,     7,     8,     0,     4,     0,     1,
      15,    16,     2,     0,     3,     5,    11,     0,     9,    17,
       0,     6,     0,     0,     0,    10,     0,     0,    12,     0,
      18,     0,     0,    48,     0,     0,     0,     0,    19,     0,
       0,    22,     0,     0,    29,    32,    33,     0,     0,     0,
      31,     0,     0,     0,    21,    20,     0,     0,     0,     0,
      30,     0,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    13,    14,     0,    25,    46,
       0,    23,    34,     0,    45,    43,    42,    44,    40,    41,
      35,    36,    37,    38,    39,     0,    49,    47,     0,    18,
      26,     0,    24,     0,    28,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,   -60,   114,   -60,   -60,   -60,   109,   -60,   -60,
     -60,   -60,   -59,   -60,   -60,   -60,   -60,   -34,   -60,   -31
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     6,     7,     8,    17,    18,    37,    12,
      13,    20,    31,    38,    39,    40,    41,    49,    80,    50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      42,    51,    52,    83,    56,    71,    72,    73,    97,    59,
       1,    57,     4,     5,    61,    95,    69,    70,    71,    72,
      73,     9,    77,    78,    44,    33,    16,    44,    33,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
     103,    45,    46,    98,    45,    46,    10,    11,    47,    14,
      32,    47,    42,    19,    33,    34,    48,    21,    22,    48,
      58,    62,    23,    26,    42,    24,    35,    63,    64,    65,
      66,    27,    42,    36,    63,    64,    65,    66,    28,    67,
      68,    69,    70,    71,    72,    73,    67,    68,    69,    70,
      71,    72,    73,    63,    64,    65,    66,    30,    81,    43,
      29,    53,    54,    55,    76,    67,    68,    69,    70,    71,
      72,    73,    63,    64,    65,    66,    60,    82,    56,    79,
      73,    15,   102,   104,    67,    68,    69,    70,    71,    72,
      73,    25,     0,     0,    96,    63,    64,    65,    66,     0,
       0,     0,     0,     0,     0,     0,     0,    67,    68,    69,
      70,    71,    72,    73,    75,    63,    64,    65,    66,     0,
      74,     0,    63,    64,    65,    66,     0,    67,    68,    69,
      70,    71,    72,    73,    67,    68,    69,    70,    71,    72,
      73,    63,    64,    65,    66,    32,     0,     0,     0,    33,
      34,     0,     0,     0,     0,    69,    70,    71,    72,    73,
      32,    35,     0,   101,    33,    34,    32,    99,   100,     0,
      33,    34,     0,     0,   105,     0,    35,     0,     0,     0,
       0,     0,    35
};

static const yytype_int8 yycheck[] =
{
      31,    35,    36,    62,    40,    35,    36,    37,    11,    43,
       8,    47,     5,     6,    48,    74,    33,    34,    35,    36,
      37,     0,    56,    57,    10,    11,    11,    10,    11,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      99,    27,    28,    46,    27,    28,     5,     6,    34,     9,
       7,    34,    83,    29,    11,    12,    42,    38,    39,    42,
      46,    13,    40,    10,    95,    42,    23,    19,    20,    21,
      22,    43,   103,    30,    19,    20,    21,    22,    41,    31,
      32,    33,    34,    35,    36,    37,    31,    32,    33,    34,
      35,    36,    37,    19,    20,    21,    22,     3,    43,    42,
      44,     4,    38,    38,    45,    31,    32,    33,    34,    35,
      36,    37,    19,    20,    21,    22,    10,    43,    40,    11,
      37,     7,    43,    38,    31,    32,    33,    34,    35,    36,
      37,    22,    -1,    -1,    41,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    19,    20,    21,    22,    -1,
      24,    -1,    19,    20,    21,    22,    -1,    31,    32,    33,
      34,    35,    36,    37,    31,    32,    33,    34,    35,    36,
      37,    19,    20,    21,    22,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,
       7,    23,    -1,    25,    11,    12,     7,    14,    15,    -1,
      11,    12,    -1,    -1,    15,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    49,    50,     5,     6,    51,    52,    53,     0,
       5,     6,    57,    58,     9,    51,    11,    54,    55,    29,
      59,    38,    39,    40,    42,    55,    10,    43,    41,    44,
       3,    60,     7,    11,    12,    23,    30,    56,    61,    62,
      63,    64,    67,    42,    10,    27,    28,    34,    42,    65,
      67,    65,    65,     4,    38,    38,    40,    47,    46,    65,
      10,    65,    13,    19,    20,    21,    22,    31,    32,    33,
      34,    35,    36,    37,    24,    38,    45,    65,    65,    11,
      66,    43,    43,    60,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    60,    41,    11,    46,    14,
      15,    25,    43,    60,    38,    15
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    51,    51,    52,    53,    53,    54,
      54,    55,    55,    56,    57,    58,    58,    59,    60,    60,
      61,    61,    61,    62,    62,    63,    64,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    66,    66,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     0,     2,     3,     1,     1,     1,
       3,     1,     4,     3,    10,     1,     1,     1,     0,     2,
       2,     2,     1,     4,     6,     3,     5,     7,     6,     1,
       2,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     2,     1,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 107 "src/compiler.y"
                                            {/*final execution done from here*/}
#line 1509 "src/y.tab.c"
    break;

  case 3:
#line 110 "src/compiler.y"
                                               {/*this will itself be a linked list */}
#line 1515 "src/y.tab.c"
    break;

  case 5:
#line 114 "src/compiler.y"
                                         {/*start node will be attatched to linked list  here*/}
#line 1521 "src/y.tab.c"
    break;

  case 6:
#line 117 "src/compiler.y"
                                            {joingdec((yyvsp[-1].gl),(yyvsp[-2].iValue));/*create head for this linked list here .*/}
#line 1527 "src/y.tab.c"
    break;

  case 7:
#line 120 "src/compiler.y"
                                        { (yyval.iValue)=1;/*make rrty gb var as 1 , so that we know this waas int */}
#line 1533 "src/y.tab.c"
    break;

  case 8:
#line 121 "src/compiler.y"
                                        { (yyval.iValue)=0;}
#line 1539 "src/y.tab.c"
    break;

  case 9:
#line 124 "src/compiler.y"
                                {(yyval.gl)=arcrgli((yyvsp[0].at));/*puts("end");*//*attach this to glist*/}
#line 1545 "src/y.tab.c"
    break;

  case 10:
#line 125 "src/compiler.y"
                                      {joinglis((yyvsp[-2].gl),arcrgli((yyvsp[0].at)));(yyval.gl)=(yyvsp[-2].gl);/*printf("%d ",cnt++);*/}
#line 1551 "src/y.tab.c"
    break;

  case 11:
#line 128 "src/compiler.y"
                                        { (yyval.at)=cratfirst((yyvsp[0].sindex));/*keep counting the num if 0 then var else array .*/}
#line 1557 "src/y.tab.c"
    break;

  case 12:
#line 129 "src/compiler.y"
                                        {         (yyval.at)=crat((yyvsp[-3].at),(yyvsp[-1].iValue));                 }
#line 1563 "src/y.tab.c"
    break;

  case 13:
#line 133 "src/compiler.y"
                                        { 					}
#line 1569 "src/y.tab.c"
    break;

  case 14:
#line 136 "src/compiler.y"
                                                                                                { 	nphd=(yyvsp[-3].nptlis);rtty=(yyvsp[-9].iValue);			  	  }
#line 1575 "src/y.tab.c"
    break;

  case 15:
#line 138 "src/compiler.y"
                                        { (yyval.iValue)=1;/*make rrty gb var as 1 , so that we know this waas int */}
#line 1581 "src/y.tab.c"
    break;

  case 16:
#line 139 "src/compiler.y"
                                { (yyval.iValue)=0;}
#line 1587 "src/y.tab.c"
    break;

  case 17:
#line 143 "src/compiler.y"
                                        { 					}
#line 1593 "src/y.tab.c"
    break;

  case 18:
#line 149 "src/compiler.y"
                                                {(yyval.nptlis)=(struct nptlist *)malloc(sizeof(struct nptlist)); /*puts("first");*/ }
#line 1599 "src/y.tab.c"
    break;

  case 19:
#line 150 "src/compiler.y"
                                                { joinnpt((yyvsp[-1].nptlis),(yyvsp[0].npt));(yyval.nptlis)=(yyvsp[-1].nptlis);/*puts("lst")*/;						}
#line 1605 "src/y.tab.c"
    break;

  case 20:
#line 153 "src/compiler.y"
                                                        { 	(yyval.npt)=(yyvsp[-1].npt);/*puts("ass");*/						 }
#line 1611 "src/y.tab.c"
    break;

  case 21:
#line 154 "src/compiler.y"
                                                { (yyval.npt)=(yyvsp[-1].npt);/*puts("writte");*/}
#line 1617 "src/y.tab.c"
    break;

  case 22:
#line 155 "src/compiler.y"
                                                { (yyval.npt)=(yyvsp[0].npt);/*puts("condstmt");*/}
#line 1623 "src/y.tab.c"
    break;

  case 23:
#line 158 "src/compiler.y"
                                                        {(yyval.npt)=sts(writeexp,(yyvsp[-1].npt),NULL,NULL,0,NULL,NULL);  }
#line 1629 "src/y.tab.c"
    break;

  case 24:
#line 159 "src/compiler.y"
                                                     { (yyval.npt)=sts(writestmt,NULL,NULL,NULL,0,(yyvsp[-2].vl),NULL);}
#line 1635 "src/y.tab.c"
    break;

  case 25:
#line 163 "src/compiler.y"
                                                { 	(yyval.npt)=exprs((yyvsp[-2].npt),(yyvsp[0].npt),eqt,assstmt);/*puts("assins");*/					}
#line 1641 "src/y.tab.c"
    break;

  case 26:
#line 166 "src/compiler.y"
                                                        {(yyval.npt)=sts(iff,(yyvsp[-3].npt),(yyvsp[-1].nptlis),NULL,0,NULL,NULL); 	/*puts("condstmt");*/}
#line 1647 "src/y.tab.c"
    break;

  case 27:
#line 167 "src/compiler.y"
                                                                        { (yyval.npt)=sts(ifelse,(yyvsp[-5].npt),(yyvsp[-3].nptlis),(yyvsp[-1].nptlis),0,NULL,NULL);		}
#line 1653 "src/y.tab.c"
    break;

  case 28:
#line 168 "src/compiler.y"
                                                            { (yyval.npt)=sts(whle,(yyvsp[-4].npt),(yyvsp[-2].nptlis),NULL,0,NULL,NULL);	 	/*puts("condstmt");*/				}
#line 1659 "src/y.tab.c"
    break;

  case 29:
#line 171 "src/compiler.y"
                                                        { (yyval.npt)=sts(exp,NULL,NULL,NULL,(yyvsp[0].iValue),NULL,NULL)	;	}
#line 1665 "src/y.tab.c"
    break;

  case 30:
#line 172 "src/compiler.y"
                                                {  		(yyval.npt)=sts(exp,NULL,NULL,NULL,-(yyvsp[0].iValue),NULL,NULL)	;				   }
#line 1671 "src/y.tab.c"
    break;

  case 31:
#line 173 "src/compiler.y"
                                                { 	(yyval.npt)=(yyvsp[0].npt);		}
#line 1677 "src/y.tab.c"
    break;

  case 32:
#line 174 "src/compiler.y"
                                                { 		(yyval.npt)=sts(exp,NULL,NULL,NULL,1,NULL,NULL)	;				  	}
#line 1683 "src/y.tab.c"
    break;

  case 33:
#line 175 "src/compiler.y"
                                                { 	(yyval.npt)=sts(exp,NULL,NULL,NULL,0,NULL,NULL)	;}
#line 1689 "src/y.tab.c"
    break;

  case 34:
#line 176 "src/compiler.y"
                                                {  (yyval.npt)=(yyvsp[-1].npt);			}
#line 1695 "src/y.tab.c"
    break;

  case 35:
#line 178 "src/compiler.y"
                                                { (yyval.npt)=exprs((yyvsp[-2].npt),(yyvsp[0].npt),plus,exp);	}
#line 1701 "src/y.tab.c"
    break;

  case 36:
#line 179 "src/compiler.y"
                                                { 	(yyval.npt)=exprs((yyvsp[-2].npt),(yyvsp[0].npt),minus,exp);					}
#line 1707 "src/y.tab.c"
    break;

  case 37:
#line 180 "src/compiler.y"
                                                { 			(yyval.npt)=exprs((yyvsp[-2].npt),(yyvsp[0].npt),multiply,exp);}
#line 1713 "src/y.tab.c"
    break;

  case 38:
#line 181 "src/compiler.y"
                                                { 		(yyval.npt)=exprs((yyvsp[-2].npt),(yyvsp[0].npt),divide,exp);			}
#line 1719 "src/y.tab.c"
    break;

  case 39:
#line 182 "src/compiler.y"
                                                { 	(yyval.npt)=exprs((yyvsp[-2].npt),(yyvsp[0].npt),rem,exp);					}
#line 1725 "src/y.tab.c"
    break;

  case 40:
#line 183 "src/compiler.y"
                                                { 			(yyval.npt)=exprs((yyvsp[-2].npt),(yyvsp[0].npt),lt,exp);			}
#line 1731 "src/y.tab.c"
    break;

  case 41:
#line 184 "src/compiler.y"
                                                { 			(yyval.npt)=exprs((yyvsp[-2].npt),(yyvsp[0].npt),gt,exp);			}
#line 1737 "src/y.tab.c"
    break;

  case 42:
#line 185 "src/compiler.y"
                                                                                { 				(yyval.npt)=exprs((yyvsp[-2].npt),(yyvsp[0].npt),gte,exp);		}
#line 1743 "src/y.tab.c"
    break;

  case 43:
#line 186 "src/compiler.y"
                                                        {  		(yyval.npt)=exprs((yyvsp[-2].npt),(yyvsp[0].npt),lte,exp);				}
#line 1749 "src/y.tab.c"
    break;

  case 44:
#line 187 "src/compiler.y"
                                                        { 		(yyval.npt)=exprs((yyvsp[-2].npt),(yyvsp[0].npt),nt,exp);				}
#line 1755 "src/y.tab.c"
    break;

  case 45:
#line 188 "src/compiler.y"
                                                { 		(yyval.npt)=exprs((yyvsp[-2].npt),(yyvsp[0].npt),ee,exp);				}
#line 1761 "src/y.tab.c"
    break;

  case 46:
#line 190 "src/compiler.y"
                                              {(yyval.vl)=crvhead((yyvsp[0].sindex));}
#line 1767 "src/y.tab.c"
    break;

  case 47:
#line 191 "src/compiler.y"
                                   {joinv((yyvsp[-1].vl),(yyvsp[0].sindex));(yyval.vl)=(yyvsp[-1].vl); }
#line 1773 "src/y.tab.c"
    break;

  case 48:
#line 194 "src/compiler.y"
                                { 	(yyval.npt)=sts(varexa,NULL,NULL,NULL,0,NULL,(yyvsp[0].sindex));			  }
#line 1779 "src/y.tab.c"
    break;

  case 49:
#line 195 "src/compiler.y"
                                                {  ttt=(yyvsp[-3].npt);ttt->ifst=(yyvsp[-1].npt);(yyval.npt)=(yyvsp[-3].npt);                   }
#line 1785 "src/y.tab.c"
    break;


#line 1789 "src/y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 197 "src/compiler.y"

int main()
{
	symcnt=0;
headgd	=(struct gdec *)malloc(sizeof(struct gdec));
headgd->val =NULL;
headgd->next =NULL;
nphd = (struct nptlist *)malloc(sizeof(struct nptlist));
nphd->next=NULL;
yyparse();
puts("printing the tree ");
executegd();
if(rtty){printf("INT MAIN\n\n");}
else{puts("BOOL MAIN\n");}
synprint(1,nphd,NULL);
puts("\n\nevaluating ");
evaluate(1,nphd,NULL);
puts("\n\nprinting symbol table");
stprint();

}
void yyerror(char *s) {
fprintf(stdout, "%s\n", s);
}
struct varlis *crvhead(char *s)
{
	struct varlis *temp = (struct varlis *)malloc(sizeof(struct varlis));
	temp->nam = strdup(s);
	temp->next=NULL;
	return temp;
}
void joinv(struct varlis*head,char *s)
{
	struct varlis *p = (struct varlis *)malloc(sizeof(struct varlis));
	struct varlis*temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=p;
	p->next=NULL;
	p->nam=strdup(s);
}



struct arrtype* cratfirst(char *s)
{
	struct arrtype* temp=(struct arrtype*)malloc(sizeof(struct arrtype));
	temp->nam=strdup(s);
	temp->siz=0;
	return temp;
}


struct arrtype* crat(struct arrtype * ar,int n)
{
	ar->siz=n;
	return ar;
}

struct glis * arcrgli(struct arrtype *ar)
{
	struct glis* temp= (struct glis*)malloc(sizeof(struct glis));
	temp->wh=1;
	temp->nex=NULL;
	temp->at=ar;
	return temp;
}
// struct glis * fucrgli(struct fdecl *ar)
// {
// 	struct glis* temp= (struct glis*)malloc(sizeof(struct glis));
// 	temp->wh=2;
// 	temp->nex=NULL;
// 	temp->fu=ar;
// 	return temp;
// }
void joinglis(struct glis * hd,struct glis * nw)
{
	struct glis * temp=hd;
	while(temp->nex!=NULL)
	{
		temp=temp->nex;
	}
	temp->nex=nw;
	
}

void joingdec(struct glis * nw,int ty)
{
	struct gdec* ins =(struct gdec*)malloc(sizeof(struct gdec));
	struct gdec* temp=headgd;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	ins->val=nw;
	ins->typ=ty;
	ins->next=NULL;
	temp->next=ins;
	
}	


struct nptlist * crhnpt()
{
struct nptlist * temp =( struct nptlist *)malloc(sizeof(struct nptlist ));
temp->next=NULL;
}

struct nptstmt * sts(stmtp vale,struct nptstmt *f,struct nptlist* ff,struct nptlist *ss,int nu,struct varlis*vv,char *se)
{
	struct nptstmt * temp= (struct nptstmt *)malloc(sizeof(struct nptstmt));
	temp->wt=vale;
	switch (vale)
	{
	case ifelse/* constant-expression */:
		/* code */
		temp->wt=vale;
		temp->ifst=f;
		temp->ifl=ff;
		temp->elst=ss;
		break;
	case iff:
		temp->wt=vale;
		temp->ifst=f;
		temp->ifl=ff;
		break;
	case whle:
		temp->ifst=f;
		temp->ifl=ff;
		break;
	case writestmt:
		temp->vl=vv;
		break;
	case varexa:
		temp->s=se;
		temp->num=nu;
		break;
	case exp:
		// printf("num was %d\n",nu);
		temp->num=nu;
		// printf("num was %d\n",temp->num);
		temp->op=num;
		break;
	case writeexp:
		temp->ifst=f;
		break;
	default:
		break;
	}
	return temp;
}


struct nptstmt * exprs(struct nptstmt* left,struct nptstmt* right,operat valu,stmtp vale)
{
		struct nptstmt * temp = (struct nptstmt *)malloc(sizeof(struct nptstmt));
		temp->op=valu;
		temp->wt=vale;
		temp->exl=left;
		temp->exr=right;
		return temp;
}


void joinnpt(struct nptlist *head,struct nptstmt *sm)
{

	struct nptlist *p = (struct nptlist *)malloc(sizeof(struct nptlist));
	struct nptlist *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=p;
	temp->val=sm;
	p->next=NULL;
	// p->val=sm;
}
int sfind(char *s)
{
	// puts(s);
	for(int i=0;i<symcnt;i++)
	{
		if(strcmp(smt[i].nam,s)==0)
		{return 0;}
	}
	return 1;
}
void sinsert(struct arrtype *temp,int typ)
{
	// puts(temp->nam);
	if(sfind(temp->nam))
	{
			smt[symcnt].nam=temp->nam;
			if(temp->siz!=0)
			{
				printf("ARR VAR %d",temp->siz);
				smt[symcnt].tp=typ;
				smt[symcnt].size=temp->siz;
				smt[symcnt].val=(int *)malloc((temp->siz)*sizeof(int));
			}
			else
			{
				printf("VAR ");
				smt[symcnt].tp=typ;

				smt[symcnt].size=0;

				smt[symcnt].val=(int *)malloc((1)*sizeof(int));
			}
			symcnt++;
	}
	else
	{
		printf("error: name already exists");
	}
}
void stupdate(char * s,int n,int v)
{int *x;
// puts(s);
int aa=0;
	for(int i=0;i<symcnt;i++)
	{
		if(strcmp(smt[i].nam,s)==0)
		{
			aa=1;
			// printf("%dth,elemnet\n",i);
			if(smt[i].size==0)
			{
				x=smt[i].val;
				*x=v;
				if(!smt[i].tp&&!(v==0||v==1))
				{
					puts("warning : assigning integer value to bool variable");
				}
			}
			else
			{
				x=smt[i].val;
				*(x+n)=v;
				if(!smt[i].tp&&!(v==0||v==1))
				{
					puts("warning : assigning integer value to bool variable");
				}
			}
			return ;
		}
	}
	if(!aa)
	{
		puts("cant update a name that doesnot exist");
	}
}

void stprint()
{
	for(int i=0;i<symcnt;i++)
	{
		if(smt[i].size==0)
		{
				printf("%s = %d\n",smt[i].nam,*(smt[i].val));
		}
		else
		{
				for(int k=0;k<smt[i].size;k++)
				printf("%s [%d] = %d\n",smt[i].nam,k,*(smt[i].val+k));
		}
	}
}
int stval(char * s,int n)
{int *x;
// puts(s);
	for(int i=0;i<symcnt;i++)
	{
		if(strcmp(smt[i].nam,s)==0)
		{
			if(smt[i].size==0)
			{
				x=smt[i].val;
				return *x;
			}
			else
			{
				x=smt[i].val;
				return *(x+n);
			}
		}
	}
	printf("%s this variable doesnot exist1",s);
	return 0;
}
void prinvlis(struct varlis *v)
{
	struct varlis * temp = v;
	while(1)
	{
		printf("VAR ");
		if(temp->next==NULL)
		{
			break;
		}
		temp=temp->next;
	}
}

void evprinvlis(struct varlis *v)
{
	struct varlis * temp = v;
	printf("writing ");
	while(1)
	{
		printf("%d ",stval(temp->nam,0));
		if(temp->next==NULL)
		{
			break;
		}
		temp=temp->next;
	}
}
void executegd()
{
	// puts("hello!");
	struct gdec*temp =headgd;
	temp=temp->next;
	while(temp->val!=NULL)
	{
		
		struct glis * temp2=temp->val;
		printf("DECL ");
		if(temp->typ)
		{
			printf("INT ");
		}
		else
		{
			printf("BOOL ");
		}
		while(1)
		{

			sinsert(temp2->at,temp->typ);
			if(temp2->nex==NULL)
			{

				break;
			}
			printf(",");
			temp2=temp2->nex;
		}
		puts(" ");
		if(temp->next==NULL)
		{
			//puts("reached here");
			break;
		}
		temp=temp->next;
	}
}
void synprint(int type,struct nptlist *li,struct nptstmt * sta)
{
	
	if(type==1)
	{
		// puts("hello");
		// if(li==NULL)
		// {
		// 	puts("NULL");
		// }
		struct nptlist *temp=li;
		while(temp->val!=NULL)
		{
			struct nptstmt *temps=temp->val;
			switch(temps->wt)
			{
				case ifelse:
				printf("IF ")				;
				synprint(2,NULL,temps->ifst);
				puts(" ");
				synprint(1,temps->ifl,NULL);
				printf("ELSE ");
				synprint(1,temps->elst,NULL);
				puts(" ");
				puts("ENDIF ");
				break;
				case iff:
				printf("IF ")				;
				synprint(2,NULL,temps->ifst);
				puts(" ");
				synprint(1,temps->ifl,NULL);
				puts(" ");
				puts("ENDIF ");
				break;
				case whle:
				printf("WHILE ");
				synprint(2,NULL,temps->ifst);
				puts(" ");
				synprint(1,temps->ifl,NULL);
				puts("ENDWHILE ");
				break;
				case assstmt:
				printf("ASSIGN ");
				synprint(2,NULL,temps->exl);
				synprint(2,NULL,temps->exr);
				puts(" ");
				break;
				case writestmt:
				printf("FUNCALL ");
				prinvlis(temps->vl);
				break;
				case writeexp:
				printf("FUNCALL ");
				synprint(2,NULL,temps->ifst);
				puts(" ");
				break;
				case exp:
					switch(temps->op)
					{
						case plus:
						printf("PLUS ");
						break;
						case minus:
						printf("MINUS ");
						break;
						case multiply:
						printf("MULTIPLY ");
						break;
						case divide:
						printf("DIVIDE ");
						break;
						case rem:
						printf("REMAINDER ");
						break;
						case gt:
						printf("GREATERTHAN ");
						break;
						case lt:
						printf("LESSTHAN ");
						break;
						case gte:
						printf("GREATERTHANEQUAL ");
						break;
						case lte:
						printf("LESSTHANEQUAL ");
						break;
						case ee:
						printf("EQUALEQUAL ");
						break;
						case nt:
						printf("NOTEQUALTO ");
						break;
						case num:
						printf("NUM ");
						break;
					}
					if(temps->op!=num)
					{
						synprint(2,NULL,temps->exl);
						synprint(2,NULL,temps->exr);
					}
					puts(" ");
					break;
					case varexa:
					if(temps->ifst==NULL)
					{printf("VAR ");}
					else
					{
						printf("ARREF VAR NUM");
					}
					break;
			}
			if(temp->next!=NULL) {
				temp=temp->next;
			}
			else
			{break;}
		}
	}
	else
	{
		struct nptstmt *temps=sta;
			switch(temps->wt)
			{
				case ifelse:
				printf("IF ")				;
				synprint(2,NULL,temps->ifst);
				puts(" ");
				synprint(1,temps->ifl,NULL);
				printf("ELSE ");
				synprint(1,temps->elst,NULL);
				puts(" ");
				break;
				case iff:
				printf("IF ")				;
				synprint(2,NULL,temps->ifst);
				puts(" ");
				synprint(1,temps->ifl,NULL);
				puts(" ");
				break;
				case whle:
				printf("WHILE ");
				synprint(2,NULL,temps->ifst);
				puts(" ");
				synprint(1,temps->ifl,NULL);
				break;
				case assstmt:
				printf("ASSIGN ");
				synprint(2,NULL,temps->exl);
				synprint(2,NULL,temps->exr);
				puts(" ");
				break;
				case writestmt:
				printf("FUNCALL ");
				prinvlis(temps->vl);
				break;
				case writeexp:
				printf("FUNCALL ");
				synprint(2,NULL,temps->ifst);
				puts(" ");
				break;
				case exp:
					switch(temps->op)
					{
						case plus:
						printf("PLUS ");
						break;
						case minus:
						printf("MINUS ");
						break;
						case multiply:
						printf("MULTIPLY ");
						break;
						case divide:
						printf("DIVIDE ");
						break;
						case rem:
						printf("REMAINDER ");
						break;
						case gt:
						printf("GREATERTHAN ");
						break;
						case lt:
						printf("LESSTHAN ");
						break;
						case gte:
						printf("GREATERTHANEQUAL ");
						break;
						case lte:
						printf("LESSTHANEQUAL ");
						break;
						case ee:
						printf("EQUALEQUAL ");
						break;
						case nt:
						printf("NOTEQUALTO ");
						break;
						case num:
						printf("NUM ");
						break;
					}
					if(temps->op!=num)
					{
						synprint(2,NULL,temps->exl);
						synprint(2,NULL,temps->exr);
					}
					puts(" ");
					break;
					case varexa:
					if(temps->ifst==NULL)
					{printf("VAR ");}
					else
					{
						printf("ARREF VAR ");
						synprint(2,NULL,temps->ifst);
					}
					break;
			}
	}
}

int evaluate(int type,struct nptlist *li,struct nptstmt * sta)
{
	// puts("HELLO EVALUATING")	;
	if(type==1)
	{
		// puts("hello");
		// if(li==NULL)
		// {
		// 	puts("NULL");
		// }
		struct nptlist *temp=li;
		while(temp->val!=NULL)
		{
			struct nptstmt *temps=temp->val;
			switch(temps->wt)
			{
				case ifelse:
				// printf("IF ")				;
				if(evaluate(2,NULL,temps->ifst))
				{
				evaluate(1,temps->ifl,NULL);
				}
				else{evaluate(1,temps->elst,NULL);}
				// return 0;
				break;
				case iff:
				if(evaluate(2,NULL,temps->ifst))
				{
				evaluate(1,temps->ifl,NULL);
				}
				// return 0;
				break;
				case whle:
				
				// printf("WHILE ");
				while(evaluate(2,NULL,temps->ifst))
				{
					// puts("inwhile");

				evaluate(1,temps->ifl,NULL);
				}	
				// return 0;
				break;
				case assstmt:
				// printf("ASSIGN ");
				// synprint(2,NULL,temps->exl);
					if(temps->exl->ifst==NULL)
					{  
						// puts("assigning var");
						  stupdate(temps->exl->s,0,evaluate(2,NULL,temps->exr));
						// return 0;
						}
					else
					{
						stupdate(temps->exl->s,evaluate(2,NULL,temps->exl->ifst),evaluate(2,NULL,temps->exr));
						// return 0;
						}
				// synprint(2,NULL,temps->exr);
				break;
				case writestmt:
				// printf("FUNCALL ");
				evprinvlis(temps->vl);
				// return 0;
				// prinvlis(temps->vl);
				break;
				case writeexp:
				// printf("FUNCALL ");
				printf("writing %d\n",evaluate(2,NULL,temps->ifst));
				// return 0;
				break;
				case exp:
					switch(temps->op)
					{
						case plus:
						// printf("PLUS ");
						return (evaluate(2,NULL,temps->exl)+evaluate(2,NULL,temps->exr));
						break;
						case minus:
						// npnrintf("MINUS ");
						return (evaluate(2,NULL,temps->exl)-evaluate(2,NULL,temps->exr));
						break;
						case multiply:
						
						// printf("MULTIPLY ");
						return (evaluate(2,NULL,temps->exl)*evaluate(2,NULL,temps->exr));
						break;
						case divide:
						// printf("DIVIDE ");
						return (evaluate(2,NULL,temps->exl)/evaluate(2,NULL,temps->exr));
						break;
						case rem:
                        return (evaluate(2,NULL,temps->exl)%evaluate(2,NULL,temps->exr));
						// printf("REMAINDER ");
						break;
						case gt:
						// printf("GREATERTHAN ");
						return (evaluate(2,NULL,temps->exl)>evaluate(2,NULL,temps->exr))?1:0;
						break;
						case lt:
                        return (evaluate(2,NULL,temps->exl)<evaluate(2,NULL,temps->exr))?1:0;
						// printf("LESSTHAN ");
						break;
						case gte:
						// printf("GREATERTHANEQUAL ");
						return (evaluate(2,NULL,temps->exl)<=evaluate(2,NULL,temps->exr))?1:0;
						break;
						case lte:
						// printf("LESSTHANEQUAL ");
						return (evaluate(2,NULL,temps->exl)>=evaluate(2,NULL,temps->exr))?1:0;
						break;
						case ee:
						// printf("EQUALEQUAL ");
						return (evaluate(2,NULL,temps->exl)==evaluate(2,NULL,temps->exr))?1:0;
						break;
						case nt:
						// printf("NOTEQUALTO ");
						return (evaluate(2,NULL,temps->exl)!=evaluate(2,NULL,temps->exr))?1:0;
						break;
						case num:
						// printf("NUM ");
						return temps->num;
						break;
					}
					// if(temps->op!=num)
					// {
					// 	synprint(2,NULL,temps->exl);
					// 	synprint(2,NULL,temps->exr);
					// }
					break;
					case varexa:
					if(temps->ifst==NULL)
					{return stval(temps->s,0);}
					else
					{
						// synprint(2,NULL,temps->ifst);
						return stval(temps->s,evaluate(2,NULL,temps->ifst));
					}
					break;
			}

			if(temp->next!=NULL) {
				// puts("next temp");
				temp=temp->next;
			}
			else
			{break;}
		}
		return 0;
	}
	else
	{
		struct nptstmt *temps=sta;
			switch(temps->wt)
			{
				case ifelse:
				// printf("IF ")				;
				if(evaluate(2,NULL,temps->ifst))
				{
				evaluate(1,temps->ifl,NULL);
				}
				else{evaluate(1,temps->elst,NULL);}
				return 0;
				break;
				case iff:
				if(evaluate(2,NULL,temps->ifst))
				{
				evaluate(1,temps->ifl,NULL);
				}
				return 0;
				break;
				case whle:
				// printf("WHILE ");
				while(evaluate(2,NULL,temps->ifst))
				{
					// puts("inwhile");

				evaluate(1,temps->ifl,NULL);
				}	
				return 0;
				break;
				case assstmt:
				// printf("ASSIGN ");
				// synprint(2,NULL,temps->exl);
					if(temps->exl->ifst==NULL)
					{  
						// puts("assigning var");
						  stupdate(temps->exl->s,0,evaluate(2,NULL,temps->exr));
						return 0;}
					else
					{
						stupdate(temps->exl->s,evaluate(2,NULL,temps->exl->ifst),evaluate(2,NULL,temps->exr));
						return 0;}
				// synprint(2,NULL,temps->exr);
				break;
				case writestmt:
				// printf("FUNCALL ");
				evprinvlis(temps->vl);
				return 0;
				// prinvlis(temps->vl);
				break;
				case writeexp:
				// printf("FUNCALL ");
				printf("writing %d\n",evaluate(2,NULL,temps->ifst));
				return 0;
				break;
				case exp:
					switch(temps->op)
					{
						case plus:
						// printf("PLUS ");
						return (evaluate(2,NULL,temps->exl)+evaluate(2,NULL,temps->exr));
						break;
						case minus:
						// npnrintf("MINUS ");
						return (evaluate(2,NULL,temps->exl)-evaluate(2,NULL,temps->exr));
						break;
						case multiply:
						
						// printf("MULTIPLY ");
						return (evaluate(2,NULL,temps->exl)*evaluate(2,NULL,temps->exr));
						break;
						case divide:
						// printf("DIVIDE ");
						return (evaluate(2,NULL,temps->exl)/evaluate(2,NULL,temps->exr));
						break;
						case rem:
                        return (evaluate(2,NULL,temps->exl)%evaluate(2,NULL,temps->exr));
						// printf("REMAINDER ");
						break;
						case gt:
						// printf("GREATERTHAN ");
						return (evaluate(2,NULL,temps->exl)>evaluate(2,NULL,temps->exr))?1:0;
						break;
						case lt:
                        return (evaluate(2,NULL,temps->exl)<evaluate(2,NULL,temps->exr))?1:0;
						// printf("LESSTHAN ");
						break;
						case gte:
						// printf("GREATERTHANEQUAL ");
						return (evaluate(2,NULL,temps->exl)<=evaluate(2,NULL,temps->exr))?1:0;
						break;
						case lte:
						// printf("LESSTHANEQUAL ");
						return (evaluate(2,NULL,temps->exl)>=evaluate(2,NULL,temps->exr))?1:0;
						break;
						case ee:
						// printf("EQUALEQUAL ");
						return (evaluate(2,NULL,temps->exl)==evaluate(2,NULL,temps->exr))?1:0;
						break;
						case nt:
						// printf("NOTEQUALTO ");
						return (evaluate(2,NULL,temps->exl)!=evaluate(2,NULL,temps->exr))?1:0;
						break;
						case num:
						// printf("NUM ");
						// puts("returning num ");
						// if(temps->num==NULL)puts("suddenly NULL");
						// printf("of value %d",temps->num);
						return (temps->num);
						break;
					}
					// if(temps->op!=num)
					// {
					// 	synprint(2,NULL,temps->exl);
					// 	synprint(2,NULL,temps->exr);
					// }
					break;
					case varexa:
					if(temps->ifst==NULL)
					{return stval(temps->s,0);}
					else
					{
						// synprint(2,NULL,temps->ifst);
						return stval(temps->s,evaluate(2,NULL,temps->ifst));
					}
					break;
			}
	}
}
