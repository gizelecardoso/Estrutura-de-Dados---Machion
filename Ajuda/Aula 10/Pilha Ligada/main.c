#include <time.h>
#include "pilha.h"

int main(int argc, char *argv[]) {
	Pilha *p = cria_pilha();
	int i;
	srand(time(0));
	do {
		if (rand()%2) {
			if (push(rand()%10, p)) {
				printf("Inseriu: ");
				mostra_pilha(p);
			}
			else {
				printf("tooiinn (encheu a pilha, carai)");
			}
		}
		else {
			if (pop(&i, p)) {
				printf("%d saiu: ", i);
				mostra_pilha(p);
			}
			else {
				printf("oh oh (pilha vazia, otario)");
			}
		}
	} while (!pilha_vazia(p));
	return 0;
}

