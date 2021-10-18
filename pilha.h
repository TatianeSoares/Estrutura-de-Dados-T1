#ifndef __PILHA__H
#define __PILHA__H

//Define "Pinfo" como um void pointer
typedef void *Pinfo;
//Define "Pilha" como um void pointer
typedef void *Pilha;

/*
*Cria uma pilha vazia
*Não precisa de parametros
*Retorna um void pointer para a pilha que foi criada
*/
Pilha criaPilha();

/**
 * Verifica se a pilha esta cheia
 * Precisa de um void pointer pilha
 * Retorna 0 para falso e 1 para verdadeiro
 * */
int isFull(Pilha pilha);

/*
*Insere um elemento no topo da pilha
*Precisa de um void pointer info e de um void pointer pilha
*Retorna nada.
*/
void empilhar(Pilha pilha, Pinfo info);

/**
 * Verifica se a pilha esta vazia
 * Precisa de um void pointer pilha
 * Retorna 0 para falso e 1 para verdadeiro
 * */
int isEmpty(Pilha pilha);

/**
 * Retorna o tamanho da pilha
 * Precisa de um void pointer pilha
 **/
int tamanhoPilha(Pilha pilha);

/**
 * Retorna o elemento que esta no topo da pilha
 * Precisa de um void pointer pilha
 **/
Pinfo getTopPilha(Pilha pilha);

/*
*Retira um elemento no topo da pilha
*Precisa de um void pointer pilha
*Retorna a info do elemento removido.
*/
Pinfo desempilha(Pilha pilha);

#endif