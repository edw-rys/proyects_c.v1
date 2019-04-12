#include<limits.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int hanoi(int );
void mover_torres(int d,int x,int discos_hanoi[][3]);
int main(){
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
	}
	printf("\t  A  \t\t  B  \t\t  C");	
	printf("\n");
		
	if(discos!=1)
		for(int i=0;i<hanoi(discos);i++){
			printf("\n\tMovimiento %d",i+1);
			mover_torres(discos,i+1,discos_hanoi);
			printf("\n");
			printf("\n");
		}
	else{
		printf("\n");
		printf("\t| | |\t\t| | |\t\t| %d |\t",discos_hanoi[0][0]);
		printf("\n\t  A  \t\t  B  \t\t  C");	
	}
	system("pause");
}


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
