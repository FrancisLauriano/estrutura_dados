#include <stdio.h>

#define PI 3.14

double calcularDiametro(double r);
double calcularPerimetro(double r);
double calcularArea(double r);


int main(){
    double raio, area, diametro, perimetro;

    printf("Insira o raio: ");
    scanf("%lf", &raio);

    printf("Valor do raio: %lf | Enrereco raio: %p\n", raio, &raio);

    area = calcularArea(raio);
    diametro = calcularDiametro(raio);
    perimetro = calcularPerimetro(raio);

    printf("Area: %.2lf | Endereco: %p\n", area, &area);
    printf("Diametro: %.2lf | Endereco: %p\n", diametro, &diametro);
    printf("Perimetro: %.2lf | Endereco: %p\n", perimetro, &perimetro);

    return 0;
}



double calcularDiametro(double r){
    return r * PI;
}

double calcularPerimetro(double r){
    return calcularDiametro(r) * 2;
}


double calcularArea(double r){
    return PI * (r * r);
}