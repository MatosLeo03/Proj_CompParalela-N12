# Exercícios LAB 06:

## LAB 06 - PARTE I

### Passos de como compilar o programa em C

Para compilar o programa da pasta "Lab06" é necessário utilizar o compilador C GCC e o seguinte comando no terminal:

`gcc Lab06.c -o Lab06 -fopenmp -lm`

### Como executar o programa

Para executar o programa "Lab06.c" vamos utilizar o seguinte comando no terminal: 

`./Lab06`

### Comprovação de resultado

Esse código realiza uma aproximação numérica para calcular a integral de uma função usando a regra do trapézio em juntamente da biblioteca OpenMP. Ele solicita a entrada do intervalo, o número de trapézios e usa múltiplas threads (por padrão 4) para calcular a integral aproximada. O resultado é exibido na saída abaixo.

![image](https://user-images.githubusercontent.com/84693356/233215573-25d4dd52-7743-42ab-82f4-4e5a0068df65.png)

## LAB 06 - PARTE II

### Passos de como compilar o programa em C

Para compilar o programa da pasta "Lab06" é necessário utilizar o compilador C GCC e o seguinte comando no terminal:

`gcc Lab06.c -o Lab06 -fopenmp -lm`

### Como executar o programa

Para executar o programa "Lab06.c" vamos utilizar o seguinte comando no terminal: 

`./Lab06`

### Comprovação de resultado

Os métodos "critical" e "reduction" são fundamentais no OpenMP para garantir a precisão e a performance de programas paralelos. A cláusula "critical" assegura a exclusão mútua de regiões críticas, evitando conflitos no acesso a recursos compartilhados. Enquanto isso, a cláusula "reduction" permite que cada thread calcule sua própria parcela em uma variável compartilhada, agilizando a soma final. A quantidade de processadores (e threads) afeta a velocidade de execução, já que aumentando a quantidade, é possível paralelizar mais tarefas e diminuir o tempo de execução.

### Gráfico das Comparações


|Método| 1 vCPU | 4 vCPU |
|--------| -------- | -------- |
| Critical | 7,813s | 4,726s |
| Reduction | 8,641s | 5,087s |


![image](https://user-images.githubusercontent.com/84693356/234723191-fdfd51fb-6feb-433d-a9cc-ec468edf0f0e.png)

*_Foram utilizados os dados de tempo de execução do algoritmo da Regra dos Trapézios_

## LAB 06 - PARTE III

![image](https://user-images.githubusercontent.com/84693356/235823347-e1591e89-0695-4fc3-a412-ebd1600eeb91.png)

