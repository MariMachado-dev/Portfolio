public class Main {
    public static void main(String[] args) {
        Funcionario f1 = new Gerente("Carlos", 4000, 1000);
        Funcionario f2 = new Desenvolvedor("Maria", 5000, 20);

        System.out.println("Salário do gerente " + f1.getNome() + ": " + f1.calcularSalario());
        System.out.println("Salário do desenvolvedor " + f2.getNome() + ": " + f2.calcularSalario());
    }
}
