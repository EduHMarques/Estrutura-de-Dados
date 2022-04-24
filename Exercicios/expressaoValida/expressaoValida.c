#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define true 1
#define false 0
 
int checarExpressao(int tamanho, char exp[])
{
    int i;
    int contador = 0;
 
    for (i = 0; i < tamanho; i++)
    {
        if (exp[i] == '(') contador++;
        else if (exp[i] == ')') contador--;
        else return false;
 
        if (contador < 0) return false;
    }
 
    if (contador == 0) return true;
    else return false;
}
 
int main()
{
    int i;
    int contador = 0;
    char expressao[20];
 
    scanf("%s", expressao);
 
    int tamanho = strlen(expressao);
 
    int res = checarExpressao(tamanho, expressao);
 
    if (res == true) printf("A expressao eh valida! :)\n");
    else printf("Expressao Invalida.\n");
    
    return 0;
}