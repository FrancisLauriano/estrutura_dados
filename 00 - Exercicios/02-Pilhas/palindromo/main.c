#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"



// trata string
void tratarStr(char pl[]){
    int i;

    for(i = 0; pl[i] != '\0'; i += 1){
        if(pl[i] == '\n'){
            pl[i] = '\0';
            break;
        }
    }

}


// receber string
void receber(char pl[], int t){
    printf("Informe a palavra: ");
    fgets(pl, t, stdin);

    tratarStr(pl);
}



// palindromo
int palindromo(char pal[]){
    Pilha p = criar();
    int i, tam;

    if(p == NULL){
        return 0;
    }

    tam = strlen(pal);

    for(i = tam - 1; i >= 0; i -= 1){
        if(pal[i] != acessarTopo(p)){
            destruir(p);
            return 0;
        }
        desempilhar(p);
    }

    detruir(p);
    
    return 1;
}