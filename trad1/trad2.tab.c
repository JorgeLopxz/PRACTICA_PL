/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 4 "trad2.y"
                            // SECCION 1 Declaraciones de C-Yacc

#include <stdio.h>
#include <ctype.h>            // declaraciones para tolower
#include <string.h>           // declaraciones para cadenas
#include <stdlib.h>           // declaraciones para exit ()

#define FF fflush(stdout);    // para forzar la impresion inmediata

int yylex () ;
int yyerror () ;
char *mi_malloc (int) ;
char *gen_code (char *) ;
char *int_to_string (int) ;
char *char_to_string (char) ;
void add_local(char* nombre) ;
int es_local(char* nombre) ;
char* get_var_name(char* id) ;

char temp [2048] ;

// Abstract Syntax Tree (AST) Node Structure

typedef struct ASTnode t_node ;

struct ASTnode {
    char *op ;
    int type ;		// leaf, unary or binary nodes
    t_node *left ;
    t_node *right ;
} ;


// Definitions for explicit attributes

typedef struct s_attr {
    int value ;    // - Numeric value of a NUMBER 
    char *code ;   // - to pass IDENTIFIER names, and other translations 
    t_node *node ; // - for possible future use of AST
} t_attr ;

#define YYSTYPE t_attr


#line 116 "trad2.tab.c"

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

