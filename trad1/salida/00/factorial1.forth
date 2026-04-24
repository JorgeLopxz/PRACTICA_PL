Gforth 0.7.3, Copyright (C) 1995-2008 Free Software Foundation, Inc.
Gforth comes with ABSOLUTELY NO WARRANTY; for details type `license'
Type `bye' to exit
 variable resultado  0  resultado !   ok
 variable n  0  n !   ok
 : main  7  n !   compiled
 1  resultado !   compiled
 BEGIN  compiled
 n @  1  >  WHILE  compiled
 resultado @  n @  *  resultado !   compiled
 n @  1  -  n !   compiled
 REPEAT  compiled
 resultado @  .  ;  ok
 main 5040  ok

