#include <stdio.h>
#include <ctype.h>

int main()
{
    int memoria = 0, valor;
    char A, B, C, D, E, F, operacoes;
    
    do {
        printf("Escolha uma das operaçoes seguintes para realizar:(A) Soma; "
        "(B) Subtração; (C) Multiplicação; (D) Divisão; (E) Limpar memoria; (F) Sair:");
        scanf(" %c", &operacoes);
        getchar();
        operacoes = toupper(operacoes);
        
        if (operacoes == 'A')
        {
            printf("Qual valor a ser adicionado para a memoria?");
            scanf("%d", &valor);
            
            memoria += valor;

        }
        
        else if (operacoes == 'B')
        {
            printf("Qual valor a ser subtraido da memoria?");
            scanf("%d", &valor);
            
            memoria -= valor;
        }
        
        else if (operacoes == 'C')
        {
            printf("Qual valor a ser multiplicado pela memoriaa?");
            scanf("%d", &valor);
            
            memoria *= valor;
        }
        
        else if (operacoes == 'D')
        {
            printf("Qual valor a ser dividido da memoria?");
            scanf("%d", &valor);
            
            memoria /= valor;
        }
        
        else if (operacoes == 'E')
        {
            memoria = 0;
        }
        
        
        
    } while (operacoes != 'F');
    
    printf("\nValor final:%d", memoria);
    
    return 0;
}
