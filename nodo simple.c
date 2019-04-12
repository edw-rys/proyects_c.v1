#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int edad, ci;
	char nombre[10];
	float nota;
	
}Estudiante;
 struct Nodo // Se crea el tipo de dato Nodo
{
	int m;
 Estudiante e;
struct Nodo *sig;
};

struct Nodo *ini=NULL;
struct Nodo *ultimo=NULL;

struct Nodo *Crea_Nodo_Vacio(struct Nodo *); // Crea un nodo vacío  
void Asignar_Datos_Nodo(struct Nodo *); 
void Mostrar_Nodo(struct Nodo *); // imprime un nodo
int Cantidad_Nodos();
struct Nodo *Agregar_Nodo_Final(struct Nodo *);
void Agregar_Nodo_Inicio(struct Nodo *N);
void Recorre_Lista();// imprime todos los nodos
void *Vaciar_Lista();
void *Eliminar_Nodo(int );
void Muestra_Opciones();  // Muestra el menú del sistema 
int main()
{
Muestra_Opciones();
		
	getch ();
}

struct Nodo *Crea_Nodo_Vacio(struct Nodo *N)
{	
	 N=(struct Nodo *)malloc(sizeof(struct Nodo));
// Agregar_Nodo_Final(ini, N);
return N;

}

void Muestra_Opciones(){
	int Z,VVV;
	struct Nodo *N;
	int num;
	do{
	
	printf("*************** MANEJO DE UNA LISTA ******************\n");
 	printf("*\t\t\t\t\t\t\t*\n");
 		printf("* Agregar Nodo al Final ..................1 *\n");
 		printf("* Agregar Nodo al Inicio .................2 *\n");
 		printf("* Nodos en la Lista ......................3 *\n");
 		printf("* Mostrar Lista ......................... 4 *\n");
 		printf("* Eliminar Nodo ..........................5 *\n");
 		printf("* Eliminar Nodo ..........................5 *\n");
 		printf("* Vaciar Lista ...........................6 *\n");
 		printf("* Finalizar ..............................7 *\nOPCION:");
 		scanf("%d",&num);
 		
 		switch(num)
 		{
 			case 1:{
 			
 N=	Crea_Nodo_Vacio(N);
 	    N=Agregar_Nodo_Final(N);
 	    
 	    
 			Mostrar_Nodo( N);
			 	//system("cls");
				break;
			 }
 			case 2:{
 				N=	Crea_Nodo_Vacio(N);
 			Agregar_Nodo_Inicio( N);
 			
 			Mostrar_Nodo( N);
				break;
			 }
 			case 3:{
 			printf("\nHay %d nodos\n",	Cantidad_Nodos());
				break;
			 }
 			case 4:{
 					Recorre_Lista();
				break;
			 }
		 
		 case 5:{
		 	
		 printf("\nQue nodo desea borrar,seleccione el numero de cedula para borrar datos de ese nodo:"); 
		 scanf("%d",&Z);
		 	Eliminar_Nodo( Z);
			break;
		 }
		 
		 case 6 :{
		 
		 
		 Vaciar_Lista();
			break;
		 }
		 
		  case 7 :{
		 		printf("\nPulse enter");
			break;
		 }
		 
		 default :{
		 
		 printf("\nOPCION NO VALIDA\n");
		
			break;
		 }
		 
	}
		
}while(num!=7);	
}

void Recorre_Lista()
{struct Nodo *actual=(struct Nodo*)malloc(sizeof(struct Nodo));
	actual=ini;
	if(ini!=NULL)
	{
		while(actual!=NULL)
		{
			
				printf("\nNombre del estudiante : %s \n",actual->e.nombre);
printf("Numero de cedula: %d\n",actual->e.ci);
printf("edad: %d \n",actual->e.edad);
printf("Nota : %.2f\n",actual->e.nota);
		 actual=actual->sig;
		 
		}
		
	}else
	{
		printf("la lista esta vacia\n");
		
	}
 } 

void Asignar_Datos_Nodo(struct Nodo *N){


	printf("Digite nombre del estudiante : ");
	scanf("%s",&N->e.nombre);
printf("Digite numero de cedula: ");
scanf("%d",&N->e.ci);
printf("Digite la edad: ");
scanf("%d",&N->e.edad);
printf("Digite la nota: ");
scanf("%f",&N->e.nota);
}

void Mostrar_Nodo(struct Nodo *N)
{	
	
		printf("\nUsted ha digitado \nNombre del estudiante : %s \n",N->e.nombre);
printf("Numero de cedula: %d\n",N->e.ci);
printf("edad: %d \n",N->e.edad);
printf("Nota : %.2f\n",N->e.nota);
	 
}
int Cantidad_Nodos()
{
	int n;
	struct Nodo *cont=(struct Nodo*)malloc(sizeof(struct Nodo));
	cont=ini;
	if(ini!=NULL)
	{
		while(cont!=NULL)
		{
		n++;
		 cont=cont->sig;
		}
		
	}else
	{
		printf("la lista esta vacia\n");
		
	}
	return n;
}
void Agregar_Nodo_Inicio(struct Nodo *N)
{
Asignar_Datos_Nodo( N);
		
	N->sig=ini;
	ini=N;
}

struct Nodo *Agregar_Nodo_Final(struct Nodo *N)
{
Asignar_Datos_Nodo( N);
if(ini==NULL)
{
	ini=N;
	ini->sig=NULL;
	ultimo=N;
//printf("hol  %d,  %d",ini->e.edad,ultimo->e.edad);

}else{
	ultimo->sig=N;
	N->sig=NULL;
	ultimo=N;

//	printf("hol04  %d,  %d\n",ini->e.edad,ultimo->e.edad);
}

return N;
}

void *Vaciar_Lista( )
{
	struct	Nodo *vaciar=(struct Nodo*)malloc(sizeof(struct Nodo));
	vaciar=ini;
	if(ini!=NULL)
	{
	do{
			vaciar=ini;
		ini=vaciar->sig;
		free(ini);
	}	while(ini!=NULL );
	}	

	else
		printf("la lista esta vacia\n");

}

void *Eliminar_Nodo(int Z)
{
	
struct	Nodo *borrar=(struct Nodo*)malloc(sizeof(struct Nodo));
	borrar=ini;
	if(ini!=NULL)
	{
		struct Nodo *anterior=NULL;
		while(borrar!=NULL &&  Z!=borrar->e.ci)
		{
        anterior=borrar;
		 borrar=borrar->sig;
		}
		
		if(borrar==NULL)
		printf("\nElemento no enontrado\n");
		else{
			if(anterior ==NULL){
				ini =ini->sig;
				free( borrar);
			}else{
				
			anterior->sig=borrar->sig;
			free( borrar);	
			}
			
		}
	}else
		printf("la lista esta vacia\n");
}

