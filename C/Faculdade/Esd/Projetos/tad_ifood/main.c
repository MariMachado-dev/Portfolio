//Henrique Campbell Trechau
//Mariana da Conceição Albuquerque Machado

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Entregas.h"
#include "entregador.h"
#include "pedido.h"
#include "horario.h"


int main(void)
{

    Entregador* vetorEntregadores[3];
    vetorEntregadores[0] = entregador_criar("Carlos Moto", "Moto");
    vetorEntregadores[1] = entregador_criar("Ana Bike", "Bike");
    vetorEntregadores[2] = entregador_criar("Pedro Carro", "Carro");
    
    Pedido* vetorPedidos[4];
    vetorPedidos[0] = pedido_criar(1, "João Silva", 32.50, 8,15);
    vetorPedidos[1] = pedido_criar(2, "Maria Santos", 45.90, 8,30);
    vetorPedidos[2] = pedido_criar(2, "Maria Santos", 45.90, 8,45);
    vetorPedidos[3] = pedido_criar(3, "Ana Costa", 67.30, 9,0);
    
    //Exibição de entregadores cadastrados e pedidos feitos
    
    printf("=== SISTEMA DE ENTREGAS RÁPIDO EXPRESS ===\n\n");
    printf("=== ENTREGADORES CADASTRADOS ===\n");
    
    
    char* exibicao;
    int i;
    
    for (i = 0; i < 3; i++)
    {
        exibicao = entregador_paraString(vetorEntregadores[i]);
        printf("%s\n", exibicao);
    }

    for (i = 0; i < 4; i++)
    {
        exibicao = pedido_paraString(vetorPedidos[i]);
        printf("%s\n", exibicao);
    }
    
    int hora = 9;
    int minuto = 30;
    
    printf("\n=== CONSULTA ===\n");
    printf("Horário atual para simulação (hora minuto): 9 30\n");
    
    // Declaração de variaveis usadas nas operações
    Horario *h = hor_criar(hora, minuto);
    char *exibicaoHorario = hor_paraString(h);
    char* nomeEntregador, nomeCliente, melhorEntregador;
    int id, status, disponivel;
    float valor;
    
    printf("\n=== INICIANDO OPERAÇÕES (referência: %s) ===\n", exibicaoHorario);
    
    //Funcao setEntregador pedido 1 Carlos com horario hora e  minuto
    //Funcao setEntregador pedido 2 Ana com hora e minuto
    
    Entregas* vetorEntregas[4];

    for (i = 0; i < 4; i++) {
    
        vetorEntregas[i] = entrega_criar(&vetorEntregas[i], *vetorEntregadores, *vetorPedidos);
        
        if (i < 2){
        entregas_atribuirPedido(vetorEntregas[i], id, hora, minuto);
        }
    }

   
        
    for (i = 0; i < 4; i++) {

        nomeEntregador = entregador_get(vetorEntregadores[i]);
        nomeCliente = pedido_getCliente(vetorPedidos[i]);
        id = pedido_getID(vetorPedidos[i]);
        status = pedido_getStatus(vetorPedidos[i]);
        disponivel = entregador_estaDisponivel(vetorEntregadores[i]);
        valor = pedido_getValor(vetorPedidos[i]);

        if (entregador_estaDisponivel(vetorEntregadores[i] && vetorEntregas[i]!= NULL)) {
            entregas_atribuirPedido(vetorEntregas[i], id, hora, minuto);
            printf("%s - Pedido %d atribuído a %s\n", exibicaoHorario, id, nomeEntregador);
        }

        
    }

    printf("\n=== PEDIDOS EM ROTA (%s) ===\n", exibicaoHorario);
            
    int pedidosFinalizados = 0;

    for (i = 0; i < 4; i++) {
        if (entregas_obterStatus(vetorEntregas[i]) == 1) {
            exibicao = pedido_paraString(vetorPedidos[i]);
            printf("%s\n", exibicao);
        }
    }
        
    for (int i = 0; i < 4; i++) { // Simulando passagem de tempo
        int tempoDecorrido = hor_diferencaMinutos(h, hor_criar(0, 30));
        hor_atualizar(h, hor_criar(0, 30));
        if (tempoDecorrido >= 25 && tempoDecorrido <= 105) { 
            entregas_finalizarPedido(vetorEntregas[0], id, 9, 55);
            nomeEntregador = entregador_get(vetorEntregadores[0]);
            printf("%s - Pedido %d finalizado por %s\n", exibicaoHorario, id, nomeEntregador);
            Horario* hfinal1 = hor_criar(9,55);
            pedidosFinalizados++;
            printf("\n");
        }
        if (tempoDecorrido >= 105 && tempoDecorrido < 175) { 
            entregas_finalizarPedido(vetorEntregas[1], id, hora, minuto); 
            nomeEntregador = entregador_get(vetorEntregadores[1]);
            printf("%s - Pedido %d finalizado por %s\n", exibicaoHorario, id, nomeEntregador);
            pedidosFinalizados++;
            printf("\n");

            vetorEntregas[2] = entrega_criar(&vetorEntregas[i], *vetorEntregadores, *vetorPedidos);
            int IDpedido = pedido_getID(vetorPedidos[2]);
            entregas_atribuirPedido(vetorEntregas[2], id, hora, minuto);
            nomeEntregador = entregador_get(vetorEntregadores[2]);
            printf("%s - Pedido %d atribuído a %s\n", exibicaoHorario, id, nomeEntregador);
            printf("\n");

        }
        if (tempoDecorrido >= 175) {
            entregas_finalizarPedido(vetorEntregas[2], id, hora, minuto);
            nomeEntregador = entregador_get(vetorEntregadores[2]);
            printf("%s - Pedido %d finalizado por %s\n", exibicaoHorario, id, nomeEntregador);
            pedidosFinalizados++; 
            printf("\n");  
        }
    }

    printf("\n=== RESUMO FINAL ===\n");
    printf("\nPedidos Realizados: %d\n", pedidosFinalizados);
    printf("Faturamento Total: %2.f\n", entregas_faturamento(vetorEntregas));
    
    printf("\n=== SITUAÇÃO DOS PEDIDOS ===\n");
    for (i = 0; i < 4; i++) {
        exibicao = pedido_paraString(vetorPedidos[i]);
        printf("%s\n", exibicao);
    }

    printf("\n=== ESTATÍSTICAS DOS ENTREGADORES ===\n");
    for (i = 0; i < 3; i++)
    {
        exibicao = entregador_paraString(vetorEntregadores[i]);
        printf("%s\n", exibicao);
    }

    printf("\n=== MELHOR ENTREGADOR DO DIA ===\n");
    melhorEntregador = entregas_melhorEntregador(vetorEntregadores); 

    hor_liberar(h);
    
    for(int i = 0;i<3;i++) {
        entregador_liberar(vetorEntregadores[i]);
    }

    for(int i = 0;i<3;i++) {
        entregador_liberar(vetorEntregadores[i]);
    }
    
    for(int i = 0;i<4;i++) {
        pedido_liberar(vetorPedidos[i]);
    }

    for(int i = 0;i<4;i++) {
        entrega_liberar(vetorEntregas[i]);
    }

    printf("\n=== SISTEMA FINALIZADO. MEMÓRIA LIBERADA ===");
        
}





