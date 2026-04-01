#include <stdio.h>

int main()
{
    int n, i, produto = 1, soma = 0;

    for (i = 1;i < 100 ;i++)
    {
        printf("Digite um número (0 para sair): ");
        scanf("%d", &n);
        
        if (n == 0 || n < 0)
        {
            break;
        }
        else if (n % 2 == 0)
        {
            soma += n;
        }
        else
        {
            produto *= n;
        }
    }
    printf("O produto dos impares é %d e a soma dos pares é %d.", produto, soma);
    
    return 0;
}
