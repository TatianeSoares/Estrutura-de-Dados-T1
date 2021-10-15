#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lerQry.h"

void lerQry (char saidaQry[], char arqQry[], Lista listasQry[], Lista listaObjeto[])
{
    char* saidaTxt = malloc((5 + strlen(saidaQry))*sizeof(char));
    char* saidaSvg = malloc((5 + strlen(saidaQry))*sizeof(char));
    sprintf(saidaTxt,"%s.txt",saidaQry);
    sprintf(saidaSvg,"%s.svg",saidaQry);

    FILE* qry = fopen(arqQry,"r");
    if(qry == NULL)
    {
        printf("Erro ao abrir o QRY ");
    }

    FILE* saida = fopen(saidaTxt,"w");
    if(saida == NULL)
    {
        printf("Erro ao gerar o TXT\n");
        exit(1);
    }

    FILE* arqSaidaSvg = fopen(saidaSvg, "w");

    if(arqSaidaSvg == NULL)
    {
        printf("Erro ao abrir o arquivo de saida qry\n");
        exit(1);
    }

    iniciaSvg(arqSaidaSvg);

    char j[20];
    char k[20];
    char id[20];
    char tipo[5];
    char corb[20];
    char corp[20];
    char cor1[20];
    char cor2[20];

    double x;
    double y;
    double w;
    double h;

    while(fscanf(qry,"%s",tipo) != EOF)
    {
        if(strcmp(tipo,"o?") == 0)
        {
            fscanf(qry,"%s %s %s %s %s", j, k, id, cor1, cor2);
            fprintf(saida,"%s %s %s\n", tipo, j, k);
            o(j, k, id, cor1, cor2, saida, listasQry, listaObjeto);
        }
        else if(strcmp(tipo,"i?") == 0)
        {
            fscanf(qry,"%s %lf %lf", j, &x, &y);
            fprintf(saida,"%s %s %lf %lf\n", tipo, j, x, y);
            i(listaObjeto, j, x, y, saida, listasQry);
        }
        else if(strcmp(tipo,"pnt") == 0)
        {
            fscanf(qry,"%s %s %s", j, corb, corp);
            fprintf(saida,"%s %s %s %s\n",tipo, j, corb, corp);
            //pnt(j, corb, corp, saida);

        }
        else if(strcmp(tipo,"delf") == 0)
        {
            fscanf(qry,"%s", j);
            fprintf(saida,"%s %s\n", tipo, j);
            //delf(j, saida);
        }
    }

    gerarSvgQry(listaObjeto, arqSaidaSvg, listasQry);

    finalizaSvg(arqSaidaSvg);

    fclose(saida);
    fclose(qry);
    fclose(arqSaidaSvg);
    free(saidaSvg);
    free(saidaTxt);
}