#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 3
#define P 3

int A[M][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int B[N][P] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int C[M][P];

int main(int argc, char* argv[]) {
    int i, j, k;

    #pragma acc data copyin(A, B) copyout(C)
    {
        #pragma acc parallel loop collapse(2)
        for (i = 0; i < M; i++) {
            for (j = 0; j < P; j++) {
                int temp = 0;
                for (k = 0; k < N; k++) {
                    temp += A[i][k] * B[k][j];
                }
                C[i][j] = temp;
            }
        }
    }

    // Imprime o resultado da multiplicação de matrizes armazenado na matriz C
    printf("Resultado da multiplicação de matrizes:\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < P; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

