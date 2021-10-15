#ifndef __LERGEO_H
#define __LERGEO_H

#include "svg.h"
#include "texto.h"
#include "lista.h"
#include "linha.h"
#include "circulo.h"
#include "retangulo.h"

/*
*Le o arquivo geo
*precisa do nome do arquivo e a lista para salvar as informacoes
*não retorna nada
*/
void lerGeo(char arqGeo[], char nomeSvgGeo[], Lista listaObjeto[]);

#endif