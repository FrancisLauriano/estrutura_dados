#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// constante
#define PI 3.14
#define QTD 1
#define TAM 3

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
    
    int i, l, iMenorPerimetro = 0, iMaiorArea = 0;
    double raio;
    struct Circulo *listaCirculos[TAM];

    for(i = 0; i < TAM; i += 1){
        printf("Raio do circulo %d: ", i + 1);
        scanf("%lf", &raio);
        listaCirculos[i] = criarCirculo(raio);
    }

    // printf("...............................................................................\n");
    // printf("Perimetro Circulo %d: %.2lf\n", 1, calcularPerimetro(listaCirculos[0]));
    // printf("Area Circulo %d: %.2lf\n", 1, calcularArea(listaCirculos[0]));
    // for(i = 1; i < TAM; i += 1){
    for(i = 0; i < TAM; i += 1){
 
        printf("...............................................................................\n");
        printf("Perimetro Circulo %d: %.2lf\n", i + 1, calcularPerimetro(listaCirculos[i]));
        printf("Area Circulo %d: %.2lf\n", i + 1, calcularArea(listaCirculos[i]));
       

        if(calcularPerimetro(listaCirculos[i]) < calcularPerimetro(listaCirculos[iMenorPerimetro])){
            iMenorPerimetro = i;


        }

        if(calcularArea(listaCirculos[i]) > calcularArea(listaCirculos[iMaiorArea])){
            iMaiorArea = i;
        }

    }
    printf("...............................................................................\n");

    printf("===============================================================================\n");
    printf("Menor Perimetro - Circulo %d: %.2lf\n", iMenorPerimetro + 1, calcularPerimetro(listaCirculos[iMenorPerimetro]));
    printf("Maior Area - Circulo %d: %.2lf\n", iMaiorArea + 1 , calcularArea(listaCirculos[iMaiorArea]));
    printf("===============================================================================\n");

    for(i = 0; i < TAM; i += 1){
        destruirCirculo(listaCirculos[i]);
    }



    
    // double r, areaCirculo, perimetroCirculo;
    // struct Circulo *circulo;

    // r = receberValor(circulo);
    // circulo = criarCirculo(r);

    // areaCirculo = calcularArea(circulo);
    // printf("Area do circulo: %.2lf\n", areaCirculo);

    // perimetroCirculo = calcularPerimetro(circulo);
    // printf("Perimetro do circulo: %.2lf\n", perimetroCirculo);

    // destruirCirculo(circulo);

    return 0;
}
