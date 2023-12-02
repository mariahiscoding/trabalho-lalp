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
    int opcao;
    char nome[60], curso[30], dia[3], mes[3], ano[5], matricula[12], saldo[8];

    fila = fila_cria();
    le_arquivo(&fila, file);

    while (1){
        printf("Fila inicial:\n");
        fila_imprime(&fila);
        printf("Escolha uma das seguintes opções digitando o número referente a sua escolha:\n  1.Enfileira: adicionar os dados de uma pessoa a lista\n  2.Desenfileira:Retira a primeira pessoa da fila\n  3.Salvar conteudo da lista\n  4.Fechar implementação da lista e salvar arquivo\n");
        scanf("%d", &opcao);
        fgetc(stdin);
        switch (opcao){
        case 1:
            scanf("%[^,]s", nome);
            fgetc(stdin);
            fgetc(stdin);
            scanf("%[^,]s", curso);
            fgetc(stdin);
            fgetc(stdin);
            scanf("%[^/]s", dia);
            fgetc(stdin);
            scanf("%[^/]s", mes);
            fgetc(stdin);
            scanf("%[^,]s", ano);
            fgetc(stdin);
            fgetc(stdin);
            scanf("%[^,]s", matricula);
            fgetc(stdin);
            fgetc(stdin);
            scanf("%[^\n]s", saldo);
            fgetc(stdin);

            fila_insere_final(&fila, nome, curso, dia, mes, ano, matricula, saldo); 
            break;
        case 2:
            fila_remove(&fila);
            fila_imprime(&fila);
            break;
        case 3:
            salvar_fila(&fila);
            break;

        case 4:
            salvar_fila(&fila);
            desenfileira_fila(&fila);
            desaloca_fila(&fila);
            break;
        default:
            printf("Opção inválida, digite novamente\n");
            break;
        }
        if (opcao == 4)
            exit(0);
        
    }
    
    

    return 0;
}