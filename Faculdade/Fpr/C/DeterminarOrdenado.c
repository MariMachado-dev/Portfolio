#include <stdio.h>
#include <string.h>

int determinarOrdenado(char nomeArq[]);

void main ()
{
    char nomeArquivo[30];
    int resp;
    
    printf("Nome do arquivo: ");
    fgets(nomeArquivo, sizeof(nomeArquivo), stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

    resp = determinarOrdenado(nomeArquivo);
    
    switch (resp)
	{
        case -1: printf ("\n\nNao foi possivel abrir o arquivo!\n");
		         break;

		case 1: printf ("\n\nOs numeros escritos no arquivo %s estao ordenados!\n", nomeArquivo);
		         break;
        
		case 0:  printf ("\n\nOs numeros escritos no arquivo %s nao estao ordenados!\n", nomeArquivo);
		         break;
    }
}

int determinarOrdenado(char nomeArq[])
{
    FILE *arq;
    int atual, anterior;
    char c;

    arq = fopen (nomeArq,"r");
	
	if (!arq) 
	{
		return -1;
	}

	else
	{
		
		fscanf(arq, "%d", &anterior);

        while (fscanf(arq, "%d", &atual) != EOF)
        {
            if (atual < anterior)
            {
                fclose (arq);
                return 0;
            }

            anterior = atual;
        }
		
		//Passo 4: fechar o arquivo
		fclose (arq);
		
		return 1;
	}	
}