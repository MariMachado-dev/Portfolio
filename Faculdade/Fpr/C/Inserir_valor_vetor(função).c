#include <stdio.h>

void exibirVetor(int vet[], int tamanho);
int posicionarValorVet(int vet[], int tamanho, int valor);

int main()
{
    int tamanho = 5, x, posicao;
    int vetor[] = {1,5,8,11,17};
    
    printf("Forneça um numero para colocar dentro do vetor em sua devida posição:");
    scanf("%d", &x);

    tamanho = posicionarValorVet(vetor, tamanho, x);
    
    exibirVetor(vetor, tamanho);

    return 0;
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

int posicionarValorVet(int vet[], int tamanho, int valor)
{
    int i;
    
    for (i = 0; i < tamanho; i++)
    {
        if (valor <= vet[i])
        {
            // Desloca os elementos para a direita
            for (int j = tamanho; j > i; j--)
            {
                vet[j] = vet[j - 1];
            }

            // Insere o valor na posição encontrada
            vet[i] = valor;

            // Retorna o novo tamanho
            return tamanho + 1;
        }
    }

    vet[tamanho] = valor;
    return tamanho + 1;
}
