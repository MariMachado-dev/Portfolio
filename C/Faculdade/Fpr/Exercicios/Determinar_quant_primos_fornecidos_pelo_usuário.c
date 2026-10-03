#include <stdio.h>
#define NUM_POSSIVEL_MULTIPLOS 50

int main()
{
    //Declara variaáveis
    int x, i, y, cont_multiplos = 0;
    
    //Pedir x
    printf("Escolha um número inteiro positivo x: ");
    scanf("%d", &x);
    
    for (i = 1; i <= NUM_POSSIVEL_MULTIPLOS; i++)
    {
        printf("Forneça %d número:", i);
        scanf("%d", &y);
        
        if (y % x == 0)
        {
            cont_multiplos++;
        }
        
    }
    printf("\nO total de múltiplos de x fornecdiso é %d.", cont_multiplos);

    return 0;
}
