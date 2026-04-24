Gforth 0.7.3, Copyright (C) 1995-2008 Free Software Foundation, Inc.
Gforth comes with ABSOLUTELY NO WARRANTY; for details type `license'
Type `bye' to exit
 variable primo  0  primo !   ok
 variable n  0  n !   ok
 variable m  0  m !   ok
 variable d  0  d !   ok
 variable i  0  i !   ok
 variable p  0  p !   ok
 : main  1  i !   compiled
 1  n !   compiled
 100  m !   compiled
 2  i !   compiled
 BEGIN  compiled
 i @  m @  <  WHILE  compiled
 1  primo !   compiled
 2  d !   compiled
 BEGIN  compiled
 d @  i @  <  WHILE  compiled
 i @  d @  mod  0  =  IF  0  primo !   compiled
 THEN  compiled
 d @  1  +  d !   compiled
 REPEAT  compiled
 primo @  0  = 0=  IF  i @  .  ."  "  THEN  compiled
 i @  1  +  i !   compiled
 REPEAT  compiled
 ;  ok
 main 2  3  5  7  11  13  17  19  23  29  31  37  41  43  47  53  59  61  67  71  73  79  83  89  97   ok

