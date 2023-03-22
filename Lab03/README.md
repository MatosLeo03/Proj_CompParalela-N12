# Exercícios LAB 03:

### Passos de como compilar o programa em C

Para compilar o programas da pasta "Lab03" é necessário utilizar o compilador C GCC e o seguinte comando no terminal:

`gcc Lab03.c -o Exercicio-Memória.out`

### Como executar o programa

Para executar o programa "Lab03.c" vamos utilizar o seguinte comando no terminal: 

`./Lab03.out`

### Comprovação de resultado

O programa na linguagem C consiste em criar um processo pai que estabelece uma região de memória compartilhada, associa a região de memória compartilhada ao processo pai, define um valor inicial para a variável compartilhada e gera um processo filho. O processo filho modifica o valor da variável compartilhada e  aguarda o término. Por fim, o processo pai atualiza o valor da variável compartilhada, desassocia e remove a região de memória compartilhada.

Dessa maneira, ao executarmos o comando acima o programa deverá exibir no terminal a resposta do exercício:

> Pai: valor inicial = 5`

> Valor inicial do filho = 5`

> Novo valor do filho = 7`

> Novo valor do pai = 28`

