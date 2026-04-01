#include <stdio.h>

void contarPot(int maior, int menor, int* contPot, int* maiorPot);

void main()
{
    int a, b, maior,  menor;
    int quantPot, maiorValor;
    
    printf("Forneça o primeiro numero do intervalo:");
    scanf("%d", &a);
    
    printf("Forneça o segundo numero do intervalo maior que o primeiro:");
    scanf("%d", &b);
    
    //Definir maior
    if (a > b)
    {
        maior = a;
        menor = b;
    }
    
    else
    {
        maior = b;
        menor = a;
    }
    
    contarPot(maior, menor, &quantPot, &maiorValor);
    
    //Exibindo aos parametros saida
    printf("O intervalo apresenta %d potencias de 2.\nA maior potrncia é %d.", quantPot, maiorValor);
}

void contarPot(int maior, int menor, int *contPot, int *maiorPot)
{
    int i, j;
    
    *contPot = 0;
    *maiorPot = 0;
    
    //Fazer for para contar intervalo
    for (i = menor;i <= maior; i++)
    {
        for (j = 1; j <= i; j *= 2)
        {
            if (j == i)
            {
                (*contPot)++;
                
                //Guardar maior potrncia
                if (j > *maiorPot)
                {
                    *maiorPot = j;
                }
            }
        }
    }
}
