typedef struct venda *Venda;

// criar uma venda;
Venda criarVenda(int cod, double valor, int qtd);

// consultar seus dados - codProduto:
int consultarCodProduto(Venda v);

// consultar seus dados - valor:
double consultarValor(Venda v);

// consultar seus dados - qtd:
int consultarQtd(Venda v);

// imprimir seus dados;
void imprimirVenda(Venda v);

// liberar uma venda.
void liberarVenda(Venda v);
