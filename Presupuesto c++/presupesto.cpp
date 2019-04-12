#include <stdio.h>
#include <string.h>
#include <conio.h>
#include<windows.h>


int totalPresupuestos=0;

struct Detalles{
	char descripcion[100];
	float precio;
	int num_detale;
};
struct Fecha{
	char mes[10];
	int anio;
	int dia;
};

struct Nodo{
	int codigo_unico;
	
	Detalles manoObra[50];	
	int tam_manoObra,tam_material;
	Detalles materiales[50];	
	Nodo *sig;	
	Nodo *atras;
	char Nombre_proyecto[20];
	Fecha fecha;
	float total;
	char cliente[50];
	float T_MO;//total mano de obra
	float T_MAT;//totl materiales	
};
//Asigna espacio en memoria al nodo
Nodo *Crear_nodo_Vacio()
{
	
 return (struct Nodo *)malloc(sizeof(struct Nodo));//Retorna 	
}

//int key_code;//Codigo de unico del presupuesto

void gotoxy(int x, int y)//FUNCION GOTOXY
{
	HANDLE hCon;//HANDLE: IDENTIFICADOR DE OBJETOS O RECURSOS
	COORD dwPos;//CORD: ESTRUCTURRA DE COORDENADAS
	
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);//RECUPERA UN IDENTIFICADOR PARA EL DISPOSITIVO ESTANDAR EL CUAL SE LO IDENTIFICA COMO PARAMETRO DE SALIDA ESTANDAR 
	SetConsoleCursorPosition(hCon, dwPos);//SITUA EL CURSOR EN LA POSICION X Y
}
//validar ingreso numeros
int validarNumeros(char num[]){
	
	for(int i=0;i<strlen(num);i++){
		if(num[i]!='1' && num[i]!='2' && num[i]!='3' && num[i]!='4' && num[i]!='5' && num[i]!='6' && num[i]!='8' && num[i]!='9' && num[i]!='0' && num[i]!='7'){
		
			return 300;
			
		}
	}
	return atoi(num);
	
}

///ValidarMES
bool validarMes(char mes[10]){
	return strcmp(mes,"ENERO")==0 || strcmp(mes,"FEBRERO")==0 || strcmp(mes,"MARZO")==0 || strcmp(mes,"ABRIL")==0 || strcmp(mes,"MAYO")==0 || strcmp(mes,"JUNIO")==0 ||
	strcmp(mes,"JULIO")==0 || strcmp(mes,"AGOSTO")==0 || strcmp(mes,"SEPTIEMBRE")==0 || strcmp(mes,"OCTUBRE")==0 || strcmp(mes,"NOVIEMBRE")==0 || strcmp(mes,"DICIEMBRE")==0 ;
}

//validar ingreso float
float validarDecimal(char h[]){
	for(int j=0;j<strlen(h);j++){
        if(h[j]!='0' && h[j]!='.' && h[j]!='1' && h[j]!='2' && h[j]!='3' &&h[j]!='4' && h[j]!='5' && h[j]!='6' && h[j]!='7' && h[j]!='8' && h[j]!='9' )
		{
			return -555;
			
		}
        					
     }
     return atof(h);
}

int  menuPresupesto(int , int , int ,int , int , int );
void recorreListaYMuestra(Nodo *Lista);
void mostrarDatos(Nodo *Lista);
Nodo *agregarDatos(Nodo *Lista, Nodo *nuevo);
void bucarPresupuesto(Nodo *lista, int code);
void escribePresupuesto(Nodo *Datos);
Nodo *LeerPresupuesto(Nodo *Lista);
void escibreTOtal();
void leeTotal();
void concatenarEspacios(char frase[]);
void quitarSubguiones(char frase[]);

