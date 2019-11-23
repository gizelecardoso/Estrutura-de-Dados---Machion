#include<stdio.h>
#include<stdlib.h>

struct dado {
    int numero;
};

typedef struct componente* Lista;

Lista * cria_lista();

void libera_lista(Lista * li);

int tamanho_lista(Lista * li);

int lista_vazia(Lista * li);

int insere_lista_inicio(Lista * li, struct dado d);

int insere_lista_final(Lista * li, struct dado d);

int remove_lista_inicio (Lista *li);

int remove_lista_final (Lista *li);

//1 - Remover um elemento da lista (Ex.: Elemento 7). 
//Caso o elemento não esteja na lista devolver fracasso.

int remove_elemento_lista(Lista * li, int elemento);

//2 - Remover todas as ocorrências de um elemento da lista. 
//A função devolve quantos elementos foram removidos. (Dica: Fazer função de busca).

int remove_todosElemento_lista(Lista * li, int elemento);
//3 - Remover um elemento de uma determinada posição. 
//Se a posição for maior que o tamanho da lista, devolver fracasso.

int remove_elementoPosicao_lista(Lista * li, int posicao);
//4 - Inserir um elemento em uma determinada posição. 
//Se a posição for maior que o tamanho da lista, continue contando.

int insere_elementoPosicao_lista(Lista * li, int posicao, struct dado d);
//5 - Inserir elementos na ordem topológica (Ex.: 1, 2, 3). 
//Observação: Essa função só funciona quando os elementos estão na ordem.

int insere_lista_ordenada (Lista * li, struct dado d);
