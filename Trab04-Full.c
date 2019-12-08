#include<stdio.h>
#include <stdlib.h>
struct no{
	int val,id,op,alt;
	struct no* pai;
	struct no* esq;
	struct no* dir;
};
typedef struct no no;
struct arv{
	no* raiz;
};
typedef struct arv arv;
no* criar_no(int id){
	no* aux=malloc(sizeof(no));
	aux->pai=NULL;
	aux->esq=NULL;
	aux->dir=NULL;
	aux->id=id;
	return aux;
	}
arv* criar_arv(){
	arv* aux=malloc(sizeof(arv));
	aux->raiz=NULL;
	return aux;
}
void destroi_no(no* n){
	free(n);
}
no* insere_busca(arv* a,no* n,no* frente,no* fundo){
	if(frente==NULL){
		if(fundo==NULL)
			a->raiz=n;
		else{
			n->pai=fundo;
			if(n->id>fundo->id)
				fundo->dir=n;
			else
				fundo->esq=n;
		}
		return n;
	}
	else{
		if(frente->id==n->id){
			destroi_no(n);
			return frente;

		}
		fundo=frente;
		if(frente->id<n->id)
			frente=frente->dir;
		else
			frente=frente->esq;
		return insere_busca(a,n,frente,fundo);
	}
}
int arv_h(arv* a){
	return a->raiz->alt;
}
void buscar_nivel(no* n,int i,int j){
	if(n!=NULL){
		if(i==j)
			printf("%d\n",n->id);
		else{
			buscar_nivel(n->esq,i+1,j);
			buscar_nivel(n->dir,i+1,j);
		}
	}
}
void in_ordem_c(no* n){
	if(n!=NULL){
		in_ordem_c(n->esq);
		printf("%d\n",n->id);
		in_ordem_c(n->dir);
	}
}
void in_ordem_d(no* n){
	if(n!=NULL){
		in_ordem_d(n->dir);
		printf("%d\n",n->id);
		in_ordem_d(n->esq);
	}
}
void crescente(arv* a){
	in_ordem_c(a->raiz);
}
void decrescente(arv* a){
	in_ordem_d(a->raiz);
}
no* busca(arv* a,int id){
	no* aux=a->raiz;
	while(aux!=NULL && aux->id!=id){
		if (aux->id<id)
			aux=aux->dir;
		else
			aux=aux->esq;
	}
	return aux;
}
void recalcular_altura(no* n){
	int c=1;
	if(n->esq!=NULL)
		c=n->esq->alt+1;
	if(n->dir!=NULL && c<n->dir->alt+1)
		c=n->dir->alt+1;
	n->alt=c;
}
int balanceamento(no* n){
	if(n==NULL)
		return 0;
	int c=0;
	if(n->esq!=NULL)
		c+=n->esq->alt;
	if(n->dir!=NULL)
		c-=n->dir->alt;
	return c;
}
void rot_s_direita(arv* a,no* n){
	no* aux=n->esq->dir;
	if(aux!=NULL)
		aux->pai=n;
	n->esq->dir=n;
	n->esq->pai=n->pai;
	if(n->pai!=NULL){
		if(n->pai->esq==n)
			n->pai->esq=n->esq;
		else
			n->pai->dir=n->esq;
	}
	else
		a->raiz=n->esq;
	n->pai=n->esq;
	n->esq=aux;
	recalcular_altura(n);
	recalcular_altura(n->pai->dir);
	recalcular_altura(n->pai);
}
void rot_s_esquerda(arv* a,no* n){
	no* aux=n->dir->esq;
	if(aux!=NULL)
		aux->pai=n;
	n->dir->esq=n;
	n->dir->pai=n->pai;
	if(n->pai!=NULL){
		if(n->pai->dir==n)
			n->pai->dir=n->dir;
		else
			n->pai->esq=n->dir;
	}
	else
		a->raiz=n->dir;
	n->pai=n->dir;
	n->dir=aux;
	recalcular_altura(n);
	recalcular_altura(n->pai->esq);
	recalcular_altura(n->pai);
}
void rot_d_direita(arv* a,no* n){
	no* aux1=n->esq->dir->esq;
	no* aux2=n->esq->dir->dir;
	if(aux1!=NULL)
		aux1->pai=n->esq;
	if(aux2!=NULL)
		aux2->pai=n;
	n->esq->dir->pai=n->pai;
	if(n->pai!=NULL){
		if(n->pai->esq==n)
			n->pai->esq=n->esq->dir;
		else
			n->pai->dir=n->esq->dir;
	}
	else
		a->raiz=n->esq->dir;
	n->esq->dir->esq=n->esq;
	n->esq->dir->dir=n;
	n->esq->pai=n->esq->dir;
	n->pai=n->esq->dir;
	n->esq->dir=aux1;
	n->esq=aux2;
	recalcular_altura(n);
	recalcular_altura(n->pai->dir);
	recalcular_altura(n->pai);
}
void rot_d_esquerda(arv* a,no* n){
	no* aux1=n->dir->esq->dir;
	no* aux2=n->dir->esq->esq;
	if(aux1!=NULL)
	aux1->pai=n->dir;
	if(aux2!=NULL)
		aux2->pai=n;
	n->dir->esq->pai=n->pai;
	if(n->pai!=NULL){
		if(n->pai->dir==n)
			n->pai->dir=n->dir->esq;
		else
			n->pai->esq=n->dir->esq;
	}
	else
		a->raiz=n->dir->esq;
	n->dir->esq->dir=n->dir;
	n->dir->esq->esq=n;
	n->dir->pai=n->dir->esq;
	n->pai=n->dir->esq;
	n->dir->esq=aux1;
	n->dir=aux2;
	recalcular_altura(n);
	recalcular_altura(n->pai->esq);
	recalcular_altura(n->pai);
}
void rebalancear(arv* a,no* n){
	int c=balanceamento(n);
	if(c==2 || c==-2){
		if(c==2){
			if(balanceamento(n->esq)==-1)
				rot_d_direita(a,n);
			else
				rot_s_direita(a,n);
		}
		else
			if(balanceamento(n->esq)==1)
				rot_d_esquerda(a,n);
			else
				rot_s_esquerda(a,n);
	}
}
no* arv_raiz(arv* a){
	return a->raiz;
}
void insere(arv* a,int id,int op,int val){
	no* n=criar_no(id);
	n=insere_busca(a,n,a->raiz,NULL);
	n->op=op;
	n->val=val;
	while(n!=NULL){
		recalcular_altura(n);
		rebalancear(a,n);
		n=n->pai;
	}
}
void transplante(no* n,no* aux){
	n->id=aux->id;
	n->val=aux->val;
	n->op=aux->op;
}
no* removendo_no(arv* a,no* n){
	no* aux=NULL;
	if(n->esq==NULL||n->dir==NULL){
		if(n->esq!=NULL){
			n->esq->pai=n->pai;
			aux=n->esq;
		}
		if(n->dir!=NULL){
			n->dir->pai=n->pai;
			aux=n->dir;
		}
		if(a->raiz==n)
			a->raiz=aux;
		else{
			if(n->pai->esq==n)
				n->pai->esq=aux;
			else
				n->pai->dir=aux;
		}
		if(aux==NULL)
			aux=n->pai;
		destroi_no(n);
		return aux;
	}
	else{
		aux=n->dir;
		while(aux->esq!=NULL)
			aux=aux->esq;
		transplante(n,aux);
		return removendo_no(a,aux);
	}
}
void remove_no(arv* a,int id){
	no* n=busca(a,id);
	if(n!=NULL){
		n=removendo_no(a,n);
		while(n!=NULL){
			recalcular_altura(n);
			rebalancear(a,n);
			n=n->pai;
		}
	}
}
void remove_raiz(arv* a){
	no* n=a->raiz;
	if(n!=NULL){
		printf("%d %d %d\n",a->raiz->id,a->raiz->op,a->raiz->val);
		n=removendo_no(a,n);
		while(n!=NULL){
			recalcular_altura(n);
			rebalancear(a,n);
			n=n->pai;
		}
	}
}
void destroi_arv(arv* a){
	while(a->raiz!=NULL)
		remove_raiz(a);
	free(a);
}
void exib(arv* a){
	char c;
	scanf("%c",&c);
	if(c!='c')
		decrescente(a);
	else
		crescente(a);
}
void inserir(arv* a){
	int id,op,val;
	scanf("%d %d %d",&id,&op,&val);
	insere(a,id,op,val);
}
void remover(arv* a){
	int id;
	scanf("%d",&id);
	remove_no(a,id);
}
void consulta(arv* a){
	int id;
	scanf("%d",&id);
	no* aux=busca(a,id);
	if(aux!=NULL)
		printf("existe no com chave: %d\n",id);
	else
		printf("nao existe no com chave: %d\n",id);
}
void altura(a){
	printf("%d\n",arv_h(a));
}
void nivel(arv* a){
	int i;
	scanf("%d",&i);
	buscar_nivel(a->raiz,1,i);
}
int main(){
	char x;
	arv* a=criar_arv();
	while(1){
		scanf("%c",&x);
		if(x=='n'){
			nivel(a);
		}
		if(x=='h'){
			altura(a);
		}
		if(x=='i'){
			inserir(a);
		}
		if(x=='c'){
				consulta(a);
		}
		if(x=='r'){
				remover(a);
		}
		if(x=='f'){
				destroi_arv(a);
				break;
		}
		if(x=='p'){
				exib(a);
		}
	}
	return 0;
}
