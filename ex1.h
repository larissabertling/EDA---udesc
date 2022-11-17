#include <stdio.h>
#include <stdlib.h>

typedef struct queue Queue;
struct queue{
    int valor;
    Queue *prox, *ant;
};

typedef struct aux deque;
struct aux{
    Queue *frente, *tras;
};

deque * addFrente(deque *r, int a);
deque * addAtras(deque *r, int a);
deque * delFrente(deque *r);
deque * delAtras(deque *r);
