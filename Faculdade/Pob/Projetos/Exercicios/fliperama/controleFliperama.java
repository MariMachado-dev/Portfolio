package fliperama;
import java.util.Scanner;

public class controleFliperama {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("====== 🎮 FLIPERAMA 🎮 ======");

        cartao c1 = new cartao (123);
        cartao c2 = new cartao(456);

        System.out.print("\nQuanto deseja colocar no Cartao 1 (R$)? ");
        int dinheiro = sc.nextInt();
        double creditos = dinheiro * 2;

        c1.setCredito(creditos);

        System.out.println("Cartao " + c1.getId() + " agora tem " + c1.getCredito() + " creditos.");


        jogos j1 = new jogos(4);
        jogos j2 = new jogos(7);
        jogos j3 = new jogos(2);

        System.out.println("\n--- Jogando com Cartao 1 ---");
        j1.usarCartao(c1);
        j2.usarCartao(c1);

        System.out.println("\n--- Jogando com Cartao 2 ---");
        j3.usarCartao(c2); 

        System.out.println("\nDeseja transferir tudo do Cartao 1 para o Cartao 2? [s/n]");
        String resp = sc.next();

        if (resp.equalsIgnoreCase("s")) {
            c2.setCredito(c2.getCredito() + c1.getCredito());
            c2.setTickets(c2.getTickets() + c1.getTickets());

            c1.setCredito(0);
            c1.setTickets(0);

            System.out.println("Transferencia realizada!");
        }

        System.out.println("\n--- Status dos Cartoes ---");
        System.out.println("Cartao " + c1.getId() + " | Creditos: " + c1.getCredito() + " | Tickets: " + c1.getTickets());
        System.out.println("Cartao " + c2.getId() + " | Creditos: " + c2.getCredito() + " | Tickets: " + c2.getTickets());

        categoriaPremio p1 = new categoriaPremio("Carro", 20, 3);
        categoriaPremio p2 = new categoriaPremio("Boneca", 15, 0);
        categoriaPremio p3 = new categoriaPremio("Jogo", 40, 1);

        System.out.println("\n--- Troca de Premios ---");

        if (c2.getTickets() >= p1.getCustoTickets() && p1.getQtdItens() > 0) {
            c2.setTickets(c2.getTickets() - p1.getCustoTickets());
            p1.setQtdItens(p1.getQtdItens() - 1);
            System.out.println("Premio ganho: " + p1.getNome());
        } else {
            System.out.println("Nao foi possivel pegar premio 1");
        }

        j1.usarCartao(c1);

        System.out.println("\n--- Tentando trocar premio ---");
        if (c1.getTickets() >= p3.getCustoTickets()) {
            System.out.println("Premio ganho!");
        } else {
            System.out.println("Tickets insuficientes!");
        }

        System.out.println("\n====== FIM DO TESTE ======");
    }
}