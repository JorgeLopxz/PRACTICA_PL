// ESPECIFICACIÓN 1: Variables Globales (simples y múltiples con/sin init)
// ESPECIFICACIÓN 12: Vectores (Declaración global)
int global_a = 10, global_b = 0, global_c;
int vector_global[5];

// ESPECIFICACIÓN 11: Funciones (Parámetros, retornos múltiples, return)
es_par_o_impar(int v)
{
    // ESPECIFICACIÓN 8: Variables Locales
    int local_ep = 0;

    // ESPECIFICACIÓN 7: Estructura de control IF-ELSE
    // ESPECIFICACIÓN 5: Operadores lógicos y relacionales (%, ==)
    if (v % 2 == 0)
    {
        // ESPECIFICACIÓN 3: Impresión de cadenas (puts)
        puts(" El numero es par");
        local_ep = 1;
    }
    else
    {
        puts(" El numero es impar");
        local_ep = 0;
    }
    return local_ep; // Retorno formal
}

procesar_vector(int multiplicador)
{
    int local_i = 0, temp = 0;

    // ESPECIFICACIÓN 9: Estructura de control FOR con macros INC
    for (local_i = 0; local_i < 5; inc(local_i))
    {
        // ESPECIFICACIÓN 12: Vector como operando y en asignación
        temp = vector_global[local_i];
        vector_global[local_i] = temp * multiplicador;
    }
    return 1;
}

// ESPECIFICACIÓN 2: Función MAIN
main()
{
    // ESPECIFICACIÓN 8: Variables Locales Múltiples
    // ESPECIFICACIÓN 12: Vectores (Declaración local)
    int i = 0, j = 0, k = 2, test_val = 4, res = 0;
    int vector_local[3];

    puts("--- INICIANDO PRUEBA DE LAS 12 ESPECIFICACIONES ---");

    // ESPECIFICACIÓN 6: Estructura de control WHILE
    while (i < 5)
    {
        // Asignación simple a un vector
        vector_global[i] = i + 1;
        i = i + 1;
    }

    // ESPECIFICACIÓN 4: Impresión de expresiones y cadenas
    printf("El valor de vector_global en pos 3 es: %d", vector_global[3]);
    puts(""); // Salto de línea

    // Llamada a función que procesa un vector (Especificación 11)
    res = procesar_vector(10);
    printf("Tras multiplicar por 10, vector_global en pos 3 es: %d", vector_global[3]);
    puts("");

    // ESPECIFICACIÓN 10: Estructura de control Switch/Case/Default
    switch (k)
    {
    case 1:
        puts("Ejecutando Caso 1 del switch");
        break;
    case 2:
        // k vale 2, así que debería entrar aquí
        puts("Ejecutando Caso 2 del switch (CORRECTO)");
        break;
    default:
        puts("Ejecutando Caso default del switch");
        break;
    }

    // ESPECIFICACIÓN 5: Precedencia y Operadores Lógicos
    if (global_a > 5 && global_b != 10)
    {
        puts("Condicion relacional compleja evaluada como verdadera");
    }

    // Comprobamos el vector local y las funciones
    vector_local[0] = test_val;
    printf("Probando la funcion es_par con el valor %d extraido del vector", vector_local[0]);
    res = es_par_o_impar(vector_local[0]);

    puts("--- FIN DE LAS PRUEBAS ---");

    return 0; // Return del main
}

//@ (main)
