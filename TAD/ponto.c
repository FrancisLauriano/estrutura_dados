#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto{
    double x;
    double y;
};


typedef struct ponto Ponto;


Ponto *criar(double x, double y){

    Ponto *p = malloc(sizeof(Ponto));

    if(p != NULL){
        p -> x = x;
        p -> y = y;
    }
    return p;
}


double distanciaEntrePontos(Ponto *p1, Ponto *p2){
    double x1, x2, y1, y2;
    x1 = p1 -> x;
    x2 = p2 -> x;
    y1 = p1 -> y;
    y2 = p2 -> y;

    return  sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}


void destruir(Ponto *p){
    if(p != NULL){
        free(p);
    }

}


double receberX(char pontoX){
    double x;
    printf("Informe X%c: ", pontoX);
    scanf("%lf", &x);

    return x;
}

double receberY(char pontoY){
    double y;
    printf("Informe Y%c: ", pontoY);
    scanf("%lf", &y);

    return y;
}




int main(){
    Ponto *p1;
    Ponto *p2;
    double x1, y1, x2, y2, disDoisPonto;


    // receber pelo teclado
    // printf("Ponto 1 - X: ");
    // scanf("%lf", &x1);
    // printf("Ponto 1 - Y: ");
    // scanf("%lf", &y1);

    // printf("Ponto 2 - X: ");
    // scanf("%lf", &x2);
    // printf("Ponton 2 - Y: ");
    // scanf("%lf", &y2);

    // receber os valores pelo teclado
    x1 = receberX('1');
    y1 = receberY('1');

    x2 = receberX('2');
    y2 = receberY('2');


    // criar 
    p1 = criar(x1, y1);
    p2 = criar(x2, y2);

    // mensagem erro

    if(p1 == NULL || p2 == NULL){
        printf("Erro na alocacao de memoria\n");

        // destruir
        destruir(p1);
        destruir(p2);

        return 1;
    }


    // calcular distancia
    disDoisPonto = distanciaEntrePontos(p1, p2);
    printf("Distancia entre P1 e P2: %.2lf\n", disDoisPonto);


    // destruir
    destruir(p1);
    destruir(p2);

    return 0;
}