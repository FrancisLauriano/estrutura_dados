#define TAM 5

typedef struct conjunto *Conjunto;

// criar conjunto
Conjunto criar(int v[], int qtd);


// (b) Cria um conjunto vazio
Conjunto criarVazio();


// (l) Testa se o conjunto é vazio
int verVazio(Conjunto p);

// (k) Tamanho
int tamanho(Conjunto p);


// destruir conjunto
void destruir(Conjunto p);



// repeticao
int repeticao(int v[], int qtd, int valor);


// (g) Testa se um número pertence ao conjunto
int pertence(Conjunto p, int valor);


// (a) União
Conjunto uniao(Conjunto p1, Conjunto p2);

// (e) Interseção
Conjunto intersecao(Conjunto p1, Conjunto p2);



// (f) Diferença
Conjunto diferenca(Conjunto p1, Conjunto p2);


// (j) Testa se os conjuntos são iguais
int todoIguais(Conjunto p1, Conjunto p2);


// (c) Insere
Conjunto inserir(Conjunto p, int valor);


// (d) Remove
Conjunto remover(Conjunto p, int valor);

// (h) Menor valor
int menor(Conjunto p);


// (i) Maior valor
int maior(Conjunto p);


