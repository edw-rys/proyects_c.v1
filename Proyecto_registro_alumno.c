#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCED 11
#define MAXNOMBRE 51
#include <time.h>


struct Persona{
    int cedula;
    char nombre[MAXNOMBRE];
     char apellido[MAXNOMBRE];
    int edad;
    char sexo[20];
    float nota_1;
    float nota_2;
    float promedio;
    };

struct Curso{
	 int cupoMax;
    struct Persona arrEstudiantes[50];
    char nombre_CURSO[50];
    char horario[50];
    int F_ini[3];
    char code[20];
    int matriculados;
};

//validar numeros
int validar_numero( char  numero[])
{
	
    int i;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            printf("\nINGRESA SOLO NUMEROS ENTEROS POSITIVOS\n\n");
            system("pause");
            return 0;
        }
    }
    return 1;
}


///numero de digitos de cedula
int numero_digitos(int n){		
	int num=1;

	while(n>0){
		n/=10;
		num=num+1;
	}
	if(num!=10)
    printf("\nEl numero de cedula debe constar de 10 digitos \n\n");
	return num;
}



int MatricularEstudiante(struct Curso *);
void ListarEstudiantes(struct Curso *);

int validar(int x,struct Curso *c){
	  int v=0,i;
	  for( i=0; i < c->matriculados; i++)
    {  v=0;
       if(x== c->arrEstudiantes[i].cedula)
      {v=1;
	  break;}
	
    }
    
   return v; 
    
}

int MatricularEstudiante(struct Curso *c)
{	
	char num_v[20];
    if (c->matriculados < c->cupoMax)
    {
       
	    printf("Matricula de estudiante al curso\n");
        printf("********************************\n");
       
	do{
	   	do{		   	   
	   		do{
				printf("Ingrese cedula->");
        		fflush(stdin);
        		gets(num_v);        		        		
			}while(validar_numero(num_v)==0);     
				   	        		
				 c->arrEstudiantes[c->matriculados].cedula=atoi(num_v); 
				       							
        }while( numero_digitos(c->arrEstudiantes[c->matriculados].cedula)!=10);
	    		
        		if(validar( c->arrEstudiantes[c->matriculados].cedula,c)==1)
        		printf("\nEl estudiante ya ha sido registrado anteriormente\n");
  	}while(validar( c->arrEstudiantes[c->matriculados].cedula,c)==1);
	    printf("Ingrese nombres->");
        fflush(stdin);
        gets( c->arrEstudiantes[c->matriculados].nombre);
        strupr(c->arrEstudiantes[c->matriculados].nombre);
         printf("Ingrese apellidos->");
        fflush(stdin);
        	gets(c->arrEstudiantes[c->matriculados].apellido);
        	strupr(c->arrEstudiantes[c->matriculados].apellido);
    do{
	
	    do{			
    
	    printf("Ingrese edad\tLa edad minima es de 5 y la maxima es de 40\n->");
        gets(num_v);
        
    	}while(validar_numero(num_v)==0);
	
		
		c->arrEstudiantes[c->matriculados].edad=atoi(num_v);
    if(	c->arrEstudiantes[c->matriculados].edad<5 || 	c->arrEstudiantes[c->matriculados].edad>50)
    printf("\nEdad ingresada fuera del rango predeterminado\nRango : 5 y 40 años\n");
}while(	c->arrEstudiantes[c->matriculados].edad<5 || 	c->arrEstudiantes[c->matriculados].edad>50);
        
		do{
		
		 printf("\nEscriba el sexo perteneciente\tMASCULINO O FEMENINO\n->");
        fflush(stdin);
        
		scanf("%s", c->arrEstudiantes[c->matriculados].sexo);
		strupr( c->arrEstudiantes[c->matriculados].sexo);
	//	puts(c->arrEstudiantes[c->matriculados].sexo);
		if(strcmp(c->arrEstudiantes[c->matriculados].sexo,"MASCULINO")!=0 && strcmp( c->arrEstudiantes[c->matriculados].sexo,"FEMENINO")!=0)
		printf("\nSolo se puede ingresar masculino o femenino");
	}
        while(strcmp(c->arrEstudiantes[c->matriculados].sexo,"MASCULINO")!=0 && strcmp(c->arrEstudiantes[c->matriculados].sexo,"FEMENINO")!=0);
		c->matriculados++;
		puts("");
        return 1;
    }
    else
    {
        return 0;
    }
}

