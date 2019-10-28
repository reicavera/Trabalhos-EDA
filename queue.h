#include<stdlib.h>
#include "queue.h"
#include "node.h"
#ifndef QUEUE
#define QUEUE

struct queue{
    //Registro de fila que contém indicadores do tamanho máximo e atual,
    //da frete e do fundo da fila e um ponteiro para alocar os elementos.
    node_p* data;
    long long max_size,size,front,bottom;
};
queue* create_queue(long long n);
void add_queue(queue* f,long long scpfc,long long scpft,char sop,long long svalor);
node_p* remove_queue(queue* f);
void destroy_queue(queue* f);

#endif
