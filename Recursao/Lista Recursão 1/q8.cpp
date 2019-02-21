#include <stdio.h>
#include <stdlib.h>

int somar(int num);

int main(){
	int num=123, soma=0;
	
	soma=somar(num);
	printf("Soma: %d", soma);
}

int somar(int num){
	int aux;
	if(num==0){
		return num;
	}else{
		aux = num % 10;
		num = num/10;
		return aux + somar(num);
	}
}