void ingreso_de_notas(struct Curso *c){
	int i;
	char h[20];
	int j,val=0;
	printf("\n***INGRESO DE NOTAS***\nCedula \t Nombres \t Apellidos\n");
	for(i=0; i < c->matriculados; i++)
    {
    	printf("\n%d \t %s \t %s \t", c->arrEstudiantes[i].cedula,c->arrEstudiantes[i].nombre,c->arrEstudiantes[i].apellido);
    	if(c->arrEstudiantes[i].promedio>0.1 && c->arrEstudiantes[i].promedio<=10)
    	{    		
    		printf("\nNotas ya registradas\nPrimer Nota: %.2f\nSegunda Nota: %.2f",c->arrEstudiantes[i].nota_1,c->arrEstudiantes[i].nota_2);    		
		}
		else
		{					
      			 do{
	   					
						   do{
						   	val=0;
						   printf("\nDigite nota del primer parcial: " );
        				scanf("%s",&h);					
        				for(j=0;j<strlen(h);j++){
        					if(h[j]!='0' && h[j]!='.' && h[j]!='1' && h[j]!='2' && h[j]!='3'
								&&h[j]!='4' && h[j]!='5' && h[j]!='6' && h[j]!='7' && h[j]!='8' && h[j]!='9' )
						{
						val=1;
			
							break;
		
						}
        					
        				}
        				if(val==1)
        				printf("\n\nSolo numeros \n\n");
					}while(val==1);
						c->arrEstudiantes[i].nota_1=atof(h);
						if(c->arrEstudiantes[i].nota_1>10 || c->arrEstudiantes[i].nota_1<0.1)
        				printf("\nLas notas ingresadas deben estar dentro del rango mayor a 0 y menor a 10\n\n");
    			}while(c->arrEstudiantes[i].nota_1>10 || c->arrEstudiantes[i].nota_1<0.1);
		  
		  		do{
		  			
		  			do{
					  val=0;
		  				printf(" Digite nota del segundo parcial:");
           				scanf("%s",&h);					
        				for(j=0;j<strlen(h);j++){
        					if(h[j]!='0' && h[j]!='.' && h[j]!='1' && h[j]!='2' && h[j]!='3'
								&&h[j]!='4' && h[j]!='5' && h[j]!='6' && h[j]!='7' && h[j]!='8' && h[j]!='9' )
						{
						val=1;
			
							break;
		
						}
        					
        				}
        				if(val==1)
        				printf("\n\nSolo numeros \n\n");
				}while(val==1);
					
            	c->arrEstudiantes[i].nota_2=atof(h);
					
						if(c->arrEstudiantes[i].nota_2>10 || c->arrEstudiantes[i].nota_2<0)
        				printf("\nLas notas ingresadas deben estar dentro del rango mayor a 0 y menor a 10\n\n");
    			}while(c->arrEstudiantes[i].nota_2>10 || c->arrEstudiantes[i].nota_2<0.1);
		  
		  c->arrEstudiantes[i].promedio=( c->arrEstudiantes[i].nota_1 +c->arrEstudiantes[i].nota_2)/2;
	printf("\n\t\tNotas ingresadas correctamente\n\n");
	
	
		}
			  
    
	
	}
    
}


void busqueda_del_estudiante(int ci, struct Curso *c){
	int i=0,o=0;
	for(i=0; i < c->matriculados; i++)
    {
    	if(c->arrEstudiantes[i].cedula==ci)
		{
			o=1;
			break;    	
		}	
	}
	if(o==1){
	
	
	printf("\nEstudiante \n");
	 printf("Cedula : %d \nNombres: %s\nApellidos: %s \nNota primer parcial: %.2f \nNota primer parcial: %.2f\nPromedio:  %.2f\nEdad: %d\nSexo: %s\n", c->arrEstudiantes[i].cedula ,  c->arrEstudiantes[i].nombre,  c->arrEstudiantes[i].apellido,   
	 c->arrEstudiantes[i].nota_1,  c->arrEstudiantes[i].nota_2,  c->arrEstudiantes[i].promedio,  c->arrEstudiantes[i].edad,c->arrEstudiantes[i].sexo);
	}
	else
	printf("\nEstudiante no ha sido maticulado\n");

}



