#include <stdio.h>

int contVet(int vetor[], int tamanho, int n);

int main()
{
    int vet[5], valor, i, contOcorrencia;
    
    for (i = 0;i < 5;i++)
    {
        printf("Forneça um valor do vetor:");
        scanf("%d", &vet[i]);
    }
    
    printf("Numero comparado no vetor:");
    scanf("%d", &valor);
    
    contOcorrencia = contVet(vet, 5, valor);
    printf("O valor aparece %d vezes no vetor", contOcorrencia);

}

int contVet(int vetor[], int tamanho, int n)
{
    int i, cont = 0;
    
    for (i = 0; i < tamanho; i++)
    {
        if (vetor[i] == n)
        {
            cont++;
        }
    }
    
    return cont;
}
