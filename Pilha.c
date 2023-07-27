#include<stdio.h>
#include<stdlib.h>

typedef struct cell
{
    int info;
    struct cell *next;
} Cell;

Cell *getnode()
{
    return (Cell*) malloc(sizeof(Cell));
}

void start(Cell **cell)
{
    *cell = NULL;
}

void freenode(Cell *cell)
{
    free(cell);
}

void push(Cell **cell, int value)
{
    Cell *aux;
    aux = getnode();
    if(aux != NULL)
    {
        aux->info = value;
        aux->next = *cell;
        *cell = aux;
    }
}

int emptyCell(Cell *cell)
{
    if(cell == NULL)
        return 1;
    return 0;
}

void pop(Cell **cell)
{
    Cell *aux;
    if(!emptyCell(*cell))
    {
        aux = *cell;
        *cell = (*cell)->next;
        freenode(aux);
    }
}

void showAll(Cell *cell)
{
    if(cell !=  NULL)
    {
        while(cell->next != NULL)
        {
            printf("%d\t", cell->info);
            cell = cell->next;
        }
        printf("%d\t", cell->info);
        printf("\n");
    }
}

void main()
{
    Cell *pilha;
    start(&pilha);
    push(&pilha, 3);
    push(&pilha, 2);
    push(&pilha, 1);
    push(&pilha, 4);
    showAll(pilha);
    pop(&pilha);
    showAll(pilha);
    pop(&pilha);
    showAll(pilha);
}