void ListarEstudiantes(struct Curso *c)
{
    int i;
    printf("Listado de estudiantes matriculados\n");
    //printf("Cedula \t\tNombres \t\tApellidos \t\tEdad\t Sexo\n");
    printf("***********************************\n");
    for(i=0; i < c->matriculados; i++)
    {
    printf("\nEstudiante %d\n",i+1);
       
	printf("\nEstudiante \n");
	if(c->arrEstudiantes[i].promedio>=0.1)
	 printf("Cedula : %d \nNombres: %s\nApellidos: %s \nNota primer parcial: %.2f \nNota segundo parcial: %.2f\nPromedio:  %.2f\nEdad: %d\nSexo: %s\n", c->arrEstudiantes[i].cedula ,  c->arrEstudiantes[i].nombre,  c->arrEstudiantes[i].apellido,   
	 	 c->arrEstudiantes[i].nota_1,  c->arrEstudiantes[i].nota_2,  c->arrEstudiantes[i].promedio,  c->arrEstudiantes[i].edad,c->arrEstudiantes[i].sexo);
	 	 else
	 	  printf("Cedula : %d \nNombres: %s\nApellidos: %s \nNota primer parcial:  No ingresadas \nNota primer parcial: No ingresadas\nPromedio:  %.2f\nEdad: %d\nSexo: %s\n", c->arrEstudiantes[i].cedula ,  c->arrEstudiantes[i].nombre,  c->arrEstudiantes[i].apellido,   
	 	  c->arrEstudiantes[i].promedio,  c->arrEstudiantes[i].edad,c->arrEstudiantes[i].sexo);
    }
}




int OpcionesMenu(struct Curso *c)
{
    int opcion=0;
    char validar_[10];
        do{
		system("cls");
			
        printf("\t********************\n\t*  %s-%s\n\t*Jornada: %s\n\t*Estudiantes maximos: %d\n\t*Cupos disponibles: %d",c->nombre_CURSO,  c->code, 
		 c->horario, c->cupoMax,(c->cupoMax-c->matriculados));
		 
		  time_t tiempo = time(0);
		 struct tm *tlocal = localtime(&tiempo);
        char output[128];
        strftime(output,128,"%d/%m/%y ",tlocal);
        printf("\n\t*Fecha: %s\n",output);
		 
		 
        printf("\n****************************************************\n");
		printf("\n*            Menu de opciones                      *\n");
		printf(  "*       1) Matricular                              *\n");
        printf(  "*       2) Listar                                  *\n");
        printf(  "*       3) Busqueda de estudiante y sus datos      *\n");
        printf(  "*       4) Ingreso de notas                        *\n");        
        printf(  "*       5) Estadisticas del curso                  *\n");
        printf(  "*       6) Salir                                   *\n");
        printf("\n****************************************************\n");
        printf(  " Opcion->");
            
       gets(validar_);
       fflush(stdin);    
	}while(validar_numero(validar_)==0);
		opcion=atoi(validar_);

    return opcion;
}

