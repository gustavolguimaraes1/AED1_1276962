/* -----------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gustavo Lima Guimarães
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 20/08/2026
Objetivo    : Verificar se o sudoku está corretamente preenchido.
Dificuldade : Alta.
Uso de IA   : Para achar a solução de verificar os "mini quadrantes" (3x3).
------------------------------------------------------------------------- */

#include <stdio.h>

int verifica (int v[]){
    int i, j;
    for (i=0 ; i<9 ; i++){
        if (v[i] < 1 || v[i] > 9){
            return 0;
        }
        for (j=i+1 ; j<9 ; j++){
            if (v[i] == v[j])
                return 0;
        }
    }
    return 1;
}
int main (){
    int v[9];
    int M[9][9];
    int n, instancia, valido;
    int i, j, a, b, pos;
    scanf ("%d", &n);
    for (instancia = 1 ; instancia <= n ; instancia++){
        valido = 1;
        /*lê a matriz*/
        for (i=0 ; i<9 ; i++){
            for (j=0 ; j<9 ; j++){
                scanf ("%d", &M[i][j]);
            }
        }
        /*verifica se a linha tem algum repetido*/
        for (i=0 ; i<9 ; i++){
            for (j=0 ; j<9 ; j++){
                v[j] = M[i][j];
            }
            if (!verifica(v))
                valido = 0;
        }
        /*verifica se a coluna tem algum repetido*/
        for (j=0 ; j<9 ; j++){
            for (i=0 ; i<9 ; i++){
                v[i] = M[i][j];
            }
            if (!verifica(v))
                valido = 0;
        }
        /*verifica as regioes 3x3 */
        for (i=0 ; i<9 ; i += 3){
            for (j=0 ; j<9 ; j+= 3){
                pos = 0;
                for (a = i ; a < i+3 ; a++){
                    for (b = j; b<j+3 ; b++){
                        v[pos] = M[a][b];
                        pos++;
                    }
                }
                if (!(verifica(v)))
                valido = 0;
            }
        }
        /*mostrar o resultado*/
        printf ("Instancia %d\n", instancia);
        if (valido){
            printf ("SIM\n\n");
        } else{
            printf ("NAO\n\n");
        }
    }    
    return 0;
}
