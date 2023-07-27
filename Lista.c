#include<stdio.h>

typedef struct lista
{
    int info;
    struct lista *next;
} Lista;

void inicializar(Lista **lista)
{
    *lista = NULL;
}

Lista *getnode()
{
    return (Lista*) malloc(sizeof(Lista));
}

void freenode(Lista *lista)
{
    free(lista);
}

int vazia(Lista *lista)
{
    if(lista == NULL)
        return 1;
    return 0;
}

void insere_inicio(Lista **lista, int valor)
{
    Lista *novo;
    novo = getnode();
    if(novo != NULL)
    {
        novo->info = valor;
        novo->next = *lista;
        *lista = novo;
    }
}

void insere_fim(Lista **lista, int valor)
{
    Lista *novo;
    Lista *percorre;
    novo = getnode();
    if(novo != NULL)
    {
        novo->info = valor;
        novo->next = NULL;
        if(vazia(&(*lista)))
        {
            *lista = novo;
        }
        else
        {
            percorre = *lista;
            while(percorre->next != NULL)
                percorre = percorre->next;
            percorre->next = novo;
        }
    }
}

Lista *pesquisar(Lista *lista, int valor)
{
    if(!vazia(lista))
    {
        while(lista->next != NULL)
        {
            if(lista->info == valor)
            {
                return lista;
            }
            lista = lista->next;
        }
    }
}

void remove_inicio(Lista **lista)
{
    Lista *removido;
    if(!vazia(*lista))
    {
        removido = *lista;
        *lista = (*lista)->next;
        freenode(removido);
    }
}

void remove_valor(Lista **lista, int valor)
{
    Lista *aux;
    Lista *pesquisado;
    if(!vazia(*lista))
    {
        aux = *lista;
        if((pesquisado = pesquisar(*lista, valor)) != NULL)
        {
            if(aux == pesquisado)
            {
                remove_inicio(*lista);
            }
            else
            {
                while(aux->next != pesquisado)
                {
                    aux = aux->next;
                }
                aux->next = pesquisado->next;
                freenode(pesquisado);
            }
        }
    }
}

void exibe_lista(Lista *lista)
{
    if(!vazia(lista))
    {
        while(lista != NULL)
        {
            printf("%d\t", lista->info);
            lista = lista->next;
        }
    }
}


void main()
{
    Lista *lista;
    inicializar(&lista);
    insere_inicio(&lista, 4);
    insere_inicio(&lista, 5);
    insere_fim(&lista, 3);
    insere_fim(&lista, 1);
    exibe_lista(lista);
    remove_valor(&lista, 3);
    printf("\n");
    exibe_lista(lista);
    remove_inicio(&lista);
    printf("\n");
    exibe_lista(lista);
}
