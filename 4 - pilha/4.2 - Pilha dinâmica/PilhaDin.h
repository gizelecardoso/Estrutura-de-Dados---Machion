
struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct elemento* Pilha; //pilha é um ponteiro para struct elemento.//ponteiro para ponteiro pois no programa principal definimos Pilha *pi;

Pilha* cria_Pilha();

void libera_Pilha(Pilha* pi);

int tamanh_Pilha(Pilha* pi);

int Pilha_Cheia(Pilha *pi);

int Pilha_vazia(Pilha *pi);

int insere_Pilha(Pilha* pi, struct aluno al);

int remove_Pilha(Pilha* pi);

int consulta_topo_Pilha(Pilha* pi, struct aluno *al);