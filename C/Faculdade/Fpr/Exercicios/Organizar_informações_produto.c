
int main()
{
    //Definir variáveis
    int x, i;
    int contador_generoF = 0, contador_generoM = 0;
    int contador_opiniaoS = 0, contador_opiniaoN = 0;
    char genero, opiniao;
    
    //Definir número de intrevistados
    printf("Número de intrevistados: ");
    scanf("%d", &x);
    getchar();
        
    //Adquirir informações
    for (i = 1; i <= x; i++)
    {
        printf("\n%d⁰  entrevistado. \n", i);
        
        printf("Indique seu gênero([F] [M]): ");
        scanf(" %c", &genero);
        
        printf("Gostou do produto?([S] [N]): ");
        scanf(" %c", &opiniao);
        
        //Adicionar informações válidas a banco de dados
        if (genero == 'F')
            contador_generoF++;
        else if (genero == 'M')
            contador_generoM++;

        if (opiniao == 'S')
            contador_opiniaoS++;
        else if (opiniao == 'N')
            contador_opiniaoN++;
        
   
    }
    
    //Exibir dados da pesquisa
    printf("\n%d pessoas gostaram do produto.\n", contador_opiniaoS);
    printf("%d pessoas não gostaram do produto.\n", contador_opiniaoN);
        
    //Checar em que gênero o produto teve uma melhor aceitação.
    if (contador_generoM > contador_generoF)
    printf("O produto teve uma maior taxa de aprovação no público masculino");
        
    else if (contador_generoM < contador_generoF)
    printf("O produto teve uma maior taxa de aprovação no público feminino");
    
    else
    printf("A taxa de aprovação do produto foi a igual.");
    

    return 0;
}
