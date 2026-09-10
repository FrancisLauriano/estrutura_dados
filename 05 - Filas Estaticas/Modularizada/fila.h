#define TAM 5

typedef struct fila *Fila;

Fila criar();


int enfileirar(Fila p, int valor);


int desenfileirar(Fila p);

int acessarInicio(Fila p);

int tamanho(Fila p);


void destruir(Fila p);
