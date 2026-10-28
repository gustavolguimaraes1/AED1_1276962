/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1466
Data        : 28/10/2026
Objetivo    : Montar uma árvore binária de busca com numeros indicados e imprimir o percurso por nível.
Dificuldade : Média. Entender como passar os niveis.
Uso de IA   : Entender como eu poderia passar de um nivel para o outro organizando em filas organizadas.
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
    novo = malloc(sizeof(no));
    novo->conteudo = k;
    novo->esq = novo->dir = NULL;
    return novo;
}

arvore InsereR (no *novo, arvore r){
    if (r == NULL) return novo;
    if (novo->conteudo <r-> conteudo)
        r->esq = InsereR (novo, r->esq);
    else r->dir = InsereR (novo, r->dir);
    return r;
}

void PercursoNivel (arvore r, int n){
    if(r==NULL) return;
    no **fila = malloc (n*sizeof(no *));
    int inicio =0, fim = 0;
    fila [fim++] = r;
    int primeiro = 1;
    while (inicio<fim){
        no *atual = fila[inicio++];
        if (primeiro == 1){
            printf ("%d", atual->conteudo);
            primeiro = 0;
        } else printf (" %d", atual->conteudo);
        if (atual->esq !=NULL) 
            fila[fim++] = atual->esq;
        if (atual->dir !=NULL)
            fila[fim++] = atual->dir;      
    }
    printf ("\n");
    free (fila);
}

int main (){
    int c, i;
    scanf ("%d", &c);
    for (i=1 ; i<=c ; i++){
        int n;
        scanf ("%d", &n);
        int j, k;
        arvore r = NULL;
        no *novo;
        for (j=0 ; j<n ; j++){
            scanf ("%d", &k);
            novo = Criar (k);
            r = InsereR (novo, r);
        }
        printf ("Case %d:\n", i);
        PercursoNivel (r, n);
        printf ("\n");
    }
    return 0;
}
