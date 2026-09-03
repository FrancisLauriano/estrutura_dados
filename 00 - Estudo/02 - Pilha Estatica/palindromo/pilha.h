#define TAM 5

typedef struct pilha *Pilha;

// cria pilha
Pilha criar();

// empilhar - push
int empilhar(Pilha p, char valor);

// desempilhar - pop
int desempilhar(Pilha p);

// ver topo - peek
char verTopo(Pilha p);

// tamanho
int tamanho(Pilha p);

// destruir pilha
void destruir(Pilha p);

