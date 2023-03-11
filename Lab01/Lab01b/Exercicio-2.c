#include <stdio.h>

int main() {
    float N1, N2, N3, mediaEx, mediaFinal;

    printf("Inserir a nota 1: ");
    scanf("%f", &N1);;
    printf("Inserir a nota 2: ");
    scanf("%f", &N2);;
    printf("Inserir a nota 3: ");
    scanf("%f", &N3);
    printf("Inserir a média dos exercícios: ");
    scanf("%f", &mediaEx);

    mediaFinal = (N1 + N2*2 + N3*3 + mediaEx)/7;

    printf("Média final de aproveitamento: %.2f\n", mediaFinal);
    if (mediaFinal >= 9) {
        printf("Nota A\n");
    } else if (mediaFinal >= 7.5 && mediaFinal < 9) {
        printf("Nota B\n");
    } else if (mediaFinal >= 6 && mediaFinal < 7.5) {
        printf("Nota C\n");
    } else if (mediaFinal >= 4 && mediaFinal < 6) {
        printf("Nota D\n");
    } else {
        printf("Nota E\n");
    }

    return 0;
}
