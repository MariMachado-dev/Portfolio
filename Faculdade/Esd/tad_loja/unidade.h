#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Data.h"

typedef struct unidade tUnidade;

tUnidade* unid_cria(tData *dta, int lote);

void unid_libera(tUnidade* p);

void unid_exibe(tUnidade* p);

char* unid_getUnidade(tUnidade* p);

char* unid_getLote(tUnidade* p);

tData* unid_getData(tUnidade* u);

void unid_setData(tUnidade* p, tData *dta);

void unid_setLote(tUnidade* p, int lote);

int tempoIdade(tUnidade* p, tData* dtaAlvo);

int ehMenor(tUnidade* p1, tUnidade* p2);