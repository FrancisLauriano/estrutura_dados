#include <stdbool.h>

typedef struct ponto Ponto;

Ponto *criar(double x, double y);
double acessar(Ponto *p, char tipoValor);
_Bool alterar(Ponto *p, double novoValor, char tipoValor);
void destruir(Ponto *p);
double distanciaEntrePontos(Ponto *p1, Ponto *p2);