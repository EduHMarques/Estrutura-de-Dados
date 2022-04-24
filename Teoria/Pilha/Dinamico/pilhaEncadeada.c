#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct{
    char nome[15];
    int idade;
} Elem;

typedef struct no{
    Elem elemento;
    struct no *proximo;
} No;

typedef struct{
    No *topo;
} Pilha;

void inicializaPilha(Pilha *p)
{
    p->topo = NULL;
}

int checaVazia(Pilha p)
{
    return p.topo == NULL;
}

int tamanhoPilha(Pilha p)
{
    int tamanho = 0;

    No *atual = p.topo;
    while (atual != NULL)
    {
        tamanho++;
        atual = atual->proximo;
    }
    return tamanho;
}

int main()
{

    return 0;
}