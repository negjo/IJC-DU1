/*
bitset.h
Řešení IJC-DU1, příklad A), 21.3.2021
Autor: Roman Vintoňak, FIT
Přeloženo: gcc 9.3.0
*/

#include <limits.h>
#include <stdlib.h>
#include <assert.h>
#include "error.h"

typedef unsigned long *bitset_t;
typedef unsigned long bitset_index_t;

#define bitset_create(jmeno_pole, velikost)     static_assert(velikost > 0, "Velikost pole nemůže být záporná!"); \
                                                unsigned long jmeno_pole[(velikost/(CHAR_BIT*sizeof(unsigned long))+2)] = {velikost, 0}

#define bitset_alloc(jmeno_pole, velikost)      unsigned long *jmeno_pole = calloc(velikost/(sizeof(unsigned long))+2, sizeof(unsigned long)); \
                                                if(jmeno_pole == NULL){ \
                                                    printf("bitset_alloc: Chyba alokace paměti"); \
                                                    exit(1); \
                                                }; \
                                                jmeno_pole[0] = velikost



#ifdef USE_INLINE

    static inline void bitset_free(bitset_t jmeno_pole){
        free(jmeno_pole);
    }

    static inline unsigned long bitset_size(bitset_t jmeno_pole){
        return jmeno_pole[0];
    }

    static inline void bitset_setbit(bitset_t jmeno_pole, unsigned long index, int vyraz){
        unsigned long mez = jmeno_pole[0];
        if(index > mez){
            error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)mez);
        }
        (vyraz) ? (jmeno_pole[index/(CHAR_BIT*sizeof(unsigned long))+1] |= (1UL << index%(CHAR_BIT*sizeof(unsigned long)))) : (jmeno_pole[index/(CHAR_BIT*sizeof(unsigned long))+1] &= (~1UL << index%(CHAR_BIT*sizeof(unsigned long))));
    }

    static inline int bitset_getbit(bitset_t jmeno_pole, unsigned long index){
        unsigned long mez = jmeno_pole[0];
        if(index > mez){
            error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)mez);
        }
        return (jmeno_pole[index/(CHAR_BIT*sizeof(unsigned long))+1] & 1UL << index%(CHAR_BIT*sizeof(unsigned long))) ? (1) : (0);
    }

#else
    #define bitset_free(jmeno_pole) free(jmeno_pole)
    #define bitset_size(jmeno_pole) jmeno_pole[0]
    #define bitset_setbit(jmeno_pole, index, vyraz) ((index > jmeno_pole[0]) ? (error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)jmeno_pole[0])) : ((void)0)); \
                                                    (vyraz) ? (jmeno_pole[index/(CHAR_BIT*sizeof(unsigned long))+1] |= (1UL << index%(CHAR_BIT*sizeof(unsigned long)))) : (jmeno_pole[index/(CHAR_BIT*sizeof(unsigned long))+1] &= (~1UL << index%(CHAR_BIT*sizeof(unsigned long))))
   
    #define bitset_getbit(jmeno_pole, index)        ((((unsigned long)index > jmeno_pole[0]) ? (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)jmeno_pole[0])) : ((void)0)) , ((jmeno_pole[index/(CHAR_BIT*sizeof(unsigned long))+1] & 1UL << index%(CHAR_BIT*sizeof(unsigned long))) ? (1) : (0)))
#endif

