#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 100

struct conjuto{
    int num[TAM];
    int qtd;
};


typedef struct conjuto Conjunto;

// criar conjunto
Conjunto *criar(int n[], int qtd){
    Conjunto *c = malloc(sizeof(Conjunto));
    int i;

    if(c != NULL){
        c -> qtd = qtd;

        for(i = 0; i < qtd; i += 1){
            c -> num[i] = n[i];
        }
    }

    return c;
}

// (b) Cria um conjunto vazio
Conjunto *criarVazio(){
    Conjunto *c = malloc(sizeof(Conjunto));

    if(c != NULL){
        c -> qtd = 0;
    }

    return c;
}

// repetido
int repetido(int v[], int qtd, int valor){
    int i;

    for(i = 0; i < qtd; i += 1){
        if(v[i] == valor){
            return 1;
        }
    }
    return 0;
}


// pertence
// (g) Testa se um número pertence ao conjunto
int pertence(Conjunto *c, int valor){
    return repetido(c -> num, c -> qtd, valor);
}


// (a) União
Conjunto *uniao(Conjunto *c1, Conjunto *c2){
    int v3[TAM], i, l = 0;

    for(i = 0; i < c1 -> qtd; i += 1){

        if(!repetido(v3, l, c1 -> num[i])){
            v3[l] = c1 -> num[i];
            l += 1;
        }
    }

    for(i = 0; i < c2 -> qtd; i+= 1){

        if(!repetido(v3, l, c2 -> num[i])){
            v3[l] = c2 -> num[i];
            l += 1;

        }
    }

    return criar(v3, l);
}



// (e) Interseção
Conjunto *intersecao(Conjunto *c1, Conjunto *c2){
    int v3[TAM], i, j = 0;

    for(i = 0; i < c1 -> qtd; i += 1){

        if(pertence(c2, c1 -> num[i])){

            if(!repetido(v3, j, c1 -> num[i])){
                v3[j] = c1 -> num[i];
                j += 1;
            }
        }
    }

    return criar(v3, j);
}



// (f) Diferença
Conjunto *diferenca(Conjunto *c1, Conjunto *c2){
    int v3[TAM], i, j = 0;

    for(i = 0; i < c1 -> qtd; i += 1){
        if(!pertence(c2, c1 -> num[i])){
            if(!repetido(v3, j, c1 -> num[i])){
                v3[j] = c1 -> num[i];
                j += 1;
            }
        }
    }


    return criar(v3, j);
}



// (c) Insere
int inserir(Conjunto *c, int valor){
    int tam;
    tam = c -> qtd;

    if(tam >= TAM){
        return 0;
    }

    c -> num[tam] = valor;
    c -> qtd += 1;
    return 1;
}


// (d) Remove --> remove a primeira ocorrencia
int remover(Conjunto *c, int valor){
    int qtdV, i, j;
    qtdV = c -> qtd;

    if(qtdV <= 0){
        return -1;
    }

    for(i = 0; i < qtdV; i += 1){
        if(c -> num[i] == valor){

            for(j = i; j < qtdV - 1; j += 1){
                c -> num[j] = c -> num[j + 1]; 
            }

            c -> qtd -= 1;
            return 1;
        }

    }

    return -1;
}

// (h) Menor valor
int menor(Conjunto *c){
    int menor, i;
    menor = 0;

    if(ehVazio(c)){
       return 0;
    }

    for(i = 1; i < c -> qtd; i += 1){
        if(c -> num[menor] > c -> num[i]){
            menor = i;
        }
    }

    return c -> num[menor];
}


// (i) Maior valor
int maior(Conjunto *c){
    int maior, i;
    maior = 0;

    if(ehVazio(c)){
       return 0;
    }

    for(i = 1; i < c -> qtd; i += 1){
        if(c -> num[maior] < c -> num[i]){
            maior = i;
        }
    }
    return c -> num[maior];
}

// (j) Testa se os conjuntos são iguais
_Bool ehIgual(Conjunto *c1, Conjunto *c2){
    int i;

    for(i = 0; i < c1 -> qtd; i += 1){
        if(!pertence(c2, c1 -> num[i])){
            return false;
        }
    }

    
    for(i = 0; i < c2 -> qtd; i += 1){
        if(!pertence(c1, c2 -> num[i])){
            return false; 
        }

    }

    return true;
}

// (k) Tamanho
int tamanho(Conjunto *c){
    return c -> qtd - 1;

}

// (l) Testa se o conjunto é vazio
_Bool ehVazio(Conjunto *c){
    if(c -> qtd == 0){
        return true;
    }

    return false;
}

// detruir 
void destruir(Conjunto *c){
    if(c != NULL){
        free(c);
    }
}