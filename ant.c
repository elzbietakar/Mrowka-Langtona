// ARROW_NORTH_WHITE:△
// ARROW_NORTH_BLACK:▲
// ARROW_EAST_WHITE:▷
// ARROW_EAST_BLACK:▶
// ARROW_SOUTH_WHITE:▽
// ARROW_SOUTH_BLACK:▼
// ARROW_WEST_WHITE:◁
// ARROW_WEST_BLACK:◀

#include "board.h" 

Ant initAnt (Board *B, int x, int y, char direction, char team, int alive) {
	Ant A;

	A.x = x;
	A.y = y;
	A.color = B->array[x][y];
	A.direction = direction;
	A.team = team;
	A.alive = alive;

	B->array[x][y] = 2; //2 zaznaczamy miejsce mrówki na planszy

return A;
}

int moveAnt (Board *B, Ant *A) {
	
	// zmień kolor aktualnego pola na odwrotne
	if (A->color == 0)
                B->array[A->x][A->y] = 1;
        else
                B->array[A->x][A->y] = 0;

	//odpowiednio przesuń mrówkę
	switch (A->direction) {
        case 'n':
                if (A->color == 0) {
                        A->direction = 'e';
			A->y += 1;
		}
                else { 
                	A->direction = 'w';
			A->y -= 1;        
		}
            break;
        case 'e':
		 if (A->color == 0) {
                        A->direction = 's';
                        A->x += 1;
                }
                else {
                        A->direction = 'n';
                        A->x -= 1;
                }
	    break;
        case 's':
		if (A->color == 0) {
                        A->direction = 'w';
                        A->y -= 1;
                }
                else {
                        A->direction = 'e';
                        A->y += 1;
                }
	    break;
        case 'w':
		if (A->color == 0) {
                        A->direction = 'n';
                        A->x -= 1;
                }
                else {
                        A->direction = 's';
                        A->x += 1;
                }
	    break;
        }

	//nadpisz aktualny kolor pola na którym znajduje się mrówka
	A->color = B->array[A->x][A->y];

	//oznacz pole na którym znajduje się mrówka jako '2'
	B->array[A->x][A->y] = 2;
	
return 0;
}


void printAnt (Board *B, int x, int y, FILE *out) {

	Ant * ant = B->ants;
	while (ant->x != x && ant->y != y)
		ant++;

	//na danym polu jest tylko jedna mrówka
	if (B->array[x][y] == 2) {

		switch (ant->direction) {	
        	case 'n':
			if (ant->color == 0)
            			fprintf(out, "△");
			else 
				fprintf(out, "▲");
            	break;
        	case 'e':
			if (ant->color == 0)
                        	fprintf(out, "▷");
                	else
                        	fprintf(out, "▶");
            	break;
        	case 's':
            		if (ant->color == 0)
                	        fprintf(out, "▽");
                else
                        	fprintf(out, "▼");
            	break;
        	case 'w':
            		if (ant->color == 0)
                        	fprintf(out, "◁");
                	else
                        	fprintf(out, "◀");
           	 break;
    		}
	// na danym polu jest naraz kilka mrowek tego samego koloru
	} else {
		fprintf(out, "x");	
	}
}
