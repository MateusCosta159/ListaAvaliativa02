#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, X, count = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);

    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite %d números:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Digite um número para encontrar os múltiplos: ");
    scanf("%d", &X);

    printf("Múltiplos de %d no vetor:\n", X);
    for (int i = 0; i < N; i++) {
        if (array[i] % X == 0) {
            printf("%d ", array[i]);
            count++;
        }
    }
    printf("\nQuantidade de múltiplos: %d\n", count);

    free(array);
    return 0;
}
