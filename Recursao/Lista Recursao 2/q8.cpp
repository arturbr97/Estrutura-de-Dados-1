#include <stdio.h>
#include <stdlib.h>

//INCOMPLETA

int ordena(int *vet, int cont);

int main(){
	int *vet, cont=0, a;
	
	vet= (int*) malloc (4 * sizeof(int));
	for(i=0;i<4;i++){
		vet[i]=i+1;
	}
	a= ordena(vet, cont);
}

int ordena(int *vet, int cont){
	int aux;
	if(cont==4){
		return cont;
	}else{
		if(vet[cont]>vet[cont+1]){
		}
		
		
		cont++;
		return ordena(vet, cont);
	}
}
