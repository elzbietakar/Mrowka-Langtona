#include "read_write.h"
#include "board.h"

void writeToFile (FILE *out, Board *B) {

	fprintf(out, "%i %i\n\n", B->rows, B->cols);

        for (int i = 0; i < B->rows; i++) {
                for (int j = 0; j < B->cols; j++)
                        fprintf(out, "%i", B->array[i][j]);
                fprintf(out, "\n");
        }

	fprintf(out, "\n%i\n", B->num_of_ants);

	for (int i = 0; i < B->num_of_ants; i++) 
		fprintf(out, "%i %i %i %c %c %i\n", B->ants[i].x, B->ants[i].y, B->ants[i].color, B->ants[i].direction, B->ants[i].team, B->ants[i].alive);
}


Board readFromFile (FILE *in) {

	int rows, cols;
	fscanf(in, "%i", &rows);
	fscanf(in ,"%i", &cols);

	Board B = initBoard (rows, cols);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			fscanf(in, "%i", &(B.array[i][j]));

	fscanf(in, "%i", &(B.num_of_ants));

	B.ants = malloc ( B.num_of_ants * sizeof(Ant));
	
	int x, y, alive;
	char direction, team;

	for (int i = 0; i < B.num_of_ants; i++) {
		fscanf(in, "%i", &x);
        	fscanf(in ,"%i", &y);
		fscanf(in ,"%s", &direction);
		fscanf(in ,"%s", &team);
		fscanf(in ,"%i", &alive);

		B.ants[i] = initAnt (&B, x, y, direction, team, alive);
	} 

return B;
}
