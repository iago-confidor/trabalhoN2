#include <stdio.h>
#include <stdlib.h>
#define MALLOC(x) ((x *) malloc (sizeof(x)))

struct no{
   char tarefa[30];
   struct no *proximo;
         };

typedef struct no no_t;
no_t *novo;

no_t *cria(no_t *lista);
no_t *insini(no_t *lista);
no_t *insfim(no_t *lista);
no_t *retira(no_t *lista);
int imprime(no_t *lista);
int primeiro(no_t *lista);
no_t *libera(no_t *lista);


int main(void)
{
   int op,k,r,m;
   no_t *lista;
   for (;;)
   {
      system("clear");
      printf("\n0 - Cria uma fila de tarefas do personagem");
      printf("\n1 - Insere uma tarefa para o personagem");
      printf("\n2 - Remove tarefa do personagem");
      printf("\n3 - Imprime as tarefas na fila");
      printf("\n4 - Imprime a primeira tarefa da fila");
      printf("\n5 - Exclui a lista de tarefas do personagem");
      printf("\n6 - Sair");
      printf("\n\nOpção: \n");
      scanf("%d",&op);
      switch(op){
         case 0 : 
	    lista=cria(lista);
            break;
         case 1 : 
            getchar();
            if(lista==NULL)
               lista=insini(lista);
            else
               lista=insfim(lista);
            break; 
         case 2 : 
           lista=retira(lista);
            break;                          
         case 3 : 
            imprime(lista);
            break;
         case 4 : 
            primeiro(lista);
            break;
         case 5 :
            lista=libera(lista);
            break;
         case 6 : 
          exit(0);
                
         default: 
            system("clear");
            printf("Opção Errada");
            scanf("%d",&k);
      }
   }    
   return 0;            
}


no_t *cria(no_t *lista){
   system("clear");
   lista = MALLOC(no_t);
   lista=0;
   printf("Lista de tarefas criada com sucesso!\n");
   sleep(3);
   return lista;
};


no_t *retira(no_t *lista){
   no_t *p;
   p=lista;
   if(lista!=NULL)
   {
      lista=lista->proximo;
      free(p);
      return lista;
   }
   return NULL;
};


no_t *libera(no_t *lista){
   no_t *p;
   p=lista;
   if(lista!=NULL)
   {
      while(p!=NULL)
      {
         p=lista->proximo;
         free(lista);
         lista=p;
      }
   }
    return NULL;
};

no_t *insini(no_t *lista){
   char tf[30];

   printf("Digite o nome da atividade\n");
   gets(tf);

   novo = MALLOC(no_t);
   novo->proximo = lista; 
   sprintf(novo->tarefa,"%s",tf);
   return novo;
};

no_t *insfim(no_t *lista){
   no_t *aux;
   char tf[30];
   aux=lista;

   printf("Digite o nome da atividade\n");
   gets(tf);


   novo = MALLOC(no_t);
   while(aux->proximo!=NULL){
      aux=aux->proximo;
   }
   novo->proximo = NULL;
   sprintf(novo->tarefa,"%s",tf);
   aux->proximo=novo;
   return lista;
};

int imprime(no_t *lista){
   no_t *p;
   int k,i=0;
   system("clear");
   if (lista==NULL)
   {
      
      system("clear");
      printf("Lista Vazia\n");
      printf("0 para retornar!\n");
      scanf("%d",&k);
      
      return 0;
   }
   p = lista;
   do{
      printf("\ntarefa: %s",p->tarefa);
      printf("\n");
      p = p->proximo;
      i++;
   }while (p!=NULL);
   printf("\n\nTEM %d TAREFAS NA FILA",i);
   scanf("%d",&k);
    
   
   return 0; 
};

int primeiro(no_t *lista)
{
   no_t *p;
   int k;
   system("clear");
   if (lista==NULL)
   {
      system("clear");
      printf("Lista Vazia");
      scanf("%d",&k);
      return 0;
   }
   p = lista;
   printf("\ntarefa: %s",p->tarefa);
   printf("\n"); 
   scanf("%d",&k);
   return 0; 
};