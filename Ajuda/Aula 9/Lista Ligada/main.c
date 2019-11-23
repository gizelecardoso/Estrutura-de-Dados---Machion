#include "lista.h"

void teste_no() {
	struct no * no1;
	struct no * no2;
	no1 = constroi_no(5);
	if (no1) {
		printf("\nNo1 alocado com sucesso\n");
	}
	else {
		printf("\nFalha na alocacao\n");
	}
	/*while (1) { FAÇA ISSO EM CASA (a gi, vocês não)
		no1 = constroi_no(5)
	}
	*/
	no2 = constroi_no(7);
	if (no2) {
		printf("\nNo1 alocado com sucesso\n");
	}
	else {
		printf("\nFalha na alocacao\n");
	}
	no1->prox = no2;
	no1->prox->info = 13;
	printf("\nCampo info de no2 = %d", no2->info);
}
void teste_lista () {
	struct lista * l = constroi_lista();
	int n;
	if (l) {
		insere_inicio(3, l);
		insere_inicio(5, l);
		insere_inicio(5, l);
		insere_inicio(7, l);
		mostra_lista("Lista depois das insercoes de inicio", l);
		insere_fim(2, l);
		insere_fim(4, l);
		insere_fim(5, l);
		mostra_lista("Lista depois das insercoes de fim", l);
		/*if (remove_inicio (&n, l)) {
			printf ("\n%d foi removido do inicio\n", n);
			mostra_lista("lista depois da remocao de inicio", l);
		}
		if (remove_fim (&n, l)) {
			printf ("\n%d foi removido do fim\n", n);
			mostra_lista("lista depois da remocao de fim", l);
		}*/
	}
	else {
		printf("\nFalha na criacao da lista\n");
	}
	
	mostra_lista("lista agora", l);
	
	/*int a;
	a = elementos_media(l);
	printf ("\n%d", a);
	
	int b;
	b = insere_posicao(10,4,l);
	mostra_lista("Lista depois da insercao de 10 na pos 4", l);
	
	int c;
	c = remove_posicao(7,l);
	mostra_lista("Lista depois da remocao de 6 na pos 7", l);
	
	
	int d;
	d = remove_elemento(4,l);
	mostra_lista("Lista depois de remover o elemento 4", l);
	
	int z;
	z = remove_elemento(10,l);
	mostra_lista("Lista depois de remover o elemento 10", l);
	
	int y;
	y = remove_elemento(3,l);
	mostra_lista("Lista depois de remover o elemento 3", l);
	
	int e;
	e = verifica_elemento(2,l);
	printf ("\n%d\n", e);*/
	
	int f;
	f = remove_ocorrencia(5,l);
	mostra_lista("Lista depois de remover todos os elementos com valor 5", l);
	
}

int main(int argc, char *argv[]) {
	//teste_no();
	teste_lista();
	return 0;
}


