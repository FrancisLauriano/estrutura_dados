#include <stdio.h>
#include <stdlib.h>


struct complexo{
    int a;
    int b;
};


typedef struct complexo Complexo;


// numero complexo a + bi
//  i ² = -1 ==> raiz i = -1;



// (a) criar um número complexo
Complexo *criar(int valorA, int valorB){
    Complexo *c = malloc(sizeof(Complexo));

    if(c != NULL){
        c -> a = valorA;
        c -> b = valorB;
    }

    return c;
}



// (b) destruir um número complexo
void destruir(Complexo *c){
    if(c != NULL){
        free(c);
    }

}


// receber valor a
int receberA(Complexo *c){
    int valorA;
    valorA = c -> a;
    return valorA;

}


// receber valor b
int receberB(Complexo *c){
    int valorB;
    valorB = c -> b;
    return valorB;
}


// (c) soma de dois números complexos
Complexo *soma(Complexo *c1, Complexo *c2){
    int valorA1, valorB1, valorA2, valorB2, somaR, somaI;

    valorA1 = receberA(c1);
    valorB1 = receberB(c1);

    valorA2 = receberA(c2);
    valorB2 = receberB(c2);


    somaR = valorA1 + valorA2;
    somaI = valorB1 + valorB2;
    
    
    return criar(somaR, somaI);
}



// (d) subtração de dois números complexos
Complexo *subtracao(Complexo *c1, Complexo *c2){
    int valorA1, valorB1, valorA2, valorB2, subR, subI;

    valorA1 = receberA(c1);
    valorB1 = receberB(c1);

    valorA2 = receberA(c2);
    valorB2 = receberB(c2);

    subR = valorA1 - valorA2;
    subI = valorB1 - valorB2;

    return criar(subR, subI);
}


// (e) multiplicação de dois números complexos 
// z1 = a + bi
// z2 = c +di
// z1 · z2 = (ac – bd) + (ad + cb)i
Complexo *multiplicacao(Complexo *c1, Complexo *c2){
    int valorA1, valorB1, valorA2, valorB2, multR, multI;

    valorA1 = receberA(c1); // a
    valorB1 = receberB(c1);  // b

    valorA2 = receberA(c2);  // c
    valorB2 = receberB(c2);  // d

    // (ac – bd) 
    multR = (valorA1 * valorA2) - (valorB1 * valorB2);

    // (ad + cb)i
    multI = (valorA1 * valorB2) + (valorA2 * valorB1);


    return criar(multR, multI);
}



// (f) divisão de dois números complexos
// x = (ac + bd) / (c^2 + d^2)
// y = (bc - ad) / ( c^2 + d^2)
Complexo *divisao(Complexo *c1, Complexo *c2){
    int valorA1, valorB1, valorA2, valorB2, divR, divI;
    double denominador;

    valorA1 = receberA(c1); // a
    valorB1 = receberB(c1);  // b

    valorA2 = receberA(c2);  // c
    valorB2 = receberB(c2);  //d

    denominador = (valorA2 * valorA2) + (valorB2 * valorB2);

    if(denominador == 0 ){
        return NULL;
    }

    divR = ((valorA1 * valorA2) + (valorB1 * valorB2)) / denominador;
    divI = ((valorB1 * valorA2) - (valorA1 * valorB2)) / denominador;

    return criar(divR, divI);
}


int receberReal(char qualNumC){
    int real;

    printf("%c Numero - Parte Real: ", qualNumC);
    scanf("%d", &real);
    
    return real;
}


int receberImaginario(char qualNumC){
    int ima;

    printf("%c Numero - Parte imaginaria: ", qualNumC);
    scanf("%d", &ima);
    
    return ima;
}

void imprimir(Complexo *c){
    if(c -> b >= 0){
       printf("%d + %di\n", c -> a, c -> b); 
    }else{
        printf("%d %di\n", c -> a, c -> b);
    }

}


int main(){
    Complexo *c1;
    Complexo *c2;
    Complexo *c3;

    int r1, i1, r2, i2, r3, i3;

    r1 = receberReal('1');
    i1 = receberImaginario('1');

    r2 = receberReal('2');
    i2 = receberImaginario('2');


    // criar n1 e n2
    c1 = criar(r1, i1);
    c2 = criar(r2, i2);

    // calcular soma
    c3 = soma(c1, c2);

    // imprimir soma
    printf("Resultado da Soma: ");
    imprimir(c3);

    // calcular subtracao
    c3 = subtracao(c1, c2);

    // imprimir soma
    printf("Resultado da Subtracao: ");
    imprimir(c3);

    // calcular multiplicacao
    c3 = multiplicacao(c1, c2);

    // imprimir multiplicacao
    printf("Resultado da Multiplicacao: ");
    imprimir(c3);

    // calcular divisao
    c3 = divisao(c1, c2);

    // imprimir divisao
    printf("Resultado da Divisao: ");
    imprimir(c3);

    destruir(c1);
    destruir(c2);
    destruir(c3);

    return 0;
}