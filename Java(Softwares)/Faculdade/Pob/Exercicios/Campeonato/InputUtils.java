package logica.Campeonato;
import java.util.Scanner;

public class InputUtils {
    
    public static double lerValor(String mensagem) {
        Scanner sc = new Scanner(System.in);
        double temperatura = 0;
        boolean entradaValida = false;

        while (!entradaValida) {
            try {
                System.out.print(mensagem);
                temperatura = Double.parseDouble(sc.nextLine());
                entradaValida = true;
            } catch (NumberFormatException e) {
                System.out.println("Entrada inválida! Digite um número válido.");
            }
        }

        return temperatura;
    }
}