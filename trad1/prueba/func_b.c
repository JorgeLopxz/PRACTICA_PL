// Variable global para probar que las funciones pueden modificar el entorno
int global_res = 0;

// 1. Prueba: Funcion sin parametros (Apartado 11.a)
saluda()
{
    puts("--- Iniciando pruebas de funciones (Solo paso de parametros) ---");
}

// 2. Prueba: Funcion con 1 parametro (Apartado 11.b.i)
imprime_doble(int x)
{
    printf("El doble del parametro es: ", x * 2);
    puts("");
}

// 3. Prueba: Funcion con multiples parametros y variables locales (Apartado 11.b.ii)
suma_y_guarda(int a, int b)
{
    // Variable local para asegurar que los prefijos funcionan bien junto a los parametros
    int local_sum;
    local_sum = a + b;

    // Modificamos una variable global usando los parametros
    global_res = local_sum;

    printf("La suma calculada es: ", local_sum);
    puts("");
}

// Funcion principal
main()
{
    // Variables locales del main
    int n1 = 10;
    int n2 = 5;

    // Llamada sin argumentos
    saluda();

    // Llamada con un argumento (usando variable local del main)
    imprime_doble(n1);

    // Llamada con un argumento (usando un literal/expresion)
    imprime_doble(100 + 50);

    // Llamada con varios argumentos
    suma_y_guarda(n1, n2);

    // Comprobamos que la funcion anterior logro modificar la variable global
    printf("El valor de la variable global_res despues de la funcion es: ", global_res);
    puts("");
}

// Marcador para ejecutar el programa en CLISP
//@ (main)
