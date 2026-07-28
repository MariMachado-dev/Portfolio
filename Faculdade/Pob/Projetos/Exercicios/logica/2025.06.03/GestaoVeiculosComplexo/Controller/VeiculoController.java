package GestaoVeiculosComplexo.Controller;

import GestaoVeiculosComplexo.Model.*;
import GestaoVeiculosComplexo.Repository.VeiculoRespository;
import java.io.IOException;
import java.util.ArrayList;

public class VeiculoController {
    private VeiculoRespository respository ;

    public VeiculoController(VeiculoRespository respository) {
        this.respository = respository;
    }

    public void adicionarVeiculo(String tipo, String placa, double custoFixo, double valorExtra) throws Exception {
        Veiculo veiculo;

        switch (tipo.toLowerCase()) {
            case "carro":
                veiculo = new Carro((int) valorExtra, custoFixo, placa);
                break;
            case "caminhao":
                veiculo = new Caminhao(valorExtra, custoFixo, placa);
                break;
            default:
                throw new IllegalArgumentException("Tipo de veículo inválido: " + tipo);
        }

        respository.adicionarVeiculo(veiculo);
    }

    //Controller procura o veículo na lista por placa e, se encontrado, chama o método de
    //  remoção do repositório q so faz remove pq ja sabe quem é q vai ser removido
    public void removerVeiculo(String placa) {
        ArrayList<Veiculo> veiculos = respository.getVeiculos();
        Veiculo veiculoParaRemover = null; 
        
        for (Veiculo v : veiculos) {
            if (v.getPlaca().equalsIgnoreCase(placa)) {
                veiculoParaRemover = v;
                break;
            }
        }

        if (veiculoParaRemover != null) {
            respository.removerVeiculo(veiculoParaRemover);
            System.out.println("Veículo removido com sucesso!");
        } else {
            System.out.println("Veículo com placa " + placa + " não encontrado.");
        }
        
    }

    public ArrayList<Veiculo> listarVeiculos() {
        return respository.getVeiculos();
    }

    public void salvarDados(String nomeArquivo) throws IOException {
        respository.salvarDadosEmArquivo(nomeArquivo);
    }

    public ArrayList<String> lerDados(String nomeArquivo) throws IOException {
        return respository.lerDadosDoArquivo(nomeArquivo);
    }
}