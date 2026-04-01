#include <stdio.h>
#include <ctype.h>

#define NUM_ENTREVISTADOS 50

int main()
{
    //Definir variaveis
    int i;
    float altura, maior_altura = 0, menor_altura = 100, media_alturaF = 0, media_alturaP = 0;
    float contadorH = 0, contadorF = 0, PorcentagemH;
    char genero;
    
    //Fazer pesquisa NUM_ENTREVISTADOS vezes
    for (i = 1; i <= NUM_ENTREVISTADOS; i++)
    {
        printf("Entrevistado %d\n\n", i);
        
        printf("Qual a sua altura?" );
        scanf("%f", &altura);
        
        printf("Qual o seu gênero, [M] ou [F]?" );
        scanf(" %c", &genero);
        genero = toupper(genero);
        
        //Melhora formatação
        if (i == 1)
        {
            printf("\n");
        }
        
        //Checa menor e maior altura entre intrevistados
        if (altura > maior_altura)
        {
            maior_altura = altura;
        }
        if (altura < menor_altura)
        {
            menor_altura = altura;
        }
        
        //Faz média da altura das mulheres e conta número de homens
        if (genero == 'F')
        {
            contadorF++;
            media_alturaF += altura;
        }
        else if (genero == 'M')
        {
            contadorH++;
        }
        
        //media altura geral
        media_alturaP += altura;
        
        //Melhora formatação
        if (i == NUM_ENTREVISTADOS)
        {
            printf("\n");
        }
        
    }
    //Calcular porcentagem de homens da população
    PorcentagemH = (float)contadorH / NUM_ENTREVISTADOS;
    PorcentagemH = PorcentagemH * 100;
    
    //Calcular as 2 médias necessárias
    media_alturaP = (float)media_alturaP / NUM_ENTREVISTADOS;
    media_alturaF = media_alturaF / contadorF;
    
    //Exibir todas essas informações
    printf("%.2f é a maior altura e %.2f é a menor altura encontrada.\n", maior_altura, menor_altura);
    printf("%.2f é a média das alturas das mulheres.\n", media_alturaF);
    printf("%.2f é a média das alturas da população.\n", media_alturaP);
    printf("%.1f%% é a porcentagem de homens na população.\n", PorcentagemH);
    

    return 0;
}
