#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main() {
  Node * raiz = NULL;
  raiz = inserir(raiz, 25);
  inserir(raiz, 22);
  inserir(raiz, 40);
  inserir(raiz, 30);
  inserir(raiz, 45);
  inserir(raiz, 27);
  inserir(raiz, 20);

  printf("\nPre Order:\n");
  preOrder(raiz);
  printf("\nIn Order:\n");
  inOrder(raiz);
  printf("\nPost Order:\n");
  postOrder(raiz);

  removerMaior(raiz);
  removerMenor(raiz);
  
  printf("\n\nMaior e menor valor removidos.\n");
  
  printf("\nIn Order:\n");
  inOrder(raiz);

  return 0;
}