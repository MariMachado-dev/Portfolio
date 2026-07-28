package logica.Campeonato;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Random;

public class Main
{
	public static void main(String[] args) {
		ArrayList<Jogo> jogos = new ArrayList<>();
		Scanner sc = new Scanner(System.in);
		double tempAtual, maiorTemp = 0, tempMedia = 0, contTemp = 0;
		int idx1, idx2;
		int contDiasFrios = 0;
		
		Random rand = new Random();
		
		Equipe[] equipes = {
            new Equipe("Flamengo"),
            new Equipe("Fluminense"),
            new Equipe("Botafogo"),
            new Equipe("Vasco")
        };
		
		while (contDiasFrios < 3) {
		    tempAtual = InputUtils.lerValor("Forneça uma temperatura:");
		    
		    if (tempAtual > maiorTemp) {
		        maiorTemp = tempAtual;
		    }
		    
		    tempMedia = (tempMedia * contTemp + tempAtual) / (contTemp + 1);
		    contTemp++;
		    if (tempAtual > 1) {
    		    for (int i = 0;i < 2;i++) {
    		        idx1 = rand.nextInt(equipes.length);
                    idx2 = rand.nextInt(equipes.length);
                    
                    while (idx1 == idx2) {
                        idx2 = rand.nextInt(equipes.length);
                    }
                    
                    Equipe equipe1 = equipes[idx1];
                    Equipe equipe2 = equipes[idx2];  
                    
                    Jogo novoJogo = new Jogo(equipe1, equipe2, tempAtual);
                    novoJogo.gerarPontuacao(); 
                    jogos.add(novoJogo);
                    
                    contDiasFrios = 0;
    		    }
    		}
    		
    		else {
    		    System.out.println("Too cold!");
    		    contDiasFrios++;
    		}   
		}
		
		//Fim da temporada
		System.out.println("Season is over");
		System.out.println("\n\n*********RESULTS*********\n\n");
		
		for (Equipe e : equipes) {
            e.exibirEquipe();
        }
		
		for (Jogo j : jogos) {
            j.exibirPlacar();
        }
		
		System.out.println("\nHottest Temp: "+maiorTemp);
		System.out.println("Average Temp:"+tempMedia);

		sc.close();
	}
}
