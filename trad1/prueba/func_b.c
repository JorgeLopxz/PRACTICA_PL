int global_res = 0;

saluda()
{
    puts("--- Iniciando pruebas de funciones (Solo paso de parametros) ---");
}

imprime_doble(int x)
{
    printf("El doble del parametro es: ", x * 2);
    puts("");
}

suma_y_guarda(int a, int b)
{
    int local_sum;
    local_sum = a + b;

    global_res = local_sum;

    printf("La suma calculada es: ", local_sum);
    puts("");
}

// Funcion principal
main()
{
    int n1 = 10;
    int n2 = 5;

    saluda();

    imprime_doble(n1);

    imprime_doble(100 + 50);

    suma_y_guarda(n1, n2);

    printf("El valor de la variable global_res despues de la funcion es: ", global_res);
    puts("");
}

//@ (main)
