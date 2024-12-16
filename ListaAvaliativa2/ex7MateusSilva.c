#include <stdio.h>
#include <string.h>

#define MAX_ANIMAIS 20
#define MAX_ESPECIE 30

typedef struct {
    int id;
    char especie[MAX_ESPECIE];
    float peso;
    int statusSaude; // 0 - Saudável, 1 - Em tratamento
} Animal;

// Funções
void registrarAnimal(Animal animais[], int *quantidade);
void atualizarStatus(Animal *animal);
void calcularMediaPesoPorEspecie(Animal animais[], int quantidade);
void exibirEmTratamento(Animal animais[], int quantidade);
void removerAnimal(Animal animais[], int *quantidade);

int main() {
    Animal animais[MAX_ANIMAIS];
    int quantidade = 0;
    int opcao;

    do {
        printf("\nMenu do Zoológico:\n");
        printf("1. Registrar um novo animal\n");
        printf("2. Atualizar status de saúde\n");
        printf("3. Calcular média de peso por espécie\n");
        printf("4. Exibir animais em tratamento\n");
        printf("5. Remover animal do sistema\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registrarAnimal(animais, &quantidade);
                break;
            case 2: {
                int id;
                printf("Digite o ID do animal para atualizar o status: ");
                scanf("%d", &id);
                for (int i = 0; i < quantidade; i++) {
                    if (animais[i].id == id) {
                        atualizarStatus(&animais[i]);
                        break;
                    }
                }
                break;
            }
            case 3:
                calcularMediaPesoPorEspecie(animais, quantidade);
                break;
            case 4:
                exibirEmTratamento(animais, quantidade);
                break;
            case 5:
                removerAnimal(animais, &quantidade);
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

void registrarAnimal(Animal animais[], int *quantidade) {
    if (*quantidade >= MAX_ANIMAIS) {
        printf("Capacidade máxima atingida. Não é possível registrar mais animais.\n");
        return;
    }

    Animal novoAnimal;
    printf("Digite o ID do animal: ");
    scanf("%d", &novoAnimal.id);
    
    printf("Digite a espécie do animal: ");
    scanf("%s", novoAnimal.especie);

    printf("Digite o peso do animal: ");
    scanf("%f", &novoAnimal.peso);

    printf("Digite o status de saúde (0 - Saudável, 1 - Em tratamento): ");
    scanf("%d", &novoAnimal.statusSaude);

    for (int i = 0; i < *quantidade; i++) {
        if (animais[i].id == novoAnimal.id && strcmp(animais[i].especie, novoAnimal.especie) == 0) {
            printf("Já existe um animal com o mesmo ID e espécie registrado.\n");
            return;
        }
    }

    animais[*quantidade] = novoAnimal;
    (*quantidade)++;
    printf("Animal registrado com sucesso!\n");
}

void atualizarStatus(Animal *animal) {
    printf("Atualizando status do animal com ID %d (Espécie: %s).\n", animal->id, animal->especie);
    printf("Status atual: %s\n", animal->statusSaude == 0 ? "Saudável" : "Em tratamento");

    printf("Digite o novo status de saúde (0 - Saudável, 1 - Em tratamento): ");
    scanf("%d", &animal->statusSaude);

    printf("Status atualizado com sucesso!\n");
}

void calcularMediaPesoPorEspecie(Animal animais[], int quantidade) {
    char especie[MAX_ESPECIE];
    printf("Digite a espécie para calcular a média de peso: ");
    scanf("%s", especie);

    float somaPesos = 0;
    int contador = 0;

    for (int i = 0; i < quantidade; i++) {
        if (strcmp(animais[i].especie, especie) == 0) {
            somaPesos += animais[i].peso;
            contador++;
        }
    }

    if (contador > 0) {
        printf("A média de peso para a espécie %s é %.2f kg.\n", especie, somaPesos / contador);
    } else {
        printf("Não foram encontrados animais da espécie %s.\n", especie);
    }
}

void exibirEmTratamento(Animal animais[], int quantidade) {
    printf("Animais em tratamento:\n");

    for (int i = 0; i < quantidade; i++) {
        if (animais[i].statusSaude == 1) {
            printf("ID: %d, Espécie: %s, Peso: %.2f kg\n", 
                animais[i].id, animais[i].especie, animais[i].peso);
        }
    }
}

void removerAnimal(Animal animais[], int *quantidade) {
    int id;
    printf("Digite o ID do animal a ser removido: ");
    scanf("%d", &id);

    for (int i = 0; i < *quantidade; i++) {
        if (animais[i].id == id) {
            for (int j = i; j < *quantidade - 1; j++) {
                animais[j] = animais[j + 1];
            }

            (*quantidade)--;
            printf("Animal removido com sucesso!\n");
            return;
        }
    }

    printf("Animal com ID %d não encontrado.\n", id);
}
