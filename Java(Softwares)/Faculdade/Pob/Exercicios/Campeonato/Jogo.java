package logica.Campeonato;
import java.util.Random;

public class Jogo {
    private Equipe equipe1;
    private Equipe equipe2;
    private int pontosEquipe1;
    private int pontosEquipe2;
    private double tempDia;
    private int id;
    
    private static int contadorId = 1;
    
    public Jogo(Equipe equipe1, Equipe equipe2, double tempDia) {
        this.equipe1 = equipe1;
        this.equipe2 = equipe2;
        this.pontosEquipe1 = 0;
        this.pontosEquipe2 = 0;
        this.tempDia = tempDia;
        this.id = contadorId++;
    }
    
    public int getId() {
        return id;
    }
    
    public double getTemp() {
        return tempDia;
    }
    
    public String getNomeEquipe1() {
        return equipe1.getNome(); 
    }
    
    public String getNomeEquipe2() {
        return equipe2.getNome();
    }
    
    public int getPontosEquipe1() {
        return pontosEquipe1;
    }
    
    public int getPontosEquipe2() {
        return pontosEquipe2;
    }
    
    public void gerarPontuacao() {
        int maxGols = (int) (tempDia / 7);
        
        Random r = new Random();
        this.pontosEquipe1 = r.nextInt(maxGols + 1);
        this.pontosEquipe2 = r.nextInt(maxGols + 1);
        
        if (pontosEquipe1 > pontosEquipe2) {
            equipe1.setVitorias(equipe1.getVitorias() + 1);
            equipe2.setDerrotas(equipe1.getDerrotas() + 1);
        }
        
        else if (pontosEquipe2 > pontosEquipe1) {
            equipe2.setVitorias(equipe1.getVitorias() + 1);
            equipe1.setDerrotas(equipe1.getDerrotas() + 1);
        }
        
        else {
            equipe1.setEmpates(equipe1.getEmpates() + 1);
            equipe2.setEmpates(equipe1.getEmpates() + 1);
        }
        
        equipe1.setGolsMarcados(equipe1.getGolsMarcados()+pontosEquipe1);
        equipe2.setGolsMarcados(equipe2.getGolsMarcados()+pontosEquipe2);
        equipe1.setGolsSofridos(equipe1.getGolsSofridos()+pontosEquipe2);
        equipe2.setGolsMarcados(equipe2.getGolsMarcados()+pontosEquipe1);
    }
    
    public void exibirPlacar() {
        System.out.println("\n\nGame #"+ id);
	    System.out.println("Temperature: "+ tempDia);
	    System.out.println("Away Team: "+getNomeEquipe1()+", "+ pontosEquipe1);
        System.out.println("Home Team: "+getNomeEquipe2()+", "+ pontosEquipe2);		
    }
}