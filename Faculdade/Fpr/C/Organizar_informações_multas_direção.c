#include <stdio.h>

int main()
{
    int numero_carteira, i, numero_multas, j, mais_multas = 0, motorista_multas;
    float valor_multa, divida = 0, recursos = 0;
    
    for (j = 1; j < 1000 ;j++)
    {
        printf("Número da carteira de motorista[digite 0 quando terminar de processar todos os motoristas]: ");
        scanf("%d", &numero_carteira);
        
        if (numero_carteira == 0)
        {
            break;
        }
        else
        {
            divida = 0;
            
            printf("Quantidade de multas recebidas: ");
            scanf("%d", &numero_multas);
            
            if (numero_multas > mais_multas)
            {
                mais_multas = numero_multas;
                motorista_multas = numero_carteira;
            }
        
            for (i = 1; i <= numero_multas;i++)
            {
                printf("Valor da %d multa: ", i);
                scanf("%f", &valor_multa);
                divida += valor_multa;
                
            }
            printf("Dívida total do motorista com carteira %d: R$ %.2f\n\n", numero_carteira, divida);
            
        recursos += divida;
        

        }
        
    }
    printf("Total de recursos arrecadados é %.2f reais.\n", recursos);
    printf("A pessoa com o número de carteira de motorista %d obteve o maior número de multas.", motorista_multas);
    
    

    return 0;
}
