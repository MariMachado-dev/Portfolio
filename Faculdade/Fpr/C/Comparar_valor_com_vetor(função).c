#include <stdio.h>
#include <limits.h>

void compararnVet(int valor, int vet[], int tam, int *maiorValor, int *menorValor);

int main()
{
    int n;
    int maiorQueN, menorQueN;
    int tamanho = 3;
    int vetor[] = {4,2,7,9};
    
    printf("Forneça um numero n real:");
    scanf("%d", &n);
    
    compararnVet(n, vetor, tamanho, &maiorQueN, &menorQueN);
    
    printf("O menor valor dentro do vetor e maior que n é %d.\n", maiorQueN);
    
    printf("O maior valor dentro do vetor e menor que n é %d.\n", menorQueN);

    return 0;
}

void compararnVet(int valor, int vet[], int tam, int *maiorValor, int *menorValor)
{
    int i;
    *maiorValor = INT_MAX;
    *menorValor = INT_MIN;
    
    for (int i = 0; i < tam; i++)
    {
        if (vet[i] > valor && vet[i] < *maiorValor)
        {
            *maiorValor = vet[i];
        }
        
        if (vet[i] < valor && vet[i] > *menorValor) 
        {
            *menorValor = vet[i];
        }
    }
}
