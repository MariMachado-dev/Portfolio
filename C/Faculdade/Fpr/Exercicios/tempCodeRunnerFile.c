#include <stdio.h>
#include <string.h>

int criarArquivoIntersecao(char nomeArqA[], char nomeArqB[], char nomeArqC[]);

void main ()
{
    char nomeArquivoA[30], nomeArquivoB[30], nomeArquivoC[30];
    int resp;
    
    printf ("Nome do primeiro arquivo: ");
    fgets (nomeArquivoA, sizeof(nomeArquivoA), stdin);
    nomeArquivoA[strcspn(nomeArquivoA, "\n")] = '\0';
    
    printf ("Nome do segundo arquivo: ");
    fgets (nomeArquivoB, sizeof(nomeArquivoB), stdin);
    nomeArquivoB[strcspn(nomeArquivoB, "\n")] = '\0';

    printf ("Nome do novo arquivo: ");
    fgets (nomeArquivoC, sizeof(nomeArquivoC), stdin);
    nomeArquivoC[strcspn(nomeArquivoC, "\n")] = '\0';
            
    resp = criarArquivoIntersecao (nomeArquivoA, nomeArquivoB, nomeArquivoC);
    
    if (resp == 1)
        printf ("\nArquivo %s gerado com sucesso!\n", nomeArquivoC);
    else
        printf ("\nErro na abertura dos arquivos!\n");
}

int criarArquivoIntersecao(char nomeArqA[], char nomeArqB[], char nomeArqC[])
{
    FILE *arqA;
    FILE *arqB;
    FILE *arqC;

    float numA, numB;
	int temA, temB;

    arqA = fopen(nomeArqA, "r");
    arqB = fopen(nomeArqB, "r");
    arqC = fopen(nomeArqC, "w");


    if (!arqA || !arqB || !arqC)
    {
        return 0;
    }

    temA = fscanf(arqA, "%f", &numA);
    temB = fscanf(arqB, "%f", &numB);

    while (temA != EOF && temB != EOF)
    {
        if (numA == numB)
        {
            fprintf(arqC, "%f", numA);
            temA = fscanf(arqA, "%f", &numA);
            temB = fscanf(arqB, "%f", &numB);
        }

        else if (numA < numB)
        {
            temA = fscanf(arqA, "%f", &numA);
        }

        else if (numA > numB)
        {
            temB = fscanf(arqB, "%f", &numB);
        }
    }

    fclose (arqA);
	fclose (arqB);	
    fclose (arqC);	

    return 1;
}