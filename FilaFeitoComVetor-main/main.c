#include <stdio.h>
#include <stdlib.h>

int adicionaAtividade(int inicioFila, int finalFila, int atividades[]);
void percorreFila(int inicioFila, int finalFila, int atividades[]);
int andaFila(int inicioFila, int finalFila, int atividades[]);

int main()
{

    int atividadePersonagem[5] = {0,0,0,0,0};

    int inicioFila = 0;
    int finalFila = 0;

    finalFila = adicionaAtividade(inicioFila,finalFila,atividadePersonagem);
    finalFila = adicionaAtividade(inicioFila,finalFila,atividadePersonagem);
    finalFila = adicionaAtividade(inicioFila,finalFila,atividadePersonagem);


    percorreFila(inicioFila,finalFila, atividadePersonagem);

    printf("\n");

    inicioFila = andaFila(inicioFila,finalFila,atividadePersonagem);
    inicioFila = andaFila(inicioFila,finalFila,atividadePersonagem);
    inicioFila = andaFila(inicioFila,finalFila,atividadePersonagem);

    percorreFila(inicioFila,finalFila, atividadePersonagem);

    inicioFila = andaFila(inicioFila,finalFila,atividadePersonagem);


    return 0;
}

int adicionaAtividade(int inicioFila, int finalFila, int atividades[]){
    if(inicioFila == 0 && finalFila == 4+1){
        printf("fila cheia\n");
        return finalFila;
    } else if(inicioFila == finalFila && inicioFila != 0 && finalFila != 0) {
        printf("fila cheia\n");
        return finalFila;
    }

    if(inicioFila == 0 && finalFila == 0){
        if(atividades[inicioFila] != 0 && atividades[finalFila] != 0){
            printf("fila cheia\n");
            return finalFila;
        } else {
            finalFila++;
            atividades[inicioFila] = 1;
            printf("atividade adicionada e iniciano fila\n");
            return finalFila;
        }
    } else {
        if(finalFila == 4){
            atividades[finalFila] = 1;
            printf("atividade adicionada na posicao %d\n", finalFila);
            finalFila = 0;
            return finalFila;
        } else {
            atividades[finalFila] = 1;
            printf("atividade adicionada na posicao %d\n", finalFila);
            finalFila++;
            return finalFila;
        }
    }
}

void percorreFila(int inicioFila, int finalFila, int atividades[]){

    for(int i = 0; i < 5; i++){
        printf("%d - ", atividades[i]);
    }

    printf("\nposicao inicial: %d\n", inicioFila);
    printf("final da fila: %d\n", finalFila);
}

int andaFila(int inicioFila, int finalFila, int atividades[]){
    if(inicioFila == 0 && finalFila == 0){
        if(atividades[inicioFila] == 0 && atividades[finalFila] == 0){
            printf("a fila esta vazia!\n");
            return 0;
        } else {
            printf("A fila andou!\n");
            atividades[inicioFila] = 0;
            inicioFila++;
            return inicioFila;
        }
    } else {
        if(atividades[inicioFila] == 0 && atividades[finalFila] == 0){
            printf("a fila esta vazia!\n");
            return 0;
        }else if(inicioFila == 4){
            printf("A fila andou!\n");
            atividades[inicioFila] = 0;
            inicioFila = 0;
            return inicioFila;
        } else {
            printf("A fila andou!\n");
            atividades[inicioFila] = 0;
            inicioFila++;
            return inicioFila;
        }
    }
}




