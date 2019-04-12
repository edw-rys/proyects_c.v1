
#include <conio.h>
#include <time.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef  struct {
	char Palabra[20];
	char nombre_jugador[20];
	char FECHA_SIST[30];
	int palabras_Acert;

	int puntos_;
}Datos;


struct Nodo{
	
	Datos nuevo_d;
	struct Nodo *sig;
};


struct Pres{
	int p[30];
	
}Presenta;

struct Nodo *nuevo_nodo(){
	return (struct Nodo *)malloc(sizeof(struct Nodo));
}
 void recuperar_jugador();
void JUega_extreme(struct Nodo *nodo_palabras);
void mostrar_menu();
void Juega_(struct Nodo * nodo_palabras, int extreme);
void datos_jugador(int puntos,int palabras_acerto);
struct Nodo *Agrega_DAtos(struct Nodo  *cabeza,struct Nodo *N);
void registra_jugadores(struct Nodo *dat);
struct Nodo* escanea_palabras_(struct Nodo *);
void ingresa_palabras(char palabra_nueva[20]);
struct Nodo * ordena(struct Nodo *ini);
void Ordenar_D(Datos D[], int tam);

void mostrar_palabras(struct Nodo *ini){
	if(ini!=NULL){
		
		struct Nodo *aux=ini;
		while(aux!=NULL){
			printf("\n%s",aux->nuevo_d.Palabra);
			aux=aux->sig;
			
		}
	}
	
}

int main(){
	
	struct Nodo *ini_jugadores,*ini_palabras=NULL;
	FILE *Fp;
	int opcion;
	
	
	
	
	do{
		mostrar_menu();
		ini_palabras=escanea_palabras_(ini_palabras);
		//mostrar_palabras(ini_palabras);
		scanf("%d",&opcion);
	
		switch(opcion){
			
			case 1:{
				Juega_(ini_palabras,0);
				
				break;
			}
			
			case 2:{
					JUega_extreme(ini_palabras);
					

				break;
			}
			case 3:{
				recuperar_jugador();
				break;
			}
			case 4:{
			/*	char pal[20];
				printf("\n\nNueva palabra: ");
				scanf("%s",&pal);
				ingresa_palabras(pal);*/
				break;
			}
			
				
			
			default :{
				printf("\nOpcion Erronea\n");
				break;
			}
			
		}
			system("cls");
	}	while(opcion!=4);

}


void mostrar_menu(){
		printf("**** JUEGO DEL AHORCADO ***** \n"); 
	printf("1.Iniciar juego del ahorcado normal\n");
	printf("2. Modo extremo\n");
	printf("3. Presentar mejores jugadores y puntajes\n");
//	printf("4. Agregar otra palabra");
	printf("4. Salir\n");
	printf("Opcion: ");
	
}

/////////jugar

