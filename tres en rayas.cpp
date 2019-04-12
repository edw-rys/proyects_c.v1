#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<conio.h>
int tresEnRayas[3][3];
bool termina=false;

void juegaMaquina(int,int);
bool compararGana(int jugador_maquina) ;
void estrategia(int marca);
int posibilidadDeGanarHorizontal(int turno_ataca, int turno_defiende);
int posibilidadDeGanarVertica(int turno_ataca, int turno_defiende);
bool empiezaMaquina(int turno);
bool empiezaMaquinaEstrategia_2(int turno);
bool estrategiaEsquinas(int turno);

int posibilidadDeGanarDiagonales(int turno_ataca, int turno_defiende){
	int diagonal_der=0,diagonal_izq=0;
	/*
	 x| |x  d| |   | |i 
	  |x|	d| |   | |i
	 x| |x  d| |   | |i 
	*/
	int Tipo_diagonal=0;//10 derecha , 20 izquierda, 0 ninguna

	bool probabilidad_der=false, probabilidad_izq=false;
	
	if(tresEnRayas[0][0] !=0 && tresEnRayas[1][1] !=0 && tresEnRayas[2][2] !=0){
		probabilidad_der=true;
	}		
	
		if(tresEnRayas[0][2] !=0 && tresEnRayas[1][1] !=0 && tresEnRayas[2][0] !=0)
		probabilidad_izq=true;
		
	
		

		
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			
			if((i%2==0 && j %2==0) || (j== 1 && i==1)){
				
				if(tresEnRayas[i][j]==turno_ataca && tresEnRayas[i][j]!=turno_defiende )
				if(j== 1 && i==1)
					{
					if(!probabilidad_der)
						diagonal_der++;
						if(!probabilidad_izq)
						diagonal_izq++;
					}else{
						if(j== 0 && i==0){
						if(!probabilidad_der)
							diagonal_der++;
						}else{
							if(i== 0 && j==2){
								if(!probabilidad_izq)
								diagonal_izq++;				
							}
										
						}
						
						if(i==2 && j==0){
							if(!probabilidad_izq)
							diagonal_izq++;
						}
							
							else
							if(i==2 && j==2){
							if(!probabilidad_der)				
									diagonal_der++;	
							}
							
					}
				
			}
		}
	}
	
	if(diagonal_der==2){
		Tipo_diagonal=10;
	}else{
		if(diagonal_izq==2){
		Tipo_diagonal=20;
	}
	}
	
	
	
	
//	printf("*  %d *",Tipo_diagonal);
	return Tipo_diagonal;
}

/*
   x| | x
    | | 
   x| | x 
*/

bool DefensaEsquinas(int turnoAtaca, int turnoDefiende){
	int i=2,j=0;
	int direccion=0;
	if(tresEnRayas[0][0] ==turnoAtaca && tresEnRayas[2][2]!= turnoAtaca)	
	{
		if( tresEnRayas[0][2] == 0){
			tresEnRayas[0][2] =2;
			return true;
		}else
		{
				if( tresEnRayas[2][0] == 0){
					tresEnRayas[2][0] =2;
					return true;
				}
		}
	}else{
		if(tresEnRayas[0][2] ==turnoAtaca && tresEnRayas[2][0]!= turnoAtaca)	{
			if( tresEnRayas[0][0] == 0){
			tresEnRayas[0][0] =2;
			return true;
		}else
		{
				if( tresEnRayas[2][2] == 0){
					tresEnRayas[2][2] =2;
					return true;
				}
				else return false;
		}
		}
	}
	return false;
}


int turnoJugador(){
		int marca;
		bool mal=false;
		
	int cont=0;
	do{
		mal=false;
		cont=0;
		do{
			printf("\nIndique numero:");
			scanf("%d",&marca);
		}	while(marca>9 || marca<1);
	
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cont ++;
			if(cont ==marca)
			{
				if(tresEnRayas[i][j]!=0)
				mal=true;
				else{
					tresEnRayas[i][j]=1;
					mal=false;
				}
				
				break;
			}
		}
	}
	if(mal)
	printf(" Mala jugada");
	}while(mal);
	
	return marca;
}


