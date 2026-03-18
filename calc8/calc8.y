//  509 , Raoul Vlad Ivaszuk Ivaszuk , Jorge Lopez Alonso
//  100508621@alumnos.uc3m.es , 100495876@alumnos.uc3m.es
%{                      // SECCION 1 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int yylex () ;
extern int yyerror () ;

char temp [2048] ;

#define FF fflush(stdout);

// --- INICIO CÓDIGO AST ---

// Estructura del nodo del Árbol de Sintaxis Abstracta (AST)
typedef struct ASTnode t_node;
struct ASTnode {
    char *op;
    int type; // 0: Hoja, 1: Unario, 2: Binario
    t_node *left;
    t_node *right;
};

// Función para crear un nuevo nodo
t_node * createASTNode (char *op, int type, t_node *left, t_node *right) {
    t_node *node = (t_node*) malloc (sizeof (t_node));
    node->op = strdup (op);
    node->type = type;
    node->left = left;
    node->right = right;
    return node;
}

// Función para liberar la memoria del AST
void freeAST (t_node *node) {
    if (node != NULL) {
        freeAST (node->left);
        freeAST (node->right);
        free (node->op);
        free (node);
    }
}

// Función para imprimir el AST en notación prefija (LISP)
void printAST2Prefix (t_node *node) {
    if (node == NULL) return;
    
    if (node->type == 0) {
        // Nodo Hoja (Número o Variable)
        printf("%s", node->op);
    } else if (node->type == 1) {
        // Nodo Unario (ej. print o menos unario)
        printf("(%s ", node->op);
        printAST2Prefix(node->left);
        printf(")");
    } else {
        // Nodo Binario (+, -, *, /, setq)
        printf("(%s ", node->op);
        printAST2Prefix(node->left);
        printf(" ");
        printAST2Prefix(node->right);
        printf(")");
    }
}
// --- FIN CÓDIGO AST ---

char *mi_malloc (int nbytes)
{
    char *p ;
    static long int nb = 0;
    static int nv = 0 ;
    
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

char *genera_cadena (char *nombre)
{
    char *p ;
    int l ;
    
    l = strlen (nombre)+1 ;
    p = (char *) mi_malloc (l) ;
    strcpy (p, nombre) ;
    
    return p ;
}

char *int_to_string(int n)
{
    sprintf(temp, "%d", n);
    return genera_cadena(temp);
}

char *char_to_string(char c)
{
    sprintf(temp, "%c", c);
    return genera_cadena(temp);
}


typedef struct s_attr {
    int valor ;
	int indice ;
    char *cadena ;
    t_node *node ; // ¡NUEVO! Campo para enlazar el AST
} t_attr ;

#define YYSTYPE t_attr

%}

%token  NUMERO
%token  VARIABLE

%right  '='             //  es la ultima operacion que se debe realizar
%left   '+' '-'         //  menor orden de precedencia 
%left   '*' '/'         //  orden de precedencia intermedio 
%left   SIGNO_UNARIO    //  mayor orden de precedencia 
%%
                
        // SECCION 3: Gramatica - Semantico

axioma:         /* lambda */				{ ; }
            |
            axioma sentencia '\n'	    { 
                                          printAST2Prefix($2.node); 
                                          printf("\n"); 
                                          freeAST($2.node); 
                                        }
            |
            axioma '\n'                 { ; }        
            ;

sentencia:  expresion                   { $$.node = $1.node; }
            |
            asignacion                  { $$.node = $1.node; }
            |
            impresion                   { $$.node = $1.node; }
            ;

asignacion: VARIABLE '=' expresion      {
                                          t_node *var_node = createASTNode(char_to_string($1.indice), 0, NULL, NULL);
                                          $$.node = createASTNode("setq", 2, var_node, $3.node);
                                        }
            | VARIABLE '=' asignacion   { // SOPORTE PARA ASIGNACIONES ENCADENADAS
                                          t_node *var_node = createASTNode(char_to_string($1.indice), 0, NULL, NULL);
                                          $$.node = createASTNode("setq", 2, var_node, $3.node);
                                        }
            ;

impresion:  '@' expresion               { $$.node = createASTNode("print", 1, $2.node, NULL); }
            ;

expresion:  termino					    { $$.node = $1.node ; }
            |
            expresion '+' expresion   	{ $$.node = createASTNode("+", 2, $1.node, $3.node); }
            |
            expresion '-' expresion   	{ $$.node = createASTNode("-", 2, $1.node, $3.node); }
            |
            expresion '*' expresion   	{ $$.node = createASTNode("*", 2, $1.node, $3.node); }
            |
            expresion '/' expresion   	{ $$.node = createASTNode("/", 2, $1.node, $3.node); }
            ;

termino:    operando				    { $$.node = $1.node; }                          
            |
            '+' operando %prec SIGNO_UNARIO { $$.node = $2.node; }
            |
            '-' operando %prec SIGNO_UNARIO { $$.node = createASTNode("-", 1, $2.node, NULL); }  
            ;

operando:   VARIABLE				    { $$.node = createASTNode(char_to_string($1.indice), 0, NULL, NULL); }
            | 
            NUMERO					    { $$.node = createASTNode(int_to_string($1.valor), 0, NULL, NULL); }
            |   
            '(' expresion ')'			{ $$.node = $2.node; }
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
    } while (c == ' ' || c == '\r') ;

    if (c == '.' || (c >= '0' && c <= '9')) {
         ungetc (c, stdin) ;
         scanf ("%d", &yylval.valor) ;
         return NUMERO ;
    }

    if ((c >= 'A' && c <= 'Z') ||
    		 (c >= 'a' && c <= 'z')) {
         yylval.indice = c;
         return VARIABLE ;
    }

    if (c == '\n')
          n_linea++ ;

    return c ;
}

int main ()
{
    yyparse () ;
}