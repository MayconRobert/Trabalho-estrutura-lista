#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include "lista.h"

#define BUFFER_SIZE 100


static float media;

void gotoxy(float x, float y){

    COORD c;
    c.X = x - 1;
    c.Y = y - 1;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);

}

void tela(){

    float	c,l;
 // Desenha as linhas horizontais
     for(c=1; c<=120; c++)
     {
          gotoxy(c,1); printf("=");
          gotoxy(c,5); printf("=");
          gotoxy(c,30); printf("=");
     }
 // Desenha as linhas verticais
     for( l=1;l<=30;l++)
     {
          gotoxy(1,l); printf("|");
          gotoxy(120,l); printf("|");
     }
 }

PTR_LISTA criar_lista(){
    PTR_LISTA lista = (PTR_LISTA)malloc(sizeof(PTR_LISTA));
    lista->tamanho = 0;
    lista->inicio = NULL;
    return lista;
}

void inserir_aluno(PTR_LISTA lista){

    char nome[30];
    float massa,altura;

    tela();
    gotoxy(50,3);printf("ADICIONAR ALUNO");

    // Criar uma celula e adicionar o conteúdo
    PTR_CELULA celula = (PTR_CELULA)malloc(sizeof(PTR_CELULA));
    gotoxy(35, 11);printf("Insira o nome do Aluno: ");
    gets(nome);
    strcpy(celula->nome, nome);

    gotoxy(35, 13);printf("Insira a massa do Aluno: ");
    scanf("%f", &massa);
    celula->massa = massa;

    gotoxy(35, 15);printf("Insira a altura do Aluno: ");
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

    tela();
    gotoxy(50,3);printf("BUSCAR ALUNO");

    if (lista->tamanho == 0){
        gotoxy(50, 14);printf("Lista Vazia");
        getche();
        return;
    }

    gotoxy(35,11);printf("Insira o nome do Aluno que deseja buscar: ");
    gets(nome);

    PTR_CELULA celula = lista->inicio;

    while (celula != NULL){
        if(strcmp(celula->nome,nome) == 0){
            gotoxy(50,14);printf("Nome: %s\n", celula->nome);
            gotoxy(50,15);printf("Massa: %.2f Kg\n", celula->massa);
            gotoxy(50,16);printf("Altura: %.2f m\n", celula->altura);
            gotoxy(50,17);printf("IMC: %.1f\n", celula->imc);

            getche();

            return;
            }
        celula = celula->proxima;
    }
    gotoxy(47,16);printf("Aluno nao Encontrado");
    getche();
}

void remover_especifico(PTR_LISTA lista){

    char nome[30];
    int primeira_rodada = 0;

    tela();
    gotoxy(50,3);printf("REMOVER ALUNO");


    if (lista->tamanho == 0){
        gotoxy(52, 15);printf("Lista Vazia");
        getche();
        return;
    }

    gotoxy(35,11);printf("Insira o nome do aluno que deseja remover: ");
    gets(nome);

    PTR_CELULA celula_lixo = lista->inicio;
    PTR_CELULA celula_anterior = lista->inicio;

    while (celula_lixo != NULL){
        if(strcmp(celula_lixo->nome,nome) == 0){
            celula_anterior->proxima = celula_lixo->proxima;
            free(celula_lixo);
            lista->tamanho--;
            gotoxy(50,16);printf("Aluno removido com sucesso");

            getche();

            return;
            }
        celula_lixo = celula_lixo->proxima;
        if(primeira_rodada)
            celula_anterior = celula_anterior->proxima;
        primeira_rodada = 1;
    }
    gotoxy(47,16);printf("Aluno nao Encontrado");
    getche();
}

void excluir_todos(PTR_LISTA lista){

    tela();
    gotoxy(45,3);printf("REMOVER TODOS OS ALUNOS");

    if (lista->tamanho == 0){
        gotoxy(50,14);printf("Lista vazia");
        getche();
        return;
    }
    while (lista->tamanho > 0) {
        PTR_CELULA lixo = lista->inicio;
        lista->inicio = lista->inicio->proxima;
        free(lixo);
        lista->tamanho--;
    }
    gotoxy(45, 14);printf("Todos os alunos removidos");
    getche();
}

float retorna_media_imc(PTR_LISTA lista){
    PTR_CELULA media_imc=(PTR_CELULA)malloc(sizeof(PTR_CELULA));

    if(lista->tamanho == 0){
        printf("Não tem aluno adicionado!\n");
    }

     PTR_CELULA temp = lista->inicio;
    if(lista->tamanho == 1 && temp ->proxima == NULL){
        printf("%.2f", temp->imc);
    }

    int contador=0;
    float soma_dos_imc=0;


    while (temp != NULL)
    {
        soma_dos_imc += temp->imc;
        contador++;
        temp = temp->proxima;
    }

    media = soma_dos_imc/contador;
    printf("%.2f\n", media);

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
        printf("%.2f", temp->imc);
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

    float desvio;

    desvio = sqrt(resultado_final_variancia);

    printf("%.2f\n\n",  desvio);

    system("pause");

}

int salvar(PTR_LISTA lista) {
   FILE * arq;

   if (lista == NULL){
        return 0;
    }
    // abrir arquivo alunos.txt no modo escrita "w" -> write
    arq = fopen("alunos.txt", "w");

    //testando se o arquivo foi realmente criado
    if(arq == NULL){
       return 0;
    }

    PTR_CELULA aluno = lista->inicio;
    while(aluno != NULL) {
        //usando fprintf para armazenar no arquivo
        fprintf(arq, "%s#%.2f#%.2f#%.1f\n", aluno->nome, aluno->massa, aluno->altura, aluno->imc);

        aluno = aluno->proxima;
    }

    //usando fclose para fechar o arquivo
    fclose(arq);

    return 1;
}

PTR_CELULA carregar_celula(char* str){

    PTR_CELULA celula = (PTR_CELULA)malloc(sizeof(PTR_CELULA));
    int flag = 0;
    char *token = strtok(str, "#");

    while( token != NULL )
    {
        if (0 == flag)
            strcpy(celula->nome, token);
        else if (1 == flag)
            celula->massa = atof(token);
        else if(2 == flag)
            celula->altura = atof(token);
        else
            celula->imc = atof(token);

        flag++;
        token = strtok( NULL, "#" );
    }

    return celula;

}

int carregar(PTR_LISTA lista) {

    FILE * fp = fopen( "alunos.txt", "r" );
    char buffer[BUFFER_SIZE];

    if(!fp)
        return 0;

    while(fgets(buffer, BUFFER_SIZE, fp)){

        PTR_CELULA celula = (PTR_CELULA)malloc(sizeof(PTR_CELULA));
        celula = carregar_celula(buffer);

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

    //usando fclose para fechar o arquivo
    fclose(fp);
    return 1;
}





