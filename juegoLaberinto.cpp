#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>

#define ARRIBA 72	//PARA HACER EL JUEGO MAS AMIGABLE CON EL USUARIO
#define IZQUIERDA 75 //VAMOS A UTIILIZAR LAS FLECHAS DEL TECLADO USANDO CODIGO
#define DERECHA 77	//ASCII
#define ABAJO 80

int Mounstruo=2;
int Jugador=1;
int Obstaculo=3;
int Meta=5;

int Fila=0;
int JUEGO[30][30];
int Columna=0;
//////IDENTIFICADORES
//  1 JUGADO0R
//  3 OBSTACULO
//  2 MOUNSTRUO
//  5 META
void presenta();
void llenaObstaculos(int n_o);
void asignarPosicion(int turno);
bool juegaPartida(int );
bool mueveMounstruo();
int main(){
	int C,F;//COLUMNAS Y FILAS
	do{
		printf("\nColumnas(3-30): ");
		scanf("%d",&C);
	}while(C>30 || C<3);	//No sea mayor de 100  O MENOR A 3
	do{
		printf("\nFilas(3-30): ");
		scanf("%d",&F);
	}while(F>30 || F<3);	//No sea mayor de 100
	 Fila=F;
	 Columna=C;
	
	
		for(int i=0;i<F;i++){       
			for(int j=0;j<C;j++){
				JUEGO[i][j]=0;    //Se encera el arreglo
			}
		}
		
	int n_obst;
	do{
		printf("\nNumero de obstaculos: ");
		scanf("%d",&n_obst);
	}while(n_obst <0 || n_obst >=F*C);
	
	
	
	

	printf("\n\tPosicion jugador\n ");
	asignarPosicion(Jugador);

	
		printf("\n\tPosicion Meta\n ");
	asignarPosicion(Meta);
	
	
	
		printf("\n\tPosicion Mounstruo\n ");
	asignarPosicion(Mounstruo);
	
	
	llenaObstaculos(n_obst);//Se llenan obstaculos aleatoriamente
	
	bool gameOver=false;
	presenta();
	do{
				
		gameOver=juegaPartida(n_obst);
	//	getch();
		
		
	}while(!gameOver);
	int n;
	scanf("%d",&n);
	printf("\n\n");
		presenta();
	//system("cls");
}


