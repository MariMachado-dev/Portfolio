#include <stdio.h>

int main()
{
    int i, j, resultado;
    
    for (i = 0; i <= 9; i++)
    {
        for (j = 1; j <= 9; j++)
        {
            resultado = i * j;
            printf ("%d × %d = %-2d   ", j, i,  resultado);
            
        }
        printf("\n");
    }

    return 0;
}
