#include <stdio.h>

int main()
{
    //Declarar variáveis
    int i, n, valor, peso, produto_ponderado, soma_ponderada = 0, soma_pesos = 0;
    float media_ponderada;
    
    //Fornecer limite de valores
    printf("Quantidade de valores a serem inseridos: ");
    scanf("%d", &n);
    
    //Formatção
    printf("\n");
    
    //Receber valores e seus pesos 1 por 1
    for (i = 1; i <= n; i++)
    {
        printf("Valor %d: ", i);
        scanf("%d", &valor);
        
        printf("Peso do valor %d: ", i);
        scanf("%d", &peso);
        
        //Calcular a soma produto ponderado e dos pesos
        produto_ponderado = valor * peso;
        soma_ponderada += produto_ponderado;
        soma_pesos += peso;
        
        //Formatção
        printf("\n");
    }
    
    //Calcular media ponderada e exibi-la
    media_ponderada = (float)soma_ponderada / soma_pesos;
    printf("A media ponderada dos valores fornecidos é %.1f", media_ponderada);

    return 0;
}
