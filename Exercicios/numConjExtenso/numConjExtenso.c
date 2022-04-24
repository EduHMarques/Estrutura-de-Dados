#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define numDigitos 11

int checaValidez(int tamanho, char string[])
{
   int j, i = 0;
   int virgulas = 0;
   char digitos[numDigitos] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ','};
   if (string[0] == '+' || string[0] == '-') i = 1;
   if(string[i] == ',') return false;

    for (; i < tamanho; i++)
    {
        char digito = string[i];
        for (j = 0; j < numDigitos; j++)
        {
            if (digitos[j] == digito) break;
            if (j == numDigitos - 1 && digitos[j] != digito) return false;
        }
        if (digito == ',') virgulas++;
    }
    if (virgulas > 1 || string[tamanho - 1] == ',') return false;
    return true;
}

void escreverNumeracao(int conj, int resto, char cent)
{
    if (resto != 0) conj += 1;

    if (conj == 5) printf("trilhao ");
    else if (conj == 4) printf("bilhao ");
    else if (conj == 3) printf("milhao ");
    else if (conj == 2) printf("mil ");

    if (cent == '0' && conj > 1) printf("e ");          
}

void centena(char cent, char dez, char uni)
{
    if (cent == '1' && dez == '0' && uni == '0') printf("cem ");
    else if (cent == '1')
    {
        printf("cento ");
        if (dez != '0' || uni != '0') printf("e ");
    } 

    if (cent == '2') printf("duzentos ");
    else if (cent == '3') printf("trezentos ");
    else if (cent == '4') printf("quatrocentos ");
    else if (cent == '5') printf("quinhentos ");
    else if (cent == '6') printf("seiscentos ");
    else if (cent == '7') printf("setecentos ");
    else if (cent == '8') printf("oitocentos ");
    else if (cent == '9') printf("novecentos ");
    else return;

    if (dez != '0' || uni != '0') printf("e ");
}

void dezena (char dez, char uni)
{
    if (dez == '1' && uni == '0') printf("dez ");
    else if (dez == '1' && uni == '1') printf("onze ");
    else if (dez == '1' && uni == '2') printf("doze ");
    else if (dez == '1' && uni == '3') printf("treze ");
    else if (dez == '1' && uni == '4') printf("quatorze ");
    else if (dez == '1' && uni == '5') printf("quinze ");
    else if (dez == '1' && uni == '6') printf("dezesseis ");
    else if (dez == '1' && uni == '7') printf("dezessete ");
    else if (dez == '1' && uni == '8') printf("dezoito ");
    else if (dez == '1' && uni == '9') printf("dezenove ");

    if (dez == '2') printf("vinte ");
    else if (dez == '3') printf("trinta ");
    else if (dez == '4') printf("quarenta ");
    else if (dez == '5') printf("cinquenta ");
    else if (dez == '6') printf("sessenta ");
    else if (dez == '7') printf("setenta ");
    else if (dez == '8') printf("oitenta ");
    else if (dez == '9') printf("noventa ");
    else return;

    if (uni != '0' && dez != '1') printf("e ");
}

void unidade(char uni, int conj, int j)
{
    if (uni == '1' && conj == 1 && j == 0) return;

    if (uni == '1') printf("um ");
    else if (uni == '2') printf("dois ");
    else if (uni == '3') printf("tres ");
    else if (uni == '4') printf("quatro ");
    else if (uni == '5') printf("cinco ");
    else if (uni == '6') printf("seis ");
    else if (uni == '7') printf("sete ");
    else if (uni == '8') printf("oito ");
    else if (uni == '9') printf("nove ");
    else if (uni == '0') printf("zero ");
}

void escreverConj(int posFinal, char valor[], int conj, int j)
{
    centena(valor[posFinal - 2], valor[posFinal - 1], valor[posFinal]);
    dezena(valor[posFinal - 1], valor[posFinal]);

    if (valor[posFinal - 1] != '1') unidade(valor[posFinal], conj, j);
}

void escreverNumCompleto(char valor[], int tamNum)
{
    int i = 0;
    int posVirgula = 0;
    int tamanhoNumeroPrimario = 0;
    int virgulas = 0;

    for (i = 0; i < tamNum; i++)
    {
        if (valor[i] == ',') virgulas++;
    }
    if (virgulas > 1) return;

    i = 0;

    for (; posVirgula < tamNum; posVirgula++)
    {
        if (valor[posVirgula] == ',') break;
    }

    if (valor[0] == '+' || valor[0] == '-') 
    {
        if (valor[0] == '-') printf("menos ");
        i = 1;
    } 

    tamanhoNumeroPrimario = posVirgula - i;

    int conj = tamanhoNumeroPrimario / 3;
    int resto = tamanhoNumeroPrimario % 3;
    int posConj = resto + 3;
    int j = 0;

    if (resto != 0)
    {
        escreverConj((resto + i) - 1, valor, conj, j);
        escreverNumeracao(conj, resto, valor[posConj - 3]);
        j++;
    }
    resto = 0;
    for (; conj > 0; conj--)
    {
        printf("feio");
        escreverConj((posConj + i) - 1, valor, conj, j);
        escreverNumeracao(conj, resto, valor[posConj - 3]);
        posConj += 3;
        j++;
    }

    if (valor[posVirgula] == ',') printf("virgula ");

    int aux;

    for (posVirgula++; posVirgula < tamNum; posVirgula++)
    {
        char digito = valor[posVirgula];
        for (aux = posVirgula; aux < tamNum; aux++)
        {
            if (valor[aux] != '0') break;
            if (aux == tamNum - 1 && valor[aux] == '0')
            {
                return;
            } 
        }
        unidade(digito, 1, 1);
    }
}

int main()
{
    int i = 0;
    char valor[15];

    scanf("%s", valor);

    int tamNum = strlen(valor);
    int validez = checaValidez(tamNum, valor);

    if (validez == 0)
    {
        printf("Valor invalido.\n"); 
        return 0;
    }

    escreverNumCompleto(valor, tamNum);

    return 0;
}