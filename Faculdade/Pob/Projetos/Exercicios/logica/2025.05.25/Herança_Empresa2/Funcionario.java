public class Funcionario { 
    private String cpf;
    private double salario;

    public Funcionario(String cpf, double salario) {
        this.cpf = cpf;
        this.salario = salario;
    }

    //get e setters
    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }
}