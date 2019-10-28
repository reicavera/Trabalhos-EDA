#include<stdlib.h>
#include "queue.h"
queue* create_queue(long long n){
     //Cria uma fila circular estática. Seus elementos são nós padrões
    queue* aux=NULL;
    aux=malloc(sizeof(queue));
    if(aux==NULL)
        return NULL;
    aux->data=malloc(sizeof(node_p)*n);
    if(aux->data==NULL)
        return NULL;
    aux->max_size=n;
    aux->size=0;
    aux->front=0;
    aux->bottom=0;
    return aux;
}
void add_queue(queue* f,long long scpfc,long long scpft,char sop,long long svalor){
    //Coloca os valores do cpf cliente,cpf terceiro,valor e a operação no fundo da fila,
    //muda o novo fundo para o próximo elemento e incrementa em 1 o indicador do tamanho
    //atual da fila.
    f->data[f->bottom].cpfc=scpfc;
    f->data[f->bottom].cpft=scpft;
    f->data[f->bottom].op=sop;
    f->data[f->bottom].valor=svalor;
    f->bottom=(f->bottom+1)%f->max_size;
    f->size++;
}
node_p* remove_queue(queue* f){
    //Remove elemento da fila. Retorna o nó padrão removido.
    node_p* aux;
    aux=create_node_p();
    aux->cpfc=f->data[f->front].cpfc;
    aux->cpft=f->data[f->front].cpft;
    aux->op=f->data[f->front].op;
    aux->valor=f->data[f->front].valor;
    f->front=(f->front+1)%f->max_size;
    f->size--;
    return aux;
}
void destroy_queue(queue* f){
     //Desaloca a fila e seus elementos. Não retorna nada.
    free(f->data);
    f->data=NULL;
    free(f);
    f=NULL;
}
