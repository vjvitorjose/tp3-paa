#include "forca-bruta.h"

void forcaBruta(char *texto, char *padrao){

    int tamTexto = strlen(texto);
    int tamPadrao = strlen(padrao);
    int j;

    for (int i = 0; i <= tamTexto-tamPadrao; i++){

        j = 0;
        
        while (j < tamPadrao && texto[i + j] == padrao[j])
            j++;

        if (j == tamPadrao){
            printf("S %d\n", i);
            return;
        }

    }

    printf("N\n");

}