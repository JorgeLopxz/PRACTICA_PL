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
char *get_var_name(char* id) ;
void set_current_function(char* nombre) ;

char temp [2048] ;
char current_function [256] = "" ;

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


#line 118 "trad2.tab.c"

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
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_27_ = 27,                       /* '='  */
  YYSYMBOL_28_ = 28,                       /* '<'  */
  YYSYMBOL_29_ = 29,                       /* '>'  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '%'  */
  YYSYMBOL_UNARY_SIGN = 35,                /* UNARY_SIGN  */
  YYSYMBOL_36_ = 36,                       /* '('  */
  YYSYMBOL_37_ = 37,                       /* ')'  */
  YYSYMBOL_38_ = 38,                       /* '{'  */
  YYSYMBOL_39_ = 39,                       /* '}'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* ':'  */
  YYSYMBOL_43_ = 43,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_axioma = 45,                    /* axioma  */
  YYSYMBOL_def_func = 46,                  /* def_func  */
  YYSYMBOL_def_main = 47,                  /* def_main  */
  YYSYMBOL_48_1 = 48,                      /* $@1  */
  YYSYMBOL_def_otras = 49,                 /* def_otras  */
  YYSYMBOL_50_2 = 50,                      /* $@2  */
  YYSYMBOL_lista_param_def = 51,           /* lista_param_def  */
  YYSYMBOL_param_def_nonempty = 52,        /* param_def_nonempty  */
  YYSYMBOL_dec_var = 53,                   /* dec_var  */
  YYSYMBOL_dec_var_local = 54,             /* dec_var_local  */
  YYSYMBOL_integer = 55,                   /* integer  */
  YYSYMBOL_lista_integer = 56,             /* lista_integer  */
  YYSYMBOL_r_integer = 57,                 /* r_integer  */
  YYSYMBOL_integer_local = 58,             /* integer_local  */
  YYSYMBOL_lista_integer_local = 59,       /* lista_integer_local  */
  YYSYMBOL_bq_sent = 60,                   /* bq_sent  */
  YYSYMBOL_sentencia = 61,                 /* sentencia  */
  YYSYMBOL_op_inc_dec = 62,                /* op_inc_dec  */
  YYSYMBOL_st_while = 63,                  /* st_while  */
  YYSYMBOL_st_for = 64,                    /* st_for  */
  YYSYMBOL_st_if = 65,                     /* st_if  */
  YYSYMBOL_st_switch = 66,                 /* st_switch  */
  YYSYMBOL_lista_cases = 67,               /* lista_cases  */
  YYSYMBOL_case_item = 68,                 /* case_item  */
  YYSYMBOL_opt_default = 69,               /* opt_default  */
  YYSYMBOL_elem_print = 70,                /* elem_print  */
  YYSYMBOL_lista_print = 71,               /* lista_print  */
  YYSYMBOL_lista_arg = 72,                 /* lista_arg  */
  YYSYMBOL_arg_nonempty = 73,              /* arg_nonempty  */
  YYSYMBOL_expresion = 74,                 /* expresion  */
  YYSYMBOL_termino = 75,                   /* termino  */
  YYSYMBOL_operando = 76                   /* operando  */
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
#define YYLAST   416

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
       2,     2,     2,    43,     2,     2,     2,    34,     2,     2,
      36,    37,    32,    30,    40,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    41,
      28,    27,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      25,    26,    35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    82,    82,    89,    93,    93,    98,    99,    99,   105,
     106,   109,   112,   117,   118,   127,   128,   137,   141,   143,
     147,   149,   154,   158,   161,   166,   167,   174,   181,   188,
     195,   204,   206,   208,   209,   216,   220,   222,   226,   235,
     248,   251,   255,   264,   265,   269,   279,   280,   289,   290,
     294,   296,   300,   301,   304,   305,   309,   310,   312,   314,
     316,   318,   320,   322,   324,   326,   328,   330,   332,   334,
     338,   339,   340,   342,   346,   348,   350,   351
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
  "CASE", "DEFAULT", "BREAK", "RETURN", "'='", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "UNARY_SIGN", "'('", "')'", "'{'", "'}'", "','",
  "';'", "':'", "'!'", "$accept", "axioma", "def_func", "def_main", "$@1",
  "def_otras", "$@2", "lista_param_def", "param_def_nonempty", "dec_var",
  "dec_var_local", "integer", "lista_integer", "r_integer",
  "integer_local", "lista_integer_local", "bq_sent", "sentencia",
  "op_inc_dec", "st_while", "st_for", "st_if", "st_switch", "lista_cases",
  "case_item", "opt_default", "elem_print", "lista_print", "lista_arg",
  "arg_nonempty", "expresion", "termino", "operando", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-61)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -61,    16,    29,   -61,   -61,    14,   -61,    21,   -20,     4,
      33,   -61,     5,   -61,   -61,    56,    59,    26,    30,    65,
      41,   -61,   -61,    14,   -61,    39,    32,   -61,    42,    56,
     -61,   -61,   -61,    77,    77,    80,    44,    64,    91,    33,
     -61,   -61,   -23,    51,    52,    53,    55,    58,    60,    28,
      88,    57,   -61,   -61,   -61,   -61,   -61,    66,    28,    28,
      28,    98,    99,    28,    10,    28,   -61,    71,     3,     3,
      28,     3,   317,   -61,   -61,   -61,   -61,    80,   317,    72,
     -61,   213,   243,    74,    75,   253,    73,   280,    28,   -61,
     -61,   290,   -61,    28,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,   -61,   -61,    28,    78,
     -61,    -1,    81,    28,    83,    85,   -61,   373,   324,   382,
     382,    -7,    -7,    -7,    -7,    43,    43,   -61,   -61,   -61,
     -61,   -61,   -61,    87,    86,   317,   -61,   189,    89,   -61,
     116,    -1,   -61,   135,    17,   115,    20,   -61,   -61,   -61,
     114,   100,   101,   103,   104,   105,   -61,   102,   110,   145,
     146,   113,   -61,   -61,   -61,   -61,   119,   122,   -61,   355,
     374,   154,   -61,   -61,   173,   112,   124,   -61,   -61,   -61,
     -61
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      13,     0,     6,     1,     7,     0,     2,     0,     0,     0,
      20,    17,     0,     3,    14,     9,     0,    18,     0,     0,
       0,    10,    21,     0,     4,    11,     0,    19,     0,     0,
      15,    15,    12,    25,    25,     0,     0,     0,     0,    20,
      22,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     0,    27,    29,    28,    30,     5,    23,     0,    52,
       0,     0,     0,     0,     0,     0,    75,    74,     0,     0,
       0,     0,    35,    56,    70,     8,    26,     0,    31,     0,
      53,    54,     0,     0,     0,     0,     0,     0,    52,    71,
      72,     0,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,    34,     0,     0,
      32,     0,     0,     0,     0,     0,    76,    58,    57,    59,
      60,    62,    64,    61,    63,    65,    66,    67,    68,    69,
      55,    25,    49,    50,     0,    48,    25,     0,     0,    77,
       0,     0,    33,     0,     0,     0,    46,    43,    38,    51,
      40,     0,     0,     0,     0,     0,    44,     0,     0,     0,
       0,     0,    25,    25,    42,    25,     0,     0,    25,     0,
       0,     0,    36,    37,     0,     0,     0,    41,    39,    45,
      47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,   -61,   -61,   -61,   117,   -61,   -61,   131,   -61,
     137,   -61,   143,   130,   -61,    93,   -34,   108,   -61,   -61,
     -61,   -61,   -61,   -61,    38,   -61,   -61,    34,    90,    79,
     -48,   -61,   -60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     6,    13,    28,     7,     9,    20,    21,     2,
      33,     8,    11,    17,    36,    40,    37,    51,   153,    52,
      53,    54,    55,   146,   147,   157,   133,   134,    79,    80,
      81,    73,    74
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      38,    72,    66,    67,    58,   132,    66,    67,    89,    90,
      78,    92,    82,    59,    42,    85,     3,    87,    10,    44,
      45,    14,    91,   101,   102,   103,   104,   105,    12,    68,
      69,    66,    67,     4,     5,    70,    49,   151,   152,    70,
      15,    18,    71,   145,   155,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    68,    69,
      16,    19,    22,   135,    70,   137,    23,    24,    42,    25,
      30,    71,    43,    44,    45,   103,   104,   105,    26,    29,
      31,    46,    35,    47,    39,    41,    48,    60,    61,    62,
      49,    63,     4,   135,    64,    42,    65,   140,    76,    43,
      44,    45,   143,    50,    83,    84,    77,    88,    46,   107,
      47,   110,   145,    48,   113,   111,   131,    49,   154,   136,
      42,   138,   139,   142,    43,    44,    45,   141,   169,   170,
      56,   171,   158,    46,   174,    47,   159,   160,    48,    42,
     161,   164,    49,    43,    44,    45,   162,   163,   165,   166,
     167,   168,    46,   179,    47,   148,   172,    48,    42,   173,
      32,    49,    43,    44,    45,   180,    27,    75,    34,    57,
     106,    46,    86,    47,   150,   149,    48,    42,   115,     0,
      49,    43,    44,    45,   156,     0,     0,   130,     0,     0,
      46,     0,    47,   177,     0,    48,     0,     0,     0,    49,
      93,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,   178,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,   105,    93,    94,    95,    96,    97,    98,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,   105,     0,     0,
       0,     0,     0,   108,    93,    94,    95,    96,    97,    98,
       0,     0,     0,     0,    93,    94,    95,    96,    97,    98,
       0,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     109,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     112,    93,    94,    95,    96,    97,    98,     0,     0,     0,
       0,    93,    94,    95,    96,    97,    98,     0,    99,   100,
     101,   102,   103,   104,   105,     0,     0,   114,    99,   100,
     101,   102,   103,   104,   105,     0,     0,   116,    93,    94,
      95,    96,    97,    98,     0,    93,     0,    95,    96,    97,
      98,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,   105,    99,   100,   101,   102,   103,   104,   105,    42,
       0,     0,     0,    43,    44,    45,     0,     0,     0,     0,
       0,     0,    46,     0,    47,     0,     0,    48,    42,     0,
     175,    49,    43,    44,    45,     0,    95,    96,    97,    98,
       0,    46,     0,    47,     0,     0,    48,    97,    98,   176,
      49,    99,   100,   101,   102,   103,   104,   105,     0,     0,
      99,   100,   101,   102,   103,   104,   105
};

