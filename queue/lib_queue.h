// Header File

#ifndef FILA_H
#define FILA_H

Queue *queue();
int empty(Queue *q);
int enqueue(Queue *q, int value);
int push(Queue *q, int value);
int dequeue(Queue *q);
int pop(Queue *q);
int size(Queue *q);
int front(Queue *q);
int back(Queue *q);

#endif
