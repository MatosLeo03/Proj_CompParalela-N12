//Esse código implementa a multiplicação de matrizes utilizando memória compartilhada, porém sem otimização

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define R1 3 // número de linhas na Matriz 1
#define C1 3 // número de colunas na Matriz 1
#define R2 3 // número de linhas na Matriz 2
#define C2 3 // número de colunas na Matriz 2

void mulMat(int mat1[][C1], int mat2[][C2], int *rslt)
{
    printf("A multiplicação das matrizes é:\n");

    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            rslt[i * C2 + j] = 0;

            for (int k = 0; k < R2; k++) {
                rslt[i * C2 + j] += mat1[i][k] * mat2[k][j];
            }

            printf("%d\t", rslt[i * C2 + j]);
        }

        printf("\n");
    }
}

int main()
{
    int mat1[R1][C1];
    int mat2[R2][C2];
    int shmid;
    int *rslt;

    // Preenche as matrizes com valores sequenciais
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C1; j++) {
            mat1[i][j] = i * C1 + j + 1;
            mat2[i][j] = i * C2 + j + 1;
        }
    }

    // Aloca um segmento de memória compartilhada
    shmid = shmget(IPC_PRIVATE, sizeof(int) * R1 * C2, IPC_CREAT | 0666);

    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    rslt = shmat(shmid, NULL, 0);

    if (rslt == (int *) -1) {
        perror("shmat");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) { 
        mulMat(mat1, mat2, rslt);
        exit(0);
    } else { // Processo pai
        wait(NULL);

        printf("\nResultado:\n");

        for (int i = 0; i < R1; i++) {
            for (int j = 0; j < C2; j++) {
                printf("%d\t", rslt[i * C2 + j]);
            }

            printf("\n");
        }

        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}
