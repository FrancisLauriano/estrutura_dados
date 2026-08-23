#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

struct cilindro{
    double altura;
    double raio;
};

typedef struct cilindro Cilindro;


// criar cilindro
Cilindro *criar(double r, double h){
    Cilindro *c = malloc(sizeof(Cilindro));

    if(c != NULL){
       c -> raio = r;
       c -> altura = h;
    }

    return c;
}


// receber teclado
double receberRaioTeclado(){
    double r;

    printf("Informe raio: ");
    scanf("%lf", &r);

    return r; 
}

double receberAlturaTeclado(){
    double h;

    printf("Informe altura: ");
    scanf("%lf", &h);

    return h;
}


// receber raio
double receberRaio(Cilindro *c){
    double r;
    r = c -> raio;
    return r;

}


// receber altura
double receberAltura(Cilindro *c){
    double h;
    h = c -> altura;
    return h;
}


// calcular area ==> area: pi * r^2
double calcularArea(Cilindro *c){
    double r;
    
    r = receberRaio(c);

    return PI * (r * r);
}


// calcular volume ==> volume: pi * r^2 * h
double calcularVolume(Cilindro *c){
    double r, h;

    r = receberRaio(c);
    h = receberAltura(c);

    return PI * (r * r) * h;
}


// destruir cilindo
void destruir(Cilindro *c){

    if(c != NULL){
        free(c);
    }
}





// main
int main(){
    Cilindro *c;
    double r, h, area, volume;
    
    r = receberRaioTeclado();
    h = receberAlturaTeclado();

    c = criar(r, h);

    if(c == NULL){
        printf("Erro ao alocar memoria\n");
        destruir(c);
        return 1;
    }

    area = calcularArea(c);
    printf("Area: %.2lf\n", area);

    volume = calcularVolume(c);
    printf("Volume: %.2lf\n", volume);

    destruir(c);

    return 0;
}
