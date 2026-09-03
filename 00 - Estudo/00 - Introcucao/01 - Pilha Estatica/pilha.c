#include <stdlib.h>
#include "pilha.h"

struct pilha{
    int dados[TAM];
    int topo;
};


// criar pilha
Pilha criarPilha(){
    Pilha p = malloc(sizeof(struct pilha));

    if(p != NULL){
        p -> topo = 0;
    }
    return p;
}

// empilhar - push
int empilhar(Pilha p, int valor){
    if(p == NULL || p -> topo >= TAM){
        return 0;
    }

    p -> dados[p -> topo] = valor;
    p -> topo += 1;

    return 1;
}

// desempilhar - pop
int desempilhar(Pilha p){
    if(p == NULL || p -> topo == 0){
        return 0;
    }

    p -> topo -= 1;
    return 1;

}

// ver topo - peek
int verTopo(Pilha p){
    if(p == NULL){
        return 0;

    }

    return p -> dados[p -> topo -1];
}

// tamanho
int tamanho(Pilha p){
    if(p == NULL){
        return 0;
    }

    return p -> topo;
}

// destruir
void destruir(Pilha p){
    if(p != NULL){
        free(p);
    }
}