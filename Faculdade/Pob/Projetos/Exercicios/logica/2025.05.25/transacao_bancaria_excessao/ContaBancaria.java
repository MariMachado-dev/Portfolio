public class ContaBancaria {
    private String titular;
    private double saldo;

    public ContaBancaria(double saldoInicial, String titular) {
        this.saldo = saldoInicial;
        this.titular = titular;
    }

    public void sacar(double valor, String titular) throws SaldoInsuficienteException {
        if (valor > saldo) {
            throw new SaldoInsuficienteException(saldo, valor);
        }
        saldo -= valor;
    }

    public double getSaldo() {
        return saldo;
    }
}
