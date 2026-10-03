#include "peso.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Tipo exportado */
/* cria uma medida de comprimento como em kg e g*/
struct pes {
  int kg, g;
};
/* funções auxiliares */
int converteParag(Peso *p) { return p->kg * 1000 + p->g; }

Peso *peso_cria(int kg, int g) {
  Peso *p = (Peso *)malloc(sizeof(Peso));
  if (p == NULL) {
    printf("Memória insuficiente!\n");
    exit(1);
  }

  p->kg = kg;
  p->g = g;
  return p;
}
/* Função libera - Libera a memória de um peso previamente criado */
void pes_libera(Peso *p) { free(p); }

/* Função acessa - Retorna os valores de um peso */
void pes_acessa(Peso *p, int *kg, int *g) {
  *kg = p->kg;
  *g = p->g;
}
/* Função atribui - Atribui novos valores às partes de um peso */
void setPeso(Peso *p, int kg, int g) {
  p->kg = kg;
  p->g = g;
}
/* Função exibe -Escreve na tela o peso no formato  kg,g */

void pes_exibe(Peso* p) { printf("\n %d,%02dkg", p->kg, p->g); }

char *getPeso(Peso *p) {
  char *pt = malloc(20);
  sprintf(pt, "%d,%02dg", p->kg, p->g);
  return pt;
}

void alteraPeso(Peso *p, int g) {
    int total_g = converteParag(p) + g;
    int quilosAlterados = total_g / 1000;
    int gramasAlteradas = total_g % 1000;
    setPeso(p, quilosAlterados, gramasAlteradas);
}


int pes_compara(Peso *p1, Peso *p2) {
  int peso1 = converteParag(p1);
  int peso2 = converteParag(p2);
  int dif = peso1 - peso2;
  return dif;
}


Peso *pes_soma(Peso *p, int g) {
  int total_g = converteParag(p) + g;
  int novos_quilos = total_g / 1000;
  int novas_gramas = total_g % 1000;
  return peso_cria(novos_quilos, novas_gramas);
}

Peso *pes_copia(Peso *p) {
  if (p == NULL) {
    return NULL;
  }
  return peso_cria(p->kg, p->g);
}