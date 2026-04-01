import java.util.Scanner;

public class validandoPINBancario {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int PIN = 123;
        int PIN_inserido;

        System.out.print("Qual o seu pin?");
        PIN_inserido = sc.nextInt();

        while (PIN != PIN_inserido) {
            System.out.print("Qual o seu pin?");
            PIN_inserido = sc.nextInt();
        }

        System.err.println("PIN correto inserido! Você pode acessar a conta!");

        sc.close();
    }
}
