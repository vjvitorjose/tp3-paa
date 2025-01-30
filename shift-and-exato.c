#include "shift-and-exato.h"

int** criaMascara(int l, int c){

    int** mascara = malloc(l*sizeof(int*));

    for(int j = 0; j < l; j++){
        mascara[j] = (int*)malloc(c*sizeof(int));
    }

<<<<<<< HEAD
    uint64_t mascara[256] = {0}; // Tabela de bits para cada caractere ASCII
    uint64_t estado = 0;         // Estado atual
    uint64_t mascaraFinal = (1ULL << (m - 1)); // Mascara para verificar o padrão completo
    int i;
    
    // Construir a máscara para cada caractere do padrão
    for (i = 0; i < m; i++) {
        mascara[(unsigned char)padrao[i]] |= (1ULL << i);
    }

    printf("Procurando o padrão '%s' no texto '%s'\n", padrao, texto);

    // Percorrer o texto
    for (i = 0; i < n; i++) {
        // Atualizar o estado atual usando operações bitwise
        estado = ((estado << 1) | 1ULL) & mascara[(unsigned char)texto[i]];

        // Verificar se o padrão foi encontrado
        if (estado & mascaraFinal) {
            printf("Padrão encontrado na posição %d\n", i - m + 1);
        }
    }
=======
    return mascara;

>>>>>>> d1d587b (.)
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

void shiftAnd(char* texto, char* padrao){

    int** mascara = criaMascara(26, strlen(padrao));

    preencheMascara(mascara, padrao);

    int R[sizeof(padrao)];

    

    freeMascara(mascara, 26, strlen(padrao));    

}

int main(){
    char* texto = "ABCDEFG";
    char* padrao = "BCD";
    shiftAnd(texto, padrao);
    return 1;
}