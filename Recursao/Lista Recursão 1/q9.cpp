#include <stdio.h>
#include <stdlib.h>

int fatorial(int num);

int main(){
	int num=10, fat=0, quad=0;
	fat=fatorial(num);
	quad = (2*fat)/fat;
	printf("Fatorial quadruplo: %d", quad);
}

int fatorial(int num){
	int aux;
	if(num==1){
		return num;
	}else{
		aux= num;
		num= num-1;
		return aux * fatorial(num);
	}
}
