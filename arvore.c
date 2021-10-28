#include "arvore.h"

arvore *criar(){    //aloca memória para a arvore
    arvore *a = (arvore *) malloc(sizeof(arvore));
    a->raiz = NULL;
    return a;    
}

int EstaVazia(arvore *a){   //verifica se está vazia
    if(a == NULL)
        return 1; //erro
    if(a->raiz == NULL)
        return -1; //vazia
    return 0; //sucesso
}

int altura(no *no){
    if(no == NULL)
        return 1; //erro
    else
        return no->altura;
}

int balanceamento(no *p){
    return (altura (no->esq) - altura(no->dir));
}

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

no *busca(no *raiz, elem x){    //faz a busca de um elemento x na arvore
    if(raiz == NULL)
        return NULL;
        
    if(raiz->info == x)
        return raiz;
    
    no *p = busca(raiz->esq, x);
    if(p == NULL)
        p = busca(raiz->dir, x);
        
    return p;
}

no *BuscaPai(no *raiz, elem x){ //faz a busca do pai de determinado elemento
     if(raiz == NULL)
        return NULL;
        
    if(raiz->esq != NULL && raiz->esq->info == x)
        return raiz;
    if(raiz->dir != NULL && raiz->dir->info == x)
        return raiz;
        
    no *p = BuscaPai(raiz->esq, x);
    if(p == NULL)
        p = BuscaPai(raiz->dir, x);
        
    return p;
}

int InserirEsq(arvore *a, elem x, elem pai){    //insere um no à esquerda
    no *p = (no *) malloc(sizeof(no));
    p->esq = NULL;
    p->dir = NULL;
    p->info = x;
    
    if(pai == -1){
        if(a->raiz == NULL){
            a->raiz = p;
            //a->raiz->info = -1;
        } else{
            free(p);
            return 0;
        }
    } else{
        no *aux = busca(a->raiz, pai);
        if(aux != NULL && aux->esq == NULL){
            aux->esq = p;
        } else{
            free(p);
            return 0;
        }
    }
    
    return 1;   //sucesso
}

int InserirDir(arvore *a, elem x, elem pai){    //insere um no à direita
    no *p = (no *) malloc(sizeof(no));
    p->esq = NULL;
    p->dir = NULL;
    p->info = x;
    
    if(pai == -1){
        if(a->raiz == NULL){
            a->raiz = p;
        } else{
            free(p);
            return 0;
        }
    } else{
        no *aux = busca(a->raiz, pai);
        if(aux != NULL && aux->dir == NULL){
            aux->dir = p;
        } else{
            free(p);
            return 0;
        }
    }
    
    return 1;   //sucesso
}

int remover(arvore *a, elem x){ //remove determinado elemento da arvore
    no *p, *pai;
    int esq;
    
    if(a->raiz != NULL && a->raiz->info == x){
        p = a->raiz;
        pai = NULL;
    } else{
        pai = BuscaPai(a->raiz, x);
        if(pai != NULL){
            if(pai->esq != NULL && pai->esq->info == x){
                p = pai->esq;
                esq = 1;
            } else{
                p = pai->dir;
                esq = 0;
            }
        } else{ // pai == NULL
            p = NULL;
        }
    }
    
    if(p == NULL){  //remoção de p
        return 0;
    } else{
        if(p->esq == NULL && p->dir == NULL){   // remoção de p como folha
            if(pai == NULL){
                a->raiz = NULL;
            } else{
                if(esq){
                    pai->esq = NULL;
                } else{
                    pai->dir = NULL;
                }
            }
            free(p);
            return 1;
        } else{
            if(p->esq != NULL){
                p->info = p->esq->info;
                p->esq->info = x;
            } else{
                p->info = p->dir->info;
                p->dir->info = x;
            }
            return remover(a, x);
        }
    }
    
    return 0;
}

void Pre_Ordem(no *raiz){ //impressão em pré ordem
  if(raiz != NULL){
        printf("%d ", raiz->info);
        Pre_Ordem(raiz->esq);
        Pre_Ordem(raiz->dir);
    }
        
    return;
}

void Em_Ordem(no *raiz){  //impressão em ordem
    if(raiz != NULL){
        Em_Ordem(raiz->esq);
        printf("%d ", raiz->info);
        Em_Ordem(raiz->dir);
    }

    return;
}

void Pos_Ordem(no *raiz){   //impressão em pós ordem
    if(raiz != NULL){
        Pos_Ordem(raiz->esq);
        Pos_Ordem(raiz->dir);
        printf("%d ", raiz->info);
    }
        
    return;
}

void finalizar(no *raiz){   //libera a memória alocada
    if(raiz != NULL){
        finalizar(raiz->esq);
        finalizar(raiz->dir);
        free(raiz);
    }
}
