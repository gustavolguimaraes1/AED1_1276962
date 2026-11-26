/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1076
Data        : 26/11/2026
Objetivo    : Contar a quantidade de movimentos de caneta para desenhar o labirinto.
Dificuldade : Entender como adaptar o contador para tirar as "arestas duplas".
Uso de IA   : entender como "eliminar" as arestas duplas.
------------------------------------------------------------------------- */

#include <stdio.h>

void dfs (int V, int grafo[V][V], int visitado[], int *contador, int N){
    visitado[N] = 1;
    for (int i = 0; i<V ; i++){
        if (grafo[N][i] == 1 && visitado[i] == 0){
            (*contador)++;
            dfs(V, grafo, visitado, contador, i);
        }
    }
}

int main (){
    int T, i;
    scanf ("%d", &T);
    for (i=0 ; i<T ; i++){
        int N;
        scanf ("%d", &N);
        int V, A;
        scanf ("%d %d", &V, &A);
        int grafo[V][V];
        int j, k;
        for (j=0 ; j<V ; j++){
            for (k=0 ; k<V ; k++){
                grafo[j][k] = 0;
            }
        }
        for (j=0 ; j<A ; j++){
            int m, n;
            scanf ("%d %d", &m, &n);
            grafo[m][n] = 1;
            grafo[n][m] = 1;
        }
        int visitado[V];
        for (j=0 ; j<V ; j++){
            visitado[j] = 0;
        }
        int contador = 0;
        dfs (V, grafo, visitado, &contador, N);
        printf ("%d\n", 2*contador);
    }
    return 0;
}
