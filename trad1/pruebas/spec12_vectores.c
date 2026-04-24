// SPEC 12: Vectores
//   Declaración:   int v[N];           -> (setq v (make-array N))
//   Operando:      v[expr]             -> (aref v expr)
//   Receptor:      v[expr] = expr2;    -> (setf (aref v expr) expr2)
//   Se excluyen vectores como parámetro de función.
//   Se permiten como argumento de llamada (indexando un elemento).

int global_vec[5];

mayor(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

main()
{
    int local_vec[3];
    int i = 0;

    // Asignación a vector global por índice
    global_vec[0] = 10;
    global_vec[1] = 20;
    global_vec[2] = 30;
    global_vec[3] = 40;
    global_vec[4] = 50;

    // Acceso a vector global como operando
    printf("%d", global_vec[2]);   // 30
    puts("");

    // Asignación a vector local
    local_vec[0] = 1;
    local_vec[1] = 2;
    local_vec[2] = 3;
    printf("%d", local_vec[1]);    // 2
    puts("");

    // Índice como expresión
    i = 1;
    printf("%d", global_vec[i + 2]);  // 40
    puts("");

    // Vector como argumento (elemento indexado) de una función
    printf("%d", mayor(global_vec[0], global_vec[1])); // 20
}

//@ (main)
