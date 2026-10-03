#include "produto.h"
#include "unidade.h"
#include "Data.h"

struct produto {
    char id[20];
    char codBarras[40];
    float preco;
    int qtUnidades;
    tUnidade** unidades;
};

tProduto* prod_cria(tUnidade** unidades, char* id, char* codBarras, float preco, int qtUnidades) {
    tProduto* p = (tProduto*) malloc(sizeof(struct produto));

    strcpy(p->id, "Produto");
    strcpy(p->codBarras, "");
    p->preco = 0.0;
    p->qtUnidades = qtUnidades;

    if (id != NULL) {
        strcpy(p->id, id);
    }

    if (codBarras != NULL) {
        strcpy(p->codBarras, codBarras);
    }

    if (preco > 0) {
        p->preco = preco;
    }


    p->unidades = malloc(qtUnidades * sizeof(tUnidade*));

    for (int i = 0; i < qtUnidades; i++) {
        p->unidades[i] = unidades[i];
    }

    return p;
}

void prod_libera(tProduto* p) {
    for (int i = 0; i < p->qtUnidades; i++) {
        unid_libera(p->unidades[i]);
    }

    free(p->unidades);
    free(p);
}

void prod_exibe(tProduto* p) {
    printf("Id do produto: %s\n"
           "Codigo de barras do produto: %s\n"
           "Preco do produto: %.2f\n"
           "Quantidade de Unidades do produto: %d\n",
           p->id, p->codBarras, p->preco, p->qtUnidades);
        
    for (int i = 0; i < p->qtUnidades; i++) {
        printf("%d unidade:",i+1);
        unid_exibe(p->unidades[i]);
    } 
}

char* prod_getProduto(tProduto* p) {
    int pos = 0;
    char* str = (char*) malloc(500 * sizeof(char));
    
    pos += sprintf(str + pos, "Id:%s, Cod:%s, Preco:%.2f, Qt:%d\n",
                   p->id, p->codBarras, p->preco, p->qtUnidades);

    for (int i = 0; i < p->qtUnidades; i++) {
        char* unidStr = unid_getUnidade(p->unidades[i]);
        pos += sprintf(str + pos, "%s\n", unidStr);

        free(unidStr);
    }

    return str;
}

char* prod_getId(tProduto* p) {
    return p->id;
}

char* prod_getCodBarras(tProduto* p) {
    return p->codBarras;
}

float prod_getPreco(tProduto* p) {
    return p->preco;
}

int prod_getQtUnidades(tProduto* p) {
    return p->qtUnidades;
}  

void prod_setId(tProduto* p, char* id) {
    strcpy(p->id,id);
}

void prod_setCodBarras(tProduto* p, char* codBarras) {
    strcpy(p->codBarras,codBarras);
}

void prod_setPreco(tProduto* p, float preco) {
    p->preco=preco;
}

void prod_setQtUnidades(tProduto* p, int qtUnidades) {
    p->qtUnidades=qtUnidades;
}

tUnidade** prod_getUnidades(tProduto* p) {
    return p->unidades;
}

int ehSemelhanteId(tProduto* p1, tProduto* p2) {
    if (strcmp(p1->id, p2->id) == 0) {
        return 1;
    }
    return 0;
}

int ehIgual(tProduto* p1, tProduto* p2) {
     if (strcmp(p1->id, p2->id) != 0 || 
        strcmp(p1->codBarras, p2->codBarras) != 0 ||
        p1->preco != p2->preco || 
        p1->qtUnidades != p2->qtUnidades) 
    {
        return 0;
    }

    for (int i = 0; i < p1->qtUnidades; i++) {
        if (ehMenor(p1->unidades[i], p2->unidades[i]) != -1) {
            return 0;
        }
    }

    return 1;
}


void reajuste(tProduto* p, float preco, int reajuste) {
    float novoPreco;
    novoPreco = preco*(1+(reajuste/100.0));
    prod_setPreco(p, novoPreco);
}
