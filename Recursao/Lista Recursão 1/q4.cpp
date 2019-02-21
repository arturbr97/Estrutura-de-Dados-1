#include <stdio.h>
#include <stdlib.h>

int funcao(int num, int n, int qtd);


int main(){
	int num=45333, n=3, qtd, aux2, a;
	
	a= funcao(num, n, qtd);
	printf("Quantidade de vezes que o numero se repetiu: %d", a);
}

int funcao(int num, int n, int qtd){
	int aux;
	if(num==0){
		return qtd;
	}else{
		aux= num % 10;
		if(aux == n){
			qtd++;
		}	
		num=num/10;
		return funcao(num, n, qtd);
	}
}
