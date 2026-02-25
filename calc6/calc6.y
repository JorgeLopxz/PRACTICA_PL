/*
     Raoul Vlad Ivaszuk Ivaszuk, Jorge Lopez Alonso 509
     100508621@alumnos.uc3m.es 100495876@alumnos.uc3m.es
*/
%{                   // SECCION 1 - Definiciones
#include <stdio.h>
%}                   // SECCION 2 - Directivas
%union {                // El tipo de la pila (del AP) tiene caracter dual 
      int valor ;       //  - valor numerico entero 
      int indice ;      //  - indice para identificar una variable 
}  
%token  <valor>  NUMERO    // Todos los token tienen un tipo para la pila
%token  <indice> VARIABLE
%type   <valor>  expresion // Se asocia tambien a los No Terminales un tipo 
%type   <valor>  termino operando
%right  '='             //  es la ultima operacion que se debe realizar
%left   '+' '-'         //  menor orden de precedencia 
%left   '*' '/'         //  orden de precedencia intermedio 
%left   SIGNO_UNARIO    //  mayor orden de precedencia 
%%
                     // SECCION 3: Gramatica - Semantico 
axioma:       expresion '\n'              { printf (".\n") ; } 
                       r_expr
            | VARIABLE '=' expresion '\n' { printf ("%c !\n", $1+'A');}
                       r_expr
            ;

r_expr:                      /* lambda */
            | axioma
            ;

expresion:    termino                    { ; }
            | expresion '+' expresion    { printf("+ ") ;  }
            | expresion '-' expresion    { printf("- ") ;  }
            | expresion '*' expresion    { printf("* ") ;  }
            | expresion '/' expresion    { printf("/ ") ;  }
            ;

termino:      operando                           { ; }
            | '+' operando %prec SIGNO_UNARIO    { ; }
            | '-' operando %prec SIGNO_UNARIO    { printf("negate ") ; }
            ;

operando:     VARIABLE                   { printf("%c @ ", $1+'A'); }
            | NUMERO                     { printf("%d ", $1) ; }
            | '(' expresion ')'          { ; }
            ;

%%

                     /* SECCION 4  Codigo en C */
int n_linea = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_linea) ;
}

int yylex ()
{
    unsigned char c ;

    do {
         c = getchar () ;
    } while (c == ' ') ;

    if (c == '.' || (c >= '0' && c <= '9')) {
         ungetc (c, stdin) ;
         scanf ("%d", &yylval.valor) ;
         return NUMERO ;
    }

    if (c >= 'a' && c <= 'z') {
         yylval.indice = c - 'a' ;  // resta a c el valor ascii de a 
         return VARIABLE ;
    }

    if (c >= 'A' && c <= 'Z') {
         yylval.indice = c - 'A' ;  // resta a c el valor ascii de A
         return VARIABLE ;
    }

    if (c == '\n')
          n_linea++ ;
    return c ;
}

int main ()
{
     int i;
     for (i = 0; i < 26; i++)
         printf ("variable %c ", 'A'+i) ;
     printf ("\n") ;
     printf(": negate 0 swap - ; \n");
    yyparse () ;
    return 0 ;
}
