#include <stdio.h>
#include <string.h>

int ContChar(char nomeArq[], char caract);

void main ()
{
    char nomeArquivo[30], caractere;
    int resp;
    
    printf("Nome do arquivo: ");
    fgets(nomeArquivo, sizeof(nomeArquivo), stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

    printf ("Caracter a ser contado: ");
	fflush (stdin);
	scanf ("%c", &caractere);

    resp = ContChar(nomeArquivo, caractere);
    
    switch (resp)
	{
		case -1: printf ("\n\nContagem nao foi possivel de ser realizada!\n");
		         break;
		         
		case 0:  printf ("\n\nO caracter %c nao existe no arquivo %s!\n", caractere, nomeArquivo);
		         break;
		         
		default: printf ("\n\nExistem %d caractere(s) '%c' no arquivo %s!\n\n", resp, caractere, nomeArquivo);
	}
}

int ContChar(char nomeArq[], char caract)
{
    FILE *arq;
    int cont = 0;
    char c;

    arq = fopen (nomeArq,"r");
	
	if (!arq) 
	{
		fclose (arq);
		
		return -1;
	}

	else
	{
		
		while (fscanf(arq, "%c", &c) != EOF)
        {
            if (c == caract)
            {
                cont++;
            }
		}
		
		//Passo 4: fechar o arquivo
		fclose (arq);
		
		return cont;
	}	
}