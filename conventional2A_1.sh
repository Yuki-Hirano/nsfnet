#!/bin/sh


for T in 100 10 1 0.1 0.01;do
	 for rho in 0.99;do
		  
		      gcc -Wall SA_main_gen2A.c -lm;./a.out 0.075 0.05 $T $rho
	 done
done
