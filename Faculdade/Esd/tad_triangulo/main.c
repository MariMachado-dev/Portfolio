#include <stdio.h>
#include <stdlib.h>
#include "TADTriangulo.h"

int main() {
    tTriangulo *t1 = tri_cria(0, 0, 3, 0, 0, 4);
    tTriangulo *t2 = tri_cria(0, 0, 5, 0, 0, 5);

    printf("Perimetro T1: %.2f\n", tri_perimetro(t1));
    printf("Perimetro T2: %.2f\n", tri_perimetro(t2));

    tri_compara(t1, t2);

    tri_libera(t1);
    tri_libera(t2);

    return 0;
}