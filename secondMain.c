#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "lerGeo.h"
#include "lerQry.h"


char *concatenacao(char dir_entrada[])
{	
	char* arqGeoConcatenado = NULL;
    char* aux = strrchr(dir_entrada,'/');

    if(aux == NULL)
	{
		arqGeoConcatenado=strtok(dir_entrada,".");
        return(arqGeoConcatenado);
    }

	arqGeoConcatenado=strtok(&aux[1],".");
	return(arqGeoConcatenado);

}

void mainS(char dir_entrada[], char dir_saida[], char arq_geoNome[], char arq_consulta[])
{
    char *saida = NULL;
    char *arqGeo = NULL;
    char *arqQry = NULL;
    char *nomeGeo = NULL;
    char *nomeQry = NULL;
    char *saidaQry = NULL;
    char *nomeSvgGeo = NULL;

    Lista listaObjeto[4];

    for(int i = 0; i < 4; i++)
    {
        listaObjeto[i] = create();
    }

    Lista listaQry[4];

    for(int i = 0; i < 4; i++)
    {
        listaQry[i] = create();
    }

    if(arq_geoNome == NULL || dir_saida == NULL)
    {
        printf("\nERRO\nArgumento essencial nao inserido\n");
        exit(1);
    }
    else if (dir_entrada != NULL) 
    {
        if(dir_entrada[strlen(dir_entrada) - 1] != '/')
        {
            arqGeo = (char *)malloc((strlen(arq_geoNome)+strlen(dir_entrada)+2)*sizeof(char));
    	    sprintf(arqGeo,"%s/%s",dir_entrada,arq_geoNome);
        }
        else
        {
            arqGeo = (char *)malloc((strlen(arq_geoNome)+strlen(dir_entrada)+1)*sizeof(char));
    	    sprintf(arqGeo,"%s%s",dir_entrada,arq_geoNome);
        }
        if(arq_consulta!= NULL)
        {
            arqQry = (char *)malloc((strlen(arq_consulta)+strlen(dir_entrada)+2)*sizeof(char));
            sprintf(arqQry,"%s/%s",dir_entrada,arq_consulta);
        }
    }
    else 
    {
		arqGeo = (char *)malloc((strlen(arqGeo)+1)*sizeof(char));
    	strcpy(arqGeo, arq_geoNome);
    }

    nomeGeo = concatenacao(arq_geoNome);

    if (dir_saida[strlen(dir_saida) - 1] == '/')
    {
        saida = (char*)malloc((strlen(nomeGeo) + strlen(dir_saida) + 1)*sizeof(char));
        sprintf(saida,"%s%s",dir_saida,nomeGeo);
    }
    else
    {
        saida = (char*)malloc((strlen(nomeGeo) + strlen(dir_saida) + 2)*sizeof(char));
        sprintf(saida,"%s/%s",dir_saida,nomeGeo);
    }

    nomeSvgGeo = (char*)malloc((strlen(saida) + 5)*sizeof(char));
    sprintf(nomeSvgGeo,"%s.svg",saida);

    lerGeo(arqGeo, nomeSvgGeo, listaObjeto);

    if(arq_consulta != NULL)
    {
        nomeQry = concatenacao(arq_consulta);
        saidaQry = (char*)malloc((strlen(nomeQry) + strlen(saida) + 2)*sizeof(char));
        sprintf(saidaQry,"%s-%s",saida,nomeQry);

        lerQry(saidaQry, arqQry, listaQry, listaObjeto);
    }

    free(saida);
    free(arqGeo);
    free(arqQry);
    //free(nomeGeo);
    //free(nomeQry);
    free(saidaQry);   
    free(nomeSvgGeo);
        
}