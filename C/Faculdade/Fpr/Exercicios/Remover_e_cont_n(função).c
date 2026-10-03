#include <stdio.h>

void preencherUsuario(float vet[], int tamanho);
void exibirVetor(float vet[], int tamanho);
int removerxCont(float vet[], int *tamanho, float valor);


void main()
{
    int tamanho = 5;
    float vetor[tamanho], x;
    int contRemocoes;
    
    preencherUsuario(vetor, tamanho);
    exibirVetor(vetor, tamanho);
    
    printf("\n\nQual numero deseja que seja removido?");
    scanf("%f", &x);

    contRemocoes = removerxCont(vetor, &tamanho, x);
    
    printf("O numero foi removido %d vezes.\n", contRemocoes);
    
    exibirVetor(vetor, tamanho);
}

int removerxCont(float vet[], int *tamanho, float valor)
{
    int i, cont = 0, j = 0;
    
    for (i = 0;i < *tamanho;i++)
    {
        if (vet[i] == valor)
        {
            cont++;
        }
        else
        {
            vet[j] = vet[i];
            j++;
        }
    }
    *tamanho = j;
    
    return cont;
}

void preencherUsuario(float vet[], int tamanho)
{
    int i;
   
    for (i = 0;i < tamanho;i++)
    {
        printf("Forneça o %d valor do vetor:", i + 1);
        scanf("%f", &vet[i]);
    }
}

void exibirVetor(float vet[], int tamanho)
{
    int i;
    
    printf("\nElementos do vetor:\n\n");
    
    for (i = 0;i < tamanho;i++)
    {
        printf("%.2f ", vet[i]);
    }
}
