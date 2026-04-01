#include <stdio.h>

int calcularLog(int base, int potencia);

void main()
{
    int base, potencia, resultado;
    
    printf("Forneça a base do logaritimo:");
    scanf("%d", &base);
    
    printf("Forneça a potencia do logaritimo:");
    scanf("%d", &potencia);
    
    resultado = calcularLog(base, potencia);
    
    printf("O logaritimo desses valores é %d", resultado);
}

int calcularLog(int base, int potencia)
{
    int limite = 1, logaritimo = 0;
    
    do
    {
        limite *= base;
        logaritimo++;
        
    } while (limite < potencia);
    
    return logaritimo;
}
