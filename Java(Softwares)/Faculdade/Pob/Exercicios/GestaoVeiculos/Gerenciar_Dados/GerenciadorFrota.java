package GestaoVeiculos.Gerenciar_Dados;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import GestaoVeiculos.Dominio.Carro;
import GestaoVeiculos.Dominio.Caminhao;
import GestaoVeiculos.Dominio.Veiculo;

public class GerenciadorFrota {
    private List<Veiculo> frota = new ArrayList<>();

    public void adicionarVeiculo(Veiculo v) { 
        frota.add(v);
    }

    public void salvarDadosEmArquivo(String nomeArquivo) throws IOException {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(nomeArquivo))) {
            for (Veiculo v : frota) {
                String tipoVeiculo;
                double custoTotal = v.calcularCustoTotal();

                if (v instanceof Carro) {
                    tipoVeiculo = "Carro";
                } else if (v instanceof Caminhao) {
                    tipoVeiculo = "Caminhão";
                } else {
                    tipoVeiculo = "Veículo";
                }

                writer.write(tipoVeiculo + "," + v.getPlaca() + "," + custoTotal);
                writer.newLine();
            }
        }
    }

    // Ler e processar dados do arquivo em tela utilizando BufferedReader
    public void lerDadosDoArquivo(String nomeArquivo) throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(nomeArquivo))) {
            String linha;
            while ((linha = reader.readLine()) != null) {
                String[] partes = linha.split(",");
                String tipoVeiculo = partes[0];
                String placa = partes[1];
                double custoTotal = Double.parseDouble(partes[2]);
                System.out.println("Tipo: " + tipoVeiculo + " | Placa: " + placa + " | Custo Total: R$ " + custoTotal);
            }
        }
    }
}