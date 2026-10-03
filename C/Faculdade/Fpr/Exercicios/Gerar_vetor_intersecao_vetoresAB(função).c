#include <stdio.h>

void exibirVetor(int vet[], int tamanho);
int IntersecaoAB(int vetA[], int vetB[], int tamanhoA, int tamanhoB, int vetC[]);

int main()
{
    int tamanhoA = 5;
    int tamanhoB = 5;
    int vetorA[] = {1,6,15,0,3};
    int vetorB[] = {4,73,8,1,0};
    int tamanhoC, VetorC[100];
    
    printf("Elementos do vetor A\n");
    exibirVetor(vetorA, tamanhoA);
    
    printf("\n\nElementos do vetor B\n");
    exibirVetor(vetorB, tamanhoB);

    tamanhoC = IntersecaoAB(vetorA, vetorB, tamanhoA, tamanhoB, VetorC);
    
    if (tamanhoC == 0)
    {
        printf("\n\nVetor C é vazio.");
    }
    
    else
    {
        printf("\n\nElementos do vetor C\n");
        exibirVetor(VetorC, tamanhoC);
    }

    return 0;
}

void exibirVetor(int vet[], int tamanho)
{
    int i;
    
    
    for (i = 0;i < tamanho;i++)
    {
        printf("%d ", vet[i]);
    }
}

int IntersecaoAB(int vetA[], int vetB[], int tamanhoA, int tamanhoB, int vetC[])
{
    int i, j, k = 0, tamanhoC = 0;

    for (i = 0;i < tamanhoA;i++)
    {
        for (j = 0; j < tamanhoB; j++)
        {
            if (vetA[i] == vetB[j])
            {
                tamanhoC++;
                vetC[k] = vetA[i];
                k++;
            }
        }
    }
    
    return tamanhoC;
}
