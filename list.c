#include<stdlib.h>
#include "list.h"
#include "node.h"
list* create_list(){
    //Um auxiliar aloca um registro de pilha e retorna o endereço alocado.
    list* l=NULL;
    l=malloc(sizeof(list));
    if(l==NULL)
        return NULL;
    l->first=NULL;
    l->counter=0;
    return l;
}
long long list_size(list* l){
    return l->counter;
}
void search_list(long long valor,long long cpf,list* l){
    //Se a lista está vazia,cria-se um nó de lista que aponta para ele mesmo em ambos os sentidos e o insere como primeiro
    //elemento da lista.Se o cpf é maior que o atual maior ou menor que o atual menor,entao o né criado para ficar entre os
    //dois(caso seja menor que o menor,ele assume o inicio da lista).Caso contrario a lista é percorrida até que se encontre
    //um nó cujo cpf não seja menor que o do que se pretende adicionar.Se os cpfs são iguais,apenas se altera os dados do cpf
    //já existente e caso contrário,é criado um nó que fica entre o nó buscado e seu anterior.
    node_l* aux;
    node_l* n;
    if(l->first==NULL){
        n=create_node_l();
        n->balance=valor;
        n->cpf=cpf;
        n->next=n;
        n->previous=n;
        l->first=n;
        l->counter++;
    }
    else if(cpf>l->first->previous->cpf || cpf<l->first->cpf){
        n=create_node_l();
        n->balance=valor;
        n->cpf=cpf;
        n->next=l->first;
        n->previous=l->first->previous;
        l->first->previous->next=n;
        l->first->previous=n;
        l->counter++;
        if(cpf<l->first->cpf)
            l->first=n;
    }
    else{
        aux=l->first;
        while(aux->cpf<cpf)
            aux=aux->next;
        if(aux->cpf>cpf){
            n=create_node_l();
            n->balance=valor;
            n->cpf=cpf;
            n->next=aux;
            n->previous=aux->previous;
            aux->previous->next=n;
            aux->previous=n;
            l->counter++;
        }
        else{
            aux->nop++;
            aux->balance+=valor;
        }
    }
}
void add_list(list* l,node_p* n)    {
    //retira um nó da pilha e verifica os possíveis casos de mudança na lista baseada
    //na operação bancária armazenda no nó.Retorna o nó padrão retirado da pilha.
    switch(n->op){
        case 'S':
            search_list(-n->valor,n->cpfc,l);
            break;
        case 'D':
            search_list(0,n->cpfc,l);
            search_list(n->valor,n->cpft,l);
            break;
        case 'T':
            search_list(-n->valor,n->cpfc,l);
            search_list(n->valor,n->cpft,l);
            break;
    }
}
node_l* remove_list_first(list* l){
    //Retira e retorna o primeiro elemento da lista.
    node_l* aux;
    aux=l->first;
    if(l->counter==1){
        l->first=NULL;
    }
    else{
        aux->next->previous=aux->previous;
        aux->previous->next=aux->next;
        l->first=aux->next;
    }
    aux->next=NULL;
    aux->previous=NULL;
    l->counter--;
    return aux;
}
void destroy_list(list* l){
    //Enquanto houver elementos na lista,é retirado e desalocado o primeiro nó da lista.
    //Então desaloca a lista em si.Não retorna nada.
    node_l* aux;
    while(l->first!=NULL){
        aux=remove_list_first(l);
        destroy_node_l(aux);
    }
    free(l);
    l=NULL;
}
