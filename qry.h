#ifndef __QRY_H
#define __QRY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "svg.h"
#include "texto.h"
#include "lista.h"
#include "linha.h"
#include "busca.h"
#include "circulo.h"
#include "auxiliar.h"
#include "retangulo.h"

void o(char j[], char k[], char id[], char cor1[], char cor2[], FILE* saida, Lista listasQry[], Lista listaObjeto[]);

void retanguloInt(Info r1, Info r2, FILE* saida, Lista listasQry[], char id[], char cor1[], char cor2[]);

void circuloInt(Info c1, Info c2, FILE* saida, Lista listasQry[], char id[], char cor1[], char cor2[]);

void retanguloxCirculo(Info circ, Info ret, FILE* saida, Lista listasQry[], char id[], char cor1[], char cor2[]);

void i(Lista listaObjeto[], char j[],  double x, double y, FILE* saida, Lista listasQry[]);


#endif