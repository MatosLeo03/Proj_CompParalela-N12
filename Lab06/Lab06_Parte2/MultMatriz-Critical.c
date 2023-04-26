#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define M 3 
#define N 3 
#define P 3 

int A[M][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int B[N][P] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int C[M][P];

int threads_count = 3; // Número de threads utilizadas 

int main(int argc, char* argv[]) {
    int i, j, k;
    int local_m = M / threads_count; 
    
    #pragma omp parallel num_threads(threads_count)
    {
        int my_rank = omp_get_thread_num(); // Obtém o identificador da thread
        int my_first_row = my_rank * local_m; 
        int my_last_row = (my_rank + 1) * local_m - 1;
        
        // Calculando as linhas de C que essa thread irá calcular
        for (i = my_first_row; i <= my_last_row; i++) {
            for (j = 0; j < P; j++) {
                int temp = 0;
                for (k = 0; k < N; k++) {
                    temp += A[i][k] * B[k][j];
                }
                #pragma omp critical
                {
                    C[i][j] += temp;
                }
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
