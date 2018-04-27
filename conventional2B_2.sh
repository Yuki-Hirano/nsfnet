#!/bin/sh


for T in 10000 1000 100 10 1 0.1 0.01;do
	 for rho in 0.99;do
		  
		      gcc -Wall SA_main_gen2B.c -lm;./a.out 0.01 0.05 $T $rho
	 done
done
