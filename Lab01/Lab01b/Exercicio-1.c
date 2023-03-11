#include <stdio.h>

int main() {
    int defMatriz[3][3] = {{7, 5, 2}, 
                        {7, 3, 1}, 
                        {4, 10, 4}}; 

    int menorEle = defMatriz[0][0];
    int linhaMenor = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (defMatriz[i][j] < menorEle) {
                menorEle = defMatriz[i][j];
                linhaMenor = i;
            }}}

    printf("O menor elemento é %d e está na linha %d.\n", menorEle, linhaMenor+1);

    return 0;
}
