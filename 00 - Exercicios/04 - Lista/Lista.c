// 5.  Implemente uma lista unicamente encadeada, que deve conter os métodos: 
// cria_lista, libera_lista, lista_vazia, tamanho_lista, insere_inicio, insere_final, 
// remove_inicio, remove_final, imprime_lista, imprime_lista_reverso, busca_valor, 
// consulta_lista_posicao.

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct elem{
    int valor;
    struct elem *prox;
};

typedef struct elem *Elem;

struct lista{
    int qtd;
    Elem inicio;
};

// cria_lista
Lista criarLista(){
    Lista li = malloc(sizeof(struct lista));

    if(li != NULL){
        li -> qtd = 0;
        li -> inicio = NULL;
    }

    return li;
}

// acessar inicio na lista
int acessarInicio(Lista li){
    if(li != NULL){
        li -> inicio -> valor;
    }
    return 0;
}

// lista_vazia
int listaVazia(Lista li){
    if(li != NULL){
        if(li -> qtd == 0){
            return 1;
        }

        return 0;
    }

    return 0;
}

// tamanho_lista
int tamanhoLista(Lista li){
    if(li != NULL){
        return li -> qtd;
    }

    return -1;
}



// insere_inicio
int inserirInicio(Lista li, int valor){
    if(li != NULL){
        Elem no = malloc(sizeof(struct elem));

        if(no != NULL){
            no -> valor = valor;
            no -> prox = li -> inicio;
            li -> inicio = no;
            li -> qtd += 1;
            return 1;
        }

    }

    return 0;
}



