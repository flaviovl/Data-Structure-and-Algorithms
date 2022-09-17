#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

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
}
// //*===------------------------------------------------------------------------===*
//  Objetivo  : Inserir elementos na fila

void inserir()
{
	int dado, i, n, temp;
	system("clear");
	puts("\n==================================================================");
	puts("\n\t==>>  1. Inserir elementos na fila\n");

	temp = tamanhoFila();

	printf("\tDigite quantos elementos deseja inserir: __\b\b");
	scanf(" %d%*[^\n]", &n);

	for (i = 0; i < n; i++)
	{
		printf("\n\tInsira o numero inteiro [0-999] %d: ___\b\b\b", i);
		scanf(" %d%*[^\n]", &dado);

		if (dado < 0 || dado > 999)
		{
			puts("\t-----> ** Valor Invalido ** !!!\n");
			i--;
		}

		else
		{
			if (inseriFila(dado))
			{

				printf("\t---> %d Elemento inserido com sucesso!\n", temp++);
				getchar();
			}
			else
			{
				puts("\tNao foi possivel inserir esse elemento! (Fila Cheia)\n");
				printf("\n\n\t---> %d Elementos inseridos com sucesso!", i);
				i = n;
				getchar();
			}
		}
	}
	//	puts ("\n\n\n ** Todos os elementos inseridos com sucesso!!\n");
	puts("\n\n------------> Pressione uma tecla para voltar ao menu inicial");
	puts("==================================================================");
	getchar();
}
//*===------------------------------------------------------------------------===*
//  Objetivo  : Remover elementos na fila

void remover()
{
	system("clear");
	int n, i, y;
	puts("\n==================================================================");
	puts("\n\t==>>  2. Remover elementos na fila\n");

	printf("\tDigite quantos elementos deseja remover: __\b\b");
	scanf(" %d%*[^\n]", &n);
	getchar();

	for (i = 0; i < n; i++)

		if (removeFila(&y))
		{
			printf("\t>> %2d Elemento [%2d] removido com sucesso!\n", i + 1, y);
		}
		else
		{
			puts("\n\n\t--->Nao foi possivel remover mais elementos! (Fila vazia)");
			printf("\n\t---> %d Elementos removidos com sucesso!!", i);
			i = n;
		}
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
