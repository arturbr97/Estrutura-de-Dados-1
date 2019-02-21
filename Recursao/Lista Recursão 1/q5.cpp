#include <stdio.h>
#include <stdlib.h>

int funcao(int num, int bin, int cont);
int bina(int num, int mult);

int main(){
	int num=7, rec=0, bin=0, cont=0, i=0;
	
	rec= bina(num,1);//funcao(num, bin, cont);
	printf("%d", rec);
}

//int funcao(int num, int bin, int cont){
//	if(num==1){
//		bin = num;
//		printf("%d", bin);
//		return bin;
//	}else{
//		bin = num % 2;
//		num = num / 2;
//		cont++;
//		int jesus = funcao(num, bin, cont);
//		printf("%d", bin);
//		return jesus;
//	}
//}


int bina(int num, int mult){
	if(num==0){
		return 0;
	}
	int bin = num % 2;
	num = num / 2;
	return bin * mult + bina(num,mult*10);
}
