#include <stdio.h>

void preencherUsuario(int vet[], int tamanho);
void exibirVetor(int vet[], int tamanho);
void alterarxy(int vet[], int tamanho, int original, int substituido);


void main()
{
    int const tamanho = 5;
    int vetor[tamanho], x, y;
    
    preencherUsuario(vetor, tamanho);
    exibirVetor(vetor, tamanho);
    
    printf("\n\nQual numero deseja que seja substituido?");
    scanf("%d", &x);
    
    printf("E por qual numero?");
    scanf("%d", &y);
    
    alterarxy(vetor, tamanho, x, y);
    
    exibirVetor(vetor, tamanho);
    
    
    
}

void alterarxy(int vet[], int tamanho, int original, int substituido)
{
    int i;
    
    for (i = 0;i < tamanho;i++)
    {
        if (vet[i] == original)
        {
            vet[i] = substituido;
        }
    }
}

void preencherUsuario(int vet[], int tamanho)
{
    int i;
   
    for (i = 0;i < tamanho;i++)
    {
        printf("Forneça o %d valor do vetor:", i + 1);
        scanf("%d", &vet[i]);
    }
}

void exibirVetor(int vet[], int tamanho)
{
    int i;
    
    printf("\nElementos do vetor:\n\n");
    
    for (i = 0;i < tamanho;i++)
    {
        printf("%d ", vet[i]);
    }
}
