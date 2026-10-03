/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include "TADPonto.h"
#include "TADCirculo.h"
int main()
{
    Ponto*pt1;
    pt1=pto_cria(2,3);
    tCirculo *circ1;
    tCirculo *circ2;
    circ1=circ_cria(12,13,4);

    printf("ponto: %s",pto_getPonto(pt1));
    
    printf("\n\n%s", circ_getCirculo(circ1));
    
    return 0;
}
