#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


Pilha inverter(Pilha p){
    Pilha pAux1 = criar();
    Pilha pAux2 = criar();

    int i, valor;

    if(p == NULL || pAux1 == NULL || pAux2 == NULL){
        return NULL;
    }

    for(i = 0; i < tamanho(p); i += 1){
        valor = acessarTopo(p);
        empilhar(pAux1, valor);
        desempilhar(p);
    }

    for(i = 0; i < tamanho(pAux1); i += 1){
        valor = acessarTopo(pAux1);
        empilhar(pAux2, valor);
        desempilhar(pAux1);
    }

    for(i = 0; i < tamanho(pAux2); i += 1){
        valor = acessarTopo(pAux2);
        empilhar(p, valor);
        desempilhar(pAux2);
    }

    detruir(pAux1);
    destruir(pAux2);

    return p;
}