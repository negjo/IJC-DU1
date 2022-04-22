/*
steg-decode.c
Řešení IJC-DU1, příklad A), 21.3.2021
Autor: Roman Vintoňak, FIT
Přeloženo: gcc 9.3.0
*/


#include "ppm.h"
#include "error.h"

int main(int argc, char **argv){

    if(argc != 2){
        exit(1);
    }

    struct ppm *a = ppm_read(argv[1]);
    if(a == NULL){
        error_exit("steg_decode: Chyba čtení souboru");
    }

    unsigned long image_size = (a->xsize)*(a->ysize)*8;
    bitset_alloc(bitset, image_size);
    Eratosthenes(bitset, image_size);

    int letter_bit = 0;
    char letter = 0;
    for(unsigned long i = 23; i < image_size; i++){
        if(!bitset_getbit(bitset, i)){
            
            letter |= ((a->data[i+1] & 1) << letter_bit);
            letter_bit ++;
            if(letter_bit > 7){
                printf("%c", letter);
                if(letter == '\0'){
                    //break;
                }
                letter = 0;
                letter_bit = 0;
            }

        }
    }
    bitset_free(bitset);
    error_exit("Zprává není korektně ukončená pomocí '\\0'");
    return 0;

}
