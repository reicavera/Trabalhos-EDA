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
		int qtd;
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
		aux->qtd=0;
		return aux;
	}
	void destroi_no(no* n){
		free(n);
	}
	int num_clientes(arv* a){
		return a->qtd;
	}
	no* insere_busca(arv* a,no* n,no* frente,no* fundo){
		if(frente==NULL){
			a->qtd++;
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
		if(a->raiz==NULL)
			return 0;
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
			printf("%d %d %d\n",n->id,n->op,n->val);
			in_ordem_c(n->dir);
		}
	}
	void in_ordem_d(no* n){
		if(n!=NULL){
			in_ordem_d(n->dir);
			printf("%d %d %d\n",n->id,n->op,n->val);
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
		if(n!=NULL){
		int c=1;
		if(n->esq!=NULL)
			c=n->esq->alt+1;
		if(n->dir!=NULL && c<n->dir->alt+1)
			c=n->dir->alt+1;
		n->alt=c;
		}
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
		no* aux2=n->esq;
		aux2->pai=n->pai;
		if(aux!=NULL)
			aux->pai=n;
		if(n->pai!=NULL){
			if(n->pai->esq==n)
				n->pai->esq=aux2;
			else
				n->pai->dir=aux2;
		}
		else
			a->raiz=aux2;
		n->esq=aux;
		n->pai=aux2;
		aux2->dir=n;
		recalcular_altura(n);
		recalcular_altura(aux2);
	}
	void rot_s_esquerda(arv* a,no* n){
		no* aux=n->dir->esq;
		no* aux2=n->dir;
		if(aux!=NULL)
			aux->pai=n;
		aux2->pai=n->pai;
		if(n->pai!=NULL){
			if(n->pai->esq==n)
				n->pai->esq=aux2;
			else
				n->pai->dir=aux2;
		}
		else
			a->raiz=aux2;
		n->dir=aux;
		n->pai=aux2;
		aux2->esq=n;
		recalcular_altura(n);
		recalcular_altura(aux2);
	}
	void rot_d_direita(arv* a,no* n){
		no* aux1=n->esq->dir->esq;
		no* aux2=n->esq->dir->dir;
		no* x=n->esq;
		no* y=n->esq->dir;
		if(aux1!=NULL)
			aux1->pai=x;
		if(aux2!=NULL)
			aux2->pai=n;
		y->pai=n->pai;
		if(n->pai!=NULL){
			if(n->pai->esq==n)
				n->pai->esq=y;
			else
				n->pai->dir=y;
		}
		else
			a->raiz=y;
		x->dir=aux1;
		n->esq=aux2;
		y->esq=x;
		y->dir=n;
		x->pai=y;
		n->pai=y;
		recalcular_altura(n);
		recalcular_altura(x);
		recalcular_altura(y);
	}
	void rot_d_esquerda(arv* a,no* n){
		no* aux1=n->dir->esq->dir;
		no* aux2=n->dir->esq->esq;
		no* x=n->dir;
		no* y=n->dir->esq;
		if(aux1!=NULL)
			aux1->pai=x;
		if(aux2!=NULL)
			aux2->pai=n;
		y->pai=n->pai;
		if(n->pai!=NULL){
			if(n->pai->esq==n)
				n->pai->esq=y;
			else
				n->pai->dir=y;
		}
		else
			a->raiz=y;
		x->esq=aux1;
		n->dir=aux2;
		y->dir=x;
		y->esq=n;
		x->pai=y;
		n->pai=y;
		recalcular_altura(n);
		recalcular_altura(x);
		recalcular_altura(y);
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
		if(op==1)
			n->val*=-1;
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
			a->qtd--;
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
		printf("-+- Inicio relatorio -+-\n%d\n",num_clientes(a));
		while(a->raiz!=NULL)
			remove_raiz(a);
		free(a);
		printf("-+- Fim relatorio -+-\n");
	}
	void exib(arv* a,char x){
		if(x=='c')
			crescente(a);
		else
			decrescente(a);
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
	void altura(arv* a){
		printf("%d\n",arv_h(a));
	}
	void nivel(arv* a){
		int i;
		scanf("%d",&i);
		buscar_nivel(a->raiz,1,i);
	}
	int main(){
		char x;
		int flag=0;
		arv* a=criar_arv();
		while(1){
			scanf("%c",&x);
			switch(x){
				case 'c':
					if(flag==1){
						flag=0;
						exib(a,x);
					}	
					else
						consulta(a);
					break;
				case 'p':
					flag=1;
					break;
				case 'n':
					nivel(a);
					break;
				case'h':
					altura(a);
					break;
				case 'i':
					inserir(a);
					break;
				case 'd':
					flag=0;
					exib(a,x);
					break;
				case 'r':
					remover(a);
					break;
				case 'f':
					destroi_arv(a);
					break;
			}
		}
		return 0;
	}
