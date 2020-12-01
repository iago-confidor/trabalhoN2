#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

typedef struct node {
    int valor;
    struct node *esq;
    struct node *dir;
} Node;

Node* criar(int valor);

Node* inserir(Node* raiz, int valor);

void preOrder(Node* raiz);

void inOrder(Node* raiz);

void postOrder(Node* raiz);

void removerMaior(Node* raiz);

void removerMenor(Node* raiz);

#endif // NODE_H_INCLUDED