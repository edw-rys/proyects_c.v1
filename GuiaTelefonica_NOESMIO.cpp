#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<windows.h>
#include<iostream>
#include<stdio.h>
using namespace std;

int cont = 0; 

struct Nodo{
	char dato;
	Nodo *siguiente;	
};

struct pilas
{
	char valor;
	pilas *direccionA;
};
pilas *pilao,*pilaaux; 

struct invertir{
	char dato;
}inv[100];

struct contacto{
	string nombre,apellido,telefono;
}datos;

void menu();
void menu1();
void ingresoPila(pilas*&);
void mostrarPila();
void eliminarPila();
void insertarCola(Nodo *&,Nodo *&,char);
bool cola_vacia(Nodo *);
void suprimirCola(Nodo *&,Nodo *&,char &);
void crear_contacto();
void agregar_contacto();
void visualizar_contacto();
void gotoxy(short x, short y);
void marco();
int main(){
	
	menu();
	
	getch();
	return 0;
}

void menu(){
	Nodo *pila = NULL;
	int opcion;
	char dato1;
	char dato2;
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	
	do{
         
			system("cls");
			marco();
			gotoxy(30,7);cout<<"\n\t\t\tPROYECTO SEGUNDO PARCIAL\n";
			gotoxy(10,7);cout<<"\tMyleen Ching Valle - Justin Rivera Jordan\n";
            gotoxy(6,9);cout<<"________________________________________________________________";
        	gotoxy(30,11);cout<<".:MENU:.\n";
           	gotoxy(7,13);cout<<"1. Agregar elementos a la pila"<<endl;
           	gotoxy(7,15);cout<<"2. Mostrar pila invertida"<<endl;
           	gotoxy(7,17);cout<<"3. Eliminar un elemento de la pila"<<endl;
            gotoxy(7,19);cout<<"4. Agregar elementos a la cola"<<endl;
            gotoxy(7,21);cout<<"5. Mostrar los elementos de la cola"<<endl;
            gotoxy(7,23);cout<<"6. Eliminar los elementos de la cola"<<endl;
            gotoxy(7,25);cout<<"7. Agenda telefonica"<<endl;
            gotoxy(7,27);cout<<"8. Salir"<<endl;
            gotoxy(7,29);cout<<"\t\tOPCION[ ]\b\b";
          cin>>opcion;
			
	
		
		switch(opcion){
                      
			case 1:
                 
                 system ("cls");
                  marco(); 
                 gotoxy(7,7);cout<<"Digite un caracter: "<<endl;
                 ingresoPila(pilao);
					gotoxy(10,10);system("pause");
					break;
			case 2: 
			
			     system ("cls");
                  marco(); 
                 gotoxy(7,7);cout<<"\n\tMostrar pila invertida";
				 mostrarPila();	
					gotoxy(20,20);system("pause");
					break;	
			case 3: 
                  system ("cls");
                  marco();
                  gotoxy(7,7);cout<<"\n\tEliminar elementos de la pila: ";
					eliminarPila();
				 gotoxy(10,10);system("pause");
					break;
			case 4: 
                 system ("cls");
                  marco(); 
                 gotoxy(7,7); cout<<"\n\tIngrese el caracter para agregar a la cola: ";
					cin>>dato2;
					insertarCola(frente,fin,dato2);
					gotoxy(20,20);system("pause");
					break;
			case 5:
                  system ("cls");
                  marco(); 
                 gotoxy(7,7);cout<<"\n\tMostrando los elementos de la cola: ";
					while(frente != NULL){
						suprimirCola(frente,fin,dato2);
						if(frente != NULL){
							cout<<dato2<<" , ";
						}
						else{
							cout<<dato2<<".";
						}
					}
					cout<<"\n";
				gotoxy(10,10);system("pause");
					break;			
			case 6: 
                 system ("cls");
                  marco(); 
                 gotoxy(7,7);cout<<"\n\tEliminar los elementos de la cola: ";
					while(frente != NULL){
						suprimirCola(frente,fin,dato2);
						if(frente != NULL){
							cout<<dato2<<" , ";
						}
						else{
							cout<<dato2<<".";
						}
					}
					cout<<"\n";
				gotoxy(20,20);system("pause");
					break;		
			case 7:  //menu1(); 
			{
			
				
	int opcion;
	
	do{
		system("cls");
		marco();
		gotoxy(24,7);cout<<"-----AGENDA TELEFONICA-----";
        gotoxy(6,9);cout<<"________________________________________________________________";
		gotoxy(7,13);cout<<"1. Crear Agenda Telefonica"<<endl;
		gotoxy(7,15);;cout<<"2. Agregar mas contactos"<<endl;
		gotoxy(7,17);cout<<"3. Visualizar contactos existentes"<<endl;
		gotoxy(7,19);cout<<"4. Salir"<<endl;
		gotoxy(7,21);cout<<"\t\tOPCION[ ]\b\b";
          cin>>opcion;
		
		switch(opcion){
			case 1: 
                 system ("cls");
                 marco(); 
                 gotoxy(24,7);cout<<"-----REGISTRAR CONTACTO-----";
                 gotoxy(6,9);cout<<"________________________________________________________________";
                    crear_contacto();
                    cout<<"\n";
				gotoxy(25,25);system("pause");
					break;
			case 2:
                  gotoxy(24,7);cout<<"-----REGISTRAR NUEVO CONTACTO-----";
                 gotoxy(6,9);cout<<"________________________________________________________________";
                  agregar_contacto();
                  cout<<"\n";
				gotoxy(15,15);system("pause");
					break;
			case 3:
                 system("cls");
                 cout<<"\t\t____________________________________ \n";
                 cout<<"\t\t\t-----CONTACTOS-----\n";
                 cout<<"\t\t____________________________________\n\n";
                  visualizar_contacto();
					cout<<"\n";
					system("pause");
					break;
		}
		system("cls");
	}while(opcion!=4);		
	
}
	break;
			case 8: break;
		}
		system("cls"); 
	}while(opcion != 8);
}