//menu de llenado de datos del curso
void menu_curso(struct Curso *Programacion){
	do{

		printf("Nombre del curso: ");
		scanf("%s", Programacion->nombre_CURSO);
		if(strlen(Programacion->nombre_CURSO)<3)
		printf("\nEl nombre del curso no puede tener menos de 3 letras\nPor favor, vuelva a ingresar el nombre\n\n");
	}while(strlen(Programacion->nombre_CURSO)<3);
	do{
	printf("Codigo del curso: ");
	scanf("%s", Programacion->code);	
	if(strlen(Programacion->code)<=4)
		printf("\nEl codigo del curso no puede tener menos de 5 caracteres\nPor favor, vuelva a ingresar el codigo\n\n");
}while(strlen(Programacion->code)<=4);
	do{
	
		printf("\n*****Horario-Opciones*****\nMatutino\nVespertino\nNocturno\nDigite: ");
		scanf("%s", Programacion->horario);
		strupr(Programacion->horario);
	if(strcmp("MATUTINO",Programacion->horario)!=0 && strcmp("VESPERTINO",Programacion->horario)!=0 && strcmp("NOCTURNO",Programacion->horario)!=0)
		printf("\nSolo se permite ingresar las opciones mostrada anteriormente\n");
	}while(strcmp("MATUTINO",Programacion->horario)!=0 & strcmp("VESPERTINO",Programacion->horario)!=0 && strcmp("NOCTURNO",Programacion->horario)!=0);
	
	char val_num[11];
		printf("\nFecha de inicio\n\tFORMATO : DD/M/AA\n");
		
		
		 time_t tiempo = time(0);
		 struct tm *tlocal = localtime(&tiempo);
        char output[128];
        strftime(output,128,"%d/%m/%y ",tlocal);
        printf("\t\t%s\n",output);
/*
do{

	do{
		printf("\nDia: ");
		scanf("%s", val_num);
	}while(validar_numero(val_num)==0);
	Programacion->F_ini[0]=atoi(val_num);
	if(Programacion->F_ini[0]>30 || Programacion->F_ini[0]<1)
	printf("\nDia incorrecto\n");
}while(Programacion->F_ini[0]>30 || Programacion->F_ini[0]<1);
	do{

	do{
		printf("\nMes: ");
		scanf("%s", val_num);
	}while(validar_numero(val_num)==0);
	Programacion->F_ini[1]=atoi(val_num);
	if(Programacion->F_ini[1]>12 || Programacion->F_ini[1]<1)
	printf("\nMes incorrecto\n");
}while(Programacion->F_ini[1]>12 || Programacion->F_ini[1]<1);


	do{

	do{
		printf("\nAnio: ");
		scanf("%s", val_num);
	}while(validar_numero(val_num)==0);
	Programacion->F_ini[2]=atoi(val_num);
	if(Programacion->F_ini[2]<2017 || Programacion->F_ini[2]>2018)
	printf("\nAnio incorrecto\n");
}while(Programacion->F_ini[2]<2017 || Programacion->F_ini[2]>2018);
*/
system("pause");
}


//estadisticas del curso
void estadisticas(struct Curso *c){
	int i, cont_mas=0, cont_feme=0;
	float prom_c=0,max=-1,min=11;
	int p_max,p_min;
	int edades_p[7]={0,0,0,0,0,0,0};
	
	 for(i=0; i <=c->matriculados; i++)
    {
    	prom_c+=c->arrEstudiantes[i].promedio;    	
    	
    	if(c->arrEstudiantes[i].promedio>max){
    		max=c->arrEstudiantes[i].promedio;
    		p_max=i;    	
		}		
		if(strcmp(c->arrEstudiantes[i].sexo,"MASCULINO")==0)
		cont_mas++;
		if(strcmp(c->arrEstudiantes[i].sexo,"FEMENINO")==0)	
		cont_feme++;
		
		if(c->arrEstudiantes[i].edad>=5 && c->arrEstudiantes[i].edad<10)
		edades_p[0]++;
		else
			if(c->arrEstudiantes[i].edad>=10 && c->arrEstudiantes[i].edad<15)
			edades_p[1]++;
			else
				if(c->arrEstudiantes[i].edad>=15 && c->arrEstudiantes[i].edad<20)
				edades_p[2]++;
				else
					if(c->arrEstudiantes[i].edad>=20 && c->arrEstudiantes[i].edad<25)
					edades_p[3]++;
					else
						if(c->arrEstudiantes[i].edad>=25 && c->arrEstudiantes[i].edad<30)
					edades_p[4]++;
					else
					if(c->arrEstudiantes[i].edad>=30 && c->arrEstudiantes[i].edad<35)
					edades_p[5]++;
						else
					if(c->arrEstudiantes[i].edad>=35 && c->arrEstudiantes[i].edad<=40)
					edades_p[6]++;
    }
     for(i=0; i <=c->matriculados-1; i++)
    {
    if(c->arrEstudiantes[i].promedio<min)
		{
			min=c->arrEstudiantes[i].promedio;
			p_min=i;
		}
		
}
        
    	printf("\nPromedio del curso:  %.2f\nEstudiante con nota maxima\n%s %s \tci: %d\t Promedio : %.2f",prom_c/c->matriculados,c->arrEstudiantes[p_max].apellido,c->arrEstudiantes[p_max].nombre,
		c->arrEstudiantes[p_max].cedula,max);
		printf("\nEstudiante con nota minima\n%s %s \tci: %d\t Promedio : %.2f    ",c->arrEstudiantes[p_min].apellido,c->arrEstudiantes[p_min].nombre,
		c->arrEstudiantes[p_min].cedula,min);
		printf("\nContablilizacion por sexo\nMasculino: %d\nFemenino: %d",cont_mas,cont_feme);
		printf("\nContabilizacion de estudiantes segun las edades\nDesde 5 hasta 9 anios: %d",edades_p[0]);
		printf("\nDesde 10 hasta 14 anios: %d",edades_p[1]);
		printf("\nDesde 15 hasta 19 anios: %d",edades_p[2]);
		printf("\nDesde 20 hasta 24 anios: %d",edades_p[3]);	
		printf("\nDesde 25 hasta 29 anios: %d",edades_p[4]);
		printf("\nDesde 30 hasta 34 anios: %d",edades_p[3]);	
		printf("\nDesde 35 hasta 40 anios: %d",edades_p[4]);
		
}

