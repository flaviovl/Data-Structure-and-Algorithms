#ifndef GRAPH_ADJ_MATRIX_H_
#define GRAPH_ADJ_MATRIX_H_

typedef struct graph graph_t;

graph_t *create_graph(int num_vertex);
void destroy_graph(graph_t *g);
void print_graph(graph_t *g);
void print_disgraph(graph_t *g);
int add_edge(graph_t *g, int from_node, int to_node);
int has_edge(graph_t *g, int from_node, int to_node);

#endif
