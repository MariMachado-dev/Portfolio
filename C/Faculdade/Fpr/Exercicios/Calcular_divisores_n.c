#include <stdio.h>

int main()
{


    int n, i, soma = 0;
    
    printf("Forneça um múmero a ser dividido: ");
    scanf("%d", &n);
     
    printf("Divisores de n\n");
     
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            printf(" %d", i);
        }
    }


    return 0;

