#include <stdio.h>
#include <stdlib.h>

int menor(int *vet, int aux, int cont);

int main(){
	int *vet, aux,cont=2;
	
	vet=(int*) malloc (3 * sizeof(int));
	vet[0]=4;
	vet[1]=2;
	vet[2]=3;
	aux=vet[0];
	
	printf("Menor: %d", menor(vet, aux, cont));
	
}

int menor(int *vet, int aux, int cont){
	if(cont==0){
		return aux;
	}else{
		if(vet[cont]<aux){
			aux=vet[cont];
		}
		cont--;
		return menor(vet, aux, cont);
	}
}
