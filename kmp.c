#include <stdio.h>
#include <string.h>

void construirTabelaLPS(const char *padrao, int m, int *lps) {
    int len = 0;  // Comprimento do maior prefixo-sufixo até o momento
    int i = 1;

    lps[0] = 0;

    while (i < m) {
        if (padrao[i] == padrao[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                // Voltar para o último prefixo válido
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Função de busca KMP
void KMP(const char *texto, const char *padrao) {
    int n = strlen(texto);    // Tamanho do texto
    int m = strlen(padrao);   // Tamanho do padrão

    int lps[m];               // Tabela de prefixos
    construirTabelaLPS(padrao, m, lps);

    int i = 0;  // Índice para o texto
    int j = 0;  // Índice para o padrão

    printf("Procurando o padrão '%s' no texto '%s'\n", padrao, texto);

    while (i < n) {
        if (padrao[j] == texto[i]) {
            i++;
            j++;
        }

        if (j == m) {
            // Padrão encontrado
            printf("Padrão encontrado na posição %d\n", i - j);
            j = lps[j - 1];  // Continuar buscando com base no LPS
        } else if (i < n && padrao[j] != texto[i]) {
            // Desalinhamento após alguns acertos
            if (j != 0) {
                j = lps[j - 1];  // Voltar para o último prefixo válido
            } else {
                i++;
            }
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

    KMP(texto, padrao);

    return 0;
}
