#include<limits.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Nodo{
	int dato_N;
Nodo *sig;	
	Nodo *atras;
};
Nodo *inicio;//listas simples y doblemente enlazadas
Nodo *Head_D_E;//lista doblemente enlazada
Nodo *Lista_cir;//listas circulares
Nodo *L_C_D_E;//lista circular doblemente enlazadas
//funciones
void Funciones();
void numero_par_impar(int );
void numero_par_impar(int);
void cantidad_de_digitos();
int fibonacci(int );
int hanoi(int );
void mover_torres(int d,int x,int discos_hanoi[][3]);
int factorial(int ); 
//arreglos
void menu_arreglos();
long  potencia (int base , int e);
void registrar_potencia ();

void registrar_pares();
void contar_impares(int[],int);
int primo(int n);
int pop (int A[], int x);
int push(int A[], int x);
void registrar_primos ();
void menu_pilas();
void menu_colas();
int vaciar_pila (int A[], int x);
int  desencolar(int A[],int x);
void presentar_cola(int A[], int x);
//3.4
void registrar_primos ();

//nodos listas
void funcion_nodos();
int Cantidad_Nodos();
void presentar_lista();
void presentar_pila(int A[], int x);
//listas simples 
void menu_listas_simples();
void Nodo_ultimo(int );
void ingresar_nodo_ordenado (int );
void Vaciar_Lista( );
void eliminar_nodo(int);
void  nodo_inicio(int );
void eliminar_inicio_s();
void eliminar_ultimo_s();

//listas dobles
void menu_listas_dobles();
void Nodo_ultimo_doblemente_e(int );
void ingresar_nodo_ordenado_doblemente_E (int );
void  nodo_inicio_doble_e(int );
void eliminar_ultimo_doblem();
void eliminar_nodo_doblemente_Enl(int);

int Cantidad_Nodos_doblemente_Enlazados();
void presentar_lista_Doble();


//listas circulares
void menu_listas_circulares_simples();
void ingresar_dato_l_c_s(int i);
int cantidad_datos_l_c_S();
void ingresar_dato_ordenado_l_c_s (int );
void presentar_lista_circular_simple();
void Vaciar_Lista_c_s(int );
void eliminar_datos_l_c(int,int);


//listas circulares doblemente enlazadas
void menu_listas_circulares_doblemente_enlazada();
void ingresar_dato_l_c_dobles_e(int i);
int cantidad_datos_l_c_dobles_Enlazadas();
void ingresar_dato_ordenado_l_c_dobles_elazadas (int );
void presentar_lista_circular_dobles_enlazada();
void Vaciar_Lista_c_dobles_enlazadas( int );
void eliminar_datos_l_c_dobles_enlazadas(int,int);

//void eliminar_dato-circular_s(int);



//listas circulares doblemente enlazadas


Nodo *Crear_nodo_Vacio()
{
	
 return (struct Nodo *)malloc(sizeof(struct Nodo));

	 
}



int main(){
	int opcion ;
		system("color A5");
	do{
	system("cls");
	printf("Menu\n1. Funciones/ recursivas\n2.Listas \n3. Arreglos \n4.Salir \nOpcion: ");
	scanf("%d",&opcion);
	switch(opcion){
	
	case 1: {
		
		Funciones();
		break;
	}
	case 2:{
		funcion_nodos();
		break;
	}
	case 3:{
		 menu_arreglos();
		break;
	}
	case 4:{
		
		break;
	}
	default:{
		printf("Opcion no valida, ");
		system("pause");
		break;
	}
	}puts("");
}while(opcion!=4);
	getch();
}
//1.funciones
void Funciones(){
	
	int opcion ;
	int num;
	do{system("cls");
	
	printf("Menu--Funciones\n1. Ingrese un numero positivo y determine si es par o impar\n2. Ingrese un numero y determine cuantos digitos tiene\n3.Serie de Fibonacci \n4. Factorial\n5. Hanoi\n6. Regresar al menu anterior\nOpcion: ");
	scanf("%d",&opcion);
	switch(opcion){
	
	case 1: {
	int num;
	do{
	
	printf("\nDigite un numero positivo: ");	
	scanf("%d",&num);
	if(num<0)
	printf("\nEl numero ingresado tiene que ser positivo\n\n");
}while(num<0);
		numero_par_impar(num);
		break;
	}
	case 2:{
		cantidad_de_digitos();
		break;
	}
	case 3:{
		printf("\nDigite la cantidad de numeros que desea imprimir de la serie de fibonacci: ");
		scanf("%d",&num);
		for (int i=0;i<num;i++)		
			printf("%d, ",fibonacci(i));				
		break;
	}
	case 4:{
		printf("\nDigite el numero: ");
		scanf("%d",&num);
		printf("\nEl factorial es: %d",factorial(num));
		break;
	}
	case 5:{
		int discos, mov;
    printf("\t\tTORRES DE HANOI\n");
    do{
	printf("Digite numero de discos: ");
	scanf("%d",&discos);
	if(discos>31 || discos <0)
	printf("\nNumero de discos erroneos, no pueden ser mas de 31 discos\n");
    }while(discos>31 || discos <0);
	printf("Los movimientos necesarios para ordenar los discos en la torre son: %d\n", hanoi(discos));	
	int discos_hanoi[discos][3];
    int g=discos-1;
    int pp=discos;
    
     for(int i=0;i<discos;i++){
						for(int j=0;j<3;j++){
							discos_hanoi[i][j]=0;
		}
	}
    
    for(int i=discos-1;i>=0;i--){											
					discos_hanoi[i][0]=pp;																				
					pp--;
					}
    printf("Torre de hanoi:\n");
    for(int i=0;i<discos;i++){
						for(int j=0;j<3;j++){
							if(discos_hanoi[i][j]==0)
							printf("\t| | |\t");
							else
							printf("\t| %d |\t",discos_hanoi[i][j]);
						}
							printf("\n");
						
					
		}printf("\t  A  \t\t  B  \t\t  C");	
			printf("\n");
		if(discos!=1)
		for(int i=0;i<hanoi(discos);i++){
				printf("\n\tMovimiento %d",i+1);
				
				mover_torres(discos,i+1,discos_hanoi);
				
				printf("\n");
			//	system("pause");
					printf("\n");
		}
		else{
			printf("\n");
			printf("\t| | |\t\t| | |\t\t| %d |\t",discos_hanoi[0][0]);
			printf("\n\t  A  \t\t  B  \t\t  C");	
		}
	
		break;
	}
	case 6:{
		
		break;
	}
	default:{
		printf("\nOpcion incorrecta\n");
		break;
	}
	}
	puts("\n");
	if(opcion!=6)
	system("pause");
	puts("");
}while(opcion!=6);
	
	
}


