#include <pthread.h>

int m, n; // Dimensões da matriz A
double **A; // Matriz A
double *x, *y; // Vetores x e y
int threads_count; // Número de threads

int main(int argc, char* argv[]) {
    long thread;
    pthread_t* thread_handles;

    thread_handles = malloc(threads_count*sizeof(pthread_t));
    for (thread = 0; thread < threads_count; thread++) {
        pthread_create(&thread_handles[thread], NULL,
            Pth_mat_vect, (void*) thread);
    }
    for (thread = 0; thread < threads_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }
    free(thread_handles);
    
    return 0;
}

void *Pth_mat_vect (void* rank){
long my_rank = (long) rank;
int i, j;
int local_m = m/threads_count;
int my_first_row = my_rank*local_m;
int my_last_row = (my_rank+1)*local_m - 1;

for (i = my_first_row; i <= my_last_row; i++)
	y[i] = 0.0;
	for (j = 0; j < n; j++)
		y[i] += A[i][j]*x[j];
	}
	
	return NULL;
} /*Pth_mat_vect */
