#include "FilaEstatica.c"

//Exercicio 6 -  Desenvolva uma funcao para testar se uma fila F1 tem mais elementos do que uma fila F2. 

void maior_fila(Fila * f1, Fila * f2){

	if(tamanho_fila(f1) > tamanho_fila(f2)){
		printf("A maior lista e f1 ");
	} else{
		printf("A maior lista e f2 ");
	}
}


int  main(){
	
	Fila * f1 = cria_fila();
	Fila * f2 = cria_fila();
	
	maior_fila(f1, f2);
		
	return 0;
}
