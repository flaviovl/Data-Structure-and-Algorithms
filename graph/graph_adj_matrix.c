
#include <stdio.h>
#include <stdlib.h>

#define MAXV 10000

//*===----------------------------< Global >----------------------------------===*
typedef struct Node
{
    int data;
    struct Node *next;
} node_t;

//*===--------------------------< Prototipos >--------------------------------===*
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

typedef struct
{
    int v;
    int w;
    int value;
} Edge;

struct graph
{
    int V;
    int E;
    int **adj;
};
typedef struct graph Graph;

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

static int cnt, pre[MAXV];

//*===-------------------------- Prototipos --------------------------------===*
Edge *EDGE(int v, int w);
Graph *GRAPHinit(int v); // qtd de vertices
int **MATRIXint(int line, int column, int value);
void GRAPHinsertE(Graph *G, int v, int w);
void GRAPHshow(Graph *G);
int GRAPHsearch(Graph *G);

int GRAPHEdges(Edge[], Graph G);

void DFS(Graph *G, int v, int w);

void BFS(int G[][7], int start, int n);
void enqueue(int x);
int dequeue();
int isEmpty();

//*===------------------------------ Main  ---------------------------------===*
int main()
{
    // int Gr[7][7]={{0,0,0,0,0,0,0},
    //              {0,0,1,1,0,0,0},
    //              {0,1,0,0,1,0,0},
    //              {0,1,0,0,1,0,0},
    //              {0,0,1,1,0,1,1},
    //              {0,0,0,0,1,0,0},
    //              {0,0,0,0,1,0,0}};

    // DFS(Gr,4,7);

    int V, v, w, ne;
    Graph *G;

    scanf("%d", &V);
    G = GRAPHinit(V);

    ne = 0;
    while (scanf("%d %d", &v, &w) != EOF)
    {
        GRAPHinsertE(G, v, w);
        ne++;
    }
    printf("*===-----------------------------------------------------===*\n");
    printf("ne = %d\n", ne);
    printf("*===-----------------------------------------------------===*\n");
    GRAPHshow(G);
    printf("*===-----------------------------------------------------===*\n\n");
    printf("return GS = %d\n", GRAPHsearch(G));

    // DFSr(G, EDGE(0, 0));

    return 0;
}

//*===---------------------------- Sub Funcoes -----------------------------===*
Graph *GRAPHinit(int V)
{
    Graph *G = malloc(sizeof(Graph));
    G->V = V;
    G->E = 0;
    G->adj = MATRIXint(V, V, 0); // alocar matriz e iniciar com 0
    return G;
}

//*===----------------------------------------------------------------------===*
int **MATRIXint(int line, int column, int value)
{
    int i, j;
    int **m = malloc(line * sizeof(int *));

    for (i = 0; i < line; ++i)
        m[i] = malloc(column * sizeof(int));

    for (i = 0; i < line; ++i)
        for (j = 0; j < column; ++j)
            m[i][j] = value;

    return m;
}
//*===----------------------------------------------------------------------===*
void GRAPHinsertE(Graph *G, int v, int w)
{
    if (G->adj[v][w] == 0)
    {
        G->adj[v][w] = 1;
        G->E++;
    }
}

//*===----------------------------------------------------------------------===*
void GRAPHremoveE(Graph *G, int v, int w)
{
    if (G->adj[v][w] == 1)
    {
        G->adj[v][w] = 0;
        G->E--;
    }
}
//*===----------------------------------------------------------------------===*
void GRAPHshow(Graph *G)
{
    int v;
    for (v = 0; v < G->V; ++v)
    {
        printf("%2d:", v);

        for (int w = 0; w < G->V; ++w)
            if (G->adj[v][w] == 1)
                printf(" %2d", w);
        printf("\n");
    }
}
//*===----------------------------------------------------------------------===*
// void DFS(int G[][7],int start,int n)
void DFS(Graph *G, int v, int w)
{
    int j;

    if (pre[v] == -1)
    {
        printf("%d ", v);
        pre[v] = 1;

        for (j = 0; j < G->V; j++)
        {
            if (G->adj[v][j] == 1 && pre[j] == -1)
                DFS(G, j, w);
        }
    }
}
//*===----------------------------------------------------------------------===*
void DFSr(Graph *G, int v, int id)
{
    int t;
    pre[v] = id;

    for (t = 0; t < G->V; t++) // percorrer todo o conjunto de vertices
        if (G->adj[v][t] != 0)
            if (pre[t] == -1)
                DFSr(G, t, id);
}

//*===----------------------------------------------------------------------===*
int GRAPHsearch(Graph *G)
{
    int v, id;
    cnt = id = 0;
    printf("G->V = %d\n", G->V);

    for (v = 0; v < G->V; v++)
        pre[v] = -1;

    for (v = 0; v < G->V; v++)
    {
        printf("pre[%d]= %d\n", v, pre[v]);
        if (pre[v] == -1)
        {
            printf("DFSr(v = %d, w = %d)\n", v, id);

            // DFS(G, v, id++);
            DFSr(G, v, id++);
            printf("cnt   = %d\n\n", cnt);
        }
    }
    printf("cnt = %d <> id  = %d\n", cnt, id);
    return id;
}
//*===----------------------------------------------------------------------===*
Edge *EDGE(int v, int w)
{
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    edge->v = v;
    edge->w = w;

    return edge;
}
// //*===----------------------------------------------------------------------===*
// Edge EDGE(int v, int w, int value)
// {
//     Edge *tmp = (Edge *)  malloc(sizeof(Edge));
//     tmp->v = v;
//     tmp->w = w;
//     tmp->value = value;
// }

//*===----------------------------------------------------------------------===*
//*===----------------------------------------------------------------------===*

int GRAPHedges(Edge a[], Graph G)
{
    // int v, w, e = 0;
    // for(v=0; v < G->V; v++)
    //     for(w = v+1; w<G->V; w++)
    //         a[e++] = EDGE(v, w);

    // return e;
}

//*===----------------------------------------------------------------------===*
void BFS(int G[][7], int start, int n)
{
    int i = start, j;
    int visited[7] = {0};
    printf("%d ", i);
    visited[i] = 1;

    enqueue(i);

    while (!isEmpty())
    {
        i = dequeue();
        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}
//*===----------------------------------------------------------------------===*
void enqueue(int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));

    if (t == NULL)
        printf("Fila cheia! Sem Memoria\n");

    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
//*===----------------------------------------------------------------------===*
int dequeue()
{
    int x = -1;
    struct node *t;
    if (front == NULL)
        printf("Fila Vazia\n");
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}
//*===----------------------------------------------------------------------===*
int isEmpty()
{
    return front == NULL;
}

//*===----------------------------------------------------------------------===*
// int GRAPHconComps( Graph *G)
// {
//    int id = 0;
//    for (int v = 0; v < G->V; ++v)
//       cc[v] = -1;
//    for (int v = 0; v < G->V; ++v)
//       if (cc[v] == -1)
//         //  dfsRconComps( G, v, id++);
//    return id;
// }

//*===----------------------------------------------------------------------===*
// void DFS_Lista(Graph G, Edge e)
// {
//     int t, w = e.w;
//     link l;
//     pre[w] = cnt++;

//     for(l = G->adj[w; l != NULL; l=l->next)  // percorrer todo o conjunto de vertices
//     {
//         t=l->v;
//         if(pre[t] == -1)
//             DFSr(G, EDGE(w, t));
//     }
