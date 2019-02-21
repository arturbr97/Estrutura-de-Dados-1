#include <stdio.h>
#include <stdlib.h>

int produto(int *vet, int cont, int aux);

int main(){
	int *vet, i, cont=0, aux=1;
	vet= (int*) malloc (6 * sizeof(int));
	for(i=0;i<6;i++){
		vet[i]=i+1;
	}
	printf("Produtos dos numeros pares: %d", produto(vet, cont, aux));	
}

int produto(int *vet, int cont, int aux){
	if(cont==6){
		return aux;
	}else{
		if(vet[cont] % 2 == 0){
			aux = aux * vet[cont];
		}
		cont++;
		return produto(vet, cont, aux);	
	}
	
}
