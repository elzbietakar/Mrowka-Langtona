#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <time.h>

#include "board.h"
#include "read_write.h"



int main (int argc, char **argv) {
	clock_t start_time = clock();
	setlocale(LC_ALL, "C.UTF-8");
	srand(time(NULL));
	int aflag = 0;
	int bflag = 0;

	char *bvalue = NULL;
	int avalue = 0;
	int index;
	int c;
	int m;
	int n;
	int liczba_mrowek;
	int iteracje;
	char *name;
	Board BOARD;
	char file_name [64];


	opterr = 0;


	while ((c = getopt (argc, argv, "a:b:")) != -1)  
		switch (c)
		{
		case 'a':
			aflag = 1;
			avalue = atoi(optarg);
			break;
		case 'b':
			if(aflag==0){
				bflag = 1;
				bvalue = optarg;
			}
			else{ 
				fprintf (stderr, "Nie mozna wykonac opcji -a i -b jednoczesnie.\n");
				return 1;
			}
			break;
		case '?':
			if (optopt == 'a'||optopt == 'b')
			fprintf (stderr, "opcja -%c wymaga dodatkowego argumentu.\n", optopt);
			else 
			fprintf (stderr, "Nieznana opcja `-%c'.\n", optopt);
			return 1;
		default:
			abort ();
		}


	index = optind;
		if(bflag==0){
			m= argc > index ? atoi(argv[index]): 20;
			index++;
			n= argc > index ? atoi(argv[index]): 20;
			index++;
			liczba_mrowek=argc > index ? atoi(argv[index]): 3;
			index++;
		}
		iteracje=argc > index ? atoi(argv[index]): 20;
		index++;
		name = argc > index ? argv[index]: NULL;
		index++;

	FILE *in= fopen( bvalue, "r" );
	FILE *out=stdout;


	if(bflag==0){
		BOARD = initBoard(m,n);
		BOARD.num_of_ants=liczba_mrowek;
		MakeRandomAnt(&BOARD,liczba_mrowek);
	}
	else{
		BOARD = readFromFile(in);
	}



	if(aflag==1)
	MakeBlackSpots(&BOARD,avalue);
	if(name!=NULL){
		sprintf(file_name, "./wyniki_graficznie/%s.txt", name);
		out = fopen(file_name, "w");
	}
	printBoard(&BOARD, out);
    for(int i=0;i<iteracje;i++){    
        for(int j=0;j<BOARD.num_of_ants;j++){
            moveAnt2(&BOARD,j);   
        }
		if(name!=NULL){
		sprintf(file_name, "./wyniki/%s_%i.txt", name, i+1);
		out = fopen(file_name, "w");
		writeToFile(out,&BOARD);
		sprintf(file_name, "./wyniki_graficznie/%s_%i.txt", name, i+1);
		out = fopen(file_name, "w");		
		}
        printBoard(&BOARD, out);

		

    }
	clock_t end_time = clock();
	double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
	printf("Execution time: %f seconds\n", elapsed_time);

return 0;
}