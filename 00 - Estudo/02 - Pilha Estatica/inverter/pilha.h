#define TAM 5

typedef struct pilha *Pilha;

Pilha criar();

int empilhar(Pilha p, char caracter);

int desempilhar(Pilha p);

char verTopo(Pilha p);

int tamanho(Pilha p);

void destruir(Pilha p);
