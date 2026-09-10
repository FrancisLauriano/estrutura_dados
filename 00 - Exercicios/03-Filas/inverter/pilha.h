#define TAM 10

typedef struct pilha *Pilha;

Pilha criarPilha();
int empilhar(Pilha p, int valor);
int desempilhar(Pilha p);
int verTopo(Pilha p);
int tamanhoPilha(Pilha p);
void destruirPilha(Pilha p);