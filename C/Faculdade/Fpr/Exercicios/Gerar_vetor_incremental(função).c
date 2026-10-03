void ArmazenarVetor(int vet[], int tamanho);
void exibirVetor(int vet[], int tamanho);

int main()
{
    int const tamanho = 50;
    int vetor[tamanho];
    
    ArmazenarVetor(vetor, tamanho);
    exibirVetor(vetor, tamanho);


    return 0;
}
void ArmazenarVetor(int vet[], int tamanho)
{
    int i, Soma = 1;
    
    for (i = 0; i < tamanho;i++)
    {
        vet[i] = Soma;
        Soma += i;
    }
}

void exibirVetor(int vet[], int tamanho)
{
    int i;
    
    for (i = 1; i < tamanho;i++)
    {
        printf("%d, ", vet[i]);
    }
}
