/*
Maria Paula Ferreira Maia
Matrícula: 20232010327
Polyana Melissa Teixeira Neves
Matrícula: 20232017408
*/

#include "fila.h"

Fila fila_cria() {
    Fila l;
    l.inicio = (No *) malloc(sizeof(No));

    l.inicio->prox = NULL;
    l.fim = l.inicio;

    return l;
}

int fila_vazia(Fila *l) {
    return l->fim == l->inicio;
}

void fila_insere_final(Fila *l, No generico) {
    No *aux = (No *) malloc(sizeof(No));
    
    strcpy(aux->nome, generico.nome);
    strcpy(aux->curso, generico.curso);
    //aux.data = generico.data;
    aux->matricula = generico.matricula;
    aux->saldo = generico.saldo;


    //faz prox do fim apontar para aux, prox do aux apontar para NULL e fim apontar para aux
    l->fim->prox = aux;
    aux->prox = NULL;
    l->fim = aux;
}

// int lista_remove(Lista *l, No *atual) {
//     int removeu = 0;
//     No *aux = l->inicio->prox;

//     //pesquisa ate que o prox do aux aponte para o atual
//     while(aux->prox != atual && aux->prox != NULL)
//         aux = aux->prox;

//     if(aux->prox == atual) {
//         //prox do aux aponta para o prox do aux, isolando o atual da lista
//         aux->prox = atual->prox;

//         //desaloca o atual
//         free(atual);
//         atual = NULL;

//         removeu = 1;
//     }

//     return removeu;
// }

void fila_imprime(Fila *l) {
    No *aux = l->inicio->prox;

    while(aux != NULL) {
        printf("%s\n %s\n %d\n  %lf\n", aux->nome, aux->curso, aux->matricula, aux->saldo);

        aux = aux->prox;
    }
    printf("\n");
}