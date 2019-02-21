#include <stdio.h>
#include <stdlib.h>

int funcao(int x);

int main(){
	int x=123;
	x=funcao(x);
	
}

int funcao(int x){
	
	if(x==0){
		return x;
	}else{
		printf("%d", x % 10);
		x = x/10;
		return funcao(x);
	}
}
