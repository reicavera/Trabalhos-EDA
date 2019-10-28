#include <stdlib.h>
#ifndef NODE
#include "node.h"
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
long long node_p_display_cpfc(node_p* p);
long long node_p_display_cpft(node_p* p);
long long node_p_display_valor(node_p* p);
char node_p_display_op(node_p* p);
void destroy_node_p(node_p* n);
struct node_l{
    //Define o registro de dados para impressão do relatório final como Nó de lista.
    long long cpf,nop,balance;
    struct node_l* next;
    struct node_l* previous;
};
typedef struct node_l node_l;
node_l* create_node_l();
long long node_l_display_cpf(node_l* n);
long long node_l_display_nop(node_l* n);
long long node_l_display_balance(node_l* n);
void destroy_node_l(node_l* n);

#endif
