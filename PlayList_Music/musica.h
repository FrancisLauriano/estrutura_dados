#define TAM_MUSIC 100

typedef struct musica *Musica;


// criar uma música
Musica criarMusica(char tit[], char art[], int dur);

// consultar seus dados - titulo
char *consultarTitulo(Musica m);


// consultar seus dados - artista
char *consultarArtista(Musica m);


// consultar seus dados - duracao
int consultarDuracao(Musica m);


// imprimir seus dados
void imprimirDados(Musica m);


// liberar/destruir a música
void destruirMusica(Musica m);