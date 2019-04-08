#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"

void main(){

    home();

 }

void home(){

    setlocale(LC_ALL,"Portuguese");
    system("color 4F");
    system("MODE 120, 30");    //Define tamanho do CMD

    int opcao = 10;

    PTR_LISTA lista = criar_lista();

    while(opcao != 8){

        //Cria a Moldura
        system("cls");
        tela();

        //Titulo da Janela
        gotoxy(50,3);printf("AGENDA DE ALUNOS");

        //Menu Principal
        gotoxy(55,10);printf("MENU");
        gotoxy(45,12);printf("1 - Cadastro de Alunos");
        gotoxy(45,13);printf("2 - Remover Aluno Especifico");
        gotoxy(45,14);printf("3 - Remover Todos os Alunos");
        gotoxy(45,15);printf("4 - Buscar Aluno");
        gotoxy(45,16);printf("5 - Exibe a Media do IMC e o Desvio Padrão");
        gotoxy(45,17);printf("6 - Exibe Maior e menor altura Exibe Maior e menor Massa");
        gotoxy(45,18);printf("7 - Salvar em um Arquivo");
        gotoxy(45,19);printf("8 - Sair");

        gotoxy(45,23);printf("Escolha a opcao desejada: ");
        gotoxy(71,23);scanf("%d",&opcao);
        fflush(stdin);
        system("cls");

        switch(opcao){

            case 1: inserir_aluno(lista);break;
            case 2: remover_especifico(lista);break;
            case 3: excluir_todos(lista);break;
            case 4: buscar_aluno(lista);break;
            case 5: retorna_media_imc(lista); retorna_desvio_padrao(lista);break;
            case 6: retorna_maior_altura(lista);
                    retorna_menor_altura(lista);
                    retorna_maior_massa(lista);
                    retorna_menor_massa(lista);
                    getche();break;
            case 7: salvar_alunos(lista);break;
            case 8: exit(EXIT_SUCCESS);break;

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

    getche();
    home();
}

void carregar_alunos(PTR_LISTA lista) {
    if(carregar(lista) == 0) {
        gotoxy(45,25);printf("Erro na abertura do arquivo!");
    } else {
        gotoxy(45,25);printf("Alunos recuperados com sucesso!");
    }

    getche();
    home();
}
