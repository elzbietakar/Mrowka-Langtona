#include "board.h"
#include "ant.h"

#include <stdio.h>


int main () {

	Board BOARD = initBoard (5, 5); //ilosc wierszy, ilosc kolumn
	Ant ANT = initAnt (&BOARD, 2, 2, 'n', 'r'); //x, y, kierunek [n, e, s, w], druzyna [r, p, s]

	printBoard(&BOARD, &ANT, stdout);

return 0;
}