bool juegaPartida(int n_obst){

	
	int ColJ,FilJ;
	bool parar=false;
	for(FilJ=0;FilJ<Fila;FilJ++   )
	{
		for(ColJ =0;ColJ< Columna;ColJ++){
			if(JUEGO[FilJ][ColJ]==1)
			{
				parar=true;
				break; 
			}			
		}
		if(parar)
			break;
	}
//	printf("%d  %d" ,FilJ , ColJ);
	if(kbhit()){// CAPTURA LA TECLA PRESIONADA
		char tecla=getch();
			if(tecla==IZQUIERDA ){	
				if( ColJ ==0)
					printf("\nMala jugada\n");
					else
					{
						if(JUEGO[FilJ][ColJ-1]!=Obstaculo){
							if(  JUEGO[FilJ][ColJ-1]==Meta ){
								printf("GANASTE :v");
								return true;
							}
							else{
								 if( JUEGO[FilJ][ColJ-1]==Mounstruo) {
								 	printf("Perdiste we, que sad :'v");
									return true;								 	
								 }
							}
							JUEGO[FilJ][ColJ]=0;
							JUEGO[FilJ][ColJ-1]=1;
						}
						
					}
					llenaObstaculos(n_obst);
			return	mueveMounstruo();
				
			}
			if(tecla==DERECHA ){
				if( ColJ ==Columna-1)
					printf("\nMala jugada\n");
				else
				{
					if(JUEGO[FilJ][ColJ+1]!=Obstaculo){
						if(  JUEGO[FilJ][ColJ+1]==Meta ){
								printf("GANASTE :v");
								return true;
							}else{
								if( JUEGO[FilJ][ColJ+1]==Mounstruo) {
								 	printf("Perdiste we, que sad :'v");
									return true;								 	
								 }
							}
						JUEGO[FilJ][ColJ]=0;
						JUEGO[FilJ][ColJ+1]=1;	
					}else{
							printf("\nMala jugada\n");
						}			
				}
				llenaObstaculos(n_obst);
							
				return mueveMounstruo();
			}
			
			if(tecla==ARRIBA ){
				if( FilJ ==0)
					printf("\nMala jugada\n");
				else
				{
					if(JUEGO[FilJ-1][ColJ]!=Obstaculo){
						if(  JUEGO[FilJ-1][ColJ]==Meta ){
								printf("GANASTE :v");
								return true;
							}else{
								if( JUEGO[FilJ-1][ColJ]==Mounstruo) {
								 	printf("Perdiste we, que sad :'v");
									return true;								 	
								 }
							}
						JUEGO[FilJ][ColJ]=0;
						JUEGO[FilJ-1][ColJ]=1;
					}else
						printf("\nMala jugada\n");
				}
			llenaObstaculos(n_obst);
			return	mueveMounstruo();
			}
			if(tecla==ABAJO ){
				if( FilJ ==Fila-1)
					printf("\nMala jugada\n");
				else
				{
					if(JUEGO[FilJ+1][ColJ]!=Obstaculo){
						
						if(  JUEGO[FilJ+1][ColJ]==Meta ){
								printf("GANASTE :v");
								return true;
							}else{
								if( JUEGO[FilJ+1][ColJ]==Mounstruo) {
								 	printf("Perdiste we, que sad :'v");
									return true;								 	
								 }
							}
						
						JUEGO[FilJ][ColJ]=0;
						JUEGO[FilJ+1][ColJ]=1;
					}else
						printf("\nMala jugada\n");
					
				}
			llenaObstaculos(n_obst);
				
			return	mueveMounstruo();
			}
			system("cls");
				presenta();	
			 
	}
	
	
	Sleep(100);
	return false;
}
void presenta(){
		for(int i=0;i<Columna;i++){       
			for(int j=0;j<Fila;j++){
				if(JUEGO[i][j]!=0  )
					if(JUEGO[i][j]==5)
						printf("| V");
						else
							if(  JUEGO[i][j]==1 )
								printf("| J");
									else
										if(JUEGO[i][j]==2)
											printf("| M");
											else
											printf("| *");			
				else
					printf("|  ");
			}
			printf("\n");
		}
		printf("\n");
	
}

void llenaObstaculos(int n_o){
	for(int i=0;i<Fila;i++){       
			for(int j=0;j<Columna;j++){
				if( JUEGO[i][j]==Obstaculo )
					JUEGO[i][j]=0;    //Se encera el arreglo
			}
		}
	
	srand(time(NULL));
	for(int i=0;i<n_o;i++){    
	int F= 0+rand()%(Fila+0); 
	int C= 0+rand()%(Columna+0); 			
				if(JUEGO[F][C]==0  )
					JUEGO[F][C]=Obstaculo;
				else
					i--;
	}
	
	
	
}


void asignarPosicion(int turno){
		int posicionJF,  posicionJC;
	
	do{
	
		printf("\n\tIngrese posiciones\n ");
		do{
			printf("\nFila: ");
			scanf("%d",&posicionJF);
			posicionJF=posicionJF-1;
		}while(posicionJF<0 || posicionJF>=Fila );
		do{
			printf("\nColumna: ");
			scanf("%d",&posicionJC);
			posicionJC=posicionJC-1;
		}while(posicionJC<0 || posicionJC>=Columna );
		
		if( JUEGO[posicionJF][posicionJF]!=0)
			printf("\n\tPosuicion ya ha sido asignada anteriormente\n\n");
	}while(JUEGO[posicionJC][posicionJF]!=0);
	
	JUEGO[posicionJC][posicionJF]=turno;
}

