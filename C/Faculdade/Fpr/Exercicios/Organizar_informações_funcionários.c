#include <stdio.h>

int main()
{
    int matricula, idade, salario, tempo, i, contador21 = 0, quantidadef = 0, 
    somas = 0, maior_tempo = 0, cont_m = 0, menor_tempo = 10000, matricula_maisnovo = 0, 
    matricula_maisvelho = 0;
	char genero;
	float medias = 0;
	
	for (i = 1; i <= 3; i++)
	{
		printf("\n%d entrevistado: \n", i);
		
		printf("\nInforme sua matricula:");
	    scanf("%d", &matricula);
	
	    printf("Informe seu gênero [M/F]: ");
        scanf(" %c", &genero);  // Espaço antes de %c para evitar problemas
    
        printf("Informe sua idade: ");
        scanf("%d", &idade);
	
   	printf("Informe seu salario:");    	     
   	scanf("%d", &salario);
	
   	printf("Informe seu tempo(em anos) de trabalho:");
   	scanf("%d", &tempo);
   	
   	if (idade - tempo < 21)
   	{
   		contador21++;
   	}
   	
   	if (genero == 'F')
   	{
   		quantidadef++;
   	}
   	
   	if (genero == 'M')
   	{
   	cont_m++;
   	somas += salario;
   	}
   	
   	if (tempo > maior_tempo)
   	{
   		matricula_maisvelho = matricula;
   		maior_tempo = tempo;
   	}
   	if (tempo < menor_tempo)
   	{
   		matricula_maisnovo = matricula;
   		menor_tempo = tempo;
   	}
	}
	
	printf("\nExistem %d entrevistados que foram contratados com menos de 21 anos.", contador21);
	
	printf("\nExistem %d entrevistados do genero femino", quantidadef);
	
	medias = (float)somas / cont_m;
	printf("\nA media salarial dos homens é %.2f", medias);
	
	printf("\nO funcionário %d é o mais velho na empresa.", matricula_maisvelho);
	
	printf("\nO funcionário %d é o mais novo na empresa.", matricula_maisnovo);
	
	

    return 0;
}
