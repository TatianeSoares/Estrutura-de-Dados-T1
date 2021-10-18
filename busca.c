#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "busca.h"

No buscarCirculo(Lista listasObjetos[], char id[])
{
    No node;
    Info info;

    for(node = getFirst(listasObjetos[0]); node != NULL; node = getNext(node))
    {
        info = getInfo(node);
        if(strcmp(getCirculoI(info), id) == 0)
        {
            return node;
        }
    }

    return node=NULL; 
} 

No buscarRetangulo(Lista listasObjetos[], char id[])
{
    No node;
    Info info;

    for(node = getFirst(listasObjetos[1]); node != NULL; node = getNext(node))
    {
        info = getInfo(node);
        if(strcmp(getRetanguloI(info), id) == 0)
        {
            return node;
        }
    }

    return node=NULL; 
} 

No buscarLinha(Lista listasObjetos[], char id[])
{
    No node;
    Info info;

    for(node = getFirst(listasObjetos[2]); node != NULL; node = getNext(node))
    {
        info = getInfo(node);
        if(strcmp(getLinhaId(info), id) == 0)
        {
            return node;
        }
    }

    return node=NULL; 
} 

No buscarTexto(Lista listasObjetos[], char id[])
{
    No node;
    Info info;

    for(node = getFirst(listasObjetos[3]); node != NULL; node = getNext(node))
    {
        info = getInfo(node);
        if(strcmp(getTextoI(info), id) == 0)
        {
            return node;
        }
    }

    return node=NULL; 
} 