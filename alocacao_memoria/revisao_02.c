#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// constante
#define PI 3.14

// struct
struct circulo{
    double raio;
};


typedef struct circulo Circulo;


// criarCirculo
Circulo *criarCirculo(double r){
    Circulo *circulo = malloc(sizeof(Circulo));

    if(circulo == NULL){
        return NULL;
    }else{
        circulo -> raio = r;
    }

    return circulo;
}

// receber raio 
double receberRaio(Circulo *c){
    double r;
    r = c -> raio;
    return r;
}


// calcularArea
double calcularArea(Circulo *c){
    double raio = receberRaio(c);
    return PI * (raio * raio);
}


// calcularPerimetro
double calcularPerimetro(Circulo *c){
    double raio = receberRaio(c);
    return 2 * PI * raio;
}

// destruirCirculo
void destruirCirculo(Circulo *c){
     if(c != NULL){
        free(c);
    }
}


// receberValor
double receberValor(Circulo *c){
    double r;
    r = receberRaio(c);
    printf("Informe o raio: ");
    scanf("%lf", &r);
    return r;
}




int main(){
    
    

    
    double r, areaCirculo, perimetroCirculo;
    Circulo *circulo;

    r = receberValor(circulo);
    circulo = criarCirculo(r);

    areaCirculo = calcularArea(circulo);
    printf("Area do circulo: %.2lf\n", areaCirculo);

    perimetroCirculo = calcularPerimetro(circulo);
    printf("Perimetro do circulo: %.2lf\n", perimetroCirculo);

    destruirCirculo(circulo);

    return 0;
}
