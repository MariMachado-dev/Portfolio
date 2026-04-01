#include <stdio.h>

int main()
{
    //Definir variáveis
    int a1, r, n, an, i;
    
    printf("Forneça quantos termos deseja que sejam calculados: ");
    scanf("%d", &n);
    
    printf("Forneça o primeiro termo da PA: ");
    scanf("%d", &a1);
    
    printf("Forneça a razão da PA: ");
    scanf("%d", &r);
    
    for (i = 1;i <= n;i++)
    {
        an = a1 + (i - 1)*r;
        printf(" %d", an);
    }

    return 0;
}
