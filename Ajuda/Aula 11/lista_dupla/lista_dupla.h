#include "no_duplo.h"

struct lista_dupla {
	struct no_duplo * prim;
};

struct lista_dupla * cria_lista_dupla();

int lista_dupla_vazia (struct lista_dupla *);

int insere_inicio_dupla (int, struct lista_dupla *);
int remove_inicio_dupla (int *, struct lista_dupla *);

void mostra_lista_dupla (const char *, struct lista_dupla *);    //const - a veriavel e passada por referencia, mas nao pode ser modificada

int insere_fim_dupla (int, struct lista_dupla *);
int remove_fim_dupla (int *, struct lista_dupla *);

int remove_por_endereco (struct no_duplo *, int *, struct lista_dupla *);

/*int insere_final_dupla (int, struct lista_dupla *);

int remove_final_dupla (struct lista_dupla *);**/

int tamanho_lista_dupla (struct lista_dupla *);

int remove_elemento_lista_dupla (int, struct lista_dupla *);

int remove_ocorrencia_lista_dupla (int, struct lista_dupla *);

int remove_posicao_lista_dupla (int, struct lista_dupla *);

int insere_posicao_lista_dupla (int, int, struct lista_dupla *);

int insere_ordem_lista_dupla (int, struct lista_dupla *);


