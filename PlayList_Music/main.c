#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"
#include "lista.h"

// adiciona_musica: adicionar uma música ao final da playlist
void adiciona_musica(Lista li, Musica m){
    if(inserirFinal(li, m)){
        printf("Musica adicionada\n");
        return;
    }
    printf("Nao foi possivel adicionar musica\n");
}

// adiciona_musica_posicao: adicionar uma música em uma posição específica da playlist
void adiciona_musica_posicao(Lista li, Musica m, int pos){
    if(inserirPorPosicao(li, m, pos)){
        printf("Musica adicionada na posicao %d\n", pos);
        return;

    }

    printf("Nao foi possivel adicionar musica na posicao desejada\n");
}


// remove_musica: remover uma música de uma posição específica da playlist
void remove_musica(Lista li, int pos){
    if(removerPorPosicao(li, pos)){
        printf("Musica removida na posicao %d\n", pos);
        return;
    }

    printf("Nao foi possivel remover musica na posicao desejada\n");
}


// tempo_restante: calcular e informar o tempo total restante para o fim da playlist
int tempo_restante(Lista li, int proximaMusica){

    if(li != NULL){
        int soma = 0;
        int i = proximaMusica;
        while(i < qtdMusicas(li)){
            Musica m = consultarPorPosicao(li, i);
            soma += consultarDuracao(m);
            i += 1;
            
        }

        return soma;
    }

    return 0;
}

// play: "tocar" a próxima música da playlist, exibindo seus dados e avançando para a próxima posição
void play(Lista li, int *proximaMusica){
    if(li != NULL){
        Musica m = consultarPorPosicao(li, *proximaMusica);

        if(m != NULL){
            imprimirDados(m);
            *proximaMusica += 1;
            return;
        }
      
    }
    printf("Nao ha proxima musica para reproduzir\n");

}

// musicas_reproduzidas: informar quantas músicas da playlist já foram "tocadas"
void musicas_reproduzidas(int proximaMusica){
    printf("Foram reproduzida %d musicas\n", proximaMusica);
}


int main(){
    

    Lista li = criarLista();

    if(li != NULL){
        // crie 10 músicas diretamente no código e utilize as funções implementadas para simular o funcionamento da playlist
        
        int proximaMusica = 0;

        // criando 10 musicas com duracao em segundos
        Musica m1 = criarMusica("Musica 1", "Artista 1", 180);
        Musica m2 = criarMusica("Musica 2", "Artista 2", 200);
        Musica m3 = criarMusica("Musica 3", "Artista 3", 240);
        Musica m4 = criarMusica("Musica 4", "Artista 4", 190);
        Musica m5 = criarMusica("Musica 5", "Artista 5", 210);
        Musica m6 = criarMusica("Musica 6", "Artista 6", 230);
        Musica m7 = criarMusica("Musica 7", "Artista 7", 170);
        Musica m8 = criarMusica("Musica 8", "Artista 8", 250);
        Musica m9 = criarMusica("Musica 9", "Artista 9", 220);
        Musica m10 = criarMusica("Musica 10", "Artista 10", 195);

        // adicionando as musicas na playlist 
        adiciona_musica(li, m1);
        adiciona_musica(li, m2);
        adiciona_musica(li, m3);
        adiciona_musica(li, m4);
        adiciona_musica(li, m5);
        adiciona_musica(li, m6);
        adiciona_musica(li, m7);
        adiciona_musica(li, m8);
        adiciona_musica(li, m9);
        adiciona_musica(li, m10);

        // remover musica posicao 4
        remove_musica(li, 4);

        // adicionar na posicao 2
        Musica m11 = criarMusica("Musica 11", "Artista 11", 190);
        adiciona_musica_posicao(li, m11, 2);


        // tocando playlist
        printf("===== PLAYLIST =====\n");
        play(li, &proximaMusica);
        play(li, &proximaMusica);
        play(li, &proximaMusica);


        // qtd de musicas reproduzidas
        printf("===== QTD MUSICAS REPRODUZIDAS =====\n");
        musicas_reproduzidas(proximaMusica);

        // tempo restante
        printf("===== TEMPO RESTANTE =====\n");
        printf("%d segundos\n", tempo_restante(li, proximaMusica));


        printf("\n");

        // a quantidade de músicas presentes na playlist
        printf("Quantidade de musicas presentes na playlist: %d\n", qtdMusicas(li));


        // a posição da próxima música a ser reproduzida
        printf("Posicao da proxima musica a ser reproduzida: %d\n", proximaMusica);


    }

    
    destruirLista(li);

    return 0;
}