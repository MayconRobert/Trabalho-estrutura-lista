#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

PTR_LISTA criar_lista(){
    PTR_LISTA lista = (PTR_LISTA)malloc(sizeof(PTR_LISTA));
    lista->tamanho = 0;
    lista->inicio = NULL;
    return lista;
}

void exibir_lista(PTR_LISTA lista){
    if (lista->tamanho == 0)
        return;

    PTR_CELULA celula = lista->inicio;
    while (celula != NULL){
        printf("%d\n", celula->numero);
        celula = celula->proxima;
    }
    printf("\n");
}

void inserir_final(PTR_LISTA lista, int numero){
    // Criar uma celula e adicionar o conteúdo
    PTR_CELULA celula = (PTR_CELULA)malloc(sizeof(PTR_CELULA));
    celula->numero = numero;
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

void inserir_inicio(PTR_LISTA lista, int numero){
// Criar uma celula e adicionar o conteúdo
    PTR_CELULA celula = (PTR_CELULA)malloc(sizeof(PTR_CELULA));
    celula->numero = numero;
    celula->proxima = NULL;

    // Inserir a celula na lista vazia
    if (lista->tamanho == 0){
        lista->inicio = celula;
    } else {
        celula->proxima = lista->inicio;
        lista->inicio = celula;
    }

    lista->tamanho++;
}


void remover_final(PTR_LISTA lista){
    if (lista->tamanho != 0){
        // Inicio -> 10 -> 20 -> 30 -> 40
        // Lixo -> 40
        PTR_CELULA lixo = lista->inicio;
        PTR_CELULA penultimo = lista->inicio;
        while(lixo->proxima != NULL){
            lixo = lixo->proxima;
            if (lixo->proxima != NULL){
                penultimo = penultimo->proxima;
            }
        }
        penultimo->proxima = NULL;
        free(lixo);
        lista->tamanho--;
    }
}

void remover_inicio(PTR_LISTA lista){
    if (lista->tamanho != 0){
        PTR_CELULA lixo = lista->inicio;
        lista->inicio = lista->inicio->proxima;
        free(lixo);
        lista->tamanho--;
    }
}

void salvar_contatos(PTR_LISTA lista) {
   FILE * arq;

    // abrir arquivo contatos.txt no modo escrita "w" -> write
    arq = fopen("alunos.txt", "w");

    //testando se o arquivo foi realmente criado
    if(arq == NULL){
      gotoxy(45,25);printf("Erro na abertura do arquivo!");
    }

    //APENAS TESTE, VERSAO FINAL DEPENDE DA STRUC DE ALUNO
    //usando fprintf para armazenar no arquivo
    fprintf(arq, "%s", "aaaaa");

    //usando fclose para fechar o arquivo
    fclose(arq);

    gotoxy(45,25);printf("Contatos gravados com sucesso!");
}