void Juega_(struct Nodo * nodo_palabras,int extreme){
	struct Nodo *aux=nodo_palabras;
	int total_puntos_acumulados=0;
		
	int acertados=0,errores=0,i;//contadores 
			
	int tamanio_palabra;
	char inserta_pal;
		
	 
		
	
	
	int acierto=0;//booleano si acerto en la palabra o no
	
	int juega_ota_mas=1,j=4;
	int numero_palabras_acertadas=0;
	
	
	while(aux!=NULL && juega_ota_mas==1){
		acierto=0;acertados=0;errores=0;
	
		tamanio_palabra=strlen(aux->nuevo_d.Palabra);
		char reserva_palabra[tamanio_palabra];
	////////////serviran para mostrar las letras adivinadas
	
	int palabra_Acert[tamanio_palabra+4];
	
		strcpy(reserva_palabra,aux->nuevo_d.Palabra);
	
	/////////////encerar el arreglo de verificacion
	
	
		
	
	
		for(i=0;i<tamanio_palabra;i++){	
				
			Presenta.p[i]=0;
		}
			
	

	
		system("cls");
		printf("\nEmpecemos :)\n");
		if(extreme==1)	
		{
		//	total_puntos_acumulados=2;
			Presenta.p[0]=1;
			Presenta.p[tamanio_palabra-1 ]=1;
			reserva_palabra[0]='.';
			reserva_palabra[ tamanio_palabra-1 ]= '.';
			acertados=2;
		}
		
		
		for( i=0;i< tamanio_palabra;i++){
					if(	Presenta.p[i]==1){
					printf("%c ",aux->nuevo_d.Palabra[i]);
				}else
				printf("_ ");			
			}
			
		///////repite hasta que el numero de errores sea igual a la mitad del tamaño de la palabra
		
		
		
		do{
			
			acierto=0;
			printf("\nPalabra:\n");
			
			
			
		////////////////pide letra
			printf("\nDigite una letra: ");
			//fflush;
			scanf("%s",&inserta_pal);
			//////////letra a mayuscula
			inserta_pal=toupper (inserta_pal);
			printf("\t**%c**\n",inserta_pal);
			/////////////compara si la letra existe
			acierto=0;
			
			for(i=0;i<tamanio_palabra;i++){				
				if(inserta_pal == reserva_palabra[i]){				
						Presenta.p[i]=1;
					acierto=1;	
						acertados++;
						reserva_palabra[i]='.';	
						total_puntos_acumulados++;												
				}													
			}
			
		
		
		
		
			if(acierto==0){
				errores++;		
				printf("\nPalabra incorrecta, le quedan %d intentos",((tamanio_palabra/2)-errores));	
			}
			
			
			
		
		
			
				puts("");
			for( i=0;i< tamanio_palabra;i++){
				if(	Presenta.p[i]==1){
					printf("%c ",aux->nuevo_d.Palabra[i]);
				}else
				printf("_ ");							
			}
				puts("");
		
			if(acertados == tamanio_palabra)
				break;
		}while(errores<(tamanio_palabra/2));///////repite hasta que el numero de errores sea igual a la mitad del tamaño de la palabra
		
		if(errores==(tamanio_palabra/2))
		{
			printf("\nUsted ha perdido\nLa palabra a adivinar es \"%s\"",aux->nuevo_d.Palabra);
			break;
		}
		
		if(acertados==tamanio_palabra){
			printf("Felicidades ha adivinado la palabra %s",  aux->nuevo_d.Palabra );
		
			numero_palabras_acertadas++;
			
		}
		
//	total_puntos_acumulados+=acertados;
		do{
			printf("\n\nDeseqa seguir jugando el ahorcado con otra palabra?\n1.Si\n0.No\n-->");
			scanf("%d",&juega_ota_mas);
			if(juega_ota_mas!=0 && juega_ota_mas!=1)
				printf("\nOpcion invalida\nSolo puede ingresar 1 o 0\nVuelva a ingresar una opcion\n");

		}while(juega_ota_mas!=0 && juega_ota_mas!=1);
		
		
		
	
		
		
		
		aux=aux->sig;
	} 
	
	
	
	datos_jugador(total_puntos_acumulados,  numero_palabras_acertadas);
	
}




