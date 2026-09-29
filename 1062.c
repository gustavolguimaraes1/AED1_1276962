/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 29/09/2026
Objetivo    : Pegar os vagões de um trem que estavam ordenados e pararão na estação e ver se eles podem ser realocados de outras formas.
Dificuldade : Manter ele testando para as permutações até chegar no zero. A primeira foi facil, mas a partir da segunda complicou.
Uso de IA   : para manter o laço até o zero.
------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int valor;
    struct Celula *prox;
} Celula;

void pop (Celula **aux){
    Celula *p = *aux;
    *aux = (*aux)->prox;
    free(p);
}

void push (Celula **pilha, int x){
    Celula *novo = malloc(sizeof(Celula));
    novo->valor = x;
    novo->prox = *pilha;
    *pilha = novo;
}

int main (){
    int n, i;
    scanf ("%d", &n);
    while (n != 0){
        int exp[n];
        while (1){
            scanf ("%d", &exp[0]);
            Celula *lst;
            lst = malloc(sizeof(Celula));
            lst->valor = 1;
            lst->prox = NULL;
            Celula *fim = lst;
            for (i=2 ; i<=n ; i++){
                Celula *p = malloc(sizeof(Celula));
                p->valor = i;
                p->prox = NULL;
                fim->prox = p;
                fim = p;
            }
            if (exp[0] == 0) break;
            for (i=1 ; i<n ; i++){
                scanf ("%d", &exp[i]);
            }
            Celula *pilha = NULL;
            for (i=0 ; i<n ; i++){
                if (pilha != NULL && pilha->valor == exp[i]){
                pop (&pilha);
                } else {
                    while (lst != NULL && lst ->valor != exp[i]){
                    push(&pilha, lst->valor);
                    pop(&lst);
                    }
                    if (lst != NULL && lst->valor == exp[i])
                        pop(&lst);
                }
            }
            if (pilha != NULL || lst != NULL) printf ("No\n");
            else printf ("Yes\n");
            while (pilha != NULL) pop(&pilha);
            while (lst != NULL) pop (&lst);
        }
        printf ("\n");
        scanf ("%d", &n);
    }
    return 0;
}
