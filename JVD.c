#include <stdio.h>
#include <stdlib.h>

char tabuleiro[3][3];
char player = 'X';

void inicializarTabuleiro() {
    char pos = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) 
            tabuleiro[i][j] = pos++;
}

void Tabuleiro() {
    system("cls");
    printf("\n     1   2   3\n\n");

    for (int i = 0; i < 3; i++)
    {
        printf(" %d   ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            char c = tabuleiro[i][j];
            if (c == 'X')
            {
                printf("\033[1;31mX\033[0m");
            }
            else if (c == 'O')
            {
                printf("\033[1;34mO\033[0m");
            }
            else
            {
                printf("%c", c);
            }

            if (j < 2)
                printf(" | ");
        }
        printf("\n");
        if (i < 2)
            printf("    ---|---|---\n");
    }

    printf("\n");
}

int verificarVitoria() {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) return 1;
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]) return 1;
    }
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) return 1;
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) return 1;
    return 0;
}

int verificarEmpate() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tabuleiro[i][j] != 'X' && tabuleiro[i][j] != 'O')
                return 0;
    return 1;
}

void instrucoes() {
    system("cls");
    printf("=== INSTRUCOES DO JOGO ===\n\n");
    printf("1. Dois jogadores alternam jogadas.\n");
    printf("2. O jogador escolhe uma posicao de 1 a 9.\n");
    printf("3. Vence quem formar uma linha, coluna ou diagonal.\n");
    printf("4. Se todas as posicoes forem preenchidas e ninguem vencer, da empate.\n\n");
    system("pause");
}

void jogarTurno() {
    char escolha;
    int linha, coluna;

    Tabuleiro();
    printf("\n Jogador %c, escolha uma posicao (1-9): ", player);
    scanf(" %c", &escolha);

    int valido = 0;
    for (linha = 0; linha < 3; linha++) {
        for (coluna = 0; coluna < 3; coluna++) {
            if (tabuleiro[linha][coluna] == escolha) {
                tabuleiro[linha][coluna] = player;
                valido = 1;
                break;
            }
        }
        if (valido) break;
    }

    if (!valido) {
        printf("Posicao invalida ou casa ocupada. Escolha outra.\n");
        system("pause");
        jogarTurno();
    }
}

void jogar() {
    player = 'X';
    inicializarTabuleiro();

    while (1) {
        jogarTurno();

        if (verificarVitoria()) {
            Tabuleiro();
            printf("Parabens! Jogador %c venceu!\n", player);
            break;
        }

        if (verificarEmpate()) {
            Tabuleiro();
            printf("Empate! Ninguem venceu.\n");
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    printf("\nFim de jogo!\n");
    system("pause");
}

int main() {
    int opcao;

    do {
        system("cls");
        printf("=== MENU PRINCIPAL ===\n");
        printf("1. Jogar\n");
        printf("2. Instrucoes\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                jogar();
                break;
            case 2:
                instrucoes();
                break;
            case 3:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                system("pause");
        }
    } while (opcao != 3);

    return 0;
}
