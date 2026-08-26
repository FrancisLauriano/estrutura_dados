#include <stdio.h>
#include <stdbool.h>
#include "ponto.h"

int main(){

    Ponto *p1, *p2;

    double distancia_p1_p2;

    // criar p1
    p1 = criar(2.5, 5);

    // criar p2
    p2 = criar(7, 11.6);

    // imprimir o p1
    printf("X1: %.2lf - Y1: %.2lf\n", acessar(p1, 'x'), acessar(p1, 'y'));

    // imprimir o p2
    printf("X2: %.2f - Y2: %.2f\n", acessar(p2, 'x'), acessar(p2, 'y'));

    // distancia entre os pontos

    distancia_p1_p2 =  distanciaEntrePontos(p1, p2);

    printf("Distancia entre P1 e P2: %.2lf\n", distancia_p1_p2);

    printf("=====================================================================\n");


    // alterar p1 e p2

    // _Bool alterar(Ponto *p, double novoValor, char tipoValor);

    _Bool alteradoX, alteradoY;
    alteradoX = alterar(p1, 5, 'x');
    alteradoY = alterar(p1, 10.2, 'y');

    if(alteradoX && alteradoY){
        printf("P1 alterado com sucesso\n");
        printf("Novo X1: %.2lf - Novo Y1: %.2lf\n", acessar(p1, 'x'), acessar(p1, 'y'));
        printf("=====================================================================\n");

    }


    alteradoX = alterar(p2, 18, 'x');
    alteradoY = alterar(p2, 25.5, 'y');

    if(alteradoX && alteradoY){
        printf("P1 alterado com sucesso\n");
        printf("Novo X1: %.2lf - Novo Y1: %.2lf\n", acessar(p2, 'x'), acessar(p2, 'y'));
        printf("=====================================================================\n");

    }


    // distancia entre os pontos - novos valores

    distancia_p1_p2 =  distanciaEntrePontos(p1, p2);

    printf("Distancia entre P1 e P2: %.2lf\n", distancia_p1_p2);

    printf("=====================================================================\n");


    // destruir p1
    destruir(p1);

    // destruir p1
    destruir(p2);

    return 0;
}

