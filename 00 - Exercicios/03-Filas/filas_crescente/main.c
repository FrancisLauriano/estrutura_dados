#include <stdio.h>
#include "fila.h"


Fila filasCrescentes(Fila f1, Fila f2, Fila f3){
    if(f1 == NULL || f2 == NULL || f3 == NULL){
        return NULL;
    }

    int valor1, valor2;

    while(tamanhoFila(f1) > 0 && tamanhoFila(f2) > 0){
        valor1 = acessarInicio(f1);
        valor2 = acessarInicio(f2);

        if(valor1 <= valor2){
            enfileirar(f3, valor1);
            desenfileirar(f1);
        }else{
            enfileirar(f3, valor2);
            desenfileirar(f2);
        }
    }

    while(tamanhoFila(f1) > 0){
        valor1 = acessarValor(f1);
        enfileirar(f3, valor1);
        desenfileirar(f1);
    }


    while(tamanhoFila(f2) > 0){
        valor2 = acessarValor(f2);
        enfileirar(f3, valor2);
        desenfileirar(f2);
    }

    return f3;
}