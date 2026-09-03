// 8. Escreva um programa que utilize uma pilha para 
// verificar se expressoes aritmeticas estao
// com a parentizacao correta. O programa deve verificar 
// expressoes para ver se cada “abre parenteses”
// tem um “fecha parenteses” correspondente.
// Ex.: 
// Correto: ( ( ) ) – ( ( )( ) ) – ( ) ( )
// Incorreto: )( – ( ( ) ( – ) ) ( (

#include <stdio.h>
#include <string.h>
#include "pilha.h"

int parentizacao(char expressoes[]){
    Pilha p = criar();
    int tam, i;

    if(p == NULL){
        return 0;
    }

    tam = strlen(expressoes);

    for(i = 0; i < tam; i += 1){
        if(expressoes[i] == '('){
            empilhar(p, '(');
        }else if(expressoes[i] == ')'){
            if(tamanho(p) == 0){
                detruir(p);
                return 0;
            }

            desempilha(p);
        }
    }

    if(tamanho(p) == 0){
        destruir(p);
        return 1;
    }


    destruir(p);
    return 0;
}
    