#include "musica.h"

typedef struct lista *Lista;

// liberar/destruir a lista
void destruirLista(Lista li);

// consultar a primeira
Musica consultarPrimeiraMusica(Lista li);

// consultar por posição
Musica consultarPorPosicao(Lista li, int pos);

// remover por posição
int removerPorPosicao(Lista li, int pos);

// remover a última
int removerUltima(Lista li);

// remover a primeira
int removerPrimeira(Lista li);

// inserir por posição
int inserirPorPosicao(Lista li, Musica m, int pos);

// inserir no final
int inserirFinal(Lista li, Musica m);

// inserir no início
int inserirInicio(Lista li, Musica m);

// criar a lista
Lista criarLista();

// consultar a quantidade de músicas na lista
int qtdMusicas(Lista li);