void JUega_extreme(struct Nodo *nodo_palabras) {
	
	struct Nodo *aux=nodo_palabras;
	int total_puntos_acumulados=0;
		
	int acertados=0,errores=0,i;//contadores 
			
	int tamanio_palabra;
	char inserta_pal;
	int acierto=0;//booleano si acerto en la palabra o no
	
	int juega_ota_mas=1,j=4,k;
	int numero_palabras_acertadas=0;
	int T;///tamañoo de las 2 palabras
	struct Nodo *aux_2=NULL;
		while(aux->sig!=NULL && juega_ota_mas==1){
			aux_2=aux->sig;
			T= strlen(aux->nuevo_d.Palabra) +strlen(aux_2->nuevo_d.Palabra);
			acierto=0;acertados=0;errores=0;
			tamanio_palabra=strlen(aux->nuevo_d.Palabra) ;
			char reserva_palabra[tamanio_palabra];
			char reserv_sec[ strlen(aux_2->nuevo_d.Palabra) ];
			////////////serviran para mostrar las letras adivinadas
	
		//	int palabra_Acert[tamanio_palabra+4];
			strcpy(reserv_sec,aux_2->nuevo_d.Palabra);
			
			strcpy(reserva_palabra,aux->nuevo_d.Palabra);
	
	/////////////encerar el arreglo de verificacion
			
			for(i=0;i<T;i++){	
				
				Presenta.p[i]=0;
			}	
			system("cls");
		printf("\nEmpecemos :)\n");
	
		//	total_puntos_acumulados=2;
			Presenta.p[0]=1;
			Presenta.p[T-1 ]=1;
			reserva_palabra[0]='.';
			reserv_sec[strlen(aux_2->nuevo_d.Palabra)-1 ]='.';
			acertados=2;
		
			for( i=0;i< tamanio_palabra;i++){
					if(	Presenta.p[i]==1){
					printf("%c ",aux->nuevo_d.Palabra[i]);
				}else
				printf("_ ");			
			}
				printf("   ");		
				k=0;
			for( i=strlen(aux->nuevo_d.Palabra);i< T;i++){
					if(	Presenta.p[i]==1){
					printf("%c ",aux_2->nuevo_d.Palabra[k]);
				}else
				printf("_ ");			
				k++;
			}
			///////repite hasta que el numero de errores sea igual a la mitad del tamaño de la palabra
			do{
			
				acierto=0;
				printf("\nPalabra:\n");
			////////////////pide letra
			printf("\nDigite una letra: ");
			scanf("%s",&inserta_pal);
			//////////letra a mayuscula
			inserta_pal=toupper (inserta_pal);
			printf("\t**%c**\n",inserta_pal);
			/////////////compara si la letra existe
			acierto=0;
			
			for(i=0;i<tamanio_palabra;i++){				
				if(inserta_pal == reserva_palabra[i]){				
						Presenta.p[i]=1;
					acierto=1;	
						acertados++;
						reserva_palabra[i]='.';	
						total_puntos_acumulados++;												
				}													
			}
			k=0;
			for(i=tamanio_palabra;i<T;i++){	
			
				if(inserta_pal == aux_2->nuevo_d.Palabra[k] &&	Presenta.p[i] !=1 ){				
						Presenta.p[i]=1;
						acierto=1;	
						acertados++;
						reserv_sec[k]='.';	
						total_puntos_acumulados++;												
				}
				k++;													
			}
		
			
			if(acierto==0){
				errores++;		
				printf("\nPalabra incorrecta, le quedan %d intentos",((T/2)-errores));	
			}
			
			
			puts("");
			for( i=0;i< tamanio_palabra;i++){
				if(	Presenta.p[i]==1){
					printf("%c ",aux->nuevo_d.Palabra[i]);
				}else
				printf("_ ");							
			}
				printf("    ");	
					k=0;
			for( i=tamanio_palabra;i<T ;i++){
				if(	Presenta.p[i]==1){
					printf("%c ",aux_2->nuevo_d.Palabra[k]);
				}else
				printf("_ ");							
				k++;
			}
			
				puts("");
			if(acertados == T)
				break;
			}while(errores<(T/2));
			
		if(errores==(T/2))
		{
			printf("\nUsted ha perdido\nLa palabra a adivinar es \"%s\"",aux->nuevo_d.Palabra);
		//	break;
		}
		
	
		if(acertados==T){
			printf("Felicidades ha adivinado la palabra %s",  aux->nuevo_d.Palabra );		
			numero_palabras_acertadas=numero_palabras_acertadas+2;;			
		}
			
			do{
			printf("\n\nDeseqa seguir jugando el ahorcado con otra palabra?\n1.Si\n0.No\n-->");
			scanf("%d",&juega_ota_mas);
			if(juega_ota_mas!=0 && juega_ota_mas!=1)
				printf("\nOpcion invalida\nSolo puede ingresar 1 o 0\nVuelva a ingresar una opcion\n");

		}while(juega_ota_mas!=0 && juega_ota_mas!=1);
			
			aux=aux->sig->sig;
		}

		
		//	total_puntos_acumulados+=acertados;
		
		
	
	datos_jugador(total_puntos_acumulados,  numero_palabras_acertadas);
}

/////////////guardar_datos


void ingresa_palabras(char palabra_nueva[20]){
		FILE *Fp; 
		char nomb[20]="palabras.dat";
 		int termino=0;
 		Fp=fopen(nomb,"a+");
 		
 		if(Fp!=NULL)
 		fprintf(Fp,"\n%s",  palabra_nueva );
 	
 	fclose(Fp);
 }




void datos_jugador(int puntos,int palabras_acerto){
	struct  Nodo *dat=nuevo_nodo();
	printf("**\n Nombre del jugador: ");
	scanf("%s",&dat->nuevo_d.nombre_jugador);
	
	dat->nuevo_d.palabras_Acert=palabras_acerto;
	dat->nuevo_d.puntos_=puntos;
		printf("**Palabras acertadas: %d \n",dat->nuevo_d.palabras_Acert );
		
		
		printf("** Puntos totales: %d",	dat->nuevo_d.puntos_);
		printf("\nAceptar");
		getch();
	registra_jugadores(dat);
}



