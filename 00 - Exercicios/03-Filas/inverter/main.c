#include <stdio.h>
#include "pilha.h"
#include "fila.h"

// inverter fila
Fila inverte(Fila f){
    Pilha pAux = criarPilha();
    int valor;

    if(f == NULL || pAux == NULL){
        return NULL;
    }

    while(tamanhoFila(f) > 0){
        valor = acessarInicio(f);
        empilhar(pAux, valor);
        desenfileirar(f);
    }

    while(tamanhoPilha(pAux) > 0){
        valor = acessarTopo(pAux);
        enfileirar(f, valor);
        desempilhar(pAux);
    }

    destruirPilha(pAux);

    return f;
}

