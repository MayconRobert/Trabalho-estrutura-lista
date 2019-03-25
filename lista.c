#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

PTR_LISTA criar_lista(){
    PTR_LISTA lista = (PTR_LISTA)malloc(sizeof(PTR_LISTA));
    lista->tamanho = 0;
    lista->inicio = NULL;
    return lista;
}

void inserir_aluno(PTR_LISTA lista){

    char nome[30];
    float massa,altura;

    // Criar uma celula e adicionar o conteúdo
    PTR_CELULA celula = (PTR_CELULA)malloc(sizeof(PTR_CELULA));
    printf("Insira o nome do Aluno: ");
    gets(nome);
    strcpy(celula->nome, nome);

    printf("Insira a massa do Aluno: ");
    scanf("%f", &massa);
    celula->massa = massa;

    printf("Insira a altura do Aluno: ");
    scanf("%f", &altura);
    celula->altura = altura;

    celula->imc = massa/(altura * altura);

    celula->proxima = NULL;


    // Inserir a celula na lista vazia
    if (lista->tamanho == 0){
        lista->inicio = celula;
    } else { // Inserir a celula na lista com elementos
        PTR_CELULA temp = lista->inicio;
        while (temp->proxima != NULL){
            temp = temp->proxima;
        }
        temp->proxima = celula;
    }

    lista->tamanho++;
}

void buscar_aluno(PTR_LISTA lista){

    char nome[30];

    if (lista->tamanho == 0){
        printf("Lista Vazia");
        getche();
        return;
    }

    printf("Insira o nome do Aluno que deseja buscar: ");
    gets(nome);

    PTR_CELULA celula = lista->inicio;

    while (celula != NULL){
        if(strcmp(celula->nome,nome) == 0){
            printf("%s\n", celula->nome);
            printf("%f\n", celula->massa);
            printf("%f\n", celula->altura);
            printf("%f\n", celula->imc);

            getche();

            return;
            }
        celula = celula->proxima;
    }
    printf("Aluno não Encontrado");
    getche();
}

void remover_especifico(PTR_LISTA lista){

    char nome[30];
    int primeira_rodada = 0;

    if (lista->tamanho == 0){
        printf("Lista Vazia");
        getche();
        return;
    }

    printf("Insira o nome do aluno que deseja remover: ");
    gets(nome);

    PTR_CELULA celula_lixo = lista->inicio;
    PTR_CELULA celula_anterior = lista->inicio;

    while (celula_lixo != NULL){
        if(strcmp(celula_lixo->nome,nome) == 0){
            celula_anterior->proxima = celula_lixo->proxima;
            free(celula_lixo);
            lista->tamanho--;
            printf("Aluno removido com sucesso");

            getche();

            return;
            }
        celula_lixo = celula_lixo->proxima;
        if(primeira_rodada)
            celula_anterior = celula_anterior->proxima;
        primeira_rodada = 1;
    }
    printf("Aluno Não Encontrado");
    getche();
}
