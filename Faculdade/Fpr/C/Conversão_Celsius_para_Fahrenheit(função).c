#include <stdio.h>

float conversaoTemp(float tempC)
{
    float tempF;
    
    tempF = (tempC * 1.8) + 32;
    
    return tempF;
}

int main()
{
    float tempC;
    
    printf("Forneça uma temperatura em Celsius:");
    scanf("%f", &tempC);
    
    float tempF = conversaoTemp(tempC);
    
    printf("%.1f graus Celsius são %.1f graus Fahrenheit.", tempC, tempF);
    
    return 0;
}
