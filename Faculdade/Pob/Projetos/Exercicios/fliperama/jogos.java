package fliperama;
import java.util.Random;

public class jogos {
    private double custoCredito;

    public jogos(double custoCredito) {
    if (custoCredito < 0) {
        throw new IllegalArgumentException("Custo do jogo em credito inválido.");
    }
       this.custoCredito = custoCredito;
   }

   public double getCustoCredito() {
       return custoCredito;
   }

   public void setCustoCredito(double custoCredito) {
       this.custoCredito = custoCredito;
   }

    public void usarCartao(cartao c) {
        double creditoAtual;
        int ticketsGanhos, ticketsIniciais;

        if (c.getCredito() < custoCredito) {
            System.out.println("Quantidade de creditos insuficiente! Recarregue o cartao!");
        }

        else {
            creditoAtual = c.getCredito();
            creditoAtual -= custoCredito;
            c.setCredito(creditoAtual);

            Random rand = new Random();
            ticketsGanhos = rand.nextInt(100);

            System.out.println("Cartao "+c.getId()+" usado.");
            System.out.println("Voce ganhou "+ticketsGanhos+" tickets!");

            ticketsIniciais = c.getTickets();
            c.setTickets(ticketsIniciais+ticketsGanhos);
        }
    }
}
