#ifndef _DECLARATIONS_H
#define _DECLARATIONS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Ant {
        int x;
        int y;
        int color;
        char direction;
        char team;

} Ant;

typedef struct Board {
        int ** array;

        int rows;
        int cols;

} Board;


Ant initAnt (Board *B, int x, int y, char direction, char team);

int moveAnt (Board *B, Ant *A);

void printAnt (Ant *A, FILE *out);


int printBoard (Board * B, Ant * A, FILE * out);

Board initBoard (int rows, int cols);

#endif
