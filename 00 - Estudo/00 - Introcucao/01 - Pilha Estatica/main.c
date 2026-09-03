#include <stdio.h>
#include "pilha.h"

// fazer copia de uma pilha p sem destruir a pilha original p 
// e retornar um copia da pilha (pCopia)
Pilha copiaPilha(Pilha p){
    Pilha pAux = criarPilha();
    Pilha pCopia = criarPilha();

    int valor;

    while(verTopo(p)){
        valor = verTopo(p);
        empilhar(pAux, valor);
        desempilhar(p);
    }

    while(verTopo(pAux)){
        valor = verTopo(pAux);
        empilhar(pCopia, valor);
        empilhar(p, valor);
        desempilhar(pAux);
    }

    destruir(pAux);

    return pCopia;

}

int main(){


    return 0;
}