//1.1 par o impar
void numero_par_impar(int num){
	if(num%2==0)
	printf("\El numero %d es par",num);
	else
	printf("\El numero %d es impar",num);
}

//1.2 Ingrese un numero y determine cuantos digitos tiene
void cantidad_de_digitos(){
int num,i=0;
	printf("\nDigite un numero: ");	
	scanf("%d",&num);
	for(i=0;num >0;i++)
	num=num/10;


	printf("Total de digitos del numero digitado es/son : %d",i);
}

//1.3

int fibonacci(int n)
{
 if (n<2)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}
//1.4 factorial
int factorial(int n) 
{ 
	int r; 
	if (n==1) 
	{ 
		return 1; 
	} 
		r=n*factorial(n-1 ) ; 
	return r  ; 
} 
//1.5 hanoi
int hanoi(int discos)
{
    if(discos==1)
        return 1;
    else
        return 2 * hanoi(discos-1) + 1;
}

void mover_torres(int d,int x,int discos_hanoi[][3]){
	int g=d-1;
	int posicion=d;
	int inicio=(x&x-1)%3;
    int llegada= ((x|x-1)+1)%3;
    
	int cont=0;
	int valLlegada=2;
    for(int k=0;k<3;k++){
    	if(inicio==k && llegada==valLlegada ){
    		int m;
    		for(int i=0;i<d;i++){
				if(discos_hanoi[i][k]!=0){
					m=i;
					break;
				}
			}
			for(int i=0;i<d;i++){	
				if(discos_hanoi[g][valLlegada] ==0 ){
					discos_hanoi[g][valLlegada]=discos_hanoi[m][k];
					discos_hanoi[m][k]=0;
					break;													
				}
				g--;																		
			}
		}
		
		cont ++;
		if(cont%2!=0){
			k--;
		}
		
		valLlegada--;
		if(valLlegada==-1){
				valLlegada=2;
			}
	}
			int a[3]={0,2,1};
	
    	printf("\n");
    	if(d!=1)
    	if(d%2==0){
    		for(int i=0;i<d;i++){
    			for(int j=0;j<3;j++){
					if(discos_hanoi[i][a[j]]==0)
						printf("\t| | |\t");
					else
						printf("\t| %d |\t",discos_hanoi[i][a[j]]);
				}
				printf("\n");
			}
		}else{					
			for(int i=0;i<d;i++){
				for(int j=0;j<3;j++){
					if(discos_hanoi[i][j]==0)
						printf("\t| | |\t");
					else
						printf("\t| %d |\t",discos_hanoi[i][j]);
				}						
				printf("\n");					
			}		
		}
	printf("\t  A  \t\t  B  \t\t  C");	
}
//2. NODOS
void funcion_nodos(){
	int opcion ;
	do{system("cls");
	printf("Menu--Listas\n1. Listas simplemente enlazadas\n2.Listas doblemente enlazadas \n3.Listas circulares simples\n4.Listas circulares doblemente enlazadas \n5. Regresar al menu anterior\nOpcion: ");
		scanf("%d",&opcion);
		switch(opcion){
	
	case 1: {
		menu_listas_simples();
	
		break;
	}
	case 2:{
	menu_listas_dobles();
		break;
	}
	case 3:{menu_listas_circulares_simples();
		break;
	}
	case 4:{
		menu_listas_circulares_doblemente_enlazada();	
		break;
	}
	case 5:{
		
		break;
	}
	default:{
		printf("Opcion no valida, ");
		
		break;
	}

	}
	puts("");		
	if(opcion!=5)
	system("pause");
}while(opcion!=5);
	
}

