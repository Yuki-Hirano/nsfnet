#!/bin/sh


for rho in 0.9 0.99 0.0999 0.9999;do
	 
		      gcc -Wall SA_main_discrete2A.c -lm;./a.out 0.1 0.05 30000 20000 $rho

done
