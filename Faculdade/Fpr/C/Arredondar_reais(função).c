#include <stdio.h>

float arredondar(float valor);

void main()
{
    int arredondado;
    float n;
    
    printf("Forneça um numero n real:");
    scanf("%f", &n);
    
    arredondado = arredondar(n);
    
    printf("O numero foi arredondado para %d", arredondado);
}

float arredondar(float valor)
{
    int corrigirValor;
    
    if (valor >= 0)
    {
        corrigirValor = valor + 0.5;
    }
    
    else
    {
        corrigirValor = valor - 0.5;   
    }
    
    return corrigirValor;
}