//2.1 listas simples
void menu_listas_simples(){
	int opcion ;
	int num;
	do{
system("cls");
	printf("Menu--Lista simplemente enlazada\n1. Insertar al inicio\n2. Insertar al final  \n3. Insertar ordenada\n4. Contar  nodos en la lista\n5. Presentar lista\n6. Eliminar al inicio\n7.Eliminar al final \n8. Eliminar intermedio\n9. Vaciar lista\n10. Regresar al menu anterior\nOpcion: ");
	scanf("%d",&opcion);
	switch(opcion){
	
	case 1: {
		printf("Digite un numero: ");
		scanf("%d",&num);
		nodo_inicio(num);
		break;
	}
	case 2:{
	printf("Digite un numero: ");
		 scanf("%d",&num);
		
		Nodo_ultimo(num);
		
		break;
	}
	case 3:{
		printf("Digite un numero: ");
		 scanf("%d",&num);
		  if(inicio==NULL)
		ingresar_nodo_ordenado(num);
		else{
			
			if(num<inicio->dato_N)
			nodo_inicio(num);
			else
		ingresar_nodo_ordenado(num);	
		}
		
		break;
	}
	case 4:{
		if(inicio!=NULL)
		printf("\n\nHay %d nodos en la lista",Cantidad_Nodos());
		else printf("\n\nLa lista esta vacia\n");
		break;
	}
		case 5: {
			if(inicio!=NULL)
		presentar_lista();
	else
	printf("\n\nLista vacia\n\n");	
		break;
	}
	case 6:{
	 eliminar_inicio_s();

		break;
	}
	case 7:{
	if(Cantidad_Nodos()==1)
	 eliminar_inicio_s();
 else
 eliminar_ultimo_s();
 
		break;
	}
	case 8:{
		int bandera=0;
		if(inicio!=NULL){
			if(Cantidad_Nodos()==1)
			eliminar_inicio_s();
			else{
			presentar_lista();
			do{bandera=0;
			
		printf("\nDigite la posicion de  numero que desea eliminar eliminar : ");
		 scanf("%d",&num);
		 if(Cantidad_Nodos()<num || num <0){
		 	bandera=1;
		 	 printf("\nPosicion fuera del rango\n");
		 }
		
		 }while(bandera==1 );
		 if(Cantidad_Nodos()==num)
		 eliminar_ultimo_s();
		 if(num==1)
		 eliminar_inicio_s();
		 else
		 eliminar_nodo(num);
	}
}
	else
	printf("\n\nLista vacia\n\n");
		break;
	}
		case 9: {
		
	Vaciar_Lista();
		break;
	}
		case 10: {
		if(inicio!=NULL){
				 printf("\n\n\tDesea eliminar los datos de la lista?\nDigite 1 si esta de acuerdo, de lo contrario digite otro numero.");
	 scanf("%d",&num);
	 if(num==1)
	Vaciar_Lista();
			
		}
		
	
		break;
	}

	default:{
		printf("Opcion no valida, ");
		system("pause");
	//	getch();
		break;
	}
	}puts("");
	if(opcion!=10)
	system("pause");
}while(opcion!=10);
}



//2.1.1
void nodo_inicio(int num)
{
	Nodo *nuevo=Crear_nodo_Vacio();
	nuevo->dato_N=num;
	if(inicio==NULL)
	{
	inicio=nuevo;
	nuevo->sig=NULL;
	//fin=nuevo;
//fin->sig=NULL;
}
	else{
		nuevo->sig=inicio;
		inicio=nuevo;		
	}
}
//2.1.2
void Nodo_ultimo(int num)
{
	Nodo *nuevo=Crear_nodo_Vacio();
	nuevo->dato_N=num;
	if(inicio==NULL)
	{
	inicio=nuevo;
		nuevo->sig=NULL;
	//fin=nuevo;
	}
	else{	
	Nodo *aux=inicio;
	while(aux->sig!=NULL)
	{
		aux=aux->sig;
	}
	aux->sig=nuevo;
	nuevo->sig=NULL;
	/*
	fin->sig=nuevo;
	fin=nuevo;
	fin->sig=NULL;
*/
}
}

//2.1.3 Lista ordenada
void ingresar_nodo_ordenado(int num){
	
		Nodo *nuevo=Crear_nodo_Vacio();
		Nodo *aux=inicio;
		Nodo *ant=Crear_nodo_Vacio();
	nuevo->dato_N=num;
	if(inicio==NULL)
	{
	inicio=nuevo;
	nuevo->sig=NULL;}
	else{	
	while(aux!=NULL){
		if(num<aux->dato_N)
		break;
		ant=aux;
		aux=aux->sig;		
	}
	nuevo->sig=aux;
	ant->sig=nuevo;
	
}
	
}

//2.1.4
int Cantidad_Nodos()
{
	int n;
	struct Nodo *cont=(struct Nodo*)malloc(sizeof(struct Nodo));
	cont=inicio;
	
	
		while(cont!=NULL)
		{
		n++;
		 cont=cont->sig;
		}

	return n;
}

