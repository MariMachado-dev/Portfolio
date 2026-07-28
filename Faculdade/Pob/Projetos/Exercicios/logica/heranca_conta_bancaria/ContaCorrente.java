package heranca_conta_bancaria;

public class ContaCorrente extends Conta {
    private double limite;

    public ContaCorrente(String nome, double saldo, int numero, double limite) {
        super(nome, saldo, numero);
        this.limite = limite;
    }

    @Override
    public void sacarSaldo(double valor) {
        double novoSaldo;
        
        if (valor > saldo + limite) {
            System.out.println("Valor excede o limite da conta. Tente novamente");
            return;
        }
        novoSaldo = saldo - valor;
        this.saldo = novoSaldo;
        System.out.println("Operacao de saque na conta corrente realizada com sucesso!");
    }
}