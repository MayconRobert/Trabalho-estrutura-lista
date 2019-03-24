#ifndef __LISTA_H__
#define __LISTA_H__

typedef struct _celula {
    struct _celula *proxima;
    int numero;
} CELULA;

typedef CELULA *PTR_CELULA;

typedef struct _lista {
    PTR_CELULA inicio;
    int tamanho;
} LISTA;

typedef LISTA *PTR_LISTA;

PTR_LISTA criar_lista();
int lista_esta_vazia(PTR_LISTA lista);
void exibir_lista(PTR_LISTA lista);
void inserir_final(PTR_LISTA lista, int numero);
void inserir_inicio(PTR_LISTA lista, int numero);
void inserir_posicao(PTR_LISTA lista, int posicao, int numero);
void remover_final(PTR_LISTA lista);
void remover_inicio(PTR_LISTA lista);
void remover_posicao(PTR_LISTA lista, int posicao);
void salvar_contatos(PTR_LISTA lista);

#endif
