#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "qry.h"

void o(char j[], char k[], char id[], char cor1[], char cor2[], FILE* saida, Lista listasQry[], Lista listaObjeto[])
{
    Info info1;
    Info info2;

    if(buscarCirculo(listaObjeto, j) != NULL && buscarCirculo(listaObjeto, k) != NULL)
    {
        info1 = getInfo(buscarCirculo(listaObjeto, j));
        info2 = getInfo(buscarCirculo(listaObjeto, k));
        circuloInt(info1, info2, saida, listasQry, id, cor1, cor2);
    }
    else if(buscarCirculo(listaObjeto, j) != NULL && buscarRetangulo(listaObjeto, k) != NULL)
    {
        info1 = getInfo(buscarCirculo(listaObjeto, j));
        info2 = getInfo(buscarRetangulo(listaObjeto, k));
        retanguloxCirculo(info1, info2, saida, listasQry, id, cor1, cor2);
    }
    else if(buscarRetangulo(listaObjeto, j) != NULL && buscarCirculo(listaObjeto, k) != NULL)
    {
        info1 = getInfo(buscarRetangulo(listaObjeto, j));
        info2 = getInfo(buscarCirculo(listaObjeto, k));
        retanguloxCirculo(info2, info1, saida, listasQry, id, cor1, cor2);
    }
    else if(buscarRetangulo(listaObjeto, j) != NULL && buscarRetangulo(listaObjeto, k) != NULL)
    {
        info1 = getInfo(buscarRetangulo(listaObjeto, j));
        info2 = getInfo(buscarRetangulo(listaObjeto, k));
        retanguloInt(info1, info2, saida, listasQry, id, cor1, cor2);
    }
}

void retanguloInt(Info r1, Info r2, FILE* saida, Lista listasQry[], char id[], char cor1[], char cor2[])
{
    float x,w,y,h;

    x = min(getRetanguloX(r1),getRetanguloX(r2));
    w = max(getRetanguloX(r1) + getRetanguloW(r1),getRetanguloX(r2) + getRetanguloW(r2)) - x;
    y = min(getRetanguloY(r1),getRetanguloY(r2));
    h = max(getRetanguloY(r1) + getRetanguloH(r1),getRetanguloY(r2) + getRetanguloH(r2)) - y;

    Linha linha = criaLinha(id, getRetanguloX(r1), getRetanguloY(r1), getRetanguloX(r2), getRetanguloY(r2), "black");
    insert(listasQry[2], linha);

    if (w <= getRetanguloW(r1) + getRetanguloW(r2) && h <= getRetanguloH(r1) + getRetanguloH(r2))
    {
        fprintf(saida,"%s: retangulo %s: retangulo SIM\n", getRetanguloI(r1),getRetanguloI(r2));

        // Retangulo ret = criaRetangulo("0", w, h, x, y, "1", "black", "none");
        // insert(listasQry[1], ret);
        setRetanguloCorp(r1, cor1);
        setRetanguloCorp(r2, cor1);
    }
    else
    {
        fprintf(saida,"%s: retangulo %s: retangulo NAO\n", getRetanguloI(r1),getRetanguloI(r2));

        // Retangulo ret = criaRetangulo("0", w, h, x, y, "1", "black", "none");
        // insert(listasQry[5], ret);
        setRetanguloCorp(r1, cor2);
        setRetanguloCorp(r2, cor2);
    }
}

void circuloInt(Info c1, Info c2, FILE* saida, Lista listasQry[], char id[], char cor1[], char cor2[])
{
    float dist;
    //,x,y,w,h;

    dist = distancia(getCirculoX(c1), getCirculoY(c1), getCirculoX(c2), getCirculoY(c2));
    // x = min(getCirculoX(c1) - getCirculoR(c1), getCirculoX(c2) - getCirculoR(c2));
    // w = max(getCirculoX(c1) + getCirculoR(c1), getCirculoX(c2) + getCirculoR(c2)) - x;
    // y = min(getCirculoY(c1) - getCirculoR(c1), getCirculoY(c2) - getCirculoR(c2));
    // h = max(getCirculoY(c1) + getCirculoR(c1), getCirculoY(c2) + getCirculoR(c2)) - y;

    Linha linha = criaLinha(id, getCirculoX(c1), getCirculoY(c1),  getCirculoX(c2), getCirculoY(c2), "black");
    insert(listasQry[2], linha);

    if(dist <= getCirculoR(c2) + getCirculoR(c1))
    {
        fprintf(saida,"%s: circulo %s: circulo SIM\n", getCirculoI(c1),getCirculoI(c2));

        // Retangulo ret = criaRetangulo("0", w, h  x, y, "1", "black", "none");
        // insert(listasQry[1], ret);
        setCirculoCorp(c1, cor1);
        setCirculoCorp(c2, cor1);

    }
    else
    {
        fprintf(saida,"%s: circulo %s: circulo NAO\n",getCirculoI(c1),getCirculoI(c2));

        // Retangulo ret = criaRetangulo("0", w, h, x, y, "1", "black", "none");
        // insert(listasQry[5], ret);
        setCirculoCorp(c1, cor2);
        setCirculoCorp(c2, cor2);

    }
}