////PRINCIPAL
int main()
{
	int i,j;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	tresEnRayas[i][j]=0;
	 srand(time(NULL));
	int turno= 1+rand()%(3-1);
		
	int marca=0, ganador_pres=0; //si ganador es  0 nadiwe ha ganado, si es 1 gano jugador si es 2 gano maquina
	
	printf("Posiciones\n  1  |   2   |   3\n  4  |	 5   |   6\n  7  |   8   |   9\n");
	
	system("pause");
int n=0;
	while(!termina){
	n++;
	
	if(turno==1){
	//jugador turno
	
	marca=turnoJugador();
	termina=compararGana(1);
	if(termina){
		ganador_pres=1;
	}
	
	turno=2;
	}
		else
	if(turno==2){

		int fila=0, columna=0;
		//Primero verificar si hay posibilidad para ganar 
		fila=posibilidadDeGanarHorizontal(2,1);
		columna=posibilidadDeGanarVertica(2,1);
		
		int diagonal =posibilidadDeGanarDiagonales(2,1);//10 derecha , 20 izquierda, 0 ninguna
		if(diagonal==0 ){
		
		//si  no hay 
		if(fila>50&& columna >50){
			fila=posibilidadDeGanarHorizontal(1,2);
		columna=posibilidadDeGanarVertica(1,2);
		
		diagonal =posibilidadDeGanarDiagonales(1,2);//10 derecha , 20 izquierda, 0 ninguna
	
			
		/*
		*/	
		
		///Verificar si el oponente tiene oportunidad
				//si me bolta una fila y columna akta no tiene posibilidad
				
				if(diagonal ==0 ){
				
				if(fila>50&& columna >50){
					juegaMaquina(marca, n); //////////////////////////////////////JUGAR MAQUINA SI EL JUEGO ESTA ABIERTO ( ,turno)
				}
				//me botara un num en fila  o culumna si el oponente va a ganar para tapartle la salida
				
				else{
					//printf(" *%d*  %d ",fila , columna);
					if(fila>50){
					for(i=0;i<3;i++){
						if(tresEnRayas[i][columna]== 0){
							tresEnRayas[i][columna]= 2;
							break;
						}
					}
			}else
			{
				if(columna>50){
						for(i=0;i<3;i++){
						if(tresEnRayas[fila][i]== 0){
							tresEnRayas[fila][i]= 2;
							break;
						}
					}
				}
				else{
					for(i=0;i<3;i++){
						if(tresEnRayas[fila][i]== 0){
							tresEnRayas[fila][i]= 2;
							break;
						}
				}
			}
			}
				}
				
			
				
			}///DIagonal falso
			else
	{
		//printf("%d",diagonal);
		if(diagonal==10){//10 derecha , 20 izquierda
		for(i=0;i<3;i++){
				if(tresEnRayas[i][i]==0){
					tresEnRayas[i][i]=2;
					break;
				}
				
		}
		
		}else{
			if(diagonal==20){
				j=2;
			for(i=0;i<3;i++){
				if(tresEnRayas[i][j]==0){
					tresEnRayas[i][j]=2;
					break;
				}
				j--;
				
		}
			}
		}
		
	}
		}
	
		else{
			
			if(fila==100){
					for(i=0;i<3;i++){
						if(tresEnRayas[i][columna]== 0){
							tresEnRayas[i][columna]= 2;
							break;
						}
					}
			}else
			{
				if(columna==100){
						for(i=0;i<3;i++){
						if(tresEnRayas[fila][i]== 0){
							tresEnRayas[fila][i]= 2;
							break;
						}
					}
				}else{
					for(i=0;i<3;i++){
						if(tresEnRayas[fila][i]== 0){
							tresEnRayas[fila][i]= 2;
							break;
						}
				}
			}
			}
		}
		
	}else
	{
		//printf("%d",diagonal);
		if(diagonal==10){//10 derecha , 20 izquierda
		for(i=0;i<3;i++){
				if(tresEnRayas[i][i]==0){
					tresEnRayas[i][i]=2;
					break;
				}
				
		}
		
		}else{
			if(diagonal==20){
				j=2;
			for(i=0;i<3;i++){
				if(tresEnRayas[i][j]==0){
					tresEnRayas[i][j]=2;
					break;
				}
				j--;
				
		}
			}
		}
		
	}
			termina=compararGana(2);
			turno=1;
			if(termina)
			ganador_pres=2;
			
			//printf("dadnand");
	}
	
	
	system("cls");
		printf("Posiciones\n  1  |   2   |   3\n  4  |	 5   |   6\n  7  |   8   |   9\n");

		printf("Turno %d\n",n);
	for(i=0;i<3;i++)	{
	
		for(j=0;j<3;j++)
	{
			printf("|");
		if(tresEnRayas[i][j]==1)
		printf(" x ");
		else
		if(tresEnRayas[i][j]==2)
		printf(" 0 ");
		else
		printf("   ");
	//	printf("|");
	}
	printf("\n");
	}
	if(ganador_pres!=0){
		if(ganador_pres==1)
		printf("\n* Ganador Jugador");
		else
		if(ganador_pres==2)
			printf("\nGanador Maquina");
	}

	
	
	if(n==9 && !termina) {
			printf("\nEmpate ");
			break;
	}
	
	}
	getch();
}
	
	int Estrategia_definida=0;
	

