
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "graph_adj_matrix.h"

//*===--------------------------< Structure >--------------------------------===*
typedef struct graph
{
    int num_vertex;
    bool **edges;

} graph_t;

//*===----------------------------< Funcoes >---------------------------------===*
graph_t *create_graph(int num_vertex)
{
    int i;
    graph_t *g = malloc(sizeof(*g));
    if (g == NULL)
        return NULL;

    g->num_vertex = num_vertex;

    g->edges = calloc(sizeof(bool *), g->num_vertex);
    if (g->edges == NULL)
    {
        free(g);
        return NULL;
    }

    for (i = 0; i < g->num_vertex; i++)
    {
        g->edges[i] = calloc(sizeof(bool *), g->num_vertex);
        if (g->edges[i] == NULL)
        {
            destroy_graph(g);
            return NULL;
        }
    }
    return g;
}
//*===------------------------------------------------------------------------===*
void destroy_graph(graph_t *g)
{
    int i;
    if (g->edges == NULL)
    {
        free(g);
        return;
    }

    for (i = 0; i < g->num_vertex; i++)
        if (g->edges[i]) // != NULL
            free(g->edges[i]);

    free(g->edges);
    free(g);
}
//*===------------------------------------------------------------------------===*
void print_disgraph(graph_t *g)
{
    int from, to;
    printf("digraph {\n");

    for (from = 0; from < g->num_vertex; from++)
        for (to = 0; to < g->num_vertex; to++)
            if (g->edges[from][to])
                printf("%d -> %d;\n", from, to);

    printf("}\n");
}
//*===------------------------------------------------------------------------===*
void print_graph(graph_t *g)
{
    int from, to;
    printf("graph {\n");

    for (from = 1; from < g->num_vertex; from++)
        for (to = from + 1; to < g->num_vertex; to++)
            if (g->edges[from][to])
                printf("%d -- %d;\n", from, to);

    printf("}\n");
}
//*===------------------------------------------------------------------------===*
int add_edge(graph_t *g, int from_node, int to_node)
{
    assert(g != NULL);
    assert(from_node < g->num_vertex);
    assert(to_node < g->num_vertex);

    if (has_edge(g, from_node, to_node))
        return 0;

    g->edges[from_node][to_node] = 1;
    // g->edges[to_node][from_node] = 1;

    return 1;
}
//*===------------------------------------------------------------------------===*
int has_edge(graph_t *g, int from_node, int to_node)
{
    assert(g != NULL);
    assert(from_node < g->num_vertex);
    assert(to_node < g->num_vertex);

    return g->edges[from_node][to_node];
}
//*===------------------------------------------------------------------------===*
