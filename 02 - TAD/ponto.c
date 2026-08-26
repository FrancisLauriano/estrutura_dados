#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>



struct ponto{
    double x;
    double y;

};


typedef struct ponto Ponto;


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
double acessar(Ponto *p, char tipoPonto){

    if(tipoPonto == 'x' || tipoPonto == 'X'){
        return p -> x;
    }else if(tipoPonto == 'y' || tipoPonto == 'Y'){
        return p -> y;
    }else{
        return -1;
    }
}


// alterar
_Bool alterar(Ponto *p, double novoValor, char tipoValor){
   
    
    if(tipoValor == 'x' || tipoValor == 'X'){
        p -> x = novoValor;
        return true;
    }else if(tipoValor == 'y' || tipoValor == 'Y'){
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


// distancia entre ponto
double distanciaEntrePontos(Ponto *p1, Ponto *p2){
    double x1, y1, x2, y2;

    x1 = acessar(p1, 'x');
    y1 = acessar(p1, 'y');
    x2 = acessar(p2, 'x');
    y2 = acessar(p2, 'y');

    // return pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 1.0/2.0);
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

