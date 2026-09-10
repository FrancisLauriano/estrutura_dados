#include <stdlib.h>
#include "pilha.h"

struct pilha{
    int num[TAM];
    int topo;
};

Pilha criar(){
    Pilha p = malloc(sizeof(struct pilha));

    if(p != NULL){
        p -> topo = 0;
    }

    return p;
}


int inserir(Pilha p, int valor){
    if(p == NULL || p -> topo == TAM){
        return 0;
    }

    p -> num[p -> topo] = valor;
    p -> topo += 1;

    return 1;
}


int remover(Pilha p){
    if(p == NULL || p -> topo == 0){
        return 0;
    }

    p -> topo -= 1;
    return 1;
}



int verTopo(Pilha p){
    if(p == NULL || p -> topo == 0){
        return 0;
    }

    return p -> num[p -> topo -1];
}


int tamanho(Pilha p){
    if(p == NULL){
        return -1;
    }
    return p -> topo;
}


void destruir(Pilha p){
    if(p != NULL){
        free(p);
    }

}