#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node* criar(int valor) {
  Node* temp = (Node* ) malloc(sizeof(Node));
  temp -> valor = valor;
  temp -> esq = temp -> dir = NULL;
  return temp;
}

Node* inserir(Node* raiz, int valor) {
  if (raiz == NULL) {
    return criar(valor);
  }
  if (valor < raiz -> valor) {
    raiz -> esq = inserir(raiz -> esq, valor);
  }
  if (valor > raiz -> valor) {
    raiz -> dir = inserir(raiz -> dir, valor);
  }
  return raiz;
}

void preOrder(Node* raiz) {
  if (raiz != NULL) {
    printf("%d\t", raiz -> valor);
    preOrder(raiz -> esq);
    preOrder(raiz -> dir);
  }
}

void inOrder(Node* raiz) {
  if (raiz != NULL) {
    inOrder(raiz -> esq);
    printf("%d\t", raiz -> valor);
    inOrder(raiz -> dir);
  }
}

void postOrder(Node* raiz) {
  if (raiz != NULL) {
    postOrder(raiz -> esq);
    postOrder(raiz -> dir);
    printf("%d\t", raiz -> valor);
  }
}

void removerMaior(Node* raiz) {
  // Se raiz for null, não fazer nada.
  if (raiz == NULL) {
    return;
  }
  // Iterar até o maior node e reservar o pai.
  Node* maiorPai = NULL;
  Node* maior = raiz;
  while (maior->dir != NULL) {
    maiorPai = maior;
    maior = maior->dir;
  }
  // Se não tem filho à esquerda, apenas o deleta e atualiza o pai.
  if (maior->esq == NULL) {
    free(maior);
    maior = NULL;
    if (maiorPai != NULL) {
      maiorPai->dir = NULL;
    }
  }
  // Senão, copia os atributos do filho e o deleta.
  else {
    Node* filho = maior->esq;
    maior->valor = filho->valor;
    maior->esq = filho->esq;
    maior->dir = filho->dir;
    free(filho);
    filho = NULL;
  }
}

void removerMenor(Node* raiz) {
  // Se raiz for null, não fazer nada.
  if (raiz == NULL) {
    return;
  }
  // Iterar até o menor node e reservar o pai.
  Node* menorPai = NULL;
  Node* menor = raiz;
  while (menor->esq != NULL) {
    menorPai = menor;
    menor = menor->esq;
  }
  // Se não tem filho à direita, apenas o deleta e atualiza o pai.
  if (menor->dir == NULL) {
    free(menor);
    menor = NULL;
    if (menorPai != NULL) {
      menorPai->esq = NULL;
    }
  }
  // Senão, copia os atributos do filho e o deleta.
  else {
    Node* filho = menor->dir;
    menor->valor = filho->valor;
    menor->esq = filho->esq;
    menor->dir = filho->dir;
    free(filho);
    filho = NULL;
  }
}