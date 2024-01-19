#include "read_write.h"
#include "board.h"


void writeToFile (FILE *out, Board *B) {

	fprintf(out, "%i %i\n\n", B->rows, B->cols);

        for (int i = 0; i < B->rows; i++) {
                for (int j = 0; j < B->cols; j++)
                        fprintf(out, "%i ", B->array[i][j].color);
                fprintf(out, "\n");
        }

	fprintf(out, "\n\n%i\n\n", B->num_of_ants);
        int x, y;
        for (int i = 0; i < B->num_of_ants; i++) {
                x = B->antsx[i];
                y = B->antsy[i];
                fprintf(out, "%i %i ", x, y);
                fprintf(out,"%i %i %i\n", B->array[x][y].ant, B->array[x][y].direction, B->array[x][y].team);
        }
}


Board readFromFile (FILE *in) {

	int rows, cols;
	fscanf(in, "%i", &rows);
	fscanf(in ,"%i", &cols);

	Board B = initBoard (rows, cols);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			fscanf(in, "%i", &(B.array[i][j].color));

	fscanf(in, "%i", &(B.num_of_ants));
	
	int x, y, ant,direction,team;
	B.antsx=malloc(B.num_of_ants * sizeof(int));
	B.antsy=malloc(B.num_of_ants * sizeof(int));

	for (int i = 0; i < B.num_of_ants; i++) {
		fscanf(in, "%i", &x);
        fscanf(in ,"%i", &y);
		fscanf(in ,"%i", &ant);
		fscanf(in ,"%i", &direction);
		fscanf(in ,"%i", &team);
		B.antsx[i]=x;
		B.antsy[i]=y;
		B.array[x][y].ant =	ant;
		B.array[x][y].direction = direction;
		B.array[x][y].team = team;
	} 

return B;
}
