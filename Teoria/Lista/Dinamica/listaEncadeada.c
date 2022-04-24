#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef struct{
    char nome[15];
    int idade;
} Elem;

typedef struct no{
    Elem elemento;
    struct no *proximo;
} No;

typedef struct{
    No *inicio;
} Lista;

///////////////////////////////////

void inicializarLista(Lista *l)
{   
    l->inicio = NULL;
}

int checaVazia(Lista l)
{
    return (l.inicio == NULL);
}

int tamanhoLista(Lista l)
{
    No *atual;
    int tamanho = 0;

    for (atual = l.inicio; atual != NULL; atual = atual->proximo)
    {
        tamanho++;
    } 
    return tamanho;
}

/*
    Passo 1: criar um novo com o elemento a ser inserido.
    Passo 2: atribuir o elemento 1 como prox do novo nó.
    Passo 3: atribuir o nó criado como o novo início da lista.
*/

int inserirInicio(Lista *l, Elem novoElemento)
{
    No *novo;

    if ((novo = malloc(sizeof(No))) == NULL) return false;
        
    novo->elemento = novoElemento;
    novo->proximo = l->inicio;
    l->inicio = novo;

    return true;
}

/*
    Passo 1: chegar ao último elemento da lista.
    Passo 2: criar um novo nó e atribuir seu valor.
    Passo 3: atualizar a referência do "antigo" ultimo elemento.
    Passo 4: atualizar a referência do novo nó (NULL).
*/

int inserirFinal(Lista *l, Elem novoElemento)
{
    No *novo;
    No *atual;

    atual = l->inicio;
    while(atual->proximo != NULL)
        atual = atual->proximo;

    if ((novo = malloc(sizeof(No))) == NULL) return false;

    atual->proximo = novo;
    novo->proximo = NULL;
    novo->elemento = novoElemento;

    return true;
}

void imprimeLista(Lista l)
{
    No *atual;

    for (atual = l.inicio; atual != NULL; atual = atual->proximo)
    {
        printf("Nome: %s - ", atual->elemento.nome);
        printf("Idade: %d anos\n", atual->elemento.idade);
    }
}

int procurarElemento(Lista l, char *nome)       // Procura baseado no nome;
{
    No *atual = l.inicio;

    while (atual != NULL)
    {
        if (stricmp(atual->elemento.nome, nome) == 0) return true;
        atual = atual->proximo;
    }
    return false;
}

/*  REMOVER DO INÍCIO
    Passo 1: apontamos para o primeiro nó, usando uma referência 'atual'.
    Passo 2: início aponta para o próximo do 'atual'.
    Passo 3: liberamos espaço do atual.
*/

int removeInicio(Lista *l, Elem *elem)
{
    No *atual;

    if (checaVazia(*l)) return false;

    atual = l->inicio;
    l->inicio = atual->proximo;
    *elem = atual->elemento;
    free(atual);
    return true;
}

int removeFinal(Lista *l, Elem *elem)
{
    No *atual;
    No *anterior = NULL;

    if (checaVazia(*l) == true) return false;

    atual = l->inicio;
    while (atual->proximo != NULL)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL)               // Significa que a lista só possui 1 elemento.  
        return removeInicio (l, elem);

    *elem = atual->elemento;
    anterior->proximo = atual->proximo;

    free(atual);
    return true;
}

