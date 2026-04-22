// SPEC 1: Variables Globales
//   a) int <id>;                -> (setq <id> 0)
//   b) int <id> = <cte>;        -> (setq <id> <cte>)
//   c) int <id1>=3, <id2>, ...; -> (setq <id1> 3) (setq <id2> 0) ...

int sin_init;
int con_init = 42;
int mult_a = 1, mult_b, mult_c = 7;

main()
{
    printf("%d", sin_init);
    puts("");
    printf("%d", con_init);
    puts("");
    printf("%d", mult_a);
    puts("");
    printf("%d", mult_b);
    puts("");
    printf("%d", mult_c);
}

//@ (main)
