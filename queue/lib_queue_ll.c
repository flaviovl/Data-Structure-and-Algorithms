#include <stdio.h>
#include <stdlib.h>
#include "lib_queue.h"

//*===----------------------------< Global >----------------------------------===*

typedef struct node
{
    int value;
    struct node *next;

} Node;

typedef struct
{
    Node *head;
    Node *tail;
} Queue;

// static Queue *queue;

//*===----------------------------< Funcoes >---------------------------------===*

Queue *queue()
{
    Queue *queue = malloc(sizeof(Queue));

    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}
//*===------------------------------------------------------------------------===*
int empty(Queue *q)
{
    return q->head == NULL;
}
//*===------------------------------------------------------------------------===*
int enqueue(Queue *q, int value)
{
    Node *newnode = malloc(sizeof(Node));
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
int push(Queue *q, int value)
{
    return enqueue(q, value);
}
//*===------------------------------------------------------------------------===*
int dequeue(Queue *q)
{
    if (empty(q))
        return 0;

    Node *tmp = q->head;
    int value = tmp->value;

    q->head = q->head->next;

    if (q->head == NULL)
        q->tail = NULL;

    free(tmp);
    return value;
}
//*===------------------------------------------------------------------------===*
int pop(Queue *q)
{
    return dequeue(q);
}
//*===------------------------------------------------------------------------===*
int size(Queue *q)
{
    int i = 0;
    if (empty(q))
        return i;

    Node *p = q->head;

    while (p != NULL)
    {
        i++;
        p = p->next;
    }

    return i;
}
//*===------------------------------------------------------------------------===*
int front(Queue *q)
{
    return q->head->value;
}
//*===------------------------------------------------------------------------===*
int back(Queue *q)
{
    return q->tail->value;
}

//*===------------------------------------------------------------------------===*
int main()
{
    Queue *a1 = queue();
    Node *tmp;

    push(a1, 10);
    enqueue(a1, 20);
    push(a1, 30);

    tmp = a1->head;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }

    printf("front = %d\n", front(a1));
    printf("pop   = %d\n", pop(a1));
    printf("front = %d\n", front(a1));
    printf("pop   = %d\n", dequeue(a1));

    printf("front = %d\n", front(a1));
    printf("back  = %d\n", back(a1));

    return 0;
}

//*===------------------------------------------------------------------------===*