//ordenar de la a hasta z
void ordenar_alabeticamente(struct Curso *c){
int i,j;
struct Curso reserva;
 for(i=0; i < c->matriculados; i++)
    {
	 for(j=0; j < c->matriculados-1; j++)
    {
		if(c->arrEstudiantes[j].apellido[0]>c->arrEstudiantes[j+1].apellido[0] )
		{
			reserva.arrEstudiantes[0]=c->arrEstudiantes[j];
			c->arrEstudiantes[j]=c->arrEstudiantes[j+1];
			c->arrEstudiantes[j+1]=reserva.arrEstudiantes[0];
		}
	
	
	}
	
	}
}




int main()
{
    struct Curso Programacion;
	int MAX;
	int comprobar_i_n=0;
	int ci;
	char validar_[10];
	
	do{
	
	do{
	system("cls");
    	printf("\nDigite numero de estudiantes a registrar\n\tRANGO 1 hasta 50 \nDigite:");
    //	gets(validar_);    
    scanf("%s",&validar_);
		fflush(stdin);		
	}while(validar_numero(validar_)==0);
	MAX=atoi(validar_);
	if(MAX>50)
	printf("\nFuera del rango\n");
}while(MAX>50);
	Programacion.cupoMax = MAX;
 	menu_curso(&Programacion);
	
	Programacion.matriculados = 0;
    int opcion;

   do
    {
        opcion = OpcionesMenu(&Programacion);
        system("cls");
        switch(opcion)
        {
            case 1:
                 if (MatricularEstudiante(&Programacion)==1)
                 {
                     printf("registrado corrrectamente\n");
                 }
                 else
                 {
                     printf("No hay cupos disponibles\n");
                 }
                 system("pause");
                 break;
            case 2:
            	
            	if(Programacion.arrEstudiantes[0].cedula!=0)
        		{
        			ordenar_alabeticamente(&Programacion);
                 ListarEstudiantes(&Programacion);                 
                 }
    			else 
    			printf("\nNo se ha registrado estudiantes\n");
    		 printf("\n\nPulse enter para continuar\n");
   			 getch();
                 break;
        	case 3:
        		if(Programacion.arrEstudiantes[0].cedula!=0)
        		{
				do{
        		do{
				
        			printf("\nDigite numero de cedula del estudiante a buscar: ");
        	//gets(validar_);
        			scanf("%s",validar_);
        			fflush(stdin);
      			
			
				  	  }while(validar_numero(validar_)==0);
      			   ci=atoi(validar_);
      			  
      		}while(numero_digitos(ci)!=10);
      			  busqueda_del_estudiante(ci,&Programacion);
        
    				}
    				else 
    				printf("\nNo se ha registrado estudiantes\n");
    				 printf("\n\nPulse enter para continuar\n");
   					 getch();
        		break;
        		case 4:        	
        	if(Programacion.arrEstudiantes[0].cedula!=0)
        		{
				ingreso_de_notas(&Programacion);
				}
    		else 
    			printf("\nNo se ha registrado estudiantes\n");
    	 	printf("\n\nPulse enter para continuar\n");
    		getch();
        
        			break;
        		default:{
        			printf("\nOpcion no valida\n");
					break;
					
					case 5:{
							if(Programacion.arrEstudiantes[0].cedula!=0)
        		{
						estadisticas(&Programacion);
							}
    		else 
    			printf("\nNo se ha registrado estudiantes\n");
    	 	printf("\n\nPulse enter para continuar\n");
    		getch();
						break;
					}
					case 6:{
						
						break;
					}
					
				}
		}
    }while(opcion!=6);
    system("pause");
}
