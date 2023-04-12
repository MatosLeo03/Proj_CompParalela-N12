#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define M 3 
#define N 3 
#define P 3 

int A[M][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int B[N][P] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int C[M][P];

int threads_count = 3; // Número de threads utilizadas 

// Função executada por cada thread
void *Pth_mat_vect(void* rank) {
    long my_rank = (long) rank; // Convertendo o parâmetro rank para um long

    int i, j, k;
    int local_m = M / threads_count; 
    int my_first_row = my_rank * local_m; 
    int my_last_row = (my_rank + 1) * local_m - 1; 

    // Calculando as linhas de C que essa thread irá calcular
    for (i = my_first_row; i <= my_last_row; i++) {
        for (j = 0; j < P; j++) {
            C[i][j] = 0;
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return NULL;
}

int main(int argc, char* argv[]) {
    long thread;
    pthread_t* thread_handles;

    thread_handles = malloc(threads_count*sizeof(pthread_t)); // Aloca memória para armazenar os identificadores das threads
    // Cria cada thread
    for (thread = 0; thread < threads_count; thread++) {
        pthread_create(&thread_handles[thread], NULL,
            Pth_mat_vect, (void*) thread);
    }

    for (thread = 0; thread < threads_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    free(thread_handles); // Libera a memória alocada

    // Imprime o resultado da multiplicação de matrizes armazenado na matriz C
    printf("Resultado da multiplicação de matrizes:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
