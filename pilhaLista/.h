typedef struct pilha Pilha;

Pilha* criar();
void push(Pilha* p, char* tarefa);
int pop(Pilha* p);
int vazia(Pilha* p);
char* topo(Pilha* p);
void liberar(Pilha* p);
void imprimir(Pilha* p);