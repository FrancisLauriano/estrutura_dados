#include <stdio.h>
#include <string.h>
#include "pilha.h"

int parentizacao(char pal[]){
    Pilha pAux = criar();
    int i, tam;

    if(pAux == NULL){
        return 0;
    }

    tam = strlen(pal);

    for(i = 0; i < tam; i += 1){
        if(pal[i] == '('){
            empilhar(pAux, '(');
        }else if(pal[i] == ')'){
            if(tamanho(pAux) == 0){
                detruir(pAux);
                return 0;
            }

            desempilhar(pAux);
        }
    }

    if(tamanho(pAux) == 0){
        detruir(pAux);
        return 1;
    }

    detruir(pAux);
    return 0;

}