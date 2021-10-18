#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

typedef struct no{
    Pinfo info;
    struct no *anterior;
}StructNo;

typedef struct pilha
{
    StructNo *topo;
    int tamanho;
}StructPilha;

Pilha criaPilha()
{
    StructPilha *p = (StructPilha*) malloc(sizeof(StructPilha));
    p->tamanho = 0;
    p->topo = NULL;

    return p;
}

int isFull(Pilha pilha)
{
    if(tamanhoPilha(pilha) == 1300)
    {
        return 1;
    }

    return 0;
}

void empilhar(Pilha pilha, Pinfo info)
{
    StructPilha *p = (StructPilha*)pilha;
    StructNo *no = (StructNo*) malloc(sizeof(StructNo));

    if(isFull(pilha) == 0)
    {

        no->info = info;
        no->anterior = p->topo;
        p->topo = no;

        p->tamanho++;
        
    }
    
}

int isEmpty(Pilha pilha)
{
    StructPilha *p = (StructPilha*)pilha;

    if(p->tamanho == 0)
    {
        return 1;
    }
  
    return 0;
    
}

int tamanhoPilha(Pilha pilha)
{
    StructPilha *p = (StructPilha*)pilha;
    return p->tamanho;
}

Pinfo getTopPilha(Pilha pilha)
{
    StructPilha *p = (StructPilha*)pilha;
    return p->topo;
}

Pinfo desempilha(Pilha pilha)
{
    StructPilha *p = (StructPilha*)pilha;

    if(p->tamanho == 0)
    {
        return NULL;
    }

    StructNo *aux = p->topo;
    Pinfo info = aux->info;
    p->topo = aux->anterior;

    p->tamanho--;
    free(aux);
    
    return info;
}