void juegaMaquina(int jugador_marca,int turno){

	bool hacerMovimiento;
	if(Estrategia_definida==0){
		srand(time(NULL));
	
	 	Estrategia_definida=1+rand()%(4-1);		
	}
	

	if(Estrategia_definida==1)
	hacerMovimiento=empiezaMaquinaEstrategia_2(turno);
	else{
		if(Estrategia_definida==2){
		hacerMovimiento=	estrategiaEsquinas(turno);
		}else{
			hacerMovimiento=empiezaMaquina(turno);
		}
	}
	 
	

	if(hacerMovimiento){
	printf("\nmarca Maquina\n");
	}else{		
	if(jugador_marca==0)
	{
		int jugada= 1+rand()%(5-1);
		switch(jugada){
			case 1:{
				tresEnRayas[0][0]==2;
				break;
			}
			case 2:{
				tresEnRayas[0][2]==2;
				break;
			}
			case 3:{
				tresEnRayas[1][1]==2;
				break;
			}
			case 4:{
				tresEnRayas[2][0]==2;
				break;
			}
			case 5:{
				tresEnRayas[2][2]==2;
				break;
			}
		}
		
	}else{
		estrategia(jugador_marca);
		
	}
}
	
	
	

}
		
bool compararGana(int jugador_maquina) {
	//

		bool term=false;
	int cont=0;
	for(int i=0;i<3;i++)
	{
		cont=0;
		
		for(int j=0;j<3;j++){
			
			if( tresEnRayas[i][j] ==0){
			//	term=false;
				break;
			}		
			else{
					if(  tresEnRayas[i][j]==jugador_maquina)
				cont++;
			}
			if(cont==3){
				
				printf("Ganador ");
				term=true;
				break;
			}	
			}
						
		}
		
		
			for(int i=0;i<3;i++)
	{
		cont=0;
		
		for(int j=0;j<3;j++){
			
			if( tresEnRayas[j][i] ==0){
				
				break;
			}		
			else{
				if(  tresEnRayas[j][i]==jugador_maquina)
				cont++;
			}
			if(cont==3){
				term=true;
				break;
			}	
				
			}
					
		}
	
		if(tresEnRayas[0][0] ==jugador_maquina && tresEnRayas[1][1] ==jugador_maquina && tresEnRayas[2][2] ==jugador_maquina)
		term=true;
		else
		if(tresEnRayas[0][2] ==jugador_maquina && tresEnRayas[1][1] ==jugador_maquina && tresEnRayas[2][0] ==jugador_maquina)
		term=true;
		
		return term;//si termina es verdad si no es falso
	
}


