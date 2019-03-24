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

    printf("Insira o nome do Aluno: ");
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
