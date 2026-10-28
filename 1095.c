/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1095
Data        : 28/10/2026
Objetivo    : Imprimir combinaçoes de i somando de 3 em 3 com j subtraindo de 5 em 5 até chegar em 0.
Dificuldade : Entender para qual parte precisaria usar árvores binarias, sendo que o problema era simples de ser resolvido sem elas.
Uso de IA   : Justamente para entender como poderia aplicar árvores binárias em um exercício tão simples como aquele.
------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

/* SEM USAR ARVORES BINARIAS: FORMA MAIS SIMPLES */

int main (){
    int i = 1, j;
    for (j=60; j >= 0 ; j-=5){
        printf ("I=%d J=%d\n", i, j);
        i+=3;
    }
    return 0;
}

/* USANDO ARVORES BINARIAS*/

typedef struct cel{
    int i, j;
    struct cel *dir;
    struct cel *esq;
} nó;

typedef nó *árvore;

nó *Criar (int i, int j){
    nó *novo;
    novo = malloc(sizeof(nó));
    novo->i = i;
    novo->j = j;
    novo->esq = novo->dir = NULL;
    return novo;
}

árvore InsereR (nó *novo, árvore r){
    if (r == NULL) return novo;
    if (novo->i > r->i) 
        r->dir = InsereR (novo, r->dir);
    else r->esq = InsereR (novo, r->esq);
    return r;
}

void ErdR (árvore r){
    if (r !=NULL){
        ErdR (r->esq);
        printf ("I=%d J=%d\n", r->i, r->j);
        ErdR(r->dir);
    }
}

void Libera (árvore r){
    if (r!=NULL){
        Libera (r->esq);
        Libera (r->dir);
        free (r);
    }
}

int main (){
    int i, j;
    árvore r = NULL;
    nó *novo;
    for (i=1, j=60 ; j>=0 ; i+=3, j-=5){
        novo = Criar (i, j);
        r = InsereR (novo, r);
    }
    ErdR (r);
    Libera (r);
    return 0;
}
