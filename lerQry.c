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

    int r;
    int ro;
    int rd;
    int index;
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
    double prop;
    double incprop;

    Pilha pilhas[10];
    
    for(int i = 0; i < 10; i++)
    {
        pilhas[i] = criaPilha();
    }

    Fila filas[10];

    for(int i = 0; i < 10; i++)
    {
        filas[i] = criaFila();
    }

    Lista listas[10];

    for(int i = 0; i < 10; i++)
    {
        listas[i] = create();
    }

    No registradores[10];

    for(int i = 0; i < 10; i++)
    {
        registradores[i] = NULL;
    }

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
            pnt(listaObjeto, j, corb, corp, saida);

        }
        else if(strcmp(tipo,"delf") == 0)
        {
            fscanf(qry,"%s", j);
            fprintf(saida,"%s %s\n", tipo, j);
            delf(listaObjeto, j, saida);
        }
        else if(strcmp(tipo,"psh") == 0)
        {
            fscanf(qry,"%d %s", &index, j);
            psh(listaObjeto, j, pilhas[index]);
            pshQ(listasQry, j, pilhas[index]);
        }
        else if(strcmp(tipo,"pop") == 0)
        {
            fprintf(saida,"%s %s\n", tipo, j);
            fscanf(qry,"%d %s %lf %lf %lf", &index, j, &x, &y, &prop);
            pop(listasQry, listaObjeto, pilhas[index], x, y, prop, j, saida);
        }
        else if(strcmp(tipo,"inf") == 0)
        {
            fscanf(qry,"%d %s", &index, j);
            inf(listaObjeto, j, filas[index]);
            infQ(listasQry, j, filas[index]);
        }
        else if(strcmp(tipo,"rmf") == 0)
        {
            fprintf(saida,"%s %s\n", tipo, j);
            fscanf(qry,"%d %s %lf %lf %lf", &index, j, &x, &y, &prop);
            rmf(listasQry, listaObjeto, filas[index], x, y, prop, j, saida);
        }
        else if(strcmp(tipo,"ii") == 0)
        {
            fscanf(qry,"%d %s %d", &index, j, &r);
            registradores[r] = ii(listaObjeto, listas[index], j, registradores[r]);
            registradores[r] = iiQ(listasQry, listas[index], j, registradores[r]);
        }
        else if(strcmp(tipo,"if") == 0)
        {
            fscanf(qry,"%d %s %d", &index, j, &r);
            registradores[r] = iF(listaObjeto, listas[index], j, registradores[r]);
            registradores[r] = iFQ(listasQry, listas[index], j, registradores[r]);
        }
        else if(strcmp(tipo,"ia") == 0)
        {
            fscanf(qry,"%d %s %d %d", &index, j, &ro, &rd);
            if(registradores[ro] != NULL)
            {
                registradores[rd] = ia(listaObjeto, listas[index], j, registradores[ro], registradores[rd]);
                registradores[rd] = iaQ(listasQry, listas[index], j, registradores[ro], registradores[rd]);
            }
        }
        else if(strcmp(tipo,"id") == 0)
        {
            fscanf(qry,"%d %s %d %d", &index, j, &ro, &rd);
            if(registradores[ro] != NULL)
            {
                registradores[rd] = iD(listaObjeto, listas[index], j, registradores[ro], registradores[rd]);
                registradores[rd] = idQ(listasQry, listas[index], j, registradores[ro], registradores[rd]);
            }
        }
        else if(strcmp(tipo,"da") == 0)
        {
            fscanf(qry,"%d %d", &index, &r);
            if(registradores[r] != NULL)
            {
                No aux = getPrevious(registradores[r]);
        	    if(aux != NULL)
                {
                    removerNo(listas[index], aux, NULL);
                }
            }   
        }
        else if(strcmp(tipo,"dd") == 0)
        {
            fscanf(qry,"%d %d", &index, &r);
            if(registradores[r] != NULL)
            {
                No aux = getNext(registradores[r]);
        	    if(aux != NULL)
                {
                    removerNo(listas[index], aux, NULL);
                }
            }
        }
        else if(strcmp(tipo,"dpl") == 0)
        {
            fscanf(qry,"%d %s %lf %lf %lf %lf", &index, j, &x, &y, &prop, &incprop);
            dpl(listasQry, listas[index], x, y, j, prop, incprop, saida);
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