//2.1.5
void presentar_lista(){
	Nodo *aux=inicio;
	
	int i=0;
	while(aux!=NULL)
	{i++;
		printf("\nDato %d = %d",i,aux->dato_N);
		aux=aux->sig;
	}
}
//2.1.6
void eliminar_inicio_s(){
	if(inicio!=NULL)
	{
	Nodo *aux=inicio;
	inicio=inicio->sig;
		free(aux);
		printf("\nSe ha eliminado el numero");
	}else
	printf("\n\nLista vacia\n\n");
}


//2.1.7

void eliminar_ultimo_s(){
	if(inicio!=NULL)
	{
	Nodo *aux=inicio;
	Nodo *ant=NULL;
	while(aux->sig!=NULL){
		ant=aux;
		aux=aux->sig;
						
	}

	free(aux);
		ant->sig=NULL;
		printf("\nSe ha eliminado el numero");
		}else
	printf("\n\nLista vacia\n\n");
}
//2.1.8
void eliminar_nodo(int dato){
	Nodo *aux=inicio;
		Nodo *ant=(struct Nodo*)malloc(sizeof(struct Nodo));;
		int cont=1;
	while(aux->sig!=NULL)
	{
	
	if(dato==cont)
	break;
	cont++;

	ant=aux;
	aux=aux->sig;			
	}											
				ant->sig=aux->sig;
				free(aux);							
			printf("\nElemento eliminado con exito\n");
		
}

//2.1.9
void Vaciar_Lista( )
{
	struct	Nodo *vaciar=(struct Nodo*)malloc(sizeof(struct Nodo));
	vaciar=inicio;
	if(inicio!=NULL)
	{
	do{
			vaciar=inicio;
		inicio=vaciar->sig;
		free(vaciar);
	}	while(inicio!=NULL );
	printf("\n\nLista vaciada\n\n");
	}	

	else
		printf("\n\nla lista esta vacia\n\n");

}




void eliminar_inicio_doblemente_e();
//2.2 LISTAS DOBLES

void menu_listas_dobles(){
	int opcion ;
	int num;
	do{
system("cls");
	printf("Menu--LISTA DOBLEMENTE ENLAZADA\n1. Insertar al inicio\n2. Insertar al final  \n3. Insertar ordenada\n4. Contar  nodos en la lista\n5. Presentar lista\n6. Eliminar al inicio\n7.Eliminar al final \n8. Eliminar intermedio\n9. Vaciar lista\n10. Regresar al menu anterior\nOpcion: ");
	scanf("%d",&opcion);
	switch(opcion){
	
	case 1: {
		printf("Digite un numero: ");
		scanf("%d",&num);
		nodo_inicio_doble_e(num);
		//nodo_inicio(num);
		break;
	}
	case 2:{
	printf("Digite un numero: ");
		 scanf("%d",&num);
		 Nodo_ultimo_doblemente_e(num);
		break;
	}
	case 3:{
		printf("Digite un numero: ");
		 scanf("%d",&num);
		 if(Head_D_E!=NULL){
		 	if(Head_D_E->dato_N>num)
		 nodo_inicio_doble_e(num);
		 else
		ingresar_nodo_ordenado_doblemente_E(num);		 	
		 }
		 else
		 ingresar_nodo_ordenado_doblemente_E(num);			
		break;
	}
	case 4:{
		if(Head_D_E!=NULL)
		printf("\n\nHay %d nodos en la lista",Cantidad_Nodos_doblemente_Enlazados());
		else printf("\n\nLa lista esta vacia\n");
		
		break;
	}
		case 5: {
			if(Head_D_E!=NULL)
		presentar_lista_Doble();
	else
	printf("\n\nLista vacia\n\n");	
		break;
	}
  case 6:{
	 eliminar_inicio_doblemente_e();
		break;
	}
	case 7:{
	if(Cantidad_Nodos_doblemente_Enlazados()==1)
	 eliminar_inicio_doblemente_e();
 else
 eliminar_ultimo_doblem();
 
		break;
	}
	case 8:{
		int tot_nodos=Cantidad_Nodos_doblemente_Enlazados();
		if(Head_D_E!=NULL){
			if(Cantidad_Nodos_doblemente_Enlazados()==1)
			eliminar_inicio_doblemente_e();
			else{
			presentar_lista_Doble();
			do{
			
		printf("\nDigite la posicion de  numero que desea eliminar eliminar : ");
		 scanf("%d",&num);
		 if(tot_nodos<num || num <0)
		 printf("\nPosicion fuera del rango\n");
		 }while(tot_nodos<num || num<0);
		
		 if(num==1)
		 eliminar_inicio_doblemente_e();
		 else{		 	
		 	 if(Cantidad_Nodos_doblemente_Enlazados()==num)
		 eliminar_ultimo_doblem();
		 else
		 eliminar_nodo_doblemente_Enl(num);
		 }
		
	}
}
	else
	printf("\n\nLista vacia\n\n");
		break;
	}
		case 9: {
		
	Vaciar_Lista();
		break;
	}
		case 10: {
		
	
		break;
	}

	default:{
		printf("Opcion no valida, ");
		system("pause");
		break;
	}
	}puts("");	
	if(opcion!=10)
	system("pause");
}while(opcion!=10);
}




