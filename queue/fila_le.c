#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//*===----------------------------< Global >----------------------------------===*

typedef struct reg
{
	int valor;
	struct reg *prox;

} celula;

static celula *fila;

//*===----------------------------< Funcoes >---------------------------------===*

void criaFila()
{
	fila = (celula *)malloc(sizeof(celula));
	fila->prox = fila;
	fila->valor = 0;
}
//*===------------------------------------------------------------------------===*
int inseriFila(int y)
{
	celula *novo = (celula *)malloc(sizeof(celula));

	if (novo == NULL)
		return -1;

	novo->valor = fila->valor + 1;
	novo->prox = fila->prox;
	fila->prox = novo;
	fila->valor = y;
	fila = novo;

	return 1;
}
//*===------------------------------------------------------------------------===*
int removeFila(int *y)
{
	if (filaVazia())
		return 0;

	celula *temp;
	temp = fila->prox;
	*y = temp->valor;
	fila->valor = fila->valor - 1;
	fila->prox = temp->prox;
	free(temp);
	return 1;
}
//*===------------------------------------------------------------------------===*
int filaCheia()
{
	return 0;
}
//*===------------------------------------------------------------------------===*
int filaVazia()
{
	return fila->prox == fila; // true (1) fila vazia
}
//*===------------------------------------------------------------------------===*
int tamanhoFila()
{
	return fila->valor;
}
//*===------------------------------------------------------------------------===*
void printFila()
{

	celula *tp;
	tp = fila->prox;
	while (tp != fila)
	{
		printf("+---------+\n");
		printf("|%3d|*prox|\n", tp->valor);
		tp = tp->prox;
		printf("+---------+\n");
		printf("        |\n");
		printf("        V\n");
	}

	if (filaVazia())
	{
		puts("\n\n\t+------------------------+");
		puts("\t| --->  Fila Vazia !!    |");
		puts("\t+------------------------+");
	}

	getchar();
}
//*===------------------------------------------------------------------------===*
