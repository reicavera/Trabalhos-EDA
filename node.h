#include <stdlib.h>
#include "node.h"
#ifndef NODE
#define NODE

struct node_p{
    //Registro de dados do cliente, contendo:
    //cpf do cliente, cpf de terceiros, o valor da operação,
    //o tipo de operação efetuada e um ponteiro para o próximo Nó.
    long long cpfc,cpft,valor;
    char op;
    struct node_p* next;
};
typedef struct node_p node_p;
node_p* create_node_p();
void destroy_node_p(node_p* n);
struct node_l{
    //Define o registro de dados para impressão do relatório final como Nó de lista.
    long long cpf,nop,balance;
    struct node_l* next;
    struct node_l* previous;
};
typedef struct node_l node_l;
node_l* create_node_l();
void destroy_node_l(node_l* n);

#endif
