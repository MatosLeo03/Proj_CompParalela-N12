#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    int idade;
    float peso;
    float altura;
}Pessoa;

int main() {
        Pessoa pessoas[3];

    for (int i = 0; i < 3; i++) {
        printf("Insira o nome da pessoa: ");
        scanf("%s", pessoas[i].nome);
        printf("Insira a idade da pessoa: ");
        scanf("%d", &pessoas[i].idade);
        printf("Insira o peso da pessoa: ");
        scanf("%f", &pessoas[i].peso);
        printf("Insira a altura da pessoa: ");
        scanf("%f", &pessoas[i].altura);
    }

    for (int i = 0; i < 3; i++) {
        printf("--Dados da pessoa--\n");
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d anos\n", pessoas[i].idade);
        printf("Peso: %.2f kg\n", pessoas[i].peso);
        printf("Altura: %.2f m\n", pessoas[i].altura);
        printf("\n");
    }

    return 0;
}
