int global_a = 10;
int global_b;

funcion_prueba()
{
    int local_func = 5;
    int contador = 0;

    puts("Dentro de funcion_prueba");

    while (contador < local_func)
    {
        contador = contador + 1;
        if (contador == 3)
        {
            puts("Mitad del bucle");
        }
    }

    global_b = contador * 2;
}

otra_funcion()
{
    int x = 100;
    puts("Dentro de otra_funcion");
    global_a = x - 50;
}

// Funcion principal
main()
{
    int local_main = 1;

    puts("Iniciando main");

    if (global_a == 50)
    {
        puts("El valor global inicial es correcto");
    }
}

//@ (funcion_prueba)
//@ (otra_funcion)
//@ (main)
