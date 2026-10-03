//Henrique Campbell Trechau
//Mariana da Conceição Albuquerque Machado
#include "pedido.h"
#include "entregador.h"
#include "Entregas.h"
#include "Horario.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct entregas {
    Entregador** entregadores; // vetor dinâmico
    int qtdEntregadores;
    int capEntregadores;
    Pedido** pedidos; // vetor dinâmico
    int qtdPedidos;
    int capPedidos;
    int proximoID; // próximo ID disponível (começa em 1)
};

Entregas* entrega_criar(Entregador* entregas, Entregador** entregadores, Pedido** pedidos) {
    
    Entregas* e = (Entregas*)malloc(sizeof(struct entregas));
    e->qtdEntregadores = 0;
    e->proximoID = 1;
    int capEntregadores = 3;
    int capPedidos = 5;
    
    e->entregadores = malloc(capEntregadores * sizeof(Entregador*));

    for (int i = 0; i < capEntregadores; i++) {
        e->entregadores[i] = entregadores[i];
        exit(1);
    }
    
    e->pedidos = malloc(capPedidos * sizeof(Pedido*));

    for (int i = 0; i < capPedidos; i++) {
        e->pedidos[i] = pedidos[i];
        exit(1);
    }

    return e;
}

void entregas_liberar(Entregas* e) {
    for (int i = 0; i < e->qtdEntregadores; i++) {
        unid_libera(e->entregadores[i]);
    }
    free(e->entregadores);

    for (int i = 0; i < e->qtdPedidos; i++) {
        unid_libera(e->pedidos[i]);
    }
    free(e->pedidos);

    free(e); 
}

int entregas_getProximoId(Entregas* e) {
    return e->proximoID;
}

int entregas_buscarEntregadorLivre(Entregas* e)
{
    int disponivel;
    disponivel = entregador_estaDisponivel(e->entregadores);

    for (int i = 0; i < e->qtdEntregadores; i++)
    {
        if (disponivel == 1)
        {
            return i;
        }
    }

    return -1;
}

void entregas_cadastrarEntregador(Entregas* e, Entregador* entregadores)
{
    int NovaQuant;

    if (e->qtdEntregadores > 5) {
        e->capPedidos = realloc(e->capPedidos, 10 * sizeof(int));
    }

    NovaQuant = e->qtdEntregadores+1;
    entregadores[NovaQuant] = entregador_criar("Novo Entregador", "veiculo");
}

int entregas_novoPedido(Entregas* e, char* cliente, float valor, int hora, int minuto) {
    int novoId;
    novoId = entregas_getProximoId(e);

    pedido[e->proximoId] = pedido_criar(novoId, cliente, valor, hora, minuto);
    novoId++;
    return novoId;
}


int entregas_atribuirPedido(Entregas* e, int idPedido, int horaSaida, int minutoSaida) {
    int status; 
    int idPedidoVet;
    for (int i = 0; i< e->qtdPedidos;i++) {
        status = pedido_getStatus(e->pedidos[i]);
        idPedidoVet = pedido_getId(e->pedidos[i]);
        
        if (idPedidoVet == idPedido) {
            if (status == 1) {
                pedido_atribuir(e->pedidos[i]);
                entregador_setDisponivel(e, 0);
                return 1;
            }
        }
    }
}

int entregas_finalizarPedido(Entregas* e, int idPedido, int horaEntrega, int
minutoEntrega) {
    int status; 
    int idPedidoVet;
    for (int i = 0; i< e->qtdPedidos;i++) {
        status = pedido_getStatus(e->pedidos[i]);
        idPedidoVet = pedido_getId(e->pedidos[i]);
        
        if (idPedidoVet == idPedido) {
            if (status == 1) {
                pedido_entregar(e->pedidos[i]);
                entregador_setDisponivel(e, 1);
                return 1;
            }
        }
    }
    return 0;
}

char* entregas_listarPendentes(Entregas* e) {
    int status; 
    int idPedido;
    char* str = (char*) malloc(500 * sizeof(char));
    
    for (int i = 0; i< e->qtdPedidos;i++) {
        status = pedido_getStatus(e->pedidos[i]);
        idPedido = pedido_getId(e->pedidos[i]);
        
        if (status == 0 || status = 1) {
            sprintf(str, "Pedido:#%d pendente",
                   idPedido);
        }
    }
    free(str);
}

float entregas_faturamento(Entregas* e) {
    int statusAtual;
    float faturamentoTotal = 0, valorAtual;

    for (int i = 0;i<e->qtdPedidos;i++) {
        statusAtual = pedido_getStatus(e->pedidos[i]);
        if (statusAtual == 2) {
            valorAtual = pedido_getValor(e->pedidos);
            faturamentoTotal += valorAtual;
        }
    }
    return faturamentoTotal;
}

char* entregas_melhorEntregador(Entregas* e) {
    int maioQntEntregas = 0;
    char* melhorEntregador;
    int qtdEntrega;
    
    for (int i = 0;i < e->qtdEntregadores;i++) {
        qtdEntrega = entregador_getEntregas(e->entregadores[i]);
        if (qtdEntrega > maioQntEntregas) {
            maioQntEntregas = qtdEntrega;
            melhorEntregador = entregador_getNome(e->entregadores[i]);
        }
    }
    return melhorEntregador;
}


