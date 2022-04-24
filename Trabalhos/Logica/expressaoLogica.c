#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

int inferencia(char operacao, char esquerda, char direita)
{
    int p, q;

    if (esquerda == 'V') p = true;
    else p = false;
    if (direita == 'V') q = true;
    else q = false;

    if (operacao == '^')            // Conjunção
    {
        return (p && q);
    }
    else if (operacao == 'v')       // Disjunção
    {
        return (p || q);
    }
    else if (operacao == 's')       // Implicação
    {
        if (p == true && q == false) return false;
        else return true;
    }
    else                            // Dupla implicação
    {
        if (p != q) return false;
        else return true;
    }
}

int checaElem(char elemento, char array[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (array[i] == elemento) return true;
    }
    return false;
}

int main()
{
    int i, j;
    char operadores[4] = {'v', '^', 's', 'd'};
    char atomos[2] = {'V', 'F'};
    char expressao[10];
    char pilhaOp[10];
    char pilhaAtom[10];
    int topoOperador = -1;
    int topoAtomos = -1;

    printf("Digite a expressao: ");
    scanf("%s", &expressao);                    // Trocar por fgets.

    getchar();

    int tamExpressao = strlen(expressao);

    for (i = 0; i < tamExpressao; i++)          // Passando os operandos para a pilha.
    {
        int ehAtomo = checaElem(expressao[i], atomos, 2);
        if (ehAtomo)
        {
            topoAtomos++;
            pilhaAtom[topoAtomos] = expressao[i];
        }
    }

    for (i = 0; i < tamExpressao; i++)          // Passando os operadores para a pilha.
    {
        int ehOperador = checaElem(expressao[i], operadores, 4);
        if (ehOperador)
        {
            topoOperador++;
            pilhaOp[topoOperador] = expressao[i];
        }
    }

    printf("Pilha Atomos\n[");
    for (i = 0; i <= topoAtomos; i++)
    {
        printf("%c ", pilhaAtom[i]);
    }
    printf("]\n");
    printf("Pilha Operadores\n[");
    for (i = 0; i <= topoOperador; i++)
    {
        printf("%c ", pilhaOp[i]);
    }
    printf("]\n");

    char atomTemp[10];
    char opTemp[10];

    j = 0;
    // printf("topo atomos: %d\n", topoAtomos);
    for (i = topoAtomos; i >= 0; i--)
    {
        atomTemp[j] = pilhaAtom[i];
        j++;
    }
    j = 0;
    for (i = topoOperador; i >= 0; i--)
    {
        opTemp[j] = pilhaOp[i];
        j++;
    }

    // printf("\nPilha temp Atomos\n[");
    // for (i = 0; i <= topoAtomos; i++)
    // {
    //     printf("%c ", atomTemp[i]);
    // }
    // printf("]\n");
    // printf("Pilha temp Operadores\n[");
    // for (i = 0; i <= topoOperador; i++)
    // {
    //     printf("%c ", opTemp[i]);
    // }
    // printf("]\n");

    printf("\nOperacao:\n");

    for (i = topoOperador; i >= 0; i--)
    {
        printf("Pilha Atomos\n[");
        for (j = 0; j <= topoAtomos; j++)
        {
            printf("%c ", atomTemp[j]);
        }
        printf("]\n");
        printf("Pilha Operadores\n[");
        for (j = 0; j <= topoOperador; j++)
        {
            printf("%c ", opTemp[j]);
        }
        printf("]\n");
        
        char operador = opTemp[i];
        // printf("topo: %d, operador: %c\n", i, operador);
        char p = atomTemp[topoAtomos];
        char q = atomTemp[topoAtomos - 1];

        // printf("i: %d, p: %c, q: %c, op: %c\n", i, p, q, operador);
        
        int resultado = inferencia(operador, p, q);

        // printf("i: %d, p: %c, q: %c, op: %c, res: %d\n", i, p, q, operador, resultado);

        topoAtomos--;
        if (resultado == true) atomTemp[topoAtomos] = 'V';
        else atomTemp[topoAtomos] = 'F';
        topoOperador--;
    }

    printf("Pilha Atomos\n[");
    for (i = 0; i <= topoAtomos; i++)
    {
        printf("%c ", atomTemp[i]);
    }
    printf("]\n");

    printf("Pilha Operadores\n[");
    for (i = 0; i <= topoOperador; i++)
    {
        printf("%c ", opTemp[i]);
    }
    printf("]\n");

    // printf("Expressao: %s", expressao);

    return 0;
}