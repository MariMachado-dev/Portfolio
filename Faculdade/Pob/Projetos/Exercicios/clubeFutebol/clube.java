public class clube { 
   private String nome;
   private int vitorias;
    private int derrotas;
   private int empates;


   // Construtor para inicializar os atributos
   public clube(String nome, int vitorias, int derrotas, int empates) { 
       this.nome = nome;
       this.vitorias = vitorias;
       this.derrotas = derrotas;
       this.empates = empates;
   }

   // Getters e setters
   public String getNome() {
       return nome;
   }

   public void setNome(String nome) {
       this.nome = nome;
   }

   public int getVitorias() {
       return vitorias;
   }

   public void setVitorias(int vitorias) {
       this.vitorias = vitorias;
   }
   
   public int getDerrotas() {
       return derrotas;
   }

   public void setDerrotas(int derrotas) {
       this.derrotas = derrotas;
   }
   
   public int getEmpates() {
       return empates;
   }

   public void setEmpates(int empates) {
       this.empates = empates;
   }

   // Método para calcular o valor total a pagar
   public int totalJogos() {
       return vitorias+derrotas+empates;
   }
   
   public int pontosGanhos() {
       return vitorias*3+empates;
   }
   
   public int pontosPerdidos() {
       return derrotas*3+empates*3;
   }
   
   public double aproveitamento() {
       return ((double)vitorias/totalJogos())*100;
   }
}