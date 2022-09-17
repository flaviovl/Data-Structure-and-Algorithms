#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//*===--------------------------< Prototipos >--------------------------------===*

void menu();
char leValidaOpcao();
void inserir();
void remover();
void imprimir();

//*===-----------------------------< Main >-----------------------------------===*

int main(int argc, char **argv)
{
	criaFila();
	char opcao;

	do
	{
		menu();
		opcao = leValidaOpcao();
		switch (opcao)
		{
		case '1':
			inserir();
			break; // Inserir Elementos
		case '2':
			remover();
			break; // Remover elementos
		case '3':
			imprimir();
			break; // Imprimir elementos
		}
	} while (opcao != '4');

	puts("\n\n---> Finalizando programa.........");
	puts("\n\n===================================================================================================\n");
	getchar();
	return 0;
} // fim da main

//*===--------------------------< Sub Funcoes >-------------------------------===*
//  Objetivo:  Apresentar menu

void menu(void)
{
	// system ("cls");
	printf("\e[H\e[2J"); // limpa a tela

	puts("\n==================================================================");
	puts("\t\t    ESTRUTURA DE DADOS - FILA");
	puts("==================================================================\n\n");
	puts("\t +-------------------------------------+");
	puts("\t | --> Escolha uma das opcoes abaixo   |");
	puts("\t +-------------------------------------+");
	puts("\t |  1. Inserir elementos na fila       |");
	puts("\t |  2. Remover elementos na fila       |");
	puts("\t |  3. Imprimir a fila                 |");
	puts("\t |  4. Sair                            |");
	puts("\t +-------------------------------------+");
}
// //*===------------------------------------------------------------------------===*
//  Objetivo  : Ler e validar Opcao do menu
//  retorno   :	Opcao validada
char leValidaOpcao()
{
	char op, controle;
	int i = 1;
	do
	{
		printf("\n\tSelecione uma opcao [1-4]: _\b");
		scanf(" %c%*[^\n]", &op);

		if (op < '0' || op > '4')
		{
			puts("\t ** Opcao invalida! **");
			getchar();
		}
		else if (op != '4')
			return op;
		else // op == 4 (sair)
		{
			printf("\e[H\e[2J");
			puts("\n\n==================================================================\n");
			printf("\t[S] ---> Sim - \n\t[N] ---> Retornar\n\n\t\t Deseja realmente sair: _\b");
			scanf(" %c%*[^\n]", &controle);

			if (controle == 's' || controle == 'S')
				return op;
			i = 0;
			puts("\n\n------------> Pressione uma tecla para voltar ao menu inicial");
			puts("\n\n==================================================================\n");
			getchar();
			getchar();
		}
	} while (i);
	return op;
}
// //*===------------------------------------------------------------------------===*
//  Objetivo  : Inserir elementos na fila

void inserir()
{
	int num, temp;
	char op;

	temp = tamanhoFila();

	do
	{
		system("clear");
		puts("\n==================================================================");
		puts("  ==>>  1. Inserir elementos na fila\n");

		printf("\n\t>> Insira o numero inteiro: ___\b\b\b");
		scanf(" %d%*[^\n]", &num);

		if (inseriFila(num))
		{
			printf("\n\t%dª Elemento --> inserido com sucesso!\n", ++temp);
			getchar();
		}
		else
		{
			puts("\tNao foi possivel inserir na fila (Fila Cheia)\n");
			getchar();
		}
		printf("\n\nDeseja inserir outro elemento [S]sim ou [N] não: ");
		scanf(" %c", &op);
	} while (op == 's' || op == 'S');

	puts("\n\n------------> Pressione uma tecla para voltar ao menu inicial");
	puts("==================================================================");
	getchar();
}
//*===------------------------------------------------------------------------===*
//  Objetivo  : Remover elementos na fila

void remover()
{
	int y;
	char op;

	do
	{
		system("clear");
		puts("\n==================================================================");
		puts("\n\t==>>  2. Remover elementos na fila\n");

		if (removeFila(&y))
			printf("\t>> Elemento [%2d] removido com sucesso!\n", y);

		else
			puts("\n\n\t--->Nao foi possivel remover mais elementos! (Fila vazia)");

		printf("\n\nDeseja remover outro elemento [S]sim ou [N] não: ");
		scanf(" %c", &op);
	} while (op == 's' || op == 'S');

	puts("\n\n------------> Pressione uma tecla para voltar ao menu inicial");
	puts("==================================================================");
	getchar();
}
//*===------------------------------------------------------------------------===*
//  Objetivo  : Imprimir elementos na fila
void imprimir()
{
	system("clear");
	puts("\n==================================================================\n");
	puts("\t==>>  3. Imprimir a fila \n");

	printFila();

	puts("\n\n------------> Pressione uma tecla para voltar ao menu inicial");
	puts("==================================================================");
	getchar();
}
//*===------------------------------------------------------------------------===*
