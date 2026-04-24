// =======================================================================
// PRUEBA GRANDE COMBINADA
// Cubre las 12 especificaciones del enunciado (frontend C -> Lisp).
// -----------------------------------------------------------------------
//   spec  1: Variables globales (simples, inicializadas, múltiples)
//   spec  2: Función main
//   spec  3: puts (cadenas)
//   spec  4: printf (expresiones y cadenas)
//   spec  5: Operadores aritméticos / lógicos / relacionales + precedencia
//   spec  6: while
//   spec  7: if / if-else
//   spec  8: Variables locales (con concatenación <func>_<var>)
//   spec  9: for (con macros INC / DEC)
//   spec 10: switch / case / default
//   spec 11: Funciones (varios parámetros, return estructurado y return-from)
//   spec 12: Vectores (global y local, aref, setf aref, argumento indexado)
// =======================================================================

// -- SPEC 1: Variables Globales --------------------------------------------
int simple;                              // sin init
int contador = 0;                        // con init
int a = 1, b = 2, c = 3;                 // múltiple con init
int vector_global[10];                   // SPEC 12: vector global

// -- SPEC 11.a: función sin parámetros -------------------------------------
cabecera()
{
    puts("==== PRUEBA COMBINADA ====");
}

// -- SPEC 11.b/c: función con parámetro y return estructurado --------------
cuadrado(int v)
{
    return v * v;
}

// -- SPEC 11.c.ii: return-from intermedio (no última sentencia) ------------
valor_abs(int n)
{
    if (n < 0)
    {
        return -n;
    }
    return n;
}

// -- SPEC 11.b.ii: lista de parámetros -------------------------------------
max3(int x, int y, int z)
{
    int m = 0;                           // SPEC 8: local 'm' -> max3_m
    m = x;
    if (y > m)
    {
        m = y;
    }
    if (z > m)
    {
        m = z;
    }
    return m;
}

// Función que carga el vector global usando FOR (SPEC 9)
cargar_vector()
{
    int i = 0;                           // SPEC 8
    for (i = 0; i < 10; INC(i))
    {
        vector_global[i] = i * i;        // SPEC 12: setf aref + SPEC 5 (*)
    }
    return 1;
}

// Suma los elementos del vector entre pos 0 y n-1 usando WHILE (SPEC 6)
suma_vector(int n)
{
    int i = 0, s = 0;                    // SPEC 8: locales múltiples
    while (i < n)                        // SPEC 6
    {
        s = s + vector_global[i];        // SPEC 12: aref
        i = i + 1;
    }
    return s;                            // SPEC 11.c
}

// Clasifica un número usando SWITCH (SPEC 10)
clasifica(int k)
{
    switch (k)
    {
    case 0:
        puts("cero");
        break;
    case 1:
        puts("uno");
        break;
    case 2:
        puts("dos");
        break;
    default:
        puts("otro");
        break;
    }
    return k;
}

// -- SPEC 2: Función main --------------------------------------------------
main()
{
    // SPEC 8: variables locales (con y sin init, simples y múltiples)
    int i = 0, total = 0, res = 0;
    int local_vec[4];                    // SPEC 12: vector local

    cabecera();                          // SPEC 11.d: llamada como procedimiento

    // ----- SPEC 4: printf con varios parámetros --------------------------
    printf("globales: %d %d %d %d", simple, a, b, c);
    puts("");

    // ----- SPEC 5: precedencia y mezcla de operadores --------------------
    printf("%d", a + b * c - 1);                  // 1 + 2*3 - 1 = 6
    puts("");
    printf("%d", (a + b) * c);                    // 9
    puts("");
    printf("%d", 10 % 3 + 1);                     // 1 + 1 = 2
    puts("");

    if (a < b && b < c || a == 99)                // SPEC 5 + SPEC 7
    {
        puts("logica compuesta OK");
    }

    // ----- SPEC 7: if-else --------------------------------------------------
    if (a == 0)
    {
        puts("rama then");
    }
    else
    {
        puts("rama else");
    }

    // ----- SPEC 9: for con INC -------------------------------------------
    for (i = 0; i < 4; INC(i))
    {
        local_vec[i] = i + 1;                     // SPEC 12: setf aref local
    }

    // ----- SPEC 6: while + uso de vector + función ----------------------
    cargar_vector();
    total = suma_vector(5);                       // 0+1+4+9+16 = 30
    printf("suma 0..4 cuadrados = %d", total);
    puts("");

    // ----- SPEC 11: funciones con retorno --------------------------------
    res = cuadrado(7);                            // 49
    printf("cuadrado(7) = %d", res);
    puts("");

    res = max3(local_vec[0], local_vec[2], local_vec[1]);   // max(1,3,2)=3
    printf("max3 local_vec = %d", res);
    puts("");

    res = valor_abs(-123);                        // 123
    printf("|-123| = %d", res);
    puts("");

    // ----- SPEC 10: switch ------------------------------------------------
    clasifica(0);
    clasifica(2);
    clasifica(7);

    // ----- SPEC 9: for descendente con DEC --------------------------------
    for (i = 3; i > 0; DEC(i))
    {
        printf("%d ", i);                         // 3 2 1
    }
    puts("");

    // ----- SPEC 12: índice como expresión + argumento indexado -----------
    printf("%d", vector_global[a + b]);           // vector_global[3] = 9
    puts("");

    puts("==== FIN ====");
    return 0;                                     // SPEC 11.c
}

//@ (main)
