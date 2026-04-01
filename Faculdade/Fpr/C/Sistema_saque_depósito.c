#include <stdio.h>
#include <ctype.h>

int main()
{
    float saldo, valor, total_saque, total_deposito;
    char Saque, Deposito, Fim, operacoes;
    
    do
    {
    printf("Qual o saldo inicial?");
    scanf("%f", &saldo);
    
    //Invalidar números negativos
    } while (saldo < 0);
    
    do {
        //Escolher operações
        printf("Escolha uma das operaçoes seguintes:(S) Saque; (D) Deposito; (F) Fim:");
        scanf(" %c", &operacoes);
        operacoes = toupper(operacoes);
        
        //Sacar (caso exista saldo)
        if (operacoes == 'S')
        {
            printf("Quanto deseja sacar?");
            scanf("%f", &valor);
            
            if (saldo < valor)
            {
                printf("ERRO:Saldo indisponivel\n\n");
            }
            else
            {
                saldo -= valor;
                total_saque += valor;
                printf("\n");
            }
        }
        
        else if (operacoes == 'D')
        {
            printf("Quanto deseja depositar?");
            scanf("%f", &valor);
            
            if (valor < 0)
            {
                printf("ERRO:Valor invalido\n\n");
            }
            else
            {
                saldo += valor;
                total_deposito += valor;
                printf("\n");
            }
        }
    } while (operacoes != 'F');
    
    printf("\n");
    printf("Total em reais de saques realizados:%.2f\n", total_saque);
    printf("Total em reais de saques realizados:%.2f\n", total_deposito);
    printf("Valor final:%.2f", saldo);
    
    return 0;
}
