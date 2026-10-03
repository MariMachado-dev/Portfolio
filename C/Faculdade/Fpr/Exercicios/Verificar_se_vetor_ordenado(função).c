#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void preecharUsuario(int vet[], int tamanho);
void exibirVetor(int vet[], int tamanho);
int ordenarVetor(int vet[], int tamanho);


int main()
{
    int const tamanho = 5;
    int vetor[tamanho];
    
    preecharUsuario(vetor, tamanho);
    exibirVetor(vetor, tamanho);

    
    if (ordenarVetor(vetor, tamanho) == 1)
    {
        printf("\n\nO vetor não esta ordenado");
    }
    else
    {
        printf("\n\nO vetor esta ordenado");
    }
    

    return 0;
}

int ordenarVetor(int vet[], int tamanho)
{
    int i;
    
    for(i = 0; i < tamanho - 1; i++)
    {
        if (vet[i] > vet[i + 1])
        {
            return 1;
        }
    }
    return 0;
}

void preecharUsuario(int vet[], int tamanho)
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
    
    printf("Elementos do vetor:");
    
    for (i = 0;i < tamanho;i++)
    {
        printf("%d ", vet[i]);
    }
}
