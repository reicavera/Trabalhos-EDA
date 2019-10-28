#ifndef NODE
#define NODE
#include <stdlib.h>
#include "node.h"

struct node_p{
    //Registro de dados do cliente, contendo:
    //cpf do cliente, cpf de terceiros, o valor da operação,
    //o tipo de operação efetuada e um ponteiro para o próximo Nó.
    long long cpfc,cpft,valor;
    char op;
    struct node_p* next;
};
typedef struct node_p node_p;
node_p* create_node_p();//Cria um nó padrão e o retorna.
long long node_p_display_cpfc(node_p* p);//dado um nó padrão,retorna o cpf do cliente.
long long node_p_display_cpft(node_p* p);//dado um nó padrão,retorna o cpf de terceiro.
long long node_p_display_valor(node_p* p);//dado um nó padrão,retorna o o valor da operação.
char node_p_display_op(node_p* p);//dado um nó padrão,retorna o tipo de operação realizada.
void destroy_node_p(node_p* n);//desaloca o nó padrão que foi dado.
struct node_l{
    //Define o registro de dados para impressão do relatório final como nó de lista.
    long long cpf,nop,balance;
    struct node_l* next;
    struct node_l* previous;
};
typedef struct node_l node_l;
node_l* create_node_l();//cria um nó de lista e o retorna.Note que o numero de operações ja começa como 1. 
long long node_l_display_cpf(node_l* n);//dado um nó de lista,retorna o cpf.
long long node_l_display_nop(node_l* n);//dado um nó de lista,retorna o numero de operações.
long long node_l_display_balance(node_l* n);//dado um nó de lista,retorna o saldo.
void destroy_node_l(node_l* n);//desaloca o nó de lista que foi dado.

#endif
