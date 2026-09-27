#include <stdio.h>
#include <stdlib.h>
#include "venda.h"
#include "fila.h"

// registra_venda: adicionar uma venda ao final da fila;
void registrarVenda(Fila f, int cod, double valor, int qtd){
    if(f == NULL || cod == 0 || valor == 0.00 || qtd == 0){
        printf("Nao foi possivel registrar a venda\n");
        return;
    }

    Venda v = criarVenda(cod, valor, qtd);

    if(v == NULL){
        printf("Nao foi possivel registrar a venda\n");
        return;
    }

    if(inserirVenda(f, v)){
        printf("Venda registrada com sucesso\n");
        return;
    }

    liberarVenda(v);
    printf("Nao foi possivel registrar a venda\n");
}


// consulta_proxima_venda: mostrar os dados da próxima 
// venda a ser processada, sem removê-la;
void consultaDaProximaVenda(Fila f){

    if(f == NULL){
        printf("Nao foi possivel mostrar os dados da proxima venda\n");
        return;
    }

    Venda v = consultarProxVenda(f);

    if(v == NULL){
        printf("Nao foi possivel mostrar os dados da proxima venda\n");
        return;
    }

    printf("===== Dados da proxima venda =====\n");
    imprimirVenda(v);
}



// processa_venda: processar e remover a primeira 
// venda da fila, atualizando o valor total das vendas
// processadas.
void processarVenda(Fila f, double *valorTotal){
    double totalVendas;

    if(f == NULL){
        printf("Nao foi possivel processae e remover primeiras venda da fila\n");
        return;
    }

    Venda v = consultarProxVenda(f);

    if(v == NULL){
        printf("Nao foi possivel processae e remover primeiras venda da fila\n");
        return; 
    }


    double totalVendas = consultarValor(v) * consultarQtd(v);
    *valorTotal += totalVendas;

    printf("===== Total Venda processada =====\n");
    printf("R$ %.2lf\n", totalVendas);

    removerVenda(f);
    liberarVenda(v);

}

int main(){

    Fila f = criarFila();

    double valorTotal = 0;

    registrarVenda(f, 101, 10.00, 2);

    registrarVenda(f, 102, 25.00, 3);

    registrarVenda(f, 103, 8.50, 4);

    registrarVenda(f, 104, 40.00, 1);


    consultaDaProximaVenda(f);


    processarVenda(f, &valorTotal);

    processarVenda(f, &valorTotal);


    printf("\n=======================================\n");

    printf("Vendas aguardando processamento: %d\n",
           qtdVendas(f));

    printf("Valor total das vendas processadas: R$ %.2lf\n",
           valorTotal);

    printf("=======================================\n");


    liberarFila(f);

    return 0;
}