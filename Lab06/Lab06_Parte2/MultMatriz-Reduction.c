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


void Mat_vect() {
    int i, j, k;
    int local_m = M / threads_count;
    int my_first_row = omp_get_thread_num() * local_m;
    int my_last_row = (omp_get_thread_num() + 1) * local_m - 1;

    for (i = my_first_row; i <= my_last_row; i++) {
        for (j = 0; j < P; j++) {
            int sum = 0; 
#pragma omp parallel for reduction(+:sum) // Cria uma região paralela e aplica a cláusula de reduction
            for (k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum; 
        }
    }
}

int main(int argc, char* argv[]) {
    omp_set_num_threads(threads_count);

#pragma omp parallel
    Mat_vect();

    printf("Resultado da multiplicação de matrizes:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
