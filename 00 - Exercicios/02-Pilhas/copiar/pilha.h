#define TAM 5

typedef struct pilha *Pilha;

Pilha criar();
int inserir(Pilha p, int valor);
int remover(Pilha p);
int verTopo(Pilha p);
int tamanho(Pilha p);
void destruir(Pilha p);