static const yytype_int16 yycheck[] =
{
      34,    49,     3,     4,    27,     6,     3,     4,    68,    69,
      58,    71,    60,    36,     4,    63,     0,    65,     4,     9,
      10,    41,    70,    30,    31,    32,    33,    34,     7,    30,
      31,     3,     4,     4,     5,    36,    26,    20,    21,    36,
      36,    36,    43,    23,    24,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    30,    31,
      27,     5,     3,   111,    36,   113,    40,    37,     4,     4,
      38,    43,     8,     9,    10,    32,    33,    34,    37,    40,
      38,    17,     5,    19,     4,    41,    22,    36,    36,    36,
      26,    36,     4,   141,    36,     4,    36,   131,    41,     8,
       9,    10,   136,    39,     6,     6,    40,    36,    17,    37,
      19,    37,    23,    22,    41,    40,    38,    26,     3,    38,
       4,    38,    37,    37,     8,     9,    10,    40,   162,   163,
      39,   165,    18,    17,   168,    19,    36,    36,    22,     4,
      37,    39,    26,     8,     9,    10,    42,    42,    38,     4,
       4,    38,    17,    41,    19,    39,    37,    22,     4,    37,
      29,    26,     8,     9,    10,    41,    23,    50,    31,    39,
      77,    17,    64,    19,    39,   141,    22,     4,    88,    -1,
      26,     8,     9,    10,   146,    -1,    -1,   108,    -1,    -1,
      17,    -1,    19,    39,    -1,    22,    -1,    -1,    -1,    26,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    11,    12,    13,    14,    15,    16,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    40,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,    16,
      -1,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      37,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      37,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    11,    12,    13,    14,    15,    16,    -1,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    37,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    37,    11,    12,
      13,    14,    15,    16,    -1,    11,    -1,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    28,    29,    30,    31,    32,    33,    34,     4,
      -1,    -1,    -1,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    19,    -1,    -1,    22,     4,    -1,
      25,    26,     8,     9,    10,    -1,    13,    14,    15,    16,
      -1,    17,    -1,    19,    -1,    -1,    22,    15,    16,    25,
      26,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,    53,     0,     4,     5,    46,    49,    55,    50,
       4,    56,     7,    47,    41,    36,    27,    57,    36,     5,
      51,    52,     3,    40,    37,     4,    37,    56,    48,    40,
      38,    38,    52,    54,    54,     5,    58,    60,    60,     4,
      59,    41,     4,     8,     9,    10,    17,    19,    22,    26,
      39,    61,    63,    64,    65,    66,    39,    57,    27,    36,
      36,    36,    36,    36,    36,    36,     3,     4,    30,    31,
      36,    43,    74,    75,    76,    49,    41,    40,    74,    72,
      73,    74,    74,     6,     6,    74,    61,    74,    36,    76,
      76,    74,    76,    11,    12,    13,    14,    15,    16,    28,
      29,    30,    31,    32,    33,    34,    59,    37,    40,    37,
      37,    40,    37,    41,    37,    72,    37,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      73,    38,     6,    70,    71,    74,    38,    74,    38,    37,
      60,    40,    37,    60,    41,    23,    67,    68,    39,    71,
      39,    20,    21,    62,     3,    24,    68,    69,    18,    36,
      36,    37,    42,    42,    39,    38,     4,     4,    38,    60,
      60,    60,    37,    37,    60,    25,    25,    39,    39,    41,
      41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    48,    47,    49,    50,    49,    51,
      51,    52,    52,    53,    53,    54,    54,    55,    56,    56,
      57,    57,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    61,    61,    61,    61,    61,    62,    62,    63,    64,
      65,    65,    66,    67,    67,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      75,    75,    75,    75,    76,    76,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     8,     0,     0,    10,     0,
       1,     2,     4,     0,     3,     0,     3,     2,     2,     4,
       0,     2,     2,     2,     4,     0,     3,     2,     2,     2,
       2,     3,     4,     6,     4,     2,     4,     4,     7,    11,
       7,    11,     8,     1,     2,     6,     0,     5,     1,     1,
       1,     3,     0,     1,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     2,     2,     2,     1,     1,     3,     4
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
#line 82 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                                printf ("%s\n", yyvsp[-1].code) ;
                                                              }
                                                              printf ("%s\n", yyvsp[0].code) ;
                                                            }
