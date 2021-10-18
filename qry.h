#ifndef __QRY_H
#define __QRY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "svg.h"
#include "fila.h"
#include "pilha.h"
#include "texto.h"
#include "lista.h"
#include "linha.h"
#include "busca.h"
#include "circulo.h"
#include "auxiliar.h"
#include "retangulo.h"

/**
 * Verifica se as figuras com identificadores i e j se sobrepõem
 * Desenha uma linha e muda as cores das figuras que sobrepõem
 * Recebe todos os parametros necessarios para a função e não retorna nada
 **/
void o(char j[], char k[], char id[], char cor1[], char cor2[], FILE* saida, Lista listasQry[], Lista listaObjeto[]);

/**
 * Verifica se dois retangulos se sobrepõem
 * Recebe todos os parametros necessarios para a função e não retorna nada
 **/
void retanguloInt(Info r1, Info r2, FILE* saida, Lista listasQry[], char id[], char cor1[], char cor2[]);

/**
 * Verifica se dois circulos se sobrepõem
 * Recebe todos os parametros necessarios para a função e não retorna nada
 **/
void circuloInt(Info c1, Info c2, FILE* saida, Lista listasQry[], char id[], char cor1[], char cor2[]);

/**
 * Verifica se um retangulo e um circulo se sobrepõem
 * Recebe todos os parametros necessarios para a função e não retorna nada
 **/
void retanguloxCirculo(Info circ, Info ret, FILE* saida, Lista listasQry[], char id[], char cor1[], char cor2[]);

/**
 * Verifica se um ponto é interno a uma figura
 * Desenha um ponto com cores determinadas para cada caso
 * Desenha uma linha ligando o ponto a figura
 * Recebe todos os parametros necessarios para a função e não retorna nada
 **/
void i(Lista listaObjeto[], char j[],  double x, double y, FILE* saida, Lista listasQry[]);

/**
 * Muda as cores corb e corp da forma ou texto designado pelo id
 * Recebe todos os parametros necessarios para a função e não retorna nada
 **/
void pnt(Lista listaObjeto[], char j[], char corb[], char corp[], FILE* saida);

/**
 * Remove o elemento designado pelo id
 * Recebe todos os parametros necessarios para a função e não retorna nada
 **/
void delf(Lista listaObjeto[], char j[], FILE* saida);

/**
 * Busca a forma ou texto de identificador i
 * Insere o elemento na pilha
 * Recebe todos os parametros necessarios para a função e não retorna nada
 **/
void psh(Lista listaObjeto[], char j[], Pilha pilha);

/**
 * Busca a forma ou texto de identificador i
 * Insere o elemento na pilha
 * Recebe todos os parametros necessarios para a função e não retorna nada
 **/
void pshQ(Lista listaQry[], char j[], Pilha pilha);

/**
 * Remove o elemento do topo da pilha
 * Cria nova forma 
 * Recebe todos os parametros necessarios para a função e não retorna nada
 **/
void pop(Lista listaQry[], Lista listaObjeto[], Pilha pilha, double dx, double dy, double prop, char i[], FILE *saida);

/**
 * Busca a forma ou texto de identificador i
 * Insere o elemento na fila
 * Recebe todos os parametros necessarios para a função e não retorna nada
 **/
void inf(Lista listaObjeto[], char j[], Fila fila);

/**
 * Busca a forma ou texto de identificador i
 * Insere o elemento na fila
 * Recebe todos os parametros necessarios para a função e não retorna nada
 **/
void infQ(Lista listaQry[], char j[], Fila fila);

/**
 * Remove o elemento do fim da fila
 * Cria nova forma 
 * Recebe todos os parametros necessarios para a função e não retorna nada
 **/
void rmf(Lista listaQry[], Lista listaObjeto[], Fila fila, double dx, double dy, double prop, char i[], FILE *saida);

/**
 * Busca a forma ou texto de identificador i
 * Insere o elemento no inicio da lista
 * Recebe todos os parametros necessarios para a função e retorna um no
 **/
No ii(Lista listaObjeto[], Lista lista,char j[], No regis);

/**
 * Busca a forma ou texto de identificador i
 * Insere o elemento no inicio da lista
 * Recebe todos os parametros necessarios para a função e retorna um no
 **/
No iiQ(Lista listaQry[], Lista lista,char j[], No regis);

/**
 * Busca a forma ou texto de identificador i
 * Insere o elemento no fim da lista
 * Recebe todos os parametros necessarios para a função e retorna um no
 **/
No iF(Lista listaObjeto[], Lista lista, char j[], No regis);

/**
 * Busca a forma ou texto de identificador i
 * Insere o elemento no fim da lista
 * Recebe todos os parametros necessarios para a função e retorna um no
 **/
No iFQ(Lista listaQry[], Lista lista, char j[], No regis);

/**
 * Busca a forma ou texto de identificador i
 * Insere o elemento antes do no designado por r1
 * Recebe todos os parametros necessarios para a função e retorna um no
 **/
No ia(Lista listaObjeto[], Lista lista, char j[], No r1, No r2);

/**
 * Busca a forma ou texto de identificador i
 * Insere o elemento antes do no designado por r1
 * Recebe todos os parametros necessarios para a função e retorna um no
 **/
No iaQ(Lista listaQry[], Lista lista, char j[], No r1, No r2);

/**
 * Busca a forma ou texto de identificador i
 * Insere o elemento após o no designado por r1
 * Recebe todos os parametros necessarios para a função e retorna um no
 **/
No iD(Lista listaObjeto[], Lista lista, char j[], No r1, No r2);

/**
 * Busca a forma ou texto de identificador i
 * Insere o elemento após o no designado por r1
 * Recebe todos os parametros necessarios para a função e retorna um no
 **/
No idQ(Lista listaQry[], Lista lista, char j[], No r1, No r2);

/**
 * Remove os elementos da lista em ordem
 * Cria novas formas
 * Recebe todos os parametros necessarios para a função e não retorna nada
 **/
void dpl(Lista listaQry[], Lista lista, double dx, double dy, char i[], double prop, double incprop , FILE *saida);

#endif