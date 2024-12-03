#include <stdio.h>
#define TAM 10

void calcular(float temp[TAM]); 

int main() {
    float temp[TAM];

   
    for (int i = 0; i < TAM; i++) {
        printf("Digite a temperatura do dia %d: ", i + 1);
        scanf("%f", &temp[i]);
    }

   
    calcular(temp);
    
    return 0;
}

void calcular(float temp[TAM]) {
    float soma = 0, max, min;

    max = min = temp[0];  

    // Calcula a soma, o máximo e o mínimo
    for (int i = 0; i < TAM; i++) {
        soma += temp[i];

        if (temp[i] > max) {
            max = temp[i];
        }
        if (temp[i] < min) {
            min = temp[i];
        }
    }

    // Exibe os resultados
    printf("Soma das temperaturas: %.2f\n", soma);
    printf("Temperatura máxima: %.2f\n", max);
    printf("Temperatura mínima: %.2f\n", min);
}
