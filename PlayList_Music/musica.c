#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "musica.h"

struct musica{
    char titulo[TAM_MUSIC];
    char artista[TAM_MUSIC];
    int duracao;
};

// criar uma música
Musica criarMusica(char tit[], char art[], int dur){
    Musica m = malloc(sizeof(struct musica));

    if(m != NULL){
        strcpy(m -> titulo, tit);
        strcpy(m -> artista, art);
        m -> duracao = dur;
    }

    return m;
}


// consultar seus dados - titulo
char *consultarTitulo(Musica m){
    if(m != NULL){
        return m -> titulo;

    }
    return NULL;
}


// consultar seus dados - artista
char *consultarArtista(Musica m){
    if(m != NULL){
        return m -> artista;

    }

    return NULL;
}



// consultar seus dados - duracao
int consultarDuracao(Musica m){
    if(m != NULL){
        return m -> duracao;
    }

    return 0;
}


// imprimir seus dados
void imprimirDados(Musica m){
    if(m != NULL){
        printf("Titulo: %s\n", consultarTitulo(m));
        printf("Artista: %s\n", consultarArtista(m));
        printf("Duracao: %d\n", consultarDuracao(m));
    }
}


// liberar/destruir a música
void destruirMusica(Musica m){
    if(m != NULL){
        free(m);
    }
}