int main(){
	totalPresupuestos=0;

	int opc;
leeTotal();
	char validar[5];
	Nodo *Lista=NULL;
	Lista =LeerPresupuesto(Lista);
	do{
	system("cls");//Limpia pantalla
	
	menuPresupesto(2,14,9,14,60,14);//Imprime marcos
		gotoxy(12,4);
		printf("1. Registro de nuevo presupesto");
		gotoxy(12,6);
		printf("2. Buscar presupesto por codigo");
		gotoxy(12,8);
		printf("3. Ver todos los presupestos resgitrados");
		gotoxy(12,10);
		printf("0. Salir");
		gotoxy(12,12);
		printf("Opcion   [   ]");

		gotoxy(23,12);
		scanf("%s",&validar); fflush(stdin);
	
	opc=validarNumeros(validar);
	
	if(opc==300)//si el dato generado es 300, significa que no es numero
	{
			gotoxy(1,1);
		printf("Error de dato ingresado");
	}
	
	switch(opc){
		case 0:{
			system("cls");//Limpia pantalla	
			break;
		}
		case 1:{
			system("cls");//Limpia pantalla	
			Nodo *nuevo=Crear_nodo_Vacio();
			   fflush(stdin);
			   	gotoxy(5,3);		printf("*---------------------------------------------------------------------------------*");	
			   do {gotoxy(5,5);		printf("| Nombre del Proyecto: ");			scanf("%100[^\n]",nuevo->Nombre_proyecto);		fflush(stdin);//limpia buffer  
			   	}while(strcmp(nuevo->Nombre_proyecto,"")==0);
				 
				 do{				 
				   gotoxy(5,7); 		printf("| Nombre del cliente: ");   scanf("%100[^\n]",nuevo->cliente);			fflush(stdin);
			}while(strcmp("",nuevo->cliente  )==0);
				gotoxy(5,9);   		printf("|                    FECHA");
				do{	
					do{
					do{
						gotoxy(5,10);   		printf("|         A%co:             ",164); 	gotoxy(22,10); scanf("%100[^\n]",&validar);   fflush(stdin);
					}while(  strcmp(validar,"")==0);
						nuevo->fecha.anio=validarNumeros(validar);//guarda año
						if(nuevo->fecha.anio==300)
						{
							gotoxy(1,1); printf("Error de fecha'a%co' *",164); 	
						}
					}while(nuevo->fecha.anio==300);
					if(nuevo->fecha.anio <2017 || nuevo->fecha.anio >2020) 
						{gotoxy(1,1); printf("Error de fecha'a%co'*",164); 	}	
				}while(nuevo->fecha.anio <2017 || nuevo->fecha.anio >2020);
				gotoxy(1,1); printf("                    ");
			do{
				do{
				gotoxy(5,11);   		printf("|         MES:            "); gotoxy(22,11); scanf("%100[^\n]",nuevo->fecha.mes); fflush(stdin);}while(strcmp(nuevo->fecha.mes,"")==0);
				strupr(nuevo->fecha.mes);
				if(!validarMes(nuevo->fecha.mes))
				{gotoxy(1,1); printf("Error de fecha'MES'*"); 	}	
		}while(!validarMes(nuevo->fecha.mes));
			gotoxy(1,1); printf("                    ");
				do{	
					do{
					do{
					gotoxy(5,12);   	printf("|         Dia:                  "); gotoxy(22,12); scanf("%s",&validar);   fflush(stdin);
					}while(  strcmp(validar,"")==0);
						nuevo->fecha.dia=validarNumeros(validar);//guarda año
						if(nuevo->fecha.dia==300)
						{
							gotoxy(1,1); printf("Error de fecha'Dia'*"); 	
						}
					}while(nuevo->fecha.dia==300);
					if(nuevo->fecha.dia <2017 || nuevo->fecha.anio >2020) 
						{gotoxy(1,1); printf("Error de fecha'Dia*"); 	}	
				}while(nuevo->fecha.dia <1 || nuevo->fecha.dia >30);
				 gotoxy(1,1); printf("                           ");
		/*	
			scanf("%d",& nuevo->fecha.anio);
			*/
	
	//REGISTRO DE MANO DE OBRA
	system("cls");
			printf("Digite la descripcion de la mano de obra y su precio.\n");
			int cantidad_descr=0;//cuenta el tamaño de mano de obra
			
			int fin;
		nuevo->total=0;
		nuevo->T_MO=0;
			fflush(stdin);	
		int pos =4;
			do{
					
		do{
			gotoxy(5,pos); 
				printf("Detalle mano de obra: ");   scanf("%100[^\n]",&nuevo->manoObra[cantidad_descr].descripcion);	
					fflush(stdin);	
	}while(strcmp("",nuevo->manoObra[cantidad_descr].descripcion )==0);
	pos=pos+2;
			do{
				gotoxy(5,pos); 	printf("Precio:                       ");
				gotoxy(13,pos); scanf("%100[^\n]",&validar); fflush(stdin);
				nuevo->manoObra[cantidad_descr].precio=validarDecimal(validar);
				if( nuevo->manoObra[cantidad_descr].precio==-555)
				{
					gotoxy(1,1); printf("Error de Dato 'Precio'*"); 	
				}
					gotoxy(0,pos+1);  printf("                                                                           ");
				gotoxy(0,pos+2);  printf("                                                                            ");
		}while(nuevo->manoObra[cantidad_descr].precio==-555); 			 gotoxy(1,1); printf("                             ");
		
		
				 fflush(stdin);  pos=pos+2;
			//float n=nuevo->manoObra[cantidad_descr].precio;
			nuevo->T_MO=nuevo->manoObra[cantidad_descr].precio+ nuevo->T_MO;
				nuevo->total =   nuevo->manoObra[cantidad_descr].precio+  nuevo->total;
				cantidad_descr++;
			do{
				
					gotoxy(5,pos); 
				printf("Desea segui con el registro de mano de obra?  (1. Si / 0. No):                                     ");
			do{
				gotoxy(67,pos); scanf("%s",& validar);
				 fflush(stdin);
				}while(strcmp("",validar)==0);
				
				fin=validarNumeros(validar);
				if(fin!=1 && fin!=0 ){
				gotoxy(1,1); 
				printf("Opcion no es valida* \n");
				}
					gotoxy(0,pos+1);  printf("                                                                           ");
				gotoxy(0,pos+2);  printf("                                                                            ");
			}while(fin!=1 && fin!=0);
			
				gotoxy(0,pos);  printf("                                                                            ");
				
			}while(fin!=0);
			
			nuevo->tam_manoObra=cantidad_descr;//guarda el tamaño de toddos los detales
			
	//////////////////////////////////////////////////////////////////////////////////
			system("cls");
			
			///REGISTRO DE MATERIALES Y PRECIOS
			printf("Digite la descripcion de los materiales y su precio.\n");
			cantidad_descr=0;
			pos =4;
			do{
			 
			do{
				gotoxy(5,pos);
			printf("Detalle Materiales: ");
			scanf("%100[^\n]",&nuevo->materiales[cantidad_descr].descripcion);			 
			   fflush(stdin);
		}while(strcmp("",nuevo->materiales[cantidad_descr].descripcion )==0);
			   pos=pos+2;
			   
			do{
				gotoxy(5,pos);  printf("Precio:             ");
			gotoxy(13,pos); 		 scanf("%s",&validar); fflush(stdin);
				nuevo->materiales[cantidad_descr].precio=validarDecimal(validar);
			if( nuevo->materiales[cantidad_descr].precio==-555)
				{
					gotoxy(1,1); printf("Error de Dato 'Precio'*"); 	
				}
				
					gotoxy(0,pos+1);  printf("                                                                           ");
				gotoxy(0,pos+2);  printf("                                                                            ");
		}while(nuevo->materiales[cantidad_descr].precio==-555);    gotoxy(1,1); printf("                          ");
			 
			pos=pos+2;
			//float n=nuevo->manoObra[cantidad_descr].precio;
			nuevo->total =   nuevo->materiales[cantidad_descr].precio+  nuevo->total;
			nuevo->T_MAT=nuevo->T_MAT+nuevo->materiales[cantidad_descr].precio;
			
			cantidad_descr++;
			do{
				gotoxy(5,pos); 
				printf("Desea segui con el registro de Materiales?  (1. Si / 0. No):                      ");
						
		do{
				gotoxy(67,pos); scanf("%s",& validar);}while(strcmp("",validar)==0);
				fin=validarNumeros(validar);
				if(fin!=1 && fin!=0 ){
				gotoxy(1,1); 
				printf("Opcion no es valida\n");}
					gotoxy(0,pos);  printf("                                                                                ");
				gotoxy(0,pos+1);  printf("                                                                            ");
				gotoxy(0,pos+2);  printf("                                                                            ");
				gotoxy(0,pos+3);  printf("                                                                            ");
			}while(fin!=1 && fin!=0);
		 gotoxy(1,1); printf("                            ");
			}while(fin!=0);
			
			nuevo->tam_material=cantidad_descr;
			
			
			Lista=agregarDatos(Lista,nuevo);
			
			totalPresupuestos++;
			nuevo->codigo_unico=totalPresupuestos;
			mostrarDatos(nuevo);
			escibreTOtal();
			
			escribePresupuesto(nuevo);
			
			//printf("%s",Lista->Nombre_proyecto);
			break;
		}
		case 2:{
			if(Lista ==NULL)
			{
					gotoxy(1,1);	
		printf("No hay presupuestos");
			}
			else{
			int codigo;
			system("cls");
			do{	
			menuPresupesto(2,8,9,8,60,8);//Imprime marcos
				gotoxy(10,3);printf("Ingrese codigo del presupuesto a buscar:         ");			
				gotoxy(51,3);scanf("%s",&validar); fflush(stdin);	
				codigo=validarNumeros(validar);
	
				if(codigo==300)//si el dato generado es 300, significa que no es numero
				{
					gotoxy(1,1);
					printf("Error de dato ingresado");
				}
			
			}while(codigo==300);
			bucarPresupuesto(Lista, codigo);
		}
			break;
		}
		case 3:{
			recorreListaYMuestra(Lista);
			break;
		}
		default:{
				gotoxy(1,1);
		printf("Opcion no es valida");
			break;
		}
	}
	
	getch();
	
	
	}while(opc!=0);
	
}

