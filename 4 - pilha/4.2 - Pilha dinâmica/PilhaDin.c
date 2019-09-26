

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        *pi = NULL;
    }
    return pi;
}

void libera_Pilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;

        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi) -> prox;
            free(no);
        }

        free(pi);
    }
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL){
        return 0;
    }

    int cont = 0;
    Elem* no = *pi;

    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int Pilha_cheia(Pilha* pi){
    return 0;
    //pilha dinamica nunca estará cheia, a não ser que acabe a memória.
}

int Pilha_vazia(Pilha* pi){
    if(pi == NULL){ //pi é a representação da pilha
        return 1;
    }

    if(*pi == NULL){ //*pi representação do primeiro elemento da pilha (topo)
        return 1;
    }

    return 0;
}


int insere_Pilha(Pilha* pi, struct aluno al){
    if(pi == NULL){//verifica se a pilha é igual a nulo, não tem pilha para inserir elemento
        return 0;
    }

    Elem* no = (Elem*) malloc(sizeof(Elem)); //criando um novo elemento e aloco memória para ele

    if(no == NULL){ //verifico se deu certo a alocação - se não for igual a nulo, continuo
        return 0;
    }

    no->dados = al; //copio os dados do aluno para o campo de dados desse novo elemento;
    no->prox = (*pi); // esse novo nó vai apontar para o topo da pilha
    *pi = no; //topo da pilha vai se tornar esse novo elemento
    return 1; //deu certo a operação de inserção.
}

int remove_Pilha(Pilha* pi){
    if(pi == NULL){//verifica se pilha é igual a nulo, não existe pilha
        return 0;
    }

    if((*pi) == NULL){ //topo da pilha é igual a nulo - pilha vazia
        return 0;
    }

    Elem *no = *pi; //cria nó auxiliar que recebe o topo da pilha
    *pi = no->prox; //topo da pilha é o próximo elemento seguinte ao nó
    free(no);//libero o elemento nó
    return 1;
}

int consulta_topo_Pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL){//verifico se a pilha existe
        return 0;
    }

    if((*pi) == NULL){//verifico se o topo é vazio
        return 0;
    }

    *al = (*pi) -> dados; //referencia recebe o topo com os dados
    return 1;
}