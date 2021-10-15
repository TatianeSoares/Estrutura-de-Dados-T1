#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "lerGeo.h"
#include "circulo.h"
#include "secondMain.h"

int main(int argc, char *argv[])
{
    char *dir_entrada = NULL;
    char *dir_saida = NULL;

    char *arq_geoNome = NULL;
    char *arq_consulta = NULL;
 
    int i;
    for(i=1;i<argc;i++)
    {
        if(strcmp("-e", argv[i]) == 0 )
        {
            i++;
            if(argv[i] == NULL)
            {
                printf("\nERRO\nDiretorio de entrada nao encontrado\n");
                exit(1);
            }
            dir_entrada = (char*) malloc((strlen(argv[i]) + 1)*sizeof (char));
            strcpy(dir_entrada,argv[i]);
        }
        else if(strcmp("-f", argv[i]) == 0)
        {
            i++;
            if(argv[i] == NULL)
            {
                printf("\nERRO\nParametro nao foi encontrado em -f\n");
                exit(1);
            }
            arq_geoNome = (char*) malloc((strlen(argv[i]) + 1)*sizeof (char));
            strcpy(arq_geoNome,argv[i]);
        
        }
        else if(strcmp("-q", argv[i]) == 0)
        {
            i++;
            if(argv[i] == NULL)
            {
                printf("\nERRO\nParametro nao foi econtrado em -q\n");
                exit(1);
            }

            arq_consulta = (char*) malloc((strlen(argv[i]) + 1)*sizeof (char));
            strcpy(arq_consulta,argv[i]);

        }
        else if(strcmp("-o", argv[i]) == 0)
        {
            i++;
            if(argv[i] == NULL)
            {
                printf("\nERRO\nDiretorio de saida nao foi econtrado\n");
                exit(1);
            }
            dir_saida = (char*) malloc((strlen(argv[i]) + 1)*sizeof (char));
            strcpy(dir_saida, argv[i]);      
        }
    }

    mainS(dir_entrada, dir_saida, arq_geoNome, arq_consulta);

    free(dir_saida);
    free(dir_entrada);
    //free(arq_geoNome);
    free(arq_consulta);
}