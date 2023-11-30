#include "fila.h"
#include <stdio.h>

int main() {
    Fila fila;
    No generico;
    int n, i;
    char nome[60], curso[30];

    fila = fila_cria();

    printf("Lista vazia? %d\n", fila_vazia(&fila));

    //quantidade de nomes a inserir na lista
    scanf("%d", &n);

    getchar();

    //insere nomes na lista
    for(i=0; i<n; i++) {
        scanf("%s, %s, %d, %lf", nome, curso, &generico.matricula, &generico.saldo);
        getchar();
        strcpy(generico.nome, nome);
        strcpy(generico.curso, curso);

        fila_insere_final(&fila, generico);
    }

    printf("Lista vazia? %d\n\n", fila_vazia(&fila));

    //imprime conteudo
    fila_imprime(&fila);

    // //pesquisa por Joselito
    // aux = lista_pesquisa(&lista, "Joselito");

    // if(lista_remove(&lista, aux))
    //     printf("Joselito está fora! :-(\n\n");
    
    // //imprime conteudo
    // lista_imprime(&lista);

    return 0;
}