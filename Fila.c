#include<stdio.h>
#include<stdlib.h>

typedef struct fila
{
    int info;
    struct fila *next;
} Fila;

void inicializar(Fila **i, Fila **f)
{
    *i = NULL;
    *f = NULL;
}

Fila *getnode()
{
    return (Fila *) malloc(sizeof(Fila));
}

void freenode(Fila *fila)
{
    free(fila);
}

int vazia(Fila *i)
{
    if(i == NULL)
        return 1;
    return 0;
}

void enfileirar(Fila **i, Fila **f, int val)
{
    Fila *novo;
    novo = getnode();
    if(novo != NULL)
    {
        novo->info = val;
        novo->next = NULL;
        if(vazia(*i))
        {
            *i = novo;
            *f = novo;
        }
        else
        {
            (*f)->next = novo;
            *f = novo;
        }
    }
}

void desenfileirar(Fila **i, Fila **f)
{
    Fila *removido;
    if(!vazia(*i))
    {
        if((*i)->next == NULL)
        {
            freenode(*i);
            *i = NULL;
            *f = NULL;
        }
        else
        {
            removido = *i;
            *i = (*i)->next;
            freenode(removido);
        }
    }
}

void apresentar(Fila *i)
{
    if(!vazia(i))
    {
        printf("inicio > ");
        while(i != NULL)
        {
            printf("%d ", i->info);
            i = i->next;
        }
        printf("< fim");
        printf("\n");
    }
    else
    {
        printf("inicio > NULL < fim\n");
    }
}

void main()
{
    Fila *inicio;
    Fila *fim;
    inicializar(&inicio, &fim);
    enfileirar(&inicio, &fim, 3);
    enfileirar(&inicio, &fim, 4);
    enfileirar(&inicio, &fim, 6);
    apresentar(inicio);
    desenfileirar(&inicio, &fim);
    apresentar(inicio);
    desenfileirar(&inicio, &fim);
    desenfileirar(&inicio, &fim);
    apresentar(inicio);
    apresentar(inicio);
    enfileirar(&inicio, &fim, 12);
    apresentar(inicio);
}
