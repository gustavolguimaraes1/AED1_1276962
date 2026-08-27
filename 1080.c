/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 20/08/2026
Objetivo    : Leia 100 valores inteiros. Apresente então o maior valor lido e a posição dentre os 100 valores lidos.
Dificuldade : Nenhuma. Foi simples.
Uso de IA   : Não usei.
------------------------------------------------------------------------- */

#include <stdio.h>

void achar (int v[]){
    int j, maior, indice;
    indice = 1;
    maior = v[0];
    for (j=1; j<100 ; j++){
        if (v[j] > maior){
            maior = v[j];
            indice = j + 1;
        }
    }
    printf ("%d\n%d\n", maior, indice);
}

int main (){
    int v[100], i;
    for (i=0 ; i<100 ; i++)
        scanf ("%d", &v[i]);
    achar (v);
    return 0;
}
