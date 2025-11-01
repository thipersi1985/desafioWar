#include <stdio.h>
#include <string.h> // Para utilizar o método 'strcspn()'

#define MAX_TERRITORIOS 5
#define TAM_STRING 100

// definição da estrutura (struct)
struct territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// função para limpar o buffer de entrada
void limparBuffer() {      // 'void' - função que não retorna valor
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// função principal
int main() {
    struct territorio meuTerritorio[MAX_TERRITORIOS]; //criação do vetor com espaço para armazenar 5 territórios, mas é expansível, bastando alterar a constante 'MAX_TERRITORIOS'. 
    int totalTerritorio = 0;
    int opcao;

    // laço principal do menu
    do {
        printf("BEM-VINDO AO JOGO WAR!\n");
        printf("============================\n");
        printf("1 - Cadastrar novo território\n");
        printf("2 - Listar todos os territórios\n");
        printf("0 - Sair\n");
        printf("============================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();     // Limpa o '/n' deixado pelo scanf.

        // processamento das opções
        switch (opcao) {
            case 1:     // cadastro
                printf("Cadastro de novo território \n");

                if (totalTerritorio < MAX_TERRITORIOS) {
                    printf("Digite o nome do território: ");
                    fgets(meuTerritorio[totalTerritorio].nome, TAM_STRING, stdin); //stdin - trata-se do Ponteiro do arquivo de onde a string será lida (nesse caso, leitura do teclado).

                    printf("Digite a cor do exército: ");
                    fgets(meuTerritorio[totalTerritorio].cor, TAM_STRING, stdin);   //TAM_STRING - número máximo de caracteres a serem lidos.
                                                                                    //meuTerritorio[] é a variável que armazenará a string, nesse caso, a variável é um vetor, e os atributos (nome e cor) estão na struct.  
                    
                    meuTerritorio[totalTerritorio].nome[strcspn(meuTerritorio[totalTerritorio].nome, "\n")] = '\0'; // Substitui '\n' pelo terminador nulo '\0'
                    meuTerritorio[totalTerritorio].cor[strcspn(meuTerritorio[totalTerritorio].cor, "\n")] = '\0'; // strcspn - Recebe duas strings: a primeira é a string onde a pesquisa é realizada, e a segunda é a string que contém os caracteres de "proibição" ou que servem como referência.

                    printf("Digite a quantidade de tropas: ");
                    scanf("%d", &meuTerritorio[totalTerritorio].tropas);
                    limparBuffer();     // Limpa o '/n' deixado pelo scanf.

                    totalTerritorio++;

                    printf("\nTerritório cadastrado com sucesso!\n");

                } else {
                    printf("Não é possível cadastrar mais territórios.\n\n");
                }
    
            case 2: // LISTAGEM DE TERRITÓRIOS
                printf("MAPA DO MUNDO - ESTADO ATUAL\n");

                if (totalTerritorio == 0){
                    printf("Nenhum território cadastrado ainda.\n");

                } else {
                    for (int i = 0; i < totalTerritorio; i++) {
                        printf("==========================\n");
                        printf("TERRITÓRIO %d\n", i + 1);    // 0 + 1 - primeiro território
                        printf("Nome: %s\n", meuTerritorio[i].nome);
                        printf("Dominado por: Exército %s\n", meuTerritorio[i].cor);
                        printf("Tropas: %d\n", meuTerritorio[i].tropas);
                    }
                    printf("==========================\n");
                }
                // a pausa é crucial para que o usuário veja a lista antes do próximo loop limpar a tela.
                printf("\nPressione enter para continuar...");
                getchar(); // Esta função serve para ler um único caractere da entrada padrão (geralmente o teclado) e retorná-lo como um valor inteiro.
            break;
            
            case 0: // SAIR
                printf("\nSaindo do sistema...\n");
            break;
            
            default: // OPÇÃO INVÁLIDA
                printf("\nOpção inválida! Tente novamente.\n");
                printf("\nPressione Enter para continuar...\n");
                getchar();  //comumente usada em programas C para ler a entrada do usuário, aguardando que o usuário digite algo e pressione Enter.
            break;
        }
    
    } while (opcao !=0);

    return 0;
}