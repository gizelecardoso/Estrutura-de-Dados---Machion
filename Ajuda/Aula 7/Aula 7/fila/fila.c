#include "fila.h"

struct fila {
	int *v;
	int prim, ult, cont, capacidade;
};

Fila * cria_fila (int n) {
	Fila * aux = (Fila *) malloc (sizeof(Fila));
	if (aux) {
		aux->v = (int *) malloc (n * sizeof(int));     //v é um campo da estrutura que aux aponta.
		if (!aux->v)
			return NULL;
		aux->cont = 0;
		aux->prim = 0;
		aux->ult = 0;
		aux->capacidade = n;
	}
	return aux;
}

int fila_vazia (Fila *f) {
	if (f->cont == 0)
		return 1;
	return 0;
}
	
int fila_cheia (Fila *f) {
	if (f->cont == f->capacidade)
		return 1;
	return 0;	
}

int proxima (int pos, Fila *f) {
	return (pos + 1) % f->capacidade;
}

int insere_elemento (int i, Fila *f) {
	if (fila_cheia(f))
		return 0;
	f->v[f->ult] = i;
	f->ult = proxima(f->ult, f);
	f->cont++;
	return 1;
}

int remove_elemento (int *i, Fila *f) {
	if (fila_vazia(f))
		return 0;
	*i = f->v[f->prim];
	f->prim = proxima(f->prim, f);
	f->cont--;
	return 1;
}

int tamanho_fila (Fila *f) {
	return f->cont;
}

void mostra_fila (Fila *f) {
	int i;
	if (fila_vazia(f)) { 
		printf ("Fila Vazia");
	}
	else {
		i=f->prim;
		do {
			printf ("%d ", f->v[i]);				
			i = proxima (i, f);
		} while (i != f->ult);
	printf ("\n");
	}
}

void mostra_vetor (Fila *f) {
	int i;
	if (f->prim < f->ult) {
		for (i=0; i<f->prim; i++)
		printf ("_ ");
		for (i=f->prim; i<f->ult; i++)
			printf("%d ", f->v[i]);
		for (i=f->ult; i<f->capacidade; i++)	
			printf ("_ ");
	}
	else {
		for (i=0; i<f->ult; i++)
			printf("%d ", f->v[i]);
		for (i=f->ult; i<f->prim; i++)
			printf ("_ ");
		for (i=f->prim; i<f->capacidade; i++)	
			printf("%d ", f->v[i]);
	}
	printf ("  |  ");
}

//Função que devolve o primeiro elemento.

int consulta_prim (Fila *f) {
	int i;
	if (fila_vazia(f)) { 
		return 0;
	}
	i=f->v[f->prim];
 	return i;
}

//Ex. 06:
//Desenvolva uma funcao para testar se uma fila F1 tem mais elementos do que uma fila F2.

int compara_fila (Fila *f1, Fila *f2) {
	if (fila_vazia(f1) && fila_vazia(f2)) {
		return -1;
	}
		
	if (fila_vazia(f1)) {
		return 0;
	}
		
	if (fila_vazia(f2)) {
		return 1;
	}
			
	if (f1->cont > f2->cont) {
		return 1;	
	}
	return 0;
}

//Ex. 08:
//Faca uma funcao que receba tres filas, duas ja preenchidas em ordem crescente e preencha a ultima com os valores das duas primeiras em ordem crescente.

int unifica_fila (Fila *f1, Fila *f2) {
	int i;
	Fila * f3 = cria_fila ((tamanho_fila(f1))+(tamanho_fila(f2)));
	
	if (fila_vazia(f1) && fila_vazia(f2)) {
		return 0;
	}
	
	while (!fila_vazia(f1) && !fila_vazia(f2)) {
		
		while (!fila_vazia(f1) && !fila_vazia(f2) && consulta_prim(f1) <= consulta_prim(f2)) {
			remove_elemento (&i, f1);
			insere_elemento (i, f3);
		}
		
		while (!fila_vazia(f1) && !fila_vazia(f2) && consulta_prim(f2) <= consulta_prim(f1)) {
			remove_elemento (&i, f2);
			insere_elemento (i, f3);
		}		
		
	}
	
	while (!fila_vazia(f1)) {
		remove_elemento (&i, f1);
		insere_elemento (i, f3);
	}
	
	while (!fila_vazia(f2)) {
		remove_elemento (&i, f2);
		insere_elemento (i, f3);
	}
	
	return 1;
	
}

//Ex. 15:
//Faca uma funcao que inverta a ordem dos elementos da fila.
//Importar a biblioteca da pilha.

int inverte_fila (Fila *f) {
	int i;
	Pilha * aux = cria_pilha (tamanho_fila(f));
	
	while (!fila_vazia(f)) {
		remove_elemento (&i, f);
		push (i, aux);
	}
	
	while (!pilha_vazia(aux)) {
		pop (&i, aux);
		insere_elemento (i, f);
	}
	
	mostra_fila(f);
	return 1;
	
}

//Ex. 16:
//Faca uma funcao para retornar o numero de elementos da fila que possuem valor impar

int soma_impar (Fila *f) {
	int soma;
	int i;
	
	if (fila_vazia(f)) {
		return 0;
	}
	
	i=f->prim;
	do {
		if (f->v[i]%2 == 1){
			soma = soma+1;
		}
		i = proxima (i, f);	
		
	} while (i != f->ult);

	return soma;
}

//Ex.18:
//Faca uma funcao para intercalar filas: a funcao recebe as duas filas e retorna a fila com os elementos das duas filas intercalados conforme a ordem
//com que elas se dispoe na fila. 

