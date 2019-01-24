#!/bin/sh


    
gcc -Wall SA_main_discrete2A.c -lm;./a.out 0.075 0.05 0.988 1000;
gcc -Wall SA_main_discrete2A.c -lm;./a.out 0.075 0.05 0.9975 5000;
gcc -Wall SA_main_discrete2A.c -lm;./a.out 0.075 0.05 0.9987 10000;
gcc -Wall SA_main_discrete2A.c -lm;./a.out 0.075 0.05 0.9994 20000;
