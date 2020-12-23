#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
int num, change;
int state[2]={0,1};
void draw(){
	system("cls");
	printf("Autômato a ser trabalhado: \n\n");
	printf("         1\n");
	printf("      ------\n");
	printf("  S0-|      |-S1<- \n");
	printf("      ------\n");
	printf("         0\n \n");
	printf("=====\n");
	printf("Estado inicial: S0\n");
	printf("Estado atual: %d\n________\n", num);
}
main(){
	setlocale(LC_ALL, "Portuguese");
	int exit=1;
	num=state[0];
	while(exit!=0){
		draw();
		printf("Digite um valor reconhecido pelo autômato: ");
		scanf("%d",&change);
		if(num==0 && change!=0) printf("Valor não reconhecido\n");
		if(num==0 && change==1) {
			num=state[1];
			draw();
		}
		if(num==1 && change==0) {
			num=state[0];
			draw();
		}
		if(num==1 && change==1) {
			num=state[1];
			draw();
		}
		printf("\n");
		printf("Para encerrar as entradas digite 0\nPara continuar apenas digite 1\n");
		scanf(" %d",&exit);
		printf("------\n");
	}
	if(num==0)printf("Expressão inválida");
	if(num==1)printf("Expressão válida");
}
