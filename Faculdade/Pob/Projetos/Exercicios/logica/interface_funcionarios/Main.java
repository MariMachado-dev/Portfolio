public class Main {

    public static void main(String[] args) {
        Gerente g = new Gerente("Ana", "123");
        Cliente c = new Cliente("Joao", "456");

        g.trabalhar();
        g.aprovarRelatorio();

        if (g.autenticar("123")) {
            System.out.println("Gerente autenticado");
        }

        System.out.println("----------------");

        if (c.autenticar("456")) {
            System.out.println("Cliente autenticado");
        }
    }
}