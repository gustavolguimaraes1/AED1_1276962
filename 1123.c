/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1123
Data        : 26/11/2026
Objetivo    : Achar o menor custo de um serviço de caminhão testando os diferentes caminhos para voltar para a rota.
Dificuldade : Juntar o custo de voltar para a rota com o custo de continuar na rota.
Uso de IA   : Explicar como resolver essa dificuldade.
------------------------------------------------------------------------- */

#include <stdio.h>
#define INF 99999999

void dijkstra (int N, int grafo[N][N], int K, int voltaRota[], int C){
    int visitado[N];
    int i;
    for (i=0 ; i<N ; i++){
        visitado[i] = 0;
        voltaRota[i] = INF;
    }
    voltaRota[K] = 0;
    for (i = 0; i<N ; i++){
        int menor = INF;
        int u = -1;
        for (int j = 0; j<N; j++){
            if (!visitado[j] && voltaRota[j] < menor){
                menor = voltaRota[j];
                u = j;
            }
        }
        if (u == -1) break;
        visitado[u] = 1;
        if (u>=C){
            for (int v =0 ; v<N ; v++){
                if (grafo[u][v] != -1 && !visitado[v]){
                    if (voltaRota[u] + grafo[u][v] < voltaRota[v]){
                        voltaRota[v] = voltaRota[u] + grafo[u][v];
                    }
                }
            }
        }
    }
}

int main (){
    while (1){
        int N, M, C, K;
        scanf ("%d %d %d %d", &N, &M, &C, &K);
        if (N == 0 && M == 0 && C == 0 && K == 0) break;
        if (N >=4 && N <=250 && M >= 3 && M <= N*(N-1)/2 && C>=2 && C <= N-1 && K >= C && K <= N-1){
            int grafo[N][N];
            int i, j, a, b, c;
            for (i=0 ; i<N ; i++){
                for (j=0 ; j<N ; j++){
                    if (i == j) grafo[i][j] = 0;
                    else grafo[i][j] = -1;
                }
            }
            for (i=0 ; i< M ; i++){
                scanf ("%d %d %d", &a, &b, &c);
                grafo[a][b] = c;
                grafo[b][a] = c;
            }
            int voltaRota[N];
            dijkstra (N, grafo, K, voltaRota, C);
            int custo[C];
            custo[C-1] = 0;
            for (i = C-2 ; i>=0 ; i--){
                custo[i] = custo[i+1] + grafo[i][i+1];
            }
            int barato = INF;
            for (i=0 ; i<C ; i++){
                if (voltaRota[i] + custo[i] < barato){
                    barato = voltaRota[i] + custo[i];
                }
            }
            printf ("%d\n", barato);
        }
    }
    return 0;
}
