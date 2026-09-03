#include <stdio.h>
#include "pilha.h"

// fazer uma copia da pilha
Pilha pilhaCopy(Pilha p){
    Pilha pCopy = criar();
    Pilha pAux = criar();

    if(p == NULL || pCopy == NULL || pAux == NULL){
        return NULL;
    }

    int valor;

    while(tamanho(p) > 0){
        valor = verTopo(p);
        empilhar(pAux, valor);
        desempilhar(p);
    }

    while(tamanho(pAux) > 0){
        valor = verTopo(pAux);
        empilhar(pCopy, valor);
        empilhar(p, valor);
        desempilhar(pAux);
    }

    destruir(pAux);

    return pCopy;
}