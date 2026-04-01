package fliperama;

public class cartao { 
    private double credito;
    private int tickets;
    private int id;


   // Construtor para inicializar os atributos
   public cartao(int id) {
    if (id < 0) {
        throw new IllegalArgumentException("Id inválido.");
    }

       this.credito = 0;
       this.tickets = 0;
       this.id = id;
   }

   public double getCredito() {
       return credito;
   }

   public void setCredito(double credito) {
    if (credito < 0) {
        throw new IllegalArgumentException("O valor de creditos não pode ser negativo");
    }
       this.credito = credito;
   }
   
   public int getTickets() {
       return tickets;
   }

   public void setTickets(int tickets) {
    if (tickets < 0) {
        throw new IllegalArgumentException("O valor de tickets não pode ser negativo");
    }
       this.tickets = tickets;
   }

   public int getId() {
       return id;
   }
}