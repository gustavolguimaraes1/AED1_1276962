/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1194
Data        : 26/11/2026
Objetivo    : Transformar espressoes infixa e prefixa de uma arvore em uma posfixa.
Dificuldade : Entender onde colocar o passo recursivo.
Uso de IA   : Para implementar o passo recursivo.
------------------------------------------------------------------------- */

#include <stdio.h>

void posfixa (char pre[], char inf[], int N){
    if (N == 0) return;
    char raiz = pre[0];
    int k;
    for (k=0 ; k<N ; k++){
        if (inf[k] == raiz) break;
    }
    posfixa (pre+1, inf, k);
    posfixa (pre+k+1, inf+k+1, N-k-1);
    printf ("%c", raiz);
}


int main (){
    int C;
    scanf ("%d", &C);
    for (int i =0; i<C ; i++){
        int N;
        scanf ("%d", &N);
        char pre[N+1];
        char inf[N+1];
        scanf ("%s", pre);
        scanf ("%s", inf);
        posfixa (pre, inf, N);
        printf ("\n");
    }
    return 0;
}
