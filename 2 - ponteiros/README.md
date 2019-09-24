PONTEIROS
    
                            arquivo inicial teste.c

    Conceito: Variáveis especiais que armazenam endereços de memória. Finalidade apontar um endereço de memória;
    
    1) FORMAS BÁSICAS: 
        1 - declaração de variáveis - tipo_da_variável * nome_variavel
        2 - Pegar um endereço da memória - int *p - p=&d - ponteiro p do tipo int - e esse vetor recebe o endereço de memoria da variável a.
            printf("%d", d) - imprime o valor do inteiro d.
            printf("%d", &d) - imprime o endereço da variável d.
            printf("%p", p) - imprime o endereço onde o p aponta - no caso o endereço de d.
            
        3 - (LER) Acessar o conteúdo da variável ao qual o ponteiro aponta (* nome_variável) .
            printf("%p", *p) - imprime o conteudo da variavel d.

            3.1 - (ESCREVER) Também permite modificar o conteúdo da variável.
                *p = 12;

                *p = 12;
                printf("%d\n", *p);//12
                
                c++;
                printf("%d\n", *c);//16

                c = c + 15;
                printf("%d\n", *c);//76

                c = c - 2;
                printf("%d\n", *c);//68


    2) OPERAÇÕES:

        1- ATRIBUIÇÃO: 
            Um ponteiro só pode receber o endereço de memória  de uma variável do mesmo tipo do ponteiro.
                int *p / int a / float b     - p = &a OK    -   p = &b ERRADO

        2 - SOMA e SUBTRAÇÃO:
            São as únicas operações matemáticas que podemos fazer com um vetor - dependem do tipo de dado.

            INTEIRO - OCUPA 4 BYTES.

        3 - COMPARAÇÃO
            Ponteiros podem ser comparados usando:
                ==(igual) , !=(diferente)  , >(maior que)   , < (menor que) ,  >= (maior ou igual)  , <= (menor ou igual)
    
    3) PONTEIROS GENÉRICOS

        INT * -> INT (como estavamos fazendo)
        Ponteiro genérico: pode apontar para todos os tipos de dados existentes, ou que ainda serão criados.
            
            Forma geral: 

                    void *nome_ponteiro;
        
            OBS:
                Antes de acessar o conteúdo é preciso converter o ponteiro genérico para
                o tipo de ponteiro com o qual ele deseja trabalhar.

                PRECISA SER FEITO UM CAST NO PONTEIRO.
                 pp = &p2;
                //printf("Conteudo: %d \n", *pp); ERRO
                printf("Conteudo: %d \n", *(int *)pp); 

                                            ponteiro pp deve ser convertido para int * e depois poderemos acessar o conteudo dele (*).
                
                OPERAÇÕES ARITMÉTICAS
                    São sempre realizadas com base em uma unidade de memória (1 byte)
                        
                        void *p;
                        *p = 12;
                        printf("%d\n", *p);//12
                        
                        p++;
                        printf("%d\n", *c);//13

                        p = p + 15;
                        printf("%d\n", *c);//28

                        p = p - 2;
                        printf("%d\n", *c);//26


    4) PONTEIROS E ARRAYS

                         Arquivo ponteiro_array.c

        ARRAY: conjunto de dados armazenados de forma sequencial.


                O nome do array é apenas um ponteiro que aponta para o primeiro elemento do array.

                        Podemos acessar de duas maneiras

                            - p[i]           a anotação com colchetes é apenas uma simplificação da                  aritmética de ponteiros com acesso ao conteudo.

                                printf("%d\n", p[i]);

                            - *(p + i)

                                printf("%d\n", *(p+i));


                                printf("&vet[2] = &d\n", &vet[2]);//pega o endereco de vet[2]
                                
                                printf("&vet[2] = &d\n", (vet + 2));

        ARRAY já é um PONTEIRO, MAAAAS nada impede de declarar um array do tipo ponteiro.

            tipo_dado *nome_array[tamanho];     
            
                        int *vet[5];    //eu tenho um vetor com 5 posições,                                                cada uma delas é um ponteiro para inteiro


    5) PONTEIRO PARA PONTEIRO

        A linguagem C permite criar ponteiros com diferentes níveis de apontamento:
                    ponteiros que apontam para outros ponteiros.

                    int **p2 - p2 é um ponteiro para ponteiro de inteiros.

                          p2 ->       p            ->            x           =       10 
                                endereco de p(p2)     endereco de x (*p2)       conteudo de x (**p2)

                    printf("p2: %d\n", p2);//endereco em p - &p
                    printf("*p2: %d\n", *p2);//conteudo do endereco - &x
                    printf("**p2: %d\n", **p2);//conteudo do endereco do endereco - x  conteudo do                                  ultimo endereco
     
        É a quantidade de asteriscos (*) na declaração que indica o número de níveis do ponteiro

                    variavel int
                        int x;
                    ponteiro para int (1 nível)
                        int *p1;
                    ponteiro para ponteiro de int (2 níveis)
                        int **p2;
                    ponteiro para ponteiro para ponteiro de int (3 níveis)
                        int ***p3;
                
                #quantos níveis quiser;