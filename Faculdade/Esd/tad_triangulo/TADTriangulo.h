typedef struct triangulo tTriangulo;
#include "TADPonto.h"
/* Funções exportadas */

tTriangulo* tri_cria(int x1, int y1, int x2, int y2, int x3, int y3); 

/* Função libera - Libera a memória de um triangulo previamente criado */
void tri_libera(tTriangulo* t);

/* Função exibe -Escreve na tela o triangulo no formato */
void tri_exibe(tTriangulo* t);

/* Funções Set e Get - atribui/ acessa pontos */
Ponto* tri_getPontoA(tTriangulo* t);
Ponto* tri_getPontoB(tTriangulo* t);
Ponto* tri_getPontoC(tTriangulo* t);

/* Função getCirculo - Retorna uma string no formato*/
char* tri_getTriangulo(tTriangulo* t);

void tri_setPontoA(tTriangulo* t, int x1, int y1);
void tri_setPontoB(tTriangulo* t, int x2, int y2);
void tri_setPontoC(tTriangulo* t, int x3, int y3);

/* Função Area - Retorna o valor da área do triangulo */
float tri_area(tTriangulo * t); 
/* Função Comprimento - Retorna o valor do perimetro triangulo */
float tri_Perimetro(tTriangulo *t);

/* Função Compara - determina pelo perimetro dos triangulo */
int tri_compara(tTriangulo *t1, tTriangulo *t2); 

