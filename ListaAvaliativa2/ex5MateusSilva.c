#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FORMIGAS 20
#define MAX_NOME 20

typedef enum {
    PROCURANDO_ALIMENTO,
    VOLTANDO_AO_FORMIGUEIRO
} StatusFormiga;

typedef struct {
    char nome[MAX_NOME];
    int energia;
    StatusFormiga status;
} Formiga;

// Funções
void movimentarFormigas(Formiga formigas[], int quantidade);
void coletarAlimento(Formiga formigas[], int quantidade);
void gerenciarEnergia(Formiga formigas[], int quantidade);
void exibirEstadoColonia(Formiga formigas[], int quantidade);
void resgatarFormiga(Formiga *formiga);

int main() {
    Formiga formigas[MAX_FORMIGAS];
    int quantidade = 0;
    int opcao;

    do {
        printf("\nMenu da Colônia de Formigas:\n");
        printf("1. Adicionar uma nova formiga\n");
        printf("2. Movimentar formigas\n");
        printf("3. Simular coleta de alimento\n");
        printf("4. Gerenciar energia\n");
        printf("5. Exibir estado da colônia\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (quantidade < MAX_FORMIGAS) {
                    printf("Digite o nome da formiga: ");
                    scanf("%s", formigas[quantidade].nome);
                    formigas[quantidade].energia = 100;
                    formigas[quantidade].status = PROCURANDO_ALIMENTO;
                    quantidade++;
                } else {
                    printf("Capacidade máxima atingida. Não é possível adicionar mais formigas.\n");
                }
                break;
            case 2:
                movimentarFormigas(formigas, quantidade);
                break;
            case 3:
                coletarAlimento(formigas, quantidade);
                break;
            case 4:
                gerenciarEnergia(formigas, quantidade);
                break;
            case 5:
                exibirEstadoColonia(formigas, quantidade);
                break;
            case 6:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}

void movimentarFormigas(Formiga formigas[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        if (formigas[i].status == PROCURANDO_ALIMENTO) {
            formigas[i].energia -= 5;
            if (formigas[i].energia <= 0) {
                formigas[i].energia = 0;
                formigas[i].status = PROCURANDO_ALIMENTO; 
                printf("A formiga %s ficou sem energia e não pode mais se mover.\n", formigas[i].nome);
            }
        }
    }
}

void coletarAlimento(Formiga formigas[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        if (formigas[i].status == PROCURANDO_ALIMENTO) {
            formigas[i].status = VOLTANDO_AO_FORMIGUEIRO;
            formigas[i].energia += (rand() % 21) + 10; 
            if (formigas[i].energia > 100) {
                formigas[i].energia = 100;
            }
            printf("A formiga %s terminou a coleta e está voltando ao formigueiro com %d de energia.\n",
                    formigas[i].nome, formigas[i].energia);
        }
    }
}

void gerenciarEnergia(Formiga formigas[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        if (formigas[i].energia == 0) {
            resgatarFormiga(&formigas[i]);
            printf("A formiga %s foi resgatada e teve sua energia restaurada para 50.\n", formigas[i].nome);
        }
    }
}

void exibirEstadoColonia(Formiga formigas[], int quantidade) {
    printf("\nEstado da Colônia de Formigas:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Nome: %s, Energia: %d, Status: %s\n",
                formigas[i].nome,
                formigas[i].energia,
                formigas[i].status == PROCURANDO_ALIMENTO ? "Procurando alimento" : "Voltando ao formigueiro");
    }
}

void resgatarFormiga(Formiga *formiga) {
    formiga->energia = 50;
}
