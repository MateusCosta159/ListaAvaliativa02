#include <stdio.h>
#include <stdlib.h>

int main() {
    int sorteados[6], bilhete[6], acertos = 0;

    printf("Digite os 6 números sorteados:\n");
    for (int i = 0; i < 6; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &sorteados[i]);
    }

    printf("Digite os 6 números do seu bilhete:\n");
    for (int i = 0; i < 6; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &bilhete[i]);
    }

    int *numeros_corretos = (int *)malloc(6 * sizeof(int));
    if (numeros_corretos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (sorteados[i] == bilhete[j]) {
                numeros_corretos[acertos++] = sorteados[i];
                break;
            }
        }
    }

    printf("Números sorteados: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", sorteados[i]);
    }
    printf("\n");

    printf("Números acertados: ");
    for (int i = 0; i < acertos; i++) {
        printf("%d ", numeros_corretos[i]);
    }
    printf("\n");

    free(numeros_corretos);
    return 0;
}
