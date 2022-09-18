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
} queue_t;
//*===----------------------------< Funcoes >---------------------------------===*

queue_t *q_create(int max_size)
{
	queue_t *q = (queue_t *)malloc(sizeof(queue_t));
	q->size = max_size;
	q->vector = (int *)malloc(sizeof(int) * max_size);
	q->num = 0;
	q->head = 0;
	q->tail = -1;

	return q;
}
//*===------------------------------------------------------------------------===*
int q_empty(queue_t *q)
{
	return (q->num == 0);
}
//*===------------------------------------------------------------------------===*
int q_full(queue_t *q)
{
	return (q->num == q->size);
}
//*===------------------------------------------------------------------------===*

void q_destroy(queue_t *q)
{
	free(q->vector);
	free(q);
}

//*===------------------------------------------------------------------------===*

int q_enqueue(queue_t *q, int value)
{
	if (q_full(q))
		return 0;

	q->vector[++q->tail] = value;
	q->num++;

	q->tail = q->tail % q->size;

	return 1;
}
//*===------------------------------------------------------------------------===*
int q_push(queue_t *q, int value)
{
	return q_enqueue(q, value);
}
//*===------------------------------------------------------------------------===*
int q_dequeue(queue_t *q)
{
	int tmp;

	if (q_empty(q))
		return 0;

	tmp = q->vector[q->head++];
	q->head = q->head % q->size;
	q->num--;

	return tmp;
}
//*===------------------------------------------------------------------------===*
int q_pop(queue_t *q)
{
	return q_dequeue(q);
}
//*===------------------------------------------------------------------------===*
int q_size(queue_t *q)
{
	return q->size;
}
//*===------------------------------------------------------------------------===*
int q_front(queue_t *q)
{
	return q->vector[q->head];
}
//*===------------------------------------------------------------------------===*
int q_back(queue_t *q)
{
	return q->vector[q->tail];
}

//*===------------------------------------------------------------------------===*
