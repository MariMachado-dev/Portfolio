#include <stdio.h>

int main()
{
    int base, expoente, resultado = 1, i;
	
	printf("Forneça a base: ");
	scanf("%d", &base);
	
	printf("Forneça o expoente: ");
	scanf("%d", &expoente);
	
	for (i =1; i <= expoente; i++)
	{
		resultado *= base;
	}
	
	printf("O resultado da potencia é %d",resultado);
	
	return 0;
}
