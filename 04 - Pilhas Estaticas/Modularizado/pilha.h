#define TAM 5

typedef struct pilha *Pilha;

// criar pilha
Pilha criarPilha();

// empilhar - push
int empilhar(Pilha p, int valor);
// desempilhar - pop
int desempilhar(Pilha p);

// ver topo - peek
int verTopo(Pilha p);

// tamanho
int tamanho(Pilha p);

// destruir
void destruir(Pilha p);