#include<stdlib.h>
#include "node.h"
node_p* create_node_p(){
    //Um auxiliar aloca espaço para um Nó padrão e retorna um endereço para o mesmo.
    node_p* aux=NULL;
    aux=malloc(sizeof(node_p));
    if(aux==NULL)
        return NULL;
    return aux;
}
long long node_p_display_cpfc(node_p* p){
    return p->cpfc;
}
long long node_p_display_cpft(node_p* p){
    return p->cpft;
}
long long node_p_display_valor(node_p* p){
    return p->valor;
}
char node_p_display_op(node_p* p){
    return p->op;
}
void destroy_node_p(node_p* n){
    //Recebe o endereço de um Nó padrão e desaloca o espaço ocupado por ele.
    free(n);
    n=NULL;
}
node_l* create_node_l(){
    //Um auxiliar aloca espaço para um Nó de lista(Inicia o número de operações desse
    //Nó com uma operação e retorna o endereço do Nó alocado.
    node_l* n=NULL;
    n=malloc(sizeof(node_l));
    if(n==NULL)
        return NULL;
    n->nop=1;
    return n;
}
long long node_l_display_cpf(node_l* n){
    return n->cpf;
}
long long node_l_display_nop(node_l* n){
    return n->nop;
}
long long node_l_display_balance(node_l* n){
    return n->balance;
}
void destroy_node_l(node_l* n){
     //Desaloca o espaço ocupado por esse Nó na memória.
    free(n);
    n=NULL;
}