//Recibe datos fila inicio, fila fin, columna inicio, columna fin , tamaño de lineas horizontales

//Detalles del menú principal
int menuPresupesto(int C1, int C2, int F1,int F2,int  tamanio_Hor, int tam_vert){
	//Linesas horizontales
	for(int i=10;i<tamanio_Hor;i++)
	{
		gotoxy(i,C1);
		printf("%c",205);
		gotoxy(i,C2);
		printf("%c",205);
	}
	//Lines verticales
	for(int i=3;i<tam_vert;i++)
	{
		gotoxy(F1,i);
		printf("%c",186);
		gotoxy(tamanio_Hor,i);
		printf("%c",186);
	}
	//esquina superior izquierda
		gotoxy(F1,C1);
		printf("%c",201);
	//esquina inferior izquierda	
		gotoxy(F1,C2);
		printf("%c",200);
		//esquina superior derecha
		gotoxy(tamanio_Hor,C1);
		printf("%c",187);
		//esquina inferior derecha
		gotoxy(tamanio_Hor,C2);
		printf("%c",188);
		//menu

		

}


//Proceso listas doblemente enlazadas


Nodo *agregarDatos(Nodo *Lista, Nodo *nuevo){//Recibe toda la lista, recibe el nuevo nodo a agregar
	if(Lista==NULL){//Si lista está vacia, seagrega dato al inicio
		Lista=nuevo;
		Lista->sig=NULL;
		Lista->atras=NULL;
	}
	else
	{
		Nodo *aux=Lista;//se guarda la lista en un auxiliar para recorrerla
		while(aux->sig!=NULL)//recorre hasta que su siguiente sea nulo
		aux=aux->sig;//avanza al sig nodo

		aux->sig=nuevo;//agrega dato al ultimo
		nuevo->atras=aux;
	}
	return Lista;
	
}

