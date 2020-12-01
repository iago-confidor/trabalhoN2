#include <stdio.h>
#include<stdlib.h>


#include "pilha.h"

int menu(){	
	int opcao;
	printf("\n0 - Sair");
	printf("\n1 - Cadastrar tarefa");
	printf("\n2 - Remover tarefa");
	printf("\n3 - Exibir tarefas");
	printf("\n4 - Eliminar todas as tarefas");

	printf("\n\nEscolha a opcao: ");
    scanf ("%d", &opcao);   
    printf("\n ");
	return opcao;
}

int main()
{
	
	Pilha* p = criar();
	char tarefa[50];
	int opcao = -1;

	while(opcao != 0){
		 
		 opcao = menu();
		 
		
		switch (opcao) {
			
			case 0:
				exit(0);
 			break;
            
            case 1:

                printf("Digite o nome da tarefa: ");
                scanf("%s", tarefa); 
                push(p, tarefa);                
                
            break;
            
            case 2:
                pop(p);
            //
			    imprimir(p);
                
            break;
            
			case 3:
                imprimir(p);
            break;

			case 4:
                liberar(p);
            break;
			            
            default:
            	printf("\n Opcao invalida...\n");
            	break;
        }
		

		

	}
		return 0;
}
	
	
	


