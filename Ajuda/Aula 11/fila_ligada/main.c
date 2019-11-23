#include <time.h>
#include "fila.h"

int main(int argc, char *argv[]) {
	Fila *f = cria_fila();
	int i;
	srand(time(0));
	if (f) {
		printf ("\nFila alocada com sucesso!\n");
		do {
			if (rand() % 2) { 
				insere_elemento (rand() % 10, f);
			}
			else {
				remove_elemento(&i, f);
			}
			mostra_fila(f);
		} while (!fila_vazia(f));
	}
	else {
		printf ("\nFalha na alocacao\n");
	}
	return 0;
}

/*int main(int argc, char *argv[]) {
	Fila *f = cria_fila(10);
	Fila *g = cria_fila(10);
	
	if (f) {
		
		insere_elemento (1,f);
		insere_elemento (3,f);
		insere_elemento (5,f);
		insere_elemento (6,f);
		insere_elemento (7,f);
		insere_elemento (9,f);
			
	}
		
	if (g) {
		
		insere_elemento (1,g);
		insere_elemento (2,g);
		insere_elemento (5,g);
		insere_elemento (8,g);
		insere_elemento (11,g);
		
	}
	
	mostra_fila(f);
	mostra_fila(g);
	
	int a;
	a = compara_fila (f,g);
	printf("%d\n", a);

	int b;
	b = unifica_fila (f,g);
	printf("%d\n", b);
	
    //inverte_fila (Fila f);

	int c;
	c = soma_impar (f);
	printf("%d\n", c);
		
	int d;
	d = intercala_fila (f,g);
	printf("%d\n", d);
	
	int e;
	e = inverte_fila (f);
	printf("%d\n", e);
	
	return 0;
}
*/