int removeElemento(Lista *l, char *nome, Elem *elem)
{
    No *atual;
    No *anterior;

    if(checaVazia(*l) == true) return false;

    anterior = NULL;
    atual = l->inicio;

    while (atual != NULL)
    {
        if (stricmp(atual->elemento.nome, nome) == 0)
        {
            if (anterior == NULL) return removeInicio(l, elem);

            anterior->proximo = atual->proximo;
            *elem = atual->elemento;
            free(atual);
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return false;
}

void lobby()
{
    int opcao = 1;
    Lista listaEncadeada;
    Lista *l;

    l = &listaEncadeada;

    inicializarLista(l);

    printf("inicio: %d\n", listaEncadeada.inicio);

    while(1)
    {
        printf("LISTA - Operacoes validas:\n");
        printf("[1] - Inserir elemento\n");
        printf("[2] - Remover elemento\n");
        printf("[3] - Printar lista\n");
        printf("[4] - Tamanho da lista\n");
        printf("[5] - Checar elemento\n");
        printf("[0] - Encerrar programa\n");

        printf("Digite a operacao: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            printf("[1] - Inserir no inicio\n");
            printf("[2] - Inserir no final\n");
            printf("Digite a operacao: ");
            scanf("%d", &opcao);

            if (opcao == 1)
            {
                Elem novoElemento;

                printf("Digite o nome do elemento: ");
                scanf(" %s", novoElemento.nome);
                getchar();
                printf("Agora digite a idade do elemento: ");
                scanf("%d", &novoElemento.idade);

                int insercao = inserirInicio(l, novoElemento);
                if (insercao) printf("Elemento inserido.\n");
                else printf("Erro ao inserir elemento.\n");
            }
            else if (opcao == 2)
            {
                Elem novoElemento;

                printf("Digite o nome do elemento: ");
                scanf(" %s", novoElemento.nome);
                getchar();
                printf("Agora digite a idade do elemento: ");
                scanf("%d", &novoElemento.idade);

                int insercao = inserirFinal(l, novoElemento);
                if (insercao == true) printf("Elemento inserido.\n");
                else printf("Erro ao inserir elemento.\n");
            }
        }
        else if (opcao == 2)
        {
            printf("[1] - Remover no inicio\n");
            printf("[2] - Remover no final\n");
            printf("[3] - Remover um elemento especifico\n");
            printf("Digite a operacao: ");
            scanf("%d", &opcao);

            if (opcao == 1)
            {
                Elem elementoRemovido;
                Elem *e;
                e = &elementoRemovido;                
                int remocao = removeInicio(l, e);

                if (remocao == false) printf("Nao foi possivel remover. Lista vazia.\n");
                else
                { 
                    printf("Elemento removido:\n");
                    printf("Nome: %s - ", elementoRemovido.nome);
                    printf("Idade: %d anos\n", elementoRemovido.idade);
                }
            }
            else if (opcao == 2)
            {
                Elem elementoRemovido;
                Elem *e;
                e = &elementoRemovido;
                int remocao = removeFinal(l, e);

                if (remocao == false) printf("Nao foi possivel remover. Lista vazia.\n");
                else
                { 
                    printf("Elemento removido:\n");
                    printf("Nome: %s - ", elementoRemovido.nome);
                    printf("Idade: %d anos\n", elementoRemovido.idade);
                }
            }
            else if (opcao == 3)
            {
                Elem elementoRemovido;
                Elem *e;
                e = &elementoRemovido;

                printf("Digite o nome do elemento que voce deseja remover: ");
                scanf(" %s", elementoRemovido.nome);
                getchar();

                int remocao = removeElemento(l, e->nome, e);
                if (remocao == false) printf("Nao foi possivel remover.\nElemento nao encontrado ou lista vazia.\n");
                else
                { 
                    printf("Elemento removido:\n");
                    printf("Nome: %s - ", elementoRemovido.nome);
                    printf("Idade: %d anos\n", elementoRemovido.idade);
                }
            }
            else printf("Comando invalido.\n");
        }
        else if (opcao == 3)
        {
            if (listaEncadeada.inicio != NULL) imprimeLista(listaEncadeada);
            else printf("Lista vazia.\n");
        }
        else if (opcao == 4)
        {
            int tam;
            tam = tamanhoLista(listaEncadeada);
            printf("A lista possui %d elementos.\n", tam);
        }
        else if (opcao == 5)
        {
            if (listaEncadeada.inicio != NULL)
            {
                Elem elementoChecado;
                Elem *e;
                e = &elementoChecado;

                printf("Digite o nome do elemento que voce deseja verificar: ");
                scanf(" %s", elementoChecado.nome);
                getchar();

                int checagem = procurarElemento(listaEncadeada, e->nome);

                if (checagem == true) printf("%s esta presente na lista.\n", elementoChecado.nome);
                else printf("Elemento nao encontrado.\n", elementoChecado.nome);
            }
            else printf("Lista vazia.\n");
        }
        else if (opcao == 0) break;
    }
}

int main()
{
    lobby();

    return 0;
}