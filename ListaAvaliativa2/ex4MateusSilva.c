#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_TABULEIRO 10

void posicionarNavios(int *tabuleiro, int tamanho);
void realizarDisparo(int *tabuleiro, int tamanho);
int verificarVitoria(int *tabuleiro, int tamanho);
int validarPosicao(int *tabuleiro, int tamanho, int posicao);
void exibirTabuleiro(int *tabuleiro, int tamanho);

int main() {
    int tabuleiro[TAMANHO_TABULEIRO] = {0};
    int tamanho = TAMANHO_TABULEIRO;
    int opcao;

    posicionarNavios(tabuleiro, tamanho);

    do {
        printf("\nBatalha Naval:\n");
        printf("1. Realizar disparo\n");
        printf("2. Exibir tabuleiro\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                realizarDisparo(tabuleiro, tamanho);
                break;
            case 2:
                exibirTabuleiro(tabuleiro, tamanho);
                break;
            case 3:
                printf("Encerrando o jogo.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        if (verificarVitoria(tabuleiro, tamanho)) {
            printf("Parabéns! Você destruiu todos os navios. Você venceu!\n");
            break;
        }
    } while (opcao != 3);

    return 0;
}

void posicionarNavios(int *tabuleiro, int tamanho) {
    srand(time(NULL));
    int navios = 5;

    while (navios > 0) {
        int posicao = rand() % tamanho;
        if (*(tabuleiro + posicao) == 0) {
            *(tabuleiro + posicao) = 1;
            navios--;
        }
    }
}

void realizarDisparo(int *tabuleiro, int tamanho) {
    int posicao;
    printf("Digite a posição para disparo (0 a 9): ");
    scanf("%d", &posicao);

    if (posicao >= 0 && posicao < tamanho) {
        if (validarPosicao(tabuleiro, tamanho, posicao)) {
            printf("Posição já atacada.\n");
        } else {
            if (*(tabuleiro + posicao) == 1) {
                *(tabuleiro + posicao) = -1;
                printf("Acertou um navio!\n");
            } else {
                *(tabuleiro + posicao) = -1;
                printf("Água atingida.\n");
            }
        }
    } else {
        printf("Posição inválida. Tente novamente.\n");
    }
}

int verificarVitoria(int *tabuleiro, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (*(tabuleiro + i) == 1) {
            return 0;
        }
    }
    return 1;
}

int validarPosicao(int *tabuleiro, int tamanho, int posicao) {
    return *(tabuleiro + posicao) == -1;
}

void exibirTabuleiro(int *tabuleiro, int tamanho) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < tamanho; i++) {
        if (*(tabuleiro + i) == 0) {
            printf(" ~ ");
        } else if (*(tabuleiro + i) == 1) {
            printf(" N ");
        } else if (*(tabuleiro + i) == -1) {
            printf(" X ");
        }
    }
    printf("\n");
}
