/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 01/09/2026
Objetivo    : Montar uma pilha com numeros de 1 ate um n, e ai tirar o elemento do topo e colocar o proximo por ultimo e assim sucessivamente ate sobrar um elemento.
Dificuldade : Entender a logica do problema. Adaptar para retirar todos e depois deixar o que sobrar.
Uso de IA   : Para entender o problema, o que ele queria que eu fizesse.
------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    int valor;
    struct Celula *prox;
} Celula;

int main (){
    int n;
    Celula *lst;
    Celula *fim;
    Celula *p;
    int i;
    printf ("Digite um numero de cartas (ate 50) : ");
    scanf ("%d", &n);
    while (n!=0){
        lst = NULL;
        fim = NULL;
        for (i=1 ; i<=n ; i++){
            p = malloc (sizeof(Celula));
            if (p == NULL)
                return 1;
            p->valor = i;
            p->prox = NULL;
            if (lst == NULL){
                lst = p;
                fim = p;
            } else {
                fim->prox = p;
                fim = p;
            }
        }
    
        printf ("\nDiscarded cards : ");
        while (lst != fim){
            // descarta o topo
            p = lst;
            lst = lst->prox;
            printf (" %d ", p->valor);
            free (p);
            if (lst == fim)
                break;
            // pega a carta que esta no novo topo e coloca ela no final
            p = lst;
            lst = p->prox;
            //coloca a carta no final
            p->prox = NULL;
            fim->prox = p;
            fim = p;
        }
        printf ("\nRemaining card : %d\n", lst->valor);
        free (lst);
        printf("Digite o numero de cartas: ");
        scanf ("%d", &n);
    }
    return 0;   
}
