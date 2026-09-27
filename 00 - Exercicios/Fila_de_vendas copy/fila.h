#include "venda.h"

#define TAM 100


typedef struct fila *Fila;
                                        
// criar a fila
Fila criarFila();


// verificar se a fila está vazia
int filaVazia(Fila f);


// verificar se a fila está cheia
int filaCheia(Fila f);

// inserir uma venda
int inserirVenda(Fila f, Venda v);


// remover a próxima venda
int removerVenda(Fila f);


// consultar a próxima venda
Venda consultarProxVenda(Fila f);


// consultar a quantidade de vendas na fila
int qtdVendas(Fila f);


// liberar a fila
void liberarFila(Fila f);