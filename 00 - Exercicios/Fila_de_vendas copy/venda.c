#include <stdlib.h>
#include <stdio.h>
#include "venda.h"

struct venda{
    int codProduto;
    double valor;
    int qtd;
};

// criar uma venda;
Venda criarVenda(int cod, double valor, int qtd){
    Venda v = malloc(sizeof(struct venda));

    if(v != NULL){
        v -> codProduto = cod;
        v -> valor = valor;
        v -> qtd = qtd;
    }

    return v;
}


// consultar seus dados - codProduto:
int consultarCodProduto(Venda v){
    if(v == NULL){
        return -1;
    }

    return v -> codProduto;

}


// consultar seus dados - valor:
double consultarValor(Venda v){
    if(v == NULL){
        return -1.0;
    }

    return v -> valor;
}


// consultar seus dados - qtd:
int consultarQtd(Venda v){
    if(v == NULL){
        return -1;
    }

    return v -> qtd;

}


// imprimir seus dados;
void imprimirVenda(Venda v){
    if(v == NULL){
        printf("Erro\n");
        return;
    }

    printf("---------------------------------------\n");
    printf("Codigo: %d\n", consultarCodProduto(v));
    printf("Valor R$: %.2lf\n", consultarValor(v));
    printf("Qtd: %d\n", consultarQtd(v));
    printf("---------------------------------------\n");

}


// liberar uma venda.
void liberarVenda(Venda v){
    if(v != NULL){
        free(v);
    }
}
