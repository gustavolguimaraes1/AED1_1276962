/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 27/08/2026
Objetivo    : Leia 100 valores inteiros. Apresente então o maior valor lido e a posição dentre os 100 valores lidos com alocação dinâmica de vetores.
Dificuldade : Passar para a função o vetor.
Uso de IA   : Não usei.
------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

void func (int *v, int n){
    int maior, posicao, i;
    maior = v[0];
    posicao = 1;
    for (i=0 ; i<n ; i++){
        if (v[i] > maior){
            maior = v[i];
            posicao = i + 1;
        }
    }
    printf ("O maior valor = %d e esta na posicao %d", maior, posicao);
}

int main (){
    int *v;
    int i;
    // Aqui vou selecionar espaço da memoria para poder caber o vetor
    v = (int * ) malloc(100 * sizeof(int));
    // verificar se o espaço que eu reservei está vazio 
    if (v == NULL){
        printf ("Erro de alocação\n");
        return 1;
    }
    printf ("Digite os valores : ");
    for (int i = 0; i < 100; i++) {
    scanf("%d", &v[i]);
    }
    func (v, n);
    free (v);
    return 0;
}
