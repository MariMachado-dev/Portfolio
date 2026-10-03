int main()
{
    int i,n, contador = 0;
    
    printf("Quantidade de números a serem exibidos: ");
    scanf("%d", &n);
    
    for (i = 2; contador < n; i *= 2)

    {
        printf(" %d", i);
        contador++;
    }
    
    

    return 0;
}
