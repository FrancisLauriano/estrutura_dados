// 7. Considere uma pilha que armazene caracteres. 
// Escreva uma funcao que verifique se 
// uma palavra e um palindromo.

#include <stdio.h>
#include <string.h>
#include "pilha.h"

int palindromo(Pilha p){
    char caracter;

    Pilha pAux = criar();
    Pilha pInvert = criar();
    Pilha pCopy = criar();

    if(p == NULL || pAux == NULL || pInvert == NULL || pCopy == NULL){
        return 0;
    }

    while(tamanho(p) > 0){
        caracter = verTopo(p);
        empilhar(pInvert, caracter);
        empilhar(pAux, caracter);
        desempilhar(p);
    }

    while(tamanho(pAux) > 0){
        caracter = verTopo(pAux);
        empilhar(p, caracter);
        empilhar(pCopy, caracter);
        desempilhar(pAux);
    }

    destruir(pAux);

    int i, tam = tamanho(p);

    for(i = 0; i < tam; i += 1){
        if(verTopo(pCopy) != verTodo(pInvert)){
            destruir(pCopy);
            destruir(pInvert);
            return 0;
        }
        desempilhar(pCopy);
        desempilhar(pInvert);
    }

    destruir(pCopy);
    destruir(pInvert);

    return 1;
}