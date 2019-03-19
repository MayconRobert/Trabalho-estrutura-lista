#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    PTR_LISTA lista = criar_lista();

    inserir_final(lista, 10);
    inserir_final(lista, 20);
    inserir_final(lista, 30);
    inserir_final(lista, 40);

    inserir_inicio(lista, 50);

    exibir_lista(lista);

    remover_inicio(lista);
    remover_final(lista);

    exibir_lista(lista);

    return 0;
}

