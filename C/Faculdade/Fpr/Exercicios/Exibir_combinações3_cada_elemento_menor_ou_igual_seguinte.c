#include <stdio.h>

int main()
{
    int i, j, k, n;
    
    printf("Limite do intervalo:");
    scanf("%d", &n);
    
    for (i = 1;i <= n; i++)
    {
        for (j = i;j <= n; j++)
        {
            for (k = j;k <= n; k++)
            {
                printf("%d %d %d\n", i, j, k);
            }
        }
    }

    return 0;
}
