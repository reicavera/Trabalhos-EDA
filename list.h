#include<stdlib.h>
#include "list.h"
#ifndef LIST
#define LIST

struct list{
    //O registro da lista contém um contador dque indica o número de elementos da lista
    //e um ponteiro indicando o primeiro nó da lista.
    node_l* first;
    long long counter;
};
typedef struct list list;
list* create_list();
void search_list(long long valor,long long cpf,list* l);
node_p* add_list(list* l,stack* s);
node_l* remove_list_first(list* l);
void destroy_list(list* l);

#endif // LIST
