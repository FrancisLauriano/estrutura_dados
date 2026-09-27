#include <stdlib.h>
#include "musica.h"
#include "lista.h"


struct elem{
    Musica music;
    struct elem *prox;
};

typedef struct elem *Elem;

struct lista{
    int qtd;
    Elem inicio;
};


// liberar/destruir a lista
void destruirLista(Lista li){
    if(li != NULL){
        while(li -> qtd > 0){
            removerPrimeira(li);
        }

        free(li);

    }
}

// consultar a primeira
Musica consultarPrimeiraMusica(Lista li){
    if(li != NULL && li -> qtd > 0){
        return li -> inicio -> music;

    }

    return NULL;
}

// consultar por posição
Musica consultarPorPosicao(Lista li, int pos){

    if(li != NULL && li -> qtd > 0 && pos >= 0 && pos < li -> qtd){
        if(pos == 0){
            return consultarPrimeiraMusica(li);
        }

        int i = 0;
        Elem aux = li -> inicio;

        while(i < pos){
            aux = aux -> prox;
            i += 1;
        }

        return aux -> music;
    }

    return NULL;
}

// remover por posição
int removerPorPosicao(Lista li, int pos){
    if(li != NULL && pos >= 0 && pos < li -> qtd){
        if(pos == 0){
            return removerPrimeira(li);
            
        }

        int i = 0;
        Elem aux = li -> inicio;

        while(i < pos - 1){
            aux = aux -> prox;
            i += 1;
        }

        Elem remover = aux -> prox;
        aux -> prox = remover -> prox;
        destruirMusica(remover -> music);
        free(remover);
        li -> qtd -= 1;

        return 1;

    }
    return 0;
}

// remover a última
int removerUltima(Lista li){
    if(li != NULL && li -> qtd != 0){

        if(li -> qtd == 1){
            destruirMusica(li -> inicio -> music);
            free(li -> inicio);
            li -> inicio = NULL;
            li -> qtd = 0;
            return 1;
        }

        Elem aux = li -> inicio;
        Elem ant;

        while(aux -> prox != NULL){
            ant = aux;
            aux = aux -> prox;
        }

        ant -> prox = NULL;
        li -> qtd -= 1;

        destruirMusica(aux -> music);
        free(aux);
        return 1;

    }

    return 0;
}

// remover a primeira
int removerPrimeira(Lista li){
    if(li != NULL && li -> qtd != 0){
        Elem aux = li -> inicio;
        li -> inicio = li -> inicio -> prox;
        li -> qtd -= 1;

        destruirMusica(aux -> music);
        free(aux);
        return 1;

    }
    return 0;
}

// inserir por posição
int inserirPorPosicao(Lista li, Musica m, int pos){
    if(li != NULL && m != NULL && pos >= 0 && pos <= li -> qtd){
        Elem no = malloc(sizeof(struct elem));

        if(no != NULL){
            no -> music = m;

            if(pos == 0){
                no -> prox = li -> inicio;
                li -> inicio = no;
                li -> qtd += 1;
                return 1;
            }

            int i = 0;
            Elem aux = li -> inicio;

            while(i < pos - 1){
                aux =  aux -> prox;
                i += 1;
            }

            no -> prox = aux -> prox;
            aux -> prox = no;

            li -> qtd += 1;
            return 1;

        }

    }
    return 0;
}

// inserir no final
int inserirFinal(Lista li, Musica m){
    if(li != NULL && m != NULL){
        Elem no = malloc(sizeof(struct elem));

        if(no != NULL){
            no -> music = m;
            no -> prox = NULL;

            if(li -> qtd == 0){
                li -> qtd += 1;
                li -> inicio = no;
                return 1;
            }

            Elem aux;
            aux = li -> inicio;

            while(aux -> prox != NULL){
                aux = aux -> prox;

            }

            aux -> prox = no;
            li -> qtd += 1;
            return 1;
        }

    }
    return 0;
}

// inserir no início
int inserirInicio(Lista li, Musica m){
    if(li != NULL && m != NULL){
        Elem no = malloc(sizeof(struct elem));

        if(no != NULL){
            no -> music = m;
            no -> prox = li -> inicio;
            li -> qtd += 1;
            li -> inicio = no;
            return 1;
        }

    }

    return 0;
}

// consultar a quantidade de músicas na lista
int qtdMusicas(Lista li){
    if(li != NULL){
        return li -> qtd;

    }

    return -1;
}

// criar a lista
Lista criarLista(){
    Lista li = malloc(sizeof(struct lista));

    if(li != NULL){
        li -> qtd = 0;
        li -> inicio = NULL;

    }

    return li;
}










