#include<stdlib.h>
#include "stack.h"
#ifndef STACK
#define STACK
struct stack{
    //Registro de dados de um pilha que contém:
    //Um ponteiro para o topo da pilha e um contador
    //para o número de elementos nessa pilha.
    node_p* top;
    long long counter;
};
typedef struct stack stack;
stack* create_stack();
void add_stack(stack* s,node_p* n);
node_p* remove_stack(stack* s);
void destroy_stack(stack* s);

#endif