/*
primes.c
Řešení IJC-DU1, příklad A), 21.3.2021
Autor: Roman Vintoňak, FIT
Přeloženo: gcc 9.3.0
*/


#include "eratosthenes.h"
#include <time.h>

int main(){
    clock_t start = clock();
    bitset_create(abc, 200000000);
    Eratosthenes(abc, 200000000);

    int printed = 0;
    unsigned long to_print[10];
    for(int i = 200000000; printed <= 9; i--){
        if(!bitset_getbit(abc, i)){
            to_print[printed] = i;
            printed++;
        }
    }

    for(int i = 9; i >= 0; i--){
        printf("%lu \n", to_print[i]);
    }
    

    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}