void mostrarDatos(Nodo *aux){
	
quitarSubguiones(aux->cliente);
quitarSubguiones(aux->Nombre_proyecto);

	//system("cls");	
			system("cls");
			menuPresupesto(2,50,9,14,84,50);
			gotoxy(30,4);
			printf("PRESUPUESTO  \" %s\"",aux->Nombre_proyecto);
			
		gotoxy(70,4); printf("Codigo: %d",aux->codigo_unico);
				gotoxy(22,6);
			printf("Cliente: %s",aux->cliente);
			gotoxy(22,8);
			printf("Fecha: %d / %s / %d",aux->fecha.dia,aux->fecha.mes,aux->fecha.anio);
			int t=10;
			
			gotoxy(20,10);
			printf("Mano de obra");
			
			for(int i=0;i<aux->tam_manoObra;i++){
				quitarSubguiones(aux->manoObra[i].descripcion);
				gotoxy(12,(i+1)+12);	
				printf("%d. %s ",i+1,aux->manoObra[i].descripcion);
					gotoxy(70,(i+1)+12);	
				printf("%.2f", aux->manoObra[i].precio);
				t=(i+1)+12;
			}
			gotoxy(20,t+2);
			printf("Total mano de obra: ");
			gotoxy(74,t+2);
			printf("%.2f",aux->T_MO);
			
			t=t+5;
			gotoxy(20,t);
			printf("Materiales");
			t=t+2;
			for(int i=0;i<aux->tam_material;i++){
				quitarSubguiones(aux->materiales[i].descripcion);
				gotoxy(12,t);	
				printf("%d. %s ",i+1,aux->materiales[i].descripcion);
					gotoxy(70,t);	
				printf("%.2f", aux->materiales[i].precio);
				t=1+t;
			}
			
			gotoxy(12,t+2);
			printf("Total Materiales: ");
			gotoxy(74,t+2);
			printf("%.2f",aux->T_MAT);
			
				gotoxy(12,47);
			printf("Total Presupuesto ");
			gotoxy(70,47);
			printf("%.2f ",aux->total);									
						
}



