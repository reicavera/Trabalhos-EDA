#include<stdio.h>
#include<stdlib.h>
struct node{
    long long cpfc,cpft,valor;
    char op;
    struct node* next;
};
typedef struct node node;
node* create_node(){
    node* aux;
    aux=malloc(sizeof(node));
    return aux;
}
struct stack{
    node* top;
    long long counter;
};
struct queue{
    node* data;
    int max_size,size,front,bottom;
};
typedef struct queue queue;
queue* create_queue(long long n){
    queue* aux;
    aux->data=malloc(sizeof(node)*n);
    aux->max_size=n;
    aux->size=0;
    aux->front=0;
    aux->bottom=0;
    return aux;
}
void destroy_queue(queue* f){
    free(f->data);
}
void add_queue(queue* f,long long scpfc,long long scpft,char sop,long long svalor){
    f->data[f->bottom].cpfc=scpfc;
    f->data[f->bottom].cpft=scpft;
    f->data[f->bottom].op=sop;
    f->data[f->bottom].valor=svalor;
    f->bottom=(f->bottom+1)%f->max_size;
    f->size++;
}
node* remove_queue(queue* f){
    node* aux;
    aux=create_code();
    aux->cpfc=f->data[f->front].cpfc;
    aux->cpft=f->data[f->front].cpft;
    aux->op=f->data[f->front].op;
    aux->valor=f->data[f->front].valor;
    f->front=(f->front+1)%f->max_size;
    return aux;
}
struct list{
    node* first;
};
typedef struct list list;


int main(){
    long long n,scpfc,scpft,svalor;
    char sop;
    queue* f;
    scanf("%lli",&n);
    f=create_queue(n);
    for(int i=0;i<n;i++){
        scanf("%lli %lli %c %lli",scpfc,scpft,sop,svalor);
        add_queue(f,scpfc,scpft,sop,svalor);
    }
    destroy_queue(f);

    return 0;
}
