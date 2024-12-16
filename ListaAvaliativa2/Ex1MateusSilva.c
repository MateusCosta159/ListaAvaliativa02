#include <stdio.h>
#include <string.h>
#define TAM 50


struct playlists{
    char nome[50];
    char nomeCriador[50];
    int qtdMusicas;
    float tempo;
};

void exibirMenu();
void adicionarPlaylist(struct playlists p[TAM], int *pos);
void excluirPlaylist(struct playlists p[], int *pos);
void adicionarMusica(struct playlists p[],int *pos);
void exibirPlaylist(struct playlists p[], int *pos);
void removerMusica(struct playlists p[],int *pos);

int main(){

    exibirMenu();

    return 0;
}

void exibirMenu(){
    int opcao;
    int sair = 1;
    int posicao = 0;
    struct playlists playlist[TAM];
    while (sair != 0)
    {
          printf(" Digite a opção que deseja: \n Criar Nova playlist[1]\n Excluir playlist[2]\n Adicionar Música[3]\n Remover Música[4]\n Exibir playlist[5]");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
       adicionarPlaylist(playlist, &posicao);
        break;
    case 2:
        excluirPlaylist(playlist, &posicao);
        break;
    case 3:
        adicionarMusica(playlist, &posicao);
        break;
    case 4:
       removerMusica(playlist, &posicao);
        break;
    case 5:
        exibirPlaylist(playlist, &posicao);
        break;
    
    default:
        printf("Valor invalido");
        break;
    }

    printf(" Digite 0 para sair ou 1 para continuar: ");
    scanf("%d", &sair);
        
    }
}

void adicionarPlaylist(struct playlists p[TAM], int *pos){

    int i;
    char nome[20];
    if (*pos >= TAM) {
        printf("Limite de playlists atingido!\n");
        return;
    }

    printf(" Digite o nome da playlist: ");
    scanf("%s", &nome);
    for (i = 0; i < *pos; i++){
        if(strcmp(p[i].nome, nome) == 0){
            printf("Já existe playlist com esse nome Digite outro:");
            scanf("%s", &nome);
            nome[strcspn(nome, "\n")] = '\0';
            i = -1; 
        }
    }
    strcpy(p[*pos].nome, nome);

    printf(" Digite o nome do Criador: ");
    scanf("%s", &p[*pos].nomeCriador);
    printf(" Digite quantas musicas tem a playlist: ");
    scanf("%d", &p[*pos].qtdMusicas);
    printf(" Digite o tempo em minutos dessa playlist: ");
    scanf("%f", &p[*pos].tempo);

        (*pos)++;
}

void excluirPlaylist(struct playlists p[], int *pos){

    int i, j;
    int encontrou = 0;
    char nome[20];

    if (*pos == 0) {
        printf("\nNenhuma conta cadastrada para excluir.\n");
        return;
    }

    printf("\nDigite o nome da Playlist que deseja excluir: ");
    scanf("%s", &nome);

    for (i = 0; i < *pos; i++) {
        if (strcmp(p[i].nome, nome) == 0) {
            
            for (j = i; j < *pos - 1; j++) {
                p[j] = p[j + 1];
            }

            (*pos)--; 

            printf("\Playlist excluída com sucesso.\n");
            encontrou = 1;
            break;
        }
    }

    if (!encontrou) {
        printf("\Playlist não encontrada.\n");
    }

}

void adicionarMusica(struct playlists p[],int *pos){

    char play[50];
    int i, musi;
    float min;

    printf("Digite a quantidade de musica que deseja adicionar: ");
    scanf("%d", &musi);
    printf("Digite o tempo em minutos: ");
    scanf("%f", &min);

    printf("Digite a playlist que deseja Adicionar a musica: ");
    scanf("%s", &play);

    for (i = 0; i < *pos; i++){
        if(strcmp(p[i].nome, play) == 0){
            p[i].qtdMusicas += musi;
            p[i].tempo += min;
            printf("\Musica adicionada com sucesso.\n");
        }else{
            printf("Playlist não existe");
            break;
        }
    }

}
void removerMusica(struct playlists p[],int *pos){

    char play[50];
    int i, musi;
    float min;

    printf("Digite a quantidade de musica que deseja remover: ");
    scanf("%d", &musi);
    printf("Digite o tempo em minutos que deseja removver: ");
    scanf("%f", &min);

    printf("Digite a playlist que deseja Adicionar a musica: ");
    scanf("%s", &play);

    for (i = 0; i < *pos; i++){
        if(strcmp(p[i].nome, play) == 0){
            p[i].qtdMusicas -= musi;
            p[i].tempo -= min;
            printf("\Musica Removida com sucesso.\n");
        }else{
            printf("Playlist não existe");
            break;
        }
    }

}

void exibirPlaylist(struct playlists p[], int *pos){

    char nome[50];
    int i;

    printf("Digite o nome da playlist que deseja exibir: ");
    scanf("%c", &nome);

    for (i = 0; i < *pos; i++){
        if(strcmp(p[i].nome, nome) == 0){
            printf("Nome: %s \n", p[i].nome);
            printf("Criador: %s \n", p[i].nomeCriador);
            printf("Quantidade de musicas: %d \n", p[i].qtdMusicas);
            printf("Tempo em Minutos: %0.2f \n", p[i].tempo);
        }else{
            printf("Playlist não encontrada");
            break;
        }
    }
}