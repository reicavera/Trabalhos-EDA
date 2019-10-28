#include<stdlib.h>
#include "stack.h"
#include "node.h"
stack** create_stack(long long m){
    //dado um número m,é criado um vetor com m pilhas vazias.
    stack** aux=NULL;
    aux=malloc(sizeof(stack*)*m);
    if(aux==NULL)
        return NULL;
    for(long long i=0;i<m;i++){
        aux[i]=NULL;
        aux[i]=malloc(sizeof(stack));
        if(aux[i]==NULL)
            return NULL;
        aux[i]->top=NULL;
        aux[i]->counter=0;
    }
    return aux;
}
long long stack_size(stack* s){
    //Retorna o numero de elementos da pilha.
    return s->counter;
}
long long empty_stack(stack* s){
    //Retorna 1 caso a pilha esteja vazia e 1 caso possua algum elemento.
    if(s->top==NULL)
        return 1;
    return 0;
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
void destroy_stack(stack** s,long long m){
    //Para cada pilha do vetor,desaloca o espaço na memória de todos os elementos presentes na pilha e desaloca a pilha
    //em si.Após isso o vetor em si é desalocado.
    node_p* n1;
    for(int i=0;i<m;i++){
        while(s[i]->top!=NULL){
            n1=remove_stack(s[i]);
            destroy_node_p(n1);
        }
        free(s[i]);
    }
    free(s);
    s=NULL;
}
