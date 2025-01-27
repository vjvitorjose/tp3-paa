#include "forca-bruta.h"
#include <stdio.h>
#include <string.h>

void forcaBrutaPadrao(const char *texto, const char *padrao) {
    int n = strlen(texto);
    int m = strlen(padrao);
    int i, j;

    printf("Procurando o padrão '%s' no texto '%s'\n", padrao, texto);

    for (i = 0; i <= n - m; i++) {
        j = 0;
        
        while (j < m && texto[i + j] == padrao[j]) {
            j++;
        }

        if (j == m) {
            printf("Padrão encontrado na posição %d\n", i);
        }
    }
}

int main() {
    char texto[1000], padrao[100];

    printf("Digite o texto: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0';

    printf("Digite o padrão: ");
    fgets(padrao, sizeof(padrao), stdin);
    padrao[strcspn(padrao, "\n")] = '\0';

    forcaBrutaPadrao(texto, padrao);

    return 0;
}
