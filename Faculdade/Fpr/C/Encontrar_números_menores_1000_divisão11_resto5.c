#include <stdio.h>

int main()
{
    int i, contador = 0;
    
    for (i = 1000; i < 2000;i++)
    {
        if (i % 11 == 5)
        {
            contador++;
            if (contador == 5)
            {
                printf("O número %d é quinto número maior que 1000, cuja divisão por 11 tenha resto 5.", i);
                return 0;
            }
        }        
        else    
        {
            //Volta no for
        }
    }
}
