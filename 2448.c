/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 24/09/2026
Objetivo    : Encomendas nas casas ordenadas (busca binária).
Dificuldade : Entender a forma como organizaria as encomendas para passar uma por uma para a função da busca.
Uso de IA   : Compreender como passaria cada encomenda de forma separada para a busca binária do vetor de casas ordenado.
------------------------------------------------------------------------- */

#include <stdio.h>

int buscabin (int x, int casas[], int n){
    int d = n;
    int e = 0;
    while (e<d){
        int meio = (d+e)/2;
        if (casas[meio] == x) {
            return meio;
        } else if (casas[meio] < x){
            e = meio + 1;
        } else d = meio;
    }
    return -1;
} 

int main (){
    int n, m, i;
    scanf ("%d %d", &n, &m);
    int casas[n];
    for (i=0 ; i<n ; i++){
        scanf ("%d", &casas[i]);
    }
    int encomendas[m];
    for (i=0 ; i<m ; i++){
        scanf ("%d", &encomendas[i]);
    }
    long long tempo = 0;
    int atual = 0;
    for (i=0 ; i<m ; i++){
        int destino = buscabin(encomendas[i], casas, n);
        if (destino > atual) tempo += (destino - atual);
        else tempo += (atual - destino);
        atual = destino;
    }
    printf ("%lld\n", tempo);
    return 0;
}
