
int main(){

    Pilha *pi;

    pi = cria_Pilha();

    libera_Pilha(pi);

    int x = tamanho_Pilha(pi);

    int x = Pilha_cheia(pi);
    if(Pilha_cheia(pi)){}

    int x = Pilha_vazia(pi);
    if(Pilha_vazia(pi)){}

    int x = insere_Pilha(pi, dados_aluno);

    int x = remove_Pilha(pi);

    int x = consulta_topo_Pilha(pi, &dados_aluno);//endereco da estrutra dados que vai receber os dados do aluno que estou consultando

    return 0;
}