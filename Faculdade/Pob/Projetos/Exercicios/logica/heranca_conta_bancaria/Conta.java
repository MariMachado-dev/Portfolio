package heranca_conta_bancaria;

public class Conta {
    protected String nome;
    protected double saldo;
    protected int senha;
    
    public Conta(String nome, double saldo, int senha) {
        this.nome = nome;
        this.saldo = saldo;
        this.senha = senha;
    }
    
    public void escolherOperacao(char operacao, double valor) {
        switch (operacao) {
            case 'S':
                sacarSaldo(valor);
                break;
            case 'A':
                adicionarSaldo(valor);
                break;
            default:
                System.out.println("Operacao inexistente. Tente novamente");
                return;
        }
    }
    
    public void sacarSaldo(double valor) {
        if (valor > saldo) {
            System.out.println("Valor excede o saldo da conta. Tente novamente");
            return;
        }

        double novoSaldo;
        
        novoSaldo = saldo - valor;
        this.saldo = novoSaldo;
        System.out.println("Operacao de saque realizada com sucesso! Novo saldo: " + saldo);
    }
    
    public void adicionarSaldo(double valor) {
        double novoSaldo;
        
        novoSaldo = saldo + valor;
        this.saldo = novoSaldo;
        System.out.println("Valor adicionado com sucesso! Novo saldo: " + saldo);
    }
}