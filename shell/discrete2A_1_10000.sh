#!/bin/sh


for itr in 6000 7000 8000 9000 10000;do
	 for rho in 0.99;do
		  
		      gcc -Wall SA_main_discrete2A_10000.c -lm;./a.out 0.075 0.05 $itr $rho
	 done
done
