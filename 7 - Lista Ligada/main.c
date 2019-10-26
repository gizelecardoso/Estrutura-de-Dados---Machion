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
	/*while (1) { FA�A ISSO EM CASA (a gi, voc�s n�o)
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
		insere_inicio(7, l);
		mostra_lista("Lista depois das insercoes de inicio ", l);
		insere_fim(2, l);
		insere_fim(4, l);
		insere_fim(6, l);
		mostra_lista("Lista depois das insercoes de fim ", l);
		if(remove_inicio(&n, l)){
			printf("\n%d foi removido do inicio\n", n);
			mostra_lista("Lista depois da remocao de inicio", l);
		}
		if(remove_fim(&n, l)){
			printf("\n%d foi removido do fim\n", n);
			mostra_lista("Lista depois da remocao de fim", l);
		}
	}
	else {
		printf("\nFalha na criacao da lista\n");
	}
}
int main(int argc, char *argv[]) {
	//teste_no();
	teste_lista();
	return 0;
}
