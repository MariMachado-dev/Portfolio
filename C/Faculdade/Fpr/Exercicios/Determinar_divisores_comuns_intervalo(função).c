#include <stdio.h>

int acharDivisoresIguais(int a, int b, int n)
{
    //Definir variaveis
    int i, j, contDivisor = 0;
    
    //Checar divisores de n
    for (j = a; j <= b; j++)
    {
        //Caso divisivel, dividir pelos numeros do intervalo 
        for (i = 2; i <= n; i++)
        {
            //Se tbm divisiel pelo numero do intervalo, exibi-lo
            if (n % i == 0 && j % i == 0)
            {
                contDivisor++;
                break;
            }
        }
    }
    
    return contDivisor;
}

int main()
{
    int n, a, b;
    
    printf("Forneça o primeiro numero do intervalo:");
    scanf("%d", &a);
    
    printf("Forneça o primeiro numero do intervalo:");
    scanf("%d", &b);
    
    printf("Forneça o numero a ser comparado:");
    scanf("%d", &n);
    
    printf("Existem %d numeros no intervalo que possuem pelo menos 1 divisor igual a %d", acharDivisoresIguais(a, b, n), n);

    return 0;
}
