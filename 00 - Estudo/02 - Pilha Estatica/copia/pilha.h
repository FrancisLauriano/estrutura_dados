#define TAM 5

typedef struct pilha *Pilha;

Pilha criar();

int empilhar(Pilha p, int valor);

int desempilha(Pilha p);

int verTopo(Pilha p);

int tamanho(Pilha p);

void destruir(Pilha p);