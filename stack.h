#ifndef STACK
#define STACK
#include<stdlib.h>
#include "node.h"
#include "stack.h"

struct stack{
    //Registro de dados de uma pilha que contém:
    //Um ponteiro para o topo da pilha e um contador
    //para o número de elementos nessa pilha.
    node_p* top;
    long long counter;
};
typedef struct stack stack;
stack** create_stack(long long m);//cria uma pilha vazia e a retorna.
long long stack_size(stack* s);//Retorna no numero de elementos da pilha dada.
long long empty_stack(stack* s);//Retorna 1 se a pilha está vazia e 0 caso possua algum elemento. 
void add_stack(stack* s,node_p* n);//adiciona um nó padrão no topo da pilha.
node_p* remove_stack(stack* s);//Remove o topo da fila e o retorna.
void destroy_stack(stack** s,long long m);//desaloca a pilha e todos os seus elementos.

#endif
