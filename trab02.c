#include<stdio.h>
#include<stdlib.h>
struct node_p{
    long long cpfc,cpft,valor;
    char op;
    struct node_p* next;
};
typedef struct node_p node_p;
node_p* create_node_p(){
    node_p* aux;
    aux=malloc(sizeof(node_p));
    return aux;
}
void destroy_node_p(node_p* n){
    free(n);
}
struct node_l{
    long long cpf,nop,balance;
    struct node_l* next;
};
typedef struct node_l node_l;
node_l* create_node_l(){
    node_l* n;
    n=malloc(sizeof(node_l));
    n->nop=1;
    return n;
}
void destroy_node_l(node_l* n){
    free(n);
}
struct stack{
    node_p* top;
    long long counter;
};
typedef struct stack stack;
stack* create_stack(){
    stack* aux;
    aux=malloc(sizeof(stack));
    aux->top=NULL;
    aux->counter=0;
    return aux;
}
void add_stack(stack* s,node_p* n){
    n->next=s->top;
    s->top=n;
    s->counter++;
}
node_p* remove_stack(stack* s){
    node_p* aux;
    aux=s->top;
    s->top=aux->next;
    s->counter--;
    return aux;
}
void destroy_stack(stack* s){
    node_p* n1;
    for(int i=0;i<3;i++)
        while(s->top!=NULL){
            n1=remove_stack(s);
            destroy_node_p(n1);
        }
    free(s);
}
struct queue{
    node_p* data;
    long long max_size,size,front,bottom;
};
typedef struct queue queue;
queue* create_queue(long long n){
    queue* aux;
    aux=malloc(sizeof(queue));
    aux->data=malloc(sizeof(node_p)*n);
    aux->max_size=n;
    aux->size=0;
    aux->front=0;
    aux->bottom=0;
    return aux;
}
void add_queue(queue* f,long long scpfc,long long scpft,char sop,long long svalor){
    f->data[f->bottom].cpfc=scpfc;
    f->data[f->bottom].cpft=scpft;
    f->data[f->bottom].op=sop;
    f->data[f->bottom].valor=svalor;
    f->bottom=(f->bottom+1)%f->max_size;
    f->size++;
}
node_p* remove_queue(queue* f){
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
    free(f->data);
    free(f);
}
struct list{
    node_l* first;
    long long counter;
};
typedef struct list list;
list* create_list(){
    list* l;
    l=malloc(sizeof(list));
    l->first=NULL;
    l->counter=0;
    return l;
}
void search_list(long long valor,long long cpf,list* l){
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
    node_l* aux;
    aux=l->first;
    l->first=aux->next;
    return aux;
}
void destroy_list(list* l){
    node_l* aux;
    while(l->first!=NULL){
        aux=remove_list_first(l);
        destroy_node_l(aux);
    }
    free(l);
}
void display_partial(list* l,stack* s[3]){
    printf("-:| RELATÓRIO PARCIAL |:-\n3\n");
    node_p* n1;
    for(long long i=0;i<3;i++){
        printf("Guiche %lli: %lli\n",i+1,s[i]->counter);
        while(s[i]->counter!=0){
            n1=add_list(l,s[i]);
            printf("[%lli,%lli,%c,%lli]\n",n1->cpfc,n1->cpft,n1->op,n1->valor);
            destroy_node_p(n1);
        }
    }
}
void display_final(list* l){
    printf("-:| RELATÓRIO FINAL|:-\n %lli\n",l->counter);
    node_l* n;
    while(l->first!=NULL){
        n=remove_list_first(l);
        printf("-:[ %lli : %lli %lli\n",n->cpf,n->nop,n->balance);
        destroy_node_l(n);
    }
}
int main(){
    long long n,scpfc,scpft,svalor;
    char sop;
    queue* f;
    scanf("%lli",&n);
    f=create_queue(n);
    for(long long i=0;i<n;i++){
        scanf("%lli %lli %c %lli",&scpfc,&scpft,&sop,&svalor);
        add_queue(f,scpfc,scpft,sop,svalor);
    }
    stack* s[3];
    for(int i=0;i<3;i++)
        s[i]=create_stack();
    for(long long i=0;i<n;i++)
        add_stack(s[i%3],remove_queue(f));
    list* l;
    l=create_list();
    display_partial(l,s);
    display_final(l);
    for(int i=0;i<3;i++)
        destroy_stack(s[i]);
    destroy_queue(f);
    destroy_list(l);
    return 0;
}
