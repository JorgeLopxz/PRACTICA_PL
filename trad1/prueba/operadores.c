int a = 2;
int b = 3;
int c = 4;

main()
{
    printf("%d", a + b * c); // 14
    puts("");
    printf("%d", (a + b) * c); // 20
    puts("");

    printf("%d", 10 % 3); // 1
    puts("");

    printf("%d", -a + b); // 1
    puts("");

    if (a < b && b < c)
    {
        puts("AND correcto");
    }
    if (a == 2 || b == 0)
    {
        puts("OR correcto");
    }
    if (!(a > b))
    {
        puts("NOT correcto");
    }

    if (a + 1 == b && c - 1 >= b)
    {
        puts("Mezcla correcta");
    }
}

//@ (main)
