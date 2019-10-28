#ifndef LIST
#define LIST
#include<stdlib.h>
#include "node.h"
#include "list.h"

struct list{
    //O registro da lista contém um contador dque indica o número de elementos da lista
    //e um ponteiro indicando o primeiro nó da lista.
    node_l* first;
    long long counter;
};
typedef struct list list;
list* create_list();//cria uma lista e a reorna.
long long list_size(list* l);//retorna o numero de elementos na lista.
void add_list(list* l,node_p* n);//Faz todo o controle de dados a partir do tipo de operação
//e adiciona um novo dado ordenando de acordo com o cpf caso ainda não exista algum dos cpfs e altera o 
//saldo e incrementa o numero de operações caso o algum dos cpfs ja esteja na lista.
node_l* remove_list_first(list* l);//Retira o primeiro elemento da lista e o retorna.
void destroy_list(list* l);//Destroi a lista e todos os elementos dela.

#endif // LIST
