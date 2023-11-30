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

typedef struct No_ {
    char nome[60];
    char curso[30];
    int data [3];
    int matricula;
    double saldo;

    struct No_ *prox;
} No;

typedef struct {
    No *inicio, *fim;
} Fila;

Fila fila_cria();

int fila_vazia(Fila *);

void fila_insere_final(Fila *, No generico);

int remove_fila(Fila *, No *);

void desenfileira_fila(Fila *, No *);

void desaloca_fila(Fila *, No *);

void fila_imprime(Fila *);

void le_arquivo(Fila *);

void salvar_fila(Fila *);



#endif