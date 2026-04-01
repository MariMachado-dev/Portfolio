#include <stdio.h>
#define NUM_HABITANTES 300

int main()
{
    //Definir váriaveis
    int i, num_filhos, soma_filhos = 0;
    int salario, soma_salario = 0, maior_salario = 0, cont_salario_ate_1000 = 0;
	float media_salario, media_filhos, dec_salario1000, porcent_salario1000;
	
	//Fazer pesquisa
	for (i = 1; i <= NUM_HABITANTES; i++)
	{
		printf("%d habitante\n\n", i);
		
		printf("Qual é o seu salario? ");
		scanf("%d", &salario);
		
		soma_salario += salario;
		
		//Checar maior salário
		if (maior_salario < salario)
		{
		    maior_salario = salario;
		}
		
		//Checar se salario é maior que 1000
		if (salario <= 1000)
		{
		    cont_salario_ate_1000++;
		}
		
		printf("Quantos filhos voce tem? ");
		scanf("%d", &num_filhos);
		
		soma_filhos += num_filhos;
		
		printf("\n");
	}
    
    //Calcular média salarial, de filhos e porecent de pessoas com salario até R$1000
    media_salario = (float)soma_salario / NUM_HABITANTES;
    media_filhos = (float)soma_filhos / NUM_HABITANTES;
    dec_salario1000 = (float)cont_salario_ate_1000 / NUM_HABITANTES;
    porcent_salario1000 = dec_salario1000 * 100;
    
    //Exibir média salarial, de filhos e porecent de pessoas com salario até R$1000
    printf("A media dos salarios dos habitantes é %.2f\n", media_salario);
    printf("A media de filhos dos habitantes é %.1f\n", media_filhos);
    printf("O maior salario entre os habitantes é %d\n", maior_salario);
    printf("A porcentagem de habitantes com salario até 1000 reais é de %.1f%%", porcent_salario1000);
    
    
    return 0;
}
