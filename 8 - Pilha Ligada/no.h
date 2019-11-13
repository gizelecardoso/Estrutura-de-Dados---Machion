#include <stdio.h>
#include <stdlib.h>

struct no {
	int info;
	struct no * prox;
};

struct no * constroi_no (int);

