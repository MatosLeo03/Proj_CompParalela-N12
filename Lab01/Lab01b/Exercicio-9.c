/*
EXERCÍCIO DE CP – TURMA 05N12
Leonardo Henrique de Oliveira Matos, TIA 32139561.
Atividade Lab 01b 
*/

#include <stdio.h>

void matrizModulo(int m[2][3], int linha, int col) {
    int i, j;
    for (i = 0; i < linha; i++) {
        for (j = 0; j < col; j++) {
            if (m[i][j] < 0) {
                m[i][j] = -m[i][j];
            }
        }
   }}

int main() {
    int m[2][3] = {{-1, 3, 4}, {8, -10, 9}};
    int i;
    int j;
    
    printf("Matriz:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    
    matrizModulo(m, 2, 3);
    
    printf("\nMatriz com modulo:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
