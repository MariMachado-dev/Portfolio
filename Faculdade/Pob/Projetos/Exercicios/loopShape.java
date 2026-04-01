import java.util.Scanner;

public class loopShape {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a, b, c, sucessoCriacao1, sucessoCriacao2;
        System.out.print("Qual a largura do retangulo?");
        a  = sc.nextInt();

        System.out.print("Qual a altura do retangulo?");
        b  = sc.nextInt();

        System.out.print("Qual a altura da perna do triangulo?");
        c  = sc.nextInt();

        sucessoCriacao1 = createRectangle(a, b);
        sucessoCriacao2 = createTriangle(c);

        if (sucessoCriacao1 == 1) {
            System.out.println("\n\nRetângulo criado com sucesso");
        } else {
            System.err.println("\n\nErro ao criar retângulo");
        }

        if (sucessoCriacao2 == 1) {
            System.out.println("Triângulo criado com sucesso");
        } else {
            System.err.println("Erro ao criar triângulo");
        }

        sc.close();
    }

    public static int createRectangle(int largura, int altura) {

        //Impedir inserir valores invalidos
        if (largura < 1 || altura < 1) {
            return -1;
        }

        System.out.println("\n");
        //largura 1
        for (int i = 1;i <= largura;i++) {
            System.out.print("#");
        }

        //altura
        System.out.println();
        for (int i = 1;i<altura-1;i++) {
            System.out.print("#");

            for (int j = 1;j<largura-1;j++) {
                System.out.print(" ");
            }
            System.out.println("#");
        }

        //largura 2
        for (int i = 1;i <= largura;i++) {
            System.out.print("#");
        }

        return 1;
    }

    public static int createTriangle(int alturaPerna) {
        //Impedir inserir valores invalidos
        if (alturaPerna < 1) {
            return -1;
        }

        //Inicio
        System.out.println("\n");
        System.out.print("#");
        System.out.println("");

        for (int i = 1;i < alturaPerna-1;i++) {
            System.out.print("#");

            for (int j = 1;j<i;j++) {
                System.err.print(" ");
            }

            System.out.println("#");
        }

        //cateto 2
        for (int i = 1;i <= alturaPerna;i++) {
            System.out.print("#");
        }

        return 1;
    }
}