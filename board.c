#include "board.h"

// LINE_VERTICAL:│
// LINE_HORIZONTAL:─
// LINE_DOWN_RIGHT:┌
// LINE_DOWN_LEFT:┐
// LINE_UP_RIGHT:└
// LINE_UP_LEFT:┘
// SQUARE_WHITE: 
// SQUARE_BLACK:█

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

return B;
}

int printBoard (Board * B, Ant *A, FILE * out) {
	
	if (B->array == NULL) {
		fprintf (stderr, "Tablica nie istnieje\n");
		return -1;
	}

	fprintf(out, "┌");
	for (int i = 0; i < 2*B->rows; i++)	
		 fprintf(out, "─");
	fprintf(out, "┐\n");

	for (int i = 0; i < B->rows; i++) {
		fprintf(out, "│");
                for (int j = 0; j < B->cols; j++) {
			if ( B->array[i][j] == 0) 
                        	fprintf(out, "", B->array[i][j]);
			else
				if ( B->array[i][j] == 1)
                                	fprintf(out, "", B->array[i][j]);	
			     	else
					printAnt(A, out);
		fprintf(out, "│\n");
	}	

	fprintf(out, "└");
        for (int i = 0; i < 2*B->rows; i++)
                 fprintf(out, "─");
        fprintf(out, "┘\n");
	

return 0;
} 
