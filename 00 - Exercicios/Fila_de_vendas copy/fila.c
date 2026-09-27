#include <stdlib.h>
#include "fila.h"
#include "venda.h"


struct fila{
    Venda vendas[TAM];
    int inicio;
    int fim;
    int qtd;
};


// criar a fila
Fila criarFila(){
    Fila f = malloc(sizeof(struct fila));

    if(f != NULL){
        f -> inicio = 0;
        f -> fim = 0;
        f -> qtd = 0;
    }

    return f;
}


// verificar se a fila está vazia
int filaVazia(Fila f){

    if(f != NULL && f -> qtd == 0){
        return 1;
    }

    return 0;
}


// verificar se a fila está cheia
int filaCheia(Fila f){

    if(f != NULL && f -> qtd == TAM){
        return 1;
    }

    return 0;
}

// inserir uma venda
int inserirVenda(Fila f, Venda v){
    if(f == NULL || v == NULL || filaCheia(f)){
        return 0;
    }

    f -> vendas[f -> fim] = v;
    f -> fim = (f -> fim + 1) % TAM;
    f -> qtd += 1;

    return 1;
}


// remover a próxima venda
int removerVenda(Fila f){
    if(f == NULL || filaCheia(f)){
        return 0;
    }

    f -> inicio = (f -> inicio + 1) % TAM;
    f -> qtd -= 1;

    return 1;
}


// consultar a próxima venda
Venda consultarProxVenda(Fila f){
    if(f == NULL || filaVazia(f)){
        return NULL;
    }


    return f -> vendas[f -> inicio];
    
}


// consultar a quantidade de vendas na fila
int qtdVendas(Fila f){
    if(f == NULL){
        return -1;
    }

    return f -> qtd;

}


// liberar a fila
void liberarFila(Fila f){
    Venda v;

    if(f != NULL){
        while(!filaVazia(f)){
            v = consultarProxVenda(f);
            // removerVenda(f);
            liberarVenda(v);
            removerVenda(f);
        }
        free(f);
    }
}
