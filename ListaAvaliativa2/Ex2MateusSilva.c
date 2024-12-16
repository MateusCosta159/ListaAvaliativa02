#include <stdio.h>
#include <string.h>
#define TAM 50

struct serieFilme {
    char nome[50];
    int tipo;
    int status;
};
void exibirMenu();
void adicionar(struct serieFilme sf[TAM], int *pos);
void atualizar(struct serieFilme sf[TAM], int *pos);
void mostrarCatalogo(struct serieFilme sf[TAM], int *pos);
int main(){

    exibirMenu();

    return 0;
}

void exibirMenu(){

    int posicao = 0, opcao, sair = 1;
    struct serieFilme sf[TAM];

    while (sair =! 0){

        printf("Digite o que quer fazer: \n"
        "\n"
        "Adicionar Série ou Filme[1] \n"
        "Atualizar Status[2] \n"
        "Consultar Catálogo[3] \n"
        "Excluir entrada[4] \n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionar(sf, &posicao);
            break;
        case 2:
            atualizar(sf, &posicao);
            break;
        case 3:
            mostrarCatalogo(sf, &posicao);
            break;
        case 4:
        
            break;
        
        default:
            printf("O numero digitado não é valido");
            break;
        }

        printf("Digite [0] para sair ou [1] para continuar: ");
        scanf("%d", &sair);
    }
    
}
void adicionar(struct serieFilme sf[TAM], int *pos){

    printf("Vamos adicionar sua Série ou Filme \n");

    int i;
    int tipo, status;
    char nome[20];
    if (*pos >= TAM) {
        printf("Limite de Series ou filme atingido!\n");
        return;
    }

    printf("Digite o nome: ");
    scanf("%19s", &nome);
    for (i = 0; i < *pos; i++){
        if(strcmp(sf[i].nome, nome) == 0){
            printf("Já existe Serie ou Filme com esse nome Digite outro:");
            scanf("%19s", &nome);
            nome[strcspn(nome, "\n")] = '\0';
            i = -1; 
        }
    }
    strcpy(sf[*pos].nome, nome);

        do {
        printf("Digite o tipo: Série[0] ou Filme[1]: ");
        scanf("%d", &tipo);
        if (tipo != 0 && tipo != 1) {
            printf("Valor inválido. Digite 0 para Série ou 1 para Filme.\n");
        }
        } while (tipo != 0 && tipo != 1);
    sf[*pos].tipo = tipo;

        do {
        printf("Digite o Status: Não iniciado[0], Iniciado[1], Concluído[2]: ");
        scanf("%d", &status);
        if (status < 0 || status > 2) {
            printf("Valor inválido. Digite 0 para Não iniciado, 1 para Iniciado ou 2 para Concluído.\n");
        }
        } while (status < 0 || status > 2);
    sf[*pos].status = status;
    (*pos)++;
    printf("Item cadastrado com Sucesso \n");
}
void atualizar(struct serieFilme sf[TAM], int *pos){

    int i;
    int tipo, status;
    char nome[20];

    printf("Digite o nome: ");
    scanf("%s", &nome);
    do {
        printf("Digite o tipo: Série[0] ou Filme[1]: ");
        scanf("%d", &tipo);
        if (tipo != 0 && tipo != 1) {
            printf("Valor inválido. Digite 0 para Série ou 1 para Filme.\n");
        }
        } while (tipo != 0 && tipo != 1);
   

        do {
        printf("Digite o Status: Não iniciado[0], Iniciado[1], Concluído[2]: ");
        scanf("%d", &status);
        if (status < 0 || status > 2) {
            printf("Valor inválido. Digite 0 para Não iniciado, 1 para Iniciado ou 2 para Concluído.\n");
        }
        } while (status < 0 || status > 2);

      for (i = 0; i < *pos; i++){
        if(strcmp(sf[i].nome, nome) == 0){
            sf[i].status = status;
            sf[i].tipo = tipo;
            printf("\Atualizado com sucesso.\n");
        }else{
            printf("Série ou Filme não existe");
            break;
        }
    }
}

void mostrarCatalogo(struct serieFilme sf[TAM], int *pos){
  
    printf("Aqui está sua lista de Séries e Filmes:\n");

    // Exibe os itens com status 0 (Não Iniciado)
    for (int i = 0; i < *pos; i++) {
        if(sf[i].status == 0){
            printf("Nome: %s\n", sf[i].nome);
            if(sf[i].tipo == 0){
                printf("Tipo: Série \n");
            }else{
                printf("Tipo: Filme \n");
            }
            printf("Status: Não Iniciado\n\n");
        }
    }

    // Exibe os itens com status 1 (Iniciado)
    for (int i = 0; i < *pos; i++) {
        if(sf[i].status == 1){
            printf("Nome: %s\n", sf[i].nome);
            if(sf[i].tipo == 0){
                printf("Tipo: Série \n");
            }else{
                printf("Tipo: Filme \n");
            }
            printf("Status: Iniciado\n\n");
        }
    }

    // Exibe os itens com status 2 (Concluído)
    for (int i = 0; i < *pos; i++) {
        if(sf[i].status == 2){
            printf("Nome: %s\n", sf[i].nome);
            if(sf[i].tipo == 0){
                printf("Tipo: Série \n");
            }else{
                printf("Tipo: Filme \n");
            }
            printf("Status: Concluído\n\n");
        }
    }
}


void excluirPlaylist(struct serieFilme sf[TAM], int *pos){

    int i, j;
    int encontrou = 0;
    char nome[20];

    if (*pos == 0) {
        printf("\nNenhuma Serie ou Filme cadastrada para excluir.\n");
        return;
    }

    printf("\nDigite o nome que deseja excluir: ");
    scanf("%s", &nome);

    for (i = 0; i < *pos; i++) {
        if (strcmp(sf[i].nome, nome) == 0) {
            
            for (j = i; j < *pos - 1; j++) {
                sf[j] = sf[j + 1];
            }

            (*pos)--; 

            printf("Playlist excluída com sucesso.\n");
            encontrou = 1;
            break;
        }
    }

    if (!encontrou) {
        printf("Série ou filme não encontrada.\n");
    }

}

