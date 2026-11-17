/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : 17/11/2026
Objetivo    : Ver se os documentos formam um ciclo de acordo com suas dependências ou não.
Dificuldade : Arrumar um jeito de ele testar todos os começos de "ordens" de documentos para ver se conseguiria sair do looping ou não.
Uso de IA   : Para ajudar na implementação da lista de adjacência.
------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int destino;
    struct celula *prox;
} Celula;

int dfs (int V, Celula *grafo[], int v, int visitado[]){
    visitado[v] = 1;
    Celula *p = grafo[v];
    while (p != NULL){
        int i = p->destino;
        if (visitado[i] == 1) return 1;
        if (visitado[i] == 0){
            if (dfs(V, grafo, i, visitado) == 1)
                return 1;
        }
        p = p->prox;
    }
    visitado[v] = 2;
    return 0;
}

int main (){
    int n, i;
    scanf ("%d", &n);
    for (i=0 ; i<n ; i++){
        int V, A;
        scanf ("%d %d", &V, &A);
        Celula *grafo[V];
        int j;
        for (j=0 ; j<V ; j++){
            grafo[j] = NULL;
        }
        for (j=0 ; j< A ; j++){
            int k, l;
            scanf ("%d %d", &k, &l);
            Celula *nova = malloc(sizeof(Celula));
            nova->destino = l-1;
            nova->prox = grafo[k-1];
            grafo[k-1] = nova;
        }
        int visitado[V];
        for (j=0 ; j<V ; j++){
            visitado[j] = 0;
        }
        int ciclo = 0;
        for (j=0 ; j<V ; j++){
            if (visitado[j] == 0){
                if (dfs(V, grafo, j, visitado) == 1){
                    ciclo = 1;
                    break;
                }
            }
        }
        if (ciclo == 1) printf ("SIM\n");
        else printf ("NAO\n");
        for (int j=0 ; j<V ; j++){
            Celula *p = grafo[j];
            while (p !=NULL){
                Celula *aux = p;
                p = p->prox;
                free (aux);
            }
        }
    }
    return 0;
}