int intercala_fila (Fila *f1, Fila *f2) {
	int i;
	Fila * intercalada = cria_fila ((tamanho_fila(f1))+(tamanho_fila(f2)));
	
	if (fila_vazia(f1) && fila_vazia(f2)) {
		return 0;
	}
	
	while (!fila_vazia(f1) && !fila_vazia(f2)) {
		remove_elemento (&i, f1);
		insere_elemento (i, intercalada);
		remove_elemento (&i, f2);
		insere_elemento (i, intercalada);
	}
	
	while (!fila_vazia(f1)) {
		remove_elemento (&i, f1);
		insere_elemento (i, intercalada);	
	}
	
	while (!fila_vazia(f2)) {
		remove_elemento (&i, f2);
		insere_elemento (i, intercalada);
	}

	return 1;
	
}

/*Ex. 08: (Primeira Versao)
//Faca uma funcao que receba tres filas, duas ja preenchidas em ordem crescente e preencha a ultima com os valores das duas primeiras em ordem crescente.

int unifica_fila (Fila *f1, Fila *f2, Fila *f3) {
	int i;
	int x;
	Fila * aux = cria_fila (tamanho_fila(f3));    //cria uma fila auxiliar, do tamanho da fila f3
	
	if (fila_vazia(f1) && fila_vazia(f2)) {       //verifica se as filas f1 e f2 estão vazias
		return 0;
	}
	
	if (!fila_vazia(f3)) {                       //verifica se a fila f3 esta vazia para receber a junção das filas f1 e f2
		return 0;
	}
	
	while (!fila_vazia(f1)) {                   //move os elementos da fila f1 para a fila aux
		remove_elemento (&i, f1);
		insere_emento (i, aux);
	}
	
	while (!fila_vazia(aux)) {                 //move os elementos da fila aux para as filas f3 e f1
		remove_elemento (&i, aux);
		insere_elemento (i, f3);
		insere_elemento (i, f1);
	}
	
	while (!fila_vazia(f2) && f2->prim < f3->ult) {  //remove elementos enquanto f2 não vazia e o primeiro elemento for menor ao ultimo de f3
		remove_elemento (&i, f2);
			while (!fila_vazia(f3) && f3->ult > i) { //remove elementos enquanto f3 não vazia e o ultimo for maior do que o valor em i
				remove_elemento (&x, f3);             
				insere_elemento (x, aux);
			}
		insere_elemento (i, f3);                   //insere o elemento guardado em i na f3
		while (!fila_vazia(aux)) {                 //devolve os elementos da aux pra f3
				remove_elemento (&x, aux);
				insere_elemento (x, f3);
		}
	insere_elemento (i, f3);			           //caso o prim de f1 seja maior ou igual ao ult de f3, será apenas inserido em f3	
	}	
	return 1;	
}

*/

/*Ex. 15: (Primeira Versao)
//Faca uma funcao que inverta a ordem dos elementos da fila.

int inverte_fila (Fila *f) {
	int i;
	Fila * invertida = cria_fila (tamanho_fila(f));
	
	if (fila_vazia (f)) {
		return 0;
	}	
	
	while (!fila_vazia(f)) {
		i = f->v[f->ult];
		f->ult = f->v[f->ult-1];
		f->cont--;
		insere_elemento (i, invertida);
	}
	return 1;
}
*/

/*Ex. 16: (Versao Original)
//Faca uma funcao para retornar o numero de elementos da fila que possuem valor impar

int soma_impar (Fila *f) {
	int soma;
	
	if (fila_vazia(f)) {
		return 0;
	}
	
	for (i=0; i<f->cont; i++){
		if (v[i]%2 == 1){
			soma = soma+1;
		}
	}
	return soma;
}
*/

/*Ex.18: (Versao Original)
//Faca uma funcao para intercalar filas: a funcao recebe as duas filas e retorna a fila com os elementos das duas filas intercalados conforme a ordem
//com que elas se dispoe na fila. 

int intercala_fila (Fila *f1, Fila *f2) {
	int i;
	Fila * aux = cria_fila (tamanho_fila((f1)+(f2)));          //verificar possibilidade de somar o tamanho das filas
	Fila * intercalada = cria_fila (tamanho_fila((f1)+(f2))); //verificar possibilidade de somar o tamanho das filas
	
	if (fila_vazia(f1) && fila_vazia(f2)) {                  //verifica se as duas filas estão vazias
		return 0;
	}
	
	if (fila_vazia(f1)) {                                  //se apenas f1 estiver vazia, passa a f2 para a fila intercalada
		while (!fila_vazia(f2)) {
			remove_elemento (&i, f2);
			insere elemento (i, aux);
		}
		while (!fila_vazia(aux)) {
			remove_elemento (&i, aux);
			insere_elemento (i, intercalada);
			insere_elemento (i, f2);
		}
	}
	
	if (fila_vazia(f2)) {                                  //se apenas f2 estiver vazia, passa a f1 para a fila intercalada
		while (!fila_vazia(f1)) {
			remove_elemento (&i, f1);
			insere elemento (i, aux);
		}
		while (!fila_vazia(aux)) {
			remove_elemento (&i, aux);
			insere_elemento (i, intercalada);
			insere_elemento (i, f1);
		}
	}
	
	while ((!fila_vazia(f1)) && (fila_vazia(f2))) {        //passa os elementos de ambas as filas para a fila intercalada
		remove_elemento (&i, f1);
		insere_elemento (i, intercalada);
		remove_elemento (&i, f2);
		insere_elemento (i, intercalada);
	}
	return 1;
}
*/

