// SPEC 10: Estructura de control Switch/Case/Default
//   switch (<var>) {
//     case v1: <sent>; break;
//     case v2: <sent>; break;
//     default: <sent>; break;
//   }
//   ->
//   (case <var>
//     (v1 <expr>)
//     (v2 <expr>)
//     (otherwise <expr>))

int k;

main()
{
    // Caso que entra por case 2
    k = 2;
    switch (k)
    {
    case 1:
        puts("uno");
        break;
    case 2:
        puts("dos");
        break;
    case 3:
        puts("tres");
        break;
    default:
        puts("otro");
        break;
    }

    // Caso que entra por default
    k = 99;
    switch (k)
    {
    case 1:
        puts("nunca");
        break;
    default:
        puts("entra default");
        break;
    }

    // Caso sin default (uso opcional)
    k = 5;
    switch (k)
    {
    case 5:
        puts("cinco sin default");
        break;
    }
}

//@ (main)