//2.2.1
void  nodo_inicio_doble_e(int num){
	Nodo *nuevo=Crear_nodo_Vacio();
	nuevo->dato_N=num;
	if(Head_D_E==NULL)
	{
	Head_D_E=nuevo;
	nuevo->sig=NULL;	
	Head_D_E->atras=NULL;
	}
	else{
		nuevo->sig=Head_D_E;
		Head_D_E->atras=nuevo;
		Head_D_E=nuevo;		
		Head_D_E->atras=NULL;
	}
	
	
}

//2.2.2
void Nodo_ultimo_doblemente_e(int num)
{
		Nodo *nuevo=Crear_nodo_Vacio();
	nuevo->dato_N=num;
	if(Head_D_E==NULL)
	{
	Head_D_E=nuevo;
		nuevo->sig=NULL;
	Head_D_E->atras=NULL;
	}
	else{	
	Nodo *aux=Head_D_E;
	while(aux->sig!=NULL)
	{
		aux=aux->sig;
	}
	aux->sig=nuevo;
	nuevo->atras=aux;
	nuevo->sig=NULL;
	
}
}


//2.2.3 Lista ordenada doblemente enlazada
void ingresar_nodo_ordenado_doblemente_E (int num){	
		Nodo *nuevo=Crear_nodo_Vacio();
		Nodo *aux=Head_D_E;
		
	nuevo->dato_N=num;
	if(Head_D_E==NULL)
	{
	Head_D_E=nuevo;
	nuevo->sig=NULL;}
	else{	
	while(aux!=NULL){
		if(num<aux->dato_N)
		break;		
		aux=aux->sig;
			
	}
	if(aux!=NULL && aux->atras!=NULL){
	nuevo->sig=aux;
	aux->atras->sig=nuevo;
	nuevo->atras=aux->atras;
	aux->atras=nuevo;		
	}
	if(aux==NULL)
	Nodo_ultimo_doblemente_e(num);
	

}
	
}

//2.2.4
int Cantidad_Nodos_doblemente_Enlazados()
{
	int n;
	struct Nodo *cont=(struct Nodo*)malloc(sizeof(struct Nodo));
	cont=Head_D_E;
	
	
		while(cont!=NULL)
		{
		n++;
		 cont=cont->sig;
		}

	return n;
}
//2.2.5 PRESENAT DATOS
void presentar_lista_Doble(){
	Nodo *aux=Head_D_E;
	
	int i=0;
	while(aux!=NULL)
	{i++;
		printf("\nDato %d = %d",i,aux->dato_N);
		aux=aux->sig;
	}
}	

//2.2.6 Eliminar iniciio
void eliminar_inicio_doblemente_e(){
	if(Head_D_E!=NULL)
	{
	Nodo *aux=Head_D_E;
	Head_D_E=Head_D_E->sig;
		free(aux);
		printf("\nSe ha eliminado el numero");
	}else
	printf("\n\nLista vacia\n\n");
}




//2.2.7

void eliminar_ultimo_doblem(){
	if(Head_D_E!=NULL)
	{
	Nodo *aux=Head_D_E;	
	while(aux->sig!=NULL){	
		aux=aux->sig;						
	}
	Nodo *anular_sig=aux->atras;
	
	free(aux);
	anular_sig->sig=NULL;
		printf("\nSe ha eliminado el numero");
		}else
	printf("\n\nLista vacia\n\n");
}

//2.2.8
void eliminar_nodo_doblemente_Enl(int dato){
	Nodo *aux=Head_D_E;
		int cont=1;
	while(aux->sig!=NULL)
	{
	
	if(dato==cont)
	break;
	cont++;
	aux=aux->sig;			
	}											
				aux->atras->sig=aux->sig;
				aux->sig->atras=aux->atras;
				free(aux);							
			printf("\nElemento eliminado con exito\n");
		
}



void menu_listas_circulares_simples(){
	
	int opcion ;
	int num;
	do{
		system("cls");
		printf("Menu\tLISTA CIRCULAR SIMPLEMENTE ENLAZADA\n1. Ingresar dato a la lista circular\n2. Contar  nodos en la lista\n3. Presentar lista\n4. Eliminar dato\n5. Vaciar lista\n6. Regresar al menu anterior\nOpcion: ");
		scanf("%d",&opcion);
switch(opcion){
	
	case 1: {
		printf("Digite un numero: ");
		scanf("%d",&num);
		ingresar_dato_l_c_s(num);
		break;
	}
	
		case 2:{
			if(Lista_cir!=NULL)
			printf("\nLa cantidad de datos es: %d",  cantidad_datos_l_c_S());
	else
	printf("\nLista vacia\n");
		break;
	}
	case 3:{
		 presentar_lista_circular_simple();
		break;
	}
	case 4:{
			if(Lista_cir!=NULL){
				presentar_lista_circular_simple();
				printf("\nDigite el dato de la lista el  cual desea eliminar\n");
				scanf("%d",&num);
				eliminar_datos_l_c(num,cantidad_datos_l_c_S() );
			}else
			printf("\nLista vacia\n");
		 
		break;
	}
		case 5: {
		Vaciar_Lista_c_s(cantidad_datos_l_c_S() );	
	}
  case 6:{
	 if(Lista_cir!=NULL){
	  printf("\n\n\tDesea eliminar los datos de la lista?\nDigite 1 si esta de acuerdo, de lo contrario digite otro numero.");
	 scanf("%d",&num);
	 if(num==1)
	 Vaciar_Lista_c_s( cantidad_datos_l_c_S());}
		break;
	}
	
	default:{
		printf("Opcion no valida, ");			
		break;
	}
	}puts("");
		if(opcion!=6)
	system("pause");
}while(opcion!=6);
	
}

