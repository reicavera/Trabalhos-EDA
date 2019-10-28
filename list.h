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
list* create_list();
long long list_size(list* l);
void add_list(list* l,node_p* n);
node_l* remove_list_first(list* l);
void destroy_list(list* l);

#endif // LIST
