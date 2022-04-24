#include <stdio.h>

#define true 1
#define false 0
#define BOARD_SIZE 3

void printarTabuleiro(char tabuleiro[][BOARD_SIZE])
{
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int checaVitoria(char tabuleiro[][BOARD_SIZE], char player)
{
    if (tabuleiro[0][0] == player && tabuleiro[1][0] == player && tabuleiro[2][0] == player) return true;       // Coluna 0 preenchida
    else if (tabuleiro[0][1] == player && tabuleiro[1][1] == player && tabuleiro[2][1] == player) return true;  // Coluna 1 preenchida
    else if (tabuleiro[0][2] == player && tabuleiro[1][2] == player && tabuleiro[2][2] == player) return true;  // Coluna 2 preenchida
    else if (tabuleiro[0][0] == player && tabuleiro[0][1] == player && tabuleiro[0][2] == player) return true;  // Linha 0 preenchida
    else if (tabuleiro[1][0] == player && tabuleiro[1][1] == player && tabuleiro[1][2] == player) return true;  // Linha 1 preenchida
    else if (tabuleiro[2][0] == player && tabuleiro[2][1] == player && tabuleiro[2][2] == player) return true;  // Linha 2 preenchida
    else if (tabuleiro[0][0] == player && tabuleiro[1][1] == player && tabuleiro[2][2] == player) return true;  // Diagonal principal preenchida
    else if (tabuleiro[0][2] == player && tabuleiro[1][1] == player && tabuleiro[2][0] == player) return true;  // Diagonal secundaria preenchida
    else return false;
}

void escolherJogada(char tabuleiro[][BOARD_SIZE])
{
    int i, j;
    int jogadas = 0;
    int maxJogadas = 9;


    while(1)
    {
        printf("Vez do Jogador 1\n\n");

        while(1)
        {
            int posI, posJ;
            printf("Escolha a linha de X: ");
            scanf("%d", &posI);
            printf("Agora escolha a coluna de X: ");
            scanf("%d", &posJ);

            posI--;
            posJ--;

            if (posI < 0 || posI > 2 || posJ < 0 || posJ > 2 || tabuleiro[posI][posJ] != '-') printf("Valor invalido, digite novamente.\n");
            else
            {
                tabuleiro[posI][posJ] = 'X';
                jogadas++;
                printf("\n");
                break;
            }
        }

        printarTabuleiro(tabuleiro);

        if (checaVitoria(tabuleiro, 'X'))
        {
            printf("\nJogador 1 ganhou!!!\n"); break;
        }
        else if (jogadas >= 9)
        {
            printf("\nHouve empate!\n");
            break;
        } 

        printf("\nVez do Jogador 2\n\n");

        while(1)
        {
            int posI, posJ;
            printf("Escolha a linha de O: ");
            scanf("%d", &posI);
            printf("Agora escolha a coluna de O: ");
            scanf("%d", &posJ);

            posI--;
            posJ--;

            if (posI < 0 || posI > 2 || posJ < 0 || posJ > 2 || tabuleiro[posI][posJ] != '-') printf("Valor invalido, digite novamente.\n");
            else
            {
                tabuleiro[posI][posJ] = 'O';
                jogadas++;
                printf("\n");
                break;
            } 
        }

        printarTabuleiro(tabuleiro);

        if (checaVitoria(tabuleiro, 'O'))
        {
            printf("\nJogador 2 ganhou!!!\n"); break;
        }
        else if (jogadas >= 9)
        {
            printf("\nHouve empate!\n"); 
            break;
        } 
    }
}

int main()
{
    int i, j;
    char tabuleiro[BOARD_SIZE][BOARD_SIZE];

    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            tabuleiro[i][j] = '-';
        }
    }

    escolherJogada(tabuleiro);

    return 0;
}