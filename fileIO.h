//
// Created by bpefei on 2020/5/26.
//

#ifndef INC_1_FILEIO_H
#define INC_1_FILEIO_H

#include <stdio.h>
#include <stdlib.h>
#include "is_something.h"
#define null NULL
#define string const char*
#define Grammer char***
FILE* open(const char* filename, unsigned int* nLines);

char* simplify(string str);

Grammer getGrammer(const char* filename, int* nLs);

void freeGrammer(Grammer waste, int nLs);

#endif //INC_1_FILEIO_H
