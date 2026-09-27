#include <stdio.h>
#include <stdlib.h>


// elemento
struct elem{
    int valor;
    struct elem* prox;
};

typedef struct elem Elem;





// lista 
struct lista{
    int qtd; // nao pode ser negativo: unsigned int
    Elem* inicio;
};

typedef struct lista *Lista;



// criar lista encadeada
Lista CriarLista(){
    Lista li = malloc(sizeof(struct lista));

    if(li != NULL){
        li -> qtd = 0;
        li -> inicio = NULL;
    }
    return li;
}


// verificar se lista vazia
int listaVazia(Lista li){
    if(li != NULL && li -> inicio == NULL){
        return 1;
    }

    return 0;
}

// inserir final
int inserirFinal(Lista li, int valor){
    if(li != NULL){
        Elem* no = malloc(sizeof(Elem));

        if(no == NULL){
            return 0;
        }

        no -> valor = valor;
        no -> prox = NULL;
    
        if(li -> inicio == NULL){
            li -> qtd += 1;
            li -> inicio = no;
            return 1;
        }

        Elem* aux = li -> inicio;

        while(aux -> prox != NULL){
            aux = aux -> prox;
        }

        aux -> prox = no;
        li -> qtd += 1;
        return 1;
        
    }

    return 0;
}



// inserir no inicio
int inserirInicio(Lista li, int valor){
    if(li != NULL){
        Elem* no = malloc(sizeof(Elem));

        if(no == NULL){
            return 0;
        }

        no -> valor = valor;
        no -> prox = li -> inicio;
        li -> inicio = no;
        li -> qtd += 1;
        return 1;
        
    }
    return 0;
}




// acessar inicio
int acessarInicio(Lista li){
    if(li != NULL && li -> inicio != NULL){
        return li -> inicio -> valor;

    }
    return 0;
}



// acessar final
int acessarFinal(Lista li){
    if(li != NULL && li -> inicio != NULL){
        Elem* aux = li -> inicio;
        
        while(aux -> prox != NULL){
            aux = aux -> prox;
        }

        return aux -> valor;
        
    }

    return 0;
}



// buscar por valor
int buscarPorValor(Lista li, int valor){
    if(li != NULL && li -> inicio != NULL && li -> qtd > 0){
        Elem* aux = li -> inicio;

        while(aux != NULL){
            if(aux -> valor == valor){
                return aux -> valor;
            }
            aux = aux -> prox;
        }

    }
    return 0;
}



// buscar por posicao
int buscarPorPosicao(Lista li, int posicao){
    if(li != NULL && posicao >= 0 && posicao < li -> qtd){
        int qtd = 0;

        Elem* aux = li -> inicio;

        while(posicao > qtd){
            qtd += 1;
            
            aux = aux -> prox;
        }
        return aux -> valor;
    }
    return 0;
}

// tamanho da lista
int tamanhoLista(Lista li){
    if(li != NULL){
        Elem* aux = li -> inicio;
        int qtd = 0;

        while(aux != NULL){
            aux = aux -> prox;
            qtd += 1;
        }
        return qtd;
    }
    return 0;
}

// tamanhho da lista
int tamanhoLista(Lista li){
    if(li != NULL){
        return li -> qtd;
    }
    return 0;
}

// remover inicio
int removerInicio(Lista li){
    if(li != NULL && li -> inicio != NULL && li -> qtd > 0){
        Elem* aux = li -> inicio;
        li -> inicio = aux -> prox;
        li -> qtd -= 1;
        free(aux);
        return 1;
    }

    return 0;
}



// remover final
int removerFinal(Lista li){
    if(li != NULL && li -> inicio != NULL && li -> qtd > 0){
        Elem* aux = li -> inicio;

        if(aux -> prox == NULL){
            free(aux);
            li -> inicio = NULL;
            li -> qtd -= 1;
            return 1;
        }

        Elem* ant;

        while(aux -> prox != NULL){
            ant = aux;
            aux = aux -> prox;
        }

        ant -> prox = NULL;
        free(aux);
        li -> qtd -= 1;
        return 1;
           
    }
    return 0;
}


// destruir
void destruir(Lista li){
    if(li != NULL){
        Elem* aux = li -> inicio;
        Elem* prox;

        while(aux != NULL){
            prox = aux -> prox;
            free(aux);
            aux = prox;
        }
        free(li);
    }

}

 