bool mueveMounstruo(){
	int ColJ,FilJ;
	bool gameOver=false;
	bool parar=false;
	for(FilJ=0;FilJ<Fila;FilJ++   )
	{
		for(ColJ =0;ColJ< Columna;ColJ++){
			if(JUEGO[FilJ][ColJ]==Jugador)
			{
				parar=true;
				break; 
			}			
		}
		if(parar)
			break;
	}
	int ColM,FilM;
	parar=false;
	for(FilM=0;FilM<Fila;FilM++   )
	{
		for(ColM =0;ColM< Columna;ColM++){
			if(JUEGO[FilM][ColM]== Mounstruo)
			{
				parar=true;
				break; 
			}			
		}
		if(parar)
			break;
	}
	
	if( FilM > FilJ){//si la posicion del jugador (FILA ) es menor a la posicion actual del mounstruo (Fila)
		
		if(  ColM > ColJ)//si la posicion del jugador (Columna ) es mayor a la posicion actual del mounstruo (Columna)
		{
			if( JUEGO[FilM][ColM-1]!=Obstaculo && JUEGO[FilM][ColM-1]!=Meta)
				{
					
					if(JUEGO[FilM][ColM-1] ==1){
						gameOver=true;
						printf("\nPerdiste we, que sad :'v ");
					}	
					JUEGO[FilM][ColM]=0;
					JUEGO[FilM][ColM-1]=Mounstruo;
				}
		}else{
			if(  ColM < ColJ)//si la posicion del jugador (Columna ) es igual a la posicion actual del mounstruo (Columna)
			{
				if( JUEGO[FilM][ColM+1]!=Obstaculo && JUEGO[FilM][ColM+1]!=Meta)
				{
					if(JUEGO[FilM][ColM+1] ==1){
						gameOver=true;
						printf("\nPerdiste we, que sad :'v ");
					}
					JUEGO[FilM][ColM]=0;
					JUEGO[FilM][ColM+1]=Mounstruo;
				}
			}else{
				if( JUEGO[FilM-1][ColM]!=Obstaculo && JUEGO[FilM][ColM+1]!=Meta)
				{
					if(JUEGO[FilM-1][ColM] ==1){
						gameOver=true;
						printf("\nPerdiste we, que sad :'v ");
					}
					JUEGO[FilM][ColM]=0;
					JUEGO[FilM-1][ColM]=Mounstruo;
				}else{
					
				}
			}
		}
	}else{
		if( FilM < FilJ){//si la posicion del jugador (FILA ) es mayor a la posicion actual del mounstruo (Fila)
		
		if( JUEGO[FilM][ColM+1]!=Obstaculo && JUEGO[FilM][ColM+1]!=Meta)
				{
					
					if(JUEGO[FilM][ColM+1] ==1){
						gameOver=true;
						printf("\nPerdiste we, que sad :'v ");
					}	
					JUEGO[FilM][ColM]=0;
					JUEGO[FilM][ColM+1]=Mounstruo;
				}
		
		}else{//si la posicion del jugador (FILA ) es igual a la posicion actual del mounstruo (Fila)
			if(  ColM > ColJ)//si la posicion del jugador (Columna ) es mayor a la posicion actual del mounstruo (Columna)
		{
			if( JUEGO[FilM][ColM-1]!=Obstaculo && JUEGO[FilM][ColM-1]!=Meta)
				{
					if(JUEGO[FilM][ColM-1] ==1){
						gameOver=true;
						printf("\nPerdiste we, que sad :'v ");
					}
					JUEGO[FilM][ColM]=0;
					JUEGO[FilM][ColM-1]=Mounstruo;
				}
		}else{
			if(  ColM < ColJ)//si la posicion del jugador (Columna ) es igual a la posicion actual del mounstruo (Columna)
			{
				if( JUEGO[FilM][ColM+1]!=Obstaculo && JUEGO[FilM][ColM+1]!=Meta)
				{
					if(JUEGO[FilM][ColM+1] ==1){
						gameOver=true;
						printf("\nPerdiste we, que sad :'v ");
					}
					JUEGO[FilM][ColM]=0;
					JUEGO[FilM][ColM+1]=Mounstruo;
				}
			}else{
				if( JUEGO[FilM+1][ColM]!=Obstaculo &&JUEGO[FilM+1][ColM]!=Meta )
				{
					if(JUEGO[FilM+1][ColM] ==1 ){
						gameOver=true;
						printf("\nPerdiste we, que sad :'v ");
					}
					JUEGO[FilM][ColM]=0;
					JUEGO[FilM+1][ColM]=Mounstruo;
				}else{
					
				}
			}
			
		}
	}
	}
	return gameOver;
}

