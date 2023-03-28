#include <stdio.h>
#include <stdlib.h>

typedef struct tLista{
    struct tElemento* inicio;
    int quantidade;
} tLista;

typedef struct tElemento{
    char musica;
    struct tElemento* proximo;
} tElemento;

tLista *inicializa() {
    struct tLista * playlist;
    playlist = malloc(sizeof(tLista));
    playlist -> inicio = NULL;
    playlist -> quantidade = 0;

    return playlist;
}

void insereFinal (tLista *playlist, char dado) {
    //alocando uma região de memória
    tElemento *aux;
    tElemento *novoElemento = malloc(sizeof(tElemento));
    novoElemento -> musica = dado;
    novoElemento -> proximo = NULL;
    if(playlist -> inicio == NULL) {
        //se a playlist estiver vazia ela aponta para o novo elemento
        playlist -> inicio = novoElemento;
        playlist -> quantidade++;
    } else {
        aux = playlist -> inicio;

        while(aux != NULL) {
            aux = aux -> proximo;
        }
        aux->proximo = novoElemento;
        playlist->quantidade++;
    }
}

void mostrar(tLista *lista) {
    tElemento *aux;
    aux = lista -> inicio;
    if (aux -> proximo == NULL){
        printf("Erro - lista vazia");
    } else {
        while (aux != NULL) {
            printf("%c\n", aux -> musica);
            aux=aux->proximo;
        }
    }
}

void inserePosicao(tLista *playlist, int posicao, char dado){
    int numeroElemento = 0;
    tElemento *aux;
    tElemento *novoElemento = malloc(sizeof(tElemento));
    novoElemento->musica=dado;
    novoElemento->proximo=NULL;

    if (playlist->inicio == NULL || posicao == 0){
        novoElemento->proximo=playlist->inicio;
        playlist->inicio = novoElemento;
    } else {
        aux = playlist->inicio;
        numeroElemento = 0;

        while(aux->proximo != NULL && numeroElemento != posicao){
            //auxiliar anda
            aux=aux->proximo;
            numeroElemento++;
        }
        aux->proximo = novoElemento;
    }
    playlist->quantidade++;
}

int main()
{
    tLista *playlist;
    playlist = inicializa();

    insereFinal(playlist, 'A');
    insereFinal(playlist, 'B');
    insereFinal(playlist, 'C');

    mostrar(playlist);

    return 0;
}