void estrategia(int marca){
		
		
		/*
			0|0|0
			0|1|0
			0|0|0
		*/
		
		//usuario marca enmedio
	if(marca==5){

	for(int i=0;i<9;i+=2){
		if(i!=4){
		
			if(i== 2 || i==0)
			{
				if(	tresEnRayas[0][i]==0){
					tresEnRayas[0][i] =2;	
					break;
				}
						
			}else{
				if(i== 8 || i==6)	
				if(	tresEnRayas[2][i]==0){
					tresEnRayas[2][i] =2;	
					break;
				}		
										
			}
		}
	}
	
		
}
else
	{//lados laterales

	if(marca%2==0){
		/*
			0|1|0
			1|0|1
			0|1|0
		*/
		if(marca== 2 )
		{
			
					if(tresEnRayas[1][1]== 0  )
					 tresEnRayas[1][1] =2;
					 else
			if(tresEnRayas[2][1] ==0){
				tresEnRayas[2][1] =2;				
			}
			else
			if(tresEnRayas[0][0]== 0 )
				tresEnRayas[0][0] =2;	
				else
					if(tresEnRayas[0][2]== 0 )
					tresEnRayas[0][2] =2;
					
					 else
					if(tresEnRayas[1][2]== 0  )
					 tresEnRayas[1][2] =2;
					 else
					if(tresEnRayas[2][0]== 0  )
					 tresEnRayas[2][0] =2;
					 else
					if(tresEnRayas[2][2]== 0  )
					 tresEnRayas[2][2] =2;
					 else
					 tresEnRayas[1][0] =2;
		}
		else
		if(marca== 4 )
		{
			
			if(tresEnRayas[1][1]== 0  )
					 tresEnRayas[1][1] =2;	
				else
				if(tresEnRayas[1][2] ==0){
				tresEnRayas[1][2] =2;				
			}
			else
			
					if(tresEnRayas[0][2]== 0 )
					tresEnRayas[0][2] =2;
					else
					
						if(tresEnRayas[0][0]== 0 )
						tresEnRayas[0][0] =2;
					 else
					 if(tresEnRayas[2][0]== 0  )
					 tresEnRayas[2][0] =2;					
					 else
					if(tresEnRayas[2][2]== 0  )
					 tresEnRayas[2][2] =2;
					  else
					
					if(tresEnRayas[2][1]== 0  )
					 tresEnRayas[2][1] =2;
					 else
					 tresEnRayas[0][1] =2;
		}
		else
			if(marca== 6 )
		{
			if(tresEnRayas[1][1]== 0  )
					 tresEnRayas[1][1] =2;	
				else
				if(tresEnRayas[1][0] ==0){
				tresEnRayas[1][0] =2;				
			}
			else			
					if(tresEnRayas[0][2]== 0 )
					tresEnRayas[0][2] =2;
					else
					if(tresEnRayas[2][2]== 0  )
					 tresEnRayas[2][2] =2;
						
					 else
					 if(tresEnRayas[2][0]== 0  )
					 tresEnRayas[2][0] =2;					
					 else
					if(tresEnRayas[0][0]== 0 )
						tresEnRayas[0][0] =2;
					  else
					
					if(tresEnRayas[2][1]== 0  )
					 tresEnRayas[2][1] =2;
					 else
					 tresEnRayas[0][1] =2;
		}
		else
			if(marca== 8 )
		{
			if(tresEnRayas[1][1]== 0  )
				 tresEnRayas[1][1] =2;	
			 else
				if(tresEnRayas[0][1] ==0){
					tresEnRayas[0][1] =2;				
				}
				else			
					if(tresEnRayas[2][2]== 0  )
					 tresEnRayas[2][2] =2;
						
					 else
					 if(tresEnRayas[2][0]== 0  )
					 tresEnRayas[2][0] =2;
					 
				else
				
					if(tresEnRayas[0][2]== 0 )
					tresEnRayas[0][2] =2;
										
					 else
					if(tresEnRayas[0][0]== 0 )
						tresEnRayas[0][0] =2;
					  else
					
					if(tresEnRayas[1][2]== 0  )
					 tresEnRayas[1][2] =2;
					 else
					 tresEnRayas[1][0] =2;
		}
	}
	else{
		if(marca%2!=0){
			if(marca==1){
				if(tresEnRayas[1][1]== 0  )
					 tresEnRayas[1][1] =2;	
					else
					if(tresEnRayas[2][2]== 0  )
					 tresEnRayas[2][2] =2;
			else
			if(tresEnRayas[0][1] ==0){
				tresEnRayas[0][1] =2;				
			}else
					
					if(tresEnRayas[1][2]== 0  )
					 tresEnRayas[1][2] =2;
					 
						
					 else
					 if(tresEnRayas[2][0]== 0  )
					 tresEnRayas[2][0] =2;
					 
				else
				
					if(tresEnRayas[0][2]== 0 )
					tresEnRayas[0][2] =2;
										
					 else
					if(tresEnRayas[2][1]== 0 )
						tresEnRayas[2][1] =2;
					  
					 else
					 tresEnRayas[1][0] =2;
				
			}
			
			else{
				if(marca==3 ){
					if(tresEnRayas[1][1]== 0  )
					 tresEnRayas[1][1] =2;	
					else
					 if(tresEnRayas[2][0]== 0  )
					 tresEnRayas[2][0] =2;
					 else
					if(tresEnRayas[2][2]== 0  )
					 tresEnRayas[2][2] =2;	
			else
			if(tresEnRayas[0][1] ==0){
				tresEnRayas[0][1] =2;				
			}else
					
					if(tresEnRayas[1][2]== 0  )
					 tresEnRayas[1][2] =2;
				else				
					if(tresEnRayas[0][0]== 0 )
					tresEnRayas[0][0] =2;
										
					 else
					if(tresEnRayas[2][1]== 0 )
						tresEnRayas[2][1] =2;					  
					 else
					 tresEnRayas[1][0] =2;
				}
		else{
		
					if(marca==7){
						if(tresEnRayas[1][1]== 0  )
					 tresEnRayas[1][1] =2;	
					else
					 if(tresEnRayas[0][2]== 0  )
					 tresEnRayas[0][2] =2;
					 else
					if(tresEnRayas[2][2]== 0  )
					 tresEnRayas[2][2] =2;	
			else
			if(tresEnRayas[0][1] ==0){
				tresEnRayas[0][1] =2;				
			}else
					
					if(tresEnRayas[1][2]== 0  )
					 tresEnRayas[1][2] =2;
				else				
					if(tresEnRayas[0][0]== 0 )
					tresEnRayas[0][0] =2;
										
					 else
					if(tresEnRayas[2][1]== 0 )
						tresEnRayas[2][1] =2;					  
					 else
					 tresEnRayas[1][0] =2;
					}
					else
					{
						
						/////////
						if(marca==9){
								if(tresEnRayas[1][1]== 0  )
					 tresEnRayas[1][1] =2;	
					 	else				
					if(tresEnRayas[0][0]== 0 )
					tresEnRayas[0][0] =2;
					else
					 if(tresEnRayas[0][2]== 0  )
					 tresEnRayas[0][2] =2;	
					 else
					 if(tresEnRayas[1][2]== 0  )
					 tresEnRayas[1][2] =2;	
					 else
					if(tresEnRayas[2][1]== 0 )
						tresEnRayas[2][1] =2;				 
					else
						if(tresEnRayas[0][1] ==0){
						tresEnRayas[0][1] =2;				
					}else
					if( tresEnRayas[2][0] ==0 )
					tresEnRayas[2][0] =2;
					 else
					 tresEnRayas[1][0] =2;
						}
					}
				}
			}
		
		}
	}
}
}

