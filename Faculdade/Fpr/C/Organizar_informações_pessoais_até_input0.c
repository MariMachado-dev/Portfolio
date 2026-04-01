#include <stdio.h>

int main()
{
    int idade, cont_idade = 0, cont_pesquisa = 0, i = 0;
    float altura, peso, soma_h, media_h, maior_peso = 0;
    
    while (i < 1000000)
    {
        i++;
        printf("Forneça sua idade (digite 0 se deseja sair do programa):");
        scanf("%d", &idade);
    
        if (idade == 0)
        {
            break;
        }
        else
        {
            printf("Forneça sua altura:");
            scanf("%f", &altura);
            
            printf("Forneça sua peso:");
            scanf("%f", &peso);
            
            printf("\n");
        
            cont_pesquisa++;
            
            if (idade > 50)
            {
                cont_idade++;
            }
            
            if (peso > 80)
            {
                soma_h += altura;
            }
            
            if (altura > 1.65 && idade < 30)
            {
                if (peso > maior_peso)
                {
                    maior_peso = peso;
                }
            }
        }
    }
    media_h = soma_h / cont_pesquisa;
    
    printf("\n%d pessoas tem mais de 30 anos\n", cont_idade);
    printf("A media das alturas entre pessoas com mais de 80 kg é %.2f\n", media_h);
    
    if (maior_peso != 0)
    {
        printf("O maior peso dentre as pessoas acima de 1.65 m de altura e com idade inferior a 30 anos é de %f.", maior_peso);
    }
    else
    {
        printf("Não existem pessoas acima de 1.65 m de altura e com idade inferior a 30 anos ao mesmo tempo na pesquisa.");
    }

    return 0;
}
