#ifndef __BUSCA_H
#define __BUSCA_H

#include "texto.h"
#include "lista.h"
#include "linha.h"
#include "circulo.h"
#include "retangulo.h"

/**
 * Faz a busca em uma lista para achar determinado no atraves de seu id
 * Precisa de uma lista e um id
 * Retorna o no achado ou NULL caso nao encontre nada
 **/
No buscarCirculo(Lista listasObjetos[], char id[]);

/**
 * Faz a busca em uma lista para achar determinado no atraves de seu id
 * Precisa de uma lista e um id
 * Retorna o no achado ou NULL caso nao encontre nada
 **/
No buscarRetangulo(Lista listasObjetos[], char id[]);

/**
 * Faz a busca em uma lista para achar determinado no atraves de seu id
 * Precisa de uma lista e um id
 * Retorna o no achado ou NULL caso nao encontre nada
 **/
No buscarLinha(Lista listasObjetos[], char id[]);

/**
 * Faz a busca em uma lista para achar determinado no atraves de seu id
 * Precisa de uma lista e um id
 * Retorna o no achado ou NULL caso nao encontre nada
 **/
No buscarTexto(Lista listasObjetos[], char id[]);

#endif