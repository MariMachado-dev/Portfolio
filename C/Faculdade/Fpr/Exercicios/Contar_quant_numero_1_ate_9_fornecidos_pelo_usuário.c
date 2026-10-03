#include <stdio.h>

int main()
{
    int i = 1, valor, cont_1 = 0, cont_2 = 0, cont_3 = 0, cont_4 = 0;
    int cont_5 = 0, cont_6 = 0, cont_7 = 0, cont_8 = 0, cont_9 = 0;
	
	do 
	{
		printf("Forneça o %d valor (0 para sair):", i);
		scanf("%d", &valor);
        i++;
        
        if (valor == 1)
        {
            cont_1++;
        }    
        
        if (valor == 2)
        {
            cont_2++;
        }    
        
        if (valor == 3)
        {
            cont_3++;
        }  
        
        if (valor == 4)
        {
            cont_4++;
        }   
        
        if (valor == 5)
        {
            cont_5++;
        }   
        
        if (valor == 6)
        {
            cont_6++;
        }   
        
        if (valor == 7)
        {
            cont_7++;
        }   
        
        if (valor == 8)
        {
            cont_8++;
        }   
        
        if (valor == 9)
        {
            cont_9++;
        }   
        
	} while (valor != 0);
    
    printf("\n1 - %d vez(es)\n2 - %d vez(es)\n3 - %d vez(es)\n4 - %d vez(es)\n5 - %d vez(es)\n6 - %d vez(es)\n7 - %d vez(es)\n8 - %d vez(es)\n9 - %d vez(es)\n", cont_1, cont_2, cont_3, cont_4, cont_5, cont_6, cont_7, cont_8, cont_9);
    
    return 0;
}
