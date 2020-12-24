//bibliotecas
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>

//vari�veis globais
int num, change;
int state[2]={0,1};

//Dsenho do aut�mato
void draw(){
	system("cls");
	printf("Aut�mato a ser trabalhado: \n\n");
	printf("         1\n");
	printf("      --->--\n");
	printf("  S0-|      |-S1<- \n");
	printf("      ---<--\n");
	printf("         0\n \n");
	printf("=====\n");
	printf("Estado inicial: S0\n");
	printf("Estado atual: %d\n________\n", num);
}

//main
main(){
	setlocale(LC_ALL, "Portuguese"); //colocando o idioma em pt-br para usar acentos
	int exit=1;
	int error=0;
	num=state[0];
	while(exit!=0){
		draw();
		printf("Digite um valor reconhecido pelo aut�mato: ");
		scanf("%d",&change);
		if(num==0 && change!=1 || num==1 && change!=0) { //inputs inv�lidas
			printf("Valor n�o reconhecido\n"); 
			printf("------\n");
			exit=0;
			error=1;
		}
		if(num==0 && change==1) {
			num=state[1];
			draw();
		}
		if(num==1 && change==0) {
			num=state[0];
			draw();
		}
		if(error==0){
			printf("Para encerrar as entradas digite 0\nPara continuar apenas digite 1\n");
			scanf(" %d",&exit);
			printf("------\n");
		}
	}
	if(num==0 || error==1)printf("Express�o inv�lida");
	if(num==1 && error==0)printf("Express�o v�lida");
}
