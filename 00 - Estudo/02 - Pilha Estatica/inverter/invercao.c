//11. Desenvolva uma funcao para inverter a posicao dos elementos de uma pilha P.

#include <stdio.h>
#include "pilha.h"

int inverterPilha(Pilha p){
    Pilha pAux1 = criar();
    Pilha pAux2 = criar();

    if(p == NULL || pAux1 == NULL || pAux2 == NULL){
        return 0;
    }

    char caracter;

    while(quantidade(p) > 0){
        caracter = verTopo(p);
        empilhar(pAux1, caracter);
        desempilhar(p);
    }

    while(quantidade(pAux1) > 0){
        caracter = verTopo(pAux1);
        empilhar(pAux2, caracter);
        desempilhar(pAux1);
    }

    while(quantidade(pAux2) > 0){
        caracter = verTopo(pAux2);
        empilhar(p, caracter);
        desempilhar(pAux2);
    }

    destruir(pAux1);
    destruir(pAux2);

    return 1;
}



// inverter e retornar a copiada da pilha invertida e manter a pilha original sem inversao
Pilha inverteCopy(Pilha p){
    Pilha pCopy = criar();
    Pilha pAux = criar();
    char caracter;

    if(p == NULL || pCopy  == NULL|| pAux == NULL){
        return NULL;
    }


    while(tamanho(p) > 0){
        caracter = verTopo(p);
        empilhar(pCopy, caracter);
        empilhar(pAux, caracter);
        desempilhar(p);
    }

    while(tamanho(pAux) > 0){
        caracter = verTopo(pAux);
        empilhar(p, caracter);
        desempilhar(pAux);
    }

    detruir(pAux);

    return pCopy;
}