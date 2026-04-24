// SPEC 6: Estructura de control WHILE
//   while (<expr>) { <codigo> }  ->  (loop while <expr> do <codigo>)

int i;
int suma;

main()
{
    i = 1;
    suma = 0;
    while (i <= 5)
    {
        suma = suma + i;
        i = i + 1;
    }
    printf("%d", suma);   // 15
}

//@ (main)
