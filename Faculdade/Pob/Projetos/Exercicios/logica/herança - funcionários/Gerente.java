public class Gerente extends Funcionario {
    private String departamento;

    public Gerente(String nome, double salario, String departamento) {
        super(nome, salario);
        this.departamento = departamento;
    }

    @Override
    public double calcularBonus() {
        double bonus;

        if (departamento.equalsIgnoreCase("TI")) {
            bonus = salario * 0.30;
        } 
        
        else if (departamento.equalsIgnoreCase("RH")) {
            bonus = salario * 0.20;
        } 
        
        else {
            bonus = salario * 0.10;
        }

        return bonus;
    }

    public void exibirDados() {
        System.out.println("Gerente: " + nome);
        System.out.println("Salario: " + salario);
        System.out.println("Departamento: " + departamento);
        System.out.println("Bonus: " + calcularBonus());
    }
}