#include <stdio.h>

void exibirPrimos(int n)
{
    int i, j;
    
    //Contar numeros primos
    for (i = 2; i <= n; i++)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (j == i) 
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int n;
    
    printf("Forneça um numero limite:");
    scanf("%d", &n);
    
    exibirPrimos(n);

    return 0;
}
