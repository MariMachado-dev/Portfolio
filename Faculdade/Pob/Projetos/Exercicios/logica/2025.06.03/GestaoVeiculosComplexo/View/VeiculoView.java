package GestaoVeiculosComplexo.View;

import GestaoVeiculosComplexo.Controller.*;
import GestaoVeiculosComplexo.Model.*;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class VeiculoView {
    private VeiculoController controller;
    private Scanner scanner;

    public VeiculoView(VeiculoController controller) {
        this.controller = controller;
        this.scanner = new Scanner(System.in);
    }

    public void exibirMenu() {
        while (true) {
            System.out.println("\nBem vindo ao Sistema de Gestão de Veículos. Insira a opção desejada:\n");
            System.out.println("1. Adicionar Veículo");
            System.out.println("2. Listar Veículos");
            System.out.println("3. Remover Veículo");
            System.out.println("4. Salvar Dados");
            System.out.println("5. Ler Dados");
            System.out.println("6. Sair");
            int opcao;
        try {
            opcao = Integer.parseInt(scanner.nextLine().trim());
        } catch (NumberFormatException e) {
            System.out.println("Opção inválida.");
            continue;
        }
            switch (opcao) {
                case 1:
                    System.out.println("Digite o tipo do veículo (Carro/Caminhao):");
                    String tipo = scanner.nextLine();

                    System.out.println("Digite a placa do veículo:");   
                    String placa;
                    try {
                        placa = scanner.nextLine();
                    } catch (Exception e) {
                        System.out.println("Placa inválida: " + e.getMessage());
                        break;
                    }

                    System.out.println("Digite o custo fixo do veículo:");
                    double custoFixo;
                    try { //Impedir que o programa quebre caso o usuário insira um valor não numérico
                        custoFixo = Double.parseDouble(scanner.nextLine().trim());
                    } catch (NumberFormatException e) {
                        System.out.println("Custo fixo inválido. Digite um número válido.");
                        break;
                    }

                    try {
                        if (tipo.equalsIgnoreCase("carro")) {
                            System.out.println("Digite a quilometragem do carro:");
                            int quilometragem;
                            try {
                                quilometragem = Integer.parseInt(scanner.nextLine().trim());
                            } catch (NumberFormatException e) {
                                System.out.println("Quilometragem inválida. Veículo não adicionado.");
                                break;
                            }
                            controller.adicionarVeiculo(tipo, placa, custoFixo, quilometragem);
                        } 
                        
                        else if (tipo.equalsIgnoreCase("caminhao")) {
                            System.out.println("Digite as toneladas de carga do caminhão:");
                            double toneladas;
                            try {
                                toneladas = Double.parseDouble(scanner.nextLine().trim());
                            } catch (NumberFormatException e) {
                                System.out.println("Tonelagem inválida. Veículo não adicionado.");
                                break;
                            }
                            controller.adicionarVeiculo(tipo, placa, custoFixo, toneladas);
                        } else {
                            System.out.println("Tipo inválido.");
                            break;
                        }

                        System.out.println("Veículo adicionado com sucesso!");
                    } catch (Exception e) {
                        System.out.println("Erro ao adicionar veículo: " + e.getMessage());
                    }
                    break;  

                case 2:
                    try {
                        if (controller.listarVeiculos().isEmpty()) {
                            System.out.println("Nenhum veículo cadastrado.");
                        } else {
                            for (Veiculo v : controller.listarVeiculos()) {
                                System.out.println(
                                    "Placa: " + v.getPlaca() +
                                    " | Custo Fixo: " + v.getCustoFixo() +
                                    " | Custo Total: " + v.calcularCustoTotal()
                                );
                            }
                        }
                    } catch (Exception e) {
                        System.out.println("Erro ao listar veículos: " + e.getMessage());
                    }
                    break;

                case 3:
                    try {
                        System.out.println("Digite a placa do veículo a ser removido:");
                        String placaRemover = scanner.nextLine();
                        controller.removerVeiculo(placaRemover);
                    } catch (Exception e) {
                        System.out.println("Erro ao remover veículo: " + e.getMessage());
                    }
                    break;

                case 4:
                    System.out.println("Em que arquivo  deseja salvar os dados?");
                    String nomeArquivoSalvar = scanner.nextLine();
                    try {
                        controller.salvarDados(nomeArquivoSalvar);
                    } catch (IOException e) {
                        System.out.println("Erro ao salvar dados: " + e.getMessage());
                    }
                    break;
                    
                case 5:
                    System.out.println("Em que arquivo deseja ler os dados?");
                    String nomeArquivoLer = scanner.nextLine();

                    try {
                        ArrayList<String> dados = controller.lerDados(nomeArquivoLer);

                        if (dados.isEmpty()) {
                            System.out.println("Arquivo vazio.");
                        } else {
                            for (String linha : dados) {
                                System.out.println(linha);
                            }
                        }
                    } catch (IOException e) {
                        System.out.println("Erro ao ler dados: " + e.getMessage());
                    }
                    break;
                case 6:
                    System.out.println("Saindo...\n");
                    return;
                default:
                    System.out.println("Opção inválida.");
            }
        }
    }
}