struct Nodo *Agrega_DAtos(struct Nodo  *ini,struct Nodo *N)
{
	
	if(ini==NULL){
		
		ini=N;		
		N->sig=NULL;
	}else{	
		struct Nodo *aux=ini;
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		aux->sig=N;
		N->sig=NULL;
	}
	return ini;

}







void registra_jugadores(struct Nodo *dat){
	//struct Nodo *nuevo=nuevo_nodo();
		FILE *Fp; 
		
		
		//fecha del sistema
		char fecha[20];
	 	time_t t;
	   	struct tm *tm;
	   	t=time(NULL);
 		tm=localtime(&t);
  		strftime(fecha, 100, "%d/%m/%Y", tm);
	
	
	
	//////////////
	
		
		char nombre[20]="jugadores.dat";
	
	//////////////
	
		if((Fp=fopen(nombre,"w"))!=NULL){
				fprintf(Fp,"%d\n%s\n%d\n%s\n",dat->nuevo_d.puntos_,dat->nuevo_d.nombre_jugador,dat->nuevo_d.palabras_Acert, fecha );
		}
	fclose(Fp);
	
	 
  //printf ("Hoy es: %s\n", nuevo->nuevo_d.FECHA_SIST);
	
}


int cuenta_m(struct Nodo  *cabeza){
	int cont=0;
	if(cabeza != NULL)
	{
		struct Nodo *aux=nuevo_nodo();
		aux=cabeza;
		while(aux!=NULL){
			cont++;
			aux=aux->sig;
		}
		return cont;
	}
	else 
	return 0;
}


 ////////////Recuperar_datos
 

 void recuperar_jugador(){
 	
 
 	FILE *Fp;
 	 Datos D[100];
 	char nomb[20]="jugadores.dat";
 	
	
 		int i=0;
 		
 		
 		Fp=fopen(nomb,"r");
 	if(Fp!=NULL){
 	
 		while( feof (Fp)==0){
 			
 	
		
			fscanf(Fp,"%d",&D[i].puntos_);
			 fscanf(Fp,"%s",&D[i].nombre_jugador);
		 	fscanf(Fp,"%d",&D[i].palabras_Acert);
			 fscanf(Fp,"%s",&D[i].FECHA_SIST);
		 	
		 i++;
		 }
	 }
	 
	 fclose(Fp);
	 i--;
	 
	 Ordenar_D(D,i);
	 int j=0;
	 system("cls");
	 printf("\nPuesto\tPuntos\tNombre\tPalabras acertadas\tFecha\n");
	 for( j=0;j<i;j++){
	 	
	 	printf( "\n%d\t%d\t%s\t%d\t\t%s",j+1,D[j].puntos_,D[j].nombre_jugador,D[j].palabras_Acert,D[j].FECHA_SIST  );
	 	if(j==9)
	 	break;
	 }
	 



 	getch();
 	
 }
 
 
 
 struct Nodo* escanea_palabras_(struct Nodo *ini_palabras){
 		struct Nodo *nuevo=nuevo_nodo();
 	
		FILE *Fp; 
		char nomb[20]="palabras.dat";
 		int termino=0;
 		Fp=fopen(nomb,"r");
 		
 		if(Fp!=NULL){
 			
 			while(feof(Fp)==0){
 				nuevo=nuevo_nodo();
		
			 	termino=fscanf(Fp,"%s",&nuevo->nuevo_d.Palabra);
			 	strupr(nuevo->nuevo_d.Palabra);
 				ini_palabras=Agrega_DAtos(ini_palabras,nuevo);
			 
			 }
 		
		 }
		 else
		 {
		 	printf("\nError, no existen palabras\n");
		 }
		 	
		 fclose(Fp);
		
		 return ini_palabras;
 }





/////////////ordenar posiciones
void Ordenar_D(Datos D[], int tam){
	Datos RES;
	int i=0,j=0;
	for( i=0;i<tam; i++){
		for( j=0;j<tam-1; j++){
			if(D[j].puntos_<D[j+1].puntos_){
				
				RES=D[j];
				D[j]=D[j+1];
				D[j+1]=RES;
				
			}
		}
		
		
	}
}
//


///YYY

