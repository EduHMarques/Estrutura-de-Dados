#include <stdio.h>

/*
    Funções para aplicar:
        - Retornar a cabeça;
        - Retornar a cauda;
        - Concatenar arrays;
        - Printar elementos;                            x
        - Adicionar elementos;                          x
        - Remover elementos;                            x
        - Retornar comprimento do array;                x
        - Verificar se um elemento existe no array;     x
        - Inverter array;
*/

#define ARRAY_SIZE 10

void addElem(int array[], int *tamanho)
{
    if (*tamanho == ARRAY_SIZE)
    {
        printf("Lista cheia!\n");
        return;
    }

    int elem, i, j;

    printf("Digite o elemento da posicao %d: \n", *tamanho + 1);
    scanf("%d", &elem);

    array[*tamanho] = elem;
    *tamanho = *tamanho + 1;
    return;
}

void removerElemento(int array[], int *tamanho)
{
    int i;
    if (*tamanho <= 0)
    {
        printf("Lista vazia!\n");
        return;
    }

    int elem;

    printf("Digite o elemento que voce deseja remover: \n");
    scanf("%d", &elem);

    for(i = 0; i < *tamanho; i++)
    {
        if (array[i] == elem)
        {
            for(; i < *tamanho; i++)
            {
                array[i] = array[i + 1];
            }
            *tamanho = *tamanho - 1;
            printf("Elemento removido.\n");
            return;
        }
    }
    printf("Elemento nao encontrado.\n");
    return;
}

void printarLista(int array[], int elementos)
{
    int i;
    for(i = 0; i < elementos; i++)
    {
        if (i == elementos - 1)
        {
            printf("%d", array[i]);
            break;
        }
        else printf("%d, ", array[i]);
    }
    printf("\n");
}

void tamanhoLista(int tamanho)
{
    printf("A lista possui %d elementos.\n", tamanho);
    return;
}

void verificarElemento(int array[], int tamanho)
{   
    int i;
    if (tamanho <= 0)
    {
        printf("Lista vazia!\n");
        return;
    }

    int elemento;

    printf("Digite o elemento que voce deseja checar: \n");
    scanf("%d", &elemento);
    
    for(i = 0; i < tamanho; i++)
    {
        if (array[i] == elemento)
        {
            printf("O valor %d existe na lista.\n", elemento);
            return;
        }
    }
    printf("O valor %d nao existe na lista.\n", elemento);
    return;
}

void lobby()
{
    int array[10];
    int numElem = 0;
    int *p;
    int inserir, i;

    p = &numElem;

    while(1)
    {
        int comando;
        
        printf("\nDIGITE O COMANDO QUE VOCE DESEJA REALIZAR: \n");
        printf("[1] - Adicionar elemento\n");
        printf("[2] - Remover elemento\n");
        printf("[3] - Printar lista\n");
        printf("[4] - Exibir tamanho da lista\n");
        printf("[5] - Checar elemento\n");
        printf("[0] - Fechar programa\n");

        scanf("%d", &comando);

        if (comando == 1)
        {
            addElem(array, p);
        }
        else if (comando == 2)
        {
            removerElemento(array, p);
        }
        else if (comando == 3)
        {
            printarLista(array, numElem);
        }
        else if (comando == 4)
        {
            tamanhoLista(numElem);
        }
        else if (comando == 5)
        {
            verificarElemento(array, numElem);
        }
        else if (comando == 0) break;
        else printf("Comando invalido!\n");
    }
}

int main()
{
    lobby();

    return 0;
}