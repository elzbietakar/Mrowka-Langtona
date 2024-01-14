// LINE_VERTICAL:│
// LINE_HORIZONTAL:─
// LINE_DOWN_RIGHT:┌
// LINE_DOWN_LEFT:┐
// LINE_UP_RIGHT:└
// LINE_UP_LEFT:┘
// SQUARE_WHITE: 
// SQUARE_BLACK:█

#include "board.h"

Board initBoard (int rows, int cols) {
	Board B;
	B.rows = rows;
	B.cols = cols;
	
	B.array = malloc( rows * sizeof (int*));
	for (int i = 0; i < rows; i++) 
		B.array[i] = malloc (cols * sizeof (int));
		
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) 
			B.array[i][j] = 0;

	B.ants = NULL;
	B.num_of_ants = 0;

return B;
}

int printBoard (Board * B, FILE * out) {
	
	if (B->array == NULL) {
		fprintf (stderr, "Tablica nie istnieje\n");
		return -1;
	}

	fprintf(out, "┌");
	for (int i = 0; i < B->cols; i++)	
		 fprintf(out, "─");
	fprintf(out, "┐\n");

	for (int i = 0; i < B->rows; i++) {
		fprintf(out, "│");
                
		for (int j = 0; j < B->cols; j++) {
			if ( B->array[i][j] == 0) 
                        	fprintf(out, " ");
			else
				if ( B->array[i][j] == 1)
                                	fprintf(out, "█");	
			     	else
					printAnt(B, i, j, out);
		} 
		
		fprintf(out, "│\n");
	}	

	fprintf(out, "└");
        for (int i = 0; i < B->cols; i++)
                 fprintf(out, "─");
        fprintf(out, "┘\n");
	

return 0;
} 