void recorreListaYMuestra(Nodo *Lista){
		if(Lista ==NULL)
	{
	gotoxy(1,1);	
		printf("No hay presupuestos");
		return;		
	}
	Nodo *aux=Lista;//se guarda la lista en un auxiliar para recorrerla
	system("cls");
	

		while(aux!=NULL)//recorre hasta que su siguiente sea nulo
		{
			mostrarDatos(aux);
			getch();
			aux=aux->sig;
		
		}
	
	
}

void bucarPresupuesto(Nodo *Lista, int code){
	
	if(Lista ==NULL)
	{
	gotoxy(1,1);	
		printf("No hay presupuestos");
		return;		
	}
	Nodo *aux=Lista;//se guarda la lista en un auxiliar para recorrerla
	system("cls");	
	bool encontro=false;
		while(aux!=NULL)//recorre hasta que su siguiente sea nulo
		{
			if(aux->codigo_unico==code){
				mostrarDatos(aux);
						encontro=true;		
			}			
			aux=aux->sig;		
		}
		if(!encontro )
		{
				gotoxy(1,1);	
		printf("Presupuesto no encontrado");
		}
		getch();
}

//Ficheros

void resgitraDetallesManoObra(Nodo *Datos){
	int i=0;
	char nomb[30]="DetallesManoObra.txt";
	FILE *fp;
if((fp=fopen(nomb,"a+"))!=NULL){
	fprintf(fp,"%d\n",Datos->codigo_unico);
	while(Datos->tam_manoObra>i){
		concatenarEspacios(Datos->manoObra[i].descripcion);
			fprintf(fp,"%s\n",Datos->manoObra[i].descripcion);
			fprintf(fp,"%.2f\n",Datos->manoObra[i].precio);
			i++;
		}
	}
	fclose(fp);
}

void resgitraDetallesMateriales(Nodo *Datos){
	int i=0;
	char nomb[30]="DetallesMateriales.txt";
	FILE *fp;
if((fp=fopen(nomb,"a+"))!=NULL){
	fprintf(fp,"%d\n",Datos->codigo_unico);
	while(Datos->tam_material>i){
		concatenarEspacios(Datos->materiales[i].descripcion);
			fprintf(fp,"%s\n",Datos->materiales[i].descripcion);
			fprintf(fp,"%.2f\n",Datos->materiales[i].precio);
			i++;
		}
	}
	fclose(fp);
}

/*
	
	concatenarEspacios(nuevo->codigo_unico);
	concatenarEspacios(nuevo->codigo_unico);
	concatenarEspacios(nuevo->codigo_unico);*/

void escribePresupuesto(Nodo *Datos){
	
	char nomb[20]="Presupuestos.txt";
	FILE *fp;
if((fp=fopen(nomb,"a+"))!=NULL){

	concatenarEspacios(Datos->Nombre_proyecto);
	concatenarEspacios(Datos->cliente);

		fprintf(fp,"%d\n",Datos->codigo_unico);
		fprintf(fp,"%s\n",Datos->Nombre_proyecto);
		fprintf(fp,"%s\n",Datos->cliente);
		fprintf(fp,"%.2f\n",Datos->T_MO);
		fprintf(fp,"%.2f\n",Datos->T_MAT);				
		fprintf(fp,"%.2f\n",Datos->total);		
		fprintf(fp,"%d\n",Datos->fecha.anio);
		fprintf(fp,"%s\n",Datos->fecha.mes);
		fprintf(fp,"%d\n",Datos->fecha.dia);
		fprintf(fp,"MANO_OBRA\n");	
		fprintf(fp,"%d\n",Datos->tam_manoObra);
			resgitraDetallesManoObra(Datos);
		
		fprintf(fp,"MATERIALES\n");		
		fprintf(fp,"%d\n",Datos->tam_material);	
		resgitraDetallesMateriales(Datos);
}
fclose(fp);
	
}

