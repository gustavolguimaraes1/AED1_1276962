/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1200
Data        : 28/10/2026
Objetivo    : Montar frases posfixas, infixas, prefixas, inserir elementos e buscar elementos em árvores.
Dificuldade : Chegar na forma de organizar tudo isso no main.
Uso de IA   : Para saber como eu procuro as formas infixa, posfixa e prefixa na árvore.
------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
    char conteudo;
    struct cel *dir;
    struct cel *esq;
} no;

typedef no *arvore;

no *Criar (char c){
    no * novo = malloc(sizeof(no));
    novo->conteudo = c;
    novo->dir = novo->esq = NULL;
    return novo;
}

arvore InsereR (no *novo, arvore r){
    if (r == NULL) return novo;
    if (r->conteudo > novo->conteudo) 
        r->esq = InsereR (novo, r->esq);
    else r->dir = InsereR (novo, r->dir);    
    return r;
}

int Busca (char c, arvore r){
    if (r == NULL) return 0;
    if (r->conteudo == c) return 1;
    if (c < r->conteudo) return Busca (c, r->esq);
    else return Busca (c, r->dir);
}

void Infixa (arvore r, int *primeiro){
    if (r == NULL) return;
    Infixa (r->esq, primeiro);
    if (!(*primeiro))
        printf (" ");
    printf ("%c", r->conteudo);
    *primeiro = 0;
    Infixa (r->dir, primeiro);
}

void Prefixa (arvore r, int *primeiro){
    if (r == NULL) return;
    if (!(*primeiro))
        printf (" ");
    printf ("%c", r->conteudo);
    *primeiro = 0;
    Prefixa (r->esq, primeiro);
    Prefixa (r->dir, primeiro);
}

void Posfixa (arvore r, int *primeiro){
    if (r == NULL) return;
    Posfixa (r->esq, primeiro);
    Posfixa (r->dir, primeiro);
    if (!(*primeiro))
        printf (" ");
    printf ("%c", r->conteudo);
    *primeiro = 0;
}

int main (){
    arvore r= NULL;
    char comando[20];
    char c;
    no *novo;
    while (scanf("%19s", comando) != EOF){
        if (strcmp(comando,"I") == 0){
            scanf (" %c", &c);
            novo = Criar (c);
            r = InsereR (novo, r);
        } else if (strcmp(comando, "P") == 0){
            scanf (" %c", &c);
            if (Busca (c, r) == 0) printf ("%c nao existe\n", c);
            else printf ("%c existe\n", c);
        } else if (strcmp(comando, "INFIXA") == 0){
            int primeiro = 1;
            Infixa (r, &primeiro);
            printf ("\n");                    
        } else if (strcmp(comando, "PREFIXA") == 0){
            int primeiro = 1;
            Prefixa (r, &primeiro);
            printf ("\n"); 
        } else if (strcmp(comando, "POSFIXA") == 0){
            int primeiro = 1;
            Posfixa (r, &primeiro);
            printf ("\n"); 
        }
    }
    return 0;
}
