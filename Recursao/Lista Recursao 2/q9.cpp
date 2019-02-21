#include <stdio.h>
#include <stdlib.h>

int busca(int *vet, int num, int cont);

int main(){
	int *vet, num=2, cont=4, i;
	
	vet=(int*) malloc (4 * sizeof(int));
	for(i=0;i<4;i++){
		vet[i]=i+1;
	}
	
	printf("Posicao: %d", busca(vet, num, cont));
}

int busca(int *vet, int num, int cont){
	if(cont==-1){
		return 0;
	}else{
		if(vet[cont]==num){
			return cont;
		}
		cont--;
		return busca(vet, num, cont);
	}
}
