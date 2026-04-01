#include <stdio.h>

void combinaçoes(int n)
{
    int i, j;
    
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
            {
            }
            else
            {
                printf("(%d %d)", i, j);
            }
        }
    }
}

int main()
{
    int n;
    
    printf("Forneça um limite para as combinaçoes:");
    scanf("%d", &n);

    combinaçoes(n);
    
    return 0;
}
