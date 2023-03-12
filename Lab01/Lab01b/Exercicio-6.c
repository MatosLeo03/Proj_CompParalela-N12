#include <stdio.h>

int main() {
    int matriz[50][50], matrizTras[50][50];
    int lin, col, i, j;

    printf("número de linhas: ");
    scanf("%d", &lin);
    printf("número de colunas: ");
    scanf("%d", &col);

    printf("inserir elementos:\n");
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (i = 0; i < col; i++) {
        for (j = 0; j < lin; j++) {
            matrizTras[i][j] = matriz[j][i];
        }
    }
    printf("Transposta:\n");
    for (i = 0; i < col; i++) {
        for (j = 0; j < lin; j++) {
            printf("%d ", matrizTras[i][j]);
        }
        printf("\n");
    }

    return 0;
}
