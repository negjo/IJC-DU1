/*
ppm.c
Řešení IJC-DU1, příklad A), 21.3.2021
Autor: Roman Vintoňak, FIT
Přeloženo: gcc 9.3.0
*/
 
#include "ppm.h"

struct ppm * ppm_read(const char * filename){
    FILE *file;
    file = fopen(filename, "rb");
    
    fseek(file, 0L, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    struct ppm *abc = malloc(size*sizeof(char));
    
    if(fscanf(file, "P6 %u %u 255", &abc->xsize, &abc->ysize) != 2){
        free(abc);
        fclose(file);
        warning_msg("ppm_read: chyba formátu souboru");
        return NULL;
    }

    if(fread(abc->data, 1, 3*abc->xsize*abc->ysize, file) == 0){
        free(abc);
        fclose(file);
        warning_msg("ppm_read: chyba formátu souboru");
        return NULL;
    }
    fclose(file);
    return abc;
}

void ppm_free(struct ppm *p);