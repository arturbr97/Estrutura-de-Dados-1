#include <stdio.h>
#include <stdlib.h>

int funcao(int x, int n);

int main(){
	int x=2,n=3, res;
	
	res= funcao(x,n);
	printf("Resultado: %d", res);
	
}

int funcao(int x, int n){
	if(n==1){
		return x;
	}else{
		n--;
		return x * funcao(x, n);
	}
}