//2.3.1
void ingresar_dato_l_c_s(int i){	
	Nodo *nuevo=Crear_nodo_Vacio();
	nuevo->dato_N=i;
	if(Lista_cir==NULL){
		Lista_cir=nuevo;
		Lista_cir->sig=Lista_cir;
	}else
	{nuevo->sig=Lista_cir->sig;
		Lista_cir->sig=nuevo;
		
		Lista_cir=nuevo;
	}
	
}

//2.3.2
int cantidad_datos_l_c_S(){
	int cont =1;
	Nodo *aux=Lista_cir;
	while(aux->sig!=Lista_cir){
		cont ++;
		aux=aux->sig;
	}
	return cont;
}

//2.3.3
void presentar_lista_circular_simple(){
	if(Lista_cir!=NULL){
		
	Nodo *aux=Lista_cir;
	while(aux->sig!=Lista_cir)
	{
		printf("\nDato: %d",aux->dato_N);
		
		aux=aux->sig;
	}
	printf("\nDato: %d",aux->dato_N);	
	}else
	printf("\nLa lista esta vacia\n");		
}
//2.3.4
void Vaciar_Lista_c_s(int pos){
	
	if(Lista_cir!=NULL){
		
		Nodo *aux=Lista_cir;int i=1;
		Nodo *ant=Lista_cir;
		
		if(pos==1){
			free(Lista_cir);
			Lista_cir=NULL;
		}
		else{
			if(pos==2){
			Lista_cir=Lista_cir->sig;	
				free(aux);
				free(Lista_cir);
				Lista_cir=NULL;
			}else{
		
		
		
		while(ant->sig!=Lista_cir){
		
		ant=ant->sig;
		}
		
		while(aux->sig!=Lista_cir)
		{
		aux=Lista_cir;
				
			Lista_cir=Lista_cir->sig;
			ant->sig=Lista_cir;	
			free(aux);
		}
		Lista_cir=NULL;
	}}
		printf("\nLista vaciada correctamente\n");
	}else 
	printf("\nLa lista esta vacia\n");					
}
//2.3.5
void eliminar_datos_l_c(int dato,int tot_lcs ){
		Nodo *aux=Lista_cir;
	while(aux->sig!=Lista_cir){
		if(aux->sig->dato_N==dato)
		break;
		aux=aux->sig;
	}
	if( tot_lcs == 1 && aux->dato_N==dato){
		free(Lista_cir);
		Lista_cir=NULL;
	}else{
	
		if(aux->sig->dato_N==dato){
			
			Nodo *ant=aux;
			aux=aux->sig;
			ant->sig=aux->sig;
			
			if(aux==Lista_cir)
			Lista_cir=ant;
			free(aux);
			printf("\nDato eiminado correctamente\n");
		}	
		else
		printf("\nDato no encontrado\n");		}
	}

//2.4
void menu_listas_circulares_doblemente_enlazada(){
	
	int opcion ;
	int num;
	do{
		system("cls");
		printf("Menu\tLISTA CIRCULAR DOBLEMENTE ENLAZADA \n1. Ingresar dato a la lista circular\n2. Contar datos en la lista\n3. Presentar lista\n4. Eliminar dato\n5. Vaciar lista\n6. Regresar al menu anterior\nOpcion: ");
		scanf("%d",&opcion);
switch(opcion){
	
	case 1: {
		printf("Digite un numero: ");
		scanf("%d",&num);
		ingresar_dato_l_c_dobles_e(num);
		break;
	}
	
		case 2:{
			if(L_C_D_E!=NULL)
			printf("\nLa cantidad de datos es: %d",  cantidad_datos_l_c_dobles_Enlazadas());
	else
	printf("\nLista vacia\n");
		break;
	}
	case 3:{
		 presentar_lista_circular_dobles_enlazada();
		break;
	}
	case 4:{
			if(L_C_D_E!=NULL){
				presentar_lista_circular_dobles_enlazada();
				printf("\nDigite el dato de la lista el  cual desea eliminar\n");
				scanf("%d",&num);
				eliminar_datos_l_c_dobles_enlazadas(num,cantidad_datos_l_c_dobles_Enlazadas());
			}else
			printf("\nLista vacia\n");
		 
		break;
	}
		case 5: {
		Vaciar_Lista_c_dobles_enlazadas(cantidad_datos_l_c_dobles_Enlazadas() );	
	}
  case 6:{
  	if(L_C_D_E!=NULL){
	 printf("\n\n\tDesea eliminar los datos de la lista?\nDigite 1 si esta de acuerdo, de lo contrario digite otro numero.");
	 scanf("%d",&num);
	 if(num==1)
	 Vaciar_Lista_c_dobles_enlazadas(cantidad_datos_l_c_dobles_Enlazadas() );	}
		break;
	}
	
	default:{
		printf("Opcion no valida, ");			
		break;
	}
	}puts("");
		if(opcion!=6)
	system("pause");
}while(opcion!=6);
	
}
//2.4.1
void ingresar_dato_l_c_dobles_e(int i){
	
	Nodo *nuevo=Crear_nodo_Vacio();
	nuevo->dato_N=i;
	if(L_C_D_E==NULL){
		L_C_D_E=nuevo;
		L_C_D_E->sig=L_C_D_E;
		L_C_D_E->atras=L_C_D_E;
	}else
	{nuevo->sig=L_C_D_E->sig;
//	L_C_D_E->atras=nuevo;	
		L_C_D_E->sig->atras=nuevo;
		L_C_D_E->sig=nuevo;
		nuevo->atras=L_C_D_E;
		L_C_D_E=nuevo;
	}
	
}



