#ifndef _BOARD_H
#define _BOARD_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
        int ant;
        int color;
        int direction;
        int team;
} Ant;

typedef struct {
        Ant ** array;
        int rows;
        int cols;
	    int num_of_ants;
        int * antsx;
        int * antsy;

} Board;


Ant initAnt (Board *B, int x, int y, char direction, char team, int alive);

void moveAnt2 (Board *B,int i);

void printAnt (Board *B, int i, int j, FILE *out);

int printBoard (Board *B, FILE * out);

Board initBoard (int rows, int cols) ;

Ant AntWar(Ant A1, Ant A2);

void reset(Ant *A);

Ant moveAnt(Ant A1, Ant A2);

#endif
