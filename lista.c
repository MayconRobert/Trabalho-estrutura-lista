#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include <math.h>
float media = 0;
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

void excluir_todos(PTR_LISTA lista){
    if (lista == NULL){
        return;
    }
    while (lista->tamanho > 0) {
        PTR_CELULA lixo = lista->inicio;
        lista->inicio = lista->inicio->proxima;
        free(lixo);
        lista->tamanho--;

    }
}

int salvar(PTR_LISTA lista) {
   FILE * arq;

   if (lista == NULL){
        return 0;
    }
    // abrir arquivo contatos.txt no modo escrita "w" -> write
    arq = fopen("alunos.txt", "w");

    //testando se o arquivo foi realmente criado
    if(arq == NULL){
       return 0;
    }

    PTR_CELULA aluno = lista->inicio;
    while(aluno != NULL) {
        //usando fprintf para armazenar no arquivo
        fprintf(arq, "Nome: %s, peso: %f, altura: %f, imc: %f\n", aluno->nome, aluno->massa, aluno->altura, aluno->imc);

        aluno = aluno->proxima;
    }

    //usando fclose para fechar o arquivo
    fclose(arq);

    return 1;
}

int salvar_binario(PTR_LISTA lista) {
 size_t nbytes = 0L;
    FILE * fp = fopen( "alunos.dat", "wb" );

    if(!fp)
        return 0;

    nbytes = fwrite(lista, sizeof(PTR_LISTA), 1, fp );

    fclose(fp);
    return 1;
}

int carregar(PTR_LISTA lista) {
    size_t nbytes = 0L;
    FILE * fp = fopen( "alunos.dat", "rb" );

    if(!fp)
        return 0;

    nbytes = fread(lista, sizeof(PTR_LISTA), 1, fp );

    //usando fclose para fechar o arquivo
    fclose(fp);
    return 1;
}

float retorna_media_imc(PTR_LISTA lista){
    PTR_CELULA media_imc=(PTR_CELULA)malloc(sizeof(PTR_CELULA));

    if(lista->tamanho == 0){
        printf("Não tem aluno adicionado!\n");
    }

     PTR_CELULA temp = lista->inicio;
    if(lista->tamanho == 1 && temp ->proxima == NULL){
        printf("media imc: %.2f", temp->imc);
    }

    int contador=0;
    float soma_dos_imc=0;


    while (temp != NULL)
    {
        soma_dos_imc += temp->imc;
        contador++;
        temp = temp->proxima;
    }

    float media = soma_dos_imc/contador;
    printf("media imc: %.2f\n", media);

    system("pause");

    return media;
}

void retorna_desvio_padrao(PTR_LISTA lista){
    PTR_CELULA d_padrao =(PTR_CELULA)malloc(sizeof(PTR_CELULA));

    if(lista->tamanho == 0){
        printf("Não tem aluno adicionado!\n");
    }

    PTR_CELULA temp = lista->inicio;
    if(lista->tamanho == 1 && temp ->proxima == NULL){
        printf("desvio padrão: %.2f", temp->imc);
    }

    int contador=0;
    float soma_dos_imc=0;
    float soma_variancia = 0;
    float resultado_final_variancia;
    float variancia;

    while (temp != NULL)
    {
        variancia = pow((temp->imc - media),2);
        soma_variancia += variancia;
        contador++;
        temp = temp->proxima;
    }
    contador -= 1;
    resultado_final_variancia = soma_variancia/contador;
    printf("desvio padrão: %.2f\n\n",  sqrt(resultado_final_variancia));

    system("pause");
}

void ordena(PTR_LISTA lista)
{
    PTR_CELULA temp = (PTR_CELULA)malloc(sizeof(PTR_CELULA));
    PTR_CELULA temp2 ;
    temp = lista->inicio;

    while(temp != NULL){

       if(strcmp(temp->nome,temp->proxima->nome) > 0){
        {
        temp2 = temp;
        temp = temp->proxima;
        temp->proxima = temp2;
        }
        free(temp2);
        temp = temp->proxima;
    }

    system("pause");
    }
}
void retorna_maior_altura(PTR_LISTA lista)
{
    PTR_CELULA maior_altura = (PTR_CELULA)malloc(sizeof(PTR_CELULA));
     if (lista->tamanho == 0){
         printf("Nao tem aluno adicionado!");
     }
     else if (lista->tamanho == 1 && maior_altura->proxima == NULL){
         maior_altura = lista->inicio;
         printf("maior altura: %.2f", maior_altura->altura);
     }
	else{
    maior_altura = lista->inicio;
    PTR_CELULA temp = maior_altura->proxima;
    while (temp != NULL)
    {

        if(maior_altura->altura < temp->altura)
        {
            maior_altura = temp;
        }
     temp = temp->proxima;

    }
	printf("maior altura: %.2f", maior_altura->altura);
	}


    system("pause");
}

void retorna_menor_altura(PTR_LISTA lista)
{
    PTR_CELULA menor_altura = (PTR_CELULA)malloc(sizeof(PTR_CELULA));
     if (lista->tamanho == 0){
         printf("Nao tem aluno adicionado!");
     }
     else if (lista->tamanho == 1 && menor_altura->proxima == NULL){
         menor_altura = lista->inicio;
         printf("menor altura: %.2f", menor_altura->altura);
     }
	else{
    menor_altura = lista->inicio;
    PTR_CELULA temp = menor_altura->proxima;
    while (temp != NULL)
    {

        if(menor_altura->altura > temp->altura)
        {
            menor_altura = temp;
        }
     temp = temp->proxima;

    }
	printf("menor altura: %.2f", menor_altura->altura);
	}

    system("pause");
}

void retorna_maior_massa(PTR_LISTA lista)
{
    PTR_CELULA maior_massa = (PTR_CELULA)malloc(sizeof(PTR_CELULA));
     if (lista->tamanho == 0){
         printf("Nao tem aluno adicionado!");
     }
     else if (lista->tamanho == 1 && maior_massa->proxima == NULL){
         maior_massa = lista->inicio;
         printf("maior massa: %.2f", maior_massa->massa); // RETORNA 1 ALUNO
     }
   	else{
    maior_massa = lista->inicio;
    PTR_CELULA temp = maior_massa->proxima;
    while (temp != NULL)
    {

        if(maior_massa->massa < temp->massa)
        {
            maior_massa = temp;
        }
     temp = temp->proxima;

    }

    printf("maior massa: %.2f", maior_massa->massa);
	}

    system("pause");
}

void retorna_menor_massa(PTR_LISTA lista)
{
    PTR_CELULA menor_massa = (PTR_CELULA)malloc(sizeof(PTR_CELULA));
     if (lista->tamanho == 0){
         printf("Nao tem aluno adicionado!");
     }
     else if (lista->tamanho == 1 && menor_massa->proxima == NULL){
         menor_massa = lista->inicio;
         printf("menor massa: %.2f", menor_massa->massa); // RETORNA 1 ALUNO
     }
     else{
    menor_massa = lista->inicio;
    PTR_CELULA temp = menor_massa->proxima;
    while (temp != NULL)
    {

        if(menor_massa->massa > temp->massa)
        {
            menor_massa = temp;
        }
     temp = temp->proxima;

    }
 	printf("menor massa: %.2f", menor_massa->massa);
	}

    system("pause");
}
