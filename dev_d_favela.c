#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include "dev_d_favela.h"

void gritaAe(const char* formato, ...) {
    va_list args;
    va_start(args, formato);
    vprintf(formato, args);
    va_end(args);
}

void esqueceSahDroga(void* ponteiro) {
    free(ponteiro);
}
