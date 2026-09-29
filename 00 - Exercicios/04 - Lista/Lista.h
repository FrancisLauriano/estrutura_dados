typedef struct lista *Lista;


// cria_lista
Lista criarLista();

// lista_vazia
int listaVazia(Lista li);

// tamanho_lista
int tamanhoLista(Lista li);


// insere_inicio
int inserirInicio(Lista li, int valor);


// insere_final 
int inserirFinal(Lista li, int valor);


// remove_inicio
int removerInicio(Lista li);


// remove_final
int removerFinal(Lista li);

// imprime_lista
void imprimirLista(Lista li);


// imprime_lista_reverso
void imprimirListaReverso(Lista li);


// busca_valor e retorna o indice
int buscarValor(Lista li, int valor);

// consulta_lista_posicao
int consultaListaPosicao(Lista li, int pos);

// libera_lista
void liberarLista(Lista li);
