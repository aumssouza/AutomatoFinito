//bibliotecas
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

//variáveis globais
int num=0;
int state[5]={0,1,2,3,4};

//Dsenho do autômato
void draw(){
	system("cls");
	printf("Autômato a ser trabalhado: \n\n");
	printf("     c /->S1---->|b    \n");
	printf("      /    ^     |  \n");
	printf("a[S0-¦    b|     ¦-S2<-\n");
	printf("     |     |    / b\n");
	printf("    a|<---S3-<-/ \n");
	printf("         c||c\n");
	printf("        a[S4<-\n \n");
	printf("o uso de [ representa um loop\n");
	printf("=====\n");
	printf("Estado inicial: S0\n");
	printf("Estado atual: S%d\n________\n", num);
}

//main
main(){
	setlocale(LC_ALL, "Portuguese"); //colocando o idioma em pt-br para usar acentos
	char change; //entrada do usuário
	char seq[]=""; //montagem da expressão
	int exit=1;
	int error=0;
	char l;
	num=state[0];
	while(exit!=0){
		draw();
		l=getch();
		printf("Digite um valor reconhecido pelo autômato: ");
		scanf("%c",&change);
		//inputs inválidas
	/*	if(num==0 && (change!='a' || change!='c')||
			 num==1 && change!='b' ||
			 num==2 && change!='b' || 
			 num==3 && change!='a' || num==3 && change!='b' || num==3 && change!='c' ||
			 num==4 && change!='a' || num==4 && change!='c') { 
			printf("Valor não reconhecido\n"); 
			printf("------\n");
			exit=0;
			error=1;
			strncat(seq, &change, 1);
		}*/
		//S0
		if((num==0) && (change=='a')) {
			num=state[0];
			draw();
		}
		if((num==0) && (change=='c')) {
			num=state[1];
			draw();
		}
		//S1
		if((num==1) && (change=='b')) {
			num=state[2];
			draw();
		}
		//S2
		if((num==2) && (change=='b')) {
			num=state[3];
			draw();
		}
		//S3
		if((num==3) && (change=='a')) {
			num=state[0];
			draw();
		}
		if((num==3) && (change=='b')) {
			num=state[1];
			draw();
		}
		if((num==3) && (change=='c')) {
			num=state[4];
			draw();
		}
		//S4
		if((num==4) && (change=='a')) {
			num=state[4];
			draw();
		}
		if((num==4) && (change=='c')) {
			num=state[3];
			draw();
		}
		if(error==0){
			strncat(seq, &change, 1);
			printf("Para encerrar as entradas digite 0\nPara continuar apenas digite 1\n");
			scanf(" %d",&exit);
			printf("------\n");	
		}
	}
	printf("Expressão gerada: %s\n", seq);
	if(num==0 || num==1 || num==3 || error==1)printf("Expressão inválida");
	if((num==2 || num==4 ) && error==0)printf("Expressão válida");
}
