// SPEC 2: Función MAIN
//   main () { <sentencias> }  ->  (defun main () <sentencias>)
//   La directiva //@ (main) se transcribe como (main) para lanzar la ejecución

int x;

main()
{
    x = 100;
    printf("%d", x);
}

//@ (main)