/////////LEER FICHEROS
 


Nodo *leerDetallesMateriales(Nodo *Datos){
	
	int i=0, codeexacto=0;
	char nomb[30]="DetallesMateriales.txt";
	FILE *fp;
	

	if((fp=fopen(nomb,"r"))!=NULL){
		char prueba[20];

	while(!feof(fp)){
	i=0;
		fscanf(fp,"%d",&codeexacto);
			
			
			while(Datos->tam_material > i){
				fscanf(fp,"%s",&Datos->materiales[i].descripcion);
				fscanf(fp,"%f",&Datos->materiales[i].precio);
				i++;				
			}
			
			if(codeexacto==Datos->codigo_unico)
			break;
		}
	
	}	
	fclose(fp);
	return Datos;
}

 Nodo *leerDetallesManoObra(Nodo *Datos){
	
	int i=0, codeexacto=0;
	char nomb[30]="DetallesManoObra.txt";
	FILE *fil;
if((fil=fopen(nomb,"r"))!=NULL){
		char prueba[20];
	while(!feof(fil)){
		i=0;
		fscanf(fil,"%d",&codeexacto);
			while(Datos->tam_manoObra>i){
			
				fscanf(fil,"%s",&Datos->manoObra[i].descripcion);
				fscanf(fil,"%f",&Datos->manoObra[i].precio);
				i++;
				
			}

			if(codeexacto==Datos->codigo_unico)
			break;
		}
		
	
	}	
	fclose(fil);

	return Datos;
}


Nodo *LeerPresupuesto(Nodo *Lista){
	
	char nomb[20]="Presupuestos.txt";
	FILE *fp;
	int i=0;
if((fp=fopen(nomb,"r"))!=NULL){
	char prueba[20];
	
	while(!feof(fp)){
		
		
		Nodo *Datos=Crear_nodo_Vacio();
				
		fscanf(fp,"%d",&Datos->codigo_unico);
		fscanf(fp,"%s",&Datos->Nombre_proyecto);
		fscanf(fp,"%s",&Datos->cliente);
		fscanf(fp,"%f",&Datos->T_MO);
		fscanf(fp,"%f",&Datos->T_MAT);				
		fscanf(fp,"%f",&Datos->total);		
		fscanf(fp,"%d",&Datos->fecha.anio);
		fscanf(fp,"%s",&Datos->fecha.mes);
		fscanf(fp,"%d",&Datos->fecha.dia);
		fscanf(fp,"%s",&prueba);	
		fscanf(fp,"%d",&Datos->tam_manoObra);
		
		Datos=	leerDetallesManoObra(Datos);
			
		fscanf(fp,"%s",&prueba);		
		fscanf(fp,"%d",&Datos->tam_material);	
		Datos= leerDetallesMateriales(Datos);
		
		
	//	mostrarDatos(Datos);
		Lista=agregarDatos(Lista,Datos);
		
		i++;
		if(i == totalPresupuestos)
		break;
		
	}
		fclose(fp);
}




	return Lista ;
}


/////
void escibreTOtal(){
		char nomb[30]="totalPresupuestos.txt";
			FILE *fp;
		if((fp=fopen(nomb,"w"))!=NULL){
			fprintf(fp,"%d",totalPresupuestos);
		}
		
		fclose(fp);
		
}

void leeTotal(){
		char nomb[30]="totalPresupuestos.txt";
			FILE *fp;
		if((fp=fopen(nomb,"r"))!=NULL){
		fscanf(fp,"%d",&totalPresupuestos);
		}else
		
		totalPresupuestos=0;
		fclose(fp);		
}

/// concatenar ESpacios
void concatenarEspacios(char frase[]){
	
	for(int i=0;i<strlen(frase);i++){
		if(frase[i]==' ')
			frase[i]='_';
		
	}		
}

void quitarSubguiones(char frase[]){
	
	for(int i=0;i<strlen(frase);i++){
		if(frase[i]=='_')
			frase[i]=' ';
		
	}		
}
