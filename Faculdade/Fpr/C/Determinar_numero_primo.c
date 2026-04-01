#include <stdio.h>

int main()
{
    //Definir variaáveis
    int n, i = 2, y;
    
    //Adquir numero n qualuwer
    printf("Forneça um numero:");
    scanf("%d", &n);
    
    //Testar divisoes do n por i
    while (i < n)
    {
        y = n % i;
        i++;
        
        if (y == 0)
        {
            printf("Ele não é um numero primo");
            return 0;
        }

    }
    printf("Ele é um numero primo");

    return 0;
}
