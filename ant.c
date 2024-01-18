#include "board.h" 
#include <time.h>


void moveAnt2 (Board *B,int numer) {
        int i = B->antsx[numer];
        int j = B->antsy[numer];


        if(B->array[i][j].color==0){
            switch (B->array[i][j].direction){
                case 0:
                    B->array[i][j].direction=2;
                break;
                case 1:
                    B->array[i][j].direction=3;
                break;
                case 2:
                    B->array[i][j].direction=1;
                break;
                case 3:
                    B->array[i][j].direction=0;
                break;
            }
        }
        else{
            switch (B->array[i][j].direction){
            case 0:
                B->array[i][j].direction=3;
            break;
            case 1:
                B->array[i][j].direction=2;
            break;
            case 2:
                B->array[i][j].direction=0;
            break;
            case 3:
                B->array[i][j].direction=1;
            break;
            }          
        }


        if (B->array[i][j].color== 0)
            B->array[i][j].color=1;
        else
            B->array[i][j].color=0;



        if (B->array[i][j].direction== 0){
            if (i==0){
                if(B->array[B->rows-1][j].ant== 0){
                    B->array[B->rows-1][j]=moveAnt(B->array[B->rows-1][j],B->array[i][j]);
                    reset(&B->array[i][j]);
                }
                else{
                    if(B->array[B->rows-1][j].team!=B->array[i][j].team){
                        B->array[B->rows-1][j] = AntWar(B->array[B->rows-1][j],B->array[i][j]);
                        reset(&B->array[i][j]);
                    }
                    else{
                        B->array[B->rows-1][j]=moveAnt(B->array[B->rows-1][j],B->array[i][j]);
                        reset(&B->array[i][j]);
                    }
                }
                B->antsx[numer]=B->rows-1;
            }
            else{
                if(B->array[i-1][j].ant== 0){
                    B->array[i-1][j]=moveAnt(B->array[i-1][j],B->array[i][j]);
                    reset(&B->array[i][j]);
                }
                else{
                    if(B->array[i-1][j].team!=B->array[i][j].team){
                        B->array[i-1][j] = AntWar(B->array[i-1][j],B->array[i][j]);
                        reset(&B->array[i][j]);
                    }
                    else{
                        B->array[i-1][j]=moveAnt(B->array[i-1][j],B->array[i][j]);
                        reset(&B->array[i][j]);
                    }
                }
                B->antsx[numer]=i-1;
            }

        }









        if (B->array[i][j].direction== 1){
            if(i==B->rows-1){
                if(B->array[0][j].ant== 0){
                    B->array[0][j]=moveAnt(B->array[0][j],B->array[i][j]);
                    reset(&B->array[i][j]);
                }
                else{
                    if(B->array[0][j].team!=B->array[i][j].team){
                        B->array[0][j] = AntWar(B->array[0][j],B->array[i][j]);
                        reset(&B->array[i][j]);
                    }
                    else{
                        B->array[0][j]=moveAnt(B->array[0][j],B->array[i][j]);
                        reset(&B->array[i][j]);
                    }
                }
                B->antsx[numer]=0;  
            }
            else{
                if(B->array[i+1][j].ant== 0){
                    B->array[i+1][j]=moveAnt(B->array[i+1][j],B->array[i][j]);
                    reset(&B->array[i][j]);
                }
                else{
                    if(B->array[i+1][j].team!=B->array[i][j].team){
                        B->array[i+1][j] = AntWar(B->array[i+1][j],B->array[i][j]);
                        reset(&B->array[i][j]);
                    }
                    else{
                        B->array[i+1][j]=moveAnt(B->array[i+1][j],B->array[i][j]);
                        reset(&B->array[i][j]);
                    }
                }
                B->antsx[numer]=i+1;                   
            }
        }









        if (B->array[i][j].direction== 2){
            if(j==B->cols-1){
                if(B->array[i][0].ant== 0){
                    B->array[i][0]=moveAnt(B->array[i][0],B->array[i][j]);
                    reset(&B->array[i][j]);
                }
                else{
                    if(B->array[i][0].team!=B->array[i][j].team){
                        B->array[i][0] = AntWar(B->array[i][0],B->array[i][j]);
                        reset(&B->array[i][j]);
                    }
                    else{
                        B->array[i][0]=moveAnt(B->array[i][0],B->array[i][j]);
                        reset(&B->array[i][j]);
                    }
                }
                B->antsy[numer]=0;  
            }
            else{
                if(B->array[i][j+1].ant== 0){
                    B->array[i][j+1]=moveAnt(B->array[i][j+1],B->array[i][j]);
                    reset(&B->array[i][j]);
                }
                else{
                    if(B->array[i][j+1].team!=B->array[i][j].team){
                        B->array[i][j+1] = AntWar(B->array[i][j+1],B->array[i][j]);
                        reset(&B->array[i][j]);
                    }
                    else{
                        B->array[i][j+1]=moveAnt(B->array[i][j+1],B->array[i][j]);
                        reset(&B->array[i][j]);
                    }
                }
                B->antsy[numer]=j+1;                    
            }
        }







        if (B->array[i][j].direction== 3){
            if(j==0){
                if(B->array[i][B->cols-1].ant== 0){
                    B->array[i][B->cols-1]=moveAnt(B->array[i][B->cols-1],B->array[i][j]);
                    reset(&B->array[i][j]);
                }
                else{
                    if(B->array[i][B->cols-1].team!=B->array[i][j].team){
                        B->array[i][B->cols-1] = AntWar(B->array[i][B->cols-1],B->array[i][j]);
                        reset(&B->array[i][j]);
                    }
                    else{
                        B->array[i][B->cols-1]=moveAnt(B->array[i][B->cols-1],B->array[i][j]);
                        reset(&B->array[i][j]);
                    }
                }
                B->antsy[numer]=B->cols-1;   
            }
            else{
                if(B->array[i][j-1].ant== 0){
                    B->array[i][j-1]=moveAnt(B->array[i][j-1],B->array[i][j]);
                    reset(&B->array[i][j]);
                }
                else{
                    if(B->array[i][j-1].team!=B->array[i][j].team){
                        B->array[i][j-1] = AntWar(B->array[i][j-1],B->array[i][j]);
                        reset(&B->array[i][j]);
                    }
                    else{
                        B->array[i][j-1]=moveAnt(B->array[i][j-1],B->array[i][j]);
                        reset(&B->array[i][j]);
                    }
                }
                B->antsy[numer]=j-1;                    
            }
        }

}

