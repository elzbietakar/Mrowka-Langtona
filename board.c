#include "board.h"
#include <stdlib.h>


Board initBoard(int rows, int cols) {
    
    Board board;
    board.array =(Ant**)malloc(rows * sizeof(Ant *));
    for (int i = 0; i < rows; i++) {
        board.array[i] = (Ant*)malloc(cols * sizeof(Ant));
    }
    
    board.rows = rows;
    board.cols = cols;
    board.num_of_ants = 0;
    board.antsx =NULL;
    board.antsy =NULL;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            
            board.array[i][j].ant = 0;        
            board.array[i][j].color = 0;      
            board.array[i][j].direction = 0; 
            board.array[i][j].team = 0;      
        }
    }
    return board;
}

int printBoard (Board * B, FILE * out) {
	
	if (B->array == NULL) {
		fprintf (stderr, "Tablica nie istnieje\n");
		return -1;
	}

	fprintf(out, "┌");
	for (int i = 0; i < B->cols; i++)	
		 fprintf(out, "──");
	fprintf(out, "┐\n");

	for (int i = 0; i < B->rows; i++) {
		fprintf(out, "│");
                
		for (int j = 0; j < B->cols; j++) {
			if ( B->array[i][j].ant == 0) {
                if(B->array[i][j].color == 0)
                    fprintf(out, "  ");
                if(B->array[i][j].color == 1)
                    fprintf(out, "██");
            }
            if (B->array[i][j].ant >= 1){
                printAnt(B,i,j,out);
            }
		} 
		
		fprintf(out, "│\n");
	}	

	fprintf(out, "└");
        for (int i = 0; i < B->cols; i++)
                 fprintf(out, "──");
        fprintf(out, "┘\n");
	

return 0;
} 

void MakeBlackSpots(Board *B,int i){
    int j=0;
    int a=0;
    int suma_komorek=B->rows*B->cols;
    while(a==0){
        if((double)j/suma_komorek>(double)i/100)
            a=1;
        int x=rand() % B->rows;
        int y=rand() % B->cols;
        if(B->array[x][y].color==0){
            B->array[x][y].color=1;
            j++;
        }
    } 
}