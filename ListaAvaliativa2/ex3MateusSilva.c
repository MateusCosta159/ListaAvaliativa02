#include <stdio.h>

#define TAM 30


void preencherVetor(int vet[TAM]);
void calcular(int vet[TAM], float *media, int *min, int *max);
void diasConsecutivos(int dias[TAM], int vet[TAM]);

int main() {
    int vet[TAM];
    int diasConsecutivosAbaixo15[TAM];
    float media = 0;
    int min = 0, max = 0;

    preencherVetor(vet);

  
    calcular(vet, &media, &min, &max);

    printf("Média das temperaturas: %.2f\n", media);
    printf("Temperatura mínima: %d\n", min);
    printf("Temperatura máxima: %d\n", max);

    diasConsecutivos(diasConsecutivosAbaixo15, vet);

    printf("Dias consecutivos com temperatura abaixo de 15:\n");
    for (int i = 0; i < TAM && diasConsecutivosAbaixo15[i] != -1; i++) {
        printf("Dia %d: %d°C\n", i + 1, diasConsecutivosAbaixo15[i]);
    }

    return 0;
}


void preencherVetor(int vet[TAM]) {
    printf("Preencha o vetor abaixo:\n");
    for (int i = 0; i < TAM; i++) {
        printf("Digite a temperatura do dia %d: ", i + 1);
        scanf("%d", &vet[i]);
    }
}

void calcular(int vet[TAM], float *media, int *min, int *max) {
    int soma = 0;
    *min = vet[0];
    *max = vet[0];

    for (int i = 0; i < TAM; i++) {
        soma += vet[i];

        if (vet[i] < *min) {
            *min = vet[i];
        }
        if (vet[i] > *max) {
            *max = vet[i];
        }
    }

    *media = (float)soma / TAM;

void diasConsecutivos(int dias[TAM], int vet[TAM]) {
    int j = 0;

    for (int i = 0; i < TAM; i++) {
        if (vet[i] < 15) {
            dias[j++] = vet[i];
        } else {
            break; 
        }
    }

    dias[j] = -1; 
}
