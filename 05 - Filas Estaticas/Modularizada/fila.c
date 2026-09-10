#include <stdlib.h>
#include "fila.h"

struct fila{
    int dados[TAM];
    int inicio;
    int final;
    int qtd;
};


Fila criar(){
    Fila p = malloc(sizeof(struct fila));

    if(p != NULL){
        p -> inicio = 0;
        p -> final = 0;
        p -> qtd = 0;
    }

    return p;
}


int enfileirar(Fila p, int valor){
    if(p -> qtd == TAM){
        return 0;
    }

    p -> dados[p -> final] = valor;
    p -> final = (p -> final + 1) % TAM;
    p -> qtd += 1;

    return 1;
}


int desenfileirar(Fila p){
    if(p == NULL || p -> qtd == 0){
        return 0;
    }

    p -> inicio = (p -> inicio + 1) % TAM;
    p -> qtd -= 1;

    return 1;

}




int acessarInicio(Fila p){
    if(p == NULL || p -> qtd == 0){
        return 0;
    }

    return p -> dados[p -> inicio];
}


int tamanho(Fila p){
    if(p == NULL){
        return -1;
    }

    return p -> qtd;
}


void destruir(Fila p){
    if(p != NULL){
        free(p);
    }
}