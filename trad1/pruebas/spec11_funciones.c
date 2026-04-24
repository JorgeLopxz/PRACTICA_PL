// SPEC 11: Funciones
//   a) sin retorno, sin parámetros
//   b) con un parámetro / lista de parámetros
//   c) con return (estructurado: última sentencia)
//   d) llamada como procedimiento (se descarta el valor)
//   Las funciones se definen en orden inverso jerárquico (primero las simples).

// (a) sin parámetros, sin retorno
saluda()
{
    puts("hola");
}

// (b.i) un parámetro, con return (c.i)
cuadrado(int v)
{
    return v * v;
}

// (b.ii) lista de parámetros
suma(int a, int b, int c)
{
    return a + b + c;
}

// (c.ii) return intermedio (return-from)
valor_abs(int n)
{
    if (n < 0)
    {
        return -n;
    }
    return n;
}

// Función que llama a otras
compuesta(int x)
{
    int r = 0;
    r = cuadrado(x) + suma(1, 2, 3);
    return r;
}

main()
{
    int r = 0;

    // (d) llamada como procedimiento
    saluda();

    // llamada en expresión
    r = cuadrado(5);
    printf("%d", r);          // 25
    puts("");

    // llamada con varios parámetros
    printf("%d", suma(10, 20, 30));  // 60
    puts("");

    // return-from intermedio
    printf("%d", valor_abs(-7));     // 7
    puts("");
    printf("%d", valor_abs(9));      // 9
    puts("");

    // llamada en expresión compuesta
    printf("%d", compuesta(4));      // 16 + 6 = 22
}

//@ (main)
