/*
     Raoul Vlad Ivaszuk Ivaszuk, Jorge Lopez Alonso 509
     100508621@alumnos.uc3m.es, 100495876@alumnos.uc3m.es
*/
%{                            /* Primera Seccion */
#include "calc52.tab.h"        /* Cabecera con decl. de token etc. */
extern int n_linea;
%}
%%                            /* Segunda Seccion */
[ \t]                    { ; } /* ignorar espacios y tabuladores */
[0-9]+\.?|[0-9]*\.[0-9]+ { sscanf (yytext, "%lf", &yylval.valor); return (NUMERO); }
[A-Z]                   { yylval.indice = yytext[0] - 'A'; return VARIABLE; }
[a-z]                    { yylval.indice = yytext[0] - 'a' + 26; return VARIABLE; }
\n                       { n_linea++; return ('\n'); }
.                        { return (yytext [0]); }   /* literales */
%%                            /* Tercera Seccion */
int yywrap ()     /* se incluye para evitar un error de compilacion */
{
    return (0) ; /* para el control de fin de fichero */
}
