#include <stdio.h>
#include <conio.h>
int num, change;
int state[2]={0,1};
main(){
	printf("Autômato a ser trabalhado:");
	printf("       1\n");
	printf("    ------\n");
	printf("S0-|      |-S1<- \n");
	printf("    ------\n");
	printf("       0\n \n");
	int exit=1;
	num=state[0];
	while(exit!=0){
		printf("Digite um valor reconhecido pelo automato: ");
		scanf("%d",&change);
		if(num==0 && change==0) printf("Valor não reconhecido\n");
		if(num==0 && change==1) num=state[1];
		if(num==1 && change==0) num=state[0];
		if(num==1 && change==1) num=state[1];
		printf("Estado atual: %d\n------\n", num);
		printf("Para encerrar as entradas digite 0\nPara continuar apenas digite 1\n");
		scanf(" %d",&exit);
		printf("------\n");
	}
	if(num==0)printf("Expressão inválida");
	if(num==1)printf("Expressão válida");
}
