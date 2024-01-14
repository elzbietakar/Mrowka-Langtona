#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "board.h"
#include "read_write.h"


int main (int argc, char **argv) {

	FILE *in= argc > 1 ? fopen( argv[1], "r" ) : NULL;
	FILE *out = argc > 2 ? fopen( argv[2], "w" ) : NULL;

	if (in == NULL) {
  		fprintf(stderr, "BŁąd: nie mogę wczytać planszy\n");
  	    	return -1;
     	} 

	Board BOARD = readFromFile(in);
	
	for (int i = 0; i < 6; i++) {
		printBoard(&BOARD, stdout);
		for (int j = 0; j < BOARD.num_of_ants; j++) 
			moveAnt(&BOARD, j);
	}

	if (out != NULL)
		writeToFile(out, &BOARD);

return 0;
}
