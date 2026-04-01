#include <stdio.h>

int main()
{
    int n, i;
    
    printf("Escolha um limite: ");
    scanf("%d", &n);
    
    for (i = 2; i <= n; i += 2)
    {
        printf(" %d", i);
    }

    return 0;
}