void printAnt (Board *B, int i, int j, FILE *out) {


	//na danym polu jest tylko jedna mrówka
	if (B->array[i][j].ant >= 1) {
        if (out==stdout){
            if (B->array[i][j].team==0)
                printf("\033[31m");
            if (B->array[i][j].team==1)
                printf("\033[32m");
            if (B->array[i][j].team==2)
                printf("\033[33m");
        }

		if(B->array[i][j].direction==0) {
            if(B->array[i][j].ant == 1){
			        if (B->array[i][j].color == 0)
            			    fprintf(out, " △");
			        else 
				            fprintf(out, " ▲");
            }
            else{
 			        if (B->array[i][j].color == 0)
            			    fprintf(out, "△△");
			        else 
				            fprintf(out, "▲▲");               
            }
        }

		if(B->array[i][j].direction==1) {
            if(B->array[i][j].ant == 1){
            		if (B->array[i][j].color == 0)
                	        fprintf(out, " ▽");
                    else
                        	fprintf(out, " ▼");
            }
            else{
            		if (B->array[i][j].color == 0)
                	        fprintf(out, "▽▽");
                    else
                        	fprintf(out, "▼▼");
            }
        }
		if(B->array[i][j].direction==2) {
            if(B->array[i][j].ant == 1){
			        if (B->array[i][j].color == 0)
                        	fprintf(out, " ▷");
                	else
                        	fprintf(out, " ▶");
            }
            else{
                	if (B->array[i][j].color == 0)
                        	fprintf(out, "▷▷");
                	else
                        	fprintf(out, "▶▶");

            }
        }
		if(B->array[i][j].direction==3) {
            if(B->array[i][j].ant == 1){
            		if (B->array[i][j].color == 0)
                        	fprintf(out, " ◁");
                	else
                        	fprintf(out, " ◀");
            }
            else{
             		if (B->array[i][j].color == 0)
                        	fprintf(out, "◁◁");
                	else
                        	fprintf(out, "◀◀");               
            }
    	}
        if (out==stdout)
            printf("\033[m");
	// na danym polu jest naraz kilka mrowek tego samego koloru
	} 
    
}
Ant AntWar(Ant A1, Ant A2){
    if (A1.ant>A2.ant){
        A1.color=A1.color;
        return A1;
    }
    if (A1.ant<A2.ant){
        A2.color = A1.color;
        return A2;
    }
        
    else{
        if(A1.team==0 && A2.team==1){
            A1.color=A2.color;
            return A1;
        }
        if(A2.team==0 && A1.team==1){
            A2.color=A1.color;
            return A2;
        }
        if(A1.team==0 && A2.team==2){
            A2.color = A1.color;
            return A2;
        }
        if(A2.team==0 && A1.team==2){
            A1.color=A2.color;
            return A1;
        }  
        if(A1.team==1 && A2.team==2){
            A1.color = A2.color;
            return A1;
        }            
        if(A2.team==1 && A1.team==2){
            A2.color = A1.color;
            return A2;
        }
            
    }


}

void reset(Ant *A){
    A->ant=0;
    A->direction=0;
    A->team=0;
}

Ant moveAnt(Ant A1, Ant A2){
    Ant A3;
    A3.ant = A2.ant + A1.ant;
    A3.color = A1.color;
    A3.direction = A2.direction;
    A3.team = A2.team;
    return A3;
}

void MakeRandomAnt(Board *B,int i){
    B->antsx=malloc(B->num_of_ants * sizeof(int));
    B->antsy=malloc(B->num_of_ants * sizeof(int));
    for(int i=0; i<B->num_of_ants;i++){
        int x=rand() % B->rows;
        int y=rand() % B->cols;
        B->array[x][y].ant=1;
        B->array[x][y].direction=rand() % 4;
        B->array[x][y].team=rand() % 3;
        B->antsx[i]=x;
        B->antsy[i]=y; 
    }  
}