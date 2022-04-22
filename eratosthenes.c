/*
eratosthenes.c
Řešení IJC-DU1, příklad A), 21.3.2021
Autor: Roman Vintoňak, FIT
Přeloženo: gcc 9.3.0
*/


#include <stdio.h>
#include <math.h>
#include "eratosthenes.h"


void Eratosthenes(bitset_t pole, unsigned long N){
  
    pole[1] = 3;

    for(int i = 0; i < sqrt(200000000); i++){        
        if(bitset_getbit(pole, i)){
            continue;
        }
        for(unsigned long j = 2*i; j <= N; j += i){
            bitset_setbit(pole, j, 1);
        }
    }
}

