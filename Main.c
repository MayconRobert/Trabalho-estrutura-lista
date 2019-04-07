#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "lista.h"

// Função para posicionamento de cursor (col, lin);
void gotoxy(float x, float y){

    COORD c;
    c.X = x - 1;
    c.Y = y - 1;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);

}

// Função que desenha moldura na tela
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

 void main(){

    setlocale(LC_ALL,"Portuguese");
    system("color 4F");
    system("MODE 120, 30");    //Define tamanho do CMD

    int opcao = 10;

    /*PTR_LISTA lista;
    if(lista)
        PTR_LISTA lista = criar_lista();*/
    PTR_LISTA lista = criar_lista();

    while(opcao != 9){

        //Cria a Moldura
        system("cls");
        tela();

        //Titulo da Janela
        gotoxy(50,3);printf("AGENDA DE ALUNOS");

        //Menu Principal
        gotoxy(55,10);printf("MENU");
        gotoxy(45,12);printf("1 - Cadastro de Alunos");
        gotoxy(45,13);printf("2 - Remover Aluno Específico");
        gotoxy(45,14);printf("3 - Remover Todos os Alunos");
        gotoxy(45,15);printf("4 - Buscar Aluno");
        gotoxy(45,16);printf("5 - Salvar em um Arquivo texto");
        gotoxy(45,17);printf("6 - Exibe a Media do IMC e o Desvio Padrão");
        gotoxy(45,18);printf("7 - Exibe Maior e menor altura Exibe Maior e menor Massa");
        gotoxy(45,19);printf("8 - Sair");

        gotoxy(45,23);printf("Escolha a opção desejada: ");
        gotoxy(71,23);scanf("%d",&opcao);
        fflush(stdin);
        system("cls");

        switch(opcao){
            case 1: inserir_aluno(lista);break;
            case 2: remover_especifico(lista);break;
            case 3: excluir_todos(lista);break;
            case 4: buscar_aluno(lista);break;
            case 5: salvar_alunos(lista);break;
            case 6: retorna_media_imc(lista); retorna_desvio_padrao(lista);break;
            case 7: retorna_maior_altura(lista);
            retorna_menor_altura(lista);
            retorna_maior_massa(lista);
            retorna_menor_massa(lista);break;
            case 8: ;break;
        }
    }
    system("pause");
 }

void salvar_alunos(PTR_LISTA lista) {
    if(salvar(lista) == 0) {
        gotoxy(45,25);printf("Erro na abertura do arquivo!");
    } else {
        gotoxy(45,25);printf("Alunos salvos com sucesso!");
    }
}

void carregar_alunos(PTR_LISTA lista) {
    if(carregar(lista) == 0) {
        gotoxy(45,25);printf("Erro na abertura do arquivo!");
    } else {
        gotoxy(45,25);printf("Alunos recuperados com sucesso!");
    }
}
