#include <stdio.h>
#include <string.h>

#define TAM_ALFABETO 256 // Número de caracteres ASCII

// Função para criar a tabela de saltos
void construirTabelaSaltos(const char *padrao, int m, int tabela[TAM_ALFABETO]) {
    for (int i = 0; i < TAM_ALFABETO; i++) {
        tabela[i] = m; // Valor padrão de salto
    }
    for (int i = 0; i < m - 1; i++) {
        tabela[(unsigned char)padrao[i]] = m - 1 - i;
    }
}

// Algoritmo de busca BMH
void buscarPadraoBMH(const char *texto, const char *padrao) {
    int n = strlen(texto);
    int m = strlen(padrao);
    int tabela[TAM_ALFABETO];
    
    construirTabelaSaltos(padrao, m, tabela);

    printf("Buscando o padrão '%s' no texto...\n", padrao);

    int i = 0;
    while (i <= n - m) {
        int j = m - 1;

        while (j >= 0 && padrao[j] == texto[i + j]) {
            j--;
        }

        if (j < 0) {
            printf("Padrão encontrado na posição %d\n", i);
            i += tabela[(unsigned char)texto[i + m - 1]];
        } else {
            i += tabela[(unsigned char)texto[i + m - 1]];
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

    buscarPadraoBMH(texto, padrao);

    return 0;
}