//2.4.2

int cantidad_datos_l_c_dobles_Enlazadas()
{

	int cont =1;
	Nodo *aux=L_C_D_E;
	while(aux->sig!=L_C_D_E){
		cont ++;
		aux=aux->sig;
	}
	return cont;
}

//2.4.3

void presentar_lista_circular_dobles_enlazada(){
	if(L_C_D_E!=NULL){
		
	Nodo *aux=L_C_D_E;
	while(aux->sig!=L_C_D_E)
	{
		printf("\nDato: %d",aux->dato_N);
		
		aux=aux->sig;
	}
	printf("\nDato: %d",aux->dato_N);	
	}else
	printf("\nLa lista esta vacia\n");		
}

//2.4.5
void Vaciar_Lista_c_dobles_enlazadas(int pos){
	
	if(L_C_D_E!=NULL){
		
		
		
		Nodo *aux=L_C_D_E;
		Nodo *ant=L_C_D_E;
		
		if(pos==1){
			free(L_C_D_E);
			L_C_D_E=NULL;
		}
		else{
			if(pos==2){
			L_C_D_E=L_C_D_E->sig;	
				free(aux);
				free(L_C_D_E);
				L_C_D_E=NULL;
			}else{
					while(ant->sig!=L_C_D_E){				
		ant=ant->sig;
		}
		
		while(aux->sig!=L_C_D_E)
		{
		aux=L_C_D_E;
				
			L_C_D_E=L_C_D_E->sig;
			ant->sig=L_C_D_E;	
			free(aux);
		}
		L_C_D_E=NULL;
				
			}
			
		}
	
		printf("\nLista vaciada correctamente\n");
	}else 
	printf("\nLa lista esta vacia\n");					
}


//2.4.4

void eliminar_datos_l_c_dobles_enlazadas(int dato, int tot_lc_d){
		Nodo *aux=L_C_D_E;
	while(aux->sig!=L_C_D_E){
		if(aux->sig->dato_N==dato)
		break;
		aux=aux->sig;
	}
	if(tot_lc_d==1 && aux->dato_N==dato){
		free(L_C_D_E);
		L_C_D_E=NULL;
	}else {
	
		if(aux->sig->dato_N==dato){					
			aux=aux->sig;
			aux->atras->sig=aux->sig;
			aux->sig->atras=aux->atras;
			if(aux==L_C_D_E)
			L_C_D_E=aux->atras;
			free(aux);
			printf("\nDato eiminado correctamente\n");
		}	
		else
		printf("\nDato no encontrado\n");		}
	}
	
//3 ARREGLOS
void menu_pilas();
void menu_colas();
void menu_arreglos(){
	
	int opcion ;
	do{system("cls");
	printf("Menu--ARREGLOS\n1. Permita almacenar en un arreglo la potencia del indice del arreglo de un arreglo de 50\n");
	printf("2. Resolver una funcion que me permita registrar 100 numeros pares positivos en un arreglo\n");
	printf("3. Realizar una funcion q me permita contar cuantos numeros impares tiene un arreglo\n");
	printf("4. Funcion que me permita guardar los 100 primeros numeros primos \n");
	printf("5. Pilas\n");
	printf("6. Colas \n7. Regresar al menu anterior");
	printf("\nOpcion: ");
		scanf("%d",&opcion);
		switch(opcion){
	
	case 1: {
		registrar_potencia ();
	
		break;
	}
	case 2:{
	registrar_pares();
		break;
	}
	case 3:{
		int tamanio;
	printf("\n\nCuantos numeros: ");scanf("%d",&tamanio);
	int A[tamanio];
	for(int i=0;tamanio>i;i++){
		printf("\nDigite numero %d: ",i+1);
		scanf("%d",&A[i]);
		
	}
	contar_impares(A,tamanio);
	
		break;
	}
	case 4:{
		registrar_primos();
		break;
	}
	case 5:{
		menu_pilas();
		break;
	}
	case 6:{
		menu_colas();
		
		break;
	}
	case 7:{
		
		break;
	}
	default:{
		printf("Opcion no valida, ");
	
		break;
	}
	}puts("");
		system("pause");
}while(opcion!=7);
}

//3.1



