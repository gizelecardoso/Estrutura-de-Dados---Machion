ARQUIVO pilha.h

4 - Typedef - arquivo para colocar apelidos para tipos já existentes
    no caso criamos um typedef para uma pilha do tipo STRUCT - e damos o apelido de Pilha.

PONTEIROS
    Conceito: Variáveis especiais que armazenam endereços de memória. Finalidade apontar um endereço de memória;
    Formas básicas: 
        1 - declaração de variáveis - tipo_da_variável * nome_variavel
        2 - Pegar um endereço da memória - int *p - p=&d - ponteiro p do tipo int - e esse vetor recebe o endereço de memoria da variável a.
            printf("%d", d) - imprime o valor do inteiro d.
            printf("%d", &d) - imprime o endereço da variável d.
            printf("%p", p) - imprime o endereço onde o p aponta - no caso o endereço de d.
            
        3 - (LER) Acessar o conteúdo da variável ao qual o ponteiro aponta (* nome_variável) .
            printf("%p", *p) - imprime o conteudo da variavel d.

            3.1 - (ESCREVER) Também permite modificar o conteúdo da variável.
                *p = 12;
    Operações:
        1- ATRIBUIÇÃO: 
            Um ponteiro só pode receber o endereço de memória  de uma variável do mesmo tipo do ponteiro.
                int *p / int a / float b     - p = &a OK    -   p = &b ERRADO

        2 - SOMA e SUBTRAÇÃO:
            São as únicas operações matemáticas que podemos fazer com um vetor - VALORES INTEIROS A UM PONTEIRO
    * criando um método que é um PONTEIRO do tipo PILHA e recebe como parâmetro um inteiro = Pilha * cria_pilha(int)
