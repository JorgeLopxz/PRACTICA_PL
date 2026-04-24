// SPEC 8: Variables Locales
//   Se declaran dentro del cuerpo de la función.
//   Se traducen concatenando el nombre de la función: <func>_<var>
//   Asignaciones usan setf (no setq) para distinguir declaración de asignación.

int a;                 // global 'a'

doble()
{
    int a = 10;        // local 'a' -> doble_a (no colisiona con global 'a')
    int b = 3;         // local 'b' -> doble_b
    a = a + b;
    printf("%d", a);   // 13 (usa local doble_a)
}

main()
{
    int a = 1;         // local 'a' del main -> main_a
    int b = 2, c = 3;  // declaracion multiple local
    a = a + 100;       // setf main_a
    b = c * 2;         // setf main_b
    printf("%d", a);   // 101
    puts("");
    printf("%d", b);   // 6
    puts("");
    doble();           // imprime 13 sin pisar main_a
    puts("");
    printf("%d", a);   // sigue siendo 101
}

//@ (main)
