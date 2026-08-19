#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// constante
#define PI 3.14
#define QTD 1

// struct
struct Circulo{
    double raio;
};


// criarCirculo
struct Circulo *criarCirculo(double r){
    struct Circulo *circulo = malloc(QTD * sizeof(struct Circulo));

    if(circulo == NULL){
        return NULL;
    }else{
        circulo -> raio = r;
    }

    return circulo;
}

// receber raio 
double receberRaio(struct Circulo *c){
    double r;
    r = c -> raio;
    return r;
}


// calcularArea
double calcularArea(struct Circulo *c){
    double raio = receberRaio(c);
    return PI * (raio * raio);
}


// calcularPerimetro
double calcularPerimetro(struct Circulo *c){
    double raio = receberRaio(c);
    return 2 * PI * raio;
}

// destruirCirculo
void destruirCirculo(struct Circulo *c){
    free(c);
}


// receberValor
double receberValor(struct Circulo *c){
    double r;
    r = receberRaio(c);
    printf("Informe o raio: ");
    scanf("%lf", &r);
    return r;
}


int main(){
    double r, areaCirculo, perimetroCirculo;
    struct Circulo *circulo;

    r = receberValor(circulo);
    circulo = criarCirculo(r);

    areaCirculo = calcularArea(circulo);
    printf("Area do circulo: %.2lf\n", areaCirculo);

    perimetroCirculo = calcularPerimetro(circulo);
    printf("Perimetro do circulo: %.2lf\n", perimetroCirculo);

    destruirCirculo(circulo);

    return 0;
}
