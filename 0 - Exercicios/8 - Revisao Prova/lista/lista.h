#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct dado {
    int numero;
};

typedef struct listaEstatica ListaE;
typedef struct listaElementoD* ListaD;
typedef struct listaElementoDu* ListaDu;

ListaE * cria_listaE();
void libera_lista(ListaE *li);
int tamanho_lista(ListaE *li);
int lista_cheia (ListaE *li);
int lista_vazia (ListaE *li);
int insere_lista_final(ListaE *li, struct dado d);
int insere_lista_inicio(ListaE *li, struct dado d);
int insere_lista_ordenanda(ListaE *li, struct dado d);
int remove_lista_final(ListaE *li);
int remove_lista_inicio(ListaE *li);
int remove_lista_ordenanda(ListaE *li);
int consulta_lista_pos(ListaE *li,int pos, struct dado d);
int consulta_lista_mat(ListaE *li,int mat, struct dado d);

ListaD * cria_listaD();
void libera_lista(ListaD *li);
int tamanho_lista(ListaD *li);
int lista_vazia (ListaD *li);
int insere_lista_final(ListaD *li, struct dado d);
int insere_lista_inicio(ListaD *li, struct dado d);
int insere_lista_ordenanda(ListaD *li, struct dado d);
int remove_lista_final(ListaD *li);
int remove_lista_inicio(ListaD *li);
int remove_lista_ordenada(ListaD *li);
int consulta_lista_pos(ListaD *li,int pos, struct dado d);
int consulta_lista_mat(ListaD *li,int mat, struct dado d);

ListaDu * cria_listaDu();
void libera_lista(ListaDu *li);
int tamanho_lista(ListaDu *li);
int lista_vazia (ListaDu *li);
int insere_lista_final(ListaDu *li, struct dado d);
int insere_lista_inicio(ListaDu *li, struct dado d);
int insere_lista_ordenanda(ListaDu *li, struct dado d);
int remove_lista_final(ListaDu *li);
int remove_lista_inicio(ListaDu *li);
int remove_lista_ordenanda(ListaDu *li);
int consulta_lista_pos(ListaDu *li,int pos, struct dado d);
int consulta_lista_mat(ListaDu *li,int mat, struct dado d);

