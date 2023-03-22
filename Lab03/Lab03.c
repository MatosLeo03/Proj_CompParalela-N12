#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE  sizeof(int)

int main()
{
    int shmid, *data;
    pid_t pid;

    // área de memória compartilhada
    if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((data = shmat(shmid, NULL, 0)) == (int *) -1) {
        perror("shmat");
        exit(1);
    }

   
    *data = 5; //Variável compartilhada

    printf("Pai: valor inicial = %d\n", *data);

    if ((pid = fork()) < 0) {// cria um novo processo
        perror("fork");
        exit(1);
    }

    if (pid == 0) {  
        printf("Valor inicial do filho = %d\n", *data);
        *data += 2;  
        printf("Novo valor do filho = %d\n", *data);

        
        if (shmdt(data) == -1) { //desanexar o segmento de memória compartilhada da área de dados do processo atual.
            perror("shmdt");
            exit(1);
        }

        exit(0);
    } else {  
        
        if (waitpid(pid, NULL, 0) == -1) {
            perror("waitpid");
            exit(1);
        }

        *data *= 4;  
        printf("Pai: novo valor = %d\n", *data);
      
        if (shmdt(data) == -1) {
            perror("shmdt");
            exit(1);
        }

        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}

