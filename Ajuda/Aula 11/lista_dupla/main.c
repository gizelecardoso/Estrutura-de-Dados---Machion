#include <time.h>
#include "lista_dupla.h"

/*int main(int argc, char *argv[]) {
	struct lista_dupla *l = cria_lista_dupla();
	int n;
	mostra_lista_dupla ("Lista depois da Criacao", l);
	insere_inicio_dupla (2,l);
	insere_inicio_dupla (4,l);
	insere_inicio_dupla (6,l);
	mostra_lista_dupla ("Lista Depois das Insercoes de Inicio", l);
	insere_fim_dupla (1,l);
	insere_fim_dupla (3,l);
	insere_fim_dupla (5,l);
	mostra_lista_dupla ("Lista Depois das Insercoes de Fim", l);
	if (remove_inicio_dupla(&n, l)) {
		printf("\n%d saiu do inicio", n);
		mostra_lista_dupla ("Lista Depois da Remocao de Inicio", l);
	}
	else {
		printf ("\nFalha na remocao de inicio");
	}
	if (remove_fim_dupla(&n, l)) {
		printf("\n%d saiu do fim", n);
		mostra_lista_dupla ("Lista Depois da Remocao de Fim", l);
	}
	else {
		printf ("\nFalha na remocao de Fim");
	}
	if (remove_por_endereco(l->prim->prox->prox, &n, l)) {
		printf ("\n%d Saiu da Terceira Posicao", n);
		mostra_lista_dupla ("Lista Depois da Remocao por Endereco", l);
	}
	else {
		printf ("\nFalha na Remocao por Endereco");
	}
	
	return 0;
}
*/

/*int main () {
	int i, j, k;
	struct lista_dupla *l = cria_lista_dupla();
	struct no_duplo * aux, * batedor;
	srand(time(0));
	
	for (i=1; i<=12; i++) {
		insere_fim_dupla (i,l);
	}
	
	k = rand () % 21;
	printf ("\nk = %d", k);
	aux = l->prim; 
	
	while (l->prim != l->prim->prox) {
		for (j=1; j<=k; aux = aux->prox, j++);
		batedor = aux->prox;
		remove_por_endereco (aux, &i,l); 
		printf ("\n%d Dancou", i);
		mostra_lista_dupla ("",l);
		aux = batedor;
	}	
	mostra_lista_dupla ("Vencedor", l);
	return 0;
	
}*/


int main(int argc, char *argv[]) {
	struct lista_dupla *l = cria_lista_dupla();

	insere_inicio_dupla (5,l);
	mostra_lista_dupla ("", l);
	insere_fim_dupla (3,l);
	mostra_lista_dupla ("", l);
	insere_fim_dupla (2,l);
	insere_fim_dupla (2,l);
	insere_fim_dupla (2,l);
	insere_fim_dupla (5,l);
	insere_fim_dupla (2,l);
	
	insere_posicao_lista_dupla (9,12,l);
	
	mostra_lista_dupla ("", l);
	remove_ocorrencia_lista_dupla(5,l);
	mostra_lista_dupla ("", l);
	remove_ocorrencia_lista_dupla(3,l);
	mostra_lista_dupla ("", l);
	remove_ocorrencia_lista_dupla(2,l);
	mostra_lista_dupla ("", l);
	int a = remove_ocorrencia_lista_dupla(9,l);
	printf ("hhh  %d", a);
	mostra_lista_dupla ("", l);
	
	
	insere_inicio_dupla (3,l);
	insere_fim_dupla (4,l);
	insere_fim_dupla (5,l);
	mostra_lista_dupla ("", l);

	remove_posicao_lista_dupla (8,l);
	mostra_lista_dupla ("", l);
	
	int b = tamanho_lista_dupla (l);
	printf ("tamanho %d", b);
	
	insere_posicao_lista_dupla (7,0,l);
	remove_posicao_lista_dupla (0,l);
	remove_posicao_lista_dupla (0,l);
	mostra_lista_dupla ("", l);
	
	
	
	
	insere_ordem_lista_dupla (10,l);
	mostra_lista_dupla ("", l);
	
	//insere_fim_dupla (11,l);
	//mostra_lista_dupla ("", l);
	
	insere_ordem_lista_dupla (12,l);
	mostra_lista_dupla ("", l);
	
	
	/*remove_posicao_lista_dupla (2,l);
	mostra_lista_dupla ("", l);
	
	remove_posicao_lista_dupla (1,l);
	mostra_lista_dupla ("", l);
	*/
	
	/*int a = remove_ocorrencia_lista_dupla (5,l);
	printf ("Remocoes: %d", a);
	mostra_lista_dupla ("", l);
	
	/*remove_elemento_lista_dupla (3,l);
	mostra_lista_dupla ("", l);
	
	remove_elemento_lista_dupla (5,l);
	mostra_lista_dupla ("", l);
	
	remove_elemento_lista_dupla (2,l);
	mostra_lista_dupla ("", l);
	
	remove_elemento_lista_dupla (4,l);
	mostra_lista_dupla ("", l);
	
	//remove_elemento_lista_dupla (5,l);
	//mostra_lista_dupla ("", l);
	
	int a = remove_final_dupla (l);
	printf("%d",a);
	mostra_lista_dupla (l);
	int b = remove_final_dupla (l);
	mostra_lista_dupla (l);
	int c = remove_final_dupla (l);
	mostra_lista_dupla (l);
	int d = remove_final_dupla (l);

	mostra_lista_dupla (l);
	
	int e = remove_final_dupla (l);
	printf ("%d\n", e);
	
	insere_inicio_dupla (5,l);
	mostra_lista_dupla (l);
	
	insere_inicio_dupla (8, l);
	
	
	insere_posicao_lista_dupla (9,0,l);
	
	mostra_lista_dupla (l);
	
	remove_final_dupla (l);
	remove_final_dupla (l);
	remove_final_dupla (l);	
	remove_final_dupla (l);
	remove_final_dupla (l);
	
	
	insere_final_dupla (50,l);
	insere_final_dupla (51,l);
	
	mostra_lista_dupla (l);*/
	
	
	
	return 0;
}

//Divertimento para o feriado:
//Criar uma funcao:
//a) Para inserir no final
//b) Para remover do final
//c) Mostrar a lista

//Atencao: Lista circular!!

//Uma funcao que remove um elemento de um determinado endereco.
