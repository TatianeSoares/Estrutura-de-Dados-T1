#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"svg.h"

void iniciaSvg(FILE* arqSvg)
{
    fprintf(arqSvg, "<svg version=\"1.1\" baseProfile=\"full\" width=\"10000\" height=\"10000\" xmlns=\"http://www.w3.org/2000/svg\">");    
    
}

void desenhaCirculo(Circulo circulo, FILE* arqSvg)
{
    fprintf(arqSvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ", getCirculoX(circulo), getCirculoY(circulo), 
    getCirculoR(circulo), getCirculoCorb(circulo), getCirculoCorp(circulo));
}

void desenhaRetangulo(Retangulo retangulo, FILE* arqSvg)
{
    fprintf(arqSvg, "\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width =\"1\"/>\n",
    getRetanguloX(retangulo), getRetanguloY(retangulo), getRetanguloW(retangulo), getRetanguloH(retangulo),
    getRetanguloCorp(retangulo), getRetanguloCorb(retangulo));
}

void escreveTexto(Texto texto, FILE* arqSvg)
{
    fprintf(arqSvg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">%s</text>\n",
    getTextoX(texto), getTextoY(texto), getTextoCorb(texto), getTextoCorp(texto), getTextoTxto(texto));
}

void desenhaLinha(Linha linha, FILE* arqSvg)
{
    fprintf(arqSvg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n", 
    getLinhaX1(linha), getLinhaY1(linha), getLinhaX2(linha), getLinhaY2(linha), getLinhaCor(linha));

}

void desenhaGeoSvg(FILE* arqSvg, Lista listaObjeto[])
{
    No no;

    if(getFirst(listaObjeto[0]) != NULL)
    {
        for(no = getFirst(listaObjeto[0]); no != NULL; no = getNext(no))
        {
            desenhaCirculo(getInfo(no), arqSvg);
        }
    }
    if(getFirst(listaObjeto[1]) != NULL)
    {
        for(no = getFirst(listaObjeto[1]); no != NULL; no = getNext(no))
        {
            desenhaRetangulo(getInfo(no), arqSvg);
        }
    }
    if(getFirst(listaObjeto[2]) != NULL)
    {
        for(no = getFirst(listaObjeto[2]); no != NULL; no = getNext(no))
        {
            desenhaLinha(getInfo(no), arqSvg);
        }
    }
    if(getFirst(listaObjeto[3]) != NULL)
    {
        for(no = getFirst(listaObjeto[3]); no != NULL; no = getNext(no))
        {
            escreveTexto(getInfo(no), arqSvg);
        }
    }
}

void gerarSvgQry(Lista listaObjeto[], FILE *saidaSvg, Lista listasQry[])
{
    desenhaGeoSvg(saidaSvg, listaObjeto);

    int i=0;

    if(i == 0)
    {
        No no;

        for(no = getFirst(listasQry[i]); no != NULL; no = getNext(no))
        {
            desenhaCirculo(getInfo(no), saidaSvg);
        }

        i++;

    }
    if(i == 1)
    {
        No no;

        for(no = getFirst(listasQry[i]); no != NULL; no = getNext(no))
        {
            desenhaRetangulo(getInfo(no), saidaSvg);
        }

        i++;

    }
    if(i == 2)
    {
        No no;

        for(no = getFirst(listasQry[i]); no != NULL; no = getNext(no))
        {
            desenhaLinha(getInfo(no), saidaSvg);
        }

        i++;

    }
    if(i == 3)
    {
        No no;

        for(no = getFirst(listasQry[i]); no != NULL; no = getNext(no))
        {
            escreveTexto(getInfo(no), saidaSvg);
        }

        i++;

    }
}

void finalizaSvg(FILE* arqSvg)
{
    fprintf(arqSvg, "</svg>");
}