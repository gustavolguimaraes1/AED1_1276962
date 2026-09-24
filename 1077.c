/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 24/09/2026
Objetivo    : Transformar uma expressão infixa em uma posfixa.
Dificuldade : Como colocar os operadores na ordem correta e usá-los adequadamente.
Uso de IA   : Para entender uma forma que eu poderia colcoar os operadores na sequencia correta na forma posfixa.
------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    char valor;
    struct Celula *prox;
} Celula;

void push (Celula **pilha, char valor){
    Celula *novo = malloc(sizeof(Celula));
    novo->valor = valor;
    novo->prox = *pilha;
    *pilha = novo;
}

char pop (Celula **pilha){
    char valor = (*pilha)->valor;
    Celula *p = *pilha;
    *pilha = (*pilha)->prox;
    free (p);
    return valor;
}

int prioridade (char operador){
    if (operador == '+' || operador == '-')
        return 1;
    if (operador == '*' || operador == '/')
        return 2;
    if (operador == '^')
        return 3;
    return 0;
}

int main (){
    int n, i, j;
    scanf ("%d", &n);
    getchar ();
    char expressao[300];
    for (j = 0; j<n ; j++){
        fgets (expressao, 300, stdin);
        Celula *pilha = NULL;
        for (i=0 ; expressao[i] != '\0' ; i++){
            if ((expressao[i] >= 'A' && expressao[i]<= 'Z') || (expressao[i] >='a' && expressao[i] <= 'z') || (expressao[i] >= '0' && expressao[i] <='9')){
                printf ("%c", expressao[i]);
            } else if (expressao[i] == '(') {
                    push (&pilha, expressao[i]); 
            } else if (expressao[i] == ')'){
                while (pilha != NULL && pilha->valor != '('){
                    printf ("%c", pop(&pilha));
                }
                if (pilha != NULL) pop (&pilha);
            } else if (expressao[i] == '+' || expressao[i] == '^' || expressao[i] == '-' || expressao[i] == '*' || expressao[i] == '/'){
                while (pilha != NULL && pilha->valor != '(' && prioridade(pilha->valor) >= prioridade(expressao[i])){
                    printf ("%c", pop (&pilha));
                }
                push (&pilha, expressao[i]);
            }
        }
        while (pilha != NULL){
            printf ("%c", pop (&pilha));
        }
        printf ("\n");
    }
    return 0;
}
