#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

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
    system("color 1F");
    system("MODE 120, 30");    //Define tamanho do CMD

    int opcao = 0;

    while(opcao != 9){

        //Cria a Moldura
        tela();

        //Titulo da Janela
        gotoxy(50,3);printf("AGENDA DE ALUNOS");

        //Menu Principal
        gotoxy(55,10);printf("MENU");
        gotoxy(45,12);printf("1 - Cadastro de Alunos");
        gotoxy(45,13);printf("2 - Excluir Aluno Específico");
        gotoxy(45,14);printf("3 - Excluir Todos os Alunos");
        gotoxy(45,15);printf("4 - Exibir Alunos");
        gotoxy(45,16);printf("5 - Exibir Alunos de Forma Ordenada");
        gotoxy(45,17);printf("6 - Relatório");
        gotoxy(45,18);printf("7 - Salvar Alunos em Arquivo de Texto");
        gotoxy(45,19);printf("8 - Carregar Alunos do Arquivo de Texto");
        gotoxy(45,20);printf("9 - Sair");

        gotoxy(45,22);printf("Escolha a opção desejada: ");
        gotoxy(71,22);scanf("%d",&opcao);
        fflush(stdin);
        system("cls");

        switch(opcao){
            /*case 1: cadastro();break;
            case 2: excluir_especifico();break;
            case 3: escluir_todos();break;
            case 4: exibir_alunos();break;
            case 5: exibir_ordenado();break;
            case 6: relatorio();break;
            case 7: salvar_contatos();break;
            case 8: carregar_contatos();break;*/

            case 9: ;break;

            default: printf("Opção Inválida");break;
        }
    }
    system("pause");
 }
