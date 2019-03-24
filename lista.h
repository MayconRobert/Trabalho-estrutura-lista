#ifndef __LISTA_H__
#define __LISTA_H__

typedef struct _celula {
    struct _celula *proxima;
    char nome[30];
    float massa;
    float altura;
    float imc;
} CELULA;

typedef CELULA *PTR_CELULA;

typedef struct _lista {
    PTR_CELULA inicio;
    int tamanho;
} LISTA;

typedef LISTA *PTR_LISTA;

PTR_LISTA criar_lista();
void inserir_aluno(PTR_LISTA lista);
void buscar_aluno(PTR_LISTA lista);


#endif
