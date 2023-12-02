/*
Maria Paula Ferreira Maia
Matrícula: 20232010327
Polyana Melissa Teixeira Neves
Matrícula: 20232017408
*/

#include <stdio.h>
#include "fila.h"

int main() {
    Fila fila;
    FILE *file;
    file = fopen("conteudo.txt", "r+");


    fila = fila_cria();
    printf("%d\n", fila_vazia(&fila));  

    le_arquivo(&fila, file);
    
    fila_imprime(&fila);
    
    fila_remove(&fila);
    fila_imprime(&fila);
    
    desenfileira_fila(&fila);
    fila_imprime(&fila);

    
    salvar_fila(&fila);

    return 0;
}