#include <stdio.h>
#include <stdlib.h>
#include "queue_ll.h"

//*===----------------------------< Funcoes >---------------------------------===*
queue_t *q_create()
{
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));

    q->head = NULL;
    q->tail = NULL;

    return q;
}
//*===------------------------------------------------------------------------===*
int q_empty(queue_t *q)
{
    return q->head == NULL;
}
//*===------------------------------------------------------------------------===*
int q_enqueue(queue_t *q, int value)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    if (newnode == NULL)
        return 0;

    newnode->value = value;
    newnode->next = NULL;

    if (q->head == NULL)
        q->head = newnode;

    if (q->tail != NULL)
        q->tail->next = newnode;

    q->tail = newnode;

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
    if (q_empty(q))
        return 0;

    node_t *tmp = q->head;
    int value = tmp->value;

    q->head = q->head->next;

    if (q->head == NULL)
        q->tail = NULL;

    free(tmp);
    return value;
}
//*===------------------------------------------------------------------------===*
int q_pop(queue_t *q)
{
    return q_dequeue(q);
}
//*===------------------------------------------------------------------------===*
int q_size(queue_t *q)
{
    int i = 0;
    if (q_empty(q))
        return i;

    node_t *p = q->head;

    while (p != NULL)
    {
        i++;
        p = p->next;
    }

    return i;
}
//*===------------------------------------------------------------------------===*
int q_front(queue_t *q)
{
    return q->head->value;
}
//*===------------------------------------------------------------------------===*
int q_back(queue_t *q)
{
    return q->tail->value;
}
//*===------------------------------------------------------------------------===*
