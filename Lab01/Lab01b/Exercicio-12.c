/*
EXERCÍCIO DE CP – TURMA 05N12
Leonardo Henrique de Oliveira Matos, TIA 32139561.
Atividade Lab 01b 
*/
#include <stdio.h>
#include <string.h>

int achaString(char *str, char x) {
    int tamString = strlen(str);
    for (int i = 0; i < tamString; i++) {
        if (str[i] == x) {
            return i+1;
        }
    }
    return 0;
}

int main() {
    char str[] = "abacaxi";
    char x = 'b';
    int posicaoString = achaString(str, x);
      if(posicaoString < 0){
        printf("Impossível localizar");
          }
  else{
        printf("O caracterfoi encontrado na posicao %d\n", posicaoString);
    }
    return 0;
  }
