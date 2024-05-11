#include<stdio.h>
#include<stdlib.h>

struct arvore{
   struct arvore *esq;
   struct arvore *dir;
   int info;
};

typedef struct arvore arv;

void buscar(arv *r, int valor){
    arv *aux = r;
    
    if(aux != NULL){

       if(valor == aux -> info){
        printf("\nValor encontrado!\n");
       } 

       else if(valor < aux -> info){
        buscar(aux -> esq, valor);
       }
       else{
        buscar(aux -> dir, valor);
       }

    }
    else{
        printf("\nO valor nao foi encontrado\n");
    }

}

int altura (arv *r){
	if (r == NULL){
		return -1;
	}
	else{
		int e = altura(r->esq);
		int d = altura(r->dir);
		
		if(e > d){
			return e + 1;
		}
		else{
			return d + 1;
		}
	}
}

void insere(arv *r, int valor){
    arv *novo = (arv*)malloc(sizeof(arv));
    novo -> info = valor;
    novo -> esq = NULL;
    novo -> dir = NULL;

    if (r == NULL){
        r = novo;
    }
    else{
        if(valor < r-> info){
            esquerda(r, valor);
        }     

        else{
            direita(r, valor);
        }
    }
}
void esquerda(arv *r, int valor){
    if(r->esq == NULL){
        arv *novo = (arv*)malloc(sizeof(arv));
        novo -> info = valor;
        novo -> esq = NULL;
        novo -> dir = NULL;
        r->esq = novo;
    }

    else{
        if(valor < r->esq->info){
            esquerda(r->esq, valor);
        }
        else{
            direita(r->esq, valor);
        }
    }
}


void direita(arv *r, int valor){
    if(r->dir == NULL){
         arv *novo = (arv*)malloc(sizeof(arv));
        novo -> info = valor;
        novo -> esq = NULL;
        novo -> dir = NULL;
        r->dir = novo;
    }

    else{
        if(valor > r->dir->info){
            direita(r->dir, valor);
        }
        else{
            esquerda(r->dir, valor);
        }
    }

}

void imprimir(arv *r){
    if(r != NULL){
    	imprimir(r->esq);
        printf("\n%d\n", r->info);
     	imprimir(r->dir);   
    }
}

int main(){

    arv *r = NULL;
    int op, valor;
   
    do{
        printf("\n 0 - Sair\n 1 - Inserir\n 2 - Imprimir\n 3 - Altura\n 4 - Buscar valor na arvore\n");
        scanf("%d", &op);

        switch(op){
            case 0:
            printf("\n saindo...\n");
            break;
            case 1:
            printf("\nDigite um valor\n");
            scanf("%d", &valor);
            insere(&r, valor);
            break;
            case 2:
            printf("\n imprimir arvore binaria\n");
            imprimir(r);
            break;
            case 3:
            printf("Altura da Arvore: %d", altura(r));
            break;
            case 4:
            printf("Digite o valor que deve ser verificado:");
            scanf("%d", &valor);
            buscar(r, valor);
            break;
            default:
            printf("\n opcao invalida...\n");
        }
    }while(op != 0);

    return 0;
}