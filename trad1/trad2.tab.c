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
  YYSYMBOL_42_ = 42,                       /* '['  */
  YYSYMBOL_43_ = 43,                       /* ']'  */
  YYSYMBOL_44_ = 44,                       /* ':'  */
  YYSYMBOL_45_ = 45,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_axioma = 47,                    /* axioma  */
  YYSYMBOL_def_func = 48,                  /* def_func  */
  YYSYMBOL_def_main = 49,                  /* def_main  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_def_otras = 51,                 /* def_otras  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_lista_param_def = 53,           /* lista_param_def  */
  YYSYMBOL_param_def_nonempty = 54,        /* param_def_nonempty  */
  YYSYMBOL_dec_var = 55,                   /* dec_var  */
  YYSYMBOL_dec_var_local = 56,             /* dec_var_local  */
  YYSYMBOL_integer = 57,                   /* integer  */
  YYSYMBOL_lista_integer = 58,             /* lista_integer  */
  YYSYMBOL_r_integer = 59,                 /* r_integer  */
  YYSYMBOL_integer_local = 60,             /* integer_local  */
  YYSYMBOL_lista_integer_local = 61,       /* lista_integer_local  */
  YYSYMBOL_vector_decl = 62,               /* vector_decl  */
  YYSYMBOL_vector_decl_local = 63,         /* vector_decl_local  */
  YYSYMBOL_bq_sent = 64,                   /* bq_sent  */
  YYSYMBOL_sentencia = 65,                 /* sentencia  */
  YYSYMBOL_op_inc_dec = 66,                /* op_inc_dec  */
  YYSYMBOL_st_while = 67,                  /* st_while  */
  YYSYMBOL_st_for = 68,                    /* st_for  */
  YYSYMBOL_st_if = 69,                     /* st_if  */
  YYSYMBOL_st_switch = 70,                 /* st_switch  */
  YYSYMBOL_lista_cases = 71,               /* lista_cases  */
  YYSYMBOL_case_item = 72,                 /* case_item  */
  YYSYMBOL_opt_default = 73,               /* opt_default  */
  YYSYMBOL_elem_print = 74,                /* elem_print  */
  YYSYMBOL_lista_print = 75,               /* lista_print  */
  YYSYMBOL_lista_arg = 76,                 /* lista_arg  */
  YYSYMBOL_arg_nonempty = 77,              /* arg_nonempty  */
  YYSYMBOL_expresion = 78,                 /* expresion  */
  YYSYMBOL_termino = 79,                   /* termino  */
  YYSYMBOL_operando = 80                   /* operando  */
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
#define YYLAST   442

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

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
       2,     2,     2,    45,     2,     2,     2,    34,     2,     2,
      36,    37,    32,    30,    40,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    41,
      28,    27,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
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
     106,   109,   110,   114,   115,   122,   131,   132,   139,   148,
     152,   154,   158,   160,   165,   169,   172,   177,   182,   187,
     188,   195,   202,   209,   216,   225,   227,   229,   230,   237,
     241,   243,   247,   256,   269,   272,   276,   285,   286,   290,
     300,   301,   310,   311,   315,   317,   321,   322,   325,   326,
     330,   331,   333,   335,   337,   339,   341,   343,   345,   347,
     349,   351,   353,   355,   359,   360,   361,   363,   367,   369,
     371,   372,   374
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
  "';'", "'['", "']'", "':'", "'!'", "$accept", "axioma", "def_func",
  "def_main", "$@1", "def_otras", "$@2", "lista_param_def",
  "param_def_nonempty", "dec_var", "dec_var_local", "integer",
  "lista_integer", "r_integer", "integer_local", "lista_integer_local",
  "vector_decl", "vector_decl_local", "bq_sent", "sentencia", "op_inc_dec",
  "st_while", "st_for", "st_if", "st_switch", "lista_cases", "case_item",
  "opt_default", "elem_print", "lista_print", "lista_arg", "arg_nonempty",
  "expresion", "termino", "operando", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -57,    12,    28,   -57,   -57,    13,   -57,    34,     1,     3,
      27,   -18,   -57,    33,   -57,   -57,   -57,    14,    68,    72,
      45,    35,    83,    52,   -57,   -57,    47,    88,   -57,    53,
      56,   -57,    70,   -57,    58,    14,   -57,   -57,   -57,    96,
      96,    95,    65,    66,    69,    94,   -17,   -57,   -57,   -57,
     -22,    73,    76,    78,    79,    82,    89,    31,   115,    85,
     -57,   -57,   -57,   -57,   -57,   121,    87,    31,    31,    31,
     122,   123,    31,    11,    31,   -57,   -14,     4,     4,    31,
       4,   343,   -57,   -57,   -57,   -57,    91,   127,   343,    99,
     -57,   239,   269,   105,   104,   279,   107,   306,    31,    31,
     -57,   -57,   316,   -57,    31,    31,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,   -57,    70,   -57,
     -57,    31,   111,   -57,     0,   112,    31,   117,   114,   191,
     -57,   399,   350,   408,   408,    50,    50,    50,    50,    32,
      32,   -57,   -57,   -57,   -57,   -57,   -57,   118,   116,   343,
     -57,   215,   134,   -57,   -57,   113,     0,   -57,   137,    18,
     158,    23,   -57,   -57,   -57,   144,   131,   132,   133,   125,
     128,   -57,   135,   139,   167,   176,   143,   -57,   -57,   -57,
     -57,   149,   150,   -57,   381,   400,   156,   -57,   -57,   175,
     147,   148,   -57,   -57,   -57,   -57
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      13,     0,     6,     1,     7,     0,     2,     0,     0,     0,
       0,    22,    19,     0,     3,    14,    15,     9,     0,     0,
      20,     0,     0,     0,    10,    23,     0,     0,     4,    11,
       0,    27,    22,    21,     0,     0,    16,    16,    12,    29,
      29,     0,     0,     0,     0,     0,    22,    24,    17,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
      31,    33,    32,    34,     5,     0,    25,     0,    56,     0,
       0,     0,     0,     0,     0,    79,    78,     0,     0,     0,
       0,    39,    60,    74,     8,    30,     0,     0,    35,     0,
      57,    58,     0,     0,     0,     0,     0,     0,    56,     0,
      75,    76,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    22,    26,
      38,     0,     0,    36,     0,     0,     0,     0,     0,     0,
      80,    62,    61,    63,    64,    66,    68,    65,    67,    69,
      70,    71,    72,    73,    59,    29,    53,    54,     0,    52,
      29,     0,     0,    82,    81,     0,     0,    37,     0,     0,
       0,    50,    47,    42,    55,    44,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,    29,    29,    46,
      29,     0,     0,    29,     0,     0,     0,    40,    41,     0,
       0,     0,    45,    43,    49,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -57,   -57,   -57,   -57,   -57,   138,   -57,   -57,   155,   -57,
     154,   -57,   166,   -44,   -57,   124,   -57,   -57,   -40,   126,
     -57,   -57,   -57,   -57,   -57,   -57,    37,   -57,   -57,    44,
     110,    92,   -56,   -57,   -51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     6,    14,    34,     7,    10,    23,    24,     2,
      39,     8,    12,    20,    42,    47,     9,    43,    44,    59,
     168,    60,    61,    62,    63,   161,   162,   172,   147,   148,
      89,    90,    91,    82,    83
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      45,    81,    66,    75,    76,    67,   146,    75,    76,    18,
      18,    88,     3,    92,    68,    50,    95,    11,    97,    22,
      52,    53,    98,   102,    19,    65,   100,   101,    99,   103,
      77,    78,     4,     5,    75,    76,    79,    57,   166,   167,
      79,    13,    15,   129,    16,    80,   160,   170,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    77,    78,    17,   114,   115,   116,    79,   149,    21,
     151,    25,    28,    50,    66,    26,    80,    51,    52,    53,
     112,   113,   114,   115,   116,    27,    54,    29,    55,    30,
      31,    56,    32,    35,    36,    57,    37,    18,    50,    46,
     149,    41,    51,    52,    53,   155,    48,    49,    58,    69,
     158,    54,    70,    55,    71,    72,    56,    50,    73,     4,
      57,    51,    52,    53,    86,    74,    85,    87,    93,    94,
      54,   118,    55,    64,   117,    56,   120,   184,   185,    57,
     186,    50,   123,   189,   124,    51,    52,    53,   126,   145,
     150,   153,   163,   157,    54,   152,    55,   160,   156,    56,
      50,   169,   173,    57,    51,    52,    53,   174,   175,   177,
     176,   181,   178,    54,   179,    55,   165,   180,    56,    50,
     182,   183,    57,    51,    52,    53,   187,   188,   194,   195,
      38,    40,    54,    33,    55,   192,    84,    56,   171,    96,
     164,    57,   104,   105,   106,   107,   108,   109,   128,     0,
       0,   119,     0,   144,   193,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   104,   105,   106,   107,
     108,   109,     0,     0,   154,     0,     0,     0,     0,     0,
       0,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     104,   105,   106,   107,   108,   109,   159,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,   121,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,     0,   110,   111,   112,
     113,   114,   115,   116,     0,     0,   122,   110,   111,   112,
     113,   114,   115,   116,     0,     0,   125,   104,   105,   106,
     107,   108,   109,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,     0,   110,   111,   112,   113,   114,   115,
     116,     0,     0,   127,   110,   111,   112,   113,   114,   115,
     116,     0,     0,   130,   104,   105,   106,   107,   108,   109,
       0,   104,     0,   106,   107,   108,   109,     0,     0,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   110,   111,
     112,   113,   114,   115,   116,    50,     0,     0,     0,    51,
      52,    53,     0,     0,     0,     0,     0,     0,    54,     0,
      55,     0,     0,    56,    50,     0,   190,    57,    51,    52,
      53,     0,   106,   107,   108,   109,     0,    54,     0,    55,
       0,     0,    56,   108,   109,   191,    57,   110,   111,   112,
     113,   114,   115,   116,     0,     0,   110,   111,   112,   113,
     114,   115,   116
};

