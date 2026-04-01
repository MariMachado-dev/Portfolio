#include <stdio.h>

int main()
{
    int n, i, elemento, maior_elemento = 0, menor_elemento = 1000000;
    
    printf("Limite de valores a serem fornecidos: ");
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++)
    {
        printf("Valor %d: ", i);
        scanf("%d", &elemento);
        
        //Checando se é o maior elemento
        if (elemento > maior_elemento)
        {
            maior_elemento = elemento;
        }
        
        //Checando se é o menor elemento
        if (elemento < menor_elemento)
        {
            menor_elemento = elemento;
        }
        
        
    }
    
    printf("O menor elemento fornecido é %d e o maior é %d.", menor_elemento, maior_elemento);

    return 0;
}
