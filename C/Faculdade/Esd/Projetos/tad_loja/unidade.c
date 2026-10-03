#include "unidade.h"
#include "Data.h"

struct unidade {
    int lote;
    tData* dta;
};

// funcoes do TAD Data

tUnidade* unid_cria(tData *dta, int lote) {
    tUnidade* p = (tUnidade*)malloc(sizeof(struct unidade));

    if (p != NULL) {
        if (dta == NULL) {
            p->dta = dta_cria(14, 3, 2025);
        } 
        
        else {
            p->dta = dta;
        }

        p->lote = lote;
    }

    return p;
}

void unid_libera(tUnidade* p) {
    dta_libera(p->dta);
    free(p);
}

void unid_exibe(tUnidade* p) {
    char* dataStr = dta_getData(p->dta);
    printf("lote:%d, data:%s\n", p->lote, dataStr);

    free(dataStr);
}

char* unid_getUnidade(tUnidade* p) {
    char* dataStr = dta_getData(p->dta);
    char* unidade = (char*) malloc(50 * sizeof(char));

    sprintf(unidade, "Data:%s, lote:%d", dataStr, p->lote);
    free(dataStr); 

    return unidade;
}

char* unid_getLote(tUnidade* p) {
    char *slote = malloc(20);
    sprintf(slote, "%d", p->lote);
    return slote;
}

tData* unid_getData(tUnidade* u) {
    return u->dta;
}

void unid_setData(tUnidade* p, tData *dta) {
    p->dta = dta;
}

void unid_setLote(tUnidade* p, int lote) {
    p->lote = lote;
}


int tempoIdade(tUnidade* p, tData* dtaAlvo) {
    int idade;
    idade = abs(dta_diferenca(p->dta, dtaAlvo)); 
    return idade;
}

int ehMenor(tUnidade* p1, tUnidade* p2) {
    int idade;
    idade = (dta_diferenca(p1->dta, p2->dta)); 

    if (idade > 0) {
        //dta 1 é maior q dta 2
        return 0;
    }

    else if (idade<0) {
        //contrario
        return 1;
    }

    else {
        if (p1->lote > p2->lote) {
            return 0;
        }

         else if (p1->lote < p2->lote) {
            return 1;
        }
        else {
            return -1; //Sao iguais(pra usar na funcao em produto.c)
        }
    }
}