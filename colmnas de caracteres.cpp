#include<stdio.h>
#include<conio.h>
void presenta(int columnas, int e,char c , int t[]){
	int mayor=t[0];
	for(int i=1;i<columnas;i++){
		if(mayor <t[i])		
		mayor=t[i];
	}
	int aux=mayor;
	for(int k=0;k<aux;k++){
		//mayor=aux;
		for(int i=0;i<columnas;i++){
		
		for(int p=0;p<t[i];p++){
			
			if(mayor <= t[i]){
				printf("%c",c);			
			}
			else
			printf(" ");
		}
		//	printf("%d",e);
			for(int j=0;j<e;j++)
				{
					printf(" ");
				}
		
				
				
	}
	mayor--;
		printf("\n");
	}

	
}




int main(){
	int e; int N;char c;
		printf("caracter: ");
	scanf("%s",&c);
	printf("NUMERO DE COLUMNAS: ");
	scanf("%d",&N);

	printf("NUMERO DE espacios: ");
	scanf("%d",&e);
	//fflush;
	
	
	printf("%d",e);
	int t[N];
	for(int i=0;i<N;i++){
		printf("\ntamaño de la columna %d: ",i+1);
		scanf("%d",&t[i]);
	}
	puts(" \n");
		
	presenta(N,e,c,t);
	getch();
}


