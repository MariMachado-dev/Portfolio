#include <stdio.h>
#define ALUNOS 30

int main()
{
    int cont_reprovados = 0, cont_aprovados = 0, cont_avf = 0, cont_melhora = 0;
    int i, matricula, menor_media = 10, pior_matricula;
    float media, av1, av2, avf, porcent_melhora;
    
    for (i = 1;i <= ALUNOS; i++)
    {
        printf("Forneça a %d matricula:", i);
        scanf("%d", &matricula);
        
        printf("Forneça a nota da av1:");
        scanf("%f", &av1);
        
        printf("Forneça a nota da av2:");
        scanf("%f", &av2);
        
        //calcular media
        media = (av1 + av2) / 2;
        
        //Alunos que melhoraram a nota da av1 a av2
        if (av2 > av1)
        {    
            cont_melhora++;
        }
        
        //Fazer afv
        if (media < 6 && media >= 4)
        {
            if (media <= menor_media)
            {
                menor_media = media;
                pior_matricula = matricula;
            }
            
            cont_avf++;
            printf("Forneça a nota da avf:");
            scanf("%f", &avf);
            media = avf;
        }
        
        
        if (media >= 6)
        {    
            cont_reprovados++;
        }
        
        else
        {    
            cont_aprovados++;
        }
        
        printf("\n");
    }
    porcent_melhora = ((float)cont_melhora / ALUNOS) * 100;
    
    printf("Houveram %d alunos reprovados.\n", cont_reprovados);
    printf("Houveram %d alunos aprovados.\n", cont_aprovados);
    printf("Houveram %d alunos que ficaram em afv.\n", cont_avf);
    printf("%.1f%% dos alunos apresentaram uma aumento de desempenho da av1 a av2.\n", porcent_melhora);
    printf("O aluno com a matricula %d precisa tirar a maior nota na afv para ser aprovado.\n", pior_matricula);
    
    return 0;
}
