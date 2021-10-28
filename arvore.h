#include <stdio.h>
#include <stdlib.h>

typedef int elem;
typedef struct no_t no;

typedef struct arvore_t{
    no *raiz;
} arvore;

struct no_t{
    no *esq, *dir;
    elem info;
    int alt;
};

arvore *criar();
int EstaVazia(arvore *a);
int altura(no *raiz);
no *busca(no *raiz, elem x);
no *BuscaPai(no *raiz, elem x);
int InserirEsq(arvore *a, elem x, elem pai);
int InserirDir(arvore *a, elem x, elem pai);
int remover(arvore *a, elem x);
void Pre_Ordem(no *raiz);
void Em_Ordem(no *raiz);
void Pos_Ordem(no *raiz);
void finalizar(no *raiz);
