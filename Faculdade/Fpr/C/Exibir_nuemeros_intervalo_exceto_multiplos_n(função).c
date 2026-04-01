void exibirNumerosIntervaloExcetoN();

void main()
{
    int n, a , b;
    
    printf("Forneça o primeiro numero do intervalo:");
    scanf("%d", &a);
    
    printf("Forneça o segundo numero do intervalo maior que o primeiro:");
    scanf("%d", &b);
    
    printf("Forneça um numero para pular seus multiplos:");
    scanf("%d", &n);
    
    exibirNumerosIntervaloExcetoN(n, a, b);
}

void exibirNumerosIntervaloExcetoN(int numero, int a, int b)
{
    int i;
    
    for (i = a; i <= b; i++)
    {
        if (i % numero != 0)
        {
            printf("%d ", i);
        }
    }
}
