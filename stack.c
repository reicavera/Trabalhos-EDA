#include<stdlib.h>
#include "stack.h"
stack* create_stack(){
    //Um auxiliar aloca espaço espaço para uma pilha vazia e retorna o seu endereço.
    stack* aux;
    aux=malloc(sizeof(stack));
    aux->top=NULL;
    aux->counter=0;
    return aux;
}
void add_stack(stack* s,node_p* n){
    //Coloca o Nó no topo da pilha e Adiciona mais um ao contador de elementos da pilha.
    n->next=s->top;
    s->top=n;
    s->counter++;
}
node_p* remove_stack(stack* s){
    //Guarda o endereço do elemento do topo da pilha em um auxiliar,retira o topo da pilha e
    //subtrai um da quantidade de elementos da pilha.Retorna o endereço do elemento removido.
    node_p* aux;
    aux=s->top;
    s->top=aux->next;
    s->counter--;
    return aux;
}
void destroy_stack(stack* s){
    //Desaloca o espaço na memória de todos os elementos presentes na pilha para depois
    //desalocar o espaço ocupado pela própria pilha.
    node_p* n1;
    for(int i=0;i<3;i++)
        while(s->top!=NULL){
            n1=remove_stack(s);
            destroy_node_p(n1);
        }
    free(s);
}
