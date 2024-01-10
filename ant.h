#ifndef _ANT_H
#define _ANT_H

#include <stdio.h>
#include <stdlib.h>

#include "board.h"

typedef struct Ant {
        int x;
        int y;
	int color;
        char direction;
	char team;

} Ant;

Ant initAnt (B_ptr B, int x, int y, char direction, char team); 

int moveAnt (B_ptr B, Ant *A);

void printAnt (Ant *A, FILE *out);
#endif
