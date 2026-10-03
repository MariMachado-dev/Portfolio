#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Data.h"
#include "unidade.h"

typedef struct produto tProduto;

tProduto* prod_cria(tUnidade** unidades, char* id, char* codBarras, float preco, int qtUnidade);

void prod_libera(tProduto* p);

void prod_exibe(tProduto* p);

char* prod_getProduto(tProduto* p);

char* prod_getId(tProduto* p);

char* prod_getCodBarras(tProduto* p);

float prod_getPreco(tProduto* p);

int prod_getQtUnidades(tProduto* p);

tUnidade** prod_getUnidades(tProduto* p);

void prod_setId(tProduto* p, char* id);

void prod_setCodBarras(tProduto* p, char* codBarras);

void prod_setPreco(tProduto* p, float preco);

void prod_setQtUnidades(tProduto* p, int qtUnidades);

int ehSemelhanteId(tProduto* p1, tProduto* p2);

int ehIgual(tProduto* p1, tProduto* p2);

void reajuste(tProduto* p, float preco, int reajuste);

