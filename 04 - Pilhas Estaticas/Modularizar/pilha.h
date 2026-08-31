#define TAM 5

// typedef
typedef struct pilha *Pilha;

Pilha criar();
int empilhar(Pilha p, int valor);
int desempilhar(Pilha p);
int acessarTopo(Pilha p);
int tamanho(Pilha p);
void destruir(Pilha p);