import java.util.Scanner;

public class ControleVenda {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Digite o nome do clube: ");
        String nome = sc.next();

        System.out.print("Digite a quantidade de vitorias: ");
        int vitorias = sc.nextInt();
        
        System.out.print("Digite a quantidade de empates: ");
        int empates = sc.nextInt();
        
        System.out.print("Digite a quantidade de derrotas: ");
        int derrotas = sc.nextInt();

        // Criando o objeto VendaProduto com os dados inseridos
        clube flamengo = new clube(nome, vitorias, derrotas, empates);

        // Exibindo os dados da venda com formatação via DecimalFormat
        System.out.println("\nDados do clube:");
        System.out.println("Nome do clube: " + flamengo.getNome());
        System.out.println("Quantidade de vitorias: " + flamengo.getVitorias());
        System.out.println("Quantidade de empates: " + flamengo.getEmpates());
        System.out.println("Quantidade de derrotas: " + flamengo.getDerrotas());
        System.out.println("\n\nTotal de jogos: " + flamengo.totalJogos());
        System.out.println("Pontos ganhos durante a temporada: " + flamengo.pontosGanhos());
        System.out.println("Pontos perdidos durante a temporada: " + flamengo.pontosPerdidos());
        int ap = (int) flamengo.aproveitamento();
        System.out.println("Aproveitamento: " + ap + "%");


        sc.close();  // Fechar o Scanner após o uso
    }
}