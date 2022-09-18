// #include <stdbool.h>
// #include <limits.h>

#ifndef FILA_H
#define FILA_H

//*===----------------------------< Structs >----------------------------------===*
typedef struct node
{
    int value;
    struct node *next;
} node_t;

typedef struct
{
    node_t *head;
    node_t *tail;
} queue_t;

//*===----------------------------< prototypes >--------------------------------===*

queue_t *q_create();
int q_empty(queue_t *q);
int q_enqueue(queue_t *q, int value);
int q_push(queue_t *q, int value);
int q_dequeue(queue_t *q);
int q_pop(queue_t *q);
int q_size(queue_t *q);
int q_front(queue_t *q);
int q_back(queue_t *q);

#endif
