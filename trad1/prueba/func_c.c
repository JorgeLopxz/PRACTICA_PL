int global_res = 0;

saluda()
{
    puts("--- Iniciando pruebas de funciones ---");
}

cuadrado(int x)
{
    return x * x;
}

suma(int a, int b)
{
    int res_local;
    res_local = a + b;
    return res_local;
}

maximo(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// Funcion principal
main()
{
    int n1 = 5;
    int n2 = 10;
    int c = 0;

    saluda();

    c = cuadrado(n1);
    printf("El cuadrado de 5 es: \n", c);
    puts("");

    c = suma(n1, n2);
    printf("La suma de 5 y 10 es: \n", c);
    puts("");

    global_res = maximo(100, 25);
    printf("El maximo entre 100 y 25 es: \n", global_res);
    puts("");

    printf("El cuadrado de 4 es: \n", cuadrado(4));
    puts("");
}

//@ (main)
