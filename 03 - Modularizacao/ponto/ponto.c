#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "ponto.h"

// struct
struct ponto{
    double x;
    double y;
};


// criar
Ponto *criar(double x, double y){

    Ponto *p = malloc(sizeof(Ponto));

    if(p != NULL){
        p -> x = x;
        p -> y = y;
    }

    return p;
}


// acessar
double acessar(Ponto *p, char tipoValor){
    if(tipoValor == 'x' || tipoValor == 'X'){
        return p -> x;
    }
    if(tipoValor == 'y' || tipoValor == 'Y'){
        return p -> y;
    }
    return -1;
}


// alterar
_Bool alterar(Ponto *p, double novoValor, char tipoValor){
    if(tipoValor == 'x' || tipoValor == 'X'){
        p -> x = novoValor;
        return true;
    }
    if(tipoValor == 'y' || tipoValor == 'Y'){
        p -> y = novoValor;
        return true;
    }

    return false;
}


// destruir
void destruir(Ponto *p){
    if(p != NULL){
        free(p);
    }

}


// distancia entre os dois
double distanciaEntrePontos(Ponto *p1, Ponto *p2){
    double x1, y1, x2, y2;

    x1 = acessar(p1, 'x');
    y1 = acessar(p1, 'y');
    x2 = acessar(p2, 'x');
    y2 = acessar(p2, 'y');

    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

}