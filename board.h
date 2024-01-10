#ifndef _BOARD_H
#define _BOARD_H

#include <stdio.h>
#include <stdlib.h>

#include "ant.c"

typedef struct Board {
        int ** array;

        int rows;
        int cols;

} Board;

int printBoard (Board * B, Ant * A, FILE * out);

Board initBoard (int rows, int cols);


#endif