#include "trad2.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIF = 4,                    /* IDENTIF  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_MAIN = 7,                       /* MAIN  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_PUTS = 9,                       /* PUTS  */
  YYSYMBOL_PRINTF = 10,                    /* PRINTF  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_EQ = 13,                        /* EQ  */
  YYSYMBOL_NE = 14,                        /* NE  */
  YYSYMBOL_LE = 15,                        /* LE  */
  YYSYMBOL_GE = 16,                        /* GE  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_INC = 20,                       /* INC  */
  YYSYMBOL_DEC = 21,                       /* DEC  */
  YYSYMBOL_SWITCH = 22,                    /* SWITCH  */
  YYSYMBOL_CASE = 23,                      /* CASE  */
  YYSYMBOL_DEFAULT = 24,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 25,                     /* BREAK  */
  YYSYMBOL_26_ = 26,                       /* '='  */
  YYSYMBOL_27_ = 27,                       /* '<'  */
  YYSYMBOL_28_ = 28,                       /* '>'  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '*'  */
  YYSYMBOL_32_ = 32,                       /* '/'  */
  YYSYMBOL_33_ = 33,                       /* '%'  */
  YYSYMBOL_UNARY_SIGN = 34,                /* UNARY_SIGN  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_41_ = 41,                       /* ':'  */
  YYSYMBOL_42_ = 42,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_axioma = 44,                    /* axioma  */
  YYSYMBOL_def_func = 45,                  /* def_func  */
  YYSYMBOL_def_main = 46,                  /* def_main  */
  YYSYMBOL_def_otras = 47,                 /* def_otras  */
  YYSYMBOL_dec_var = 48,                   /* dec_var  */
  YYSYMBOL_dec_var_local = 49,             /* dec_var_local  */
  YYSYMBOL_integer_local = 50,             /* integer_local  */
  YYSYMBOL_lista_integer_local = 51,       /* lista_integer_local  */
  YYSYMBOL_bq_sent = 52,                   /* bq_sent  */
  YYSYMBOL_sentencia = 53,                 /* sentencia  */
  YYSYMBOL_op_inc_dec = 54,                /* op_inc_dec  */
  YYSYMBOL_st_while = 55,                  /* st_while  */
  YYSYMBOL_st_for = 56,                    /* st_for  */
  YYSYMBOL_st_if = 57,                     /* st_if  */
  YYSYMBOL_st_switch = 58,                 /* st_switch  */
  YYSYMBOL_lista_cases = 59,               /* lista_cases  */
  YYSYMBOL_case_item = 60,                 /* case_item  */
  YYSYMBOL_opt_default = 61,               /* opt_default  */
  YYSYMBOL_elem_print = 62,                /* elem_print  */
  YYSYMBOL_lista_print = 63,               /* lista_print  */
  YYSYMBOL_integer = 64,                   /* integer  */
  YYSYMBOL_lista_integer_global = 65,      /* lista_integer_global  */
  YYSYMBOL_r_integer = 66,                 /* r_integer  */
  YYSYMBOL_expresion = 67,                 /* expresion  */
  YYSYMBOL_termino = 68,                   /* termino  */
  YYSYMBOL_operando = 69                   /* operando  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_uint8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   364

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   281


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,     2,     2,    33,     2,     2,
      35,    36,    31,    29,    40,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    39,
      27,    26,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      25,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    80,    80,    87,    91,    95,    96,   106,   107,   116,
     117,   125,   129,   132,   137,   138,   145,   152,   159,   166,
     175,   177,   179,   182,   184,   188,   197,   210,   213,   217,
     227,   228,   232,   242,   243,   253,   254,   258,   260,   264,
     268,   270,   274,   276,   280,   281,   283,   285,   287,   289,
     291,   293,   295,   297,   299,   301,   303,   305,   309,   310,
     311,   313,   317,   319,   321
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIF",
  "INTEGER", "STRING", "MAIN", "WHILE", "PUTS", "PRINTF", "AND", "OR",
  "EQ", "NE", "LE", "GE", "IF", "ELSE", "FOR", "INC", "DEC", "SWITCH",
  "CASE", "DEFAULT", "BREAK", "'='", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "UNARY_SIGN", "'('", "')'", "'{'", "'}'", "';'", "','",
  "':'", "'!'", "$accept", "axioma", "def_func", "def_main", "def_otras",
  "dec_var", "dec_var_local", "integer_local", "lista_integer_local",
  "bq_sent", "sentencia", "op_inc_dec", "st_while", "st_for", "st_if",
  "st_switch", "lista_cases", "case_item", "opt_default", "elem_print",
  "lista_print", "integer", "lista_integer_global", "r_integer",
  "expresion", "termino", "operando", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-49)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -49,     4,    18,   -49,    14,   -14,   -49,   -49,   -13,     5,
       7,    19,    46,   -49,    54,   -49,    61,    33,    41,   -49,
       5,   -49,    32,   -49,    70,    48,    83,    50,    52,   -49,
       5,    56,   -49,    68,    64,    66,    67,    71,    76,    77,
     -49,    74,   -49,   -49,   -49,   -49,    70,   -49,   101,    24,
      24,   108,   109,    24,    -1,    24,   -49,    69,     5,   -49,
     -49,    13,    13,    24,    13,   267,   -49,   -49,   195,    80,
      78,   205,    81,   231,   -49,   -49,   -49,   -49,   241,   -49,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    86,   -49,    16,    87,    24,    91,   -49,
     322,   274,   331,   331,    51,    51,    51,    51,   -20,   -20,
     -49,   -49,   -49,   -49,   -49,   -49,   -30,   267,   -49,   166,
     106,   100,   -49,    16,   117,     9,   127,    40,   -49,   -49,
     -49,   113,    97,    98,    99,    96,   102,   -49,   104,   103,
     140,   144,   112,   -49,   -49,   -49,   -49,   114,   115,   -49,
     304,   323,   137,   -49,   -49,   154,   118,   121,   -49,   -49,
     -49,   -49
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,     0,     0,     1,     0,     0,     2,     5,     0,    42,
      39,     0,     3,     8,     0,    40,     0,     0,     0,    43,
      42,     9,     0,    41,    14,     0,     0,     0,     0,     9,
      42,    11,    10,     0,     0,     0,     0,     0,     0,     0,
       4,     0,    16,    18,    17,    19,    14,    12,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,    42,    63,
      62,     0,     0,     0,     0,    20,    44,    58,     0,     0,
       0,     0,     0,     0,     6,    13,    59,    60,     0,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,    64,
      46,    45,    47,    48,    50,    52,    49,    51,    53,    54,
      55,    56,    57,    14,    36,    37,     0,    35,    14,     0,
       0,     0,    22,     0,     0,     0,     0,    33,    30,    25,
      38,    27,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,    14,    14,    29,    14,     0,     0,    14,
       0,     0,     0,    23,    24,     0,     0,     0,    28,    26,
      32,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -49,   -49,   -49,   -49,   -49,   -49,   123,   -49,   -49,   -46,
     107,   -49,   -49,   -49,   -49,   -49,   -49,    26,   -49,    42,
     -49,   -49,   -49,    -6,   -48,   -49,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     6,     7,    12,     2,    24,    27,    31,    28,
      41,   134,    42,    43,    44,    45,   127,   128,   138,   115,
     116,     8,    10,    15,   117,    66,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    65,    68,    33,     3,    71,   122,    73,    35,    36,
     123,    90,    91,    92,    23,    78,    59,    60,     9,    59,
      60,    11,   114,     4,    47,     5,    13,    59,    60,   132,
     133,    14,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    61,    62,    16,    63,   119,
      18,    63,    75,    61,    62,    17,    33,    19,    64,    63,
      34,    35,    36,   126,   136,    20,    64,   121,    25,    37,
      21,    38,   124,    33,    39,    26,    22,    34,    35,    36,
      88,    89,    90,    91,    92,    29,    37,    30,    38,    32,
      40,    39,    76,    77,    49,    79,    48,   150,   151,    50,
     152,    51,    52,   155,    33,    58,    53,    74,    34,    35,
      36,    54,    55,    56,    69,    70,    94,    37,    95,    38,
      97,    33,    39,   113,   118,    34,    35,    36,   120,   126,
     135,   139,   140,   141,    37,   142,    38,   143,   129,    39,
     146,    33,   145,   144,   147,    34,    35,    36,   148,   149,
     153,   154,    46,   137,    37,   131,    38,   160,    33,    39,
     161,    72,    34,    35,    36,   130,     0,     0,     0,     0,
       0,    37,     0,    38,     0,   158,    39,    80,    81,    82,
      83,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,     0,     0,   125,    80,    81,    82,    83,
      84,    85,     0,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,    93,    86,    87,    88,    89,    90,    91,    92,     0,
       0,    96,    80,    81,    82,    83,    84,    85,     0,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,    98,    86,    87,
      88,    89,    90,    91,    92,     0,     0,    99,    80,    81,
      82,    83,    84,    85,     0,    80,     0,    82,    83,    84,
      85,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    86,    87,    88,    89,    90,    91,    92,    33,     0,
       0,     0,    34,    35,    36,     0,     0,     0,     0,     0,
       0,    37,     0,    38,     0,     0,    39,    33,     0,   156,
       0,    34,    35,    36,     0,    82,    83,    84,    85,     0,
      37,     0,    38,     0,     0,    39,    84,    85,   157,    86,
      87,    88,    89,    90,    91,    92,     0,     0,    86,    87,
      88,    89,    90,    91,    92
};

static const yytype_int16 yycheck[] =
{
      46,    49,    50,     4,     0,    53,    36,    55,     9,    10,
      40,    31,    32,    33,    20,    63,     3,     4,     4,     3,
       4,    35,     6,     5,    30,     7,    39,     3,     4,    20,
      21,    26,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    29,    30,    40,    35,    97,
       4,    35,    58,    29,    30,    36,     4,     3,    42,    35,
       8,     9,    10,    23,    24,     4,    42,   113,    36,    17,
      37,    19,   118,     4,    22,     5,    35,     8,     9,    10,
      29,    30,    31,    32,    33,    37,    17,     4,    19,    39,
      38,    22,    61,    62,    26,    64,    40,   143,   144,    35,
     146,    35,    35,   149,     4,     4,    35,    38,     8,     9,
      10,    35,    35,    39,     6,     6,    36,    17,    40,    19,
      39,     4,    22,    37,    37,     8,     9,    10,    37,    23,
       3,    18,    35,    35,    17,    36,    19,    41,    38,    22,
      37,     4,    38,    41,     4,     8,     9,    10,     4,    37,
      36,    36,    29,   127,    17,    38,    19,    39,     4,    22,
      39,    54,     8,     9,    10,   123,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    19,    -1,    38,    22,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    39,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    16,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    36,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    36,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    16,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    36,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    36,    11,    12,
      13,    14,    15,    16,    -1,    11,    -1,    13,    14,    15,
      16,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    27,    28,    29,    30,    31,    32,    33,     4,    -1,
      -1,    -1,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    19,    -1,    -1,    22,     4,    -1,    25,
      -1,     8,     9,    10,    -1,    13,    14,    15,    16,    -1,
      17,    -1,    19,    -1,    -1,    22,    15,    16,    25,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,    48,     0,     5,     7,    45,    46,    64,     4,
      65,    35,    47,    39,    26,    66,    40,    36,     4,     3,
       4,    37,    35,    66,    49,    36,     5,    50,    52,    37,
       4,    51,    39,     4,     8,     9,    10,    17,    19,    22,
      38,    53,    55,    56,    57,    58,    49,    66,    40,    26,
      35,    35,    35,    35,    35,    35,    39,    52,     4,     3,
       4,    29,    30,    35,    42,    67,    68,    69,    67,     6,
       6,    67,    53,    67,    38,    66,    69,    69,    67,    69,
      11,    12,    13,    14,    15,    16,    27,    28,    29,    30,
      31,    32,    33,    36,    36,    40,    36,    39,    36,    36,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    37,     6,    62,    63,    67,    37,    67,
      37,    52,    36,    40,    52,    39,    23,    59,    60,    38,
      62,    38,    20,    21,    54,     3,    24,    60,    61,    18,
      35,    35,    36,    41,    41,    38,    37,     4,     4,    37,
      52,    52,    52,    36,    36,    52,    25,    25,    38,    38,
      39,    39
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    46,    47,    47,    48,    48,    49,
      49,    50,    51,    51,    52,    52,    52,    52,    52,    52,
      53,    53,    53,    54,    54,    55,    56,    57,    57,    58,
      59,    59,    60,    61,    61,    62,    62,    63,    63,    64,
      65,    65,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    68,    68,
      68,    68,    69,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     7,     0,     8,     0,     3,     0,
       3,     2,     2,     4,     0,     3,     2,     2,     2,     2,
       3,     4,     6,     4,     4,     7,    11,     7,    11,     8,
       1,     2,     6,     0,     5,     1,     1,     1,     3,     2,
       2,     4,     0,     2,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     2,
       2,     2,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* axioma: dec_var def_func  */
