#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main(){
    int dados[] = {1, 2, 3, 4, 5};

    ArvBin* raiz = cria_ArvBin();

    for (int i = 0; i < sizeof(dados) / sizeof(dados[0]); i++) {
        insere_ArvBin(raiz, dados[i]);
    }

    printf("altura: %d\n", altura_ArvBin(raiz));
    libera_ArvBin(raiz);

    return 0;
}