// insere_final 
int inserirFinal(Lista li, int valor){
    if(li != NULL){
        Elem no = malloc(sizeof(struct elem));

        if(no != NULL){
            no -> valor = valor;
            no -> prox = NULL;

            if(li -> qtd == 0){
                li -> inicio = no;
                li -> qtd += 1;
                return 1;
            }

            Elem aux = li -> inicio;

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



// remove_inicio
int removerInicio(Lista li){
    if(li != NULL && li -> qtd != 0){
        Elem no = li -> inicio;
        li -> inicio = no -> prox;
        li -> qtd -= 1;
        free(no);
        return 1;
    }

    return 0;
}


// remove_final
int removerFinal(Lista li){
    if(li != NULL && li -> qtd != 0){
        Elem no = li -> inicio;

        if(li -> qtd == 1){
            free(no);
            li -> inicio = NULL;
            li -> qtd -= 1;
            return 1;
        }

        Elem ant;

        while(no -> prox != NULL){
            ant = no;
            no = no -> prox;
        }

        ant -> prox = NULL;
        free(no);
        li -> qtd -= 1;
        return 1;

    }

    return 0;
}

// imprime_lista
void imprimirLista(Lista li){
    if(li != NULL && li -> qtd != 0){
        Elem no = li -> inicio;

        int i = 1;
        while(no != NULL){
            printf("%dº Valor: %d\n", i, no -> valor);
            no = no -> prox;
            i += 1;
        }
    }
}


// imprime_lista_reverso
void imprimirListaReverso(Lista li){
    if(li != NULL && li -> qtd != 0){
        int i = li -> qtd -1;

        while(i >= 0){
            printf("%iº valor: %d\n", i + 1, consultaListaPosicao(li, i));
            i -= 1;
        }

    }

}



// busca_valor
int buscarValor(Lista li, int valor){
    if(li != NULL && li -> qtd != 0){
        Elem aux = li -> inicio;

        int i = 0;
        while(aux != NULL){
            if(aux -> valor == valor){
                return i;
            }
            aux = aux -> prox;
            i += 1;
        }
    }

    return -1;
}

// consulta_lista_posicao
int consultaListaPosicao(Lista li, int pos){
    if(li != NULL && pos >= 0 && pos < li -> qtd){

        if(pos == 0){
            return li -> inicio -> valor;
        }
    
        int i = 0;
        Elem aux = li -> inicio;

        while(i < pos){
            aux = aux -> prox;
            i += 1;
        }
        return aux -> valor;

    }

    return 0;
}


// libera_lista
void liberarLista(Lista li){
    if(li != NULL){
        while(li -> qtd != 0){
            removerInicio(li);
        }
        free(li);

    }
}


// 6. Faça um programa que possua uma lista que armazene números inteiros.
// O programa deve executar os seguintes passos:

//    (a) Inserir os seguintes valores na lista: 1, 0, 5, -2, -5, 7.  
void inserir(){
    Lista li = criarLista();

    inserirFinal(li, 1);
    inserirFinal(li, 0);
    inserirFinal(li, 5);
    inserirFinal(li, -2);
    inserirFinal(li, -5);
    inserirFinal(li, 7);
}
//    (b) Calcular a soma entre o primeiro, o segundo e o último elemento da lista.  
int soma(Lista li){
    Lista li = criarLista();

    inserirFinal(li, 1);
    inserirFinal(li, 0);
    inserirFinal(li, 5);
    inserirFinal(li, -2);
    inserirFinal(li, -5);
    inserirFinal(li, 7);

    if(li != 0){
        int n1 = consultaListaPosicao(li, 0);
        int n2 = consultaListaPosicao(li, 1);
        int nUltimo = consultaListaPosicao(li, tamanhoLista(li) - 1);
        
        return n1 + n2 + nUltimo;

    }

    return 0;
}

//    (c) Modificar um elemento da lista.  
int modificarElemento(Lista li, int pos, int novoValor){
    if(li != NULL && tamanhoLista(li) != 0 && pos >= 0 && pos < tamanhoLista(li)){
        if(pos == 0){
            li -> inicio -> valor = novoValor;
            return 1;
        }

        Elem aux = li -> inicio;
        int qtd = 0;

        while(qtd < pos){
            aux = aux -> prox;
            qtd += 1;
        }

        aux -> valor = novoValor;
        return 1;

    }

    return 0;
}


//    (d) Imprimir todos os valores da lista.
void imprimirTodaLista(Lista li){
    if(li != NULL && li -> qtd != 0){
        Elem no = li -> inicio;

        int i = 1;
        while(no != NULL){
            printf("%dº Valor: %d\n", i, no -> valor);
            no = no -> prox;
            i += 1;
        }
    }
}


// 7. Crie um programa que leia valores inteiros e armazene em uma lista encadeada. 
// Em seguida, mostre na tela os valores lidos.
int main(){

    Lista li = criarLista();

    if(li != NULL){
        int i;
        int valor;
        for(i = 0; i < 5; i += 1){
            printf("Informe o %d° valor inteiro: ", i + 1);
            scanf("%d", &valor);
            inserirFinal(li, valor);

        }

        imprimirLista(li);

    }

    liberarLista(li);

    return 0;
}



// 8. Ler um conjunto de números reais, armazenando-os em uma lista encadeada
// e calcular o quadrado de cada elemento, armazenando o resultado em outra lista. 
// Imprimir ambas as listas.
struct elem2{
    double valor;
    struct elem2 *prox;
};

typedef struct elem2 *Elem2;

struct lista2{
    int qtd;
    Elem2 inicio;
};

typedef struct lista2 *Lista2;

Lista2 criarLista2(){
    Lista2 li = malloc(sizeof(struct lista2));

    if(li != NULL){
        li -> qtd = 0;
        li -> inicio = NULL;
    }

    return li;
}
// insere_final2 
int inserirFinal2(Lista2 li, double valor){
    if(li != NULL){
        Elem2 no = malloc(sizeof(struct elem2));

        if(no != NULL){
            no -> valor = valor;
            no -> prox = NULL;

            if(li -> qtd == 0){
                li -> inicio = no;
                li -> qtd += 1;
                return 1;
            }

            Elem2 aux = li -> inicio;

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

// tamanho_lista2
int tamanhoList2(Lista2 li){
    if(li != NULL){
        return li -> qtd;
    }

    return -1;
}

// consulta_lista_posicao2
double consultaListaPosicao2(Lista2 li, int pos){
    if(li != NULL && pos >= 0 && pos < li -> qtd){

        if(pos == 0){
            return li -> inicio -> valor;
        }
    
        int i = 0;
        Elem2 aux = li -> inicio;

        while(i < pos){
            aux = aux -> prox;
            i += 1;
        }
        return aux -> valor;

    }

    return 0;
}

void imprimirTodaLista2(Lista2 li){
    if(li != NULL && li -> qtd != 0){
        Elem2 no = li -> inicio;

        int i = 1;
        while(no != NULL){
            printf("%dº Valor: %lf\n", i, no -> valor);
            no = no -> prox;
            i += 1;
        }
    }
}

// remove_inicio
int removerInicio2(Lista2 li){
    if(li != NULL && li -> qtd != 0){
        Elem2 no = li -> inicio;
        li -> inicio = no -> prox;
        li -> qtd -= 1;
        free(no);
        return 1;
    }

    return 0;
}


// libera_lista
void liberarLista2(Lista2 li){
    if(li != NULL){
        while(li -> qtd != 0){
            removerInicio2(li);
        }
        free(li);

    }
}


#define TAM 5
void questaoOito(){
    Lista2 li1 = criarLista2();

    if(li1 != NULL){
        int i;
        double valor;
        for(i = 0; i < TAM; i += 1){
            printf("Informe o %dº valor: ", i + 1);
            scanf("%lf", &valor);
            inserirFinal2(li1, valor);
        }

        Lista2 li2 = criarLista2();
        double valor2;
        double quadrado;

        if(li2 != NULL){

            int i = 0;
            while(i < tamanhoList2(li1)){
                valor2 = consultaListaPosicao2(li1, i);
                quadrado = valor2 * valor2;
                inserirFinal2(li2, quadrado);
                i += 1;
            }

        imprimirTodaLista2(li1);
        imprimirTodaLista2(li2);  

        liberarLista2(li2);
        }
    }
    liberarLista2(li1);
    
}

// 9. Faça um programa que leia uma lista e, em seguida, leia duas posições X e Y. 
// Ao final, o programa deverá escrever a soma dos valores encontrados nessas posições.
void questaoNove(){
    Lista li = criarLista();

    if(li != NULL){
        int continuar = 1;
        int valor;

        while(continuar){
            printf("Informe um valor da lista: ");
            scanf("%d", &valor);
            inserirFinal(li, valor);

            printf("Continuar inserindo valores na lista?\n1. SIM\t0. NAO\n");
            scanf("%d", &continuar);

        }

        int x, y, valorX, valorY, soma;

        if(tamanhoLista(li) >= 2){

            printf("Informe a posicao X: ");
            scanf("%d", &x);

            printf("Informe a posicao Y: ");
            scanf("%d", &y);

            if(x >= 0 && x < tamanhoLista(li) && y >= 0 && y < tamanhoLista(li)){

                valorX = consultaListaPosicao(li, x);
                valorY = consultaListaPosicao(li, y);

                soma = valorX + valorY;
                printf("Soma: %d\n", soma);
            }else{
                printf("Posicao invalida.\n");
            }
        }else{

            printf("A lista deve possuir pelo menos 2 elementos.\n");
        }

        liberarLista(li);
        return;
    }

    printf("Erro ao criar lista.\n");
}

// 10. Faça um programa que leia uma lista de valores inteiros. 
// Em seguida, deverá contar e escrever quantos valores negativos ela possui.
void questaoDez(Lista li){

    if(li != NULL){
        int valor, qtd = 0, i = 0;

        while(i < tamanhoLista(li)){
            valor = consultaListaPosicao(li, i);
            if(valor < 0){
                qtd += 1;
            }
            i += 1;
        }

        printf("A lista tem %d valores negativos\n", qtd);
        return;

    }

    printf("Erro na lista\n");
}


// 11. Faça um programa que receba uma lista de inteiros. 
// Em seguida, deverá ser impresso o maior e o menor elemento da lista.
void maiorEMenor(Lista li){
    if(li != NULL && tamanhoLista(li) != 0){
        int menor = acessarInicio(li);
        int maior = acessarInicio(li);
        int valor, i = 1;

        while(i < tamanhoLista(li)){
            valor = consultaListaPosicao(li, i);
            if(valor < menor){
                menor = valor;
            }

            if(valor > maior){
                maior = valor;

            }

            i += 1;

        }
        
        printf("Maior valor da lista: %d\n", maior);
        printf("menor valor da lista: %d\n", menor);
        return;

    }

    printf("Erro na lista\n");
}
