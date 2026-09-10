#include <stdlib.h>
#include "conjunto.h"

struct conjunto{
    int num[TAM];
    int qtd;
};

// criar conjunto
Conjunto criar(int v[], int qtd){

    Conjunto p = malloc(sizeof(struct conjunto));
    int i;

    if(p != NULL){
        p -> qtd = qtd;

        for(i = 0; i < qtd; i += 1){
            p -> num[i] = v[i];
        }
    }
    return p;
}


// (b) Cria um conjunto vazio
Conjunto criarVazio(){

    Conjunto p = malloc(sizeof(struct conjunto));

    if(p != NULL){
        p -> qtd = 0;
    }

    return p;
}


// (l) Testa se o conjunto é vazio
int verVazio(Conjunto p){
    if(p -> qtd == 0){
        return 1;
    }

    return 0;
}

// (k) Tamanho
int tamanho(Conjunto p){
    return p -> qtd;

}

// destruir conjunto
void destruir(Conjunto p){
    if(p != NULL){
        free(p);
    }
}



// repeticao
int repeticao(int v[], int qtd, int valor){
    int i;

    for(i = 0; i < qtd; i += 1){
        if(v[i] == valor){
            return 1;
        }
    }
    return 0;
}


// (g) Testa se um número pertence ao conjunto
int pertence(Conjunto p, int valor){
    return repeticao(p -> num, p -> qtd, valor);

}


// (a) União
Conjunto uniao(Conjunto p1, Conjunto p2){
    int v[TAM], k = 0;
    int i;

    for(i = 0; i < p1 -> qtd; i += 1){
        if(!repeticao(v, k, p1 -> num[i])){
            v[k] = p1 -> num[i];
            k += 1;
        }
    }

    for(i = 0; i < p2 -> qtd; i += 1){
        if(!repeticao(v, k, p2 -> num[i])){
            v[k] = p2 -> num[i];
            k += 1;
        }
    }

    return criar(v, k);
}


// (e) Interseção
Conjunto intersecao(Conjunto p1, Conjunto p2){
    int v[TAM];
    int i, k = 0;

    for(i = 0; i < p1 -> qtd; i += 1){
        if(pertence(p2, p1 -> num[i])){
            if(!repeticao(v, k, p1 -> num[i])){
                v[k] = p1 -> num[i];
                k += 1;
            }
        }

    }
    return criar(v, k);
}



// (f) Diferença
Conjunto diferenca(Conjunto p1, Conjunto p2){
    int v[TAM];
    int i, k = 0;

    for(i = 0; i < p1 -> qtd; i += 1){
        if(!pertence(p2, p1 -> num[i])){
            if(!repeticao(v, k, p1 -> num[i])){
                v[k] = p1 -> num[i];
            }
        }
    }

    return criar(v, k);
}

// int pertence(Conjunto p, int valor)
// int repeticao(int v[], int qtd, int valor)


// (j) Testa se os conjuntos são iguais
int todoIguais(Conjunto p1, Conjunto p2){
    int i;

    for(i = 0; i < p1 -> qtd; i += 1){
        if(!pertence(p2, p1 -> num[i])){
            return 0;
        }
    }

    for(i = 0; i < p2 -> qtd; i += 1){
        if(!pertence(p1, p2 -> num[i])){
            return 0;
        }
    }
    return 1;
}


// (c) Insere
Conjunto inserir(Conjunto p, int valor){
    if(p != NULL){
        p -> num[p -> qtd] = valor;
        p -> qtd += 1;
    }
    return p;
}



// (d) Remove
Conjunto remover(Conjunto p, int valor){
    int i, j;

    if(p != NULL){
        for(i = 0; i < p -> qtd; i += 1){
            if(p -> num[i] == valor){
                for(j = i; j < p -> qtd -1; j += 1){
                    p -> num[j] = p -> num[j + 1];
                }

                p -> qtd -= 1;
            }
        }
    }
    return p;
}


// (h) Menor valor
int menor(Conjunto p){
    int i, menor = 0;

    for(i = 1; i < p -> qtd; i += 1){
        if(p -> num[i] < p -> num[menor]){
            menor = i;
        }

    }
    return p -> num[menor];
}


// (i) Maior valor
int maior(Conjunto p){
    int i, maior = 0;

    for(i = 1; i < p -> qtd; i += 1){
        if(p -> num[i] > p -> num[maior]){
            maior = i;
        }
    }
    return p -> num[maior];
}



