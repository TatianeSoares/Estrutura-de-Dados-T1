#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lerGeo.h"

void lerGeo(char arqGeo[], char nomeSvgGeo[],  Lista listaObjeto[])
{
    FILE *geo;
    FILE *arqSvg;
    int n = 0;

    char id1[20];
    char txt[255];
    char tipo[10];
    char borda[22]; 
    char preenchimento[22];

    double raio;
    double x1, x2, y1, y2, h, w;

    geo = fopen(arqGeo, "r");

    if(geo == NULL)
    {
        printf("\nERRO\nArquivo .geo nao pode ser aberto\n");
        exit(1);
    }

    arqSvg = fopen(nomeSvgGeo, "w");
    
    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser aberto\n");
        exit(1);
    }

    iniciaSvg(arqSvg);

    while(!feof(geo))
    {
        fscanf(geo, "%s", tipo);

        if(strcmp(tipo, "c") == 0)
        {
            fscanf(geo,"%s %lf %lf %lf %s %s\n", id1, &raio, &x1, &y1, borda, preenchimento);
            Circulo circulo = criaCirculo(id1, raio, x1, y1, "2", borda, preenchimento);
            insert(listaObjeto[0], circulo); 
            
            n++;
        }
        else if(strcmp(tipo, "r") == 0)
        {
            fscanf(geo,"%s %lf %lf %lf %lf %s %s\n", id1, &w, &h, &x1, &y1, borda, preenchimento);
            Retangulo retangulo = criaRetangulo(id1, w, h, x1, y1, "2", borda, preenchimento);
            insert(listaObjeto[1], retangulo);
            
            n++;
        }
        else if(strcmp(tipo, "l") == 0)
        {
            fscanf(geo,"%s %lf %lf %lf %lf %s", id1, &x1, &y1, &x2, &y2, preenchimento);
            Linha linha = criaLinha(id1, x1, y1, x2, y2, preenchimento);
            insert(listaObjeto[2], linha);
        }
        else if(strcmp(tipo, "t") == 0)
        {
            fscanf(geo,"%s %lf %lf %s %s", id1, &x1, &y1, borda, preenchimento);
            fgets(txt, 255, geo);
            Texto texto = criaTexto(id1, x1, y1, borda, preenchimento, txt);
            insert(listaObjeto[3], texto);
        }
    }

    desenhaGeoSvg(arqSvg, listaObjeto);

    finalizaSvg(arqSvg);

    fclose(geo);
}