// Variables globales
int global_a = 10;
int global_b;

// Definicion de una funcion auxiliar sin parametros
funcion_prueba()
{
    // Variables locales de funcion_prueba
    int local_func = 5;
    int contador = 0;

    puts("Dentro de funcion_prueba");

    // Bucle y condicional dentro de la funcion
    while (contador < local_func)
    {
        contador = contador + 1;
        if (contador == 3)
        {
            puts("Mitad del bucle");
        }
    }

    // Modificando una variable global desde la funcion
    global_b = contador * 2;
}

// Definicion de otra funcion auxiliar
otra_funcion()
{
    int x = 100;
    puts("Dentro de otra_funcion");
    global_a = x - 50;
}

// Funcion principal
main()
{
    // Variables locales del main
    int local_main = 1;

    puts("Iniciando main");

    if (global_a == 50)
    {
        puts("El valor global inicial es correcto");
    }

    // Tu Lisp necesitara ejecutar las funciones para probarlas
}

// Codigo embebido para forzar la ejecucion en CLISP y ver que todo compila
//@ (funcion_prueba)
//@ (otra_funcion)
//@ (main)
