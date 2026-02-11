/*
     Raoul Vlad Ivaszuk Ivaszuk, Jorge Lopez Alonso 509
     100508621@alumnos.uc3m.es, 100495876@alumnos.uc3m.es
*/
%{                                /* Seccion 1 Declaraciones de C-bison */
#include <stdio.h>
#define YYSTYPE double            /* tipo de la pila del parser           */
int yyerror () ;
int yylex () ;
%}
%token NUMERO                     /* Seccion 2 Declaraciones de bison      */
%token VARIABLE
%left '+' '-'     /* menor orden de precedencia */
%left '*' '/'     /* orden de precedencia intermedio */
%right '='
%left SIGNO_UNARIO /* define la mayor precedencia, ademas de nuevo token */
%%
                                  /* Seccion 3 Gramatica - Semantico      */
axioma:       expresion '\n' { printf ("Expresion=%lf\n", $1) ; }    r_expr
            ;

r_expr:                    /* lambda */
            | axioma
            ;

expresion:   NUMERO                 { $$ = $1; }
           | VARIABLE                { $$ = 0;  }
           | VARIABLE '=' expresion  { $$ = $3; }
           | expresion '+' expresion { $$ = $1 + $3; }
           | expresion '-' expresion { $$ = $1 - $3; }
           | expresion '*' expresion { $$ = $1 * $3; }
           | expresion '/' expresion { $$ = $1 / $3; }
           | '(' expresion ')'       { $$ = $2; }
           | '-' expresion %prec SIGNO_UNARIO { $$ = -$2; }
           | '+' expresion %prec SIGNO_UNARIO { $$ = $2; }
           ;

%%
                                         /* Seccion 4  Codigo en C    */
int n_linea= 1 ;

int yyerror (char *mensaje)
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_linea) ;
}

/* suprimir la funcion yylex () si se usa flex */
///*
//*/

int main ()
{
    yyparse () ;
}
