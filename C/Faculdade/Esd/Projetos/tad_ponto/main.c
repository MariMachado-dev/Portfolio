#include <stdio.h>
#include "PontoM.h"

int main()
{
    Ponto * pt1;
    pt1=pto_cria(3,2);
    pto_exibe(pt1);
    char * s = pto_getPonto(pt1);
    printf("vc criou este ponto----> %s", s);

    return 0;
}
