#ifndef __AUXILIAR_H
#define __AUXILIAR_H

#include "lista.h"
#include "ponto.h"
#include "pilha.h"

/*
    *Calcula a distancia entre duas figuras
    *Precisamos das coordenadas dessas figuras
    *Retorna a distancia entre elas
*/
double distancia(double x1, double y1, double x2, double y2);

/*
    *Calcula se um numero e maior ou menor que o outro
    *Precizamos de dois numeros passando pelo parametro para serem comparados
    *Retorna o numero maior
    
*/
float max(float n1, float n2);

/*
    *Calcula se um numero e maior ou menor que o outro
    *Precizamos de dois numeros passando pelo parametro para serem comparados
    *Retorna o numero menor
    
*/
float min(float n1, float n2);

#endif