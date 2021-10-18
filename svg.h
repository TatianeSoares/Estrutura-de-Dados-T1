#ifndef __SVG_H
#define __SVG_H

#include "texto.h"
#include "linha.h"
#include "lista.h"
#include "circulo.h"
#include "retangulo.h"
/*
    *Inicia o arquivo svg colocando o comando necessario nele
    *Apenas o arquivo svg a ser aberto é passado como parametro
    *Retorna nada, fecha o svg apenas.
    * 
*/
void iniciaSvg(FILE* arqSvg);

/*
    *Desenha um circulo no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o circulo e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaCirculo(Circulo circulo, FILE* arqSvg);

/*
    *Desenha um retangulo no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o retangulo e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaRetangulo(Retangulo retangulo, FILE* arqSvg);

/*
    *Escreve um texto no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o texto e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void escreveTexto(Texto texto, FILE* arqSvg);

/*
    *Desenha uma linha no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para a linha, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaLinha(Linha linha, FILE* arqSvg);

/*
    *Imprime os elementos guardados na lista no arquivo svg
    *Precisa das listas e do arquivo a ser editado
    *Retorna nada.
    * 
*/

void desenhaGeoSvg(FILE* arqSvg, Lista listaObjeto[]);

/*
    *Imprime os elementos guardados na lista no arquivo svg feito para o qry
    *Precisa das listas e do arquivo a ser editado
    *Retorna nada.
    * 
*/
void gerarSvgQry(Lista listaObjeto[], FILE *saidaSvg, Lista listasQry[]);

/*
    *Finaliza o arquivo svg colocando o comando necessario nele
    *Apenas o arquivo svg a ser fechado é passado como parametro
    *Retorna nada, fecha o svg apenas.
    * 
*/
void finalizaSvg(FILE* arqSvg);

#endif