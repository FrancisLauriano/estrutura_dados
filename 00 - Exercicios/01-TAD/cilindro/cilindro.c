#include <stdlib.h>
#include "cilindro.h"

struct cilindro{
    double r;
    double h;
};

Cilindro criar(double r, double h){
    Cilindro p = malloc(sizeof(struct cilindro));

    if(p != NULL){
        p -> r = r;
        p -> h = h;
    }

    return p;
}

double acessarValores(Cilindro p, char opcao){
    if(p != NULL){
        if(opcao == 'r'){
            return p -> r;
        }else if(opcao == 'h'){
            return p -> h;
        }else{
            return 0;
        }

    }else{
        return 0;
    }
    

}

double areaBase(Cilindro p){
    if(p != NULL){
        return acessarValores(p, 'r') * acessarValores(p, 'r') * PI;
    }else{
        return 0;
    }

}

double areaLateral(Cilindro p){
    if(p != NULL){
        return 2 * PI * acessarValores(p, 'r') * acessarValores(p, 'h') ;
    }else{
        return 0;
    }

}

double areaTotal(Cilindro p){
    if(p != NULL){
        return 2 * (areaBase(p) + (areaLateral(p))) ;
    }else{
        return 0;
    }

}


double volumeCilindro(Cilindro p){
    if(p != NULL){
        return areaBase(p) * acessarValor(p, 'h');
    }else{
        return 0;
    }

}

void destruir(Cilindro p){
    if(p != NULL){
        free(p);
    }

}

