#define TAM 10

typedef struct fila *Fila;

Fila criarFila();

int enfileirar(Fila f, int valor);

int desenfileirar(Fila f);

int acessarInicio(Fila f);

int tamanhFila(Fila f);

void destruirFila(Fila f);