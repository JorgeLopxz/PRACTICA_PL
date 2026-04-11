int global_a = 100, global_b = 50;
int global_c;

main()
{
    int i = 0;
    int j = 5;
    int k;

    puts("=== INICIO DE PRUEBAS ===");

    puts("1. Asignaciones y Aritmetica");
    global_c = global_a + global_b * 2;
    printf("Resultado 1 (debe ser 200): ", global_c);
    puts("");

    global_c = (global_a - global_b) / 2;
    printf("Resultado 2 (debe ser 25): ", global_c);
    puts("");

    k = 10 % 3;
    printf("Modulo 10%3 (debe ser 1): ", k);
    puts("");
    puts("");

    puts("2. Condicionales (IF/ELSE) y Op. Logicos");
    if (global_a >= 100 && global_b <= 50)
    {
        puts("IF 1: Correcto (AND)");
    }
    else
    {
        puts("IF 1: Incorrecto");
    }

    if (global_a == 0 || global_b != 0)
    {
        puts("IF 2: Correcto (OR y Desigualdad)");
    }
    else
    {
        puts("IF 2: Incorrecto");
    }

    if (!(global_a < 0))
    {
        puts("IF 3: Correcto (NOT unario)");
    }
    puts("");

    puts("3. Bucle WHILE (Cuenta atras 5 a 1)");
    while (j > 0)
    {
        printf("", j);
        j = j - 1;
    }
    puts("");
    puts("");

    puts("4. Bucle FOR con INC y condicional anidado");
    for (i = 0; i <= 4; INC(i))
    {
        if (i % 2 == 0)
        {
            puts("Es par");
        }
        else
        {
            puts("Es impar");
        }
    }

    puts("=== FIN DE PRUEBAS ===");
}
//@ (main)
