#include "peso.h"
#include "altura.h"
#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    TPessoa* pessoas[4];

    pessoas[0] = pessoa_cria("Ana", peso_cria(60,0), alt_cria(1,70));
    pessoas[1] = pessoa_cria("Marcos", peso_cria(85,0), alt_cria(1,65));
    pessoas[2] = pessoa_cria("Giovana", peso_cria(100,0), alt_cria(1,80));
    pessoas[3] = pessoa_cria("Bob", peso_cria(50,0), alt_cria(1,55));

    for (int i = 0; i < 4; i++) {
        char* nome = getNome(pessoas[i]);
        char* imc_cat = pessoa_categorizaIMC(pessoas[i]);

        if (strcmp(imc_cat, "Abaixo do peso") == 0 || strcmp(imc_cat, "Obesidade") == 0) {
            printf("%s não está apta(o) para o emprego.\n", nome);
        } else {
            printf("%s está apta(o) para o emprego.\n", nome);
        }
    }

    return 0;
}