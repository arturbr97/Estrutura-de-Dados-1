#include <stdio.h>
#include <stdlib.h>

int funcao(int x, int y);

int main(){
	int x=2,y=3, res;
	
	res= funcao(x,y);
	printf("Resultado: %d", res);
	
}

int funcao(int x, int y){
	if(y==1){
		return x;
	}else{
		y--;
		return x * funcao(x, y);
	}
}
