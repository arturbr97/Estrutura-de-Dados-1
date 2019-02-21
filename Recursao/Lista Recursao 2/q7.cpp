#include <stdio.h>
#include <stdlib.h>

int multi(int a, int b);

int main(){
	int a=2, b=3;
	printf("Multiplicacao: %d", multi(a, b));
}

int multi(int a, int b){
	if(b==0){
		return b;
	}else{
		b--;
		return a + multi(a,b);
	}
	
	
}
