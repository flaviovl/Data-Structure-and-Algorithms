#include <stdio.h>
#include <stdlib.h>
#include "graph_adj_matrix.h"
// #include "../queue/queue_ll.h"

#define MAX_VERTEX 7

// #include "graph_adj_list.h"
// #include "graph_comp_list.h"

//*===--------------------------< prototypes >--------------------------------===*

// queue_t *q_create();
// int q_empty(queue_t *q);
// int q_enqueue(queue_t *q, int value);
// int q_push(queue_t *q, int value);
// int q_dequeue(queue_t *q);
// int q_pop(queue_t *q);
// int q_size(queue_t *q);
// int q_front(queue_t *q);
// int q_back(queue_t *q);
//*===-----------------------------< Main >-----------------------------------===*

int main()
{
    int i, j;
    graph_t *g1 = create_graph(MAX_VERTEX);

    int a[MAX_VERTEX][MAX_VERTEX] = {{0, 0, 0, 0, 0, 0, 0},
                                     {0, 0, 1, 1, 0, 0, 0},
                                     {0, 1, 0, 0, 1, 0, 0},
                                     {0, 1, 0, 0, 1, 0, 0},
                                     {0, 0, 1, 1, 0, 1, 1},
                                     {0, 0, 0, 0, 1, 0, 0},
                                     {0, 0, 0, 0, 1, 0, 0}};

    for (i = 0; i < MAX_VERTEX; i++)
        for (j = 0; j < MAX_VERTEX; j++)
            if (a[i][j])
                add_edge(g1, i, j);

    print_graph(g1);
    destroy_graph(g1);

    return (EXIT_SUCCESS);
}