int posibilidadDeGanarVertica(int turno_ataca, int turno_defiende){
	int posicion_v=100,vertical=0; //si es 100 no cumple 
	int lleno=0;
	bool term=false;
	for(int i=0;i<3;i++){
		vertical=0;
		lleno=0;
			for( int j=0;j<3;j++){
				
				if(tresEnRayas[j][i] == turno_ataca &&  tresEnRayas[j][i] != turno_defiende){
					vertical++;
					if(vertical==2){
					
							posicion_v=i;
							term=true;
						
							//break;
					}					
				}
				if(tresEnRayas[j][i] !=0)
				lleno++;
				if(lleno>=3){
				term=false;
				posicion_v=100;
				}
			}
			if(term)
			break;
			
	}	
	return posicion_v;
}

int posibilidadDeGanarHorizontal(int turno_ataca, int turno_defiende){
	int horizontal=0, diagonal_der=0,diagonal_izq=0;
	int posicion_h=100;//si es 100 no cumple 
	
	int lleno=0;
	bool posibilidad=false;
	for(int i=0;i<3;i++){
		horizontal=0;lleno=0;
			for( int j=0;j<3;j++){
				
				if(tresEnRayas[i][j] == turno_ataca &&  tresEnRayas[i][j] != turno_defiende){
					horizontal++;
					if(horizontal==2){
						posibilidad=true;
							posicion_h=i;
						//	break;
					}
					
				}
					if(tresEnRayas[i][j] !=0)
				lleno++;
				if(lleno==3)
				posicion_h=100;
				
			}
			if(posibilidad)
			break;
			
	}
	
	
	
	return posicion_h;

	
}


