#include <stdio.h>
#include <stdlib.h>

struct no_duplo {
	struct no_duplo * prox;
	struct no_duplo * ant;
	int info;
};

struct no_duplo * cria_no_duplo (int);

