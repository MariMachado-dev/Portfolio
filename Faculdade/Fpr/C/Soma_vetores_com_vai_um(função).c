int criarVetorSoma(int vetA[],int vetB[],int  tamA,int tamB,int vetC[], int tamC);
void exibirVetor(int vet[], int tamanho);

int main()
{
    int tamanhoA = 3;
    int vetorA[] = {8,3,7};
    int tamanhoB = 3;
    int vetorB[] = {1,8,3};
    int vetorC[4];
    int tamanhoC = tamanhoA;
    
    printf("Elementos dos vetores a serem somados:\n\n");
    
    exibirVetor(vetorA, tamanhoA);
    exibirVetor(vetorB, tamanhoB);
    
    tamanhoC = criarVetorSoma(vetorA, vetorB, tamanhoA, tamanhoB, vetorC, tamanhoC);
    
    printf("\nResultado:");
    
    exibirVetor(vetorC, tamanhoC);

    return 0;
}

int criarVetorSoma(int vetA[],int vetB[],int  tamA,int tamB,int vetC[], int tamC)
{
    int i, j = i, mais1 = 0, soma;
    
    for (i = tamA - 1; i >= 0; i--)
    {
        soma = vetA[i] + vetB[i] + mais1;
           
        if (soma > 9)
        {
            vetC[i] = soma - 10;
            mais1 = 1;
          
            if (i == 0)
            {
              for (j = tamA; j > 0; j--)
              {
                  vetC[j] = vetC[j - 1];
                  
              }
              
              vetC[0] = 1;
              tamC++;
            }
        }
        
        else
        {
            vetC[i] = soma;
        }
    }
    
    return tamC;
}

void exibirVetor(int vet[], int tamanho)
{
    int i;
    
    for (i = 0;i < tamanho;i++)
    {
        printf("%d ", vet[i]);
    }
    
    printf("\n");
}
