#include <stdlib.h>
#include <stdio.h>
#include "TADTriangulo.h"


struct triangulo {
 Ponto *pontoA;
 Ponto *pontoB;
 Ponto *pontoC;
} ;


tTriangulo* tri_cria(int x1, int y1, int x2, int y2, int x3, int y3) {
    tTriangulo * t=(tTriangulo*)malloc(sizeof(tTriangulo));
    t->pontoA=pto_cria(x1,y1);
    t->pontoB=pto_cria(x2,y2);
    t->pontoC=pto_cria(x3,y3);
    return t;
}

void tri_libera(tTriangulo* t) {

    pto_libera(t->pontoA);
    pto_libera(t->pontoB); 
    pto_libera(t->pontoC);  
    free(t);
}

void tri_exibe(tTriangulo* t) {
    printf("A: ");
    pto_exibe(t->pontoA);

    printf("B: ");
    pto_exibe(t->pontoB);

    printf("C: ");
    pto_exibe(t->pontoC);
}

Ponto* tri_getPontoA(tTriangulo* t) {
    return t->pontoA;
}

Ponto* tri_getPontoB(tTriangulo* t) {
    return t->pontoB;
}

Ponto* tri_getPontoC(tTriangulo* t) {
    return t->pontoC;
}

char* tri_getTriangulo(tTriangulo* t) {
    char* a = pto_getPonto(t->pontoA);
    char* b = pto_getPonto(t->pontoB);
    char* c = pto_getPonto(t->pontoC);

    char* tri = malloc(200);

    sprintf(tri, "(A:%s, B:%s, C:%s)", a, b, c);

    return tri;
}

void tri_setPontoA(tTriangulo* t, int x1, int y1) {
    pto_atribui(t->pontoA, x1, y1); 
}

void tri_setPontoB(tTriangulo* t, int x2, int y2) {
    pto_atribui(t->pontoB, x2, y2); 
}

void tri_setPontoC(tTriangulo* t, int x3, int y3) {
    pto_atribui(t->pontoC, x3, y3); 
}

float tri_area(tTriangulo * t){
    float x1, y1;
    float x2, y2;
    float x3, y3;

    pto_acessa(t->pontoA, &x1, &y1);
    pto_acessa(t->pontoB, &x2, &y2);
    pto_acessa(t->pontoC, &x3, &y3);
    return x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
}

float tri_perimetro(tTriangulo *t) {
    return pto_distancia(t->pontoA, t->pontoB)+pto_distancia(t->pontoB, t->pontoC)+pto_distancia(t->pontoC, t->pontoA);
}

int tri_compara(tTriangulo *t1, tTriangulo *t2) {
    float p1 = tri_perimetro(t1);
    float p2 = tri_perimetro(t2);

    if (p1 > p2) {
        printf("Primeiro triangulo maior\n");
        return 1;
    }
    else if (p1 == p2) {
        printf("Triangulos iguais\n");
        return 0;
    }
    else {
        printf("Segundo triangulo maior\n");
        return -1;
    }
}