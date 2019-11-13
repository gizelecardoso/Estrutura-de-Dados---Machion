#include<time.h>
#include "pilha.h"

int main(){
	
	printf("ola ");
	Pilha *p = cria_pilha();
	int i;
	
	srand(time(0));//gerador rand�mico - ou � NULL ou � 0
	
	do{
		
		if(rand()%2){
			if(push(rand()%10, p)){

				printf("inseriu: ");
				mostra_pilha(p);
			}else{
				printf("\ntoooinn\n");//bateu no topo, pilha esta cheia
			}
			
		}else{
			if(pop(&i, p)){
				printf("%d saiu: ", i);
				mostra_pilha(p);
			}else{
				printf("oh oh");
			}
			
		}
		
	}while(!pilha_vazia(p));
	
	
	return 0;
}