//Funcion para insertar cola.
void insertarCola(Nodo *&frente,Nodo *&fin,char n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin->siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
}

//Función para determinar si la cola está vacia
bool cola_vacia(Nodo *frente){
	return (frente == NULL)? true : false; 
}

//Función para eliminar elementos de la cola
void suprimirCola(Nodo *&frente,Nodo *&fin,char &n){
	n = frente->dato;
	Nodo *aux = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente->siguiente;
	}
	delete aux;
}

//Funcion para crear un contacto
void crear_contacto(){
	ofstream archivo;
	char rpt;
	
	archivo.open("AgendaTelefonica.txt",ios::out); //Abrimos el archivo en modo escritura
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	archivo<<"\tAgenda Telefonica\n\n";
	
	do{
    system("cls");
                       marco();
        gotoxy(24,7);cout<<"-----REGISTRAR CONTACTO-----";
        gotoxy(6,9);cout<<"________________________________________________________________";
		fflush(stdin);
		gotoxy(7,11);cout<<"Digite su nombre: ";
		getline(cin,datos.nombre);
		gotoxy(7,13);cout<<"Digite su Apellido: ";
		getline(cin,datos.apellido);
		gotoxy(7,15);cout<<"Digite su Telefono: ";
		getline(cin,datos.telefono);
	
		archivo<<"Nombre: "<<datos.nombre<<endl;
		archivo<<"Apellido: "<<datos.apellido<<endl;
		archivo<<"Telefono: "<<datos.telefono<<endl<<endl;
		
		gotoxy(7,17);cout<<"Desea Agregar otro contacto <S/N>: ";
		cin>>rpt;
		system("cls");
	}while((rpt == 'S') || (rpt == 's'));
	
	archivo.close(); //Cerramos el archivo	
}

//Funcion para agregar más contactos
void agregar_contacto(){
	ofstream archivo;
	char rpt;
	
	archivo.open("AgendaTelefonica.txt",ios::app); //Abrimos el archivo en modo agregar
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	do{
        system("cls");
         marco();
        gotoxy(24,7);cout<<"-----REGISTRAR NUEVO CONTACTO-----";
        gotoxy(6,9);cout<<"________________________________________________________________";
		fflush(stdin);
		gotoxy(7,11);cout<<"Nombre: "; getline(cin,datos.nombre);
		gotoxy(7,13);cout<<"Apellido: "; getline(cin,datos.apellido);
		gotoxy(7,15);cout<<"Telefono: "; getline(cin,datos.telefono);
	
		archivo<<"Nombre: "<<datos.nombre<<endl;
		archivo<<"Apellido: "<<datos.apellido<<endl;
		archivo<<"Telefono: "<<datos.telefono<<endl<<endl;
	
		gotoxy(7,17);cout<<"Desea Agregar otro contacto <S/N>: ";
		cin>>rpt;
			system("cls");
	}while((rpt == 'S') || (rpt == 's'));
	
	archivo.close(); //Cerramos el archivo
}

void visualizar_contacto(){
	ifstream archivo;
	string texto;
	
	archivo.open("AgendaTelefonica.txt",ios::in); //Abrimos el archivo en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	while(!archivo.eof()){ //mientras no sea el final de archivo
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	
	archivo.close(); //Cerramos el archivo
}


void ingresoPila(pilas *&pilao){

	int cant,salir=0;
	system("cls");
	cout<<"¿Cuantos datos desea ingresar?"<<endl;
	cin>>cant;

	while(salir!=cant){
		pilaaux=new(pilas);
		cout<<"\nIngrese dato a la pila"<<endl;
		cin>>pilaaux->valor;
		cout<<"Dato ["<<pilaaux->valor<<"] ingresado correctamente"<<endl;
		pilaaux->direccionA=pilao;
		
		inv[cont].dato= pilaaux->valor;
		cont++;


		pilao=pilaaux;
		salir++;
	}

	
	getch();
}
void mostrarPila(){
	int inve=0;
	if(pilao==NULL){
		cout<<"\n\tNo hay datos en la pila"<<endl;
		getch();
	}
	pilaaux=pilao;
	cout<<"\n\t  ELEMENTOS DE LA PILA\n"<<endl;
	cout<<"\n\t|pila|  |pila invertida|\n"<<endl;
	while(pilaaux!=NULL){
		cout<<"\t| "<<pilaaux->valor<<"  -----  "<<inv[inve].dato<<" |"<<endl;
		pilaaux=pilaaux->direccionA;
		inve++;
	}
	cout<<"\tFIN DE LA PILA"<<endl;
	getch();
}
void eliminarPila(){
	if(pilao==NULL){
		cout<<"\n\tNo hay datos en la pila"<<endl;
		getch();
		return;
	}
	pilaaux=new(pilas);
	pilaaux=pilao;
	cout<<"\n\tElemento eliminado "<<pilaaux->valor<<endl;
	pilao=pilaaux->direccionA;
	delete(pilaaux);
	getch();
}


//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void marco(){
int x=5;
int x1=5;
int y=6;
int y1=6;
for(int i =0;i<66;i++)
{
gotoxy(x,5);printf("*");
gotoxy(x1,31);printf("*");
x++;
x1++;
}
for( int i=0;i<25;i++){
 gotoxy(5,y);printf("|");
 gotoxy(70,y1);printf("|");
 y1++ ;
 y++;
}
}

