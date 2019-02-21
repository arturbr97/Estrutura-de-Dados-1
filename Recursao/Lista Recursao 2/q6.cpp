#include <stdio.h>
#include <stdlib.h>

int media(int *vet, int cont, int aux);

int main(){
	int *vet, i, cont=2, aux=0;
	
	vet= (int*) malloc (3 * sizeof(int));
	for(i=0;i<3;i++){
		vet[i]=i+1;
	}
	
	printf("Media: %d", media(vet, cont, aux));
}

int media(int *vet, int cont, int aux){
	if(cont==-1){
		return aux/3;
	}else{
		aux+=vet[cont];
		cont--;
		return media(vet, cont, aux);
	}
}
