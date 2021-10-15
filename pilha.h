#ifndef __PILHA__H
#define __PILHA__H

typedef void *Pinfo;
typedef void *Pilha;

Pilha criaPilha();

int isFull(Pilha pilha);

void empilhar(Pilha pilha, Pinfo info);

int isEmpty(Pilha pilha);

int tamanhoPilha(Pilha pilha);

Pinfo getTopPilha(Pilha pilha);

Pinfo desempilha(Pilha pilha);

#endif