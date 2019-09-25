ALOCAÇÃO DE MEMÓRIA

    A linguagem C permite alocar (reservar) dinamicamente (em tempo de execução)
        blocos de memória utilizando ponteiros.

        pegar um PONTEIRO e trasnformar ele em um array.
    
    A linguagem C ANSI usa apenas 4 funções para alocação dinâmica,
            disponíveis na biblioteca stdlib.h

            1) malloc
            2) calloc
            3) realloc
            4) free

            operador   -     sizeof

        
        0) OPERADOR SIZEOF

            Alocar memória do tipo int é diferente de alocar memória do tipo char:
                tipos diferentes podem ter tamanhos diferentes.

                - char:     1 byte;
                - int:      4 bytes;
                - float:    4 bytes;
                - double:   8 bytes;

            Como faço para saber qual operador preciso:
                
                SIZEOF

            O operador sizeof() retorna o número de bytes necessários para alocar um único elemento de um determinado tipo de dado.

                Forma geral:

                    sizeof(nome_do_tipo);

        1) Função malloc;

            Serve para alocar memória durante a execução do programa.
            Ela faz o pedido de memória ao computador e retorna
                um ponteiro com o endereço do início do espaço da memória alocado.

            
            Protótipo
                void* malloc(unsigned int num); //ponteiro genérico - retorna um inteiro positivo.
        
            A função malloc() recebe por parâmetro:
                - a quantidade de bytes a ser alocada;
            e retorna:
                - NULL: no caso de erro;
                - ponteiro para a primeira posição do array; 

                Exemplo
                    Criar um array de 50 inteiros (200 bytes)
                        int *v = malloc(200);

                    Criar um array de 200 char (200 bytes) 
                        int *c = malloc(200);

                    Usando sizeof
                        int *v = (int*) malloc(50 * sizeof(int));
                        int *c = (char*) malloc(200 * sizeof(char));
                    
            
        2) Funçao free - libera a memória alocada.
                    free(var_mem_alocada);

        
        3) Função calloc;

            igual malloc.

            Protótipo
                
                void* calloc(unsigned int num, unsigned int size);


                int *v = (int*) calloc(50, 4);
                char *c = (char*) calloc(50, 1);

                int *v = (int*) calloc(50, sizeof(int));
                int *c = (char*) calloc(50, sizeof(char));


                malloc x calloc

                    ambas servem para alocar memória, mas calloc() inicializa todos os BITS do espaço alocado com 0

                    malloc faz apenas alocação de memoria.

        4) Função realloc;
            Serve para alocar e realocar memória dentro da execução do programa.
            Ele faz um pedido de memória ao computador e vai retornar um ponteiro com o endereço da primeira posição.

            Podemos ter um vetor que foi alocado dinamicamente, e queremos mudar seu tamanho
             então realocamos ele.


            Funcionamento:
                REALOCANDO A MEMÓRIA

                    void* realloc(void* ptr, unsigned int num);

                        recebe dois parâmetros:
                            1) ponteiro do tipo void*
                                ponteiro para um bloco de memória já alocado.
                            
                            2) tamanho em bytes
                                da nova quantidade de memória. 

                        e retorna:
                            - NULL: no caso de erro;
                            - ponteiro para a primeira posição do array;

                            v = (int* ) ralloc(100 * sizeof(int));      
                
                ALOCANDO A MEMÓRIA

                    Se o ponteiro para o bloco de memória previamente alocado for NULL
                    realloc() irá alocar a memória da mesma forma como malloc()

                        int p*;

                        p = (int* ) realloc(NULL, 50 * sizeof(int));

                LIBERANDO MEMÓRIA

                    Se o tamanho de memória solicitado for igual a zero, realloc irá liberar a memória da mesma forma como a funçao free

                        p = (int *) realloc (p,0); = free(p);


                SE NÃO HOUVER MEMÓRIA SUFICIENTE PARA ALOCAR A MEMÓRIA REQUISITADA, A FUNÇÃO RALLOC RETORNA NULL.

                    int *p = (int* ) malloc (5 * sizeof(int));
                    int *p1 = (int* ) realloc( p, 15 * sizeof(int));

                    if(p1 != NULL){
                        p = p1;
                    }

                    criou outro ponteiro para colocar o realloc, porque se caso der erro
                    não perde o ponteiro p, o que aconteceria, se fizesse o ralloc no ponteiro p.

        5) ALOCAÇÃO MATRIZES

            Para alocação de matrizes usamos o conceito de "ponteiro para ponteiro"

            - Ponteiro (1 nível) : cria um VETOR:
                int *p = (int *) malloc (5 * sizeof(int));

            - Ponteiro para ponteiro (2 níveis) : cria uma MATRIZ
                int **m;

            - Ponteiro para ponteiro para ponteiro : cria um array de 3 DIMENSÕES
                int ***d;

         ***d                ->                  **m            ->              *p
(int *)malloc(n*sizeof(int)) -> (int **) malloc(n*sizeof(int*)) -> (int ***)malloc(n*sizeof(int))
        
                
                
