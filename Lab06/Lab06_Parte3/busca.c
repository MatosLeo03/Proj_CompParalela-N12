#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int i, x, valorEnc = 0;
    int vetor[65536];

    // Abrir arquivo de entrada
    FILE *arquivo = fopen("vetor1.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    // Ler números do arquivo
    i = 0;
    while (fscanf(arquivo, "%d", &vetor[i]) != EOF) {
        i++;
    }
    fclose(arquivo);

    printf("Digite o valor para ser buscado no vetor: ");
    scanf("%d", &x);

    // Buscar elemento no vetor
    #pragma omp parallel num_threads(omp_get_max_threads())
    {
        int id = omp_get_thread_num();
        int inicio = id * (65536 / omp_get_num_threads());
        int fim = (id + 1) * (65536 / omp_get_num_threads());

        for (i = inicio; i < fim; i++) {
            if (vetor[i] == x) {
                valorEnc = 1;
                printf("Elemento encontrado na posição %d pela thread %d\n", i, id);
            }
        }
    }

    if (!valorEnc) {
        printf("Elemento não encontrado\n");
    }

    return 0;
}
