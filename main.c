#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <time.h>

#include "board.h"
#include "read_write.h"



int main (int argc, char **argv) {
    setlocale(LC_ALL, "C.UTF-8");
	clock_t start_time = clock();

	FILE *in= argc > 1 ? fopen( argv[1], "r" ) : NULL;
	FILE *out = argc > 2 ? fopen( argv[2], "w" ) : NULL;

	if (in == NULL) {
  		fprintf(stderr, "BŁąd: nie mogę wczytać planszy\n");
  	    	return -1;
     	} 


	Board BOARD = readFromFile(in);
    printBoard(&BOARD, stdout);
    for(int i=0;i<12000;i++){    
        for(int j=0;j<BOARD.num_of_ants;j++){
            moveAnt2(&BOARD,j);
            
        }
        
    }
	printBoard(&BOARD, stdout);
	if (out != NULL)
		writeToFile(out, &BOARD);
	clock_t end_time = clock();
	double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
	printf("Execution time: %f seconds\n", elapsed_time);

return 0;
}