#line 80 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                                printf ("%s\n", yyvsp[-1].code) ;
                                                              }
                                                              printf ("%s\n", yyvsp[0].code) ;
                                                            }
#line 1316 "trad2.tab.c"
    break;

  case 3: /* def_func: def_main def_otras  */
#line 87 "trad2.y"
                                                             { sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1323 "trad2.tab.c"
    break;

  case 4: /* def_main: MAIN '(' ')' '{' dec_var_local bq_sent '}'  */
#line 91 "trad2.y"
                                                                { sprintf (temp, "(defun main ()\n%s\n%s\n)", yyvsp[-2].code, yyvsp[-1].code) ;
                                                                  yyval.code = gen_code (temp) ; }
#line 1330 "trad2.tab.c"
    break;

  case 5: /* def_otras: %empty  */
#line 95 "trad2.y"
                                                             { yyval.code = gen_code ("") ; }
#line 1336 "trad2.tab.c"
    break;

  case 6: /* def_otras: def_otras IDENTIF '(' ')' '{' dec_var_local bq_sent '}'  */
#line 96 "trad2.y"
                                                                         {
                                                                if (strlen (yyvsp[-7].code) > 0) {
                                                                    sprintf (temp, "%s\n(defun %s ()\n%s\n%s\n)", yyvsp[-7].code, yyvsp[-6].code, yyvsp[-2].code, yyvsp[-1].code) ;
                                                                } else {
                                                                    sprintf (temp, "(defun %s ()\n%s\n%s\n)", yyvsp[-6].code, yyvsp[-2].code, yyvsp[-1].code) ;
                                                                }
                                                                yyval.code = gen_code (temp) ;
                                                            }
#line 1349 "trad2.tab.c"
    break;

  case 7: /* dec_var: %empty  */
#line 106 "trad2.y"
                                                            { yyval.code = gen_code ("") ; }
#line 1355 "trad2.tab.c"
    break;

  case 8: /* dec_var: dec_var integer ';'  */
#line 107 "trad2.y"
                                                            { if (strlen (yyvsp[-2].code) > 0) {
                                                                sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[-1].code) ;
                                                              } else {
                                                                sprintf (temp, "%s", yyvsp[-1].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ;
                                                            }
#line 1367 "trad2.tab.c"
    break;

  case 9: /* dec_var_local: %empty  */
#line 116 "trad2.y"
                                                                { yyval.code = gen_code ("") ; }
#line 1373 "trad2.tab.c"
    break;

  case 10: /* dec_var_local: dec_var_local integer_local ';'  */
#line 117 "trad2.y"
                                                                { if (strlen (yyvsp[-2].code) > 0) {
                                                                    sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[-1].code) ;
                                                                } else {
                                                                    sprintf (temp, "%s", yyvsp[-1].code) ;
                                                                }
                                                                yyval.code = gen_code (temp) ; }
#line 1384 "trad2.tab.c"
    break;

  case 11: /* integer_local: INTEGER lista_integer_local  */
#line 125 "trad2.y"
                                                                { yyval = yyvsp[0] ; }
#line 1390 "trad2.tab.c"
    break;

  case 12: /* lista_integer_local: IDENTIF r_integer  */
#line 129 "trad2.y"
                                                                { add_local(yyvsp[-1].code);
                                                                  sprintf (temp, "(setq main_%s %s)", yyvsp[-1].code, yyvsp[0].code);
                                                                  yyval.code = gen_code(temp); }
#line 1398 "trad2.tab.c"
    break;

  case 13: /* lista_integer_local: lista_integer_local ',' IDENTIF r_integer  */
#line 132 "trad2.y"
                                                                { add_local(yyvsp[-1].code);
                                                                  sprintf (temp, "%s\n(setq main_%s %s)", yyvsp[-3].code, yyvsp[-1].code, yyvsp[0].code);
                                                                  yyval.code = gen_code(temp); }
#line 1406 "trad2.tab.c"
    break;

  case 14: /* bq_sent: %empty  */
#line 137 "trad2.y"
                                                            { yyval.code = gen_code ("") ; }
#line 1412 "trad2.tab.c"
    break;

  case 15: /* bq_sent: bq_sent sentencia ';'  */
#line 138 "trad2.y"
                                                            { if (strlen (yyvsp[-2].code) > 0) {
                                                                sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[-1].code) ;
                                                              } else {
                                                                sprintf (temp, "%s", yyvsp[-1].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ;
                                                            }
#line 1424 "trad2.tab.c"
    break;

  case 16: /* bq_sent: bq_sent st_while  */
#line 145 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                                sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                              } else {
                                                                sprintf (temp, "%s", yyvsp[0].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ;
                                                            }
#line 1436 "trad2.tab.c"
    break;

  case 17: /* bq_sent: bq_sent st_if  */
#line 152 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                              sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                              } else {
                                                                sprintf (temp, "%s", yyvsp[0].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ; 
                                                            }
#line 1448 "trad2.tab.c"
    break;

  case 18: /* bq_sent: bq_sent st_for  */
#line 159 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                                sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                              } else {
                                                                sprintf (temp, "%s", yyvsp[0].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ; 
                                                            }
#line 1460 "trad2.tab.c"
    break;

  case 19: /* bq_sent: bq_sent st_switch  */
#line 166 "trad2.y"
                                                                        { if (strlen (yyvsp[-1].code) > 0) {
                                                                                                                                sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                                                                                            } else {
                                                                                                                                sprintf (temp, "%s", yyvsp[0].code) ;
                                                                                                                            }
                                                                                                                            yyval.code = gen_code (temp) ;
                                                                                                                        }
#line 1472 "trad2.tab.c"
    break;

  case 20: /* sentencia: IDENTIF '=' expresion  */
#line 175 "trad2.y"
                                                            { sprintf (temp, "(setf %s %s)", get_var_name(yyvsp[-2].code), yyvsp[0].code) ; 
                                                              yyval.code = gen_code (temp) ; }
#line 1479 "trad2.tab.c"
    break;

  case 21: /* sentencia: PUTS '(' STRING ')'  */
#line 177 "trad2.y"
                                                            { sprintf (temp, "(print \"%s\")", yyvsp[-1].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1486 "trad2.tab.c"
    break;

  case 22: /* sentencia: PRINTF '(' STRING ',' lista_print ')'  */
#line 179 "trad2.y"
                                                            { yyval = yyvsp[-1] ; }
#line 1492 "trad2.tab.c"
    break;

  case 23: /* op_inc_dec: INC '(' IDENTIF ')'  */
#line 182 "trad2.y"
                                            { sprintf (temp, "(setf %s (+ %s 1))", get_var_name(yyvsp[-1].code), get_var_name(yyvsp[-1].code)) ;
                                              yyval.code = gen_code (temp) ; }
#line 1499 "trad2.tab.c"
    break;

  case 24: /* op_inc_dec: DEC '(' IDENTIF ')'  */
#line 184 "trad2.y"
                                            { sprintf (temp, "(setf %s (- %s 1))", get_var_name(yyvsp[-1].code), get_var_name(yyvsp[-1].code)) ;
                                              yyval.code = gen_code (temp) ; }
#line 1506 "trad2.tab.c"
    break;

  case 25: /* st_while: WHILE '(' expresion ')' '{' bq_sent '}'  */
#line 188 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                                sprintf (temp, "(loop while %s do\n%s)", yyvsp[-4].code, yyvsp[-1].code) ;
                                                              } else {
                                                                sprintf (temp, "(loop while %s do)", yyvsp[-4].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ;
                                                            }
#line 1518 "trad2.tab.c"
    break;

  case 26: /* st_for: FOR '(' sentencia ';' expresion ';' op_inc_dec ')' '{' bq_sent '}'  */
#line 198 "trad2.y"
                                { 
                                    if (strlen (yyvsp[-1].code) > 0) {
                                        // Si hay código en el bloque, el incremento va al final del bloque
                                        sprintf (temp, "%s\n(loop while %s do\n%s\n%s)", yyvsp[-8].code, yyvsp[-6].code, yyvsp[-1].code, yyvsp[-4].code) ;
                                    } else {
                                        // Si el bloque está vacío, solo se ejecuta el incremento dentro del bucle
                                        sprintf (temp, "%s\n(loop while %s do\n%s)", yyvsp[-8].code, yyvsp[-6].code, yyvsp[-4].code) ;
                                    }
                                    yyval.code = gen_code (temp) ; 
                                }
#line 1533 "trad2.tab.c"
    break;

  case 27: /* st_if: IF '(' expresion ')' '{' bq_sent '}'  */
#line 210 "trad2.y"
                                                                            { sprintf (temp, "(if %s\n(progn\n%s\n)\n)", yyvsp[-4].code, yyvsp[-1].code) ;
                                                                              yyval.code = gen_code (temp) ; }
#line 1540 "trad2.tab.c"
    break;

  case 28: /* st_if: IF '(' expresion ')' '{' bq_sent '}' ELSE '{' bq_sent '}'  */
#line 213 "trad2.y"
                                                                            { sprintf (temp, "(if %s\n(progn\n%s\n)\n(progn\n%s\n)\n)", yyvsp[-8].code,   yyvsp[-5].code, yyvsp[-1].code) ;
                                                                              yyval.code = gen_code (temp) ; }
#line 1547 "trad2.tab.c"
    break;

  case 29: /* st_switch: SWITCH '(' expresion ')' '{' lista_cases opt_default '}'  */
#line 217 "trad2.y"
                                                                            {
                                                                                if (strlen (yyvsp[-2].code) > 0) {
                                                                                    sprintf (temp, "(case %s\n%s\n%s\n)", yyvsp[-5].code, yyvsp[-2].code, yyvsp[-1].code) ;
                                                                                } else {
                                                                                    sprintf (temp, "(case %s\n%s\n)", yyvsp[-5].code, yyvsp[-1].code) ;
                                                                                }
                                                                                yyval.code = gen_code (temp) ;
                                                                            }
#line 1560 "trad2.tab.c"
    break;

  case 30: /* lista_cases: case_item  */
#line 227 "trad2.y"
                                                                             { yyval = yyvsp[0] ; }
#line 1566 "trad2.tab.c"
    break;

  case 31: /* lista_cases: lista_cases case_item  */
#line 228 "trad2.y"
                                                                              { sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                                                yyval.code = gen_code (temp) ; }
#line 1573 "trad2.tab.c"
    break;

  case 32: /* case_item: CASE NUMBER ':' bq_sent BREAK ';'  */
#line 232 "trad2.y"
                                                                             {
                                                                                if (strlen (yyvsp[-2].code) > 0) {
                                                                                    sprintf (temp, "(%d\n%s\n)", yyvsp[-4].value, yyvsp[-2].code) ;
                                                                                } else {
                                                                                    sprintf (temp, "(%d)", yyvsp[-4].value) ;
                                                                                }
                                                                                yyval.code = gen_code (temp) ;
                                                                            }
#line 1586 "trad2.tab.c"
    break;

  case 33: /* opt_default: %empty  */
#line 242 "trad2.y"
                                                                            { yyval.code = gen_code ("") ; }
#line 1592 "trad2.tab.c"
    break;

  case 34: /* opt_default: DEFAULT ':' bq_sent BREAK ';'  */
#line 243 "trad2.y"
                                                                              {
                                                                                if (strlen (yyvsp[-2].code) > 0) {
                                                                                    sprintf (temp, "(otherwise\n%s\n)", yyvsp[-2].code) ;
                                                                                } else {
                                                                                    sprintf (temp, "(otherwise)") ;
                                                                                }
                                                                                yyval.code = gen_code (temp) ;
                                                                            }
#line 1605 "trad2.tab.c"
    break;

  case 35: /* elem_print: expresion  */
#line 253 "trad2.y"
                                                            { yyval = yyvsp[0] ; }
#line 1611 "trad2.tab.c"
    break;

  case 36: /* elem_print: STRING  */
#line 254 "trad2.y"
                                                            { sprintf (temp, "\"%s\"", yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1618 "trad2.tab.c"
    break;

  case 37: /* lista_print: elem_print  */
#line 258 "trad2.y"
                                                            { sprintf (temp, "(princ %s)", yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1625 "trad2.tab.c"
    break;

  case 38: /* lista_print: lista_print ',' elem_print  */
#line 260 "trad2.y"
                                                            { sprintf (temp, "%s\n(princ %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1632 "trad2.tab.c"
    break;

  case 39: /* integer: INTEGER lista_integer_global  */
#line 264 "trad2.y"
                                                            { yyval = yyvsp[0] ; }
#line 1638 "trad2.tab.c"
    break;

  case 40: /* lista_integer_global: IDENTIF r_integer  */
#line 268 "trad2.y"
                                                            { sprintf (temp, "(setq %s %s)", yyvsp[-1].code, yyvsp[0].code);
                                                              yyval.code = gen_code(temp); }
#line 1645 "trad2.tab.c"
    break;

  case 41: /* lista_integer_global: lista_integer_global ',' IDENTIF r_integer  */
#line 270 "trad2.y"
                                                            { sprintf (temp, "%s\n(setq %s %s)", yyvsp[-3].code, yyvsp[-1].code, yyvsp[0].code);
                                                              yyval.code = gen_code(temp); }
#line 1652 "trad2.tab.c"
    break;

  case 42: /* r_integer: %empty  */
#line 274 "trad2.y"
                                                            { sprintf (temp, "0");
                                                              yyval.code = gen_code(temp);}
#line 1659 "trad2.tab.c"
    break;

  case 43: /* r_integer: '=' NUMBER  */
#line 276 "trad2.y"
                                                            { sprintf (temp, "%s", int_to_string(yyvsp[0].value));
                                                              yyval.code = gen_code(temp);}
#line 1666 "trad2.tab.c"
    break;

  case 44: /* expresion: termino  */
#line 280 "trad2.y"
                                                            { yyval = yyvsp[0] ; }
#line 1672 "trad2.tab.c"
    break;

  case 45: /* expresion: expresion OR expresion  */
#line 281 "trad2.y"
                                                            { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1679 "trad2.tab.c"
    break;

  case 46: /* expresion: expresion AND expresion  */
#line 283 "trad2.y"
                                                            { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1686 "trad2.tab.c"
    break;

  case 47: /* expresion: expresion EQ expresion  */
#line 285 "trad2.y"
                                                            { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1693 "trad2.tab.c"
    break;

  case 48: /* expresion: expresion NE expresion  */
#line 287 "trad2.y"
                                                            { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1700 "trad2.tab.c"
    break;

  case 49: /* expresion: expresion '<' expresion  */
#line 289 "trad2.y"
                                                            { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1707 "trad2.tab.c"
    break;

  case 50: /* expresion: expresion LE expresion  */
#line 291 "trad2.y"
                                                            { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1714 "trad2.tab.c"
    break;

  case 51: /* expresion: expresion '>' expresion  */
#line 293 "trad2.y"
                                                            { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1721 "trad2.tab.c"
    break;

  case 52: /* expresion: expresion GE expresion  */
#line 295 "trad2.y"
                                                            { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1728 "trad2.tab.c"
    break;

  case 53: /* expresion: expresion '+' expresion  */
#line 297 "trad2.y"
                                                            { sprintf (temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1735 "trad2.tab.c"
    break;

  case 54: /* expresion: expresion '-' expresion  */
#line 299 "trad2.y"
                                                            { sprintf (temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1742 "trad2.tab.c"
    break;

  case 55: /* expresion: expresion '*' expresion  */
#line 301 "trad2.y"
                                                            { sprintf (temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1749 "trad2.tab.c"
    break;

  case 56: /* expresion: expresion '/' expresion  */
#line 303 "trad2.y"
                                                            { sprintf (temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1756 "trad2.tab.c"
    break;

  case 57: /* expresion: expresion '%' expresion  */
#line 305 "trad2.y"
                                                            { sprintf (temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1763 "trad2.tab.c"
    break;

  case 58: /* termino: operando  */
#line 309 "trad2.y"
                                                            { yyval = yyvsp[0] ; }
#line 1769 "trad2.tab.c"
    break;

  case 59: /* termino: '+' operando  */
#line 310 "trad2.y"
                                                            { yyval = yyvsp[-1] ; }
#line 1775 "trad2.tab.c"
    break;

  case 60: /* termino: '-' operando  */
#line 311 "trad2.y"
                                                            { sprintf (temp, "(- %s)", yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1782 "trad2.tab.c"
    break;

  case 61: /* termino: '!' operando  */
#line 313 "trad2.y"
                                                            { sprintf (temp, "(not %s)", yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1789 "trad2.tab.c"
    break;

  case 62: /* operando: IDENTIF  */
#line 317 "trad2.y"
                                                            { sprintf (temp, "%s", get_var_name(yyvsp[0].code)) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1796 "trad2.tab.c"
    break;

  case 63: /* operando: NUMBER  */
#line 319 "trad2.y"
                                                            { sprintf (temp, "%d", yyvsp[0].value) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1803 "trad2.tab.c"
    break;

  case 64: /* operando: '(' expresion ')'  */
#line 321 "trad2.y"
                                                            { yyval = yyvsp[-1] ; }
#line 1809 "trad2.tab.c"
    break;


#line 1813 "trad2.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 325 "trad2.y"
                            // SECCION 4    Codigo en C

int n_line = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_line) ;
    printf ( "\n") ;	// bye
    return 0 ;
}

char *int_to_string (int n)
{
    char ltemp [2048] ;

    sprintf (ltemp, "%d", n) ;

    return gen_code (ltemp) ;
}

char *char_to_string (char c)
{
    char ltemp [2048] ;

    sprintf (ltemp, "%c", c) ;

    return gen_code (ltemp) ;
}

char *my_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
        fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}


/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_keyword { // para las palabras reservadas de C
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords [] = { // define las palabras reservadas y los
    { "main",        MAIN },           // y los token asociados
    { "int",         INTEGER },
    { "while",       WHILE },
    { "for",         FOR },
    { "inc",         INC },
    { "dec",         DEC },
    { "puts",        PUTS },
    { "printf",      PRINTF },
    { "&&",          AND },
    { "||",          OR },
    { "==",          EQ },
    { "!=",          NE },
    { "<=",          LE },
    { ">=",          GE },
    { "if",          IF },
    { "else",        ELSE },
    { "switch",      SWITCH },
    { "case",        CASE },
    { "default",     DEFAULT },
    { "break",       BREAK },
    { NULL,          0 }               // para marcar el fin de la tabla
} ;

t_keyword *search_keyword (char *symbol_name)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
	    if (strcmp (sim [i].name, symbol_name) == 0) {
		                             // strcmp(a, b) devuelve == 0 si a==b
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}

 
/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/

char *gen_code (char *name)     // copia el argumento a un
{                                      // string en memoria dinamica
    char *p ;
    int l ;
	
    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;
	
    return p ;
}

/***************************************************************************/
/******************* Seccion del Variables Locales *************************/
/***************************************************************************/
char tabla_locales[100][256]; // Tabla para guardar hasta 100 variables locales
int num_locales = 0;

void add_local(char* nombre) {
    strcpy(tabla_locales[num_locales++], nombre);
}

int es_local(char* nombre) {
    for(int i = 0; i < num_locales; i++) {
        if(strcmp(tabla_locales[i], nombre) == 0) return 1;
    }
    return 0; // No está en la tabla, por lo que es global
}

char* get_var_name(char* id) {
    if (es_local(id)) {
        char temp_name[256];
        sprintf(temp_name, "main_%s", id); // Le añade el prefijo
        return gen_code(temp_name);
    }
    return id; // Si es global, devuelve el nombre tal cual
}
// ------------------------------------


int yylex ()
{
// NO MODIFICAR ESTA FUNCION SIN PERMISO
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "!<=|>%&/+-*" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;

        if (c == '#') {	// Ignora las lineas que empiezan por #  (#define, #include)
            do {		//	OJO que puede funcionar mal si una linea contiene #
                c = getchar () ;
            } while (c != '\n') ;
        }

        if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
            cc = getchar () ;
            if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
                ungetc (cc, stdin) ;
            } else {
                c = getchar () ;	// ...
                if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
                    do {		// Se trata de codigo inline (Codigo embebido en C)
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n') ;
                } else {		// ==> comentario, ignorar la linea
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        } else if (c == '\\') c = getchar () ;
		
        if (c == '\n')
            n_line++ ;

    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_line) ;
        }		 	// habria que leer hasta el siguiente " , pero, y si falta?
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
//         printf ("\nDEV: NUMBER %d\n", yylval.value) ;        // PARA DEPURAR
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
            temp_str [i++] = tolower (c) ;
            c = getchar () ;
        }
        temp_str [i] = '\0' ;
        ungetc (c, stdin) ;

        yylval.code = gen_code (temp_str) ;
        symbol = search_keyword (yylval.code) ;
        if (symbol == NULL) {    // no es palabra reservada -> identificador antes vrariabre
//               printf ("\nDEV: IDENTIF %s\n", yylval.code) ;    // PARA DEPURAR
            return (IDENTIF) ;
        } else {
//               printf ("\nDEV: OTRO %s\n", yylval.code) ;       // PARA DEPURAR
            return (symbol->token) ;
        }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // aunque no se use
            return (symbol->token) ;
        }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}


int main ()
{
    yyparse () ;
}
