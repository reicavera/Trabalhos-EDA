#ifndef QUEUE
#define QUEUE
#include<stdlib.h>
#include "node.h"
#include "queue.h"

struct queue{
    //Registro de fila que contém indicadores do tamanho máximo e atual,
    //da frete e do fundo da fila e um ponteiro para alocar os elementos.
    node_p* data;
    long long max_size,size,front,bottom;
};
typedef struct queue queue;
queue* create_queue(long long n);//cria uma fila com tamanho n.
void add_queue(queue* f,long long scpfc,long long scpft,char sop,long long svalor);//Adiciona no fundo da fila
//as informações de cpf do cliente,cpf de terceiros,valor e o tipo de operação.
node_p* remove_queue(queue* f);//Remove a frente da fila e retorna um nó padrão com os dados da casa removida. 
void destroy_queue(queue* f);//Desaloca o vetor com os dados e a fila em si. 

#endif