int primer_paso; int segundo_paso;
bool empiezaMaquina(int turno){ //si retorna true ya agrego un paso , caso contrario no
	
	bool completadoPaso= false;
	
	if(turno==1){
	
	int paso;
	 srand(time(NULL));
	do{
		paso= 1+rand()%(9-1);
	
	}while(paso%2!=0 );
	
	primer_paso=paso;
	
	int recorrer=0;
	for(int i=0;i<3;i++){
		//recorrer++;
		for(int j=0;j<3;j++){
				
				recorrer++;
				if(recorrer==paso){
					tresEnRayas[i][j]=2;
					completadoPaso=true;
					break;
				}
				
		}
	}
	
	}
	else{
		
		if(turno==3){
		
		
		int cumplido=0;
		int movimiento=0;
		if(primer_paso==2 || primer_paso==8){
		
		
				for(int i=0;i<3;i++){
					for(int j=0;j<3;j++){
						movimiento++;
						if(movimiento==4){
							if(tresEnRayas[i][j]==0){
								tresEnRayas[i][j]=2;
								completadoPaso=true;
								segundo_paso=4;
								break;
								
							}
						}else{
							if(movimiento==6){
								if(tresEnRayas[i][j]==0){
									tresEnRayas[i][j]=2;
									completadoPaso=true;
									segundo_paso=6;
									break;
								}
								
							}
						}
						if(completadoPaso)
						break;
						
					}
				}
				
		}
		else{
			if(primer_paso==4 || primer_paso==6){
					
				for(int i=0;i<3;i++){
					for(int j=0;j<3;j++){
						movimiento++;
						if(movimiento==2){
							if(tresEnRayas[i][j]==0){
							//	printf("xdxd");
								tresEnRayas[i][j]=2;
								completadoPaso=true;
								segundo_paso=2;
								break;
							}
						}else{
							if(movimiento==8){
								if(tresEnRayas[i][j]==0){
									//printf("xdxd");
									tresEnRayas[i][j]=2;
									completadoPaso=true;
									segundo_paso=8;
									break;
								}
								
							}
						}
						
					}
					if(completadoPaso)
					break;
				}
				
				
			}			
		}
		
	}
	else{
		
		if(primer_paso==2 || primer_paso==8){
			
			int F;
			if(primer_paso==2){
				 F=0;
			}else
			{
				F=2;
			}
			if(segundo_paso==4){
				if(tresEnRayas[F][0]==0)
				{
					tresEnRayas[F][0]=2;
					completadoPaso=true;
				}
				else{
						if(tresEnRayas[1][1]==0){
							tresEnRayas[1][1]=2;
							completadoPaso=true;
						}
					}
			}else{
					if(segundo_paso==6){
						if(tresEnRayas[F][2]==0)
						{
							tresEnRayas[F][2]=2;
							completadoPaso=true;
						}
						else{
						if(tresEnRayas[1][1]==0){
							tresEnRayas[1][1]=2;
							completadoPaso=true;
						}
					}
					}
			}
			
			
		}else{
			if(primer_paso==4 || primer_paso==6){
				int C;
			if(primer_paso==4){
				 C=0;
			}else
			{
				C=2;
			}
				if(segundo_paso==2){
				if(tresEnRayas[0][C]==0)
				{
					tresEnRayas[0][C]=2;
					completadoPaso=true;
				}else{
						if(tresEnRayas[1][1]==0){
							tresEnRayas[1][1]=2;
							completadoPaso=true;
						}
			}
				
			}else{
					if(segundo_paso==8){
						if(tresEnRayas[2][C]==0)
						{
							tresEnRayas[2][C]=2;
							completadoPaso=true;
						}
						else{
						if(tresEnRayas[1][1]==0){
							tresEnRayas[1][1]=2;
							completadoPaso=true;
						}
					}
					}
			}
			}
		}
	}
		
	}
	
	return completadoPaso;
	}
	


