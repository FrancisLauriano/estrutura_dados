#include <stdlib.h>
#include "fila.h"

struct fila{
    int num[TAM];
    int inicio;
    int fim;
    int qtd;
};


Fila criarFila(){
    Fila f = malloc(sizeof(struct fila));

    if(f != NULL){
        f -> inicio = 0;
        f -> fim = 0;
        f -> qtd = 0;
    }

    return f;
}

int enfileirar(Fila f, int valor){
    if(f == NULL || f -> qtd == TAM){
        return 0;
    }

    f -> num[f -> fim] = valor;
    f -> fim = (f -> fim + 1) % TAM;
    f -> qtd += 1;

    return 1;
}

int desenfileirar(Fila f){
    if(f == NULL || f -> qtd == 0){
        return 0;
    }

    f -> inicio = (f -> inicio + 1) % TAM;
    f -> qtd -= 1;

    return 1;
}

int acessarInicio(Fila f){
    if(f == NULL || f -> qtd == 0){
        return 0;
    }

    return f -> num[f -> inicio];
}

int tamanhFila(Fila f){
    if(f == NULL){
        return -1;
    }

    return f -> qtd;
}

void destruirFila(Fila f){
    if(f != NULL){
        free(f);
    }
}