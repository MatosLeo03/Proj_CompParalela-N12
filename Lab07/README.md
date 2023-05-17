# Exercícios LAB 07:

## LAB 07 - OpenACC

### Passos de como compilar o programa em C

Para compilar o programa da pasta "Lab07" é necessário utilizar o compilador C GCC e a bibliotec OpenACC. Segue o comando no terminal:

`/opt/nvidia/hpc_sdk/Linux_x86_64/23.3/compilers/bin/nvc  -acc -gpu=managed  -fast -Minfo=accel -o Lab07 Lab07.c`

### Como executar o programa

Para executar o programa "Lab07.c" vamos utilizar o seguinte comando no terminal: 

`./Lab07`

### Comprovação de resultado

O OpenACC é um modelo de programação projetado para simplificar a programação paralela de sistemas heterogêneos CPU/GPU. Ele é um padrão aberto para programação paralela que permite aos desenvolvedores acelerar aplicativos em uma ampla variedade de plataformas de hardware.

Para a verificação mais detalhada do hardware, utilizamos o comando nvidia-smi. É uma ferramenta de linha de comando fornecida pela NVIDIA para monitorar e gerenciar GPUs NVIDIA em um sistema. Ele exibe informações sobre o uso da GPU, consumo de energia, temperatura e outros parâmetros. Abaixo um print como exeplo:

![nvidia-smi](https://github.com/MatosLeo03/Proj_CompParalela-N12/assets/84693356/db7a4633-c493-403b-9bad-dcfadbfbdeac)

![MultMatriz_acc](https://github.com/MatosLeo03/Proj_CompParalela-N12/assets/84693356/ac6a266a-ddd1-44ef-921e-75d55a49ce3c)

![Trapezio_acc](https://github.com/MatosLeo03/Proj_CompParalela-N12/assets/84693356/4099591d-0e5b-476f-ba9b-a8ce6d6bd7e2)
