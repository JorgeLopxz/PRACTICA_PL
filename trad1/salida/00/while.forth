Gforth 0.7.3, Copyright (C) 1995-2008 Free Software Foundation, Inc.
Gforth comes with ABSOLUTELY NO WARRANTY; for details type `license'
Type `bye' to exit
 variable a  0  a !   ok
 variable b  0  b !   ok
 : main  10  a !   compiled
 BEGIN  compiled
 a @  0  >  WHILE  compiled
 a @  .  a @  2  mod  0  =  IF  ."  es par " cr  ELSE  compiled
 ."  es impar " cr  THEN  compiled
 a @  1  -  a !   compiled
 REPEAT  compiled
 ;  ok
 main 10  es par 
9  es impar 
8  es par 
7  es impar 
6  es par 
5  es impar 
4  es par 
3  es impar 
2  es par 
1  es impar 
 ok

