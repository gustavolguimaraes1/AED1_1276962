/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 27/08/2026
Objetivo    : Verificar se o sudoku está corretamente preenchido usando alocação dinâmica de matrizes.
Dificuldade : Alta.
Uso de IA   : Para auxiliar na solução de verificar os "mini quadrantes" (3x3).
------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int verifica (int *v){
    int i, j;
    // verifica se os numeros vao de 1 a 9
    for (i=0 ; i<9 ; i++){
        if (v[i] < 1 || v[i] > 9){
            return 0;
        }
        // verifica se os numeros nao repetem
        for (j=i+1 ; j<9 ; j++){
            if (v[i] == v[j]){
            return 0;
            }
        }
    }
    return 1;
}

int main (){
    //O vetor é auxiliar para conseguir passar os valores para a funcao e comparar
    int *v;
    int **M;
    int n, instancia, valido;
    int i, j, a, b, pos;
    printf ("Digite o numero de instancias : ");
    scanf ("%d", &n);
     // alocar as posicoes para o vetor
    v = (int *) malloc (9*sizeof(int));
    if (v == NULL){
        printf ("ERRO DE ALOCACAO");
        return 1;
    }
    // instancia é a qtd de sudokus que ele vai inserir que vai variar ate a qtd n indicada
    for (instancia = 1; instancia <= n ; instancia++){
        valido = 1;
        //alocar as posicoes para a matriz
        M = (int **) malloc (9*sizeof(int *));
        if (M == NULL){
            printf ("ERRO DE ALOCACAO\n");
            return 1;
        }
        for (i = 0 ; i < 9 ; i++){
            M[i] = (int *) malloc (9*sizeof(int));
            if (M[i] == NULL){
                printf ("ERRO DE ALOCACAO\n");
                return 1;
            }
        }
        //lê a matriz
        for (i=0 ; i<9 ; i++){
            for (j=0 ; j<9 ; j++){
                scanf ("%d", &M[i][j]);
            }
        }
        //verificar as linhas
        for (i=0 ; i<9 ; i++){
            for (j=0 ; j<9 ; j++){
                v[j] = M[i][j];
            }
            if (!verifica(v))
                valido = 0;
        }
        //verificar as colunas
        for (j=0 ; j<9 ; j++){
            for (i=0 ; i<9 ; i++){
                v[i] = M[i][j];
            }
            if (!verifica(v))
                valido = 0;
        }
        //verificar os "Mini quadrados"
        for (i=0 ; i<9 ; i += 3){
            for (j=0 ; j< 9 ; j += 3){
                pos = 0;
                for (a = i ; a < i+3 ; a++){
                    for (b = j ; b < j+3 ; b++){
                        v[pos] = M[a][b];
                        pos++;
                    }
                }
                if (!(verifica(v)))
                valido = 0;
            }
        }
        //mostrar os resultados
        printf ("Instancia : %d", instancia);
        if (valido){
            printf ("SIM\n");
        }else { 
            printf ("NAO\n");
        }
        for (i =0 ; i<9 ; i++){
            free (M[i]);
        }
        free (M);
    }
    free (v);
    return 0;
}
