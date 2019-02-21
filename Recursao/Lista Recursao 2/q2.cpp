#include <stdio.h>
#include <stdlib.h>

int soma(int num);

int main(){
	int num=4;
	
	printf("Somatorio: %d", soma(num));
	
}

int soma(int num){
	int aux;
	if(num==0){
		return num;
	}else{
		aux = num;
		num=num-1;
		return aux + soma(num);
	}
	
	
}
