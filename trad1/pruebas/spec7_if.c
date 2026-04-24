// SPEC 7: Estructura de control IF / IF-ELSE
//   if (<e>) { <c1> }            -> (if <e> (progn <c1>))
//   if (<e>) { <c1> } else {<c2>}-> (if <e> (progn <c1>) (progn <c2>))

int x = 5;

main()
{
    // IF sin else, rama verdadera
    if (x > 0)
    {
        puts("x positivo");
    }

    // IF-ELSE rama verdadera
    if (x == 5)
    {
        puts("x es 5");
    }
    else
    {
        puts("x no es 5");
    }

    // IF-ELSE rama falsa
    if (x < 0)
    {
        puts("rama nunca");
    }
    else
    {
        puts("rama else");
    }

    // IF anidado
    if (x > 0)
    {
        if (x < 10)
        {
            puts("x esta entre 1 y 9");
        }
    }
}

//@ (main)
