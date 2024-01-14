#ifndef _BOARD_H
#define _BOARD_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
        int x;
        int y;
        int color;
        char direction;
        char team;
	int alive;
} Ant;

typedef struct {
        int ** array;
	Ant * ants;

        int rows;
        int cols;
	int num_of_ants;

} Board;


Ant initAnt (Board *B, int x, int y, char direction, char team, int alive);

int moveAnt (Board *B, Ant *A);

void printAnt (Board *B, int x, int y, FILE *out);

int printBoard (Board *B, FILE * out);

Board initBoard (int x, int y);

#endif
