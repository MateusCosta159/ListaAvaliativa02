#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARROS 10
#define DISTANCIA_MAXIMA 1000

typedef struct {
    int id;
    int velocidadeMaxima; // Em km/h
    int distanciaPercorrida; // Em metros
} Carro;

// Funções
void atualizarDistancia(Carro carros[], int numCarros);
void exibirPosicoes(Carro carros[], int numCarros);
void ajustarVelocidade(Carro *carro);
int verificarVencedores(Carro carros[], int numCarros);

int main() {
    Carro carros[NUM_CARROS];
    int corridaFinalizada = 0;
    int rodadas = 0;

  
    srand(time(NULL));
    for (int i = 0; i < NUM_CARROS; i++) {
        carros[i].id = i + 1;
        carros[i].velocidadeMaxima = rand() % 201 + 100;
        carros[i].distanciaPercorrida = 0;
    }

    printf("Corrida iniciada com %d carros!\n", NUM_CARROS);


    while (!corridaFinalizada) {
        rodadas++;
        printf("\nRodada %d:\n", rodadas);

        atualizarDistancia(carros, NUM_CARROS);

        exibirPosicoes(carros, NUM_CARROS);

    
        corridaFinalizada = verificarVencedores(carros, NUM_CARROS);

        if (!corridaFinalizada) {
            int ajustar;
            printf("\nDeseja ajustar a velocidade de um carro? (1 - Sim, 0 - Não): ");
            scanf("%d", &ajustar);
            if (ajustar) {
                int idCarro;
                printf("Digite o ID do carro para ajustar a velocidade: ");
                scanf("%d", &idCarro);
                if (idCarro >= 1 && idCarro <= NUM_CARROS) {
                    ajustarVelocidade(&carros[idCarro - 1]);
                } else {
                    printf("ID de carro inválido.\n");
                }
            }
        }
    }

    printf("\nA corrida foi finalizada após %d rodadas!\n", rodadas);
    return 0;
}

void atualizarDistancia(Carro carros[], int numCarros) {
    for (int i = 0; i < numCarros; i++) {
        if (carros[i].distanciaPercorrida < DISTANCIA_MAXIMA) {
            
            int incremento = rand() % 101 + 100;
            carros[i].distanciaPercorrida += incremento;

           
            if (carros[i].distanciaPercorrida > DISTANCIA_MAXIMA) {
                carros[i].distanciaPercorrida = DISTANCIA_MAXIMA;
            }
        }
    }
}

void exibirPosicoes(Carro carros[], int numCarros) {
    printf("Posições dos carros na corrida:\n");
    for (int i = 0; i < numCarros; i++) {
        printf("Carro %d: %d metros (Velocidade Máx: %d km/h)\n",
               carros[i].id, carros[i].distanciaPercorrida, carros[i].velocidadeMaxima);
    }
}

void ajustarVelocidade(Carro *carro) {
    printf("Carro %d: Velocidade Máxima Atual: %d km/h\n", carro->id, carro->velocidadeMaxima);
    printf("Digite a nova velocidade máxima: ");
    scanf("%d", &carro->velocidadeMaxima);
    printf("Velocidade máxima ajustada com sucesso!\n");
}

int verificarVencedores(Carro carros[], int numCarros) {
    int todosVenceram = 1;
    for (int i = 0; i < numCarros; i++) {
        if (carros[i].distanciaPercorrida < DISTANCIA_MAXIMA) {
            todosVenceram = 0;
        } else {
            printf("Carro %d cruzou a linha de chegada!\n", carros[i].id);
        }
    }
    return todosVenceram;
}
