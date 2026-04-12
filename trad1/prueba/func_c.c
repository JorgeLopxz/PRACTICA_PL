// Variables globales
int global_res = 0;

// 1. Prueba: Funcion sin parametros (para comprobar que no hemos roto lo anterior)
saluda()
{
    puts("--- Iniciando pruebas de funciones ---");
}

// 2. Prueba: Funcion con 1 parametro (Apartado 11.b.i) y return (Apartado 11.c)
cuadrado(int x)
{
    return x * x;
}

// 3. Prueba: Funcion con multiples parametros (Apartado 11.b.ii) y locales
suma(int a, int b)
{
    // Declaramos una local para ver que no colisiona con los parametros
    int res_local;
    res_local = a + b;
    return res_local;
}

// 4. Prueba: Parametros mezclados con logica condicional
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
    // Variables locales del main
    int n1 = 5;
    int n2 = 10;
    int c = 0;

    // Llamada sin argumentos
    saluda();

    // Llamada con un argumento como expresion
    c = cuadrado(n1);
    printf("El cuadrado de 5 es: \n", c);
    puts("");

    // Llamada con varios argumentos pasando variables
    c = suma(n1, n2);
    printf("La suma de 5 y 10 es: \n", c);
    puts("");

    // Llamada con literales y asignacion a variable global
    global_res = maximo(100, 25);
    printf("El maximo entre 100 y 25 es: \n", global_res);
    puts("");

    // Llamada a funcion anidada o directamente en el printf (como operando)
    printf("El cuadrado de 4 es: \n", cuadrado(4));
    puts("");
}

// Marcador para ejecutar el programa en CLISP
//@ (main)