#line 1347 "trad2.tab.c"
    break;

  case 3: /* def_func: def_otras def_main  */
#line 89 "trad2.y"
                                                            { sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1354 "trad2.tab.c"
    break;

  case 4: /* $@1: %empty  */
#line 93 "trad2.y"
                             { set_current_function ("main") ; }
#line 1360 "trad2.tab.c"
    break;

  case 5: /* def_main: MAIN '(' ')' $@1 '{' dec_var_local bq_sent '}'  */
#line 94 "trad2.y"
                                                                { sprintf (temp, "(defun main ()\n%s\n%s)", yyvsp[-2].code, yyvsp[-1].code) ;
                                                                  yyval.code = gen_code (temp) ; }
#line 1367 "trad2.tab.c"
    break;

  case 6: /* def_otras: %empty  */
#line 98 "trad2.y"
                                                                { yyval.code = gen_code ("") ; }
#line 1373 "trad2.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 99 "trad2.y"
                        { set_current_function (yyvsp[0].code) ; }
#line 1379 "trad2.tab.c"
    break;

  case 8: /* def_otras: IDENTIF $@2 '(' lista_param_def ')' '{' dec_var_local bq_sent '}' def_otras  */
#line 100 "trad2.y"
                                                                { sprintf (temp, "(defun %s (%s)\n%s\n%s)\n\n%s", yyvsp[-9].code, yyvsp[-6].code, yyvsp[-3].code, yyvsp[-2].code, yyvsp[0].code) ;
                                                                  yyval.code = gen_code (temp) ;
                                                                }
#line 1387 "trad2.tab.c"
    break;

  case 9: /* lista_param_def: %empty  */
#line 105 "trad2.y"
                                                                    { yyval.code = gen_code ("") ; }
#line 1393 "trad2.tab.c"
    break;

  case 10: /* lista_param_def: param_def_nonempty  */
#line 106 "trad2.y"
                                                                    { yyval = yyvsp[0] ; }
#line 1399 "trad2.tab.c"
    break;

  case 11: /* param_def_nonempty: INTEGER IDENTIF  */
#line 109 "trad2.y"
                                                                    { add_local(yyvsp[0].code) ;
                                                                      sprintf (temp, "%s_%s", current_function, yyvsp[0].code) ;
                                                                      yyval.code = gen_code (temp) ; }
#line 1407 "trad2.tab.c"
    break;

  case 12: /* param_def_nonempty: INTEGER IDENTIF ',' param_def_nonempty  */
#line 112 "trad2.y"
                                                                    { add_local(yyvsp[-2].code) ;
                                                                      sprintf (temp, "%s_%s %s", current_function, yyvsp[-2].code, yyvsp[0].code) ; 
                                                                      yyval.code = gen_code (temp) ; }
#line 1415 "trad2.tab.c"
    break;

  case 13: /* dec_var: %empty  */
#line 117 "trad2.y"
                                                            { yyval.code = gen_code ("") ; }
#line 1421 "trad2.tab.c"
    break;

  case 14: /* dec_var: dec_var integer ';'  */
#line 118 "trad2.y"
                                                            { if (strlen (yyvsp[-2].code) > 0) {
                                                                sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[-1].code) ;
                                                              } else {
                                                                sprintf (temp, "%s", yyvsp[-1].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ;
                                                            }
#line 1433 "trad2.tab.c"
    break;

  case 15: /* dec_var_local: %empty  */
#line 127 "trad2.y"
                                                                { yyval.code = gen_code ("") ; }
#line 1439 "trad2.tab.c"
    break;

  case 16: /* dec_var_local: dec_var_local integer_local ';'  */
#line 128 "trad2.y"
                                                                { if (strlen (yyvsp[-2].code) > 0) {
                                                                    sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[-1].code) ;
                                                                  } else {
                                                                    sprintf (temp, "%s", yyvsp[-1].code) ;
                                                                  }
                                                                  yyval.code = gen_code (temp) ; 
                                                                }
#line 1451 "trad2.tab.c"
    break;

  case 17: /* integer: INTEGER lista_integer  */
#line 137 "trad2.y"
                                                            { yyval = yyvsp[0] ; }
#line 1457 "trad2.tab.c"
    break;

  case 18: /* lista_integer: IDENTIF r_integer  */
#line 141 "trad2.y"
                                                            { sprintf (temp, "(setq %s %s)", yyvsp[-1].code, yyvsp[0].code);
                                                              yyval.code = gen_code(temp); }
#line 1464 "trad2.tab.c"
    break;

  case 19: /* lista_integer: IDENTIF r_integer ',' lista_integer  */
#line 143 "trad2.y"
                                                            { sprintf (temp, "(setq %s %s) \n%s", yyvsp[-3].code, yyvsp[-2].code, yyvsp[0].code);
                                                              yyval.code = gen_code(temp); }
#line 1471 "trad2.tab.c"
    break;

  case 20: /* r_integer: %empty  */
#line 147 "trad2.y"
                                                            { sprintf (temp, "0");
                                                              yyval.code = gen_code(temp);}
#line 1478 "trad2.tab.c"
    break;

  case 21: /* r_integer: '=' NUMBER  */
#line 149 "trad2.y"
                                                            { sprintf (temp, "%s", int_to_string(yyvsp[0].value));
                                                              yyval.code = gen_code(temp);}
#line 1485 "trad2.tab.c"
    break;

  case 22: /* integer_local: INTEGER lista_integer_local  */
#line 154 "trad2.y"
                                                                { yyval = yyvsp[0] ; }
#line 1491 "trad2.tab.c"
    break;

  case 23: /* lista_integer_local: IDENTIF r_integer  */
#line 158 "trad2.y"
                                                                { add_local(yyvsp[-1].code);
                                                                  sprintf (temp, "(setq %s_%s %s)", current_function, yyvsp[-1].code, yyvsp[0].code);
                                                                  yyval.code = gen_code(temp); }
#line 1499 "trad2.tab.c"
    break;

  case 24: /* lista_integer_local: IDENTIF r_integer ',' lista_integer_local  */
#line 161 "trad2.y"
                                                                { add_local(yyvsp[-3].code);
                                                                  sprintf (temp, "(setq %s_%s %s) \n%s", current_function, yyvsp[-3].code, yyvsp[-2].code, yyvsp[0].code);
                                                                  yyval.code = gen_code(temp); }
#line 1507 "trad2.tab.c"
    break;

  case 25: /* bq_sent: %empty  */
#line 166 "trad2.y"
                                                            { yyval.code = gen_code ("") ; }
#line 1513 "trad2.tab.c"
    break;

  case 26: /* bq_sent: bq_sent sentencia ';'  */
#line 167 "trad2.y"
                                                            { if (strlen (yyvsp[-2].code) > 0) {
                                                                sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[-1].code) ;
                                                              } else {
                                                                sprintf (temp, "%s", yyvsp[-1].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ;
                                                            }
#line 1525 "trad2.tab.c"
    break;

  case 27: /* bq_sent: bq_sent st_while  */
#line 174 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                                sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                              } else {
                                                                sprintf (temp, "%s", yyvsp[0].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ;
                                                            }
#line 1537 "trad2.tab.c"
    break;

  case 28: /* bq_sent: bq_sent st_if  */
#line 181 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                              sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                              } else {
                                                                sprintf (temp, "%s", yyvsp[0].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ; 
                                                            }
#line 1549 "trad2.tab.c"
    break;

  case 29: /* bq_sent: bq_sent st_for  */
#line 188 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                                sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                              } else {
                                                                sprintf (temp, "%s", yyvsp[0].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ; 
                                                            }
#line 1561 "trad2.tab.c"
    break;

  case 30: /* bq_sent: bq_sent st_switch  */
#line 195 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                              sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                              } else {
                                                              sprintf (temp, "%s", yyvsp[0].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ;
                                                            }
#line 1573 "trad2.tab.c"
    break;

  case 31: /* sentencia: IDENTIF '=' expresion  */
#line 204 "trad2.y"
                                                            { sprintf (temp, "(setf %s %s)", get_var_name(yyvsp[-2].code), yyvsp[0].code) ; 
                                                              yyval.code = gen_code (temp) ; }
#line 1580 "trad2.tab.c"
    break;

  case 32: /* sentencia: PUTS '(' STRING ')'  */
#line 206 "trad2.y"
                                                            { sprintf (temp, "(print \"%s\")", yyvsp[-1].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1587 "trad2.tab.c"
    break;

  case 33: /* sentencia: PRINTF '(' STRING ',' lista_print ')'  */
#line 208 "trad2.y"
                                                            { yyval = yyvsp[-1] ; }
#line 1593 "trad2.tab.c"
    break;

  case 34: /* sentencia: IDENTIF '(' lista_arg ')'  */
#line 209 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                                sprintf (temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code) ;
                                                              } else {
                                                                sprintf (temp, "(%s)", yyvsp[-3].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ; 
                                                            }
#line 1605 "trad2.tab.c"
    break;

  case 35: /* sentencia: RETURN expresion  */
#line 216 "trad2.y"
                                                            { sprintf (temp, "(return-from %s %s)", current_function, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1612 "trad2.tab.c"
    break;

  case 36: /* op_inc_dec: INC '(' IDENTIF ')'  */
#line 220 "trad2.y"
                                            { sprintf (temp, "(setf %s (+ %s 1))", get_var_name(yyvsp[-1].code), get_var_name(yyvsp[-1].code)) ;
                                              yyval.code = gen_code (temp) ; }
#line 1619 "trad2.tab.c"
    break;

  case 37: /* op_inc_dec: DEC '(' IDENTIF ')'  */
#line 222 "trad2.y"
                                            { sprintf (temp, "(setf %s (- %s 1))", get_var_name(yyvsp[-1].code), get_var_name(yyvsp[-1].code)) ;
                                              yyval.code = gen_code (temp) ; }
#line 1626 "trad2.tab.c"
    break;

  case 38: /* st_while: WHILE '(' expresion ')' '{' bq_sent '}'  */
#line 226 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                                sprintf (temp, "(loop while %s do\n%s)", yyvsp[-4].code, yyvsp[-1].code) ;
                                                              } else {
                                                                sprintf (temp, "(loop while %s do)", yyvsp[-4].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ;
                                                            }
#line 1638 "trad2.tab.c"
    break;

  case 39: /* st_for: FOR '(' sentencia ';' expresion ';' op_inc_dec ')' '{' bq_sent '}'  */
#line 236 "trad2.y"
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
#line 1653 "trad2.tab.c"
    break;

  case 40: /* st_if: IF '(' expresion ')' '{' bq_sent '}'  */
#line 248 "trad2.y"
                                                                            { sprintf (temp, "(if %s\n(progn\n%s\n)\n)", yyvsp[-4].code, yyvsp[-1].code) ;
                                                                              yyval.code = gen_code (temp) ; }
#line 1660 "trad2.tab.c"
    break;

  case 41: /* st_if: IF '(' expresion ')' '{' bq_sent '}' ELSE '{' bq_sent '}'  */
#line 251 "trad2.y"
                                                                            { sprintf (temp, "(if %s\n(progn\n%s\n)\n(progn\n%s\n)\n)", yyvsp[-8].code,   yyvsp[-5].code, yyvsp[-1].code) ;
                                                                              yyval.code = gen_code (temp) ; }
#line 1667 "trad2.tab.c"
    break;

  case 42: /* st_switch: SWITCH '(' expresion ')' '{' lista_cases opt_default '}'  */
#line 255 "trad2.y"
                                                                            { if (strlen (yyvsp[-2].code) > 0) {
                                                                                sprintf (temp, "(case %s\n%s\n%s\n)", yyvsp[-5].code, yyvsp[-2].code, yyvsp[-1].code) ;
                                                                              } else {
                                                                                sprintf (temp, "(case %s\n%s\n)", yyvsp[-5].code, yyvsp[-1].code) ;
                                                                              }
                                                                              yyval.code = gen_code (temp) ;
                                                                            }
#line 1679 "trad2.tab.c"
    break;

  case 43: /* lista_cases: case_item  */
#line 264 "trad2.y"
                                                                            { yyval = yyvsp[0] ; }
#line 1685 "trad2.tab.c"
    break;

  case 44: /* lista_cases: lista_cases case_item  */
#line 265 "trad2.y"
                                                                            { sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                                              yyval.code = gen_code (temp) ; }
#line 1692 "trad2.tab.c"
    break;

  case 45: /* case_item: CASE NUMBER ':' bq_sent BREAK ';'  */
#line 269 "trad2.y"
                                                                            {
                                                                              if (strlen (yyvsp[-2].code) > 0) {
                                                                                sprintf (temp, "(%d\n%s\n)", yyvsp[-4].value, yyvsp[-2].code) ;
                                                                              } else {
                                                                                sprintf (temp, "(%d)", yyvsp[-4].value) ;
                                                                              }
                                                                              yyval.code = gen_code (temp) ;
                                                                            }
#line 1705 "trad2.tab.c"
    break;

  case 46: /* opt_default: %empty  */
#line 279 "trad2.y"
                                                                            { yyval.code = gen_code ("") ; }
#line 1711 "trad2.tab.c"
    break;

  case 47: /* opt_default: DEFAULT ':' bq_sent BREAK ';'  */
#line 280 "trad2.y"
                                                                            { if (strlen (yyvsp[-2].code) > 0) {
                                                                                sprintf (temp, "(otherwise\n%s\n)", yyvsp[-2].code) ;
                                                                              } else {
                                                                                sprintf (temp, "(otherwise)") ;
                                                                              }
                                                                              yyval.code = gen_code (temp) ;
                                                                            }
#line 1723 "trad2.tab.c"
    break;

  case 48: /* elem_print: expresion  */
#line 289 "trad2.y"
                                                            { yyval = yyvsp[0] ; }
#line 1729 "trad2.tab.c"
    break;

  case 49: /* elem_print: STRING  */
#line 290 "trad2.y"
                                                            { sprintf (temp, "\"%s\"", yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1736 "trad2.tab.c"
    break;

  case 50: /* lista_print: elem_print  */
#line 294 "trad2.y"
                                                            { sprintf (temp, "(princ %s)", yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1743 "trad2.tab.c"
    break;

  case 51: /* lista_print: elem_print ',' lista_print  */
#line 296 "trad2.y"
                                                            { sprintf (temp, "(princ %s)\n%s", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1750 "trad2.tab.c"
    break;

  case 52: /* lista_arg: %empty  */
#line 300 "trad2.y"
                                                        { yyval.code = gen_code ("") ; }
#line 1756 "trad2.tab.c"
    break;

  case 53: /* lista_arg: arg_nonempty  */
#line 301 "trad2.y"
                                                        { yyval = yyvsp[0] ; }
#line 1762 "trad2.tab.c"
    break;

  case 54: /* arg_nonempty: expresion  */
#line 304 "trad2.y"
                                                        { yyval = yyvsp[0] ; }
#line 1768 "trad2.tab.c"
    break;

  case 55: /* arg_nonempty: expresion ',' arg_nonempty  */
#line 305 "trad2.y"
                                                        { sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code (temp) ; }
#line 1775 "trad2.tab.c"
    break;

  case 56: /* expresion: termino  */
#line 309 "trad2.y"
                                                            { yyval = yyvsp[0] ; }
#line 1781 "trad2.tab.c"
    break;

  case 57: /* expresion: expresion OR expresion  */
#line 310 "trad2.y"
                                                            { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1788 "trad2.tab.c"
    break;

  case 58: /* expresion: expresion AND expresion  */
#line 312 "trad2.y"
                                                            { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1795 "trad2.tab.c"
    break;

  case 59: /* expresion: expresion EQ expresion  */
#line 314 "trad2.y"
                                                            { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1802 "trad2.tab.c"
    break;

  case 60: /* expresion: expresion NE expresion  */
#line 316 "trad2.y"
                                                            { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1809 "trad2.tab.c"
    break;

  case 61: /* expresion: expresion '<' expresion  */
#line 318 "trad2.y"
                                                            { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1816 "trad2.tab.c"
    break;

  case 62: /* expresion: expresion LE expresion  */
#line 320 "trad2.y"
                                                            { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1823 "trad2.tab.c"
    break;

  case 63: /* expresion: expresion '>' expresion  */
#line 322 "trad2.y"
                                                            { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1830 "trad2.tab.c"
    break;

  case 64: /* expresion: expresion GE expresion  */
#line 324 "trad2.y"
                                                            { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1837 "trad2.tab.c"
    break;

  case 65: /* expresion: expresion '+' expresion  */
#line 326 "trad2.y"
                                                            { sprintf (temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1844 "trad2.tab.c"
    break;

  case 66: /* expresion: expresion '-' expresion  */
#line 328 "trad2.y"
                                                            { sprintf (temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1851 "trad2.tab.c"
    break;

  case 67: /* expresion: expresion '*' expresion  */
#line 330 "trad2.y"
                                                            { sprintf (temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1858 "trad2.tab.c"
    break;

  case 68: /* expresion: expresion '/' expresion  */
#line 332 "trad2.y"
                                                            { sprintf (temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1865 "trad2.tab.c"
    break;

  case 69: /* expresion: expresion '%' expresion  */
#line 334 "trad2.y"
                                                            { sprintf (temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1872 "trad2.tab.c"
    break;

  case 70: /* termino: operando  */
#line 338 "trad2.y"
                                                            { yyval = yyvsp[0] ; }
#line 1878 "trad2.tab.c"
    break;

  case 71: /* termino: '+' operando  */
#line 339 "trad2.y"
                                                            { yyval = yyvsp[-1] ; }
#line 1884 "trad2.tab.c"
    break;

  case 72: /* termino: '-' operando  */
#line 340 "trad2.y"
                                                            { sprintf (temp, "(- %s)", yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1891 "trad2.tab.c"
    break;

  case 73: /* termino: '!' operando  */
#line 342 "trad2.y"
                                                            { sprintf (temp, "(not %s)", yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1898 "trad2.tab.c"
    break;

  case 74: /* operando: IDENTIF  */
#line 346 "trad2.y"
                                                            { sprintf (temp, "%s", get_var_name(yyvsp[0].code)) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1905 "trad2.tab.c"
    break;

  case 75: /* operando: NUMBER  */
#line 348 "trad2.y"
                                                            { sprintf (temp, "%d", yyvsp[0].value) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1912 "trad2.tab.c"
    break;

  case 76: /* operando: '(' expresion ')'  */
#line 350 "trad2.y"
                                                            { yyval = yyvsp[-1] ; }
#line 1918 "trad2.tab.c"
    break;

  case 77: /* operando: IDENTIF '(' lista_arg ')'  */
#line 351 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                                sprintf (temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code) ;
                                                              } else {
                                                                sprintf (temp, "(%s)", yyvsp[-3].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ; 
                                                            }
#line 1930 "trad2.tab.c"
    break;


#line 1934 "trad2.tab.c"

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

#line 361 "trad2.y"
                            // SECCION 4    Codigo en C

int n_line = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_line) ;
    printf ( "\n") ;	// bye
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
    "main",        MAIN ,           // y los token asociados
    "int",         INTEGER ,
    "while",       WHILE ,
    "for",         FOR ,
    "inc",         INC ,
    "dec",         DEC ,
    "puts",        PUTS ,
    "printf",      PRINTF ,
    "&&",          AND ,
    "||",          OR ,
    "==",          EQ ,
    "!=",          NE ,
    "<=",          LE ,
    ">=",          GE ,
    "if",          IF ,
    "else",        ELSE ,
    "switch",      SWITCH ,
    "case",        CASE ,
    "default",     DEFAULT ,
    "break",       BREAK ,
    "return",      RETURN,
    NULL,          0              // para marcar el fin de la tabla
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
char tabla_locales[100][512]; // Tabla para guardar hasta 100 variables locales
int num_locales = 0;

void add_local(char* nombre) {
    sprintf(tabla_locales[num_locales++], "%s_%s", current_function, nombre);
}

int es_local(char* nombre) {
    char nombre_acotado[512];
    sprintf(nombre_acotado, "%s_%s", current_function, nombre);
    for(int i = 0; i < num_locales; i++) {
        if(strcmp(tabla_locales[i], nombre_acotado) == 0) return 1;
    }
    return 0; // No está en la tabla, por lo que es global
}

char* get_var_name(char* id) {
    if (es_local(id)) {
        char temp_name[512];
        sprintf(temp_name, "%s_%s", current_function, id); // Le añade el prefijo de la función actual
        return gen_code(temp_name);
    }
    return id; // Si es global, devuelve el nombre tal cual
}
// ------------------------------------

void set_current_function(char* nombre) {
  strncpy(current_function, nombre, sizeof(current_function) - 1);
  current_function[sizeof(current_function) - 1] = '\0';
}


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
