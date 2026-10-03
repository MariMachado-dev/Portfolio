package logica.Campeonato;
public class Equipe {
    private String nome;
    private int vitorias;
    private int derrotas;
    private int empates;
    private int golsMarcados;
    private int golsSofridos;
    
    public Equipe(String nome) {
        this.nome = nome;
        vitorias = 0;
        derrotas = 0;
        empates = 0;
        golsMarcados = 0;
        golsSofridos = 0;
    }
    
    //Getters
    public String getNome() { return nome; }
    public int getVitorias() { return vitorias; }
    public int getDerrotas() { return derrotas; }
    public int getEmpates() { return empates; }
    public int getGolsMarcados() { return golsMarcados; }
    public int getGolsSofridos() { return golsSofridos; }
    
    //Setters
    public void setNome() { this.nome = nome; }
    public void setVitorias(int vitorias) { this.vitorias = vitorias; }
    public void setDerrotas(int derrotas) { this.derrotas = derrotas; }
    public void setEmpates(int empates) { this.empates = empates; }
    public void setGolsMarcados(int golsMarcados) { this.golsMarcados = golsMarcados; }
    public void setGolsSofridos(int golsSofridos) { this.golsSofridos = golsSofridos; }
    
    public void exibirEquipe() {
        System.out.println("Team: " + nome);
        System.out.println("Wins: " + vitorias + ", Loses: " + derrotas + ", Ties: " + empates);
        System.out.println("Points Scored: " + golsMarcados + ", Points Allowed: " + golsSofridos);
    }
}
  