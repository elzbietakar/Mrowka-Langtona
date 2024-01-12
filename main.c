#include "declarations.h"

#include <stdio.h>


int main () {

	Board BOARD = initBoard (5, 11); //ilosc wierszy, ilosc kolumn
	Ant ANT = initAnt (&BOARD, 2, 5, 'n', 'r'); //x, y, kierunek [n, e, s, w], druzyna [r, p, s]
	
	for (int i = 0; i < 20; i++) {
		moveAnt (&BOARD, &ANT);
		printBoard(&BOARD, &ANT, stdout);
	}

return 0;
}