static const yytype_int16 yycheck[] =
{
      40,    57,    46,     3,     4,    27,     6,     3,     4,    27,
      27,    67,     0,    69,    36,     4,    72,     4,    74,     5,
       9,    10,    36,    79,    42,    42,    77,    78,    42,    80,
      30,    31,     4,     5,     3,     4,    36,    26,    20,    21,
      36,     7,    41,    99,    41,    45,    23,    24,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    30,    31,    36,    32,    33,    34,    36,   124,    36,
     126,     3,    37,     4,   118,     3,    45,     8,     9,    10,
      30,    31,    32,    33,    34,    40,    17,     4,    19,    37,
      43,    22,     4,    40,    38,    26,    38,    27,     4,     4,
     156,     5,     8,     9,    10,   145,    41,    41,    39,    36,
     150,    17,    36,    19,    36,    36,    22,     4,    36,     4,
      26,     8,     9,    10,     3,    36,    41,    40,     6,     6,
      17,     4,    19,    39,    43,    22,    37,   177,   178,    26,
     180,     4,    37,   183,    40,     8,     9,    10,    41,    38,
      38,    37,    39,    37,    17,    38,    19,    23,    40,    22,
       4,     3,    18,    26,     8,     9,    10,    36,    36,    44,
      37,     4,    44,    17,    39,    19,    39,    38,    22,     4,
       4,    38,    26,     8,     9,    10,    37,    37,    41,    41,
      35,    37,    17,    27,    19,    39,    58,    22,   161,    73,
     156,    26,    11,    12,    13,    14,    15,    16,    98,    -1,
      -1,    87,    -1,   121,    39,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    11,    12,    13,    14,
      15,    16,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      11,    12,    13,    14,    15,    16,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    40,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      11,    12,    13,    14,    15,    16,    -1,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    37,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    37,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    11,    12,    13,
      14,    15,    16,    -1,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    37,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    37,    11,    12,    13,    14,    15,    16,
      -1,    11,    -1,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    28,    29,
      30,    31,    32,    33,    34,     4,    -1,    -1,    -1,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      19,    -1,    -1,    22,     4,    -1,    25,    26,     8,     9,
      10,    -1,    13,    14,    15,    16,    -1,    17,    -1,    19,
      -1,    -1,    22,    15,    16,    25,    26,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,    55,     0,     4,     5,    48,    51,    57,    62,
      52,     4,    58,     7,    49,    41,    41,    36,    27,    42,
      59,    36,     5,    53,    54,     3,     3,    40,    37,     4,
      37,    43,     4,    58,    50,    40,    38,    38,    54,    56,
      56,     5,    60,    63,    64,    64,     4,    61,    41,    41,
       4,     8,     9,    10,    17,    19,    22,    26,    39,    65,
      67,    68,    69,    70,    39,    42,    59,    27,    36,    36,
      36,    36,    36,    36,    36,     3,     4,    30,    31,    36,
      45,    78,    79,    80,    51,    41,     3,    40,    78,    76,
      77,    78,    78,     6,     6,    78,    65,    78,    36,    42,
      80,    80,    78,    80,    11,    12,    13,    14,    15,    16,
      28,    29,    30,    31,    32,    33,    34,    43,     4,    61,
      37,    40,    37,    37,    40,    37,    41,    37,    76,    78,
      37,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    77,    38,     6,    74,    75,    78,
      38,    78,    38,    37,    43,    64,    40,    37,    64,    41,
      23,    71,    72,    39,    75,    39,    20,    21,    66,     3,
      24,    72,    73,    18,    36,    36,    37,    44,    44,    39,
      38,     4,     4,    38,    64,    64,    64,    37,    37,    64,
      25,    25,    39,    39,    41,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    50,    49,    51,    52,    51,    53,
      53,    54,    54,    55,    55,    55,    56,    56,    56,    57,
      58,    58,    59,    59,    60,    61,    61,    62,    63,    64,
      64,    64,    64,    64,    64,    65,    65,    65,    65,    65,
      66,    66,    67,    68,    69,    69,    70,    71,    71,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    79,    79,    79,    79,    80,    80,
      80,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     8,     0,     0,    10,     0,
       1,     2,     4,     0,     3,     3,     0,     3,     3,     2,
       2,     4,     0,     2,     2,     2,     4,     5,     5,     0,
       3,     2,     2,     2,     2,     3,     4,     6,     4,     2,
       4,     4,     7,    11,     7,    11,     8,     1,     2,     6,
       0,     5,     1,     1,     1,     3,     0,     1,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     2,     2,     2,     1,     1,
       3,     4,     4
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
#line 1364 "trad2.tab.c"
    break;

  case 3: /* def_func: def_otras def_main  */
#line 89 "trad2.y"
                                                            { sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1371 "trad2.tab.c"
    break;

  case 4: /* $@1: %empty  */
#line 93 "trad2.y"
                             { set_current_function ("main") ; }
#line 1377 "trad2.tab.c"
    break;

  case 5: /* def_main: MAIN '(' ')' $@1 '{' dec_var_local bq_sent '}'  */
#line 94 "trad2.y"
                                                                { sprintf (temp, "(defun main ()\n%s\n%s)", yyvsp[-2].code, yyvsp[-1].code) ;
                                                                  yyval.code = gen_code (temp) ; }
#line 1384 "trad2.tab.c"
    break;

  case 6: /* def_otras: %empty  */
#line 98 "trad2.y"
                                                                { yyval.code = gen_code ("") ; }
#line 1390 "trad2.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 99 "trad2.y"
                        { set_current_function (yyvsp[0].code) ; }
#line 1396 "trad2.tab.c"
    break;

  case 8: /* def_otras: IDENTIF $@2 '(' lista_param_def ')' '{' dec_var_local bq_sent '}' def_otras  */
#line 100 "trad2.y"
                                                                { sprintf (temp, "(defun %s (%s)\n%s\n%s)\n\n%s", yyvsp[-9].code, yyvsp[-6].code, yyvsp[-3].code, yyvsp[-2].code, yyvsp[0].code) ;
                                                                  yyval.code = gen_code (temp) ;
                                                                }
#line 1404 "trad2.tab.c"
    break;

  case 9: /* lista_param_def: %empty  */
#line 105 "trad2.y"
                                                                    { yyval.code = gen_code ("") ; }
#line 1410 "trad2.tab.c"
    break;

  case 10: /* lista_param_def: param_def_nonempty  */
#line 106 "trad2.y"
                                                                    { yyval = yyvsp[0] ; }
#line 1416 "trad2.tab.c"
    break;

  case 11: /* param_def_nonempty: INTEGER IDENTIF  */
#line 109 "trad2.y"
                                                                    { yyval.code = gen_code (yyvsp[0].code) ; }
#line 1422 "trad2.tab.c"
    break;

  case 12: /* param_def_nonempty: INTEGER IDENTIF ',' param_def_nonempty  */
#line 110 "trad2.y"
                                                                    { sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ; 
                                                                      yyval.code = gen_code (temp) ; }
#line 1429 "trad2.tab.c"
    break;

  case 13: /* dec_var: %empty  */
#line 114 "trad2.y"
                                                            { yyval.code = gen_code ("") ; }
#line 1435 "trad2.tab.c"
    break;

  case 14: /* dec_var: dec_var integer ';'  */
#line 115 "trad2.y"
                                                            { if (strlen (yyvsp[-2].code) > 0) {
                                                                sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[-1].code) ;
                                                              } else {
                                                                sprintf (temp, "%s", yyvsp[-1].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ;
                                                            }
#line 1447 "trad2.tab.c"
    break;

  case 15: /* dec_var: dec_var vector_decl ';'  */
#line 122 "trad2.y"
                                                            { if (strlen (yyvsp[-2].code) > 0) {
                                                                sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[-1].code) ;
                                                              } else {
                                                                sprintf (temp, "%s", yyvsp[-1].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ;
                                                            }
#line 1459 "trad2.tab.c"
    break;

  case 16: /* dec_var_local: %empty  */
#line 131 "trad2.y"
                                                                { yyval.code = gen_code ("") ; }
#line 1465 "trad2.tab.c"
    break;

  case 17: /* dec_var_local: dec_var_local integer_local ';'  */
#line 132 "trad2.y"
                                                                { if (strlen (yyvsp[-2].code) > 0) {
                                                                    sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[-1].code) ;
                                                                  } else {
                                                                    sprintf (temp, "%s", yyvsp[-1].code) ;
                                                                  }
                                                                  yyval.code = gen_code (temp) ; 
                                                                }
#line 1477 "trad2.tab.c"
    break;

  case 18: /* dec_var_local: dec_var_local vector_decl_local ';'  */
#line 139 "trad2.y"
                                                                { if (strlen (yyvsp[-2].code) > 0) {
                                                                    sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[-1].code) ;
                                                                  } else {
                                                                    sprintf (temp, "%s", yyvsp[-1].code) ;
                                                                  }
                                                                  yyval.code = gen_code (temp) ;
                                                                }
#line 1489 "trad2.tab.c"
    break;

  case 19: /* integer: INTEGER lista_integer  */
#line 148 "trad2.y"
                                                            { yyval = yyvsp[0] ; }
#line 1495 "trad2.tab.c"
    break;

  case 20: /* lista_integer: IDENTIF r_integer  */
#line 152 "trad2.y"
                                                            { sprintf (temp, "(setq %s %s)", yyvsp[-1].code, yyvsp[0].code);
                                                              yyval.code = gen_code(temp); }
#line 1502 "trad2.tab.c"
    break;

  case 21: /* lista_integer: IDENTIF r_integer ',' lista_integer  */
#line 154 "trad2.y"
                                                            { sprintf (temp, "(setq %s %s) \n%s", yyvsp[-3].code, yyvsp[-2].code, yyvsp[0].code);
                                                              yyval.code = gen_code(temp); }
#line 1509 "trad2.tab.c"
    break;

  case 22: /* r_integer: %empty  */
#line 158 "trad2.y"
                                                            { sprintf (temp, "0");
                                                              yyval.code = gen_code(temp);}
#line 1516 "trad2.tab.c"
    break;

  case 23: /* r_integer: '=' NUMBER  */
#line 160 "trad2.y"
                                                            { sprintf (temp, "%s", int_to_string(yyvsp[0].value));
                                                              yyval.code = gen_code(temp);}
#line 1523 "trad2.tab.c"
    break;

  case 24: /* integer_local: INTEGER lista_integer_local  */
#line 165 "trad2.y"
                                                                { yyval = yyvsp[0] ; }
#line 1529 "trad2.tab.c"
    break;

  case 25: /* lista_integer_local: IDENTIF r_integer  */
#line 169 "trad2.y"
                                                                { add_local(yyvsp[-1].code);
                                                                  sprintf (temp, "(setq %s_%s %s)", current_function, yyvsp[-1].code, yyvsp[0].code);
                                                                  yyval.code = gen_code(temp); }
#line 1537 "trad2.tab.c"
    break;

  case 26: /* lista_integer_local: IDENTIF r_integer ',' lista_integer_local  */
#line 172 "trad2.y"
                                                                { add_local(yyvsp[-3].code);
                                                                  sprintf (temp, "(setq %s_%s %s) \n%s", current_function, yyvsp[-3].code, yyvsp[-2].code, yyvsp[0].code);
                                                                  yyval.code = gen_code(temp); }
#line 1545 "trad2.tab.c"
    break;

  case 27: /* vector_decl: INTEGER IDENTIF '[' NUMBER ']'  */
#line 177 "trad2.y"
                                                               { sprintf (temp, "(setq %s (make-array %d))", yyvsp[-3].code, yyvsp[-1].value) ;
                                                                  yyval.code = gen_code (temp) ; }
#line 1552 "trad2.tab.c"
    break;

  case 28: /* vector_decl_local: INTEGER IDENTIF '[' NUMBER ']'  */
#line 182 "trad2.y"
                                                               { add_local(yyvsp[-3].code) ;
                                                                  sprintf (temp, "(setq main_%s (make-array %d))", yyvsp[-3].code, yyvsp[-1].value) ;
                                                                  yyval.code = gen_code (temp) ; }
#line 1560 "trad2.tab.c"
    break;

  case 29: /* bq_sent: %empty  */
#line 187 "trad2.y"
                                                            { yyval.code = gen_code ("") ; }
#line 1566 "trad2.tab.c"
    break;

  case 30: /* bq_sent: bq_sent sentencia ';'  */
#line 188 "trad2.y"
                                                            { if (strlen (yyvsp[-2].code) > 0) {
                                                                sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[-1].code) ;
                                                              } else {
                                                                sprintf (temp, "%s", yyvsp[-1].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ;
                                                            }
#line 1578 "trad2.tab.c"
    break;

  case 31: /* bq_sent: bq_sent st_while  */
#line 195 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                                sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                              } else {
                                                                sprintf (temp, "%s", yyvsp[0].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ;
                                                            }
#line 1590 "trad2.tab.c"
    break;

  case 32: /* bq_sent: bq_sent st_if  */
#line 202 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                              sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                              } else {
                                                                sprintf (temp, "%s", yyvsp[0].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ; 
                                                            }
#line 1602 "trad2.tab.c"
    break;

  case 33: /* bq_sent: bq_sent st_for  */
#line 209 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                                sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                              } else {
                                                                sprintf (temp, "%s", yyvsp[0].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ; 
                                                            }
#line 1614 "trad2.tab.c"
    break;

  case 34: /* bq_sent: bq_sent st_switch  */
#line 216 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                              sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                              } else {
                                                              sprintf (temp, "%s", yyvsp[0].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ;
                                                            }
#line 1626 "trad2.tab.c"
    break;

  case 35: /* sentencia: IDENTIF '=' expresion  */
#line 225 "trad2.y"
                                                            { sprintf (temp, "(setf %s %s)", get_var_name(yyvsp[-2].code), yyvsp[0].code) ; 
                                                              yyval.code = gen_code (temp) ; }
#line 1633 "trad2.tab.c"
    break;

  case 36: /* sentencia: PUTS '(' STRING ')'  */
#line 227 "trad2.y"
                                                            { sprintf (temp, "(print \"%s\")", yyvsp[-1].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1640 "trad2.tab.c"
    break;

  case 37: /* sentencia: PRINTF '(' STRING ',' lista_print ')'  */
#line 229 "trad2.y"
                                                            { yyval = yyvsp[-1] ; }
#line 1646 "trad2.tab.c"
    break;

  case 38: /* sentencia: IDENTIF '(' lista_arg ')'  */
#line 230 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                                sprintf (temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code) ;
                                                              } else {
                                                                sprintf (temp, "(%s)", yyvsp[-3].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ; 
                                                            }
#line 1658 "trad2.tab.c"
    break;

  case 39: /* sentencia: RETURN expresion  */
#line 237 "trad2.y"
                                                            { sprintf (temp, "(return-from %s %s)", current_function, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1665 "trad2.tab.c"
    break;

  case 40: /* op_inc_dec: INC '(' IDENTIF ')'  */
#line 241 "trad2.y"
                                            { sprintf (temp, "(setf %s (+ %s 1))", get_var_name(yyvsp[-1].code), get_var_name(yyvsp[-1].code)) ;
                                              yyval.code = gen_code (temp) ; }
#line 1672 "trad2.tab.c"
    break;

  case 41: /* op_inc_dec: DEC '(' IDENTIF ')'  */
#line 243 "trad2.y"
                                            { sprintf (temp, "(setf %s (- %s 1))", get_var_name(yyvsp[-1].code), get_var_name(yyvsp[-1].code)) ;
                                              yyval.code = gen_code (temp) ; }
#line 1679 "trad2.tab.c"
    break;

  case 42: /* st_while: WHILE '(' expresion ')' '{' bq_sent '}'  */
#line 247 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                                sprintf (temp, "(loop while %s do\n%s)", yyvsp[-4].code, yyvsp[-1].code) ;
                                                              } else {
                                                                sprintf (temp, "(loop while %s do)", yyvsp[-4].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ;
                                                            }
#line 1691 "trad2.tab.c"
    break;

  case 43: /* st_for: FOR '(' sentencia ';' expresion ';' op_inc_dec ')' '{' bq_sent '}'  */
#line 257 "trad2.y"
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
#line 1706 "trad2.tab.c"
    break;

  case 44: /* st_if: IF '(' expresion ')' '{' bq_sent '}'  */
#line 269 "trad2.y"
                                                                            { sprintf (temp, "(if %s\n(progn\n%s\n)\n)", yyvsp[-4].code, yyvsp[-1].code) ;
                                                                              yyval.code = gen_code (temp) ; }
#line 1713 "trad2.tab.c"
    break;

  case 45: /* st_if: IF '(' expresion ')' '{' bq_sent '}' ELSE '{' bq_sent '}'  */
#line 272 "trad2.y"
                                                                            { sprintf (temp, "(if %s\n(progn\n%s\n)\n(progn\n%s\n)\n)", yyvsp[-8].code,   yyvsp[-5].code, yyvsp[-1].code) ;
                                                                              yyval.code = gen_code (temp) ; }
#line 1720 "trad2.tab.c"
    break;

  case 46: /* st_switch: SWITCH '(' expresion ')' '{' lista_cases opt_default '}'  */
#line 276 "trad2.y"
                                                                            { if (strlen (yyvsp[-2].code) > 0) {
                                                                                sprintf (temp, "(case %s\n%s\n%s\n)", yyvsp[-5].code, yyvsp[-2].code, yyvsp[-1].code) ;
                                                                              } else {
                                                                                sprintf (temp, "(case %s\n%s\n)", yyvsp[-5].code, yyvsp[-1].code) ;
                                                                              }
                                                                              yyval.code = gen_code (temp) ;
                                                                            }
#line 1732 "trad2.tab.c"
    break;

  case 47: /* lista_cases: case_item  */
#line 285 "trad2.y"
                                                                            { yyval = yyvsp[0] ; }
#line 1738 "trad2.tab.c"
    break;

  case 48: /* lista_cases: lista_cases case_item  */
#line 286 "trad2.y"
                                                                            { sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                                              yyval.code = gen_code (temp) ; }
#line 1745 "trad2.tab.c"
    break;

  case 49: /* case_item: CASE NUMBER ':' bq_sent BREAK ';'  */
#line 290 "trad2.y"
                                                                            {
                                                                              if (strlen (yyvsp[-2].code) > 0) {
                                                                                sprintf (temp, "(%d\n%s\n)", yyvsp[-4].value, yyvsp[-2].code) ;
                                                                              } else {
                                                                                sprintf (temp, "(%d)", yyvsp[-4].value) ;
                                                                              }
                                                                              yyval.code = gen_code (temp) ;
                                                                            }
#line 1758 "trad2.tab.c"
    break;

  case 50: /* opt_default: %empty  */
#line 300 "trad2.y"
                                                                            { yyval.code = gen_code ("") ; }
#line 1764 "trad2.tab.c"
    break;

  case 51: /* opt_default: DEFAULT ':' bq_sent BREAK ';'  */
#line 301 "trad2.y"
                                                                            { if (strlen (yyvsp[-2].code) > 0) {
                                                                                sprintf (temp, "(otherwise\n%s\n)", yyvsp[-2].code) ;
                                                                              } else {
                                                                                sprintf (temp, "(otherwise)") ;
                                                                              }
                                                                              yyval.code = gen_code (temp) ;
                                                                            }
#line 1776 "trad2.tab.c"
    break;

  case 52: /* elem_print: expresion  */
#line 310 "trad2.y"
                                                            { yyval = yyvsp[0] ; }
#line 1782 "trad2.tab.c"
    break;

  case 53: /* elem_print: STRING  */
#line 311 "trad2.y"
                                                            { sprintf (temp, "\"%s\"", yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1789 "trad2.tab.c"
    break;

  case 54: /* lista_print: elem_print  */
#line 315 "trad2.y"
                                                            { sprintf (temp, "(princ %s)", yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1796 "trad2.tab.c"
    break;

  case 55: /* lista_print: elem_print ',' lista_print  */
#line 317 "trad2.y"
                                                            { sprintf (temp, "(princ %s)\n%s", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1803 "trad2.tab.c"
    break;

  case 56: /* lista_arg: %empty  */
#line 321 "trad2.y"
                                                        { yyval.code = gen_code ("") ; }
#line 1809 "trad2.tab.c"
    break;

  case 57: /* lista_arg: arg_nonempty  */
#line 322 "trad2.y"
                                                        { yyval = yyvsp[0] ; }
#line 1815 "trad2.tab.c"
    break;

  case 58: /* arg_nonempty: expresion  */
#line 325 "trad2.y"
                                                        { yyval = yyvsp[0] ; }
#line 1821 "trad2.tab.c"
    break;

  case 59: /* arg_nonempty: expresion ',' arg_nonempty  */
#line 326 "trad2.y"
                                                        { sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code (temp) ; }
#line 1828 "trad2.tab.c"
    break;

  case 60: /* expresion: termino  */
#line 330 "trad2.y"
                                                            { yyval = yyvsp[0] ; }
#line 1834 "trad2.tab.c"
    break;

  case 61: /* expresion: expresion OR expresion  */
#line 331 "trad2.y"
                                                            { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1841 "trad2.tab.c"
    break;

  case 62: /* expresion: expresion AND expresion  */
#line 333 "trad2.y"
                                                            { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1848 "trad2.tab.c"
    break;

  case 63: /* expresion: expresion EQ expresion  */
#line 335 "trad2.y"
                                                            { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1855 "trad2.tab.c"
    break;

  case 64: /* expresion: expresion NE expresion  */
#line 337 "trad2.y"
                                                            { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1862 "trad2.tab.c"
    break;

  case 65: /* expresion: expresion '<' expresion  */
#line 339 "trad2.y"
                                                            { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1869 "trad2.tab.c"
    break;

  case 66: /* expresion: expresion LE expresion  */
#line 341 "trad2.y"
                                                            { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1876 "trad2.tab.c"
    break;

  case 67: /* expresion: expresion '>' expresion  */
#line 343 "trad2.y"
                                                            { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1883 "trad2.tab.c"
    break;

  case 68: /* expresion: expresion GE expresion  */
#line 345 "trad2.y"
                                                            { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1890 "trad2.tab.c"
    break;

  case 69: /* expresion: expresion '+' expresion  */
#line 347 "trad2.y"
                                                            { sprintf (temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1897 "trad2.tab.c"
    break;

  case 70: /* expresion: expresion '-' expresion  */
#line 349 "trad2.y"
                                                            { sprintf (temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1904 "trad2.tab.c"
    break;

  case 71: /* expresion: expresion '*' expresion  */
#line 351 "trad2.y"
                                                            { sprintf (temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1911 "trad2.tab.c"
    break;

  case 72: /* expresion: expresion '/' expresion  */
#line 353 "trad2.y"
                                                            { sprintf (temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1918 "trad2.tab.c"
    break;

  case 73: /* expresion: expresion '%' expresion  */
#line 355 "trad2.y"
                                                            { sprintf (temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1925 "trad2.tab.c"
    break;

  case 74: /* termino: operando  */
#line 359 "trad2.y"
                                                            { yyval = yyvsp[0] ; }
#line 1931 "trad2.tab.c"
    break;

  case 75: /* termino: '+' operando  */
#line 360 "trad2.y"
                                                            { yyval = yyvsp[-1] ; }
#line 1937 "trad2.tab.c"
    break;

  case 76: /* termino: '-' operando  */
#line 361 "trad2.y"
                                                            { sprintf (temp, "(- %s)", yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1944 "trad2.tab.c"
    break;

  case 77: /* termino: '!' operando  */
#line 363 "trad2.y"
                                                            { sprintf (temp, "(not %s)", yyvsp[0].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1951 "trad2.tab.c"
    break;

  case 78: /* operando: IDENTIF  */
#line 367 "trad2.y"
                                                            { sprintf (temp, "%s", get_var_name(yyvsp[0].code)) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1958 "trad2.tab.c"
    break;

  case 79: /* operando: NUMBER  */
#line 369 "trad2.y"
                                                            { sprintf (temp, "%d", yyvsp[0].value) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1965 "trad2.tab.c"
    break;

  case 80: /* operando: '(' expresion ')'  */
#line 371 "trad2.y"
                                                            { yyval = yyvsp[-1] ; }
#line 1971 "trad2.tab.c"
    break;

  case 81: /* operando: IDENTIF '[' expresion ']'  */
#line 372 "trad2.y"
                                                            { sprintf (temp, "(aref %s %s)", get_var_name(yyvsp[-3].code), yyvsp[-1].code) ;
                                                              yyval.code = gen_code (temp) ; }
#line 1978 "trad2.tab.c"
    break;

  case 82: /* operando: IDENTIF '(' lista_arg ')'  */
#line 374 "trad2.y"
                                                            { if (strlen (yyvsp[-1].code) > 0) {
                                                                sprintf (temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code) ;
                                                              } else {
                                                                sprintf (temp, "(%s)", yyvsp[-3].code) ;
                                                              }
                                                              yyval.code = gen_code (temp) ; 
                                                            }
#line 1990 "trad2.tab.c"
    break;


#line 1994 "trad2.tab.c"

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

#line 384 "trad2.y"
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
