# Exercícios LAB 05:

### Passos de como compilar o programa em C

Para compilar o programa da pasta "Lab05" é necessário utilizar o compilador C GCC e o seguinte comando no terminal:

`gcc Lab05.c -o Lab05.out`

### Como executar o programa

Para executar o programa "Lab05.c" vamos utilizar o seguinte comando no terminal: 

`./Lab05`

### Comprovação de resultado

O código realiza a multiplicação de duas matrizes de tamanho 3x3, utilizando três threads. As threads são criadas e cada uma realiza o cálculo de uma parcela das linhas da matriz resultado. Ao final da execução, é impressa na tela a matriz resultado da multiplicação. Como o tamanho das matrizes é pequeno, o uso de três threads pode não ter impacto significativo no tempo de execução do programa.
O tempo de execução do programa foi de 0.001s

![image](https://user-images.githubusercontent.com/84693356/231605714-62d8dc8f-d484-4c08-8b02-4d399b0f4c19.png)


