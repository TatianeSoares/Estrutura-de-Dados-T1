#ifndef __FILA__H
#define __FILA__H

//Define "Fila" como um void pointer
typedef void *Fila;
//Define "filaInfo" como um void pointer
typedef void *filaInfo;

/*
*Cria uma fila vazia
*Não precisa de parametros
*Retorna um void pointer para a fila que foi criada
*/
Fila criaFila();

/*
*Insere um elemento no fim da fila
*Precisa de um void pointer info e de um void pointer fila
*Retorna nada.
*/
void insereFila(Fila fila, filaInfo info);

/**
 * Retira um elemnto da fila
 * Precisa de um void pointer fila
 * Retorna a info do elemento retirado
 **/
filaInfo retiraFila(Fila fila);

/**
 * Verifica se a fila esta vazia
 * Precisa de um void pointer fila
 * Retorna 0 para falso e 1 para verdadeiro
 * */
int filaIsEmpty(Fila fila);

/**
 * Retorna o inicio da fila
 * Precisa de um void pointer fila
 **/
filaInfo getInicioFila(Fila fila);

#endif