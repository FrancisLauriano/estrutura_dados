#include <stdio.h>
#include "fila.h"

Fila concatena(Fila f1, Fila f2){

    if(f1 == NULL || f2 == NULL){
        return NULL;
    }
    
    int valor;

    while(tamanhoFila(f2) > 0){
        valor = acessarInicio(f2);
        enfileirar(f1, valor);
        desenfileirar(f2);
    }

    return f1;
}