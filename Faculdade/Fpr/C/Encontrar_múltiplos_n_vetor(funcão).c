#include <stdio.h>

void intervalo(int a, int b, int n)
{
    int i;
    
    for (i = a; i <= b; i++)
    {
        if (i % n == 0)
        {
            printf("%d ", i);
        }
    }
}


int main()
{
    int a, b, n;
    
    printf("Forneça o primeiro numero do intervalo:");
    scanf("%d", &a);
    
    printf("Forneça o ultimo numero do intervalo:");
    scanf("%d", &b);
    
    printf("Forneça um numero para achar seus multiplos no intervalo:");
    scanf("%d", &n);
    
    intervalo(a, b, n);
    
    return 0;
}
