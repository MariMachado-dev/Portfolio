int main()
{
    int i = 0,n, passo, potencia;
    
    printf("Quantidade de números a serem exibidos: ");
    scanf("%d", &n);
    
    for (passo = 0;passo < n; passo ++)

    {
        i += passo;
        
        potencia = 1;
        for (int j = 0; j < i; j++) 
        {
            potencia *= 2;
        }
        printf(" %d", potencia);
        
    }
    
    
    return 0;
}
