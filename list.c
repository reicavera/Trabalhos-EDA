#include<stdlib.h>
#include "list.h"
list* create_list(){
    //Um auxiliar aloca um registro de pilha e retorna o endereço alocado.
    list* l;
    l=malloc(sizeof(list));
    l->first=NULL;
    l->counter=0;
    return l;
}
void search_list(long long valor,long long cpf,list* l){
    //Primeiramente verifica se a lista está vazia ou se o cpf do primeiro elemento é
    //maior do que do próvável novo nó.Se sim,adiciona um nó na primeira posição da lista.
    //Se não,verifica se o cpf do primeiro elemento é igual ao do cpf próvalvel nó.Se sim,
    //apenas altera o saldo e incrementa o número de operações do primeiro elemento da lista.
    //Se não,é feito um loop com um auxiliar percorrendo a lista até que se chegue no ultimo
    //elemento ou que o cpf do próximo elemento seja deixe de ser menor que o cpf do possível
    //novo elemento.Caso o auxiliar tenha chegado  ao ultimo elemento ou que o cpf do próximo
    //seja maior,adiciona um nó logo após o nó apontado pelo auxiliar.Caso contrário,apenas
    //altera o saldo e incrementa o número de operações do próximo do auxiliar.Não retorna nada.
    node_l* aux;
    node_l* n;
    if(l->first==NULL || l->first->cpf>cpf){
        n=create_node_l();
        n->balance=valor;
        n->cpf=cpf;
        n->next=l->first;
        l->first=n;
        l->counter++;
    }
    else if(l->first->cpf==cpf){
        l->first->nop++;
        l->first->balance+=valor;
    }
    else{
        aux=l->first;
        while(aux->next!=NULL && aux->next->cpf<cpf)
            aux=aux->next;
        if(aux->next==NULL || aux->next->cpf>cpf){
            n=create_node_l();
            n->balance=valor;
            n->cpf=cpf;
            n->next=aux->next;
            aux->next=n;
            l->counter++;
        }
        else{
            aux->next->nop++;
            aux->next->balance+=valor;
        }
    }
}
node_p* add_list(list* l,stack* s){
    //retira um nó da pilha e verifica os possíveis casos de mudança na lista baseada
    //na operação bancária armazenda no nó.Retorna o nó padrão retirado da pilha.
    node_p* n;
    n=remove_stack(s);
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
    return n;
}

node_l* remove_list_first(list* l){
    //Retira e retorna o primeiro elemento da lista.
    node_l* aux;
    aux=l->first;
    l->first=aux->next;
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
}
