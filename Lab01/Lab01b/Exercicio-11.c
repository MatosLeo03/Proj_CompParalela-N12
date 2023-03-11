#include <stdio.h>

void matrizSoma(int n[][3], int linha, int coluna, int L1, int L2) {
    int i;
    int sum = 0, mult = 1;

    for (i = 0; i < coluna; i++) {
        sum += n[L1][i];
        sum += n[L2][i];
        n[L2][i] = sum;
        sum = 0;
    }
}

int main() {
    int n[2][3] = { {1, 2, 3},
                      {4, 5, 6}, };
    int linha = 2;
    int coluna = 3;
    int L1 = 0;
    int L2 = 1;

    printf("Matriz:\n\n");
    int i, j;
    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            printf("%d ", n[i][j]);
        }
        printf("\n");
    }

    matrizSoma(n, linha, coluna, L1, L2);
    printf("Matriz com linhas somadas:\n\n");
    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            printf("%d ", n[i][j]);
        }
        printf("\n");
    }

    return 0;
}
