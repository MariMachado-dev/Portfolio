#include <stdio.h>
#include <string.h>

int criarArquivoOrdenado(char nomeArqA[], char nomeArqB[]);
int ordenarArq(char nomeArq[], int *maior, int limite);

void main ()
{
	char nomeArquivoA[30], nomeArquivoB[30];
	int resp;
	
	printf ("Nome do arquivo original: ");
	fgets (nomeArquivoA, sizeof(nomeArquivoA), stdin);
	nomeArquivoA[strcspn(nomeArquivoA, "\n")] = '\0';
	
	printf ("Nome do novo arquivo: ");
	fgets (nomeArquivoB, sizeof(nomeArquivoB), stdin);
	nomeArquivoB[strcspn(nomeArquivoB, "\n")] = '\0';
			
	resp = criarArquivoOrdenado (nomeArquivoA, nomeArquivoB);
	
	if (resp == 1)
	{
		printf ("\n\nArquivo %s gerado com sucesso!", nomeArquivoB);
	}
	else
	{
		printf ("\n\nErro na abertura dos arquivos!");
	}
}

int criarArquivoOrdenado (char nomeArqA[], char nomeArqB[])
{
	FILE *arqB;
	int maior, limite = 999999;

	arqB = fopen (nomeArqB, "w");   
	
	if (arqB)   
	{
		while (ordenarArq (nomeArqA, &maior, limite) != 0)
		{		
			fprintf (arqB, "%d\n", maior);
			limite = maior;
		}
		fclose (arqB);
		
		return 1;		
	}
	else
	{
		return 0;
	}
}

int ordenarArq(char nomeArq[], int* maior, int limite)
{
    FILE *arq;
	int num, atualizou = 0;
	
    arq = fopen (nomeArq, "r");

	if (!arq)
	{
		return -1;
	}
	else
	{
		*maior = -999999;
    }

    while (fscanf(arq, "%d", &num) != EOF)
    {
        if ((num < limite) && (num > *maior))
		{
			*maior = num;
			atualizou = 1;
		}
    }

	fclose (arq);
	return atualizou;
}