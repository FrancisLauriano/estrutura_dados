#include <stdlib.h>
#include "pilha.h"

struct pilha{
    char dados[TAM];
    int topo;
};


Pilha criar(){
    Pilha p = malloc(sizeof(struct pilha));

    if(p != NULL){
        p -> topo = 0;
    }

    return p;
}


int empilhar(Pilha p, char caracter){
    if(p == NULL || p -> topo == TAM){
        return 0;
    }

    p -> dados[p -> topo] = caracter;
    p -> topo += 1;

    return 1;
}

int desempilhar(Pilha p){
    if(p == NULL || p -> topo == 0){
        return 0;
    }

    p -> topo -= 1;

    return 1;
}

char verTopo(Pilha p){
    if(p == NULL || p -> topo == 0){
        return '\0';
    }

    return p -> dados[p -> topo -1];
}

int tamanho(Pilha p){
    if(p == NULL){
        return 0;
    }

    return p -> topo;
}

void destruir(Pilha p){
    if(p != NULL){
        free(p);
    }
}