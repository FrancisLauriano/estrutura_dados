#include <stdlib.h>
#include "pilha.h"

struct pilha{
    char dados[TAM];
    int topo;
};

// cria pilha
Pilha criar(){
    Pilha p = malloc(sizeof(struct pilha));

    if(p != NULL){
        p -> topo = 0;
    }

    return p;
}

// empilhar - push
int empilhar(Pilha p, char caracter){
    if(p == NULL || p -> topo == TAM){
        return 0;
    }

    p -> dados[p -> topo] = caracter;
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
char verTopo(Pilha p){
    if(p == NULL || p -> topo == 0){
        return '\0';
    }

    return p -> dados[p -> topo - 1];
}


// tamanho
int tamanho(Pilha p){
    if(p == NULL){
        return -1;
    }

    return p -> topo;
}


// destruir pilha
void destruir(Pilha p){
    if(p != NULL){
        free(p);
    }
}
