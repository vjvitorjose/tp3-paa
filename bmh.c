#include <stdio.h>
#include <string.h>
#include <limits.h> // Para definir o tamanho máximo da tabela (256 para caracteres ASCII)

// Função para construir a tabela de saltos
void construirTabelaSaltos(const char *padrao, int m, int tabela[256]) {
    int i;

    // Inicializa todos os valores com o tamanho do padrão
    for (i = 0; i < 256; i++) {
        tabela[i] = m;
    }

    // Preenche a tabela com base nos caracteres do padrão
    for (i = 0; i < m - 1; i++) {
        tabela[(unsigned char)padrao[i]] = m - 1 - i;
    }
}

// Função BMH para buscar o padrão no texto
void BMH(const char *texto, const char *padrao) {
    int n = strlen(texto);    // Tamanho do texto
    int m = strlen(padrao);   // Tamanho do padrão
    int tabela[256];          // Tabela de saltos (256 para caracteres ASCII)

    construirTabelaSaltos(padrao, m, tabela);

    printf("Procurando o padrão '%s' no texto '%s'\n", padrao, texto);

    int i = 0; // Índice no texto

    // Percorrer o texto
    while (i <= n - m) {
        int j = m - 1; // Começa a comparação do final do padrão

        // Verifica os caracteres do padrão e texto de trás para frente
        while (j >= 0 && padrao[j] == texto[i + j]) {
            j--;
        }

        if (j < 0) {
            // Padrão encontrado
            printf("Padrão encontrado na posição %d\n", i);
            i += tabela[(unsigned char)texto[i + m - 1]]; // Saltar com base na tabela
        } else {
            // Saltar com base no próximo caractere fora do padrão
            i += tabela[(unsigned char)texto[i + m - 1]];
        }
    }
}

int main() {
    char texto[1000], padrao[100];

    printf("Digite o texto: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o padrão: ");
    fgets(padrao, sizeof(padrao), stdin);
    padrao[strcspn(padrao, "\n")] = '\0'; // Remove o caractere de nova linha

    BMH(texto, padrao);

    return 0;
}
