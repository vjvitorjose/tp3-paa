#include <stdio.h>
#include <string.h>
#include <stdint.h> // Para usar inteiros de tamanho fixo, como uint64_t

#define TAMANHO_MAX_PADRAO 64 // Limite máximo para o tamanho do padrão

void shiftAndExato(const char *texto, const char *padrao) {
    int n = strlen(texto);    // Tamanho do texto
    int m = strlen(padrao);   // Tamanho do padrão

    if (m > TAMANHO_MAX_PADRAO) {
        printf("O padrão excede o tamanho máximo suportado (%d caracteres).\n", TAMANHO_MAX_PADRAO);
        return;
    }

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
}

int main() {
    char texto[1000], padrao[65];

    printf("Digite o texto: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o padrão (máximo %d caracteres): ", TAMANHO_MAX_PADRAO);
    fgets(padrao, sizeof(padrao), stdin);
    padrao[strcspn(padrao, "\n")] = '\0'; // Remove o caractere de nova linha

    shiftAndExato(texto, padrao);

    return 0;
}
