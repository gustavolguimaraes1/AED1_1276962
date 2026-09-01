/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 01/09/2026
Objetivo    : Verificar se uma expressao está "correta", ou seja, o tanto de parenteses aberto = tanto que está fechado.
Dificuldade : Como criar a pilha com caracteres (adaptá-la)
Uso de IA   : Para ter uma ideia de por onde partir, quais elementos seriam colocados na pilha.
------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    char valor;
    struct Celula *prox;
} Celula;
// Coloca o elemento '(' no comeco da fila 
void push (Celula **topo, char x){
    Celula *p;
    p = malloc (sizeof(Celula));
    p->valor = x;
    p->prox = *topo;
    *topo = p;
}

// Verifica se ja tem um parenteses aberto para ele poder fechar e 'anular' ele
void pop (Celula **topo){
    Celula *p;
    p = *topo;
    *topo = p->prox;
    free(p);
}


int main (){
    Celula *topo;
    int i, j, N;
    char expressao [1001];
    int correto;
    scanf ("%d", &N);
    getchar ();
    if (N >= 1 && N <=10000){
        for (i = 0 ; i<N ; i++){
            topo = NULL;
            correto = 1;
            fgets (expressao, 1001, stdin);
            for (j = 0; expressao[j] != '\0' ; j++){
                if (expressao [j] == '('){
                    push(&topo, '(');
                } else if (expressao[j] == ')'){
                    if (topo == NULL){
                        correto = 0;
                        break;
                    }
                    pop (&topo);
                }
            }
            if (topo != NULL)
                correto = 0;
            if (correto == 1)
                printf ("correct\n");
            if (correto == 0)
                printf ("incorrect\n");
            while (topo != NULL)
                pop (&topo);
        }
    }
    return 0;
}
