// SPEC 4: Impresión de expresiones y cadenas con printf
//   printf(<string>, <e1>, ..., <eN>); -> (princ <e1>) ... (princ <eN>)
//   El primer <string> (formato) NO se traduce.
//   Los parámetros pueden ser expresiones o strings.

int a = 3;
int b = 4;

main()
{
    // Caso a: printf con un solo parámetro numérico
    printf("formato descartado", 123);
    puts("");

    // Caso a: printf con un solo parámetro string
    printf("formato descartado", " texto ");
    puts("");

    // Caso b: printf con varios parámetros (mezcla expresión + string)
    printf("fmt %d %s %d", a + b, " suma = ", a * b);
}

//@ (main)
