package heranca_conta_bancaria;

public class ContaPoupanca extends Conta {
    private double taxa;

    public ContaPoupanca(String nome, double saldo, int numero, double taxa) {
        super(nome, saldo, numero);
        this.taxa = taxa;
    }

    @Override
    public void sacarSaldo(double valor) {
        if (valor > saldo) {
            System.out.println("Valor excede o saldo da conta. Tente novamente");
            return;
        }
        
        double novoSaldo;
        
        valor = valor * (taxa / 100 + 1);
        novoSaldo = saldo - valor;
        this.saldo = novoSaldo;
        System.err.println("Operacao de saque na conta poupanca realizada com sucesso! Valor descontado: " + valor);
    }
}
