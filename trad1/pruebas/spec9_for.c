// SPEC 9: Estructura de control FOR (versión canónica)
//   for (<ini>; <expr>; INC(x)) { <codigo> }
//   -> <ini> (loop while <expr> do <codigo> (setf x (+ x 1)))
//
//   Los incrementos/decrementos SOLO con las macros INC y DEC.
//   #define INC(x) x=x+1
//   #define DEC(x) x=x-1

int i;
int j;

main()
{
    // FOR ascendente con INC
    for (i = 0; i < 5; INC(i))
    {
        printf("%d ", i);
    }
    puts("");

    // FOR descendente con DEC
    for (j = 5; j > 0; DEC(j))
    {
        printf("%d ", j);
    }
    puts("");

    // FOR con cuerpo vacío: solo el contador
    for (i = 0; i < 3; INC(i))
    {
    }
    printf("%d", i);   // 3
}

//@ (main)
