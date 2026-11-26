/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1191
Data        : 26/11/2026
Objetivo    : Transformar uma expressao prefixa e infixa em uma posfixa usando arvore.
Dificuldade : Entender como usar a recursividade.
Uso de IA   : Entender como os valores retornavam e em que trecho isso acontecia.
------------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>
#define MAX 27

void posfixo (char pre[], char inf[], int n){
    if (n ==0) return;
    char raiz = pre[0];
    int k;
    for (k=0 ; k<n ; k++){
        if (inf[k] == raiz) break;
    }
    posfixo (pre+1, inf, k);
    posfixo (pre+k+1, inf + k + 1, n-k-1);
    printf ("%c", raiz);
}

int main (){
    char pre[MAX], inf[MAX];
    while (scanf ("%s %s", pre, inf) != EOF){
        int n = strlen(pre);
        posfixo (pre, inf, n);
        printf ("\n");
    }
    return 0;
}
