/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1082
Data        : 12/11/2026
Objetivo    : Contar quantos componentes conexos tem em cada grafo e quais são eles.
Dificuldade : Achei muito dificil, principalmente adaptar o bfs para um caso em que separa os componentes.
Uso de IA   : Achar uma solução para conseguir separar em componentes conexos diferentes e aplicar isso no bfs.
------------------------------------------------------------------------- */
#include <stdio.h>

void bfs (int V, int grafo[V][V], int componente[], int fila[], int *inicio, int *fim, int id){
    if (*inicio == *fim) return;
    int v = fila[(*inicio)++];
    for (int i = 0; i<V ; i++){
        if (grafo[v][i] == 1 && componente[i] == -1){
            componente[i] = id;
            fila[(*fim)++] = i;
        }
    }
    bfs (V, grafo, componente, fila, inicio, fim, id);
}

int main(){
    int n, i;
    scanf ("%d", &n);
    for (i=0 ; i<n ; i++){
        printf ("Case #%d:\n", i+1);
        int V, A;
        scanf ("%d %d", &V, &A);
        int grafo[V][V];
        int j, x;
        char k, l;
        for (j=0 ; j< V ; j++){
            for (x=0 ; x<V ; x++){
                grafo[j][x] = 0;
            }
        }
        for (j=0; j<A ; j++){
            scanf (" %c %c", &k, &l); 
            grafo[k - 'a'][l - 'a'] = 1;
            grafo[l - 'a'][k - 'a'] = 1;       
        }
        int componente[V];
        for (j=0 ; j<V ; j++){
            componente[j] = -1;
        }
        int qtd = 0;
        for (j=0 ; j<V ; j++){
            if (componente[j] == -1){
                int fila[V];
                int inicio = 0;
                int fim = 0;
                fila[fim++] = j;
                componente[j] = qtd;
                bfs (V, grafo, componente, fila, &inicio, &fim, qtd);
                qtd++;
            }
        }
        for (j=0 ; j<qtd ; j++){
            for (x=0 ; x<V ; x++){
                if (componente[x] ==j) printf ("%c,", 'a' + x);
            }
            printf ("\n");
        }
        printf ("%d connected components\n\n", qtd);
    }
    return 0;
}
