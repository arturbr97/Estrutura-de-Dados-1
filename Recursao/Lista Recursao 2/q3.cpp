#include <stdio.h>
#include <stdlib.h>

int maxmin(int *vet, int maior, int *menor, int cont);

int main(){
	int *vet, maior=0, menor=0, cont=0;
	
	vet= (int*) malloc (3 * sizeof(int));
	vet[0]=7;
	vet[1]=3;
	vet[2]=5;
	maior=vet[0];
	menor=vet[0];
	
	maior= maxmin(vet, maior, &menor, cont);
	
	printf("Maior numero: %d\nMenor numero: %d", maior, menor);
}

int maxmin(int *vet, int maior, int *menor, int cont){
	if(cont==2){
		return maior;
	}else{
		if(vet[cont]>maior){
			maior= vet[cont];
		}
		if(vet[cont]<*menor){
			*menor= vet[cont];
		}
		cont++;
		return maxmin(vet, maior, menor, cont);
	}
}
