/*
Suponga que una empresa desea instalar una oficina de atención al cliente. Diseñe un
programa que permita ingresar clientes (CI) al sistema, los cuales serán atendidos en
orden de llegada.
Al llegar el cliente suministra su cédula y el sistema le asignará un turno.
Cuando un cliente es atendido se retira de la fila..
Al finalizar el día el sistema deberá generar un reporte en un archivo con la siguiente
información.
1. Fecha del Reporte:
2. Cantidad de clientes atendidos.
3. Cantidad de cliente que quedaron sin atender.
4. Cantidad máxima de clientes que hubo en espera.
5. Listado de clientes atendidos y el tiempo de espera en la cola de cada uno.
*/
/*INTEGRANTES
1. EDWARD ANTHONY REYES VILLÓN*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
int dia,mes,anio;
typedef struct{
	char ci[10];
	int t_h,t_m;
	
}CLIENTE;
 struct Nodo // Se crea el tipo de dato Nodo
{
	//int max_clientes;//Cantidad máxima de clientes que hubo en espera.
	int t_e;//tiempo esperado por cliente
 CLIENTE client;
struct Nodo *sig;
};
//en cola por atender
struct Nodo *ini=NULL;
struct Nodo *ultimo=NULL;
//Nodo de atendidos
struct Nodo *RESERVAR=NULL, *FIN=NULL;




void menu(int *);
struct Nodo *Crea_Nodo_Vacio();
void registrar_cliente(struct Nodo *);
struct Nodo *Agregar_Nodo_Final(struct Nodo *);
struct Nodo *Retira( int t);
struct Nodo *atendidos(struct Nodo *);
void Mostrar_Cola(int t);
void Mostrar_Nodo(struct Nodo *, int t);
int Cantidad_Nodos();
int Cantidad_Nodos_atendidos();


void escribe(int , int,int);
void calcula_time_esp();
void reporte_diario();
int main(){
 	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[30];
//    strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
	strftime(output,128,"%d",tlocal);
	dia =atoi(output);
	strftime(output,128,"%m",tlocal);
    mes =atoi(output);
	strftime(output,128,"%y",tlocal);
    anio =atoi(output);
    printf("%d %d %d",dia,mes,anio);
	int i=0;
	do{
		reporte_diario();
		
	}while(i<1);

	getch ();
}



void reporte_diario()
{
	int retorno;
		

	FILE *fp;
	char nomb[20]="clientes.txt";
		menu(&retorno);

		int vuelta;
		system("cls");
		
		//INICIO DE REPORTE////////////////////////////////////////////////////////////////////////////////////
		//1. FECHA
	    printf("\t\t\t");printf("%c",201);
	    for(vuelta=0;vuelta<89;vuelta++)
	    printf("=");
	    printf("%c",187);
	    puts("");
		printf("\t\t\t");	printf("%c	-- Fecha del Reporte\t\t\t\t\t\t\t\t  %c\n",186,186);
		printf("\t\t\t");	printf("%c\t\t\t****\"D%ca %d  mes: %d a%co: %d\"****\t\t\t\t  %c\n",186,161, dia,mes,164,anio,186);
		printf("\t\t\t"); 	printf("%c",200);
	for(vuelta=0;vuelta<89;vuelta++)
	    printf("=");
	    printf("%c",188);
	puts("\n\n");
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	    //2. CLIENTES ATENDIDOS//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	    printf("\t\t\t"); printf("%c",201);
	for(vuelta=0;vuelta<89;vuelta++)
	    printf("=");
	      printf("%c",187);
	    puts("");
	printf("\t\t\t");	printf("%c	-- Cantidad de clientes atendidos\t\t\t\t\t\t  %c\n",186,186);
	printf("\t\t\t");	printf("%c\t\t\t****\"HUBO \"%d\" CLIENTES ATENDIDOS\"****\t\t\t\t  %c\n",186,Cantidad_Nodos_atendidos(),186);
	printf("\t\t\t"); 	printf("%c",200);
	for(vuelta=0;vuelta<89;vuelta++)
	    printf("=");
	    printf("%c",188);
	puts("\n\n");
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//3. CLIENTES SIN ATENDER
	printf("\t\t\t"); printf("%c",201);
	for(vuelta=0;vuelta<89;vuelta++)
	    printf("=");
	      printf("%c",187);
	    puts("");
	printf("\t\t\t");	printf("%c	-- Cantidad de cliente que quedaron sin atender\t\t\t\t\t  %c\n",186,186);
	printf("\t\t\t");	printf("%c		\t****\" HUBO \"%d\" CLIENTES QUE NO FUERON ATENDIDOS\"****\t\t  %c\n",186,Cantidad_Nodos(),186);
	printf("\t\t\t"); 	printf("%c",200);
	for(vuelta=0;vuelta<89;vuelta++)
	    printf("=");
	    printf("%c",188);
	puts("\n\n");
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	// 4. Cantidad máxima de clientes que hubo en espera.
		printf("\t\t\t"); printf("%c",201);
	for(vuelta=0;vuelta<89;vuelta++)
	    printf("=");
	      printf("%c",187);
	    puts("");
	printf("\t\t\t");	printf("%c	-- Cantidad m%cxima de clientes que hubo en espera\t\t\t\t  %c\n",186,160,186);		
				printf("\t\t\t%c	****\" La m%cxima cantidad de clientes que hubo en espera fue de : %d \"****\t  %c\n",186,160,retorno,186);
	printf("\t\t\t"); 	printf("%c",200);
	for(vuelta=0;vuelta<89;vuelta++)
	    printf("=");
	    printf("%c",188);
	puts("\n\n");
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	//5. Listado de clientes atendidos y el tiempo de espera en la cola de cada uno.
	
	printf("\t\t\t"); printf("%c",201);
	for(vuelta=0;vuelta<89;vuelta++)
	    printf("=");
	      printf("%c",187);
	    puts("");
	printf("\t\t\t");	printf("%c	-- Listado de clientes atendidos y el tiempo de espera en la cola de cada uno.    %c\n",186,186);
	
	
	if(RESERVAR!=NULL){
		struct Nodo *timepo_atendidos=Crea_Nodo_Vacio();
		timepo_atendidos=RESERVAR;
			
			
			printf("\t\t\t");
		printf("%c",201);
		
		for(vuelta=0;vuelta<89;vuelta++)
	    printf("=");
	    printf("%c",187);
			printf("\n\t\t\t");	printf("|Cedula: %d, Tiempo de espera: \"FUE EL PRIMERO Y NO TUVO QUE ESPERAR TURNOS\"\t    |",timepo_atendidos->client.ci);
			timepo_atendidos=timepo_atendidos->sig;
			
			while(timepo_atendidos!=NULL)
			{
				printf("\n\t\t\t|Cedula: %d, Tiempo de espera: %d minutos \t\t\t\t\t\t    |",timepo_atendidos->client.ci,timepo_atendidos->t_e);
			timepo_atendidos=timepo_atendidos->sig;
			}	
			
			}else
			printf("\t\t\t%c\t\t\t****No hay clientes ****\"\t\t\t\t\t\t  %c",186,186);
	
	printf("\n\t\t\t%c",200);
		
		for(vuelta=0;vuelta<89;vuelta++)
	    printf("=");
	    printf("%c",188);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	if(ini!=NULL)
	{
		struct	Nodo *vaciar=(struct Nodo*)malloc(sizeof(struct Nodo));
	vaciar=ini;
		
	do{
			vaciar=ini;
		ini=vaciar->sig;
		free(ini);
	}	while(ini!=NULL );
	
	}
	

	if(RESERVAR!=NULL){
	 	struct	Nodo *v_d=(struct Nodo*)malloc(sizeof(struct Nodo));
	 	v_d=RESERVAR;
	 	
	 	do{
			v_d=RESERVAR;
		RESERVAR=v_d->sig;
		free(RESERVAR);
	}	while(RESERVAR!=NULL );
	} 
	    	
		dia++;
			if(dia>30)
			{
				mes++;
				dia=1;
			}
			if(mes>12)
			{
				mes=1;
				anio++;
			}
			
		puts("\n\n");
		system("pause");
}














struct Nodo *Crea_Nodo_Vacio(){	
return 	 (struct Nodo *)malloc(sizeof(struct Nodo));
}


void menu(int *retorno ){	
	char val[10];
	struct Nodo *N=NULL;
	int max_cl=0;
	int turno=1,t1=1;
	system("color A5");
	

	int menU,v;
	//int val=0;
	do{
	
	do{
	
	system("cls");
	int vuelta;
	printf("\t\t\t");
		printf("%c",201);
		
		for(vuelta=0;vuelta<55;vuelta++)
	    printf("=");
	    printf("%c",187);
	    
	printf("\n\t\t\t%c		Men%c\t\t\t\t\t%c\n",186,163,186);
	printf("\t\t\t"); printf("%c	1. Ingresar clientes\t\t\t\t%c\n",186,186);
	printf("\t\t\t"); printf("%c	2. Atender cliente\t\t\t\t%c\n",186,186);
	printf("\t\t\t"); printf("%c	3. Mostrar Lista de clientes\t\t\t%c\n",186,186);
	printf("\t\t\t"); printf("%c	4. Finalizar atencion\t\t\t\t%c\n",186,186);
	printf("");
	printf("\t\t\t");
	printf("%c",200);
	for(vuelta=0;vuelta<55;vuelta++)
	    printf("=");
	    printf("%c",188);
	printf("\n\t\t\t\t\tEscoja una opcion: ");
	scanf("%s",&val);
	v=validar_numero(val);

	
}while(v==0);
	menU=atoi(val);
	switch(menU){
		
		case 1:{
			N=Crea_Nodo_Vacio();
			registrar_cliente(N);
			printf("\t\t\t\t**Turno %d**\n",turno);
			N=Agregar_Nodo_Final(N);
		
			max_cl++;
			system("pause");
			turno++;
			break;
		}
		case 2:{
			
			if(max_cl>(*retorno)){
				*retorno=max_cl;
				
				max_cl=0;
			}
				 if(ini!=NULL)
 				{		
 						N=Crea_Nodo_Vacio();
						N=Retira(t1);
				
	 			}else
	printf("\n\t\t\t******No hay mas turnos que atender*******\n");
			
			t1++;
		puts("\n");
			system("pause");
			
			//atender_cliente();
			break;
		}
		case 3:{
			
			Mostrar_Cola(t1);
			
			puts("\n");
			system("pause");
			//recorrer_lista();
			break;
		}
		case 4:{
			
			printf("\n\t\t\t*******D%ca finalizado*********\n",161);
			system("pause");
			break;
		}

		default :{
			printf("\t\t\t*********Opci%cn no v%clida********\n",162,160);
			system("pause");
			break;
		}
	}
	}while(menU!=4);
		calcula_time_esp();
			escribe(dia,mes,anio);
		
}


void registrar_cliente(struct Nodo *N){
char val[10]; int v;
	do{
		printf("\n\t\t\tDigite la cedula del cliente: ");
		do{
			scanf("%s",&val);	
			if(strlen(val)!=10)
				printf("\n\t\t\tCedula de longitud incorrecta, digite otra vez: ");
		}while(strlen(val)!=10);
		puts("");
	}while(validar_numero(val)==0);
	strcpy( N->client.ci,val);



	printf("\n\t\t\tITiempo de inicio de la atenci%cn:\n",162);
	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[30];
    strftime(output,128,"%H:%M:%S",tlocal);
	printf("\n\t\t\t%s ",output);
	strftime(output,128,"%H",tlocal);
    N->client.t_h=atoi(output);
    strftime(output,128,"%M",tlocal);
    N->client.t_m=atoi(output);
    puts("");
//	do{
//	
//	do{
//		printf("\t\t\tHora: ");
//		scanf("%s",&val);
//		v=validar_numero(val);
//		puts("");
//	}while(v==0);
//	N->client.t_h=atoi(val);
//		if(N->client.t_h>24)
//		printf("\n\n\t\t\t*******No pueden ser mas de 24 horas, Ingrese de nuevo*******\n");
//	}	while(N->client.t_h>24);
//	
//		do{
//			
//			do{
//					printf("\t\t\tMinutos: ");
//		scanf("%s",&val);
//		v=validar_numero(val);
//		puts("");
//			}while(v==0);
//	N->client.t_m=atoi(val);
//		if(N->client.t_m>60)
//		printf("\n\n\t\t\t*******Los minutos no pueden pasarse de 60, Ingrese de nuevo*******\n");
//		}while(N->client.t_m>60);

	N->sig=NULL;
}

struct Nodo *Agregar_Nodo_Final(struct Nodo *N)
{
	if(ini==NULL)
	{
		ini=N;
		ini->sig=NULL;
		ultimo=N;	
	}else{
		ultimo->sig=N;
		N->sig=NULL;
		ultimo=N;
}

return N;
}



//Atender a un cliente
struct Nodo *Retira(int t )
{
struct Nodo *a,*b;

  a=ini;
	b=Crea_Nodo_Vacio();
	b->client.t_h=ini->client.t_h;
	b->client.t_m=ini->client.t_m;
	strcpy(b->client.ci, ini->client.ci);
	b->sig=NULL;
 	ini=ini->sig;
 	printf("\n\t\t\t**ATENDIENDO A : \" %d\" , TURNO %d**\n",a->client.ci,t);
 	 b= atendidos(b);
 	if(ini!=NULL){
 		t++;
 		Mostrar_Cola(t);
	 }
	 	
 	
 //	RESERVAR=a;
 free(a);

return ini;
}

//Guarda en una nueva lista los clientes atendidos
struct Nodo *atendidos(struct Nodo *N)
{
	if(RESERVAR==NULL)
	{
		RESERVAR=N;
		RESERVAR->sig=NULL;
		FIN=N;	
	}else{
		FIN->sig=N;
		N->sig=NULL;
		FIN=N;
}

return N;
}
// mostrar los ultimos clientes en la cola
void Mostrar_Cola(int t)
{
  struct Nodo *a;
  a=ini;
     if(ini!=NULL)
     {
     	
     	printf("\n\t\t\t SIGUIENTES:\n");

	while (a!=NULL)
	{
			Mostrar_Nodo(a,t);
			t++;
			a=a->sig;

	}
	 }else
	 printf("\n\t\t\t********No hay clientes********\n");
	
}
// muestra los datos del nodo indicado
void Mostrar_Nodo(struct Nodo *N, int t){
	
	printf("\n\t\t\t\"%d\"  TURNO \"%d\"",N->client.ci,t);
	
}


//calcular el tiempo que se demoraron en atender al cliente
void calcula_time_esp(){
	if(RESERVAR!=NULL)
	{
	struct Nodo *timepo_atendidos=Crea_Nodo_Vacio(),*despues=Crea_Nodo_Vacio();
			timepo_atendidos=RESERVAR;	
			despues=timepo_atendidos->sig;
			timepo_atendidos->t_e=0;
			while(timepo_atendidos->sig!=NULL){
				despues->t_e=((despues->client.t_h*60)+despues->client.t_m)-((timepo_atendidos->client.t_h*60)+timepo_atendidos->client.t_m);
				timepo_atendidos=timepo_atendidos->sig;
				despues=despues->sig;
			}		
	}
	
	
	
}

//VALIDACION,,comprueba si el dato ingresado es numero, retorna 1, de lo contrario retorna 0
int validar_numero( char  numero[])
{
	
    int i;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            printf("\nINGRESA SOLO NUMEROS\n\n");
//            system("pause");
            return 0;
        }
    }
    
    return 1;
}

//cuenta todos los nodos de la lista
int Cantidad_Nodos()
{
	int n=0;
	struct Nodo *cont=(struct Nodo*)malloc(sizeof(struct Nodo));
	cont=ini;
	if(ini!=NULL)
	{
		while(cont!=NULL)
		{
		n++;
		 cont=cont->sig;
		}
		
	}
	return n;
}

//cuenta los clientes atendidos
int Cantidad_Nodos_atendidos()
{
	int n=0;
	struct Nodo *FFF=(struct Nodo*)malloc(sizeof(struct Nodo));
	FFF=RESERVAR;
	if(RESERVAR!=NULL)
	{
		while(FFF!=NULL)
		{
		n++;
		 FFF=FFF->sig;
		}
		
	}

	return n;
}



//Crear fichero y escribir en el los datos de los clientes
void escribe(int dia,int mes,int ao){
	FILE *fp;
	char nomb[20]="CLIENTES.txt";
	struct Nodo *R=Crea_Nodo_Vacio(),*A=Crea_Nodo_Vacio();
	A=RESERVAR;
	R=ini;
	int turno=1;
	if((fp=fopen(nomb,"a+"))!=NULL){
		
		fprintf(fp,"\t\t***** Dia %d\tMes %d\tAnio  %d *****\n",dia,mes,ao);
		fprintf(fp,"\n\t\t\"ATENDIDOS\"\n");
		if(RESERVAR!=NULL){
			
		fprintf(fp,"\t\t** CI: %d\tHora de entrada %d:%d\tTURNO: %d\tFue el priemro **\n",A->client.ci,A->client.t_h,A->client.t_m,turno);
		turno++;
		A=A->sig;
		while(A!=NULL){
			
			fprintf(fp,"\t\t** CI: %d\tHora de entrada %d:%d\tTURNO: %d\tTIEMPO ESPERA: %d minutos**\n",A->client.ci,A->client.t_h,A->client.t_m,turno,A->t_e);
			turno++;
			A=A->sig;
		}	
			
		}
		else
		fprintf(fp,"\t\t\" Hoy no hubo clientes atendidos\"\n\n");
		fprintf(fp,"\n\t\t\"SIN ATENDER\"\n\n");
		if(ini!=NULL)
		{
		
		while(R!=NULL){
			
			fprintf(fp,"\t\t** CI: %d\tHora de entrada %d:%d\tTURNO: %d **\n",R->client.ci, R->client.t_h, R->client.t_m,turno);
			turno++;
			R=R->sig;
		}	
		fprintf(fp,"\n");
		}else
		fprintf(fp,"\t\t\" Hoy no hubo clientes sin atender\"\n\n");
		
		fclose(fp);
	}else
	printf("\nNo se pued escribir el fichero\n");
	
}



