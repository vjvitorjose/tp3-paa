#include "in-out.h"

int leitura(char** argv){

    FILE* file = fopen(argv[1], "r");

    if(!file)
        return 0;

    int tamTexto, tamPadrao;
    char* texto = NULL;
    char* padrao = NULL;
    char buffer[256];

    while(1){

        fscanf(file, "%d %d\n", &tamTexto, &tamPadrao);

        if(tamTexto == 0)
            break;

        texto = malloc(tamTexto+1 * sizeof(char)); //incrementa 1 no tamanho do texto para incluir o \0
        padrao = malloc(tamPadrao+1 * sizeof(char));

        texto[tamTexto] = '\0';
        padrao[tamPadrao] = '\0';

        fgets(buffer, sizeof(buffer), file);
    
        {
            int j = 0;
            for(int i = 0; i < sizeof(buffer); i++){

                if(buffer[i] == '\n')
                    break;

                if(buffer[i] == ' ' || buffer[i] == '#' || buffer[i] == 'b')
                    continue;

                texto[j] = buffer[i];

                if(buffer[i+1] == '#')
                    texto[j] = texto[j] + 7;

                if(buffer[i+1] == 'b')
                    texto[j] = texto[j] + 14;

                j++;

            }
        }

        fgets(buffer, sizeof(buffer), file);

        {
            int j = 0;
            for(int i = 0; i < sizeof(buffer); i++){

                if(buffer[i] == '\n')
                    break;

                if(buffer[i] == ' ' || buffer[i] == '#' || buffer[i] == 'b')
                    continue;

                padrao[j] = buffer[i];

                if(buffer[i+1] == '#')
                    padrao[j] = padrao[j] + 7;

                if(buffer[i+1] == 'b')
                    padrao[j] = padrao[j] + 14;

                j++;

            }
        }

        switch(atoi(argv[2])){
            case 1:
                forcaBruta(texto, padrao);
                break;
            case 2:
                //kmp
                break;
            case 3:
                //bmh
                break;
            case 4:
                //shiftAnd
                break;
        }

        free(texto);
        free(padrao);

    }

    return 1;

}