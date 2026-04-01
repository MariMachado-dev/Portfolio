#include <stdio.h>

int main()
{
    int binario, base = 1, resto, decimal, decimal_final = 0;
    printf("Forneça um numero binario:");
    scanf("%d", &binario);
    
    do{;
        resto = binario % 10;
        decimal = resto * base;
        decimal_final += decimal;
        base *= 2;
        binario /= 10;
        
    } while (binario > 0);
    
    printf("%d", decimal_final);
    return 0;
}
