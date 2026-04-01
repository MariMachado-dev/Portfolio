#include <stdio.h>

int main ()
{
    {
        int c, ano = 0;
        float c_porcent, m_inicial, m_dobro;
        
        printf("Qual é o crescimento constante da plantação?");
        scanf("%d", &c);
        
        printf("Quanto é a sua produção anual atualmente?");
        scanf("%f", &m_inicial);
        
        m_dobro = 2 * m_inicial;
        
        while (m_inicial < m_dobro)
        {
            ano++;
            c_porcent = 1 + (float)c / 100;
            m_inicial *= (float)c_porcent;
        }
        
        printf("A peodução ira dobrar em %d anos", ano);
        
        
    }

    return 0;
}
