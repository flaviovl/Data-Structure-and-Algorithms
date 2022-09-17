#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//*===----------------------------< Global >----------------------------------===*

static int p, u, N;
static int *fila;

//*===----------------------------< Funcoes >---------------------------------===*

void criaFila()
{
	p = 0;
	u = 0;
	N = 10;

	fila = (int *)malloc(N * sizeof(int));
}

//*===------------------------------------------------------------------------===*

int inseriFila(int y)
{
	if (filaCheia())
		return 0;

	fila[u++] = y;
	if (u == N)
		u = 0;

	return 1;
}

//*===------------------------------------------------------------------------===*

int removeFila(int *y)
{
	if (filaVazia())
		return 0;
	*y = fila[p++];
	if (p == N)
		p = 0;
	return 1;
}

//*===------------------------------------------------------------------------===*

int filaCheia()
{
	if ((u + 1) % N == p)
	{
		N *= 2;
		fila = realloc(fila, N * sizeof(int));
		if (fila == NULL)
			return -1;
	}
	return 0;
}

//*===------------------------------------------------------------------------===*

int filaVazia()
{
	return (p == u); // true (1) fila vazia
}

//*===------------------------------------------------------------------------===*

int tamanhoFila()
{
	if (u < p)
		return p + u;
	else
		return u + 1;
}

//*===------------------------------------------------------------------------===*

void printFila()
{
	int i, j, k, l;
	j = (p + 1) * 4 - 1; // posicao de p
	k = (u - p) * 4 - 1; // posicao de u
	l = (N * 4) - 1;	 // quantidade de '-'

	printf("+");
	for (i = 0; i < l; i++)
		printf("-");
	printf("+\n");

	for (i = 0; i < N; i++)
		if (i < u)
			printf("|%3d", fila[i]);
		else
			printf("|xxx");
	puts("|");

	printf("+");
	for (i = 0; i < l; i++)
		printf("-");
	printf("+\n");

	for (i = 0; i < j - 1; i++)
		printf(" ");
	printf("p");

	for (i = 0; i < k; i++)
		printf(" ");
	printf("u");

	if (filaVazia())
	{
		puts("\n\n\t+------------------------+");
		puts("\t| --->  Fila Vazia !!    |");
		puts("\t+------------------------+");
	}
	printf("\n\n  u = %d", u);
	printf("\n  p = %d", p);

	getchar();
}

//*===------------------------------------------------------------------------===*
