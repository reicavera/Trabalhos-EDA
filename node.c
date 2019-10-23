#include<stdlib.h>
#include "node.h"
node_p* create_node_p(){
    //Um auxiliar aloca espaço para um Nó padrão e retorna um endereço para o mesmo.
    node_p* aux;
    aux=malloc(sizeof(node_p));
    return aux;
}
void destroy_node_p(node_p* n){
    //Recebe o endereço de um Nó padrão e desaloca o espaço ocupado por ele.
    free(n);
}
node_l* create_node_l(){
     //Um auxiliar aloca espaço para um Nó de lista(Inicia o número de operações desse
    //Nó com uma operação e retorna o endereço do Nó alocado.
    node_l* n;
    n=malloc(sizeof(node_l));
    n->nop=1;
    return n;
}
void destroy_node_l(node_l* n){
     //Desaloca o espaço ocupado por esse Nó na memória.
    free(n);
}
