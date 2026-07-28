package GestaoVeiculosComplexo.Repository;

import GestaoVeiculosComplexo.Model.*;
import java.io.*;
import java.util.ArrayList;

public class VeiculoRespository {
    private ArrayList<Veiculo> frota;

    public VeiculoRespository() {
        this.frota = new ArrayList<>();
    }

    public void adicionarVeiculo(Veiculo v) {
        frota.add(v);
    }

    public void removerVeiculo(Veiculo v) {
        frota.remove(v);
    }

    public ArrayList<Veiculo> getVeiculos() {
        return frota;
    }

    public void salvarDadosEmArquivo(String nomeArquivo) throws IOException {
        try (BufferedWriter writer =
                     new BufferedWriter(new FileWriter(nomeArquivo))) {

            for (Veiculo v : frota) {

                String tipo;
                double custoTotal = v.calcularCustoTotal();

                if (v instanceof Carro) {
                    tipo = "Carro";
                } else if (v instanceof Caminhao) {
                    tipo = "Caminhao";
                } else {
                    tipo = "Veiculo";
                }

                writer.write(
                        tipo + "," +
                        v.getPlaca() + "," +
                        v.getCustoFixo() + "," +
                        custoTotal
                );

                writer.newLine();
            }
        }
    }

    public ArrayList<String> lerDadosDoArquivo(String nomeArquivo) throws IOException {
        ArrayList<String> dados = new ArrayList<>();
              try (BufferedReader reader =
                     new BufferedReader(new FileReader(nomeArquivo))) {

            String linha;

            while ((linha = reader.readLine()) != null) {
                dados.add(linha);
            }
        }

        return dados;
    }
}
