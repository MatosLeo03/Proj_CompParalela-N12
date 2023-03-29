# Exercícios LAB 04:

### Passos de como compilar o programa em C

Para compilar os programas da pasta "Lab04" é necessário utilizar o compilador C GCC e o seguinte comando no terminal:

`gcc Lab04.c -o Lab04.out`

### Como executar o programa

Para executar o programa "Lab04.c" vamos utilizar o seguinte comando no terminal: 

`./Lab04.out`

### Comprovação de resultado

Este código implementa a multiplicação de matrizes utilizando memória compartilhada. O processo pai aloca um segmento de memória compartilhada e cria um processo filho para executar a multiplicação de matrizes. O resultado é armazenado na memória compartilhada e depois exibido pelo processo pai.

No final de execução, considerando matrizes de tamanho 1000 cada, obtivemos o resultado de *25.789s* para a conclusão das multiplicações.

![Screenshot from 2023-03-29 20-45-39](https://user-images.githubusercontent.com/84693356/228692359-b1cdd43b-faad-4c03-b856-2100ae149b75.png)

Porém ao tentar executar utilazando os métodos de compilação propostos como *-o0* e *-03* e programa apresentou uma falha e não foi possível testá-lo.




