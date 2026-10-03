#include <stdio.h>
#include <string.h>

int ContCaracteres(char nomeArq[]);

int main() 
{
    char nomeArquivo[30];
    int resp;

    printf("Nome do arquivo: ");
    fgets(nomeArquivo, sizeof(nomeArquivo), stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

    resp = ContCaracteres(nomeArquivo);
    printf("O arquivo %s tem %d caracteres.", nomeArquivo, resp);
}

int ContCaracteres(char nomeArq[])
{
    int contChar = 0;
    char c;

    FILE *arq;
    arq = fopen (nomeArq, "r");

    if (arq == NULL) 
    {
    printf("Erro ao abrir o arquivo.\n");
    }
    
    while (fscanf(arq, "%c", &c) != EOF)
    {
        contChar++;
    }

    fclose(arq);
    return contChar;
}