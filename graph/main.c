#include <stdio.h>
#include <stdlib.h>
#include "graph_adj_matrix.h"
#include "../queue/queue_ll.h"

// #include "graph_adj_list.h"
// #include "graph_comp_list.h"

//*===----------------------------< Global >----------------------------------===*
typedef struct Node
{
    int data;
    struct Node *next;
} node_t;

//*===--------------------------< prototypes >--------------------------------===*

queue_t *q_create();
int q_empty(queue_t *q);
int q_enqueue(queue_t *q, int value);
int q_push(queue_t *q, int value);
int q_dequeue(queue_t *q);
int q_pop(queue_t *q);
int q_size(queue_t *q);
int q_front(queue_t *q);
int q_back(queue_t *q);
//*===-----------------------------< Main >-----------------------------------===*

int main()
{

    return (EXIT_SUCCESS);
}
//*===--------------------------< Sub Funcoes >-------------------------------===*
//*===----------------------------< Funcoes >---------------------------------===*

//*===------------------------------------------------------------------------===*

//*===------------------------------------------------------------------------===*
//*===------------------------------------------------------------------------===*
//*===------------------------------------------------------------------------===*
