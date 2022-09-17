#include <stdio.h>
#include <stdlib.h>
// #include "lib_queue.h"

//*===----------------------------< Global >----------------------------------===*

typedef struct
{
	int *vector;
	int head;
	int tail;
	int size;
	int num;
} Queue;
//*===----------------------------< Funcoes >---------------------------------===*

Queue *queue()
{
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	return queue;
}

void init_queue(Queue *q, int max_size)
{
	q->size = max_size;
	q->vector = (int *)malloc(sizeof(int) * max_size);
	q->num = 0;
	q->head = 0;
	q->tail = -1;
}
//*===------------------------------------------------------------------------===*
int empty(Queue *q)
{
	return (q->num == 0);
}
//*===------------------------------------------------------------------------===*
int full(Queue *q)
{
	return (q->num == q->size);
}
//*===------------------------------------------------------------------------===*

void destroy(Queue *q)
{
	free(q->vector);
	free(q);
}

//*===------------------------------------------------------------------------===*

int enqueue(Queue *q, int value)
{
	if (full(q))
		return 0;

	q->vector[++q->tail] = value;
	q->num++;

	q->tail = q->tail % q->size;

	return 1;
}
//*===------------------------------------------------------------------------===*
int push(Queue *q, int value)
{
	return enqueue(q, value);
}
//*===------------------------------------------------------------------------===*
int dequeue(Queue *q)
{
	int tmp;

	if (empty(q))
		return 0;

	tmp = q->vector[q->head++];
	q->head = q->head % q->size;
	q->num--;

	return tmp;
}
//*===------------------------------------------------------------------------===*
int pop(Queue *q)
{
	return dequeue(q);
}
//*===------------------------------------------------------------------------===*
int size(Queue *q)
{
	return q->size;
}
//*===------------------------------------------------------------------------===*
int front(Queue *q)
{
	return q->vector[q->head];
}
//*===------------------------------------------------------------------------===*
int back(Queue *q)
{
	return q->vector[q->tail];
}

//*===------------------------------------------------------------------------===*
int main()
{
	Queue *a1 = queue();
	init_queue(a1, 50);
	int t;

	push(a1, 10);
	enqueue(a1, 20);
	push(a1, 30);

	while ((t = dequeue(a1)) != 0)
		printf("t = %d\n", t);
	printf("\n\n==========================================\n\n");

	printf("front = %d\n", front(a1));
	printf("back  = %d\n", back(a1));
	push(a1, 10);
	printf("front = %d\n", front(a1));
	printf("back  = %d\n", back(a1));
	enqueue(a1, 20);
	printf("front = %d\n", front(a1));
	printf("back  = %d\n", back(a1));
	enqueue(a1, 30);
	push(a1, 40);

	printf("\n\n==========================================\n\n");

	printf("front = %d\n", front(a1));
	printf("pop   = %d\n", pop(a1));
	printf("front = %d\n", front(a1));
	printf("pop   = %d\n", dequeue(a1));

	printf("front = %d\n", front(a1));
	printf("back  = %d\n", back(a1));

	return 0;
}

//*===------------------------------------------------------------------------===*
//*===------------------------------------------------------------------------===*
