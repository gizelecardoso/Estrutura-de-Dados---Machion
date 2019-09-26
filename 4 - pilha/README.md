PILHAS

    Uma estrutura do tipo PILHA:
        é uma sequência de elementos do mesmo tipo, como as LISTAS e FILAS.
        Seus elementos possuem uma estrutura interna abstraída, ou seja
        sua complexidade é arbitrária e não afeta o seu funcionamento.

    Uma PILHA é um tipo especial de lista:
        - inserções e exclusões de elementos ocorrem apenas no início da lista (topo);
    
    Aplicações:
        - análise de uma expressão matemática;
        - avaliação de expressão pós-fixa;
        - converter uma expressão in-fixa para pós-fixa;
        - converter um número decimal para binário;
        - etc.

    Operações básicas:
        - criação da pilha;
        - inserção de um elemento no "início" (topo);
        - exclusão de um elemento do "início" (topo);
        - acesso a um elemento do "início" (topo);
        - destruição da pilha;

    Essas operações dependem do tipo de alocação de memória usada:
        - estática:
            -> Espaço de memória é alocada no momento da compilação;
            -> Exige a definição do número máximo de elementos da PILHA;
            -> Acesso sequencial: elementos consecutivos na memória; 

        - dinâmica:
            -> O espaço de memória é alocado em tempo de execução;
            -> A PILHA cresce á medida que novos elementos são armazenados,
                        diminuiu á medida que elementos são removidos;
            -> Acesso encadeado:
                cada elemento pode estar em uma área distinta da memória.
                Para acessar um elemento, é preciso percorrer todos os seus antecessores na PILHA.
        
    PILHA ESTÁTICA

        Tipo de PILHA onde o sucessor de um elemento ocupa a posição física seguinte do mesmo (uso de ARRAY)

        Implementando uma PILHA ESTÁTICA:
            "PilhaSequencial.h": definir
                - os protótipos das funções;
                - o tipo de dados armazenado na pilha;
                - o ponteiro "pilha";
                - tamanho do vetor usado na pilha;
            
            "PilhaSequencial.c": definir
                - o tipo de dados "pilhas";
                - implementar as suas funções;
            

        Em uma pilha a inserção, remoção e consulta é sempre no seu início (topo)
        Também existe o caso onde a inserção é feita em uma pilha vazia
        Cuidado: por ser uma pilha estática, não se pode inserir em pilha cheia.

        Cuidado: por ser uma pilha estática, não se pode remover em pilha vazia.

    
    
