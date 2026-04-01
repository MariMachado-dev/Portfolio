#include "Data.h"
#include "unidade.h"
#include "produto.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    int validade = 30, dias, n=2, qtd;
    int dia,mes,ano;
    float precoProduto, reajustePreco;
    char* nomeProduto;

    tUnidade* u1 = unid_cria(dta_cria(10, 3, 2020), 1);
    tUnidade* u2 = unid_cria(dta_cria(15, 4, 2021), 2);

    tUnidade* lista1[2];
    lista1[0] = u1;
    lista1[1] = u2;
    tProduto* p1 = prod_cria(lista1, "Arroz", "123456", 10.0, 2);
    tProduto* p3 = prod_cria(lista1, "Arroz", "123456", 10.0, 2);

    tUnidade* u3 = unid_cria(dta_cria(1, 1, 2022), 3);
    tUnidade* lista2[1];
    lista2[0] = u3;
    tProduto* p2 = prod_cria(lista2, "Feijao", "999999", 20.0, 1);
    tProduto* produtos[3];
    produtos[0] = p1;
    produtos[1] = p2;
    produtos[2] = p3;

    printf("Deseja comparar os produtos com qual data? (dd mm aaaa): ");
    scanf("%d %d %d", &dia, &mes, &ano);
    tData* dtaAlvo = dta_cria(dia, mes, ano);

    for(int i = 0; i<n;i++) {
        qtd = prod_getQtUnidades(produtos[i]);
        tUnidade** unidades = prod_getUnidades(produtos[i]);
        nomeProduto = prod_getId(produtos[i]);
        precoProduto = prod_getPreco(produtos[i]);

        for (int j = 0; j < qtd; j++) {
            tData* dataFabricacao = unid_getData(unidades[j]);
            tData* vencimento = dta_intervalo(dataFabricacao, validade);
            dias = dta_diferenca(dtaAlvo, vencimento);
            
            if (dias == 0) {
                printf("Produto %s - unidade %d vence na data alvo.\n", nomeProduto, j);
            }

            else if (dias > 0 && dias < 4) {
                printf("Coloque um reajuste no produto ja que vence em 3 dias:");
                scanf("%f", &reajustePreco);
                reajuste(produtos[i], precoProduto, reajustePreco);
                printf("Novo preço com reajuste:%.2f\n", prod_getPreco(produtos[i]));
            }
            
            else {
                printf("O produto nao vence na data alvo e nem recebe reajuste.\n");
            }
        }
    }

}

