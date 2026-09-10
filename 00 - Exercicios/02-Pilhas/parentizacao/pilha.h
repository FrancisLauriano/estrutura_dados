#define TAM 10

typedef struct pilha *Pilha;

Pilha criar();

int inserir(Pilha p, char valor);

int remover(Pilha p);

char acessarTopo(Pilha p);

int tamanho(Pilha p);

void destruir(Pilha p);