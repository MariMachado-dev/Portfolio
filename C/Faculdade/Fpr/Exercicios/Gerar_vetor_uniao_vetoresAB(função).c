#include <stdio.h>

void exibirVetor(int vet[], int tamanho);
int GerarVetorC(int vetA[], int vetB[], int tamanhoA, int tamanhoB, int vetC[]);

int main()
{
    int tamanhoA = 5;
    int tamanhoB = 5;
    int vetorA[] = {1,5,8,11,17};
    int vetorB[] = {2,6,15,0,3};
    int tamanhoC, VetorC[100];
    
    printf("Vetor A:");
    exibirVetor(vetorA, tamanhoA);
    
    printf("\n\nVetor B:");
    exibirVetor(vetorB, tamanhoB);

    tamanhoC = GerarVetorC(vetorA, vetorB, tamanhoA, tamanhoB, VetorC);
    
    printf("\n\nVetor C:");
    exibirVetor(VetorC, tamanhoC);
    

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

int GerarVetorC(int vetA[], int vetB[], int tamanhoA, int tamanhoB, int vetC[])
{
    int i, j = 0, tamanhoC;
    tamanhoC = tamanhoA + tamanhoB; 

    for (i = 0;i < tamanhoC;i++)
    {
        if (i < tamanhoA)
        {
            
            vetC[i] = vetA[i];
        }
            
        else
        {
            vetC[i] = vetB[j];
            j++;
        }
    }
    
    return tamanhoC;
}
