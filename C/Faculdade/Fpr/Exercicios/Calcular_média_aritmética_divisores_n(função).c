#include <stdio.h>

int mediaDivisoresn(int n)
{
    int i, soma = 0, contDivisores = 0;
    float media;
    
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            soma += i;
            contDivisores++;
        }
    }
    
    //Calcular media
    media = soma / contDivisores;
    
    return media;
}

int main()
{
    int n; 
    
    printf("Forneça um numero inteiro:");
    scanf("%d", &n);
    
    printf("A media aritimetica dos divisores de n é %d.", mediaDivisoresn(n));

    return 0;
}
