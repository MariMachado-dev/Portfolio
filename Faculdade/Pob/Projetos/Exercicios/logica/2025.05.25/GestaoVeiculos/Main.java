package GestaoVeiculos;

import GestaoVeiculos.Dominio.*;
import GestaoVeiculos.Gerenciar_Dados.GerenciadorFrota;
import GestaoVeiculos.Validacao.PlacaInvalidaException;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        GerenciadorFrota frota = new GerenciadorFrota();
        Veiculo v1 = null;

        try {
            v1 = new Carro(50000, 20000, "AB12");
            System.out.println("Custo Total do Carro: " + v1.calcularCustoTotal());
            System.out.println("IPVA do Carro: " + ((Tributavel) v1).calcularIPVA());
        } catch (PlacaInvalidaException e) {
            System.out.println(e.getMessage());
        }

        if (v1 != null) {
            frota.adicionarVeiculo(v1);
        }

        try {
            frota.adicionarVeiculo(new Caminhao(10, 50000, "CD1-234"));
            frota.adicionarVeiculo(new Carro(30000, 15000, "EFD-156"));
        } catch (PlacaInvalidaException e) {
            System.out.println(e.getMessage());
        }

        try {
            frota.salvarDadosEmArquivo("frota.txt");
            frota.lerDadosDoArquivo("frota.txt");
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
