#include<stdio.h>
#include<stdlib.h>
struct no{
/* Criando o struct "no" que contem as informacoes de cada registro,assim como o endereco
do proximo registro na pilha.*/
    long long cpfc,cpft,valor;
    char op;
    struct no* prox;
};
typedef struct no reg;
struct pilha{
/* Criando o struct "pilha" que guarda o endereço do último registro adicionado
e o número de registros referente ao guiche escolhido.*/
    reg* topo;
    long long cont;
};
typedef struct pilha guiche;
guiche* create_guiche(){
/*Criando efetivamente um guiche através de uma variável auxiliar.O endereço da
memória criada será enviado para aux e o topo do guiche não apontará para nada.
Essa funcão retorna o endereço criado.*/
    guiche* aux;
    aux=malloc(sizeof(guiche));
    aux->topo=NULL;
    aux->cont=0;
    return aux;
}
reg* create_reg(guiche* gn){
/*Criando efetivamente um registro através de uma variável auxiliar.O endereço da
memória criada será enviado para aux,que fará com que a nova memória aponte para
o ropo da pilha.Essa função retorna o endereço da memória criada.*/
    reg* aux;
    aux=malloc(sizeof(reg));
    aux->prox=gn->topo;
    return aux;
}
void show_all(guiche* gn){
    if(gn->topo!=NULL){
        reg* aux;
        aux=gn->topo;
        while(aux->prox!=NULL){
            printf("[%lli, %lli, %c, %lli]\n",aux->cpfc,aux->cpft,aux->op,aux->valor);
            aux=aux->prox;
        }
        printf("[%lli, %lli, %c, %lli]\n",aux->cpfc,aux->cpft,aux->op,aux->valor);
    }
}
void delete_all(guiche* gn){
    reg* aux;
    while(gn->topo!=NULL){
          aux=(gn->topo)->prox;
    free(gn->topo);
    gn->topo=aux;
    }
    free(gn);
}
int main(){
/*declarando as variáveis que iremos precisar:N indicará a quantidade de registros,
v será o vetor que apontará para cada guiche e o resto para o scanf dos dados do
registro.*/
    long long n,scpfc,scpft,svalor;
    char sop;
    guiche* v[3];
/*Criando os 3 guiches e fazendo v apontar para cada um dos guiches*/
    for(int i=0;i<3;i++)
        v[i]=create_guiche();
/*Lendo as entradas do programa.Será criado N registros com os dados que o usuário entrar*/
	scanf("%lli",&n);
    for(long long i=0;i<n;i++){
        scanf("%lli %lli %c %lli",&scpfc,&scpft,&sop,&svalor);
        v[i%3]->topo=create_reg(v[i%3]);
        (v[i%3]->topo)->cpfc=scpfc;
        (v[i%3]->topo)->cpft=scpft;
        (v[i%3]->topo)->op=sop;
        (v[i%3]->topo)->valor=svalor;
        v[i%3]->cont++;
    }
/*Saída do programa.Mostra os registros de cada guiche*/
    printf("-:| RELATÓRIO PARCIAL |:-\n3\n");
    for(int i=0;i<3;i++){
        printf("guiche %d: %lli\n",i+1,v[i]->cont);
        show_all(v[i]);
    }
/*Deleta todos os guiches,assim como os dados que eles continham*/
    for(int i=0;i<3;i++)
        delete_all(v[i]);
return 0;
}

