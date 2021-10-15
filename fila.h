#ifndef __FILA__H
#define __FILA__H

typedef void *Fila;
typedef void *filaInfo;


Fila criaFila();

void insereFila(Fila fila, filaInfo info);

filaInfo retiraFila(Fila fila);

int filaIsEmpty(Fila fila);

filaInfo getInicioFila(Fila fila);

#endif