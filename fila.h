/*
Maria Paula Ferreira Maia
Matrícula: 20232010327
Polyana Melissa Teixeira Neves
Matrícula: 20232017408
*/
#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[60];
    char curso[30];
    char data[11];
    char matricula[13];
    char saldo[8];
    struct No* prox;
} No;

typedef struct fila {
    No* inicio;
    No* fim;
} Fila;


Fila fila_cria();

int fila_vazia(Fila *);

void fila_insere_final(Fila *f, char nome[], char curso[], char dia[], char mes[], char ano[], char matricula[], char saldo[]);

void fila_remove(Fila *);

void desenfileira_fila(Fila *);

void desaloca_fila(Fila *);

void fila_imprime(Fila *);

void le_arquivo(Fila *fila, FILE *file);

void salvar_fila(Fila *);



#endif