#include "peso.h"
#include "altura.h"
#include "pessoa.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Tipo exportado */
struct pessoa {
    char nome[30];
    Altura* alt;
    Peso* pes;
};

TPessoa *pessoa_cria(const char* nome, Peso* pes, Altura *alt) {
    TPessoa *p = (TPessoa *)malloc(sizeof(TPessoa));
    if (p == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }

    strcpy(p->nome, nome);
    p -> alt = alt;
    p->pes = pes;
    return p;
}

void pessoa_libera(TPessoa *p) {
    free(p->alt);
    free(p->pes);
    free(p);
}

char *getNome(TPessoa *p) {
    return p->nome;
}

Peso* pessoa_getPeso(TPessoa* p) {
    return p->pes;
}

Altura* getAltura(TPessoa* p) {
    return p->alt;
}

void setNome(TPessoa *p, const char *nome) {
    strcpy(p->nome, nome);
}

void setAltura(TPessoa* p, Altura* alt) {
    p-> alt = alt;
}

void pessoa_setPeso(TPessoa* p, Peso* pes) {
    p-> pes = pes;
}

float pessoa_calculaIMC(TPessoa* p) {
    int kg, g;
    int m, cm;
    float peso, altura, imc;

    alt_acessa(p->alt, &m, &cm);
    altura = m+(cm/100.0);
    pes_acessa(p->pes, &kg, &g);
    peso = kg+(g/1000.0);
    imc = peso/(altura*altura);
    return imc;
}

char* pessoa_categorizaIMC(TPessoa *p) {
    float resposta = pessoa_calculaIMC(p);

    if (resposta < 18.5) {
        return "Abaixo do peso";
    }
    else if (resposta < 25) {
        return "peso normal";
    }
    else if (resposta < 30) {
        return "Sobrepeso";
    }
    else {
        return "Obesidade";
    }
}