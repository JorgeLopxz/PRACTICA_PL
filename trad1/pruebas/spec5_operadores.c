// SPEC 5: Operadores, precedencia y asociatividad
//   Aritméticos: +, -, *, /, %   unarios: +x, -x, !x
//   Lógicos:     &&, ||, !       Relacionales: ==, !=, <, <=, >, >=
//   C    &&  ||  !    !=  ==  <  <=  >  >=  %
//   Lisp and or not  /=  =   <  <=  >  >=  mod

int a = 2;
int b = 3;
int c = 4;

main()
{
    // Precedencia: *,/,% mayor que +,-
    printf("%d", a + b * c);              // 14
    puts("");
    printf("%d", (a + b) * c);            // 20
    puts("");

    // Módulo
    printf("%d", 10 % 3);                 // 1
    puts("");

    // Unario -
    printf("%d", -a + b);                 // 1
    puts("");

    // Relacional y lógico
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

    // Mezcla precedencia aritmética/relacional/lógica
    if (a + 1 == b && c - 1 >= b)
    {
        puts("Mezcla correcta");
    }
}

//@ (main)
