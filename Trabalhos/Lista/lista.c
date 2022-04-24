#include <stdio.h>

/*
        Lista estática com gaps preferencialmente no início.
            Antepenultimo nome: Henrique
                Gaps preferencialmente no início separados.

        Por isso, coloquei para que os números sejam inseridos à direita na lista.
        Além disso, o shift é executado de modo que os valores vão para direita e os gaps para a esquerda.
        O shift pode ser executado manualmente, mas também é executado a cada 5 remoções de elementos.

        - Caso tenha um gap entre elementos, o próximo elemento a ser inserido, irá ocupar o espaço desse gap,
        economizando um pouco de processamento na hora do próximo shift.
    */

#define ARRAY_SIZE 20

void addElem(int array[], int* tamanho)
{
    if (*tamanho == ARRAY_SIZE)
    {
        printf("Lista cheia!\n");
        return;
    }

    int elem, i;

    printf("Digite o elemento da posicao %d lista: \n", ARRAY_SIZE - *tamanho);
    scanf("%d", &elem);

    if (elem < 0)
    {
        printf("Valor nao natural!");
        return;
    }
        
    for(i = ARRAY_SIZE; i >= 0; i--)
    {
        if (array[i] == -1)
        {
            array[i] = elem;
            *tamanho = *tamanho + 1;
            break;
        }
    }
}

void removerElemento(int array[], int * tamanho)
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

    if (elem < 0)
    {
        printf("Valor nao existente na lista!");
        return;
    }

    for(i = 0; i < ARRAY_SIZE; i++)
    {
        if (array[i] == elem)
        {
            array[i] = -1;
            *tamanho = *tamanho - 1;
            printf("Elemento removido.\n");
            return;
        }
    }

    printf("Elemento nao encontrado.\n");
    return;
}

void shift(int array[], int* tamanho, int* elementosRemovidos)
{
    int i, j;
    int elemShiftados = 0;

    if (*tamanho <= 0)
    {
        printf("Lista vazia!\n");
        return;
    }

    for (i = ARRAY_SIZE; i >= 0; i--)
    {
        if (array[i] != -1)
        {
            for (j = i; j < ARRAY_SIZE - elemShiftados; j++)
            {
                int aux = array[j + 1];
                array[j + 1] = array[j];
                array[j] = aux;
            }
            elemShiftados++;
        }
    }
}

void printarLista(int array[], int elementos)
{
    if (elementos == 0)
    {
        printf("Lista vazia!\n");
        return;
    }

    int i;

    printf("Array com gaps: [");
    for(i = 0; i < ARRAY_SIZE; i++)
    {        
        if (i == (ARRAY_SIZE - 1))
        {
            printf(" %d]", array[i]);
            break;
        }
        else if (i == 0)
        {
            printf("%d", array[i]);
        }
        else
        {
            printf(" %d", array[i]);
        }
    }
    
    printf("\nArray sem gaps: [");
    for(i = 0; i < ARRAY_SIZE; i++)
    {        
        if (array[i] != -1)
        {
            if (i == (ARRAY_SIZE - 1))
            {
                    printf(" %d]", array[i]);
                    return;
            }
            else if (i == 0) printf("%d", array[i]);
            else printf(" %d", array[i]);
        }
    }
    printf("]\n");
}

void tamanhoLista(int tamanho)
{
    printf("A lista possui %d elementos.\n", tamanho);
}

void verificarElemento(int array[], int tamanho)
{   
    int i;
    if (tamanho <= 0) { printf("Lista vazia!\n"); return; }

    int elemento;
    printf("Digite o elemento que voce deseja checar: \n");
    scanf("%d", &elemento);
    
    for(i = 0; i < ARRAY_SIZE; i++)
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
    int array[ARRAY_SIZE];
    int numElem = 0;
    int *p;
    int inserir, i;
    int elemRemovidos = 0;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = -1;
    }

    p = &numElem;

    while(1)
    {
        int comando;

        // Capacidade de 20 inteiros.
        
        printf("\nLista de numeros naturais [0 - Infinito]\n");
        printf("DIGITE O COMANDO QUE VOCE DESEJA REALIZAR: \n");
        printf("[1] - Adicionar elemento\n");
        printf("[2] - Remover elemento\n");
        printf("[3] - Printar lista\n");
        printf("[4] - Exibir tamanho da lista\n");
        printf("[5] - Checar elemento\n");
        printf("[6] - Shift (eh realizado automaticamente a cada 5 remocoes)\n");
        printf("[0] - Fechar programa\n");

        scanf("%d", &comando);

        if (comando == 1)
        {
            addElem(array, p);
        }
        else if (comando == 2)
        {
            removerElemento(array, p);
            elemRemovidos++;
            if (elemRemovidos >= 5)
            {
                shift(array, p, 0);
                elemRemovidos = 0;
                printf("Shift realizado automaticamente.\n");
            }
        }
        else if (comando == 3)
        {
            printarLista(array, numElem);
            printf("\n");
        }
        else if (comando == 4)
        {
            tamanhoLista(numElem);
        }
        else if (comando == 5)
        {
            verificarElemento(array, numElem);
        }
        else if (comando == 6)
        {
            shift(array, p, 0);
            elemRemovidos = 0;
            printf("Shift realizado.\n");
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