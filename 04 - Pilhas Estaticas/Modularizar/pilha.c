#include <stdlib.h>
#include "pilha.h"

// struct
struct pilha{
    int dados[TAM];
    int topo;
};


// criar pilha
Pilha criar(){

    Pilha p = malloc(sizeof(struct pilha));

    if(p != NULL){
        p -> topo = 0;
    }

    return p;
}

// empilhar - push
int empilhar(Pilha p, int valor){
    if(p != NULL && p -> topo < TAM){
        p -> dados[p -> topo] = valor;
        p -> topo += 1;
        return 1;
    }

    return 0;
}

// desempilhar - pop
int desempilhar(Pilha p){
    if(p != NULL && p -> topo > 0){
        p -> topo -= 1;
        return 1;
    }

    return 0;
}

// acessar topo pilha - peek
int acessarTopo(Pilha p){
    if(p != NULL && p -> topo > 0){
        return p -> dados[p -> topo -1];
    }

    return -1;
}

// tamanho da pilha
int tamanho(Pilha p){
    if(p != NULL){
        return p -> topo;
    }

    return -1;
}


// destruir pilha
void destruir(Pilha p){
    if(p != NULL){
        free(p);
    }
}

// main