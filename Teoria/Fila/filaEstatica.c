#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define TAM 10

typedef struct{
    char nome[15];
    int idade;
} Pessoa;

typedef struct{
    Pessoa pessoas[TAM];
    int inicio;
    int elementos;
} Fila;

int inicializaFila(Fila *f)
{
    f->inicio = 0;
    f->elementos = 0;
    return true;
}

int verificaVazia(Fila f)
{
    if (f.elementos == 0) return true;
    return false;
}

int verificaCheia(Fila f)
{
    if (f.elementos == TAM) return true;
    return false;
}

int tamanhoFila(Fila f)
{
    return f.elementos;
}

int printarFila(Fila *f)
{
    printf("Fila: \" ");

    int i = f->inicio;
    int j;

    for (j = 0; j < f->elementos; j++)
    {
        printf("Nome: %s , Idade: %d | ", f->pessoas[i].nome, f->pessoas[i].idade);
        i = (i + 1) % TAM;
    }
    printf("\"\n");
}

int inserirFila(Fila *f)
{
    if (verificaCheia(*f)) return false;

    int posicao = (f->inicio + f->elementos) % TAM;

    printf("Digite o primeiro nome da pessoa: ");
    scanf("%s", &f->pessoas[posicao].nome);
    getchar();
    printf("Agora digite a idade da pessoa: ");
    scanf("%d", &f->pessoas[posicao].idade);

    f->elementos += 1;
    return true;
}

int removeFila(Fila *f)
{
    if (f->elementos == 0) return false;

    printf("Excluindo: %s, %d anos\n", f->pessoas[f->inicio].nome, f->pessoas[f->inicio].idade);

    f->inicio = (f->inicio + 1) % TAM;
    f->elementos--;
    return true;
}

void lobby()
{
    Fila caixa;
    Fila *p;
    p = &caixa;
    inicializaFila(p);


    while(1)
    {
        int op;

        printf("[1] - Adicionar elemento\n");
        printf("[2] - Remover elemento\n");
        printf("[3] - Checar tamanho\n");
        printf("[4] - Printar fila\n");
        printf("[5] - Reinicializar fila\n");
        printf("[0] - Encerrar\n");
        printf("Digite a operacao que voce deseja realizar: ");
        scanf("%d", &op);

        if (op == 1)
        {
            inserirFila(p);
        }
        else if (op == 2)
        {
            removeFila(p);
        }
        else if (op == 3)
        {
            int tam = tamanhoFila(caixa);
            printf("Tamanho: %d\n", tam);
        }
        else if (op == 4)
        {
            printarFila(p);
        }
        else if (op == 5)
        {
            inicializaFila(p);
        }
        else if (op == 0) break;
    }
}

int main()
{
    lobby();

    return 0;
}