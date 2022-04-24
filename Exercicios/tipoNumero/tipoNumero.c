#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

int checaCaractereArray(char caractere, char array[], int tamanhoArray)
{
    for (int i = 0; i < tamanhoArray; i++)
    {
        if (caractere == array[i]) return true;
    }
    return false;
}

int checaValidez(char valor[], int tamanho)
{   
    char digitos[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char sinais[2] = {'+', '-'};
    int virgulas = 0;
    int neg = 0;
    int i;

    if (checaCaractereArray(valor[0], sinais, 2) == 0 && checaCaractereArray(valor[0], digitos, 10) == 0)  
    {
        return false;
    }
    if (valor[0] == '-') neg = 1;

    for (i = 1; i < tamanho; i++)
    {
        char caractere = valor[i];

        if (checaCaractereArray(caractere, digitos, 10) == 0 && caractere != ',' && i != 0)
        {
            return false;
        }
        if (caractere == ',')
        {
            if (virgulas >= 1 || i == tamanho - 1) return false;
            virgulas++;
        }  
    }

    if (neg == 0 && virgulas == 0) return 1;  // Natural
    else if (neg == 1 && virgulas == 0) return 2; // Inteiro
    else return 3; // Real
}   

int main()
{
    char valor[100];

    fgets(valor, 100, stdin);

    int tamanho = strlen(valor);
    tamanho--;

    int validez = checaValidez(valor, tamanho);

    if (validez == 0) printf("Valor Invalido.\n");
    else if (validez == 1) printf("Valor Natural.\n");
    else if (validez == 2) printf("Valor Inteiro.\n");
    else printf("Valor Real.\n");

    return 0;
}