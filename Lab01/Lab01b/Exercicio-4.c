#include <stdio.h>
#include <string.h>

int main() {
    char nomeA[50], nomeB[50];

    printf("Digite os nomes: ");
    scanf("%s %s", nomeA, nomeB);

    if (strcmp(nomeA, nomeB) < 0) {
        printf("%s\n%s\n", nomeA, nomeB);
    } else if (strcmp(nomeA, nomeB) > 0) {
        printf("%s\n%s\n", nomeB, nomeA);
    } else {
        printf("Os nomes são iguais: %s\n", nomeA);
    }

    return 0;
}
