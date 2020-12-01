#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct node {
	char *tarefa;
	struct Node *proximo;
} Node;

typedef struct pilha
{
	Node *inicio;
	int tamanho;
} Pilha;

Pilha* criar()
{
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->inicio = NULL;
	p->tamanho = 0;
	return p;
}

void push(Pilha* p, char *t)
{
	Node* novo = (Node*)malloc(sizeof(Node));
	novo->tarefa = (char *)malloc(50 * sizeof(char));
	strcpy (novo->tarefa, t);
	novo->proximo = p->inicio;
	p->inicio = novo;
	p->tamanho++;

}

int pop(Pilha* p)
{
	if(p->inicio == NULL) {
		printf("\nPilha vazia\n");
		return -1;
	}
	Node* temp = p->inicio;
	printf("\nTopo removido: %s\n", p->inicio->tarefa);
    p->inicio = temp->proximo;
    free(temp);
    p->tamanho--;
    return p->tamanho;
}

char* topo(Pilha* p)
{ 
	if(p->inicio == NULL){
	//	printf("\nPilha vazia\n");
		return "";
	}
	return p->inicio->tarefa; 
}


void liberar(Pilha* p)
{
	while(p->inicio != NULL){
		pop(p);
	}
}


void imprimir(Pilha * p){
	
if(p->inicio == NULL) {
	printf("\nPilha vazia\n");
}
	
Node *atual = p->inicio;
int i;
for(i=0; i < p->tamanho; ++i){
	printf("\n%s", atual->tarefa);
	atual = atual->proximo;
}
}


