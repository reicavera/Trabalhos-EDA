#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "node.h"
#include "stack.h"
#include "queue.h"
#include "list.h"
void display_partial(long long j,long long m,list* l,stack** s){
    //Primeira parte da saída do programa.Vale notar que essa função
    //também chama a adição de nós na lista e a desalocação dos nós
    //da pilha.
    printf("-:| RELATORIO DIARIO %lli |:-\n%lli\n",j,m);
    node_p* n1;
    for(long long i=0;i<m;i++){
        printf("Guiche %lli: %lli\n",i+1,stack_size(s[i]));
        while(empty_stack(s[i])==0){
            n1=remove_stack(s[i]);
            add_list(l,n1);
            printf("[%lli,%lli,%c,%lli]\n",node_p_display_cpfc(n1),node_p_display_cpft(n1),node_p_display_op(n1),node_p_display_valor(n1));
            destroy_node_p(n1);
        }
    }
}
void display_final(list* l){
    //Segunda parte da saída do programa.Vale notar que essa função também
    // chama a desalocação da dos nós de lista.
    printf("\n-:| RELATORIO FINAL |:-\n%lli\n",list_size(l));
    node_l* n;
    while(list_size(l)!=0){
        n=remove_list_first(l);
        printf("-:[ %lli : %lli %lli\n",node_l_display_cpf(n),node_l_display_nop(n),node_l_display_balance(n));
        destroy_node_l(n);
    }
}
node_p* queuing(queue* f){
    long long scpfc,scpft,svalor;
    char sop;
    scanf("%lli %lli %c %lli",&scpfc,&scpft,&sop,&svalor);
        add_queue(f,scpfc,scpft,sop,svalor);
    node_p* aux;
    aux=remove_queue(f);
    return aux;
}
void guiche(stack* s,node_p* p){
    add_stack(s,p);
}
int main(){
    long long j,n,m,d;
    queue* f=NULL;
    list* l=NULL;
    l=create_list();
    scanf("%lli %lli %lli",&n,&m,&d);
    f=create_queue(floor(sqrt(n)));
    stack** s=NULL;
    s=create_stack(m);
    for(j=1;j*d<=n;j++){
        for(long long i=0;i<d;i++)
            guiche(s[i%m],queuing(f));
        display_partial(j,m,l,s);
    }
    if(n%d!=0){
        for(long long i=0;i<n%d;i++)
            guiche(s[i%m],queuing(f));
        display_partial(j,m,l,s);
    }
    display_final(l);
    destroy_stack(s[i],m);
    destroy_queue(f);
    destroy_list(l);
    return 0;
}