void registrar_potencia ()
{
	int i;
	long  A[50];
	for (i=0;i<50;i++)	
{  
A[i]=potencia(i,i);
		printf("Potencia de %d a la %d: %d\n",i,i,A[i]);
}}
long potencia (int base , int e)
{
	long p=1;
	for(int x=0; x<e; x++)
		p=p*base;
	return p;
}

//3.2
void registrar_pares ()
{
	int  A[100], y=0;
	for(int i=0;i<100;i++)
	{
		if(y%2==0)
		A[i]=y;
		else i--;
		y++;
	}
	for(int i=0;i<100;i++)
	printf("\nNumero %d: %d",i+1,A[i]);
}
//3.3
void contar_impares (int A[],int t)
{
	int y=0;
	for(int i=0;i<t;i++)
	{
		if(A[i]%2!=0)
		{
		y++;
	}
	}
	
	printf("\nHay \"%d\" numeros impares ingresados\n\n" , y);
}

//3.4
void registrar_primos ()
{
	int A[100], d,arreglo_t=0;
	int pnum=2,n=2,es_primo;
	//for(int i=0;i<100;i++)
	 while (arreglo_t <100) 
	 {

        /* determinar si n es primo */
        es_primo = 1;
        for (d = 2; d < n; ++d) {
            if (n % d == 0) {
                es_primo = 0;
                break;
            }
        }

        /* mostrar el numero
         * y actualizar el contador */
        if (es_primo) {
            A[arreglo_t]=n;
            arreglo_t++;
        }
        n++;
    }

	for(int i=0;i<100;i++){
		printf("\n%d) Numero primo : %d",i+1 ,A[i]);
	}


}

int primo(int n)
{
	int p, c=0;
for(int i=1;i<=n;i++)
	if (n%1==0)
		c++;
return ((c>2)?0:1);
}


void menu_pilas(){
	int opcion;
	int x=-1;
	int cima;
	printf("\n\nDefina la cima de la pila: ");
	scanf("%d",&cima);
	int A[cima];
	do{
	system("cls");
	printf("\n1. Apilar \n2. Desapilar\n3. Presentar datos\n4. Vaciar pila\n5. Regresar al menu anterior\nOpcion: ");
	scanf("%d",&opcion);
	switch(opcion){
		case 1:{
			if(x==cima-1)
			printf("\nPila llena\n");
			else x=push(A, x);
			break;
		}
		case 2:{
			if(x<0)
			printf("\nNo hay datos en la pila");
			else
			x=pop(A,x);
			break;
		}
		case 3:{
			if(x>=0)
			presentar_pila(A,x);
			else
			printf("\nLa pila esta vacia\n");
			break;
		}
		case 4:{
			if(x>=0)
			{x=-1;
			printf("\nPila vaciada\n");
			}
						else
			printf("\nPila esta vacia\n");
			break;
		}
		case 5:{
			
			break;
		}
		default: {
			printf("\nOpcion equivocada");
			break;
		}
	}
	puts("");
	puts("");
	if(opcion!=5)
	system("pause");
}while(opcion!=5);
}



/*  agregar pila */

int  push(int A[], int x){
		x++;
	printf("Agrege el numero de la pila: ");
	scanf("%d",&A[x]);

return x;
}
//Desapilar
int pop (int A[], int x){
	A[x]=0;
	x--;
return x;	
}
void presentar_pila(int A[], int x){
	for(int i=x;i>=0;i--){
		
		printf("\nDato: %d",A[i]);
	}
	
}


int agregar_cola(int A[],int x){
	x++;
	printf("Agrege el numero de la cola: ");
	scanf("%d",&A[x]);
	
	return x;
}



void menu_colas(){
		int opcion;
	int x=-1;
	int cola_;
	printf("\n\nDefina la de datos que desea almacenar en la cola: ");
	scanf("%d",&cola_);
	int A[cola_];
	
	do{
	system("cls");
	printf("\n1. Agregar cola \n2. Desencolar\n3. Presentar datos\n4. Vaciar cola\n5. Regresar al menu anterior\nOpcion: ");
	scanf("%d",&opcion);
	switch(opcion){
		case 1:{
			if(x==cola_-1)
			printf("\nCola llena\n");
			else 
			x=agregar_cola(A, x);
			break;
		}
		case 2:{
			if(x<0)
			printf("\nNo hay datos en la cola");
			else
			x=desencolar(A,x);
			break;
		}
		case 3:{
			if(x>=0)
			presentar_cola(A,x);
			else
			printf("\nLa cola esta vacia\n");
			break;
		}
		case 4:{
			if(x>=0)
	
		x=-1;
						else
			printf("\nLa cola esta vacia\n");
			break;
		}
		case 5:{
			
			break;
		}
		default: {
			printf("\nOpcion equivocada");
			break;
		}
	}
	puts("");
	puts("");
	if(opcion!=5)
	system("pause");
}while(opcion!=5);
	
}

int  desencolar(int A[],int x){
	int aux=0;
	for(int i=0;i<=x;i++){
		A[i]=A[i+1];
		
	}
	x--;
	return x;
}


void presentar_cola(int A[], int x){
	for(int i=0;i<=x;i++){
		
		printf("\nDato: %d",A[i]);
	}
	
}

