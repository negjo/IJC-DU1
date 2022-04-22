/*
error.h
Řešení IJC-DU1, příklad A), 21.3.2021
Autor: Roman Vintoňak, FIT
Přeloženo: gcc 9.3.0
*/


#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void warning_msg(const char *fmt, ...);
void error_exit(const char *fmt, ...);