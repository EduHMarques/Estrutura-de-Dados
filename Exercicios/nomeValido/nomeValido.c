#include <stdio.h>
#include <string.h>

#define false 0
#define true 1
#define ALFABET_TAM 26

int checaCaractere(char caractere, char letrasValidas[])
{
    int i;

    for (i = 0; i < ALFABET_TAM; i++)
    {
        if (caractere == letrasValidas[i]) return true;
    }

    return false;
}

int checaValidez(char nome[], char LETRAS[], char letras[], int tamanhoNome)
{
    int i;
    
    if (tamanhoNome <= 0) return false;
    if (checaCaractere(nome[0], LETRAS) == 0) return false;

    for (i = 1; i < tamanhoNome; i++)
    {
        if (checaCaractere(nome[i], letras) == 0 && nome[i] != ' ')
        {
            if (nome[i - 1] != ' ') return false;
        } 
        if (nome[i] == ' ' && checaCaractere(nome[i + 1], LETRAS) == 0) return false;
    }

    return true;
}

int main()
{
    char letras[ALFABET_TAM] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char LETRAS[ALFABET_TAM] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    char nome[50];
    fgets(nome, 50, stdin);

    int tamanhoNome = strlen(nome);
    int validezNome = checaValidez(nome, LETRAS, letras, tamanhoNome - 1);

    if (validezNome == true) printf("Seu nome eh valido.\n");
    else printf("Seu nome eh invalido.\n");

    return 0;
}