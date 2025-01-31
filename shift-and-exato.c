#include "shift-and-exato.h"

int** criaMascara(int l, int c){

    int** mascara = malloc(l*sizeof(int*));

    for(int j = 0; j < l; j++){
        mascara[j] = (int*)malloc(c*sizeof(int));
    }

    zeraMascara(mascara, l, c);

    return mascara;

}

void zeraMascara(int** mascara, int l, int c){

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            mascara[i][j] = 0;
        }
    }

}

void freeMascara(int** mascara, int l, int c){

    for(int i = 0; i < l; i++){
        free(mascara[i]);
    }

    free(mascara);

}

void preencheMascara(int** mascara, char* padrao){

    for(int i = 0; i < strlen(padrao); i++)
        mascara[(int)padrao[i]-65][i] = 1;

}

void zeraR(int* R, int tam){

    for(int i = 0; i < tam; i++){
        R[i] = 0;
    }

}

void deslocaR(int* R, int tam){

    for(int j = tam-1; j > 0; j--){
        R[j] = R[j-1];  
    }
    R[0] = 1;

}

void RAndMascara(int* R, int tamR, int** mascara, char caracter){

    for(int i = 0; i < tamR; i++){
        R[i] = R[i] && mascara[(int)caracter-65][i];
    }

}

void shiftAnd(char* texto, char* padrao){

    int** mascara = criaMascara(26, strlen(padrao));

    preencheMascara(mascara, padrao);

    int tamR = strlen(padrao);
    int* R = malloc(tamR*sizeof(int));
    zeraR(R, tamR);

    for(int i = 0; i < strlen(texto); i++){

        deslocaR(R, tamR);
        RAndMascara(R, tamR, mascara, texto[i]);

        if(R[tamR-1] == 1){
            printf("S %d\n", i-tamR+1);
            freeMascara(mascara, 26, strlen(padrao));
            free(R);
            return;
        }

    }

    printf("N\n");
    freeMascara(mascara, 26, strlen(padrao));
    free(R);  

}