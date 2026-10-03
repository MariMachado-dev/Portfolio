//Henrique Campbell Trechau
//Mariana da Conceição Albuquerque Machado

#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "entregador.h"
#include "pedido.h"

typedef struct entregas Entregas;
Entregas* entrega_criar(Entregador* entregas, Entregador** entregadores, Pedido** pedidos);
void entregas_liberar(Entregas* e);

void entregas_cadastrarEntregador(Entregas* e, Entregador* ent);
int entregas_novoPedido(Entregas* e, char* cliente, float valor, int hora, int minuto);
int entregas_buscarEntregadorLivre(Entregas* e);
int entregas_getProximoId(Entregas* e);
int entregas_atribuirPedido(Entregas* e, int idPedido, int horaSaida, int minutoSaida);
int entregas_finalizarPedido(Entregas* e, int idPedido, int horaEntrega, int
minutoEntrega);
char* entregas_listarPendentes(Entregas* e);
float entregas_faturamento(Entregas* e);
char* entregas_melhorEntregador(Entregas* e);