bool empiezaMaquinaEstrategia_2(int turno){
//	printf("hol");
	if( tresEnRayas[1][1]== 1)
	return false;
	else{
		if(turno == 1 || turno ==2){
			if(tresEnRayas[1][1] ==0){
				tresEnRayas[1][1]=2;
				return true;
			}else
			return false;
			
		}else{
			if(tresEnRayas[0][0] ==0) {
				tresEnRayas[0][0]=2;
					return true;
			}else
			{
				if(tresEnRayas[0][2] ==0){
					tresEnRayas[0][2]=2;
						return true;
				}	else{
					if(tresEnRayas[2][0] ==0){
						tresEnRayas[2][0]=2;
							return true;
					}else{
						
						if(tresEnRayas[2][2] ==0){
							tresEnRayas[2][2]=2;
								return true;
						}else
						return false;
					}
				}
				
			}
			
		}
	}
	
}

bool estrategiaEsquinas(int turno){
	
	if(turno ==1 ){
		int paso;
		srand(time(NULL));
	do{
		paso= 1+rand()%(9-1);
	
	}while(paso%2==0  || paso==5);
	//printf(" %d ",paso);
		if(paso ==1 ){
			tresEnRayas[0][0]=2;
			return true;
		}else
		{
			if(paso ==3){
				tresEnRayas[0][2]=2;
				return true;
			}else{
				if(paso== 7){
					tresEnRayas[2][0]=2;
					return true;
				}else
				{
					if(paso ==9){
						tresEnRayas[2][2]=2;	
						return true;
					}
				}
			}
		}
		
	}else{
		if(turno == 3){
			if(tresEnRayas[0][0]==2){
				if(tresEnRayas[2][2]==0)
				{
					tresEnRayas[2][2]=2;
					return true;
				}else
				return 
				false;
			}else{
				if(tresEnRayas[0][2]==2){
				if(tresEnRayas[2][0]==0)
				{
					tresEnRayas[2][0]=2;
					return true;
				}else
				return 
				false;
			}else
			{
				if(tresEnRayas[2][0]==2){
				if(tresEnRayas[0][2]==0)
				{
					tresEnRayas[0][2]=2;
					return true;
				}else
				return 
				false;
			}else{
				if(tresEnRayas[2][2]==2){
				if(tresEnRayas[0][0]==0)
				{
					tresEnRayas[0][0]=2;
					return true;
				}else
				return 
				false;
			}
			}
			}
			}
			
		}else{
			if(turno == 5){
				if(  tresEnRayas[0][0]==2 && tresEnRayas[2][2]==2 ){
					if(tresEnRayas[2][0]== 0){
						tresEnRayas[2][0]=2;
							return true;
					}else{
					if(tresEnRayas[0][2]== 0){
						tresEnRayas[0][2]=2;
							return true;
					}
					else
					{
							if(tresEnRayas[1][1]== 0){
						tresEnRayas[1][1]=2;
							return true;
					}else
					return false;
					}
					}
				}
				else{
					if(  tresEnRayas[0][2]==2 && tresEnRayas[2][0]==2 ){
					if(tresEnRayas[0][0]== 0){
						tresEnRayas[0][0]=2;
							return true;
					}else{
					if(tresEnRayas[2][2]== 0){
						tresEnRayas[2][2]=2;
							return true;
					}
					else
					{
							if(tresEnRayas[1][1]== 0){
						tresEnRayas[1][1]=2;
							return true;
					}else
					return false;
					}
					}
				}
				}
			}
		}
		
	}
	return false;
}

