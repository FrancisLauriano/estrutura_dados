#include <stdio.h>
#include "pilha.h"

int main(){
    Pilha p = criar();
    empilhar(p, 50);
    empilhar(p, 60);
    empilhar(p, 70);
    empilhar(p, 20);
    printf("Topo da pilha: %d\n", acessarTopo(p));
    desempilhar(p);
    desempilhar(p);
    empilhar(p, 80);
    empilhar(p, 100);
    empilhar(p, 200);
    printf("Topo da pilha: %d\n", acessarTopo(p));
    destruir(p);


    return 0;
}