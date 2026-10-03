#include <stdio.h>
#include <string.h>

int criarArquivoOrdenado(char nomeArqA[], char nomeArqB[], char nomeArqC[]);

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
            
    resp = criarArquivoOrdenado (nomeArquivoA, nomeArquivoB, nomeArquivoC);
    
    if (resp == 1)
        printf ("\nArquivo %s gerado com sucesso!\n", nomeArquivoC);
    else
        printf ("\nErro na abertura dos arquivos!\n");
}

int criarArquivoOrdenado(char nomeArqA[], char nomeArqB[], char nomeArqC[])
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

    else
    {
        temA = fscanf(arqA, "%f", &numA);
        temB = fscanf(arqB, "%f", &numB);

        while (temA != EOF && temB != EOF)
        {
            if (numA < numB) 
            {
            fprintf(arqC, "%f", numA);
            temA = fscanf(arqA, "%f", &numA);
            } 
            
            else if (numB < numA) 
            {
            fprintf(arqC, "%f", numB);
            temB = fscanf(arqB, "%f", &numB);
            }
            
            else 
            {
            fprintf(arqC, "%.2f\n", numA);
            temA = fscanf(arqA, "%f", &numA);
            temB = fscanf(arqB, "%f", &numB);
            }
        }
    }
        fclose (nomeArqA);
		fclose (nomeArqB);	
        fclose (nomeArqC);	

        return 1;
}
