/*
Maria Paula Ferreira Maia
Matrícula: 20232010327
Polyana Melissa Teixeira Neves
Matrícula: 20232017408
*/

#include "fila.h"

Fila fila_cria() {
    Fila f; 
    f.inicio = (No*)malloc(sizeof(No));
    f.inicio->prox = NULL;
    f.fim = f.inicio;
    return f;
}

int fila_vazia(Fila *f) {
    return f->fim == f->inicio;
}

void fila_insere_final(Fila *f, char nome[], char curso[], char dia[], char mes[], char ano[], char matricula[], char saldo[]) {
    No *aux = (No *) malloc(sizeof(No));
    char data[11];
    data[0] = dia[0];
    data[1] = dia[1];
    data[2] = '/';
    data[3] = mes[0];
    data[4] = mes[1];
    data[5] = '/';
    data[6] = ano[0];
    data[7] = ano[1];
    data[8] = ano[2];
    data[9] = ano[3];
    data[10] = '\0';

    strcpy(aux->nome, nome);
    strcpy(aux->curso, curso);
    strcpy(aux->data, data);
    strcpy(aux->matricula, matricula);
    strcpy(aux->saldo, saldo);


    f->fim->prox = aux;
    aux->prox = NULL;
    f->fim = aux;
}

void fila_remove(Fila *f) {
    No *aux = f->inicio;

    aux->prox = aux->prox->prox;
    f->inicio->prox = aux->prox;
    free(aux);


}
void desenfileira_fila(Fila *f){
    No *aux = f->inicio;

    if(aux->prox == NULL){
        return;
    }

    while(aux->prox != NULL){
        aux->prox = aux->prox->prox;
    }
    desaloca_fila(f);

}

void desaloca_fila(Fila *f){
    No *aux = f->inicio->prox;
    if(aux != NULL)
        desenfileira_fila(f);
    free(aux);
    f = NULL;
}

void fila_imprime(Fila *f) {
    No *aux = f->inicio->prox;

    while(aux != NULL) {
    printf( "%s, %s, %s, %s, %s\n", aux->nome, aux->curso, aux->data, aux->matricula, aux->saldo);
        aux = aux->prox;
    }
    printf("\n");
}

void le_arquivo(Fila *fila, FILE *file){
    char nome[60], curso[30], dia[3], mes[3], ano[5], matricula[12], saldo[8];
    while (fscanf(file, "%[^,]s", nome) != EOF){
        fgetc(file);
        fgetc(file);
        fscanf(file, "%[^,]s", curso);
        fgetc(file);
        fgetc(file);
        fscanf(file, "%[^/]s", dia);
        fgetc(file);
        fscanf(file, "%[^/]s", mes);
        fgetc(file);
        fscanf(file, "%[^,]s", ano);
        fgetc(file);
        fgetc(file);
        fscanf(file, "%[^,]s", matricula);
        fgetc(file);
        fgetc(file);
        fscanf(file, "%[^\n]s", saldo);
        fgetc(file);
        fila_insere_final(fila, nome, curso, dia, mes, ano, matricula, saldo); 
    }
}

void salvar_fila(Fila *fila){
    No *aux = fila->inicio->prox;
    FILE * arq;
    arq = fopen("conteudo.txt", "w+");

    while(aux != NULL){
        fprintf(arq ,"%s, %s, %s, %s, %s\n", aux->nome, aux->curso, aux->data, aux->matricula, aux->saldo);
 
        aux = aux->prox;
    }
    

    fclose(arq);
    
}