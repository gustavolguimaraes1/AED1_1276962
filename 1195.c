/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1195
Data        : 26/11/2026
Objetivo    : Montar uma arvore binaria de busca e depois escrever as expressões posfixa, infixa e prefixa delas.
Dificuldade : Lembrar como era a ordem da prefixa, posfixa e infixa.
Uso de IA   : Me ajudou a lembrar as ordens.
------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int conteudo;
    struct cel *dir;
    struct cel *esq;
} no;

typedef no *arvore;

no *Criar (int k){
    no *novo;
    novo = malloc (sizeof(no));
    novo->conteudo = k;
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}

arvore InsereR (arvore r, no *novo){
    if (r == NULL) return novo;
    if (r->conteudo > novo->conteudo) r->esq = InsereR (r->esq, novo);
    else r->dir = InsereR (r->dir, novo);
    return r;
}

void prefixa (arvore r){
    if (r == NULL) return;
    printf (" %d", r->conteudo);
    prefixa (r->esq);
    prefixa (r->dir);
}

void infixa (arvore r){
    if (r == NULL) return;
    infixa (r->esq);
    printf (" %d", r->conteudo);
    infixa (r->dir);
}

void posfixa (arvore r){
    if (r == NULL) return;
    posfixa (r->esq);
    posfixa (r->dir);
    printf (" %d", r->conteudo);
}

int main (){
    int C;
    scanf ("%d", &C);
    for (int i = 0; i<C ; i++){
        arvore r = NULL;
        printf ("Case %d:\n", i+1);
        int N;
        scanf ("%d", &N);
        for (int j = 0; j<N ; j++){
            int k;
            scanf ("%d", &k);
            no *novo;
            novo = Criar (k);
            r = InsereR (r, novo);
        }
        printf ("Pre.:");
        prefixa (r);
        printf ("\nIn..:");
        infixa (r);
        printf ("\nPost:");
        posfixa (r);
        printf ("\n\n");
    }
    return 0;
}
