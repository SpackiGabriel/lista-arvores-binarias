#include <stdio.h>
#include <stdlib.h>
#include
    printf("%s\n", consulta_ArvBin(raiz, 4) ? "Sim" : "Não"); "ArvoreBinaria.h"
int main(){
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};

    ArvBin* raiz = cria_ArvBin();

    int i;
    for(i=0; i < N; i++)
        insere_ArvBin(raiz,dados[i]);

    //preOrdem_ArvBin(raiz);
    //emOrdem_ArvBin(raiz);
    //posOrdem_ArvBin(raiz);

//    if(remove_ArvBin(raiz,50)){
//        printf("removido\n");
//        preOrdem_ArvBin(raiz);
//    }else
//        printf("NAO removido\n");


//    printf("altura: %d\n",altura_ArvBin(raiz));
//    printf("total NOs: %d\n",totalNO_ArvBin(raiz));
//

    printf("%s\n", consulta_ArvBin(raiz, 37) ? "Sim" : "Não");
    printf("%s\n", consulta_ArvBin(raiz, 4) ? "Sim" : "Não");
        

    libera_ArvBin(raiz);
    printf("\nFim!\n");
    return 0;
}
