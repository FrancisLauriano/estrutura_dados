// 7. Considere uma pilha que armazene caracteres. 
// Escreva uma funcao que verifique se 
// uma palavra e um palindromo.

#include <stdio.h>
#include <string.h>
#include "pilha.h"


int palindromo(char palavra[]){
    Pilha p = criar();
    int tam, i;

    if(p == NULL){
        return 0;
    }

    tam = strlen(palavra);

    for(i = tam -1; i >= 0; i -= 1){
       empilhar(p, palavra[i]); 
    }

    for(i = 0; i < tam; i += 1){
        if(palavra[i] != verTopo(p)){
            detruir(p);
            return 0;
        }
        desempilhar(p);
    }

    destruir(p);

    return 1;
}