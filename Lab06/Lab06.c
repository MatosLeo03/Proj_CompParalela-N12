#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double f(double x) {
    return sin(x);
}

void Trap(double local_a, double local_b, int local_n, double h, double* my_result_p) {
    double x, my_result;
    my_result = (f(local_a) + f(local_b)) / 2.0;
    for (int i = 1; i <= local_n - 1; i++) {
        x = local_a + i * h;
        my_result += f(x);
    }
    my_result = my_result * h;
    *my_result_p = my_result;
}

int main() {
    double global_result = 0.0; 
    double a, b;                
    int n;                      
    int thread_count;
    
    printf("A = valor inicial\nB = valor final\nN = número de trapézios
    printf("Ínserir valores de *a*, *b* e *n* \n");
    if (scanf("%lf %lf %d", &a, &b, &n) != 3 || n <= 0) {
        printf("Erro na inserção.\n");
        return 1;
    }

    thread_count = omp_get_max_threads();
    printf("Utilizando %d threads.\n", thread_count);

    double h = (b - a) / n;
    #pragma omp parallel num_threads(thread_count)
    {
        int my_rank = omp_get_thread_num();
        int local_n = n / thread_count;
        double local_a = a + my_rank * local_n * h;
        double local_b = local_a + local_n * h;
        double my_result;
        Trap(local_a, local_b, local_n, h, &my_result);
        #pragma omp critical
        global_result += my_result;
    }

    printf("Com n = %d trapézios", n);
    printf("O valor aproximado da integral entreo %f e %f = %.14e\n", a, b, global_result);

    return 0;
}