void retanguloxCirculo(Info circ, Info ret, FILE* saida, Lista listasQry[], char id[], char cor1[], char cor2[])
{
    float deltaX, deltaY;
    // x, y, w, h;

    if(getCirculoX(circ) > getRetanguloX(ret))
    {
        deltaX = pow(getRetanguloX(ret) + getRetanguloW(ret) - getCirculoX(ret),2);
    }
    else
    {
        deltaX = pow(getRetanguloX(ret) - getCirculoX(circ),2);
    }
    if(getCirculoY(circ) > getRetanguloY(ret))
    {
        deltaY = pow(getRetanguloY(ret) + getRetanguloH(ret) - getCirculoY(circ),2);
    }
    else
    {
        deltaY = pow(getRetanguloY(ret) - getCirculoY(circ),2);
    }

    // x = min(getRetanguloX(ret),getCirculoX(circ) - getCirculoR(circ));
    // w = max(getRetanguloX(ret) + getRetanguloW(ret),getCirculoX(circ) + getCirculoR(circ)) - x;
    // y = min(getRetanguloY(ret),getCirculoY(circ) - getCirculoR(circ));
    // h = max(getRetanguloY(ret) + getRetanguloH(ret),getCirculoY(circ) + getCirculoR(circ)) - y;

    Linha linha = criaLinha(id, getRetanguloX(ret), getRetanguloY(ret), getCirculoX(circ), getCirculoY(circ), "black");
    insert(listasQry[2], linha);

    if(sqrt(deltaX + deltaY) <= getCirculoR(circ))
    {
        fprintf(saida,"%s: circulo %s: retangulo SIM\n", getCirculoI(circ), getRetanguloI(ret));

        // Retangulo ret = criaRetangulo("0", w,h,x,y, "1", "black", "none");
        // insert(listasQry[1], ret);
        setCirculoCorp(circ, cor1);
        setRetanguloCorp(ret, cor1);
    }
    else
    {
        fprintf(saida,"%s: circulo %s: retangulo NAO\n", getCirculoI(circ), getRetanguloI(ret));

        // Retangulo ret = criaRetangulo("0", w,h,x,y, "1", "black", "none");
        // insert(listasQry[5], ret);
        setCirculoCorp(circ, cor2);
        setRetanguloCorp(ret, cor2);

    }
}

void i(Lista listaObjeto[], char j[],  double x, double y, FILE* saida, Lista listasQry[])
{
    No no = buscarCirculo(listaObjeto, j);

    if(no != NULL)
    {
        Info c = getInfo(no);

        if(getCirculoR(c) >= distancia(x, y, getCirculoX(c), getCirculoY(c)))
        {
            fprintf(saida,"CIRCULO: Ponto interno\n");

            Circulo circ = criaCirculo("0", 2, x, y, "1", "blue", "blue");
            insert(listasQry[0], circ);

            Linha lin = criaLinha("0", x, y, getCirculoX(c), getCirculoY(c), "blue");
            insert(listasQry[2], lin);
        }
        else
        {
            fprintf(saida,"CIRCULO: Ponto não interno\n");

            Circulo circ = criaCirculo("0", 2, x, y, "1", "magenta", "magenta");
            insert(listasQry[0], circ);

            Linha lin = criaLinha("0", x, y, getCirculoX(c), getCirculoY(c), "magenta");
            insert(listasQry[2], lin);
        }
    }

    no = buscarRetangulo(listaObjeto, j);

    if(no != NULL)
    {
        Info  r = getInfo(no);
        float difx = x - getRetanguloX(r);
        float dify = y - getRetanguloY(r);

        if(difx >= 0 && difx <= getRetanguloW(r) && dify >= 0 && dify <= getRetanguloH(r))
        {
            fprintf(saida,"RETANGULO: Ponto interno\n");

            Circulo circ = criaCirculo("0", 2, x, y, "1", "blue", "blue");
            insert(listasQry[0], circ);
            Linha lin = criaLinha("0", x, y, getRetanguloX(r) + getRetanguloW(r)/2, getRetanguloY(r) + getRetanguloH(r)/2, "blue");
            insert(listasQry[2], lin);
        }
        else
        {
            fprintf(saida,"RETANGULO: Ponto não interno\n");

            Circulo circ = criaCirculo("0", 2, x, y, "1", "magenta", "magenta");
            insert(listasQry[0], circ);
            Linha lin = criaLinha("0", x, y, getRetanguloX(r) + getRetanguloW(r)/2, getRetanguloY(r) + getRetanguloH(r)/2, "magenta");
            insert(listasQry[2], lin);
        }
    }

}