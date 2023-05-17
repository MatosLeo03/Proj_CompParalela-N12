#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    
    printf("A = valor inicial\nB = valor final\nN = número de trapézios\n\n");
    printf("Ínserir valores de *a*, *b* e *n* \n");
    if (scanf("%lf %lf %d", &a, &b, &n) != 3 || n <= 0) {
        printf("Erro na inserção.\n");
        return 1;
    }

    double h = (b - a) / n;
    #pragma acc parallel loop reduction(+:global_result)
    for (int i = 0; i < n; i++) {
        double local_a = a + i * h;
        double local_b = local_a + h;
        double my_result;
        Trap(local_a, local_b, 1, h, &my_result);
        global_result += my_result;
    }

    printf("Com n = %d trapézios\n", n);
    printf("O valor aproximado da integral entre %f e %f = %.14e\n", a, b, global_result);

    return 0;
}
