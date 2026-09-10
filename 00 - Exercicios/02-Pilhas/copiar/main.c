#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


// copiar de uma pilha para outra 
Pilha copiar(Pilha p){
    Pilha pCopy = criar();
    Pilha pAux = criar();
    int i, valor;


    if(pCopy == NULL || pAux == NULL){
        returnn NULL;
    }

    for(i = 0; i < tamanho(p); i += 1){
        valor = acessar(p);
        empilhar(pAux, valor);
        desempilhar(p);
    }

    for(i = 0; i < tamanho(pAux); i += 1){
        valor = acessar(pAux);
        empilhar(pCopy, valor);
        empilhar(p, valor);
        desempilhar(pAux);
    }

    destruir(pAux);

    return pCopy;
}