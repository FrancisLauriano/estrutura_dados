#define TAM 10

typedef struct fila *Fila;

Fila criar();

int enfileirar(Fila f, int valor);

int desenfileira(Fila f);

int acessarInicio(Fila f);

int tamanho(Fila f);

void destruir(Fila f);