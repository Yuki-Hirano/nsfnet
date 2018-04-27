#!/bin/sh


for rho in 0.9 0.99 0.999 0.9999;do
	
		      gcc -Wall SA_main_discrete2B.c -lm;./a.out 0.075 0.05 30000 20000 $rho
       
done
